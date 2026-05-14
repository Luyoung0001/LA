`timescale 1ns / 1ps

module s5_issue_lane_dispatch_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s5_valid;
    logic issue_ready_go;
    logic s6_allowin;
    logic consume_allow;
    logic promoted_slot1;
    logic promoted_emit_block;
    logic slot1_issue_valid;
    logic slot1_pair_compute;
    logic slot1_pair_load;
    logic slot1_pair_store;
    logic slot1_pair_ctrl;
    logic dual_issue;
    logic branch_redirect;

    logic slot0_emit_valid_o;
    logic slot0_fire_o;
    logic slot0_accept_o;
    logic slot1_issue_valid_o;
    logic slot1_fire_o;
    logic slot1_accept_o;
    logic slot1_fire_compute_o;
    logic slot1_fire_load_o;
    logic slot1_fire_store_o;
    logic slot1_fire_ctrl_o;
    logic [3:0] slot1_issue_class_o;
    logic [3:0] slot1_fire_class_o;
    logic dual_issue_o;
    logic single_issue_fire_o;
    logic dual_issue_fire_o;
    logic branch_redirect_valid_o;

    s5_issue_lane_dispatch u_dut (
        .s5_valid_i(s5_valid),
        .issue_ready_go_i(issue_ready_go),
        .s6_allowin_i(s6_allowin),
        .consume_allow_i(consume_allow),
        .promoted_slot1_i(promoted_slot1),
        .promoted_emit_block_i(promoted_emit_block),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_pair_compute_i(slot1_pair_compute),
        .slot1_pair_load_i(slot1_pair_load),
        .slot1_pair_store_i(slot1_pair_store),
        .slot1_pair_ctrl_i(slot1_pair_ctrl),
        .dual_issue_i(dual_issue),
        .branch_redirect_i(branch_redirect),
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
        .branch_redirect_valid_o(branch_redirect_valid_o)
    );

    task automatic clear_inputs;
        begin
            s5_valid = 1'b0;
            issue_ready_go = 1'b0;
            s6_allowin = 1'b0;
            consume_allow = 1'b0;
            promoted_slot1 = 1'b0;
            promoted_emit_block = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_pair_compute = 1'b0;
            slot1_pair_load = 1'b0;
            slot1_pair_store = 1'b0;
            slot1_pair_ctrl = 1'b0;
            dual_issue = 1'b0;
            branch_redirect = 1'b0;
        end
    endtask

    task automatic check_slot1_fire_class(
        input string name,
        input        exp_compute,
        input        exp_load,
        input        exp_store,
        input        exp_ctrl
    );
        begin
            `check32(name,
                     {28'd0, slot1_fire_class_o},
                     {28'd0, exp_compute, exp_load, exp_store, exp_ctrl});
            `check32({name, " individual bits"},
                     {28'd0, slot1_fire_compute_o, slot1_fire_load_o,
                      slot1_fire_store_o, slot1_fire_ctrl_o},
                     {28'd0, exp_compute, exp_load, exp_store, exp_ctrl});
        end
    endtask

    task automatic check_slot1_issue_class(
        input string name,
        input        exp_compute,
        input        exp_load,
        input        exp_store,
        input        exp_ctrl
    );
        begin
            `check32(name,
                     {28'd0, slot1_issue_class_o},
                     {28'd0, exp_compute, exp_load, exp_store, exp_ctrl});
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("DISPATCH idle emits nothing",
               !slot0_emit_valid_o && !slot0_fire_o &&
               !slot0_accept_o && !slot1_issue_valid_o &&
               !slot1_fire_o && !slot1_accept_o &&
               !dual_issue_o && !single_issue_fire_o && !dual_issue_fire_o &&
               !branch_redirect_valid_o);
        check_slot1_issue_class("DISPATCH idle clears slot1 issue class", 1'b0, 1'b0, 1'b0, 1'b0);
        check_slot1_fire_class("DISPATCH idle clears slot1 fire class", 1'b0, 1'b0, 1'b0, 1'b0);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b0;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        branch_redirect = 1'b1;
        #1;
        `check("DISPATCH ready_go blocks slot0 fire and redirect",
               !slot0_emit_valid_o && !slot0_fire_o &&
               !slot0_accept_o && !slot1_fire_o && !slot1_accept_o &&
               !single_issue_fire_o &&
               !dual_issue_fire_o && !branch_redirect_valid_o);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b0;
        consume_allow = 1'b1;
        branch_redirect = 1'b1;
        #1;
        `check("DISPATCH downstream backpressure keeps emit but no fire",
               slot0_emit_valid_o && !slot0_fire_o &&
               !slot0_accept_o && !slot1_fire_o && !slot1_accept_o &&
               !single_issue_fire_o &&
               !dual_issue_fire_o && !branch_redirect_valid_o);
        check_slot1_fire_class("DISPATCH backpressure clears slot1 fire class", 1'b0, 1'b0, 1'b0, 1'b0);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b0;
        branch_redirect = 1'b1;
        #1;
        `check("DISPATCH queue consume block suppresses emit",
               !slot0_emit_valid_o && !slot0_fire_o &&
               !slot0_accept_o && !slot1_fire_o && !slot1_accept_o &&
               !single_issue_fire_o &&
               !dual_issue_fire_o && !branch_redirect_valid_o);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b0;
        promoted_slot1 = 1'b1;
        #1;
        `check("DISPATCH promoted slot may emit while queue holds upstream",
               slot0_emit_valid_o && slot0_fire_o && slot0_accept_o &&
               single_issue_fire_o && !dual_issue_fire_o);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        branch_redirect = 1'b1;
        #1;
        `check("DISPATCH slot0 fire gates branch redirect",
               slot0_emit_valid_o && slot0_fire_o &&
               slot0_accept_o &&
               single_issue_fire_o && !dual_issue_fire_o &&
               !slot1_fire_o && !slot1_accept_o && branch_redirect_valid_o);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        promoted_emit_block = 1'b1;
        branch_redirect = 1'b1;
        #1;
        `check("DISPATCH promoted duplicate block suppresses emit",
               !slot0_emit_valid_o && !slot0_fire_o &&
               !slot0_accept_o && !slot1_fire_o && !slot1_accept_o &&
               !single_issue_fire_o &&
               !dual_issue_fire_o && !branch_redirect_valid_o);

        clear_inputs();
        slot1_issue_valid = 1'b1;
        slot1_pair_load = 1'b1;
        dual_issue = 1'b1;
        #1;
        `check("DISPATCH forwards slot1 issue lane visibility without fire",
               slot1_issue_valid_o && dual_issue_o &&
               !slot1_fire_o && !slot1_accept_o &&
               !single_issue_fire_o && !dual_issue_fire_o);
        check_slot1_issue_class("DISPATCH visible slot1 keeps issue class", 1'b0, 1'b1, 1'b0, 1'b0);
        check_slot1_fire_class("DISPATCH visible slot1 without fire clears class", 1'b0, 1'b0, 1'b0, 1'b0);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_pair_compute = 1'b1;
        dual_issue = 1'b1;
        #1;
        `check("DISPATCH dual issue fire exposes both-lane accept",
               slot0_fire_o && slot1_issue_valid_o && slot1_fire_o &&
               slot0_accept_o && slot1_accept_o &&
               !single_issue_fire_o && dual_issue_fire_o);
        check_slot1_issue_class("DISPATCH compute slot1 issue class", 1'b1, 1'b0, 1'b0, 1'b0);
        check_slot1_fire_class("DISPATCH compute slot1 fire class", 1'b1, 1'b0, 1'b0, 1'b0);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_pair_load = 1'b1;
        dual_issue = 1'b1;
        #1;
        check_slot1_fire_class("DISPATCH load slot1 fire class", 1'b0, 1'b1, 1'b0, 1'b0);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_pair_store = 1'b1;
        dual_issue = 1'b1;
        #1;
        check_slot1_fire_class("DISPATCH store slot1 fire class", 1'b0, 1'b0, 1'b1, 1'b0);

        clear_inputs();
        s5_valid = 1'b1;
        issue_ready_go = 1'b1;
        s6_allowin = 1'b1;
        consume_allow = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_pair_ctrl = 1'b1;
        dual_issue = 1'b1;
        #1;
        check_slot1_fire_class("DISPATCH control slot1 fire class", 1'b0, 1'b0, 1'b0, 1'b1);

        finish_tb();
    end
endmodule
