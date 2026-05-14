`timescale 1ns / 1ps

module s7_ex_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s7_ready_go;
    logic        s7_to_s8_valid;
    logic        s7_allowin;
    logic        load_use_hazard;
    logic        rs1_late_s10;
    logic        rs2_late_s10;
    logic        rs1_wait_raw;
    logic        rs2_wait_raw;
    logic        rs1_wait_s8;
    logic        rs1_wait_s8_slot1;
    logic        rs1_wait_s9;
    logic        rs1_wait_s9_slot1;
    logic        rs1_wait_s10;
    logic        rs1_wait_s10_slot1;
    logic        rs2_wait_s8;
    logic        rs2_wait_s8_slot1;
    logic        rs2_wait_s9;
    logic        rs2_wait_s9_slot1;
    logic        rs2_wait_s10;
    logic        rs2_wait_s10_slot1;
    logic        slot1_emit_valid;
    logic        slot1_fire;
    logic [3:0]  slot1_emit_class;
    logic        branch_redirect_valid;
    logic [31:0] branch_redirect_pc;
    logic        branch_redirected;

    logic        s7_ready_go_o;
    logic        s7_to_s8_valid_o;
    logic        s7_allowin_o;
    logic        load_use_hazard_o;
    logic        rs1_late_s10_o;
    logic        rs2_late_s10_o;
    logic        rs1_wait_raw_o;
    logic        rs2_wait_raw_o;
    logic        slot1_emit_valid_o;
    logic        slot1_fire_o;
    logic [3:0]  slot1_emit_class_o;
    logic        branch_redirect_valid_o;
    logic [31:0] branch_redirect_pc_o;
    logic        branch_redirected_o;
    logic [11:0] operand_wait_summary_o;
    logic [3:0]  late_wait_summary_o;
    logic [11:0] ex_event_reason_o;

    s7_ex_event_packet u_dut (
        .s7_ready_go_i(s7_ready_go),
        .s7_to_s8_valid_i(s7_to_s8_valid),
        .s7_allowin_i(s7_allowin),
        .load_use_hazard_i(load_use_hazard),
        .rs1_late_s10_i(rs1_late_s10),
        .rs2_late_s10_i(rs2_late_s10),
        .rs1_wait_raw_i(rs1_wait_raw),
        .rs2_wait_raw_i(rs2_wait_raw),
        .rs1_wait_s8_i(rs1_wait_s8),
        .rs1_wait_s8_slot1_i(rs1_wait_s8_slot1),
        .rs1_wait_s9_i(rs1_wait_s9),
        .rs1_wait_s9_slot1_i(rs1_wait_s9_slot1),
        .rs1_wait_s10_i(rs1_wait_s10),
        .rs1_wait_s10_slot1_i(rs1_wait_s10_slot1),
        .rs2_wait_s8_i(rs2_wait_s8),
        .rs2_wait_s8_slot1_i(rs2_wait_s8_slot1),
        .rs2_wait_s9_i(rs2_wait_s9),
        .rs2_wait_s9_slot1_i(rs2_wait_s9_slot1),
        .rs2_wait_s10_i(rs2_wait_s10),
        .rs2_wait_s10_slot1_i(rs2_wait_s10_slot1),
        .slot1_emit_valid_i(slot1_emit_valid),
        .slot1_fire_i(slot1_fire),
        .slot1_emit_class_i(slot1_emit_class),
        .branch_redirect_valid_i(branch_redirect_valid),
        .branch_redirect_pc_i(branch_redirect_pc),
        .branch_redirected_i(branch_redirected),
        .s7_ready_go_o(s7_ready_go_o),
        .s7_to_s8_valid_o(s7_to_s8_valid_o),
        .s7_allowin_o(s7_allowin_o),
        .load_use_hazard_o(load_use_hazard_o),
        .rs1_late_s10_o(rs1_late_s10_o),
        .rs2_late_s10_o(rs2_late_s10_o),
        .rs1_wait_raw_o(rs1_wait_raw_o),
        .rs2_wait_raw_o(rs2_wait_raw_o),
        .slot1_emit_valid_o(slot1_emit_valid_o),
        .slot1_fire_o(slot1_fire_o),
        .slot1_emit_class_o(slot1_emit_class_o),
        .branch_redirect_valid_o(branch_redirect_valid_o),
        .branch_redirect_pc_o(branch_redirect_pc_o),
        .branch_redirected_o(branch_redirected_o),
        .operand_wait_summary_o(operand_wait_summary_o),
        .late_wait_summary_o(late_wait_summary_o),
        .ex_event_reason_o(ex_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s7_ready_go = 1'b0;
            s7_to_s8_valid = 1'b0;
            s7_allowin = 1'b0;
            load_use_hazard = 1'b0;
            rs1_late_s10 = 1'b0;
            rs2_late_s10 = 1'b0;
            rs1_wait_raw = 1'b0;
            rs2_wait_raw = 1'b0;
            rs1_wait_s8 = 1'b0;
            rs1_wait_s8_slot1 = 1'b0;
            rs1_wait_s9 = 1'b0;
            rs1_wait_s9_slot1 = 1'b0;
            rs1_wait_s10 = 1'b0;
            rs1_wait_s10_slot1 = 1'b0;
            rs2_wait_s8 = 1'b0;
            rs2_wait_s8_slot1 = 1'b0;
            rs2_wait_s9 = 1'b0;
            rs2_wait_s9_slot1 = 1'b0;
            rs2_wait_s10 = 1'b0;
            rs2_wait_s10_slot1 = 1'b0;
            slot1_emit_valid = 1'b0;
            slot1_fire = 1'b0;
            slot1_emit_class = 4'd0;
            branch_redirect_valid = 1'b0;
            branch_redirect_pc = 32'd0;
            branch_redirected = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("EXEVT idle clears control",
               !s7_ready_go_o && !s7_to_s8_valid_o && !s7_allowin_o &&
               !load_use_hazard_o && !slot1_emit_valid_o &&
               !branch_redirect_valid_o && !branch_redirected_o);
        `check32("EXEVT idle summaries clear",
                 {16'd0, operand_wait_summary_o, late_wait_summary_o}, 32'd0);
        `check32("EXEVT idle reason clear",
                 {20'd0, ex_event_reason_o}, 32'd0);

        clear_inputs();
        s7_ready_go = 1'b1;
        s7_to_s8_valid = 1'b1;
        s7_allowin = 1'b1;
        #1;
        `check("EXEVT forwards stage handshake",
               s7_ready_go_o && s7_to_s8_valid_o && s7_allowin_o);
        `check32("EXEVT ready reason",
                 {20'd0, ex_event_reason_o}, 32'h00e);

        clear_inputs();
        load_use_hazard = 1'b1;
        rs1_wait_raw = 1'b1;
        rs2_late_s10 = 1'b1;
        rs1_wait_s8 = 1'b1;
        rs1_wait_s10_slot1 = 1'b1;
        rs2_wait_s9_slot1 = 1'b1;
        rs2_wait_s10 = 1'b1;
        #1;
        `check("EXEVT forwards operand wait and late flags",
               load_use_hazard_o && rs1_wait_raw_o && !rs2_wait_raw_o &&
               !rs1_late_s10_o && rs2_late_s10_o);
        `check32("EXEVT operand wait summary packs operands",
                 {20'd0, operand_wait_summary_o}, {20'd0, 12'b011000100001});
        `check32("EXEVT late wait summary packs raw and late",
                 {28'd0, late_wait_summary_o}, {28'd0, 4'b1001});
        `check32("EXEVT hazard reason",
                 {20'd0, ex_event_reason_o}, 32'h191);

        clear_inputs();
        s7_ready_go = 1'b1;
        s7_to_s8_valid = 1'b1;
        s7_allowin = 1'b1;
        slot1_emit_valid = 1'b1;
        slot1_fire = 1'b1;
        slot1_emit_class = 4'b0100;
        branch_redirect_valid = 1'b1;
        branch_redirect_pc = 32'h1c00_1234;
        branch_redirected = 1'b1;
        #1;
        `check("EXEVT forwards slot1 and branch events",
               slot1_emit_valid_o && slot1_fire_o &&
               slot1_emit_class_o == 4'b0100 &&
               branch_redirect_valid_o && branch_redirected_o);
        `check32("EXEVT branch redirect PC",
                 branch_redirect_pc_o, 32'h1c00_1234);
        `check32("EXEVT branch/slot1 reason",
                 {20'd0, ex_event_reason_o}, 32'he0e);

        clear_inputs();
        slot1_emit_class = 4'b1111;
        branch_redirected = 1'b1;
        #1;
        `check("EXEVT masks invalid slot1 class but preserves redirected sideband",
               !slot1_emit_valid_o && !slot1_fire_o &&
               slot1_emit_class_o == 4'd0 && branch_redirected_o);

        finish_tb();
    end
endmodule
