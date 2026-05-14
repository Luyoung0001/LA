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

    localparam [1:0] RD_IDLE = 2'd0;
    localparam [1:0] RD_REQ  = 2'd1;
    localparam [1:0] RD_RESP = 2'd2;

    localparam [1:0] WR_IDLE = 2'd0;
    localparam [1:0] WR_REQ  = 2'd1;
    localparam [1:0] WR_RESP = 2'd2;

    wire        req_is_load_w;
    wire        req_is_store_w;
    wire [1:0]  req_size_w;
    wire        req_uncached_w;
    wire        dcache_resp_valid_w;
    wire [31:0] dcache_resp_data_w;
    wire        dcache_resp_fault_w;

    wire        l2_rd_valid_w;
    wire [31:0] l2_rd_addr_w;
    wire [1:0]  l2_rd_size_w;
    wire        l2_rd_uncached_w;
    wire        l2_rd_ready_w;
    reg         l2_resp_valid_r;
    reg  [31:0] l2_resp_data0_r;
    reg  [31:0] l2_resp_data1_r;
    reg  [31:0] l2_resp_data2_r;
    reg  [31:0] l2_resp_data3_r;

    wire        l2_wr_valid_w;
    wire [31:0] l2_wr_addr_w;
    wire [31:0] l2_wr_data_w;
    wire [3:0]  l2_wr_strb_w;
    wire        l2_wr_ready_w;
    reg         l2_wr_done_r;

    reg [1:0]  rd_state_r;
    reg [1:0]  rd_word_r;
    reg [31:0] rd_base_r;
    reg        rd_uncached_r;
    reg        rd_axi_valid_r;
    reg [31:0] line_word0_r;
    reg [31:0] line_word1_r;
    reg [31:0] line_word2_r;
    reg [31:0] line_word3_r;

    reg [1:0]  wr_state_r;
    reg        wr_axi_valid_r;
    reg [31:0] wr_addr_r;
    reg [31:0] wr_data_r;
    reg [3:0]  wr_strb_r;

    wire [31:0] aligned_rd_addr_w =
        l2_rd_uncached_w ? l2_rd_addr_w : {l2_rd_addr_w[31:4], 4'b0};
    wire        rd_l2_accept_w = l2_rd_valid_w && l2_rd_ready_w;
    wire        rd_axi_fire_w = rd_axi_valid_r && axi_req_ready;
    wire        rd_axi_resp_fire_w = axi_resp_valid && (rd_state_r == RD_RESP);
    wire        wr_l2_accept_w = l2_wr_valid_w && l2_wr_ready_w;
    wire        wr_selected_w = !rd_axi_valid_r && wr_axi_valid_r;
    wire        wr_axi_fire_w = wr_selected_w && axi_req_ready;
    wire        wr_axi_resp_fire_w = axi_resp_valid && (wr_state_r == WR_RESP);

    wire unused_sideband;
    wire cacop_ready_w;
    wire cacop_done_w;
    assign unused_sideband = &{1'b0, dcache_resp_fault_w, cacop_ready_w,
                               cacop_done_w, l2_rd_size_w};

    assign req_is_load_w  = req_valid && !req_write;
    assign req_is_store_w = req_valid && req_write;
    assign req_size_w     = 2'b10;
    assign req_uncached_w = 1'b0;

    assign l2_rd_ready_w = (rd_state_r == RD_IDLE) && (wr_state_r == WR_IDLE);
    assign l2_wr_ready_w = (wr_state_r == WR_IDLE) && (rd_state_r == RD_IDLE);

    assign axi_req_valid = rd_axi_valid_r || wr_axi_valid_r;
    assign axi_req_write = wr_selected_w;
    assign axi_req_addr  = rd_axi_valid_r ? (rd_base_r + {28'b0, rd_word_r, 2'b00}) : wr_addr_r;
    assign axi_req_wdata = wr_data_r;
    assign axi_req_wstrb = rd_axi_valid_r ? 4'b0 : wr_strb_r;

    assign resp_valid = dcache_resp_valid_w;
    assign resp_rdata = dcache_resp_data_w;

    cpu_l1_dcache #(
        .XLEN(32),
        .NUM_WAYS(4),
        .NUM_LINES(128),
        .LINE_SIZE(16)
    ) u_cpu_l1_dcache (
        .clk             (clk),
        .rst_n           (~reset),

        .req_valid_i     (req_valid),
        .req_is_load_i   (req_is_load_w),
        .req_is_store_i  (req_is_store_w),
        .req_size_i      (req_size_w),
        .req_addr_i      (req_addr),
        .req_store_data_i(req_wdata),
        .req_uncached_i  (req_uncached_w),
        .resp_valid_o    (dcache_resp_valid_w),
        .resp_load_data_o(dcache_resp_data_w),
        .resp_fault_o    (dcache_resp_fault_w),

        .cacop_valid_i   (1'b0),
        .cacop_mode_i    (2'b0),
        .cacop_addr_i    (32'b0),
        .cacop_ready_o   (cacop_ready_w),
        .cacop_done_o    (cacop_done_w),

        .l2_rd_valid_o   (l2_rd_valid_w),
        .l2_rd_addr_o    (l2_rd_addr_w),
        .l2_rd_size_o    (l2_rd_size_w),
        .l2_rd_uncached_o(l2_rd_uncached_w),
        .l2_rd_ready_i   (l2_rd_ready_w),

        .l2_resp_valid_i (l2_resp_valid_r),
        .l2_resp_data_i_0(l2_resp_data0_r),
        .l2_resp_data_i_1(l2_resp_data1_r),
        .l2_resp_data_i_2(l2_resp_data2_r),
        .l2_resp_data_i_3(l2_resp_data3_r),

        .l2_wr_valid_o   (l2_wr_valid_w),
        .l2_wr_addr_o    (l2_wr_addr_w),
        .l2_wr_data_o    (l2_wr_data_w),
        .l2_wr_strb_o    (l2_wr_strb_w),
        .l2_wr_ready_i   (l2_wr_ready_w),
        .l2_wr_done_i    (l2_wr_done_r)
    );

    assign req_ready = 1'b1;

    always @(posedge clk) begin
        if (reset) begin
            rd_state_r       <= RD_IDLE;
            rd_word_r        <= 2'b0;
            rd_base_r        <= 32'b0;
            rd_uncached_r    <= 1'b0;
            rd_axi_valid_r   <= 1'b0;
            line_word0_r     <= 32'b0;
            line_word1_r     <= 32'b0;
            line_word2_r     <= 32'b0;
            line_word3_r     <= 32'b0;
            l2_resp_valid_r  <= 1'b0;
            l2_resp_data0_r  <= 32'b0;
            l2_resp_data1_r  <= 32'b0;
            l2_resp_data2_r  <= 32'b0;
            l2_resp_data3_r  <= 32'b0;

            wr_state_r       <= WR_IDLE;
            wr_axi_valid_r   <= 1'b0;
            wr_addr_r        <= 32'b0;
            wr_data_r        <= 32'b0;
            wr_strb_r        <= 4'b0;
            l2_wr_done_r     <= 1'b0;
        end else begin
            l2_resp_valid_r <= 1'b0;
            l2_wr_done_r    <= 1'b0;

            case (rd_state_r)
                RD_IDLE: begin
                    rd_axi_valid_r <= 1'b0;
                    if (rd_l2_accept_w) begin
                        rd_base_r      <= aligned_rd_addr_w;
                        rd_uncached_r  <= l2_rd_uncached_w;
                        rd_word_r      <= l2_rd_uncached_w ? l2_rd_addr_w[3:2] : 2'b0;
                        rd_axi_valid_r <= 1'b1;
                        rd_state_r     <= RD_REQ;
                    end
                end

                RD_REQ: begin
                    if (rd_axi_fire_w) begin
                        rd_axi_valid_r <= 1'b0;
                        rd_state_r     <= RD_RESP;
                    end
                end

                RD_RESP: begin
                    if (rd_axi_resp_fire_w) begin
                        case (rd_word_r)
                            2'd0: line_word0_r <= axi_resp_rdata;
                            2'd1: line_word1_r <= axi_resp_rdata;
                            2'd2: line_word2_r <= axi_resp_rdata;
                            default: line_word3_r <= axi_resp_rdata;
                        endcase

                        if (rd_uncached_r || (rd_word_r == 2'd3)) begin
                            l2_resp_valid_r <= 1'b1;
                            l2_resp_data0_r <= (rd_word_r == 2'd0) ? axi_resp_rdata : line_word0_r;
                            l2_resp_data1_r <= (rd_word_r == 2'd1) ? axi_resp_rdata : line_word1_r;
                            l2_resp_data2_r <= (rd_word_r == 2'd2) ? axi_resp_rdata : line_word2_r;
                            l2_resp_data3_r <= (rd_word_r == 2'd3) ? axi_resp_rdata : line_word3_r;
                            rd_state_r      <= RD_IDLE;
                        end else begin
                            rd_word_r      <= rd_word_r + 2'd1;
                            rd_axi_valid_r <= 1'b1;
                            rd_state_r     <= RD_REQ;
                        end
                    end
                end

                default: begin
                    rd_state_r     <= RD_IDLE;
                    rd_axi_valid_r <= 1'b0;
                end
            endcase

            case (wr_state_r)
                WR_IDLE: begin
                    wr_axi_valid_r <= 1'b0;
                    if (wr_l2_accept_w) begin
                        wr_addr_r      <= l2_wr_addr_w;
                        wr_data_r      <= l2_wr_data_w;
                        wr_strb_r      <= l2_wr_strb_w;
                        wr_axi_valid_r <= 1'b1;
                        wr_state_r     <= WR_REQ;
                    end
                end

                WR_REQ: begin
                    if (wr_axi_fire_w) begin
                        wr_axi_valid_r <= 1'b0;
                        wr_state_r     <= WR_RESP;
                    end
                end

                WR_RESP: begin
                    if (wr_axi_resp_fire_w) begin
                        l2_wr_done_r <= 1'b1;
                        wr_state_r   <= WR_IDLE;
                    end
                end

                default: begin
                    wr_state_r     <= WR_IDLE;
                    wr_axi_valid_r <= 1'b0;
                end
            endcase
        end
    end

`ifdef VERILATOR
    always @(posedge clk) begin
        if ($test$plusargs("LA_L1D_LOG")) begin
            if (reset) begin
                $display("[LA][L1D_ADAPTER][CLEAR]");
            end else if (req_valid || resp_valid || l2_rd_valid_w || l2_wr_valid_w ||
                         axi_req_valid || axi_resp_valid || l2_resp_valid_r ||
                         l2_wr_done_r) begin
                $display("[LA][L1D_ADAPTER] req(valid=%0d ready=%0d wr=%0d addr=0x%08x wdata=0x%08x strb=0x%0x) resp(valid=%0d rdata=0x%08x) rd(state=%0d l2_valid=%0d l2_ready=%0d l2_addr=0x%08x word=%0d uncached=%0d line_resp=%0d) wr(state=%0d l2_valid=%0d l2_ready=%0d done=%0d l2_addr=0x%08x data=0x%08x strb=0x%0x) axi(valid=%0d write=%0d ready=%0d addr=0x%08x resp=%0d rdata=0x%08x)",
                         req_valid, req_ready, req_write, req_addr, req_wdata,
                         req_wstrb, resp_valid, resp_rdata, rd_state_r,
                         l2_rd_valid_w, l2_rd_ready_w, l2_rd_addr_w, rd_word_r,
                         rd_uncached_r, l2_resp_valid_r, wr_state_r,
                         l2_wr_valid_w, l2_wr_ready_w, l2_wr_done_r,
                         l2_wr_addr_w, l2_wr_data_w, l2_wr_strb_w,
                         axi_req_valid, axi_req_write, axi_req_ready,
                         axi_req_addr, axi_resp_valid, axi_resp_rdata);
            end
        end
    end
`endif

endmodule
