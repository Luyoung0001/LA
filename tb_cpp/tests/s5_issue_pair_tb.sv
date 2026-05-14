`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s5_issue_pair_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    function automatic [31:0] la_i12(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_i12 = {6'h00, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_alu_3r(input [1:0] op21_20, input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_alu_3r = {6'h00, 4'h0, op21_20, op19_15, rk, rj, rd};
    endfunction

    function automatic [31:0] la_shift_imm(input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] imm);
        la_shift_imm = {6'h00, 4'h1, 2'h0, op19_15, imm, rj, rd};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_branch(input [5:0] op31_26, input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_branch = {op31_26, imm, rj, rd};
    endfunction

    function automatic [31:0] la_jirl(input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_jirl = {6'h13, imm, rj, rd};
    endfunction

    function automatic [31:0] la_lu12i(input [4:0] rd, input [19:0] imm);
        la_lu12i = {6'h05, 1'b0, imm, rd};
    endfunction

    function automatic [31:0] la_pcaddu12i(input [4:0] rd, input [19:0] imm);
        la_pcaddu12i = {6'h07, 1'b0, imm, rd};
    endfunction

    logic       slot0_valid;
    logic       slot0_single_issue;
    logic       slot0_load;
    logic       slot0_store;
    logic       slot0_atomic;
    logic       slot0_ctrl_flow;
    logic       slot0_pairable_compute;
    logic       slot0_wb_en;
    logic [4:0] slot0_rd;
    logic       slot1_valid;
    logic [6:0] slot1_opcode;
    logic [2:0] slot1_funct3;
    logic [6:0] slot1_funct7;
    logic [4:0] slot1_op_19_15;
    logic [4:0] slot1_rs1;
    logic [4:0] slot1_rs2;
    logic [4:0] slot1_rd;
    logic       slot1_branch;
    logic       slot1_jal;
    logic       slot1_jalr;
    logic       slot1_load;
    logic       slot1_store;
    logic       slot1_lui;
    logic       slot1_auipc;
    logic       slot1_unknown;
    logic       slot1_simple_alu;
    logic       slot1_compute;
    logic       slot1_ctrl_pair;
    logic       slot1_ctrl_dep_bypass;
    logic       slot1_uses_rs1;
    logic       slot1_uses_rs2;
    logic       slot1_wb_en;
    logic [1:0] slot1_src_a_sel;
    logic [1:0] slot1_src_b_sel;
    logic [3:0] slot1_alu_op;
    logic       slot1_load_pair_candidate;
    logic       slot1_load_pair_safe;
    logic       slot1_store_pair_candidate;
    logic       slot1_store_pair_safe;
    logic       slot1_pair_compute;
    logic       slot1_pair_load;
    logic       slot1_pair_store;
    logic       slot1_pair_ctrl;
    logic       pair_legal;
    logic [4:0] pair_block_reason;

    s5_slot1_lane_class u_lane_class (
        .slot1_valid_i(slot1_valid),
        .slot1_enable_alu_i(1'b1),
        .slot1_enable_branch_i(1'b1),
        .slot1_enable_mul_i(1'b1),
        .slot1_enable_load_i(1'b1),
        .slot1_enable_store_i(1'b1),
        .slot1_opcode_i(slot1_opcode),
        .slot1_funct3_i(slot1_funct3),
        .slot1_funct7_i(slot1_funct7),
        .slot1_op_19_15_i(slot1_op_19_15),
        .slot1_branch_i(slot1_branch),
        .slot1_jal_i(slot1_jal),
        .slot1_jalr_i(slot1_jalr),
        .slot1_load_i(slot1_load),
        .slot1_store_i(slot1_store),
        .slot1_lui_i(slot1_lui),
        .slot1_auipc_i(slot1_auipc),
        .slot1_unknown_i(slot1_unknown),
        .slot1_simple_alu_o(slot1_simple_alu),
        .slot1_compute_o(slot1_compute),
        .slot1_ctrl_pair_o(slot1_ctrl_pair),
        .slot1_ctrl_dep_bypass_o(slot1_ctrl_dep_bypass),
        .slot1_load_pair_candidate_o(slot1_load_pair_candidate),
        .slot1_store_pair_candidate_o(slot1_store_pair_candidate),
        .slot1_uses_rs1_o(slot1_uses_rs1),
        .slot1_uses_rs2_o(slot1_uses_rs2),
        .slot1_wb_en_o(slot1_wb_en),
        .slot1_src_a_sel_o(slot1_src_a_sel),
        .slot1_src_b_sel_o(slot1_src_b_sel),
        .slot1_alu_op_o(slot1_alu_op)
    );

    s5_issue_pair u_dut (
        .slot0_valid_i(slot0_valid),
        .slot0_single_issue_i(slot0_single_issue),
        .slot0_load_i(slot0_load),
        .slot0_store_i(slot0_store),
        .slot0_atomic_i(slot0_atomic),
        .slot0_ctrl_flow_i(slot0_ctrl_flow),
        .slot0_pairable_compute_i(slot0_pairable_compute),
        .slot0_wb_en_i(slot0_wb_en),
        .slot0_rd_i(slot0_rd),
        .slot1_valid_i(slot1_valid),
        .slot1_rs1_i(slot1_rs1),
        .slot1_rs2_i(slot1_rs2),
        .slot1_rd_i(slot1_rd),
        .slot1_compute_i(slot1_compute),
        .slot1_ctrl_pair_i(slot1_ctrl_pair),
        .slot1_ctrl_dep_bypass_i(slot1_ctrl_dep_bypass),
        .slot1_load_pair_candidate_i(slot1_load_pair_candidate),
        .slot1_store_pair_candidate_i(slot1_store_pair_candidate),
        .slot1_uses_rs1_i(slot1_uses_rs1),
        .slot1_uses_rs2_i(slot1_uses_rs2),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_load_pair_safe_o(slot1_load_pair_safe),
        .slot1_store_pair_safe_o(slot1_store_pair_safe),
        .slot1_pair_compute_o(slot1_pair_compute),
        .slot1_pair_load_o(slot1_pair_load),
        .slot1_pair_store_o(slot1_pair_store),
        .slot1_pair_ctrl_o(slot1_pair_ctrl),
        .pair_legal_o(pair_legal),
        .pair_block_reason_o(pair_block_reason)
    );

    task automatic check_pair_class(
        input string name,
        input        exp_compute,
        input        exp_load,
        input        exp_store,
        input        exp_ctrl
    );
        begin
            `check32(name,
                     {28'd0, slot1_pair_compute, slot1_pair_load,
                      slot1_pair_store, slot1_pair_ctrl},
                     {28'd0, exp_compute, exp_load, exp_store, exp_ctrl});
        end
    endtask

    task automatic clear_slot0;
        begin
            slot0_valid = 1'b1;
            slot0_single_issue = 1'b0;
            slot0_load = 1'b0;
            slot0_store = 1'b0;
            slot0_atomic = 1'b0;
            slot0_ctrl_flow = 1'b0;
            slot0_pairable_compute = 1'b1;
            slot0_wb_en = 1'b1;
            slot0_rd = 5'd8;
        end
    endtask

    task automatic clear_slot1;
        begin
            slot1_valid = 1'b0;
            slot1_opcode = 7'd0;
            slot1_funct3 = 3'd0;
            slot1_funct7 = 7'd0;
            slot1_op_19_15 = 5'd0;
            slot1_rs1 = 5'd0;
            slot1_rs2 = 5'd0;
            slot1_rd = 5'd0;
            slot1_branch = 1'b0;
            slot1_jal = 1'b0;
            slot1_jalr = 1'b0;
            slot1_load = 1'b0;
            slot1_store = 1'b0;
            slot1_lui = 1'b0;
            slot1_auipc = 1'b0;
            slot1_unknown = 1'b0;
        end
    endtask

    task automatic drive_slot1(
        input [31:0] inst,
        input        valid,
        input        is_branch,
        input        is_jal,
        input        is_jalr,
        input        is_load,
        input        is_store,
        input        is_lui_flag,
        input        is_auipc_flag,
        input        is_unknown
    );
        begin
            slot1_valid = valid;
            slot1_opcode = {1'b0, inst[31:26]};
            slot1_funct3 = {1'b0, inst[21:20]};
            slot1_funct7 = {3'b0, inst[25:22]};
            slot1_op_19_15 = inst[19:15];
            slot1_rs1 = inst[9:5];
            slot1_rd = inst[4:0];
            slot1_branch = is_branch;
            slot1_jal = is_jal;
            slot1_jalr = is_jalr;
            slot1_load = is_load;
            slot1_store = is_store;
            slot1_lui = is_lui_flag;
            slot1_auipc = is_auipc_flag;
            slot1_unknown = is_unknown;
            if (is_branch || is_store)
                slot1_rs2 = inst[4:0];
            else
                slot1_rs2 = inst[14:10];
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_slot0();
        clear_slot1();
        #1;
        `check("PAIR no slot1 means pair disabled", !pair_legal);
        `check32("PAIR invalid slot1 reason", {27'd0, pair_block_reason}, 32'h1);
        `check32("PAIR invalid clears slot1 src A", {30'd0, slot1_src_a_sel}, 32'd0);
        `check32("PAIR invalid clears slot1 src B", {30'd0, slot1_src_b_sel}, 32'd0);
        `check32("PAIR invalid clears slot1 ALU op", {28'd0, slot1_alu_op}, 32'd0);
        `check("PAIR invalid clears slot1 load candidate", !slot1_load_pair_candidate);
        `check("PAIR invalid clears slot1 load safe marker", !slot1_load_pair_safe);
        `check("PAIR invalid clears slot1 store candidate", !slot1_store_pair_candidate);
        `check("PAIR invalid clears slot1 store safe marker", !slot1_store_pair_safe);
        check_pair_class("PAIR invalid clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);

        clear_slot0();
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR addi qualifies as simple ALU", slot1_simple_alu && slot1_uses_rs1 && !slot1_uses_rs2 && slot1_wb_en);
        `check("PAIR addi is not slot1 load candidate", !slot1_load_pair_candidate);
        `check("PAIR addi is not slot1 load safe marker", !slot1_load_pair_safe);
        `check("PAIR addi is not slot1 store candidate", !slot1_store_pair_candidate);
        `check("PAIR addi is not slot1 store safe marker", !slot1_store_pair_safe);
        `check32("PAIR addi payload src A rs1", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_RS1});
        `check32("PAIR addi payload src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("PAIR addi payload ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});
        `check("PAIR independent addi pair is legal", pair_legal);
        check_pair_class("PAIR independent addi selects compute pair class", 1'b1, 1'b0, 1'b0, 1'b0);
        `check32("PAIR legal pair has no block bits", {27'd0, pair_block_reason}, 32'd0);

        clear_slot0();
        drive_slot1(la_alu_3r(2'h1, 5'h00, 5'd10, 5'd4, 5'd5), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR add.w uses both sources", slot1_simple_alu && slot1_uses_rs1 && slot1_uses_rs2);
        `check32("PAIR add.w payload src A rs1", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_RS1});
        `check32("PAIR add.w payload src B rs2", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_RS2});
        `check32("PAIR add.w payload ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});
        `check("PAIR simple 3R ALU is legal when independent", pair_legal);
        check_pair_class("PAIR simple 3R ALU selects compute pair class", 1'b1, 1'b0, 1'b0, 1'b0);

        clear_slot0();
        slot0_rd = 5'd4;
        drive_slot1(la_i12(4'ha, 5'd10, 5'd4, 12'h001), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 compute result blocks same-cycle slot1 addi RAW", !pair_legal);
        check_pair_class("PAIR blocked addi RAW clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR addi RAW reason bit", {27'd0, pair_block_reason}, 32'h8);

        clear_slot0();
        slot0_rd = 5'd5;
        drive_slot1(la_alu_3r(2'h1, 5'h0a, 5'd11, 5'd3, 5'd5), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 compute result blocks same-cycle slot1 rs2 RAW", !pair_legal);
        check_pair_class("PAIR blocked rs2 RAW clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR rs2 RAW reason bit", {27'd0, pair_block_reason}, 32'h8);

        clear_slot0();
        slot0_rd = 5'd9;
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR WAW blocks same-cycle dual issue", !pair_legal);
        check_pair_class("PAIR WAW clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR WAW reason bit", {27'd0, pair_block_reason}, 32'h10);

        clear_slot0();
        slot0_single_issue = 1'b1;
        drive_slot1(la_shift_imm(5'h09, 5'd9, 5'd2, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR single-issue slot0 blocks otherwise legal slot1", !pair_legal);
        check_pair_class("PAIR blocked single-issue slot0 clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR slot0 single-issue reason bit", {27'd0, pair_block_reason}, 32'h4);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_store = 1'b1;
        slot0_wb_en = 1'b0;
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 store can pair with independent slot1 ALU", pair_legal && slot1_simple_alu);
        `check32("PAIR slot0 store plus slot1 ALU has no block bits", {27'd0, pair_block_reason}, 32'd0);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_store = 1'b1;
        slot0_atomic = 1'b1;
        slot0_wb_en = 1'b1;
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR atomic slot0 store keeps slot1 single-issued", !pair_legal);
        `check32("PAIR atomic slot0 store reason bit", {27'd0, pair_block_reason}, 32'h4);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_store = 1'b1;
        slot0_wb_en = 1'b0;
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 store still blocks slot1 control-flow", !pair_legal);
        `check32("PAIR slot0 store control-flow reason bit", {27'd0, pair_block_reason}, 32'h4);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_load = 1'b1;
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd8;
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 load can pair with independent slot1 ALU", pair_legal && slot1_simple_alu);
        `check32("PAIR slot0 load plus independent slot1 ALU has no block bits", {27'd0, pair_block_reason}, 32'd0);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_load = 1'b1;
        slot0_atomic = 1'b1;
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd8;
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR atomic slot0 load keeps slot1 single-issued", !pair_legal);
        `check32("PAIR atomic slot0 load reason bit", {27'd0, pair_block_reason}, 32'h4);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_load = 1'b1;
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd2;
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 load still blocks slot1 RAW consumer", !pair_legal);
        check_pair_class("PAIR blocked slot0 load RAW clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR slot0 load RAW reason bit", {27'd0, pair_block_reason}, 32'h8);

        clear_slot0();
        slot0_single_issue = 1'b1;
        slot0_load = 1'b1;
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd8;
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 load still blocks slot1 control-flow", !pair_legal);
        `check32("PAIR slot0 load control-flow reason bit", {27'd0, pair_block_reason}, 32'h4);

        clear_slot0();
        drive_slot1(la_mem(4'h4, 5'd10, 5'd9, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR safe ordinary slot1 store is pair legal", !slot1_simple_alu && pair_legal);
        `check("PAIR ordinary slot1 store is marked as future store-pair candidate",
               slot1_store_pair_candidate);
        `check("PAIR ordinary slot1 store is safe behind non-control slot0",
               slot1_store_pair_safe);
        check_pair_class("PAIR safe ordinary slot1 store selects store pair class", 1'b0, 1'b0, 1'b1, 1'b0);
        `check("PAIR slot1 store prepare tracks address and data sources",
               slot1_uses_rs1 && slot1_uses_rs2 && !slot1_wb_en);
        `check32("PAIR slot1 store prepare src A rs1", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_RS1});
        `check32("PAIR slot1 store prepare src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("PAIR slot1 store prepare ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});
        `check32("PAIR safe slot1 store has no block bits", {27'd0, pair_block_reason}, 32'd0);

        clear_slot0();
        slot0_pairable_compute = 1'b0;
        drive_slot1(la_mem(4'h6, 5'd10, 5'd9, 12'h004),
                    1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1,
                    1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 store requires explicit slot0 pairable-compute anchor",
               slot1_store_pair_candidate && !slot1_store_pair_safe && !pair_legal);
        check_pair_class("PAIR non-pairable slot0 blocks slot1 store class",
                         1'b0, 1'b0, 1'b0, 1'b0);

        clear_slot0();
        drive_slot1({6'h08, 1'b0, 1'b1, 14'h004, 5'd9, 5'd10},
                    1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1,
                    1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 SC stays out of ordinary store candidate set",
               !slot1_store_pair_candidate && !slot1_store_pair_safe && !pair_legal);
        check_pair_class("PAIR rejected SC clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check("PAIR slot1 SC still exposes store source usage for future diagnostics",
               slot1_uses_rs1 && slot1_uses_rs2 && !slot1_wb_en);

        clear_slot0();
        slot0_ctrl_flow = 1'b1;
        slot0_wb_en = 1'b0;
        drive_slot1(la_mem(4'h6, 5'd10, 5'd9, 12'h004),
                    1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1,
                    1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 store candidate is unsafe behind slot0 control-flow",
               slot1_store_pair_candidate && !slot1_store_pair_safe && !pair_legal);
        check_pair_class("PAIR unsafe slot1 store clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);

        clear_slot0();
        drive_slot1(la_mem(4'h2, 5'd10, 5'd9, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR safe ordinary slot1 load is pair legal",
               !slot1_simple_alu && pair_legal);
        `check("PAIR ordinary slot1 load is marked as load-pair candidate",
               slot1_load_pair_candidate && slot1_load_pair_safe);
        check_pair_class("PAIR safe ordinary slot1 load selects load pair class", 1'b0, 1'b1, 1'b0, 1'b0);
        `check("PAIR slot1 load prepare tracks address source and writeback",
               slot1_uses_rs1 && !slot1_uses_rs2 && slot1_wb_en);
        `check32("PAIR slot1 load prepare src A rs1", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_RS1});
        `check32("PAIR slot1 load prepare src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("PAIR slot1 load prepare ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});

        clear_slot0();
        drive_slot1({6'h08, 1'b0, 1'b0, 14'h004, 5'd9, 5'd10},
                    1'b1, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0,
                    1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 LL stays out of ordinary load candidate set",
               !slot1_load_pair_candidate && !slot1_load_pair_safe && !pair_legal);
        check_pair_class("PAIR rejected LL clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check("PAIR slot1 LL still exposes load address payload for diagnostics",
               slot1_uses_rs1 && !slot1_uses_rs2 && slot1_wb_en);
        `check32("PAIR unsupported LL keeps ADD payload for address",
                 {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});
        `check32("PAIR unsupported load reason bit", {27'd0, pair_block_reason}, 32'h2);

        clear_slot0();
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 conditional branch is pair-supported but still no slot1 writeback",
               !slot1_simple_alu && slot1_uses_rs1 && slot1_uses_rs2 &&
               !slot1_wb_en && pair_legal);
        check_pair_class("PAIR conditional branch selects control pair class", 1'b0, 1'b0, 1'b0, 1'b1);
        `check32("PAIR branch supported pair has no block bits", {27'd0, pair_block_reason}, 32'd0);
        `check32("PAIR branch clears ALU src A payload", {30'd0, slot1_src_a_sel}, 32'd0);
        `check32("PAIR branch clears ALU src B payload", {30'd0, slot1_src_b_sel}, 32'd0);
        `check32("PAIR branch clears ALU op payload", {28'd0, slot1_alu_op}, 32'd0);

        clear_slot0();
        slot0_ctrl_flow = 1'b1;
        slot0_wb_en = 1'b0;
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 control-flow blocks slot1 control-flow pair",
               slot1_ctrl_pair && !pair_legal);
        check_pair_class("PAIR blocked dual-control clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR dual-control reason bit", {27'd0, pair_block_reason}, 32'h2);

        clear_slot0();
        slot0_rd = 5'd9;
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 compute result blocks same-cycle slot1 branch RAW", !pair_legal);
        check_pair_class("PAIR blocked branch RAW clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR branch RAW reason bit", {27'd0, pair_block_reason}, 32'h8);

        clear_slot0();
        drive_slot1(la_branch(6'h14, 5'd0, 5'd0, 16'h004), 1'b1, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 B is pair-supported without writeback",
               !slot1_simple_alu && !slot1_wb_en &&
               !slot1_uses_rs1 && !slot1_uses_rs2 && pair_legal);
        check_pair_class("PAIR slot1 B selects control pair class", 1'b0, 1'b0, 1'b0, 1'b1);
        `check32("PAIR slot1 B has no block bits", {27'd0, pair_block_reason}, 32'd0);

        clear_slot0();
        drive_slot1(la_branch(6'h15, 5'd0, 5'd0, 16'h004), 1'b1, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 BL is pair-supported with writeback payload",
               !slot1_simple_alu && pair_legal && slot1_wb_en &&
               !slot1_uses_rs1 && !slot1_uses_rs2);
        check_pair_class("PAIR slot1 BL selects control pair class", 1'b0, 1'b0, 1'b0, 1'b1);
        `check32("PAIR slot1 BL src A uses PC",
                 {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_PC});
        `check32("PAIR slot1 BL src B uses FOUR",
                 {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_FOUR});
        `check32("PAIR slot1 BL ALU add payload",
                 {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});

        clear_slot0();
        drive_slot1(la_jirl(5'd1, 5'd7, 16'h0008), 1'b1, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 JIRL is pair-supported with writeback payload",
               !slot1_simple_alu && pair_legal && slot1_wb_en &&
               slot1_uses_rs1 && !slot1_uses_rs2);
        check_pair_class("PAIR slot1 JIRL selects control pair class", 1'b0, 1'b0, 1'b0, 1'b1);
        `check32("PAIR slot1 JIRL src A uses PC",
                 {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_PC});
        `check32("PAIR slot1 JIRL src B uses FOUR",
                 {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_FOUR});
        `check32("PAIR slot1 JIRL ALU add payload",
                 {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});

        clear_slot0();
        drive_slot1(la_alu_3r(2'h1, 5'h18, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 mul.w is pair-supported compute",
               !slot1_simple_alu && pair_legal &&
               slot1_uses_rs1 && slot1_uses_rs2 && slot1_wb_en);
        check_pair_class("PAIR slot1 mul.w selects compute pair class", 1'b1, 1'b0, 1'b0, 1'b0);
        `check32("PAIR mul src A rs1",
                 {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_RS1});
        `check32("PAIR mul src B rs2",
                 {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_RS2});
        `check32("PAIR mul supported has no block bits", {27'd0, pair_block_reason}, 32'd0);

        clear_slot0();
        drive_slot1(la_alu_3r(2'h1, 5'h19, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 mulh.w is pair-supported compute",
               !slot1_simple_alu && pair_legal &&
               slot1_uses_rs1 && slot1_uses_rs2 && slot1_wb_en);

        clear_slot0();
        drive_slot1(la_alu_3r(2'h1, 5'h1a, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 mulh.wu is pair-supported compute",
               !slot1_simple_alu && pair_legal &&
               slot1_uses_rs1 && slot1_uses_rs2 && slot1_wb_en);

        clear_slot0();
        slot0_rd = 5'd4;
        drive_slot1(la_alu_3r(2'h1, 5'h18, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot0 compute result blocks same-cycle slot1 mul RAW", !pair_legal);
        check_pair_class("PAIR blocked mul RAW clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR mul RAW reason bit", {27'd0, pair_block_reason}, 32'h8);

        clear_slot0();
        drive_slot1(la_alu_3r(2'h2, 5'h00, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 div.w is excluded from simple ALU set", !slot1_simple_alu && !pair_legal);
        check_pair_class("PAIR rejected div.w clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);

        clear_slot0();
        drive_slot1(la_lu12i(5'd12, 20'h12345), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0);
        #1;
        `check("PAIR slot1 lu12i is treated as simple ALU", slot1_simple_alu && !slot1_uses_rs1 && !slot1_uses_rs2 && pair_legal);
        check_pair_class("PAIR slot1 lu12i selects compute pair class", 1'b1, 1'b0, 1'b0, 1'b0);
        `check32("PAIR lu12i payload src A zero", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_ZERO});
        `check32("PAIR lu12i payload src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("PAIR lu12i payload copy B", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_COPY_B});

        clear_slot0();
        drive_slot1(la_pcaddu12i(5'd12, 20'h12345), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0);
        #1;
        `check("PAIR slot1 pcaddu12i is treated as simple ALU", slot1_simple_alu && !slot1_uses_rs1 && !slot1_uses_rs2 && pair_legal);
        `check32("PAIR pcaddu12i payload src A pc", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_PC});
        `check32("PAIR pcaddu12i payload src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("PAIR pcaddu12i payload ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});

        clear_slot0();
        drive_slot1(32'hffff_ffff, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1);
        #1;
        `check("PAIR unknown slot1 is rejected", !slot1_simple_alu && !pair_legal);
        check_pair_class("PAIR unknown slot1 clears final pair class", 1'b0, 1'b0, 1'b0, 1'b0);
        `check32("PAIR unknown reason bit", {27'd0, pair_block_reason}, 32'h2);

        finish_tb();
    end
endmodule
