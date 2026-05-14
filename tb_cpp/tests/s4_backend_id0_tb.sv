`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s4_backend_id0_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    function automatic [31:0] la_addi(input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_addi = {6'h00, 4'ha, imm, rj, rd};
    endfunction
    function automatic [31:0] la_beq(input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_beq = {6'h16, imm, rj, rd};
    endfunction
    function automatic [31:0] la_branch(input [5:0] op31_26, input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_branch = {op31_26, imm, rj, rd};
    endfunction
    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction
    function automatic [31:0] la_b(input [25:0] imm);
        la_b = {6'h14, imm[15:0], imm[25:16]};
    endfunction
    function automatic [31:0] la_bl(input [25:0] imm);
        la_bl = {6'h15, imm[15:0], imm[25:16]};
    endfunction
    function automatic [31:0] la_jirl(input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_jirl = {6'h13, imm, rj, rd};
    endfunction
    function automatic [31:0] la_i12(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_i12 = {6'h00, op25_22, imm, rj, rd};
    endfunction
    function automatic [31:0] la_shift_imm(input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] imm);
        la_shift_imm = {6'h00, 4'h1, 2'h0, op19_15, imm, rj, rd};
    endfunction
    function automatic [31:0] la_alu_3r(input [1:0] op21_20, input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_alu_3r = {6'h00, 4'h0, op21_20, op19_15, rk, rj, rd};
    endfunction
    function automatic [31:0] la_pcaddu12i(input [4:0] rd, input [19:0] imm);
        la_pcaddu12i = {6'h07, 1'b0, imm, rd};
    endfunction
    function automatic [31:0] la_pcaddi(input [4:0] rd, input [19:0] imm);
        la_pcaddi = {6'h06, 1'b0, imm, rd};
    endfunction
    function automatic [31:0] la_csr(input [4:0] rd, input [4:0] rj, input [13:0] csr);
        la_csr = {6'h01, 2'b00, csr, rj, rd};
    endfunction
    function automatic [31:0] la_syscall();
        la_syscall = {6'h00, 4'h0, 2'h2, 5'h16, 15'd0};
    endfunction
    function automatic [31:0] la_break();
        la_break = {6'h00, 4'h0, 2'h2, 5'h14, 15'd0};
    endfunction
    function automatic [31:0] la_rdcntid(input [4:0] rj);
        la_rdcntid = {6'h00, 4'h0, 2'h0, 5'h00, 5'h18, rj, 5'd0};
    endfunction
    function automatic [31:0] la_rdcntvl(input [4:0] rd);
        la_rdcntvl = {6'h00, 4'h0, 2'h0, 5'h00, 5'h18, 5'd0, rd};
    endfunction
    function automatic [31:0] la_rdcntvh(input [4:0] rd);
        la_rdcntvh = {6'h00, 4'h0, 2'h0, 5'h00, 5'h19, 5'd0, rd};
    endfunction
    function automatic [31:0] la_ertn();
        la_ertn = {6'h01, 4'h9, 2'h0, 5'h10, 5'h0e, 5'd0, 5'd0};
    endfunction
    function automatic [31:0] la_tlb_barrier(input [4:0] rk);
        la_tlb_barrier = {6'h01, 4'h9, 2'h0, 5'h10, rk, 5'd0, 5'd0};
    endfunction
    function automatic [31:0] la_invtlb(input [4:0] op, input [4:0] rj, input [4:0] rk);
        la_invtlb = {6'h01, 4'h9, 2'h0, 5'h13, rk, rj, op};
    endfunction
    function automatic [31:0] la_cacop(input [4:0] op, input [4:0] rj, input [11:0] imm);
        la_cacop = {6'h01, 4'h8, imm, rj, op};
    endfunction
    function automatic [31:0] la_special(input [5:0] op31_26, input [3:0] op25_22,
                                          input [1:0] op21_20, input [4:0] op19_15,
                                          input [4:0] rk, input [4:0] rj, input [4:0] rd);
        la_special = {op31_26, op25_22, op21_20, op19_15, rk, rj, rd};
    endfunction
    function automatic [31:0] la_ll_w(input [4:0] rd, input [4:0] rj, input [13:0] imm14);
        la_ll_w = {6'h08, 1'b0, 1'b0, imm14, rj, rd};
    endfunction
    function automatic [31:0] la_sc_w(input [4:0] rd, input [4:0] rj, input [13:0] imm14);
        la_sc_w = {6'h08, 1'b0, 1'b1, imm14, rj, rd};
    endfunction

    logic flush, in_valid, allowin, s5_allowin, out_valid;
    logic pred_taken_i, ras_valid_i, fault_i, slot0_valid_i, slot1_valid_i;
    logic slot0_valid_o, slot1_valid_o;
    logic [1:0] current_epoch_i, epoch_i;
    logic [1:0] epoch_o;
    logic [5:0] fault_ecode_i, fault_ecode_o;
    logic [31:0] pc_i, pc1_i, instr_i, instr1_i, pred_target_i, ras_target_i, fault_badv_i;
    logic [31:0] pc_o, slot1_pc_o, instr_o, instr1_o, pred_target_o, fault_badv_o, imm_o, slot1_imm_o;
    logic [6:0] opcode_o, funct7_o, slot1_opcode_o, slot1_funct7_o;
    logic [2:0] funct3_o, slot1_funct3_o;
    logic [4:0] op_19_15_o, rs1_o, rs2_o, rd_o;
    logic [4:0] slot1_op_19_15_o, slot1_rs1_o, slot1_rs2_o, slot1_rd_o;
    logic pred_taken_o, fault_o, is_branch_o, is_jal_o, is_jalr_o, is_load_o, is_store_o, is_lui_o, is_auipc_o, unknown_o;
    logic slot1_is_branch_o, slot1_is_jal_o, slot1_is_jalr_o, slot1_is_load_o, slot1_is_store_o, slot1_is_lui_o, slot1_is_auipc_o, slot1_unknown_o;
    logic redirect_valid_o;
    logic [31:0] redirect_pc_o;
    logic ras_update_valid_o, ras_update_call_o, ras_update_ret_o;
    logic [31:0] ras_update_pc_o;
    s4_backend_id0 #(.EPOCH_WIDTH(2)) u_dut (
        .clk(clk), .rst_n(rst_n), .flush(flush), .current_epoch_i(current_epoch_i), .s3_to_s4_valid(in_valid),
        .s4_allowin(allowin), .s5_allowin(s5_allowin), .s4_to_s5_valid(out_valid),
        .s3_pc_i(pc_i), .s3_pc1_i(pc1_i), .s3_instr_i(instr_i), .s3_pred_taken_i(pred_taken_i),
        .s3_slot0_valid_i(slot0_valid_i), .s3_instr1_i(instr1_i),
        .s3_slot1_valid_i(slot1_valid_i), .s3_epoch_i(epoch_i),
        .s3_pred_target_i(pred_target_i), .s3_ras_valid_i(ras_valid_i),
        .s3_ras_target_i(ras_target_i), .s3_fault_i(fault_i),
        .s3_fault_ecode_i(fault_ecode_i), .s3_fault_badv_i(fault_badv_i), .s4_pc_o(pc_o),
        .s4_slot0_valid_o(slot0_valid_o), .s4_slot1_pc_o(slot1_pc_o),
        .s4_instr_o(instr_o), .s4_instr1_o(instr1_o), .s4_slot1_valid_o(slot1_valid_o),
        .s4_slot1_opcode_o(slot1_opcode_o), .s4_slot1_funct3_o(slot1_funct3_o),
        .s4_slot1_funct7_o(slot1_funct7_o), .s4_slot1_op_19_15_o(slot1_op_19_15_o),
        .s4_slot1_rs1_o(slot1_rs1_o), .s4_slot1_rs2_o(slot1_rs2_o), .s4_slot1_rd_o(slot1_rd_o),
        .s4_slot1_imm_o(slot1_imm_o), .s4_slot1_is_branch_o(slot1_is_branch_o),
        .s4_slot1_is_jal_o(slot1_is_jal_o), .s4_slot1_is_jalr_o(slot1_is_jalr_o),
        .s4_slot1_is_load_o(slot1_is_load_o), .s4_slot1_is_store_o(slot1_is_store_o),
        .s4_slot1_is_lui_o(slot1_is_lui_o), .s4_slot1_is_auipc_o(slot1_is_auipc_o),
        .s4_slot1_unknown_inst_o(slot1_unknown_o),
        .s4_pred_taken_o(pred_taken_o), .s4_pred_target_o(pred_target_o),
        .s4_epoch_o(epoch_o),
        .s4_fault_o(fault_o), .s4_fault_ecode_o(fault_ecode_o), .s4_fault_badv_o(fault_badv_o),
        .s4_opcode_o(opcode_o), .s4_funct3_o(funct3_o),
        .s4_funct7_o(funct7_o), .s4_op_19_15_o(op_19_15_o), .s4_rs1_o(rs1_o),
        .s4_rs2_o(rs2_o), .s4_rd_o(rd_o), .s4_imm_o(imm_o), .s4_is_branch_o(is_branch_o),
        .s4_is_jal_o(is_jal_o), .s4_is_jalr_o(is_jalr_o), .s4_is_load_o(is_load_o),
        .s4_is_store_o(is_store_o), .s4_is_lui_o(is_lui_o), .s4_is_auipc_o(is_auipc_o),
        .s4_unknown_inst_o(unknown_o),
        .s4_redirect_valid_o(redirect_valid_o), .s4_redirect_pc_o(redirect_pc_o),
        .s4_ras_update_valid_o(ras_update_valid_o), .s4_ras_update_pc_o(ras_update_pc_o),
        .s4_ras_update_is_call_o(ras_update_call_o), .s4_ras_update_is_ret_o(ras_update_ret_o)
    );

    initial begin
        tb_start();
        flush = 0; in_valid = 0; s5_allowin = 1; pc_i = 0; pc1_i = 0; instr_i = 0; pred_taken_i = 0; pred_target_i = 0; ras_valid_i = 0; ras_target_i = 0;
        current_epoch_i = 2'd2; slot0_valid_i = 1'b1; instr1_i = 32'h0; slot1_valid_i = 1'b0; epoch_i = 2'd0;
        fault_i = 0; fault_ecode_i = 0; fault_badv_i = 0;
        reset_dut();
        pc_i = 32'h1c010000; pc1_i = 32'h1c010004; instr_i = la_addi(5'd4, 5'd3, 12'h040);
        instr1_i = la_addi(5'd5, 5'd4, 12'h004); slot1_valid_i = 1'b1; epoch_i = 2'd2;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 valid", out_valid);
        `check32("S4 addi rs1", {27'h0, rs1_o}, 32'd3);
        `check32("S4 addi rd", {27'h0, rd_o}, 32'd4);
        `check32("S4 addi imm", imm_o, 32'h40);
        `check("S4 addi known", !unknown_o);
        `check("S4 packet sideband latched for future dual-slot path",
               u_dut.slot0_valid_r && u_dut.slot1_valid_r &&
               u_dut.pc1_r == 32'h1c010004 &&
               u_dut.instr1_r == la_addi(5'd5, 5'd4, 12'h004) &&
               u_dut.epoch_r == 2'd2);
        `check("S4 packet sideband outputs for future dual-slot path",
               slot0_valid_o && slot1_valid_o &&
               slot1_pc_o == 32'h1c010004 &&
               instr1_o == la_addi(5'd5, 5'd4, 12'h004));
        `check("S4 slot1 addi predecode metadata",
               !slot1_unknown_o && !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check32("S4 slot1 addi rs1", {27'h0, slot1_rs1_o}, 32'd4);
        `check32("S4 slot1 addi rd", {27'h0, slot1_rd_o}, 32'd5);
        `check32("S4 slot1 addi imm", slot1_imm_o, 32'h4);
        `check("S4 epoch output pass", epoch_o == 2'd2);
        instr1_i = 32'h0; slot1_valid_i = 1'b0; epoch_i = 2'd0;

        pc_i = 32'h1c010100; pc1_i = 32'h1c010104;
        instr_i = la_addi(5'd1, 5'd2, 12'h001);
        instr1_i = la_mem(4'h4, 5'd15, 5'd16, 12'h004); slot1_valid_i = 1'b1; epoch_i = 2'd2;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 slot1 store kind exposed", slot1_valid_o && slot1_is_store_o && !slot1_is_load_o);
        `check32("S4 slot1 store rs1", {27'h0, slot1_rs1_o}, 32'd16);
        `check32("S4 slot1 store rs2", {27'h0, slot1_rs2_o}, 32'd15);
        `check32("S4 slot1 store imm", slot1_imm_o, 32'h4);

        instr1_i = la_beq(5'd7, 5'd8, 16'h0004); slot1_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 slot1 branch kind exposed", slot1_valid_o && slot1_is_branch_o && !slot1_is_jal_o);
        `check32("S4 slot1 branch rs1", {27'h0, slot1_rs1_o}, 32'd8);
        `check32("S4 slot1 branch rs2", {27'h0, slot1_rs2_o}, 32'd7);
        `check32("S4 slot1 branch imm", slot1_imm_o, 32'h10);

        instr1_i = 32'hffff_ffff; slot1_valid_i = 1'b1;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 slot1 unknown recognized when valid", slot1_valid_o && slot1_unknown_o);

        instr1_i = la_addi(5'd6, 5'd5, 12'h123); slot1_valid_i = 1'b0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 slot1 invalid clears predecode sideband",
               !slot1_valid_o && !slot1_unknown_o &&
               !slot1_is_branch_o && !slot1_is_load_o && !slot1_is_store_o);
        `check32("S4 slot1 invalid clears rs1", {27'h0, slot1_rs1_o}, 32'd0);
        `check32("S4 slot1 invalid clears rd", {27'h0, slot1_rd_o}, 32'd0);
        `check32("S4 slot1 invalid clears imm", slot1_imm_o, 32'd0);
        pc_i = 32'h1c010000; pc1_i = 32'h1c010004;

        current_epoch_i = 2'd3;
        instr_i = la_b(26'h0000100); pred_taken_i = 1'b0; pred_target_i = 32'h0;
        in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 stale epoch does not emit", !out_valid);
        `check("S4 stale epoch does not early redirect", !redirect_valid_o);
        `check("S4 stale epoch does not update RAS", !ras_update_valid_o);
        current_epoch_i = 2'd2; epoch_i = 2'd2;

        fault_i = 1'b1; fault_ecode_i = `CPU_ECODE_PIF; fault_badv_i = 32'h4000_0000;
        instr_i = la_addi(5'd4, 5'd3, 12'h040); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 fault sideband pass", out_valid && fault_o);
        `check32("S4 fault ecode pass", {26'd0, fault_ecode_o}, {26'd0, `CPU_ECODE_PIF});
        `check32("S4 fault badv pass", fault_badv_o, 32'h4000_0000);
        fault_i = 1'b0; fault_ecode_i = 0; fault_badv_i = 0;

        instr_i = la_i12(4'h8, 5'd7, 5'd6, 12'hfff); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 slti known", !unknown_o);
        `check32("S4 slti sign-extends i12", imm_o, 32'hffff_ffff);
        `check32("S4 slti rs1", {27'h0, rs1_o}, 32'd6);

        instr_i = la_i12(4'hd, 5'd7, 5'd6, 12'hf80); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 andi known", !unknown_o);
        `check32("S4 andi zero-extends ui12", imm_o, 32'h0000_0f80);

        instr_i = la_shift_imm(5'h01, 5'd7, 5'd6, 5'd13); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 slli.w known", !unknown_o);
        `check32("S4 slli.w extracts ui5", imm_o, 32'd13);

        instr_i = la_pcaddu12i(5'd8, 20'h12345); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 pcaddu12i known", !unknown_o);
        `check("S4 pcaddu12i marks AUIPC", is_auipc_o && !is_lui_o);
        `check32("S4 pcaddu12i imm", imm_o, 32'h1234_5000);
        `check32("S4 pcaddu12i rd", {27'h0, rd_o}, 32'd8);

        instr_i = la_pcaddi(5'd9, 20'hfffff); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 pcaddi known", !unknown_o);
        `check("S4 pcaddi marks AUIPC", is_auipc_o && !is_lui_o);
        `check32("S4 pcaddi imm", imm_o, 32'hffff_fffc);
        `check32("S4 pcaddi rd", {27'h0, rd_o}, 32'd9);

        instr_i = la_alu_3r(2'h1, 5'h0c, 5'd10, 5'd11, 5'd12); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 orn known", !unknown_o);
        `check32("S4 orn rs2", {27'h0, rs2_o}, 32'd12);

        instr_i = la_alu_3r(2'h1, 5'h0d, 5'd13, 5'd14, 5'd15); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 andn known", !unknown_o);
        `check32("S4 andn rs2", {27'h0, rs2_o}, 32'd15);

        instr_i = la_alu_3r(2'h1, 5'h18, 5'd9, 5'd10, 5'd11); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 mul.w known", !unknown_o);
        `check32("S4 mul.w rs1", {27'h0, rs1_o}, 32'd10);
        `check32("S4 mul.w rs2", {27'h0, rs2_o}, 32'd11);

        instr_i = la_alu_3r(2'h2, 5'h00, 5'd12, 5'd13, 5'd14); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 div.w known", !unknown_o);
        `check32("S4 div.w rd", {27'h0, rd_o}, 32'd12);

        instr_i = la_csr(5'd12, 5'd0, 14'h000); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 csrrd known", !unknown_o);
        `check32("S4 csrrd rd", {27'h0, rd_o}, 32'd12);

        instr_i = la_csr(5'd13, 5'd1, 14'h006); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 csrwr known", !unknown_o);
        `check32("S4 csrwr rs2 is rd source", {27'h0, rs2_o}, 32'd13);

        instr_i = la_csr(5'd14, 5'd15, 14'h001); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 csrxchg known", !unknown_o);
        `check32("S4 csrxchg rs1 is mask", {27'h0, rs1_o}, 32'd15);
        `check32("S4 csrxchg rs2 is rd source", {27'h0, rs2_o}, 32'd14);

        instr_i = la_syscall(); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 syscall known", !unknown_o);

        instr_i = la_break(); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 break known", !unknown_o);

        instr_i = la_rdcntid(5'd6); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 rdcntid known", !unknown_o);
        `check32("S4 rdcntid destination uses rj", {27'h0, rd_o}, 32'd6);
        instr_i = la_rdcntvl(5'd7); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 rdcntvl known", !unknown_o);
        `check32("S4 rdcntvl destination uses rd", {27'h0, rd_o}, 32'd7);
        instr_i = la_rdcntvh(5'd8); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 rdcntvh known", !unknown_o);
        `check32("S4 rdcntvh destination uses rd", {27'h0, rd_o}, 32'd8);

        instr_i = la_ertn(); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 ertn known", !unknown_o);

        instr_i = la_special(6'h01, 4'h9, 2'h0, 5'h11, 5'd0, 5'd0, 5'd0); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 idle known", !unknown_o);

        instr_i = la_special(6'h0e, 4'h1, 2'h3, 5'h04, 5'd0, 5'd0, 5'd0); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 dbar known", !unknown_o);

        instr_i = la_special(6'h0e, 4'h1, 2'h3, 5'h05, 5'd0, 5'd0, 5'd0); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 ibar known", !unknown_o);

        instr_i = la_tlb_barrier(5'h0a); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 tlbsrch known", !unknown_o);
        instr_i = la_tlb_barrier(5'h0b); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 tlbrd known", !unknown_o);
        instr_i = la_tlb_barrier(5'h0c); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 tlbwr known", !unknown_o);
        instr_i = la_tlb_barrier(5'h0d); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 tlbfill known", !unknown_o);
        instr_i = la_invtlb(5'd5, 5'd12, 5'd13); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 invtlb valid op known", !unknown_o);
        `check32("S4 invtlb rs1 is rj ASID source", {27'h0, rs1_o}, 32'd12);
        `check32("S4 invtlb rs2 is rk VPN source", {27'h0, rs2_o}, 32'd13);
        instr_i = la_invtlb(5'd7, 5'd0, 5'd0); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 invtlb invalid op is unknown", unknown_o);

        instr_i = la_cacop(5'b00000, 5'd6, 12'h040); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 icacop mode0 known", !unknown_o);
        `check32("S4 cacop rs1", {27'h0, rs1_o}, 32'd6);
        `check32("S4 cacop op kept in rd field", {27'h0, rd_o}, 32'd0);
        `check32("S4 cacop signed offset", imm_o, 32'h40);
        instr_i = la_cacop(5'b10001, 5'd7, 12'hffc); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 dcacop mode2 known", !unknown_o);
        `check32("S4 dcacop negative offset", imm_o, 32'hffff_fffc);
        instr_i = la_cacop(5'b00010, 5'd7, 12'h000); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 unsupported CACOP target is nop-known", !unknown_o);
        instr_i = la_cacop(5'b11000, 5'd7, 12'h000); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 unsupported CACOP mode3 is nop-known", !unknown_o);

        instr_i = {6'h0a, 4'hb, 12'hffc, 5'd6, 5'd8}; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 preld known", !unknown_o);
        `check32("S4 preld sign-extends offset", imm_o, 32'hffff_fffc);

        instr_i = la_ll_w(5'd7, 5'd6, 14'h0004); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 ll.w known", !unknown_o);
        `check("S4 ll.w marks load", is_load_o && !is_store_o);
        `check32("S4 ll.w base rs1", {27'h0, rs1_o}, 32'd6);
        `check32("S4 ll.w offset", imm_o, 32'h0000_0010);

        instr_i = la_sc_w(5'd9, 5'd8, 14'h3fff); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 sc.w known", !unknown_o);
        `check("S4 sc.w marks store", is_store_o && !is_load_o);
        `check32("S4 sc.w base rs1", {27'h0, rs1_o}, 32'd8);
        `check32("S4 sc.w negative offset", imm_o, 32'hffff_fffc);

        instr_i = {6'h00, 4'h0, 2'h0, 5'h00, 5'h1b, 5'd4, 5'd3}; in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 cpucfg known", !unknown_o);
        `check32("S4 cpucfg rs1", {27'h0, rs1_o}, 32'd4);
        `check32("S4 cpucfg rd", {27'h0, rd_o}, 32'd3);

        instr_i = la_beq(5'd5, 5'd6, 16'h0004); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 branch", is_branch_o);
        `check32("S4 branch rs2 is rd field", {27'h0, rs2_o}, 32'd5);
        `check32("S4 branch imm", imm_o, 32'h10);

        instr_i = la_branch(6'h18, 5'd9, 5'd10, 16'hfffc); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 blt branch known", is_branch_o && !unknown_o);
        `check32("S4 blt rs1", {27'h0, rs1_o}, 32'd10);
        `check32("S4 blt rs2 is rd field", {27'h0, rs2_o}, 32'd9);
        `check32("S4 blt negative branch imm", imm_o, 32'hffff_fff0);

        instr_i = la_branch(6'h1b, 5'd11, 5'd12, 16'h0008); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 bgeu branch known", is_branch_o && !unknown_o);
        `check32("S4 bgeu rs2 is rd field", {27'h0, rs2_o}, 32'd11);
        `check32("S4 bgeu branch imm", imm_o, 32'h20);

        instr_i = la_mem(4'h0, 5'd13, 5'd14, 12'h003); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 ld.b known load", is_load_o && !is_store_o && !unknown_o);
        `check32("S4 ld.b imm", imm_o, 32'h3);
        instr_i = la_mem(4'h9, 5'd13, 5'd14, 12'hffe); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 ld.hu known load", is_load_o && !is_store_o && !unknown_o);
        `check32("S4 ld.hu sign-extends address imm", imm_o, 32'hffff_fffe);
        instr_i = la_mem(4'h4, 5'd15, 5'd16, 12'h004); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 st.b known store", is_store_o && !is_load_o && !unknown_o);
        `check32("S4 st.b rs2 is rd field", {27'h0, rs2_o}, 32'd15);
        instr_i = la_mem(4'h5, 5'd17, 5'd18, 12'h006); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 st.h known store", is_store_o && !is_load_o && !unknown_o);
        `check32("S4 st.h rs2 is rd field", {27'h0, rs2_o}, 32'd17);

        instr_i = la_b(26'h0000100); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 B as jal path", is_jal_o);
        `check("S4 B early redirect valid", redirect_valid_o);
        `check32("S4 B early redirect pc", redirect_pc_o, 32'h1c010400);
        `check("S4 B marks prediction as taken", pred_taken_o);
        `check32("S4 B forwards corrected pred target", pred_target_o, 32'h1c010400);

        pred_taken_i = 1'b1; pred_target_i = 32'h1c010400;
        instr_i = la_b(26'h0000100); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 predicted B does not re-flush target path", !redirect_valid_o);
        `check("S4 predicted B keeps taken prediction", pred_taken_o);
        `check32("S4 predicted B keeps target", pred_target_o, 32'h1c010400);

        pred_taken_i = 1'b0; pred_target_i = 32'h0; ras_valid_i = 1'b0; ras_target_i = 32'h0;
        instr_i = la_bl(26'h0000200); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 BL requests RAS push", ras_update_valid_o && ras_update_call_o && !ras_update_ret_o);
        `check32("S4 BL RAS update PC", ras_update_pc_o, 32'h1c010000);

        pred_taken_i = 1'b1; pred_target_i = 32'h1c010800;
        instr_i = la_bl(26'h0000200); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 predicted BL does not re-flush target path", !redirect_valid_o);
        `check("S4 predicted BL still requests RAS push", ras_update_valid_o && ras_update_call_o);
        `check32("S4 predicted BL keeps target", pred_target_o, 32'h1c010800);

        pred_taken_i = 1'b0; pred_target_i = 32'h0; ras_valid_i = 1'b1; ras_target_i = 32'h1c020000;
        instr_i = la_jirl(5'd0, 5'd1, 16'd0); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 ret uses RAS early redirect", redirect_valid_o);
        `check32("S4 ret redirect target", redirect_pc_o, 32'h1c020000);
        `check("S4 ret marks prediction as taken", pred_taken_o);
        `check32("S4 ret corrected pred target", pred_target_o, 32'h1c020000);
        `check("S4 ret requests RAS pop", ras_update_valid_o && !ras_update_call_o && ras_update_ret_o);

        pred_taken_i = 1'b1; pred_target_i = 32'h1c020000; ras_valid_i = 1'b1; ras_target_i = 32'h1c020000;
        instr_i = la_jirl(5'd0, 5'd1, 16'd0); in_valid = 1'b1; tick(); in_valid = 1'b0; #1;
        `check("S4 predicted ret does not re-flush target path", !redirect_valid_o);
        `check("S4 predicted ret keeps taken prediction", pred_taken_o);
        `check32("S4 predicted ret keeps target", pred_target_o, 32'h1c020000);
        `check("S4 predicted ret still requests RAS pop", ras_update_valid_o && ras_update_ret_o);
        finish_tb();
    end
endmodule
