`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ============================================================================
// Fetch Buffer — 8-entry FIFO，解耦前端取指与后端译码
//
// 插在 S3(IF2) 和 S4(ID0) 之间。
// - 写入：S3 valid 且 FB 有空位时写入
// - 读出：下游 allowin 且 FB not_empty 时弹出
// - 直通：FB empty 且下游 allowin 时，S3 当拍数据直接送到 S4
// - flush：S7 redirect 时清空
// ============================================================================
module fetch_buffer #(
    parameter XLEN  = 32,
    parameter ILEN  = 32,
    parameter DEPTH = 8,    // 必须是 2 的幂
    parameter EPOCH_WIDTH = 1,
    parameter COUNT_WIDTH = $clog2(DEPTH) + 1
) (
    input  wire            clk,
    input  wire            rst_n,
    input  wire            flush,
    input  wire [EPOCH_WIDTH-1:0] current_epoch_i,
    input  wire            dual_slot_consume_i,

    // ---- 写入侧（来自 S3） ----
    input  wire            wr_valid_i,
    input  wire [XLEN-1:0] wr_pc_i,
    input  wire [XLEN-1:0] wr_pc1_i,
    input  wire [ILEN-1:0] wr_instr_i,
    input  wire            wr_slot0_valid_i,
    input  wire [ILEN-1:0] wr_instr1_i,
    input  wire            wr_slot1_valid_i,
    input  wire [EPOCH_WIDTH-1:0] wr_epoch_i,
    input  wire            wr_pred_taken_i,
    input  wire [XLEN-1:0] wr_pred_target_i,
    input  wire            wr_ras_valid_i,
    input  wire [XLEN-1:0] wr_ras_target_i,
    input  wire            wr_fault_i,
    input  wire [5:0]      wr_fault_ecode_i,
    input  wire [XLEN-1:0] wr_fault_badv_i,
    output wire            not_full_o,     // 反压 S3
    output wire            wr_fire_o,
    output wire            bypass_o,

    // ---- 读出侧（向 S4） ----
    input  wire            rd_allowin_i,   // S4 allowin
    output wire            rd_valid_o,
    output wire            rd_fire_o,
    output wire            empty_o,
    output wire            nonempty_o,
    output wire            full_o,
    output wire [COUNT_WIDTH-1:0] level_o,
    output wire [XLEN-1:0] rd_pc_o,
    output wire [XLEN-1:0] rd_pc1_o,
    output wire [ILEN-1:0] rd_instr_o,
    output wire            rd_slot0_valid_o,
    output wire [ILEN-1:0] rd_instr1_o,
    output wire            rd_slot1_valid_o,
    output wire [EPOCH_WIDTH-1:0] rd_epoch_o,
    output wire            rd_pred_taken_o,
    output wire [XLEN-1:0] rd_pred_target_o,
    output wire            rd_ras_valid_o,
    output wire [XLEN-1:0] rd_ras_target_o,
    output wire            rd_fault_o,
    output wire [5:0]      rd_fault_ecode_o,
    output wire [XLEN-1:0] rd_fault_badv_o
);

    localparam PTR_W = $clog2(DEPTH);

    // ---- 存储 ----
    reg [XLEN-1:0] buf_pc         [0:DEPTH-1];
    reg [XLEN-1:0] buf_pc1        [0:DEPTH-1];
    reg [ILEN-1:0] buf_instr      [0:DEPTH-1];
    reg            buf_slot0_valid[0:DEPTH-1];
    reg [ILEN-1:0] buf_instr1     [0:DEPTH-1];
    reg            buf_slot1_valid[0:DEPTH-1];
    reg [EPOCH_WIDTH-1:0] buf_epoch[0:DEPTH-1];
    reg            buf_pred_taken [0:DEPTH-1];
    reg [XLEN-1:0] buf_pred_target[0:DEPTH-1];
    reg            buf_ras_valid  [0:DEPTH-1];
    reg [XLEN-1:0] buf_ras_target [0:DEPTH-1];
    reg            buf_fault      [0:DEPTH-1];
    reg [5:0]      buf_fault_ecode[0:DEPTH-1];
    reg [XLEN-1:0] buf_fault_badv [0:DEPTH-1];

    reg [PTR_W-1:0] wr_ptr_q;
    reg [PTR_W-1:0] rd_ptr_q;
    reg [PTR_W  :0] count_q;    // 多一位避免满/空歧义
    // 双槽模式下，slot1 已随前一个 packet 被后端消费；后续若 PC+4
    // 又以普通 slot0 形式到达，在这里丢弃，避免重复执行。
    reg            skip_valid_q;
    reg [XLEN-1:0] skip_pc_q;
    reg [EPOCH_WIDTH-1:0] skip_epoch_q;

    wire empty  = (count_q == 0);
    wire full   = (count_q == DEPTH);
    wire active_w = rst_n && !flush;

    wire wr_epoch_match_w = (wr_epoch_i == current_epoch_i);
    wire stored_head_epoch_match_w = (buf_epoch[rd_ptr_q] == current_epoch_i);
    wire skip_epoch_match_w = skip_valid_q && (skip_epoch_q == current_epoch_i);
    wire stored_head_skip_w =
        !empty && skip_epoch_match_w &&
        stored_head_epoch_match_w &&
        (buf_epoch[rd_ptr_q] == skip_epoch_q) &&
        (buf_pc[rd_ptr_q] == skip_pc_q);
    wire wr_skip_w =
        empty && wr_valid_i && wr_epoch_match_w && skip_epoch_match_w &&
        (wr_epoch_i == skip_epoch_q) && (wr_pc_i == skip_pc_q);
    wire stale_head_w = !empty && !stored_head_epoch_match_w;
    wire do_rd      = active_w && (rd_allowin_i || stale_head_w || stored_head_skip_w) && !empty;
    wire bypass_w   = active_w && empty && wr_valid_i && wr_epoch_match_w && !wr_skip_w;
    wire do_bypass  = bypass_w && rd_allowin_i;
    wire do_wr = active_w && wr_valid_i && wr_epoch_match_w && not_full_o && !do_bypass && !wr_skip_w;
    wire rd_real_accept_w = rd_allowin_i && rd_valid_o;
    wire rd_consumes_slot1_w = dual_slot_consume_i && rd_real_accept_w && rd_slot1_valid_o;
    wire rd_misses_pending_skip_w =
        rd_real_accept_w && skip_epoch_match_w &&
        !((rd_epoch_o == skip_epoch_q) && (rd_pc_o == skip_pc_q));

    // 满 FIFO 如果本拍同时读出，就可以接受一个新写入，避免多打一拍反压。
    assign not_full_o = !active_w || !full || do_rd;
    assign rd_valid_o = active_w && ((!empty && stored_head_epoch_match_w && !stored_head_skip_w) || bypass_w);
    assign wr_fire_o  = do_wr;
    assign rd_fire_o  = do_rd;
    assign bypass_o   = do_bypass;
    assign empty_o    = empty;
    assign nonempty_o = !empty;
    assign full_o     = full;
    assign level_o    = count_q;

    // ---- 写入 ----
    always @(posedge clk) begin
        if (do_wr) begin
            buf_pc         [wr_ptr_q] <= wr_pc_i;
            buf_pc1        [wr_ptr_q] <= wr_pc1_i;
            buf_instr      [wr_ptr_q] <= wr_instr_i;
            buf_slot0_valid[wr_ptr_q] <= wr_slot0_valid_i;
            buf_instr1     [wr_ptr_q] <= wr_instr1_i;
            buf_slot1_valid[wr_ptr_q] <= wr_slot1_valid_i;
            buf_epoch      [wr_ptr_q] <= wr_epoch_i;
            buf_pred_taken [wr_ptr_q] <= wr_pred_taken_i;
            buf_pred_target[wr_ptr_q] <= wr_pred_target_i;
            buf_ras_valid  [wr_ptr_q] <= wr_ras_valid_i;
            buf_ras_target [wr_ptr_q] <= wr_ras_target_i;
            buf_fault      [wr_ptr_q] <= wr_fault_i;
            buf_fault_ecode[wr_ptr_q] <= wr_fault_ecode_i;
            buf_fault_badv [wr_ptr_q] <= wr_fault_badv_i;
        end
    end

    // ---- 指针与计数 ----
    always @(posedge clk) begin
        if (!rst_n || flush) begin
            wr_ptr_q <= {PTR_W{1'b0}};
            rd_ptr_q <= {PTR_W{1'b0}};
            count_q  <= {(PTR_W+1){1'b0}};
            skip_valid_q <= 1'b0;
            skip_pc_q <= {XLEN{1'b0}};
            skip_epoch_q <= {EPOCH_WIDTH{1'b0}};
        end else begin
            if (do_wr)
                wr_ptr_q <= wr_ptr_q + {{(PTR_W-1){1'b0}}, 1'b1};
            if (do_rd)
                rd_ptr_q <= rd_ptr_q + {{(PTR_W-1){1'b0}}, 1'b1};
            case ({do_wr, do_rd})
                2'b10: count_q <= count_q + {{PTR_W{1'b0}}, 1'b1};
                2'b01: count_q <= count_q - {{PTR_W{1'b0}}, 1'b1};
                default: ;
            endcase

            if (rd_consumes_slot1_w) begin
                skip_valid_q <= 1'b1;
                skip_pc_q <= rd_pc1_o;
                skip_epoch_q <= rd_epoch_o;
            end else if ((stored_head_skip_w && do_rd) || wr_skip_w ||
                         rd_misses_pending_skip_w || !skip_epoch_match_w) begin
                skip_valid_q <= 1'b0;
                skip_pc_q <= {XLEN{1'b0}};
                skip_epoch_q <= {EPOCH_WIDTH{1'b0}};
            end
        end
    end

    // ---- 读出（组合）。空 FIFO 时允许同拍直通，减少断续供给时的启动空泡。----
    assign rd_pc_o          = empty ? wr_pc_i          : buf_pc         [rd_ptr_q];
    assign rd_pc1_o         = empty ? wr_pc1_i         : buf_pc1        [rd_ptr_q];
    assign rd_instr_o       = empty ? wr_instr_i       : buf_instr      [rd_ptr_q];
    assign rd_slot0_valid_o = empty ? wr_slot0_valid_i : buf_slot0_valid[rd_ptr_q];
    assign rd_instr1_o      = empty ? wr_instr1_i      : buf_instr1     [rd_ptr_q];
    assign rd_slot1_valid_o = empty ? wr_slot1_valid_i : buf_slot1_valid[rd_ptr_q];
    assign rd_epoch_o       = empty ? wr_epoch_i       : buf_epoch      [rd_ptr_q];
    assign rd_pred_taken_o  = empty ? wr_pred_taken_i  : buf_pred_taken [rd_ptr_q];
    assign rd_pred_target_o = empty ? wr_pred_target_i : buf_pred_target[rd_ptr_q];
    assign rd_ras_valid_o   = empty ? wr_ras_valid_i   : buf_ras_valid  [rd_ptr_q];
    assign rd_ras_target_o  = empty ? wr_ras_target_i  : buf_ras_target [rd_ptr_q];
    assign rd_fault_o       = empty ? wr_fault_i       : buf_fault      [rd_ptr_q];
    assign rd_fault_ecode_o = empty ? wr_fault_ecode_i : buf_fault_ecode[rd_ptr_q];
    assign rd_fault_badv_o  = empty ? wr_fault_badv_i  : buf_fault_badv [rd_ptr_q];

`ifdef VERILATOR
    always @(posedge clk) begin
        if (!rst_n || flush) begin
            `CPU_DEBUG($sformatf("[PIPE][FETCH_BUFFER][CLEAR] rst_n=%0d flush=%0d count=%0d", rst_n, flush, count_q));
        end else if (do_wr || do_rd || do_bypass || full || empty) begin
            `CPU_DEBUG($sformatf(
                "[PIPE][FETCH_BUFFER] fifo do_wr=%0d bypass=%0d wr_pc=0x%08x wr_instr=0x%08x do_rd=%0d rd_pc=0x%08x rd_instr=0x%08x count=%0d full=%0d empty=%0d wr_ptr=%0d rd_ptr=%0d",
                do_wr, do_bypass, wr_pc_i, wr_instr_i, do_rd, rd_pc_o, rd_instr_o,
                count_q, full, empty, wr_ptr_q, rd_ptr_q
            ));
        end
    end
`endif

    `CPU_DEBUG_MODULE("fetch_buffer")
endmodule
