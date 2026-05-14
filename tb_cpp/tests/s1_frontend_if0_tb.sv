`timescale 1ns / 1ps

module s1_frontend_if0_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s2_allowin, valid, redirect_valid, bpu_redirect_valid;
    logic [31:0] redirect_pc, bpu_redirect_target, pc;
    logic [1:0] redirect_epoch, epoch;
    s1_frontend_if0 #(.XLEN(32), .EPOCH_WIDTH(2), .RESET_PC(32'h8000_0000)) u_dut (
        .clk(clk), .rst_n(rst_n), .s2_allowin(s2_allowin), .s1_to_s2_valid(valid),
        .redirect_valid_i(redirect_valid), .redirect_pc_i(redirect_pc), .redirect_epoch_i(redirect_epoch),
        .bpu_redirect_valid_i(bpu_redirect_valid), .bpu_redirect_target_i(bpu_redirect_target),
        .s1_pc_o(pc), .s1_epoch_o(epoch)
    );

    initial begin
        tb_start();
        s2_allowin = 1'b1; redirect_valid = 0; redirect_pc = 0; redirect_epoch = 0; bpu_redirect_valid = 0; bpu_redirect_target = 0;
        reset_dut();
        `check("S1 valid after reset", valid);
        `check("S1 reset epoch", epoch == 2'd0);
        `check32("S1 reset PC after two accepted cycles", pc, 32'h80000008);
        tick();
        `check32("S1 sequential PC", pc, 32'h8000000c);
        `check("S1 sequential keeps epoch", epoch == 2'd0);
        s2_allowin = 1'b0; tick(); tick();
        `check32("S1 backpressure hold", pc, 32'h8000000c);
        `check("S1 backpressure holds epoch", epoch == 2'd0);
        redirect_valid = 1'b1; redirect_pc = 32'h90000000;
        redirect_epoch = 2'd2;
        bpu_redirect_valid = 1'b1; bpu_redirect_target = 32'hdeadbeef; tick();
        `check32("S1 redirect priority", pc, 32'h90000000);
        `check("S1 redirect updates epoch", epoch == 2'd2);
        redirect_valid = 1'b0;
        bpu_redirect_valid = 1'b1; bpu_redirect_target = 32'h90000040; tick();
        `check32("S1 BPU redirect updates PC", pc, 32'h90000040);
        `check("S1 BPU redirect keeps epoch", epoch == 2'd2);
        finish_tb();
    end
endmodule
