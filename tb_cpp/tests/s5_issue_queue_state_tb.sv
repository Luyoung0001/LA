`timescale 1ns / 1ps

module s5_issue_queue_state_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic promote_slot1;
    logic hold_packet_push;
    logic hold_packet_pop;
    logic current_packet_load;
    logic s5_valid;
    logic slot0_accept;
    logic held_packet_valid;
    logic held_packet_rf_ready;
    logic held_packet_ready;
    logic held_packet_capture_rf;
    logic promoted_slot1;
    logic promoted_slot1_fired;

    s5_issue_queue_state u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .promote_slot1_i(promote_slot1),
        .hold_packet_push_i(hold_packet_push),
        .hold_packet_pop_i(hold_packet_pop),
        .current_packet_load_i(current_packet_load),
        .s5_valid_i(s5_valid),
        .slot0_accept_i(slot0_accept),
        .held_packet_valid_o(held_packet_valid),
        .held_packet_rf_ready_o(held_packet_rf_ready),
        .held_packet_ready_o(held_packet_ready),
        .held_packet_capture_rf_o(held_packet_capture_rf),
        .promoted_slot1_o(promoted_slot1),
        .promoted_slot1_fired_o(promoted_slot1_fired)
    );

    initial begin
        tb_start();
        flush = 1'b0;
        promote_slot1 = 1'b0;
        hold_packet_push = 1'b0;
        hold_packet_pop = 1'b0;
        current_packet_load = 1'b0;
        s5_valid = 1'b1;
        slot0_accept = 1'b0;
        reset_dut();

        `check("QSTATE reset clears state",
               !held_packet_valid && !held_packet_rf_ready &&
               !held_packet_ready && !promoted_slot1 && !promoted_slot1_fired);

        promote_slot1 = 1'b1;
        hold_packet_push = 1'b1;
        tick();
        promote_slot1 = 1'b0;
        hold_packet_push = 1'b0;
        `check("QSTATE records promoted slot1 and held packet",
               promoted_slot1 && held_packet_valid && !held_packet_rf_ready &&
               !held_packet_ready);
        `check("QSTATE waits one cycle before RF capture", !held_packet_capture_rf);

        tick();
        `check("QSTATE marks held packet RF ready after capture",
               held_packet_valid && held_packet_rf_ready && held_packet_ready &&
               !held_packet_capture_rf);

        slot0_accept = 1'b1;
        tick();
        slot0_accept = 1'b0;
        `check("QSTATE records promoted slot1 fired while held packet waits",
               promoted_slot1 && promoted_slot1_fired);

        hold_packet_pop = 1'b1;
        tick();
        hold_packet_pop = 1'b0;
        `check("QSTATE pop clears held packet and promoted slot state",
               !held_packet_valid && !held_packet_rf_ready &&
               !held_packet_ready && !promoted_slot1 && !promoted_slot1_fired);

        promote_slot1 = 1'b1;
        tick();
        promote_slot1 = 1'b0;
        `check("QSTATE promotion without held packet is tracked",
               promoted_slot1 && !held_packet_valid);

        current_packet_load = 1'b1;
        tick();
        current_packet_load = 1'b0;
        `check("QSTATE loading current packet clears promoted slot state",
               !promoted_slot1 && !promoted_slot1_fired);

        hold_packet_push = 1'b1;
        tick();
        hold_packet_push = 1'b0;
        flush = 1'b1;
        tick();
        flush = 1'b0;
        `check("QSTATE flush clears held packet", !held_packet_valid && !held_packet_rf_ready);

        finish_tb();
    end
endmodule
