module cpu_top(
        input  wire        clk,
        input  wire        resetn,

        // AXI
        // read request
        // output   reg[ 3:0] arid,
        // output   reg[31:0] araddr,
        // output   reg[ 7:0] arlen,
        // output   reg[ 2:0] arsize,
        // output      [ 1:0] arburst,
        // output      [ 1:0] arlock,
        // output      [ 3:0] arcache,
        // output      [ 2:0] arprot,
        // output   reg       arvalid,
        // input              arready,

        // input    [ 3:0] rid,
        // input    [31:0] rdata,
        // input    [ 1:0] rresp,
        // input           rlast,
        // input           rvalid,
        // output   reg    rready,

        // output      [ 3:0] awid,
        // output   reg[31:0] awaddr,
        // output   reg[ 7:0] awlen,
        // output   reg[ 2:0] awsize,
        // output      [ 1:0] awburst,
        // output      [ 1:0] awlock,
        // output      [ 3:0] awcache,
        // output      [ 2:0] awprot,
        // output   reg       awvalid,
        // input              awready,

        // output      [ 3:0] wid,
        // output   reg[31:0] wdata,
        // output   reg[ 3:0] wstrb,
        // output   reg       wlast,
        // output   reg       wvalid,
        // input              wready,

        // input    [ 3:0] bid,
        // input    [ 1:0] bresp,
        // input           bvalid,
        // output   reg    bready,

        // inst sram interface
        // output wire        inst_sram_en,
        // output wire [3:0]  inst_sram_we,
        // output wire [31:0] inst_sram_addr,
        // output wire [31:0] inst_sram_wdata,
        // input  wire [31:0] inst_sram_rdata,

        output inst_sram_req,
        output inst_sram_wr,
        output [1:0] inst_sram_size,
        output wire [3:0] inst_sram_wstrb,
        output wire [31:0] inst_sram_addr,
        output wire [31:0] inst_sram_wdata,
        input  wire        inst_sram_addr_ok,
        input  wire        inst_sram_data_ok,
        input  wire [31:0] inst_sram_rdata,


        // data sram interface
        // output wire        data_sram_en,
        // output wire [3:0]  data_sram_we,
        // output wire [31:0] data_sram_addr,
        // output wire [31:0] data_sram_wdata,
        // input  wire [31:0] data_sram_rdata,

        output wire        data_sram_req,
        output wire        data_sram_wr,
        output wire [1:0]  data_sram_size,
        output wire [3:0]  data_sram_wstrb,
        output wire [31:0] data_sram_addr,
        output wire [31:0] data_sram_wdata,
        input  wire        data_sram_addr_ok,
        input  wire        data_sram_data_ok,
        input  wire [31:0] data_sram_rdata,


        // trace debug interface
        output wire [31:0] debug_wb_pc,
        output wire [ 3:0] debug_wb_rf_we,
        output wire [ 4:0] debug_wb_rf_wnum,
        output wire [31:0] debug_wb_rf_wdata
    );


    wire [7:0] intrpt;

    assign intrpt = 8'b0;

    wire reset;
    assign reset = ~resetn;

    // pre_IFU
    wire [31:0] preifu_inst_addr;
    wire [31:0] preifu_next_pc;
    wire preifu_pfs_excp_adef;
    wire preifu_pfs_excp;
    wire [31:0] preifu_inst_data;
    wire preifu_rvalid_o;

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


    // idu
    wire [32:0] idu_bus_br_data;

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
    wire [84:0] exu_bus_exu_bypass_data;
    wire [7:0] exu_out_mem_op;
    wire [3:0] exu_out_mem_mask;

    wire [31:0] exu_rdata_o;
    wire exu_memory_waite_o;

    wire exu_es_stop;

    // mem

    wire mem_ms_excp_out;
    wire [15:0] mem_ms_excp_num_out;
    wire [149:0] mem_bus_mem_to_wbu_data;
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    wire mem_ms_allowin;
    wire mem_ms_to_ws_valid;

    wire [84:0] mem_bus_mem_bypass_data;

    wire mem_mem_excp;
    wire mem_is_ertn;

    // wbu
    wire        wbu_rf_we;
    wire [4:0]  wbu_rf_waddr;
    wire [31:0] wbu_rf_wdata;
    wire [31:0] wbu_pc;

    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    wire wbu_ws_allowin;

    wire [84:0] wbu_bus_wbu_bypass_data;

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


    // ifu
    IFU ifu(
            .clk        (clk),
            .rst        (reset),
            .bus_br_data    (idu_bus_br_data),
            .fs_excp_out (ifu_fs_excp_out),
            .fs_excp_num_out(ifu_fs_excp_num_out),
            .flush     (wbu_flush),
            .csr_era    (csr_era_out),
            .csr_eentry (csr_eentry_out),

            .fs_pc      (ifu_fs_pc),
            .ds_allowin (idu_ds_allowin),
            .fs_to_ds_valid(ifu_fs_to_ds_valid),
            .condition_4 (ifu_condition_4),

            // like SRAM
            .req (inst_sram_req),
            .wr  (inst_sram_wr),
            .size(inst_sram_size),
            .wstrb(inst_sram_wstrb),
            .addr(inst_sram_addr),
            .wdata(inst_sram_wdata),
            .addr_ok(inst_sram_addr_ok),
            .data_ok(inst_sram_data_ok)


        );

    // regfile
    regfile u_regfile(
                .clk        (clk),

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
            .clk        (clk),
            .rst        (reset),

            // to pre_IFU
            .bus_br_data(idu_bus_br_data),

            // from ifu
            .in_pc         (ifu_fs_pc),

            .condition_4 (ifu_condition_4),

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
            .inst_sram_data    (inst_sram_rdata),
            .bus_ds_to_es_data(idu_bus_ds_to_es_data),
            .out_mem_op       (idu_out_mem_op),

            .rd_csr_addr      (idu_rd_csr_addr),
            .rd_csr_data       (csr_rd_data),

            // timer
            .timer_64(csr_timer_64_out),
            .csr_tid(csr_tid_out),

            .flush     (wbu_flush),
            .exu_excp      (exu_exu_excp),
            .has_int(csr_has_int),
            // 直通解决数据相关
            .bus_exu_bypass_data(exu_bus_exu_bypass_data),
            .bus_mem_bypass_data(mem_bus_mem_bypass_data),
            .bus_wbu_bypass_data(wbu_bus_wbu_bypass_data),

            .es_allowin (exe_es_allowin),
            .ds_allowin (idu_ds_allowin),
            .fs_to_ds_valid(ifu_fs_to_ds_valid),
            .ds_to_es_valid(idu_ds_to_es_valid)

        );



    // exu
    EXU exu(
            .clk        (clk),
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


            //  bus
            .bus_exu_bypass_data(exu_bus_exu_bypass_data),
            .out_mem_op(exu_out_mem_op),
            .out_mem_mask(exu_out_mem_mask),

            .flush     (wbu_flush),
            .mem_excp (mem_mem_excp),
            .exu_excp (exu_exu_excp),
            .mem_in_is_ertn(mem_is_ertn),

            .ms_allowin(mem_ms_allowin),
            .es_allowin(exe_es_allowin),
            .ds_to_es_valid(idu_ds_to_es_valid),
            .es_to_ms_valid(exe_es_to_ms_valid)

        );

    // mem

    MEM mem(
            .clk        (clk),
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
            .data_sram_rdata(data_sram_rdata),
            .bus_mem_bypass_data(mem_bus_mem_bypass_data),

            .flush     (wbu_flush),

            .wbu_in_is_ertn(wbu_is_ertn),
            .mem_excp(mem_mem_excp),
            .is_ertn (mem_is_ertn),

            .ws_allowin(wbu_ws_allowin),
            .ms_allowin(mem_ms_allowin),
            .es_to_ms_valid(exe_es_to_ms_valid),
            .ms_to_ws_valid(mem_ms_to_ws_valid)
        );

    // wbu

    WBU wbu(
            .clk        (clk),
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

            .ws_allowin(wbu_ws_allowin),
            .ms_to_ws_valid(mem_ms_to_ws_valid)
        );

    csr csr_o(
            .clk        (clk),
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
