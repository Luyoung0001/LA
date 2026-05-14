`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s9_slot1_owner_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        s9_valid;
    logic        lane0_is_load;
    logic        lane0_is_store;
    logic        lane0_exception;
    logic [31:0] lane0_addr;
    logic [1:0]  lane0_mem_size;
    logic [31:0] lane0_store_data;

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
    logic        slot1_exception;
    logic [5:0]  slot1_excp_ecode;
    logic [8:0]  slot1_excp_esubcode;
    logic        slot1_excp_badv_valid;
    logic [31:0] slot1_excp_badv;
    logic        slot1_issue_valid;
    logic [3:0]  slot1_issue_class;

    logic        lane1_tlb_exception;
    logic [5:0]  tlb_ecode;
    logic [31:0] tlb_badv;

    logic        slot1_mem_lsu;
    logic        slot1_load_lsu;
    logic        slot1_store_lsu;
    logic        lane1_mem;
    logic        lane1_mem_exception;
    logic        lsu_is_load;
    logic        lsu_is_store;
    logic [31:0] lsu_addr;
    logic [1:0]  lsu_mem_size;
    logic [31:0] lsu_store_data;
    logic [31:0] slot1_alu_result_o;
    logic [1:0]  slot1_mem_size_o;
    logic [31:0] slot1_store_data_o;
    logic        slot1_is_load_o;
    logic        slot1_is_store_o;
    logic        slot1_wb_en_o;
    logic        slot1_issue_valid_o;
    logic [3:0]  slot1_issue_class_o;
    logic        slot1_exception_o;
    logic [5:0]  slot1_excp_ecode_o;
    logic [8:0]  slot1_excp_esubcode_o;
    logic        slot1_excp_badv_valid_o;
    logic [31:0] slot1_excp_badv_o;

    s9_slot1_owner_packet u_dut (
        .s9_valid_i(s9_valid),
        .lane0_is_load_i(lane0_is_load),
        .lane0_is_store_i(lane0_is_store),
        .lane0_exception_i(lane0_exception),
        .lane0_addr_i(lane0_addr),
        .lane0_mem_size_i(lane0_mem_size),
        .lane0_store_data_i(lane0_store_data),
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
        .slot1_exception_i(slot1_exception),
        .slot1_excp_ecode_i(slot1_excp_ecode),
        .slot1_excp_esubcode_i(slot1_excp_esubcode),
        .slot1_excp_badv_valid_i(slot1_excp_badv_valid),
        .slot1_excp_badv_i(slot1_excp_badv),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .lane1_tlb_exception_i(lane1_tlb_exception),
        .tlb_ecode_i(tlb_ecode),
        .tlb_badv_i(tlb_badv),
        .slot1_mem_lsu_o(slot1_mem_lsu),
        .slot1_load_lsu_o(slot1_load_lsu),
        .slot1_store_lsu_o(slot1_store_lsu),
        .lane1_mem_o(lane1_mem),
        .lane1_mem_exception_o(lane1_mem_exception),
        .lsu_is_load_o(lsu_is_load),
        .lsu_is_store_o(lsu_is_store),
        .lsu_addr_o(lsu_addr),
        .lsu_mem_size_o(lsu_mem_size),
        .lsu_store_data_o(lsu_store_data),
        .slot1_pc_o(),
        .instr1_o(),
        .slot1_valid_o(),
        .slot1_opcode_o(),
        .slot1_funct3_o(),
        .slot1_funct7_o(),
        .slot1_op_19_15_o(),
        .slot1_rs1_o(),
        .slot1_rs2_o(),
        .slot1_rd_o(),
        .slot1_imm_o(),
        .slot1_is_branch_o(),
        .slot1_is_jal_o(),
        .slot1_is_jalr_o(),
        .slot1_is_load_o(slot1_is_load_o),
        .slot1_is_store_o(slot1_is_store_o),
        .slot1_is_lui_o(),
        .slot1_is_auipc_o(),
        .slot1_unknown_inst_o(),
        .slot1_wb_en_o(slot1_wb_en_o),
        .slot1_uses_rs1_o(),
        .slot1_uses_rs2_o(),
        .slot1_src_a_sel_o(),
        .slot1_src_b_sel_o(),
        .slot1_alu_op_o(),
        .slot1_alu_result_o(slot1_alu_result_o),
        .slot1_mem_size_o(slot1_mem_size_o),
        .slot1_store_data_o(slot1_store_data_o),
        .slot1_exception_o(slot1_exception_o),
        .slot1_excp_ecode_o(slot1_excp_ecode_o),
        .slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .slot1_excp_badv_o(slot1_excp_badv_o),
        .slot1_issue_valid_o(slot1_issue_valid_o),
        .slot1_issue_class_o(slot1_issue_class_o)
    );

    task automatic clear_inputs;
        begin
            s9_valid = 1'b0;
            lane0_is_load = 1'b0;
            lane0_is_store = 1'b0;
            lane0_exception = 1'b0;
            lane0_addr = 32'h1000_0010;
            lane0_mem_size = 2'b10;
            lane0_store_data = 32'haaaa_0000;
            slot1_pc = 32'h1c02_0004;
            instr1 = 32'h0;
            slot1_valid = 1'b0;
            slot1_opcode = 7'h0a;
            slot1_funct3 = 3'd0;
            slot1_funct7 = 7'h02;
            slot1_op_19_15 = 5'd0;
            slot1_rs1 = 5'd4;
            slot1_rs2 = 5'd5;
            slot1_rd = 5'd6;
            slot1_imm = 32'h4;
            slot1_is_branch = 1'b0;
            slot1_is_jal = 1'b0;
            slot1_is_jalr = 1'b0;
            slot1_is_load = 1'b0;
            slot1_is_store = 1'b0;
            slot1_is_lui = 1'b0;
            slot1_is_auipc = 1'b0;
            slot1_unknown_inst = 1'b0;
            slot1_wb_en = 1'b0;
            slot1_uses_rs1 = 1'b1;
            slot1_uses_rs2 = 1'b0;
            slot1_src_a_sel = `CPU_SRC_A_RS1;
            slot1_src_b_sel = `CPU_SRC_B_IMM;
            slot1_alu_op = `CPU_ALU_ADD;
            slot1_alu_result = 32'h4000_0104;
            slot1_mem_size = 2'b10;
            slot1_store_data = 32'h1234_5678;
            slot1_exception = 1'b0;
            slot1_excp_ecode = 6'd0;
            slot1_excp_esubcode = 9'd0;
            slot1_excp_badv_valid = 1'b0;
            slot1_excp_badv = 32'd0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
            lane1_tlb_exception = 1'b0;
            tlb_ecode = `CPU_ECODE_TLBR;
            tlb_badv = 32'h4000_0104;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S9 owner packet idle is silent",
               !slot1_mem_lsu && !lsu_is_load && !lsu_is_store &&
               !slot1_issue_valid_o && !slot1_exception_o);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_is_load = 1'b1;
        slot1_wb_en = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_alu_result = 32'h4000_0124;
        slot1_mem_size = 2'b10;
        tlb_badv = 32'h4000_0124;
        #1;
        `check("S9 owner packet issued slot1 load owns shared LSU",
               slot1_mem_lsu && slot1_load_lsu && lane1_mem &&
               !slot1_store_lsu && lsu_is_load && !lsu_is_store &&
               slot1_is_load_o && slot1_wb_en_o && slot1_issue_valid_o);
        `check32("S9 owner packet slot1 load address", lsu_addr, 32'h4000_0124);
        `check32("S9 owner packet slot1 load size", {30'd0, lsu_mem_size}, 32'd2);
        `check32("S9 owner packet slot1 load class", {28'd0, slot1_issue_class_o},
                 {28'd0, `CPU_SLOT1_CLASS_LOAD});
        `check32("S9 owner packet slot1 load alu result pass", slot1_alu_result_o, 32'h4000_0124);

        clear_inputs();
        s9_valid = 1'b1;
        lane0_is_store = 1'b1;
        lane0_addr = 32'h2000_0020;
        lane0_store_data = 32'hface_0001;
        slot1_valid = 1'b1;
        slot1_is_load = 1'b1;
        slot1_wb_en = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_alu_result = 32'h4000_0224;
        #1;
        `check("S9 owner packet lane0 memory blocks slot1 LSU ownership but keeps sideband",
               !slot1_mem_lsu && !slot1_load_lsu && !lane1_mem &&
               !lsu_is_load && lsu_is_store &&
               slot1_is_load_o && slot1_issue_valid_o && slot1_wb_en_o);
        `check32("S9 owner packet blocked slot1 load keeps address sideband",
                 slot1_alu_result_o, 32'h4000_0224);
        `check32("S9 owner packet lane0 store keeps shared LSU data", lsu_store_data, 32'hface_0001);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_is_store = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_STORE;
        slot1_store_data = 32'h5566_7788;
        slot1_alu_result = 32'h4000_0330;
        slot1_mem_size = 2'b01;
        lane1_tlb_exception = 1'b1;
        tlb_badv = 32'h4000_0330;
        #1;
        `check("S9 owner packet issued slot1 store keeps ownership and TLB exception sideband",
               slot1_mem_lsu && slot1_store_lsu && lane1_mem &&
               !lane1_mem_exception && !lsu_is_load && lsu_is_store &&
               slot1_is_store_o && slot1_issue_valid_o &&
               slot1_exception_o && slot1_excp_badv_valid_o);
        `check32("S9 owner packet slot1 store keeps LSU data", lsu_store_data, 32'h5566_7788);
        `check32("S9 owner packet slot1 store TLB ecode", {26'd0, slot1_excp_ecode_o},
                 {26'd0, `CPU_ECODE_TLBR});
        `check32("S9 owner packet slot1 store TLB badv", slot1_excp_badv_o, 32'h4000_0330);

        clear_inputs();
        s9_valid = 1'b1;
        slot1_valid = 1'b1;
        slot1_is_load = 1'b1;
        slot1_wb_en = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = `CPU_SLOT1_CLASS_LOAD;
        slot1_alu_result = 32'h4000_0444;
        slot1_mem_size = 2'b01;
        slot1_exception = 1'b1;
        slot1_excp_ecode = `CPU_ECODE_ALE;
        slot1_excp_esubcode = 9'd0;
        slot1_excp_badv_valid = 1'b1;
        slot1_excp_badv = 32'h4000_0444;
        lane1_tlb_exception = 1'b1;
        tlb_badv = 32'h0bad_0444;
        #1;
        `check("S9 owner packet local slot1 exception wins over TLB sideband",
               slot1_exception_o && slot1_excp_badv_valid_o &&
               slot1_mem_lsu && slot1_load_lsu);
        `check("S9 owner packet local memory exception still marks lane1 mem exception",
               lane1_mem_exception);
        `check32("S9 owner packet local exception ecode priority",
                 {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S9 owner packet local exception badv priority",
                 slot1_excp_badv_o, 32'h4000_0444);
        `check32("S9 owner packet local exception esubcode priority",
                 {23'd0, slot1_excp_esubcode_o}, 32'd0);

        finish_tb();
    end
endmodule
