`timescale 1ns / 1ps

module s8_redirect_sideband_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        stage_valid;
    logic        stage_fire;
    logic [31:0] lane0_pc;
    logic        lane0_pred_taken;
    logic        lane0_is_branch;
    logic        lane0_is_jal;
    logic        lane0_is_jalr;
    logic        lane0_branch_redirected;
    logic        lane0_branch_taken;
    logic        lane0_jump_taken;
    logic        lane0_control_flow;
    logic        lane0_actual_taken;
    logic [31:0] lane0_actual_target;
    logic [31:0] lane0_branch_target;
    logic [31:0] lane0_jump_target;
    logic        lane0_pred_target_miss;
    logic        lane0_redirect_raw;
    logic        lane0_inst_bl;
    logic        lane0_inst_ret;
    logic        lane0_inst_indirect_jirl;
    logic        lane0_has_exception;

    logic [31:0] lane1_pc;
    logic        lane1_ctrl_flow;
    logic        lane1_actual_taken;
    logic [31:0] lane1_actual_target;
    logic [31:0] lane1_branch_target;
    logic [31:0] lane1_jump_target;
    logic        lane1_redirect_raw;
    logic        lane1_uncond_b;
    logic        lane1_uncond_bl;
    logic        lane1_uncond_jirl;
    logic        lane1_ret;
    logic        lane1_indirect_jirl;

    logic        redirect_valid;
    logic [31:0] redirect_pc;
    logic        branch_taken;
    logic        lane0_bpu_update_valid;
    logic        lane1_bpu_update_valid;
    logic        bpu_update_valid;
    logic [31:0] bpu_update_pc;
    logic        bpu_update_taken;
    logic [31:0] bpu_update_target;
    logic        bpu_update_is_call;
    logic        bpu_update_is_ret;
    logic        bpu_update_is_jmp;
    logic        bpu_update_is_indirect_jmp;
    logic        lane0_redirect;
    logic        lane1_redirect;

    s8_redirect_sideband u_dut (
        .stage_valid_i(stage_valid),
        .stage_fire_i(stage_fire),
        .lane0_pc_i(lane0_pc),
        .lane0_pred_taken_i(lane0_pred_taken),
        .lane0_is_branch_i(lane0_is_branch),
        .lane0_is_jal_i(lane0_is_jal),
        .lane0_is_jalr_i(lane0_is_jalr),
        .lane0_branch_redirected_i(lane0_branch_redirected),
        .lane0_branch_taken_i(lane0_branch_taken),
        .lane0_jump_taken_i(lane0_jump_taken),
        .lane0_control_flow_i(lane0_control_flow),
        .lane0_actual_taken_i(lane0_actual_taken),
        .lane0_actual_target_i(lane0_actual_target),
        .lane0_branch_target_i(lane0_branch_target),
        .lane0_jump_target_i(lane0_jump_target),
        .lane0_pred_target_miss_i(lane0_pred_target_miss),
        .lane0_redirect_raw_i(lane0_redirect_raw),
        .lane0_inst_bl_i(lane0_inst_bl),
        .lane0_inst_ret_i(lane0_inst_ret),
        .lane0_inst_indirect_jirl_i(lane0_inst_indirect_jirl),
        .lane0_has_exception_i(lane0_has_exception),
        .lane1_pc_i(lane1_pc),
        .lane1_ctrl_flow_i(lane1_ctrl_flow),
        .lane1_actual_taken_i(lane1_actual_taken),
        .lane1_actual_target_i(lane1_actual_target),
        .lane1_branch_target_i(lane1_branch_target),
        .lane1_jump_target_i(lane1_jump_target),
        .lane1_redirect_raw_i(lane1_redirect_raw),
        .lane1_uncond_b_i(lane1_uncond_b),
        .lane1_uncond_bl_i(lane1_uncond_bl),
        .lane1_uncond_jirl_i(lane1_uncond_jirl),
        .lane1_ret_i(lane1_ret),
        .lane1_indirect_jirl_i(lane1_indirect_jirl),
        .redirect_valid_o(redirect_valid),
        .redirect_pc_o(redirect_pc),
        .branch_taken_o(branch_taken),
        .lane0_bpu_update_valid_o(lane0_bpu_update_valid),
        .lane1_bpu_update_valid_o(lane1_bpu_update_valid),
        .bpu_update_valid_o(bpu_update_valid),
        .bpu_update_pc_o(bpu_update_pc),
        .bpu_update_taken_o(bpu_update_taken),
        .bpu_update_target_o(bpu_update_target),
        .bpu_update_is_call_o(bpu_update_is_call),
        .bpu_update_is_ret_o(bpu_update_is_ret),
        .bpu_update_is_jmp_o(bpu_update_is_jmp),
        .bpu_update_is_indirect_jmp_o(bpu_update_is_indirect_jmp),
        .lane0_redirect_o(lane0_redirect),
        .lane1_redirect_o(lane1_redirect)
    );

    task automatic clear_inputs;
        begin
            stage_valid = 1'b0;
            stage_fire = 1'b0;
            lane0_pc = 32'h1c01_0000;
            lane0_pred_taken = 1'b0;
            lane0_is_branch = 1'b0;
            lane0_is_jal = 1'b0;
            lane0_is_jalr = 1'b0;
            lane0_branch_redirected = 1'b0;
            lane0_branch_taken = 1'b0;
            lane0_jump_taken = 1'b0;
            lane0_control_flow = 1'b0;
            lane0_actual_taken = 1'b0;
            lane0_actual_target = 32'h1c01_0010;
            lane0_branch_target = 32'h1c01_0010;
            lane0_jump_target = 32'h1c01_0020;
            lane0_pred_target_miss = 1'b0;
            lane0_redirect_raw = 1'b0;
            lane0_inst_bl = 1'b0;
            lane0_inst_ret = 1'b0;
            lane0_inst_indirect_jirl = 1'b0;
            lane0_has_exception = 1'b0;
            lane1_pc = 32'h1c01_0004;
            lane1_ctrl_flow = 1'b0;
            lane1_actual_taken = 1'b0;
            lane1_actual_target = 32'h1c01_0030;
            lane1_branch_target = 32'h1c01_0030;
            lane1_jump_target = 32'h1c01_0040;
            lane1_redirect_raw = 1'b0;
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
        `check("S8 redirect sideband idle is silent",
               !redirect_valid && !bpu_update_valid &&
               !lane0_redirect && !lane1_redirect);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane0_is_branch = 1'b1;
        lane0_control_flow = 1'b1;
        lane0_branch_taken = 1'b1;
        lane0_actual_taken = 1'b1;
        lane0_redirect_raw = 1'b1;
        lane0_actual_target = 32'h1c01_0110;
        lane0_branch_target = 32'h1c01_0110;
        #1;
        `check("S8 redirect sideband lane0 redirect wins when alone",
               redirect_valid && lane0_redirect && !lane1_redirect &&
               lane0_bpu_update_valid && !lane1_bpu_update_valid &&
               bpu_update_valid && branch_taken);
        `check32("S8 redirect sideband lane0 redirect pc", redirect_pc, 32'h1c01_0110);
        `check32("S8 redirect sideband lane0 update pc", bpu_update_pc, 32'h1c01_0000);
        `check32("S8 redirect sideband lane0 update target", bpu_update_target, 32'h1c01_0110);
        `check("S8 redirect sideband lane0 branch update type",
               bpu_update_taken && !bpu_update_is_jmp &&
               !bpu_update_is_call && !bpu_update_is_ret);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_redirect_raw = 1'b1;
        lane1_actual_target = 32'h1c01_0220;
        lane1_branch_target = 32'h1c01_0220;
        #1;
        `check("S8 redirect sideband lane1 branch can own redirect",
               redirect_valid && !lane0_redirect && lane1_redirect &&
               !lane0_bpu_update_valid && lane1_bpu_update_valid &&
               bpu_update_valid);
        `check32("S8 redirect sideband lane1 redirect pc", redirect_pc, 32'h1c01_0220);
        `check32("S8 redirect sideband lane1 update pc", bpu_update_pc, 32'h1c01_0004);
        `check32("S8 redirect sideband lane1 branch target", bpu_update_target, 32'h1c01_0220);
        `check("S8 redirect sideband lane1 branch stays non-jump",
               bpu_update_taken && !bpu_update_is_jmp &&
               !bpu_update_is_call && !bpu_update_is_ret);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_redirect_raw = 1'b1;
        lane1_actual_target = 32'h1c01_0330;
        lane1_branch_target = 32'h1c01_0440;
        lane1_jump_target = 32'h1c01_0550;
        lane1_uncond_bl = 1'b1;
        #1;
        `check("S8 redirect sideband lane1 BL updates jump metadata",
               redirect_valid && lane1_bpu_update_valid &&
               bpu_update_valid && bpu_update_is_call &&
               bpu_update_is_jmp && !bpu_update_is_ret);
        `check32("S8 redirect sideband lane1 BL uses actual redirect target", redirect_pc, 32'h1c01_0330);
        `check32("S8 redirect sideband lane1 BL trains jump target", bpu_update_target, 32'h1c01_0550);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane0_is_jal = 1'b1;
        lane0_control_flow = 1'b1;
        lane0_jump_taken = 1'b1;
        lane0_actual_taken = 1'b1;
        lane0_redirect_raw = 1'b1;
        lane0_actual_target = 32'h1c01_0660;
        lane0_jump_target = 32'h1c01_0660;
        lane1_ctrl_flow = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_redirect_raw = 1'b1;
        lane1_actual_target = 32'h1c01_0770;
        lane1_branch_target = 32'h1c01_0770;
        #1;
        `check("S8 redirect sideband lane0 redirect keeps older-lane priority",
               redirect_valid && lane0_redirect && lane1_redirect &&
               lane0_bpu_update_valid && !lane1_bpu_update_valid);
        `check32("S8 redirect sideband lane0 priority target", redirect_pc, 32'h1c01_0660);
        `check32("S8 redirect sideband lane0 jump target", bpu_update_target, 32'h1c01_0660);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane0_has_exception = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_actual_taken = 1'b1;
        lane1_redirect_raw = 1'b1;
        lane1_actual_target = 32'h1c01_0880;
        lane1_branch_target = 32'h1c01_0880;
        #1;
        `check("S8 redirect sideband lane0 exception suppresses lane1 redirect and update",
               !redirect_valid && !lane1_redirect &&
               !lane1_bpu_update_valid && !bpu_update_valid);

        finish_tb();
    end
endmodule
