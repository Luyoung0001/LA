`timescale 1ns / 1ps

module s8_ex_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s8_valid;
    logic        s8_ready_go;
    logic        s8_allowin;
    logic        s8_to_s9_valid;
    logic        s8_fire;
    logic        late_s10_ready;
    logic        late_s10_wait;
    logic        div_wait;
    logic        result_wait;
    logic        slot1_emit_valid;
    logic        slot1_fire;
    logic [3:0]  slot1_emit_class;
    logic        redirect_valid;
    logic [31:0] redirect_pc;
    logic        branch_taken;
    logic        lane0_bpu_update_valid;
    logic        lane1_bpu_update_valid;
    logic        bpu_update_valid;
    logic [31:0] bpu_update_pc;
    logic        bpu_update_taken;
    logic [31:0] bpu_update_target;
    logic        bpu_update_is_call;
    logic        bpu_update_is_ret;
    logic        bpu_update_is_jmp;
    logic        bpu_update_is_indirect_jmp;

    logic        slot1_emit_valid_o;
    logic        slot1_fire_o;
    logic [3:0]  slot1_emit_class_o;
    logic        redirect_valid_o;
    logic [31:0] redirect_pc_o;
    logic        branch_taken_o;
    logic        bpu_update_valid_o;
    logic [31:0] bpu_update_pc_o;
    logic        bpu_update_taken_o;
    logic [31:0] bpu_update_target_o;
    logic        bpu_update_is_call_o;
    logic        bpu_update_is_ret_o;
    logic        bpu_update_is_jmp_o;
    logic        bpu_update_is_indirect_jmp_o;
    logic        result_wait_o;
    logic [3:0]  stage_event_summary_o;
    logic [3:0]  wait_event_summary_o;
    logic [3:0]  control_event_summary_o;
    logic [15:0] ex_event_reason_o;

    s8_ex_event_packet u_dut (
        .s8_valid_i(s8_valid),
        .s8_ready_go_i(s8_ready_go),
        .s8_allowin_i(s8_allowin),
        .s8_to_s9_valid_i(s8_to_s9_valid),
        .s8_fire_i(s8_fire),
        .late_s10_ready_i(late_s10_ready),
        .late_s10_wait_i(late_s10_wait),
        .div_wait_i(div_wait),
        .result_wait_i(result_wait),
        .slot1_emit_valid_i(slot1_emit_valid),
        .slot1_fire_i(slot1_fire),
        .slot1_emit_class_i(slot1_emit_class),
        .redirect_valid_i(redirect_valid),
        .redirect_pc_i(redirect_pc),
        .branch_taken_i(branch_taken),
        .lane0_bpu_update_valid_i(lane0_bpu_update_valid),
        .lane1_bpu_update_valid_i(lane1_bpu_update_valid),
        .bpu_update_valid_i(bpu_update_valid),
        .bpu_update_pc_i(bpu_update_pc),
        .bpu_update_taken_i(bpu_update_taken),
        .bpu_update_target_i(bpu_update_target),
        .bpu_update_is_call_i(bpu_update_is_call),
        .bpu_update_is_ret_i(bpu_update_is_ret),
        .bpu_update_is_jmp_i(bpu_update_is_jmp),
        .bpu_update_is_indirect_jmp_i(bpu_update_is_indirect_jmp),
        .slot1_emit_valid_o(slot1_emit_valid_o),
        .slot1_fire_o(slot1_fire_o),
        .slot1_emit_class_o(slot1_emit_class_o),
        .redirect_valid_o(redirect_valid_o),
        .redirect_pc_o(redirect_pc_o),
        .branch_taken_o(branch_taken_o),
        .bpu_update_valid_o(bpu_update_valid_o),
        .bpu_update_pc_o(bpu_update_pc_o),
        .bpu_update_taken_o(bpu_update_taken_o),
        .bpu_update_target_o(bpu_update_target_o),
        .bpu_update_is_call_o(bpu_update_is_call_o),
        .bpu_update_is_ret_o(bpu_update_is_ret_o),
        .bpu_update_is_jmp_o(bpu_update_is_jmp_o),
        .bpu_update_is_indirect_jmp_o(bpu_update_is_indirect_jmp_o),
        .result_wait_o(result_wait_o),
        .stage_event_summary_o(stage_event_summary_o),
        .wait_event_summary_o(wait_event_summary_o),
        .control_event_summary_o(control_event_summary_o),
        .ex_event_reason_o(ex_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s8_valid = 1'b0;
            s8_ready_go = 1'b0;
            s8_allowin = 1'b0;
            s8_to_s9_valid = 1'b0;
            s8_fire = 1'b0;
            late_s10_ready = 1'b0;
            late_s10_wait = 1'b0;
            div_wait = 1'b0;
            result_wait = 1'b0;
            slot1_emit_valid = 1'b0;
            slot1_fire = 1'b0;
            slot1_emit_class = 4'd0;
            redirect_valid = 1'b0;
            redirect_pc = 32'd0;
            branch_taken = 1'b0;
            lane0_bpu_update_valid = 1'b0;
            lane1_bpu_update_valid = 1'b0;
            bpu_update_valid = 1'b0;
            bpu_update_pc = 32'd0;
            bpu_update_taken = 1'b0;
            bpu_update_target = 32'd0;
            bpu_update_is_call = 1'b0;
            bpu_update_is_ret = 1'b0;
            bpu_update_is_jmp = 1'b0;
            bpu_update_is_indirect_jmp = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S8EVT idle clears visible events",
               !slot1_emit_valid_o && !slot1_fire_o && !redirect_valid_o &&
               !bpu_update_valid_o && !result_wait_o);
        `check32("S8EVT idle summaries clear",
                 {16'd0, stage_event_summary_o, wait_event_summary_o,
                  control_event_summary_o, slot1_emit_class_o}, 32'd0);
        `check32("S8EVT idle masks invalid BPU payload", bpu_update_pc_o, 32'd0);

        clear_inputs();
        s8_valid = 1'b1;
        s8_ready_go = 1'b1;
        s8_allowin = 1'b1;
        s8_to_s9_valid = 1'b1;
        s8_fire = 1'b1;
        late_s10_ready = 1'b1;
        #1;
        `check32("S8EVT packs ready/fire summary",
                 {28'd0, stage_event_summary_o}, {28'd0, 4'b1111});
        `check32("S8EVT packs wait-ready summary",
                 {28'd0, wait_event_summary_o}, {28'd0, 4'b0001});
        `check32("S8EVT ready reason",
                 {16'd0, ex_event_reason_o}, 32'h01f1);

        clear_inputs();
        late_s10_wait = 1'b1;
        div_wait = 1'b1;
        result_wait = 1'b1;
        #1;
        `check("S8EVT forwards wait state", result_wait_o);
        `check32("S8EVT packs wait reasons",
                 {28'd0, wait_event_summary_o}, {28'd0, 4'b1110});
        `check32("S8EVT wait reason bits",
                 {16'd0, ex_event_reason_o}, 32'h0e00);

        clear_inputs();
        slot1_emit_valid = 1'b1;
        slot1_fire = 1'b1;
        slot1_emit_class = 4'b0100;
        redirect_valid = 1'b1;
        redirect_pc = 32'h1c00_0040;
        branch_taken = 1'b1;
        #1;
        `check("S8EVT forwards slot1 and redirect events",
               slot1_emit_valid_o && slot1_fire_o &&
               slot1_emit_class_o == 4'b0100 &&
               redirect_valid_o && branch_taken_o);
        `check32("S8EVT forwards redirect pc", redirect_pc_o, 32'h1c00_0040);
        `check32("S8EVT packs control summary",
                 {28'd0, control_event_summary_o}, {28'd0, 4'b0111});

        clear_inputs();
        bpu_update_valid = 1'b1;
        lane1_bpu_update_valid = 1'b1;
        bpu_update_pc = 32'h1c00_0080;
        bpu_update_taken = 1'b1;
        bpu_update_target = 32'h1c00_0120;
        bpu_update_is_call = 1'b1;
        bpu_update_is_jmp = 1'b1;
        #1;
        `check("S8EVT forwards BPU update payload",
               bpu_update_valid_o && bpu_update_taken_o &&
               bpu_update_is_call_o && !bpu_update_is_ret_o &&
               bpu_update_is_jmp_o && !bpu_update_is_indirect_jmp_o);
        `check32("S8EVT forwards BPU update pc", bpu_update_pc_o, 32'h1c00_0080);
        `check32("S8EVT forwards BPU update target", bpu_update_target_o, 32'h1c00_0120);
        `check32("S8EVT packs BPU reason",
                 {16'd0, ex_event_reason_o}, 32'h8004);

        clear_inputs();
        slot1_emit_class = 4'b1111;
        bpu_update_pc = 32'hffff_ffff;
        bpu_update_target = 32'heeee_eeee;
        #1;
        `check("S8EVT masks invalid slot1 class and BPU flags",
               slot1_emit_class_o == 4'd0 && !bpu_update_taken_o &&
               !bpu_update_is_call_o && !bpu_update_is_jmp_o);
        `check32("S8EVT masks invalid BPU pc", bpu_update_pc_o, 32'd0);
        `check32("S8EVT masks invalid BPU target", bpu_update_target_o, 32'd0);

        finish_tb();
    end
endmodule
