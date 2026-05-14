`timescale 1ns / 1ps

module s7_operand_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s7_valid;
    logic s8_allowin;
    logic inst_late_load_bypass;
    logic s10_load_uncached;
    logic rs1_hold_valid;
    logic rs2_hold_valid;
    logic rs1_wait_s8;
    logic rs1_wait_s8_slot1;
    logic rs1_wait_s9;
    logic rs1_wait_s9_slot1;
    logic rs1_wait_s10;
    logic rs1_wait_s10_slot1;
    logic rs1_newer_than_s10_match;
    logic rs2_wait_s8;
    logic rs2_wait_s8_slot1;
    logic rs2_wait_s9;
    logic rs2_wait_s9_slot1;
    logic rs2_wait_s10;
    logic rs2_wait_s10_slot1;
    logic rs2_newer_than_s10_match;
    logic slot1_valid;
    logic slot1_issue_valid;
    logic [3:0] slot1_issue_class;
    logic slot1_wait_raw;

    logic rs1_late_s10;
    logic rs2_late_s10;
    logic rs1_wait_raw;
    logic rs2_wait_raw;
    logic load_use_hazard;
    logic ready_go;
    logic allowin;
    logic to_next_valid;
    logic slot1_emit_valid;
    logic slot1_fire;
    logic [3:0] slot1_emit_class;

    s7_operand_stage_ctrl u_dut (
        .s7_valid_i(s7_valid),
        .s8_allowin_i(s8_allowin),
        .inst_late_load_bypass_i(inst_late_load_bypass),
        .s10_load_uncached_i(s10_load_uncached),
        .rs1_hold_valid_i(rs1_hold_valid),
        .rs2_hold_valid_i(rs2_hold_valid),
        .rs1_wait_s8_i(rs1_wait_s8),
        .rs1_wait_s8_slot1_i(rs1_wait_s8_slot1),
        .rs1_wait_s9_i(rs1_wait_s9),
        .rs1_wait_s9_slot1_i(rs1_wait_s9_slot1),
        .rs1_wait_s10_i(rs1_wait_s10),
        .rs1_wait_s10_slot1_i(rs1_wait_s10_slot1),
        .rs1_newer_than_s10_match_i(rs1_newer_than_s10_match),
        .rs2_wait_s8_i(rs2_wait_s8),
        .rs2_wait_s8_slot1_i(rs2_wait_s8_slot1),
        .rs2_wait_s9_i(rs2_wait_s9),
        .rs2_wait_s9_slot1_i(rs2_wait_s9_slot1),
        .rs2_wait_s10_i(rs2_wait_s10),
        .rs2_wait_s10_slot1_i(rs2_wait_s10_slot1),
        .rs2_newer_than_s10_match_i(rs2_newer_than_s10_match),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_wait_raw_i(slot1_wait_raw),
        .rs1_late_s10_o(rs1_late_s10),
        .rs2_late_s10_o(rs2_late_s10),
        .rs1_wait_raw_o(rs1_wait_raw),
        .rs2_wait_raw_o(rs2_wait_raw),
        .load_use_hazard_o(load_use_hazard),
        .ready_go_o(ready_go),
        .allowin_o(allowin),
        .to_next_valid_o(to_next_valid),
        .slot1_emit_valid_o(slot1_emit_valid),
        .slot1_fire_o(slot1_fire),
        .slot1_emit_class_o(slot1_emit_class)
    );

    task automatic clear_inputs;
        begin
            s7_valid = 1'b0;
            s8_allowin = 1'b0;
            inst_late_load_bypass = 1'b0;
            s10_load_uncached = 1'b0;
            rs1_hold_valid = 1'b0;
            rs2_hold_valid = 1'b0;
            rs1_wait_s8 = 1'b0;
            rs1_wait_s8_slot1 = 1'b0;
            rs1_wait_s9 = 1'b0;
            rs1_wait_s9_slot1 = 1'b0;
            rs1_wait_s10 = 1'b0;
            rs1_wait_s10_slot1 = 1'b0;
            rs1_newer_than_s10_match = 1'b0;
            rs2_wait_s8 = 1'b0;
            rs2_wait_s8_slot1 = 1'b0;
            rs2_wait_s9 = 1'b0;
            rs2_wait_s9_slot1 = 1'b0;
            rs2_wait_s10 = 1'b0;
            rs2_wait_s10_slot1 = 1'b0;
            rs2_newer_than_s10_match = 1'b0;
            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
            slot1_wait_raw = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S7CTRL empty stage can accept input",
               ready_go && allowin && !to_next_valid && !load_use_hazard &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        #1;
        `check("S7CTRL valid ready stage advances",
               ready_go && allowin && to_next_valid &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S7CTRL emits and fires selected slot1 with lane0",
               to_next_valid && slot1_emit_valid && slot1_fire &&
               slot1_emit_class == 4'b1000);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S7CTRL downstream backpressure blocks allowin only",
               ready_go && !allowin && to_next_valid &&
               slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'b1000);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        rs1_wait_s8 = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S7CTRL rs1 raw wait stalls stage",
               rs1_wait_raw && load_use_hazard &&
               !ready_go && !allowin && !to_next_valid &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        rs1_hold_valid = 1'b1;
        #1;
        `check("S7CTRL held rs1 value masks hazard",
               rs1_wait_raw && !load_use_hazard &&
               ready_go && allowin && to_next_valid &&
               slot1_emit_valid && slot1_fire && slot1_emit_class == 4'b1000);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        inst_late_load_bypass = 1'b1;
        rs1_wait_s10 = 1'b1;
        #1;
        `check("S7CTRL late S10 bypass clears rs1 raw wait",
               rs1_late_s10 && !rs1_wait_raw &&
               !load_use_hazard && ready_go);

        s10_load_uncached = 1'b1;
        #1;
        `check("S7CTRL uncached S10 disables late bypass",
               !rs1_late_s10 && rs1_wait_raw && load_use_hazard);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        inst_late_load_bypass = 1'b1;
        rs2_wait_s10 = 1'b1;
        rs2_newer_than_s10_match = 1'b1;
        #1;
        `check("S7CTRL newer producer suppresses S10 wait",
               !rs2_late_s10 && !rs2_wait_raw &&
               !load_use_hazard && ready_go);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        inst_late_load_bypass = 1'b1;
        rs2_wait_s10 = 1'b1;
        rs2_wait_s9_slot1 = 1'b1;
        #1;
        `check("S7CTRL newer slot wait blocks late S10 bypass",
               !rs2_late_s10 && rs2_wait_raw && load_use_hazard);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        slot1_issue_class = 4'b1111;
        #1;
        `check("S7CTRL masks slot1 class when slot1 is invalid",
               to_next_valid && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        #1;
        `check("S7CTRL masks slot1 class when slot1 is held but not issued",
               to_next_valid && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        clear_inputs();
        s7_valid = 1'b1;
        s8_allowin = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        slot1_wait_raw = 1'b1;
        #1;
        `check("S7CTRL slot1 raw wait stalls whole EX1 packet",
               load_use_hazard && !ready_go && !allowin && !to_next_valid &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        finish_tb();
    end
endmodule
