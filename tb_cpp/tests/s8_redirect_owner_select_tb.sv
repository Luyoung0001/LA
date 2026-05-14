`timescale 1ns / 1ps

module s8_redirect_owner_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic stage_valid;
    logic stage_fire;
    logic lane0_redirect;
    logic lane0_control_flow;
    logic lane0_has_exception;
    logic lane1_ctrl_flow;
    logic lane1_redirect_raw;

    logic lane1_redirect;
    logic redirect_valid;
    logic lane0_bpu_update_valid;
    logic lane1_bpu_update_valid;
    logic bpu_update_valid;

    s8_redirect_owner_select u_dut (
        .stage_valid_i(stage_valid),
        .stage_fire_i(stage_fire),
        .lane0_redirect_i(lane0_redirect),
        .lane0_control_flow_i(lane0_control_flow),
        .lane0_has_exception_i(lane0_has_exception),
        .lane1_ctrl_flow_i(lane1_ctrl_flow),
        .lane1_redirect_raw_i(lane1_redirect_raw),
        .lane1_redirect_o(lane1_redirect),
        .redirect_valid_o(redirect_valid),
        .lane0_bpu_update_valid_o(lane0_bpu_update_valid),
        .lane1_bpu_update_valid_o(lane1_bpu_update_valid),
        .bpu_update_valid_o(bpu_update_valid)
    );

    task automatic clear_inputs;
        begin
            stage_valid = 1'b0;
            stage_fire = 1'b0;
            lane0_redirect = 1'b0;
            lane0_control_flow = 1'b0;
            lane0_has_exception = 1'b0;
            lane1_ctrl_flow = 1'b0;
            lane1_redirect_raw = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("ROWN idle is silent",
               !lane1_redirect && !redirect_valid &&
               !lane0_bpu_update_valid && !lane1_bpu_update_valid &&
               !bpu_update_valid);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_redirect_raw = 1'b1;
        #1;
        `check("ROWN lane1 may own redirect when older lane is quiet",
               lane1_redirect && redirect_valid &&
               !lane0_bpu_update_valid && lane1_bpu_update_valid &&
               bpu_update_valid);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane0_redirect = 1'b1;
        lane0_control_flow = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_redirect_raw = 1'b1;
        #1;
        `check("ROWN lane0 redirect keeps older-lane priority",
               lane1_redirect && redirect_valid &&
               lane0_bpu_update_valid && !lane1_bpu_update_valid &&
               bpu_update_valid);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane0_has_exception = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_redirect_raw = 1'b1;
        #1;
        `check("ROWN lane0 exception suppresses lane1 redirect ownership",
               !lane1_redirect && !redirect_valid &&
               !lane0_bpu_update_valid && !lane1_bpu_update_valid &&
               !bpu_update_valid);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b1;
        lane0_control_flow = 1'b1;
        lane1_ctrl_flow = 1'b1;
        #1;
        `check("ROWN only one BPU update owner is visible",
               lane0_bpu_update_valid && !lane1_bpu_update_valid &&
               bpu_update_valid);

        clear_inputs();
        stage_valid = 1'b1;
        stage_fire = 1'b0;
        lane0_redirect = 1'b1;
        lane1_ctrl_flow = 1'b1;
        lane1_redirect_raw = 1'b1;
        #1;
        `check("ROWN redirect visibility is stage-valid based, BPU update needs fire",
               redirect_valid && lane1_redirect &&
               !lane0_bpu_update_valid && !lane1_bpu_update_valid &&
               !bpu_update_valid);

        finish_tb();
    end
endmodule
