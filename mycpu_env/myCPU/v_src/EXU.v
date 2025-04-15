module EXU (
        input wire clk,
        input wire rst,

        // for exu
        input wire [11:0] alu_op,
        input wire [31:0] alu_src1,
        input wire [31:0] alu_src2,

        // for mem
        input wire in_mem_we,
        input wire [31:0] in_rkd_value,
        input wire in_res_from_mem,

        output wire mem_we,
        output wire [31:0] rkd_value,
        output wire res_from_mem,

        output wire [31:0] alu_result,

        // for wb
        input wire in_gr_we,
        input wire [4:0] in_dest,
        input wire [31:0] in_pc,

        output wire gr_we,
        output wire [4:0] dest,
        output wire [31:0] pc,

        // 数据相关
        output wire exu_regWr,
        output wire [31:0] exu_data,
        output wire [4:0] exu_regAddr,

        // 握手信号
        // allowin
        input     ms_allowin, // 来自的下游的 allowin 信号
        output    es_allowin, // 发给上游的 allowin 信号

        input     ds_to_es_valid, // 来自的上游的 valid 信号
        output    es_to_ms_valid  // 发给下游的 valid 信号
    );


    reg [11:0] alu_op_reg;
    reg [31:0] alu_src1_reg;
    reg [31:0] alu_src2_reg;
    reg in_mem_we_reg;

    reg [31:0] in_rkd_value_reg;
    reg in_res_from_mem_reg;
    reg in_gr_we_reg;
    reg [4:0] in_dest_reg;
    reg [31:0] in_pc_reg;

    reg         es_valid      ;
    wire        es_ready_go   ;

    // always @(posedge clk or posedge rst) begin
    //     if (rst) begin
    //         alu_op_reg <= 12'd0;
    //         alu_src1_reg <= 32'd0;
    //         alu_src2_reg <= 32'd0;
    //         in_mem_we_reg <= 1'b0;

    //         in_rkd_value_reg <= 32'd0;
    //         in_res_from_mem_reg <= 1'b0;
    //         in_gr_we_reg <= 1'b0;
    //         in_dest_reg <= 5'd0;
    //         in_pc_reg <= 32'd0;
    //     end
    //     else begin
    //         alu_op_reg <= alu_op;
    //         alu_src1_reg <= alu_src1;
    //         alu_src2_reg <= alu_src2;
    //         in_mem_we_reg <= in_mem_we;

    //         in_rkd_value_reg <= in_rkd_value;
    //         in_res_from_mem_reg <= in_res_from_mem;
    //         in_gr_we_reg <= in_gr_we;
    //         in_dest_reg <= in_dest;
    //         in_pc_reg <= in_pc;
    //     end
    // end

    wire [11:0] wire_alu_op;
    wire [31:0] wire_alu_src1;
    wire [31:0] wire_alu_src2;
    wire wire_in_mem_we;
    wire [31:0] wire_in_rkd_value;
    wire wire_in_res_from_mem;
    wire wire_in_gr_we;
    wire [4:0] wire_in_dest;


    assign wire_alu_op = alu_op_reg;
    assign wire_alu_src1 = alu_src1_reg;
    assign wire_alu_src2 = alu_src2_reg;

    assign wire_in_mem_we = in_mem_we_reg;

    assign wire_in_rkd_value = in_rkd_value_reg;
    assign wire_in_res_from_mem = in_res_from_mem_reg;
    assign wire_in_gr_we = in_gr_we_reg;
    assign wire_in_dest = in_dest_reg;

    assign mem_we = wire_in_mem_we;
    assign rkd_value = wire_in_rkd_value;
    assign res_from_mem = wire_in_res_from_mem;
    assign gr_we = wire_in_gr_we & es_valid;
    assign dest = wire_in_dest;
    assign pc = in_pc_reg;

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
            // ds_to_es_bus_r <= ds_to_es_bus;
            // 卸货
            alu_op_reg <= alu_op;
            alu_src1_reg <= alu_src1;
            alu_src2_reg <= alu_src2;
            in_mem_we_reg <= in_mem_we;

            in_rkd_value_reg <= in_rkd_value;
            in_res_from_mem_reg <= in_res_from_mem;
            in_gr_we_reg <= in_gr_we;
            in_dest_reg <= in_dest;
            in_pc_reg <= in_pc;

        end
    end

endmodule
