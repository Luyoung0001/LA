module la_l1d_adapter (
    input  wire        clk,
    input  wire        reset,

    input  wire        req_valid,
    input  wire        req_write,
    input  wire [31:0] req_addr,
    input  wire [31:0] req_wdata,
    input  wire [3:0]  req_wstrb,
    output wire        req_ready,
    output wire        resp_valid,
    output wire [31:0] resp_rdata,

    output wire        axi_req_valid,
    output wire        axi_req_write,
    output wire [31:0] axi_req_addr,
    output wire [31:0] axi_req_wdata,
    output wire [3:0]  axi_req_wstrb,
    input  wire        axi_req_ready,
    input  wire        axi_resp_valid,
    input  wire [31:0] axi_resp_rdata
);

    // Decode store size and byte offset from wstrb.
    reg [1:0] store_size_r;
    reg [1:0] store_lsb_r;
    reg [31:0] store_data_raw_r;
    always @(*) begin
        case (req_wstrb)
            4'b0001: begin store_size_r = 2'b00; store_lsb_r = 2'b00; store_data_raw_r = req_wdata; end
            4'b0010: begin store_size_r = 2'b00; store_lsb_r = 2'b01; store_data_raw_r = {24'b0, req_wdata[15:8]}; end
            4'b0100: begin store_size_r = 2'b00; store_lsb_r = 2'b10; store_data_raw_r = {24'b0, req_wdata[23:16]}; end
            4'b1000: begin store_size_r = 2'b00; store_lsb_r = 2'b11; store_data_raw_r = {24'b0, req_wdata[31:24]}; end
            4'b0011: begin store_size_r = 2'b01; store_lsb_r = 2'b00; store_data_raw_r = req_wdata; end
            4'b1100: begin store_size_r = 2'b01; store_lsb_r = 2'b10; store_data_raw_r = {16'b0, req_wdata[31:16]}; end
            default: begin store_size_r = 2'b10; store_lsb_r = 2'b00; store_data_raw_r = req_wdata; end
        endcase
    end

    wire [1:0]  dc_size_w  = req_write ? store_size_r : 2'b10;
    wire [31:0] dc_addr_w  = req_write ? {req_addr[31:2], store_lsb_r} : req_addr;
    wire [31:0] dc_wdata_w = store_data_raw_r;
    wire        dc_uncached_w = (req_addr[31] == 1'b1);

    wire        dcache_resp_valid_w;
    wire [31:0] dcache_resp_data_w;
    wire        dcache_resp_fault_w;
    wire        l2_rd_valid_w, l2_rd_uncached_w;
    wire [31:0] l2_rd_addr_w;
    wire [1:0]  l2_rd_size_w;
    wire        l2_wr_valid_w;
    wire [31:0] l2_wr_addr_w, l2_wr_data_w;
    wire [3:0]  l2_wr_strb_w;
    wire        cacop_ready_w, cacop_done_w;
    wire unused_dc = &{1'b0, dcache_resp_fault_w, cacop_ready_w, cacop_done_w, l2_rd_size_w};

    assign req_ready  = 1'b1;
    assign resp_valid = dcache_resp_valid_w;
    assign resp_rdata = dcache_resp_data_w;

    cpu_l1_dcache #(.XLEN(32), .NUM_WAYS(4), .NUM_LINES(128), .LINE_SIZE(16))
    u_cpu_l1_dcache (
        .clk(clk), .rst_n(~reset),
        .req_valid_i(req_valid), .req_is_load_i(req_valid && !req_write),
        .req_is_store_i(req_valid && req_write),
        .req_size_i(dc_size_w), .req_addr_i(dc_addr_w),
        .req_store_data_i(dc_wdata_w), .req_uncached_i(dc_uncached_w),
        .resp_valid_o(dcache_resp_valid_w), .resp_load_data_o(dcache_resp_data_w),
        .resp_fault_o(dcache_resp_fault_w),
        .cacop_valid_i(1'b0), .cacop_mode_i(2'b0), .cacop_addr_i(32'b0),
        .cacop_ready_o(cacop_ready_w), .cacop_done_o(cacop_done_w),
        .l2_rd_valid_o(l2_rd_valid_w), .l2_rd_addr_o(l2_rd_addr_w),
        .l2_rd_size_o(l2_rd_size_w), .l2_rd_uncached_o(l2_rd_uncached_w),
        .l2_rd_ready_i(l2_rd_ready_w),
        .l2_resp_valid_i(l2_resp_valid_r),
        .l2_resp_data_i_0(l2_resp_data0_r), .l2_resp_data_i_1(l2_resp_data1_r),
        .l2_resp_data_i_2(l2_resp_data2_r), .l2_resp_data_i_3(l2_resp_data3_r),
        .l2_wr_valid_o(l2_wr_valid_w), .l2_wr_addr_o(l2_wr_addr_w),
        .l2_wr_data_o(l2_wr_data_w), .l2_wr_strb_o(l2_wr_strb_w),
        .l2_wr_ready_i(l2_wr_ready_w), .l2_wr_done_i(l2_wr_done_r)
    );

    // L2 read/write → AXI adapter (line fill + store writeback)
    localparam [1:0] RD_IDLE=0, RD_REQ=1, RD_RESP=2;
    localparam [1:0] WR_IDLE=0, WR_REQ=1, WR_RESP=2;
    reg [1:0] rd_state_r, wr_state_r;
    reg [1:0] rd_word_r;
    reg [31:0] rd_base_r;
    reg rd_uncached_r, rd_axi_valid_r, wr_axi_valid_r;
    reg [31:0] line_w0_r, line_w1_r, line_w2_r, line_w3_r;
    reg [31:0] wr_addr_r, wr_data_r;
    reg [3:0] wr_strb_r;
    reg l2_resp_valid_r, l2_wr_done_r;
    reg [31:0] l2_resp_data0_r, l2_resp_data1_r, l2_resp_data2_r, l2_resp_data3_r;

    wire l2_rd_ready_w = (rd_state_r == RD_IDLE) && (wr_state_r == WR_IDLE);
    wire l2_wr_ready_w = (wr_state_r == WR_IDLE) && !rd_axi_valid_r;
    wire [31:0] aligned_rd_addr = l2_rd_uncached_w ? l2_rd_addr_w : {l2_rd_addr_w[31:4], 4'b0};
    wire rd_accept = l2_rd_valid_w && l2_rd_ready_w;
    wire wr_accept = l2_wr_valid_w && l2_wr_ready_w;
    wire wr_sel = !rd_axi_valid_r && wr_axi_valid_r;

    assign axi_req_valid = rd_axi_valid_r || wr_axi_valid_r;
    assign axi_req_write = wr_sel;
    assign axi_req_addr  = rd_axi_valid_r ? (rd_base_r + {28'b0, rd_word_r, 2'b00}) : wr_addr_r;
    assign axi_req_wdata = wr_data_r;
    assign axi_req_wstrb = rd_axi_valid_r ? 4'b0 : wr_strb_r;

    always @(posedge clk) begin
        if (reset) begin
            rd_state_r<=RD_IDLE; rd_word_r<=0; rd_base_r<=0; rd_uncached_r<=0;
            rd_axi_valid_r<=0; line_w0_r<=0; line_w1_r<=0; line_w2_r<=0; line_w3_r<=0;
            l2_resp_valid_r<=0; l2_resp_data0_r<=0; l2_resp_data1_r<=0;
            l2_resp_data2_r<=0; l2_resp_data3_r<=0;
            wr_state_r<=WR_IDLE; wr_axi_valid_r<=0; wr_addr_r<=0; wr_data_r<=0; wr_strb_r<=0;
            l2_wr_done_r<=0;
        end else begin
            l2_resp_valid_r <= 1'b0;
            l2_wr_done_r <= 1'b0;
            case (rd_state_r)
                RD_IDLE: begin
                    rd_axi_valid_r <= 1'b0;
                    if (rd_accept) begin
                        rd_base_r <= aligned_rd_addr;
                        rd_uncached_r <= l2_rd_uncached_w;
                        rd_word_r <= l2_rd_uncached_w ? l2_rd_addr_w[3:2] : 2'b0;
                        rd_axi_valid_r <= 1'b1;
                        rd_state_r <= RD_REQ;
                    end
                end
                RD_REQ: if (rd_axi_valid_r && axi_req_ready) begin
                    rd_axi_valid_r <= 1'b0; rd_state_r <= RD_RESP;
                end
                RD_RESP: if (axi_resp_valid) begin
                    case (rd_word_r)
                        2'd0: line_w0_r <= axi_resp_rdata;
                        2'd1: line_w1_r <= axi_resp_rdata;
                        2'd2: line_w2_r <= axi_resp_rdata;
                        default: line_w3_r <= axi_resp_rdata;
                    endcase
                    if (rd_uncached_r || rd_word_r == 2'd3) begin
                        l2_resp_valid_r <= 1'b1;
                        l2_resp_data0_r <= (rd_word_r==0) ? axi_resp_rdata : line_w0_r;
                        l2_resp_data1_r <= (rd_word_r==1) ? axi_resp_rdata : line_w1_r;
                        l2_resp_data2_r <= (rd_word_r==2) ? axi_resp_rdata : line_w2_r;
                        l2_resp_data3_r <= (rd_word_r==3) ? axi_resp_rdata : line_w3_r;
                        rd_state_r <= RD_IDLE;
                    end else begin
                        rd_word_r <= rd_word_r + 1;
                        rd_axi_valid_r <= 1'b1;
                        rd_state_r <= RD_REQ;
                    end
                end
                default: begin rd_state_r <= RD_IDLE; rd_axi_valid_r <= 0; end
            endcase
            case (wr_state_r)
                WR_IDLE: begin
                    wr_axi_valid_r <= 1'b0;
                    if (wr_accept) begin
                        wr_addr_r <= l2_wr_addr_w; wr_data_r <= l2_wr_data_w;
                        wr_strb_r <= l2_wr_strb_w; wr_axi_valid_r <= 1'b1;
                        wr_state_r <= WR_REQ;
                    end
                end
                WR_REQ: if (wr_sel && axi_req_ready) begin
                    wr_axi_valid_r <= 1'b0; wr_state_r <= WR_RESP;
                end
                WR_RESP: if (axi_resp_valid) begin
                    l2_wr_done_r <= 1'b1; wr_state_r <= WR_IDLE;
                end
                default: begin wr_state_r <= WR_IDLE; wr_axi_valid_r <= 0; end
            endcase
        end
    end

endmodule