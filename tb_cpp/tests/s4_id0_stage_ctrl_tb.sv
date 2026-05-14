`timescale 1ns / 1ps

module s4_id0_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s4_valid;
    logic s3_to_s4_valid;
    logic s5_allowin;
    logic epoch_match;

    logic ready_go;
    logic stale;
    logic allowin;
    logic capture;
    logic to_next_valid;
    logic fire;

    s4_id0_stage_ctrl u_dut (
        .s4_valid_i(s4_valid),
        .s3_to_s4_valid_i(s3_to_s4_valid),
        .s5_allowin_i(s5_allowin),
        .epoch_match_i(epoch_match),
        .ready_go_o(ready_go),
        .stale_o(stale),
        .allowin_o(allowin),
        .capture_o(capture),
        .to_next_valid_o(to_next_valid),
        .fire_o(fire)
    );

    task automatic clear_inputs;
        begin
            s4_valid = 1'b0;
            s3_to_s4_valid = 1'b0;
            s5_allowin = 1'b0;
            epoch_match = 1'b1;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S4CTRL empty stage accepts upstream",
               ready_go && allowin && !stale && !to_next_valid && !fire);

        s3_to_s4_valid = 1'b1;
        #1;
        `check("S4CTRL empty stage captures upstream",
               capture && allowin && !to_next_valid && !fire);

        clear_inputs();
        s4_valid = 1'b1;
        s5_allowin = 1'b1;
        #1;
        `check("S4CTRL valid same-epoch stage fires",
               ready_go && allowin && !stale && to_next_valid && fire);

        s3_to_s4_valid = 1'b1;
        #1;
        `check("S4CTRL valid stage can refill while firing",
               capture && to_next_valid && fire);

        clear_inputs();
        s4_valid = 1'b1;
        s5_allowin = 1'b0;
        s3_to_s4_valid = 1'b1;
        #1;
        `check("S4CTRL issue backpressure holds same-epoch packet",
               ready_go && !allowin && !capture && to_next_valid && !fire);

        epoch_match = 1'b0;
        #1;
        `check("S4CTRL stale packet is dropped despite issue backpressure",
               stale && allowin && capture && !to_next_valid && !fire);

        s3_to_s4_valid = 1'b0;
        #1;
        `check("S4CTRL stale packet can clear without refill",
               stale && allowin && !capture && !to_next_valid && !fire);

        finish_tb();
    end
endmodule
