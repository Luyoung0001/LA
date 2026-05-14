`timescale 1ns / 1ps

module s1_if0_pc_update_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic [31:0] pc;
    logic [1:0]  epoch;
    logic        redirect_fire;
    logic [31:0] redirect_pc;
    logic [1:0]  redirect_epoch;
    logic        bpu_redirect_fire;
    logic [31:0] bpu_redirect_target;
    logic        seq_advance;
    logic [31:0] next_pc;
    logic [1:0]  next_epoch;

    s1_if0_pc_update #(
        .XLEN(32),
        .EPOCH_WIDTH(2)
    ) u_dut (
        .pc_i(pc),
        .epoch_i(epoch),
        .redirect_fire_i(redirect_fire),
        .redirect_pc_i(redirect_pc),
        .redirect_epoch_i(redirect_epoch),
        .bpu_redirect_fire_i(bpu_redirect_fire),
        .bpu_redirect_target_i(bpu_redirect_target),
        .seq_advance_i(seq_advance),
        .next_pc_o(next_pc),
        .next_epoch_o(next_epoch)
    );

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        pc = 32'h8000_0000;
        epoch = 2'd1;
        redirect_fire = 1'b0;
        redirect_pc = 32'h9000_0000;
        redirect_epoch = 2'd2;
        bpu_redirect_fire = 1'b0;
        bpu_redirect_target = 32'h8000_0100;
        seq_advance = 1'b0;
        #1;

        `check32("IF0 PC update holds PC", next_pc, 32'h8000_0000);
        `check("IF0 PC update holds epoch", next_epoch == 2'd1);

        seq_advance = 1'b1;
        #1;
        `check32("IF0 PC update sequential advance", next_pc, 32'h8000_0004);
        `check("IF0 PC update sequential keeps epoch", next_epoch == 2'd1);

        bpu_redirect_fire = 1'b1;
        #1;
        `check32("IF0 PC update BPU beats sequential", next_pc, 32'h8000_0100);
        `check("IF0 PC update BPU keeps epoch", next_epoch == 2'd1);

        redirect_fire = 1'b1;
        #1;
        `check32("IF0 PC update redirect has priority", next_pc, 32'h9000_0000);
        `check("IF0 PC update redirect updates epoch", next_epoch == 2'd2);

        seq_advance = 1'b0;
        bpu_redirect_fire = 1'b0;
        redirect_fire = 1'b0;
        pc = 32'hffff_fffc;
        #1;
        `check32("IF0 PC update hold near wrap", next_pc, 32'hffff_fffc);

        seq_advance = 1'b1;
        #1;
        `check32("IF0 PC update sequential wraps naturally", next_pc, 32'h0000_0000);

        finish_tb();
    end
endmodule
