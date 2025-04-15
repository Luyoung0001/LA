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

    reg         reset;
    always @(posedge clk) reset <= ~resetn;

    reg         valid;
    always @(posedge clk) begin
        if (reset) begin
            valid <= 1'b0;
        end
        else begin
            valid <= 1'b1;
        end
    end

    // ifu
    wire [31:0] ifu_pc;
    wire ifu_fs_to_ds_valid;

    // idu
    wire        idu_br_taken;
    wire [31:0] idu_br_target;
    wire [4:0] idu_rf_raddr1;
    wire [4:0] idu_rf_raddr2;
    wire [11:0] idu_alu_op;
    wire [31:0] idu_alu_src1;
    wire [31:0] idu_alu_src2;
    wire        idu_mem_we;
    wire [4:0] idu_dest;

    wire        idu_res_from_mem;
    wire [31:0] idu_rkd_value;
    wire [4:0] idu_rf_waddr;
    wire [31:0] idu_rf_wdata;
    wire        idu_gr_we;
    wire        idu_rf_we;
    wire [31:0] idu_pc;
    wire idu_ds_allowin;

    // exu
    wire exu_mem_we;
    wire [31:0] exu_rkd_value;
    wire        exu_res_from_mem;
    wire [31:0] exu_alu_result;

    wire exu_gr_we;
    wire [4:0] exu_dest;
    wire [31:0] exu_pc;

    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;



    // mem
    wire mem_gr_we;
    wire [4:0] mem_dest;
    wire [31:0] mem_final_result;
    wire [31:0] mem_pc;


    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    // wbu
    wire        wbu_rf_we;
    wire [4:0]  wbu_rf_waddr;
    wire [31:0] wbu_rf_wdata;
    wire [31:0] wbu_pc;

    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    //  regfile
    wire [31:0] rf_rdata1;
    wire [31:0] rf_rdata2;

    // ifu
    IFU ifu(
            .clk        (clk),
            .rst        (reset),

            // to idu
            .br_taken   (idu_br_taken),
            .br_target  (idu_br_target),

            // from idu
            .pc         (ifu_pc),
            .ds_allowin (idu_ds_allowin),
            .fs_to_ds_valid(ifu_fs_to_ds_valid)
        );


    // inst_ram

    assign inst_sram_en = 1'b1;
    assign inst_sram_we = 4'b0;
    assign inst_sram_addr = ifu_pc;
    assign inst_sram_wdata = 32'b0;

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
            .valid      (valid),
            // to ifu
            .br_taken   (idu_br_taken),
            .br_target  (idu_br_target),

            // from ifu
            .in_pc         (ifu_pc),

            // to rf
            .rf_raddr1  (idu_rf_raddr1),
            .rf_raddr2  (idu_rf_raddr2),

            // from rf
            .rf_rdata1  (rf_rdata1),
            .rf_rdata2  (rf_rdata2),

            // from inst_ram
            .inst_sram_rdata(inst_sram_rdata),

            // to exu
            .alu_op     (idu_alu_op),
            .alu_src1   (idu_alu_src1),
            .alu_src2   (idu_alu_src2),

            // to mem
            .mem_we     (idu_mem_we),
            .dest       (idu_dest),
            .res_from_mem(idu_res_from_mem),
            .rkd_value  (idu_rkd_value),

            // to wb
            .rf_waddr   (idu_rf_waddr),
            .rf_wdata   (idu_rf_wdata),
            .gr_we      (idu_gr_we),
            .rf_we      (idu_rf_we),
            .pc         (idu_pc),
            // 直通解决数据相关
            // 从 EXU 窃取
            .exu_regWr  (exu_regWr),
            .exu_data   (exu_data),
            .exu_regAddr(exu_regAddr),
            // 从 MEM 窃取
            .mem_regWr  (mem_regWr),
            .mem_data   (mem_data),
            .mem_regAddr(mem_regAddr),
            // 从 WBU 窃取
            .wbu_regWr  (wbu_regWr),
            .wbu_data   (wbu_data),
            .wbu_regAddr(wbu_regAddr),
            .fs_to_ds_valid(ifu_fs_to_ds_valid),
            .ds_allowin (idu_ds_allowin)
        );

    // exu
    EXU exu(
            .clk        (clk),
            .rst        (reset),

            // for exu
            .alu_op     (idu_alu_op),
            .alu_src1   (idu_alu_src1),
            .alu_src2   (idu_alu_src2),

            // for mem
            .in_mem_we  (idu_mem_we),
            .in_rkd_value(idu_rkd_value),
            .in_res_from_mem(idu_res_from_mem),
            .in_pc     (idu_pc),

            // to mem
            .mem_we     (exu_mem_we),
            .rkd_value  (exu_rkd_value),
            .res_from_mem(exu_res_from_mem),

            // to wb
            .alu_result (exu_alu_result),
            .in_gr_we   (idu_gr_we),
            .in_dest    (idu_dest),

            // to wb
            .gr_we      (exu_gr_we),
            .dest       (exu_dest),
            .pc         (exu_pc),

            // 数据相关
            .exu_regWr  (exu_regWr),
            .exu_data   (exu_data),
            .exu_regAddr(exu_regAddr)

        );

    // mem

    MEM mem(
            .clk        (clk),
            .rst        (reset),
            .mem_we     (exu_mem_we),
            .valid      (valid),
            .alu_result (exu_alu_result),
            .rkd_value  (exu_rkd_value),
            .res_from_mem(exu_res_from_mem),

            // to mem_sram
            .data_sram_addr(data_sram_addr),
            .data_sram_wdata(data_sram_wdata),
            .data_sram_we(data_sram_we),

            // from mem_sram
            .data_sram_rdata(data_sram_rdata),

            // for wb
            .in_gr_we   (exu_gr_we),
            .in_dest    (exu_dest),
            .in_pc      (exu_pc),

            // to wb
            .gr_we      (mem_gr_we),
            .dest       (mem_dest),

            // to wb
            .final_result(mem_final_result),
            .pc        (mem_pc),
            // 数据相关
            .mem_regWr  (mem_regWr),
            .mem_data   (mem_data),
            .mem_regAddr(mem_regAddr)
        );

    // wbu

    WBU wbu(
            .clk        (clk),
            .rst        (reset),
            .valid      (valid),
            .gr_we      (mem_gr_we),
            .dest       (mem_dest),
            .final_result(mem_final_result),
            .in_pc      (mem_pc),

            // to rf
            .rf_we      (wbu_rf_we),
            .rf_waddr   (wbu_rf_waddr),
            .rf_wdata   (wbu_rf_wdata),
            .pc         (wbu_pc),
            // 数据相关
            .wbu_regWr  (wbu_regWr),
            .wbu_data   (wbu_data),
            .wbu_regAddr(wbu_regAddr)
        );

    // debug info generate
    assign debug_wb_pc       = wbu_pc;
    assign debug_wb_rf_we   = {4{wbu_rf_we}};
    assign debug_wb_rf_wnum  = wbu_rf_waddr;
    assign debug_wb_rf_wdata = wbu_rf_wdata;


endmodule
