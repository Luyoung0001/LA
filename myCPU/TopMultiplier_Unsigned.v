module TopMultiplier_Unsigned (
        input [31:0] x_in,
        input [31:0] y_in,
        input enable,
        output [63:0] result_out
    );

    // internal connections
    wire [31:0] pp0, pp1, pp2, pp3, pp4, pp5, pp6, pp7,
         pp8, pp9, pp10, pp11, pp12, pp13, pp14, pp15,
         pp16, pp17, pp18, pp19, pp20, pp21, pp22, pp23,
         pp24, pp25, pp26, pp27, pp28, pp29, pp30, pp31;
    wire [63:0] opa, opb;
    wire [63:0] result;
    // generate PP
    Booth_Unsigned32 booth (
                         .M(x_in),
                         .R(y_in),
                         .pp0(pp0),
                         .pp1(pp1),
                         .pp2(pp2),
                         .pp3(pp3),
                         .pp4(pp4),
                         .pp5(pp5),
                         .pp6(pp6),
                         .pp7(pp7),
                         .pp8(pp8),
                         .pp9(pp9),
                         .pp10(pp10),
                         .pp11(pp11),
                         .pp12(pp12),
                         .pp13(pp13),
                         .pp14(pp14),
                         .pp15(pp15),
                         .pp16(pp16),
                         .pp17(pp17),
                         .pp18(pp18),
                         .pp19(pp19),
                         .pp20(pp20),
                         .pp21(pp21),
                         .pp22(pp22),
                         .pp23(pp23),
                         .pp24(pp24),
                         .pp25(pp25),
                         .pp26(pp26),
                         .pp27(pp27),
                         .pp28(pp28),
                         .pp29(pp29),
                         .pp30(pp30),
                         .pp31(pp31)
                     );

    // wallace tree
    WallaceTree32X32 wallace (
                         .pp0(pp0),
                         .pp1(pp1),
                         .pp2(pp2),
                         .pp3(pp3),
                         .pp4(pp4),
                         .pp5(pp5),
                         .pp6(pp6),
                         .pp7(pp7),
                         .pp8(pp8),
                         .pp9(pp9),
                         .pp10(pp10),
                         .pp11(pp11),
                         .pp12(pp12),
                         .pp13(pp13),
                         .pp14(pp14),
                         .pp15(pp15),
                         .pp16(pp16),
                         .pp17(pp17),
                         .pp18(pp18),
                         .pp19(pp19),
                         .pp20(pp20),
                         .pp21(pp21),
                         .pp22(pp22),
                         .pp23(pp23),
                         .pp24(pp24),
                         .pp25(pp25),
                         .pp26(pp26),
                         .pp27(pp27),
                         .pp28(pp28),
                         .pp29(pp29),
                         .pp30(pp30),
                         .pp31(pp31),
                         .opa(opa),
                         .opb(opb)
                     );


    CS_Adder64 resulttemp (
                   .a(opa),
                   .b(opb),
                   .cin(1'b0),
                   .sum(result),
                   .cout()
               );
    assign result_out = enable ? result : 64'b0;

endmodule
