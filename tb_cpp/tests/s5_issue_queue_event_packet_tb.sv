`timescale 1ns / 1ps

module s5_issue_queue_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s5_allowin;
    logic current_packet_consume_allow;
    logic current_packet_load;
    logic upstream_covers_slot1;
    logic promoted_raw_wait;
    logic promote_slot1;
    logic hold_packet_push;
    logic hold_packet_pop;
    logic promoted_emit_block;

    logic s5_allowin_o;
    logic current_packet_consume_allow_o;
    logic current_packet_load_o;
    logic upstream_covers_slot1_o;
    logic promoted_raw_wait_o;
    logic promote_slot1_o;
    logic hold_packet_push_o;
    logic hold_packet_pop_o;
    logic promoted_emit_block_o;

    s5_issue_queue_event_packet u_dut (
        .s5_allowin_i(s5_allowin),
        .current_packet_consume_allow_i(current_packet_consume_allow),
        .current_packet_load_i(current_packet_load),
        .upstream_covers_slot1_i(upstream_covers_slot1),
        .promoted_raw_wait_i(promoted_raw_wait),
        .promote_slot1_i(promote_slot1),
        .hold_packet_push_i(hold_packet_push),
        .hold_packet_pop_i(hold_packet_pop),
        .promoted_emit_block_i(promoted_emit_block),
        .s5_allowin_o(s5_allowin_o),
        .current_packet_consume_allow_o(current_packet_consume_allow_o),
        .current_packet_load_o(current_packet_load_o),
        .upstream_covers_slot1_o(upstream_covers_slot1_o),
        .promoted_raw_wait_o(promoted_raw_wait_o),
        .promote_slot1_o(promote_slot1_o),
        .hold_packet_push_o(hold_packet_push_o),
        .hold_packet_pop_o(hold_packet_pop_o),
        .promoted_emit_block_o(promoted_emit_block_o)
    );

    task automatic clear_inputs;
        begin
            s5_allowin = 1'b0;
            current_packet_consume_allow = 1'b0;
            current_packet_load = 1'b0;
            upstream_covers_slot1 = 1'b0;
            promoted_raw_wait = 1'b0;
            promote_slot1 = 1'b0;
            hold_packet_push = 1'b0;
            hold_packet_pop = 1'b0;
            promoted_emit_block = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("QEVENT idle clears all events",
               !s5_allowin_o && !current_packet_consume_allow_o &&
               !upstream_covers_slot1_o &&
               !current_packet_load_o &&
               !promoted_raw_wait_o && !promote_slot1_o &&
               !hold_packet_push_o && !hold_packet_pop_o &&
               !promoted_emit_block_o);

        clear_inputs();
        s5_allowin = 1'b1;
        current_packet_consume_allow = 1'b1;
        current_packet_load = 1'b1;
        promote_slot1 = 1'b1;
        hold_packet_push = 1'b1;
        #1;
        `check("QEVENT forwards accept, promote, and push",
               s5_allowin_o && current_packet_consume_allow_o &&
               current_packet_load_o &&
               promote_slot1_o && hold_packet_push_o && !hold_packet_pop_o);

        clear_inputs();
        upstream_covers_slot1 = 1'b1;
        promoted_raw_wait = 1'b1;
        hold_packet_pop = 1'b1;
        promoted_emit_block = 1'b1;
        #1;
        `check("QEVENT forwards diagnostic and pop events",
               upstream_covers_slot1_o && promoted_raw_wait_o &&
               hold_packet_pop_o && promoted_emit_block_o &&
               !promote_slot1_o && !hold_packet_push_o);

        finish_tb();
    end
endmodule
