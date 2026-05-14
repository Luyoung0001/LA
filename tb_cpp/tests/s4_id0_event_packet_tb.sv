`timescale 1ns / 1ps

module s4_id0_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s4_valid;
    logic        s4_ready_go;
    logic        s4_allowin;
    logic        s4_to_s5_valid;
    logic        s4_fire;
    logic        stale;
    logic        fault;
    logic        slot0_valid;
    logic        slot1_valid;
    logic        pred_taken;
    logic [31:0] pred_target;
    logic        redirect_valid;
    logic [31:0] redirect_pc;
    logic        ras_update_valid;
    logic [31:0] ras_update_pc;
    logic        ras_update_is_call;
    logic        ras_update_is_ret;

    logic        pred_taken_o;
    logic [31:0] pred_target_o;
    logic        redirect_valid_o;
    logic [31:0] redirect_pc_o;
    logic        ras_update_valid_o;
    logic [31:0] ras_update_pc_o;
    logic        ras_update_is_call_o;
    logic        ras_update_is_ret_o;
    logic [3:0]  stage_event_summary_o;
    logic [3:0]  decode_event_summary_o;
    logic [15:0] id0_event_reason_o;

    s4_id0_event_packet u_dut (
        .s4_valid_i(s4_valid),
        .s4_ready_go_i(s4_ready_go),
        .s4_allowin_i(s4_allowin),
        .s4_to_s5_valid_i(s4_to_s5_valid),
        .s4_fire_i(s4_fire),
        .stale_i(stale),
        .fault_i(fault),
        .slot0_valid_i(slot0_valid),
        .slot1_valid_i(slot1_valid),
        .pred_taken_i(pred_taken),
        .pred_target_i(pred_target),
        .redirect_valid_i(redirect_valid),
        .redirect_pc_i(redirect_pc),
        .ras_update_valid_i(ras_update_valid),
        .ras_update_pc_i(ras_update_pc),
        .ras_update_is_call_i(ras_update_is_call),
        .ras_update_is_ret_i(ras_update_is_ret),
        .pred_taken_o(pred_taken_o),
        .pred_target_o(pred_target_o),
        .redirect_valid_o(redirect_valid_o),
        .redirect_pc_o(redirect_pc_o),
        .ras_update_valid_o(ras_update_valid_o),
        .ras_update_pc_o(ras_update_pc_o),
        .ras_update_is_call_o(ras_update_is_call_o),
        .ras_update_is_ret_o(ras_update_is_ret_o),
        .stage_event_summary_o(stage_event_summary_o),
        .decode_event_summary_o(decode_event_summary_o),
        .id0_event_reason_o(id0_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s4_valid = 1'b0;
            s4_ready_go = 1'b0;
            s4_allowin = 1'b0;
            s4_to_s5_valid = 1'b0;
            s4_fire = 1'b0;
            stale = 1'b0;
            fault = 1'b0;
            slot0_valid = 1'b0;
            slot1_valid = 1'b0;
            pred_taken = 1'b0;
            pred_target = 32'd0;
            redirect_valid = 1'b0;
            redirect_pc = 32'd0;
            ras_update_valid = 1'b0;
            ras_update_pc = 32'd0;
            ras_update_is_call = 1'b0;
            ras_update_is_ret = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S4EVT idle clears visible events",
               !pred_taken_o && !redirect_valid_o && !ras_update_valid_o);
        `check32("S4EVT idle summaries clear",
                 {8'd0, stage_event_summary_o,
                  decode_event_summary_o, id0_event_reason_o}, 32'd0);
        `check32("S4EVT idle target pass-through zero", pred_target_o, 32'd0);

        clear_inputs();
        s4_valid = 1'b1;
        s4_ready_go = 1'b1;
        s4_allowin = 1'b1;
        s4_to_s5_valid = 1'b1;
        s4_fire = 1'b1;
        slot0_valid = 1'b1;
        slot1_valid = 1'b1;
        #1;
        `check32("S4EVT packs ready/fire summary",
                 {28'd0, stage_event_summary_o}, {28'd0, 4'b1111});
        `check32("S4EVT packs slot summary",
                 {28'd0, decode_event_summary_o}, {28'd0, 4'b0011});
        `check32("S4EVT ready reason",
                 {16'd0, id0_event_reason_o}, 32'h01fc);

        clear_inputs();
        pred_taken = 1'b1;
        pred_target = 32'h1c00_0020;
        redirect_valid = 1'b1;
        redirect_pc = 32'h1c00_0100;
        #1;
        `check("S4EVT forwards prediction and redirect",
               pred_taken_o && redirect_valid_o);
        `check32("S4EVT forwards pred target", pred_target_o, 32'h1c00_0020);
        `check32("S4EVT forwards redirect pc", redirect_pc_o, 32'h1c00_0100);
        `check32("S4EVT packs redirect reason",
                 {16'd0, id0_event_reason_o}, 32'h1800);

        clear_inputs();
        s4_valid = 1'b1;
        stale = 1'b1;
        fault = 1'b1;
        slot0_valid = 1'b1;
        #1;
        `check32("S4EVT packs stale/fault reason",
                 {16'd0, id0_event_reason_o}, 32'h0684);

        clear_inputs();
        ras_update_valid = 1'b1;
        ras_update_pc = 32'h1c00_0200;
        ras_update_is_call = 1'b1;
        #1;
        `check("S4EVT forwards call RAS update",
               ras_update_valid_o && ras_update_is_call_o && !ras_update_is_ret_o);
        `check32("S4EVT forwards call pc", ras_update_pc_o, 32'h1c00_0200);
        `check32("S4EVT packs call summary",
                 {28'd0, decode_event_summary_o}, {28'd0, 4'b1000});
        `check32("S4EVT packs call reason",
                 {16'd0, id0_event_reason_o}, 32'ha000);

        clear_inputs();
        ras_update_is_ret = 1'b1;
        #1;
        `check("S4EVT masks RAS flags when invalid",
               !ras_update_valid_o && !ras_update_is_call_o && !ras_update_is_ret_o);
        `check32("S4EVT preserves invalid RAS pc as zero", ras_update_pc_o, 32'd0);

        finish_tb();
    end
endmodule
