module mul_top(
    input [31:0] alu_src1,
    input [31:0] alu_src2,
    input mul_div_op, // 0: unsigned multiply, 1: signed multiply
    output [63:0] signed_mul_result,
    output [63:0] unsigned_mul_result
);

    wire [63:0] res_signed;
    wire [63:0] res_unsigned;

    TopMultiplier o (
        .x_in(alu_src1),
        .y_in(alu_src2),
	.enable(1'b1),
        .result_out(signed_mul_result)
    );

    TopMultiplier_Unsigned o1 (
        .x_in(alu_src1),
        .y_in(alu_src2),
	.enable(1'b1),
        .result_out(unsigned_mul_result)
    );

    // assign mul_result = (mul_div_op == 1'b1) ? res_signed : res_unsigned;

endmodule