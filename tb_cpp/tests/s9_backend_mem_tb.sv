`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s9_backend_mem_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush, in_valid, allowin, s10_allowin, out_valid;
    logic wb_en_i, is_load_i, is_store_i, mem_sign_ext_i, exception_i;
    logic is_csr_i, csr_we_i, csr_xchg_i, is_syscall_i, is_ertn_i;
    logic tlb_found_i, tlb_v_i, tlb_d_i;
    logic [5:0] excp_ecode_i, excp_ecode_o;
    logic [8:0] excp_esubcode_i, excp_esubcode_o;
    logic excp_badv_valid_i, excp_badv_valid_o;
    logic [31:0] excp_badv_i, excp_badv_o;
    logic [31:0] csr_crmd_i, csr_dmw0_i, csr_dmw1_i;
    logic [31:0] pc_i, instr_i, mem_addr_i, store_data_i, wb_data_pre_i, csr_wdata_i, csr_wmask_i;
    logic [31:0] slot1_pc_i, instr1_i, slot1_imm_i, slot1_alu_result_i, slot1_store_data_i;
    logic [1:0] epoch_i, epoch_o;
    logic [13:0] csr_addr_i;
    logic [4:0] rd_i;
    logic [4:0] slot1_op_19_15_i, slot1_rs1_i, slot1_rs2_i, slot1_rd_i;
    logic [1:0] mem_size_i;
    logic [1:0] slot1_src_a_sel_i, slot1_src_b_sel_i, slot1_mem_size_i;
    logic [1:0] slot1_src_a_sel_o, slot1_src_b_sel_o, slot1_mem_size_o;
    logic [3:0] slot1_alu_op_i, slot1_alu_op_o;
    logic [19:0] tlb_ppn_i;
    logic [5:0] tlb_ps_i;
    logic [1:0] tlb_plv_i, tlb_mat_i;
    logic [31:0] dcache_paddr_o, dcache_store_data_o, pc_o, instr_o, wb_data_pre_o, wb_data_pre_raw_o;
    logic [31:0] slot1_pc_o, instr1_o, slot1_imm_o, slot1_alu_result_o, slot1_store_data_o;
    logic slot1_mem_lsu_o;
    logic dcache_req_valid_o, dcache_is_load_o, dcache_is_store_o, dcache_uncached_o;
    logic wb_en_o, is_load_o, is_store_o, mem_uncached_o, mem_sign_ext_o, exception_o, valid_o, wb_en_raw_o;
    logic slot1_valid_i, slot1_is_branch_i, slot1_is_jal_i, slot1_is_jalr_i, slot1_is_load_i, slot1_is_store_i, slot1_is_lui_i, slot1_is_auipc_i, slot1_unknown_i;
    logic slot1_wb_en_i, slot1_uses_rs1_i, slot1_uses_rs2_i, slot1_issue_valid_i;
    logic slot1_valid_o, slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o;
    logic slot1_wb_en_o, slot1_uses_rs1_o, slot1_uses_rs2_o, slot1_issue_valid_o;
    logic slot1_emit_valid_o, slot1_fire_o;
    logic shared_mem_valid_o, shared_mem_req_valid_o, shared_mem_mem_req_o, shared_mem_preld_req_o;
    logic shared_mem_owner_slot0_o, shared_mem_owner_slot1_o;
    logic shared_mem_slot0_req_o, shared_mem_slot1_req_o;
    logic shared_mem_slot1_load_o, shared_mem_slot1_store_o;
    logic shared_mem_lane1_exception_o, shared_mem_lane0_tlb_exception_o, shared_mem_lane1_tlb_exception_o;
    logic [3:0] slot1_issue_class_i, slot1_issue_class_o;
    logic [3:0] slot1_emit_class_o;
    logic slot1_exception_i, slot1_excp_badv_valid_i;
    logic slot1_exception_o, slot1_excp_badv_valid_o;
    logic [5:0] slot1_excp_ecode_i, slot1_excp_ecode_o;
    logic [8:0] slot1_excp_esubcode_i, slot1_excp_esubcode_o;
    logic [31:0] slot1_excp_badv_i, slot1_excp_badv_o;
    logic is_csr_o, csr_we_o, csr_xchg_o, is_syscall_o, is_ertn_o, is_csr_raw_o;
    logic [13:0] csr_addr_o;
    logic [31:0] csr_wdata_o, csr_wmask_o;
    logic [1:0] dcache_size_o, mem_size_o;
    logic [4:0] rd_o, rd_raw_o;
    logic [4:0] slot1_op_19_15_o, slot1_rs1_o, slot1_rs2_o, slot1_rd_o;
    logic [6:0] slot1_opcode_i, slot1_funct7_i, slot1_opcode_o, slot1_funct7_o;
    logic [2:0] slot1_funct3_i, slot1_funct3_o;
    function automatic [31:0] la_cacop(input [4:0] op, input [4:0] rj, input [11:0] imm);
        la_cacop = {6'h01, 4'h8, imm, rj, op};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    always_comb begin
        slot1_issue_class_i = 4'd0;
        if (slot1_issue_valid_i) begin
            if (slot1_is_load_i)
                slot1_issue_class_i = 4'b0100;
            else if (slot1_is_store_i)
                slot1_issue_class_i = 4'b0010;
            else if (slot1_is_branch_i || slot1_is_jal_i || slot1_is_jalr_i)
                slot1_issue_class_i = 4'b0001;
            else
                slot1_issue_class_i = 4'b1000;
        end
    end

    s9_backend_mem #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .s8_to_s9_valid(in_valid),
        .s9_allowin(allowin), .s10_allowin(s10_allowin), .s9_to_s10_valid(out_valid),
        .s8_pc_i(pc_i), .s8_instr_i(instr_i), .s8_rd_i(rd_i), .s8_wb_en_i(wb_en_i),
        .s8_epoch_i(epoch_i),
        .s8_is_load_i(is_load_i), .s8_is_store_i(is_store_i), .s8_mem_size_i(mem_size_i),
        .s8_mem_sign_ext_i(mem_sign_ext_i), .s8_mem_addr_i(mem_addr_i), .s8_store_data_i(store_data_i),
        .s8_wb_data_pre_i(wb_data_pre_i), .s8_exception_i(exception_i),
        .s8_excp_ecode_i(excp_ecode_i), .s8_excp_esubcode_i(excp_esubcode_i),
        .s8_excp_badv_valid_i(excp_badv_valid_i), .s8_excp_badv_i(excp_badv_i),
        .tlb_found_i(tlb_found_i),
        .s8_is_csr_i(is_csr_i), .s8_csr_we_i(csr_we_i), .s8_csr_xchg_i(csr_xchg_i),
        .s8_csr_addr_i(csr_addr_i), .s8_csr_wdata_i(csr_wdata_i), .s8_csr_wmask_i(csr_wmask_i),
        .s8_is_syscall_i(is_syscall_i), .s8_is_ertn_i(is_ertn_i),
        .s8_slot1_pc_i(slot1_pc_i), .s8_instr1_i(instr1_i), .s8_slot1_valid_i(slot1_valid_i),
        .s8_slot1_opcode_i(slot1_opcode_i), .s8_slot1_funct3_i(slot1_funct3_i),
        .s8_slot1_funct7_i(slot1_funct7_i), .s8_slot1_op_19_15_i(slot1_op_19_15_i),
        .s8_slot1_rs1_i(slot1_rs1_i), .s8_slot1_rs2_i(slot1_rs2_i), .s8_slot1_rd_i(slot1_rd_i),
        .s8_slot1_imm_i(slot1_imm_i), .s8_slot1_is_branch_i(slot1_is_branch_i),
        .s8_slot1_is_jal_i(slot1_is_jal_i), .s8_slot1_is_jalr_i(slot1_is_jalr_i),
        .s8_slot1_is_load_i(slot1_is_load_i), .s8_slot1_is_store_i(slot1_is_store_i),
        .s8_slot1_is_lui_i(slot1_is_lui_i), .s8_slot1_is_auipc_i(slot1_is_auipc_i),
        .s8_slot1_unknown_inst_i(slot1_unknown_i),
        .s8_slot1_wb_en_i(slot1_wb_en_i), .s8_slot1_uses_rs1_i(slot1_uses_rs1_i),
        .s8_slot1_uses_rs2_i(slot1_uses_rs2_i), .s8_slot1_src_a_sel_i(slot1_src_a_sel_i),
        .s8_slot1_src_b_sel_i(slot1_src_b_sel_i), .s8_slot1_alu_op_i(slot1_alu_op_i),
        .s8_slot1_alu_result_i(slot1_alu_result_i),
        .s8_slot1_mem_size_i(slot1_mem_size_i),
        .s8_slot1_store_data_i(slot1_store_data_i),
        .s8_slot1_exception_i(slot1_exception_i),
        .s8_slot1_excp_ecode_i(slot1_excp_ecode_i),
        .s8_slot1_excp_esubcode_i(slot1_excp_esubcode_i),
        .s8_slot1_excp_badv_valid_i(slot1_excp_badv_valid_i),
        .s8_slot1_excp_badv_i(slot1_excp_badv_i),
        .s8_slot1_issue_valid_i(slot1_issue_valid_i),
        .s8_slot1_issue_class_i(slot1_issue_class_i),
        .tlb_ppn_i(tlb_ppn_i), .tlb_ps_i(tlb_ps_i), .tlb_plv_i(tlb_plv_i), .tlb_mat_i(tlb_mat_i),
        .tlb_v_i(tlb_v_i), .tlb_d_i(tlb_d_i),
        .csr_crmd_i(csr_crmd_i), .csr_dmw0_i(csr_dmw0_i), .csr_dmw1_i(csr_dmw1_i),
        .dcache_paddr_o(dcache_paddr_o),
        .dcache_req_valid_o(dcache_req_valid_o), .dcache_is_load_o(dcache_is_load_o),
        .dcache_is_store_o(dcache_is_store_o), .dcache_size_o(dcache_size_o),
        .dcache_store_data_o(dcache_store_data_o), .dcache_uncached_o(dcache_uncached_o),
        .s9_pc_o(pc_o), .s9_instr_o(instr_o), .s9_epoch_o(epoch_o),
        .s9_rd_o(rd_o), .s9_wb_en_o(wb_en_o), .s9_wb_data_pre_o(wb_data_pre_o),
        .s9_is_load_o(is_load_o), .s9_is_store_o(is_store_o), .s9_mem_uncached_o(mem_uncached_o),
        .s9_mem_size_o(mem_size_o),
        .s9_mem_sign_ext_o(mem_sign_ext_o), .s9_exception_o(exception_o),
        .s9_excp_ecode_o(excp_ecode_o), .s9_excp_esubcode_o(excp_esubcode_o),
        .s9_excp_badv_valid_o(excp_badv_valid_o), .s9_excp_badv_o(excp_badv_o),
        .s9_slot1_pc_o(slot1_pc_o), .s9_instr1_o(instr1_o), .s9_slot1_valid_o(slot1_valid_o),
        .s9_slot1_opcode_o(slot1_opcode_o), .s9_slot1_funct3_o(slot1_funct3_o),
        .s9_slot1_funct7_o(slot1_funct7_o), .s9_slot1_op_19_15_o(slot1_op_19_15_o),
        .s9_slot1_rs1_o(slot1_rs1_o), .s9_slot1_rs2_o(slot1_rs2_o), .s9_slot1_rd_o(slot1_rd_o),
        .s9_slot1_imm_o(slot1_imm_o), .s9_slot1_is_branch_o(slot1_is_branch_o),
        .s9_slot1_is_jal_o(slot1_is_jal_o), .s9_slot1_is_jalr_o(slot1_is_jalr_o),
        .s9_slot1_is_load_o(slot1_is_load_o), .s9_slot1_is_store_o(slot1_is_store_o),
        .s9_slot1_is_lui_o(slot1_is_lui_o), .s9_slot1_is_auipc_o(slot1_is_auipc_o),
        .s9_slot1_unknown_inst_o(slot1_unknown_o),
        .s9_slot1_wb_en_o(slot1_wb_en_o), .s9_slot1_uses_rs1_o(slot1_uses_rs1_o),
        .s9_slot1_uses_rs2_o(slot1_uses_rs2_o), .s9_slot1_src_a_sel_o(slot1_src_a_sel_o),
        .s9_slot1_src_b_sel_o(slot1_src_b_sel_o), .s9_slot1_alu_op_o(slot1_alu_op_o),
        .s9_slot1_alu_result_o(slot1_alu_result_o),
        .s9_slot1_mem_size_o(slot1_mem_size_o),
        .s9_slot1_store_data_o(slot1_store_data_o),
        .s9_slot1_mem_lsu_o(slot1_mem_lsu_o),
        .s9_slot1_exception_o(slot1_exception_o),
        .s9_slot1_excp_ecode_o(slot1_excp_ecode_o),
        .s9_slot1_excp_esubcode_o(slot1_excp_esubcode_o),
        .s9_slot1_excp_badv_valid_o(slot1_excp_badv_valid_o),
        .s9_slot1_excp_badv_o(slot1_excp_badv_o),
        .s9_slot1_issue_valid_o(slot1_issue_valid_o),
        .s9_slot1_issue_class_o(slot1_issue_class_o),
        .s9_slot1_emit_valid_o(slot1_emit_valid_o),
        .s9_slot1_fire_o(slot1_fire_o),
        .s9_slot1_emit_class_o(slot1_emit_class_o),
        .s9_shared_mem_valid_o(shared_mem_valid_o),
        .s9_shared_mem_req_valid_o(shared_mem_req_valid_o),
        .s9_shared_mem_mem_req_o(shared_mem_mem_req_o),
        .s9_shared_mem_preld_req_o(shared_mem_preld_req_o),
        .s9_shared_mem_owner_slot0_o(shared_mem_owner_slot0_o),
        .s9_shared_mem_owner_slot1_o(shared_mem_owner_slot1_o),
        .s9_shared_mem_slot0_req_o(shared_mem_slot0_req_o),
        .s9_shared_mem_slot1_req_o(shared_mem_slot1_req_o),
        .s9_shared_mem_slot1_load_o(shared_mem_slot1_load_o),
        .s9_shared_mem_slot1_store_o(shared_mem_slot1_store_o),
        .s9_shared_mem_lane1_exception_o(shared_mem_lane1_exception_o),
        .s9_shared_mem_lane0_tlb_exception_o(shared_mem_lane0_tlb_exception_o),
        .s9_shared_mem_lane1_tlb_exception_o(shared_mem_lane1_tlb_exception_o),
        .s9_valid_o(valid_o),
        .s9_is_csr_o(is_csr_o), .s9_csr_we_o(csr_we_o), .s9_csr_xchg_o(csr_xchg_o),
        .s9_csr_addr_o(csr_addr_o), .s9_csr_wdata_o(csr_wdata_o), .s9_csr_wmask_o(csr_wmask_o),
        .s9_is_syscall_o(is_syscall_o), .s9_is_ertn_o(is_ertn_o),
        .s9_wb_en_raw_o(wb_en_raw_o), .s9_rd_raw_o(rd_raw_o), .s9_wb_data_pre_raw_o(wb_data_pre_raw_o),
        .s9_is_csr_raw_o(is_csr_raw_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; s10_allowin = 1; pc_i = 32'h1c010000; instr_i = 0;
        epoch_i = 2'd2; rd_i = 5'd8; wb_en_i = 1;
        is_load_i = 1; is_store_i = 0; mem_size_i = 2'b10; mem_sign_ext_i = 1; mem_addr_i = 32'h40; store_data_i = 32'h1234; wb_data_pre_i = 32'h40; exception_i = 0;
        excp_ecode_i = 0; excp_esubcode_i = 0; excp_badv_valid_i = 0; excp_badv_i = 0;
        csr_crmd_i = 32'h0000_0010; csr_dmw0_i = 0; csr_dmw1_i = 0;
        is_csr_i = 0; csr_we_i = 0; csr_xchg_i = 0; csr_addr_i = 0; csr_wdata_i = 0; csr_wmask_i = 0; is_syscall_i = 0; is_ertn_i = 0;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h0; slot1_valid_i = 1'b0;
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_alu_result_i = 32'd0;
        slot1_mem_size_i = 2'd0; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;
        tlb_found_i = 1; tlb_ppn_i = 20'h0bfaf; tlb_ps_i = 6'd12; tlb_plv_i = 0; tlb_mat_i = 2'b01; tlb_v_i = 1; tlb_d_i = 1;
        reset_dut();
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 valid", out_valid && valid_o);
        `check("S9 epoch pass-through", epoch_o == 2'd2);
        `check("S9 load dcache request", dcache_req_valid_o && dcache_is_load_o);
        `check("S9 load owner fact belongs to slot0",
               shared_mem_valid_o && shared_mem_owner_slot0_o &&
               shared_mem_slot0_req_o && !shared_mem_owner_slot1_o);
        `check("S9 carries cached load sideband", !dcache_uncached_o && !mem_uncached_o);
        `check32("S9 translated paddr", dcache_paddr_o, 32'h0bfaf040);
        `check32("S9 data pass", wb_data_pre_o, 32'h40);
        slot1_valid_i = 1'b1;
        slot1_pc_i = 32'h1c010004; instr1_i = 32'h02801085;
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd4; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd5; slot1_imm_i = 32'h4;
        slot1_alu_result_i = 32'h1234_0008;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot1 sideband pass-through",
               slot1_valid_o && slot1_pc_o == 32'h1c010004 && instr1_o == 32'h02801085);
        `check32("S9 slot1 rs1 pass", {27'h0, slot1_rs1_o}, 32'd4);
        `check32("S9 slot1 rd pass", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S9 slot1 imm pass", slot1_imm_o, 32'h4);
        `check("S9 slot1 kind pass",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check("S9 slot1 simple ALU payload pass",
               slot1_wb_en_o && slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 && slot1_src_b_sel_o == `CPU_SRC_B_IMM &&
               slot1_alu_op_o == `CPU_ALU_ADD);
        `check32("S9 slot1 shadow ALU result pass", slot1_alu_result_o, 32'h1234_0008);
        `check("S9 slot1 issue sideband stays off in phase1", !slot1_issue_valid_o);
        `check32("S9 slot1 issue class stays off in phase1", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S9 slot1 ALU does not own LSU in phase1", !slot1_mem_lsu_o);
        slot1_issue_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot1 issue sideband passes when selected",
               slot1_valid_o && slot1_issue_valid_o && slot1_rd_o == 5'd5);
        `check32("S9 selected slot1 ALU carries compute class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b1000});
        `check("S9 selected slot1 ALU emits and fires to S10",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b1000);
        `check("S9 selected slot1 ALU still does not own LSU", !slot1_mem_lsu_o);
        `check32("S9 selected slot1 ALU result remains valid", slot1_alu_result_o, 32'h1234_0008);
        `check32("S9 selected slot1 ALU has no store size sideband",
                 {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S9 selected slot1 ALU has no store data sideband", slot1_store_data_o, 32'd0);

        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b0; instr_i = 32'h0; exception_i = 1'b0;
        mem_addr_i = 32'h4000_0200; store_data_i = 32'hfeed_cafe;
        csr_crmd_i = 32'h0000_0010; csr_dmw0_i = 32'd0; csr_dmw1_i = 32'd0;
        tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        slot1_issue_valid_i = 1'b0;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h008);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd12; slot1_rd_i = 5'd12; slot1_imm_i = 32'h8;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0;
        slot1_unknown_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_alu_result_i = 32'h0000_8808;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h1357_9bdf;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot1 store prepare remains sideband-only",
               out_valid && slot1_valid_o && slot1_is_store_o &&
               !slot1_issue_valid_o && !slot1_wb_en_o);
        `check32("S9 unissued slot1 store clears issue class",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S9 unissued slot1 store does not own LSU", !slot1_mem_lsu_o);
        `check("S9 slot1 store prepare keeps address and data source flags",
               slot1_uses_rs1_o && slot1_uses_rs2_o &&
               slot1_src_a_sel_o == `CPU_SRC_A_RS1 &&
               slot1_src_b_sel_o == `CPU_SRC_B_IMM);
        `check32("S9 slot1 store prepare address pass", slot1_alu_result_o, 32'h0000_8808);
        `check32("S9 slot1 store prepare size pass", {30'd0, slot1_mem_size_o}, 32'd2);
        `check32("S9 slot1 store prepare data pass", slot1_store_data_o, 32'h1357_9bdf);
        `check("S9 aligned slot1 store prepare has no exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check("S9 unissued slot1 store does not request DCache",
               !dcache_req_valid_o && !dcache_is_load_o && !dcache_is_store_o);
        `check("S9 unissued slot1 store has no shared owner",
               !shared_mem_valid_o && !shared_mem_owner_slot1_o);
        `check("S9 unissued slot1 store does not raise lane0 memory exception",
               !is_load_o && !is_store_o && !exception_o);

        tlb_found_i = 1'b1; tlb_ppn_i = 20'h0beef; tlb_ps_i = 6'd12;
        tlb_plv_i = 2'd0; tlb_mat_i = 2'b01; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_alu_result_i = 32'h4000_8810;
        slot1_mem_size_i = 2'b01; slot1_store_data_i = 32'h0000_55aa;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 issued slot1 store requests shared DCache store",
               out_valid && slot1_issue_valid_o &&
               dcache_req_valid_o && dcache_is_store_o && !dcache_is_load_o);
        `check32("S9 issued slot1 store carries store class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0010});
        `check("S9 issued slot1 store emits and fires to S10",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b0010);
        `check("S9 issued slot1 store carries explicit LSU ownership", slot1_mem_lsu_o);
        `check("S9 issued slot1 store owner packet is slot1 store",
               shared_mem_valid_o && shared_mem_owner_slot1_o &&
               shared_mem_slot1_req_o && shared_mem_slot1_store_o &&
               !shared_mem_owner_slot0_o);
        `check32("S9 issued slot1 store translated paddr",
                 dcache_paddr_o, 32'h0beef810);
        `check32("S9 issued slot1 store size",
                 {30'd0, dcache_size_o}, 32'd1);
        `check32("S9 issued slot1 store data",
                 dcache_store_data_o, 32'h0000_55aa);
        `check("S9 issued slot1 store keeps lane0 sideband non-memory",
               !is_load_o && !is_store_o && !exception_o);

        tlb_found_i = 1'b1; tlb_ppn_i = 20'h0cafe; tlb_ps_i = 6'd12;
        tlb_plv_i = 2'd0; tlb_mat_i = 2'b01; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_alu_result_i = 32'h4000_8824;
        slot1_mem_size_i = 2'b10;
        slot1_store_data_i = 32'h0000_0000;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 issued slot1 load requests shared DCache load",
               out_valid && slot1_issue_valid_o &&
               dcache_req_valid_o && dcache_is_load_o && !dcache_is_store_o);
        `check32("S9 issued slot1 load carries load class",
                 {28'd0, slot1_issue_class_o}, {28'd0, 4'b0100});
        `check("S9 issued slot1 load emits and fires to S10",
               slot1_emit_valid_o && slot1_fire_o && slot1_emit_class_o == 4'b0100);
        `check("S9 issued slot1 load carries explicit LSU ownership", slot1_mem_lsu_o);
        `check("S9 issued slot1 load owner packet is slot1 load",
               shared_mem_owner_slot1_o && shared_mem_slot1_req_o &&
               shared_mem_slot1_load_o && !shared_mem_slot1_store_o);
        `check32("S9 issued slot1 load translated paddr",
                 dcache_paddr_o, 32'h0cafe824);
        `check32("S9 issued slot1 load size",
                 {30'd0, dcache_size_o}, 32'd2);
        `check("S9 issued slot1 load keeps lane0 sideband non-memory",
               !is_load_o && !is_store_o && !exception_o);

        tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_alu_result_i = 32'h4000_8828;
        slot1_mem_size_i = 2'b10;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 issued slot1 load TLB miss becomes slot1 sideband exception",
               out_valid && slot1_issue_valid_o && slot1_exception_o &&
               slot1_excp_badv_valid_o && !exception_o);
        `check("S9 issued slot1 load TLB miss keeps LSU ownership sideband", slot1_mem_lsu_o);
        `check("S9 issued slot1 load TLB miss keeps owner but blocks request",
               shared_mem_owner_slot1_o && shared_mem_slot1_load_o &&
               !shared_mem_slot1_req_o && shared_mem_lane1_tlb_exception_o);
        `check32("S9 issued slot1 load TLBR ecode",
                 {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S9 issued slot1 load TLBR badv",
                 slot1_excp_badv_o, 32'h4000_8828);
        `check("S9 issued slot1 load TLB miss blocks DCache",
               !dcache_req_valid_o && !dcache_is_load_o && !dcache_is_store_o);

        tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_alu_result_i = 32'h4000_8820;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h2468_ace0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 issued slot1 store TLB miss becomes slot1 sideband exception",
               out_valid && slot1_issue_valid_o && slot1_exception_o &&
               slot1_excp_badv_valid_o && !exception_o);
        `check("S9 issued slot1 store TLB miss keeps LSU ownership sideband", slot1_mem_lsu_o);
        `check("S9 issued slot1 store TLB miss keeps owner but blocks request",
               shared_mem_owner_slot1_o && shared_mem_slot1_store_o &&
               !shared_mem_slot1_req_o && shared_mem_lane1_tlb_exception_o);
        `check32("S9 issued slot1 store TLBR ecode",
                 {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S9 issued slot1 store TLBR badv",
                 slot1_excp_badv_o, 32'h4000_8820);
        `check("S9 issued slot1 store TLB miss blocks DCache",
               !dcache_req_valid_o && !dcache_is_store_o);

        tlb_found_i = 1'b1; tlb_ppn_i = 20'h0cafe; tlb_ps_i = 6'd12;
        tlb_plv_i = 2'd0; tlb_mat_i = 2'b01; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        slot1_issue_valid_i = 1'b0;
        instr1_i = la_mem(4'h8, 5'd14, 5'd13, 12'h003);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_rs1_i = 5'd13; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd14; slot1_imm_i = 32'h3;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM; slot1_alu_op_i = `CPU_ALU_ADD;
        slot1_alu_result_i = 32'h4000_8833;
        slot1_mem_size_i = 2'b00; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot1 load prepare remains sideband-only",
               out_valid && slot1_valid_o && slot1_is_load_o &&
               !slot1_issue_valid_o && slot1_wb_en_o);
        `check32("S9 unissued slot1 load clears issue class",
                 {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S9 unissued slot1 load does not own LSU", !slot1_mem_lsu_o);
        `check("S9 unissued slot1 load does not request DCache",
               !dcache_req_valid_o && !dcache_is_load_o && !dcache_is_store_o);
        `check32("S9 slot1 load prepare address pass", slot1_alu_result_o, 32'h4000_8833);
        `check32("S9 slot1 load prepare byte size pass", {30'd0, slot1_mem_size_o}, 32'd0);
        `check("S9 unissued slot1 load does not raise lane0 memory exception",
               !is_load_o && !is_store_o && !exception_o);

        slot1_issue_valid_i = 1'b1;
        slot1_alu_result_i = 32'h4000_8834;
        slot1_mem_size_i = 2'b10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 issued slot1 load requests shared DCache load",
               out_valid && slot1_issue_valid_o &&
               dcache_req_valid_o && dcache_is_load_o && !dcache_is_store_o);
        `check("S9 issued slot1 load carries LSU ownership after replay", slot1_mem_lsu_o);
        `check32("S9 issued slot1 load translated paddr",
                 dcache_paddr_o, 32'h0cafe834);
        `check32("S9 issued slot1 load size",
                 {30'd0, dcache_size_o}, 32'd2);
        `check("S9 issued slot1 load keeps lane0 sideband non-memory",
               !is_load_o && !is_store_o && !exception_o);

        tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_alu_result_i = 32'h4000_8840;
        slot1_mem_size_i = 2'b01;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 issued slot1 load TLB miss becomes slot1 sideband exception",
               out_valid && slot1_issue_valid_o && slot1_exception_o &&
               slot1_excp_badv_valid_o && !exception_o);
        `check("S9 issued slot1 load TLB miss carries LSU ownership after replay", slot1_mem_lsu_o);
        `check32("S9 issued slot1 load TLBR ecode",
                 {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S9 issued slot1 load TLBR badv",
                 slot1_excp_badv_o, 32'h4000_8840);
        `check("S9 issued slot1 load TLB miss blocks DCache",
               !dcache_req_valid_o && !dcache_is_load_o);

        exception_i = 1'b1;
        excp_ecode_i = `CPU_ECODE_ALE;
        excp_esubcode_i = 9'd0;
        excp_badv_valid_i = 1'b1;
        excp_badv_i = 32'h1c02_0000;
        tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_valid_i = 1'b1;
        slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        slot1_alu_result_i = 32'h4000_8850;
        slot1_mem_size_i = 2'b10;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot0 exception suppresses issued slot1 load request",
               out_valid && exception_o && !dcache_req_valid_o &&
               !dcache_is_load_o && !slot1_exception_o);
        `check("S9 slot0 exception suppresses slot1 LSU ownership", !slot1_mem_lsu_o);
        `check32("S9 slot0 exception wins over slot1 load TLBR ecode",
                 {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S9 slot0 exception keeps lane0 badv",
                 excp_badv_o, 32'h1c02_0000);

        exception_i = 1'b1;
        excp_ecode_i = `CPU_ECODE_ALE;
        excp_badv_valid_i = 1'b1;
        excp_badv_i = 32'h1c02_0004;
        tlb_found_i = 1'b1; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        tlb_ppn_i = 20'h0dead; tlb_ps_i = 6'd12;
        slot1_issue_valid_i = 1'b1;
        slot1_valid_i = 1'b1;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1;
        slot1_wb_en_i = 1'b0;
        slot1_exception_i = 1'b0; slot1_excp_badv_valid_i = 1'b0;
        slot1_alu_result_i = 32'h4000_8860;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h1122_3344;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot0 exception suppresses issued slot1 store request",
               out_valid && exception_o && !dcache_req_valid_o &&
               !dcache_is_store_o && !slot1_exception_o);
        `check("S9 slot0 exception suppresses slot1 store LSU ownership", !slot1_mem_lsu_o);
        `check32("S9 slot0 exception wins over slot1 store ecode",
                 {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S9 slot0 exception keeps store lane0 badv",
                 excp_badv_o, 32'h1c02_0004);

        exception_i = 1'b0;
        excp_ecode_i = 6'd0;
        excp_badv_valid_i = 1'b0;
        excp_badv_i = 32'd0;
        slot1_issue_valid_i = 1'b0;
        slot1_valid_i = 1'b1;
        instr1_i = la_mem(4'h6, 5'd12, 5'd13, 12'h006);
        slot1_opcode_i = {1'b0, instr1_i[31:26]};
        slot1_funct3_i = {1'b0, instr1_i[21:20]};
        slot1_funct7_i = {3'b0, instr1_i[25:22]};
        slot1_op_19_15_i = instr1_i[19:15];
        slot1_imm_i = 32'h6;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b1;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_alu_result_i = 32'h0000_8806;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'h1357_9bdf;
        slot1_exception_i = 1'b1; slot1_excp_ecode_i = `CPU_ECODE_ALE; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b1; slot1_excp_badv_i = 32'h0000_8806;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 unissued unaligned slot1 store carries exception candidate",
               out_valid && slot1_valid_o && slot1_is_store_o && !slot1_issue_valid_o &&
               slot1_exception_o && slot1_excp_badv_valid_o);
        `check32("S9 slot1 store ALE ecode", {26'd0, slot1_excp_ecode_o}, {26'd0, `CPU_ECODE_ALE});
        `check32("S9 slot1 store ALE badv", slot1_excp_badv_o, 32'h0000_8806);
        `check("S9 unissued slot1 store ALE remains sideband-only",
               !dcache_req_valid_o && !dcache_is_store_o && !exception_o);
        `check("S9 unissued slot1 store ALE does not own LSU", !slot1_mem_lsu_o);

        slot1_issue_valid_i = 1'b0;
        slot1_valid_i = 1'b0;
        slot1_issue_valid_i = 1'b1;
        slot1_opcode_i = 7'h7f; slot1_funct3_i = 3'h7; slot1_funct7_i = 7'h7f; slot1_op_19_15_i = 5'h1f;
        slot1_rs1_i = 5'd31; slot1_rs2_i = 5'd30; slot1_rd_i = 5'd29; slot1_imm_i = 32'hffff_ffff;
        slot1_is_branch_i = 1'b1; slot1_is_load_i = 1'b1; slot1_is_store_i = 1'b1; slot1_unknown_i = 1'b1;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b1;
        slot1_src_a_sel_i = `CPU_SRC_A_PC; slot1_src_b_sel_i = `CPU_SRC_B_FOUR; slot1_alu_op_i = `CPU_ALU_XOR;
        slot1_alu_result_i = 32'hffff_0000;
        slot1_mem_size_i = 2'b10; slot1_store_data_i = 32'hffff_ffff;
        slot1_exception_i = 1'b1; slot1_excp_ecode_i = `CPU_ECODE_ALE; slot1_excp_esubcode_i = 9'h1ff;
        slot1_excp_badv_valid_i = 1'b1; slot1_excp_badv_i = 32'hffff_0000;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot1 invalid clears outputs",
               !slot1_valid_o && !slot1_unknown_o && !slot1_is_branch_o &&
               !slot1_is_load_o && !slot1_is_store_o);
        `check("S9 slot1 invalid clears issue sideband", !slot1_issue_valid_o);
        `check32("S9 slot1 invalid clears issue class", {28'd0, slot1_issue_class_o}, 32'd0);
        `check("S9 slot1 invalid clears emit event",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);
        `check("S9 slot1 invalid clears LSU ownership", !slot1_mem_lsu_o);
        `check("S9 slot1 invalid clears simple ALU payload",
               !slot1_wb_en_o && !slot1_uses_rs1_o && !slot1_uses_rs2_o &&
               slot1_src_a_sel_o == 2'd0 && slot1_src_b_sel_o == 2'd0 && slot1_alu_op_o == 4'd0);
        `check32("S9 slot1 invalid clears shadow ALU result", slot1_alu_result_o, 32'd0);
        `check32("S9 slot1 invalid clears store size", {30'd0, slot1_mem_size_o}, 32'd0);
        `check32("S9 slot1 invalid clears store data", slot1_store_data_o, 32'd0);
        `check("S9 slot1 invalid clears exception candidate",
               !slot1_exception_o && !slot1_excp_badv_valid_o);
        `check32("S9 slot1 invalid clears exception badv", slot1_excp_badv_o, 32'd0);
        `check32("S9 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S9 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S9 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        slot1_opcode_i = 7'd0; slot1_funct3_i = 3'd0; slot1_funct7_i = 7'd0; slot1_op_19_15_i = 5'd0;
        slot1_rs1_i = 5'd0; slot1_rs2_i = 5'd0; slot1_rd_i = 5'd0; slot1_imm_i = 32'd0;
        slot1_alu_result_i = 32'd0;
        slot1_mem_size_i = 2'd0; slot1_store_data_i = 32'd0;
        slot1_exception_i = 1'b0; slot1_excp_ecode_i = 6'd0; slot1_excp_esubcode_i = 9'd0;
        slot1_excp_badv_valid_i = 1'b0; slot1_excp_badv_i = 32'd0;
        slot1_is_branch_i = 1'b0; slot1_is_jal_i = 1'b0; slot1_is_jalr_i = 1'b0;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_lui_i = 1'b0; slot1_is_auipc_i = 1'b0; slot1_unknown_i = 1'b0; slot1_issue_valid_i = 1'b0;
        slot1_wb_en_i = 1'b0; slot1_uses_rs1_i = 1'b0; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = 2'd0; slot1_src_b_sel_i = 2'd0; slot1_alu_op_i = 4'd0;

        in_valid = 1'b0;
        tick(); #1;
        s10_allowin = 1'b0;
        slot1_valid_i = 1'b1;
        slot1_issue_valid_i = 1'b1;
        slot1_is_load_i = 1'b0; slot1_is_store_i = 1'b0; slot1_is_branch_i = 1'b0;
        slot1_wb_en_i = 1'b1; slot1_uses_rs1_i = 1'b1; slot1_uses_rs2_i = 1'b0;
        slot1_src_a_sel_i = `CPU_SRC_A_RS1; slot1_src_b_sel_i = `CPU_SRC_B_IMM;
        slot1_alu_op_i = `CPU_ALU_ADD;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 slot1 emits but does not fire under S10 backpressure",
               slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'b1000);
        s10_allowin = 1'b1;
        slot1_issue_valid_i = 1'b0;

        is_load_i = 0; is_store_i = 0; wb_en_i = 1; is_csr_i = 1; csr_we_i = 1; csr_xchg_i = 1;
        csr_addr_i = 14'h001; csr_wdata_i = 32'h3; csr_wmask_i = 32'h7; instr_i = 32'h0400_01ad;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CSR sideband pass", out_valid && is_csr_o && csr_we_o && csr_xchg_o && is_csr_raw_o);
        `check32("S9 CSR addr pass", {18'd0, csr_addr_o}, 32'h1);
        `check32("S9 CSR wdata pass", csr_wdata_o, 32'h3);
        `check("S9 CSR does not request DCache", !dcache_req_valid_o);
        exception_i = 1; excp_ecode_i = 6'h09; excp_esubcode_i = 9'h001; excp_badv_valid_i = 1; excp_badv_i = 32'h1d00_0003;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 exception sideband pass", out_valid && exception_o && excp_badv_valid_o);
        `check32("S9 exception ecode pass", {26'd0, excp_ecode_o}, 32'h9);
        `check32("S9 exception badv pass", excp_badv_o, 32'h1d00_0003);
        `check("S9 exception blocks DCache", !dcache_req_valid_o);

        exception_i = 0; is_csr_i = 0; csr_we_i = 0; csr_xchg_i = 0; is_load_i = 1; is_store_i = 0;
        instr_i = 32'h0;
        mem_addr_i = 32'h4000_0080; tlb_found_i = 1'b0; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 load TLB miss raises TLBR", out_valid && exception_o && excp_badv_valid_o);
        `check32("S9 load TLBR ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S9 load TLBR badv", excp_badv_o, 32'h4000_0080);
        `check("S9 load TLBR blocks DCache", !dcache_req_valid_o);

        mem_addr_i = 32'h4000_0084; tlb_found_i = 1'b1; tlb_v_i = 1'b0; tlb_d_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 invalid load page raises PIL", out_valid && exception_o);
        `check32("S9 PIL ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_PIL});

        is_load_i = 1'b0; is_store_i = 1'b1; mem_addr_i = 32'h4000_0088;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 invalid store page raises PIS", out_valid && exception_o);
        `check32("S9 PIS ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_PIS});

        is_load_i = 1'b1; is_store_i = 1'b0; mem_addr_i = 32'h4000_008c;
        csr_crmd_i = 32'h0000_0013; tlb_found_i = 1'b1; tlb_v_i = 1'b1; tlb_d_i = 1'b1; tlb_plv_i = 2'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 PLV violation raises PPI", out_valid && exception_o);
        `check32("S9 PPI ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_PPI});

        is_load_i = 1'b0; is_store_i = 1'b1; mem_addr_i = 32'h4000_0090;
        csr_crmd_i = 32'h0000_0010; tlb_found_i = 1'b1; tlb_v_i = 1'b1; tlb_d_i = 1'b0; tlb_plv_i = 2'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 clean store page raises PME", out_valid && exception_o);
        `check32("S9 PME ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_PME});

        csr_dmw0_i = {3'b100, 1'b0, 3'b001, 19'd0, 2'b00, 1'b0, 2'b00, 1'b1};
        mem_addr_i = 32'h8000_00a0; tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 DMW0 store suppresses TLB exception", out_valid && !exception_o && dcache_req_valid_o);
        `check32("S9 DMW0 paddr", dcache_paddr_o, 32'h2000_00a0);

        is_load_i = 1'b1; is_store_i = 1'b0; wb_en_i = 1'b1;
        mem_addr_i = 32'hbfe0_01e5; csr_crmd_i = 32'h0000_0010;
        csr_dmw0_i = 0; csr_dmw1_i = 0; tlb_found_i = 1'b1; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        tlb_ppn_i = 20'h1fe00; tlb_mat_i = 2'b01;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 MMIO load marks DCache request uncached", out_valid && dcache_req_valid_o &&
                                                            dcache_uncached_o && mem_uncached_o);

        csr_dmw0_i = 0; csr_dmw1_i = 0; csr_crmd_i = 32'h0000_0010;
        is_load_i = 1'b0; is_store_i = 1'b0; wb_en_i = 1'b0; instr_i = la_cacop(5'b00000, 5'd3, 12'h040);
        mem_addr_i = 32'h4000_00c0; tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CACOP mode0 bypasses TLB and DCache request", out_valid && !exception_o && !dcache_req_valid_o);
        `check32("S9 CACOP mode0 direct address", wb_data_pre_o, 32'h4000_00c0);

        instr_i = la_cacop(5'b01001, 5'd3, 12'h040);
        mem_addr_i = 32'h4000_00c4; tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CACOP mode1 bypasses TLB like LA500 direct-index", out_valid && !exception_o && !dcache_req_valid_o);
        `check32("S9 CACOP mode1 direct address", wb_data_pre_o, 32'h4000_00c4);

        instr_i = la_cacop(5'b10000, 5'd3, 12'h040);
        mem_addr_i = 32'h4000_00d0; tlb_found_i = 1'b0; tlb_v_i = 1'b1; tlb_d_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CACOP mode2 TLB miss raises TLBR", out_valid && exception_o && excp_badv_valid_o);
        `check32("S9 CACOP TLBR ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_TLBR});
        `check32("S9 CACOP TLBR badv", excp_badv_o, 32'h4000_00d0);

        instr_i = la_cacop(5'b10001, 5'd3, 12'h040);
        mem_addr_i = 32'h4000_00e0; tlb_found_i = 1'b1; tlb_v_i = 1'b0; tlb_d_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CACOP mode2 invalid page raises PIL", out_valid && exception_o);
        `check32("S9 CACOP PIL ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_PIL});

        instr_i = la_cacop(5'b10001, 5'd3, 12'h040);
        mem_addr_i = 32'h4000_00f0; tlb_found_i = 1'b1; tlb_v_i = 1'b1; tlb_d_i = 1'b0;
        tlb_ppn_i = 20'h12345; tlb_ps_i = 6'd12;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CACOP mode2 translates without DCache request", out_valid && !exception_o && !dcache_req_valid_o);
        `check32("S9 CACOP mode2 translated paddr", wb_data_pre_o, 32'h1234_50f0);

        instr_i = la_cacop(5'b10001, 5'd3, 12'h044);
        csr_dmw0_i = {3'b100, 1'b0, 3'b010, 19'd0, 2'b00, 1'b0, 2'b00, 1'b1};
        mem_addr_i = 32'h8000_0120; tlb_found_i = 1'b0; tlb_v_i = 1'b0; tlb_d_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 CACOP mode2 honors DMW translation", out_valid && !exception_o && !dcache_req_valid_o);
        `check32("S9 CACOP mode2 DMW paddr", wb_data_pre_o, 32'h4000_0120);

        csr_dmw0_i = 0; csr_crmd_i = 32'h0000_0013;
        instr_i = la_cacop(5'b10001, 5'd3, 12'h040);
        mem_addr_i = 32'h4000_0130; tlb_found_i = 1'b1; tlb_v_i = 1'b1; tlb_d_i = 1'b0;
        tlb_ppn_i = 20'h22345; tlb_ps_i = 6'd12; tlb_plv_i = 2'd0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 PLV3 CACOP mode2 is not IPE/PPI in LA500 semantics", out_valid && !exception_o && !dcache_req_valid_o);
        `check32("S9 PLV3 CACOP mode2 translated paddr", wb_data_pre_o, 32'h2234_5130);

        instr_i = la_cacop(5'b00001, 5'd3, 12'h040);
        csr_crmd_i = 32'h0000_0013; mem_addr_i = 32'h4000_0100; tlb_found_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S9 PLV3 CACOP mode0 raises IPE", out_valid && exception_o && !excp_badv_valid_o);
        `check32("S9 CACOP IPE ecode", {26'd0, excp_ecode_o}, {26'd0, `CPU_ECODE_IPE});
        finish_tb();
    end
endmodule
