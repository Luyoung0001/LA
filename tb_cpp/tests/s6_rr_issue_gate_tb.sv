`timescale 1ns / 1ps

module s6_rr_issue_gate_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s6_valid;
    logic load_use_hazard;
    logic s7_allowin;
    logic slot1_valid;
    logic slot1_issue_valid;
    logic [3:0] slot1_issue_class;
    logic s6_ready_go;
    logic s6_emit_valid;
    logic s6_allowin;
    logic slot1_emit_valid;
    logic slot1_fire;
    logic [3:0] slot1_emit_class;

    s6_rr_issue_gate u_dut (
        .s6_valid_i(s6_valid),
        .load_use_hazard_i(load_use_hazard),
        .s7_allowin_i(s7_allowin),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .s6_ready_go_o(s6_ready_go),
        .s6_emit_valid_o(s6_emit_valid),
        .s6_allowin_o(s6_allowin),
        .slot1_emit_valid_o(slot1_emit_valid),
        .slot1_fire_o(slot1_fire),
        .slot1_emit_class_o(slot1_emit_class)
    );

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        s6_valid = 1'b0;
        load_use_hazard = 1'b0;
        s7_allowin = 1'b0;
        slot1_valid = 1'b0;
        slot1_issue_valid = 1'b0;
        slot1_issue_class = 4'd0;
        #1;
        `check("S6 gate empty stage accepts input",
               s6_ready_go && !s6_emit_valid && s6_allowin &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        s6_valid = 1'b1;
        s7_allowin = 1'b1;
        #1;
        `check("S6 gate valid ready stage emits and allows input",
               s6_ready_go && s6_emit_valid && s6_allowin &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S6 gate emits and fires selected slot1 with lane0",
               s6_emit_valid && slot1_emit_valid && slot1_fire &&
               slot1_emit_class == 4'b1000);

        s7_allowin = 1'b0;
        #1;
        `check("S6 gate downstream backpressure keeps valid stage",
               s6_ready_go && s6_emit_valid && !s6_allowin &&
               slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'b1000);

        load_use_hazard = 1'b1;
        s7_allowin = 1'b1;
        #1;
        `check("S6 gate load-use hazard blocks emit and input",
               !s6_ready_go && !s6_emit_valid && !s6_allowin &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        s6_valid = 1'b0;
        #1;
        `check("S6 gate empty stage still accepts during hazard",
               !s6_ready_go && !s6_emit_valid && s6_allowin &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        load_use_hazard = 1'b0;
        s6_valid = 1'b1;
        slot1_valid = 1'b0;
        slot1_issue_class = 4'b1111;
        #1;
        `check("S6 gate masks slot1 class when slot1 is invalid",
               s6_emit_valid && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        #1;
        `check("S6 gate masks slot1 class when slot1 is held but not issued",
               s6_emit_valid && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        finish_tb();
    end
endmodule
