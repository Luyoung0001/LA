`timescale 1ns / 1ps

module s1_if0_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s1_valid;
    logic        s1_ready_go;
    logic        s1_allowin;
    logic        s1_to_s2_valid;
    logic        redirect_fire;
    logic        bpu_redirect_fire;
    logic        seq_advance;
    logic        pc_accept;
    logic [31:0] s1_pc;
    logic [1:0]  s1_epoch;
    logic [31:0] next_pc;
    logic [1:0]  next_epoch;

    logic        s1_to_s2_valid_o;
    logic [31:0] s1_pc_o;
    logic [1:0]  s1_epoch_o;
    logic [3:0]  stage_event_summary_o;
    logic [3:0]  pc_select_summary_o;
    logic [15:0] if0_event_reason_o;

    s1_if0_event_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .s1_valid_i(s1_valid),
        .s1_ready_go_i(s1_ready_go),
        .s1_allowin_i(s1_allowin),
        .s1_to_s2_valid_i(s1_to_s2_valid),
        .redirect_fire_i(redirect_fire),
        .bpu_redirect_fire_i(bpu_redirect_fire),
        .seq_advance_i(seq_advance),
        .pc_accept_i(pc_accept),
        .s1_pc_i(s1_pc),
        .s1_epoch_i(s1_epoch),
        .next_pc_i(next_pc),
        .next_epoch_i(next_epoch),
        .s1_to_s2_valid_o(s1_to_s2_valid_o),
        .s1_pc_o(s1_pc_o),
        .s1_epoch_o(s1_epoch_o),
        .stage_event_summary_o(stage_event_summary_o),
        .pc_select_summary_o(pc_select_summary_o),
        .if0_event_reason_o(if0_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s1_valid = 1'b0;
            s1_ready_go = 1'b0;
            s1_allowin = 1'b0;
            s1_to_s2_valid = 1'b0;
            redirect_fire = 1'b0;
            bpu_redirect_fire = 1'b0;
            seq_advance = 1'b0;
            pc_accept = 1'b0;
            s1_pc = 32'd0;
            s1_epoch = 2'd0;
            next_pc = 32'd0;
            next_epoch = 2'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S1EVT idle clears visible events",
               !s1_to_s2_valid_o && s1_pc_o == 32'd0 && s1_epoch_o == 2'd0);
        `check32("S1EVT idle summaries clear",
                 {8'd0, stage_event_summary_o, pc_select_summary_o,
                  if0_event_reason_o}, 32'd0);

        clear_inputs();
        s1_valid = 1'b1;
        s1_ready_go = 1'b1;
        s1_allowin = 1'b1;
        s1_to_s2_valid = 1'b1;
        seq_advance = 1'b1;
        pc_accept = 1'b1;
        s1_pc = 32'h8000_0000;
        s1_epoch = 2'd1;
        next_pc = 32'h8000_0004;
        next_epoch = 2'd1;
        #1;
        `check("S1EVT forwards sequential fetch output", s1_to_s2_valid_o);
        `check32("S1EVT forwards PC", s1_pc_o, 32'h8000_0000);
        `check32("S1EVT forwards epoch", {30'd0, s1_epoch_o}, 32'd1);
        `check32("S1EVT packs stage summary",
                 {28'd0, stage_event_summary_o}, {28'd0, 4'b1111});
        `check32("S1EVT packs sequential select",
                 {28'd0, pc_select_summary_o}, {28'd0, 4'b0011});
        `check32("S1EVT packs sequential reason",
                 {16'd0, if0_event_reason_o}, 32'h3f41);

        clear_inputs();
        s1_valid = 1'b1;
        s1_ready_go = 1'b1;
        redirect_fire = 1'b1;
        bpu_redirect_fire = 1'b1;
        s1_pc = 32'h8000_0100;
        s1_epoch = 2'd2;
        next_pc = 32'h9000_0000;
        next_epoch = 2'd3;
        #1;
        `check("S1EVT forwards redirect-hold output",
               !s1_to_s2_valid_o && s1_pc_o == 32'h8000_0100);
        `check32("S1EVT packs redirect select",
                 {28'd0, pc_select_summary_o}, {28'd0, 4'b1101});
        `check32("S1EVT packs redirect reason",
                 {16'd0, if0_event_reason_o}, 32'hc303);

        finish_tb();
    end
endmodule
