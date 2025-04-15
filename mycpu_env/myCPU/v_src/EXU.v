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
        output wire [4:0] exu_regAddr
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

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            alu_op_reg <= 12'd0;
            alu_src1_reg <= 32'd0;
            alu_src2_reg <= 32'd0;
            in_mem_we_reg <= 1'b0;

            in_rkd_value_reg <= 32'd0;
            in_res_from_mem_reg <= 1'b0;
            in_gr_we_reg <= 1'b0;
            in_dest_reg <= 5'd0;
            in_pc_reg <= 32'd0;
        end
        else begin
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
    assign gr_we = wire_in_gr_we;
    assign dest = wire_in_dest;
    assign pc = in_pc_reg;

    alu u_alu(
            .alu_op     (wire_alu_op    ),
            .alu_src1   (wire_alu_src1  ),
            .alu_src2   (wire_alu_src2  ),
            .alu_result (alu_result)
        );

    // 解决数据相关
    assign exu_regWr = wire_in_gr_we;
    assign exu_data = alu_result;
    assign exu_regAddr = wire_in_dest;

endmodule
