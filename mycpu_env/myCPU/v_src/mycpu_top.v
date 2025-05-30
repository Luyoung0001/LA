module mycpu_top(
        input  wire        aclk,
        input  wire        aresetn,

        // AXI
        // read request
        output   wire [ 3:0] arid,
        output   wire[31:0] araddr,
        output   wire[ 7:0] arlen,
        output   wire[ 2:0] arsize,
        output    wire  [ 1:0] arburst,
        output   wire   [ 1:0] arlock,
        output   wire   [ 3:0] arcache,
        output   wire   [ 2:0] arprot,
        output   wire       arvalid,
        input     wire         arready,

        input  wire  [ 3:0] rid,
        input  wire  [31:0] rdata,
        input  wire  [ 1:0] rresp,
        input   wire        rlast,
        input   wire        rvalid,
        output   wire    rready,

        output   wire   [ 3:0] awid,
        output   wire[31:0] awaddr,
        output   wire[ 7:0] awlen,
        output   wire[ 2:0] awsize,
        output   wire   [ 1:0] awburst,
        output   wire   [ 1:0] awlock,
        output  wire    [ 3:0] awcache,
        output  wire    [ 2:0] awprot,
        output   wire       awvalid,
        input     wire         awready,

        output    wire  [ 3:0] wid,
        output   wire[31:0] wdata,
        output   wire[ 3:0] wstrb,
        output   wire       wlast,
        output   wire       wvalid,
        input     wire         wready,

        input  wire  [ 3:0] bid,
        input   wire [ 1:0] bresp,
        input   wire        bvalid,
        output   wire    bready,

        // trace debug interface
        output wire [31:0] debug_wb_pc,
        output wire [ 3:0] debug_wb_rf_we,
        output wire [ 4:0] debug_wb_rf_wnum,
        output wire [31:0] debug_wb_rf_wdata
    );
    wire [7:0] intrpt;
    assign intrpt = 8'b0;

    wire reset;
    assign reset = ~aresetn;

    // 这里是 Xbar
    // 负责将两个类 SRAM 转成 AXI

    wire inst_sram_req;
    wire inst_sram_wr;
    wire [1:0] inst_sram_size;
    wire [3:0] inst_sram_wstrb;
    wire [31:0] inst_sram_addr;
    wire [31:0] inst_sram_wdata;
    wire inst_sram_addr_ok;
    wire inst_sram_data_ok;
    wire [31:0] inst_sram_rdata;

    wire data_sram_req;
    wire data_sram_wr;
    wire [1:0] data_sram_size;
    wire [3:0] data_sram_wstrb;
    wire [31:0] data_sram_addr;
    wire [31:0] data_sram_wdata;
    wire data_sram_addr_ok;
    wire data_sram_data_ok;
    wire [31:0] data_sram_rdata;

    // AXI-XBar
    sram_like_to_axi_bridge o (
                                .clk(aclk           ),
                                .rst(reset          ),
                                .inst_sram_req (inst_sram_req),
                                .inst_sram_wr (inst_sram_wr),
                                .inst_sram_size (inst_sram_size),
                                .inst_sram_wstrb (inst_sram_wstrb),
                                .inst_sram_addr (inst_sram_addr),
                                .inst_sram_wdata (inst_sram_wdata),
                                .inst_sram_addr_ok (inst_sram_addr_ok),
                                .inst_sram_data_ok (inst_sram_data_ok),
                                .inst_sram_rdata (inst_sram_rdata),

                                .data_sram_req (data_sram_req),
                                .data_sram_wr (data_sram_wr),
                                .data_sram_size (data_sram_size),
                                .data_sram_wstrb (data_sram_wstrb),
                                .data_sram_addr (data_sram_addr),
                                .data_sram_wdata (data_sram_wdata),
                                .data_sram_addr_ok (data_sram_addr_ok),
                                .data_sram_data_ok (data_sram_data_ok),
                                .data_sram_rdata (data_sram_rdata),

                                // AXI
                                .arid           (arid           ),
                                .araddr         (araddr         ),
                                .arlen          (arlen          ),
                                .arsize         (arsize         ),
                                .arburst        (arburst        ),
                                .arlock         (arlock         ),
                                .arcache        (arcache        ),
                                .arprot         (arprot         ),
                                .arvalid        (arvalid        ),
                                .arready        (arready        ),

                                .rid            (rid            ),
                                .rdata          (rdata          ),
                                .rresp          (rresp          ),
                                .rlast          (rlast          ),
                                .rvalid         (rvalid         ),
                                .rready         (rready         ),

                                .awid           (awid           ),
                                .awaddr         (awaddr         ),
                                .awlen          (awlen          ),
                                .awsize         (awsize         ),
                                .awburst        (awburst        ),
                                .awlock         (awlock         ),
                                .awcache        (awcache        ),
                                .awprot         (awprot         ),
                                .awvalid        (awvalid        ),
                                .awready        (awready        ),

                                .wid            (wid            ),
                                .wdata          (wdata          ),
                                .wstrb          (wstrb          ),
                                .wlast          (wlast          ),
                                .wvalid         (wvalid         ),
                                .wready         (wready         ),

                                .bid            (bid            ),
                                .bresp          (bresp          ),
                                .bvalid         (bvalid         ),
                                .bready         (bready         )
                            );




    // pre_IFU
    wire [31:0] preifu_inst_addr;
    wire [31:0] preifu_next_pc;
    wire preifu_pfs_excp_adef;
    wire preifu_pfs_excp;
    wire [31:0] preifu_inst_data;
    wire preifu_rvalid_o;
    wire [31:0] preifu_pc_o;
    wire preifu_pfs_to_fs_valid;
    wire preifu_state_valid;

    // ifu
    wire [31:0] ifu_fs_pc;
    wire ifu_fs_allowin;
    wire ifu_fs_to_ds_valid;

    wire ifu_fs_excp_out;
    wire [15:0] ifu_fs_excp_num_out;
    wire [31:0] ifu_inst_data_o;

    wire ifu_en;
    wire [3:0] ifu_we;
    wire [31:0] ifu_wdata;

    wire [31:0] ifu_rdata_o;

    wire ifu_condition_4;

    wire [31:0] ifu_pc_o;

    wire ifu_state_valid;
    wire ifu_waite_ready_o;
    // tlb
    wire [31:0] ifu_inst_vaddr;
    wire [31:0] ifu_inst_dmw0;
    wire [31:0] ifu_inst_dmw1;
    wire        ifu_inst_da;
    wire        ifu_inst_pg;
    wire        ifu_inst_dmw0_en;
    wire        ifu_inst_dmw1_en;
    wire [7:0]  ifu_inst_index;
    wire [19:0] ifu_inst_tag;
    wire [3:0]  ifu_inst_offset;
    wire        ifu_inst_tlb_found;
    wire        ifu_inst_tlb_v;
    wire [31:0] ifu_inst_tlb_d;
    wire [31:0] ifu_inst_tlb_mat;
    wire [31:0] ifu_inst_tlb_plv;



    // idu
    wire [33:0] idu_bus_br_data;

    wire idu_ds_excp_out;
    wire [15:0] idu_ds_excp_num_out;

    wire [4:0] idu_rf_raddr1;
    wire [4:0] idu_rf_raddr2;

    wire [258:0] idu_bus_ds_to_es_data;
    wire [7:0] idu_out_mem_op;

    wire [13:0] idu_rd_csr_addr;
    wire [31:0] idu_rd_csr_data;

    wire idu_ds_allowin;
    wire idu_ds_to_es_valid;

    wire [31:0] idu_inst_data;

    wire idu_get_inst;
    wire idu_br_taken_o;

    wire idu_waite_ready_o;
    wire idu_state_valid;
    // tlb
    wire [4:0] idu_tlb_inst_bus;
    wire [4:0] idu_invtlb_op;
    wire [9:0] idu_invtlb_asid;
    wire [18:0] idu_invtlb_vpn;

    // exu
    wire exu_es_excp_out;
    wire [15:0] exu_es_excp_num_out;
    wire [150:0] exu_bus_exu_to_mem_data;

    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;

    wire exu_exu_excp;
    wire exe_es_allowin;
    wire exe_es_to_ms_valid;
    wire [85:0] exu_bus_exu_bypass_data;
    wire [7:0] exu_out_mem_op;
    wire [3:0] exu_out_mem_mask;

    wire exu_memory_waite_o;
    wire exu_es_stop;

    wire exu_state_valid;
    wire exu_waite_ready_o;

    wire [31:0] exu_rdata_o;
    wire exu_exu_is_etrn;
    // tlb
    wire [4:0] exu_tlb_inst_bus_o;
    wire [31:0] exu_data_vaddr;
    wire [31:0] exu_data_dmw0;
    wire [31:0] exu_data_dmw1;
    wire exu_data_da;
    wire exu_data_pg;
    wire exu_data_dmw0_en;
    wire exu_data_dmw1_en;

    wire [31:0] exu_tlbidv_o;
    wire [5:0] exu_tlbsrch_index;
    wire exu_tlbsrch_found;
    wire [31:0] exu_tlbehi_o;
    wire [31:0] exu_tlbelo0_o;
    wire [31:0] exu_tlbelo1_o;
    wire [31:0] exu_tlbidx_o;

    wire [31:0] exu_tlbwr_fill_tlbehi_o1;
    wire [31:0] exu_tlbwr_fill_tlbelo0_o1;
    wire [31:0] exu_tlbwr_fill_tlbelo1_o1;
    wire [31:0] exu_tlbwr_fill_tlbidx_o1;

    wire [4:0] exu_invtlb_op_o;
    wire [9:0] exu_invtlb_asid_o;
    wire [18:0] exu_invtlb_vpn_o;


    // mem

    wire mem_ms_excp_out;
    wire [15:0] mem_ms_excp_num_out;
    wire [149:0] mem_bus_mem_to_wbu_data;
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    wire mem_ms_allowin;
    wire mem_ms_to_ws_valid;

    wire [85:0] mem_bus_mem_bypass_data;

    wire mem_mem_excp;
    wire mem_is_ertn;

    wire mem_state_valid;
    wire mem_waite_ready_o;

    // tlb
    wire [4:0] mem_tlb_inst_bus_o;

    wire [5:0] mem_tlbsrch_index_o;
    wire mem_tlbsrch_found_o;

    wire [31:0] mem_tlbehi_o;
    wire [31:0] mem_tlbelo0_o;
    wire [31:0] mem_tlbelo1_o;
    wire [31:0] mem_tlbidx_o;

    wire [31:0] mem_tlbwr_fill_tlbehi_o;
    wire [31:0] mem_tlbwr_fill_tlbelo0_o;
    wire [31:0] mem_tlbwr_fill_tlbelo1_o;
    wire [31:0] mem_tlbwr_fill_tlbidx_o;

    wire [4:0] mem_invtlb_op_o;
    wire [9:0] mem_invtlb_asid_o;
    wire [18:0] mem_invtlb_vpn_o;

    // wbu
    wire        wbu_rf_we;
    wire [4:0]  wbu_rf_waddr;
    wire [31:0] wbu_rf_wdata;
    wire [31:0] wbu_pc;

    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    wire wbu_ws_allowin;

    wire [85:0] wbu_bus_wbu_bypass_data;

    wire wbu_csr_we;
    wire [13:0] wbu_csr_addr;
    wire [31:0] wbu_csr_wdata;

    wire [5:0] wbu_csr_ecode;
    wire wbu_va_error;
    wire [31:0] wbu_bad_va;
    wire [8:0] wbu_csr_esubcode;
    wire wbu_excp_tlbrefill;
    wire wbu_excp_tlb;
    wire [18:0] wbu_excp_tlb_vppn;

    wire [147:0] wbu_bus_wbu_to_csr_data;

    wire [1:0] wbu_flush;

    wire [31:0] wbu_csr_era;

    wire wbu_is_ertn;
    wire wbu_waite_ready_o;

    // tlb
    wire wbu_tlbsrch_en;
    wire wbu_tlbsrch_found_o;
    wire [5:0] wbu_tlbsrch_index_o;

    wire wbu_tlbrd_en;
    wire [31:0] wbu_tlbehi_o;
    wire [31:0] wbu_tlbelo0_o;
    wire [31:0] wbu_tlbelo1_o;
    wire [31:0] wbu_tlbidx_o;

    wire [31:0] wbu_tlbwr_fill_tlbehi_o;
    wire [31:0] wbu_tlbwr_fill_tlbelo0_o;
    wire [31:0] wbu_tlbwr_fill_tlbelo1_o;
    wire [31:0] wbu_tlbwr_fill_tlbidx_o;
    wire wbu_tlbwr_en_o;

    wire wbu_tlbfill_en_o;
    wire [5:0] wbu_rand_index_o;

    wire [4:0] wbu_invtlb_op_o;
    wire [9:0] wbu_invtlb_asid_o;
    wire [18:0] wbu_invtlb_vpn_o;
    wire wbu_invtlb_en_o;

    //  regfile
    wire [31:0] rf_rdata1;
    wire [31:0] rf_rdata2;

    // csr
    wire [31:0] csr_rd_data;
    wire [31:0] csr_era_out;
    wire [31:0] csr_eentry_out;
    wire [63:0] csr_timer_64_out;
    wire [31:0] csr_tid_out;
    wire csr_has_int;

    wire [1:0] csr_plv_out;

    wire [9:0]  csr_asid_out;
    wire [18:0] csr_vppn_out;
    wire [31:0] csr_tlbehi_out;
    wire [31:0] csr_tlbelo0_out;
    wire [31:0] csr_tlbelo1_out;
    wire [31:0] csr_tlbidx_out;
    wire [5:0]  csr_rand_index;

    wire        csr_pg_out;
    wire        csr_da_out;
    wire [31:0] csr_dmw0_out;
    wire [31:0] csr_dmw1_out;
    wire [1:0]  csr_datf_out;
    wire [1:0]  csr_datm_out;
    wire [5:0]  csr_ecode_out;
    wire [5:0]  csr_rand_index;


    pre_IFU pre_ifu(
                .clk (aclk),
                .rst (reset),
                .bus_br_data (idu_bus_br_data),
                .pc_o(preifu_pc_o),
                .flush     (wbu_flush),
                .csr_era    (csr_era_out),
                .csr_eentry (csr_eentry_out),
                .waite_ready_i(ifu_waite_ready_o),
                .state_valid(preifu_state_valid)
            );


    // ifu
    IFU ifu(
            .clk        (aclk),
            .rst        (reset),

            .pc_i       (preifu_pc_o),
            .pc_o       (ifu_pc_o),

            .fs_excp_out (ifu_fs_excp_out),
            .fs_excp_num_out(ifu_fs_excp_num_out),

            .flush     (wbu_flush),

            .up_valid (preifu_state_valid),
            .state_valid (ifu_state_valid),

            .waite_ready_i(idu_waite_ready_o),
            .waite_ready_o(ifu_waite_ready_o),

            // from csr
            .csr_plv(csr_plv_out),
            

            // tlb

            // like SRAM
            .req (inst_sram_req),
            .wr  (inst_sram_wr),
            .size(inst_sram_size),
            .wstrb(inst_sram_wstrb),
            .addr(inst_sram_addr),
            .wdata(inst_sram_wdata),
            .addr_ok(inst_sram_addr_ok),
            .data_ok(inst_sram_data_ok),
            .rdata(inst_sram_rdata),
            .rdata_o(ifu_rdata_o)


        );

    // regfile
    regfile u_regfile(
                .clk        (aclk),

                .raddr1     (idu_rf_raddr1),
                .raddr2     (idu_rf_raddr2),
                .rdata1     (rf_rdata1),
                .rdata2     (rf_rdata2),
                .we         (wbu_rf_we),
                .waddr      (wbu_rf_waddr),
                .wdata      (wbu_rf_wdata)
            );

    // idu

    IDU idu(
            .clk        (aclk),
            .rst        (reset),

            // to pre_IFU
            .bus_br_data(idu_bus_br_data),

            // from ifu
            .in_pc         (ifu_pc_o),
            .in_rdata      (ifu_rdata_o),

            .fs_excp (ifu_fs_excp_out),
            .fs_excp_num(ifu_fs_excp_num_out),

            .ds_excp_out (idu_ds_excp_out),
            .ds_excp_num_out(idu_ds_excp_num_out),

            // to rf
            .rf_raddr1  (idu_rf_raddr1),
            .rf_raddr2  (idu_rf_raddr2),

            // from rf
            .rf_rdata1  (rf_rdata1),
            .rf_rdata2  (rf_rdata2),

            // from inst_ram
            .bus_ds_to_es_data(idu_bus_ds_to_es_data),
            .out_mem_op       (idu_out_mem_op),

            .rd_csr_addr      (idu_rd_csr_addr),
            .rd_csr_data       (csr_rd_data),

            // timer
            .timer_64(csr_timer_64_out),
            .csr_tid(csr_tid_out),

            .flush     (wbu_flush),
            .exu_excp      (exu_exu_excp),
            .exu_is_ertn_i (exu_exu_is_etrn),
            .has_int(csr_has_int),
            // 直通解决数据相关
            .bus_exu_bypass_data(exu_bus_exu_bypass_data),
            .bus_mem_bypass_data(mem_bus_mem_bypass_data),
            .bus_wbu_bypass_data(wbu_bus_wbu_bypass_data),

            .up_valid(ifu_state_valid),
            .state_valid(idu_state_valid),
            .waite_ready_i(exu_waite_ready_o),
            .waite_ready_o(idu_waite_ready_o)
        );



    // exu
    EXU exu(
            .clk        (aclk),
            .rst        (reset),

            .ds_excp (idu_ds_excp_out),
            .ds_excp_num (idu_ds_excp_num_out),
            .es_excp_out (exu_es_excp_out),
            .es_excp_num_out (exu_es_excp_num_out),

            .bus_ds_to_es_data(idu_bus_ds_to_es_data),
            .bus_exu_to_mem_data(exu_bus_exu_to_mem_data),

            .in_mem_op(idu_out_mem_op),


            .req(data_sram_req),
            .wr(data_sram_wr),
            .size(data_sram_size),
            .wstrb(data_sram_wstrb),
            .addr(data_sram_addr),
            .wdata(data_sram_wdata),
            .addr_ok(data_sram_addr_ok),
            .data_ok(data_sram_data_ok),
            .rdata (data_sram_rdata),
            .rdata_o(exu_rdata_o),


            //  bus
            .bus_exu_bypass_data(exu_bus_exu_bypass_data),
            .out_mem_op(exu_out_mem_op),
            .out_mem_mask(exu_out_mem_mask),

            .flush     (wbu_flush),
            .mem_excp (mem_mem_excp),
            .exu_excp (exu_exu_excp),
            .mem_in_is_ertn(mem_is_ertn),
            .exu_is_ertn(exu_exu_is_etrn), // 传给 idu

            .up_valid(idu_state_valid),
            .state_valid(exu_state_valid),
            .waite_ready_i(mem_waite_ready_o),
            .waite_ready_o(exu_waite_ready_o)

        );

    // mem

    MEM mem(
            .clk        (aclk),
            .rst        (reset),

            .es_excp (exu_es_excp_out),
            .es_excp_num (exu_es_excp_num_out),

            .ms_excp_out (mem_ms_excp_out),
            .ms_excp_num_out (mem_ms_excp_num_out),

            .in_mem_op  (exu_out_mem_op),
            .in_mem_mask(exu_out_mem_mask),
            .bus_exu_to_mem_data(exu_bus_exu_to_mem_data),
            .bus_mem_to_wbu_data(mem_bus_mem_to_wbu_data),
            // from mem_sram
            .data_sram_rdata(exu_rdata_o),
            .bus_mem_bypass_data(mem_bus_mem_bypass_data),

            .flush     (wbu_flush),

            .wbu_in_is_ertn(wbu_is_ertn),
            .mem_excp(mem_mem_excp),
            .is_ertn (mem_is_ertn),

            .up_valid(exu_state_valid),
            .state_valid(mem_state_valid),
            .waite_ready_i(wbu_waite_ready_o),
            .waite_ready_o(mem_waite_ready_o)
        );

    // wbu

    WBU wbu(
            .clk        (aclk),
            .rst        (reset),

            .bus_mem_to_wbu_data(mem_bus_mem_to_wbu_data),

            .ms_excp(mem_ms_excp_out),
            .ms_excp_num(mem_ms_excp_num_out),

            // to rf
            .rf_we      (wbu_rf_we),
            .rf_waddr   (wbu_rf_waddr),
            .rf_wdata   (wbu_rf_wdata),
            .pc         (wbu_pc),
            // 数据相关
            .bus_wbu_bypass_data(wbu_bus_wbu_bypass_data),

            .bus_wub_to_csr_data(wbu_bus_wbu_to_csr_data),
            .is_ertn    (wbu_is_ertn),
            .flush     (wbu_flush),

            .up_valid(mem_state_valid),
            .waite_ready_o(wbu_waite_ready_o)
        );

    csr csr_o(
            .clk        (aclk),
            .rst      (reset),
            //from ds for read
            .rd_addr    (idu_rd_csr_addr),
            .rd_data    (csr_rd_data),
            .interuption (intrpt),
            .timer_64_out(csr_timer_64_out),
            .tid_out(csr_tid_out),
            .bus_wbu_to_csr_data(wbu_bus_wbu_to_csr_data),
            .flush     (wbu_flush),
            .has_int(csr_has_int),

            // to ifu
            .era_out    (csr_era_out),
            .eentry_out (csr_eentry_out)
        );

    // debug info generate
    assign debug_wb_pc       = wbu_pc;
    assign debug_wb_rf_we   = {4{wbu_rf_we}};
    assign debug_wb_rf_wnum  = wbu_rf_waddr;
    assign debug_wb_rf_wdata = wbu_rf_wdata;


endmodule
