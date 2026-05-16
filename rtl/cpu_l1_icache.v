`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ============================================================================
// L1 ICache — 4-way 组相联，128 line，4 word/line（16B line = 8KB）
//
// 接口：
//   CPU 侧：req_valid/req_addr → resp_valid/resp_instr（1 word）
//   L2  侧：l2_req_valid/l2_req_addr → l2_resp_valid/l2_resp_data（4 word）
//
// FPGA 路径（RAMB36E1 原语，DOA_REG=1）：
//   T0：req_valid_i 有效，地址送入 BRAM 读端口，lookup_addr_q 锁存
//   T1：BRAM 内部寄存器
//   T2：BRAM DOA 输出有效 → 命中判断
//   T3：用寄存的 way_hit/data 产生保序队列响应，可当拍组合输出给 S3
//
//   存储：
//     data_ram：4 way × 4 word × RAMB36E1（SDP x32，深度 128）= 16 个
//     tag_ram ：4 way × RAMB36E1（SDP x32，深度 128）          =  4 个
//     共 20 个 RAMB36E1
//
// 仿真（reg 数组，组合读，与原设计完全一致，1 拍延迟）：
//   T0：req_valid_i，锁 lookup_addr_q
//   T1：组合命中判断，resp_valid/resp_instr 输出
// ============================================================================
module cpu_l1_icache #(
    parameter XLEN      = 32,
    parameter ILEN      = 32,
    parameter NUM_WAYS  = 4,
    parameter NUM_LINES = 128,
    parameter LINE_SIZE = 16,     // 字节，4 word
    parameter ENABLE_REDIRECT_PROBE_LOOKUP = 0
) (
    input  wire            clk,
    input  wire            rst_n,
    input  wire            flush,

    // ---- CPU 侧 ----
    input  wire            req_valid_i,
    output wire            req_ready_o,
    input  wire [XLEN-1:0] req_addr_i,
    // 备用路径提示：只借用空闲 lookup 做 BRAM 命中探测，命中后填 altbuf。
    input  wire            shadow_fetch_valid_i,
    input  wire [XLEN-1:0] shadow_fetch_addr_i,
    input  wire            redirect_probe_valid_i,
    input  wire [XLEN-1:0] redirect_probe_addr_i,
    output wire            redirect_probe_hit_o,
    output wire            redirect_fast_valid_o,
    output wire [XLEN-1:0] redirect_fast_addr_o,
    output wire [ILEN-1:0] redirect_fast_instr_o,
    output wire            redirect_fast_line_valid_o,
    output wire [XLEN-1:0] redirect_fast_line_addr_o,
    output wire [ILEN-1:0] redirect_fast_line_data_o_0,
    output wire [ILEN-1:0] redirect_fast_line_data_o_1,
    output wire [ILEN-1:0] redirect_fast_line_data_o_2,
    output wire [ILEN-1:0] redirect_fast_line_data_o_3,
    input  wire            redirect_fast_consume_i,
    output wire            resp_valid_o,
    output wire [ILEN-1:0] resp_instr_o,
    output wire            resp_fault_o,
    output wire            resp_line_valid_o,
    output wire [XLEN-1:0] resp_line_addr_o,
    output wire [ILEN-1:0] resp_line_data_o_0,
    output wire [ILEN-1:0] resp_line_data_o_1,
    output wire [ILEN-1:0] resp_line_data_o_2,
    output wire [ILEN-1:0] resp_line_data_o_3,

    input  wire            cacop_valid_i,
    input  wire [1:0]      cacop_mode_i,
    input  wire [XLEN-1:0] cacop_addr_i,
    output wire            cacop_ready_o,
    output wire            cacop_done_o,

    // ---- L2 请求（miss / 预取） ----
    output reg             l2_req_valid_o,
    output reg  [XLEN-1:0] l2_req_addr_o,
    output reg             l2_req_is_prefetch_o,
    input  wire            l2_req_ready_i,

    // ---- L2 响应（整行数据） ----
    input  wire            l2_resp_valid_i,
    input  wire [XLEN-1:0] l2_resp_data_i_0,
    input  wire [XLEN-1:0] l2_resp_data_i_1,
    input  wire [XLEN-1:0] l2_resp_data_i_2,
    input  wire [XLEN-1:0] l2_resp_data_i_3,

    // L2 在同一条 32B line 内顺手返回的另一个 16B half-line。
    // 该通道不对应 CPU 请求，不进入 resp 队列，只填 pfbuf 供顺序取指命中。
    input  wire            l2_pf_resp_valid_i,
    input  wire [XLEN-1:0] l2_pf_resp_addr_i,
    input  wire [XLEN-1:0] l2_pf_resp_data_i_0,
    input  wire [XLEN-1:0] l2_pf_resp_data_i_1,
    input  wire [XLEN-1:0] l2_pf_resp_data_i_2,
    input  wire [XLEN-1:0] l2_pf_resp_data_i_3
);

    localparam INDEX_WIDTH    = $clog2(NUM_LINES);                 // 7
    localparam OFFSET_WIDTH   = $clog2(LINE_SIZE);                 // 4
    localparam TAG_WIDTH      = XLEN - INDEX_WIDTH - OFFSET_WIDTH; // 21
    localparam WORDS_PER_LINE = LINE_SIZE / 4;                     // 4
    localparam WAY_WIDTH      = $clog2(NUM_WAYS);                  // 2
    localparam RESP_DEPTH     = 8;
    localparam RESP_PTR_W     = $clog2(RESP_DEPTH);
    localparam [RESP_PTR_W:0] RESP_DEPTH_COUNT = RESP_DEPTH;
    localparam ENABLE_L1_STREAM_PREFETCH = 1'b0;
    localparam ENABLE_L1_LOOKAHEAD_PROBE = 1'b1;
    localparam ENABLE_L1_EARLY_LOOKUP_HIT = 1'b1;
    localparam ENABLE_L1_EARLY_LOOKUP_MISS = 1'b1;
    localparam ENABLE_REDIRECT_LINEBUF_RTBUF_PROMOTE = 1'b0;
    localparam ENABLE_REDIRECT_RTBUF_MRU_PROMOTE = 1'b0;
    localparam [XLEN-1:0] LINE_OFFSET_MASK = LINE_SIZE - 1;

    localparam ST_LOOKUP = 2'd0;
    localparam ST_MISS   = 2'd1;
    localparam ST_CACOP  = 2'd2;

    // =========================================================================
    // RAMB36E1 原语路径（DOA_REG=1，T0→T1→T2→T3 共 3 拍命中延迟）
    // 仿真：sim/ramb36e1_model.v 提供行为等价模型，时序与上板一致
    // =========================================================================

    // --- 状态 & 控制 ---
    reg [1:0]           state_q;
    reg [WAY_WIDTH-1:0] replace_way_q;
    reg                 shadow_hint0_valid_q;
    reg [XLEN-1:0]      shadow_hint0_addr_q;
    reg                 shadow_hint1_valid_q;
    reg [XLEN-1:0]      shadow_hint1_addr_q;

    // T0 锁存（送 BRAM 地址的同时锁请求地址）
    reg [XLEN-1:0]  lookup_addr_q;   // T0→T1
    reg             lookup_valid_q;

    // T1 锁存（T2 命中判断用）
    reg [XLEN-1:0]  lookup_addr_d1;  // T1→T2
    reg             lookup_valid_d1;

    // miss 地址锁存
    reg [XLEN-1:0]  miss_addr_q;
    reg [XLEN-1:0]  cacop_addr_q;
    reg [1:0]       cacop_mode_q;
    reg             cacop_phase_q;
    reg             cacop_done_q;

    // ICache 内部可能同时存在 BRAM lookup 与 linebuf/pfbuf 快速命中，二者
    // 延迟不同；因此所有请求先进入响应保序队列，再从队首逐条发出，保证
    // CPU 侧看到的 resp 顺序与 req 顺序完全一致。
    assign resp_fault_o = 1'b0;
    assign cacop_done_o = cacop_done_q;

    // --- 地址字段 ---
    wire [INDEX_WIDTH-1:0] req_idx       = req_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0]   req_tag       = req_addr_i[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [1:0]             req_word_off  = req_addr_i[OFFSET_WIDTH-1 : 2];
    wire [INDEX_WIDTH-1:0] redirect_probe_idx =
        redirect_probe_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0] redirect_probe_tag =
        redirect_probe_addr_i[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [1:0] redirect_probe_word_off =
        redirect_probe_addr_i[OFFSET_WIDTH-1 : 2];
    wire [INDEX_WIDTH-1:0] shadow_fetch_idx =
        shadow_fetch_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0] shadow_fetch_tag =
        shadow_fetch_addr_i[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire shadow_probe_from_queue_w = shadow_hint0_valid_q;
    wire shadow_probe_input_valid_w =
        shadow_probe_from_queue_w || shadow_fetch_valid_i;
    wire [XLEN-1:0] shadow_probe_addr_w =
        shadow_probe_from_queue_w ? shadow_hint0_addr_q : shadow_fetch_addr_i;
    wire [INDEX_WIDTH-1:0] shadow_probe_idx_w =
        shadow_probe_addr_w[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0] shadow_probe_tag_w =
        shadow_probe_addr_w[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [TAG_WIDTH-1:0]   lk_tag        = lookup_addr_d1[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [1:0]             lk_word_off   = lookup_addr_d1[OFFSET_WIDTH-1 : 2];
    wire [INDEX_WIDTH-1:0] miss_idx      = miss_addr_q[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0]   miss_tag      = miss_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [1:0]             miss_word_off = miss_addr_q[OFFSET_WIDTH-1 : 2];
    wire [INDEX_WIDTH-1:0] cacop_idx     = cacop_addr_q[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0]   cacop_tag     = cacop_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire                   cacop_accept_w = cacop_valid_i && cacop_ready_o;

    // --- BRAM 地址 ---
    // RAMB36E1 SDP x32：行为模型和 7-series 原语都把 ADDR[14:5]
    // 作为 1024 深度的 x32 word 地址，[4:0] 固定为 0。
    // 因此 idx 应直接映射到 ADDR[14:5]，使同一组 BRAM 可以支持
    // 最多 1024 line；core 中把 NUM_LINES 扩到 512 时不增加 BRAM 片数。
    // fill 完成后回 ST_LOOKUP，下一拍用 miss_addr_q（已锁存）的 idx 发 BRAM 读，
    // 避开 fill 当拍写读同地址的 READ_FIRST 旧值问题
    wire redirect_probe_lookup_start_w;
    wire shadow_probe_lookup_start_w;
    wire shadow_hint_pop_w;
    wire shadow_hint_enqueue_w;
    wire lookahead_probe_start_w;
    wire [XLEN-1:0] lookahead_probe_addr_w;
    wire [INDEX_WIDTH-1:0] lookahead_probe_idx_w;
    wire [INDEX_WIDTH-1:0] lookup_issue_idx =
        lookup_issue_addr_w[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [INDEX_WIDTH-1:0] normal_lookup_idx =
        replay_lookup_fire_w ? lookup_issue_idx : req_idx;
    wire [INDEX_WIDTH-1:0] eff_rd_idx  =
        cacop_accept_w ? cacop_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH] :
        (state_q == ST_CACOP) ? cacop_idx :
        redirect_probe_lookup_start_w ? redirect_probe_idx :
        shadow_probe_lookup_start_w ? shadow_probe_idx_w :
        lookahead_probe_start_w ? lookahead_probe_idx_w :
        normal_lookup_idx;
    wire [9:0] bram_rd_line_addr =
        {{(10-INDEX_WIDTH){1'b0}}, eff_rd_idx};
    wire [9:0] bram_wr_line_addr =
        {{(10-INDEX_WIDTH){1'b0}}, (state_q == ST_CACOP) ? cacop_idx : miss_idx};
    wire [14:0] bram_rd_addr = {bram_rd_line_addr, 5'b0};
    wire [14:0] bram_wr_addr = {bram_wr_line_addr, 5'b0};

    wire [31:0] bram_tag_wdata = {{(32-(TAG_WIDTH+1)){1'b0}}, 1'b1, miss_tag};

    // --- BRAM 实例化 ---
    wire [31:0] data_bram_rd [0:NUM_WAYS-1][0:WORDS_PER_LINE-1];
    wire [31:0] tag_bram_rd  [0:NUM_WAYS-1];

    genvar gw, gb;
    generate
        for (gw = 0; gw < NUM_WAYS; gw = gw + 1) begin : gen_way_bram

            wire tag_refill_we_w = (state_q == ST_MISS) && l2_resp_valid_i &&
                                    (replace_way_q == gw[WAY_WIDTH-1:0]);
            wire cacop_way_hit_w = tag_bram_rd[gw][TAG_WIDTH] &&
                                   (tag_bram_rd[gw][TAG_WIDTH-1:0] == cacop_tag);
            wire tag_cacop_index_we_w =
                (state_q == ST_CACOP) && cacop_phase_q && (cacop_mode_q != 2'b10);
            wire tag_cacop_hit_we_w =
                (state_q == ST_CACOP) && cacop_phase_q && (cacop_mode_q == 2'b10) &&
                cacop_way_hit_w;
            wire tag_cacop_we_w = tag_cacop_index_we_w || tag_cacop_hit_we_w;
            wire [31:0] tag_wdata_w = tag_cacop_we_w ? 32'h0 : bram_tag_wdata;

            RAMB36E1 #(
                .RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36),
                .DOA_REG(1), .INIT_FILE("NONE"), .SIM_COLLISION_CHECK("NONE"),
                .WRITE_MODE_A("READ_FIRST"), .WRITE_MODE_B("READ_FIRST")
            ) u_tag (
                .CLKARDCLK(clk), .ENARDEN(1'b1),
                .RSTRAMARSTRAM(1'b0), .RSTREGARSTREG(1'b0), .REGCEAREGCE(1'b1),
                .WEA(4'h0), .ADDRARDADDR(bram_rd_addr),
                .DIADI(32'h0), .DIPADIP(4'h0),
                .DOADO(tag_bram_rd[gw]), .DOBDO(), .DOPADOP(), .DOPBDOP(),
                .CLKBWRCLK(clk), .ENBWREN(1'b1),
                .WEBWE({4'b0, {4{tag_refill_we_w || tag_cacop_we_w}}}), .ADDRBWRADDR(bram_wr_addr),
                .DIBDI(tag_wdata_w), .DIPBDIP(4'h0),
                .CASCADEINA(1'b0), .CASCADEINB(1'b0),
                .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0)
            );

            for (gb = 0; gb < WORDS_PER_LINE; gb = gb + 1) begin : gen_data_bram
                wire this_we_w = (state_q == ST_MISS) && l2_resp_valid_i &&
                                  (replace_way_q == gw[WAY_WIDTH-1:0]);
                wire [31:0] data_wdata_w =
                    (gb == 0) ? l2_resp_data_i_0 :
                    (gb == 1) ? l2_resp_data_i_1 :
                    (gb == 2) ? l2_resp_data_i_2 : l2_resp_data_i_3;

                RAMB36E1 #(
                    .RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36),
                    .DOA_REG(1), .INIT_FILE("NONE"), .SIM_COLLISION_CHECK("NONE"),
                    .WRITE_MODE_A("READ_FIRST"), .WRITE_MODE_B("READ_FIRST")
                ) u_data (
                    .CLKARDCLK(clk), .ENARDEN(1'b1),
                    .RSTRAMARSTRAM(1'b0), .RSTREGARSTREG(1'b0), .REGCEAREGCE(1'b1),
                    .WEA(4'h0), .ADDRARDADDR(bram_rd_addr),
                    .DIADI(32'h0), .DIPADIP(4'h0),
                    .DOADO(data_bram_rd[gw][gb]), .DOBDO(), .DOPADOP(), .DOPBDOP(),
                    .CLKBWRCLK(clk), .ENBWREN(1'b1),
                    .WEBWE({4'b0, {4{this_we_w}}}), .ADDRBWRADDR(bram_wr_addr),
                    .DIBDI(data_wdata_w), .DIPBDIP(4'h0),
                    .CASCADEINA(1'b0), .CASCADEINB(1'b0),
                    .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0)
                );
            end
        end
    endgenerate

    // --- T2：tag 比较 → way_hit 寄存（4bit，fo 极低）---
// way_hit 是 CARRY4 链输出，直接驱动 32bit MUX 会造成 fo=38 长布线。
// 改为：T2 把 way_hit 打一拍存入 way_hit_q（T3 有效），
    //       T3 用 way_hit_q 做 hit_data MUX，并驱动保序响应队列/组合输出。
    // 代价：hit 延迟从 T2 变为 T3（多 1 拍），miss 路径不变。
    wire [NUM_WAYS-1:0] way_hit_comb;
    wire [NUM_WAYS-1:0] normal_way_hit_comb;
    wire [31:0] way_data_comb [0:NUM_WAYS-1];
    wire [31:0] normal_way_data_comb [0:NUM_WAYS-1];
    reg [NUM_WAYS-1:0] way_hit_q;
    reg [31:0]         way_data_q [0:NUM_WAYS-1];
    reg [31:0]         way_line_q [0:NUM_WAYS-1][0:WORDS_PER_LINE-1];
    reg                cache_hit_q;
    reg                lookup_valid_d2;  // T2→T3 valid
    reg [XLEN-1:0]     lookup_addr_d2;   // T2→T3 address, aligned with hit/data
    reg                probe_lookup_valid_q;
    reg                probe_lookup_valid_d1;
    reg                probe_lookup_valid_d2;
    reg [XLEN-1:0]     probe_lookup_addr_q;
    reg [XLEN-1:0]     probe_lookup_addr_d1;
    reg [XLEN-1:0]     probe_lookup_addr_d2;
    reg                shadow_probe_valid_q;
    reg                shadow_probe_valid_d1;
    reg                shadow_probe_valid_d2;
    reg [XLEN-1:0]     shadow_probe_addr_q;
    reg [XLEN-1:0]     shadow_probe_addr_d1;
    reg [XLEN-1:0]     shadow_probe_addr_d2;
    reg                lookahead_probe_valid_q;
    reg                lookahead_probe_valid_d1;
    reg                lookahead_probe_valid_d2;
    reg [XLEN-1:0]     lookahead_probe_addr_q;
    reg [XLEN-1:0]     lookahead_probe_addr_d1;
    reg [XLEN-1:0]     lookahead_probe_addr_d2;
    wire [TAG_WIDTH-1:0] bram_cmp_tag_w =
        probe_lookup_valid_d1 ?
        probe_lookup_addr_d1[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH] :
        shadow_probe_valid_d1 ?
        shadow_probe_addr_d1[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH] :
        lookahead_probe_valid_d1 ?
        lookahead_probe_addr_d1[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH] : lk_tag;
    wire [1:0] bram_word_off_w =
        probe_lookup_valid_d1 ? probe_lookup_addr_d1[OFFSET_WIDTH-1 : 2] :
        shadow_probe_valid_d1 ? shadow_probe_addr_d1[OFFSET_WIDTH-1 : 2] :
        lookahead_probe_valid_d1 ? lookahead_probe_addr_d1[OFFSET_WIDTH-1 : 2] :
                                lk_word_off;
    genvar gw2;
    generate
        for (gw2 = 0; gw2 < NUM_WAYS; gw2 = gw2 + 1) begin : gen_hit
            assign way_hit_comb[gw2]  = tag_bram_rd[gw2][TAG_WIDTH] &&
                                         (tag_bram_rd[gw2][TAG_WIDTH-1:0] == bram_cmp_tag_w);
            assign way_data_comb[gw2] = data_bram_rd[gw2][bram_word_off_w];
            assign normal_way_hit_comb[gw2]  = tag_bram_rd[gw2][TAG_WIDTH] &&
                                                (tag_bram_rd[gw2][TAG_WIDTH-1:0] == lk_tag);
            assign normal_way_data_comb[gw2] = data_bram_rd[gw2][lk_word_off];
        end
    endgenerate

    wire cache_hit_comb = |way_hit_comb;
    wire normal_cache_hit_comb = |normal_way_hit_comb;
    // T2→T3 寄存器：way_hit 和对应 data（各 way 的目标 word）
    // way_data 同样寄存，这样 T3 做 MUX 的扇出仅来自 way_hit_q（fo=4，每 bit 驱动 1 个 MUX）

    // way_data_q 无条件写（不依赖 flush/rst），消除 CE 高扇出路径
    // flush 时 way_hit_q 清零，T3 MUX 输出无意义但 resp_valid_o 也被 flush 屏蔽。
    always @(posedge clk) begin
        way_data_q[0] <= way_data_comb[0];
        way_data_q[1] <= way_data_comb[1];
        way_data_q[2] <= way_data_comb[2];
        way_data_q[3] <= way_data_comb[3];
    end

    genvar glw, glb;
    generate
        for (glw = 0; glw < NUM_WAYS; glw = glw + 1) begin : gen_line_sample_way
            for (glb = 0; glb < WORDS_PER_LINE; glb = glb + 1) begin : gen_line_sample_word
                always @(posedge clk) begin
                    way_line_q[glw][glb] <= data_bram_rd[glw][glb];
                end
            end
        end
    endgenerate

    always @(posedge clk) begin
        if (!rst_n || flush || lookup_miss_w) begin
            way_hit_q       <= {NUM_WAYS{1'b0}};
            cache_hit_q     <= 1'b0;
            lookup_valid_d2 <= 1'b0;
            lookup_addr_d2  <= {XLEN{1'b0}};
            lookup_resp_slot_d2 <= {RESP_PTR_W{1'b0}};
        end else begin
            way_hit_q       <= way_hit_comb;
            cache_hit_q     <= normal_cache_hit_comb && !probe_lookup_valid_d1 &&
                               !shadow_probe_valid_d1 &&
                               !lookahead_probe_valid_d1;
            lookup_valid_d2 <= lookup_valid_d1 && !probe_lookup_valid_d1 &&
                               !shadow_probe_valid_d1 &&
                               !lookahead_probe_valid_d1 &&
                               !(ENABLE_L1_EARLY_LOOKUP_HIT && normal_cache_hit_comb) &&
                               !(ENABLE_L1_EARLY_LOOKUP_MISS && !normal_cache_hit_comb);
            lookup_addr_d2  <= lookup_addr_d1;
            lookup_resp_slot_d2 <= lookup_resp_slot_d1;
        end
    end

    always @(posedge clk) begin
        if (!rst_n || lookup_miss_w) begin
            probe_lookup_valid_q  <= 1'b0;
            probe_lookup_valid_d1 <= 1'b0;
            probe_lookup_valid_d2 <= 1'b0;
            probe_lookup_addr_q   <= {XLEN{1'b0}};
            probe_lookup_addr_d1  <= {XLEN{1'b0}};
            probe_lookup_addr_d2  <= {XLEN{1'b0}};
        end else if (flush) begin
            probe_lookup_valid_q  <= redirect_probe_lookup_start_w;
            probe_lookup_valid_d1 <= 1'b0;
            probe_lookup_valid_d2 <= 1'b0;
            probe_lookup_addr_q   <= redirect_probe_addr_i;
            probe_lookup_addr_d1  <= {XLEN{1'b0}};
            probe_lookup_addr_d2  <= {XLEN{1'b0}};
        end else begin
            probe_lookup_valid_q  <= 1'b0;
            probe_lookup_valid_d1 <= probe_lookup_valid_q;
            probe_lookup_valid_d2 <= probe_lookup_valid_d1;
            probe_lookup_addr_q   <= {XLEN{1'b0}};
            probe_lookup_addr_d1  <= probe_lookup_addr_q;
            probe_lookup_addr_d2  <= probe_lookup_addr_d1;
        end
    end

    always @(posedge clk) begin
        if (!rst_n || flush || lookup_miss_w) begin
            shadow_probe_valid_q  <= 1'b0;
            shadow_probe_valid_d1 <= 1'b0;
            shadow_probe_valid_d2 <= 1'b0;
            shadow_probe_addr_q   <= {XLEN{1'b0}};
            shadow_probe_addr_d1  <= {XLEN{1'b0}};
            shadow_probe_addr_d2  <= {XLEN{1'b0}};
        end else begin
            shadow_probe_valid_q  <= shadow_probe_lookup_start_w;
            shadow_probe_valid_d1 <= shadow_probe_valid_q;
            shadow_probe_valid_d2 <= shadow_probe_valid_d1;
            shadow_probe_addr_q   <= shadow_probe_lookup_start_w ?
                                      shadow_probe_addr_w : {XLEN{1'b0}};
            shadow_probe_addr_d1  <= shadow_probe_addr_q;
            shadow_probe_addr_d2  <= shadow_probe_addr_d1;
        end
    end

    always @(posedge clk) begin
        if (!rst_n || flush || lookup_miss_w) begin
            lookahead_probe_valid_q  <= 1'b0;
            lookahead_probe_valid_d1 <= 1'b0;
            lookahead_probe_valid_d2 <= 1'b0;
            lookahead_probe_addr_q   <= {XLEN{1'b0}};
            lookahead_probe_addr_d1  <= {XLEN{1'b0}};
            lookahead_probe_addr_d2  <= {XLEN{1'b0}};
        end else begin
            lookahead_probe_valid_q  <= lookahead_probe_start_w;
            lookahead_probe_valid_d1 <= lookahead_probe_valid_q;
            lookahead_probe_valid_d2 <= lookahead_probe_valid_d1;
            lookahead_probe_addr_q   <= lookahead_probe_start_w ?
                                        lookahead_probe_addr_w : {XLEN{1'b0}};
            lookahead_probe_addr_d1  <= lookahead_probe_addr_q;
            lookahead_probe_addr_d2  <= lookahead_probe_addr_d1;
        end
    end

    // T3：用寄存的 way_hit_q（fo=1/bit）做 MUX，无高扇出布线压力
    wire [31:0] hit_data =
        way_hit_q[0] ? way_data_q[0] :
        way_hit_q[1] ? way_data_q[1] :
        way_hit_q[2] ? way_data_q[2] : way_data_q[3];

    wire [31:0] hit_line_word0 =
        way_hit_q[0] ? way_line_q[0][0] :
        way_hit_q[1] ? way_line_q[1][0] :
        way_hit_q[2] ? way_line_q[2][0] : way_line_q[3][0];
    wire [31:0] hit_line_word1 =
        way_hit_q[0] ? way_line_q[0][1] :
        way_hit_q[1] ? way_line_q[1][1] :
        way_hit_q[2] ? way_line_q[2][1] : way_line_q[3][1];
    wire [31:0] hit_line_word2 =
        way_hit_q[0] ? way_line_q[0][2] :
        way_hit_q[1] ? way_line_q[1][2] :
        way_hit_q[2] ? way_line_q[2][2] : way_line_q[3][2];
    wire [31:0] hit_line_word3 =
        way_hit_q[0] ? way_line_q[0][3] :
        way_hit_q[1] ? way_line_q[1][3] :
        way_hit_q[2] ? way_line_q[2][3] : way_line_q[3][3];
    wire [31:0] early_hit_data =
        normal_way_hit_comb[0] ? normal_way_data_comb[0] :
        normal_way_hit_comb[1] ? normal_way_data_comb[1] :
        normal_way_hit_comb[2] ? normal_way_data_comb[2] : normal_way_data_comb[3];
    wire [31:0] early_hit_line_word0 =
        normal_way_hit_comb[0] ? data_bram_rd[0][0] :
        normal_way_hit_comb[1] ? data_bram_rd[1][0] :
        normal_way_hit_comb[2] ? data_bram_rd[2][0] : data_bram_rd[3][0];
    wire [31:0] early_hit_line_word1 =
        normal_way_hit_comb[0] ? data_bram_rd[0][1] :
        normal_way_hit_comb[1] ? data_bram_rd[1][1] :
        normal_way_hit_comb[2] ? data_bram_rd[2][1] : data_bram_rd[3][1];
    wire [31:0] early_hit_line_word2 =
        normal_way_hit_comb[0] ? data_bram_rd[0][2] :
        normal_way_hit_comb[1] ? data_bram_rd[1][2] :
        normal_way_hit_comb[2] ? data_bram_rd[2][2] : data_bram_rd[3][2];
    wire [31:0] early_hit_line_word3 =
        normal_way_hit_comb[0] ? data_bram_rd[0][3] :
        normal_way_hit_comb[1] ? data_bram_rd[1][3] :
        normal_way_hit_comb[2] ? data_bram_rd[2][3] : data_bram_rd[3][3];

    // 最近命中的整行寄存器。顺序取指和小范围跳转重新访问近期 line 时，
    // 可以直接从这些寄存器返回，避开 RAMB 查找流水。
    reg                  linebuf_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf_idx_q;
    reg [31:0]           linebuf_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf1_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf1_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf1_idx_q;
    reg [31:0]           linebuf1_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf2_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf2_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf2_idx_q;
    reg [31:0]           linebuf2_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf3_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf3_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf3_idx_q;
    reg [31:0]           linebuf3_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf4_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf4_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf4_idx_q;
    reg [31:0]           linebuf4_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf5_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf5_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf5_idx_q;
    reg [31:0]           linebuf5_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf6_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf6_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf6_idx_q;
    reg [31:0]           linebuf6_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf7_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf7_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf7_idx_q;
    reg [31:0]           linebuf7_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf8_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf8_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf8_idx_q;
    reg [31:0]           linebuf8_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf9_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf9_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf9_idx_q;
    reg [31:0]           linebuf9_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf10_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf10_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf10_idx_q;
    reg [31:0]           linebuf10_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf11_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf11_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf11_idx_q;
    reg [31:0]           linebuf11_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf12_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf12_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf12_idx_q;
    reg [31:0]           linebuf12_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf13_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf13_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf13_idx_q;
    reg [31:0]           linebuf13_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf14_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf14_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf14_idx_q;
    reg [31:0]           linebuf14_data_q [0:WORDS_PER_LINE-1];
    reg                  linebuf15_valid_q;
    reg [TAG_WIDTH-1:0]  linebuf15_tag_q;
    reg [INDEX_WIDTH-1:0] linebuf15_idx_q;
    reg [31:0]           linebuf15_data_q [0:WORDS_PER_LINE-1];
    // 重定向目标专用缓存。和 recent linebuf 分开，避免热跳转目标被顺序流
    // 很快挤出，用于缩短 flush 后取指恢复时间。
    reg                  rtbuf_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf_idx_q;
    reg [31:0]           rtbuf_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf1_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf1_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf1_idx_q;
    reg [31:0]           rtbuf1_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf2_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf2_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf2_idx_q;
    reg [31:0]           rtbuf2_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf3_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf3_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf3_idx_q;
    reg [31:0]           rtbuf3_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf4_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf4_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf4_idx_q;
    reg [31:0]           rtbuf4_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf5_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf5_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf5_idx_q;
    reg [31:0]           rtbuf5_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf6_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf6_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf6_idx_q;
    reg [31:0]           rtbuf6_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf7_valid_q;
    reg [TAG_WIDTH-1:0]  rtbuf7_tag_q;
    reg [INDEX_WIDTH-1:0] rtbuf7_idx_q;
    reg [31:0]           rtbuf7_data_q [0:WORDS_PER_LINE-1];
    reg                  rtbuf_pending_q;
    reg [XLEN-1:0]       rtbuf_pending_addr_q;

    // 下一 16B line 预取缓冲。L2 行宽是 32B，而 L1I 行宽是 16B；
    // 顺序流跨半行时，pfbuf 可以把下一半行提前带回，减少 L2 hit 等待。
    reg                  pfbuf_valid_q;
    reg [TAG_WIDTH-1:0]  pfbuf_tag_q;
    reg [INDEX_WIDTH-1:0] pfbuf_idx_q;
    reg [31:0]           pfbuf_data_q [0:WORDS_PER_LINE-1];
    reg                  pfbuf1_valid_q;
    reg [TAG_WIDTH-1:0]  pfbuf1_tag_q;
    reg [INDEX_WIDTH-1:0] pfbuf1_idx_q;
    reg [31:0]           pfbuf1_data_q [0:WORDS_PER_LINE-1];
    // 分支另一方向的影子缓冲。它不产生独立 CPU 响应，只在后续正常请求或
    // redirect probe 命中时作为 fastbuf 使用。
    reg                  altbuf_valid_q;
    reg [TAG_WIDTH-1:0]  altbuf_tag_q;
    reg [INDEX_WIDTH-1:0] altbuf_idx_q;
    reg [31:0]           altbuf_data_q [0:WORDS_PER_LINE-1];
    reg                  altbuf1_valid_q;
    reg [TAG_WIDTH-1:0]  altbuf1_tag_q;
    reg [INDEX_WIDTH-1:0] altbuf1_idx_q;
    reg [31:0]           altbuf1_data_q [0:WORDS_PER_LINE-1];
    reg                  pf_inflight_q;
    reg [XLEN-1:0]       pf_addr_q;
    reg                  stale_l2_resp_pending_q;

`ifdef PERF_MONI
    reg                  perf_shadow_valid_q [0:15];
    reg [TAG_WIDTH-1:0]  perf_shadow_tag_q   [0:15];
    reg [INDEX_WIDTH-1:0] perf_shadow_idx_q  [0:15];
    reg                  perf_shadow_req_hit_lo_w;
    reg                  perf_shadow_req_hit_hi_w;
    reg                  perf_shadow_redirect_hit_lo_w;
    reg                  perf_shadow_redirect_hit_hi_w;
    reg [4:0]            perf_shadow_touch_pos_w;
    integer              perf_shadow_scan_i;
    integer              perf_shadow_seq_i;
`endif

    wire linebuf0_hit_req = linebuf_valid_q &&
                            (linebuf_tag_q == req_tag) &&
                            (linebuf_idx_q == req_idx);
    wire linebuf1_hit_req = linebuf1_valid_q &&
                            (linebuf1_tag_q == req_tag) &&
                            (linebuf1_idx_q == req_idx);
    wire linebuf2_hit_req = linebuf2_valid_q &&
                            (linebuf2_tag_q == req_tag) &&
                            (linebuf2_idx_q == req_idx);
    wire linebuf3_hit_req = linebuf3_valid_q &&
                            (linebuf3_tag_q == req_tag) &&
                            (linebuf3_idx_q == req_idx);
    wire linebuf4_hit_req = linebuf4_valid_q &&
                            (linebuf4_tag_q == req_tag) &&
                            (linebuf4_idx_q == req_idx);
    wire linebuf5_hit_req = linebuf5_valid_q &&
                            (linebuf5_tag_q == req_tag) &&
                            (linebuf5_idx_q == req_idx);
    wire linebuf6_hit_req = linebuf6_valid_q &&
                            (linebuf6_tag_q == req_tag) &&
                            (linebuf6_idx_q == req_idx);
    wire linebuf7_hit_req = linebuf7_valid_q &&
                            (linebuf7_tag_q == req_tag) &&
                            (linebuf7_idx_q == req_idx);
    wire linebuf8_hit_req = linebuf8_valid_q &&
                            (linebuf8_tag_q == req_tag) &&
                            (linebuf8_idx_q == req_idx);
    wire linebuf9_hit_req = linebuf9_valid_q &&
                            (linebuf9_tag_q == req_tag) &&
                            (linebuf9_idx_q == req_idx);
    wire linebuf10_hit_req = linebuf10_valid_q &&
                             (linebuf10_tag_q == req_tag) &&
                             (linebuf10_idx_q == req_idx);
    wire linebuf11_hit_req = linebuf11_valid_q &&
                             (linebuf11_tag_q == req_tag) &&
                             (linebuf11_idx_q == req_idx);
    wire linebuf12_hit_req = linebuf12_valid_q &&
                             (linebuf12_tag_q == req_tag) &&
                             (linebuf12_idx_q == req_idx);
    wire linebuf13_hit_req = linebuf13_valid_q &&
                             (linebuf13_tag_q == req_tag) &&
                             (linebuf13_idx_q == req_idx);
    wire linebuf14_hit_req = linebuf14_valid_q &&
                             (linebuf14_tag_q == req_tag) &&
                             (linebuf14_idx_q == req_idx);
    wire linebuf15_hit_req = linebuf15_valid_q &&
                             (linebuf15_tag_q == req_tag) &&
                             (linebuf15_idx_q == req_idx);
    wire linebuf_hit_req = linebuf0_hit_req || linebuf1_hit_req ||
                           linebuf2_hit_req || linebuf3_hit_req ||
                           linebuf4_hit_req || linebuf5_hit_req ||
                           linebuf6_hit_req || linebuf7_hit_req ||
                           linebuf8_hit_req || linebuf9_hit_req ||
                           linebuf10_hit_req || linebuf11_hit_req ||
                           linebuf12_hit_req || linebuf13_hit_req ||
                           linebuf14_hit_req || linebuf15_hit_req;
    wire rtbuf0_hit_req = rtbuf_valid_q &&
                          (rtbuf_tag_q == req_tag) &&
                          (rtbuf_idx_q == req_idx);
    wire rtbuf1_hit_req = rtbuf1_valid_q &&
                          (rtbuf1_tag_q == req_tag) &&
                          (rtbuf1_idx_q == req_idx);
    wire rtbuf2_hit_req = rtbuf2_valid_q &&
                          (rtbuf2_tag_q == req_tag) &&
                          (rtbuf2_idx_q == req_idx);
    wire rtbuf3_hit_req = rtbuf3_valid_q &&
                          (rtbuf3_tag_q == req_tag) &&
                          (rtbuf3_idx_q == req_idx);
    wire rtbuf4_hit_req = rtbuf4_valid_q &&
                          (rtbuf4_tag_q == req_tag) &&
                          (rtbuf4_idx_q == req_idx);
    wire rtbuf5_hit_req = rtbuf5_valid_q &&
                          (rtbuf5_tag_q == req_tag) &&
                          (rtbuf5_idx_q == req_idx);
    wire rtbuf6_hit_req = rtbuf6_valid_q &&
                          (rtbuf6_tag_q == req_tag) &&
                          (rtbuf6_idx_q == req_idx);
    wire rtbuf7_hit_req = rtbuf7_valid_q &&
                          (rtbuf7_tag_q == req_tag) &&
                          (rtbuf7_idx_q == req_idx);
    wire rtbuf_hit_req = rtbuf0_hit_req || rtbuf1_hit_req ||
                         rtbuf2_hit_req || rtbuf3_hit_req ||
                         rtbuf4_hit_req || rtbuf5_hit_req ||
                         rtbuf6_hit_req || rtbuf7_hit_req;
    wire [31:0] linebuf0_instr =
        (req_word_off == 2'd0) ? linebuf_data_q[0] :
        (req_word_off == 2'd1) ? linebuf_data_q[1] :
        (req_word_off == 2'd2) ? linebuf_data_q[2] : linebuf_data_q[3];
    wire [31:0] linebuf1_instr =
        (req_word_off == 2'd0) ? linebuf1_data_q[0] :
        (req_word_off == 2'd1) ? linebuf1_data_q[1] :
        (req_word_off == 2'd2) ? linebuf1_data_q[2] : linebuf1_data_q[3];
    wire [31:0] linebuf2_instr =
        (req_word_off == 2'd0) ? linebuf2_data_q[0] :
        (req_word_off == 2'd1) ? linebuf2_data_q[1] :
        (req_word_off == 2'd2) ? linebuf2_data_q[2] : linebuf2_data_q[3];
    wire [31:0] linebuf3_instr =
        (req_word_off == 2'd0) ? linebuf3_data_q[0] :
        (req_word_off == 2'd1) ? linebuf3_data_q[1] :
        (req_word_off == 2'd2) ? linebuf3_data_q[2] : linebuf3_data_q[3];
    wire [31:0] linebuf4_instr =
        (req_word_off == 2'd0) ? linebuf4_data_q[0] :
        (req_word_off == 2'd1) ? linebuf4_data_q[1] :
        (req_word_off == 2'd2) ? linebuf4_data_q[2] : linebuf4_data_q[3];
    wire [31:0] linebuf5_instr =
        (req_word_off == 2'd0) ? linebuf5_data_q[0] :
        (req_word_off == 2'd1) ? linebuf5_data_q[1] :
        (req_word_off == 2'd2) ? linebuf5_data_q[2] : linebuf5_data_q[3];
    wire [31:0] linebuf6_instr =
        (req_word_off == 2'd0) ? linebuf6_data_q[0] :
        (req_word_off == 2'd1) ? linebuf6_data_q[1] :
        (req_word_off == 2'd2) ? linebuf6_data_q[2] : linebuf6_data_q[3];
    wire [31:0] linebuf7_instr =
        (req_word_off == 2'd0) ? linebuf7_data_q[0] :
        (req_word_off == 2'd1) ? linebuf7_data_q[1] :
        (req_word_off == 2'd2) ? linebuf7_data_q[2] : linebuf7_data_q[3];
    wire [31:0] linebuf8_instr =
        (req_word_off == 2'd0) ? linebuf8_data_q[0] :
        (req_word_off == 2'd1) ? linebuf8_data_q[1] :
        (req_word_off == 2'd2) ? linebuf8_data_q[2] : linebuf8_data_q[3];
    wire [31:0] linebuf9_instr =
        (req_word_off == 2'd0) ? linebuf9_data_q[0] :
        (req_word_off == 2'd1) ? linebuf9_data_q[1] :
        (req_word_off == 2'd2) ? linebuf9_data_q[2] : linebuf9_data_q[3];
    wire [31:0] linebuf10_instr =
        (req_word_off == 2'd0) ? linebuf10_data_q[0] :
        (req_word_off == 2'd1) ? linebuf10_data_q[1] :
        (req_word_off == 2'd2) ? linebuf10_data_q[2] : linebuf10_data_q[3];
    wire [31:0] linebuf11_instr =
        (req_word_off == 2'd0) ? linebuf11_data_q[0] :
        (req_word_off == 2'd1) ? linebuf11_data_q[1] :
        (req_word_off == 2'd2) ? linebuf11_data_q[2] : linebuf11_data_q[3];
    wire [31:0] linebuf12_instr =
        (req_word_off == 2'd0) ? linebuf12_data_q[0] :
        (req_word_off == 2'd1) ? linebuf12_data_q[1] :
        (req_word_off == 2'd2) ? linebuf12_data_q[2] : linebuf12_data_q[3];
    wire [31:0] linebuf13_instr =
        (req_word_off == 2'd0) ? linebuf13_data_q[0] :
        (req_word_off == 2'd1) ? linebuf13_data_q[1] :
        (req_word_off == 2'd2) ? linebuf13_data_q[2] : linebuf13_data_q[3];
    wire [31:0] linebuf14_instr =
        (req_word_off == 2'd0) ? linebuf14_data_q[0] :
        (req_word_off == 2'd1) ? linebuf14_data_q[1] :
        (req_word_off == 2'd2) ? linebuf14_data_q[2] : linebuf14_data_q[3];
    wire [31:0] linebuf15_instr =
        (req_word_off == 2'd0) ? linebuf15_data_q[0] :
        (req_word_off == 2'd1) ? linebuf15_data_q[1] :
        (req_word_off == 2'd2) ? linebuf15_data_q[2] : linebuf15_data_q[3];
    wire [31:0] linebuf_instr =
        linebuf0_hit_req ? linebuf0_instr :
        linebuf1_hit_req ? linebuf1_instr :
        linebuf2_hit_req ? linebuf2_instr :
        linebuf3_hit_req ? linebuf3_instr :
        linebuf4_hit_req ? linebuf4_instr :
        linebuf5_hit_req ? linebuf5_instr :
        linebuf6_hit_req ? linebuf6_instr :
        linebuf7_hit_req ? linebuf7_instr :
        linebuf8_hit_req ? linebuf8_instr :
        linebuf9_hit_req ? linebuf9_instr :
        linebuf10_hit_req ? linebuf10_instr :
        linebuf11_hit_req ? linebuf11_instr :
        linebuf12_hit_req ? linebuf12_instr :
        linebuf13_hit_req ? linebuf13_instr :
        linebuf14_hit_req ? linebuf14_instr : linebuf15_instr;
    wire [31:0] rtbuf_instr =
        rtbuf0_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf_data_q[2] : rtbuf_data_q[3]) :
        rtbuf1_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf1_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf1_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf1_data_q[2] : rtbuf1_data_q[3]) :
        rtbuf2_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf2_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf2_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf2_data_q[2] : rtbuf2_data_q[3]) :
        rtbuf3_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf3_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf3_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf3_data_q[2] : rtbuf3_data_q[3]) :
        rtbuf4_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf4_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf4_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf4_data_q[2] : rtbuf4_data_q[3]) :
        rtbuf5_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf5_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf5_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf5_data_q[2] : rtbuf5_data_q[3]) :
        rtbuf6_hit_req ?
            ((req_word_off == 2'd0) ? rtbuf6_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf6_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf6_data_q[2] : rtbuf6_data_q[3]) :
            ((req_word_off == 2'd0) ? rtbuf7_data_q[0] :
             (req_word_off == 2'd1) ? rtbuf7_data_q[1] :
             (req_word_off == 2'd2) ? rtbuf7_data_q[2] : rtbuf7_data_q[3]);
    wire [TAG_WIDTH-1:0] rtbuf_hit_tag_w =
        rtbuf0_hit_req ? rtbuf_tag_q :
        rtbuf1_hit_req ? rtbuf1_tag_q :
        rtbuf2_hit_req ? rtbuf2_tag_q :
        rtbuf3_hit_req ? rtbuf3_tag_q :
        rtbuf4_hit_req ? rtbuf4_tag_q :
        rtbuf5_hit_req ? rtbuf5_tag_q :
        rtbuf6_hit_req ? rtbuf6_tag_q : rtbuf7_tag_q;
    wire [INDEX_WIDTH-1:0] rtbuf_hit_idx_w =
        rtbuf0_hit_req ? rtbuf_idx_q :
        rtbuf1_hit_req ? rtbuf1_idx_q :
        rtbuf2_hit_req ? rtbuf2_idx_q :
        rtbuf3_hit_req ? rtbuf3_idx_q :
        rtbuf4_hit_req ? rtbuf4_idx_q :
        rtbuf5_hit_req ? rtbuf5_idx_q :
        rtbuf6_hit_req ? rtbuf6_idx_q : rtbuf7_idx_q;
    wire [31:0] rtbuf_hit_word0_w =
        rtbuf0_hit_req ? rtbuf_data_q[0] :
        rtbuf1_hit_req ? rtbuf1_data_q[0] :
        rtbuf2_hit_req ? rtbuf2_data_q[0] :
        rtbuf3_hit_req ? rtbuf3_data_q[0] :
        rtbuf4_hit_req ? rtbuf4_data_q[0] :
        rtbuf5_hit_req ? rtbuf5_data_q[0] :
        rtbuf6_hit_req ? rtbuf6_data_q[0] : rtbuf7_data_q[0];
    wire [31:0] rtbuf_hit_word1_w =
        rtbuf0_hit_req ? rtbuf_data_q[1] :
        rtbuf1_hit_req ? rtbuf1_data_q[1] :
        rtbuf2_hit_req ? rtbuf2_data_q[1] :
        rtbuf3_hit_req ? rtbuf3_data_q[1] :
        rtbuf4_hit_req ? rtbuf4_data_q[1] :
        rtbuf5_hit_req ? rtbuf5_data_q[1] :
        rtbuf6_hit_req ? rtbuf6_data_q[1] : rtbuf7_data_q[1];
    wire [31:0] rtbuf_hit_word2_w =
        rtbuf0_hit_req ? rtbuf_data_q[2] :
        rtbuf1_hit_req ? rtbuf1_data_q[2] :
        rtbuf2_hit_req ? rtbuf2_data_q[2] :
        rtbuf3_hit_req ? rtbuf3_data_q[2] :
        rtbuf4_hit_req ? rtbuf4_data_q[2] :
        rtbuf5_hit_req ? rtbuf5_data_q[2] :
        rtbuf6_hit_req ? rtbuf6_data_q[2] : rtbuf7_data_q[2];
    wire [31:0] rtbuf_hit_word3_w =
        rtbuf0_hit_req ? rtbuf_data_q[3] :
        rtbuf1_hit_req ? rtbuf1_data_q[3] :
        rtbuf2_hit_req ? rtbuf2_data_q[3] :
        rtbuf3_hit_req ? rtbuf3_data_q[3] :
        rtbuf4_hit_req ? rtbuf4_data_q[3] :
        rtbuf5_hit_req ? rtbuf5_data_q[3] :
        rtbuf6_hit_req ? rtbuf6_data_q[3] : rtbuf7_data_q[3];
    wire rtbuf_pending_lookup_hit_w =
        rtbuf_pending_q &&
        (lookup_hit_addr_w[XLEN-1:OFFSET_WIDTH] ==
         rtbuf_pending_addr_q[XLEN-1:OFFSET_WIDTH]);
    wire rtbuf_pending_miss_hit_w =
        rtbuf_pending_q &&
        (miss_addr_q[XLEN-1:OFFSET_WIDTH] ==
         rtbuf_pending_addr_q[XLEN-1:OFFSET_WIDTH]);

    task automatic push_linebuf;
        input                  new_valid;
        input [TAG_WIDTH-1:0]  new_tag;
        input [INDEX_WIDTH-1:0] new_idx;
        input [31:0]           new_word0;
        input [31:0]           new_word1;
        input [31:0]           new_word2;
        input [31:0]           new_word3;
        begin
            linebuf15_valid_q  <= linebuf14_valid_q;
            linebuf15_tag_q    <= linebuf14_tag_q;
            linebuf15_idx_q    <= linebuf14_idx_q;
            linebuf15_data_q[0] <= linebuf14_data_q[0];
            linebuf15_data_q[1] <= linebuf14_data_q[1];
            linebuf15_data_q[2] <= linebuf14_data_q[2];
            linebuf15_data_q[3] <= linebuf14_data_q[3];
            linebuf14_valid_q  <= linebuf13_valid_q;
            linebuf14_tag_q    <= linebuf13_tag_q;
            linebuf14_idx_q    <= linebuf13_idx_q;
            linebuf14_data_q[0] <= linebuf13_data_q[0];
            linebuf14_data_q[1] <= linebuf13_data_q[1];
            linebuf14_data_q[2] <= linebuf13_data_q[2];
            linebuf14_data_q[3] <= linebuf13_data_q[3];
            linebuf13_valid_q  <= linebuf12_valid_q;
            linebuf13_tag_q    <= linebuf12_tag_q;
            linebuf13_idx_q    <= linebuf12_idx_q;
            linebuf13_data_q[0] <= linebuf12_data_q[0];
            linebuf13_data_q[1] <= linebuf12_data_q[1];
            linebuf13_data_q[2] <= linebuf12_data_q[2];
            linebuf13_data_q[3] <= linebuf12_data_q[3];
            linebuf12_valid_q  <= linebuf11_valid_q;
            linebuf12_tag_q    <= linebuf11_tag_q;
            linebuf12_idx_q    <= linebuf11_idx_q;
            linebuf12_data_q[0] <= linebuf11_data_q[0];
            linebuf12_data_q[1] <= linebuf11_data_q[1];
            linebuf12_data_q[2] <= linebuf11_data_q[2];
            linebuf12_data_q[3] <= linebuf11_data_q[3];
            linebuf11_valid_q  <= linebuf10_valid_q;
            linebuf11_tag_q    <= linebuf10_tag_q;
            linebuf11_idx_q    <= linebuf10_idx_q;
            linebuf11_data_q[0] <= linebuf10_data_q[0];
            linebuf11_data_q[1] <= linebuf10_data_q[1];
            linebuf11_data_q[2] <= linebuf10_data_q[2];
            linebuf11_data_q[3] <= linebuf10_data_q[3];
            linebuf10_valid_q  <= linebuf9_valid_q;
            linebuf10_tag_q    <= linebuf9_tag_q;
            linebuf10_idx_q    <= linebuf9_idx_q;
            linebuf10_data_q[0] <= linebuf9_data_q[0];
            linebuf10_data_q[1] <= linebuf9_data_q[1];
            linebuf10_data_q[2] <= linebuf9_data_q[2];
            linebuf10_data_q[3] <= linebuf9_data_q[3];
            linebuf9_valid_q  <= linebuf8_valid_q;
            linebuf9_tag_q    <= linebuf8_tag_q;
            linebuf9_idx_q    <= linebuf8_idx_q;
            linebuf9_data_q[0] <= linebuf8_data_q[0];
            linebuf9_data_q[1] <= linebuf8_data_q[1];
            linebuf9_data_q[2] <= linebuf8_data_q[2];
            linebuf9_data_q[3] <= linebuf8_data_q[3];
            linebuf8_valid_q  <= linebuf7_valid_q;
            linebuf8_tag_q    <= linebuf7_tag_q;
            linebuf8_idx_q    <= linebuf7_idx_q;
            linebuf8_data_q[0] <= linebuf7_data_q[0];
            linebuf8_data_q[1] <= linebuf7_data_q[1];
            linebuf8_data_q[2] <= linebuf7_data_q[2];
            linebuf8_data_q[3] <= linebuf7_data_q[3];
            linebuf7_valid_q  <= linebuf6_valid_q;
            linebuf7_tag_q    <= linebuf6_tag_q;
            linebuf7_idx_q    <= linebuf6_idx_q;
            linebuf7_data_q[0] <= linebuf6_data_q[0];
            linebuf7_data_q[1] <= linebuf6_data_q[1];
            linebuf7_data_q[2] <= linebuf6_data_q[2];
            linebuf7_data_q[3] <= linebuf6_data_q[3];
            linebuf6_valid_q  <= linebuf5_valid_q;
            linebuf6_tag_q    <= linebuf5_tag_q;
            linebuf6_idx_q    <= linebuf5_idx_q;
            linebuf6_data_q[0] <= linebuf5_data_q[0];
            linebuf6_data_q[1] <= linebuf5_data_q[1];
            linebuf6_data_q[2] <= linebuf5_data_q[2];
            linebuf6_data_q[3] <= linebuf5_data_q[3];
            linebuf5_valid_q  <= linebuf4_valid_q;
            linebuf5_tag_q    <= linebuf4_tag_q;
            linebuf5_idx_q    <= linebuf4_idx_q;
            linebuf5_data_q[0] <= linebuf4_data_q[0];
            linebuf5_data_q[1] <= linebuf4_data_q[1];
            linebuf5_data_q[2] <= linebuf4_data_q[2];
            linebuf5_data_q[3] <= linebuf4_data_q[3];
            linebuf4_valid_q  <= linebuf3_valid_q;
            linebuf4_tag_q    <= linebuf3_tag_q;
            linebuf4_idx_q    <= linebuf3_idx_q;
            linebuf4_data_q[0] <= linebuf3_data_q[0];
            linebuf4_data_q[1] <= linebuf3_data_q[1];
            linebuf4_data_q[2] <= linebuf3_data_q[2];
            linebuf4_data_q[3] <= linebuf3_data_q[3];
            linebuf3_valid_q  <= linebuf2_valid_q;
            linebuf3_tag_q    <= linebuf2_tag_q;
            linebuf3_idx_q    <= linebuf2_idx_q;
            linebuf3_data_q[0] <= linebuf2_data_q[0];
            linebuf3_data_q[1] <= linebuf2_data_q[1];
            linebuf3_data_q[2] <= linebuf2_data_q[2];
            linebuf3_data_q[3] <= linebuf2_data_q[3];
            linebuf2_valid_q  <= linebuf1_valid_q;
            linebuf2_tag_q    <= linebuf1_tag_q;
            linebuf2_idx_q    <= linebuf1_idx_q;
            linebuf2_data_q[0] <= linebuf1_data_q[0];
            linebuf2_data_q[1] <= linebuf1_data_q[1];
            linebuf2_data_q[2] <= linebuf1_data_q[2];
            linebuf2_data_q[3] <= linebuf1_data_q[3];
            linebuf1_valid_q  <= linebuf_valid_q;
            linebuf1_tag_q    <= linebuf_tag_q;
            linebuf1_idx_q    <= linebuf_idx_q;
            linebuf1_data_q[0] <= linebuf_data_q[0];
            linebuf1_data_q[1] <= linebuf_data_q[1];
            linebuf1_data_q[2] <= linebuf_data_q[2];
            linebuf1_data_q[3] <= linebuf_data_q[3];
            linebuf_valid_q   <= new_valid;
            linebuf_tag_q     <= new_tag;
            linebuf_idx_q     <= new_idx;
            linebuf_data_q[0] <= new_word0;
            linebuf_data_q[1] <= new_word1;
            linebuf_data_q[2] <= new_word2;
            linebuf_data_q[3] <= new_word3;
        end
    endtask

    task automatic fill_rtbuf;
        input                  new_valid;
        input [TAG_WIDTH-1:0]  new_tag;
        input [INDEX_WIDTH-1:0] new_idx;
        input [31:0]           new_word0;
        input [31:0]           new_word1;
        input [31:0]           new_word2;
        input [31:0]           new_word3;
        reg hit0;
        reg hit1;
        reg hit2;
        reg hit3;
        reg hit4;
        reg hit5;
        reg hit6;
        begin
            hit0 = new_valid && rtbuf_valid_q &&
                   (rtbuf_tag_q == new_tag) && (rtbuf_idx_q == new_idx);
            hit1 = new_valid && rtbuf1_valid_q &&
                   (rtbuf1_tag_q == new_tag) && (rtbuf1_idx_q == new_idx);
            hit2 = new_valid && rtbuf2_valid_q &&
                   (rtbuf2_tag_q == new_tag) && (rtbuf2_idx_q == new_idx);
            hit3 = new_valid && rtbuf3_valid_q &&
                   (rtbuf3_tag_q == new_tag) && (rtbuf3_idx_q == new_idx);
            hit4 = new_valid && rtbuf4_valid_q &&
                   (rtbuf4_tag_q == new_tag) && (rtbuf4_idx_q == new_idx);
            hit5 = new_valid && rtbuf5_valid_q &&
                   (rtbuf5_tag_q == new_tag) && (rtbuf5_idx_q == new_idx);
            hit6 = new_valid && rtbuf6_valid_q &&
                   (rtbuf6_tag_q == new_tag) && (rtbuf6_idx_q == new_idx);
            if (!hit0) begin
                if (!hit1 && !hit2 && !hit3 && !hit4 && !hit5 && !hit6) begin
                    rtbuf7_valid_q   <= rtbuf6_valid_q;
                    rtbuf7_tag_q     <= rtbuf6_tag_q;
                    rtbuf7_idx_q     <= rtbuf6_idx_q;
                    rtbuf7_data_q[0] <= rtbuf6_data_q[0];
                    rtbuf7_data_q[1] <= rtbuf6_data_q[1];
                    rtbuf7_data_q[2] <= rtbuf6_data_q[2];
                    rtbuf7_data_q[3] <= rtbuf6_data_q[3];
                end
                if (!hit1 && !hit2 && !hit3 && !hit4 && !hit5) begin
                    rtbuf6_valid_q   <= rtbuf5_valid_q;
                    rtbuf6_tag_q     <= rtbuf5_tag_q;
                    rtbuf6_idx_q     <= rtbuf5_idx_q;
                    rtbuf6_data_q[0] <= rtbuf5_data_q[0];
                    rtbuf6_data_q[1] <= rtbuf5_data_q[1];
                    rtbuf6_data_q[2] <= rtbuf5_data_q[2];
                    rtbuf6_data_q[3] <= rtbuf5_data_q[3];
                end
                if (!hit1 && !hit2 && !hit3 && !hit4) begin
                    rtbuf5_valid_q   <= rtbuf4_valid_q;
                    rtbuf5_tag_q     <= rtbuf4_tag_q;
                    rtbuf5_idx_q     <= rtbuf4_idx_q;
                    rtbuf5_data_q[0] <= rtbuf4_data_q[0];
                    rtbuf5_data_q[1] <= rtbuf4_data_q[1];
                    rtbuf5_data_q[2] <= rtbuf4_data_q[2];
                    rtbuf5_data_q[3] <= rtbuf4_data_q[3];
                end
                if (!hit1 && !hit2 && !hit3) begin
                    rtbuf4_valid_q   <= rtbuf3_valid_q;
                    rtbuf4_tag_q     <= rtbuf3_tag_q;
                    rtbuf4_idx_q     <= rtbuf3_idx_q;
                    rtbuf4_data_q[0] <= rtbuf3_data_q[0];
                    rtbuf4_data_q[1] <= rtbuf3_data_q[1];
                    rtbuf4_data_q[2] <= rtbuf3_data_q[2];
                    rtbuf4_data_q[3] <= rtbuf3_data_q[3];
                end
                if (!hit1 && !hit2) begin
                    rtbuf3_valid_q   <= rtbuf2_valid_q;
                    rtbuf3_tag_q     <= rtbuf2_tag_q;
                    rtbuf3_idx_q     <= rtbuf2_idx_q;
                    rtbuf3_data_q[0] <= rtbuf2_data_q[0];
                    rtbuf3_data_q[1] <= rtbuf2_data_q[1];
                    rtbuf3_data_q[2] <= rtbuf2_data_q[2];
                    rtbuf3_data_q[3] <= rtbuf2_data_q[3];
                end
                if (!hit1) begin
                    rtbuf2_valid_q   <= rtbuf1_valid_q;
                    rtbuf2_tag_q     <= rtbuf1_tag_q;
                    rtbuf2_idx_q     <= rtbuf1_idx_q;
                    rtbuf2_data_q[0] <= rtbuf1_data_q[0];
                    rtbuf2_data_q[1] <= rtbuf1_data_q[1];
                    rtbuf2_data_q[2] <= rtbuf1_data_q[2];
                    rtbuf2_data_q[3] <= rtbuf1_data_q[3];
                end
                rtbuf1_valid_q   <= rtbuf_valid_q;
                rtbuf1_tag_q     <= rtbuf_tag_q;
                rtbuf1_idx_q     <= rtbuf_idx_q;
                rtbuf1_data_q[0] <= rtbuf_data_q[0];
                rtbuf1_data_q[1] <= rtbuf_data_q[1];
                rtbuf1_data_q[2] <= rtbuf_data_q[2];
                rtbuf1_data_q[3] <= rtbuf_data_q[3];
            end
            rtbuf_valid_q   <= new_valid;
            rtbuf_tag_q     <= new_tag;
            rtbuf_idx_q     <= new_idx;
            rtbuf_data_q[0] <= new_word0;
            rtbuf_data_q[1] <= new_word1;
            rtbuf_data_q[2] <= new_word2;
            rtbuf_data_q[3] <= new_word3;
            rtbuf_pending_q <= 1'b0;
        end
    endtask

    task automatic fill_altbuf;
        input                  new_valid;
        input [TAG_WIDTH-1:0]  new_tag;
        input [INDEX_WIDTH-1:0] new_idx;
        input [31:0]           new_word0;
        input [31:0]           new_word1;
        input [31:0]           new_word2;
        input [31:0]           new_word3;
        reg hit0;
        begin
            hit0 = new_valid && altbuf_valid_q &&
                   (altbuf_tag_q == new_tag) && (altbuf_idx_q == new_idx);
            if (!hit0) begin
                altbuf1_valid_q   <= altbuf_valid_q;
                altbuf1_tag_q     <= altbuf_tag_q;
                altbuf1_idx_q     <= altbuf_idx_q;
                altbuf1_data_q[0] <= altbuf_data_q[0];
                altbuf1_data_q[1] <= altbuf_data_q[1];
                altbuf1_data_q[2] <= altbuf_data_q[2];
                altbuf1_data_q[3] <= altbuf_data_q[3];
            end
            altbuf_valid_q   <= new_valid;
            altbuf_tag_q     <= new_tag;
            altbuf_idx_q     <= new_idx;
            altbuf_data_q[0] <= new_word0;
            altbuf_data_q[1] <= new_word1;
            altbuf_data_q[2] <= new_word2;
            altbuf_data_q[3] <= new_word3;
        end
    endtask

    wire pfbuf0_hit_req = pfbuf_valid_q &&
                          (pfbuf_tag_q == req_tag) &&
                          (pfbuf_idx_q == req_idx);
    wire pfbuf1_hit_req = pfbuf1_valid_q &&
                          (pfbuf1_tag_q == req_tag) &&
                          (pfbuf1_idx_q == req_idx);
    wire pfbuf_hit_req = pfbuf0_hit_req || pfbuf1_hit_req;
    wire altbuf_hit_req = altbuf_valid_q &&
                          (altbuf_tag_q == req_tag) &&
                          (altbuf_idx_q == req_idx);
    wire altbuf1_hit_req = altbuf1_valid_q &&
                           (altbuf1_tag_q == req_tag) &&
                           (altbuf1_idx_q == req_idx);
    wire altbuf_any_hit_req = altbuf_hit_req || altbuf1_hit_req;
    wire [31:0] pfbuf_instr =
        pfbuf0_hit_req ?
            ((req_word_off == 2'd0) ? pfbuf_data_q[0] :
             (req_word_off == 2'd1) ? pfbuf_data_q[1] :
             (req_word_off == 2'd2) ? pfbuf_data_q[2] : pfbuf_data_q[3]) :
            ((req_word_off == 2'd0) ? pfbuf1_data_q[0] :
             (req_word_off == 2'd1) ? pfbuf1_data_q[1] :
             (req_word_off == 2'd2) ? pfbuf1_data_q[2] : pfbuf1_data_q[3]);
    wire [31:0] altbuf_instr =
        altbuf_hit_req ?
            ((req_word_off == 2'd0) ? altbuf_data_q[0] :
             (req_word_off == 2'd1) ? altbuf_data_q[1] :
             (req_word_off == 2'd2) ? altbuf_data_q[2] : altbuf_data_q[3]) :
            ((req_word_off == 2'd0) ? altbuf1_data_q[0] :
             (req_word_off == 2'd1) ? altbuf1_data_q[1] :
             (req_word_off == 2'd2) ? altbuf1_data_q[2] : altbuf1_data_q[3]);
    wire [TAG_WIDTH-1:0] altbuf_hit_tag_w =
        altbuf_hit_req ? altbuf_tag_q : altbuf1_tag_q;
    wire [INDEX_WIDTH-1:0] altbuf_hit_idx_w =
        altbuf_hit_req ? altbuf_idx_q : altbuf1_idx_q;
    wire [31:0] altbuf_hit_word0_w =
        altbuf_hit_req ? altbuf_data_q[0] : altbuf1_data_q[0];
    wire [31:0] altbuf_hit_word1_w =
        altbuf_hit_req ? altbuf_data_q[1] : altbuf1_data_q[1];
    wire [31:0] altbuf_hit_word2_w =
        altbuf_hit_req ? altbuf_data_q[2] : altbuf1_data_q[2];
    wire [31:0] altbuf_hit_word3_w =
        altbuf_hit_req ? altbuf_data_q[3] : altbuf1_data_q[3];
    wire [TAG_WIDTH-1:0] pfbuf_hit_tag_w =
        pfbuf0_hit_req ? pfbuf_tag_q : pfbuf1_tag_q;
    wire [INDEX_WIDTH-1:0] pfbuf_hit_idx_w =
        pfbuf0_hit_req ? pfbuf_idx_q : pfbuf1_idx_q;
    wire [31:0] pfbuf_hit_word0_w =
        pfbuf0_hit_req ? pfbuf_data_q[0] : pfbuf1_data_q[0];
    wire [31:0] pfbuf_hit_word1_w =
        pfbuf0_hit_req ? pfbuf_data_q[1] : pfbuf1_data_q[1];
    wire [31:0] pfbuf_hit_word2_w =
        pfbuf0_hit_req ? pfbuf_data_q[2] : pfbuf1_data_q[2];
    wire [31:0] pfbuf_hit_word3_w =
        pfbuf0_hit_req ? pfbuf_data_q[3] : pfbuf1_data_q[3];
    wire fastbuf_hit_req =
        linebuf_hit_req || rtbuf_hit_req || pfbuf_hit_req ||
        altbuf_any_hit_req;
    wire [31:0] fastbuf_instr =
        linebuf_hit_req ? linebuf_instr :
        rtbuf_hit_req   ? rtbuf_instr :
        pfbuf_hit_req   ? pfbuf_instr : altbuf_instr;

    wire redirect_probe_linebuf0_hit_w = linebuf_valid_q &&
                                         (linebuf_tag_q == redirect_probe_tag) &&
                                         (linebuf_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf1_hit_w = linebuf1_valid_q &&
                                         (linebuf1_tag_q == redirect_probe_tag) &&
                                         (linebuf1_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf2_hit_w = linebuf2_valid_q &&
                                         (linebuf2_tag_q == redirect_probe_tag) &&
                                         (linebuf2_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf3_hit_w = linebuf3_valid_q &&
                                         (linebuf3_tag_q == redirect_probe_tag) &&
                                         (linebuf3_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf4_hit_w = linebuf4_valid_q &&
                                         (linebuf4_tag_q == redirect_probe_tag) &&
                                         (linebuf4_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf5_hit_w = linebuf5_valid_q &&
                                         (linebuf5_tag_q == redirect_probe_tag) &&
                                         (linebuf5_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf6_hit_w = linebuf6_valid_q &&
                                         (linebuf6_tag_q == redirect_probe_tag) &&
                                         (linebuf6_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf7_hit_w = linebuf7_valid_q &&
                                         (linebuf7_tag_q == redirect_probe_tag) &&
                                         (linebuf7_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf8_hit_w = linebuf8_valid_q &&
                                         (linebuf8_tag_q == redirect_probe_tag) &&
                                         (linebuf8_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf9_hit_w = linebuf9_valid_q &&
                                         (linebuf9_tag_q == redirect_probe_tag) &&
                                         (linebuf9_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf10_hit_w = linebuf10_valid_q &&
                                          (linebuf10_tag_q == redirect_probe_tag) &&
                                          (linebuf10_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf11_hit_w = linebuf11_valid_q &&
                                          (linebuf11_tag_q == redirect_probe_tag) &&
                                          (linebuf11_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf12_hit_w = linebuf12_valid_q &&
                                          (linebuf12_tag_q == redirect_probe_tag) &&
                                          (linebuf12_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf13_hit_w = linebuf13_valid_q &&
                                          (linebuf13_tag_q == redirect_probe_tag) &&
                                          (linebuf13_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf14_hit_w = linebuf14_valid_q &&
                                          (linebuf14_tag_q == redirect_probe_tag) &&
                                          (linebuf14_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf15_hit_w = linebuf15_valid_q &&
                                          (linebuf15_tag_q == redirect_probe_tag) &&
                                          (linebuf15_idx_q == redirect_probe_idx);
    wire redirect_probe_linebuf_hit_w =
        redirect_probe_linebuf0_hit_w || redirect_probe_linebuf1_hit_w ||
        redirect_probe_linebuf2_hit_w || redirect_probe_linebuf3_hit_w ||
        redirect_probe_linebuf4_hit_w || redirect_probe_linebuf5_hit_w ||
        redirect_probe_linebuf6_hit_w || redirect_probe_linebuf7_hit_w ||
        redirect_probe_linebuf8_hit_w || redirect_probe_linebuf9_hit_w ||
        redirect_probe_linebuf10_hit_w || redirect_probe_linebuf11_hit_w ||
        redirect_probe_linebuf12_hit_w || redirect_probe_linebuf13_hit_w ||
        redirect_probe_linebuf14_hit_w || redirect_probe_linebuf15_hit_w;
    wire redirect_probe_rtbuf0_hit_w = rtbuf_valid_q &&
                                       (rtbuf_tag_q == redirect_probe_tag) &&
                                       (rtbuf_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf1_hit_w = rtbuf1_valid_q &&
                                       (rtbuf1_tag_q == redirect_probe_tag) &&
                                       (rtbuf1_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf2_hit_w = rtbuf2_valid_q &&
                                       (rtbuf2_tag_q == redirect_probe_tag) &&
                                       (rtbuf2_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf3_hit_w = rtbuf3_valid_q &&
                                       (rtbuf3_tag_q == redirect_probe_tag) &&
                                       (rtbuf3_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf4_hit_w = rtbuf4_valid_q &&
                                       (rtbuf4_tag_q == redirect_probe_tag) &&
                                       (rtbuf4_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf5_hit_w = rtbuf5_valid_q &&
                                       (rtbuf5_tag_q == redirect_probe_tag) &&
                                       (rtbuf5_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf6_hit_w = rtbuf6_valid_q &&
                                       (rtbuf6_tag_q == redirect_probe_tag) &&
                                       (rtbuf6_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf7_hit_w = rtbuf7_valid_q &&
                                       (rtbuf7_tag_q == redirect_probe_tag) &&
                                       (rtbuf7_idx_q == redirect_probe_idx);
    wire redirect_probe_rtbuf_hit_w =
        redirect_probe_rtbuf0_hit_w || redirect_probe_rtbuf1_hit_w ||
        redirect_probe_rtbuf2_hit_w || redirect_probe_rtbuf3_hit_w ||
        redirect_probe_rtbuf4_hit_w || redirect_probe_rtbuf5_hit_w ||
        redirect_probe_rtbuf6_hit_w || redirect_probe_rtbuf7_hit_w;
    wire [31:0] redirect_probe_linebuf0_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf_data_q[2] : linebuf_data_q[3];
    wire [31:0] redirect_probe_linebuf1_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf1_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf1_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf1_data_q[2] : linebuf1_data_q[3];
    wire [31:0] redirect_probe_linebuf2_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf2_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf2_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf2_data_q[2] : linebuf2_data_q[3];
    wire [31:0] redirect_probe_linebuf3_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf3_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf3_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf3_data_q[2] : linebuf3_data_q[3];
    wire [31:0] redirect_probe_linebuf4_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf4_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf4_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf4_data_q[2] : linebuf4_data_q[3];
    wire [31:0] redirect_probe_linebuf5_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf5_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf5_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf5_data_q[2] : linebuf5_data_q[3];
    wire [31:0] redirect_probe_linebuf6_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf6_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf6_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf6_data_q[2] : linebuf6_data_q[3];
    wire [31:0] redirect_probe_linebuf7_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf7_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf7_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf7_data_q[2] : linebuf7_data_q[3];
    wire [31:0] redirect_probe_linebuf8_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf8_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf8_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf8_data_q[2] : linebuf8_data_q[3];
    wire [31:0] redirect_probe_linebuf9_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf9_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf9_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf9_data_q[2] : linebuf9_data_q[3];
    wire [31:0] redirect_probe_linebuf10_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf10_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf10_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf10_data_q[2] : linebuf10_data_q[3];
    wire [31:0] redirect_probe_linebuf11_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf11_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf11_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf11_data_q[2] : linebuf11_data_q[3];
    wire [31:0] redirect_probe_linebuf12_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf12_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf12_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf12_data_q[2] : linebuf12_data_q[3];
    wire [31:0] redirect_probe_linebuf13_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf13_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf13_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf13_data_q[2] : linebuf13_data_q[3];
    wire [31:0] redirect_probe_linebuf14_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf14_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf14_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf14_data_q[2] : linebuf14_data_q[3];
    wire [31:0] redirect_probe_linebuf15_instr_w =
        (redirect_probe_word_off == 2'd0) ? linebuf15_data_q[0] :
        (redirect_probe_word_off == 2'd1) ? linebuf15_data_q[1] :
        (redirect_probe_word_off == 2'd2) ? linebuf15_data_q[2] : linebuf15_data_q[3];
    wire [31:0] redirect_probe_linebuf_instr_w =
        redirect_probe_linebuf0_hit_w ? redirect_probe_linebuf0_instr_w :
        redirect_probe_linebuf1_hit_w ? redirect_probe_linebuf1_instr_w :
        redirect_probe_linebuf2_hit_w ? redirect_probe_linebuf2_instr_w :
        redirect_probe_linebuf3_hit_w ? redirect_probe_linebuf3_instr_w :
        redirect_probe_linebuf4_hit_w ? redirect_probe_linebuf4_instr_w :
        redirect_probe_linebuf5_hit_w ? redirect_probe_linebuf5_instr_w :
        redirect_probe_linebuf6_hit_w ? redirect_probe_linebuf6_instr_w :
        redirect_probe_linebuf7_hit_w ? redirect_probe_linebuf7_instr_w :
        redirect_probe_linebuf8_hit_w ? redirect_probe_linebuf8_instr_w :
        redirect_probe_linebuf9_hit_w ? redirect_probe_linebuf9_instr_w :
        redirect_probe_linebuf10_hit_w ? redirect_probe_linebuf10_instr_w :
        redirect_probe_linebuf11_hit_w ? redirect_probe_linebuf11_instr_w :
        redirect_probe_linebuf12_hit_w ? redirect_probe_linebuf12_instr_w :
        redirect_probe_linebuf13_hit_w ? redirect_probe_linebuf13_instr_w :
        redirect_probe_linebuf14_hit_w ? redirect_probe_linebuf14_instr_w :
                                         redirect_probe_linebuf15_instr_w;
    wire [31:0] redirect_probe_rtbuf_instr_w =
        redirect_probe_rtbuf0_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf_data_q[2] : rtbuf_data_q[3]) :
        redirect_probe_rtbuf1_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf1_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf1_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf1_data_q[2] : rtbuf1_data_q[3]) :
        redirect_probe_rtbuf2_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf2_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf2_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf2_data_q[2] : rtbuf2_data_q[3]) :
        redirect_probe_rtbuf3_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf3_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf3_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf3_data_q[2] : rtbuf3_data_q[3]) :
        redirect_probe_rtbuf4_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf4_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf4_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf4_data_q[2] : rtbuf4_data_q[3]) :
        redirect_probe_rtbuf5_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf5_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf5_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf5_data_q[2] : rtbuf5_data_q[3]) :
        redirect_probe_rtbuf6_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? rtbuf6_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf6_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf6_data_q[2] : rtbuf6_data_q[3]) :
            ((redirect_probe_word_off == 2'd0) ? rtbuf7_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? rtbuf7_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? rtbuf7_data_q[2] : rtbuf7_data_q[3]);
    wire [TAG_WIDTH-1:0] redirect_probe_rtbuf_tag_w =
        redirect_probe_rtbuf0_hit_w ? rtbuf_tag_q :
        redirect_probe_rtbuf1_hit_w ? rtbuf1_tag_q :
        redirect_probe_rtbuf2_hit_w ? rtbuf2_tag_q :
        redirect_probe_rtbuf3_hit_w ? rtbuf3_tag_q :
        redirect_probe_rtbuf4_hit_w ? rtbuf4_tag_q :
        redirect_probe_rtbuf5_hit_w ? rtbuf5_tag_q :
        redirect_probe_rtbuf6_hit_w ? rtbuf6_tag_q : rtbuf7_tag_q;
    wire [INDEX_WIDTH-1:0] redirect_probe_rtbuf_idx_w =
        redirect_probe_rtbuf0_hit_w ? rtbuf_idx_q :
        redirect_probe_rtbuf1_hit_w ? rtbuf1_idx_q :
        redirect_probe_rtbuf2_hit_w ? rtbuf2_idx_q :
        redirect_probe_rtbuf3_hit_w ? rtbuf3_idx_q :
        redirect_probe_rtbuf4_hit_w ? rtbuf4_idx_q :
        redirect_probe_rtbuf5_hit_w ? rtbuf5_idx_q :
        redirect_probe_rtbuf6_hit_w ? rtbuf6_idx_q : rtbuf7_idx_q;
    wire [31:0] redirect_probe_rtbuf_word0_w =
        redirect_probe_rtbuf0_hit_w ? rtbuf_data_q[0] :
        redirect_probe_rtbuf1_hit_w ? rtbuf1_data_q[0] :
        redirect_probe_rtbuf2_hit_w ? rtbuf2_data_q[0] :
        redirect_probe_rtbuf3_hit_w ? rtbuf3_data_q[0] :
        redirect_probe_rtbuf4_hit_w ? rtbuf4_data_q[0] :
        redirect_probe_rtbuf5_hit_w ? rtbuf5_data_q[0] :
        redirect_probe_rtbuf6_hit_w ? rtbuf6_data_q[0] : rtbuf7_data_q[0];
    wire [31:0] redirect_probe_rtbuf_word1_w =
        redirect_probe_rtbuf0_hit_w ? rtbuf_data_q[1] :
        redirect_probe_rtbuf1_hit_w ? rtbuf1_data_q[1] :
        redirect_probe_rtbuf2_hit_w ? rtbuf2_data_q[1] :
        redirect_probe_rtbuf3_hit_w ? rtbuf3_data_q[1] :
        redirect_probe_rtbuf4_hit_w ? rtbuf4_data_q[1] :
        redirect_probe_rtbuf5_hit_w ? rtbuf5_data_q[1] :
        redirect_probe_rtbuf6_hit_w ? rtbuf6_data_q[1] : rtbuf7_data_q[1];
    wire [31:0] redirect_probe_rtbuf_word2_w =
        redirect_probe_rtbuf0_hit_w ? rtbuf_data_q[2] :
        redirect_probe_rtbuf1_hit_w ? rtbuf1_data_q[2] :
        redirect_probe_rtbuf2_hit_w ? rtbuf2_data_q[2] :
        redirect_probe_rtbuf3_hit_w ? rtbuf3_data_q[2] :
        redirect_probe_rtbuf4_hit_w ? rtbuf4_data_q[2] :
        redirect_probe_rtbuf5_hit_w ? rtbuf5_data_q[2] :
        redirect_probe_rtbuf6_hit_w ? rtbuf6_data_q[2] : rtbuf7_data_q[2];
    wire [31:0] redirect_probe_rtbuf_word3_w =
        redirect_probe_rtbuf0_hit_w ? rtbuf_data_q[3] :
        redirect_probe_rtbuf1_hit_w ? rtbuf1_data_q[3] :
        redirect_probe_rtbuf2_hit_w ? rtbuf2_data_q[3] :
        redirect_probe_rtbuf3_hit_w ? rtbuf3_data_q[3] :
        redirect_probe_rtbuf4_hit_w ? rtbuf4_data_q[3] :
        redirect_probe_rtbuf5_hit_w ? rtbuf5_data_q[3] :
        redirect_probe_rtbuf6_hit_w ? rtbuf6_data_q[3] : rtbuf7_data_q[3];
    wire [TAG_WIDTH-1:0] redirect_probe_linebuf_tag_w =
        redirect_probe_linebuf0_hit_w ? linebuf_tag_q :
        redirect_probe_linebuf1_hit_w ? linebuf1_tag_q :
        redirect_probe_linebuf2_hit_w ? linebuf2_tag_q :
        redirect_probe_linebuf3_hit_w ? linebuf3_tag_q :
        redirect_probe_linebuf4_hit_w ? linebuf4_tag_q :
        redirect_probe_linebuf5_hit_w ? linebuf5_tag_q :
        redirect_probe_linebuf6_hit_w ? linebuf6_tag_q :
        redirect_probe_linebuf7_hit_w ? linebuf7_tag_q :
        redirect_probe_linebuf8_hit_w ? linebuf8_tag_q :
        redirect_probe_linebuf9_hit_w ? linebuf9_tag_q :
        redirect_probe_linebuf10_hit_w ? linebuf10_tag_q :
        redirect_probe_linebuf11_hit_w ? linebuf11_tag_q :
        redirect_probe_linebuf12_hit_w ? linebuf12_tag_q :
        redirect_probe_linebuf13_hit_w ? linebuf13_tag_q :
        redirect_probe_linebuf14_hit_w ? linebuf14_tag_q : linebuf15_tag_q;
    wire [INDEX_WIDTH-1:0] redirect_probe_linebuf_idx_w =
        redirect_probe_linebuf0_hit_w ? linebuf_idx_q :
        redirect_probe_linebuf1_hit_w ? linebuf1_idx_q :
        redirect_probe_linebuf2_hit_w ? linebuf2_idx_q :
        redirect_probe_linebuf3_hit_w ? linebuf3_idx_q :
        redirect_probe_linebuf4_hit_w ? linebuf4_idx_q :
        redirect_probe_linebuf5_hit_w ? linebuf5_idx_q :
        redirect_probe_linebuf6_hit_w ? linebuf6_idx_q :
        redirect_probe_linebuf7_hit_w ? linebuf7_idx_q :
        redirect_probe_linebuf8_hit_w ? linebuf8_idx_q :
        redirect_probe_linebuf9_hit_w ? linebuf9_idx_q :
        redirect_probe_linebuf10_hit_w ? linebuf10_idx_q :
        redirect_probe_linebuf11_hit_w ? linebuf11_idx_q :
        redirect_probe_linebuf12_hit_w ? linebuf12_idx_q :
        redirect_probe_linebuf13_hit_w ? linebuf13_idx_q :
        redirect_probe_linebuf14_hit_w ? linebuf14_idx_q : linebuf15_idx_q;
    wire [31:0] redirect_probe_linebuf_word0_w =
        redirect_probe_linebuf0_hit_w ? linebuf_data_q[0] :
        redirect_probe_linebuf1_hit_w ? linebuf1_data_q[0] :
        redirect_probe_linebuf2_hit_w ? linebuf2_data_q[0] :
        redirect_probe_linebuf3_hit_w ? linebuf3_data_q[0] :
        redirect_probe_linebuf4_hit_w ? linebuf4_data_q[0] :
        redirect_probe_linebuf5_hit_w ? linebuf5_data_q[0] :
        redirect_probe_linebuf6_hit_w ? linebuf6_data_q[0] :
        redirect_probe_linebuf7_hit_w ? linebuf7_data_q[0] :
        redirect_probe_linebuf8_hit_w ? linebuf8_data_q[0] :
        redirect_probe_linebuf9_hit_w ? linebuf9_data_q[0] :
        redirect_probe_linebuf10_hit_w ? linebuf10_data_q[0] :
        redirect_probe_linebuf11_hit_w ? linebuf11_data_q[0] :
        redirect_probe_linebuf12_hit_w ? linebuf12_data_q[0] :
        redirect_probe_linebuf13_hit_w ? linebuf13_data_q[0] :
        redirect_probe_linebuf14_hit_w ? linebuf14_data_q[0] : linebuf15_data_q[0];
    wire [31:0] redirect_probe_linebuf_word1_w =
        redirect_probe_linebuf0_hit_w ? linebuf_data_q[1] :
        redirect_probe_linebuf1_hit_w ? linebuf1_data_q[1] :
        redirect_probe_linebuf2_hit_w ? linebuf2_data_q[1] :
        redirect_probe_linebuf3_hit_w ? linebuf3_data_q[1] :
        redirect_probe_linebuf4_hit_w ? linebuf4_data_q[1] :
        redirect_probe_linebuf5_hit_w ? linebuf5_data_q[1] :
        redirect_probe_linebuf6_hit_w ? linebuf6_data_q[1] :
        redirect_probe_linebuf7_hit_w ? linebuf7_data_q[1] :
        redirect_probe_linebuf8_hit_w ? linebuf8_data_q[1] :
        redirect_probe_linebuf9_hit_w ? linebuf9_data_q[1] :
        redirect_probe_linebuf10_hit_w ? linebuf10_data_q[1] :
        redirect_probe_linebuf11_hit_w ? linebuf11_data_q[1] :
        redirect_probe_linebuf12_hit_w ? linebuf12_data_q[1] :
        redirect_probe_linebuf13_hit_w ? linebuf13_data_q[1] :
        redirect_probe_linebuf14_hit_w ? linebuf14_data_q[1] : linebuf15_data_q[1];
    wire [31:0] redirect_probe_linebuf_word2_w =
        redirect_probe_linebuf0_hit_w ? linebuf_data_q[2] :
        redirect_probe_linebuf1_hit_w ? linebuf1_data_q[2] :
        redirect_probe_linebuf2_hit_w ? linebuf2_data_q[2] :
        redirect_probe_linebuf3_hit_w ? linebuf3_data_q[2] :
        redirect_probe_linebuf4_hit_w ? linebuf4_data_q[2] :
        redirect_probe_linebuf5_hit_w ? linebuf5_data_q[2] :
        redirect_probe_linebuf6_hit_w ? linebuf6_data_q[2] :
        redirect_probe_linebuf7_hit_w ? linebuf7_data_q[2] :
        redirect_probe_linebuf8_hit_w ? linebuf8_data_q[2] :
        redirect_probe_linebuf9_hit_w ? linebuf9_data_q[2] :
        redirect_probe_linebuf10_hit_w ? linebuf10_data_q[2] :
        redirect_probe_linebuf11_hit_w ? linebuf11_data_q[2] :
        redirect_probe_linebuf12_hit_w ? linebuf12_data_q[2] :
        redirect_probe_linebuf13_hit_w ? linebuf13_data_q[2] :
        redirect_probe_linebuf14_hit_w ? linebuf14_data_q[2] : linebuf15_data_q[2];
    wire [31:0] redirect_probe_linebuf_word3_w =
        redirect_probe_linebuf0_hit_w ? linebuf_data_q[3] :
        redirect_probe_linebuf1_hit_w ? linebuf1_data_q[3] :
        redirect_probe_linebuf2_hit_w ? linebuf2_data_q[3] :
        redirect_probe_linebuf3_hit_w ? linebuf3_data_q[3] :
        redirect_probe_linebuf4_hit_w ? linebuf4_data_q[3] :
        redirect_probe_linebuf5_hit_w ? linebuf5_data_q[3] :
        redirect_probe_linebuf6_hit_w ? linebuf6_data_q[3] :
        redirect_probe_linebuf7_hit_w ? linebuf7_data_q[3] :
        redirect_probe_linebuf8_hit_w ? linebuf8_data_q[3] :
        redirect_probe_linebuf9_hit_w ? linebuf9_data_q[3] :
        redirect_probe_linebuf10_hit_w ? linebuf10_data_q[3] :
        redirect_probe_linebuf11_hit_w ? linebuf11_data_q[3] :
        redirect_probe_linebuf12_hit_w ? linebuf12_data_q[3] :
        redirect_probe_linebuf13_hit_w ? linebuf13_data_q[3] :
        redirect_probe_linebuf14_hit_w ? linebuf14_data_q[3] : linebuf15_data_q[3];
    wire redirect_probe_pfbuf0_hit_w = pfbuf_valid_q &&
                                       (pfbuf_tag_q == redirect_probe_tag) &&
                                       (pfbuf_idx_q == redirect_probe_idx);
    wire redirect_probe_pfbuf1_hit_w = pfbuf1_valid_q &&
                                       (pfbuf1_tag_q == redirect_probe_tag) &&
                                       (pfbuf1_idx_q == redirect_probe_idx);
    wire redirect_probe_pfbuf_hit_w =
        redirect_probe_pfbuf0_hit_w || redirect_probe_pfbuf1_hit_w;
    wire redirect_probe_altbuf_hit_w = altbuf_valid_q &&
                                       (altbuf_tag_q == redirect_probe_tag) &&
                                       (altbuf_idx_q == redirect_probe_idx);
    wire redirect_probe_altbuf1_hit_w = altbuf1_valid_q &&
                                        (altbuf1_tag_q == redirect_probe_tag) &&
                                        (altbuf1_idx_q == redirect_probe_idx);
    wire redirect_probe_altbuf_any_hit_w =
        redirect_probe_altbuf_hit_w || redirect_probe_altbuf1_hit_w;
    wire [TAG_WIDTH-1:0] redirect_probe_altbuf_tag_w =
        redirect_probe_altbuf_hit_w ? altbuf_tag_q : altbuf1_tag_q;
    wire [INDEX_WIDTH-1:0] redirect_probe_altbuf_idx_w =
        redirect_probe_altbuf_hit_w ? altbuf_idx_q : altbuf1_idx_q;
    wire [31:0] redirect_probe_pfbuf_instr_w =
        redirect_probe_pfbuf0_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? pfbuf_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? pfbuf_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? pfbuf_data_q[2] : pfbuf_data_q[3]) :
            ((redirect_probe_word_off == 2'd0) ? pfbuf1_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? pfbuf1_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? pfbuf1_data_q[2] : pfbuf1_data_q[3]);
    wire [TAG_WIDTH-1:0] redirect_probe_pfbuf_tag_w =
        redirect_probe_pfbuf0_hit_w ? pfbuf_tag_q : pfbuf1_tag_q;
    wire [INDEX_WIDTH-1:0] redirect_probe_pfbuf_idx_w =
        redirect_probe_pfbuf0_hit_w ? pfbuf_idx_q : pfbuf1_idx_q;
    wire [31:0] redirect_probe_pfbuf_word0_w =
        redirect_probe_pfbuf0_hit_w ? pfbuf_data_q[0] : pfbuf1_data_q[0];
    wire [31:0] redirect_probe_pfbuf_word1_w =
        redirect_probe_pfbuf0_hit_w ? pfbuf_data_q[1] : pfbuf1_data_q[1];
    wire [31:0] redirect_probe_pfbuf_word2_w =
        redirect_probe_pfbuf0_hit_w ? pfbuf_data_q[2] : pfbuf1_data_q[2];
    wire [31:0] redirect_probe_pfbuf_word3_w =
        redirect_probe_pfbuf0_hit_w ? pfbuf_data_q[3] : pfbuf1_data_q[3];
    wire [31:0] redirect_probe_altbuf_instr_w =
        redirect_probe_altbuf_hit_w ?
            ((redirect_probe_word_off == 2'd0) ? altbuf_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? altbuf_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? altbuf_data_q[2] :
                                                 altbuf_data_q[3]) :
            ((redirect_probe_word_off == 2'd0) ? altbuf1_data_q[0] :
             (redirect_probe_word_off == 2'd1) ? altbuf1_data_q[1] :
             (redirect_probe_word_off == 2'd2) ? altbuf1_data_q[2] :
                                                 altbuf1_data_q[3]);
    wire [31:0] redirect_probe_altbuf_word0_w =
        redirect_probe_altbuf_hit_w ? altbuf_data_q[0] : altbuf1_data_q[0];
    wire [31:0] redirect_probe_altbuf_word1_w =
        redirect_probe_altbuf_hit_w ? altbuf_data_q[1] : altbuf1_data_q[1];
    wire [31:0] redirect_probe_altbuf_word2_w =
        redirect_probe_altbuf_hit_w ? altbuf_data_q[2] : altbuf1_data_q[2];
    wire [31:0] redirect_probe_altbuf_word3_w =
        redirect_probe_altbuf_hit_w ? altbuf_data_q[3] : altbuf1_data_q[3];
    wire redirect_probe_fastbuf_hit_w =
        redirect_probe_linebuf_hit_w || redirect_probe_rtbuf_hit_w ||
        redirect_probe_pfbuf_hit_w || redirect_probe_altbuf_any_hit_w;
    wire [31:0] redirect_probe_fastbuf_instr_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_instr_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_instr_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_instr_w :
                                       redirect_probe_altbuf_instr_w;
    wire [TAG_WIDTH-1:0] redirect_probe_fastbuf_tag_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_tag_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_tag_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_tag_w :
                                       redirect_probe_altbuf_tag_w;
    wire [INDEX_WIDTH-1:0] redirect_probe_fastbuf_idx_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_idx_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_idx_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_idx_w :
                                       redirect_probe_altbuf_idx_w;
    wire [31:0] redirect_probe_fastbuf_word0_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_word0_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_word0_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_word0_w :
                                       redirect_probe_altbuf_word0_w;
    wire [31:0] redirect_probe_fastbuf_word1_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_word1_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_word1_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_word1_w :
                                       redirect_probe_altbuf_word1_w;
    wire [31:0] redirect_probe_fastbuf_word2_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_word2_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_word2_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_word2_w :
                                       redirect_probe_altbuf_word2_w;
    wire [31:0] redirect_probe_fastbuf_word3_w =
        redirect_probe_linebuf_hit_w ? redirect_probe_linebuf_word3_w :
        redirect_probe_rtbuf_hit_w   ? redirect_probe_rtbuf_word3_w :
        redirect_probe_pfbuf_hit_w   ? redirect_probe_pfbuf_word3_w :
                                       redirect_probe_altbuf_word3_w;
    assign redirect_probe_lookup_start_w =
        ENABLE_REDIRECT_PROBE_LOOKUP &&
        flush && redirect_probe_valid_i && !redirect_probe_fastbuf_hit_w;
    wire probe_lookup_hit_complete_w =
        ENABLE_REDIRECT_PROBE_LOOKUP &&
        (state_q == ST_LOOKUP) && probe_lookup_valid_d2 && (|way_hit_q);
    wire shadow_probe_hit_complete_w =
        (state_q == ST_LOOKUP) && shadow_probe_valid_d2 && (|way_hit_q);
    wire lookahead_probe_hit_complete_w =
        ENABLE_L1_LOOKAHEAD_PROBE &&
        (state_q == ST_LOOKUP) && lookahead_probe_valid_d2 && (|way_hit_q);
    wire [1:0] probe_lookup_word_off_w = probe_lookup_addr_d2[OFFSET_WIDTH-1 : 2];
    wire [31:0] probe_lookup_instr_w =
        (probe_lookup_word_off_w == 2'd0) ? hit_line_word0 :
        (probe_lookup_word_off_w == 2'd1) ? hit_line_word1 :
        (probe_lookup_word_off_w == 2'd2) ? hit_line_word2 : hit_line_word3;
    assign redirect_probe_hit_o = redirect_probe_valid_i && redirect_probe_fastbuf_hit_w;

    reg            redirect_fast_valid_q;
    reg [XLEN-1:0] redirect_fast_addr_q;
    reg [ILEN-1:0] redirect_fast_instr_q;
    reg            redirect_fast_line_valid_q;
    reg [XLEN-1:0] redirect_fast_line_addr_q;
    reg [ILEN-1:0] redirect_fast_line_word0_q;
    reg [ILEN-1:0] redirect_fast_line_word1_q;
    reg [ILEN-1:0] redirect_fast_line_word2_q;
    reg [ILEN-1:0] redirect_fast_line_word3_q;

    assign redirect_fast_valid_o = redirect_fast_valid_q;
    assign redirect_fast_addr_o  = redirect_fast_addr_q;
    assign redirect_fast_instr_o = redirect_fast_instr_q;
    assign redirect_fast_line_valid_o = redirect_fast_line_valid_q;
    assign redirect_fast_line_addr_o  = redirect_fast_line_addr_q;
    assign redirect_fast_line_data_o_0 = redirect_fast_line_word0_q;
    assign redirect_fast_line_data_o_1 = redirect_fast_line_word1_q;
    assign redirect_fast_line_data_o_2 = redirect_fast_line_word2_q;
    assign redirect_fast_line_data_o_3 = redirect_fast_line_word3_q;

    reg                  resp_done_q  [0:RESP_DEPTH-1];
    reg [31:0]           resp_data_q  [0:RESP_DEPTH-1];
    reg [XLEN-1:0]       resp_addr_q  [0:RESP_DEPTH-1];
    reg                  resp_line_valid_q [0:RESP_DEPTH-1];
    reg [31:0]           resp_line_word0_q [0:RESP_DEPTH-1];
    reg [31:0]           resp_line_word1_q [0:RESP_DEPTH-1];
    reg [31:0]           resp_line_word2_q [0:RESP_DEPTH-1];
    reg [31:0]           resp_line_word3_q [0:RESP_DEPTH-1];
    reg                  resp_wait_lookup_q [0:RESP_DEPTH-1];
    reg                  resp_lookup_merge_q [0:RESP_DEPTH-1];
    reg                  resp_wait_miss_q [0:RESP_DEPTH-1];
    reg [RESP_PTR_W-1:0] resp_wr_ptr_q;
    reg [RESP_PTR_W-1:0] resp_rd_ptr_q;
    reg [RESP_PTR_W:0]   resp_count_q;

    reg [RESP_PTR_W-1:0] lookup_resp_slot_q;
    reg [RESP_PTR_W-1:0] lookup_resp_slot_d1;
    reg [RESP_PTR_W-1:0] lookup_resp_slot_d2;
    reg [RESP_PTR_W-1:0] miss_resp_slot_q;

    wire resp_fifo_empty_w = (resp_count_q == {(RESP_PTR_W+1){1'b0}});
    wire resp_fifo_full_w  = (resp_count_q == RESP_DEPTH_COUNT);
    wire resp_head_done_w  = !resp_fifo_empty_w && resp_done_q[resp_rd_ptr_q];
    wire resp_emit_w       = resp_head_done_w;

    wire early_lookup_hit_complete_w =
        ENABLE_L1_EARLY_LOOKUP_HIT &&
        (state_q == ST_LOOKUP) && lookup_valid_d1 &&
        !probe_lookup_valid_d1 && !shadow_probe_valid_d1 &&
        !lookahead_probe_valid_d1 &&
        normal_cache_hit_comb;
    wire early_lookup_miss_complete_w =
        ENABLE_L1_EARLY_LOOKUP_MISS &&
        (state_q == ST_LOOKUP) && lookup_valid_d1 &&
        !probe_lookup_valid_d1 && !shadow_probe_valid_d1 &&
        !lookahead_probe_valid_d1 &&
        !normal_cache_hit_comb;
    wire lookup_hit_complete_late_w =
        (state_q == ST_LOOKUP) && lookup_valid_d2 && cache_hit_q;
    wire lookup_miss_complete_late_w =
        (state_q == ST_LOOKUP) && lookup_valid_d2 && !cache_hit_q;
    wire lookup_miss_w =
        early_lookup_miss_complete_w || lookup_miss_complete_late_w;
    wire lookup_hit_complete_w =
        early_lookup_hit_complete_w || lookup_hit_complete_late_w;
    wire miss_complete_w = (state_q == ST_MISS) && l2_resp_valid_i;
    wire [31:0] miss_resp_data_w =
        (miss_word_off == 2'd0) ? l2_resp_data_i_0 :
        (miss_word_off == 2'd1) ? l2_resp_data_i_1 :
        (miss_word_off == 2'd2) ? l2_resp_data_i_2 : l2_resp_data_i_3;
    wire lookup_resp_bypass_w =
        !resp_head_done_w && !resp_fifo_empty_w &&
        ((early_lookup_hit_complete_w &&
          (lookup_resp_slot_d1 == resp_rd_ptr_q)) ||
         (lookup_hit_complete_late_w &&
          (lookup_resp_slot_d2 == resp_rd_ptr_q)));
    wire miss_resp_bypass_w =
        !resp_head_done_w && !resp_fifo_empty_w &&
        miss_complete_w && (miss_resp_slot_q == resp_rd_ptr_q);
    wire resp_bypass_w = lookup_resp_bypass_w || miss_resp_bypass_w;
    wire resp_pop_w    = resp_emit_w || resp_bypass_w;
    wire [31:0] lookup_hit_data_w =
        early_lookup_hit_complete_w ? early_hit_data : hit_data;
    wire [31:0] lookup_hit_line_word0_w =
        early_lookup_hit_complete_w ? early_hit_line_word0 : hit_line_word0;
    wire [31:0] lookup_hit_line_word1_w =
        early_lookup_hit_complete_w ? early_hit_line_word1 : hit_line_word1;
    wire [31:0] lookup_hit_line_word2_w =
        early_lookup_hit_complete_w ? early_hit_line_word2 : hit_line_word2;
    wire [31:0] lookup_hit_line_word3_w =
        early_lookup_hit_complete_w ? early_hit_line_word3 : hit_line_word3;
    wire [XLEN-1:0] lookup_hit_addr_w =
        early_lookup_hit_complete_w ? lookup_addr_d1 : lookup_addr_d2;
    wire [RESP_PTR_W-1:0] lookup_hit_resp_slot_w =
        early_lookup_hit_complete_w ? lookup_resp_slot_d1 : lookup_resp_slot_d2;
    wire [XLEN-1:0] lookup_miss_addr_w =
        early_lookup_miss_complete_w ? lookup_addr_d1 : lookup_addr_d2;
    wire [RESP_PTR_W-1:0] lookup_miss_resp_slot_w =
        early_lookup_miss_complete_w ? lookup_resp_slot_d1 : lookup_resp_slot_d2;
    wire [31:0] resp_bypass_data_w =
        lookup_resp_bypass_w ? lookup_hit_data_w : miss_resp_data_w;
    wire [31:0] resp_bypass_line_word0_w =
        lookup_resp_bypass_w ? lookup_hit_line_word0_w : l2_resp_data_i_0;
    wire [31:0] resp_bypass_line_word1_w =
        lookup_resp_bypass_w ? lookup_hit_line_word1_w : l2_resp_data_i_1;
    wire [31:0] resp_bypass_line_word2_w =
        lookup_resp_bypass_w ? lookup_hit_line_word2_w : l2_resp_data_i_2;
    wire [31:0] resp_bypass_line_word3_w =
        lookup_resp_bypass_w ? lookup_hit_line_word3_w : l2_resp_data_i_3;
    wire [31:0] fastbuf_line_word0_w =
        linebuf_hit_req ? (
            linebuf0_hit_req ? linebuf_data_q[0] :
            linebuf1_hit_req ? linebuf1_data_q[0] :
            linebuf2_hit_req ? linebuf2_data_q[0] :
            linebuf3_hit_req ? linebuf3_data_q[0] :
            linebuf4_hit_req ? linebuf4_data_q[0] :
            linebuf5_hit_req ? linebuf5_data_q[0] :
            linebuf6_hit_req ? linebuf6_data_q[0] :
            linebuf7_hit_req ? linebuf7_data_q[0] :
            linebuf8_hit_req ? linebuf8_data_q[0] :
            linebuf9_hit_req ? linebuf9_data_q[0] :
            linebuf10_hit_req ? linebuf10_data_q[0] :
            linebuf11_hit_req ? linebuf11_data_q[0] :
            linebuf12_hit_req ? linebuf12_data_q[0] :
            linebuf13_hit_req ? linebuf13_data_q[0] :
            linebuf14_hit_req ? linebuf14_data_q[0] : linebuf15_data_q[0]
        ) : rtbuf_hit_req ? rtbuf_hit_word0_w :
            pfbuf_hit_req ? pfbuf_hit_word0_w : altbuf_hit_word0_w;
    wire [31:0] fastbuf_line_word1_w =
        linebuf_hit_req ? (
            linebuf0_hit_req ? linebuf_data_q[1] :
            linebuf1_hit_req ? linebuf1_data_q[1] :
            linebuf2_hit_req ? linebuf2_data_q[1] :
            linebuf3_hit_req ? linebuf3_data_q[1] :
            linebuf4_hit_req ? linebuf4_data_q[1] :
            linebuf5_hit_req ? linebuf5_data_q[1] :
            linebuf6_hit_req ? linebuf6_data_q[1] :
            linebuf7_hit_req ? linebuf7_data_q[1] :
            linebuf8_hit_req ? linebuf8_data_q[1] :
            linebuf9_hit_req ? linebuf9_data_q[1] :
            linebuf10_hit_req ? linebuf10_data_q[1] :
            linebuf11_hit_req ? linebuf11_data_q[1] :
            linebuf12_hit_req ? linebuf12_data_q[1] :
            linebuf13_hit_req ? linebuf13_data_q[1] :
            linebuf14_hit_req ? linebuf14_data_q[1] : linebuf15_data_q[1]
        ) : rtbuf_hit_req ? rtbuf_hit_word1_w :
            pfbuf_hit_req ? pfbuf_hit_word1_w : altbuf_hit_word1_w;
    wire [31:0] fastbuf_line_word2_w =
        linebuf_hit_req ? (
            linebuf0_hit_req ? linebuf_data_q[2] :
            linebuf1_hit_req ? linebuf1_data_q[2] :
            linebuf2_hit_req ? linebuf2_data_q[2] :
            linebuf3_hit_req ? linebuf3_data_q[2] :
            linebuf4_hit_req ? linebuf4_data_q[2] :
            linebuf5_hit_req ? linebuf5_data_q[2] :
            linebuf6_hit_req ? linebuf6_data_q[2] :
            linebuf7_hit_req ? linebuf7_data_q[2] :
            linebuf8_hit_req ? linebuf8_data_q[2] :
            linebuf9_hit_req ? linebuf9_data_q[2] :
            linebuf10_hit_req ? linebuf10_data_q[2] :
            linebuf11_hit_req ? linebuf11_data_q[2] :
            linebuf12_hit_req ? linebuf12_data_q[2] :
            linebuf13_hit_req ? linebuf13_data_q[2] :
            linebuf14_hit_req ? linebuf14_data_q[2] : linebuf15_data_q[2]
        ) : rtbuf_hit_req ? rtbuf_hit_word2_w :
            pfbuf_hit_req ? pfbuf_hit_word2_w : altbuf_hit_word2_w;
    wire [31:0] fastbuf_line_word3_w =
        linebuf_hit_req ? (
            linebuf0_hit_req ? linebuf_data_q[3] :
            linebuf1_hit_req ? linebuf1_data_q[3] :
            linebuf2_hit_req ? linebuf2_data_q[3] :
            linebuf3_hit_req ? linebuf3_data_q[3] :
            linebuf4_hit_req ? linebuf4_data_q[3] :
            linebuf5_hit_req ? linebuf5_data_q[3] :
            linebuf6_hit_req ? linebuf6_data_q[3] :
            linebuf7_hit_req ? linebuf7_data_q[3] :
            linebuf8_hit_req ? linebuf8_data_q[3] :
            linebuf9_hit_req ? linebuf9_data_q[3] :
            linebuf10_hit_req ? linebuf10_data_q[3] :
            linebuf11_hit_req ? linebuf11_data_q[3] :
            linebuf12_hit_req ? linebuf12_data_q[3] :
            linebuf13_hit_req ? linebuf13_data_q[3] :
            linebuf14_hit_req ? linebuf14_data_q[3] : linebuf15_data_q[3]
        ) : rtbuf_hit_req ? rtbuf_hit_word3_w :
            pfbuf_hit_req ? pfbuf_hit_word3_w : altbuf_hit_word3_w;
    wire lookup_idle_w = !lookup_valid_q && !lookup_valid_d1 && !lookup_valid_d2;
    wire lookup_head_inflight_w =
        !resp_fifo_empty_w &&
        ((lookup_valid_q  && (lookup_resp_slot_q  == resp_rd_ptr_q)) ||
         (lookup_valid_d1 && (lookup_resp_slot_d1 == resp_rd_ptr_q)) ||
         (lookup_valid_d2 && (lookup_resp_slot_d2 == resp_rd_ptr_q)));
    wire replay_lookup_pending_w =
        !resp_fifo_empty_w && resp_wait_lookup_q[resp_rd_ptr_q] &&
        !resp_done_q[resp_rd_ptr_q] && !lookup_head_inflight_w;
    wire demand_l2_resp_pending_w = (state_q == ST_MISS) &&
                                    (!l2_req_valid_o || l2_req_ready_i);
    wire prefetch_l2_resp_pending_w = pf_inflight_q &&
                                      (!l2_req_valid_o || l2_req_ready_i);
    wire flush_leaves_l2_resp_w = (demand_l2_resp_pending_w ||
                                   prefetch_l2_resp_pending_w) &&
                                  !l2_resp_valid_i;
    wire req_same_line_lookup_q_w =
        lookup_valid_q &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] ==
         lookup_addr_q[XLEN-1:OFFSET_WIDTH]);
    wire req_same_line_lookup_d1_w =
        lookup_valid_d1 &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] ==
         lookup_addr_d1[XLEN-1:OFFSET_WIDTH]);
    wire req_same_line_lookup_d2_w =
        lookup_valid_d2 &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] ==
         lookup_addr_d2[XLEN-1:OFFSET_WIDTH]);
    wire lookup_merge_req_w =
        (state_q == ST_LOOKUP) &&
        (req_same_line_lookup_q_w ||
         req_same_line_lookup_d1_w ||
         req_same_line_lookup_d2_w);
    wire req_same_line_probe_q_w =
        probe_lookup_valid_q &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] ==
         probe_lookup_addr_q[XLEN-1:OFFSET_WIDTH]);
    wire req_same_line_probe_d1_w =
        probe_lookup_valid_d1 &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] ==
         probe_lookup_addr_d1[XLEN-1:OFFSET_WIDTH]);
    wire req_same_line_probe_d2_w =
        probe_lookup_valid_d2 &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] ==
         probe_lookup_addr_d2[XLEN-1:OFFSET_WIDTH]);
    wire probe_merge_req_w =
        ENABLE_REDIRECT_PROBE_LOOKUP &&
        (state_q == ST_LOOKUP) &&
        (req_same_line_probe_q_w ||
         req_same_line_probe_d1_w ||
         req_same_line_probe_d2_w);
    wire lookup_merge_ready_w =
        lookup_merge_req_w && !resp_fifo_full_w &&
        !stale_l2_resp_pending_q && !pf_inflight_q && !l2_req_valid_o;
    wire probe_lookup_blocks_req_w =
        probe_merge_req_w && !fastbuf_hit_req;
    wire probe_merge_ready_w = 1'b0;
    wire miss_merge_req_w =
        (state_q == ST_MISS) &&
        (req_addr_i[XLEN-1:OFFSET_WIDTH] == miss_addr_q[XLEN-1:OFFSET_WIDTH]);
    wire miss_merge_ready_w =
        miss_merge_req_w && !l2_resp_valid_i && !resp_fifo_full_w;
    wire early_miss_merge_ready_w =
        early_lookup_miss_complete_w && req_same_line_lookup_d1_w &&
        !resp_fifo_full_w;

    // CPU 侧 ready 必须覆盖整条查找流水：
    // 已经有 lookup 在 T0/T1/T2 中飞行时，同一条 16B line 的后续 word
    // 可以先分配响应槽并绑定到该 lookup；若老 lookup hit，T3 用同一条
    // line 的 4 个 word 填完这些槽；若老 lookup miss，所有同 line 槽一起
    // 转为等待同一条 L2 refill。其他地址等待，避免单端口 BRAM 读地址被覆盖，
    // 也避免 cold miss/错路取指提前扩大 L2 压力。
    // linebuf/pfbuf 命中不访问 BRAM，可在没有 pending miss 时直接接收。
    // 预取在途时，非 buffer 命中请求先等待，避免 L2 预取响应和 demand miss
    // 响应在同一个 4-word 返回口上失配。
    assign cacop_ready_o = !flush &&
                           (state_q == ST_LOOKUP) &&
                           !pf_inflight_q && !l2_req_valid_o &&
                           !stale_l2_resp_pending_q;
    wire req_lookup_ready_w = (state_q == ST_LOOKUP) && !lookup_miss_w &&
                              !resp_fifo_full_w &&
                              !replay_lookup_pending_w &&
                              (fastbuf_hit_req || probe_merge_ready_w ||
                               lookup_merge_ready_w ||
                               (!probe_lookup_blocks_req_w &&
                                !stale_l2_resp_pending_q &&
                                !pf_inflight_q && !l2_req_valid_o));
    assign req_ready_o = !flush && !cacop_valid_i &&
                         (req_lookup_ready_w || miss_merge_ready_w ||
                          early_miss_merge_ready_w);

    wire req_fire_w         = req_valid_i && req_ready_o;
    wire req_linebuf_fire_w = req_fire_w && linebuf_hit_req;
    wire req_rtbuf_fire_w   =
        req_fire_w && !linebuf_hit_req && rtbuf_hit_req;
    wire req_pfbuf_fire_w   =
        req_fire_w && !linebuf_hit_req && !rtbuf_hit_req && pfbuf_hit_req;
    wire req_altbuf_fire_w  =
        req_fire_w && !linebuf_hit_req && !rtbuf_hit_req &&
        !pfbuf_hit_req && altbuf_any_hit_req;
    wire req_pfbuf0_fire_w  =
        req_fire_w && !linebuf_hit_req && !rtbuf_hit_req && pfbuf0_hit_req;
    wire req_pfbuf1_fire_w  = req_fire_w && !linebuf_hit_req && !rtbuf_hit_req &&
                              !pfbuf0_hit_req && pfbuf1_hit_req;
    wire req_miss_merge_fire_w =
        req_fire_w &&
        ((state_q == ST_MISS) || early_miss_merge_ready_w);
    wire req_lookup_merge_fire_w =
        req_fire_w && (state_q == ST_LOOKUP) && lookup_merge_ready_w &&
        !fastbuf_hit_req && !early_miss_merge_ready_w;
    wire req_probe_merge_fire_w =
        req_fire_w && (state_q == ST_LOOKUP) && probe_merge_ready_w &&
        !fastbuf_hit_req && !req_lookup_merge_fire_w;
    wire req_lookup_merge_hit_complete_w =
        req_lookup_merge_fire_w && lookup_hit_complete_w &&
        (early_lookup_hit_complete_w ? req_same_line_lookup_d1_w :
                                       req_same_line_lookup_d2_w);
    wire req_probe_merge_hit_complete_w =
        req_probe_merge_fire_w && probe_lookup_hit_complete_w &&
        req_same_line_probe_d2_w;
    wire [31:0] req_lookup_merge_hit_data_w =
        (req_word_off == 2'd0) ? lookup_hit_line_word0_w :
        (req_word_off == 2'd1) ? lookup_hit_line_word1_w :
        (req_word_off == 2'd2) ? lookup_hit_line_word2_w :
                                 lookup_hit_line_word3_w;
    wire [31:0] req_probe_merge_hit_data_w =
        (req_word_off == 2'd0) ? hit_line_word0 :
        (req_word_off == 2'd1) ? hit_line_word1 :
        (req_word_off == 2'd2) ? hit_line_word2 : hit_line_word3;
    wire req_fastbuf_fire_w =
        req_fire_w && (state_q == ST_LOOKUP) && fastbuf_hit_req;
    wire req_fastbuf_direct_resp_w =
        req_fastbuf_fire_w && resp_fifo_empty_w;
    wire req_lookup_fire_w  =
        req_fire_w && (state_q == ST_LOOKUP) && !fastbuf_hit_req &&
        !req_lookup_merge_fire_w && !req_probe_merge_fire_w &&
        !early_miss_merge_ready_w;
    wire req_enqueue_w = req_fire_w && !req_fastbuf_direct_resp_w;
    wire [RESP_PTR_W-1:0] req_resp_slot_w = resp_wr_ptr_q;
    wire replay_lookup_fire_w =
        (state_q == ST_LOOKUP) && !lookup_miss_w &&
        replay_lookup_pending_w && !stale_l2_resp_pending_q &&
        !pf_inflight_q && !l2_req_valid_o && !cacop_valid_i;
    wire lookup_issue_valid_w = replay_lookup_fire_w || req_lookup_fire_w;
    wire [XLEN-1:0] lookup_issue_addr_w =
        replay_lookup_fire_w ? resp_addr_q[resp_rd_ptr_q] : req_addr_i;
    wire [RESP_PTR_W-1:0] lookup_issue_slot_w =
        replay_lookup_fire_w ? resp_rd_ptr_q : req_resp_slot_w;

    wire [XLEN-1:0] linebuf_base_addr =
        {linebuf_tag_q, linebuf_idx_q, {OFFSET_WIDTH{1'b0}}};
    wire [XLEN-1:0] linebuf_next_addr = linebuf_base_addr + LINE_SIZE;
    wire [XLEN-1:0] linebuf_next2_addr = linebuf_base_addr + (LINE_SIZE << 1);
    wire [TAG_WIDTH-1:0] linebuf_next_tag =
        linebuf_next_addr[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] linebuf_next_idx =
        linebuf_next_addr[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [TAG_WIDTH-1:0] linebuf_next2_tag =
        linebuf_next2_addr[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] linebuf_next2_idx =
        linebuf_next2_addr[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire pfbuf_holds_next_w =
        (pfbuf_valid_q &&
         (pfbuf_tag_q == linebuf_next_tag) &&
         (pfbuf_idx_q == linebuf_next_idx)) ||
        (pfbuf1_valid_q &&
         (pfbuf1_tag_q == linebuf_next_tag) &&
         (pfbuf1_idx_q == linebuf_next_idx));
    wire pfbuf_holds_next2_w =
        (pfbuf_valid_q &&
         (pfbuf_tag_q == linebuf_next2_tag) &&
         (pfbuf_idx_q == linebuf_next2_idx)) ||
        (pfbuf1_valid_q &&
         (pfbuf1_tag_q == linebuf_next2_tag) &&
         (pfbuf1_idx_q == linebuf_next2_idx));
    wire linebuf_holds_next_w =
        (linebuf_valid_q &&
         (linebuf_tag_q == linebuf_next_tag) &&
         (linebuf_idx_q == linebuf_next_idx)) ||
        (linebuf1_valid_q &&
         (linebuf1_tag_q == linebuf_next_tag) &&
         (linebuf1_idx_q == linebuf_next_idx)) ||
        (linebuf2_valid_q &&
         (linebuf2_tag_q == linebuf_next_tag) &&
         (linebuf2_idx_q == linebuf_next_idx)) ||
        (linebuf3_valid_q &&
         (linebuf3_tag_q == linebuf_next_tag) &&
         (linebuf3_idx_q == linebuf_next_idx)) ||
        (linebuf4_valid_q &&
         (linebuf4_tag_q == linebuf_next_tag) &&
         (linebuf4_idx_q == linebuf_next_idx)) ||
        (linebuf5_valid_q &&
         (linebuf5_tag_q == linebuf_next_tag) &&
         (linebuf5_idx_q == linebuf_next_idx)) ||
        (linebuf6_valid_q &&
         (linebuf6_tag_q == linebuf_next_tag) &&
         (linebuf6_idx_q == linebuf_next_idx)) ||
        (linebuf7_valid_q &&
         (linebuf7_tag_q == linebuf_next_tag) &&
         (linebuf7_idx_q == linebuf_next_idx)) ||
        (linebuf8_valid_q &&
         (linebuf8_tag_q == linebuf_next_tag) &&
         (linebuf8_idx_q == linebuf_next_idx)) ||
        (linebuf9_valid_q &&
         (linebuf9_tag_q == linebuf_next_tag) &&
         (linebuf9_idx_q == linebuf_next_idx)) ||
        (linebuf10_valid_q &&
         (linebuf10_tag_q == linebuf_next_tag) &&
         (linebuf10_idx_q == linebuf_next_idx)) ||
        (linebuf11_valid_q &&
         (linebuf11_tag_q == linebuf_next_tag) &&
         (linebuf11_idx_q == linebuf_next_idx)) ||
        (linebuf12_valid_q &&
         (linebuf12_tag_q == linebuf_next_tag) &&
         (linebuf12_idx_q == linebuf_next_idx)) ||
        (linebuf13_valid_q &&
         (linebuf13_tag_q == linebuf_next_tag) &&
         (linebuf13_idx_q == linebuf_next_idx)) ||
        (linebuf14_valid_q &&
         (linebuf14_tag_q == linebuf_next_tag) &&
         (linebuf14_idx_q == linebuf_next_idx)) ||
        (linebuf15_valid_q &&
         (linebuf15_tag_q == linebuf_next_tag) &&
         (linebuf15_idx_q == linebuf_next_idx));
    wire linebuf_holds_next2_w =
        (linebuf_valid_q &&
         (linebuf_tag_q == linebuf_next2_tag) &&
         (linebuf_idx_q == linebuf_next2_idx)) ||
        (linebuf1_valid_q &&
         (linebuf1_tag_q == linebuf_next2_tag) &&
         (linebuf1_idx_q == linebuf_next2_idx)) ||
        (linebuf2_valid_q &&
         (linebuf2_tag_q == linebuf_next2_tag) &&
         (linebuf2_idx_q == linebuf_next2_idx)) ||
        (linebuf3_valid_q &&
         (linebuf3_tag_q == linebuf_next2_tag) &&
         (linebuf3_idx_q == linebuf_next2_idx)) ||
        (linebuf4_valid_q &&
         (linebuf4_tag_q == linebuf_next2_tag) &&
         (linebuf4_idx_q == linebuf_next2_idx)) ||
        (linebuf5_valid_q &&
         (linebuf5_tag_q == linebuf_next2_tag) &&
         (linebuf5_idx_q == linebuf_next2_idx)) ||
        (linebuf6_valid_q &&
         (linebuf6_tag_q == linebuf_next2_tag) &&
         (linebuf6_idx_q == linebuf_next2_idx)) ||
        (linebuf7_valid_q &&
         (linebuf7_tag_q == linebuf_next2_tag) &&
         (linebuf7_idx_q == linebuf_next2_idx)) ||
        (linebuf8_valid_q &&
         (linebuf8_tag_q == linebuf_next2_tag) &&
         (linebuf8_idx_q == linebuf_next2_idx)) ||
        (linebuf9_valid_q &&
         (linebuf9_tag_q == linebuf_next2_tag) &&
         (linebuf9_idx_q == linebuf_next2_idx)) ||
        (linebuf10_valid_q &&
         (linebuf10_tag_q == linebuf_next2_tag) &&
         (linebuf10_idx_q == linebuf_next2_idx)) ||
        (linebuf11_valid_q &&
         (linebuf11_tag_q == linebuf_next2_tag) &&
         (linebuf11_idx_q == linebuf_next2_idx)) ||
        (linebuf12_valid_q &&
         (linebuf12_tag_q == linebuf_next2_tag) &&
         (linebuf12_idx_q == linebuf_next2_idx)) ||
        (linebuf13_valid_q &&
         (linebuf13_tag_q == linebuf_next2_tag) &&
         (linebuf13_idx_q == linebuf_next2_idx)) ||
        (linebuf14_valid_q &&
         (linebuf14_tag_q == linebuf_next2_tag) &&
         (linebuf14_idx_q == linebuf_next2_idx)) ||
        (linebuf15_valid_q &&
         (linebuf15_tag_q == linebuf_next2_tag) &&
         (linebuf15_idx_q == linebuf_next2_idx));
    wire lookahead_probe_next_w = !linebuf_holds_next_w && !pfbuf_holds_next_w;
    wire lookahead_probe_next2_w =
        !lookahead_probe_next_w &&
        !linebuf_holds_next2_w && !pfbuf_holds_next2_w;
    assign lookahead_probe_addr_w =
        lookahead_probe_next_w ? linebuf_next_addr : linebuf_next2_addr;
    assign lookahead_probe_idx_w =
        lookahead_probe_next_w ? linebuf_next_idx : linebuf_next2_idx;
    wire l2_pf_resp_accept_w = l2_pf_resp_valid_i &&
                                (state_q != ST_CACOP) &&
                                !stale_l2_resp_pending_q;
    wire [TAG_WIDTH-1:0] l2_pf_resp_tag_w =
        l2_pf_resp_addr_i[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] l2_pf_resp_idx_w =
        l2_pf_resp_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire l2_pf_resp_pfbuf0_hit_w =
        pfbuf_valid_q && (pfbuf_tag_q == l2_pf_resp_tag_w) &&
        (pfbuf_idx_q == l2_pf_resp_idx_w);
    wire l2_pf_resp_fill_pfbuf0_w =
        l2_pf_resp_accept_w && (!pfbuf_valid_q || l2_pf_resp_pfbuf0_hit_w);
    wire l2_pf_resp_fill_pfbuf1_w =
        l2_pf_resp_accept_w && !l2_pf_resp_fill_pfbuf0_w;
    wire shadow_fetch_linebuf_hit_w =
        shadow_fetch_valid_i &&
        (((linebuf_valid_q && (linebuf_tag_q == shadow_fetch_tag) &&
           (linebuf_idx_q == shadow_fetch_idx)) ||
          (linebuf1_valid_q && (linebuf1_tag_q == shadow_fetch_tag) &&
           (linebuf1_idx_q == shadow_fetch_idx)) ||
          (linebuf2_valid_q && (linebuf2_tag_q == shadow_fetch_tag) &&
           (linebuf2_idx_q == shadow_fetch_idx)) ||
          (linebuf3_valid_q && (linebuf3_tag_q == shadow_fetch_tag) &&
           (linebuf3_idx_q == shadow_fetch_idx)) ||
          (linebuf4_valid_q && (linebuf4_tag_q == shadow_fetch_tag) &&
           (linebuf4_idx_q == shadow_fetch_idx)) ||
          (linebuf5_valid_q && (linebuf5_tag_q == shadow_fetch_tag) &&
           (linebuf5_idx_q == shadow_fetch_idx)) ||
          (linebuf6_valid_q && (linebuf6_tag_q == shadow_fetch_tag) &&
           (linebuf6_idx_q == shadow_fetch_idx)) ||
          (linebuf7_valid_q && (linebuf7_tag_q == shadow_fetch_tag) &&
           (linebuf7_idx_q == shadow_fetch_idx)) ||
          (linebuf8_valid_q && (linebuf8_tag_q == shadow_fetch_tag) &&
           (linebuf8_idx_q == shadow_fetch_idx)) ||
          (linebuf9_valid_q && (linebuf9_tag_q == shadow_fetch_tag) &&
           (linebuf9_idx_q == shadow_fetch_idx)) ||
          (linebuf10_valid_q && (linebuf10_tag_q == shadow_fetch_tag) &&
           (linebuf10_idx_q == shadow_fetch_idx)) ||
          (linebuf11_valid_q && (linebuf11_tag_q == shadow_fetch_tag) &&
           (linebuf11_idx_q == shadow_fetch_idx)) ||
          (linebuf12_valid_q && (linebuf12_tag_q == shadow_fetch_tag) &&
           (linebuf12_idx_q == shadow_fetch_idx)) ||
          (linebuf13_valid_q && (linebuf13_tag_q == shadow_fetch_tag) &&
           (linebuf13_idx_q == shadow_fetch_idx)) ||
          (linebuf14_valid_q && (linebuf14_tag_q == shadow_fetch_tag) &&
           (linebuf14_idx_q == shadow_fetch_idx)) ||
          (linebuf15_valid_q && (linebuf15_tag_q == shadow_fetch_tag) &&
           (linebuf15_idx_q == shadow_fetch_idx))));
    wire shadow_fetch_pfbuf_hit_w =
        shadow_fetch_valid_i &&
        (((pfbuf_valid_q && (pfbuf_tag_q == shadow_fetch_tag) &&
           (pfbuf_idx_q == shadow_fetch_idx)) ||
          (pfbuf1_valid_q && (pfbuf1_tag_q == shadow_fetch_tag) &&
           (pfbuf1_idx_q == shadow_fetch_idx))));
    wire shadow_fetch_rtbuf_hit_w =
        shadow_fetch_valid_i &&
        (((rtbuf_valid_q && (rtbuf_tag_q == shadow_fetch_tag) &&
           (rtbuf_idx_q == shadow_fetch_idx)) ||
          (rtbuf1_valid_q && (rtbuf1_tag_q == shadow_fetch_tag) &&
           (rtbuf1_idx_q == shadow_fetch_idx)) ||
          (rtbuf2_valid_q && (rtbuf2_tag_q == shadow_fetch_tag) &&
           (rtbuf2_idx_q == shadow_fetch_idx)) ||
          (rtbuf3_valid_q && (rtbuf3_tag_q == shadow_fetch_tag) &&
           (rtbuf3_idx_q == shadow_fetch_idx)) ||
          (rtbuf4_valid_q && (rtbuf4_tag_q == shadow_fetch_tag) &&
           (rtbuf4_idx_q == shadow_fetch_idx)) ||
          (rtbuf5_valid_q && (rtbuf5_tag_q == shadow_fetch_tag) &&
           (rtbuf5_idx_q == shadow_fetch_idx)) ||
          (rtbuf6_valid_q && (rtbuf6_tag_q == shadow_fetch_tag) &&
           (rtbuf6_idx_q == shadow_fetch_idx)) ||
          (rtbuf7_valid_q && (rtbuf7_tag_q == shadow_fetch_tag) &&
           (rtbuf7_idx_q == shadow_fetch_idx))));
    wire shadow_fetch_altbuf_hit_w =
        shadow_fetch_valid_i &&
        (((altbuf_valid_q && (altbuf_tag_q == shadow_fetch_tag) &&
           (altbuf_idx_q == shadow_fetch_idx)) ||
          (altbuf1_valid_q && (altbuf1_tag_q == shadow_fetch_tag) &&
           (altbuf1_idx_q == shadow_fetch_idx))));
    wire shadow_fetch_known_hit_w =
        shadow_fetch_linebuf_hit_w || shadow_fetch_pfbuf_hit_w ||
        shadow_fetch_rtbuf_hit_w || shadow_fetch_altbuf_hit_w;
    wire shadow_probe_linebuf_hit_w =
        shadow_probe_input_valid_w &&
        (((linebuf_valid_q && (linebuf_tag_q == shadow_probe_tag_w) &&
           (linebuf_idx_q == shadow_probe_idx_w)) ||
          (linebuf1_valid_q && (linebuf1_tag_q == shadow_probe_tag_w) &&
           (linebuf1_idx_q == shadow_probe_idx_w)) ||
          (linebuf2_valid_q && (linebuf2_tag_q == shadow_probe_tag_w) &&
           (linebuf2_idx_q == shadow_probe_idx_w)) ||
          (linebuf3_valid_q && (linebuf3_tag_q == shadow_probe_tag_w) &&
           (linebuf3_idx_q == shadow_probe_idx_w)) ||
          (linebuf4_valid_q && (linebuf4_tag_q == shadow_probe_tag_w) &&
           (linebuf4_idx_q == shadow_probe_idx_w)) ||
          (linebuf5_valid_q && (linebuf5_tag_q == shadow_probe_tag_w) &&
           (linebuf5_idx_q == shadow_probe_idx_w)) ||
          (linebuf6_valid_q && (linebuf6_tag_q == shadow_probe_tag_w) &&
           (linebuf6_idx_q == shadow_probe_idx_w)) ||
          (linebuf7_valid_q && (linebuf7_tag_q == shadow_probe_tag_w) &&
           (linebuf7_idx_q == shadow_probe_idx_w)) ||
          (linebuf8_valid_q && (linebuf8_tag_q == shadow_probe_tag_w) &&
           (linebuf8_idx_q == shadow_probe_idx_w)) ||
          (linebuf9_valid_q && (linebuf9_tag_q == shadow_probe_tag_w) &&
           (linebuf9_idx_q == shadow_probe_idx_w)) ||
          (linebuf10_valid_q && (linebuf10_tag_q == shadow_probe_tag_w) &&
           (linebuf10_idx_q == shadow_probe_idx_w)) ||
          (linebuf11_valid_q && (linebuf11_tag_q == shadow_probe_tag_w) &&
           (linebuf11_idx_q == shadow_probe_idx_w)) ||
          (linebuf12_valid_q && (linebuf12_tag_q == shadow_probe_tag_w) &&
           (linebuf12_idx_q == shadow_probe_idx_w)) ||
          (linebuf13_valid_q && (linebuf13_tag_q == shadow_probe_tag_w) &&
           (linebuf13_idx_q == shadow_probe_idx_w)) ||
          (linebuf14_valid_q && (linebuf14_tag_q == shadow_probe_tag_w) &&
           (linebuf14_idx_q == shadow_probe_idx_w)) ||
          (linebuf15_valid_q && (linebuf15_tag_q == shadow_probe_tag_w) &&
           (linebuf15_idx_q == shadow_probe_idx_w))));
    wire shadow_probe_pfbuf_hit_w =
        shadow_probe_input_valid_w &&
        (((pfbuf_valid_q && (pfbuf_tag_q == shadow_probe_tag_w) &&
           (pfbuf_idx_q == shadow_probe_idx_w)) ||
          (pfbuf1_valid_q && (pfbuf1_tag_q == shadow_probe_tag_w) &&
           (pfbuf1_idx_q == shadow_probe_idx_w))));
    wire shadow_probe_rtbuf_hit_w =
        shadow_probe_input_valid_w &&
        (((rtbuf_valid_q && (rtbuf_tag_q == shadow_probe_tag_w) &&
           (rtbuf_idx_q == shadow_probe_idx_w)) ||
          (rtbuf1_valid_q && (rtbuf1_tag_q == shadow_probe_tag_w) &&
           (rtbuf1_idx_q == shadow_probe_idx_w)) ||
          (rtbuf2_valid_q && (rtbuf2_tag_q == shadow_probe_tag_w) &&
           (rtbuf2_idx_q == shadow_probe_idx_w)) ||
          (rtbuf3_valid_q && (rtbuf3_tag_q == shadow_probe_tag_w) &&
           (rtbuf3_idx_q == shadow_probe_idx_w)) ||
          (rtbuf4_valid_q && (rtbuf4_tag_q == shadow_probe_tag_w) &&
           (rtbuf4_idx_q == shadow_probe_idx_w)) ||
          (rtbuf5_valid_q && (rtbuf5_tag_q == shadow_probe_tag_w) &&
           (rtbuf5_idx_q == shadow_probe_idx_w)) ||
          (rtbuf6_valid_q && (rtbuf6_tag_q == shadow_probe_tag_w) &&
           (rtbuf6_idx_q == shadow_probe_idx_w)) ||
          (rtbuf7_valid_q && (rtbuf7_tag_q == shadow_probe_tag_w) &&
           (rtbuf7_idx_q == shadow_probe_idx_w))));
    wire shadow_probe_altbuf_hit_w =
        shadow_probe_input_valid_w &&
        (((altbuf_valid_q && (altbuf_tag_q == shadow_probe_tag_w) &&
           (altbuf_idx_q == shadow_probe_idx_w)) ||
          (altbuf1_valid_q && (altbuf1_tag_q == shadow_probe_tag_w) &&
           (altbuf1_idx_q == shadow_probe_idx_w))));
    wire shadow_probe_known_hit_w =
        shadow_probe_linebuf_hit_w || shadow_probe_pfbuf_hit_w ||
        shadow_probe_rtbuf_hit_w || shadow_probe_altbuf_hit_w;
    assign shadow_hint_pop_w =
        shadow_probe_from_queue_w &&
        (shadow_probe_lookup_start_w || shadow_probe_known_hit_w);
    assign shadow_hint_enqueue_w =
        shadow_fetch_valid_i && !shadow_fetch_known_hit_w &&
        !(shadow_probe_lookup_start_w && !shadow_probe_from_queue_w);
    wire prefetch_can_start_w =
        ENABLE_L1_STREAM_PREFETCH &&
        linebuf_valid_q && !pfbuf_holds_next_w &&
        !linebuf_base_addr[OFFSET_WIDTH] &&
        !pf_inflight_q && !stale_l2_resp_pending_q &&
        !l2_req_valid_o && l2_req_ready_i &&
        (state_q == ST_LOOKUP) && !lookup_valid_q && !lookup_valid_d1 && !lookup_valid_d2 &&
        !req_lookup_fire_w;
    assign shadow_probe_lookup_start_w =
        shadow_probe_input_valid_w && !shadow_probe_known_hit_w &&
        !shadow_probe_valid_q && !shadow_probe_valid_d1 &&
        !shadow_probe_valid_d2 &&
        !redirect_probe_lookup_start_w && !redirect_probe_valid_i &&
        (state_q == ST_LOOKUP) && lookup_idle_w &&
        !probe_lookup_valid_q && !probe_lookup_valid_d1 &&
        !probe_lookup_valid_d2 &&
        !lookahead_probe_valid_q && !lookahead_probe_valid_d1 &&
        !lookahead_probe_valid_d2 &&
        !stale_l2_resp_pending_q && !pf_inflight_q && !l2_req_valid_o &&
        !lookup_issue_valid_w && (!req_valid_i || req_fastbuf_fire_w) &&
        !cacop_valid_i;
    assign lookahead_probe_start_w =
        ENABLE_L1_LOOKAHEAD_PROBE &&
        linebuf_valid_q &&
        (lookahead_probe_next_w || lookahead_probe_next2_w) &&
        (!pfbuf_valid_q || !pfbuf1_valid_q) &&
        !lookahead_probe_valid_q && !lookahead_probe_valid_d1 &&
        !lookahead_probe_valid_d2 &&
        !redirect_probe_lookup_start_w && !shadow_probe_lookup_start_w &&
        !redirect_probe_valid_i &&
        (state_q == ST_LOOKUP) && lookup_idle_w &&
        !probe_lookup_valid_q && !probe_lookup_valid_d1 &&
        !probe_lookup_valid_d2 &&
        !shadow_probe_valid_q && !shadow_probe_valid_d1 &&
        !shadow_probe_valid_d2 &&
        !stale_l2_resp_pending_q && !pf_inflight_q &&
        !l2_req_valid_o && !lookup_issue_valid_w &&
        (!req_valid_i || req_fastbuf_fire_w) &&
        !cacop_valid_i;
    wire stale_l2_resp_after_flush_w =
        (stale_l2_resp_pending_q && !l2_resp_valid_i) || flush_leaves_l2_resp_w;

`ifdef PERF_MONI
    wire perf_shadow_push_valid_w =
        (flush && redirect_probe_pfbuf_hit_w) ||
        (!flush &&
         (((state_q == ST_LOOKUP) && req_rtbuf_fire_w) ||
          ((state_q == ST_LOOKUP) && req_pfbuf_fire_w) ||
          ((state_q == ST_LOOKUP) && probe_lookup_hit_complete_w) ||
          ((state_q == ST_LOOKUP) && lookup_hit_complete_w) ||
          ((state_q == ST_MISS) && l2_resp_valid_i)));
    wire [TAG_WIDTH-1:0] perf_shadow_push_tag_w =
        (flush && redirect_probe_pfbuf_hit_w) ?
            redirect_probe_pfbuf_tag_w :
        ((state_q == ST_LOOKUP) && req_rtbuf_fire_w) ? rtbuf_hit_tag_w :
        ((state_q == ST_LOOKUP) && req_pfbuf_fire_w) ? pfbuf_hit_tag_w :
        ((state_q == ST_LOOKUP) && probe_lookup_hit_complete_w) ?
            probe_lookup_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH] :
        ((state_q == ST_LOOKUP) && lookup_hit_complete_w) ?
            lookup_hit_addr_w[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH] :
            miss_tag;
    wire [INDEX_WIDTH-1:0] perf_shadow_push_idx_w =
        (flush && redirect_probe_pfbuf_hit_w) ?
            redirect_probe_pfbuf_idx_w :
        ((state_q == ST_LOOKUP) && req_rtbuf_fire_w) ? rtbuf_hit_idx_w :
        ((state_q == ST_LOOKUP) && req_pfbuf_fire_w) ? pfbuf_hit_idx_w :
        ((state_q == ST_LOOKUP) && probe_lookup_hit_complete_w) ?
            probe_lookup_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH] :
        ((state_q == ST_LOOKUP) && lookup_hit_complete_w) ?
            lookup_hit_addr_w[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH] :
            miss_idx;
    wire perf_shadow_clear_w = (state_q == ST_CACOP) && cacop_phase_q;

    always @* begin
        perf_shadow_req_hit_lo_w = 1'b0;
        perf_shadow_req_hit_hi_w = 1'b0;
        perf_shadow_redirect_hit_lo_w = 1'b0;
        perf_shadow_redirect_hit_hi_w = 1'b0;
        perf_shadow_touch_pos_w = 5'd16;
        for (perf_shadow_scan_i = 0; perf_shadow_scan_i < 16;
             perf_shadow_scan_i = perf_shadow_scan_i + 1) begin
            if (perf_shadow_valid_q[perf_shadow_scan_i] &&
                (perf_shadow_tag_q[perf_shadow_scan_i] == perf_shadow_push_tag_w) &&
                (perf_shadow_idx_q[perf_shadow_scan_i] == perf_shadow_push_idx_w) &&
                (perf_shadow_touch_pos_w == 5'd16)) begin
                perf_shadow_touch_pos_w = perf_shadow_scan_i;
            end
            if (perf_shadow_valid_q[perf_shadow_scan_i] &&
                (perf_shadow_tag_q[perf_shadow_scan_i] == req_tag) &&
                (perf_shadow_idx_q[perf_shadow_scan_i] == req_idx)) begin
                if (perf_shadow_scan_i < 8)
                    perf_shadow_req_hit_lo_w = 1'b1;
                else
                    perf_shadow_req_hit_hi_w = 1'b1;
            end
            if (perf_shadow_valid_q[perf_shadow_scan_i] &&
                (perf_shadow_tag_q[perf_shadow_scan_i] == redirect_probe_tag) &&
                (perf_shadow_idx_q[perf_shadow_scan_i] == redirect_probe_idx)) begin
                if (perf_shadow_scan_i < 8)
                    perf_shadow_redirect_hit_lo_w = 1'b1;
                else
                    perf_shadow_redirect_hit_hi_w = 1'b1;
            end
        end
    end

    always @(posedge clk) begin
        if (!rst_n || perf_shadow_clear_w) begin
            for (perf_shadow_seq_i = 0; perf_shadow_seq_i < 16;
                 perf_shadow_seq_i = perf_shadow_seq_i + 1) begin
                perf_shadow_valid_q[perf_shadow_seq_i] <= 1'b0;
                perf_shadow_tag_q[perf_shadow_seq_i] <= {TAG_WIDTH{1'b0}};
                perf_shadow_idx_q[perf_shadow_seq_i] <= {INDEX_WIDTH{1'b0}};
            end
        end else if (perf_shadow_push_valid_w) begin
            perf_shadow_valid_q[0] <= 1'b1;
            perf_shadow_tag_q[0] <= perf_shadow_push_tag_w;
            perf_shadow_idx_q[0] <= perf_shadow_push_idx_w;
            for (perf_shadow_seq_i = 1; perf_shadow_seq_i < 16;
                 perf_shadow_seq_i = perf_shadow_seq_i + 1) begin
                if (perf_shadow_seq_i <= perf_shadow_touch_pos_w) begin
                    perf_shadow_valid_q[perf_shadow_seq_i] <=
                        perf_shadow_valid_q[perf_shadow_seq_i - 1];
                    perf_shadow_tag_q[perf_shadow_seq_i] <=
                        perf_shadow_tag_q[perf_shadow_seq_i - 1];
                    perf_shadow_idx_q[perf_shadow_seq_i] <=
                        perf_shadow_idx_q[perf_shadow_seq_i - 1];
                end
            end
        end
    end
`endif

    assign resp_valid_o = rst_n && !flush && !cacop_accept_w &&
                          (req_fastbuf_direct_resp_w || resp_pop_w);
    assign resp_instr_o = req_fastbuf_direct_resp_w ? fastbuf_instr :
                          resp_bypass_w ? resp_bypass_data_w :
                          resp_data_q[resp_rd_ptr_q];
    assign resp_line_valid_o = resp_valid_o &&
                               (req_fastbuf_direct_resp_w || resp_bypass_w ||
                                resp_line_valid_q[resp_rd_ptr_q]);
    assign resp_line_addr_o =
        (req_fastbuf_direct_resp_w ? req_addr_i :
         resp_bypass_w ? resp_addr_q[resp_rd_ptr_q] :
                         resp_addr_q[resp_rd_ptr_q]) & ~LINE_OFFSET_MASK;
    assign resp_line_data_o_0 =
        req_fastbuf_direct_resp_w ? fastbuf_line_word0_w :
        resp_bypass_w ? resp_bypass_line_word0_w :
                        resp_line_word0_q[resp_rd_ptr_q];
    assign resp_line_data_o_1 =
        req_fastbuf_direct_resp_w ? fastbuf_line_word1_w :
        resp_bypass_w ? resp_bypass_line_word1_w :
                        resp_line_word1_q[resp_rd_ptr_q];
    assign resp_line_data_o_2 =
        req_fastbuf_direct_resp_w ? fastbuf_line_word2_w :
        resp_bypass_w ? resp_bypass_line_word2_w :
                        resp_line_word2_q[resp_rd_ptr_q];
    assign resp_line_data_o_3 =
        req_fastbuf_direct_resp_w ? fastbuf_line_word3_w :
        resp_bypass_w ? resp_bypass_line_word3_w :
                        resp_line_word3_q[resp_rd_ptr_q];

    always @(posedge clk) begin
        if (!rst_n || flush || cacop_accept_w) begin
            shadow_hint0_valid_q <= 1'b0;
            shadow_hint0_addr_q  <= {XLEN{1'b0}};
            shadow_hint1_valid_q <= 1'b0;
            shadow_hint1_addr_q  <= {XLEN{1'b0}};
        end else begin
            case ({shadow_hint_enqueue_w, shadow_hint_pop_w})
                2'b10: begin
                    if (!shadow_hint0_valid_q ||
                        (shadow_hint0_addr_q[XLEN-1:OFFSET_WIDTH] ==
                         shadow_fetch_addr_i[XLEN-1:OFFSET_WIDTH])) begin
                        shadow_hint0_valid_q <= 1'b1;
                        shadow_hint0_addr_q  <= shadow_fetch_addr_i;
                    end else if (!shadow_hint1_valid_q ||
                                 (shadow_hint1_addr_q[XLEN-1:OFFSET_WIDTH] ==
                                  shadow_fetch_addr_i[XLEN-1:OFFSET_WIDTH])) begin
                        shadow_hint1_valid_q <= 1'b1;
                        shadow_hint1_addr_q  <= shadow_fetch_addr_i;
                    end else begin
                        shadow_hint1_valid_q <= 1'b1;
                        shadow_hint1_addr_q  <= shadow_fetch_addr_i;
                    end
                end
                2'b01: begin
                    shadow_hint0_valid_q <= shadow_hint1_valid_q;
                    shadow_hint0_addr_q  <= shadow_hint1_addr_q;
                    shadow_hint1_valid_q <= 1'b0;
                    shadow_hint1_addr_q  <= {XLEN{1'b0}};
                end
                2'b11: begin
                    if (!shadow_hint1_valid_q ||
                        (shadow_hint1_addr_q[XLEN-1:OFFSET_WIDTH] ==
                         shadow_fetch_addr_i[XLEN-1:OFFSET_WIDTH])) begin
                        shadow_hint0_valid_q <= 1'b1;
                        shadow_hint0_addr_q  <= shadow_fetch_addr_i;
                        shadow_hint1_valid_q <= 1'b0;
                        shadow_hint1_addr_q  <= {XLEN{1'b0}};
                    end else begin
                        shadow_hint0_valid_q <= shadow_hint1_valid_q;
                        shadow_hint0_addr_q  <= shadow_hint1_addr_q;
                        shadow_hint1_valid_q <= 1'b1;
                        shadow_hint1_addr_q  <= shadow_fetch_addr_i;
                    end
                end
                default: ;
            endcase
        end
    end

    // --- 流水延迟链 T0→T1→T2 ---
    // lookup_addr_q / lookup_valid_q 只跟踪正常取指请求。
    // miss refill 直接从 L2 返回数据产生 resp，避免写 BRAM 后立刻读回造成旧值。
    always @(posedge clk) begin
        if (!rst_n || flush || cacop_accept_w || lookup_miss_w) begin
            lookup_valid_q  <= 1'b0;
            lookup_valid_d1 <= 1'b0;
            lookup_addr_q   <= 32'h0;
            lookup_addr_d1  <= 32'h0;
            lookup_resp_slot_q  <= {RESP_PTR_W{1'b0}};
            lookup_resp_slot_d1 <= {RESP_PTR_W{1'b0}};
        end else begin
            lookup_valid_q       <= lookup_issue_valid_w;
            lookup_addr_q        <= lookup_issue_addr_w;
            lookup_resp_slot_q   <= lookup_issue_slot_w;
            lookup_valid_d1      <= lookup_valid_q;
            lookup_addr_d1       <= lookup_addr_q;
            lookup_resp_slot_d1  <= lookup_resp_slot_q;
        end
    end

    integer resp_i;
    // --- 状态机：维护响应队列、lookup 完成和 miss/refill ---
    always @(posedge clk) begin
        if (!rst_n) begin
            state_q              <= ST_LOOKUP;
            replace_way_q        <= {WAY_WIDTH{1'b0}};
            miss_addr_q          <= 32'h0;
            cacop_addr_q         <= 32'h0;
            cacop_mode_q         <= 2'b00;
            cacop_phase_q        <= 1'b0;
            cacop_done_q         <= 1'b0;
            miss_resp_slot_q     <= {RESP_PTR_W{1'b0}};
            resp_wr_ptr_q        <= {RESP_PTR_W{1'b0}};
            resp_rd_ptr_q        <= {RESP_PTR_W{1'b0}};
            resp_count_q         <= {(RESP_PTR_W+1){1'b0}};
            for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                resp_done_q[resp_i] <= 1'b0;
                resp_data_q[resp_i] <= 32'h0;
                resp_addr_q[resp_i] <= {XLEN{1'b0}};
                resp_line_valid_q[resp_i] <= 1'b0;
                resp_line_word0_q[resp_i] <= 32'h0;
                resp_line_word1_q[resp_i] <= 32'h0;
                resp_line_word2_q[resp_i] <= 32'h0;
                resp_line_word3_q[resp_i] <= 32'h0;
                resp_wait_lookup_q[resp_i] <= 1'b0;
                resp_lookup_merge_q[resp_i] <= 1'b0;
                resp_wait_miss_q[resp_i] <= 1'b0;
            end
            l2_req_valid_o       <= 1'b0;
            l2_req_addr_o        <= 32'h0;
            l2_req_is_prefetch_o <= 1'b0;
            linebuf_valid_q      <= 1'b0;
            linebuf_tag_q        <= {TAG_WIDTH{1'b0}};
            linebuf_idx_q        <= {INDEX_WIDTH{1'b0}};
            linebuf_data_q[0]    <= 32'h0;
            linebuf_data_q[1]    <= 32'h0;
            linebuf_data_q[2]    <= 32'h0;
            linebuf_data_q[3]    <= 32'h0;
            linebuf1_valid_q     <= 1'b0;
            linebuf1_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf1_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf1_data_q[0]   <= 32'h0;
            linebuf1_data_q[1]   <= 32'h0;
            linebuf1_data_q[2]   <= 32'h0;
            linebuf1_data_q[3]   <= 32'h0;
            linebuf2_valid_q     <= 1'b0;
            linebuf2_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf2_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf2_data_q[0]   <= 32'h0;
            linebuf2_data_q[1]   <= 32'h0;
            linebuf2_data_q[2]   <= 32'h0;
            linebuf2_data_q[3]   <= 32'h0;
            linebuf3_valid_q     <= 1'b0;
            linebuf3_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf3_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf3_data_q[0]   <= 32'h0;
            linebuf3_data_q[1]   <= 32'h0;
            linebuf3_data_q[2]   <= 32'h0;
            linebuf3_data_q[3]   <= 32'h0;
            linebuf4_valid_q     <= 1'b0;
            linebuf4_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf4_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf4_data_q[0]   <= 32'h0;
            linebuf4_data_q[1]   <= 32'h0;
            linebuf4_data_q[2]   <= 32'h0;
            linebuf4_data_q[3]   <= 32'h0;
            linebuf5_valid_q     <= 1'b0;
            linebuf5_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf5_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf5_data_q[0]   <= 32'h0;
            linebuf5_data_q[1]   <= 32'h0;
            linebuf5_data_q[2]   <= 32'h0;
            linebuf5_data_q[3]   <= 32'h0;
            linebuf6_valid_q     <= 1'b0;
            linebuf6_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf6_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf6_data_q[0]   <= 32'h0;
            linebuf6_data_q[1]   <= 32'h0;
            linebuf6_data_q[2]   <= 32'h0;
            linebuf6_data_q[3]   <= 32'h0;
            linebuf7_valid_q     <= 1'b0;
            linebuf7_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf7_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf7_data_q[0]   <= 32'h0;
            linebuf7_data_q[1]   <= 32'h0;
            linebuf7_data_q[2]   <= 32'h0;
            linebuf7_data_q[3]   <= 32'h0;
            linebuf8_valid_q     <= 1'b0;
            linebuf8_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf8_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf8_data_q[0]   <= 32'h0;
            linebuf8_data_q[1]   <= 32'h0;
            linebuf8_data_q[2]   <= 32'h0;
            linebuf8_data_q[3]   <= 32'h0;
            linebuf9_valid_q     <= 1'b0;
            linebuf9_tag_q       <= {TAG_WIDTH{1'b0}};
            linebuf9_idx_q       <= {INDEX_WIDTH{1'b0}};
            linebuf9_data_q[0]   <= 32'h0;
            linebuf9_data_q[1]   <= 32'h0;
            linebuf9_data_q[2]   <= 32'h0;
            linebuf9_data_q[3]   <= 32'h0;
            linebuf10_valid_q    <= 1'b0;
            linebuf10_tag_q      <= {TAG_WIDTH{1'b0}};
            linebuf10_idx_q      <= {INDEX_WIDTH{1'b0}};
            linebuf10_data_q[0]  <= 32'h0;
            linebuf10_data_q[1]  <= 32'h0;
            linebuf10_data_q[2]  <= 32'h0;
            linebuf10_data_q[3]  <= 32'h0;
            linebuf11_valid_q    <= 1'b0;
            linebuf11_tag_q      <= {TAG_WIDTH{1'b0}};
            linebuf11_idx_q      <= {INDEX_WIDTH{1'b0}};
            linebuf11_data_q[0]  <= 32'h0;
            linebuf11_data_q[1]  <= 32'h0;
            linebuf11_data_q[2]  <= 32'h0;
            linebuf11_data_q[3]  <= 32'h0;
            linebuf12_valid_q    <= 1'b0;
            linebuf12_tag_q      <= {TAG_WIDTH{1'b0}};
            linebuf12_idx_q      <= {INDEX_WIDTH{1'b0}};
            linebuf12_data_q[0]  <= 32'h0;
            linebuf12_data_q[1]  <= 32'h0;
            linebuf12_data_q[2]  <= 32'h0;
            linebuf12_data_q[3]  <= 32'h0;
            linebuf13_valid_q    <= 1'b0;
            linebuf13_tag_q      <= {TAG_WIDTH{1'b0}};
            linebuf13_idx_q      <= {INDEX_WIDTH{1'b0}};
            linebuf13_data_q[0]  <= 32'h0;
            linebuf13_data_q[1]  <= 32'h0;
            linebuf13_data_q[2]  <= 32'h0;
            linebuf13_data_q[3]  <= 32'h0;
            linebuf14_valid_q    <= 1'b0;
            linebuf14_tag_q      <= {TAG_WIDTH{1'b0}};
            linebuf14_idx_q      <= {INDEX_WIDTH{1'b0}};
            linebuf14_data_q[0]  <= 32'h0;
            linebuf14_data_q[1]  <= 32'h0;
            linebuf14_data_q[2]  <= 32'h0;
            linebuf14_data_q[3]  <= 32'h0;
            linebuf15_valid_q    <= 1'b0;
            linebuf15_tag_q      <= {TAG_WIDTH{1'b0}};
            linebuf15_idx_q      <= {INDEX_WIDTH{1'b0}};
            linebuf15_data_q[0]  <= 32'h0;
            linebuf15_data_q[1]  <= 32'h0;
            linebuf15_data_q[2]  <= 32'h0;
            linebuf15_data_q[3]  <= 32'h0;
            rtbuf_valid_q        <= 1'b0;
            rtbuf_tag_q          <= {TAG_WIDTH{1'b0}};
            rtbuf_idx_q          <= {INDEX_WIDTH{1'b0}};
            rtbuf_data_q[0]      <= 32'h0;
            rtbuf_data_q[1]      <= 32'h0;
            rtbuf_data_q[2]      <= 32'h0;
            rtbuf_data_q[3]      <= 32'h0;
            rtbuf1_valid_q       <= 1'b0;
            rtbuf1_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf1_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf1_data_q[0]     <= 32'h0;
            rtbuf1_data_q[1]     <= 32'h0;
            rtbuf1_data_q[2]     <= 32'h0;
            rtbuf1_data_q[3]     <= 32'h0;
            rtbuf2_valid_q       <= 1'b0;
            rtbuf2_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf2_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf2_data_q[0]     <= 32'h0;
            rtbuf2_data_q[1]     <= 32'h0;
            rtbuf2_data_q[2]     <= 32'h0;
            rtbuf2_data_q[3]     <= 32'h0;
            rtbuf3_valid_q       <= 1'b0;
            rtbuf3_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf3_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf3_data_q[0]     <= 32'h0;
            rtbuf3_data_q[1]     <= 32'h0;
            rtbuf3_data_q[2]     <= 32'h0;
            rtbuf3_data_q[3]     <= 32'h0;
            rtbuf4_valid_q       <= 1'b0;
            rtbuf4_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf4_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf4_data_q[0]     <= 32'h0;
            rtbuf4_data_q[1]     <= 32'h0;
            rtbuf4_data_q[2]     <= 32'h0;
            rtbuf4_data_q[3]     <= 32'h0;
            rtbuf5_valid_q       <= 1'b0;
            rtbuf5_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf5_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf5_data_q[0]     <= 32'h0;
            rtbuf5_data_q[1]     <= 32'h0;
            rtbuf5_data_q[2]     <= 32'h0;
            rtbuf5_data_q[3]     <= 32'h0;
            rtbuf6_valid_q       <= 1'b0;
            rtbuf6_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf6_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf6_data_q[0]     <= 32'h0;
            rtbuf6_data_q[1]     <= 32'h0;
            rtbuf6_data_q[2]     <= 32'h0;
            rtbuf6_data_q[3]     <= 32'h0;
            rtbuf7_valid_q       <= 1'b0;
            rtbuf7_tag_q         <= {TAG_WIDTH{1'b0}};
            rtbuf7_idx_q         <= {INDEX_WIDTH{1'b0}};
            rtbuf7_data_q[0]     <= 32'h0;
            rtbuf7_data_q[1]     <= 32'h0;
            rtbuf7_data_q[2]     <= 32'h0;
            rtbuf7_data_q[3]     <= 32'h0;
            rtbuf_pending_q      <= 1'b0;
            rtbuf_pending_addr_q <= {XLEN{1'b0}};
            pfbuf_valid_q        <= 1'b0;
            pfbuf_tag_q          <= {TAG_WIDTH{1'b0}};
            pfbuf_idx_q          <= {INDEX_WIDTH{1'b0}};
            pfbuf_data_q[0]      <= 32'h0;
            pfbuf_data_q[1]      <= 32'h0;
            pfbuf_data_q[2]      <= 32'h0;
            pfbuf_data_q[3]      <= 32'h0;
            pfbuf1_valid_q       <= 1'b0;
            pfbuf1_tag_q         <= {TAG_WIDTH{1'b0}};
            pfbuf1_idx_q         <= {INDEX_WIDTH{1'b0}};
            pfbuf1_data_q[0]     <= 32'h0;
            pfbuf1_data_q[1]     <= 32'h0;
            pfbuf1_data_q[2]     <= 32'h0;
            pfbuf1_data_q[3]     <= 32'h0;
            altbuf_valid_q       <= 1'b0;
            altbuf_tag_q         <= {TAG_WIDTH{1'b0}};
            altbuf_idx_q         <= {INDEX_WIDTH{1'b0}};
            altbuf_data_q[0]     <= 32'h0;
            altbuf_data_q[1]     <= 32'h0;
            altbuf_data_q[2]     <= 32'h0;
            altbuf_data_q[3]     <= 32'h0;
            altbuf1_valid_q      <= 1'b0;
            altbuf1_tag_q        <= {TAG_WIDTH{1'b0}};
            altbuf1_idx_q        <= {INDEX_WIDTH{1'b0}};
            altbuf1_data_q[0]    <= 32'h0;
            altbuf1_data_q[1]    <= 32'h0;
            altbuf1_data_q[2]    <= 32'h0;
            altbuf1_data_q[3]    <= 32'h0;
            pf_inflight_q        <= 1'b0;
            pf_addr_q            <= 32'h0;
            stale_l2_resp_pending_q <= 1'b0;
            redirect_fast_valid_q <= 1'b0;
            redirect_fast_addr_q  <= {XLEN{1'b0}};
            redirect_fast_instr_q <= {ILEN{1'b0}};
            redirect_fast_line_valid_q <= 1'b0;
            redirect_fast_line_addr_q  <= {XLEN{1'b0}};
            redirect_fast_line_word0_q <= {ILEN{1'b0}};
            redirect_fast_line_word1_q <= {ILEN{1'b0}};
            redirect_fast_line_word2_q <= {ILEN{1'b0}};
            redirect_fast_line_word3_q <= {ILEN{1'b0}};
        end else if (flush) begin
            state_q              <= ST_LOOKUP;
            cacop_addr_q         <= 32'h0;
            cacop_mode_q         <= 2'b00;
            cacop_phase_q        <= 1'b0;
            cacop_done_q         <= 1'b0;
            resp_wr_ptr_q        <= {RESP_PTR_W{1'b0}};
            resp_rd_ptr_q        <= {RESP_PTR_W{1'b0}};
            resp_count_q         <= {(RESP_PTR_W+1){1'b0}};
            for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                resp_done_q[resp_i] <= 1'b0;
                resp_data_q[resp_i] <= 32'h0;
                resp_addr_q[resp_i] <= {XLEN{1'b0}};
                resp_line_valid_q[resp_i] <= 1'b0;
                resp_line_word0_q[resp_i] <= 32'h0;
                resp_line_word1_q[resp_i] <= 32'h0;
                resp_line_word2_q[resp_i] <= 32'h0;
                resp_line_word3_q[resp_i] <= 32'h0;
                resp_wait_lookup_q[resp_i] <= 1'b0;
                resp_lookup_merge_q[resp_i] <= 1'b0;
                resp_wait_miss_q[resp_i] <= 1'b0;
            end
            l2_req_valid_o       <= 1'b0;
            l2_req_addr_o        <= 32'h0;
            l2_req_is_prefetch_o <= 1'b0;
            pf_inflight_q        <= 1'b0;
            pfbuf_valid_q        <= 1'b0;
            pfbuf1_valid_q       <= 1'b0;
            altbuf_valid_q       <= 1'b0;
            altbuf1_valid_q      <= 1'b0;
            miss_resp_slot_q     <= {RESP_PTR_W{1'b0}};
            stale_l2_resp_pending_q <= stale_l2_resp_after_flush_w;
            redirect_fast_valid_q <= redirect_probe_hit_o;
            redirect_fast_addr_q  <= redirect_probe_addr_i;
            redirect_fast_instr_q <= redirect_probe_fastbuf_instr_w;
            redirect_fast_line_valid_q <= redirect_probe_fastbuf_hit_w;
            redirect_fast_line_addr_q <= {
                redirect_probe_fastbuf_tag_w,
                redirect_probe_fastbuf_idx_w,
                {OFFSET_WIDTH{1'b0}}
            };
            redirect_fast_line_word0_q <= redirect_probe_fastbuf_word0_w;
            redirect_fast_line_word1_q <= redirect_probe_fastbuf_word1_w;
            redirect_fast_line_word2_q <= redirect_probe_fastbuf_word2_w;
            redirect_fast_line_word3_q <= redirect_probe_fastbuf_word3_w;
            if (redirect_probe_valid_i && !redirect_probe_fastbuf_hit_w) begin
                rtbuf_pending_q      <= 1'b1;
                rtbuf_pending_addr_q <= redirect_probe_addr_i;
            end
            if (ENABLE_REDIRECT_LINEBUF_RTBUF_PROMOTE &&
                redirect_probe_linebuf_hit_w) begin
                fill_rtbuf(1'b1,
                           redirect_probe_linebuf_tag_w,
                           redirect_probe_linebuf_idx_w,
                           redirect_probe_linebuf_word0_w,
                           redirect_probe_linebuf_word1_w,
                           redirect_probe_linebuf_word2_w,
                           redirect_probe_linebuf_word3_w);
            end else if (ENABLE_REDIRECT_RTBUF_MRU_PROMOTE &&
                         redirect_probe_rtbuf_hit_w) begin
                fill_rtbuf(1'b1,
                           redirect_probe_rtbuf_tag_w,
                           redirect_probe_rtbuf_idx_w,
                           redirect_probe_rtbuf_word0_w,
                           redirect_probe_rtbuf_word1_w,
                           redirect_probe_rtbuf_word2_w,
                           redirect_probe_rtbuf_word3_w);
            end else if (redirect_probe_pfbuf_hit_w) begin
                fill_rtbuf(1'b1,
                           redirect_probe_pfbuf_tag_w,
                           redirect_probe_pfbuf_idx_w,
                           redirect_probe_pfbuf_word0_w,
                           redirect_probe_pfbuf_word1_w,
                           redirect_probe_pfbuf_word2_w,
                           redirect_probe_pfbuf_word3_w);
                push_linebuf(1'b1,
                             redirect_probe_pfbuf_tag_w,
                             redirect_probe_pfbuf_idx_w,
                             redirect_probe_pfbuf_word0_w,
                             redirect_probe_pfbuf_word1_w,
                             redirect_probe_pfbuf_word2_w,
                             redirect_probe_pfbuf_word3_w);
            end else if (redirect_probe_altbuf_any_hit_w) begin
                fill_rtbuf(1'b1,
                           redirect_probe_altbuf_tag_w,
                           redirect_probe_altbuf_idx_w,
                           redirect_probe_altbuf_word0_w,
                           redirect_probe_altbuf_word1_w,
                           redirect_probe_altbuf_word2_w,
                           redirect_probe_altbuf_word3_w);
                push_linebuf(1'b1,
                             redirect_probe_altbuf_tag_w,
                             redirect_probe_altbuf_idx_w,
                             redirect_probe_altbuf_word0_w,
                             redirect_probe_altbuf_word1_w,
                             redirect_probe_altbuf_word2_w,
                             redirect_probe_altbuf_word3_w);
            end
        end else begin
            cacop_done_q <= 1'b0;

            if (probe_lookup_hit_complete_w) begin
                redirect_fast_valid_q <= 1'b1;
                redirect_fast_addr_q  <= probe_lookup_addr_d2;
                redirect_fast_instr_q <= probe_lookup_instr_w;
                redirect_fast_line_valid_q <= 1'b1;
                redirect_fast_line_addr_q <= probe_lookup_addr_d2 & ~LINE_OFFSET_MASK;
                redirect_fast_line_word0_q <= hit_line_word0;
                redirect_fast_line_word1_q <= hit_line_word1;
                redirect_fast_line_word2_q <= hit_line_word2;
                redirect_fast_line_word3_q <= hit_line_word3;
                fill_rtbuf(1'b1,
                           probe_lookup_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH],
                           probe_lookup_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH],
                           hit_line_word0, hit_line_word1,
                           hit_line_word2, hit_line_word3);
            end else if (redirect_probe_valid_i) begin
                redirect_fast_valid_q <= redirect_probe_fastbuf_hit_w;
                redirect_fast_addr_q  <= redirect_probe_addr_i;
                redirect_fast_instr_q <= redirect_probe_fastbuf_instr_w;
                redirect_fast_line_valid_q <= redirect_probe_fastbuf_hit_w;
                redirect_fast_line_addr_q <= {
                    redirect_probe_fastbuf_tag_w,
                    redirect_probe_fastbuf_idx_w,
                    {OFFSET_WIDTH{1'b0}}
                };
                redirect_fast_line_word0_q <= redirect_probe_fastbuf_word0_w;
                redirect_fast_line_word1_q <= redirect_probe_fastbuf_word1_w;
                redirect_fast_line_word2_q <= redirect_probe_fastbuf_word2_w;
                redirect_fast_line_word3_q <= redirect_probe_fastbuf_word3_w;
                if (!redirect_probe_fastbuf_hit_w) begin
                    rtbuf_pending_q      <= 1'b1;
                    rtbuf_pending_addr_q <= redirect_probe_addr_i;
                end
                if (ENABLE_REDIRECT_LINEBUF_RTBUF_PROMOTE &&
                    redirect_probe_linebuf_hit_w) begin
                    fill_rtbuf(1'b1,
                               redirect_probe_linebuf_tag_w,
                               redirect_probe_linebuf_idx_w,
                               redirect_probe_linebuf_word0_w,
                               redirect_probe_linebuf_word1_w,
                               redirect_probe_linebuf_word2_w,
                               redirect_probe_linebuf_word3_w);
                end else if (ENABLE_REDIRECT_RTBUF_MRU_PROMOTE &&
                             redirect_probe_rtbuf_hit_w) begin
                    fill_rtbuf(1'b1,
                               redirect_probe_rtbuf_tag_w,
                               redirect_probe_rtbuf_idx_w,
                               redirect_probe_rtbuf_word0_w,
                               redirect_probe_rtbuf_word1_w,
                               redirect_probe_rtbuf_word2_w,
                               redirect_probe_rtbuf_word3_w);
                end else if (redirect_probe_pfbuf_hit_w) begin
                    fill_rtbuf(1'b1,
                               redirect_probe_pfbuf_tag_w,
                               redirect_probe_pfbuf_idx_w,
                               redirect_probe_pfbuf_word0_w,
                               redirect_probe_pfbuf_word1_w,
                               redirect_probe_pfbuf_word2_w,
                               redirect_probe_pfbuf_word3_w);
                end else if (redirect_probe_altbuf_any_hit_w) begin
                    fill_rtbuf(1'b1,
                               redirect_probe_altbuf_tag_w,
                               redirect_probe_altbuf_idx_w,
                               redirect_probe_altbuf_word0_w,
                               redirect_probe_altbuf_word1_w,
                               redirect_probe_altbuf_word2_w,
                               redirect_probe_altbuf_word3_w);
                end
            end else if (redirect_fast_consume_i) begin
                redirect_fast_valid_q <= 1'b0;
                redirect_fast_line_valid_q <= 1'b0;
            end

            if (stale_l2_resp_pending_q && l2_resp_valid_i)
                stale_l2_resp_pending_q <= 1'b0;

            if (resp_emit_w) begin
                resp_done_q[resp_rd_ptr_q] <= 1'b0;
                resp_line_valid_q[resp_rd_ptr_q] <= 1'b0;
                resp_wait_lookup_q[resp_rd_ptr_q] <= 1'b0;
                resp_lookup_merge_q[resp_rd_ptr_q] <= 1'b0;
                resp_wait_miss_q[resp_rd_ptr_q] <= 1'b0;
                resp_rd_ptr_q <= resp_rd_ptr_q + {{(RESP_PTR_W-1){1'b0}}, 1'b1};
            end else if (resp_bypass_w) begin
                resp_done_q[resp_rd_ptr_q] <= 1'b0;
                resp_line_valid_q[resp_rd_ptr_q] <= 1'b0;
                resp_wait_lookup_q[resp_rd_ptr_q] <= 1'b0;
                resp_lookup_merge_q[resp_rd_ptr_q] <= 1'b0;
                resp_wait_miss_q[resp_rd_ptr_q] <= 1'b0;
                resp_rd_ptr_q <= resp_rd_ptr_q + {{(RESP_PTR_W-1){1'b0}}, 1'b1};
            end

            if (req_enqueue_w) begin
                resp_done_q[resp_wr_ptr_q] <=
                    req_fastbuf_fire_w || req_lookup_merge_hit_complete_w ||
                    req_probe_merge_hit_complete_w;
                resp_data_q[resp_wr_ptr_q] <= req_fastbuf_fire_w ? fastbuf_instr :
                    req_lookup_merge_hit_complete_w ? req_lookup_merge_hit_data_w :
                    req_probe_merge_hit_complete_w ? req_probe_merge_hit_data_w :
                    32'h0;
                resp_addr_q[resp_wr_ptr_q] <= req_addr_i;
                resp_line_valid_q[resp_wr_ptr_q] <=
                    req_fastbuf_fire_w || req_lookup_merge_hit_complete_w ||
                    req_probe_merge_hit_complete_w;
                resp_line_word0_q[resp_wr_ptr_q] <= req_fastbuf_fire_w ?
                    fastbuf_line_word0_w :
                    req_probe_merge_hit_complete_w ? hit_line_word0 :
                    lookup_hit_line_word0_w;
                resp_line_word1_q[resp_wr_ptr_q] <= req_fastbuf_fire_w ?
                    fastbuf_line_word1_w :
                    req_probe_merge_hit_complete_w ? hit_line_word1 :
                    lookup_hit_line_word1_w;
                resp_line_word2_q[resp_wr_ptr_q] <= req_fastbuf_fire_w ?
                    fastbuf_line_word2_w :
                    req_probe_merge_hit_complete_w ? hit_line_word2 :
                    lookup_hit_line_word2_w;
                resp_line_word3_q[resp_wr_ptr_q] <= req_fastbuf_fire_w ?
                    fastbuf_line_word3_w :
                    req_probe_merge_hit_complete_w ? hit_line_word3 :
                    lookup_hit_line_word3_w;
                resp_wait_lookup_q[resp_wr_ptr_q] <=
                    req_lookup_fire_w ||
                    (req_lookup_merge_fire_w && !req_lookup_merge_hit_complete_w) ||
                    (req_probe_merge_fire_w && !req_probe_merge_hit_complete_w);
                resp_lookup_merge_q[resp_wr_ptr_q] <=
                    (req_lookup_merge_fire_w && !req_lookup_merge_hit_complete_w) ||
                    (req_probe_merge_fire_w && !req_probe_merge_hit_complete_w);
                resp_wait_miss_q[resp_wr_ptr_q] <= req_miss_merge_fire_w;
                resp_wr_ptr_q <= resp_wr_ptr_q + {{(RESP_PTR_W-1){1'b0}}, 1'b1};
            end

            case ({req_enqueue_w, resp_pop_w})
                2'b10: resp_count_q <= resp_count_q + {{RESP_PTR_W{1'b0}}, 1'b1};
                2'b01: resp_count_q <= resp_count_q - {{RESP_PTR_W{1'b0}}, 1'b1};
                default: ;
            endcase

            case (state_q)
                ST_LOOKUP: begin
                    if (cacop_accept_w) begin
                        cacop_addr_q  <= cacop_addr_i;
                        cacop_mode_q  <= cacop_mode_i;
                        cacop_phase_q <= 1'b0;
                        state_q       <= ST_CACOP;
                        l2_req_valid_o <= 1'b0;
                        resp_wr_ptr_q  <= {RESP_PTR_W{1'b0}};
                        resp_rd_ptr_q  <= {RESP_PTR_W{1'b0}};
                        resp_count_q   <= {(RESP_PTR_W+1){1'b0}};
                        for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                            resp_done_q[resp_i] <= 1'b0;
                            resp_data_q[resp_i] <= 32'h0;
                            resp_addr_q[resp_i] <= {XLEN{1'b0}};
                            resp_line_valid_q[resp_i] <= 1'b0;
                            resp_line_word0_q[resp_i] <= 32'h0;
                            resp_line_word1_q[resp_i] <= 32'h0;
                            resp_line_word2_q[resp_i] <= 32'h0;
                            resp_line_word3_q[resp_i] <= 32'h0;
                            resp_wait_lookup_q[resp_i] <= 1'b0;
                            resp_lookup_merge_q[resp_i] <= 1'b0;
                            resp_wait_miss_q[resp_i] <= 1'b0;
                        end
                    end else begin
                        if (pf_inflight_q && l2_req_valid_o && l2_req_ready_i)
                            l2_req_valid_o <= 1'b0;

                        if (pf_inflight_q && l2_resp_valid_i) begin
                            pf_inflight_q   <= 1'b0;
                            pfbuf_valid_q   <= 1'b1;
                            pfbuf_tag_q     <= pf_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
                            pfbuf_idx_q     <= pf_addr_q[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
                            pfbuf_data_q[0] <= l2_resp_data_i_0;
                            pfbuf_data_q[1] <= l2_resp_data_i_1;
                            pfbuf_data_q[2] <= l2_resp_data_i_2;
                            pfbuf_data_q[3] <= l2_resp_data_i_3;
                            l2_req_valid_o  <= 1'b0;
                        end

                        // 主 lookup hit/miss 可在 BRAM 输出拍提前完成；保留 late
                        // 路径用于关闭 early 判定或其他查找类型。
                        if (lookup_hit_complete_w) begin
                            for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                                if (resp_lookup_merge_q[resp_i] &&
                                    (resp_addr_q[resp_i][XLEN-1:OFFSET_WIDTH] ==
                                     lookup_hit_addr_w[XLEN-1:OFFSET_WIDTH])) begin
                                    case (resp_addr_q[resp_i][OFFSET_WIDTH-1:2])
                                        2'd0: resp_data_q[resp_i] <= lookup_hit_line_word0_w;
                                        2'd1: resp_data_q[resp_i] <= lookup_hit_line_word1_w;
                                        2'd2: resp_data_q[resp_i] <= lookup_hit_line_word2_w;
                                        default: resp_data_q[resp_i] <= lookup_hit_line_word3_w;
                                    endcase
                                    resp_line_valid_q[resp_i] <= 1'b1;
                                    resp_line_word0_q[resp_i] <= lookup_hit_line_word0_w;
                                    resp_line_word1_q[resp_i] <= lookup_hit_line_word1_w;
                                    resp_line_word2_q[resp_i] <= lookup_hit_line_word2_w;
                                    resp_line_word3_q[resp_i] <= lookup_hit_line_word3_w;
                                    resp_done_q[resp_i] <= 1'b1;
                                    resp_wait_lookup_q[resp_i] <= 1'b0;
                                    resp_lookup_merge_q[resp_i] <= 1'b0;
                                end
                            end
                            if (!lookup_resp_bypass_w) begin
                                resp_done_q[lookup_hit_resp_slot_w] <= 1'b1;
                                resp_data_q[lookup_hit_resp_slot_w] <= lookup_hit_data_w;
                                resp_line_valid_q[lookup_hit_resp_slot_w] <= 1'b1;
                                resp_line_word0_q[lookup_hit_resp_slot_w] <= lookup_hit_line_word0_w;
                                resp_line_word1_q[lookup_hit_resp_slot_w] <= lookup_hit_line_word1_w;
                                resp_line_word2_q[lookup_hit_resp_slot_w] <= lookup_hit_line_word2_w;
                                resp_line_word3_q[lookup_hit_resp_slot_w] <= lookup_hit_line_word3_w;
                            end
                            resp_wait_lookup_q[lookup_hit_resp_slot_w] <= 1'b0;
                            resp_lookup_merge_q[lookup_hit_resp_slot_w] <= 1'b0;
                            resp_wait_miss_q[lookup_hit_resp_slot_w] <= 1'b0;
                            if (!pf_inflight_q) begin
                                l2_req_valid_o       <= 1'b0;
                                l2_req_addr_o        <= 32'h0;
                                l2_req_is_prefetch_o <= 1'b0;
                            end
                            push_linebuf(1'b1,
                                         lookup_hit_addr_w[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH],
                                         lookup_hit_addr_w[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH],
                                         lookup_hit_line_word0_w,
                                         lookup_hit_line_word1_w,
                                         lookup_hit_line_word2_w,
                                         lookup_hit_line_word3_w);
                            if (rtbuf_pending_lookup_hit_w) begin
                                fill_rtbuf(1'b1,
                                           lookup_hit_addr_w[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH],
                                           lookup_hit_addr_w[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH],
                                           lookup_hit_line_word0_w,
                                           lookup_hit_line_word1_w,
                                           lookup_hit_line_word2_w,
                                           lookup_hit_line_word3_w);
                            end
                        end else if (lookup_miss_w) begin
                            miss_addr_q          <= lookup_miss_addr_w;
                            miss_resp_slot_q     <= lookup_miss_resp_slot_w;
                            resp_wait_miss_q[lookup_miss_resp_slot_w] <= 1'b1;
                            resp_wait_lookup_q[lookup_miss_resp_slot_w] <= 1'b0;
                            for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                                if (resp_wait_lookup_q[resp_i] &&
                                    (resp_addr_q[resp_i][XLEN-1:OFFSET_WIDTH] ==
                                    lookup_miss_addr_w[XLEN-1:OFFSET_WIDTH])) begin
                                    resp_wait_lookup_q[resp_i] <= 1'b0;
                                    resp_lookup_merge_q[resp_i] <= 1'b0;
                                    resp_wait_miss_q[resp_i] <= 1'b1;
                                end
                            end
                            l2_req_valid_o       <= 1'b1;
                            l2_req_addr_o        <= lookup_miss_addr_w;
                            l2_req_is_prefetch_o <= 1'b0;
                            state_q              <= ST_MISS;
                        end else begin
                            if (!pf_inflight_q)
                                l2_req_valid_o <= 1'b0;
                        end

                        if (probe_lookup_hit_complete_w) begin
                            for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                                if (resp_lookup_merge_q[resp_i] &&
                                    (resp_addr_q[resp_i][XLEN-1:OFFSET_WIDTH] ==
                                     probe_lookup_addr_d2[XLEN-1:OFFSET_WIDTH])) begin
                                    case (resp_addr_q[resp_i][OFFSET_WIDTH-1:2])
                                        2'd0: resp_data_q[resp_i] <= hit_line_word0;
                                        2'd1: resp_data_q[resp_i] <= hit_line_word1;
                                        2'd2: resp_data_q[resp_i] <= hit_line_word2;
                                        default: resp_data_q[resp_i] <= hit_line_word3;
                                    endcase
                                    resp_line_valid_q[resp_i] <= 1'b1;
                                    resp_line_word0_q[resp_i] <= hit_line_word0;
                                    resp_line_word1_q[resp_i] <= hit_line_word1;
                                    resp_line_word2_q[resp_i] <= hit_line_word2;
                                    resp_line_word3_q[resp_i] <= hit_line_word3;
                                    resp_done_q[resp_i] <= 1'b1;
                                    resp_wait_lookup_q[resp_i] <= 1'b0;
                                    resp_lookup_merge_q[resp_i] <= 1'b0;
                                end
                            end
                            if (rtbuf_pending_q &&
                                (probe_lookup_addr_d2[XLEN-1:OFFSET_WIDTH] ==
                                 rtbuf_pending_addr_q[XLEN-1:OFFSET_WIDTH])) begin
                                fill_rtbuf(1'b1,
                                           probe_lookup_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH],
                                           probe_lookup_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH],
                                           hit_line_word0, hit_line_word1,
                                           hit_line_word2, hit_line_word3);
                            end
                            push_linebuf(1'b1,
                                         probe_lookup_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH],
                                         probe_lookup_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH],
                                         hit_line_word0, hit_line_word1,
                                         hit_line_word2, hit_line_word3);
                        end

                        if (shadow_probe_hit_complete_w) begin
                            fill_altbuf(1'b1,
                                        shadow_probe_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH],
                                        shadow_probe_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH],
                                        hit_line_word0, hit_line_word1,
                                        hit_line_word2, hit_line_word3);
                        end

                        if (lookahead_probe_hit_complete_w) begin
                            if (!pfbuf_valid_q) begin
                                pfbuf_valid_q   <= 1'b1;
                                pfbuf_tag_q     <= lookahead_probe_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
                                pfbuf_idx_q     <= lookahead_probe_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
                                pfbuf_data_q[0] <= hit_line_word0;
                                pfbuf_data_q[1] <= hit_line_word1;
                                pfbuf_data_q[2] <= hit_line_word2;
                                pfbuf_data_q[3] <= hit_line_word3;
                            end else if (!pfbuf1_valid_q) begin
                                pfbuf1_valid_q   <= 1'b1;
                                pfbuf1_tag_q     <= lookahead_probe_addr_d2[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
                                pfbuf1_idx_q     <= lookahead_probe_addr_d2[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
                                pfbuf1_data_q[0] <= hit_line_word0;
                                pfbuf1_data_q[1] <= hit_line_word1;
                                pfbuf1_data_q[2] <= hit_line_word2;
                                pfbuf1_data_q[3] <= hit_line_word3;
                            end
                        end

                        if (req_fastbuf_fire_w) begin
                            if (req_rtbuf_fire_w) begin
                                push_linebuf(1'b1,
                                             rtbuf_hit_tag_w,
                                             rtbuf_hit_idx_w,
                                             rtbuf_hit_word0_w,
                                             rtbuf_hit_word1_w,
                                             rtbuf_hit_word2_w,
                                             rtbuf_hit_word3_w);
                            end else if (req_pfbuf_fire_w) begin
                                push_linebuf(1'b1,
                                             pfbuf_hit_tag_w,
                                             pfbuf_hit_idx_w,
                                             pfbuf_hit_word0_w,
                                             pfbuf_hit_word1_w,
                                             pfbuf_hit_word2_w,
                                             pfbuf_hit_word3_w);
                                if (req_pfbuf0_fire_w)
                                    pfbuf_valid_q <= 1'b0;
                                if (req_pfbuf1_fire_w)
                                    pfbuf1_valid_q <= 1'b0;
                            end else if (req_altbuf_fire_w) begin
                                push_linebuf(1'b1,
                                             altbuf_hit_tag_w,
                                             altbuf_hit_idx_w,
                                             altbuf_hit_word0_w,
                                             altbuf_hit_word1_w,
                                             altbuf_hit_word2_w,
                                             altbuf_hit_word3_w);
                            end
                        end

                        if (prefetch_can_start_w) begin
                            l2_req_valid_o       <= 1'b1;
                            l2_req_addr_o        <= linebuf_next_addr;
                            l2_req_is_prefetch_o <= 1'b1;
                            pf_inflight_q        <= 1'b1;
                            pf_addr_q            <= linebuf_next_addr;
                        end
                    end
                end
                ST_MISS: begin
                    if (l2_req_valid_o && l2_req_ready_i)
                        l2_req_valid_o <= 1'b0;
                    if (l2_resp_valid_i) begin
                        for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                            if (resp_wait_miss_q[resp_i] &&
                                (resp_addr_q[resp_i][XLEN-1:OFFSET_WIDTH] ==
                                 miss_addr_q[XLEN-1:OFFSET_WIDTH])) begin
                                if (!(miss_resp_bypass_w &&
                                      (resp_i[RESP_PTR_W-1:0] == resp_rd_ptr_q))) begin
                                    case (resp_addr_q[resp_i][OFFSET_WIDTH-1:2])
                                        2'd0: resp_data_q[resp_i] <= l2_resp_data_i_0;
                                        2'd1: resp_data_q[resp_i] <= l2_resp_data_i_1;
                                        2'd2: resp_data_q[resp_i] <= l2_resp_data_i_2;
                                        default: resp_data_q[resp_i] <= l2_resp_data_i_3;
                                    endcase
                                    resp_line_valid_q[resp_i] <= 1'b1;
                                    resp_line_word0_q[resp_i] <= l2_resp_data_i_0;
                                    resp_line_word1_q[resp_i] <= l2_resp_data_i_1;
                                    resp_line_word2_q[resp_i] <= l2_resp_data_i_2;
                                    resp_line_word3_q[resp_i] <= l2_resp_data_i_3;
                                    resp_done_q[resp_i] <= 1'b1;
                                end
                                resp_wait_lookup_q[resp_i] <= 1'b0;
                                resp_lookup_merge_q[resp_i] <= 1'b0;
                                resp_wait_miss_q[resp_i] <= 1'b0;
                            end
                        end
                        push_linebuf(1'b1, miss_tag, miss_idx,
                                     l2_resp_data_i_0, l2_resp_data_i_1,
                                     l2_resp_data_i_2, l2_resp_data_i_3);
                        if (rtbuf_pending_miss_hit_w) begin
                            fill_rtbuf(1'b1, miss_tag, miss_idx,
                                       l2_resp_data_i_0, l2_resp_data_i_1,
                                       l2_resp_data_i_2, l2_resp_data_i_3);
                        end
                        replace_way_q  <= replace_way_q + 1'b1;
                        state_q        <= ST_LOOKUP;
                    end
                end
                ST_CACOP: begin
                    if (!cacop_phase_q) begin
                        cacop_phase_q <= 1'b1;
                    end else begin
                        cacop_done_q    <= 1'b1;
                        cacop_phase_q   <= 1'b0;
                        state_q         <= ST_LOOKUP;
                        resp_wr_ptr_q   <= {RESP_PTR_W{1'b0}};
                        resp_rd_ptr_q   <= {RESP_PTR_W{1'b0}};
                        resp_count_q    <= {(RESP_PTR_W+1){1'b0}};
                        for (resp_i = 0; resp_i < RESP_DEPTH; resp_i = resp_i + 1) begin
                            resp_done_q[resp_i] <= 1'b0;
                            resp_data_q[resp_i] <= 32'h0;
                            resp_addr_q[resp_i] <= {XLEN{1'b0}};
                            resp_line_valid_q[resp_i] <= 1'b0;
                            resp_line_word0_q[resp_i] <= 32'h0;
                            resp_line_word1_q[resp_i] <= 32'h0;
                            resp_line_word2_q[resp_i] <= 32'h0;
                            resp_line_word3_q[resp_i] <= 32'h0;
                            resp_wait_lookup_q[resp_i] <= 1'b0;
                            resp_lookup_merge_q[resp_i] <= 1'b0;
                            resp_wait_miss_q[resp_i] <= 1'b0;
                        end
                        linebuf_valid_q  <= 1'b0;
                        linebuf1_valid_q <= 1'b0;
                        linebuf2_valid_q <= 1'b0;
                        linebuf3_valid_q <= 1'b0;
                        linebuf4_valid_q <= 1'b0;
                        linebuf5_valid_q <= 1'b0;
                        linebuf6_valid_q <= 1'b0;
                        linebuf7_valid_q <= 1'b0;
                        linebuf8_valid_q <= 1'b0;
                        linebuf9_valid_q <= 1'b0;
                        linebuf10_valid_q <= 1'b0;
                        linebuf11_valid_q <= 1'b0;
                        linebuf12_valid_q <= 1'b0;
                        linebuf13_valid_q <= 1'b0;
                        linebuf14_valid_q <= 1'b0;
                        linebuf15_valid_q <= 1'b0;
                        rtbuf_valid_q    <= 1'b0;
                        rtbuf1_valid_q   <= 1'b0;
                        rtbuf2_valid_q   <= 1'b0;
                        rtbuf3_valid_q   <= 1'b0;
                        rtbuf4_valid_q   <= 1'b0;
                        rtbuf5_valid_q   <= 1'b0;
                        rtbuf6_valid_q   <= 1'b0;
                        rtbuf7_valid_q   <= 1'b0;
                        rtbuf_pending_q  <= 1'b0;
                        pfbuf_valid_q    <= 1'b0;
                        pfbuf1_valid_q   <= 1'b0;
                        altbuf_valid_q   <= 1'b0;
                        altbuf1_valid_q  <= 1'b0;
                        redirect_fast_valid_q <= 1'b0;
                        redirect_fast_line_valid_q <= 1'b0;
                    end
                end
            endcase

            if (l2_pf_resp_accept_w) begin
                if (l2_pf_resp_fill_pfbuf0_w) begin
                    pfbuf_valid_q   <= 1'b1;
                    pfbuf_tag_q     <= l2_pf_resp_tag_w;
                    pfbuf_idx_q     <= l2_pf_resp_idx_w;
                    pfbuf_data_q[0] <= l2_pf_resp_data_i_0;
                    pfbuf_data_q[1] <= l2_pf_resp_data_i_1;
                    pfbuf_data_q[2] <= l2_pf_resp_data_i_2;
                    pfbuf_data_q[3] <= l2_pf_resp_data_i_3;
                end else if (l2_pf_resp_fill_pfbuf1_w) begin
                    pfbuf1_valid_q   <= 1'b1;
                    pfbuf1_tag_q     <= l2_pf_resp_tag_w;
                    pfbuf1_idx_q     <= l2_pf_resp_idx_w;
                    pfbuf1_data_q[0] <= l2_pf_resp_data_i_0;
                    pfbuf1_data_q[1] <= l2_pf_resp_data_i_1;
                    pfbuf1_data_q[2] <= l2_pf_resp_data_i_2;
                    pfbuf1_data_q[3] <= l2_pf_resp_data_i_3;
                end
            end
        end
    end

`ifdef CPU_DEBUG_HAS_RUNTIME
    reg        dbg_req_hold_q;
    reg [31:0] dbg_req_addr_q;
    reg        dbg_l2_req_hold_q;
    reg [31:0] dbg_l2_req_addr_q;

    `CPU_DEBUG_WATCHDOG(icache_miss_wait, clk, rst_n,
        (state_q == ST_MISS),
        l2_resp_valid_i,
        128,
        $sformatf("[CACHE][ICACHE][DEADLOCK] miss_addr=0x%08x l2_req(valid=%0d ready=%0d addr=0x%08x)",
                  miss_addr_q, l2_req_valid_o, l2_req_ready_i, l2_req_addr_o))

    `CPU_DEBUG_WATCHDOG(icache_stale_l2_wait, clk, rst_n,
        stale_l2_resp_pending_q,
        l2_resp_valid_i,
        256,
        $sformatf("[CACHE][ICACHE][DEADLOCK] waiting stale L2 response after flush: req(valid=%0d ready=%0d addr=0x%08x) l2_req(valid=%0d ready=%0d addr=0x%08x)",
                  req_valid_i, req_ready_o, req_addr_i,
                  l2_req_valid_o, l2_req_ready_i, l2_req_addr_o))

    `CPU_DEBUG_WATCHDOG(icache_prefetch_wait, clk, rst_n,
        pf_inflight_q,
        l2_resp_valid_i,
        256,
        $sformatf("[CACHE][ICACHE][DEADLOCK] pf_addr=0x%08x l2_req(valid=%0d ready=%0d addr=0x%08x is_pf=%0d) req(valid=%0d ready=%0d addr=0x%08x)",
                  pf_addr_q, l2_req_valid_o, l2_req_ready_i, l2_req_addr_o,
                  l2_req_is_prefetch_o, req_valid_i, req_ready_o, req_addr_i))

    always @(posedge clk) begin
        if (!rst_n || flush) begin
            dbg_req_hold_q    <= 1'b0;
            dbg_l2_req_hold_q <= 1'b0;
            `CPU_DEBUG($sformatf("[CACHE][ICACHE][CLEAR] rst_n=%0d flush=%0d state=%0d", rst_n, flush, state_q));
        end else if (req_valid_i || resp_valid_o || l2_req_valid_o ||
                     l2_resp_valid_i || l2_pf_resp_valid_i ||
                     stale_l2_resp_pending_q || (lookup_valid_d2 && !cache_hit_q)) begin
            if (dbg_req_hold_q) begin
                `CPU_ASSERT("ICACHE_REQ_STABLE",
                    !req_valid_i || req_ready_o || (req_addr_i == dbg_req_addr_q),
                    $sformatf("[CACHE][ICACHE][ASSERT] CPU request address changed while stalled: prev=0x%08x now=0x%08x ready=%0d",
                              dbg_req_addr_q, req_addr_i, req_ready_o))
            end
            if (dbg_l2_req_hold_q) begin
                `CPU_ASSERT("ICACHE_L2_REQ_STABLE",
                    !l2_req_valid_o || l2_req_ready_i || (l2_req_addr_o == dbg_l2_req_addr_q),
                    $sformatf("[CACHE][ICACHE][ASSERT] L2 request address changed while stalled: prev=0x%08x now=0x%08x ready=%0d",
                              dbg_l2_req_addr_q, l2_req_addr_o, l2_req_ready_i))
            end
            dbg_req_hold_q    <= req_valid_i && !req_ready_o;
            dbg_req_addr_q    <= req_addr_i;
            dbg_l2_req_hold_q <= l2_req_valid_o && !l2_req_ready_i;
            dbg_l2_req_addr_q <= l2_req_addr_o;
            `CPU_DEBUG($sformatf(
                "[CACHE][ICACHE] state=%0d stale_l2=%0d req(valid=%0d ready=%0d fire=%0d addr=0x%08x slot=%0d) linebuf(valid=%0d hit=%0d idx=0x%0x tag=0x%0x) pfbuf(valid=%0d hit=%0d idx=0x%0x tag=0x%0x inflight=%0d addr=0x%08x) lookup(valid=%0d addr=0x%08x hit=%0d way=0x%0x slot=%0d) respq(count=%0d rd=%0d wr=%0d head_done=%0d emit=%0d bypass=%0d) l2_req(valid=%0d ready=%0d addr=0x%08x is_pf=%0d) l2_resp=%0d l2_pf_resp(valid=%0d accept=%0d addr=0x%08x) resp(valid=%0d instr=0x%08x)",
                state_q, stale_l2_resp_pending_q,
                req_valid_i, req_ready_o, req_fire_w, req_addr_i,
                req_resp_slot_w,
                linebuf_valid_q, linebuf_hit_req, linebuf_idx_q, linebuf_tag_q,
                pfbuf_valid_q, pfbuf_hit_req, pfbuf_idx_q, pfbuf_tag_q, pf_inflight_q, pf_addr_q,
                lookup_valid_d2, lookup_addr_d2, cache_hit_q, way_hit_q, lookup_resp_slot_d2,
                resp_count_q, resp_rd_ptr_q, resp_wr_ptr_q,
                resp_head_done_w, resp_emit_w, resp_bypass_w,
                l2_req_valid_o, l2_req_ready_i, l2_req_addr_o, l2_req_is_prefetch_o,
                l2_resp_valid_i, l2_pf_resp_valid_i, l2_pf_resp_accept_w, l2_pf_resp_addr_i,
                resp_valid_o, resp_instr_o
            ));
        end else begin
            dbg_req_hold_q    <= req_valid_i && !req_ready_o;
            dbg_req_addr_q    <= req_addr_i;
            dbg_l2_req_hold_q <= l2_req_valid_o && !l2_req_ready_i;
            dbg_l2_req_addr_q <= l2_req_addr_o;
        end
    end
`endif

    `CPU_DEBUG_MODULE("cpu_l1_icache")
endmodule
