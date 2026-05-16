`include "la_core_defs.vh"

module memsys_top #(
    parameter ITCM_ENABLE = `LA_ITCM_ENABLE,
    parameter L1I_ENABLE = `LA_L1I_ENABLE,
    parameter L1D_ENABLE = `LA_L1D_ENABLE,
    parameter L2_ENABLE = `LA_L2_ENABLE,
    parameter CACHE_OP_STRICT_ENABLE = `LA_CACHE_OP_STRICT_ENABLE
) (
    input  wire        clk,
    input  wire        reset,
    input  wire        ifetch_flush,
    input  wire        icacop_valid,
    input  wire [1:0]  icacop_mode,
    input  wire [31:0] icacop_addr,

    input  wire        ifetch_req_valid,
    input  wire [31:0] ifetch_req_addr,
    output wire        ifetch_req_ready,
    output wire        ifetch_resp_valid,
    output wire [31:0] ifetch_resp_data,

    input  wire        dmem_req_valid,
    input  wire        dmem_req_write,
    input  wire [31:0] dmem_req_addr,
    input  wire [31:0] dmem_req_wdata,
    input  wire [3:0]  dmem_req_wstrb,
    output wire        dmem_req_ready,
    output wire        dmem_resp_valid,
    output wire [31:0] dmem_resp_rdata,

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

    localparam [2:0] AXI_IDLE = 3'd0;
    localparam [2:0] AXI_I_AR = 3'd1;
    localparam [2:0] AXI_I_R  = 3'd2;
    localparam [2:0] AXI_D_AR = 3'd3;
    localparam [2:0] AXI_D_R  = 3'd4;
    localparam [2:0] AXI_D_AW = 3'd5;
    localparam [2:0] AXI_D_W  = 3'd6;
    localparam [2:0] AXI_D_B  = 3'd7;

    wire unused_cfg;
    assign unused_cfg = &{1'b0, ITCM_ENABLE[0], L1I_ENABLE[0], L1D_ENABLE[0],
                          L2_ENABLE[0], CACHE_OP_STRICT_ENABLE[0]};

    wire unused_axi_inputs;
    assign unused_axi_inputs = &{1'b0, rid, rresp, rlast, bid, bresp};

    wire        icache_axi_req_valid_w;
    wire [31:0] icache_axi_req_addr_w;
    wire        icache_axi_req_ready_w;
    wire        icache_axi_resp_valid_w;
    wire [31:0] icache_axi_resp_data_w;
    reg         icache_axi_resp_valid_r;
    reg  [31:0] icache_axi_resp_data_r;

    wire        dcache_axi_req_valid_w;
    wire        dcache_axi_req_write_w;
    wire        dcache_axi_req_uncached_w;
    wire [31:0] dcache_axi_req_addr_w;
    wire [31:0] dcache_axi_req_wdata_w;
    wire [3:0]  dcache_axi_req_wstrb_w;
    wire        dcache_axi_req_ready_w;
    wire        dcache_axi_resp_valid_w;
    wire [31:0] dcache_axi_resp_data_w;
    reg         dcache_axi_resp_valid_r;
    reg  [31:0] dcache_axi_resp_data_r;

    wire [3:0]  l2_arid_w;
    wire [31:0] l2_araddr_w;
    wire [7:0]  l2_arlen_w;
    wire [2:0]  l2_arsize_w;
    wire [1:0]  l2_arburst_w;
    wire [1:0]  l2_arlock_w;
    wire [3:0]  l2_arcache_w;
    wire [2:0]  l2_arprot_w;
    wire        l2_arvalid_w;
    wire        l2_rready_w;
    wire [3:0]  l2_awid_w;
    wire [31:0] l2_awaddr_w;
    wire [7:0]  l2_awlen_w;
    wire [2:0]  l2_awsize_w;
    wire [1:0]  l2_awburst_w;
    wire [1:0]  l2_awlock_w;
    wire [3:0]  l2_awcache_w;
    wire [2:0]  l2_awprot_w;
    wire        l2_awvalid_w;
    wire [3:0]  l2_wid_w;
    wire [31:0] l2_wdata_w;
    wire [3:0]  l2_wstrb_w;
    wire        l2_wlast_w;
    wire        l2_wvalid_w;
    wire        l2_bready_w;
    wire        l2_icache_req_ready_w;
    wire        l2_icache_resp_valid_w;
    wire [31:0] l2_icache_resp_data_w;
    wire        l2_dcache_req_ready_w;
    wire        l2_dcache_resp_valid_w;
    wire [31:0] l2_dcache_resp_data_w;

    reg [2:0]  axi_state_r;
    reg [3:0]  arid_r;
    reg [31:0] araddr_r;
    reg [7:0]  arlen_r;
    reg [2:0]  arsize_r;
    reg [1:0]  arburst_r;
    reg [1:0]  arlock_r;
    reg [3:0]  arcache_r;
    reg [2:0]  arprot_r;
    reg        arvalid_r;
    reg        rready_r;

    reg [3:0]  awid_r;
    reg [31:0] awaddr_r;
    reg [7:0]  awlen_r;
    reg [2:0]  awsize_r;
    reg [1:0]  awburst_r;
    reg [1:0]  awlock_r;
    reg [3:0]  awcache_r;
    reg [2:0]  awprot_r;
    reg        awvalid_r;

    reg [3:0]  wid_r;
    reg [31:0] wdata_r;
    reg [3:0]  wstrb_r;
    reg        wlast_r;
    reg        wvalid_r;
    reg        bready_r;

    reg [31:0] dwr_wdata_r;
    reg [3:0]  dwr_wstrb_r;

    generate
        if (L1I_ENABLE != 0) begin : gen_l1i_enabled
            la_l1i_adapter u_l1i_adapter (
                .clk           (clk),
                .reset         (reset),
                .flush         (ifetch_flush),
                .cacop_valid   (icacop_valid),
                .cacop_mode    (icacop_mode),
                .cacop_addr    (icacop_addr),
                .req_valid     (ifetch_req_valid),
                .req_addr      (ifetch_req_addr),
                .req_ready     (ifetch_req_ready),
                .resp_valid    (ifetch_resp_valid),
                .resp_data     (ifetch_resp_data),
                .axi_req_valid (icache_axi_req_valid_w),
                .axi_req_addr  (icache_axi_req_addr_w),
                .axi_req_ready (icache_axi_req_ready_w),
                .axi_resp_valid(icache_axi_resp_valid_w),
                .axi_resp_data (icache_axi_resp_data_w)
            );
        end else begin : gen_l1i_disabled
            icache_stub u_icache_stub (
                .clk           (clk),
                .reset         (reset),
                .flush         (ifetch_flush),
                .req_valid     (ifetch_req_valid),
                .req_addr      (ifetch_req_addr),
                .req_ready     (ifetch_req_ready),
                .resp_valid    (ifetch_resp_valid),
                .resp_data     (ifetch_resp_data),
                .axi_req_valid (icache_axi_req_valid_w),
                .axi_req_addr  (icache_axi_req_addr_w),
                .axi_req_ready (icache_axi_req_ready_w),
                .axi_resp_valid(icache_axi_resp_valid_w),
                .axi_resp_data (icache_axi_resp_data_w)
            );
        end
    endgenerate

    generate
        if (L1D_ENABLE != 0) begin : gen_l1d_enabled
            la_l1d_adapter u_l1d_adapter (
                .clk           (clk),
                .reset         (reset),
                .req_valid     (dmem_req_valid),
                .req_write     (dmem_req_write),
                .req_addr      (dmem_req_addr),
                .req_wdata     (dmem_req_wdata),
                .req_wstrb     (dmem_req_wstrb),
                .req_ready     (dmem_req_ready),
                .resp_valid    (dmem_resp_valid),
                .resp_rdata    (dmem_resp_rdata),
                .axi_req_valid (dcache_axi_req_valid_w),
                .axi_req_write (dcache_axi_req_write_w),
                .axi_req_uncached(dcache_axi_req_uncached_w),
                .axi_req_addr  (dcache_axi_req_addr_w),
                .axi_req_wdata (dcache_axi_req_wdata_w),
                .axi_req_wstrb (dcache_axi_req_wstrb_w),
                .axi_req_ready (dcache_axi_req_ready_w),
                .axi_resp_valid(dcache_axi_resp_valid_w),
                .axi_resp_rdata(dcache_axi_resp_data_w)
            );
        end else begin : gen_l1d_disabled
            dcache_stub u_dcache_stub (
                .clk           (clk),
                .reset         (reset),
                .req_valid     (dmem_req_valid),
                .req_write     (dmem_req_write),
                .req_addr      (dmem_req_addr),
                .req_wdata     (dmem_req_wdata),
                .req_wstrb     (dmem_req_wstrb),
                .req_ready     (dmem_req_ready),
                .resp_valid    (dmem_resp_valid),
                .resp_rdata    (dmem_resp_rdata),
                .axi_req_valid (dcache_axi_req_valid_w),
                .axi_req_write (dcache_axi_req_write_w),
                .axi_req_uncached(dcache_axi_req_uncached_w),
                .axi_req_addr  (dcache_axi_req_addr_w),
                .axi_req_wdata (dcache_axi_req_wdata_w),
                .axi_req_wstrb (dcache_axi_req_wstrb_w),
                .axi_req_ready (dcache_axi_req_ready_w),
                .axi_resp_valid(dcache_axi_resp_valid_w),
                .axi_resp_rdata(dcache_axi_resp_data_w)
            );
        end
    endgenerate

    assign icache_axi_req_ready_w  =
        (L2_ENABLE != 0) ? l2_icache_req_ready_w : (axi_state_r == AXI_IDLE);
    assign icache_axi_resp_valid_w =
        (L2_ENABLE != 0) ? l2_icache_resp_valid_w : icache_axi_resp_valid_r;
    assign icache_axi_resp_data_w  =
        (L2_ENABLE != 0) ? l2_icache_resp_data_w : icache_axi_resp_data_r;

    assign dcache_axi_req_ready_w  =
        (L2_ENABLE != 0) ? l2_dcache_req_ready_w :
                           ((axi_state_r == AXI_IDLE) && !icache_axi_req_valid_w);
    assign dcache_axi_resp_valid_w =
        (L2_ENABLE != 0) ? l2_dcache_resp_valid_w : dcache_axi_resp_valid_r;
    assign dcache_axi_resp_data_w  =
        (L2_ENABLE != 0) ? l2_dcache_resp_data_w : dcache_axi_resp_data_r;

    generate
        if (L2_ENABLE != 0) begin : gen_l2_enabled
            la_l2_adapter #(
                .ENABLE_PREFETCH(0)
            ) u_l2_adapter (
                .clk                (clk),
                .reset              (reset),
                .icache_req_valid   (icache_axi_req_valid_w),
                .icache_req_addr    (icache_axi_req_addr_w),
                .icache_req_ready   (l2_icache_req_ready_w),
                .icache_resp_valid  (l2_icache_resp_valid_w),
                .icache_resp_data   (l2_icache_resp_data_w),
                .dcache_req_valid   (dcache_axi_req_valid_w),
                .dcache_req_write   (dcache_axi_req_write_w),
                .dcache_req_uncached(dcache_axi_req_uncached_w),
                .dcache_req_addr    (dcache_axi_req_addr_w),
                .dcache_req_wdata   (dcache_axi_req_wdata_w),
                .dcache_req_wstrb   (dcache_axi_req_wstrb_w),
                .dcache_req_ready   (l2_dcache_req_ready_w),
                .dcache_resp_valid  (l2_dcache_resp_valid_w),
                .dcache_resp_rdata  (l2_dcache_resp_data_w),
                .arid               (l2_arid_w),
                .araddr             (l2_araddr_w),
                .arlen              (l2_arlen_w),
                .arsize             (l2_arsize_w),
                .arburst            (l2_arburst_w),
                .arlock             (l2_arlock_w),
                .arcache            (l2_arcache_w),
                .arprot             (l2_arprot_w),
                .arvalid            (l2_arvalid_w),
                .arready            (arready),
                .rid                (rid),
                .rdata              (rdata),
                .rresp              (rresp),
                .rlast              (rlast),
                .rvalid             (rvalid),
                .rready             (l2_rready_w),
                .awid               (l2_awid_w),
                .awaddr             (l2_awaddr_w),
                .awlen              (l2_awlen_w),
                .awsize             (l2_awsize_w),
                .awburst            (l2_awburst_w),
                .awlock             (l2_awlock_w),
                .awcache            (l2_awcache_w),
                .awprot             (l2_awprot_w),
                .awvalid            (l2_awvalid_w),
                .awready            (awready),
                .wid                (l2_wid_w),
                .wdata              (l2_wdata_w),
                .wstrb              (l2_wstrb_w),
                .wlast              (l2_wlast_w),
                .wvalid             (l2_wvalid_w),
                .wready             (wready),
                .bid                (bid),
                .bresp              (bresp),
                .bvalid             (bvalid),
                .bready             (l2_bready_w)
            );
        end else begin : gen_l2_disabled
            assign l2_arid_w = 4'b0;
            assign l2_araddr_w = 32'b0;
            assign l2_arlen_w = 8'b0;
            assign l2_arsize_w = 3'b010;
            assign l2_arburst_w = 2'b01;
            assign l2_arlock_w = 2'b0;
            assign l2_arcache_w = 4'b0;
            assign l2_arprot_w = 3'b0;
            assign l2_arvalid_w = 1'b0;
            assign l2_rready_w = 1'b0;
            assign l2_awid_w = 4'b0;
            assign l2_awaddr_w = 32'b0;
            assign l2_awlen_w = 8'b0;
            assign l2_awsize_w = 3'b010;
            assign l2_awburst_w = 2'b01;
            assign l2_awlock_w = 2'b0;
            assign l2_awcache_w = 4'b0;
            assign l2_awprot_w = 3'b0;
            assign l2_awvalid_w = 1'b0;
            assign l2_wid_w = 4'b0;
            assign l2_wdata_w = 32'b0;
            assign l2_wstrb_w = 4'b0;
            assign l2_wlast_w = 1'b1;
            assign l2_wvalid_w = 1'b0;
            assign l2_bready_w = 1'b0;
            assign l2_icache_req_ready_w = 1'b0;
            assign l2_icache_resp_valid_w = 1'b0;
            assign l2_icache_resp_data_w = 32'b0;
            assign l2_dcache_req_ready_w = 1'b0;
            assign l2_dcache_resp_valid_w = 1'b0;
            assign l2_dcache_resp_data_w = 32'b0;
        end
    endgenerate

    assign arid    = (L2_ENABLE != 0) ? l2_arid_w    : arid_r;
    assign araddr  = (L2_ENABLE != 0) ? l2_araddr_w  : araddr_r;
    assign arlen   = (L2_ENABLE != 0) ? l2_arlen_w   : arlen_r;
    assign arsize  = (L2_ENABLE != 0) ? l2_arsize_w  : arsize_r;
    assign arburst = (L2_ENABLE != 0) ? l2_arburst_w : arburst_r;
    assign arlock  = (L2_ENABLE != 0) ? l2_arlock_w  : arlock_r;
    assign arcache = (L2_ENABLE != 0) ? l2_arcache_w : arcache_r;
    assign arprot  = (L2_ENABLE != 0) ? l2_arprot_w  : arprot_r;
    assign arvalid = (L2_ENABLE != 0) ? l2_arvalid_w : arvalid_r;
    assign rready  = (L2_ENABLE != 0) ? l2_rready_w  : rready_r;

    assign awid    = (L2_ENABLE != 0) ? l2_awid_w    : awid_r;
    assign awaddr  = (L2_ENABLE != 0) ? l2_awaddr_w  : awaddr_r;
    assign awlen   = (L2_ENABLE != 0) ? l2_awlen_w   : awlen_r;
    assign awsize  = (L2_ENABLE != 0) ? l2_awsize_w  : awsize_r;
    assign awburst = (L2_ENABLE != 0) ? l2_awburst_w : awburst_r;
    assign awlock  = (L2_ENABLE != 0) ? l2_awlock_w  : awlock_r;
    assign awcache = (L2_ENABLE != 0) ? l2_awcache_w : awcache_r;
    assign awprot  = (L2_ENABLE != 0) ? l2_awprot_w  : awprot_r;
    assign awvalid = (L2_ENABLE != 0) ? l2_awvalid_w : awvalid_r;

    assign wid     = (L2_ENABLE != 0) ? l2_wid_w     : wid_r;
    assign wdata   = (L2_ENABLE != 0) ? l2_wdata_w   : wdata_r;
    assign wstrb   = (L2_ENABLE != 0) ? l2_wstrb_w   : wstrb_r;
    assign wlast   = (L2_ENABLE != 0) ? l2_wlast_w   : wlast_r;
    assign wvalid  = (L2_ENABLE != 0) ? l2_wvalid_w  : wvalid_r;
    assign bready  = (L2_ENABLE != 0) ? l2_bready_w  : bready_r;

    always @(posedge clk) begin
        if (reset) begin
            axi_state_r <= AXI_IDLE;

            arid_r    <= 4'b0;
            araddr_r  <= 32'b0;
            arlen_r   <= 8'b0;
            arsize_r  <= 3'b010;
            arburst_r <= 2'b01;
            arlock_r  <= 2'b0;
            arcache_r <= 4'b0;
            arprot_r  <= 3'b0;
            arvalid_r <= 1'b0;
            rready_r  <= 1'b0;

            awid_r    <= 4'b0;
            awaddr_r  <= 32'b0;
            awlen_r   <= 8'b0;
            awsize_r  <= 3'b010;
            awburst_r <= 2'b01;
            awlock_r  <= 2'b0;
            awcache_r <= 4'b0;
            awprot_r  <= 3'b0;
            awvalid_r <= 1'b0;

            wid_r    <= 4'b0;
            wdata_r  <= 32'b0;
            wstrb_r  <= 4'b0;
            wlast_r  <= 1'b1;
            wvalid_r <= 1'b0;
            bready_r <= 1'b0;

            dwr_wdata_r <= 32'b0;
            dwr_wstrb_r <= 4'b0;

            icache_axi_resp_valid_r <= 1'b0;
            icache_axi_resp_data_r  <= 32'b0;
            dcache_axi_resp_valid_r <= 1'b0;
            dcache_axi_resp_data_r  <= 32'b0;
        end else begin
            icache_axi_resp_valid_r <= 1'b0;
            dcache_axi_resp_valid_r <= 1'b0;

            case (axi_state_r)
                AXI_IDLE: begin
                    // A0 keeps the old all-miss policy. Later A2 replaces this
                    // point with copied L1/L2 and AXI arbiter modules.
                    if (icache_axi_req_valid_w) begin
                        arid_r    <= 4'h0;
                        araddr_r  <= icache_axi_req_addr_w;
                        arlen_r   <= 8'd0;
                        arsize_r  <= 3'b010;
                        arburst_r <= 2'b01;
                        arlock_r  <= 2'b0;
                        arcache_r <= 4'b0;
                        arprot_r  <= 3'b0;
                        arvalid_r <= 1'b1;

                        axi_state_r <= AXI_I_AR;
                    end else if (dcache_axi_req_valid_w) begin
                        if (dcache_axi_req_write_w) begin
                            dwr_wdata_r <= dcache_axi_req_wdata_w;
                            dwr_wstrb_r <= dcache_axi_req_wstrb_w;

                            awid_r    <= 4'h1;
                            awaddr_r  <= dcache_axi_req_addr_w;
                            awlen_r   <= 8'd0;
                            awsize_r  <= 3'b010;
                            awburst_r <= 2'b01;
                            awlock_r  <= 2'b0;
                            awcache_r <= 4'b0;
                            awprot_r  <= 3'b0;
                            awvalid_r <= 1'b1;

                            axi_state_r <= AXI_D_AW;
                        end else begin
                            arid_r    <= 4'h1;
                            araddr_r  <= dcache_axi_req_addr_w;
                            arlen_r   <= 8'd0;
                            arsize_r  <= 3'b010;
                            arburst_r <= 2'b01;
                            arlock_r  <= 2'b0;
                            arcache_r <= 4'b0;
                            arprot_r  <= 3'b0;
                            arvalid_r <= 1'b1;

                            axi_state_r <= AXI_D_AR;
                        end
                    end
                end

                AXI_I_AR: begin
                    if (arvalid_r && arready) begin
                        arvalid_r <= 1'b0;
                        rready_r  <= 1'b1;
                        axi_state_r <= AXI_I_R;
                    end
                end

                AXI_I_R: begin
                    if (rvalid && rready_r) begin
                        rready_r <= 1'b0;
                        icache_axi_resp_valid_r <= 1'b1;
                        icache_axi_resp_data_r  <= rdata;
                        axi_state_r <= AXI_IDLE;
                    end
                end

                AXI_D_AR: begin
                    if (arvalid_r && arready) begin
                        arvalid_r <= 1'b0;
                        rready_r  <= 1'b1;
                        axi_state_r <= AXI_D_R;
                    end
                end

                AXI_D_R: begin
                    if (rvalid && rready_r) begin
                        rready_r <= 1'b0;
                        dcache_axi_resp_valid_r <= 1'b1;
                        dcache_axi_resp_data_r  <= rdata;
                        axi_state_r <= AXI_IDLE;
                    end
                end

                AXI_D_AW: begin
                    if (awvalid_r && awready) begin
                        awvalid_r <= 1'b0;
                        wid_r    <= 4'h1;
                        wdata_r  <= dwr_wdata_r;
                        wstrb_r  <= dwr_wstrb_r;
                        wlast_r  <= 1'b1;
                        wvalid_r <= 1'b1;

                        axi_state_r <= AXI_D_W;
                    end
                end

                AXI_D_W: begin
                    if (wvalid_r && wready) begin
                        wvalid_r <= 1'b0;
                        bready_r <= 1'b1;
                        axi_state_r <= AXI_D_B;
                    end
                end

                AXI_D_B: begin
                    if (bvalid && bready_r) begin
                        bready_r <= 1'b0;
                        dcache_axi_resp_valid_r <= 1'b1;
                        dcache_axi_resp_data_r  <= 32'b0;
                        axi_state_r <= AXI_IDLE;
                    end
                end

                default: begin
                    axi_state_r <= AXI_IDLE;
                end
            endcase
        end
    end

endmodule
