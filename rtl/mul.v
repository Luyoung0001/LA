module mul (
    input  wire [9:0]  mul_div_op,
    input  wire [31:0] alu_src1,
    input  wire [31:0] alu_src2,
    output wire [31:0] mul_result
);

    wire [63:0] signed_mul_result64;
    wire [63:0] unsigned_mul_result64;

    wire op_mul;
    wire op_mulh;
    wire op_mulhu;

    assign op_mul   = mul_div_op[0];
    assign op_mulh  = mul_div_op[1];
    assign op_mulhu = mul_div_op[2];

    assign signed_mul_result64   = $signed(alu_src1) * $signed(alu_src2);
    assign unsigned_mul_result64 = $unsigned(alu_src1) * $unsigned(alu_src2);

    assign mul_result =
        ({32{op_mul}}   & signed_mul_result64[31:0]) |
        ({32{op_mulh}}  & signed_mul_result64[63:32]) |
        ({32{op_mulhu}} & unsigned_mul_result64[63:32]);

endmodule
