`timescale 1ns / 1ps

module s9_mem_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s9_valid;
    logic s8_to_s9_valid;
    logic s10_allowin;
    logic slot1_valid;
    logic slot1_issue_valid;
    logic [3:0] slot1_issue_class;

    logic ready_go;
    logic allowin;
    logic capture;
    logic to_next_valid;
    logic fire;
    logic slot1_emit_valid;
    logic slot1_fire;
    logic [3:0] slot1_emit_class;

    s9_mem_stage_ctrl u_dut (
        .s9_valid_i(s9_valid),
        .s8_to_s9_valid_i(s8_to_s9_valid),
        .s10_allowin_i(s10_allowin),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .ready_go_o(ready_go),
        .allowin_o(allowin),
        .capture_o(capture),
        .to_next_valid_o(to_next_valid),
        .fire_o(fire),
        .slot1_emit_valid_o(slot1_emit_valid),
        .slot1_fire_o(slot1_fire),
        .slot1_emit_class_o(slot1_emit_class)
    );

    task automatic clear_inputs;
        begin
            s9_valid = 1'b0;
            s8_to_s9_valid = 1'b0;
            s10_allowin = 1'b0;
            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S9CTRL empty stage accepts input",
               ready_go && allowin && !to_next_valid && !fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        s8_to_s9_valid = 1'b1;
        #1;
        `check("S9CTRL empty stage captures upstream",
               capture && allowin && !to_next_valid && !fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        clear_inputs();
        s9_valid = 1'b1;
        s10_allowin = 1'b1;
        #1;
        `check("S9CTRL valid ready stage fires",
               ready_go && allowin && !capture && to_next_valid && fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        #1;
        `check("S9CTRL emits and fires selected slot1 with lane0",
               to_next_valid && fire && slot1_emit_valid && slot1_fire &&
               slot1_emit_class == 4'b0100);

        s8_to_s9_valid = 1'b1;
        #1;
        `check("S9CTRL valid ready stage can refill while firing",
               capture && to_next_valid && fire &&
               slot1_emit_valid && slot1_fire && slot1_emit_class == 4'b0100);

        clear_inputs();
        s9_valid = 1'b1;
        s10_allowin = 1'b0;
        s8_to_s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        #1;
        `check("S9CTRL downstream backpressure holds stage",
               ready_go && !allowin && !capture && to_next_valid && !fire &&
               slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'b0100);

        clear_inputs();
        s9_valid = 1'b0;
        s10_allowin = 1'b0;
        s8_to_s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0100;
        #1;
        `check("S9CTRL empty stage captures despite downstream backpressure",
               ready_go && allowin && capture && !to_next_valid && !fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        clear_inputs();
        s9_valid = 1'b1;
        s10_allowin = 1'b1;
        slot1_issue_class = 4'b1111;
        #1;
        `check("S9CTRL masks slot1 class when slot1 is invalid",
               to_next_valid && fire && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        #1;
        `check("S9CTRL masks slot1 class when slot1 is held but not issued",
               to_next_valid && fire && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        finish_tb();
    end
endmodule
