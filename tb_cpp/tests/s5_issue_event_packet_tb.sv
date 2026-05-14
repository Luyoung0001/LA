`timescale 1ns / 1ps

module s5_issue_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       slot0_emit_valid;
    logic       slot0_fire;
    logic       slot0_accept;
    logic       slot1_issue_valid;
    logic       slot1_fire;
    logic       slot1_accept;
    logic       slot1_fire_compute;
    logic       slot1_fire_load;
    logic       slot1_fire_store;
    logic       slot1_fire_ctrl;
    logic [3:0] slot1_issue_class;
    logic       dual_issue;
    logic       single_issue_fire;
    logic       dual_issue_fire;
    logic       branch_redirect_valid;
    logic [4:0] issue_select_reason;
    logic [4:0] pair_block_reason;
    logic [2:0] slot1_block_reason;

    logic       slot0_emit_valid_o;
    logic       slot0_fire_o;
    logic       slot0_accept_o;
    logic       slot1_issue_valid_o;
    logic       slot1_fire_o;
    logic       slot1_accept_o;
    logic       slot1_fire_compute_o;
    logic       slot1_fire_load_o;
    logic       slot1_fire_store_o;
    logic       slot1_fire_ctrl_o;
    logic [3:0] slot1_issue_class_o;
    logic [3:0] slot1_fire_class_o;
    logic       dual_issue_o;
    logic       single_issue_fire_o;
    logic       dual_issue_fire_o;
    logic       branch_redirect_valid_o;
    logic [4:0] issue_select_reason_o;
    logic [4:0] pair_block_reason_o;
    logic [2:0] slot1_block_reason_o;

    s5_issue_event_packet u_dut (
        .slot0_emit_valid_i(slot0_emit_valid),
        .slot0_fire_i(slot0_fire),
        .slot0_accept_i(slot0_accept),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_fire_i(slot1_fire),
        .slot1_accept_i(slot1_accept),
        .slot1_fire_compute_i(slot1_fire_compute),
        .slot1_fire_load_i(slot1_fire_load),
        .slot1_fire_store_i(slot1_fire_store),
        .slot1_fire_ctrl_i(slot1_fire_ctrl),
        .slot1_issue_class_i(slot1_issue_class),
        .dual_issue_i(dual_issue),
        .single_issue_fire_i(single_issue_fire),
        .dual_issue_fire_i(dual_issue_fire),
        .branch_redirect_valid_i(branch_redirect_valid),
        .issue_select_reason_i(issue_select_reason),
        .pair_block_reason_i(pair_block_reason),
        .slot1_block_reason_i(slot1_block_reason),
        .slot0_emit_valid_o(slot0_emit_valid_o),
        .slot0_fire_o(slot0_fire_o),
        .slot0_accept_o(slot0_accept_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_fire_o(slot1_fire_o),
        .slot1_accept_o(slot1_accept_o),
        .slot1_fire_compute_o(slot1_fire_compute_o),
        .slot1_fire_load_o(slot1_fire_load_o),
        .slot1_fire_store_o(slot1_fire_store_o),
        .slot1_fire_ctrl_o(slot1_fire_ctrl_o),
        .slot1_issue_class_o(slot1_issue_class_o),
        .slot1_fire_class_o(slot1_fire_class_o),
        .dual_issue_o(dual_issue_o),
        .single_issue_fire_o(single_issue_fire_o),
        .dual_issue_fire_o(dual_issue_fire_o),
        .branch_redirect_valid_o(branch_redirect_valid_o),
        .issue_select_reason_o(issue_select_reason_o),
        .pair_block_reason_o(pair_block_reason_o),
        .slot1_block_reason_o(slot1_block_reason_o)
    );

    task automatic clear_inputs;
        begin
            slot0_emit_valid = 1'b0;
            slot0_fire = 1'b0;
            slot0_accept = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_fire = 1'b0;
            slot1_accept = 1'b0;
            slot1_fire_compute = 1'b0;
            slot1_fire_load = 1'b0;
            slot1_fire_store = 1'b0;
            slot1_fire_ctrl = 1'b0;
            slot1_issue_class = 4'd0;
            dual_issue = 1'b0;
            single_issue_fire = 1'b0;
            dual_issue_fire = 1'b0;
            branch_redirect_valid = 1'b0;
            issue_select_reason = 5'd0;
            pair_block_reason = 5'd0;
            slot1_block_reason = 3'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("EVENT idle clears issue events",
               !slot0_emit_valid_o && !slot0_fire_o &&
               !slot0_accept_o && !slot1_issue_valid_o &&
               !slot1_fire_o && !slot1_accept_o &&
               !dual_issue_o && !single_issue_fire_o &&
               !dual_issue_fire_o && !branch_redirect_valid_o);
        `check32("EVENT idle issue class clear", {28'd0, slot1_issue_class_o}, 32'd0);
        `check32("EVENT idle class clear", {28'd0, slot1_fire_class_o}, 32'd0);
        `check32("EVENT idle reasons clear",
                 {19'd0, issue_select_reason_o, pair_block_reason_o, slot1_block_reason_o},
                 32'd0);

        clear_inputs();
        slot0_emit_valid = 1'b1;
        slot0_fire = 1'b1;
        slot0_accept = 1'b1;
        single_issue_fire = 1'b1;
        branch_redirect_valid = 1'b1;
        issue_select_reason = 5'h02;
        pair_block_reason = 5'h01;
        slot1_block_reason = 3'h0;
        #1;
        `check("EVENT single issue forwards slot0 and redirect",
               slot0_emit_valid_o && slot0_fire_o &&
               slot0_accept_o &&
               single_issue_fire_o && branch_redirect_valid_o &&
               !slot1_fire_o && !slot1_accept_o && !dual_issue_fire_o);
        `check32("EVENT single issue reasons",
                 {19'd0, issue_select_reason_o, pair_block_reason_o, slot1_block_reason_o},
                 {19'd0, 5'h02, 5'h01, 3'h0});

        clear_inputs();
        slot0_emit_valid = 1'b1;
        slot0_fire = 1'b1;
        slot0_accept = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_fire = 1'b1;
        slot1_accept = 1'b1;
        slot1_fire_load = 1'b1;
        slot1_issue_class = 4'b0100;
        dual_issue = 1'b1;
        dual_issue_fire = 1'b1;
        issue_select_reason = 5'h10;
        pair_block_reason = 5'h00;
        slot1_block_reason = 3'h0;
        #1;
        `check("EVENT dual issue forwards slot1 fire",
               slot1_issue_valid_o && slot1_fire_o && slot1_accept_o &&
               dual_issue_o &&
               dual_issue_fire_o && !single_issue_fire_o);
        `check32("EVENT load issue class pack", {28'd0, slot1_issue_class_o}, 32'b0100);
        `check32("EVENT load class pack", {28'd0, slot1_fire_class_o}, 32'b0100);
        `check("EVENT load class individual bit", slot1_fire_load_o && !slot1_fire_compute_o);

        clear_inputs();
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b0010;
        issue_select_reason = 5'h04;
        #1;
        `check("EVENT preserves visible slot1 without fire",
               slot1_issue_valid_o && !slot1_fire_o && !slot1_accept_o);
        `check32("EVENT visible slot1 keeps issue class",
                 {28'd0, slot1_issue_class_o}, 32'b0010);
        `check32("EVENT visible slot1 clears fire class",
                 {28'd0, slot1_fire_class_o}, 32'd0);

        clear_inputs();
        slot1_issue_valid = 1'b1;
        slot1_fire = 1'b1;
        slot1_accept = 1'b1;
        slot1_fire_compute = 1'b1;
        slot1_fire_store = 1'b1;
        slot1_issue_class = 4'b1010;
        issue_select_reason = 5'h08;
        pair_block_reason = 5'h18;
        slot1_block_reason = 3'h5;
        #1;
        `check32("EVENT preserves multi-bit diagnostic class",
                 {28'd0, slot1_fire_class_o}, 32'b1010);
        `check32("EVENT preserves diagnostic reasons",
                 {19'd0, issue_select_reason_o, pair_block_reason_o, slot1_block_reason_o},
                 {19'd0, 5'h08, 5'h18, 3'h5});

        finish_tb();
    end

endmodule
