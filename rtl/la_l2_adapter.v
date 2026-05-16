module la_l2_adapter #(
    parameter ENABLE_PREFETCH = 0
) (
    input  wire        clk,
    input  wire        reset,

    input  wire        icache_req_valid,
    input  wire [31:0] icache_req_addr,
    output wire        icache_req_ready,
    output wire        icache_resp_valid,
    output wire [31:0] icache_resp_data,

    input  wire        dcache_req_valid,
    input  wire        dcache_req_write,
    input  wire        dcache_req_uncached,
    input  wire [31:0] dcache_req_addr,
    input  wire [31:0] dcache_req_wdata,
    input  wire [3:0]  dcache_req_wstrb,
    output wire        dcache_req_ready,
    output wire        dcache_resp_valid,
    output wire [31:0] dcache_resp_rdata,

    output wire [3:0]  arid,
    output wire [31:0] araddr,
    output wire [7:0]  arlen,
    output wire [2:0]  arsize,
    output wire [1:0]  arburst,
    output wire [1:0]  arlock,
    output wire [3:0]  arcache,
    output wire [2:0]  arprot,
    output wire        arvalid,
    input  wire        arready,

    input  wire [3:0]  rid,
    input  wire [31:0] rdata,
    input  wire [1:0]  rresp,
    input  wire        rlast,
    input  wire        rvalid,
    output wire        rready,

    output wire [3:0]  awid,
    output wire [31:0] awaddr,
    output wire [7:0]  awlen,
    output wire [2:0]  awsize,
    output wire [1:0]  awburst,
    output wire [1:0]  awlock,
    output wire [3:0]  awcache,
    output wire [2:0]  awprot,
    output wire        awvalid,
    input  wire        awready,

    output wire [3:0]  wid,
    output wire [31:0] wdata,
    output wire [3:0]  wstrb,
    output wire        wlast,
    output wire        wvalid,
    input  wire        wready,

    input  wire [3:0]  bid,
    input  wire [1:0]  bresp,
    input  wire        bvalid,
    output wire        bready
);

    wire        l2_l1i_req_valid_w;
    wire        l2_l1i_req_ready_w;
    wire        l2_l1i_resp_valid_w;
    wire [31:0] l2_l1i_resp_data0_w;
    wire [31:0] l2_l1i_resp_data1_w;
    wire [31:0] l2_l1i_resp_data2_w;
    wire [31:0] l2_l1i_resp_data3_w;
    wire        l2_l1i_pf_resp_valid_w;
    wire [31:0] l2_l1i_pf_resp_addr_w;
    wire [31:0] l2_l1i_pf_resp_data0_w;
    wire [31:0] l2_l1i_pf_resp_data1_w;
    wire [31:0] l2_l1i_pf_resp_data2_w;
    wire [31:0] l2_l1i_pf_resp_data3_w;

    wire        l2_l1d_rd_valid_w;
    wire        l2_l1d_rd_ready_w;
    wire        l2_l1d_resp_valid_w;
    wire [31:0] l2_l1d_resp_data0_w;
    wire [31:0] l2_l1d_resp_data1_w;
    wire [31:0] l2_l1d_resp_data2_w;
    wire [31:0] l2_l1d_resp_data3_w;

    wire        l2_l1d_wr_valid_w;
    wire        l2_l1d_wr_ready_w;
    wire        l2_l1d_wr_done_w;

    wire        l2_axi_arvalid_w;
    wire        l2_axi_arready_w;
    wire [31:0] l2_axi_araddr_w;
    wire [3:0]  l2_axi_arid_w;
    wire [7:0]  l2_axi_arlen_w;
    wire [2:0]  l2_axi_arsize_w;
    wire [1:0]  l2_axi_arburst_w;
    wire        l2_axi_rvalid_w;
    wire        l2_axi_rready_w;
    wire [31:0] l2_axi_rdata_w;
    wire [1:0]  l2_axi_rresp_w;
    wire [3:0]  l2_axi_rid_w;
    wire        l2_axi_rlast_w;
    wire        l2_axi_awvalid_w;
    wire        l2_axi_awready_w;
    wire [31:0] l2_axi_awaddr_w;
    wire [3:0]  l2_axi_awid_w;
    wire [7:0]  l2_axi_awlen_w;
    wire [2:0]  l2_axi_awsize_w;
    wire [1:0]  l2_axi_awburst_w;
    wire        l2_axi_wvalid_w;
    wire        l2_axi_wready_w;
    wire [31:0] l2_axi_wdata_w;
    wire [3:0]  l2_axi_wstrb_w;
    wire        l2_axi_wlast_w;
    wire        l2_axi_bvalid_w;
    wire        l2_axi_bready_w;
    wire [1:0]  l2_axi_bresp_w;
    wire [3:0]  l2_axi_bid_w;

    wire        unused_m1_arready_w;
    wire        unused_m1_rvalid_w;
    wire [31:0] unused_m1_rdata_w;
    wire [1:0]  unused_m1_rresp_w;
    wire [3:0]  unused_m1_rid_w;
    wire        unused_m1_rlast_w;

    reg        i_pending_r;
    reg [1:0]  i_word_sel_r;
    reg        d_pending_r;
    reg        d_pending_write_r;
    reg        d_pending_uncached_r;
    reg [1:0]  d_word_sel_r;

    wire icache_accept_w = l2_l1i_req_valid_w && l2_l1i_req_ready_w;
    wire dcache_read_w   = dcache_req_valid && !dcache_req_write;
    wire dcache_write_w  = dcache_req_valid && dcache_req_write;
    wire dcache_read_accept_w = l2_l1d_rd_valid_w && l2_l1d_rd_ready_w;
    wire dcache_write_accept_w = l2_l1d_wr_valid_w && l2_l1d_wr_ready_w;

    assign l2_l1i_req_valid_w = icache_req_valid && !i_pending_r;
    assign icache_req_ready   = !i_pending_r && l2_l1i_req_ready_w;

    assign l2_l1d_rd_valid_w = dcache_read_w && !d_pending_r;
    assign l2_l1d_wr_valid_w = dcache_write_w && !d_pending_r;
    assign dcache_req_ready  = dcache_req_write ?
                               (!d_pending_r && l2_l1d_wr_ready_w) :
                               (!d_pending_r && l2_l1d_rd_ready_w);

    assign icache_resp_valid = i_pending_r && l2_l1i_resp_valid_w;
    assign icache_resp_data =
        (i_word_sel_r == 2'd0) ? l2_l1i_resp_data0_w :
        (i_word_sel_r == 2'd1) ? l2_l1i_resp_data1_w :
        (i_word_sel_r == 2'd2) ? l2_l1i_resp_data2_w :
                                 l2_l1i_resp_data3_w;

    assign dcache_resp_valid =
        d_pending_r &&
        ((d_pending_write_r && l2_l1d_wr_done_w) ||
         (!d_pending_write_r && l2_l1d_resp_valid_w));
    assign dcache_resp_rdata =
        d_pending_write_r ? 32'b0 :
        d_pending_uncached_r ? l2_l1d_resp_data0_w :
        (d_word_sel_r == 2'd0) ? l2_l1d_resp_data0_w :
        (d_word_sel_r == 2'd1) ? l2_l1d_resp_data1_w :
        (d_word_sel_r == 2'd2) ? l2_l1d_resp_data2_w :
                                 l2_l1d_resp_data3_w;

    assign arlock  = 2'b0;
    assign arcache = 4'b0;
    assign arprot  = 3'b0;
    assign awlock  = 2'b0;
    assign awcache = 4'b0;
    assign awprot  = 3'b0;
    assign wid     = awid;

    wire unused_sideband;
    assign unused_sideband = &{1'b0, l2_l1i_pf_resp_valid_w,
                               l2_l1i_pf_resp_addr_w,
                               l2_l1i_pf_resp_data0_w,
                               l2_l1i_pf_resp_data1_w,
                               l2_l1i_pf_resp_data2_w,
                               l2_l1i_pf_resp_data3_w,
                               unused_m1_arready_w,
                               unused_m1_rvalid_w,
                               unused_m1_rdata_w,
                               unused_m1_rresp_w,
                               unused_m1_rid_w,
                               unused_m1_rlast_w};

    always @(posedge clk) begin
        if (reset) begin
            i_pending_r       <= 1'b0;
            i_word_sel_r      <= 2'b0;
            d_pending_r       <= 1'b0;
            d_pending_write_r <= 1'b0;
            d_pending_uncached_r <= 1'b0;
            d_word_sel_r      <= 2'b0;
        end else begin
            if (icache_accept_w) begin
                i_pending_r  <= 1'b1;
                i_word_sel_r <= icache_req_addr[3:2];
            end else if (icache_resp_valid) begin
                i_pending_r <= 1'b0;
            end

            if (dcache_read_accept_w) begin
                d_pending_r       <= 1'b1;
                d_pending_write_r <= 1'b0;
                d_pending_uncached_r <= dcache_req_uncached;
                d_word_sel_r      <= dcache_req_addr[3:2];
            end else if (dcache_write_accept_w) begin
                d_pending_r       <= 1'b1;
                d_pending_write_r <= 1'b1;
                d_pending_uncached_r <= 1'b0;
                d_word_sel_r      <= dcache_req_addr[3:2];
            end else if (dcache_resp_valid) begin
                d_pending_r       <= 1'b0;
                d_pending_write_r <= 1'b0;
                d_pending_uncached_r <= 1'b0;
            end
        end
    end

    cpu_l2_cache #(
        .XLEN(32),
        .NUM_WAYS(4),
        .NUM_LINES(128),
        .LINE_SIZE(32),
        .L1_LINE_SIZE(16),
        .AXI_ID(4'h2),
        .ENABLE_PREFETCH(ENABLE_PREFETCH)
    ) u_cpu_l2_cache (
        .clk                  (clk),
        .rst_n                (~reset),

        .l1i_req_valid_i      (l2_l1i_req_valid_w),
        .l1i_req_addr_i       (icache_req_addr),
        .l1i_req_is_prefetch_i(1'b0),
        .l1i_req_ready_o      (l2_l1i_req_ready_w),
        .l1i_resp_valid_o     (l2_l1i_resp_valid_w),
        .l1i_resp_data_o_0    (l2_l1i_resp_data0_w),
        .l1i_resp_data_o_1    (l2_l1i_resp_data1_w),
        .l1i_resp_data_o_2    (l2_l1i_resp_data2_w),
        .l1i_resp_data_o_3    (l2_l1i_resp_data3_w),
        .l1i_pf_resp_valid_o  (l2_l1i_pf_resp_valid_w),
        .l1i_pf_resp_addr_o   (l2_l1i_pf_resp_addr_w),
        .l1i_pf_resp_data_o_0 (l2_l1i_pf_resp_data0_w),
        .l1i_pf_resp_data_o_1 (l2_l1i_pf_resp_data1_w),
        .l1i_pf_resp_data_o_2 (l2_l1i_pf_resp_data2_w),
        .l1i_pf_resp_data_o_3 (l2_l1i_pf_resp_data3_w),

        .l1d_rd_valid_i       (l2_l1d_rd_valid_w),
        .l1d_rd_addr_i        (dcache_req_addr),
        .l1d_rd_size_i        (2'b10),
        .l1d_rd_uncached_i    (dcache_req_uncached),
        .l1d_rd_ready_o       (l2_l1d_rd_ready_w),
        .l1d_resp_valid_o     (l2_l1d_resp_valid_w),
        .l1d_resp_data_o_0    (l2_l1d_resp_data0_w),
        .l1d_resp_data_o_1    (l2_l1d_resp_data1_w),
        .l1d_resp_data_o_2    (l2_l1d_resp_data2_w),
        .l1d_resp_data_o_3    (l2_l1d_resp_data3_w),

        .l1d_wr_valid_i       (l2_l1d_wr_valid_w),
        .l1d_wr_addr_i        (dcache_req_addr),
        .l1d_wr_data_i        (dcache_req_wdata),
        .l1d_wr_strb_i        (dcache_req_wstrb),
        .l1d_wr_ready_o       (l2_l1d_wr_ready_w),
        .l1d_wr_done_o        (l2_l1d_wr_done_w),

        .axi_arvalid_o        (l2_axi_arvalid_w),
        .axi_arready_i        (l2_axi_arready_w),
        .axi_araddr_o         (l2_axi_araddr_w),
        .axi_arid_o           (l2_axi_arid_w),
        .axi_arlen_o          (l2_axi_arlen_w),
        .axi_arsize_o         (l2_axi_arsize_w),
        .axi_arburst_o        (l2_axi_arburst_w),
        .axi_rvalid_i         (l2_axi_rvalid_w),
        .axi_rready_o         (l2_axi_rready_w),
        .axi_rdata_i          (l2_axi_rdata_w),
        .axi_rresp_i          (l2_axi_rresp_w),
        .axi_rid_i            (l2_axi_rid_w),
        .axi_rlast_i          (l2_axi_rlast_w),

        .axi_awvalid_o        (l2_axi_awvalid_w),
        .axi_awready_i        (l2_axi_awready_w),
        .axi_awaddr_o         (l2_axi_awaddr_w),
        .axi_awid_o           (l2_axi_awid_w),
        .axi_awlen_o          (l2_axi_awlen_w),
        .axi_awsize_o         (l2_axi_awsize_w),
        .axi_awburst_o        (l2_axi_awburst_w),
        .axi_wvalid_o         (l2_axi_wvalid_w),
        .axi_wready_i         (l2_axi_wready_w),
        .axi_wdata_o          (l2_axi_wdata_w),
        .axi_wstrb_o          (l2_axi_wstrb_w),
        .axi_wlast_o          (l2_axi_wlast_w),
        .axi_bvalid_i         (l2_axi_bvalid_w),
        .axi_bready_o         (l2_axi_bready_w),
        .axi_bresp_i          (l2_axi_bresp_w),
        .axi_bid_i            (l2_axi_bid_w)
    );

    axi_arbiter u_axi_arbiter (
        .clk              (clk),
        .rst_n            (~reset),

        .m0_axi_arvalid_i (l2_axi_arvalid_w),
        .m0_axi_arready_o (l2_axi_arready_w),
        .m0_axi_araddr_i  (l2_axi_araddr_w),
        .m0_axi_arid_i    (l2_axi_arid_w),
        .m0_axi_arlen_i   (l2_axi_arlen_w),
        .m0_axi_arsize_i  (l2_axi_arsize_w),
        .m0_axi_arburst_i (l2_axi_arburst_w),
        .m0_axi_rvalid_o  (l2_axi_rvalid_w),
        .m0_axi_rready_i  (l2_axi_rready_w),
        .m0_axi_rdata_o   (l2_axi_rdata_w),
        .m0_axi_rresp_o   (l2_axi_rresp_w),
        .m0_axi_rid_o     (l2_axi_rid_w),
        .m0_axi_rlast_o   (l2_axi_rlast_w),

        .m1_axi_arvalid_i (1'b0),
        .m1_axi_arready_o (unused_m1_arready_w),
        .m1_axi_araddr_i  (32'b0),
        .m1_axi_arid_i    (4'b0),
        .m1_axi_arlen_i   (8'b0),
        .m1_axi_arsize_i  (3'b010),
        .m1_axi_arburst_i (2'b01),
        .m1_axi_rvalid_o  (unused_m1_rvalid_w),
        .m1_axi_rready_i  (1'b0),
        .m1_axi_rdata_o   (unused_m1_rdata_w),
        .m1_axi_rresp_o   (unused_m1_rresp_w),
        .m1_axi_rid_o     (unused_m1_rid_w),
        .m1_axi_rlast_o   (unused_m1_rlast_w),
        .m1_axi_awvalid_i (l2_axi_awvalid_w),
        .m1_axi_awready_o (l2_axi_awready_w),
        .m1_axi_awaddr_i  (l2_axi_awaddr_w),
        .m1_axi_awid_i    (l2_axi_awid_w),
        .m1_axi_awlen_i   (l2_axi_awlen_w),
        .m1_axi_awsize_i  (l2_axi_awsize_w),
        .m1_axi_awburst_i (l2_axi_awburst_w),
        .m1_axi_wvalid_i  (l2_axi_wvalid_w),
        .m1_axi_wready_o  (l2_axi_wready_w),
        .m1_axi_wdata_i   (l2_axi_wdata_w),
        .m1_axi_wstrb_i   (l2_axi_wstrb_w),
        .m1_axi_wlast_i   (l2_axi_wlast_w),
        .m1_axi_bvalid_o  (l2_axi_bvalid_w),
        .m1_axi_bready_i  (l2_axi_bready_w),
        .m1_axi_bresp_o   (l2_axi_bresp_w),
        .m1_axi_bid_o     (l2_axi_bid_w),

        .s_axi_arvalid_o  (arvalid),
        .s_axi_arready_i  (arready),
        .s_axi_araddr_o   (araddr),
        .s_axi_arid_o     (arid),
        .s_axi_arlen_o    (arlen),
        .s_axi_arsize_o   (arsize),
        .s_axi_arburst_o  (arburst),
        .s_axi_rvalid_i   (rvalid),
        .s_axi_rready_o   (rready),
        .s_axi_rdata_i    (rdata),
        .s_axi_rresp_i    (rresp),
        .s_axi_rid_i      (rid),
        .s_axi_rlast_i    (rlast),
        .s_axi_awvalid_o  (awvalid),
        .s_axi_awready_i  (awready),
        .s_axi_awaddr_o   (awaddr),
        .s_axi_awid_o     (awid),
        .s_axi_awlen_o    (awlen),
        .s_axi_awsize_o   (awsize),
        .s_axi_awburst_o  (awburst),
        .s_axi_wvalid_o   (wvalid),
        .s_axi_wready_i   (wready),
        .s_axi_wdata_o    (wdata),
        .s_axi_wstrb_o    (wstrb),
        .s_axi_wlast_o    (wlast),
        .s_axi_bvalid_i   (bvalid),
        .s_axi_bready_o   (bready),
        .s_axi_bresp_i    (bresp),
        .s_axi_bid_i      (bid)
    );

`ifdef VERILATOR
    always @(posedge clk) begin
        if ($test$plusargs("LA_L2_LOG")) begin
            if (reset) begin
                $display("[LA][L2_ADAPTER][CLEAR]");
            end else if (icache_req_valid || icache_resp_valid ||
                         dcache_req_valid || dcache_resp_valid ||
                         arvalid || rvalid || awvalid || wvalid || bvalid) begin
                $display("[LA][L2_ADAPTER] i(req=%0d/%0d addr=0x%08x pend=%0d resp=%0d data=0x%08x) d(req=%0d/%0d wr=%0d addr=0x%08x pend=%0d pwr=%0d resp=%0d data=0x%08x) axi(ar=%0d/%0d addr=0x%08x len=%0d r=%0d/%0d last=%0d aw=%0d/%0d w=%0d/%0d b=%0d/%0d)",
                         icache_req_valid, icache_req_ready, icache_req_addr,
                         i_pending_r, icache_resp_valid, icache_resp_data,
                         dcache_req_valid, dcache_req_ready, dcache_req_write,
                         dcache_req_addr, d_pending_r, d_pending_write_r,
                         dcache_resp_valid, dcache_resp_rdata,
                         arvalid, arready, araddr, arlen, rvalid, rready,
                         rlast, awvalid, awready, wvalid, wready, bvalid,
                         bready);
            end
        end
    end
`endif

endmodule
