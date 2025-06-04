module verilator_top(
        input  wire        rst,
        input  wire        clk

    );

    wire cpu_resetn;
    assign cpu_resetn = ~rst;

    //cpu inst sram
    wire        cpu_inst_en;
    wire [3:0]       cpu_inst_we;
    wire [31:0] cpu_inst_addr;
    wire [31:0] cpu_inst_wdata;
    wire [31:0] cpu_inst_rdata;
    //cpu data sram
    wire        cpu_data_en;
    wire  [3:0]      cpu_data_we;
    wire [31:0] cpu_data_addr;
    wire [31:0] cpu_data_wdata;
    wire [31:0] cpu_data_rdata;

    //debug
    wire [31:0] debug_wb_pc/* verilator public */;
    wire [ 3:0] debug_wb_rf_we/* verilator public */;
    wire [ 4:0] debug_wb_rf_wnum/* verilator public */;
    wire [31:0] debug_wb_rf_wdata/* verilator public */;
    wire [31:0] debug_wb_inst/* verilator public */;
    wire debug_wb_is_csr_wr_o/* verilator public */;
    wire debug_has_refetch_excp_o/* verilator public */;
    wire [31:0] csr_crmd_diff/* verilator public */;
    wire [31:0] csr_prmd_diff/* verilator public */;
    wire [31:0] csr_ecfg_diff/* verilator public */;
    wire [31:0] csr_estat_diff/* verilator public */;
    wire [31:0] csr_era_diff/* verilator public */;
    wire [31:0] csr_badv_diff/* verilator public */;
    wire [31:0] csr_eentry_diff/* verilator public */;
    wire [31:0] csr_tlbidx_diff/* verilator public */;
    wire [31:0] csr_tlbehi_diff/* verilator public */;
    wire [31:0] csr_tlbelo0_diff/* verilator public */;
    wire [31:0] csr_tlbelo1_diff/* verilator public */;
    wire [31:0] csr_asid_diff/* verilator public */;
    wire [31:0] csr_save0_diff/* verilator public */;
    wire [31:0] csr_save1_diff/* verilator public */;
    wire [31:0] csr_save2_diff/* verilator public */;
    wire [31:0] csr_save3_diff/* verilator public */;
    wire [31:0] csr_tid_diff/* verilator public */;
    wire [31:0] csr_tcfg_diff/* verilator public */;
    wire [31:0] csr_tval_diff/* verilator public */;
    wire [31:0] csr_ticlr_diff/* verilator public */;
    wire [31:0] csr_llbctl_diff/* verilator public */;
    wire [31:0] csr_tlbrentry_diff/* verilator public */;
    wire [31:0] csr_dmw0_diff/* verilator public */;
    wire [31:0] csr_dmw1_diff/* verilator public */;
    wire [31:0] csr_pgdl_diff/* verilator public */;
    wire [31:0] csr_pgdh_diff/* verilator public */;

    //data sram
    wire        data_sram_en;
    wire        data_sram_we;
    wire [31:0] data_sram_addr;
    wire [31:0] data_sram_wdata;
    wire [31:0] data_sram_rdata;

    // wire_AXI

    wire [3:0] wire_arid;
    wire [31:0] wire_araddr;
    wire [7:0] wire_arlen;
    wire [2:0] wire_arsize;
    wire [1:0] wire_arburst;
    wire [1:0] wire_arlock;
    wire [3:0] wire_arcache;
    wire [2:0] wire_arprot;
    wire        wire_arvalid;
    wire        wire_arready;

    wire [3:0] wire_rid;
    wire [31:0] wire_rdata;
    wire [1:0] wire_rresp;
    wire        wire_rlast;
    wire        wire_rvalid;
    wire        wire_rready;

    wire [3:0] wire_awid;
    wire [31:0] wire_awaddr;
    wire [7:0] wire_awlen;
    wire [2:0] wire_awsize;
    wire [1:0] wire_awburst;
    wire [1:0] wire_awlock;
    wire [3:0] wire_awcache;
    wire [2:0] wire_awprot;
    wire        wire_awvalid;
    wire        wire_awready;


    wire [3:0] wire_wid;
    wire [31:0] wire_wdata;
    wire [3:0] wire_wstrb;
    wire wire_wlast;
    wire        wire_wvalid;
    wire        wire_wready;

    wire [1:0] wire_bresp;
    wire        wire_bvalid;
    wire        wire_bready;
    wire [3:0] wire_bid;

    //cpu inst sram
    wire        cpu_inst_req;
    wire        cpu_inst_wr;
    wire [1 :0] cpu_inst_size;
    wire [3 :0] cpu_inst_wstrb;
    wire [31:0] cpu_inst_addr;
    wire [31:0] cpu_inst_wdata;
    wire        cpu_inst_addr_ok;
    wire        cpu_inst_data_ok;
    wire [31:0] cpu_inst_rdata;

    //cpu data sram
    wire        cpu_data_req;
    wire        cpu_data_wr;
    wire [1 :0] cpu_data_size;
    wire [3 :0] cpu_data_wstrb;
    wire [31:0] cpu_data_addr;
    wire [31:0] cpu_data_wdata;
    wire        cpu_data_addr_ok;
    wire        cpu_data_data_ok;
    wire [31:0] cpu_data_rdata;


    //cpu
    mycpu_top cpu(
                  .aclk              (clk       ),
                  .aresetn           (cpu_resetn    ),  //low active

                  .arid           (wire_arid),
                  .araddr         (wire_araddr),
                  .arlen          (wire_arlen),
                  .arsize         (wire_arsize),
                  .arburst        (wire_arburst),
                  .arlock         (wire_arlock),
                  .arcache        (wire_arcache),
                  .arprot         (wire_arprot),
                  .arvalid        (wire_arvalid),
                  .arready        (wire_arready),
                  .rid            (wire_rid),
                  .rdata          (wire_rdata),
                  .rresp          (wire_rresp),
                  .rlast          (wire_rlast),
                  .rvalid         (wire_rvalid),
                  .rready         (wire_rready),
                  .awid           (wire_awid),
                  .awaddr         (wire_awaddr),
                  .awlen          (wire_awlen),
                  .awsize         (wire_awsize),
                  .awburst        (wire_awburst),
                  .awlock         (wire_awlock),
                  .awcache        (wire_awcache),
                  .awprot         (wire_awprot),
                  .awvalid        (wire_awvalid),
                  .awready        (wire_awready),

                  .wid            (wire_wid),
                  .wdata          (wire_wdata),
                  .wstrb          (wire_wstrb),
                  .wlast          (wire_wlast),
                  .wvalid         (wire_wvalid),
                  .wready         (wire_wready),

                  .bresp          (wire_bresp),
                  .bvalid         (wire_bvalid),
                  .bready         (wire_bready),
                  .bid            (wire_bid),


                  .debug_wb_pc      (debug_wb_pc),
                  .debug_wb_rf_we   (debug_wb_rf_we),
                  .debug_wb_rf_wnum (debug_wb_rf_wnum),
                  .debug_wb_rf_wdata(debug_wb_rf_wdata),
                  .debug_wb_inst    (debug_wb_inst    ),
                  .debug_wb_is_csr_wr_o (debug_wb_is_csr_wr_o),
                  .debug_has_refetch_excp_o(debug_has_refetch_excp_o),
                  .csr_crmd_diff      (csr_crmd_diff    ),
                  .csr_prmd_diff      (csr_prmd_diff    ),
                  .csr_ecfg_diff      (csr_ecfg_diff    ),
                  .csr_estat_diff     (csr_estat_diff   ),
                  .csr_era_diff       (csr_era_diff     ),
                  .csr_badv_diff      (csr_badv_diff    ),
                  .csr_eentry_diff    (csr_eentry_diff  ),
                  .csr_tlbidx_diff    (csr_tlbidx_diff  ),
                  .csr_tlbehi_diff    (csr_tlbehi_diff  ),
                  .csr_tlbelo0_diff   (csr_tlbelo0_diff ),
                  .csr_tlbelo1_diff   (csr_tlbelo1_diff ),
                  .csr_asid_diff      (csr_asid_diff    ),
                  .csr_save0_diff     (csr_save0_diff   ),
                  .csr_save1_diff     (csr_save1_diff   ),
                  .csr_save2_diff     (csr_save2_diff   ),
                  .csr_save3_diff     (csr_save3_diff   ),
                  .csr_tid_diff       (csr_tid_diff     ),
                  .csr_tcfg_diff      (csr_tcfg_diff    ),
                  .csr_tval_diff      (csr_tval_diff    ),
                  .csr_ticlr_diff     (csr_ticlr_diff   ),
                  .csr_llbctl_diff    (csr_llbctl_diff  ),
                  .csr_tlbrentry_diff (csr_tlbrentry_diff),
                  .csr_dmw0_diff      (csr_dmw0_diff    ),
                  .csr_dmw1_diff      (csr_dmw1_diff    ),
                  .csr_pgdl_diff      (csr_pgdl_diff    ),
                  .csr_pgdh_diff      (csr_pgdh_diff    )

              );

    axi_ram axi_ram (
                .clock (clk),
                .reset (rst),
                // AR
                .arid           (wire_arid),
                .araddr         (wire_araddr),
                .arlen          (wire_arlen),
                .arsize         (wire_arsize),
                .arburst        (wire_arburst),
                .arlock         (wire_arlock),
                .arcache        (wire_arcache),
                .arprot         (wire_arprot),
                .arvalid        (wire_arvalid),
                .arready        (wire_arready),
                .rid            (wire_rid),
                .rdata          (wire_rdata),
                .rresp          (wire_rresp),
                .rlast          (wire_rlast),
                .rvalid         (wire_rvalid),
                .rready         (wire_rready),
                .awid           (wire_awid),
                .awaddr         (wire_awaddr),
                .awlen          (wire_awlen),
                .awsize         (wire_awsize),
                .awburst        (wire_awburst),
                .awlock         (wire_awlock),
                .awcache        (wire_awcache),
                .awprot         (wire_awprot),
                .awvalid        (wire_awvalid),
                .awready        (wire_awready),

                .wid            (wire_wid),
                .wdata          (wire_wdata),
                .wstrb          (wire_wstrb),
                .wlast          (wire_wlast),
                .wvalid         (wire_wvalid),
                .wready         (wire_wready),

                .bresp          (wire_bresp),
                .bvalid         (wire_bvalid),
                .bready         (wire_bready),
                .bid            (wire_bid)

            );




endmodule

