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

    // ifu
    wire [31:0] ifu_fs_pc;
    wire ifu_fs_allowin;
    wire ifu_fs_to_ds_valid;

    // idu
    wire [32:0] idu_bus_br_data;

    wire [4:0] idu_rf_raddr1;
    wire [4:0] idu_rf_raddr2;

    wire [177:0] idu_bus_ds_to_es_data;
    wire [7:0] idu_out_mem_op;

    wire idu_ds_allowin;
    wire idu_ds_to_es_valid;

    // exu

    wire [70:0] exu_bus_exu_to_mem_data;

    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;
    wire exe_es_allowin;
    wire exe_es_to_ms_valid;
    wire [37:0] exu_bus_exu_bypass_data;
    wire [7:0] exu_out_mem_op;
    wire [3:0] exu_out_mem_mask;



    // mem
    wire [69:0] mem_bus_mem_to_wbu_data;
    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    wire mem_ms_allowin;
    wire mem_ms_to_ws_valid;

    wire [37:0] mem_bus_mem_bypass_data;

    // wbu
    wire        wbu_rf_we;
    wire [4:0]  wbu_rf_waddr;
    wire [31:0] wbu_rf_wdata;
    wire [31:0] wbu_pc;

    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    wire wbu_ws_allowin;

    wire [37:0] wbu_bus_wbu_bypass_data;

    //  regfile
    wire [31:0] rf_rdata1;
    wire [31:0] rf_rdata2;

    pre_IFU pre_ifu(
                .clk        (clk),
                .rst        (reset),
                .fs_pc      (ifu_fs_pc),
                .bus_br_data    (idu_bus_br_data),
                .next_pc    (preifu_next_pc),
                .inst_addr  (preifu_inst_addr),
                .fs_allowin (ifu_fs_allowin)
            );

    // ifu
    IFU ifu(
            .clk        (clk),
            .rst        (reset),
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

            .ms_allowin(mem_ms_allowin),
            .es_allowin(exe_es_allowin),
            .ds_to_es_valid(idu_ds_to_es_valid),
            .es_to_ms_valid(exe_es_to_ms_valid)

        );

    // mem

    MEM mem(
            .clk        (clk),
            .rst        (reset),
            .in_mem_op  (exu_out_mem_op),
            .in_mem_mask(exu_out_mem_mask),
            .bus_exu_to_mem_data(exu_bus_exu_to_mem_data),
            .bus_mem_to_wbu_data(mem_bus_mem_to_wbu_data),
            // from mem_sram
            .data_sram_rdata(data_sram_rdata),
            .bus_mem_bypass_data(mem_bus_mem_bypass_data),

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

            // to rf
            .rf_we      (wbu_rf_we),
            .rf_waddr   (wbu_rf_waddr),
            .rf_wdata   (wbu_rf_wdata),
            .pc         (wbu_pc),
            // 数据相关
            .bus_wbu_bypass_data(wbu_bus_wbu_bypass_data),

            .ws_allowin(wbu_ws_allowin),
            .ms_to_ws_valid(mem_ms_to_ws_valid)
        );

    // debug info generate
    assign debug_wb_pc       = wbu_pc;
    assign debug_wb_rf_we   = {4{wbu_rf_we}};
    assign debug_wb_rf_wnum  = wbu_rf_waddr;
    assign debug_wb_rf_wdata = wbu_rf_wdata;


endmodule
