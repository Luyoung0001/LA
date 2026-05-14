`timescale 1ns / 1ps

module s5_issue_queue_flow_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

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

    logic current_packet_load_o;
    logic hold_packet_track_rf_o;
    logic slot1_clear_o;
    logic slot1_load_hold_o;
    logic slot1_load_s4_o;
    logic slot1_track_rf_o;
    logic slot0_load_promote_o;
    logic slot0_load_hold_o;
    logic slot0_load_s4_o;
    logic slot0_track_rf_o;

    s5_issue_queue_flow_packet u_dut (
        .current_packet_load_i(current_packet_load),
        .hold_packet_track_rf_i(hold_packet_track_rf),
        .slot1_clear_i(slot1_clear),
        .slot1_load_hold_i(slot1_load_hold),
        .slot1_load_s4_i(slot1_load_s4),
        .slot1_track_rf_i(slot1_track_rf),
        .slot0_load_promote_i(slot0_load_promote),
        .slot0_load_hold_i(slot0_load_hold),
        .slot0_load_s4_i(slot0_load_s4),
        .slot0_track_rf_i(slot0_track_rf),
        .current_packet_load_o(current_packet_load_o),
        .hold_packet_track_rf_o(hold_packet_track_rf_o),
        .slot1_clear_o(slot1_clear_o),
        .slot1_load_hold_o(slot1_load_hold_o),
        .slot1_load_s4_o(slot1_load_s4_o),
        .slot1_track_rf_o(slot1_track_rf_o),
        .slot0_load_promote_o(slot0_load_promote_o),
        .slot0_load_hold_o(slot0_load_hold_o),
        .slot0_load_s4_o(slot0_load_s4_o),
        .slot0_track_rf_o(slot0_track_rf_o)
    );

    task automatic clear_inputs;
        begin
            current_packet_load = 1'b0;
            hold_packet_track_rf = 1'b0;
            slot1_clear = 1'b0;
            slot1_load_hold = 1'b0;
            slot1_load_s4 = 1'b0;
            slot1_track_rf = 1'b0;
            slot0_load_promote = 1'b0;
            slot0_load_hold = 1'b0;
            slot0_load_s4 = 1'b0;
            slot0_track_rf = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("QFLOW idle clears all state actions",
               !current_packet_load_o && !hold_packet_track_rf_o &&
               !slot1_clear_o && !slot1_load_hold_o && !slot1_load_s4_o &&
               !slot1_track_rf_o && !slot0_load_promote_o &&
               !slot0_load_hold_o && !slot0_load_s4_o && !slot0_track_rf_o);

        clear_inputs();
        current_packet_load = 1'b1;
        slot1_load_s4 = 1'b1;
        slot0_load_s4 = 1'b1;
        #1;
        `check("QFLOW forwards fresh upstream packet actions",
               current_packet_load_o && slot1_load_s4_o && slot0_load_s4_o &&
               !slot1_clear_o && !slot0_load_promote_o);

        clear_inputs();
        slot1_clear = 1'b1;
        slot0_load_promote = 1'b1;
        #1;
        `check("QFLOW forwards slot1 promotion actions",
               slot1_clear_o && slot0_load_promote_o &&
               !slot1_load_hold_o && !slot0_load_hold_o);

        clear_inputs();
        hold_packet_track_rf = 1'b1;
        slot1_track_rf = 1'b1;
        slot0_track_rf = 1'b1;
        #1;
        `check("QFLOW forwards held/current RF tracking actions",
               hold_packet_track_rf_o && slot1_track_rf_o && slot0_track_rf_o &&
               !current_packet_load_o);

        clear_inputs();
        slot1_load_hold = 1'b1;
        slot0_load_hold = 1'b1;
        #1;
        `check("QFLOW forwards held packet pop actions",
               slot1_load_hold_o && slot0_load_hold_o &&
               !slot1_load_s4_o && !slot0_load_s4_o);

        finish_tb();
    end
endmodule
