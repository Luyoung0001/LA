`timescale 1ns / 1ps

module s5_issue_state_flow_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s5_valid;
    logic current_packet_accept;
    logic promote_slot1;
    logic hold_packet_pop;
    logic hold_packet_valid;
    logic hold_packet_rf_ready;
    logic current_packet_load;
    logic hold_packet_track_rf;
    logic slot1_clear;
    logic slot1_load_hold;
    logic slot1_load_s4;
    logic slot1_track_rf;
    logic slot0_load_promote;
    logic slot0_load_hold;
    logic slot0_load_s4;
    logic slot0_track_rf;

    s5_issue_state_flow u_dut (
        .s5_valid_i(s5_valid),
        .current_packet_load_i(current_packet_accept),
        .promote_slot1_i(promote_slot1),
        .hold_packet_pop_i(hold_packet_pop),
        .hold_packet_valid_i(hold_packet_valid),
        .hold_packet_rf_ready_i(hold_packet_rf_ready),
        .current_packet_load_o(current_packet_load),
        .hold_packet_track_rf_o(hold_packet_track_rf),
        .slot1_clear_o(slot1_clear),
        .slot1_load_hold_o(slot1_load_hold),
        .slot1_load_s4_o(slot1_load_s4),
        .slot1_track_rf_o(slot1_track_rf),
        .slot0_load_promote_o(slot0_load_promote),
        .slot0_load_hold_o(slot0_load_hold),
        .slot0_load_s4_o(slot0_load_s4),
        .slot0_track_rf_o(slot0_track_rf)
    );

    task automatic clear_inputs;
        begin
            s5_valid = 1'b0;
            current_packet_accept = 1'b0;
            promote_slot1 = 1'b0;
            hold_packet_pop = 1'b0;
            hold_packet_valid = 1'b0;
            hold_packet_rf_ready = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S5 state flow idle has no loads",
               !current_packet_load && !slot0_track_rf && !slot1_track_rf);

        s5_valid = 1'b1;
        #1;
        `check("S5 state flow tracks held slot state while valid",
               slot0_track_rf && slot1_track_rf && !hold_packet_track_rf);

        current_packet_accept = 1'b1;
        #1;
        `check("S5 state flow loads accepted current packet",
               current_packet_load && slot0_load_s4 && slot1_load_s4 &&
               !slot0_track_rf && !slot1_track_rf);

        current_packet_accept = 1'b0;
        promote_slot1 = 1'b1;
        #1;
        `check("S5 state flow promotes slot1 into slot0 and clears slot1",
               slot0_load_promote && slot1_clear &&
               !slot0_track_rf && !slot1_track_rf);

        promote_slot1 = 1'b0;
        hold_packet_pop = 1'b1;
        #1;
        `check("S5 state flow loads held packet on hold pop",
               slot0_load_hold && slot1_load_hold &&
               !slot0_track_rf && !slot1_track_rf);

        current_packet_accept = 1'b1;
        #1;
        `check("S5 state flow pop beats same-cycle upstream load",
               !current_packet_load && slot0_load_hold && slot1_load_hold &&
               !slot0_load_s4 && !slot1_load_s4);

        current_packet_accept = 1'b0;
        hold_packet_pop = 1'b0;
        hold_packet_valid = 1'b1;
        hold_packet_rf_ready = 1'b1;
        #1;
        `check("S5 state flow refreshes held RF base while waiting",
               hold_packet_track_rf && slot0_track_rf && slot1_track_rf);

        promote_slot1 = 1'b1;
        #1;
        `check("S5 state flow promote suppresses held RF tracking",
               !hold_packet_track_rf && slot0_load_promote && slot1_clear);

        finish_tb();
    end
endmodule
