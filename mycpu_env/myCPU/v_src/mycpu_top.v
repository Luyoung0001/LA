module mycpu_top
    #(
         parameter TLBNUM = 16
     )
     (
         input  wire        aclk,
         input  wire        aresetn,

         // AXI Interface
         // Read request channel
         output wire [ 3:0] arid,
         output wire [31:0] araddr,
         output wire [ 7:0] arlen,
         output wire [ 2:0] arsize,
         output wire [ 1:0] arburst,
         output wire [ 1:0] arlock,
         output wire [ 3:0] arcache,
         output wire [ 2:0] arprot,
         output wire        arvalid,
         input  wire        arready,

         // Read response channel
         input  wire [ 3:0] rid,
         input  wire [31:0] rdata,
         input  wire [ 1:0] rresp,
         input  wire        rlast,
         input  wire        rvalid,
         output wire        rready,

         // Write address channel
         output wire [ 3:0] awid,
         output wire [31:0] awaddr,
         output wire [ 7:0] awlen,
         output wire [ 2:0] awsize,
         output wire [ 1:0] awburst,
         output wire [ 1:0] awlock,
         output wire [ 3:0] awcache,
         output wire [ 2:0] awprot,
         output wire        awvalid,
         input  wire        awready,

         // Write data channel
         output wire [ 3:0] wid,
         output wire [31:0] wdata,
         output wire [ 3:0] wstrb,
         output wire        wlast,
         output wire        wvalid,
         input  wire        wready,

         // Write response channel
         input  wire [ 3:0] bid,
         input  wire [ 1:0] bresp,
         input  wire        bvalid,
         output wire        bready,

         // Trace debug interface
         output wire [31:0] debug_wb_pc,
         output wire [ 3:0] debug_wb_rf_we,
         output wire [ 4:0] debug_wb_rf_wnum,
         output wire [31:0] debug_wb_rf_wdata,
         output wire [31:0] debug_wb_inst,
         output wire        debug_wb_is_csr_wr_o,
         output wire        debug_has_refetch_excp_o,

         // CSR diff outputs
         output [31:0] csr_crmd_diff,
         output [31:0] csr_prmd_diff,
         output [31:0] csr_ecfg_diff,
         output [31:0] csr_estat_diff,
         output [31:0] csr_era_diff,
         output [31:0] csr_badv_diff,
         output [31:0] csr_eentry_diff,
         output [31:0] csr_tlbidx_diff,
         output [31:0] csr_tlbehi_diff,
         output [31:0] csr_tlbelo0_diff,
         output [31:0] csr_tlbelo1_diff,
         output [31:0] csr_asid_diff,
         output [31:0] csr_save0_diff,
         output [31:0] csr_save1_diff,
         output [31:0] csr_save2_diff,
         output [31:0] csr_save3_diff,
         output [31:0] csr_tid_diff,
         output [31:0] csr_tcfg_diff,
         output [31:0] csr_tval_diff,
         output [31:0] csr_ticlr_diff,
         output [31:0] csr_llbctl_diff,
         output [31:0] csr_tlbrentry_diff,
         output [31:0] csr_dmw0_diff,
         output [31:0] csr_dmw1_diff,
         output [31:0] csr_pgdl_diff,
         output [31:0] csr_pgdh_diff
     );

    // Internal signals
    wire [7:0] intrpt;
    assign intrpt = 8'b0;

    wire reset;
    assign reset = ~aresetn;

    // SRAM-like interface signals for instruction memory
    wire        inst_sram_req;
    wire        inst_sram_wr;
    wire [ 1:0] inst_sram_size;
    wire [ 3:0] inst_sram_wstrb;
    wire [31:0] inst_sram_addr;
    wire [31:0] inst_sram_wdata;
    wire        inst_sram_addr_ok;
    wire        inst_sram_data_ok;
    wire [31:0] inst_sram_rdata;

    // SRAM-like interface signals for data memory
    wire        data_sram_req;
    wire        data_sram_wr;
    wire [ 1:0] data_sram_size;
    wire [ 3:0] data_sram_wstrb;
    wire [31:0] data_sram_addr;
    wire [31:0] data_sram_wdata;
    wire        data_sram_addr_ok;
    wire        data_sram_data_ok;
    wire [31:0] data_sram_rdata;

    wire        icache_rd_rdy;
    wire        icache_ret_valid;
    wire        icache_ret_last;
    wire [31:0] icache_ret_data;

    wire        icache_wr_rdy;


    // AXI-XBar Bridge
    sram_like_to_axi_bridge o (
                                .clk            (aclk),
                                .rst            (reset),

                                // Instruction SRAM interface
                                // .inst_sram_req  (inst_sram_req),
                                // .inst_sram_wr   (inst_sram_wr),
                                // .inst_sram_size (inst_sram_size),
                                // .inst_sram_wstrb(inst_sram_wstrb),
                                // .inst_sram_addr (inst_sram_addr),
                                // .inst_sram_wdata(inst_sram_wdata),
                                // .inst_sram_addr_ok(inst_sram_addr_ok),
                                // .inst_sram_data_ok(inst_sram_data_ok),
                                // .inst_sram_rdata(inst_sram_rdata),

                                // icache
                                .icache_rd_req(icache_rd_req),
                                .icache_rd_type(icache_rd_type),
                                .icache_rd_addr(icache_rd_addr),
                                .icache_rd_rdy(icache_rd_rdy),
                                .icache_ret_valid(icache_ret_valid),
                                .icache_ret_last(icache_ret_last),
                                .icache_ret_data(icache_ret_data),

                                .icache_wr_req(icache_wr_req),
                                .icache_wr_type(icache_wr_type),
                                .icache_wr_addr(icache_wr_addr),
                                .icache_wr_wstrb(icache_wr_wstrb),
                                .icache_wr_data(icache_wr_data),
                                .icache_wr_rdy(icache_wr_rdy),

                                // Data SRAM interface
                                .data_sram_req  (data_sram_req),
                                .data_sram_wr   (data_sram_wr),
                                .data_sram_size (data_sram_size),
                                .data_sram_wstrb(data_sram_wstrb),
                                .data_sram_addr (data_sram_addr),
                                .data_sram_wdata(data_sram_wdata),
                                .data_sram_addr_ok(data_sram_addr_ok),
                                .data_sram_data_ok(data_sram_data_ok),
                                .data_sram_rdata(data_sram_rdata),

                                // AXI Interface
                                .arid           (arid),
                                .araddr         (araddr),
                                .arlen          (arlen),
                                .arsize         (arsize),
                                .arburst        (arburst),
                                .arlock         (arlock),
                                .arcache        (arcache),
                                .arprot         (arprot),
                                .arvalid        (arvalid),
                                .arready        (arready),

                                .rid            (rid),
                                .rdata          (rdata),
                                .rresp          (rresp),
                                .rlast          (rlast),
                                .rvalid         (rvalid),
                                .rready         (rready),

                                .awid           (awid),
                                .awaddr         (awaddr),
                                .awlen          (awlen),
                                .awsize         (awsize),
                                .awburst        (awburst),
                                .awlock         (awlock),
                                .awcache        (awcache),
                                .awprot         (awprot),
                                .awvalid        (awvalid),
                                .awready        (awready),

                                .wid            (wid),
                                .wdata          (wdata),
                                .wstrb          (wstrb),
                                .wlast          (wlast),
                                .wvalid         (wvalid),
                                .wready         (wready),

                                .bid            (bid),
                                .bresp          (bresp),
                                .bvalid         (bvalid),
                                .bready         (bready)
                            );

    // Pre-IFU signals
    wire [31:0] preifu_pc_o;
    wire        preifu_state_valid;

    // IFU signals
    wire [31:0] ifu_pc_o;
    wire        ifu_fs_excp_out;
    wire [15:0] ifu_fs_excp_num_out;
    wire        ifu_state_valid;
    wire        ifu_waite_ready_o;
    wire [31:0] ifu_rdata_o;
    wire        ifu_refetch_excp_o;

    // IFU address translation signals
    wire        ifu_inst_addr_trans_en;
    wire [ 9:0] ifu_inst_asid;
    wire [31:0] ifu_inst_vaddr;
    wire        ifu_inst_dmw0_en;
    wire        ifu_inst_dmw1_en;
    wire [31:0] ifu_inst_dmw0;
    wire [31:0] ifu_inst_dmw1;
    wire        ifu_inst_da;
    wire        ifu_inst_pg;

    // icache
    wire ifu_icache_valid;
    wire ifu_icache_op;
    wire [19:0] ifu_icache_tag;
    wire [7:0] ifu_icache_index;
    wire [3:0] ifu_icache_offset;

    wire [3:0] ifu_icache_wstrb;
    wire [31:0] ifu_icache_wdata;
    wire ifu_flush_sign_cancel;



    // IDU signals
    wire [33:0]  idu_bus_br_data;
    wire         idu_ds_excp_out;
    wire [15:0]  idu_ds_excp_num_out;
    wire [ 4:0]  idu_rf_raddr1;
    wire [ 4:0]  idu_rf_raddr2;
    wire [226:0] idu_bus_ds_to_es_data;
    wire [31:0]  idu_idu_inst_o;
    wire [ 9:0]  idu_out_mem_op;
    wire [13:0]  idu_rd_csr_addr;
    wire         idu_state_valid;
    wire         idu_waite_ready_o;
    wire         idu_is_csr_wr;
    wire [ 4:0]  idu_tlb_inst_bus;
    wire [ 4:0]  idu_invtlb_op;
    wire [ 9:0]  idu_invtlb_asid;
    wire [18:0]  idu_invtlb_vpn;
    wire         idu_refetch_excp_o;
    wire [31:0]  idu_pc_pro_o;

    wire [82:0] idu_bus_csr_rd_wr_data;

    // EXU signals
    wire         exu_es_excp_out;
    wire [15:0]  exu_es_excp_num_out;
    wire [31:0]  exu_inst_data_o;
    wire [150:0] exu_bus_exu_to_mem_data;
    wire [31:0]  exu_rdata_o;
    wire [85:0]  exu_bus_exu_bypass_data;
    wire [ 9:0]  exu_out_mem_op;
    wire [ 3:0]  exu_out_mem_mask;
    wire         exu_exu_excp;
    wire         exu_exu_is_etrn;
    wire         exu_state_valid;
    wire         exu_waite_ready_o;
    wire [ 4:0]  exu_tlb_inst_bus_o;
    wire         exu_is_csr_wr_o;
    wire         exu_refetch_excp_o;
    wire [31:0]  exu_pc_pro_o;

    // EXU address translation signals
    wire                           exu_data_addr_trans_en;
    wire [ 9:0]                    exu_data_asid;
    wire [31:0]                    exu_data_vaddr;
    wire                           exu_data_dmw0_en;
    wire                           exu_data_dmw1_en;
    wire [31:0]                    exu_data_dmw0;
    wire [31:0]                    exu_data_dmw1;
    wire                           exu_data_da;
    wire                           exu_data_pg;
    wire [$clog2(TLBNUM)-1:0]      exu_tlbsrch_index;
    wire                           exu_tlbsrch_found;
    wire [ 4:0]                    exu_invtlb_op_o;
    wire [ 9:0]                    exu_invtlb_asid_o;
    wire [18:0]                    exu_invtlb_vpn_o;

    wire [82:0] exu_bus_csr_rd_wr_data_o;
    wire [31:0] exu_paddr;

    // MEM signals
    wire         mem_ms_excp_out;
    wire [15:0]  mem_ms_excp_num_out;
    wire [31:0]  mem_inst_data_o;
    wire [149:0] mem_bus_mem_to_wbu_data;
    wire [85:0]  mem_bus_mem_bypass_data;
    wire         mem_mem_excp;
    wire         mem_is_ertn;
    wire         mem_state_valid;
    wire         mem_waite_ready_o;
    wire [ 4:0]  mem_tlb_inst_bus_o;
    wire         mem_is_csr_wr_o;
    wire         mem_refetch_excp_o;
    wire [31:0]  mem_pc_pro_o;

    // MEM TLB signals
    wire [$clog2(TLBNUM)-1:0] mem_tlbsrch_index_o;
    wire                      mem_tlbsrch_found_o;
    wire [ 4:0]               mem_invtlb_op_o;
    wire [ 9:0]               mem_invtlb_asid_o;
    wire [18:0]               mem_invtlb_vpn_o;

    wire [1:0] mem_ll_sc;
    wire [31:0] mem_paddr_o;




    // WBU signals
    wire        wbu_rf_we;
    wire [ 4:0] wbu_rf_waddr;
    wire [31:0] wbu_rf_wdata;
    wire [31:0] wbu_pc;
    wire [85:0] wbu_bus_wbu_bypass_data;
    wire [147:0] wbu_bus_wbu_to_csr_data;
    wire [ 1:0] wbu_flush;
    wire        wbu_is_ertn;
    wire        wbu_waite_ready_o;
    wire [31:0] wbu_inst_data_o;
    wire        wbu_is_refetch_sign;
    wire [31:0] wbu_refetch_pc;
    wire        wbu_refetch_sign;
    wire        wbu_wbu_refetch_flush;

    // WBU TLB signals
    wire                      wbu_tlbsrch_en;
    wire                      wbu_tlbsrch_found_o;
    wire [$clog2(TLBNUM)-1:0] wbu_tlbsrch_index_o;
    wire [31:0]               wbu_to_trans_tlbidx_o;
    wire                      wbu_csr_tlbrd_en_o;
    wire [31:0]               wbu_csr_tlbehi_o;
    wire [31:0]               wbu_csr_tlbelo0_o;
    wire [31:0]               wbu_csr_tlbelo1_o;
    wire [31:0]               wbu_csr_tlbidx_o;
    wire [ 9:0]               wbu_csr_asid_o;
    wire                      wbu_tlbwr_en_o;
    wire [31:0]               wbu_tlbwr_fill_tlbehi_o;
    wire [31:0]               wbu_tlbwr_fill_tlbelo0_o;
    wire [31:0]               wbu_tlbwr_fill_tlbelo1_o;
    wire [31:0]               wbu_tlbwr_fill_tlbidx_o;
    wire [ 5:0]               wbu_tlbwr_fill_ecode_o;
    wire [ 9:0]               wbu_tlbwr_fill_w_asid_o;
    wire                      wbu_tlbfill_en_o;
    wire [$clog2(TLBNUM)-1:0] wbu_rand_index_o;
    wire [ 4:0]               wbu_invtlb_op_o;
    wire [ 9:0]               wbu_invtlb_asid_o;
    wire [18:0]               wbu_invtlb_vpn_o;
    wire                      wbu_invtlb_en_o;

    wire                      wbu_excp_tlbrefill_o;

    wire wbu_ws_llbit_set;
    wire wbu_ws_llbit;
    wire wbu_ws_lladdr_set;
    wire [27:0] wbu_ws_lladdr;

    // Register file signals
    wire [31:0] rf_rdata1;
    wire [31:0] rf_rdata2;

    // CSR signals
    wire [31:0] csr_rd_data;
    wire [63:0] csr_timer_64_out;
    wire [31:0] csr_tid_out;
    wire        csr_has_int;
    wire [31:0] csr_era_out;
    wire [31:0] csr_eentry_out;
    wire [31:0] csr_tlbrentry_out;
    wire [ 1:0] csr_plv_out;
    wire [ 9:0] csr_asid_out;
    wire [18:0] csr_vppn_out;
    wire [31:0] csr_tlbehi_out;
    wire [31:0] csr_tlbelo0_out;
    wire [31:0] csr_tlbelo1_out;
    wire [31:0] csr_tlbidx_out;
    wire        csr_pg_out;
    wire        csr_da_out;
    wire [31:0] csr_dmw0_out;
    wire [31:0] csr_dmw1_out;
    wire [ 1:0] csr_datf_out;
    wire [ 1:0] csr_datm_out;
    wire [ 5:0] csr_ecode_out;
    wire [$clog2(TLBNUM)-1:0] csr_rand_index;

    wire csr_llbit_out;
    wire [27:0] csr_lladdr_out;

    // TLB signals
    wire                      tlb_s0_found;
    wire [$clog2(TLBNUM)-1:0] tlb_s0_index;
    wire [19:0]               tlb_s0_ppn;
    wire [ 5:0]               tlb_s0_ps;
    wire [ 1:0]               tlb_s0_plv;
    wire [ 1:0]               tlb_s0_mat;
    wire                      tlb_s0_d;
    wire                      tlb_s0_v;

    wire                      tlb_s1_found;
    wire [$clog2(TLBNUM)-1:0] tlb_s1_index;
    wire [19:0]               tlb_s1_ppn;
    wire [ 5:0]               tlb_s1_ps;
    wire [ 1:0]               tlb_s1_plv;
    wire [ 1:0]               tlb_s1_mat;
    wire                      tlb_s1_d;
    wire                      tlb_s1_v;

    wire        tlb_r_e;
    wire [18:0] tlb_r_vppn;
    wire [ 1:0] tlb_r_ps;
    wire [ 9:0] tlb_r_asid;
    wire        tlb_r_g;
    wire [19:0] tlb_r_ppn0;
    wire [ 1:0] tlb_r_plv0;
    wire [ 1:0] tlb_r_mat0;
    wire        tlb_r_d0;
    wire        tlb_r_v0;
    wire [19:0] tlb_r_ppn1;
    wire [ 1:0] tlb_r_plv1;
    wire [ 1:0] tlb_r_mat1;
    wire        tlb_r_d1;
    wire        tlb_r_v1;

    // Address translation signals
    wire [ 7:0] trans_inst_index;
    wire [19:0] trans_inst_tag;
    wire [ 3:0] trans_inst_offset;
    wire        trans_inst_tlb_found;
    wire        trans_inst_tlb_v;
    wire        trans_inst_tlb_d;
    wire [ 1:0] trans_inst_tlb_mat;
    wire [ 1:0] trans_inst_tlb_plv;

    wire [ 7:0]               trans_data_index;
    wire [19:0]               trans_data_tag;
    wire [ 3:0]               trans_data_offset;
    wire                      trans_data_tlb_found;
    wire [$clog2(TLBNUM)-1:0] trans_data_tlb_index;
    wire                      trans_data_tlb_v;
    wire                      trans_data_tlb_d;
    wire [ 1:0]               trans_data_tlb_mat;
    wire [ 1:0]               trans_data_tlb_plv;

    wire [31:0] trans_tlbehi_out;
    wire [31:0] trans_tlbelo0_out;
    wire [31:0] trans_tlbelo1_out;
    wire [31:0] trans_tlbidx_out;
    wire [ 9:0] trans_asid_out;

    // icache
    wire icache_addr_ok;
    wire icache_data_ok;
    wire [31:0] icache_rdata;

    wire icache_rd_req;
    wire [2:0] icache_rd_type;
    wire [31:0] icache_rd_addr;

    wire        icache_wr_req;
    wire [2:0]  icache_wr_type;
    wire [31:0] icache_wr_addr;
    wire [3:0]  icache_wr_wstrb;
    wire [127:0] icache_wr_data;

    // Module Instantiations

    // Pre-IFU
    pre_IFU pre_ifu(
                .clk               (aclk),
                .rst               (reset),
                .bus_br_data       (idu_bus_br_data),
                .pc_o              (preifu_pc_o),
                .flush             (wbu_flush),
                .csr_era           (csr_era_out),
                .csr_eentry        (csr_eentry_out),
                .csr_tlbrentry     (csr_tlbrentry_out),
                .wbu_excp_tlbrefill(wbu_excp_tlbrefill_o),
                .waite_ready_i     (ifu_waite_ready_o),
                .state_valid       (preifu_state_valid),
                .refetch_pc_i      (wbu_refetch_pc),
                .refetch_sign_i    (wbu_refetch_sign),
                .wbu_refetch_flush (wbu_wbu_refetch_flush)
            );

    // IFU
    IFU ifu(
            .clk               (aclk),
            .rst               (reset),
            .pc_i              (preifu_pc_o),
            .pc_o              (ifu_pc_o),
            .fs_excp_out       (ifu_fs_excp_out),
            .fs_excp_num_out   (ifu_fs_excp_num_out),
            .flush             (wbu_flush),
            .up_valid          (preifu_state_valid),
            .state_valid       (ifu_state_valid),
            .waite_ready_i     (idu_waite_ready_o),
            .waite_ready_o     (ifu_waite_ready_o),

            // From CSR
            .csr_plv           (csr_plv_out),
            .csr_dmw0          (csr_dmw0_out),
            .csr_dmw1          (csr_dmw1_out),
            .csr_da            (csr_da_out),
            .csr_pg            (csr_pg_out),
            .csr_tlbidx        (csr_tlbidx_out),
            .csr_tlbehi        (csr_tlbehi_out),
            .csr_tlbelo0       (csr_tlbelo0_out),
            .csr_tlbelo1       (csr_tlbelo1_out),
            .csr_asid          (csr_asid_out),

            // Address translation
            .inst_addr_trans_en(ifu_inst_addr_trans_en),
            .inst_asid         (ifu_inst_asid),
            .inst_vaddr        (ifu_inst_vaddr),
            .inst_dmw0_en      (ifu_inst_dmw0_en),
            .inst_dmw1_en      (ifu_inst_dmw1_en),
            .inst_dmw0         (ifu_inst_dmw0),
            .inst_dmw1         (ifu_inst_dmw1),
            .inst_da           (ifu_inst_da),
            .inst_pg           (ifu_inst_pg),

            .inst_index        (trans_inst_index),
            .inst_tag          (trans_inst_tag),
            .inst_offset       (trans_inst_offset),
            .inst_tlb_found    (trans_inst_tlb_found),
            .inst_tlb_v        (trans_inst_tlb_v),
            .inst_tlb_d        (trans_inst_tlb_d),
            .inst_tlb_mat      (trans_inst_tlb_mat),
            .inst_tlb_plv      (trans_inst_tlb_plv),

            // SRAM-like interface
            // .req               (inst_sram_req),
            // .wr                (inst_sram_wr),
            // .size              (inst_sram_size),
            // .wstrb             (inst_sram_wstrb),
            // .addr              (inst_sram_addr),
            // .wdata             (inst_sram_wdata),
            // .addr_ok           (inst_sram_addr_ok),
            // .data_ok           (inst_sram_data_ok),
            // .rdata             (inst_sram_rdata),
            .icache_valid(ifu_icache_valid),
            .icache_op(ifu_icache_op),
            .icache_tag(ifu_icache_tag),
            .icache_index(ifu_icache_index),
            .icache_offset(ifu_icache_offset),
            .flush_sign_cancel(ifu_flush_sign_cancel),

            .icache_wstrb(ifu_icache_wstrb),
            .icache_wdata(ifu_icache_wdata),

            .icache_addr_ok(icache_addr_ok),
            .icache_data_ok(icache_data_ok),
            .icache_rdata(icache_rdata),

            .rdata_o           (ifu_rdata_o),
            .wbu_refetch_sign_i(wbu_is_refetch_sign),
            .refetch_excp_o    (ifu_refetch_excp_o),
            .wbu_refetch_flush (wbu_wbu_refetch_flush)
        );

    // Register File
    regfile u_regfile(
                .clk    (aclk),
                .raddr1 (idu_rf_raddr1),
                .raddr2 (idu_rf_raddr2),
                .rdata1 (rf_rdata1),
                .rdata2 (rf_rdata2),
                .we     (wbu_rf_we),
                .waddr  (wbu_rf_waddr),
                .wdata  (wbu_rf_wdata)
            );

    // IDU
    IDU idu(
            .clk                   (aclk),
            .rst                   (reset),

            // To pre_IFU
            .bus_br_data           (idu_bus_br_data),

            // From IFU
            .in_pc                 (ifu_pc_o),
            .in_rdata              (ifu_rdata_o),
            .fs_excp               (ifu_fs_excp_out),
            .fs_excp_num           (ifu_fs_excp_num_out),
            .ds_excp_out           (idu_ds_excp_out),
            .ds_excp_num_out       (idu_ds_excp_num_out),

            // To/From register file
            .rf_raddr1             (idu_rf_raddr1),
            .rf_raddr2             (idu_rf_raddr2),
            .rf_rdata1             (rf_rdata1),
            .rf_rdata2             (rf_rdata2),

            // Output buses
            .bus_ds_to_es_data     (idu_bus_ds_to_es_data),
            .idu_inst_o            (idu_idu_inst_o),
            .out_mem_op            (idu_out_mem_op),

            // CSR interface
            .llbit(csr_llbit_out),
            .csr_plv               (csr_plv_out),

            // Control signals
            .flush                 (wbu_flush),
            .has_int               (csr_has_int),
            .exu_excp              (exu_exu_excp),
            .exu_is_ertn_i         (exu_exu_is_etrn),

            // Bypass data
            .bus_exu_bypass_data   (exu_bus_exu_bypass_data),
            .bus_mem_bypass_data   (mem_bus_mem_bypass_data),
            .bus_wbu_bypass_data   (wbu_bus_wbu_bypass_data),

            // Pipeline control
            .up_valid              (ifu_state_valid),
            .state_valid           (idu_state_valid),
            .waite_ready_i         (exu_waite_ready_o),
            .waite_ready_o         (idu_waite_ready_o),

            // TLB interface
            .tlb_inst_bus          (idu_tlb_inst_bus),
            .invtlb_op             (idu_invtlb_op),
            .invtlb_asid           (idu_invtlb_asid),
            .invtlb_vpn            (idu_invtlb_vpn),
            .is_csr_wr             (idu_is_csr_wr),

            // Refetch handling
            .wbu_refetch_sign_i    (wbu_is_refetch_sign),
            .refetch_excp_i        (ifu_refetch_excp_o),
            .refetch_excp_o        (idu_refetch_excp_o),
            .pc_pro_o              (idu_pc_pro_o),
            .wbu_refetch_flush     (wbu_wbu_refetch_flush),
            .bus_csr_rd_wr_data    (idu_bus_csr_rd_wr_data)
        );

    EXU #(TLBNUM) exu(
            // 时钟和复位
            .clk(aclk),
            .rst(reset),

            // 异常处理
            .ds_excp(idu_ds_excp_out),
            .ds_excp_num(idu_ds_excp_num_out),
            .es_excp_out(exu_es_excp_out),
            .es_excp_num_out(exu_es_excp_num_out),

            // 数据总线
            .bus_ds_to_es_data(idu_bus_ds_to_es_data),
            .inst_data_i(idu_idu_inst_o),
            .inst_data_o(exu_inst_data_o),
            .bus_exu_to_mem_data(exu_bus_exu_to_mem_data),

            // 存储器操作
            .in_mem_op(idu_out_mem_op),

            // SRAM接口
            .req(data_sram_req),
            .wr(data_sram_wr),
            .size(data_sram_size),
            .wstrb(data_sram_wstrb),
            .addr(data_sram_addr),
            .wdata(data_sram_wdata),
            .addr_ok(data_sram_addr_ok),
            .data_ok(data_sram_data_ok),
            .rdata(data_sram_rdata),
            .rdata_o(exu_rdata_o),

            // 旁路数据
            .bus_exu_bypass_data(exu_bus_exu_bypass_data),
            .out_mem_op(exu_out_mem_op),
            .out_mem_mask(exu_out_mem_mask),

            // 控制信号
            .flush(wbu_flush),
            .mem_excp(mem_mem_excp),
            .exu_excp(exu_exu_excp),
            .mem_in_is_ertn(mem_is_ertn),
            .exu_is_ertn(exu_exu_is_etrn),

            // 流水线控制
            .up_valid(idu_state_valid),
            .state_valid(exu_state_valid),
            .waite_ready_i(mem_waite_ready_o),
            .waite_ready_o(exu_waite_ready_o),

            // TLB指令总线
            .tlb_inst_bus(idu_tlb_inst_bus),
            .tlb_inst_bus_o(exu_tlb_inst_bus_o),

            // CSR寄存器输入
            .csr_plv(csr_plv_out),
            .csr_dmw0(csr_dmw0_out),
            .csr_dmw1(csr_dmw1_out),
            .csr_da(csr_da_out),
            .csr_pg(csr_pg_out),
            .csr_tlbidx(csr_tlbidx_out),
            .csr_tlbehi(csr_tlbehi_out),
            .csr_tlbelo0(csr_tlbelo0_out),
            .csr_tlbelo1(csr_tlbelo1_out),
            .csr_vppn(csr_vppn_out),
            .csr_asid(csr_asid_out),
            .ds_llbit(csr_llbit_out),

            // 地址转换接口
            .data_addr_trans_en(exu_data_addr_trans_en),
            .data_asid(exu_data_asid),
            .data_vaddr(exu_data_vaddr),
            .data_dmw0_en(exu_data_dmw0_en),
            .data_dmw1_en(exu_data_dmw1_en),
            .data_dmw0(exu_data_dmw0),
            .data_dmw1(exu_data_dmw1),
            .data_da(exu_data_da),
            .data_pg(exu_data_pg),

            .data_index(trans_data_index),
            .data_tag(trans_data_tag),
            .data_offset(trans_data_offset),
            .data_tlb_found(trans_data_tlb_found),
            .data_tlb_index(trans_data_tlb_index),
            .data_tlb_v(trans_data_tlb_v),
            .data_tlb_d(trans_data_tlb_d),
            .data_tlb_mat(trans_data_tlb_mat),
            .data_tlb_plv(trans_data_tlb_plv),

            // TLB搜索
            .tlbsrch_index(exu_tlbsrch_index),
            .tlbsrch_found(exu_tlbsrch_found),

            // TLB无效化
            .invtlb_op_i(idu_invtlb_op),
            .invtlb_asid_i(idu_invtlb_asid),
            .invtlb_vpn_i(idu_invtlb_vpn),
            .invtlb_op_o(exu_invtlb_op_o),
            .invtlb_asid_o(exu_invtlb_asid_o),
            .invtlb_vpn_o(exu_invtlb_vpn_o),

            // CSR写控制
            .is_csr_wr_i(idu_is_csr_wr),
            .is_csr_wr_o(exu_is_csr_wr_o),

            // 重取指令
            .wbu_refetch_sign_i(wbu_is_refetch_sign),
            .refetch_excp_i(idu_refetch_excp_o),
            .refetch_excp_o(exu_refetch_excp_o),
            .pc_pro_i(idu_pc_pro_o),
            .pc_pro_o(exu_pc_pro_o),
            .wbu_refetch_flush(wbu_wbu_refetch_flush),
            .bus_csr_rd_wr_data_i(idu_bus_csr_rd_wr_data),
            .bus_csr_rd_wr_data_o(exu_bus_csr_rd_wr_data_o),
            .paddr(exu_paddr),
            .lladdr(csr_lladdr_out)
        );
    MEM #(TLBNUM) mem(
            // 时钟和复位
            .clk(aclk),
            .rst(reset),

            // 异常处理
            .es_excp(exu_es_excp_out),
            .es_excp_num(exu_es_excp_num_out),
            .ms_excp_out(mem_ms_excp_out),
            .ms_excp_num_out(mem_ms_excp_num_out),

            // 存储器操作
            .in_mem_op(exu_out_mem_op),
            .in_mem_mask(exu_out_mem_mask),

            // 数据总线
            .bus_exu_to_mem_data(exu_bus_exu_to_mem_data),
            .inst_data_i(exu_inst_data_o),
            .inst_data_o(mem_inst_data_o),
            .bus_mem_to_wbu_data(mem_bus_mem_to_wbu_data),
            .data_sram_rdata(exu_rdata_o),
            .bus_mem_bypass_data(mem_bus_mem_bypass_data),

            // 控制信号
            .flush(wbu_flush),
            .wbu_in_is_ertn(wbu_is_ertn),
            .mem_excp(mem_mem_excp),
            .is_ertn(mem_is_ertn),

            // 流水线控制
            .up_valid(exu_state_valid),
            .state_valid(mem_state_valid),
            .waite_ready_i(wbu_waite_ready_o),
            .waite_ready_o(mem_waite_ready_o),

            // TLB指令总线
            .tlb_inst_bus(exu_tlb_inst_bus_o),
            .tlb_inst_bus_o(mem_tlb_inst_bus_o),

            // TLB搜索
            .tlbsrch_index(exu_tlbsrch_index),
            .tlbsrch_found(exu_tlbsrch_found),
            .tlbsrch_index_o(mem_tlbsrch_index_o),
            .tlbsrch_found_o(mem_tlbsrch_found_o),

            // TLB无效化
            .invtlb_op_i(exu_invtlb_op_o),
            .invtlb_asid_i(exu_invtlb_asid_o),
            .invtlb_vpn_i(exu_invtlb_vpn_o),
            .invtlb_op_o(mem_invtlb_op_o),
            .invtlb_asid_o(mem_invtlb_asid_o),
            .invtlb_vpn_o(mem_invtlb_vpn_o),

            // CSR写控制
            .timer_64              (csr_timer_64_out),
            .csr_tid               (csr_tid_out),
            .is_csr_wr_i(exu_is_csr_wr_o),
            .is_csr_wr_o(mem_is_csr_wr_o),

            // 重取指令
            .wbu_refetch_sign_i(wbu_is_refetch_sign),
            .refetch_excp_i(exu_refetch_excp_o),
            .refetch_excp_o(mem_refetch_excp_o),
            .pc_pro_i(exu_pc_pro_o),
            .pc_pro_o(mem_pc_pro_o),
            .wbu_refetch_flush(wbu_wbu_refetch_flush),
            .rd_csr_addr           (idu_rd_csr_addr),
            .rd_csr_data           (csr_rd_data),
            .bus_csr_rd_wr_data_i(exu_bus_csr_rd_wr_data_o),
            .ll_sc(mem_ll_sc),
            .paddr_i(exu_paddr),
            .paddr_o(mem_paddr_o)
        );

    WBU #(TLBNUM) wbu(
            // 时钟和复位
            .clk(aclk),
            .rst(reset),

            // 数据总线
            .bus_mem_to_wbu_data(mem_bus_mem_to_wbu_data),
            .inst_data_i(mem_inst_data_o),

            // 异常处理
            .ms_excp(mem_ms_excp_out),
            .ms_excp_num(mem_ms_excp_num_out),

            // 寄存器文件写接口
            .rf_we(wbu_rf_we),
            .rf_waddr(wbu_rf_waddr),
            .rf_wdata(wbu_rf_wdata),
            .pc(wbu_pc),

            // 旁路数据
            .bus_wbu_bypass_data(wbu_bus_wbu_bypass_data),
            .bus_wub_to_csr_data(wbu_bus_wbu_to_csr_data),

            // 控制信号
            .flush(wbu_flush),
            .is_ertn(wbu_is_ertn),

            // 流水线控制
            .up_valid(mem_state_valid),
            .waite_ready_o(wbu_waite_ready_o),

            // TLB指令总线
            .tlb_inst_bus(mem_tlb_inst_bus_o),

            // CSR寄存器输入
            .csr_tlbidx(csr_tlbidx_out),
            .csr_tlbehi(csr_tlbehi_out),
            .csr_tlbelo0(csr_tlbelo0_out),
            .csr_tlbelo1(csr_tlbelo1_out),
            .csr_rand_index(csr_rand_index),
            .csr_asid(csr_asid_out),
            .csr_ecode_i(csr_ecode_out),

            // TLB搜索
            .tlbsrch_en(wbu_tlbsrch_en),
            .tlbsrch_index(mem_tlbsrch_index_o),
            .tlbsrch_found(mem_tlbsrch_found_o),
            .tlbsrch_found_o(wbu_tlbsrch_found_o),
            .tlbsrch_index_o(wbu_tlbsrch_index_o),

            // TLB读取
            .to_trans_tlbidx_o(wbu_to_trans_tlbidx_o),
            .from_trans_tlbehi_in(trans_tlbehi_out),
            .from_trans_tlbelo0_in(trans_tlbelo0_out),
            .from_trans_tlbelo1_in(trans_tlbelo1_out),
            .from_trans_tlbidx_in(trans_tlbidx_out),
            .from_trans_asid_in(trans_asid_out),
            .csr_tlbrd_en_o(wbu_csr_tlbrd_en_o),
            .csr_tlbehi_o(wbu_csr_tlbehi_o),
            .csr_tlbelo0_o(wbu_csr_tlbelo0_o),
            .csr_tlbelo1_o(wbu_csr_tlbelo1_o),
            .csr_tlbidx_o(wbu_csr_tlbidx_o),
            .csr_asid_o(wbu_csr_asid_o),

            // TLB写入
            .tlbwr_en_o(wbu_tlbwr_en_o),
            .tlbwr_fill_tlbehi_o(wbu_tlbwr_fill_tlbehi_o),
            .tlbwr_fill_tlbelo0_o(wbu_tlbwr_fill_tlbelo0_o),
            .tlbwr_fill_tlbelo1_o(wbu_tlbwr_fill_tlbelo1_o),
            .tlbwr_fill_tlbidx_o(wbu_tlbwr_fill_tlbidx_o),
            .tlbwr_fill_ecode_o(wbu_tlbwr_fill_ecode_o),
            .tlbwr_fill_w_asid_o(wbu_tlbwr_fill_w_asid_o),

            // TLB填充
            .tlbfill_en_o(wbu_tlbfill_en_o),
            .rand_index_o(wbu_rand_index_o),

            // TLB无效化
            .invtlb_op_i(mem_invtlb_op_o),
            .invtlb_asid_i(mem_invtlb_asid_o),
            .invtlb_vpn_i(mem_invtlb_vpn_o),
            .invtlb_op_o(wbu_invtlb_op_o),
            .invtlb_asid_o(wbu_invtlb_asid_o),
            .invtlb_vpn_o(wbu_invtlb_vpn_o),
            .invtlb_en_o(wbu_invtlb_en_o),

            // 调试接口
            .inst_data_o(wbu_inst_data_o),
            .is_csr_wr_i(mem_is_csr_wr_o),
            .is_csr_wr_o(debug_wb_is_csr_wr_o),
            .has_refetch_excp_o(debug_has_refetch_excp_o),

            // 重取指令
            .is_refetch_sign(wbu_is_refetch_sign),
            .refetch_excp_i(mem_refetch_excp_o),
            .refetch_pc(wbu_refetch_pc),
            .refetch_sign(wbu_refetch_sign),
            .pc_pro_i(mem_pc_pro_o),
            .refetch_flush(wbu_wbu_refetch_flush),
            .excp_tlbrefill_o(wbu_excp_tlbrefill_o),

            .ws_llbit_set(wbu_ws_llbit_set),
            .ws_llbit    (wbu_ws_llbit),
            .ws_lladdr_set(wbu_ws_lladdr_set),
            .ws_lladdr    (wbu_ws_lladdr),
            .ll_sc_i      (mem_ll_sc),
            .paddr_i      (mem_paddr_o)
        );

    csr #(TLBNUM)csr_o(
            // 时钟和复位
            .clk(aclk),
            .rst(reset),

            // 读接口
            .rd_addr(idu_rd_csr_addr),
            .rd_data(csr_rd_data),

            // 中断和定时器
            .interuption(intrpt),
            .timer_64_out(csr_timer_64_out),
            .tid_out(csr_tid_out),

            // 数据总线
            .bus_wbu_to_csr_data(wbu_bus_wbu_to_csr_data),
            .flush(wbu_flush),
            .has_int(csr_has_int),

            // 异常处理输出
            .era_out(csr_era_out),
            .eentry_out(csr_eentry_out),
            .tlbrentry_out(csr_tlbrentry_out),
            .plv_out(csr_plv_out),

            .llbit_in(wbu_ws_llbit),
            .llbit_set_in(wbu_ws_llbit_set),
            .lladdr_in(wbu_ws_lladdr),
            .lladdr_set_in(wbu_ws_lladdr_set),
            .llbit_out(csr_llbit_out),
            .lladdr_out(csr_lladdr_out),
            
            // TLB读取接口
            .tlbrd_en(wbu_csr_tlbrd_en_o),
            .tlbehi_in(wbu_csr_tlbehi_o),
            .tlbelo0_in(wbu_csr_tlbelo0_o),
            .tlbelo1_in(wbu_csr_tlbelo1_o),
            .tlbidx_in(wbu_csr_tlbidx_o),
            .asid_in(wbu_csr_asid_o),

            // TLB搜索接口
            .tlbsrch_en(wbu_tlbsrch_en),
            .tlbsrch_found(wbu_tlbsrch_found_o),
            .tlbsrch_index(wbu_tlbsrch_index_o),

            // CSR寄存器输出
            .asid_out(csr_asid_out),
            .vppn_out(csr_vppn_out),
            .tlbehi_out(csr_tlbehi_out),
            .tlbelo0_out(csr_tlbelo0_out),
            .tlbelo1_out(csr_tlbelo1_out),
            .tlbidx_out(csr_tlbidx_out),
            .pg_out(csr_pg_out),
            .da_out(csr_da_out),
            .dmw0_out(csr_dmw0_out),
            .dmw1_out(csr_dmw1_out),
            .datf_out(csr_datf_out),
            .datm_out(csr_datm_out),
            .ecode_out(csr_ecode_out),
            .rand_index(csr_rand_index),

            // 差异比较信号
            .csr_crmd_diff(csr_crmd_diff),
            .csr_prmd_diff(csr_prmd_diff),
            .csr_ecfg_diff(csr_ecfg_diff),
            .csr_estat_diff(csr_estat_diff),
            .csr_era_diff(csr_era_diff),
            .csr_badv_diff(csr_badv_diff),
            .csr_eentry_diff(csr_eentry_diff),
            .csr_tlbidx_diff(csr_tlbidx_diff),
            .csr_tlbehi_diff(csr_tlbehi_diff),
            .csr_tlbelo0_diff(csr_tlbelo0_diff),
            .csr_tlbelo1_diff(csr_tlbelo1_diff),
            .csr_asid_diff(csr_asid_diff),
            .csr_save0_diff(csr_save0_diff),
            .csr_save1_diff(csr_save1_diff),
            .csr_save2_diff(csr_save2_diff),
            .csr_save3_diff(csr_save3_diff),
            .csr_tid_diff(csr_tid_diff),
            .csr_tcfg_diff(csr_tcfg_diff),
            .csr_tval_diff(csr_tval_diff),
            .csr_ticlr_diff(csr_ticlr_diff),
            .csr_llbctl_diff(csr_llbctl_diff),
            .csr_tlbrentry_diff(csr_tlbrentry_diff),
            .csr_dmw0_diff(csr_dmw0_diff),
            .csr_dmw1_diff(csr_dmw1_diff),
            .csr_pgdl_diff(csr_pgdl_diff),
            .csr_pgdh_diff(csr_pgdh_diff)
        );
    addr_trans #(TLBNUM) addr_trans_o(
                   .clk(aclk),

                   // 指令地址转换
                   .inst_addr_trans_en(ifu_inst_addr_trans_en),
                   .inst_asid(ifu_inst_asid),
                   .inst_vaddr(ifu_inst_vaddr),
                   .inst_dmw0_en(ifu_inst_dmw0_en),
                   .inst_dmw1_en(ifu_inst_dmw1_en),
                   .inst_dmw0(ifu_inst_dmw0),
                   .inst_dmw1(ifu_inst_dmw1),
                   .inst_da(ifu_inst_da),
                   .inst_pg(ifu_inst_pg),

                   .inst_index(trans_inst_index),
                   .inst_tag(trans_inst_tag),
                   .inst_offset(trans_inst_offset),
                   .inst_tlb_found(trans_inst_tlb_found),
                   .inst_tlb_v(trans_inst_tlb_v),
                   .inst_tlb_d(trans_inst_tlb_d),
                   .inst_tlb_mat(trans_inst_tlb_mat),
                   .inst_tlb_plv(trans_inst_tlb_plv),

                   // 数据地址转换
                   .data_addr_trans_en(exu_data_addr_trans_en),
                   .data_asid(exu_data_asid),
                   .data_vaddr(exu_data_vaddr),
                   .data_dmw0_en(exu_data_dmw0_en),
                   .data_dmw1_en(exu_data_dmw1_en),
                   .data_dmw0(exu_data_dmw0),
                   .data_dmw1(exu_data_dmw1),
                   .data_da(exu_data_da),
                   .data_pg(exu_data_pg),

                   .data_index(trans_data_index),
                   .data_tag(trans_data_tag),
                   .data_offset(trans_data_offset),
                   .data_tlb_found(trans_data_tlb_found),
                   .data_tlb_index(trans_data_tlb_index),
                   .data_tlb_v(trans_data_tlb_v),
                   .data_tlb_d(trans_data_tlb_d),
                   .data_tlb_mat(trans_data_tlb_mat),
                   .data_tlb_plv(trans_data_tlb_plv),

                   // TLB填充和写入
                   .tlbfill_en(wbu_tlbfill_en_o),
                   .tlbwr_en(wbu_tlbwr_en_o),
                   .w_asid(wbu_tlbwr_fill_w_asid_o),
                   .rand_index(wbu_rand_index_o),
                   .tlbehi_in(wbu_tlbwr_fill_tlbehi_o),
                   .tlbelo0_in(wbu_tlbwr_fill_tlbelo0_o),
                   .tlbelo1_in(wbu_tlbwr_fill_tlbelo1_o),
                   .tlbidx_in(wbu_tlbwr_fill_tlbidx_o),
                   .ecode_in(wbu_tlbwr_fill_ecode_o),

                   // TLB读取
                   .tlbehi_out(trans_tlbehi_out),
                   .tlbelo0_out(trans_tlbelo0_out),
                   .tlbelo1_out(trans_tlbelo1_out),
                   .tlbidx_out(trans_tlbidx_out),
                   .asid_out(trans_asid_out),

                   // TLB无效化
                   .invtlb_valid(wbu_invtlb_en_o),
                   .invtlb_op(wbu_invtlb_op_o),
                   .invtlb_asid(wbu_invtlb_asid_o),
                   .invtlb_vpn(wbu_invtlb_vpn_o)
               );

    cache icache(
              .clk(aclk),
              .resetn(aresetn),
              // ifu
              .flush_sign_cancel(ifu_flush_sign_cancel),
              .valid(ifu_icache_valid),
              .op(ifu_icache_op),
              .tag(ifu_icache_tag),
              .index(ifu_icache_index),
              .offset(ifu_icache_offset),
              .wstrb(ifu_icache_wstrb),
              .wdata(ifu_icache_wdata),

              .addr_ok(icache_addr_ok),
              .data_ok(icache_data_ok),
              .rdata(icache_rdata),
              // axi
              .rd_req(icache_rd_req),
              .rd_type(icache_rd_type),
              .rd_addr(icache_rd_addr),
              .rd_rdy(icache_rd_rdy),
              .ret_valid(icache_ret_valid),
              .ret_last(icache_ret_last),
              .ret_data(icache_ret_data),


              .wr_req(icache_wr_req),
              .wr_type(icache_wr_type),
              .wr_addr(icache_wr_addr),
              .wr_wstrb(icache_wr_wstrb),
              .wr_data(icache_wr_data),
              .wr_rdy(icache_wr_rdy)
          );
    // 后期的工作，应该在 MEM 中发起内存访问
    // 因此d cache 的访问接口应该放在 MEM 中
    // cache dcache(
    //           .clk(aclk),
    //           .resetn(aresetn),
    //           // ifu
    //           .flush_sign_cancel(ifu_flush_sign_cancel),
    //           .valid(ifu_icache_valid),
    //           .op(ifu_icache_op),
    //           .tag(ifu_icache_tag),
    //           .index(ifu_icache_index),
    //           .offset(ifu_icache_offset),
    //           .wstrb(ifu_icache_wstrb),
    //           .wdata(ifu_icache_wdata),

    //           .addr_ok(icache_addr_ok),
    //           .data_ok(icache_data_ok),
    //           .rdata(icache_rdata),
    //           // axi
    //           .rd_req(icache_rd_req),
    //           .rd_type(icache_rd_type),
    //           .rd_addr(icache_rd_addr),
    //           .rd_rdy(icache_rd_rdy),
    //           .ret_valid(icache_ret_valid),
    //           .ret_last(icache_ret_last),
    //           .ret_data(icache_ret_data),


    //           .wr_req(icache_wr_req),
    //           .wr_type(icache_wr_type),
    //           .wr_addr(icache_wr_addr),
    //           .wr_wstrb(icache_wr_wstrb),
    //           .wr_data(icache_wr_data),
    //           .wr_rdy(icache_wr_rdy)
    //       );
    assign debug_wb_pc = wbu_pc;
    assign debug_wb_rf_we = {4{wbu_rf_we}};
    assign debug_wb_rf_wnum = wbu_rf_waddr;
    assign debug_wb_rf_wdata = wbu_rf_wdata;
    assign debug_wb_inst = wbu_inst_data_o;

endmodule
