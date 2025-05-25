module CS_Adder64 (
    input [63:0] a,
    input [63:0] b,
    input cin,
    output [63:0] sum,
    output cout
);

    wire cout_low; // 低32位产生的进位

    // 实例化低32位加法器
    CS_Adder32 adder_low (
        .a(a[31:0]),
        .b(b[31:0]),
        .cin(cin),
        .sum(sum[31:0]),
        .cout(cout_low)
    );

    // 实例化高32位加法器
    CS_Adder32 adder_high (
        .a(a[63:32]),
        .b(b[63:32]),
        .cin(cout_low),
        .sum(sum[63:32]),
        .cout(cout)
    );

endmodule