`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ============================================================================
// L2 Cache — 参数化组相联统一二级缓存
//            统一服务 L1 ICache 和 L1 DCache 的 miss
//
// 默认参数是 8-way / 4096 line / 32B line；当前 core 实例化为
// 4-way / 1024 line / 32B line，用于控制 BRAM 消耗。
//
// 接口：
//   L1I  侧：rd 请求（miss/prefetch） → 整行数据返回
//   L1D  侧：rd 请求（load miss）+ wr 请求（store write-through）
//   AXI  侧：L2 miss 时发 AXI 读；L1D store 穿透写 AXI
//
// 仲裁：
//   优先级：L1D rd > L1I rd > prefetch（L1I 预取）
//   store write-through 独立通道，不阻塞 rd
//
// 预取：
//   L1 miss 服务完后，若下一行（addr + L2_LINE_SIZE）不在 L2，
//   自动后台填 L2（不返回给 L1，只填 L2）
//
// BRAM：当前代码直接例化 RAMB36E1，tag/data 按 way 和 word offset 拆分。
// ============================================================================
module cpu_l2_cache #(
    parameter XLEN       = 32,
    parameter NUM_WAYS   = 8,
    parameter NUM_LINES  = 4096,
    parameter LINE_SIZE  = 32,     // 字节，8 word
    // L1 行大小（用于确定填 L1 返回多少 word）
    parameter L1_LINE_SIZE = 16,   // 4 word
    parameter AXI_ID     = 4'hF,
    parameter ENABLE_PREFETCH = 1  // 后台 next-line 预取；可在实验中关闭
) (
    input  wire            clk,
    input  wire            rst_n,

    // ---- L1I 读接口 ----
    input  wire            l1i_req_valid_i,
    input  wire [XLEN-1:0] l1i_req_addr_i,
    input  wire            l1i_req_is_prefetch_i,
    output wire            l1i_req_ready_o,
    output reg             l1i_resp_valid_o,
    output reg  [XLEN-1:0] l1i_resp_data_o_0,
    output reg  [XLEN-1:0] l1i_resp_data_o_1,
    output reg  [XLEN-1:0] l1i_resp_data_o_2,
    output reg  [XLEN-1:0] l1i_resp_data_o_3,
    output reg             l1i_pf_resp_valid_o,
    output reg  [XLEN-1:0] l1i_pf_resp_addr_o,
    output reg  [XLEN-1:0] l1i_pf_resp_data_o_0,
    output reg  [XLEN-1:0] l1i_pf_resp_data_o_1,
    output reg  [XLEN-1:0] l1i_pf_resp_data_o_2,
    output reg  [XLEN-1:0] l1i_pf_resp_data_o_3,

    // ---- L1D 读接口 ----
    input  wire            l1d_rd_valid_i,
    input  wire [XLEN-1:0] l1d_rd_addr_i,
    input  wire [1:0]      l1d_rd_size_i,
    input  wire            l1d_rd_uncached_i,
    output wire            l1d_rd_ready_o,
    output reg             l1d_resp_valid_o,
    output reg  [XLEN-1:0] l1d_resp_data_o_0,
    output reg  [XLEN-1:0] l1d_resp_data_o_1,
    output reg  [XLEN-1:0] l1d_resp_data_o_2,
    output reg  [XLEN-1:0] l1d_resp_data_o_3,

    // ---- L1D 写接口（store write-through，穿透写到 AXI） ----
    input  wire            l1d_wr_valid_i,
    input  wire [XLEN-1:0] l1d_wr_addr_i,
    input  wire [XLEN-1:0] l1d_wr_data_i,
    input  wire [3:0]      l1d_wr_strb_i,
    output reg             l1d_wr_ready_o,
    output reg             l1d_wr_done_o,

    // ---- AXI 读接口 ----
    output reg             axi_arvalid_o,
    input  wire            axi_arready_i,
    output reg  [XLEN-1:0] axi_araddr_o,
    output wire [3:0]      axi_arid_o,
    output wire [7:0]      axi_arlen_o,
    output wire [2:0]      axi_arsize_o,
    output wire [1:0]      axi_arburst_o,
    input  wire            axi_rvalid_i,
    output wire            axi_rready_o,
    input  wire [XLEN-1:0] axi_rdata_i,
    input  wire [1:0]      axi_rresp_i,
    input  wire [3:0]      axi_rid_i,
    input  wire            axi_rlast_i,

    // ---- AXI 写接口（store write-through） ----
    output reg             axi_awvalid_o,
    input  wire            axi_awready_i,
    output reg  [XLEN-1:0] axi_awaddr_o,
    output wire [3:0]      axi_awid_o,
    output wire [7:0]      axi_awlen_o,
    output wire [2:0]      axi_awsize_o,
    output wire [1:0]      axi_awburst_o,
    output reg             axi_wvalid_o,
    input  wire            axi_wready_i,
    output reg  [XLEN-1:0] axi_wdata_o,
    output reg  [3:0]      axi_wstrb_o,
    output wire            axi_wlast_o,
    input  wire            axi_bvalid_i,
    output wire            axi_bready_o,
    input  wire [1:0]      axi_bresp_i,
    input  wire [3:0]      axi_bid_i
);

    localparam INDEX_WIDTH    = $clog2(NUM_LINES);                  // 12
    localparam OFFSET_WIDTH   = $clog2(LINE_SIZE);                  // 5
    localparam TAG_WIDTH      = XLEN - INDEX_WIDTH - OFFSET_WIDTH;  // 15
    localparam WORDS_PER_LINE = LINE_SIZE / 4;                      // 8
    localparam L1_WORDS       = L1_LINE_SIZE / 4;                   // 4
    localparam L1_OFFSET_WIDTH = $clog2(L1_LINE_SIZE);              // 4
    localparam L1_WORD_OFF_WIDTH = $clog2(L1_WORDS);                // 2
    localparam WAY_WIDTH      = $clog2(NUM_WAYS);                   // 3
    localparam DATA_ADDR_W    = INDEX_WIDTH + $clog2(WORDS_PER_LINE); // 15

    function [2:0] mem_size_to_axi_size;
        input [1:0] size;
        case (size)
            2'b00: mem_size_to_axi_size = 3'b000; // byte
            2'b01: mem_size_to_axi_size = 3'b001; // half word
            default: mem_size_to_axi_size = 3'b010; // word / cache line beat
        endcase
    endfunction

    function [2:0] wstrb_to_axi_size;
        input [3:0] strb;
        case (strb)
            4'b0001, 4'b0010, 4'b0100, 4'b1000:
                wstrb_to_axi_size = 3'b000;
            4'b0011, 4'b1100:
                wstrb_to_axi_size = 3'b001;
            default:
                wstrb_to_axi_size = 3'b010;
        endcase
    endfunction

    // -------------------------------------------------------------------------
    // 状态机（读路径）
    // -------------------------------------------------------------------------
    localparam ST_IDLE      = 3'd0;
    localparam ST_LOOKUP    = 3'd1;   // 发起 BRAM 读
    localparam ST_REFILL    = 3'd2;   // AXI 读，填 L2
    localparam ST_RESPOND   = 3'd3;   // 返回数据给 L1（refill 后）
    localparam ST_PREFETCH  = 3'd4;   // 后台预取
    localparam ST_HIT_RESP  = 3'd5;   // hit 后延一拍输出（消除 way_hit 高扇出）
    localparam ST_LOOKUP_WAIT = 3'd6; // 等待 req_addr_q 对应的 BRAM 输出有效

    reg [2:0]  rd_state_q;

    // 当前服务的请求
    reg [31:0] req_addr_q;
    reg        req_is_prefetch_q;  // 是否为 L1I 预取请求
    reg        req_no_resp_q;      // L2 内部后台预取：只填 L2，不返回 L1
    reg        req_src_q;          // 0=L1I, 1=L1D
    reg [1:0]  req_size_q;         // L1D uncache 读的访问宽度
    reg        req_uncached_q;     // L1D uncache 读：单拍 AXI，不填 L2/L1 line
    reg [WAY_WIDTH-1:0] replace_way_q;
    reg [2:0]  refill_cnt_q;
    reg        refill_resp_sent_q; // refill 期间是否已经向 L1 提前返回关键 4 word
    reg        refill_killed_by_store_q;

    // hit 时寄存的 way_hit（4bit，T2 打一拍后 fo 极低）
    reg [NUM_WAYS-1:0] hit_way_q;   // 寄存 way_hit，ST_HIT_RESP 拍使用
    reg                hit_src_q;   // 寄存 req_src_q
    reg                hit_is_pf_q; // 寄存 req_no_resp_q
    reg                hit_buddy_valid_q;
    reg [31:0]         hit_buddy_addr_q;

    // widx_q[ki]：对应 hit_word[ki] 在 L2 line 内的 word 索引，ST_LOOKUP 时寄存。
    // 每个 ki 独立一份 3bit 寄存器，各自只驱动 1 个 32bit MUX（fo=32/份），
    // 替代共享 l1_base_off（fo=384）的方案，把布线延迟从 6ns 降到 <1ns。
    reg [2:0] widx_q [0:L1_WORDS-1];

    // 预取目标
    reg [31:0] pf_addr_q;          // 下一行预取地址
    reg        pf_pending_q;       // 有待发起的预取
    reg        pf_pending_l1i_q;   // 后台预取是否由 L1I 顺序流触发
    reg        req_bgpf_to_l1i_q;  // 当前后台预取完成后是否可旁路给 ICache
    reg        bgpf_probe_lookup_q;
    reg        bgpf_probe_resp_q;
    reg [31:0] bgpf_probe_addr_q;
    reg [NUM_WAYS-1:0] bgpf_probe_way_q;
    reg [2:0]  bgpf_probe_base_off_q;
    reg        bgpf_miss_pending_q;
    reg [31:0] bgpf_miss_addr_q;

    // -------------------------------------------------------------------------
    // 地址解析
    // -------------------------------------------------------------------------
    wire [TAG_WIDTH-1:0]   req_tag    = req_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] req_idx    = req_addr_q[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [2:0]             req_w_off  = req_addr_q[OFFSET_WIDTH-1 : 2];  // L2 内 word offset

    // 返回给 L1 的 word 偏移（L1 行对齐，L1_WORDS 个连续 word）
    wire [2:0] l1_base_off =
        {req_addr_q[OFFSET_WIDTH-1 : L1_OFFSET_WIDTH], {L1_WORD_OFF_WIDTH{1'b0}}};
    wire [2:0] l1d_req_base_off =
        {l1d_rd_addr_i[OFFSET_WIDTH-1 : L1_OFFSET_WIDTH], {L1_WORD_OFF_WIDTH{1'b0}}};
    wire [2:0] l1i_req_base_off =
        {l1i_req_addr_i[OFFSET_WIDTH-1 : L1_OFFSET_WIDTH], {L1_WORD_OFF_WIDTH{1'b0}}};

    wire [TAG_WIDTH-1:0]   pf_tag  = pf_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] pf_idx  = pf_addr_q[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire pf_pending_same_wr_line_w =
        (wr_pending_w &&
         (pf_addr_q[XLEN-1:OFFSET_WIDTH] ==
          axi_awaddr_o[XLEN-1:OFFSET_WIDTH])) ||
        (l1d_wr_valid_i &&
         (pf_addr_q[XLEN-1:OFFSET_WIDTH] ==
          l1d_wr_addr_i[XLEN-1:OFFSET_WIDTH]));

    wire idle_l1d_accept_w = (rd_state_q == ST_IDLE) &&
                              l1d_rd_valid_i && l1d_rd_ready_o;
    wire idle_l1i_accept_w = (rd_state_q == ST_IDLE) &&
                              !l1d_rd_valid_i &&
                              l1i_req_valid_i && l1i_req_ready_o;
    wire bgpf_l1i_probe_accept_w =
        (rd_state_q == ST_REFILL) && req_no_resp_q && !refill_killed_w &&
        l1i_req_valid_i && !l1i_req_is_prefetch_i && !l1d_rd_valid_i &&
        (wr_st == WR_IDLE) && !l1d_wr_valid_i &&
        !bgpf_probe_lookup_q && !bgpf_probe_resp_q && !bgpf_miss_pending_q &&
        (l1i_req_addr_i[XLEN-1:OFFSET_WIDTH] != req_addr_q[XLEN-1:OFFSET_WIDTH]) &&
        (l1i_req_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1:OFFSET_WIDTH] != req_idx);
    wire idle_pf_accept_w  = ENABLE_PREFETCH &&
                              (rd_state_q == ST_IDLE) &&
                              !l1d_rd_valid_i && !l1i_req_valid_i &&
                              pf_pending_q && !pf_pending_same_wr_line_w;
    wire [XLEN-1:0] rd_lookup_addr_w =
        bgpf_l1i_probe_accept_w ? l1i_req_addr_i :
        idle_l1d_accept_w ? l1d_rd_addr_i :
        idle_l1i_accept_w ? l1i_req_addr_i :
        idle_pf_accept_w  ? pf_addr_q : req_addr_q;
    wire [INDEX_WIDTH-1:0] rd_lookup_idx_w =
        rd_lookup_addr_w[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];

    // -------------------------------------------------------------------------
    // 存储阵列
    // 每个 way：
    //   data_ram：WORDS_PER_LINE 个 RAMB36E1，每个 word offset 一片
    //   tag_ram ：1 个 RAMB36E1，存 valid + tag
    // 当前 core 配置 NUM_WAYS=4、WORDS_PER_LINE=8，因此共 4×(8+1)=36 个 RAMB36E1。
    // -------------------------------------------------------------------------

    // 读地址（T0 送入 BRAM，T1 输出有效，对应 ST_LOOKUP 判断）
    // 地址组织：8 个 BRAM 各存所有 cache line 同一 word 位置
    //   BRAM n 存 word_offset==n 的所有 cache line 数据
    //   读地址 = req_idx（行索引），选片 = word_offset
    wire [9:0]  data_rd_bram_addr  = rd_lookup_idx_w;                     // BRAM 内地址
    wire [2:0]  data_rd_word_sel   = req_addr_q[OFFSET_WIDTH-1:2];        // word offset，选 BRAM 片（读）
    wire [9:0]  tag_rd_bram_addr   = rd_lookup_idx_w;

    // 写地址（refill 时：行地址=req_idx，word=refill_cnt_q）
    // BRAM 选片 = refill_cnt_q（当前正在写第几个 word），内地址 = req_idx
    wire [9:0]  data_wr_bram_addr_w = req_idx;
    wire [2:0]  data_wr_word_sel_w  = refill_cnt_q;
    wire [9:0]  tag_wr_bram_addr_w  = req_idx;

    // =========================================================================
    // FPGA 原语实现
    // =========================================================================
    // data_ram：每路 8 个 RAMB36E1，地址高 3bit 选片，读 MUX 后输出
    // tag_ram ：每路 1 个 RAMB36E1

    // 每路的 8 个 BRAM 读输出（选片后使用）
    wire [31:0] data_bram_rd [0:NUM_WAYS-1][0:7];  // [way][bram_sel]
    wire [31:0] tag_bram_rd  [0:NUM_WAYS-1];

    // 读地址：15bit（低5bit=0，RAMB36E1 SDP x32 格式）
    wire [14:0] bram_rd_addr_data = {data_rd_bram_addr, 5'b00000};
    wire [14:0] bram_rd_addr_tag  = {tag_rd_bram_addr,  5'b00000};
    // 写地址：由状态机控制信号驱动
    wire [14:0] bram_wr_addr_data_w = {data_wr_bram_addr_w, 5'b00000};
    wire [14:0] bram_wr_addr_tag_w  = {tag_wr_bram_addr_w,  5'b00000};

    genvar gw, gb;
    generate
        for (gw = 0; gw < NUM_WAYS; gw = gw + 1) begin : gen_way_bram

            // ---- tag_ram：每路 1 个 RAMB36E1，DOA_REG=0（1拍延迟，与 ST_LOOKUP 等1拍匹配）----
            // store write-through 后失效对应 index 的所有 way，避免后续 D miss 命中 L2 旧数据。
            wire tag_refill_we_w = bram_tag_we && (replace_way_q == gw[WAY_WIDTH-1:0]);
            wire tag_inv_we_w    = inv_do_w;
            wire tag_we_w        = tag_refill_we_w || tag_inv_we_w;
            wire [14:0] tag_wr_addr_w =
                tag_inv_we_w ? {inv_idx_q, 5'b00000} : bram_wr_addr_tag_w;
            wire [31:0] tag_wr_data_w =
                tag_inv_we_w ? 32'h0 : {{(32-(TAG_WIDTH+1)){1'b0}}, bram_tag_wdata};
            RAMB36E1 #(
                .RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36),
                .DOA_REG(0), .INIT_FILE("NONE"), .SIM_COLLISION_CHECK("NONE"),
                .WRITE_MODE_A("READ_FIRST"), .WRITE_MODE_B("READ_FIRST")
            ) u_tag (
                .CLKARDCLK(clk), .ENARDEN(1'b1),
                .RSTRAMARSTRAM(1'b0), .RSTREGARSTREG(1'b0), .REGCEAREGCE(1'b1),
                .WEA(4'h0), .ADDRARDADDR(bram_rd_addr_tag),
                .DIADI(32'h0), .DIPADIP(4'h0),
                .DOADO(tag_bram_rd[gw]), .DOBDO(), .DOPADOP(), .DOPBDOP(),
                .CLKBWRCLK(clk), .ENBWREN(1'b1),
                .WEBWE({4'b0, {4{tag_we_w}}}), .ADDRBWRADDR(tag_wr_addr_w),
                .DIBDI(tag_wr_data_w), .DIPBDIP(4'h0),
                .CASCADEINA(1'b0), .CASCADEINB(1'b0),
                .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0)
            );

            // ---- data_ram：每路 8 个 RAMB36E1，各存一个 word offset 的所有 cache line ----
            for (gb = 0; gb < 8; gb = gb + 1) begin : gen_data_bram
                // 写使能：当前正在 refill 且 refill_cnt_q == gb 时写入该 BRAM
                wire data_we_w = bram_data_we &&
                                 (replace_way_q == gw[WAY_WIDTH-1:0]) &&
                                 (data_wr_word_sel_w == gb[2:0]);
                RAMB36E1 #(
                    .RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36),
                    .DOA_REG(1), .INIT_FILE("NONE"), .SIM_COLLISION_CHECK("NONE"),
                    .WRITE_MODE_A("READ_FIRST"), .WRITE_MODE_B("READ_FIRST")
                ) u_data (
                    .CLKARDCLK(clk), .ENARDEN(1'b1),
                    .RSTRAMARSTRAM(1'b0), .RSTREGARSTREG(1'b0), .REGCEAREGCE(1'b1),
                    .WEA(4'h0), .ADDRARDADDR(bram_rd_addr_data),
                    .DIADI(32'h0), .DIPADIP(4'h0),
                    .DOADO(data_bram_rd[gw][gb]), .DOBDO(), .DOPADOP(), .DOPBDOP(),
                    .CLKBWRCLK(clk), .ENBWREN(1'b1),
                    .WEBWE({4'b0, {4{data_we_w}}}), .ADDRBWRADDR(bram_wr_addr_data_w),
                    .DIBDI(bram_data_wdata), .DIPBDIP(4'h0),
                    .CASCADEINA(1'b0), .CASCADEINB(1'b0),
                    .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0)
                );
            end
        end
    endgenerate

    // 读选择寄存器（T0 送地址，T1 BRAM 输出有效；同时锁存 word_sel 供命中数据选择）
    reg [2:0]  data_rd_sel_r;
    always @(posedge clk) data_rd_sel_r <= data_rd_word_sel;

    wire [NUM_WAYS-1:0] way_hit;
    wire [31:0] way_data_fpga [0:NUM_WAYS-1];
    genvar gw2;
    generate
        for (gw2 = 0; gw2 < NUM_WAYS; gw2 = gw2 + 1) begin : gen_hit_fpga
            assign way_hit[gw2] = tag_bram_rd[gw2][TAG_WIDTH] &&
                                   (tag_bram_rd[gw2][TAG_WIDTH-1:0] == req_tag);
        end
    endgenerate

    wire cache_hit = |way_hit;

    // hit_word：用 widx_q[ki]（各自独立寄存，fo=32/份）做 MUX，消除 l1_base_off 高扇出
    wire [31:0] hit_word [0:L1_WORDS-1];
    genvar ki;
    generate
        for (ki = 0; ki < L1_WORDS; ki = ki + 1) begin : gen_hit_word_fpga
            assign hit_word[ki] =
                hit_way_q[0] ? data_bram_rd[0][widx_q[ki]] :
                hit_way_q[1] ? data_bram_rd[1][widx_q[ki]] :
                hit_way_q[2] ? data_bram_rd[2][widx_q[ki]] : data_bram_rd[3][widx_q[ki]];
        end
    endgenerate

    wire [31:0] hit_buddy_word0 =
        hit_way_q[0] ? data_bram_rd[0][4] :
        hit_way_q[1] ? data_bram_rd[1][4] :
        hit_way_q[2] ? data_bram_rd[2][4] : data_bram_rd[3][4];
    wire [31:0] hit_buddy_word1 =
        hit_way_q[0] ? data_bram_rd[0][5] :
        hit_way_q[1] ? data_bram_rd[1][5] :
        hit_way_q[2] ? data_bram_rd[2][5] : data_bram_rd[3][5];
    wire [31:0] hit_buddy_word2 =
        hit_way_q[0] ? data_bram_rd[0][6] :
        hit_way_q[1] ? data_bram_rd[1][6] :
        hit_way_q[2] ? data_bram_rd[2][6] : data_bram_rd[3][6];
    wire [31:0] hit_buddy_word3 =
        hit_way_q[0] ? data_bram_rd[0][7] :
        hit_way_q[1] ? data_bram_rd[1][7] :
        hit_way_q[2] ? data_bram_rd[2][7] : data_bram_rd[3][7];

    // 预取命中检测（基于同步读出的 tag）
    wire pf_cache_hit =
        (tag_bram_rd[0][TAG_WIDTH] && tag_bram_rd[0][TAG_WIDTH-1:0] == pf_tag) ||
        (tag_bram_rd[1][TAG_WIDTH] && tag_bram_rd[1][TAG_WIDTH-1:0] == pf_tag) ||
        (tag_bram_rd[2][TAG_WIDTH] && tag_bram_rd[2][TAG_WIDTH-1:0] == pf_tag) ||
        (tag_bram_rd[3][TAG_WIDTH] && tag_bram_rd[3][TAG_WIDTH-1:0] == pf_tag);

    wire l1d_wr_accept_w = l1d_wr_valid_i && l1d_wr_ready_o;
    wire wr_pending_w = (wr_st != WR_IDLE);
    wire wr_pending_same_l1d_line_w =
        (wr_pending_w && !l1d_rd_uncached_i &&
         (l1d_rd_addr_i[XLEN-1:OFFSET_WIDTH] ==
          axi_awaddr_o[XLEN-1:OFFSET_WIDTH])) ||
        (l1d_wr_valid_i && !l1d_rd_uncached_i &&
         (l1d_rd_addr_i[XLEN-1:OFFSET_WIDTH] ==
          l1d_wr_addr_i[XLEN-1:OFFSET_WIDTH]));
    wire wr_pending_same_l1i_line_w =
        (wr_pending_w &&
         (l1i_req_addr_i[XLEN-1:OFFSET_WIDTH] ==
          axi_awaddr_o[XLEN-1:OFFSET_WIDTH])) ||
        (l1d_wr_valid_i &&
         (l1i_req_addr_i[XLEN-1:OFFSET_WIDTH] ==
          l1d_wr_addr_i[XLEN-1:OFFSET_WIDTH]));
    wire refill_store_kill_w =
        (rd_state_q == ST_REFILL) &&
        !req_uncached_q &&
        ((wr_pending_w &&
          (axi_awaddr_o[XLEN-1:OFFSET_WIDTH] == req_addr_q[XLEN-1:OFFSET_WIDTH])) ||
         (l1d_wr_valid_i &&
          (l1d_wr_addr_i[XLEN-1:OFFSET_WIDTH] == req_addr_q[XLEN-1:OFFSET_WIDTH])));
    wire refill_killed_w = refill_killed_by_store_q || refill_store_kill_w;

    // BRAM 写控制信号直接由当前 AXI beat 产生，避免 refill 数据和地址错一拍。
    wire                  bram_data_we    = (rd_state_q == ST_REFILL) && axi_rvalid_i && !req_uncached_q;
    wire [31:0]           bram_data_wdata = axi_rdata_i;
    wire                  bram_tag_we     = bram_data_we && axi_rlast_i && !refill_killed_w;
    wire [TAG_WIDTH:0]    bram_tag_wdata  = {1'b1, req_tag};


    // -------------------------------------------------------------------------
    // 命中判断和数据选择
    // FPGA 路径：way_hit/hit_word/pf_cache_hit 已在存储块里定义
    // 仿真：3D array 组合读
    // -------------------------------------------------------------------------


    // refill 时填入的数据缓存（8 word）
    reg [31:0] refill_buf [0:WORDS_PER_LINE-1];

    wire [2:0] refill_resp_last_idx = l1_base_off + 3'd3;
    wire       refill_need_resp_w = (rd_state_q == ST_REFILL) &&
                                    axi_rvalid_i &&
                                    !req_no_resp_q &&
                                    !refill_resp_sent_q &&
                                    (refill_cnt_q == refill_resp_last_idx);
    wire [31:0] refill_resp_word0 =
        (refill_cnt_q == (l1_base_off + 3'd0)) ? axi_rdata_i : refill_buf[l1_base_off + 3'd0];
    wire [31:0] refill_resp_word1 =
        (refill_cnt_q == (l1_base_off + 3'd1)) ? axi_rdata_i : refill_buf[l1_base_off + 3'd1];
    wire [31:0] refill_resp_word2 =
        (refill_cnt_q == (l1_base_off + 3'd2)) ? axi_rdata_i : refill_buf[l1_base_off + 3'd2];
    wire [31:0] refill_resp_word3 =
        (refill_cnt_q == (l1_base_off + 3'd3)) ? axi_rdata_i : refill_buf[l1_base_off + 3'd3];

    wire       refill_prefetch_w = (rd_state_q == ST_REFILL) && req_no_resp_q;
    wire       l1d_same_refill_line_w =
        l1d_rd_valid_i && !l1d_rd_uncached_i &&
        (l1d_rd_addr_i[XLEN-1:OFFSET_WIDTH] == req_addr_q[XLEN-1:OFFSET_WIDTH]);
    wire       l1i_same_refill_line_w =
        l1i_req_valid_i && !l1i_req_is_prefetch_i &&
        (l1i_req_addr_i[XLEN-1:OFFSET_WIDTH] == req_addr_q[XLEN-1:OFFSET_WIDTH]);
    wire       l1d_critical_beat_now_w =
        axi_rvalid_i && (refill_cnt_q == (l1d_req_base_off + 3'd3));
    wire       l1i_critical_beat_now_w =
        axi_rvalid_i && (refill_cnt_q == (l1i_req_base_off + 3'd3));
    wire       l1d_promote_have_line_w = refill_cnt_q > (l1d_req_base_off + 3'd3);
    wire       l1i_promote_have_line_w = refill_cnt_q > (l1i_req_base_off + 3'd3);
    wire       l1d_prefetch_promote_w =
        refill_prefetch_w && !refill_killed_w &&
        l1d_same_refill_line_w && !l1d_critical_beat_now_w;
    wire       l1i_prefetch_promote_w =
        refill_prefetch_w && !refill_killed_w && !l1d_prefetch_promote_w &&
        l1i_same_refill_line_w && !l1i_critical_beat_now_w;
    wire [TAG_WIDTH-1:0] bgpf_probe_tag =
        bgpf_probe_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [2:0] bgpf_probe_base_off =
        {bgpf_probe_addr_q[OFFSET_WIDTH-1 : L1_OFFSET_WIDTH],
         {L1_WORD_OFF_WIDTH{1'b0}}};
    wire [NUM_WAYS-1:0] bgpf_probe_way_hit;
    assign bgpf_probe_way_hit[0] = tag_bram_rd[0][TAG_WIDTH] &&
                                   (tag_bram_rd[0][TAG_WIDTH-1:0] == bgpf_probe_tag);
    assign bgpf_probe_way_hit[1] = tag_bram_rd[1][TAG_WIDTH] &&
                                   (tag_bram_rd[1][TAG_WIDTH-1:0] == bgpf_probe_tag);
    assign bgpf_probe_way_hit[2] = tag_bram_rd[2][TAG_WIDTH] &&
                                   (tag_bram_rd[2][TAG_WIDTH-1:0] == bgpf_probe_tag);
    assign bgpf_probe_way_hit[3] = tag_bram_rd[3][TAG_WIDTH] &&
                                   (tag_bram_rd[3][TAG_WIDTH-1:0] == bgpf_probe_tag);
    wire bgpf_probe_hit_w = |bgpf_probe_way_hit;
    wire [31:0] bgpf_probe_word0 =
        bgpf_probe_way_q[0] ? data_bram_rd[0][bgpf_probe_base_off_q + 3'd0] :
        bgpf_probe_way_q[1] ? data_bram_rd[1][bgpf_probe_base_off_q + 3'd0] :
        bgpf_probe_way_q[2] ? data_bram_rd[2][bgpf_probe_base_off_q + 3'd0] :
                              data_bram_rd[3][bgpf_probe_base_off_q + 3'd0];
    wire [31:0] bgpf_probe_word1 =
        bgpf_probe_way_q[0] ? data_bram_rd[0][bgpf_probe_base_off_q + 3'd1] :
        bgpf_probe_way_q[1] ? data_bram_rd[1][bgpf_probe_base_off_q + 3'd1] :
        bgpf_probe_way_q[2] ? data_bram_rd[2][bgpf_probe_base_off_q + 3'd1] :
                              data_bram_rd[3][bgpf_probe_base_off_q + 3'd1];
    wire [31:0] bgpf_probe_word2 =
        bgpf_probe_way_q[0] ? data_bram_rd[0][bgpf_probe_base_off_q + 3'd2] :
        bgpf_probe_way_q[1] ? data_bram_rd[1][bgpf_probe_base_off_q + 3'd2] :
        bgpf_probe_way_q[2] ? data_bram_rd[2][bgpf_probe_base_off_q + 3'd2] :
                              data_bram_rd[3][bgpf_probe_base_off_q + 3'd2];
    wire [31:0] bgpf_probe_word3 =
        bgpf_probe_way_q[0] ? data_bram_rd[0][bgpf_probe_base_off_q + 3'd3] :
        bgpf_probe_way_q[1] ? data_bram_rd[1][bgpf_probe_base_off_q + 3'd3] :
        bgpf_probe_way_q[2] ? data_bram_rd[2][bgpf_probe_base_off_q + 3'd3] :
                              data_bram_rd[3][bgpf_probe_base_off_q + 3'd3];
    wire [31:0] promote_addr_w =
        l1d_prefetch_promote_w ? l1d_rd_addr_i : l1i_req_addr_i;
    wire [31:0] l1d_promote_word0 = refill_buf[l1d_req_base_off + 3'd0];
    wire [31:0] l1d_promote_word1 = refill_buf[l1d_req_base_off + 3'd1];
    wire [31:0] l1d_promote_word2 = refill_buf[l1d_req_base_off + 3'd2];
    wire [31:0] l1d_promote_word3 = refill_buf[l1d_req_base_off + 3'd3];
    wire [31:0] l1i_promote_word0 = refill_buf[l1i_req_base_off + 3'd0];
    wire [31:0] l1i_promote_word1 = refill_buf[l1i_req_base_off + 3'd1];
    wire [31:0] l1i_promote_word2 = refill_buf[l1i_req_base_off + 3'd2];
    wire [31:0] l1i_promote_word3 = refill_buf[l1i_req_base_off + 3'd3];
    wire [31:0] req_line_base_w =
        {req_addr_q[XLEN-1:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}};
    wire        l1i_lower_half_demand_w =
        !req_src_q && !req_no_resp_q && !req_is_prefetch_q &&
        (l1_base_off == 3'd0);
    wire        l1i_demand_active_w =
        !req_src_q && !req_no_resp_q && !req_is_prefetch_q;
    wire        refill_buddy_resp_w =
        (rd_state_q == ST_REFILL) && axi_rvalid_i && axi_rlast_i &&
        l1i_lower_half_demand_w && !refill_killed_w;
    wire        bgpf_l1i_lower_resp_w =
        (rd_state_q == ST_REFILL) && axi_rvalid_i &&
        req_no_resp_q && req_bgpf_to_l1i_q &&
        !refill_killed_w &&
        (refill_cnt_q == 3'd3);
    wire        bgpf_l1i_upper_resp_w =
        (rd_state_q == ST_REFILL) && axi_rvalid_i &&
        req_no_resp_q && req_bgpf_to_l1i_q &&
        !refill_killed_w &&
        axi_rlast_i;
    wire        bgpf_l1i_resp_w =
        bgpf_l1i_lower_resp_w || bgpf_l1i_upper_resp_w;
    wire [31:0] bgpf_resp_word3 =
        (refill_cnt_q == 3'd3) ? axi_rdata_i : refill_buf[3'd3];

    // -------------------------------------------------------------------------
    // AXI 固定输出
    // -------------------------------------------------------------------------
    assign axi_arid_o    = AXI_ID;
    assign axi_arlen_o   = req_uncached_q ? 8'h0 : (WORDS_PER_LINE - 1);  // 8 beat or single uncache
    assign axi_arsize_o  = req_uncached_q ? mem_size_to_axi_size(req_size_q) : 3'b010;
    assign axi_arburst_o = 2'b01;
    assign axi_rready_o  = 1'b1;
    assign axi_awid_o    = AXI_ID;
    assign axi_awlen_o   = 8'h0;                // 单 beat write
    assign axi_awsize_o  = axi_awsize_q;
    assign axi_awburst_o = 2'b01;
    assign axi_wlast_o   = 1'b1;
    assign axi_bready_o  = (wr_st != WR_IDLE);

    assign l1d_rd_ready_o  = ((rd_state_q == ST_IDLE) && !bgpf_miss_pending_q &&
                              !wr_pending_same_l1d_line_w) ||
                             l1d_prefetch_promote_w;
    assign l1i_req_ready_o = ((rd_state_q == ST_IDLE) && !bgpf_miss_pending_q &&
                              !l1d_rd_valid_i &&
                              !wr_pending_same_l1i_line_w) ||
                             l1i_prefetch_promote_w ||
                             bgpf_l1i_probe_accept_w;

    // -------------------------------------------------------------------------
    // 写状态机（store write-through，独立运行）
    // -------------------------------------------------------------------------
    reg [2:0] wr_state_q;
    localparam [2:0] WR_IDLE = 3'd0, WR_AW = 3'd1, WR_W = 3'd2, WR_B = 3'd3;
    reg [2:0] wr_st;
    reg [2:0] axi_awsize_q;

    always @(posedge clk) begin
        if (!rst_n) begin
            wr_st          <= WR_IDLE;
            axi_awvalid_o  <= 1'b0;
            axi_wvalid_o   <= 1'b0;
            axi_awsize_q    <= 3'b010;
            l1d_wr_ready_o <= 1'b1;
            l1d_wr_done_o  <= 1'b0;
        end else begin
            l1d_wr_done_o <= 1'b0;
            case (wr_st)
                WR_IDLE: begin
                    l1d_wr_ready_o <= 1'b1;
                    if (l1d_wr_accept_w) begin
                        axi_awvalid_o <= 1'b1;
                        axi_awaddr_o  <= l1d_wr_addr_i;
                        axi_awsize_q  <= wstrb_to_axi_size(l1d_wr_strb_i);
                        axi_wvalid_o  <= 1'b1;
                        axi_wdata_o   <= l1d_wr_data_i;
                        axi_wstrb_o   <= l1d_wr_strb_i;
                        l1d_wr_ready_o <= 1'b0;
                        wr_st <= WR_AW;
                    end
                end
                WR_AW: begin
                    if (axi_awvalid_o && axi_awready_i) axi_awvalid_o <= 1'b0;
                    if (axi_wvalid_o  && axi_wready_i)  axi_wvalid_o  <= 1'b0;
                    if (axi_bvalid_i) begin
                        axi_awvalid_o   <= 1'b0;
                        axi_wvalid_o    <= 1'b0;
                        l1d_wr_done_o   <= 1'b1;
                        l1d_wr_ready_o  <= 1'b1;
                        wr_st           <= WR_IDLE;
                    end else if ((!axi_awvalid_o || axi_awready_i) &&
                                 (!axi_wvalid_o  || axi_wready_i)) begin
                        wr_st <= WR_B;
                    end
                end
                WR_B: begin
                    if (axi_bvalid_i) begin
                        l1d_wr_done_o  <= 1'b1;
                        l1d_wr_ready_o <= 1'b1;
                        wr_st <= WR_IDLE;
                    end
                end
                default: wr_st <= WR_IDLE;
            endcase
        end
    end

    // L2 写通道是 write-through：store 一定写外部内存。
    // 为避免 L2 旧行覆盖新内存数据，接收 store 后失效对应 index 的所有 way；
    // 后续 load miss 会从外部内存重新 refill。
    wire l2_wr_hit;
    reg [INDEX_WIDTH-1:0] wr_idx_r;
    reg [TAG_WIDTH-1:0]   wr_tag_r;
    reg [2:0]             wr_word_off_r;
    reg [31:0]            wr_data_r;
    reg [3:0]             wr_strb_r;
    reg                   inv_pending_q;
    reg [INDEX_WIDTH-1:0] inv_idx_q;

    wire inv_do_w = inv_pending_q && !bram_tag_we;

    // 锁存写请求地址（用于 L2 内部更新）
    always @(posedge clk) begin
        if (!rst_n) begin
            inv_pending_q <= 1'b0;
            inv_idx_q     <= {INDEX_WIDTH{1'b0}};
        end else begin
            if (inv_do_w)
                inv_pending_q <= 1'b0;

            if (l1d_wr_accept_w) begin
                wr_idx_r      <= l1d_wr_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
                wr_tag_r      <= l1d_wr_addr_i[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
                wr_word_off_r <= l1d_wr_addr_i[OFFSET_WIDTH-1 : 2];
                wr_data_r     <= l1d_wr_data_i;
                wr_strb_r     <= l1d_wr_strb_i;
                inv_idx_q     <= l1d_wr_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
                inv_pending_q <= 1'b1;
            end
        end
    end

    // 早期版本尝试直接更新 L2 data_ram；当前 RAMB36E1 tag 读写时序下，
    // 更稳妥的做法是 index invalidation，所以以下地址计算只作为遗留占位。
    wire [14:0] wr_addr_w = ({5'b0, wr_idx_r} << $clog2(WORDS_PER_LINE)) + {12'b0, wr_word_off_r};

    // write-through 不直接更新 L2 data_ram；对应 index 被 invalid 后，
    // 下次 load miss 从 AXI 内存重新填入，保证 DCache 读到最新 store 结果。


    // -------------------------------------------------------------------------
    // 读状态机（服务 L1I/L1D miss 和预取）
    // -------------------------------------------------------------------------
    always @(posedge clk) begin
        if (!rst_n) begin
            rd_state_q     <= ST_IDLE;
            replace_way_q  <= {WAY_WIDTH{1'b0}};
            pf_pending_q   <= 1'b0;
            pf_pending_l1i_q <= 1'b0;
            pf_addr_q      <= 32'h0;
            req_bgpf_to_l1i_q <= 1'b0;
            bgpf_probe_lookup_q <= 1'b0;
            bgpf_probe_resp_q <= 1'b0;
            bgpf_probe_addr_q <= 32'h0;
            bgpf_probe_way_q <= {NUM_WAYS{1'b0}};
            bgpf_probe_base_off_q <= 3'd0;
            bgpf_miss_pending_q <= 1'b0;
            bgpf_miss_addr_q <= 32'h0;
            hit_way_q      <= {NUM_WAYS{1'b0}};
            hit_src_q      <= 1'b0;
            hit_is_pf_q    <= 1'b0;
            hit_buddy_valid_q <= 1'b0;
            hit_buddy_addr_q  <= 32'h0;
            req_no_resp_q  <= 1'b0;
            req_size_q     <= 2'b10;
            req_uncached_q <= 1'b0;
            refill_resp_sent_q <= 1'b0;
            refill_killed_by_store_q <= 1'b0;
            widx_q[0]      <= 3'b0;
            widx_q[1]      <= 3'b0;
            widx_q[2]      <= 3'b0;
            widx_q[3]      <= 3'b0;
            axi_arvalid_o  <= 1'b0;
            l1i_resp_valid_o <= 1'b0;
            l1i_pf_resp_valid_o <= 1'b0;
            l1i_pf_resp_addr_o  <= 32'h0;
            l1i_pf_resp_data_o_0 <= 32'h0;
            l1i_pf_resp_data_o_1 <= 32'h0;
            l1i_pf_resp_data_o_2 <= 32'h0;
            l1i_pf_resp_data_o_3 <= 32'h0;
            l1d_resp_valid_o <= 1'b0;
        end else begin
            l1i_resp_valid_o <= 1'b0;
            l1i_pf_resp_valid_o <= 1'b0;
            l1d_resp_valid_o <= 1'b0;

            if (bgpf_l1i_probe_accept_w) begin
                bgpf_probe_lookup_q <= 1'b1;
                bgpf_probe_addr_q <= l1i_req_addr_i;
            end else begin
                bgpf_probe_lookup_q <= 1'b0;
            end

            if (bgpf_probe_lookup_q) begin
                if (bgpf_probe_hit_w) begin
                    bgpf_probe_resp_q <= 1'b1;
                    bgpf_probe_way_q <= bgpf_probe_way_hit;
                    bgpf_probe_base_off_q <= bgpf_probe_base_off;
                end else begin
                    bgpf_probe_resp_q <= 1'b0;
                    bgpf_miss_pending_q <= 1'b1;
                    bgpf_miss_addr_q <= bgpf_probe_addr_q;
                end
            end else if (bgpf_probe_resp_q) begin
                bgpf_probe_resp_q <= 1'b0;
                l1i_resp_valid_o  <= 1'b1;
                l1i_resp_data_o_0 <= bgpf_probe_word0;
                l1i_resp_data_o_1 <= bgpf_probe_word1;
                l1i_resp_data_o_2 <= bgpf_probe_word2;
                l1i_resp_data_o_3 <= bgpf_probe_word3;
            end

            case (rd_state_q)

                ST_IDLE: begin
                    // 优先级：L1D rd > L1I rd（prefetch 最低）
                    if (bgpf_miss_pending_q) begin
                        req_addr_q        <= bgpf_miss_addr_q;
                        req_is_prefetch_q <= 1'b0;
                        req_no_resp_q      <= 1'b0;
                        req_src_q         <= 1'b0;
                        req_size_q        <= 2'b10;
                        req_uncached_q    <= 1'b0;
                        refill_resp_sent_q <= 1'b0;
                        bgpf_miss_pending_q <= 1'b0;
                        rd_state_q        <= ST_LOOKUP;
                    end else if (l1d_rd_valid_i && l1d_rd_ready_o) begin
                        req_addr_q        <= l1d_rd_addr_i;
                        req_is_prefetch_q <= 1'b0;
                        req_no_resp_q      <= 1'b0;
                        req_src_q         <= 1'b1;
                        req_size_q        <= l1d_rd_size_i;
                        req_uncached_q    <= l1d_rd_uncached_i;
                        if (l1d_rd_uncached_i) begin
                            axi_arvalid_o <= 1'b1;
                            axi_araddr_o  <= l1d_rd_addr_i;
                            refill_cnt_q  <= 3'h0;
                            refill_resp_sent_q <= 1'b0;
                            refill_killed_by_store_q <= 1'b0;
                            rd_state_q    <= ST_REFILL;
                        end else begin
                            rd_state_q    <= ST_LOOKUP_WAIT;
                        end
                    end else if (l1i_req_valid_i && l1i_req_ready_o) begin
                        req_addr_q        <= l1i_req_addr_i;
                        req_is_prefetch_q <= l1i_req_is_prefetch_i;
                        req_no_resp_q      <= 1'b0;
                        req_src_q         <= 1'b0;
                        req_size_q        <= 2'b10;
                        req_uncached_q    <= 1'b0;
                        rd_state_q        <= ST_LOOKUP_WAIT;
                    end else if (idle_pf_accept_w) begin
                        // 后台预取
                        req_addr_q        <= pf_addr_q;
                        req_is_prefetch_q <= 1'b1;
                        req_no_resp_q      <= 1'b1;
                        req_size_q         <= 2'b10;
                        req_uncached_q     <= 1'b0;
                        req_bgpf_to_l1i_q  <= pf_pending_l1i_q;
                        pf_pending_q      <= 1'b0;
                        pf_pending_l1i_q  <= 1'b0;
                        rd_state_q        <= ST_LOOKUP_WAIT;
                    end
                end

                ST_LOOKUP: begin
                    // 兼容兜底状态。正常路径在 ST_IDLE 接收请求的同一拍已把
                    // incoming addr 送入 BRAM，因此可直接进入 ST_LOOKUP_WAIT。
                    rd_state_q <= ST_LOOKUP_WAIT;
                end

                ST_LOOKUP_WAIT: begin
                    // 此时 tag/data BRAM 输出已对应 req_addr_q。
                    if (cache_hit) begin
                        // L2 命中：寄存 way_hit 和各 widx（消除高扇出），跳 ST_HIT_RESP 输出
                        hit_way_q    <= way_hit;
                        hit_src_q    <= req_src_q;
                        hit_is_pf_q  <= req_no_resp_q;
                        hit_buddy_valid_q <= l1i_lower_half_demand_w;
                        hit_buddy_addr_q  <= req_line_base_w + L1_LINE_SIZE;
                        // 每个 ki 独立寄存自己的 widx，各自 fo=32，不共享高扇出信号
                        widx_q[0]    <= l1_base_off + 3'd0;
                        widx_q[1]    <= l1_base_off + 3'd1;
                        widx_q[2]    <= l1_base_off + 3'd2;
                        widx_q[3]    <= l1_base_off + 3'd3;
                        if (ENABLE_PREFETCH && l1i_demand_active_w) begin
                            pf_addr_q    <= req_addr_q + LINE_SIZE;
                            pf_pending_q <= 1'b1;
                            pf_pending_l1i_q <= 1'b1;
                        end
                        rd_state_q   <= ST_HIT_RESP;
                    end else begin
                        // L2 miss：发 AXI 请求，拉取整行
                        axi_arvalid_o <= 1'b1;
                        axi_araddr_o  <= {req_addr_q[31:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}};
                        refill_cnt_q  <= 3'h0;
                        refill_resp_sent_q <= 1'b0;
                        refill_killed_by_store_q <= 1'b0;
                        rd_state_q    <= ST_REFILL;
                    end
                end

                ST_HIT_RESP: begin
                    // hit_way_q 已寄存（fo 极低），用它做 MUX 输出响应
                    if (!hit_is_pf_q) begin
                        if (!hit_src_q) begin  // L1I
                            l1i_resp_valid_o  <= 1'b1;
                            l1i_resp_data_o_0 <= hit_word[0];
                            l1i_resp_data_o_1 <= hit_word[1];
                            l1i_resp_data_o_2 <= hit_word[2];
                            l1i_resp_data_o_3 <= hit_word[3];
                            if (hit_buddy_valid_q) begin
                                l1i_pf_resp_valid_o  <= 1'b1;
                                l1i_pf_resp_addr_o   <= hit_buddy_addr_q;
                                l1i_pf_resp_data_o_0 <= hit_buddy_word0;
                                l1i_pf_resp_data_o_1 <= hit_buddy_word1;
                                l1i_pf_resp_data_o_2 <= hit_buddy_word2;
                                l1i_pf_resp_data_o_3 <= hit_buddy_word3;
                            end
                        end else begin          // L1D
                            l1d_resp_valid_o  <= 1'b1;
                            l1d_resp_data_o_0 <= hit_word[0];
                            l1d_resp_data_o_1 <= hit_word[1];
                            l1d_resp_data_o_2 <= hit_word[2];
                            l1d_resp_data_o_3 <= hit_word[3];
                        end
                    end
                    rd_state_q <= ST_IDLE;
                end

                ST_REFILL: begin
                    if (refill_store_kill_w)
                        refill_killed_by_store_q <= 1'b1;

                    if (axi_arvalid_o && axi_arready_i)
                        axi_arvalid_o <= 1'b0;

                    // 如果后台预取正在填当前 line，而真正的 L1 demand 已经请求同一
                    // line，则把这次 refill 提升为 demand。这样不用打断 AXI，也不用
                    // 等预取结束后再重新 lookup；关键半行已到齐时可立即响应。
                    if (l1d_prefetch_promote_w) begin
                        req_addr_q        <= l1d_rd_addr_i;
                        req_src_q         <= 1'b1;
                        req_is_prefetch_q <= 1'b0;
                        req_no_resp_q      <= 1'b0;
                        refill_resp_sent_q <= l1d_promote_have_line_w;
                        if (l1d_promote_have_line_w) begin
                            l1d_resp_valid_o  <= 1'b1;
                            l1d_resp_data_o_0 <= l1d_promote_word0;
                            l1d_resp_data_o_1 <= l1d_promote_word1;
                            l1d_resp_data_o_2 <= l1d_promote_word2;
                            l1d_resp_data_o_3 <= l1d_promote_word3;
                        end
                    end else if (l1i_prefetch_promote_w) begin
                        req_addr_q        <= l1i_req_addr_i;
                        req_src_q         <= 1'b0;
                        req_is_prefetch_q <= 1'b0;
                        req_no_resp_q      <= 1'b0;
                        refill_resp_sent_q <= l1i_promote_have_line_w;
                        if (l1i_promote_have_line_w) begin
                            l1i_resp_valid_o  <= 1'b1;
                            l1i_resp_data_o_0 <= l1i_promote_word0;
                            l1i_resp_data_o_1 <= l1i_promote_word1;
                            l1i_resp_data_o_2 <= l1i_promote_word2;
                            l1i_resp_data_o_3 <= l1i_promote_word3;
                        end
                    end

                    if (axi_rvalid_i) begin
                        refill_buf[refill_cnt_q] <= axi_rdata_i;
                        refill_cnt_q <= refill_cnt_q + 3'h1;

                        // Early restart：L1 只需要 4 word。关键半行到齐后立即响应，
                        // 后续 AXI beat 继续填 L2，避免前端等完整 8-beat refill。
                        if (req_uncached_q) begin
                            refill_resp_sent_q <= 1'b1;
                            if (req_src_q) begin
                                l1d_resp_valid_o  <= 1'b1;
                                l1d_resp_data_o_0 <= axi_rdata_i;
                                l1d_resp_data_o_1 <= 32'h0;
                                l1d_resp_data_o_2 <= 32'h0;
                                l1d_resp_data_o_3 <= 32'h0;
                            end
                        end else if (refill_need_resp_w) begin
                            refill_resp_sent_q <= 1'b1;
                            if (!req_src_q) begin
                                l1i_resp_valid_o  <= 1'b1;
                                l1i_resp_data_o_0 <= refill_resp_word0;
                                l1i_resp_data_o_1 <= refill_resp_word1;
                                l1i_resp_data_o_2 <= refill_resp_word2;
                                l1i_resp_data_o_3 <= refill_resp_word3;
                            end else begin
                                l1d_resp_valid_o  <= 1'b1;
                                l1d_resp_data_o_0 <= refill_resp_word0;
                                l1d_resp_data_o_1 <= refill_resp_word1;
                                l1d_resp_data_o_2 <= refill_resp_word2;
                                l1d_resp_data_o_3 <= refill_resp_word3;
                            end
                        end

                        if (bgpf_l1i_lower_resp_w) begin
                            l1i_pf_resp_valid_o  <= 1'b1;
                            l1i_pf_resp_addr_o   <= req_line_base_w;
                            l1i_pf_resp_data_o_0 <= refill_buf[3'd0];
                            l1i_pf_resp_data_o_1 <= refill_buf[3'd1];
                            l1i_pf_resp_data_o_2 <= refill_buf[3'd2];
                            l1i_pf_resp_data_o_3 <= bgpf_resp_word3;
                        end else if (bgpf_l1i_upper_resp_w) begin
                            l1i_pf_resp_valid_o  <= 1'b1;
                            l1i_pf_resp_addr_o   <= req_line_base_w + L1_LINE_SIZE;
                            l1i_pf_resp_data_o_0 <= refill_buf[3'd4];
                            l1i_pf_resp_data_o_1 <= refill_buf[3'd5];
                            l1i_pf_resp_data_o_2 <= refill_buf[3'd6];
                            l1i_pf_resp_data_o_3 <= axi_rdata_i;
                        end

                        if (axi_rlast_i) begin
                            if (refill_buddy_resp_w) begin
                                l1i_pf_resp_valid_o  <= 1'b1;
                                l1i_pf_resp_addr_o   <= req_line_base_w + L1_LINE_SIZE;
                                l1i_pf_resp_data_o_0 <= refill_buf[3'd4];
                                l1i_pf_resp_data_o_1 <= refill_buf[3'd5];
                                l1i_pf_resp_data_o_2 <= refill_buf[3'd6];
                                l1i_pf_resp_data_o_3 <= axi_rdata_i;
                            end
                            if (!req_uncached_q && !refill_killed_w)
                                replace_way_q <= replace_way_q + 1'b1;
                            if (!req_uncached_q && !refill_killed_w && ENABLE_PREFETCH &&
                                (l1i_prefetch_promote_w ||
                                 (!l1d_prefetch_promote_w && l1i_demand_active_w))) begin
                                pf_addr_q    <= (l1d_prefetch_promote_w || l1i_prefetch_promote_w) ?
                                                (promote_addr_w + LINE_SIZE) :
                                                (req_addr_q + LINE_SIZE);
                                pf_pending_q <= 1'b1;
                                pf_pending_l1i_q <= 1'b1;
                            end
                            refill_killed_by_store_q <= 1'b0;
                            if (bgpf_miss_pending_q) begin
                                req_addr_q        <= bgpf_miss_addr_q;
                                req_is_prefetch_q <= 1'b0;
                                req_no_resp_q      <= 1'b0;
                                req_src_q         <= 1'b0;
                                req_size_q        <= 2'b10;
                                req_uncached_q    <= 1'b0;
                                refill_resp_sent_q <= 1'b0;
                                bgpf_miss_pending_q <= 1'b0;
                                rd_state_q        <= ST_LOOKUP;
                            end else begin
                                rd_state_q        <= ST_IDLE;
                            end
                        end
                    end
                end

                ST_RESPOND: begin
                    // 把 L1 需要的 word 段返回
                    if (!req_no_resp_q) begin
                        if (!req_src_q) begin  // L1I
                            l1i_resp_valid_o   <= 1'b1;
                            l1i_resp_data_o_0 <= refill_buf[l1_base_off + 0];
                            l1i_resp_data_o_1 <= refill_buf[l1_base_off + 1];
                            l1i_resp_data_o_2 <= refill_buf[l1_base_off + 2];
                            l1i_resp_data_o_3 <= refill_buf[l1_base_off + 3];
                        end else begin          // L1D
                            l1d_resp_valid_o   <= 1'b1;
                            l1d_resp_data_o_0 <= refill_buf[l1_base_off + 0];
                            l1d_resp_data_o_1 <= refill_buf[l1_base_off + 1];
                            l1d_resp_data_o_2 <= refill_buf[l1_base_off + 2];
                            l1d_resp_data_o_3 <= refill_buf[l1_base_off + 3];
                        end
                        // 设置下一行预取（仅正常请求触发，预取本身不再发起新预取，防止无限循环）
                        if (ENABLE_PREFETCH && l1i_demand_active_w) begin
                            pf_addr_q    <= req_addr_q + LINE_SIZE;
                            pf_pending_q <= 1'b1;
                            pf_pending_l1i_q <= 1'b1;
                        end
                    end
                    // 预取完成不设新 pf_pending，直接回 IDLE 接受外部请求
                    rd_state_q <= ST_IDLE;
                end

            endcase
        end
    end

`ifdef CPU_DEBUG_HAS_RUNTIME
    reg        dbg_axi_ar_hold_q;
    reg [31:0] dbg_axi_araddr_q;
    reg        dbg_axi_aw_hold_q;
    reg [31:0] dbg_axi_awaddr_q;
    reg        dbg_axi_w_hold_q;
    reg [31:0] dbg_axi_wdata_q;
    reg [3:0]  dbg_axi_wstrb_q;

    `CPU_DEBUG_WATCHDOG(l2_read_wait, clk, rst_n,
        (rd_state_q == ST_REFILL),
        axi_rvalid_i,
        512,
        $sformatf("[CACHE][L2][DEADLOCK] refill req_src=%0d req_addr=0x%08x axi_ar(valid=%0d ready=%0d addr=0x%08x) refill_cnt=%0d",
                  req_src_q, req_addr_q, axi_arvalid_o, axi_arready_i, axi_araddr_o, refill_cnt_q))

    `CPU_DEBUG_WATCHDOG(l2_write_wait, clk, rst_n,
        (wr_st != WR_IDLE),
        (axi_bvalid_i || (axi_awvalid_o && axi_awready_i) || (axi_wvalid_o && axi_wready_i)),
        512,
        $sformatf("[CACHE][L2][DEADLOCK] write wr_state=%0d axi_aw(valid=%0d ready=%0d addr=0x%08x) axi_w(valid=%0d ready=%0d data=0x%08x strb=0x%0x) axi_b(valid=%0d ready=%0d)",
                  wr_st, axi_awvalid_o, axi_awready_i, axi_awaddr_o,
                  axi_wvalid_o, axi_wready_i, axi_wdata_o, axi_wstrb_o,
                  axi_bvalid_i, axi_bready_o))

    always @(posedge clk) begin
        if (!rst_n) begin
            dbg_axi_ar_hold_q <= 1'b0;
            dbg_axi_aw_hold_q <= 1'b0;
            dbg_axi_w_hold_q  <= 1'b0;
            `CPU_DEBUG($sformatf("[CACHE][L2][RESET] rd_state=%0d wr_state=%0d", rd_state_q, wr_st));
        end else begin
            if (dbg_axi_ar_hold_q) begin
                `CPU_ASSERT("L2_AXI_AR_STABLE",
                    !axi_arvalid_o || axi_arready_i || (axi_araddr_o == dbg_axi_araddr_q),
                    $sformatf("[CACHE][L2][ASSERT] AXI AR changed while stalled: prev=0x%08x now=0x%08x",
                              dbg_axi_araddr_q, axi_araddr_o))
            end
            if (dbg_axi_aw_hold_q) begin
                `CPU_ASSERT("L2_AXI_AW_STABLE",
                    !axi_awvalid_o || axi_awready_i || (axi_awaddr_o == dbg_axi_awaddr_q),
                    $sformatf("[CACHE][L2][ASSERT] AXI AW changed while stalled: prev=0x%08x now=0x%08x",
                              dbg_axi_awaddr_q, axi_awaddr_o))
            end
            if (dbg_axi_w_hold_q) begin
                `CPU_ASSERT("L2_AXI_W_STABLE",
                    !axi_wvalid_o || axi_wready_i ||
                    ((axi_wdata_o == dbg_axi_wdata_q) && (axi_wstrb_o == dbg_axi_wstrb_q)),
                    $sformatf("[CACHE][L2][ASSERT] AXI W changed while stalled: prev(data=0x%08x strb=0x%0x) now(data=0x%08x strb=0x%0x)",
                              dbg_axi_wdata_q, dbg_axi_wstrb_q, axi_wdata_o, axi_wstrb_o))
            end

            dbg_axi_ar_hold_q <= axi_arvalid_o && !axi_arready_i;
            dbg_axi_araddr_q  <= axi_araddr_o;
            dbg_axi_aw_hold_q <= axi_awvalid_o && !axi_awready_i;
            dbg_axi_awaddr_q  <= axi_awaddr_o;
            dbg_axi_w_hold_q  <= axi_wvalid_o && !axi_wready_i;
            dbg_axi_wdata_q   <= axi_wdata_o;
            dbg_axi_wstrb_q   <= axi_wstrb_o;

            if (l1d_rd_valid_i || l1i_req_valid_i || axi_arvalid_o || axi_rvalid_i ||
                l1d_resp_valid_o || l1i_resp_valid_o || l1i_pf_resp_valid_o) begin
                `CPU_DEBUG($sformatf(
                    "[CACHE][L2][READ] rd_state=%0d req_src=%0d req_addr=0x%08x hit=%0d way=0x%0x l1d_req(valid=%0d ready=%0d addr=0x%08x) l1i_req(valid=%0d ready=%0d addr=0x%08x pf=%0d) axi_ar(valid=%0d ready=%0d addr=0x%08x) axi_r(valid=%0d last=%0d data=0x%08x) resp(i=%0d d=%0d buddy=%0d buddy_addr=0x%08x)",
                    rd_state_q, req_src_q, req_addr_q, cache_hit, way_hit,
                    l1d_rd_valid_i, l1d_rd_ready_o, l1d_rd_addr_i,
                    l1i_req_valid_i, l1i_req_ready_o, l1i_req_addr_i, l1i_req_is_prefetch_i,
                    axi_arvalid_o, axi_arready_i, axi_araddr_o,
                    axi_rvalid_i, axi_rlast_i, axi_rdata_i,
                    l1i_resp_valid_o, l1d_resp_valid_o,
                    l1i_pf_resp_valid_o, l1i_pf_resp_addr_o
                ));
            end
            if (l1d_wr_valid_i || axi_awvalid_o || axi_wvalid_o || axi_bvalid_i || l1d_wr_done_o) begin
                `CPU_DEBUG($sformatf(
                    "[CACHE][L2][WRITE] wr_state=%0d l1d_wr(valid=%0d ready=%0d done=%0d addr=0x%08x data=0x%08x strb=0x%0x) axi_aw(valid=%0d ready=%0d addr=0x%08x) axi_w(valid=%0d ready=%0d data=0x%08x strb=0x%0x) axi_b(valid=%0d ready=%0d resp=0x%0x) inv_pending=%0d inv_idx=%0d",
                    wr_st, l1d_wr_valid_i, l1d_wr_ready_o, l1d_wr_done_o,
                    l1d_wr_addr_i, l1d_wr_data_i, l1d_wr_strb_i,
                    axi_awvalid_o, axi_awready_i, axi_awaddr_o,
                    axi_wvalid_o, axi_wready_i, axi_wdata_o, axi_wstrb_o,
                    axi_bvalid_i, axi_bready_o, axi_bresp_i, inv_pending_q, inv_idx_q
                ));
            end
        end
    end
`endif

    `CPU_DEBUG_MODULE("cpu_l2_cache")
endmodule
