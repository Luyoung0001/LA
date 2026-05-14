`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s5_slot1_lane_class_tb;
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

    logic       slot1_valid;
    logic       slot1_enable_alu;
    logic       slot1_enable_branch;
    logic       slot1_enable_mul;
    logic       slot1_enable_load;
    logic       slot1_enable_store;
    logic [6:0] slot1_opcode;
    logic [2:0] slot1_funct3;
    logic [6:0] slot1_funct7;
    logic [4:0] slot1_op_19_15;
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
    logic       slot1_load_pair_candidate;
    logic       slot1_store_pair_candidate;
    logic       slot1_uses_rs1;
    logic       slot1_uses_rs2;
    logic       slot1_wb_en;
    logic [1:0] slot1_src_a_sel;
    logic [1:0] slot1_src_b_sel;
    logic [3:0] slot1_alu_op;

    s5_slot1_lane_class u_dut (
        .slot1_valid_i(slot1_valid),
        .slot1_enable_alu_i(slot1_enable_alu),
        .slot1_enable_branch_i(slot1_enable_branch),
        .slot1_enable_mul_i(slot1_enable_mul),
        .slot1_enable_load_i(slot1_enable_load),
        .slot1_enable_store_i(slot1_enable_store),
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

    task automatic clear_inputs;
        begin
            slot1_valid = 1'b0;
            slot1_enable_alu = 1'b1;
            slot1_enable_branch = 1'b1;
            slot1_enable_mul = 1'b1;
            slot1_enable_load = 1'b1;
            slot1_enable_store = 1'b1;
            slot1_opcode = 7'd0;
            slot1_funct3 = 3'd0;
            slot1_funct7 = 7'd0;
            slot1_op_19_15 = 5'd0;
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
            slot1_branch = is_branch;
            slot1_jal = is_jal;
            slot1_jalr = is_jalr;
            slot1_load = is_load;
            slot1_store = is_store;
            slot1_lui = is_lui_flag;
            slot1_auipc = is_auipc_flag;
            slot1_unknown = is_unknown;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("LANE invalid has no class", !slot1_simple_alu && !slot1_compute && !slot1_ctrl_pair);
        `check("LANE invalid has no memory candidate", !slot1_load_pair_candidate && !slot1_store_pair_candidate);
        `check("LANE invalid has no operands or writeback", !slot1_uses_rs1 && !slot1_uses_rs2 && !slot1_wb_en);
        `check32("LANE invalid clears src A", {30'd0, slot1_src_a_sel}, 32'd0);
        `check32("LANE invalid clears src B", {30'd0, slot1_src_b_sel}, 32'd0);
        `check32("LANE invalid clears ALU op", {28'd0, slot1_alu_op}, 32'd0);

        clear_inputs();
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE addi is simple compute", slot1_simple_alu && slot1_compute && !slot1_ctrl_pair);
        `check("LANE addi uses rs1 and writes rd", slot1_uses_rs1 && !slot1_uses_rs2 && slot1_wb_en);
        `check32("LANE addi src A rs1", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_RS1});
        `check32("LANE addi src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("LANE addi ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});

        clear_inputs();
        drive_slot1(la_alu_3r(2'h1, 5'h00, 5'd10, 5'd4, 5'd5), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE add.w is simple 3R compute", slot1_simple_alu && slot1_compute);
        `check("LANE add.w uses two sources", slot1_uses_rs1 && slot1_uses_rs2);
        `check32("LANE add.w src B rs2", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_RS2});

        clear_inputs();
        drive_slot1(la_alu_3r(2'h1, 5'h18, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE mul is compute but not simple ALU", !slot1_simple_alu && slot1_compute);
        `check("LANE mul uses two sources and writes rd", slot1_uses_rs1 && slot1_uses_rs2 && slot1_wb_en);
        `check32("LANE mul src B rs2", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_RS2});

        clear_inputs();
        drive_slot1(la_alu_3r(2'h2, 5'h00, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE div is not slot1 compute class", !slot1_simple_alu && !slot1_compute);

        clear_inputs();
        drive_slot1(la_mem(4'h2, 5'd10, 5'd9, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE ordinary load is candidate with address payload",
               slot1_load_pair_candidate && !slot1_store_pair_candidate && slot1_uses_rs1 && !slot1_uses_rs2 && slot1_wb_en);
        `check32("LANE load src B imm", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_IMM});

        clear_inputs();
        drive_slot1(la_mem(4'h6, 5'd10, 5'd9, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE ordinary store is candidate with address/data payload",
               !slot1_load_pair_candidate && slot1_store_pair_candidate && slot1_uses_rs1 && slot1_uses_rs2 && !slot1_wb_en);
        `check32("LANE store ALU add", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_ADD});

        clear_inputs();
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE conditional branch is control pair class",
               slot1_ctrl_pair && slot1_ctrl_dep_bypass && slot1_uses_rs1 && slot1_uses_rs2 && !slot1_wb_en);
        `check32("LANE conditional branch clears ALU payload", {28'd0, slot1_alu_op}, 32'd0);

        clear_inputs();
        drive_slot1(la_branch(6'h15, 5'd0, 5'd0, 16'h004), 1'b1, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE BL is control pair with link writeback", slot1_ctrl_pair && slot1_wb_en && !slot1_uses_rs1 && !slot1_uses_rs2);
        `check32("LANE BL src A pc", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_PC});
        `check32("LANE BL src B four", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_FOUR});

        clear_inputs();
        drive_slot1(la_jirl(5'd1, 5'd7, 16'h0008), 1'b1, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        #1;
        `check("LANE JIRL is control pair with rs1 dependency",
               slot1_ctrl_pair && slot1_ctrl_dep_bypass && slot1_wb_en && slot1_uses_rs1 && !slot1_uses_rs2);
        `check32("LANE JIRL src B four", {30'd0, slot1_src_b_sel}, {30'd0, `CPU_SRC_B_FOUR});

        clear_inputs();
        drive_slot1(la_lu12i(5'd12, 20'h12345), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0);
        #1;
        `check("LANE lu12i is simple compute without source regs", slot1_simple_alu && slot1_compute && !slot1_uses_rs1 && !slot1_uses_rs2);
        `check32("LANE lu12i src A zero", {30'd0, slot1_src_a_sel}, {30'd0, `CPU_SRC_A_ZERO});
        `check32("LANE lu12i ALU copy B", {28'd0, slot1_alu_op}, {28'd0, `CPU_ALU_COPY_B});

        clear_inputs();
        drive_slot1(32'hffff_ffff, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1);
        #1;
        `check("LANE unknown instruction has no supported class",
               !slot1_simple_alu && !slot1_compute && !slot1_ctrl_pair &&
               !slot1_load_pair_candidate && !slot1_store_pair_candidate);

        clear_inputs();
        drive_slot1(la_i12(4'ha, 5'd9, 5'd2, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        slot1_enable_alu = 1'b0;
        #1;
        `check("LANE ALU gate disables slot1 compute",
               !slot1_simple_alu && !slot1_compute && !slot1_wb_en);
        `check("LANE ALU gate preserves dependency for promotion",
               slot1_uses_rs1 && !slot1_uses_rs2);

        clear_inputs();
        drive_slot1(la_branch(6'h16, 5'd10, 5'd9, 16'h004), 1'b1, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        slot1_enable_branch = 1'b0;
        #1;
        `check("LANE branch gate disables slot1 control pair",
               !slot1_ctrl_pair && !slot1_ctrl_dep_bypass && !slot1_wb_en);
        `check("LANE branch gate preserves dependencies for promotion",
               slot1_uses_rs1 && slot1_uses_rs2);

        clear_inputs();
        drive_slot1(la_alu_3r(2'h1, 5'h18, 5'd10, 5'd3, 5'd4), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        slot1_enable_mul = 1'b0;
        #1;
        `check("LANE mul gate disables slot1 mul compute",
               !slot1_simple_alu && !slot1_compute && !slot1_wb_en);
        `check("LANE mul gate preserves dependencies for promotion",
               slot1_uses_rs1 && slot1_uses_rs2);

        clear_inputs();
        drive_slot1(la_mem(4'h2, 5'd10, 5'd9, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        slot1_enable_load = 1'b0;
        #1;
        `check("LANE load gate disables slot1 load candidate",
               !slot1_load_pair_candidate && !slot1_wb_en);
        `check("LANE load gate preserves dependency for promotion",
               slot1_uses_rs1 && !slot1_uses_rs2);

        clear_inputs();
        drive_slot1(la_mem(4'h6, 5'd10, 5'd9, 12'h004), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0);
        slot1_enable_store = 1'b0;
        #1;
        `check("LANE store gate disables slot1 store candidate",
               !slot1_store_pair_candidate);
        `check("LANE store gate preserves dependencies for promotion",
               slot1_uses_rs1 && slot1_uses_rs2);

        finish_tb();
    end
endmodule
