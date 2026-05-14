`timescale 1ns / 1ps
`include "cpu_defs.vh"

module backend_operand_mux_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [1:0]  src_a_sel;
    logic [1:0]  src_b_sel;
    logic [31:0] pc;
    logic [31:0] imm;
    logic [31:0] rs1_val;
    logic [31:0] rs2_val;
    logic [31:0] op_a;
    logic [31:0] op_b;

    backend_operand_mux u_dut (
        .src_a_sel_i(src_a_sel),
        .src_b_sel_i(src_b_sel),
        .pc_i(pc),
        .imm_i(imm),
        .rs1_val_i(rs1_val),
        .rs2_val_i(rs2_val),
        .op_a_o(op_a),
        .op_b_o(op_b)
    );

    task automatic drive_base;
        begin
            src_a_sel = `CPU_SRC_A_RS1;
            src_b_sel = `CPU_SRC_B_RS2;
            pc = 32'h1c00_0040;
            imm = 32'h0000_0123;
            rs1_val = 32'haaaa_0001;
            rs2_val = 32'hbbbb_0002;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_base();
        #1;
        `check32("operand mux rs1", op_a, 32'haaaa_0001);
        `check32("operand mux rs2", op_b, 32'hbbbb_0002);

        drive_base();
        src_a_sel = `CPU_SRC_A_PC;
        #1;
        `check32("operand mux pc", op_a, 32'h1c00_0040);

        drive_base();
        src_a_sel = `CPU_SRC_A_ZERO;
        #1;
        `check32("operand mux zero", op_a, 32'h0000_0000);

        drive_base();
        src_b_sel = `CPU_SRC_B_IMM;
        #1;
        `check32("operand mux imm", op_b, 32'h0000_0123);

        drive_base();
        src_b_sel = `CPU_SRC_B_FOUR;
        #1;
        `check32("operand mux four", op_b, 32'h0000_0004);

        drive_base();
        src_a_sel = 2'b11;
        src_b_sel = 2'b11;
        #1;
        `check32("operand mux default src a rs1", op_a, 32'haaaa_0001);
        `check32("operand mux default src b rs2", op_b, 32'hbbbb_0002);

        finish_tb();
    end
endmodule
