`timescale 1ns / 1ps

module s8_slot1_pipe_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        capture;
    logic [31:0] slot1_pc;
    logic [31:0] instr1;
    logic        slot1_valid;
    logic [6:0]  slot1_opcode;
    logic [2:0]  slot1_funct3;
    logic [6:0]  slot1_funct7;
    logic [4:0]  slot1_op_19_15;
    logic [4:0]  slot1_rs1;
    logic [4:0]  slot1_rs2;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_imm;
    logic        slot1_is_branch;
    logic        slot1_is_jal;
    logic        slot1_is_jalr;
    logic        slot1_is_load;
    logic        slot1_is_store;
    logic        slot1_is_lui;
    logic        slot1_is_auipc;
    logic        slot1_unknown_inst;
    logic        slot1_wb_en;
    logic        slot1_uses_rs1;
    logic        slot1_uses_rs2;
    logic [1:0]  slot1_src_a_sel;
    logic [1:0]  slot1_src_b_sel;
    logic [3:0]  slot1_alu_op;
    logic [31:0] slot1_rs1_val;
    logic [31:0] slot1_rs2_val;
    logic [31:0] slot1_op_a;
    logic [31:0] slot1_op_b;
    logic        slot1_op_a_late_s10;
    logic        slot1_op_b_late_s10;
    logic        slot1_rs1_late_s10;
    logic        slot1_rs2_late_s10;
    logic [4:0]  slot1_late_s10_rd;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;

    logic [31:0] slot1_pc_o;
    logic [31:0] instr1_o;
    logic        slot1_valid_o;
    logic [6:0]  slot1_opcode_o;
    logic [2:0]  slot1_funct3_o;
    logic [6:0]  slot1_funct7_o;
    logic [4:0]  slot1_op_19_15_o;
    logic [4:0]  slot1_rs1_o;
    logic [4:0]  slot1_rs2_o;
    logic [4:0]  slot1_rd_o;
    logic [31:0] slot1_imm_o;
    logic        slot1_is_branch_o;
    logic        slot1_is_jal_o;
    logic        slot1_is_jalr_o;
    logic        slot1_is_load_o;
    logic        slot1_is_store_o;
    logic        slot1_is_lui_o;
    logic        slot1_is_auipc_o;
    logic        slot1_unknown_inst_o;
    logic        slot1_wb_en_o;
    logic        slot1_uses_rs1_o;
    logic        slot1_uses_rs2_o;
    logic [1:0]  slot1_src_a_sel_o;
    logic [1:0]  slot1_src_b_sel_o;
    logic [3:0]  slot1_alu_op_o;
    logic [31:0] slot1_rs1_val_o;
    logic [31:0] slot1_rs2_val_o;
    logic [31:0] slot1_op_a_o;
    logic [31:0] slot1_op_b_o;
    logic        slot1_op_a_late_s10_o;
    logic        slot1_op_b_late_s10_o;
    logic        slot1_rs1_late_s10_o;
    logic        slot1_rs2_late_s10_o;
    logic [4:0]  slot1_late_s10_rd_o;
    logic        slot1_issue_valid_o;
    logic [3:0]  slot1_issue_class_o;

    s8_slot1_pipe_regs u_dut (
        .clk(clk),
        .capture_i(capture),
        .slot1_pc_i(slot1_pc),
        .instr1_i(instr1),
        .slot1_valid_i(slot1_valid),
        .slot1_opcode_i(slot1_opcode),
        .slot1_funct3_i(slot1_funct3),
        .slot1_funct7_i(slot1_funct7),
        .slot1_op_19_15_i(slot1_op_19_15),
        .slot1_rs1_i(slot1_rs1),
        .slot1_rs2_i(slot1_rs2),
        .slot1_rd_i(slot1_rd),
        .slot1_imm_i(slot1_imm),
        .slot1_is_branch_i(slot1_is_branch),
        .slot1_is_jal_i(slot1_is_jal),
        .slot1_is_jalr_i(slot1_is_jalr),
        .slot1_is_load_i(slot1_is_load),
        .slot1_is_store_i(slot1_is_store),
        .slot1_is_lui_i(slot1_is_lui),
        .slot1_is_auipc_i(slot1_is_auipc),
        .slot1_unknown_inst_i(slot1_unknown_inst),
        .slot1_wb_en_i(slot1_wb_en),
        .slot1_uses_rs1_i(slot1_uses_rs1),
        .slot1_uses_rs2_i(slot1_uses_rs2),
        .slot1_src_a_sel_i(slot1_src_a_sel),
        .slot1_src_b_sel_i(slot1_src_b_sel),
        .slot1_alu_op_i(slot1_alu_op),
        .slot1_rs1_val_i(slot1_rs1_val),
        .slot1_rs2_val_i(slot1_rs2_val),
        .slot1_op_a_i(slot1_op_a),
        .slot1_op_b_i(slot1_op_b),
        .slot1_op_a_late_s10_i(slot1_op_a_late_s10),
        .slot1_op_b_late_s10_i(slot1_op_b_late_s10),
        .slot1_rs1_late_s10_i(slot1_rs1_late_s10),
        .slot1_rs2_late_s10_i(slot1_rs2_late_s10),
        .slot1_late_s10_rd_i(slot1_late_s10_rd),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .slot1_pc_o(slot1_pc_o),
        .instr1_o(instr1_o),
        .slot1_valid_o(slot1_valid_o),
        .slot1_opcode_o(slot1_opcode_o),
        .slot1_funct3_o(slot1_funct3_o),
        .slot1_funct7_o(slot1_funct7_o),
        .slot1_op_19_15_o(slot1_op_19_15_o),
        .slot1_rs1_o(slot1_rs1_o),
        .slot1_rs2_o(slot1_rs2_o),
        .slot1_rd_o(slot1_rd_o),
        .slot1_imm_o(slot1_imm_o),
        .slot1_is_branch_o(slot1_is_branch_o),
        .slot1_is_jal_o(slot1_is_jal_o),
        .slot1_is_jalr_o(slot1_is_jalr_o),
        .slot1_is_load_o(slot1_is_load_o),
        .slot1_is_store_o(slot1_is_store_o),
        .slot1_is_lui_o(slot1_is_lui_o),
        .slot1_is_auipc_o(slot1_is_auipc_o),
        .slot1_unknown_inst_o(slot1_unknown_inst_o),
        .slot1_wb_en_o(slot1_wb_en_o),
        .slot1_uses_rs1_o(slot1_uses_rs1_o),
        .slot1_uses_rs2_o(slot1_uses_rs2_o),
        .slot1_src_a_sel_o(slot1_src_a_sel_o),
        .slot1_src_b_sel_o(slot1_src_b_sel_o),
        .slot1_alu_op_o(slot1_alu_op_o),
        .slot1_rs1_val_o(slot1_rs1_val_o),
        .slot1_rs2_val_o(slot1_rs2_val_o),
        .slot1_op_a_o(slot1_op_a_o),
        .slot1_op_b_o(slot1_op_b_o),
        .slot1_op_a_late_s10_o(slot1_op_a_late_s10_o),
        .slot1_op_b_late_s10_o(slot1_op_b_late_s10_o),
        .slot1_rs1_late_s10_o(slot1_rs1_late_s10_o),
        .slot1_rs2_late_s10_o(slot1_rs2_late_s10_o),
        .slot1_late_s10_rd_o(slot1_late_s10_rd_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_issue_class_o(slot1_issue_class_o)
    );

    task automatic drive_payload;
        input [31:0] base;
        input        valid;
        input        issue_valid;
        begin
            slot1_pc = base;
            instr1 = base ^ 32'h2288_0018;
            slot1_valid = valid;
            slot1_opcode = base[6:0];
            slot1_funct3 = base[10:8];
            slot1_funct7 = base[18:12];
            slot1_op_19_15 = base[23:19];
            slot1_rs1 = base[4:0];
            slot1_rs2 = base[9:5];
            slot1_rd = base[14:10];
            slot1_imm = base + 32'h100;
            slot1_is_branch = base[0];
            slot1_is_jal = base[1];
            slot1_is_jalr = base[2];
            slot1_is_load = base[3];
            slot1_is_store = base[4];
            slot1_is_lui = base[5];
            slot1_is_auipc = base[6];
            slot1_unknown_inst = base[7];
            slot1_wb_en = base[8];
            slot1_uses_rs1 = base[9];
            slot1_uses_rs2 = base[10];
            slot1_src_a_sel = base[12:11];
            slot1_src_b_sel = base[14:13];
            slot1_alu_op = base[18:15];
            slot1_rs1_val = base + 32'h1000_0001;
            slot1_rs2_val = base + 32'h2000_0002;
            slot1_op_a = base + 32'h3000_0003;
            slot1_op_b = base + 32'h4000_0004;
            slot1_op_a_late_s10 = base[0];
            slot1_op_b_late_s10 = base[1];
            slot1_rs1_late_s10 = base[2];
            slot1_rs2_late_s10 = base[3];
            slot1_late_s10_rd = base[19:15];
            slot1_issue_valid = issue_valid;
            slot1_issue_class = 4'b0010;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        drive_payload(32'h1c00_8004, 1'b1, 1'b1);

        capture = 1'b1;
        tick();
        #1;
        `check32("REGS capture pc", slot1_pc_o, 32'h1c00_8004);
        `check32("REGS capture instr", instr1_o, 32'h1c00_8004 ^ 32'h2288_0018);
        `check("REGS capture valid bits", slot1_valid_o && slot1_issue_valid_o);
        `check32("REGS capture register fields",
                 {17'd0, slot1_rs1_o, slot1_rs2_o, slot1_rd_o},
                 {17'd0, 5'd4, 5'd0, 5'd0});
        `check32("REGS capture imm", slot1_imm_o, 32'h1c00_8104);
        `check32("REGS capture operands", slot1_op_a_o, 32'h4c00_8007);
        `check("REGS capture late token bits",
               !slot1_op_a_late_s10_o && !slot1_op_b_late_s10_o &&
               slot1_rs1_late_s10_o && !slot1_rs2_late_s10_o &&
               slot1_late_s10_rd_o == 5'd1);
        `check32("REGS capture issue class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});

        capture = 1'b0;
        drive_payload(32'h1c00_9008, 1'b0, 1'b0);
        tick();
        #1;
        `check32("REGS hold pc when capture low", slot1_pc_o, 32'h1c00_8004);
        `check("REGS hold valid bits when capture low", slot1_valid_o && slot1_issue_valid_o);
        `check32("REGS hold op B when capture low", slot1_op_b_o, 32'h5c00_8008);
        `check("REGS hold late token when capture low",
               !slot1_op_a_late_s10_o && !slot1_op_b_late_s10_o &&
               slot1_rs1_late_s10_o && !slot1_rs2_late_s10_o &&
               slot1_late_s10_rd_o == 5'd1);
        `check32("REGS hold issue class when capture low",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});

        capture = 1'b1;
        tick();
        #1;
        `check32("REGS recapture pc", slot1_pc_o, 32'h1c00_9008);
        `check("REGS recapture invalid bits", !slot1_valid_o && !slot1_issue_valid_o);
        `check32("REGS recapture invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check32("REGS recapture rs values", slot1_rs1_val_o, 32'h2c00_9009);
        `check("REGS recapture invalid clears late token bits",
               !slot1_op_a_late_s10_o && !slot1_op_b_late_s10_o &&
               !slot1_rs1_late_s10_o && !slot1_rs2_late_s10_o &&
               slot1_late_s10_rd_o == 5'd0);
        `check32("REGS recapture decode sideband",
                 {25'd0, slot1_opcode_o}, {25'd0, 7'h08});

        finish_tb();
    end

endmodule
