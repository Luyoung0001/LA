`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ============================================================================
// 分支预测单元 (BPU) — BTB + Gshare + RAS
//
// 架构：
//   - BTB (Branch Target Buffer): BRAM 实现，存储 PC tag + target + 分支类型
//   - PHT (Pattern History Table): BRAM 实现，2-bit 饱和计数器
//   - Gshare: 全局历史 XOR PC 索引 PHT
//   - RAS (Return Address Stack): 寄存器实现，预测函数返回
//
// 时序：
//   查找：S1 发送 lookup_pc_i → 1 拍 BRAM 延迟 → S2 接收预测结果
//   更新：S8 发送 update 信号 → 当拍更新 BTB，PHT 晚 1 拍更新
//         S4 发送 RAS update → ret/call 一进入译码后端就更新 RAS
//
// 可配置参数：
//   - BTB_ENTRIES: BTB 深度 (2^BTB_INDEX_WIDTH)
//   - PHT_ENTRIES: PHT 深度 (2^PHT_INDEX_WIDTH)
//   - RAS_ENTRIES: RAS 深度
//   - GSHARE_ENABLE: 启用 Gshare (1) 或局部历史 (0)
//   - INDIRECT_PREDICT_ENABLE: 启用普通 indirect JIRL 的 PC-indexed BTB 预测
//   - COND_ONLY_HISTORY_ENABLE: 实验开关，仅条件分支训练 PHT/history
// ============================================================================
module cpu_bpu #(
    parameter XLEN            = 32,
    parameter BTB_INDEX_WIDTH = 6,   // BTB 深度 = 2^6 = 64
    parameter PHT_INDEX_WIDTH = 9,   // PHT 深度 = 2^9 = 512
    parameter RAS_INDEX_WIDTH = 3,   // RAS 深度 = 2^3 = 8
    parameter GSHARE_ENABLE   = 1,   // 1=Gshare, 0=局部历史
    parameter COND_PREDICT_ENABLE = 1,
    parameter INDIRECT_PREDICT_ENABLE = 1,
    parameter COND_ONLY_HISTORY_ENABLE = 0
) (
    input  wire            clk,
    input  wire            rst_n,

    // ---- 查找端口（S1 请求，S2 拿结果） ----
    input  wire [XLEN-1:0] lookup_pc_i,
    output wire            pred_valid_o,       // BTB 命中
    output wire            pred_taken_o,       // 预测 taken
    output wire [XLEN-1:0] pred_target_o,      // 跳转目标
    output wire            pred_is_call_o,     // 是 call 指令
    output wire            pred_is_ret_o,      // 是 ret 指令
    output wire            pred_is_indirect_jmp_o, // 是普通 indirect JIRL
    output wire            pred_ras_valid_o,   // RAS 顶部有效（供译码后 ret 早期重定向）
    output wire [XLEN-1:0] pred_ras_target_o,  // RAS 顶部返回地址

    // ---- 更新端口（S8 分支/跳转解析） ----
    input  wire            update_valid_i,
    input  wire [XLEN-1:0] update_pc_i,
    input  wire            update_taken_i,
    input  wire [XLEN-1:0] update_target_i,
    input  wire            update_is_call_i,
    input  wire            update_is_ret_i,
    input  wire            update_is_jmp_i,
    input  wire            update_is_indirect_jmp_i,

    // ---- RAS 早期更新端口（S4 预解码 fire）----
    input  wire            ras_update_valid_i,
    input  wire [XLEN-1:0] ras_update_pc_i,
    input  wire            ras_update_is_call_i,
    input  wire            ras_update_is_ret_i
);

    localparam BTB_ENTRIES = 1 << BTB_INDEX_WIDTH;
    localparam PHT_ENTRIES = 1 << PHT_INDEX_WIDTH;
    localparam RAS_ENTRIES = 1 << RAS_INDEX_WIDTH;

    // ========================================================================
    // BTB (Branch Target Buffer) - BRAM 实现
    // ========================================================================
    localparam BTB_TAG_WIDTH = XLEN - BTB_INDEX_WIDTH - 2;  // PC[31:BTB_INDEX_WIDTH+2]

    // BTB 表项格式：{valid, tag, target, is_call, is_ret, is_direct_jmp, is_indirect_jmp}
    localparam BTB_ENTRY_WIDTH = 1 + BTB_TAG_WIDTH + XLEN + 4;

    // BTB RAM：FPGA 综合时推断为 Block RAM，仿真时为普通 reg 数组
    // 两种模式行为完全一致（1 拍读延迟），接口不变
    // FPGA 路径：LUTRAM 异步读 + 1 拍寄存，消除 BRAM 2.1 ns 读延迟
    // BTB_ENTRIES=64，BTB_ENTRY_WIDTH≈60bit，约需 60 个 LUT6-as-RAM（xc7a200t 完全够用）
    (* ram_style = "distributed" *) reg [BTB_ENTRY_WIDTH-1:0] btb_ram [0:BTB_ENTRIES-1];

    // 查找端口
    wire [BTB_INDEX_WIDTH-1:0] btb_rd_idx = lookup_pc_i[BTB_INDEX_WIDTH+1:2];

    // LUTRAM 异步读出后打一拍，保持 1 拍读延迟（与原 BRAM 接口完全兼容）
    // T0 异步读 → T1 寄存器输出，路径仅有 FDRE Q 延迟 ~0.35 ns（vs BRAM 2.1 ns）
    wire [BTB_ENTRY_WIDTH-1:0] btb_rd_data_async = btb_ram[btb_rd_idx];
    reg  [BTB_ENTRY_WIDTH-1:0] btb_rd_data_r;
    integer bi;
    initial begin
        for (bi = 0; bi < BTB_ENTRIES; bi = bi + 1)
            btb_ram[bi] = {BTB_ENTRY_WIDTH{1'b0}};
    end

    always @(posedge clk) begin
        btb_rd_data_r <= btb_rd_data_async;
    end

    // 解析 BTB 表项
    wire        btb_valid_r   = btb_rd_data_r[BTB_ENTRY_WIDTH-1];
    wire [BTB_TAG_WIDTH-1:0] btb_tag_r = btb_rd_data_r[BTB_ENTRY_WIDTH-2 -: BTB_TAG_WIDTH];
    wire [XLEN-1:0] btb_target_r = btb_rd_data_r[XLEN+3:4];
    wire        btb_is_call_r         = btb_rd_data_r[3];
    wire        btb_is_ret_r          = btb_rd_data_r[2];
    wire        btb_is_direct_jmp_r   = btb_rd_data_r[1];
    wire        btb_is_indirect_jmp_r = btb_rd_data_r[0];

    // 查找 PC (延迟 1 拍与 BRAM 对齐)
    reg [XLEN-1:0] lookup_pc_r;
    always @(posedge clk) begin
        lookup_pc_r <= lookup_pc_i;
    end

    wire [BTB_TAG_WIDTH-1:0] lookup_tag = lookup_pc_r[XLEN-1:BTB_INDEX_WIDTH+2];
    wire btb_hit = btb_valid_r && (btb_tag_r == lookup_tag);

    // 更新端口
    wire [BTB_INDEX_WIDTH-1:0] btb_wr_idx = update_pc_i[BTB_INDEX_WIDTH+1:2];
    wire [BTB_TAG_WIDTH-1:0]   btb_wr_tag = update_pc_i[XLEN-1:BTB_INDEX_WIDTH+2];
    wire                       btb_wr_is_indirect_jmp = update_is_indirect_jmp_i && !update_is_ret_i;
    wire                       btb_wr_is_direct_jmp   = update_is_jmp_i && !btb_wr_is_indirect_jmp && !update_is_ret_i;

    always @(posedge clk) begin
        if (!rst_n) begin
            // BRAM 不需要显式复位（综合工具会优化掉）
        end else if (update_valid_i) begin
            btb_ram[btb_wr_idx] <= {
                1'b1,                    // valid
                btb_wr_tag,              // tag
                update_target_i,         // target
                update_is_call_i,        // is_call
                update_is_ret_i,         // is_ret
                btb_wr_is_direct_jmp,    // is_direct_jmp
                btb_wr_is_indirect_jmp   // is_indirect_jmp
            };
        end
    end

    // ========================================================================
    // PHT (Pattern History Table) - 2-bit 饱和计数器
    // ========================================================================
    // PHT RAM：FPGA 综合时推断为 Block RAM，仿真时为普通 reg 数组
    (* ram_style = "block" *) reg [1:0] pht_ram [0:PHT_ENTRIES-1];

    // 全局历史寄存器 (Gshare)
    reg [PHT_INDEX_WIDTH-1:0] global_history_q;

    // 查找索引：Gshare = history XOR PC, 局部 = PC
    wire [PHT_INDEX_WIDTH-1:0] pht_rd_idx = GSHARE_ENABLE ?
        (global_history_q ^ lookup_pc_i[PHT_INDEX_WIDTH+1:2]) :
        lookup_pc_i[PHT_INDEX_WIDTH+1:2];

    reg [1:0] pht_rd_data_r;
    always @(posedge clk) begin
        pht_rd_data_r <= pht_ram[pht_rd_idx];
    end

    wire pht_predict_taken = (pht_rd_data_r >= 2'd2);

    // ---- PHT 更新：打一拍寄存，切断 S7 branch_taken → flush_w → PHT WE 关键路径 ----
    // 代价：PHT 更新延迟 1 拍，对预测准确率影响极小（后续分支通常不立即重用同一 PHT 条目）
    reg                          update_valid_d1;
    reg                          update_taken_d1;
    reg [PHT_INDEX_WIDTH-1:0]    pht_wr_idx_d1;

    // 实验模式：PHT / gshare history 只记录条件分支方向。
    // 默认关闭以保持既有、已通过 CoreMark 的主线行为；后续可单独打开定位
    // direct jump / call / ret / indirect JIRL 污染 history 对性能与正确性的影响。
    wire update_is_cond_branch_w =
        update_valid_i &&
        !update_is_call_i &&
        !update_is_ret_i &&
        !update_is_jmp_i &&
        !update_is_indirect_jmp_i;
    wire update_pht_history_valid_w =
        update_valid_i &&
        (!COND_ONLY_HISTORY_ENABLE || update_is_cond_branch_w);

    // 计算当拍写索引（基于当前 history，在打拍之前计算）
    wire [PHT_INDEX_WIDTH-1:0] pht_wr_idx_comb = GSHARE_ENABLE ?
        (global_history_q ^ update_pc_i[PHT_INDEX_WIDTH+1:2]) :
        update_pc_i[PHT_INDEX_WIDTH+1:2];

    always @(posedge clk) begin
        if (!rst_n) begin
            update_valid_d1 <= 1'b0;
            update_taken_d1 <= 1'b0;
            pht_wr_idx_d1   <= {PHT_INDEX_WIDTH{1'b0}};
        end else begin
            update_valid_d1 <= update_pht_history_valid_w;
            update_taken_d1 <= update_taken_i;
            pht_wr_idx_d1   <= pht_wr_idx_comb; // 写索引也一起打拍
        end
    end

    // 更新 PHT（用 _d1 信号，比 S7 晚一拍）
    integer i;
    initial begin
        for (i = 0; i < PHT_ENTRIES; i = i + 1)
            pht_ram[i] = 2'd1;  // 初始弱 not-taken，降低一次性条件分支误预测
    end

    always @(posedge clk) begin
        if (update_valid_d1 && update_taken_d1 && pht_ram[pht_wr_idx_d1] < 2'd3) begin
            pht_ram[pht_wr_idx_d1] <= pht_ram[pht_wr_idx_d1] + 2'd1;
        end else if (update_valid_d1 && !update_taken_d1 && pht_ram[pht_wr_idx_d1] > 2'd0) begin
            pht_ram[pht_wr_idx_d1] <= pht_ram[pht_wr_idx_d1] - 2'd1;
        end
    end

    // 更新全局历史（保持当拍，保证后续查找索引正确）
    always @(posedge clk) begin
        if (!rst_n)
            global_history_q <= {PHT_INDEX_WIDTH{1'b0}};
        else if (update_pht_history_valid_w)
            global_history_q <= {global_history_q[PHT_INDEX_WIDTH-2:0], update_taken_i};
    end

    // ========================================================================
    // RAS (Return Address Stack) - 寄存器实现
    // ========================================================================
    reg [XLEN-1:0] ras_stack [0:RAS_ENTRIES-1];
    reg [RAS_INDEX_WIDTH-1:0] ras_index_q;

    // RAS 预测输出
    wire [XLEN-1:0] ras_pred_target = ras_stack[ras_index_q];
    wire ras_valid = (ras_pred_target != 32'h0);  // 非零地址有效

    // RAS 更新逻辑
    integer j;
    always @(posedge clk) begin
        if (!rst_n) begin
            for (j = 0; j < RAS_ENTRIES; j = j + 1)
                ras_stack[j] <= 32'h0;
            ras_index_q <= {RAS_INDEX_WIDTH{1'b0}};
        end else if (ras_update_valid_i && ras_update_is_call_i) begin
            // Call: push 返回地址 (PC + 4)
            ras_stack[ras_index_q + 1'b1] <= ras_update_pc_i + 32'd4;
            ras_index_q <= ras_index_q + 1'b1;
        end else if (ras_update_valid_i && ras_update_is_ret_i && ras_valid) begin
            // Return: pop
            ras_index_q <= ras_index_q - 1'b1;
        end
    end

    // ========================================================================
    // 输出逻辑：组合 BTB + PHT + RAS
    // ========================================================================
    // 优先级：RAS > BTB+PHT
    // - 如果是 ret 指令且 RAS 有效 → 使用 RAS 预测
    // - 否则使用 BTB+PHT 预测

`ifdef BPU_TEST_TAKEN
    // 测试模式：对特定 PC 返回固定预测
    assign pred_valid_o    = (lookup_pc_r == 32'h80000020);
    assign pred_taken_o    = (lookup_pc_r == 32'h80000020);
    assign pred_target_o   = 32'hA0000000;
    assign pred_is_call_o  = 1'b0;
    assign pred_is_ret_o   = 1'b0;
    assign pred_is_indirect_jmp_o = 1'b0;
    assign pred_ras_valid_o = 1'b0;
    assign pred_ras_target_o = {XLEN{1'b0}};
`else
    // 正常模式
    assign pred_valid_o    = btb_hit;
    assign pred_is_call_o  = btb_hit && btb_is_call_r;
    assign pred_is_ret_o   = btb_hit && btb_is_ret_r;
    assign pred_is_indirect_jmp_o = btb_hit && btb_is_indirect_jmp_r;
    wire btb_is_cond_r = !(btb_is_direct_jmp_r || btb_is_indirect_jmp_r ||
                           btb_is_call_r || btb_is_ret_r);

    // 目标地址：ret 用 RAS，其他用 BTB
    assign pred_target_o   = (btb_hit && btb_is_ret_r && ras_valid) ?
                             ras_pred_target : btb_target_r;

    // taken 判断：direct jump/call/ret 固定 taken，普通 indirect JIRL 命中 BTB 后按参数预测 taken，
    // 条件分支看 PHT。
    assign pred_taken_o    = btb_hit && (btb_is_direct_jmp_r ||
                                         (INDIRECT_PREDICT_ENABLE && btb_is_indirect_jmp_r) ||
                                         btb_is_call_r || btb_is_ret_r ||
                                         (btb_is_cond_r && COND_PREDICT_ENABLE && pht_predict_taken));
    assign pred_ras_valid_o = ras_valid;
    assign pred_ras_target_o = ras_pred_target;
`endif

`ifdef VERILATOR
    always @(posedge clk) begin
        if (!rst_n) begin
            `CPU_DEBUG($sformatf("[BPU][RESET] history=0x%0x", global_history_q));
        end else begin
            if (update_valid_i) begin
                `CPU_DEBUG($sformatf(
                    "[BPU][UPDATE] pc=0x%08x taken=%0d target=0x%08x call=%0d ret=%0d direct_jmp=%0d indirect_jmp=%0d btb_idx=%0d pht_idx=%0d history=0x%0x",
                    update_pc_i, update_taken_i, update_target_i,
                    update_is_call_i, update_is_ret_i, btb_wr_is_direct_jmp, btb_wr_is_indirect_jmp,
                    btb_wr_idx, pht_wr_idx_comb, global_history_q
                ));
            end
            if (ras_update_valid_i) begin
                `CPU_DEBUG($sformatf(
                    "[BPU][RAS] pc=0x%08x call=%0d ret=%0d old_valid=%0d old_target=0x%08x",
                    ras_update_pc_i, ras_update_is_call_i, ras_update_is_ret_i,
                    ras_valid, ras_pred_target
                ));
            end
            if (pred_valid_o || btb_hit || lookup_pc_i != lookup_pc_r) begin
                `CPU_DEBUG($sformatf(
                    "[BPU][LOOKUP] req_pc=0x%08x aligned_pc=0x%08x btb_idx=%0d hit=%0d pred(valid=%0d taken=%0d target=0x%08x call=%0d ret=%0d indirect_jmp=%0d) pht_cnt=%0d ras(valid=%0d target=0x%08x)",
                    lookup_pc_i, lookup_pc_r, btb_rd_idx, btb_hit,
                    pred_valid_o, pred_taken_o, pred_target_o, pred_is_call_o, pred_is_ret_o,
                    pred_is_indirect_jmp_o, pht_rd_data_r, ras_valid, ras_pred_target
                ));
            end
        end
    end
`endif

    `CPU_DEBUG_MODULE("cpu_bpu")
endmodule
