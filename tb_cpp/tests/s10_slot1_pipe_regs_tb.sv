`timescale 1ns / 1ps

module s10_slot1_pipe_regs_tb;
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
    logic [31:0] slot1_alu_result;
    logic [1:0]  slot1_mem_size;
    logic [31:0] slot1_store_data;
    logic        slot1_mem_lsu;
    logic        slot1_exception;
    logic [5:0]  slot1_excp_ecode;
    logic [8:0]  slot1_excp_esubcode;
    logic        slot1_excp_badv_valid;
    logic [31:0] slot1_excp_badv;
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
    logic [31:0] slot1_alu_result_o;
    logic [1:0]  slot1_mem_size_o;
    logic [31:0] slot1_store_data_o;
    logic        slot1_mem_lsu_o;
    logic        slot1_exception_o;
    logic [5:0]  slot1_excp_ecode_o;
    logic [8:0]  slot1_excp_esubcode_o;
    logic        slot1_excp_badv_valid_o;
    logic [31:0] slot1_excp_badv_o;
    logic        slot1_issue_valid_o;
    logic [3:0]  slot1_issue_class_o;

    s10_slot1_pipe_regs u_dut (
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
        .slot1_alu_result_i(slot1_alu_result),
        .slot1_mem_size_i(slot1_mem_size),
        .slot1_store_data_i(slot1_store_data),
        .slot1_mem_lsu_i(slot1_mem_lsu),
        .slot1_exception_i(slot1_exception),
        .slot1_excp_ecode_i(slot1_excp_ecode),
        .slot1_excp_esubcode_i(slot1_excp_esubcode),
        .slot1_excp_badv_valid_i(slot1_excp_badv_valid),
        .slot1_excp_badv_i(slot1_excp_badv),
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
        .slot1_alu_result_o(slot1_alu_result_o),
        .slot1_mem_size_o(slot1_mem_size_o),
        .slot1_store_data_o(slot1_store_data_o),
        .slot1_mem_lsu_o(slot1_mem_lsu_o),
        .slot1_exception_o(slot1_exception_o),
        .slot1_excp_ecode_o(slot1_excp_ecode_o),
        .slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .slot1_excp_badv_o(slot1_excp_badv_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_issue_class_o(slot1_issue_class_o)
    );

    task automatic drive_payload;
        input [31:0] base;
        input        valid;
        input        issue_valid;
        begin
            slot1_pc = base;
            instr1 = base ^ 32'ha510_001a;
            slot1_valid = valid;
            slot1_opcode = base[6:0];
            slot1_funct3 = base[10:8];
            slot1_funct7 = base[18:12];
            slot1_op_19_15 = base[23:19];
            slot1_rs1 = base[4:0];
            slot1_rs2 = base[9:5];
            slot1_rd = base[14:10];
            slot1_imm = base + 32'h280;
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
            slot1_alu_result = base + 32'h3000_0003;
            slot1_mem_size = base[1:0];
            slot1_store_data = base + 32'h4000_0004;
            slot1_mem_lsu = valid && issue_valid && (base[3] || base[4]);
            slot1_exception = base[11];
            slot1_excp_ecode = base[16:11];
            slot1_excp_esubcode = base[20:12];
            slot1_excp_badv_valid = base[21];
            slot1_excp_badv = base + 32'h5000_0005;
            slot1_issue_valid = issue_valid;
            slot1_issue_class = 4'b0011;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        drive_payload(32'h1c00_a018, 1'b1, 1'b1);

        capture = 1'b1;
        tick();
        #1;
        `check32("S10 slot1 regs capture pc", slot1_pc_o, 32'h1c00_a018);
        `check32("S10 slot1 regs capture instr", instr1_o, 32'h1c00_a018 ^ 32'ha510_001a);
        `check("S10 slot1 regs capture valid bits", slot1_valid_o && slot1_issue_valid_o);
        `check32("S10 slot1 regs capture issue class", {28'd0, slot1_issue_class_o}, {28'd0, 4'b0011});
        `check("S10 slot1 regs capture LSU ownership", slot1_mem_lsu_o);
        `check32("S10 slot1 regs capture alu result", slot1_alu_result_o, 32'h4c00_a01b);
        `check32("S10 slot1 regs capture store data", slot1_store_data_o, 32'h5c00_a01c);
        `check32("S10 slot1 regs capture exception badv", slot1_excp_badv_o, 32'h6c00_a01d);

        capture = 1'b0;
        drive_payload(32'h1c00_b004, 1'b0, 1'b0);
        tick();
        #1;
        `check32("S10 slot1 regs hold pc when capture low", slot1_pc_o, 32'h1c00_a018);
        `check("S10 slot1 regs hold valid bits when capture low", slot1_valid_o && slot1_issue_valid_o);
        `check32("S10 slot1 regs hold issue class when capture low", {28'd0, slot1_issue_class_o}, {28'd0, 4'b0011});
        `check("S10 slot1 regs hold LSU ownership when capture low", slot1_mem_lsu_o);
        `check32("S10 slot1 regs hold mem size when capture low", {30'd0, slot1_mem_size_o}, 32'd0);

        capture = 1'b1;
        tick();
        #1;
        `check32("S10 slot1 regs recapture pc", slot1_pc_o, 32'h1c00_b004);
        `check("S10 slot1 regs recapture invalid bits", !slot1_valid_o && !slot1_issue_valid_o);
        `check32("S10 slot1 regs recapture invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S10 slot1 regs recapture invalid clears LSU ownership", !slot1_mem_lsu_o);
        `check32("S10 slot1 regs recapture imm", slot1_imm_o, 32'h1c00_b284);
        `check32("S10 slot1 regs recapture opcode", {25'd0, slot1_opcode_o}, {25'd0, 7'h04});

        finish_tb();
    end

endmodule
