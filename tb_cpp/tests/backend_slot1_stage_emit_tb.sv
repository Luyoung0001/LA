`timescale 1ns / 1ps

module backend_slot1_stage_emit_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       stage_emit_valid;
    logic       downstream_allowin;
    logic       slot1_valid;
    logic       slot1_issue_valid;
    logic [3:0] slot1_issue_class;
    logic       slot1_selected;
    logic       slot1_emit_valid;
    logic       slot1_fire;
    logic [3:0] slot1_emit_class;

    backend_slot1_stage_emit u_dut (
        .stage_emit_valid_i(stage_emit_valid),
        .downstream_allowin_i(downstream_allowin),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_selected_o(slot1_selected),
        .slot1_emit_valid_o(slot1_emit_valid),
        .slot1_fire_o(slot1_fire),
        .slot1_emit_class_o(slot1_emit_class)
    );

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        stage_emit_valid = 1'b0;
        downstream_allowin = 1'b0;
        slot1_valid = 1'b0;
        slot1_issue_valid = 1'b0;
        slot1_issue_class = 4'b1010;
        #1;
        `check("SLOT1EMIT idle masks slot1",
               !slot1_selected && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        #1;
        `check("SLOT1EMIT selected waits for stage emit",
               slot1_selected && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        stage_emit_valid = 1'b1;
        #1;
        `check("SLOT1EMIT exposes selected slot1 under backpressure",
               slot1_selected && slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'b1010);

        downstream_allowin = 1'b1;
        #1;
        `check("SLOT1EMIT fires when downstream accepts",
               slot1_selected && slot1_emit_valid && slot1_fire &&
               slot1_emit_class == 4'b1010);

        slot1_issue_valid = 1'b0;
        slot1_issue_class = 4'b1111;
        #1;
        `check("SLOT1EMIT masks held slot1",
               !slot1_selected && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        slot1_valid = 1'b0;
        slot1_issue_valid = 1'b1;
        #1;
        `check("SLOT1EMIT masks invalid slot1",
               !slot1_selected && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        finish_tb();
    end
endmodule
