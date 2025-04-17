module EXU (
        input wire clk,
        input wire rst,

        // bus
        input wire [147:0] bus_ds_to_es_data,
        output wire [70:0] bus_exu_to_mem_data,

        // to mem_sram
        output wire [31:0] data_sram_addr,
        output wire [31:0] data_sram_wdata,
        output wire [3:0] data_sram_we,

        output wire [37:0] bus_exu_bypass_data,

        // 握手信号
        // allowin
        input     ms_allowin, // 来自的下游的 allowin 信号
        output    es_allowin, // 发给上游的 allowin 信号

        input     ds_to_es_valid, // 来自的上游的 valid 信号
        output    es_to_ms_valid  // 发给下游的 valid 信号
    );

    // 数据相关
    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;

    reg [147:0] ds_to_es_bus_data_r;


    reg         es_valid      ;
    wire        es_ready_go   ;

    wire [11:0] wire_alu_op;
    wire [31:0] wire_alu_src1;
    wire [31:0] wire_alu_src2;

    wire wire_in_mem_we;
    wire [31:0] wire_in_rkd_value;
    wire wire_in_res_from_mem;

    wire wire_in_gr_we;
    wire [4:0] wire_in_dest;
    wire [31:0] wire_in_pc;

    wire res_from_mem;
    wire [31:0] alu_result;
    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;

    assign {
            wire_alu_op,
            wire_alu_src1,
            wire_alu_src2,

            wire_in_mem_we,
            wire_in_rkd_value,
            wire_in_res_from_mem,

            wire_in_gr_we,
            wire_in_dest,
            wire_in_pc
        } = ds_to_es_bus_data_r;

    assign bus_exu_to_mem_data = {
               res_from_mem,
               alu_result,
               gr_we,
               dest,
               pc
           };


    assign res_from_mem = wire_in_res_from_mem;
    assign gr_we = wire_in_gr_we & es_valid;
    assign dest = wire_in_dest;
    assign pc = wire_in_pc;

    alu u_alu(
            .alu_op     (wire_alu_op    ),
            .alu_src1   (wire_alu_src1  ),
            .alu_src2   (wire_alu_src2  ),
            .alu_result (alu_result)
        );

    // 解决数据相关
    assign exu_regWr = gr_we;
    assign exu_data = alu_result;
    assign exu_regAddr = wire_in_dest;

    assign bus_exu_bypass_data = {
               exu_regWr,
               exu_data,
               exu_regAddr};

    // 握手信号
    assign es_ready_go    = 1'b1;
    assign es_allowin     = !es_valid || es_ready_go && ms_allowin;
    assign es_to_ms_valid =  es_valid && es_ready_go;
    always @(posedge clk) begin
        if (rst) begin
            es_valid <= 1'b0;
        end
        else if (es_allowin) begin
            es_valid <= ds_to_es_valid;
        end
        if (ds_to_es_valid && es_allowin) begin
            ds_to_es_bus_data_r <= bus_ds_to_es_data;

        end
    end

    // 提前发射访存信号，必须在 es 阶段有效
    assign data_sram_we = {wire_in_mem_we && es_valid,
                           wire_in_mem_we && es_valid,
                           wire_in_mem_we && es_valid,
                           wire_in_mem_we && es_valid};
    assign data_sram_addr  = alu_result;
    assign data_sram_wdata = wire_in_rkd_value;



endmodule
