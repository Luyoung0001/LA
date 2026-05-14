`timescale 1ns / 1ps

module s5_issue_queue_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic slot0_promote_accept;
    logic slot1_valid;
    logic slot1_accept;
    logic branch_redirect;
    logic upstream_valid;
    logic [0:0] upstream_epoch;
    logic [0:0] current_epoch;
    logic [31:0] upstream_pc;
    logic [31:0] slot1_pc;
    logic [31:0] upstream_instr;
    logic [31:0] instr1;
    logic upstream_covers_slot1;
    logic s5_base_allowin;
    logic issue_ready;
    logic held_packet_valid;
    logic held_packet_rf_ready;
    logic held_packet_ready;
    logic promoted_slot1;
    logic promoted_slot1_fired;
    logic s5_allowin;
    logic current_packet_consume_allow;
    logic current_packet_load;
    logic promoted_raw_wait;
    logic promote_slot1;
    logic hold_packet_push;
    logic hold_packet_pop;
    logic promoted_emit_block;

    s5_issue_queue_ctrl #(
        .XLEN(32),
        .ILEN(32),
        .EPOCH_WIDTH(1)
    ) u_dut (
        .slot0_promote_accept_i(slot0_promote_accept),
        .slot1_valid_i(slot1_valid),
        .slot1_accept_i(slot1_accept),
        .branch_redirect_i(branch_redirect),
        .upstream_valid_i(upstream_valid),
        .upstream_epoch_i(upstream_epoch),
        .current_epoch_i(current_epoch),
        .upstream_pc_i(upstream_pc),
        .slot1_pc_i(slot1_pc),
        .upstream_instr_i(upstream_instr),
        .instr1_i(instr1),
        .s5_base_allowin_i(s5_base_allowin),
        .issue_ready_i(issue_ready),
        .held_packet_valid_i(held_packet_valid),
        .held_packet_ready_i(held_packet_ready),
        .promoted_slot1_i(promoted_slot1),
        .promoted_slot1_fired_i(promoted_slot1_fired),
        .s5_allowin_o(s5_allowin),
        .current_packet_consume_allow_o(current_packet_consume_allow),
        .current_packet_load_o(current_packet_load),
        .upstream_covers_slot1_o(upstream_covers_slot1),
        .promoted_raw_wait_o(promoted_raw_wait),
        .promote_slot1_o(promote_slot1),
        .hold_packet_push_o(hold_packet_push),
        .hold_packet_pop_o(hold_packet_pop),
        .promoted_emit_block_o(promoted_emit_block)
    );

    initial begin
        tb_start();
        slot0_promote_accept = 1'b0;
        slot1_valid = 1'b0;
        slot1_accept = 1'b0;
        branch_redirect = 1'b0;
        upstream_valid = 1'b0;
        upstream_epoch = 1'b0;
        current_epoch = 1'b0;
        upstream_pc = 32'h8000_0008;
        slot1_pc = 32'h8000_0004;
        upstream_instr = 32'h0280_0401;
        instr1 = 32'h0280_0802;
        s5_base_allowin = 1'b1;
        issue_ready = 1'b1;
        held_packet_valid = 1'b0;
        held_packet_rf_ready = 1'b0;
        held_packet_ready = 1'b0;
        promoted_slot1 = 1'b0;
        promoted_slot1_fired = 1'b0;
        #1;

        `check("QCTRL idle allows input", s5_allowin &&
               current_packet_consume_allow && !promote_slot1 &&
               !current_packet_load && !hold_packet_push &&
               !hold_packet_pop && !promoted_emit_block);

        upstream_valid = 1'b1;
        #1;
        `check("QCTRL accepts fresh upstream packet",
               s5_allowin && current_packet_consume_allow &&
               current_packet_load);

        upstream_valid = 1'b0;

        promoted_slot1 = 1'b1;
        issue_ready = 1'b0;
        #1;
        `check("QCTRL reports promoted slot RAW wait", promoted_raw_wait);

        issue_ready = 1'b1;
        #1;
        `check("QCTRL clears promoted slot RAW wait when issue is ready",
               !promoted_raw_wait);

        promoted_slot1 = 1'b0;
        slot0_promote_accept = 1'b1;
        slot1_valid = 1'b1;
        #1;
        `check("QCTRL promotes unissued slot1", promote_slot1 && !hold_packet_push);

        upstream_valid = 1'b1;
        #1;
        `check("QCTRL captures upstream packet while promoting slot1",
               promote_slot1 && hold_packet_push && s5_allowin &&
               current_packet_load);

        held_packet_valid = 1'b1;
        #1;
        `check("QCTRL blocks upstream while held packet exists", !s5_allowin &&
               !current_packet_consume_allow &&
               promote_slot1 && !current_packet_load && !hold_packet_push);

        slot1_accept = 1'b1;
        held_packet_rf_ready = 1'b1;
        held_packet_ready = 1'b1;
        #1;
        `check("QCTRL drains ready held packet when slot1 is not promoted",
               !promote_slot1 && hold_packet_pop);

        slot1_accept = 1'b0;
        #1;
        `check("QCTRL held-ready packet allows current emit but blocks upstream accept when promoted",
               !s5_allowin && current_packet_consume_allow &&
               promote_slot1 && !hold_packet_pop && !hold_packet_push);

        slot1_accept = 1'b1;
        upstream_valid = 1'b1;
        #1;
        `check("QCTRL pop can refill hold packet from upstream",
               s5_allowin && current_packet_consume_allow &&
               hold_packet_pop && hold_packet_push &&
               current_packet_load);

        held_packet_rf_ready = 1'b0;
        held_packet_ready = 1'b0;
        #1;
        `check("QCTRL waits for held packet RF alignment", !hold_packet_pop);

        slot1_accept = 1'b0;
        held_packet_valid = 1'b0;
        held_packet_rf_ready = 1'b0;
        held_packet_ready = 1'b0;
        branch_redirect = 1'b1;
        #1;
        `check("QCTRL branch redirect suppresses slot1 promotion", !promote_slot1);

        branch_redirect = 1'b0;
        upstream_pc = slot1_pc;
        upstream_instr = instr1;
        #1;
        `check("QCTRL upstream duplicate suppresses slot1 promotion",
               upstream_covers_slot1 && !promote_slot1);

        upstream_instr = 32'h0280_0c03;
        #1;
        `check("QCTRL instr mismatch clears upstream duplicate",
               !upstream_covers_slot1 && promote_slot1);

        upstream_instr = instr1;
        upstream_epoch = 1'b1;
        #1;
        `check("QCTRL epoch mismatch clears upstream duplicate",
               !upstream_covers_slot1 && promote_slot1);

        upstream_epoch = current_epoch;
        upstream_pc = 32'h8000_0008;
        promoted_slot1 = 1'b1;
        promoted_slot1_fired = 1'b1;
        held_packet_valid = 1'b1;
        held_packet_ready = 1'b1;
        #1;
        `check("QCTRL blocks duplicate promoted-slot emit", promoted_emit_block);

        finish_tb();
    end
endmodule
