`timescale 1ns / 1ps

module s5_issue_scoreboard_tb;
    localparam [1:0] FWD_RF  = 2'd0;
    localparam [1:0] FWD_S8  = 2'd1;
    localparam [1:0] FWD_S9  = 2'd2;
    localparam [1:0] FWD_S10 = 2'd3;

    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic uses_rs1, uses_rs2;
    logic slot1_valid, slot1_uses_rs1, slot1_uses_rs2;
    logic s6_valid, s6_wb_en;
    logic s6_slot1_issue_valid, s6_slot1_wb_en;
    logic s7_valid, s7_is_load, s7_wb_en;
    logic s7_slot1_issue_valid, s7_slot1_wb_en;
    logic s8_valid, s8_is_load, s8_wb_en, s8_result_wait, s8_slot1_result_wait;
    logic s8_slot1_issue_valid, s8_slot1_wb_en, s8_slot1_is_load;
    logic [3:0] s8_slot1_issue_class;
    logic s9_valid, s9_is_load, s9_wb_en;
    logic s9_slot1_issue_valid, s9_slot1_wb_en, s9_slot1_is_load;
    logic [3:0] s9_slot1_issue_class;
    logic s10_valid, s10_wb_en, s10_load_wait;
    logic s10_slot1_issue_valid, s10_slot1_wb_en, s10_slot1_load_wait;
    logic [4:0] rs1, rs2, slot1_rs1, slot1_rs2, s6_rd, s7_rd, s8_rd, s9_rd, s10_rd;
    logic [4:0] s6_slot1_rd, s7_slot1_rd, s8_slot1_rd, s9_slot1_rd, s10_slot1_rd;
    logic [31:0] s8_result, s9_result, s10_result, rf_rdata1, rf_rdata2;
    logic [31:0] s8_slot1_result, s9_slot1_result, s10_slot1_result;
    logic [31:0] slot1_rf_rdata1, slot1_rf_rdata2;
    logic rs1_ready, rs2_ready, issue_ready;
    logic [1:0] rs1_fwd_sel, rs2_fwd_sel;
    logic [2:0] issue_block_reason;
    logic rs1_wait_raw, rs2_wait_raw, load_use_hazard_raw;
    logic [31:0] rs1_val_live, rs2_val_live;
    logic slot1_rs1_ready, slot1_rs2_ready, slot1_ready;
    logic [1:0] slot1_rs1_fwd_sel, slot1_rs2_fwd_sel;
    logic [2:0] slot1_block_reason;
    logic slot1_rs1_wait_raw, slot1_rs2_wait_raw, slot1_load_use_hazard_raw;
    logic [31:0] slot1_rs1_val_live, slot1_rs2_val_live;

    s5_issue_scoreboard #(.XLEN(32)) u_dut (
        .uses_rs1_i(uses_rs1),
        .uses_rs2_i(uses_rs2),
        .rs1_i(rs1),
        .rs2_i(rs2),
        .slot1_valid_i(slot1_valid),
        .slot1_uses_rs1_i(slot1_uses_rs1),
        .slot1_uses_rs2_i(slot1_uses_rs2),
        .slot1_rs1_i(slot1_rs1),
        .slot1_rs2_i(slot1_rs2),
        .s6_valid_i(s6_valid),
        .s6_wb_en_i(s6_wb_en),
        .s6_rd_i(s6_rd),
        .s6_slot1_issue_valid_i(s6_slot1_issue_valid),
        .s6_slot1_wb_en_i(s6_slot1_wb_en),
        .s6_slot1_rd_i(s6_slot1_rd),
        .s7_valid_i(s7_valid),
        .s7_is_load_i(s7_is_load),
        .s7_wb_en_i(s7_wb_en),
        .s7_rd_i(s7_rd),
        .s7_slot1_issue_valid_i(s7_slot1_issue_valid),
        .s7_slot1_wb_en_i(s7_slot1_wb_en),
        .s7_slot1_rd_i(s7_slot1_rd),
        .s8_valid_i(s8_valid),
        .s8_is_load_i(s8_is_load),
        .s8_wb_en_i(s8_wb_en),
        .s8_result_wait_i(s8_result_wait),
        .s8_slot1_result_wait_i(s8_slot1_result_wait),
        .s8_rd_i(s8_rd),
        .s8_result_i(s8_result),
        .s8_slot1_issue_valid_i(s8_slot1_issue_valid),
        .s8_slot1_wb_en_i(s8_slot1_wb_en),
        .s8_slot1_issue_class_i(s8_slot1_issue_class),
        .s8_slot1_rd_i(s8_slot1_rd),
        .s8_slot1_result_i(s8_slot1_result),
        .s9_valid_i(s9_valid),
        .s9_is_load_i(s9_is_load),
        .s9_wb_en_i(s9_wb_en),
        .s9_rd_i(s9_rd),
        .s9_result_i(s9_result),
        .s9_slot1_issue_valid_i(s9_slot1_issue_valid),
        .s9_slot1_wb_en_i(s9_slot1_wb_en),
        .s9_slot1_issue_class_i(s9_slot1_issue_class),
        .s9_slot1_rd_i(s9_slot1_rd),
        .s9_slot1_result_i(s9_slot1_result),
        .s10_valid_i(s10_valid),
        .s10_wb_en_i(s10_wb_en),
        .s10_load_wait_i(s10_load_wait),
        .s10_rd_i(s10_rd),
        .s10_result_i(s10_result),
        .s10_slot1_issue_valid_i(s10_slot1_issue_valid),
        .s10_slot1_wb_en_i(s10_slot1_wb_en),
        .s10_slot1_load_wait_i(s10_slot1_load_wait),
        .s10_slot1_rd_i(s10_slot1_rd),
        .s10_slot1_result_i(s10_slot1_result),
        .rf_rdata1_i(rf_rdata1),
        .rf_rdata2_i(rf_rdata2),
        .slot1_rf_rdata1_i(slot1_rf_rdata1),
        .slot1_rf_rdata2_i(slot1_rf_rdata2),
        .rs1_ready_o(rs1_ready),
        .rs2_ready_o(rs2_ready),
        .issue_ready_o(issue_ready),
        .rs1_fwd_sel_o(rs1_fwd_sel),
        .rs2_fwd_sel_o(rs2_fwd_sel),
        .issue_block_reason_o(issue_block_reason),
        .rs1_wait_raw_o(rs1_wait_raw),
        .rs2_wait_raw_o(rs2_wait_raw),
        .load_use_hazard_raw_o(load_use_hazard_raw),
        .rs1_val_live_o(rs1_val_live),
        .rs2_val_live_o(rs2_val_live),
        .slot1_rs1_ready_o(slot1_rs1_ready),
        .slot1_rs2_ready_o(slot1_rs2_ready),
        .slot1_ready_o(slot1_ready),
        .slot1_rs1_fwd_sel_o(slot1_rs1_fwd_sel),
        .slot1_rs2_fwd_sel_o(slot1_rs2_fwd_sel),
        .slot1_block_reason_o(slot1_block_reason),
        .slot1_rs1_wait_raw_o(slot1_rs1_wait_raw),
        .slot1_rs2_wait_raw_o(slot1_rs2_wait_raw),
        .slot1_load_use_hazard_raw_o(slot1_load_use_hazard_raw),
        .slot1_rs1_val_live_o(slot1_rs1_val_live),
        .slot1_rs2_val_live_o(slot1_rs2_val_live)
    );

    task automatic clear_inputs;
        begin
            uses_rs1 = 1'b0; uses_rs2 = 1'b0;
            rs1 = 5'd0; rs2 = 5'd0;
            slot1_valid = 1'b0; slot1_uses_rs1 = 1'b0; slot1_uses_rs2 = 1'b0;
            slot1_rs1 = 5'd0; slot1_rs2 = 5'd0;
            s6_valid = 1'b0; s6_wb_en = 1'b0; s6_rd = 5'd0;
            s6_slot1_issue_valid = 1'b0; s6_slot1_wb_en = 1'b0; s6_slot1_rd = 5'd0;
            s7_valid = 1'b0; s7_is_load = 1'b0; s7_wb_en = 1'b0; s7_rd = 5'd0;
            s7_slot1_issue_valid = 1'b0; s7_slot1_wb_en = 1'b0; s7_slot1_rd = 5'd0;
            s8_valid = 1'b0; s8_is_load = 1'b0; s8_wb_en = 1'b0; s8_result_wait = 1'b0; s8_slot1_result_wait = 1'b0; s8_rd = 5'd0; s8_result = 32'h0;
            s8_slot1_issue_valid = 1'b0; s8_slot1_wb_en = 1'b0; s8_slot1_is_load = 1'b0; s8_slot1_issue_class = 4'd0; s8_slot1_rd = 5'd0; s8_slot1_result = 32'h0;
            s9_valid = 1'b0; s9_is_load = 1'b0; s9_wb_en = 1'b0; s9_rd = 5'd0; s9_result = 32'h0;
            s9_slot1_issue_valid = 1'b0; s9_slot1_wb_en = 1'b0; s9_slot1_is_load = 1'b0; s9_slot1_issue_class = 4'd0; s9_slot1_rd = 5'd0; s9_slot1_result = 32'h0;
            s10_valid = 1'b0; s10_wb_en = 1'b0; s10_load_wait = 1'b0; s10_rd = 5'd0; s10_result = 32'h0;
            s10_slot1_issue_valid = 1'b0; s10_slot1_wb_en = 1'b0; s10_slot1_load_wait = 1'b0; s10_slot1_rd = 5'd0; s10_slot1_result = 32'h0;
            rf_rdata1 = 32'h1111_0001; rf_rdata2 = 32'h2222_0002;
            slot1_rf_rdata1 = 32'h3333_0003; slot1_rf_rdata2 = 32'h4444_0004;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        clear_inputs();
        #1;
        `check("SB idle has no waits", !rs1_wait_raw && !rs2_wait_raw && !load_use_hazard_raw);
        `check("SB idle reports operands ready", rs1_ready && rs2_ready && issue_ready);
        `check("SB idle invalid slot1 reports ready", slot1_rs1_ready && slot1_rs2_ready && slot1_ready);
        `check32("SB idle block reason clear", {29'd0, issue_block_reason}, 32'd0);
        `check32("SB idle slot1 block reason clear", {29'd0, slot1_block_reason}, 32'd0);
        `check32("SB idle rs1 select rf", {30'd0, rs1_fwd_sel}, {30'd0, FWD_RF});
        `check32("SB idle rs2 select rf", {30'd0, rs2_fwd_sel}, {30'd0, FWD_RF});
        `check32("SB idle rs1 keeps x0 semantic zero", rs1_val_live, 32'h0000_0000);
        `check32("SB idle rs2 keeps x0 semantic zero", rs2_val_live, 32'h0000_0000);
        `check32("SB idle slot1 rs1 keeps x0 semantic zero", slot1_rs1_val_live, 32'h0000_0000);
        `check32("SB idle slot1 rs2 keeps x0 semantic zero", slot1_rs2_val_live, 32'h0000_0000);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1; slot1_uses_rs2 = 1'b1;
        slot1_rs1 = 5'd6; slot1_rs2 = 5'd7;
        rf_rdata1 = 32'h1111_1234; rf_rdata2 = 32'h2222_5678;
        slot1_rf_rdata1 = 32'h3333_aaaa; slot1_rf_rdata2 = 32'h4444_bbbb;
        #1;
        `check("SB slot1 dedicated rf path stays ready", slot1_ready);
        `check32("SB slot1 rs1 uses dedicated rf fallback", slot1_rs1_val_live, 32'h3333_aaaa);
        `check32("SB slot1 rs2 uses dedicated rf fallback", slot1_rs2_val_live, 32'h4444_bbbb);

        clear_inputs();
        uses_rs1 = 1'b1; uses_rs2 = 1'b1;
        rs1 = 5'd3; rs2 = 5'd4;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b0; s8_result_wait = 1'b0; s8_rd = 5'd3; s8_result = 32'h8888_0003;
        s9_valid = 1'b1; s9_wb_en = 1'b1; s9_is_load = 1'b0; s9_rd = 5'd4; s9_result = 32'h9999_0004;
        #1;
        `check("SB forwarding from s8/s9 stays ready", !rs1_wait_raw && !rs2_wait_raw && !load_use_hazard_raw);
        `check("SB forwarding reports issue ready", rs1_ready && rs2_ready && issue_ready);
        `check32("SB rs1 select s8", {30'd0, rs1_fwd_sel}, {30'd0, FWD_S8});
        `check32("SB rs2 select s9", {30'd0, rs2_fwd_sel}, {30'd0, FWD_S9});
        `check32("SB rs1 forwards from s8", rs1_val_live, 32'h8888_0003);
        `check32("SB rs2 forwards from s9", rs2_val_live, 32'h9999_0004);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd7;
        s6_valid = 1'b1; s6_wb_en = 1'b1; s6_rd = 5'd7;
        #1;
        `check("SB s6 producer causes raw wait", rs1_wait_raw && !load_use_hazard_raw);
        `check("SB s6 producer clears rs1/issue ready", !rs1_ready && rs2_ready && !issue_ready);
        `check32("SB s6 block reason is rs1 wait", {29'd0, issue_block_reason}, 32'h1);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd8;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b1; s8_result_wait = 1'b1; s8_rd = 5'd8;
        #1;
        `check("SB s8 unresolved load raises load-use hazard", rs1_wait_raw && load_use_hazard_raw);
        `check("SB s8 unresolved load clears issue ready", !rs1_ready && rs2_ready && !issue_ready);
        `check32("SB s8 unresolved load block reason", {29'd0, issue_block_reason}, 32'h5);

        clear_inputs();
        uses_rs2 = 1'b1;
        rs2 = 5'd8;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b0; s8_result_wait = 1'b1; s8_rd = 5'd8;
        #1;
        `check("SB s8 result_wait non-load blocks raw only", rs2_wait_raw && !load_use_hazard_raw);
        `check32("SB s8 result_wait non-load reason excludes load-use",
                 {29'd0, issue_block_reason}, 32'h2);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd9;
        s10_valid = 1'b1; s10_wb_en = 1'b1; s10_load_wait = 1'b1; s10_rd = 5'd9;
        #1;
        `check("SB s10 pending load waits without load-use flag", rs1_wait_raw && !load_use_hazard_raw);
        `check32("SB s10 pending load block reason", {29'd0, issue_block_reason}, 32'h1);
        `check32("SB s10 pending load select stays on youngest match", {30'd0, rs1_fwd_sel}, {30'd0, FWD_S10});

        clear_inputs();
        uses_rs2 = 1'b1;
        rs2 = 5'd10;
        s7_valid = 1'b1; s7_wb_en = 1'b1; s7_is_load = 1'b0; s7_rd = 5'd10;
        #1;
        `check("SB non-load s7 result still blocks raw issue", rs2_wait_raw && !load_use_hazard_raw);
        `check("SB non-load s7 blocks only rs2", rs1_ready && !rs2_ready && !issue_ready);
        `check32("SB s7 block reason is rs2 wait", {29'd0, issue_block_reason}, 32'h2);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd11;
        s10_valid = 1'b1; s10_wb_en = 1'b1; s10_load_wait = 1'b0; s10_rd = 5'd11; s10_result = 32'haaaa_0011;
        #1;
        `check("SB s10 ready writeback forwards without wait", !rs1_wait_raw && !load_use_hazard_raw);
        `check("SB s10 ready writeback reports ready", rs1_ready && rs2_ready && issue_ready);
        `check32("SB s10 ready writeback select s10", {30'd0, rs1_fwd_sel}, {30'd0, FWD_S10});
        `check32("SB rs1 forwards from s10", rs1_val_live, 32'haaaa_0011);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd21;
        s10_valid = 1'b1;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b1;
        s10_slot1_rd = 5'd21;
        s10_slot1_result = 32'h2121_dead;
        #1;
        `check("SB slot0 waits for pending S10 lane1 load",
               rs1_wait_raw && !load_use_hazard_raw && !issue_ready);
        `check32("SB pending lane1 load keeps select on RF while waiting",
                 {30'd0, rs1_fwd_sel}, {30'd0, FWD_RF});

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd21;
        s10_valid = 1'b1;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0;
        s10_slot1_rd = 5'd21;
        s10_slot1_result = 32'h2121_cafe;
        #1;
        `check("SB slot0 forwards ready S10 lane1 load data",
               issue_ready && !rs1_wait_raw);
        `check32("SB ready lane1 load selects S10",
                 {30'd0, rs1_fwd_sel}, {30'd0, FWD_S10});
        `check32("SB ready lane1 load data forwards",
                 rs1_val_live, 32'h2121_cafe);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd27;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_load_wait = 1'b0;
        s10_rd = 5'd27;
        s10_result = 32'h2727_0000;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0;
        s10_slot1_rd = 5'd27;
        s10_slot1_result = 32'h2727_1111;
        #1;
        `check("SB slot0 reads younger S10 lane1 when both lanes write same rd",
               issue_ready && !rs1_wait_raw);
        `check32("SB same-stage S10 lane1 overrides lane0",
                 rs1_val_live, 32'h2727_1111);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd28;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_load_wait = 1'b0;
        s10_rd = 5'd28;
        s10_result = 32'h2828_0000;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b1;
        s10_slot1_rd = 5'd28;
        s10_slot1_result = 32'h2828_dead;
        #1;
        `check("SB pending younger S10 lane1 blocks older lane0 same-rd bypass",
               rs1_wait_raw && !load_use_hazard_raw && !issue_ready);
        `check32("SB pending younger S10 lane1 raises rs1 reason",
                 {29'd0, issue_block_reason}, 32'h1);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1; slot1_uses_rs2 = 1'b1;
        slot1_rs1 = 5'd12; slot1_rs2 = 5'd13;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b0; s8_result_wait = 1'b0; s8_rd = 5'd12; s8_result = 32'h8888_0012;
        s9_valid = 1'b1; s9_wb_en = 1'b1; s9_is_load = 1'b0; s9_rd = 5'd13; s9_result = 32'h9999_0013;
        #1;
        `check("SB slot1 forwarding stays ready", slot1_rs1_ready && slot1_rs2_ready && slot1_ready);
        `check("SB slot0 stays independent while slot1 forwards", issue_ready && !rs1_wait_raw && !rs2_wait_raw);
        `check32("SB slot1 rs1 select s8", {30'd0, slot1_rs1_fwd_sel}, {30'd0, FWD_S8});
        `check32("SB slot1 rs2 select s9", {30'd0, slot1_rs2_fwd_sel}, {30'd0, FWD_S9});
        `check32("SB slot1 rs1 forwards from s8", slot1_rs1_val_live, 32'h8888_0012);
        `check32("SB slot1 rs2 forwards from s9", slot1_rs2_val_live, 32'h9999_0013);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd14;
        s6_valid = 1'b1; s6_wb_en = 1'b1; s6_rd = 5'd14;
        #1;
        `check("SB slot1 s6 producer causes raw wait", slot1_rs1_wait_raw && !slot1_load_use_hazard_raw);
        `check("SB slot1 s6 producer clears only slot1 ready", issue_ready && !slot1_rs1_ready && slot1_rs2_ready && !slot1_ready);
        `check32("SB slot1 s6 block reason is rs1 wait", {29'd0, slot1_block_reason}, 32'h1);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs2 = 5'd15;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b1; s8_result_wait = 1'b1; s8_rd = 5'd15;
        #1;
        `check("SB slot1 s8 load raises load-use hazard", slot1_rs2_wait_raw && slot1_load_use_hazard_raw);
        `check("SB slot1 s8 load blocks rs2 only", slot1_rs1_ready && !slot1_rs2_ready && !slot1_ready);
        `check32("SB slot1 s8 load block reason", {29'd0, slot1_block_reason}, 32'h6);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd15;
        s8_valid = 1'b1; s8_wb_en = 1'b1; s8_is_load = 1'b0; s8_result_wait = 1'b1; s8_rd = 5'd15;
        #1;
        `check("SB slot1 s8 result_wait non-load blocks raw only",
               slot1_rs1_wait_raw && !slot1_load_use_hazard_raw);
        `check32("SB slot1 s8 result_wait non-load reason excludes load-use",
                 {29'd0, slot1_block_reason}, 32'h1);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd16;
        s10_valid = 1'b1; s10_wb_en = 1'b1; s10_load_wait = 1'b1; s10_rd = 5'd16;
        #1;
        `check("SB slot1 s10 pending load waits without load-use flag", slot1_rs1_wait_raw && !slot1_load_use_hazard_raw);
        `check32("SB slot1 s10 pending load block reason", {29'd0, slot1_block_reason}, 32'h1);
        `check32("SB slot1 s10 pending load select s10", {30'd0, slot1_rs1_fwd_sel}, {30'd0, FWD_S10});

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd17;
        s10_valid = 1'b1; s10_wb_en = 1'b1; s10_load_wait = 1'b0; s10_rd = 5'd17; s10_result = 32'haaaa_0017;
        #1;
        `check("SB slot1 s10 ready writeback forwards without wait", !slot1_rs1_wait_raw && slot1_ready);
        `check32("SB slot1 ready writeback select s10", {30'd0, slot1_rs1_fwd_sel}, {30'd0, FWD_S10});
        `check32("SB slot1 rs1 forwards from s10", slot1_rs1_val_live, 32'haaaa_0017);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs2 = 5'd22;
        s10_valid = 1'b1;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b1;
        s10_slot1_rd = 5'd22;
        s10_slot1_result = 32'h2222_dead;
        #1;
        `check("SB current slot1 waits for pending S10 lane1 load",
               slot1_rs2_wait_raw && !slot1_load_use_hazard_raw && !slot1_ready);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs2 = 5'd22;
        s10_valid = 1'b1;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0;
        s10_slot1_rd = 5'd22;
        s10_slot1_result = 32'h2222_beef;
        #1;
        `check("SB current slot1 forwards ready S10 lane1 load",
               slot1_ready && !slot1_rs2_wait_raw);
        `check32("SB current slot1 ready lane1 load selects S10",
                 {30'd0, slot1_rs2_fwd_sel}, {30'd0, FWD_S10});
        `check32("SB current slot1 ready lane1 load data forwards",
                 slot1_rs2_val_live, 32'h2222_beef);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd29;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_load_wait = 1'b0;
        s10_rd = 5'd29;
        s10_result = 32'h2929_0000;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b0;
        s10_slot1_rd = 5'd29;
        s10_slot1_result = 32'h2929_1111;
        #1;
        `check("SB current slot1 reads younger S10 lane1 when both lanes write same rd",
               slot1_ready && !slot1_rs1_wait_raw);
        `check32("SB current slot1 same-stage S10 lane1 overrides lane0",
                 slot1_rs1_val_live, 32'h2929_1111);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs2 = 5'd30;
        s10_valid = 1'b1;
        s10_wb_en = 1'b1;
        s10_load_wait = 1'b0;
        s10_rd = 5'd30;
        s10_result = 32'h3030_0000;
        s10_slot1_issue_valid = 1'b1;
        s10_slot1_wb_en = 1'b1;
        s10_slot1_load_wait = 1'b1;
        s10_slot1_rd = 5'd30;
        s10_slot1_result = 32'h3030_dead;
        #1;
        `check("SB pending younger S10 lane1 blocks current slot1 same-rd bypass",
               slot1_rs2_wait_raw && !slot1_load_use_hazard_raw && !slot1_ready);
        `check32("SB pending younger S10 lane1 raises slot1 rs2 reason",
                 {29'd0, slot1_block_reason}, 32'h2);

        clear_inputs();
        uses_rs2 = 1'b1;
        rs2 = 5'd18;
        rf_rdata2 = 32'hbad0_bad0;
        s8_valid = 1'b1;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_rd = 5'd18;
        s8_slot1_result = 32'h1818_0001;
        #1;
        `check("SB slot0 forwards ready S8 lane1 producer", issue_ready && !rs2_wait_raw);
        `check32("SB slot0 rs2 selects S8 for lane1 producer", {30'd0, rs2_fwd_sel}, {30'd0, FWD_S8});
        `check32("SB slot0 rs2 forwards S8 lane1 data", rs2_val_live, 32'h1818_0001);

        clear_inputs();
        uses_rs2 = 1'b1;
        rs2 = 5'd18;
        rf_rdata2 = 32'hbad0_bad0;
        s8_valid = 1'b1;
        s8_result_wait = 1'b1;
        s8_slot1_result_wait = 1'b0;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_issue_class = 4'b1000;
        s8_slot1_rd = 5'd18;
        s8_slot1_result = 32'h1818_0002;
        #1;
        `check("SB slot0 still forwards S8 lane1 when lane0 waits",
               issue_ready && !rs2_wait_raw && !load_use_hazard_raw);
        `check32("SB slot0 selects S8 lane1 despite lane0 wait",
                 {30'd0, rs2_fwd_sel}, {30'd0, FWD_S8});
        `check32("SB slot0 gets S8 lane1 data despite lane0 wait",
                 rs2_val_live, 32'h1818_0002);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd23;
        s8_valid = 1'b1;
        s8_wb_en = 1'b1;
        s8_is_load = 1'b0;
        s8_result_wait = 1'b0;
        s8_rd = 5'd23;
        s8_result = 32'h2323_0000;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_is_load = 1'b0;
        s8_slot1_rd = 5'd23;
        s8_slot1_result = 32'h2323_1111;
        #1;
        `check("SB slot0 reads younger S8 lane1 when both lanes write same rd",
               issue_ready && !rs1_wait_raw);
        `check32("SB same-stage S8 lane1 overrides lane0",
                 rs1_val_live, 32'h2323_1111);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd24;
        s8_valid = 1'b1;
        s8_wb_en = 1'b1;
        s8_is_load = 1'b0;
        s8_result_wait = 1'b0;
        s8_rd = 5'd24;
        s8_result = 32'h2424_0000;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_is_load = 1'b1;
        s8_slot1_issue_class = 4'b0100;
        s8_slot1_rd = 5'd24;
        s8_slot1_result = 32'h2424_dead;
        #1;
        `check("SB pending younger S8 lane1 blocks older lane0 same-rd bypass",
               rs1_wait_raw && load_use_hazard_raw && !issue_ready);
        `check32("SB pending younger S8 lane1 raises rs1/load-use reason",
                 {29'd0, issue_block_reason}, 32'h5);

        s8_slot1_issue_class = 4'b1000;
        #1;
        `check("SB lane1 load payload without load class forwards normally",
               issue_ready && !rs1_wait_raw && !load_use_hazard_raw);
        `check32("SB lane1 load payload without load class data forwards",
                 rs1_val_live, 32'h2424_dead);

        clear_inputs();
        uses_rs2 = 1'b1;
        rs2 = 5'd31;
        s9_valid = 1'b1;
        s9_wb_en = 1'b1;
        s9_is_load = 1'b0;
        s9_rd = 5'd31;
        s9_result = 32'h3131_0000;
        s9_slot1_issue_valid = 1'b1;
        s9_slot1_wb_en = 1'b1;
        s9_slot1_is_load = 1'b0;
        s9_slot1_rd = 5'd31;
        s9_slot1_result = 32'h3131_1111;
        #1;
        `check("SB slot0 reads younger S9 lane1 when both lanes write same rd",
               issue_ready && !rs2_wait_raw);
        `check32("SB slot0 same-stage S9 lane1 overrides lane0",
                 rs2_val_live, 32'h3131_1111);

        clear_inputs();
        uses_rs2 = 1'b1;
        rs2 = 5'd5;
        s9_valid = 1'b1;
        s9_wb_en = 1'b1;
        s9_is_load = 1'b0;
        s9_rd = 5'd5;
        s9_result = 32'h0505_0000;
        s9_slot1_issue_valid = 1'b1;
        s9_slot1_wb_en = 1'b1;
        s9_slot1_is_load = 1'b1;
        s9_slot1_issue_class = 4'b0100;
        s9_slot1_rd = 5'd5;
        s9_slot1_result = 32'h0505_dead;
        #1;
        `check("SB pending younger S9 lane1 blocks older lane0 same-rd bypass",
               rs2_wait_raw && load_use_hazard_raw && !issue_ready);
        `check32("SB pending younger S9 lane1 raises rs2/load-use reason",
                 {29'd0, issue_block_reason}, 32'h6);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd19;
        s6_valid = 1'b1;
        s6_slot1_issue_valid = 1'b1;
        s6_slot1_wb_en = 1'b1;
        s6_slot1_rd = 5'd19;
        #1;
        `check("SB slot0 waits for too-young S6 lane1 producer", rs1_wait_raw && !issue_ready);
        `check32("SB slot0 S6 lane1 block reason", {29'd0, issue_block_reason}, 32'h1);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd20;
        slot1_rf_rdata1 = 32'hbad1_bad1;
        s9_valid = 1'b1;
        s9_slot1_issue_valid = 1'b1;
        s9_slot1_wb_en = 1'b1;
        s9_slot1_rd = 5'd20;
        s9_slot1_result = 32'h2020_0001;
        #1;
        `check("SB current slot1 forwards older S9 lane1 producer", slot1_ready && !slot1_rs1_wait_raw);
        `check32("SB slot1 rs1 selects S9 for lane1 producer", {30'd0, slot1_rs1_fwd_sel}, {30'd0, FWD_S9});
        `check32("SB slot1 rs1 forwards S9 lane1 data", slot1_rs1_val_live, 32'h2020_0001);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd6;
        s8_valid = 1'b1;
        s8_wb_en = 1'b1;
        s8_is_load = 1'b0;
        s8_result_wait = 1'b0;
        s8_rd = 5'd6;
        s8_result = 32'h0606_0000;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_is_load = 1'b0;
        s8_slot1_rd = 5'd6;
        s8_slot1_result = 32'h0606_1111;
        #1;
        `check("SB current slot1 reads younger S8 lane1 on same-rd pair",
               slot1_ready && !slot1_rs1_wait_raw);
        `check32("SB current slot1 same-stage S8 lane1 overrides lane0",
                 slot1_rs1_val_live, 32'h0606_1111);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd7;
        s8_valid = 1'b1;
        s8_wb_en = 1'b1;
        s8_is_load = 1'b0;
        s8_result_wait = 1'b0;
        s8_rd = 5'd7;
        s8_result = 32'h0707_0000;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_is_load = 1'b1;
        s8_slot1_issue_class = 4'b0100;
        s8_slot1_rd = 5'd7;
        s8_slot1_result = 32'h0707_dead;
        #1;
        `check("SB pending younger S8 lane1 blocks current slot1 same-rd bypass",
               slot1_rs1_wait_raw && slot1_load_use_hazard_raw && !slot1_ready);
        `check32("SB pending younger S8 lane1 raises slot1 rs1/load-use reason",
                 {29'd0, slot1_block_reason}, 32'h5);

        s8_slot1_issue_class = 4'b1000;
        #1;
        `check("SB current slot1 load payload without load class forwards normally",
               slot1_ready && !slot1_rs1_wait_raw && !slot1_load_use_hazard_raw);
        `check32("SB current slot1 load payload without load class data forwards",
                 slot1_rs1_val_live, 32'h0707_dead);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd7;
        s8_valid = 1'b1;
        s8_result_wait = 1'b1;
        s8_slot1_result_wait = 1'b0;
        s8_slot1_issue_valid = 1'b1;
        s8_slot1_wb_en = 1'b1;
        s8_slot1_issue_class = 4'b1000;
        s8_slot1_rd = 5'd7;
        s8_slot1_result = 32'h0707_babe;
        #1;
        `check("SB current slot1 still forwards S8 lane1 when lane0 waits",
               slot1_ready && !slot1_rs1_wait_raw && !slot1_load_use_hazard_raw);
        `check32("SB current slot1 gets S8 lane1 data despite lane0 wait",
                 slot1_rs1_val_live, 32'h0707_babe);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd25;
        s9_valid = 1'b1;
        s9_wb_en = 1'b1;
        s9_is_load = 1'b0;
        s9_rd = 5'd25;
        s9_result = 32'h2525_0000;
        s9_slot1_issue_valid = 1'b1;
        s9_slot1_wb_en = 1'b1;
        s9_slot1_is_load = 1'b0;
        s9_slot1_rd = 5'd25;
        s9_slot1_result = 32'h2525_1111;
        #1;
        `check("SB current slot1 reads younger S9 lane1 on same-rd pair",
               slot1_ready && !slot1_rs1_wait_raw);
        `check32("SB current slot1 same-stage S9 lane1 overrides lane0",
                 slot1_rs1_val_live, 32'h2525_1111);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs2 = 5'd26;
        s9_valid = 1'b1;
        s9_wb_en = 1'b1;
        s9_is_load = 1'b0;
        s9_rd = 5'd26;
        s9_result = 32'h2626_0000;
        s9_slot1_issue_valid = 1'b1;
        s9_slot1_wb_en = 1'b1;
        s9_slot1_is_load = 1'b1;
        s9_slot1_issue_class = 4'b0100;
        s9_slot1_rd = 5'd26;
        s9_slot1_result = 32'h2626_dead;
        #1;
        `check("SB pending younger S9 lane1 blocks current slot1 same-rd bypass",
               slot1_rs2_wait_raw && slot1_load_use_hazard_raw && !slot1_ready);
        `check32("SB pending younger S9 lane1 raises rs2/load-use reason",
                 {29'd0, slot1_block_reason}, 32'h6);

        clear_inputs();
        uses_rs1 = 1'b1;
        rs1 = 5'd0;
        rf_rdata1 = 32'hdead_beef;
        #1;
        `check("SB slot0 x0 source never depends on RF echo", issue_ready && !rs1_wait_raw);
        `check32("SB slot0 x0 source forced to zero", rs1_val_live, 32'h0000_0000);

        clear_inputs();
        slot1_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd0;
        slot1_rf_rdata1 = 32'hcafe_babe;
        #1;
        `check("SB slot1 x0 source never depends on RF echo", slot1_ready && !slot1_rs1_wait_raw);
        `check32("SB slot1 x0 source forced to zero", slot1_rs1_val_live, 32'h0000_0000);

        finish_tb();
    end
endmodule
