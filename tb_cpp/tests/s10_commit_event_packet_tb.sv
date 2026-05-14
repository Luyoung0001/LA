`timescale 1ns / 1ps

module s10_commit_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       commit0_valid;
    logic       commit1_valid;
    logic       commit1_accept;
    logic       dual_commit;
    logic [3:0] commit_select_reason;
    logic       wb0_we;
    logic       wb1_we;
    logic       dual_wb;
    logic [3:0] wb_select_reason;

    logic       commit0_valid_o;
    logic       commit1_valid_o;
    logic       commit1_accept_o;
    logic       dual_commit_o;
    logic [3:0] commit_select_reason_o;
    logic       wb0_we_o;
    logic       wb1_we_o;
    logic       dual_wb_o;
    logic [3:0] wb_select_reason_o;
    logic       slot1_commit_held_o;
    logic       slot1_wb_held_o;
    logic [7:0] backend_event_reason_o;

    s10_commit_event_packet u_dut (
        .commit0_valid_i(commit0_valid),
        .commit1_valid_i(commit1_valid),
        .commit1_accept_i(commit1_accept),
        .dual_commit_i(dual_commit),
        .commit_select_reason_i(commit_select_reason),
        .wb0_we_i(wb0_we),
        .wb1_we_i(wb1_we),
        .dual_wb_i(dual_wb),
        .wb_select_reason_i(wb_select_reason),
        .commit0_valid_o(commit0_valid_o),
        .commit1_valid_o(commit1_valid_o),
        .commit1_accept_o(commit1_accept_o),
        .dual_commit_o(dual_commit_o),
        .commit_select_reason_o(commit_select_reason_o),
        .wb0_we_o(wb0_we_o),
        .wb1_we_o(wb1_we_o),
        .dual_wb_o(dual_wb_o),
        .wb_select_reason_o(wb_select_reason_o),
        .slot1_commit_held_o(slot1_commit_held_o),
        .slot1_wb_held_o(slot1_wb_held_o),
        .backend_event_reason_o(backend_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            commit0_valid = 1'b0;
            commit1_valid = 1'b0;
            commit1_accept = 1'b0;
            dual_commit = 1'b0;
            commit_select_reason = 4'd0;
            wb0_we = 1'b0;
            wb1_we = 1'b0;
            dual_wb = 1'b0;
            wb_select_reason = 4'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("CEVT idle forwards no events",
               !commit0_valid_o && !commit1_valid_o &&
               !commit1_accept_o && !dual_commit_o &&
               !wb0_we_o && !wb1_we_o && !dual_wb_o);
        `check("CEVT idle holds clear",
               !slot1_commit_held_o && !slot1_wb_held_o);
        `check32("CEVT idle reason clear",
                 {24'd0, backend_event_reason_o}, 32'd0);

        clear_inputs();
        commit0_valid = 1'b1;
        wb0_we = 1'b1;
        commit_select_reason = 4'h1;
        wb_select_reason = 4'h1;
        #1;
        `check("CEVT slot0-only forwards commit and write",
               commit0_valid_o && !commit1_valid_o &&
               wb0_we_o && !wb1_we_o);
        `check32("CEVT slot0-only select reasons",
                 {24'd0, commit_select_reason_o, wb_select_reason_o},
                 {24'd0, 4'h1, 4'h1});
        `check32("CEVT slot0-only event reason",
                 {24'd0, backend_event_reason_o}, 32'h05);

        clear_inputs();
        commit0_valid = 1'b1;
        commit1_valid = 1'b0;
        commit1_accept = 1'b0;
        dual_commit = 1'b0;
        wb0_we = 1'b1;
        wb1_we = 1'b0;
        dual_wb = 1'b0;
        commit_select_reason = 4'h7;
        wb_select_reason = 4'h7;
        #1;
        `check("CEVT held slot1 candidate exposes hold flags",
               commit0_valid_o && wb0_we_o &&
               slot1_commit_held_o && slot1_wb_held_o);
        `check32("CEVT held slot1 reason",
                 {24'd0, backend_event_reason_o}, 32'hc5);

        clear_inputs();
        commit0_valid = 1'b1;
        commit1_valid = 1'b1;
        commit1_accept = 1'b1;
        dual_commit = 1'b1;
        wb0_we = 1'b1;
        wb1_we = 1'b1;
        dual_wb = 1'b1;
        commit_select_reason = 4'h3;
        wb_select_reason = 4'h3;
        #1;
        `check("CEVT dual commit/write forwards all events",
               commit0_valid_o && commit1_valid_o &&
               commit1_accept_o && dual_commit_o &&
               wb0_we_o && wb1_we_o && dual_wb_o);
        `check("CEVT dual commit/write clears hold flags",
               !slot1_commit_held_o && !slot1_wb_held_o);
        `check32("CEVT dual event reason",
                 {24'd0, backend_event_reason_o}, 32'h3f);

        clear_inputs();
        commit0_valid = 1'b1;
        commit1_valid = 1'b1;
        commit1_accept = 1'b1;
        dual_commit = 1'b1;
        wb0_we = 1'b1;
        wb1_we = 1'b1;
        dual_wb = 1'b1;
        commit_select_reason = 4'h3;
        wb_select_reason = 4'hb;
        #1;
        `check("CEVT accepted WAW write keeps write event and reasons",
               commit0_valid_o && commit1_valid_o &&
               wb0_we_o && wb1_we_o && dual_wb_o &&
               !slot1_commit_held_o && !slot1_wb_held_o);
        `check32("CEVT accepted WAW select reasons",
                 {24'd0, commit_select_reason_o, wb_select_reason_o},
                 {24'd0, 4'h3, 4'hb});
        `check32("CEVT accepted WAW event reason",
                 {24'd0, backend_event_reason_o}, 32'h3f);

        finish_tb();
    end
endmodule
