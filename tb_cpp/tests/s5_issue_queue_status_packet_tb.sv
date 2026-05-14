`timescale 1ns / 1ps

module s5_issue_queue_status_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic held_packet_valid;
    logic held_packet_rf_ready;
    logic held_packet_ready;
    logic held_packet_capture_rf;
    logic promoted_slot1;
    logic promoted_slot1_fired;

    logic held_packet_valid_o;
    logic held_packet_rf_ready_o;
    logic held_packet_ready_o;
    logic held_packet_capture_rf_o;
    logic promoted_slot1_o;
    logic promoted_slot1_fired_o;

    s5_issue_queue_status_packet u_dut (
        .held_packet_valid_i(held_packet_valid),
        .held_packet_rf_ready_i(held_packet_rf_ready),
        .held_packet_ready_i(held_packet_ready),
        .held_packet_capture_rf_i(held_packet_capture_rf),
        .promoted_slot1_i(promoted_slot1),
        .promoted_slot1_fired_i(promoted_slot1_fired),
        .held_packet_valid_o(held_packet_valid_o),
        .held_packet_rf_ready_o(held_packet_rf_ready_o),
        .held_packet_ready_o(held_packet_ready_o),
        .held_packet_capture_rf_o(held_packet_capture_rf_o),
        .promoted_slot1_o(promoted_slot1_o),
        .promoted_slot1_fired_o(promoted_slot1_fired_o)
    );

    task automatic clear_inputs;
        begin
            held_packet_valid = 1'b0;
            held_packet_rf_ready = 1'b0;
            held_packet_ready = 1'b0;
            held_packet_capture_rf = 1'b0;
            promoted_slot1 = 1'b0;
            promoted_slot1_fired = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("QSTATUS idle clears all status bits",
               !held_packet_valid_o && !held_packet_rf_ready_o &&
               !held_packet_ready_o && !held_packet_capture_rf_o &&
               !promoted_slot1_o && !promoted_slot1_fired_o);

        clear_inputs();
        held_packet_valid = 1'b1;
        held_packet_capture_rf = 1'b1;
        promoted_slot1 = 1'b1;
        #1;
        `check("QSTATUS forwards held capture status",
               held_packet_valid_o && held_packet_capture_rf_o &&
               promoted_slot1_o && !held_packet_rf_ready_o &&
               !held_packet_ready_o && !promoted_slot1_fired_o);

        clear_inputs();
        held_packet_valid = 1'b1;
        held_packet_rf_ready = 1'b1;
        held_packet_ready = 1'b1;
        promoted_slot1 = 1'b1;
        promoted_slot1_fired = 1'b1;
        #1;
        `check("QSTATUS forwards ready and fired status",
               held_packet_valid_o && held_packet_rf_ready_o &&
               held_packet_ready_o && promoted_slot1_o &&
               promoted_slot1_fired_o && !held_packet_capture_rf_o);

        finish_tb();
    end
endmodule
