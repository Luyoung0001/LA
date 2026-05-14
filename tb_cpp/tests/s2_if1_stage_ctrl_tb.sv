`timescale 1ns / 1ps

module s2_if1_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s2_valid;
    logic s1_to_s2_valid;
    logic s3_allowin;
    logic pred_valid;
    logic pred_taken;
    logic bpu_redirect_needed;
    logic s3_dup_drop;

    logic ready_go;
    logic allowin;
    logic capture;
    logic to_next_valid;
    logic fire;
    logic prediction_window;
    logic bpu_redirect_valid;

    s2_if1_stage_ctrl #(.BPU_ENABLE(1)) u_dut (
        .s2_valid_i(s2_valid),
        .s1_to_s2_valid_i(s1_to_s2_valid),
        .s3_allowin_i(s3_allowin),
        .pred_valid_i(pred_valid),
        .pred_taken_i(pred_taken),
        .bpu_redirect_needed_i(bpu_redirect_needed),
        .s3_dup_drop_i(s3_dup_drop),
        .ready_go_o(ready_go),
        .allowin_o(allowin),
        .capture_o(capture),
        .to_next_valid_o(to_next_valid),
        .fire_o(fire),
        .prediction_window_o(prediction_window),
        .bpu_redirect_valid_o(bpu_redirect_valid)
    );

    task automatic clear_inputs;
        begin
            s2_valid = 1'b0;
            s1_to_s2_valid = 1'b0;
            s3_allowin = 1'b0;
            pred_valid = 1'b0;
            pred_taken = 1'b0;
            bpu_redirect_needed = 1'b0;
            s3_dup_drop = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S2CTRL empty stage accepts input",
               ready_go && allowin && !to_next_valid && !fire);

        s1_to_s2_valid = 1'b1;
        #1;
        `check("S2CTRL empty stage captures upstream",
               capture && allowin && !to_next_valid && !fire);

        clear_inputs();
        s2_valid = 1'b1;
        s3_allowin = 1'b1;
        #1;
        `check("S2CTRL valid stage fires",
               ready_go && allowin && !capture && to_next_valid && fire);

        s1_to_s2_valid = 1'b1;
        #1;
        `check("S2CTRL valid stage can refill while firing",
               capture && to_next_valid && fire);

        clear_inputs();
        s2_valid = 1'b1;
        s3_allowin = 1'b0;
        s1_to_s2_valid = 1'b1;
        pred_valid = 1'b1;
        pred_taken = 1'b1;
        bpu_redirect_needed = 1'b1;
        #1;
        `check("S2CTRL downstream backpressure holds redirect",
               ready_go && !allowin && !capture && to_next_valid &&
               !fire && !prediction_window && !bpu_redirect_valid);

        s3_allowin = 1'b1;
        #1;
        `check("S2CTRL taken prediction redirects only when firing",
               fire && prediction_window && bpu_redirect_valid);

        pred_taken = 1'b0;
        #1;
        `check("S2CTRL not-taken prediction opens sideband without redirect",
               fire && prediction_window && !bpu_redirect_valid);

        pred_taken = 1'b1;
        bpu_redirect_needed = 1'b0;
        #1;
        `check("S2CTRL sequential prediction suppresses sideband",
               fire && !prediction_window && !bpu_redirect_valid);

        bpu_redirect_needed = 1'b1;
        s3_dup_drop = 1'b1;
        #1;
        `check("S2CTRL duplicate drop suppresses prediction side effects",
               fire && !prediction_window && !bpu_redirect_valid);

        finish_tb();
    end
endmodule
