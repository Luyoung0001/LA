`timescale 1ns / 1ps

module s5_issue_hold_rf_base_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic capture;
    logic track;
    logic [31:0] cap_s0_rs1;
    logic [31:0] cap_s0_rs2;
    logic [31:0] cap_s1_rs1;
    logic [31:0] cap_s1_rs2;
    logic [31:0] trk_s0_rs1;
    logic [31:0] trk_s0_rs2;
    logic [31:0] trk_s1_rs1;
    logic [31:0] trk_s1_rs2;
    logic [31:0] hold_s0_rs1;
    logic [31:0] hold_s0_rs2;
    logic [31:0] hold_s1_rs1;
    logic [31:0] hold_s1_rs2;

    s5_issue_hold_rf_base #(
        .XLEN(32)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .capture_i(capture),
        .capture_slot0_rs1_base_i(cap_s0_rs1),
        .capture_slot0_rs2_base_i(cap_s0_rs2),
        .capture_slot1_rs1_base_i(cap_s1_rs1),
        .capture_slot1_rs2_base_i(cap_s1_rs2),
        .track_i(track),
        .track_slot0_rs1_base_i(trk_s0_rs1),
        .track_slot0_rs2_base_i(trk_s0_rs2),
        .track_slot1_rs1_base_i(trk_s1_rs1),
        .track_slot1_rs2_base_i(trk_s1_rs2),
        .hold_slot0_rs1_base_o(hold_s0_rs1),
        .hold_slot0_rs2_base_o(hold_s0_rs2),
        .hold_slot1_rs1_base_o(hold_s1_rs1),
        .hold_slot1_rs2_base_o(hold_s1_rs2)
    );

    initial begin
        tb_start();
        flush = 1'b0;
        capture = 1'b0;
        track = 1'b0;
        cap_s0_rs1 = 32'h1111_0001;
        cap_s0_rs2 = 32'h1111_0002;
        cap_s1_rs1 = 32'h1111_0003;
        cap_s1_rs2 = 32'h1111_0004;
        trk_s0_rs1 = 32'h2222_0001;
        trk_s0_rs2 = 32'h2222_0002;
        trk_s1_rs1 = 32'h2222_0003;
        trk_s1_rs2 = 32'h2222_0004;
        reset_dut();

        `check32("HOLD_RF reset slot0 rs1", hold_s0_rs1, 32'd0);
        `check32("HOLD_RF reset slot1 rs2", hold_s1_rs2, 32'd0);

        capture = 1'b1;
        tick();
        capture = 1'b0;
        `check32("HOLD_RF captures slot0 rs1", hold_s0_rs1, 32'h1111_0001);
        `check32("HOLD_RF captures slot0 rs2", hold_s0_rs2, 32'h1111_0002);
        `check32("HOLD_RF captures slot1 rs1", hold_s1_rs1, 32'h1111_0003);
        `check32("HOLD_RF captures slot1 rs2", hold_s1_rs2, 32'h1111_0004);

        cap_s0_rs1 = 32'h3333_0001;
        cap_s0_rs2 = 32'h3333_0002;
        cap_s1_rs1 = 32'h3333_0003;
        cap_s1_rs2 = 32'h3333_0004;
        track = 1'b1;
        tick();
        track = 1'b0;
        `check32("HOLD_RF tracks slot0 rs1", hold_s0_rs1, 32'h2222_0001);
        `check32("HOLD_RF tracks slot1 rs2", hold_s1_rs2, 32'h2222_0004);

        capture = 1'b1;
        track = 1'b1;
        tick();
        capture = 1'b0;
        track = 1'b0;
        `check32("HOLD_RF capture wins over track", hold_s0_rs1, 32'h3333_0001);
        `check32("HOLD_RF capture wins slot1", hold_s1_rs2, 32'h3333_0004);

        flush = 1'b1;
        tick();
        flush = 1'b0;
        `check32("HOLD_RF flush clears slot0", hold_s0_rs1, 32'd0);
        `check32("HOLD_RF flush clears slot1", hold_s1_rs2, 32'd0);

        finish_tb();
    end
endmodule
