`timescale 1ns / 1ps

module s5_issue_queue_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s5_valid;
    logic        slot0_accept;
    logic        slot1_promote_enable;
    logic        slot1_valid;
    logic        slot1_accept;
    logic        branch_redirect;
    logic        upstream_valid;
    logic [0:0]  upstream_epoch;
    logic [0:0]  current_epoch;
    logic [31:0] upstream_pc;
    logic [31:0] slot1_pc;
    logic [31:0] upstream_instr;
    logic [31:0] instr1;
    logic        s5_base_allowin;
    logic        issue_ready;

    logic        held_packet_valid;
    logic        held_packet_rf_ready;
    logic        held_packet_ready;
    logic        held_packet_capture_rf;
    logic        promoted_slot1;
    logic        promoted_slot1_fired;
    logic        s5_allowin;
    logic        current_packet_consume_allow;
    logic        upstream_covers_slot1;
    logic        promoted_raw_wait;
    logic        promote_slot1;
    logic        hold_packet_push;
    logic        hold_packet_pop;
    logic        promoted_emit_block;
    logic        current_packet_load;
    logic        hold_packet_track_rf;
    logic        slot1_clear;
    logic        slot1_load_hold;
    logic        slot1_load_s4;
    logic        slot1_track_rf;
    logic        slot0_load_promote;
    logic        slot0_load_hold;
    logic        slot0_load_s4;
    logic        slot0_track_rf;

    s5_issue_queue #(
        .XLEN(32),
        .ILEN(32),
        .EPOCH_WIDTH(1)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(1'b0),
        .s5_valid_i(s5_valid),
        .slot0_accept_i(slot0_accept),
        .slot1_promote_enable_i(slot1_promote_enable),
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
        .held_packet_valid_o(held_packet_valid),
        .held_packet_rf_ready_o(held_packet_rf_ready),
        .held_packet_ready_o(held_packet_ready),
        .held_packet_capture_rf_o(held_packet_capture_rf),
        .promoted_slot1_o(promoted_slot1),
        .promoted_slot1_fired_o(promoted_slot1_fired),
        .s5_allowin_o(s5_allowin),
        .current_packet_consume_allow_o(current_packet_consume_allow),
        .upstream_covers_slot1_o(upstream_covers_slot1),
        .promoted_raw_wait_o(promoted_raw_wait),
        .promote_slot1_o(promote_slot1),
        .hold_packet_push_o(hold_packet_push),
        .hold_packet_pop_o(hold_packet_pop),
        .promoted_emit_block_o(promoted_emit_block),
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
            slot0_accept = 1'b0;
            slot1_promote_enable = 1'b1;
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
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        reset_dut();

        clear_inputs();
        #1;
        `check("QUEUE idle accepts empty S5",
               s5_allowin && !promote_slot1 && !hold_packet_push &&
               !hold_packet_pop && !current_packet_load);

        clear_inputs();
        upstream_valid = 1'b1;
        #1;
        `check("QUEUE loads fresh upstream packet",
               s5_allowin && current_packet_consume_allow && current_packet_load &&
               slot0_load_s4 && slot1_load_s4);

        clear_inputs();
        s5_valid = 1'b1;
        slot0_accept = 1'b1;
        slot1_promote_enable = 1'b0;
        slot1_valid = 1'b1;
        #1;
        `check("QUEUE promotion gate can disable slot1 promotion",
               !promote_slot1 && !slot1_clear && !slot0_load_promote);

        clear_inputs();
        s5_valid = 1'b1;
        slot0_accept = 1'b1;
        slot1_valid = 1'b1;
        #1;
        `check("QUEUE promotes unissued slot1",
               promote_slot1 && slot1_clear && slot0_load_promote &&
               !hold_packet_push);

        upstream_valid = 1'b1;
        #1;
        `check("QUEUE holds upstream while promoting slot1",
               promote_slot1 && hold_packet_push && !current_packet_load &&
               slot0_load_promote && slot1_clear);

        tick();
        #1;
        `check("QUEUE push sets held packet state",
               held_packet_valid && !held_packet_rf_ready && !held_packet_ready &&
               promoted_slot1);
        `check("QUEUE waits one cycle before captured RF base is ready",
               held_packet_capture_rf);

        tick();
        #1;
        `check("QUEUE captured RF base becomes ready",
               held_packet_valid && held_packet_rf_ready && held_packet_ready &&
               !held_packet_capture_rf);

        clear_inputs();
        s5_valid = 1'b1;
        slot0_accept = 1'b1;
        slot1_valid = 1'b1;
        upstream_valid = 1'b1;
        #1;
        #1;
        `check("QUEUE blocks new upstream while held packet exists",
               !s5_allowin && current_packet_consume_allow &&
               promote_slot1 && !hold_packet_push &&
               !current_packet_load);

        slot1_accept = 1'b1;
        #1;
        `check("QUEUE pops ready held packet and refills from upstream",
               !promote_slot1 && hold_packet_pop && hold_packet_push &&
               s5_allowin && current_packet_consume_allow &&
               !current_packet_load &&
               slot0_load_hold && slot1_load_hold &&
               !slot0_load_s4 && !slot1_load_s4);
        tick();
        #1;
        `check("QUEUE refill keeps held packet but waits for RF capture",
               held_packet_valid && !held_packet_rf_ready && !held_packet_ready);

        tick();
        #1;
        `check("QUEUE refilled held packet RF becomes ready",
               held_packet_valid && held_packet_rf_ready && held_packet_ready);

        clear_inputs();
        s5_base_allowin = 1'b1;
        slot1_accept = 1'b1;
        upstream_valid = 1'b0;
        #1;
        `check("QUEUE pure pop drains ready held packet",
               hold_packet_pop && !hold_packet_push &&
               slot0_load_hold && slot1_load_hold);
        tick();
        #1;
        `check("QUEUE pure pop clears held packet state",
               !held_packet_valid && !held_packet_rf_ready && !held_packet_ready);

        clear_inputs();
        s5_valid = 1'b1;
        s5_base_allowin = 1'b0;
        slot0_accept = 1'b1;
        slot1_valid = 1'b1;
        upstream_valid = 1'b1;
        s5_base_allowin = 1'b1;
        #1;
        tick();
        tick();
        slot0_accept = 1'b0;
        upstream_valid = 1'b0;
        s5_base_allowin = 1'b0;
        #1;
        `check("QUEUE tracks held/current RF bases while waiting",
               hold_packet_track_rf && slot0_track_rf && slot1_track_rf);
        clear_inputs();
        s5_base_allowin = 1'b1;
        slot1_accept = 1'b1;
        #1;
        tick();
        #1;
        `check("QUEUE cleanup pop clears held packet before later cases",
               !held_packet_valid);

        clear_inputs();
        s5_valid = 1'b1;
        slot0_accept = 1'b1;
        slot1_valid = 1'b1;
        branch_redirect = 1'b1;
        #1;
        `check("QUEUE redirect suppresses promotion",
               !promote_slot1 && !slot1_clear && !slot0_load_promote);

        clear_inputs();
        s5_valid = 1'b1;
        slot0_accept = 1'b1;
        slot1_valid = 1'b1;
        upstream_valid = 1'b1;
        upstream_pc = slot1_pc;
        upstream_instr = instr1;
        #1;
        `check("QUEUE duplicate upstream suppresses promotion",
               upstream_covers_slot1 && !promote_slot1 &&
               current_packet_load && slot0_load_s4 && slot1_load_s4);

        clear_inputs();
        s5_valid = 1'b1;
        slot0_accept = 1'b1;
        slot1_valid = 1'b1;
        upstream_valid = 1'b1;
        #1;
        tick();
        clear_inputs();
        issue_ready = 1'b0;
        #1;
        `check("QUEUE reports promoted RAW wait", promoted_raw_wait);

        issue_ready = 1'b1;
        s5_valid = 1'b1;
        s5_base_allowin = 1'b0;
        slot0_accept = 1'b1;
        #1;
        tick();
        slot0_accept = 1'b0;
        #1;
        `check("QUEUE blocks duplicate promoted emit",
               promoted_emit_block && !promoted_raw_wait);

        finish_tb();
    end
endmodule
