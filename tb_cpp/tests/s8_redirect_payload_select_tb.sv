`timescale 1ns / 1ps

module s8_redirect_payload_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        lane0_redirect;
    logic [31:0] lane0_actual_target;
    logic        lane0_branch_taken;
    logic        lane0_bpu_update_valid;
    logic [31:0] lane0_pc;
    logic        lane0_actual_taken;
    logic [31:0] lane0_branch_target;
    logic [31:0] lane0_jump_target;
    logic        lane0_jump_taken;
    logic        lane0_inst_bl;
    logic        lane0_inst_ret;
    logic        lane0_is_jal;
    logic        lane0_inst_indirect_jirl;

    logic        lane1_redirect;
    logic [31:0] lane1_actual_target;
    logic        lane1_bpu_update_valid;
    logic [31:0] lane1_pc;
    logic        lane1_actual_taken;
    logic [31:0] lane1_branch_target;
    logic [31:0] lane1_jump_target;
    logic        lane1_uncond_b;
    logic        lane1_uncond_bl;
    logic        lane1_uncond_jirl;
    logic        lane1_ret;
    logic        lane1_indirect_jirl;

    logic [31:0] redirect_pc;
    logic        branch_taken;
    logic [31:0] bpu_update_pc;
    logic        bpu_update_taken;
    logic [31:0] bpu_update_target;
    logic        bpu_update_is_call;
    logic        bpu_update_is_ret;
    logic        bpu_update_is_jmp;
    logic        bpu_update_is_indirect_jmp;

    s8_redirect_payload_select u_dut (
        .lane0_redirect_i(lane0_redirect),
        .lane0_actual_target_i(lane0_actual_target),
        .lane0_branch_taken_i(lane0_branch_taken),
        .lane0_bpu_update_valid_i(lane0_bpu_update_valid),
        .lane0_pc_i(lane0_pc),
        .lane0_actual_taken_i(lane0_actual_taken),
        .lane0_branch_target_i(lane0_branch_target),
        .lane0_jump_target_i(lane0_jump_target),
        .lane0_jump_taken_i(lane0_jump_taken),
        .lane0_inst_bl_i(lane0_inst_bl),
        .lane0_inst_ret_i(lane0_inst_ret),
        .lane0_is_jal_i(lane0_is_jal),
        .lane0_inst_indirect_jirl_i(lane0_inst_indirect_jirl),
        .lane1_redirect_i(lane1_redirect),
        .lane1_actual_target_i(lane1_actual_target),
        .lane1_bpu_update_valid_i(lane1_bpu_update_valid),
        .lane1_pc_i(lane1_pc),
        .lane1_actual_taken_i(lane1_actual_taken),
        .lane1_branch_target_i(lane1_branch_target),
        .lane1_jump_target_i(lane1_jump_target),
        .lane1_uncond_b_i(lane1_uncond_b),
        .lane1_uncond_bl_i(lane1_uncond_bl),
        .lane1_uncond_jirl_i(lane1_uncond_jirl),
        .lane1_ret_i(lane1_ret),
        .lane1_indirect_jirl_i(lane1_indirect_jirl),
        .redirect_pc_o(redirect_pc),
        .branch_taken_o(branch_taken),
        .bpu_update_pc_o(bpu_update_pc),
        .bpu_update_taken_o(bpu_update_taken),
        .bpu_update_target_o(bpu_update_target),
        .bpu_update_is_call_o(bpu_update_is_call),
        .bpu_update_is_ret_o(bpu_update_is_ret),
        .bpu_update_is_jmp_o(bpu_update_is_jmp),
        .bpu_update_is_indirect_jmp_o(bpu_update_is_indirect_jmp)
    );

    task automatic clear_inputs;
        begin
            lane0_redirect = 1'b0;
            lane0_actual_target = 32'h1c01_0010;
            lane0_branch_taken = 1'b0;
            lane0_bpu_update_valid = 1'b0;
            lane0_pc = 32'h1c01_0000;
            lane0_actual_taken = 1'b0;
            lane0_branch_target = 32'h1c01_0010;
            lane0_jump_target = 32'h1c01_0020;
            lane0_jump_taken = 1'b0;
            lane0_inst_bl = 1'b0;
            lane0_inst_ret = 1'b0;
            lane0_is_jal = 1'b0;
            lane0_inst_indirect_jirl = 1'b0;

            lane1_redirect = 1'b0;
            lane1_actual_target = 32'h1c01_0030;
            lane1_bpu_update_valid = 1'b0;
            lane1_pc = 32'h1c01_0004;
            lane1_actual_taken = 1'b0;
            lane1_branch_target = 32'h1c01_0030;
            lane1_jump_target = 32'h1c01_0040;
            lane1_uncond_b = 1'b0;
            lane1_uncond_bl = 1'b0;
            lane1_uncond_jirl = 1'b0;
            lane1_ret = 1'b0;
            lane1_indirect_jirl = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("RPAY idle keeps BPU payload zero",
               !branch_taken && !bpu_update_taken &&
               !bpu_update_is_call && !bpu_update_is_ret &&
               !bpu_update_is_jmp && !bpu_update_is_indirect_jmp);
        `check32("RPAY idle zeroes update pc", bpu_update_pc, 32'h0000_0000);
        `check32("RPAY idle zeroes update target", bpu_update_target, 32'h0000_0000);

        clear_inputs();
        lane0_redirect = 1'b1;
        lane0_branch_taken = 1'b1;
        lane0_bpu_update_valid = 1'b1;
        lane0_actual_taken = 1'b1;
        lane0_actual_target = 32'h1c01_0110;
        lane0_branch_target = 32'h1c01_0110;
        #1;
        `check32("RPAY lane0 redirect target wins", redirect_pc, 32'h1c01_0110);
        `check("RPAY lane0 branch payload stays branch-like",
               branch_taken && bpu_update_taken &&
               !bpu_update_is_call && !bpu_update_is_ret &&
               !bpu_update_is_jmp && !bpu_update_is_indirect_jmp);
        `check32("RPAY lane0 branch update pc", bpu_update_pc, 32'h1c01_0000);
        `check32("RPAY lane0 branch update target", bpu_update_target, 32'h1c01_0110);

        clear_inputs();
        lane1_redirect = 1'b1;
        lane1_bpu_update_valid = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_actual_target = 32'h1c01_0220;
        lane1_branch_target = 32'h1c01_0220;
        #1;
        `check32("RPAY lane1 redirect target appears when older lane is quiet", redirect_pc, 32'h1c01_0220);
        `check("RPAY lane1 branch keeps branch type",
               !branch_taken && bpu_update_taken &&
               !bpu_update_is_call && !bpu_update_is_ret &&
               !bpu_update_is_jmp && !bpu_update_is_indirect_jmp);
        `check32("RPAY lane1 branch update pc", bpu_update_pc, 32'h1c01_0004);
        `check32("RPAY lane1 branch update target", bpu_update_target, 32'h1c01_0220);

        clear_inputs();
        lane1_redirect = 1'b1;
        lane1_bpu_update_valid = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_actual_target = 32'h1c01_0330;
        lane1_branch_target = 32'h1c01_0440;
        lane1_jump_target = 32'h1c01_0550;
        lane1_uncond_bl = 1'b1;
        #1;
        `check32("RPAY lane1 BL redirect uses actual target", redirect_pc, 32'h1c01_0330);
        `check("RPAY lane1 BL marks call and jump",
               bpu_update_taken && bpu_update_is_call &&
               bpu_update_is_jmp && !bpu_update_is_ret &&
               !bpu_update_is_indirect_jmp);
        `check32("RPAY lane1 BL trains jump target", bpu_update_target, 32'h1c01_0550);

        clear_inputs();
        lane0_redirect = 1'b1;
        lane0_bpu_update_valid = 1'b1;
        lane0_actual_taken = 1'b1;
        lane0_actual_target = 32'h1c01_0660;
        lane0_jump_target = 32'h1c01_0660;
        lane0_jump_taken = 1'b1;
        lane0_is_jal = 1'b1;
        #1;
        `check("RPAY lane0 direct jump marks jmp only",
               bpu_update_taken && bpu_update_is_jmp &&
               !bpu_update_is_call && !bpu_update_is_ret &&
               !bpu_update_is_indirect_jmp);
        `check32("RPAY lane0 jump target uses jump target", bpu_update_target, 32'h1c01_0660);

        clear_inputs();
        lane1_redirect = 1'b1;
        lane1_bpu_update_valid = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_actual_target = 32'h1c02_0020;
        lane1_jump_target = 32'h1c02_0020;
        lane1_uncond_jirl = 1'b1;
        lane1_indirect_jirl = 1'b1;
        #1;
        `check("RPAY lane1 JIRL marks indirect jump only",
               bpu_update_taken && !bpu_update_is_call &&
               !bpu_update_is_ret && !bpu_update_is_jmp &&
               bpu_update_is_indirect_jmp);
        `check32("RPAY lane1 JIRL uses jump target", bpu_update_target, 32'h1c02_0020);

        finish_tb();
    end
endmodule
