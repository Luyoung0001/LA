`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ============================================================================
// L1 DCache — 4-way 组相联，128 line，4 word/line（16B line = 8KB）
//             Write-through 到 L2
//
// FPGA 路径（RAMB36E1 原语，DOA_REG=0，1 拍延迟，状态机不变）：
//   data_ram：4 way × 4 word × RAMB36E1（SDP x32，深度 128）= 16 个
//   tag_ram ：4 way × RAMB36E1（SDP x32，深度 128）          =  4 个
//   共 20 个 RAMB36E1
//   写端口 WEBWE[3:0] 实现字节/半字/字粒度写
//
// 仿真（reg 数组，与原设计完全一致）
// ============================================================================
module cpu_l1_dcache #(
    parameter XLEN      = 32,
    parameter NUM_WAYS  = 4,
    parameter NUM_LINES = 128,
    parameter LINE_SIZE = 16
) (
    input  wire            clk,
    input  wire            rst_n,

    input  wire            req_valid_i,
    input  wire            req_is_load_i,
    input  wire            req_is_store_i,
    input  wire [1:0]      req_size_i,
    input  wire [XLEN-1:0] req_addr_i,
    input  wire [XLEN-1:0] req_store_data_i,
    input  wire            req_uncached_i,
    output wire            resp_valid_o,
    output wire [XLEN-1:0] resp_load_data_o,
    output wire            resp_fault_o,

    input  wire            cacop_valid_i,
    input  wire [1:0]      cacop_mode_i,
    input  wire [XLEN-1:0] cacop_addr_i,
    output wire            cacop_ready_o,
    output wire            cacop_done_o,

    output wire            l2_rd_valid_o,
    output wire [XLEN-1:0] l2_rd_addr_o,
    output wire [1:0]      l2_rd_size_o,
    output wire            l2_rd_uncached_o,
    input  wire            l2_rd_ready_i,

    input  wire            l2_resp_valid_i,
    input  wire [XLEN-1:0] l2_resp_data_i_0,
    input  wire [XLEN-1:0] l2_resp_data_i_1,
    input  wire [XLEN-1:0] l2_resp_data_i_2,
    input  wire [XLEN-1:0] l2_resp_data_i_3,

    output wire            l2_wr_valid_o,
    output wire [XLEN-1:0] l2_wr_addr_o,
    output wire [XLEN-1:0] l2_wr_data_o,
    output wire [3:0]      l2_wr_strb_o,
    input  wire            l2_wr_ready_i,
    input  wire            l2_wr_done_i
`ifdef PERF_DC
    ,
    output wire            perf_dc_access,
    output wire            perf_dc_read,
    output wire            perf_dc_write,
    output wire            perf_dc_hit,
    output wire            perf_dc_miss,
    output wire            perf_dc_refill,
    output wire            perf_dc_evict
`endif
);

    localparam INDEX_WIDTH    = $clog2(NUM_LINES);                 // 7
    localparam OFFSET_WIDTH   = $clog2(LINE_SIZE);                 // 4
    localparam TAG_WIDTH      = XLEN - INDEX_WIDTH - OFFSET_WIDTH; // 21
    localparam WORDS_PER_LINE = LINE_SIZE / 4;                     // 4
    localparam WAY_WIDTH      = $clog2(NUM_WAYS);                  // 2
    localparam STOREQ_DEPTH   = 4;
    localparam [2:0] STOREQ_DEPTH_COUNT = 3'd4;

    localparam ST_IDLE      = 3'd0;
    localparam ST_LOAD_CHK  = 3'd1;
    localparam ST_LOAD_MISS = 3'd2;
    localparam ST_STORE     = 3'd3;
    localparam ST_CACOP     = 3'd4;

    function [3:0] gen_wstrb;
        input [1:0] size;
        input [1:0] addr_lsb;
        case (size)
            2'b00: gen_wstrb = 4'b0001 << addr_lsb;
            2'b01: gen_wstrb = 4'b0011 << addr_lsb;
            default: gen_wstrb = 4'b1111;
        endcase
    endfunction

    function [31:0] align_store_data;
        input [1:0] size;
        input [1:0] addr_lsb;
        input [31:0] data;
        case (size)
            2'b00: align_store_data = {24'b0, data[7:0]} << {addr_lsb, 3'b000};
            2'b01: align_store_data = {16'b0, data[15:0]} << {addr_lsb, 3'b000};
            default: align_store_data = data;
        endcase
    endfunction

    function [31:0] merge_store_word;
        input [31:0] old_word;
        input [31:0] new_data;
        input [3:0]  new_strb;
        begin
            merge_store_word = old_word;
            if (new_strb[0]) merge_store_word[7:0]   = new_data[7:0];
            if (new_strb[1]) merge_store_word[15:8]  = new_data[15:8];
            if (new_strb[2]) merge_store_word[23:16] = new_data[23:16];
            if (new_strb[3]) merge_store_word[31:24] = new_data[31:24];
        end
    endfunction

    // =========================================================================
    // FPGA 路径：RAMB36E1，DOA_REG=0（1 拍延迟，状态机与仿真完全一致）
    // =========================================================================

    reg [2:0]            state_q;
    reg [31:0]           req_addr_q;
    reg [31:0]           req_data_q;
    reg [1:0]            req_size_q;
    reg                  req_uncached_q;
    reg                  resp_valid_q;
    reg [31:0]           resp_load_data_q;
    reg                  l2_rd_valid_q;
    reg [31:0]           l2_rd_addr_q;
    reg [1:0]            l2_rd_size_q;
    reg                  l2_rd_uncached_q;
    reg [WAY_WIDTH-1:0]  replace_way_q;
    reg                  store_issued_q;
    reg                  store_l2_outstanding_q;
    reg                  store_fwd_valid_q;
    reg [31:0]           store_fwd_addr_q;
    reg [31:0]           store_fwd_data_q;
    reg [1:0]            cacop_mode_q;
    reg                  cacop_done_q;
    reg [2:0]            storeq_count_q;
    reg [31:0]           storeq_addr_q [0:STOREQ_DEPTH-1];
    reg [31:0]           storeq_data_q [0:STOREQ_DEPTH-1];
    reg [3:0]            storeq_strb_q [0:STOREQ_DEPTH-1];
    integer              sq_i;

    wire [TAG_WIDTH-1:0]   lk_tag      = req_addr_q[XLEN-1 : OFFSET_WIDTH+INDEX_WIDTH];
    wire [INDEX_WIDTH-1:0] lk_idx      = req_addr_q[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH];
    wire [1:0]             lk_word_off = req_addr_q[OFFSET_WIDTH-1 : 2];

    assign resp_fault_o     = 1'b0;
    assign cacop_ready_o    = (state_q == ST_IDLE) && !req_valid_i &&
                              !l2_rd_valid_o && (storeq_count_q == 3'd0) &&
                              !store_l2_outstanding_q && !store_issued_q;
    assign cacop_done_o     = cacop_done_q;

    wire accept_next_req_after_resp_w;
    wire storeq_l2_accept_w;

    // BRAM 读地址：ST_IDLE 时用 req_addr_i（新请求地址），其他状态保持 lk_idx
    // RAMB36E1 SDP x32：ADDRARDADDR[14:5]=行地址，[4:0]=0
    wire [INDEX_WIDTH-1:0] rd_idx       =
        ((state_q == ST_IDLE) || accept_next_req_after_resp_w) ?
            (cacop_valid_i ? cacop_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH] :
                             req_addr_i[OFFSET_WIDTH+INDEX_WIDTH-1 : OFFSET_WIDTH]) :
            lk_idx;
    wire [14:0]            bram_rd_addr = {rd_idx,  8'b0};
    wire [14:0]            bram_wr_addr = {lk_idx,  8'b0};

    // store 写控制
    wire        store_en;
    wire [3:0]  store_strb = gen_wstrb(req_size_q, req_addr_q[1:0]);
    wire [31:0] store_data = align_store_data(req_size_q, req_addr_q[1:0], req_data_q);
    wire [3:0]  direct_store_strb_w =
        gen_wstrb(req_size_i, req_addr_i[1:0]);
    wire [31:0] direct_store_data_w =
        align_store_data(req_size_i, req_addr_i[1:0], req_store_data_i);

    // refill 写控制
    wire        refill_en  = l2_resp_valid_i && (state_q == ST_LOAD_MISS) && !req_uncached_q;

    wire [31:0] bram_tag_wdata = {10'b0, 1'b1, lk_tag};

    wire [31:0] data_bram_rd [0:NUM_WAYS-1][0:WORDS_PER_LINE-1];
    wire [31:0] tag_bram_rd  [0:NUM_WAYS-1];

    // 命中判断（DOA_REG=0，ST_LOAD_CHK / ST_STORE 时 T1 输出有效）
    wire [NUM_WAYS-1:0] way_hit;
    wire [31:0]         way_data [0:NUM_WAYS-1];
    genvar gw2;
    generate
        for (gw2 = 0; gw2 < NUM_WAYS; gw2 = gw2 + 1) begin : gen_hit
            assign way_hit[gw2]  = tag_bram_rd[gw2][TAG_WIDTH] &&
                                    (tag_bram_rd[gw2][TAG_WIDTH-1:0] == lk_tag);
            assign way_data[gw2] = data_bram_rd[gw2][lk_word_off];
        end
    endgenerate

    wire        cache_hit = |way_hit;
    wire [31:0] hit_data  =
        way_hit[0] ? way_data[0] :
        way_hit[1] ? way_data[1] :
        way_hit[2] ? way_data[2] : way_data[3];
    wire store_fwd_hit_w =
        store_fwd_valid_q && (store_fwd_addr_q[31:2] == req_addr_q[31:2]);
    wire storeq_fwd_hit0_w =
        (storeq_count_q > 3'd0) && (storeq_addr_q[0][31:2] == req_addr_q[31:2]);
    wire [31:0] storeq_fwd_data0_w =
        storeq_fwd_hit0_w ? merge_store_word(hit_data, storeq_data_q[0], storeq_strb_q[0]) :
                            hit_data;
    wire storeq_fwd_hit1_w =
        (storeq_count_q > 3'd1) && (storeq_addr_q[1][31:2] == req_addr_q[31:2]);
    wire [31:0] storeq_fwd_data1_w =
        storeq_fwd_hit1_w ? merge_store_word(storeq_fwd_data0_w, storeq_data_q[1], storeq_strb_q[1]) :
                            storeq_fwd_data0_w;
    wire storeq_fwd_hit2_w =
        (storeq_count_q > 3'd2) && (storeq_addr_q[2][31:2] == req_addr_q[31:2]);
    wire [31:0] storeq_fwd_data2_w =
        storeq_fwd_hit2_w ? merge_store_word(storeq_fwd_data1_w, storeq_data_q[2], storeq_strb_q[2]) :
                            storeq_fwd_data1_w;
    wire storeq_fwd_hit3_w =
        (storeq_count_q > 3'd3) && (storeq_addr_q[3][31:2] == req_addr_q[31:2]);
    wire [31:0] storeq_fwd_data_w =
        storeq_fwd_hit3_w ? merge_store_word(storeq_fwd_data2_w, storeq_data_q[3], storeq_strb_q[3]) :
                            storeq_fwd_data2_w;
    wire [31:0] load_hit_data_w = store_fwd_hit_w ? store_fwd_data_q : storeq_fwd_data_w;
    wire load_hit_resp_w = (state_q == ST_LOAD_CHK) && !req_uncached_q && cache_hit;
    wire uncached_load_resp_w =
        (state_q == ST_LOAD_MISS) && req_uncached_q && l2_resp_valid_i;
    wire store_order_busy_w;
    wire uncached_load_direct_rd_w =
        (state_q == ST_IDLE) && req_valid_i && req_is_load_i && req_uncached_i &&
        !store_order_busy_w &&
        !l2_rd_valid_q;
    wire uncached_load_direct_accept_w =
        uncached_load_direct_rd_w && l2_rd_ready_i;
    wire uncached_store_direct_wr_w =
        (state_q == ST_IDLE) && req_valid_i && req_is_store_i && req_uncached_i &&
        !store_order_busy_w;
    wire uncached_store_direct_accept_w =
        uncached_store_direct_wr_w && l2_wr_ready_i;

    assign resp_valid_o     = resp_valid_q || load_hit_resp_w || uncached_load_resp_w;
    assign resp_load_data_o = uncached_load_resp_w ? l2_resp_data_i_0 :
                              load_hit_resp_w ? load_hit_data_w : resp_load_data_q;
    assign l2_rd_valid_o    = l2_rd_valid_q || uncached_load_direct_rd_w;
    assign l2_rd_addr_o     = uncached_load_direct_rd_w ? req_addr_i : l2_rd_addr_q;
    assign l2_rd_size_o     = uncached_load_direct_rd_w ? req_size_i : l2_rd_size_q;
    assign l2_rd_uncached_o = uncached_load_direct_rd_w ? 1'b1 : l2_rd_uncached_q;

    wire storeq_same_l2_line_w =
        ((storeq_count_q > 3'd0) && (storeq_addr_q[0][31:5] == req_addr_q[31:5])) ||
        ((storeq_count_q > 3'd1) && (storeq_addr_q[1][31:5] == req_addr_q[31:5])) ||
        ((storeq_count_q > 3'd2) && (storeq_addr_q[2][31:5] == req_addr_q[31:5])) ||
        ((storeq_count_q > 3'd3) && (storeq_addr_q[3][31:5] == req_addr_q[31:5]));
    assign store_order_busy_w =
        (storeq_count_q != 3'd0) || (store_l2_outstanding_q && !l2_wr_done_i);
    wire load_wait_store_order_w =
        (state_q == ST_LOAD_CHK) &&
        ((req_uncached_q && store_order_busy_w) ||
         (!req_uncached_q && !cache_hit && storeq_same_l2_line_w));

    wire storeq_has_space_w =
        (storeq_count_q < STOREQ_DEPTH_COUNT) || storeq_l2_accept_w;
    wire cached_store_complete_w =
        (state_q == ST_STORE) && !req_uncached_q && storeq_has_space_w;
    assign store_en = cached_store_complete_w && cache_hit;
    wire cached_load_miss_w =
        (state_q == ST_LOAD_CHK) && !req_uncached_q && !cache_hit &&
        !load_wait_store_order_w;
    wire refill_evict_w = refill_en && tag_bram_rd[replace_way_q][TAG_WIDTH];

    wire uncached_wr_valid_w =
        (state_q == ST_STORE) && req_uncached_q && !store_issued_q &&
        !store_order_busy_w;
    wire storeq_l2_valid_w = (storeq_count_q != 3'd0) && !uncached_wr_valid_w;
    assign l2_wr_valid_o = uncached_store_direct_wr_w || uncached_wr_valid_w || storeq_l2_valid_w;
    assign l2_wr_addr_o  = uncached_store_direct_wr_w ? req_addr_i :
                           uncached_wr_valid_w ? req_addr_q : storeq_addr_q[0];
    assign l2_wr_data_o  = uncached_store_direct_wr_w ? direct_store_data_w :
                           uncached_wr_valid_w ? store_data : storeq_data_q[0];
    assign l2_wr_strb_o  = uncached_store_direct_wr_w ? direct_store_strb_w :
                           uncached_wr_valid_w ? store_strb : storeq_strb_q[0];
    assign storeq_l2_accept_w = storeq_l2_valid_w && l2_wr_ready_i;
    wire uncached_store_issue_w = uncached_wr_valid_w && l2_wr_ready_i;
    wire uncached_store_complete_w = uncached_store_issue_w;
    wire storeq_enqueue_w = cached_store_complete_w;
    wire [2:0] storeq_count_after_deq_w =
        storeq_count_q - (storeq_l2_accept_w ? 3'd1 : 3'd0);
    wire [2:0] storeq_count_next_w =
        storeq_count_after_deq_w + (storeq_enqueue_w ? 3'd1 : 3'd0);

    assign accept_next_req_after_resp_w =
        req_valid_i &&
        (((state_q == ST_LOAD_CHK) && !req_uncached_q && cache_hit) ||
         ((state_q == ST_LOAD_MISS) && l2_resp_valid_i) ||
         cached_store_complete_w || uncached_store_complete_w);

    wire [31:0] refill_load_data =
        (lk_word_off == 2'd0) ? l2_resp_data_i_0 :
        (lk_word_off == 2'd1) ? l2_resp_data_i_1 :
        (lk_word_off == 2'd2) ? l2_resp_data_i_2 : l2_resp_data_i_3;

`ifdef PERF_DC
    wire perf_dc_cached_load_lookup_w =
        (state_q == ST_LOAD_CHK) && !req_uncached_q && !load_wait_store_order_w;
    wire perf_dc_cached_store_lookup_w =
        (state_q == ST_STORE) && !req_uncached_q && storeq_has_space_w;
    assign perf_dc_access = perf_dc_cached_load_lookup_w ||
                            perf_dc_cached_store_lookup_w;
    assign perf_dc_read   = perf_dc_cached_load_lookup_w;
    assign perf_dc_write  = perf_dc_cached_store_lookup_w;
    assign perf_dc_hit    = load_hit_resp_w ||
                            (perf_dc_cached_store_lookup_w && cache_hit);
    assign perf_dc_miss   = cached_load_miss_w ||
                            (perf_dc_cached_store_lookup_w && !cache_hit);
    assign perf_dc_refill = refill_en;
    assign perf_dc_evict  = refill_evict_w;
`endif

    genvar gw, gb;
    generate
        for (gw = 0; gw < NUM_WAYS; gw = gw + 1) begin : gen_way_bram

            wire tag_refill_we_w = refill_en && (replace_way_q == gw[WAY_WIDTH-1:0]);
            wire tag_cacop_index_we_w =
                (state_q == ST_CACOP) && (cacop_mode_q != 2'b10);
            wire tag_cacop_hit_we_w =
                (state_q == ST_CACOP) && (cacop_mode_q == 2'b10) && way_hit[gw];
            wire tag_cacop_we_w = tag_cacop_index_we_w || tag_cacop_hit_we_w;
            wire [31:0] tag_wdata_w = tag_cacop_we_w ? 32'h0 : bram_tag_wdata;

            RAMB36E1 #(
                .RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36),
                .DOA_REG(0), .INIT_FILE("NONE"), .SIM_COLLISION_CHECK("NONE"),
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

                wire is_target_word_w = (lk_word_off == gb[1:0]);
                wire data_store_we_w  = store_en && way_hit[gw] && is_target_word_w;
                wire data_refill_we_w = refill_en && (replace_way_q == gw[WAY_WIDTH-1:0]);
                wire any_we_w         = data_store_we_w || data_refill_we_w;

                wire [31:0] data_wdata_w =
                    data_store_we_w  ? store_data :
                    data_refill_we_w ? (
                        (gb == 0) ? l2_resp_data_i_0 :
                        (gb == 1) ? l2_resp_data_i_1 :
                        (gb == 2) ? l2_resp_data_i_2 : l2_resp_data_i_3
                    ) : 32'h0;

                wire [3:0] data_wstrb_w =
                    data_store_we_w  ? store_strb :
                    data_refill_we_w ? 4'hF : 4'h0;

                RAMB36E1 #(
                    .RAM_MODE("SDP"), .READ_WIDTH_A(36), .WRITE_WIDTH_B(36),
                    .DOA_REG(0), .INIT_FILE("NONE"), .SIM_COLLISION_CHECK("NONE"),
                    .WRITE_MODE_A("READ_FIRST"), .WRITE_MODE_B("READ_FIRST")
                ) u_data (
                    .CLKARDCLK(clk), .ENARDEN(1'b1),
                    .RSTRAMARSTRAM(1'b0), .RSTREGARSTREG(1'b0), .REGCEAREGCE(1'b1),
                    .WEA(4'h0), .ADDRARDADDR(bram_rd_addr),
                    .DIADI(32'h0), .DIPADIP(4'h0),
                    .DOADO(data_bram_rd[gw][gb]), .DOBDO(), .DOPADOP(), .DOPBDOP(),
                    .CLKBWRCLK(clk), .ENBWREN(any_we_w),
                    .WEBWE({4'b0, data_wstrb_w}), .ADDRBWRADDR(bram_wr_addr),
                    .DIBDI(data_wdata_w), .DIPBDIP(4'h0),
                    .CASCADEINA(1'b0), .CASCADEINB(1'b0),
                    .INJECTDBITERR(1'b0), .INJECTSBITERR(1'b0)
                );
            end
        end
    endgenerate

    always @(posedge clk) begin
        if (!rst_n) begin
            state_q        <= ST_IDLE;
            resp_valid_q     <= 1'b0;
            resp_load_data_q <= 32'b0;
            replace_way_q  <= {WAY_WIDTH{1'b0}};
            store_issued_q <= 1'b0;
            store_l2_outstanding_q <= 1'b0;
            store_fwd_valid_q <= 1'b0;
            store_fwd_addr_q  <= 32'h0;
            store_fwd_data_q  <= 32'h0;
            storeq_count_q <= 3'd0;
            for (sq_i = 0; sq_i < STOREQ_DEPTH; sq_i = sq_i + 1) begin
                storeq_addr_q[sq_i] <= 32'h0;
                storeq_data_q[sq_i] <= 32'h0;
                storeq_strb_q[sq_i] <= 4'h0;
            end
            cacop_mode_q   <= 2'b00;
            cacop_done_q   <= 1'b0;
            l2_rd_valid_q  <= 1'b0;
            l2_rd_addr_q   <= 32'h0;
            l2_rd_size_q   <= 2'b10;
            l2_rd_uncached_q <= 1'b0;
        end else begin
            resp_valid_q <= 1'b0;
            cacop_done_q <= 1'b0;
            store_fwd_valid_q <= 1'b0;
            case (state_q)
                ST_IDLE: begin
                    if (cacop_valid_i && cacop_ready_o) begin
                        req_addr_q   <= cacop_addr_i;
                        req_data_q   <= 32'h0;
                        req_size_q   <= 2'b10;
                        req_uncached_q <= 1'b0;
                        cacop_mode_q <= cacop_mode_i;
                        state_q      <= ST_CACOP;
                    end else if (req_valid_i) begin
                        req_addr_q <= req_addr_i;
                        req_data_q <= req_store_data_i;
                        req_size_q <= req_size_i;
                        req_uncached_q <= req_uncached_i;
                        if (req_is_load_i && req_uncached_i) begin
                            if (!store_order_busy_w) begin
                                l2_rd_valid_q <= !uncached_load_direct_accept_w;
                                l2_rd_addr_q  <= req_addr_i;
                                l2_rd_size_q  <= req_size_i;
                                l2_rd_uncached_q <= !uncached_load_direct_accept_w;
                                state_q <= ST_LOAD_MISS;
                            end else begin
                                state_q <= ST_LOAD_CHK;
                            end
                        end else if (req_is_load_i) begin
                            state_q <= ST_LOAD_CHK;
                        end else if (req_is_store_i) begin
                            if (req_uncached_i && !store_order_busy_w) begin
                                resp_valid_q <= uncached_store_direct_accept_w;
                                state_q <= uncached_store_direct_accept_w ? ST_IDLE : ST_STORE;
                            end else begin
                                state_q <= ST_STORE;
                            end
                        end
                    end
                end
                ST_LOAD_CHK: begin
                    if (!req_uncached_q && cache_hit) begin
                        if (req_valid_i) begin
                            req_addr_q <= req_addr_i;
                            req_data_q <= req_store_data_i;
                            req_size_q <= req_size_i;
                            req_uncached_q <= req_uncached_i;
                            if (req_is_load_i)
                                state_q <= ST_LOAD_CHK;
                            else if (req_is_store_i)
                                state_q <= ST_STORE;
                            else
                                state_q <= ST_IDLE;
                        end else begin
                            state_q <= ST_IDLE;
                        end
                    end else if (!load_wait_store_order_w) begin
                        l2_rd_valid_q <= 1'b1;
                        l2_rd_addr_q  <= req_uncached_q ? req_addr_q :
                                          {req_addr_q[31:OFFSET_WIDTH], {OFFSET_WIDTH{1'b0}}};
                        l2_rd_size_q  <= req_size_q;
                        l2_rd_uncached_q <= req_uncached_q;
                        state_q       <= ST_LOAD_MISS;
                    end
                end
                ST_LOAD_MISS: begin
                    if (l2_rd_valid_q && l2_rd_ready_i) begin
                        l2_rd_valid_q <= 1'b0;
                        l2_rd_uncached_q <= 1'b0;
                    end
                    if (l2_resp_valid_i) begin
                        // BRAM 写由原语写端口（refill_en）完成；本次 miss 直接返回 L2 数据。
                        // 这样不依赖 refill 后立即读同地址，避开 READ_FIRST 返回旧值的问题。
                        replace_way_q     <= replace_way_q + 1'b1;
                        resp_valid_q      <= !req_uncached_q;
                        resp_load_data_q  <= req_uncached_q ? l2_resp_data_i_0 : refill_load_data;
                        if (req_valid_i) begin
                            req_addr_q <= req_addr_i;
                            req_data_q <= req_store_data_i;
                            req_size_q <= req_size_i;
                            req_uncached_q <= req_uncached_i;
                            if (req_is_load_i)
                                state_q <= ST_LOAD_CHK;
                            else if (req_is_store_i)
                                state_q <= ST_STORE;
                            else
                                state_q <= ST_IDLE;
                        end else begin
                            state_q <= ST_IDLE;
                        end
                    end
                end
                ST_STORE: begin
                    if (cached_store_complete_w) begin
                        // cached store 更新 L1D 后进入本地 store queue，后台写穿透到 L2/AXI。
                        // 下一拍若紧跟同 word load，READ_FIRST BRAM 可能仍给旧值，
                        // 因此保留 1 拍 store-forward 数据。
                        resp_valid_q   <= 1'b1;
                        store_issued_q <= 1'b0;
                        store_fwd_valid_q <= 1'b1;
                        store_fwd_addr_q  <= req_addr_q;
                        store_fwd_data_q  <= merge_store_word(hit_data, store_data, store_strb);
                        if (req_valid_i) begin
                            req_addr_q <= req_addr_i;
                            req_data_q <= req_store_data_i;
                            req_size_q <= req_size_i;
                            req_uncached_q <= req_uncached_i;
                            if (req_is_load_i)
                                state_q <= ST_LOAD_CHK;
                            else if (req_is_store_i)
                                state_q <= ST_STORE;
                            else
                                state_q <= ST_IDLE;
                        end else begin
                            state_q <= ST_IDLE;
                        end
                    end else if (uncached_store_complete_w) begin
                        resp_valid_q   <= 1'b1;
                        store_issued_q <= 1'b0;
                        if (req_valid_i) begin
                            req_addr_q <= req_addr_i;
                            req_data_q <= req_store_data_i;
                            req_size_q <= req_size_i;
                            req_uncached_q <= req_uncached_i;
                            if (req_is_load_i)
                                state_q <= ST_LOAD_CHK;
                            else if (req_is_store_i)
                                state_q <= ST_STORE;
                            else
                                state_q <= ST_IDLE;
                        end else begin
                            state_q <= ST_IDLE;
                        end
                    end
                end
                ST_CACOP: begin
                    // 本 DCache 是 write-through，没有 dirty 位；CACOP 的写回+失效退化为失效。
                    cacop_done_q <= 1'b1;
                    state_q      <= ST_IDLE;
                end
            endcase

            if (storeq_l2_accept_w || uncached_store_issue_w || uncached_store_direct_accept_w)
                store_l2_outstanding_q <= 1'b1;
            else if (l2_wr_done_i)
                store_l2_outstanding_q <= 1'b0;

            if (storeq_l2_accept_w) begin
                if (storeq_count_q > 3'd1) begin
                    storeq_addr_q[0] <= storeq_addr_q[1];
                    storeq_data_q[0] <= storeq_data_q[1];
                    storeq_strb_q[0] <= storeq_strb_q[1];
                end
                if (storeq_count_q > 3'd2) begin
                    storeq_addr_q[1] <= storeq_addr_q[2];
                    storeq_data_q[1] <= storeq_data_q[2];
                    storeq_strb_q[1] <= storeq_strb_q[2];
                end
                if (storeq_count_q > 3'd3) begin
                    storeq_addr_q[2] <= storeq_addr_q[3];
                    storeq_data_q[2] <= storeq_data_q[3];
                    storeq_strb_q[2] <= storeq_strb_q[3];
                end
            end
            if (storeq_enqueue_w) begin
                case (storeq_count_after_deq_w)
                    3'd0: begin
                        storeq_addr_q[0] <= req_addr_q;
                        storeq_data_q[0] <= store_data;
                        storeq_strb_q[0] <= store_strb;
                    end
                    3'd1: begin
                        storeq_addr_q[1] <= req_addr_q;
                        storeq_data_q[1] <= store_data;
                        storeq_strb_q[1] <= store_strb;
                    end
                    3'd2: begin
                        storeq_addr_q[2] <= req_addr_q;
                        storeq_data_q[2] <= store_data;
                        storeq_strb_q[2] <= store_strb;
                    end
                    default: begin
                        storeq_addr_q[3] <= req_addr_q;
                        storeq_data_q[3] <= store_data;
                        storeq_strb_q[3] <= store_strb;
                    end
                endcase
            end
            if (storeq_l2_accept_w || storeq_enqueue_w)
                storeq_count_q <= storeq_count_next_w;
        end
    end

`ifdef CPU_DEBUG_HAS_RUNTIME
    reg        dbg_l2_rd_hold_q;
    reg [31:0] dbg_l2_rd_addr_q;
    reg        dbg_l2_wr_hold_q;
    reg [31:0] dbg_l2_wr_addr_q;
    reg [31:0] dbg_l2_wr_data_q;
    reg [3:0]  dbg_l2_wr_strb_q;

    `CPU_DEBUG_WATCHDOG(dcache_load_miss_wait, clk, rst_n,
        (state_q == ST_LOAD_MISS),
        l2_resp_valid_i,
        128,
        $sformatf("[CACHE][DCACHE][DEADLOCK] load_miss addr=0x%08x uncached=%0d l2_rd(valid=%0d ready=%0d addr=0x%08x size=%0d bypass=%0d)",
                  req_addr_q, req_uncached_q, l2_rd_valid_o, l2_rd_ready_i,
                  l2_rd_addr_o, l2_rd_size_o, l2_rd_uncached_o))

    `CPU_DEBUG_WATCHDOG(dcache_store_wait, clk, rst_n,
        (state_q == ST_STORE),
        (l2_wr_done_i || (l2_wr_valid_o && l2_wr_ready_i)),
        128,
        $sformatf("[CACHE][DCACHE][DEADLOCK] store addr=0x%08x issued=%0d l2_wr(valid=%0d ready=%0d done=%0d data=0x%08x strb=0x%0x)",
                  req_addr_q, store_issued_q, l2_wr_valid_o, l2_wr_ready_i, l2_wr_done_i, l2_wr_data_o, l2_wr_strb_o))

    always @(posedge clk) begin
        if (!rst_n) begin
            dbg_l2_rd_hold_q <= 1'b0;
            dbg_l2_wr_hold_q <= 1'b0;
            `CPU_DEBUG($sformatf("[CACHE][DCACHE][RESET] state=%0d", state_q));
        end else if (req_valid_i || resp_valid_o || l2_rd_valid_o || l2_wr_valid_o || l2_resp_valid_i || l2_wr_done_i) begin
            if (dbg_l2_rd_hold_q) begin
                `CPU_ASSERT("DCACHE_L2_RD_STABLE",
                    !l2_rd_valid_o || l2_rd_ready_i || (l2_rd_addr_o == dbg_l2_rd_addr_q),
                    $sformatf("[CACHE][DCACHE][ASSERT] L2 read addr changed while stalled: prev=0x%08x now=0x%08x",
                              dbg_l2_rd_addr_q, l2_rd_addr_o))
            end
            if (dbg_l2_wr_hold_q) begin
                `CPU_ASSERT("DCACHE_L2_WR_STABLE",
                    !l2_wr_valid_o || l2_wr_ready_i ||
                    ((l2_wr_addr_o == dbg_l2_wr_addr_q) &&
                     (l2_wr_data_o == dbg_l2_wr_data_q) &&
                     (l2_wr_strb_o == dbg_l2_wr_strb_q)),
                    $sformatf("[CACHE][DCACHE][ASSERT] L2 write changed while stalled: prev(addr=0x%08x data=0x%08x strb=0x%0x) now(addr=0x%08x data=0x%08x strb=0x%0x)",
                              dbg_l2_wr_addr_q, dbg_l2_wr_data_q, dbg_l2_wr_strb_q,
                              l2_wr_addr_o, l2_wr_data_o, l2_wr_strb_o))
            end
            dbg_l2_rd_hold_q <= l2_rd_valid_o && !l2_rd_ready_i;
            dbg_l2_rd_addr_q <= l2_rd_addr_o;
            dbg_l2_wr_hold_q <= l2_wr_valid_o && !l2_wr_ready_i;
            dbg_l2_wr_addr_q <= l2_wr_addr_o;
            dbg_l2_wr_data_q <= l2_wr_data_o;
            dbg_l2_wr_strb_q <= l2_wr_strb_o;
            `CPU_DEBUG($sformatf(
                "[CACHE][DCACHE] state=%0d req(valid=%0d load=%0d store=%0d addr=0x%08x size=%0d uncached=%0d data=0x%08x) cur_uncached=%0d hit=%0d way=0x%0x resp(valid=%0d data=0x%08x) l2_rd(valid=%0d ready=%0d addr=0x%08x size=%0d bypass=%0d) l2_wr(valid=%0d ready=%0d done=%0d addr=0x%08x data=0x%08x strb=0x%0x)",
                state_q, req_valid_i, req_is_load_i, req_is_store_i, req_addr_i, req_size_i, req_uncached_i, req_store_data_i,
                req_uncached_q,
                cache_hit, way_hit, resp_valid_o, resp_load_data_o,
                l2_rd_valid_o, l2_rd_ready_i, l2_rd_addr_o, l2_rd_size_o, l2_rd_uncached_o,
                l2_wr_valid_o, l2_wr_ready_i, l2_wr_done_i, l2_wr_addr_o, l2_wr_data_o, l2_wr_strb_o
            ));
        end else begin
            dbg_l2_rd_hold_q <= l2_rd_valid_o && !l2_rd_ready_i;
            dbg_l2_rd_addr_q <= l2_rd_addr_o;
            dbg_l2_wr_hold_q <= l2_wr_valid_o && !l2_wr_ready_i;
            dbg_l2_wr_addr_q <= l2_wr_addr_o;
            dbg_l2_wr_data_q <= l2_wr_data_o;
            dbg_l2_wr_strb_q <= l2_wr_strb_o;
        end
    end
`endif

    `CPU_DEBUG_MODULE("cpu_l1_dcache")
endmodule
