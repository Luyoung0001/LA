`timescale 1ns / 1ps
`include "cpu_defs.vh"

module backend_lane_alu_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [3:0]  alu_op;
    logic [31:0] op_a;
    logic [31:0] op_b;
    logic [31:0] result;

    backend_lane_alu u_dut (
        .alu_op_i(alu_op),
        .op_a_i(op_a),
        .op_b_i(op_b),
        .result_o(result)
    );

    task automatic drive_check(
        input string name,
        input [3:0]  op,
        input [31:0] a,
        input [31:0] b,
        input [31:0] expected
    );
        begin
            alu_op = op;
            op_a = a;
            op_b = b;
            #1;
            `check32(name, result, expected);
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;

        drive_check("lane ALU add", `CPU_ALU_ADD, 32'h0000_0010, 32'h0000_0020, 32'h0000_0030);
        drive_check("lane ALU sub", `CPU_ALU_SUB, 32'h0000_0010, 32'h0000_0020, 32'hffff_fff0);
        drive_check("lane ALU and", `CPU_ALU_AND, 32'ha5a5_0f0f, 32'h00ff_0ff0, 32'h00a5_0f00);
        drive_check("lane ALU andn", `CPU_ALU_ANDN, 32'ha5a5_0f0f, 32'h00ff_0ff0, 32'ha500_000f);
        drive_check("lane ALU or", `CPU_ALU_OR, 32'ha5a5_0000, 32'h0000_5a5a, 32'ha5a5_5a5a);
        drive_check("lane ALU orn", `CPU_ALU_ORN, 32'h0000_00ff, 32'hffff_0f0f, 32'h0000_f0ff);
        drive_check("lane ALU nor", `CPU_ALU_NOR, 32'hffff_0000, 32'h0000_00ff, 32'h0000_ff00);
        drive_check("lane ALU xor", `CPU_ALU_XOR, 32'ha5a5_0f0f, 32'h00ff_0ff0, 32'ha55a_00ff);
        drive_check("lane ALU sll", `CPU_ALU_SLL, 32'h0000_0001, 32'h0000_0008, 32'h0000_0100);
        drive_check("lane ALU srl", `CPU_ALU_SRL, 32'h8000_0000, 32'h0000_0004, 32'h0800_0000);
        drive_check("lane ALU sra", `CPU_ALU_SRA, 32'h8000_0000, 32'h0000_0004, 32'hf800_0000);
        drive_check("lane ALU slt true", `CPU_ALU_SLT, 32'hffff_ffff, 32'h0000_0001, 32'h0000_0001);
        drive_check("lane ALU slt false", `CPU_ALU_SLT, 32'h0000_0002, 32'hffff_ffff, 32'h0000_0000);
        drive_check("lane ALU sltu true", `CPU_ALU_SLTU, 32'h0000_0001, 32'hffff_ffff, 32'h0000_0001);
        drive_check("lane ALU copy b", `CPU_ALU_COPY_B, 32'h1234_5678, 32'h8765_4321, 32'h8765_4321);
        drive_check("lane ALU unknown op clears", 4'hf, 32'hffff_ffff, 32'hffff_ffff, 32'h0000_0000);

        finish_tb();
    end
endmodule
