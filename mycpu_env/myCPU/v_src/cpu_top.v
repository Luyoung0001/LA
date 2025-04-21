module mycpu_top(
        input  wire        clk,
        input  wire        resetn,
        // inst sram interface
        output wire        inst_sram_en,
        output wire [3:0]  inst_sram_we,
        output wire [31:0] inst_sram_addr,
        output wire [31:0] inst_sram_wdata,
        input  wire [31:0] inst_sram_rdata,

        // data sram interface
        output wire        data_sram_en,
        output wire [3:0]  data_sram_we,
        output wire [31:0] data_sram_addr,
        output wire [31:0] data_sram_wdata,
        input  wire [31:0] data_sram_rdata,

        // trace debug interface
        output wire [31:0] debug_wb_pc,
        output wire [ 3:0] debug_wb_rf_we,
        output wire [ 4:0] debug_wb_rf_wnum,
        output wire [31:0] debug_wb_rf_wdata
    );

    // reg         reset;
    // always @(posedge clk) reset <= ~resetn;
    wire reset;
    assign reset = ~resetn;

    // pre_IFU
    wire [31:0] preifu_inst_addr;
    wire [31:0] preifu_next_pc;
    wire preifu_pfs_excp_adef;
    wire preifu_pfs_excp;

    // ifu
    wire [31:0] ifu_fs_pc;
    wire ifu_fs_allowin;
    wire ifu_fs_to_ds_valid;

    wire ifu_fs_excp_out;
    wire [15:0] ifu_fs_excp_num_out;

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

    // exu

    wire exu_es_excp_out;
    wire [15:0] exu_es_excp_num_out;
    wire [118:0] exu_bus_exu_to_mem_data;

    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;

    wire exu_exu_excp;
    wire exe_es_allowin;
    wire exe_es_to_ms_valid;
    wire [84:0] exu_bus_exu_bypass_data;
    wire [7:0] exu_out_mem_op;
    wire [3:0] exu_out_mem_mask;



    // mem

    wire mem_ms_excp_out;
    wire [15:0] mem_ms_excp_num_out;
    wire [117:0] mem_bus_mem_to_wbu_data;
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    wire mem_ms_allowin;
    wire mem_ms_to_ws_valid;

    wire [84:0] mem_bus_mem_bypass_data;

        wire mem_mem_excp;

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

    wire wbu_ertn_flush;
    wire wbu_excp_flush;

    wire [31:0] wbu_csr_era;

    //  regfile
    wire [31:0] rf_rdata1;
    wire [31:0] rf_rdata2;

    // csr

    wire [31:0] csr_rd_data;
    wire [31:0] csr_era_out;
    wire [31:0] csr_eentry_out;

    pre_IFU pre_ifu(
                .clk        (clk),
                .rst        (reset),
                .fs_pc      (ifu_fs_pc),
                .bus_br_data    (idu_bus_br_data),
                .next_pc    (preifu_next_pc),
                .inst_addr  (preifu_inst_addr),
                .excp_flush (wbu_excp_flush),
                .ertn_flush (wbu_ertn_flush),
                .csr_era    (csr_era_out),
                .csr_eentry (csr_eentry_out),
                .pfs_excp_adef(preifu_pfs_excp_adef),
                .pfs_excp   (preifu_pfs_excp),
                .fs_allowin (ifu_fs_allowin)
            );

    // ifu
    IFU ifu(
            .clk        (clk),
            .rst        (reset),
            .pfs_excp_adef (preifu_pfs_excp_adef),
            .pfs_excp   (preifu_pfs_excp),

            .fs_excp_out (ifu_fs_excp_out),
            .fs_excp_num_out(ifu_fs_excp_num_out),
            .next_pc    (preifu_next_pc),
            .fs_pc      (ifu_fs_pc),
            .ds_allowin (idu_ds_allowin),
            .fs_allowin (ifu_fs_allowin),
            .fs_to_ds_valid(ifu_fs_to_ds_valid)
        );

    // inst_ram
    assign inst_sram_en = 1'b1;
    assign inst_sram_we = 4'b0;
    assign inst_sram_addr = preifu_inst_addr;
    assign inst_sram_wdata = 32'b0;

    // assign data_sram_en = 1'b1;

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

            .ertn_flush    (wbu_ertn_flush),
            .excp_flush    (wbu_excp_flush),
            .exu_excp      (exu_exu_excp),
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

            // to mem_sram
            .data_sram_addr(data_sram_addr),
            .data_sram_wdata(data_sram_wdata),
            .data_sram_we(data_sram_we),
            .data_sram_en(data_sram_en),

            //  bus
            .bus_exu_bypass_data(exu_bus_exu_bypass_data),
            .out_mem_op(exu_out_mem_op),
            .out_mem_mask(exu_out_mem_mask),

            .ertn_flush (wbu_ertn_flush),
            .excp_flush (wbu_excp_flush),
            .mem_excp (mem_mem_excp),
            .exu_excp (exu_exu_excp),

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

            .ertn_flush (wbu_ertn_flush),
            .excp_flush (wbu_excp_flush),
            .mem_excp(mem_mem_excp),

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

            // csr
            .csr_we     (wbu_csr_we),
            .csr_addr   (wbu_csr_addr),
            .csr_wdata  (wbu_csr_wdata),

            .csr_ecode  (wbu_csr_ecode),
            .va_error   (wbu_va_error),
            .bad_va     (wbu_bad_va),
            .csr_esubcode(wbu_csr_esubcode),
            .excp_tlbrefill(wbu_excp_tlbrefill),
            .excp_tlb   (wbu_excp_tlb),
            .excp_tlb_vppn(wbu_excp_tlb_vppn),
            .csr_era    (wbu_csr_era),
            .ertn_flush (wbu_ertn_flush),
            .excp_flush (wbu_excp_flush),

            .ws_allowin(wbu_ws_allowin),
            .ms_to_ws_valid(mem_ms_to_ws_valid)
        );

        csr csr_o(
            .clk        (clk),
            .reset      (reset),
            //from ds for read
            .rd_addr    (idu_rd_csr_addr),
            .rd_data    (csr_rd_data),
            // write signal
            .csr_wr_en  (wbu_csr_we),
            .wr_addr    (wbu_csr_addr),
            .wr_data    (wbu_csr_wdata),
            .era_in     (wbu_csr_era),
            .ertn_flush (wbu_ertn_flush),
            .excp_flush (wbu_excp_flush),

            .ecode_in   (wbu_csr_ecode),
            .va_error_in(wbu_va_error),
            .bad_va_in  (wbu_bad_va),
            .esubcode_in(wbu_csr_esubcode),
            .excp_tlbrefill(wbu_excp_tlbrefill),
            .excp_tlb   (wbu_excp_tlb),
            .excp_tlb_vppn(wbu_excp_tlb_vppn),

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
