`timescale 1ns / 1ps

module s5_slot0_source_select_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        load_promote;
    logic [31:0] promote_pc;
    logic [31:0] promote_instr;
    logic        promote_pred_taken;
    logic [31:0] promote_pred_target;
    logic        promote_fault;
    logic [5:0]  promote_fault_ecode;
    logic [31:0] promote_fault_badv;
    logic [6:0]  promote_opcode;
    logic [2:0]  promote_funct3;
    logic [6:0]  promote_funct7;
    logic [4:0]  promote_op_19_15;
    logic [4:0]  promote_rs1;
    logic [4:0]  promote_rs2;
    logic [4:0]  promote_rd;
    logic [31:0] promote_imm;
    logic        promote_is_branch;
    logic        promote_is_jal;
    logic        promote_is_jalr;
    logic        promote_is_load;
    logic        promote_is_store;
    logic        promote_is_lui;
    logic        promote_is_auipc;
    logic        promote_unknown_inst;
    logic [31:0] promote_rf1_base;
    logic [31:0] promote_rf2_base;

    logic        load_hold;
    logic [31:0] hold_pc;
    logic [31:0] hold_instr;
    logic [1:0]  hold_epoch;
    logic        hold_pred_taken;
    logic [31:0] hold_pred_target;
    logic        hold_fault;
    logic [5:0]  hold_fault_ecode;
    logic [31:0] hold_fault_badv;
    logic [6:0]  hold_opcode;
    logic [2:0]  hold_funct3;
    logic [6:0]  hold_funct7;
    logic [4:0]  hold_op_19_15;
    logic [4:0]  hold_rs1;
    logic [4:0]  hold_rs2;
    logic [4:0]  hold_rd;
    logic [31:0] hold_imm;
    logic        hold_is_branch;
    logic        hold_is_jal;
    logic        hold_is_jalr;
    logic        hold_is_load;
    logic        hold_is_store;
    logic        hold_is_lui;
    logic        hold_is_auipc;
    logic        hold_unknown_inst;
    logic [31:0] hold_rf1_base;
    logic [31:0] hold_rf2_base;

    logic        load_s4;
    logic [31:0] s4_pc;
    logic [31:0] s4_instr;
    logic [1:0]  s4_epoch;
    logic        s4_pred_taken;
    logic [31:0] s4_pred_target;
    logic        s4_fault;
    logic [5:0]  s4_fault_ecode;
    logic [31:0] s4_fault_badv;
    logic [6:0]  s4_opcode;
    logic [2:0]  s4_funct3;
    logic [6:0]  s4_funct7;
    logic [4:0]  s4_op_19_15;
    logic [4:0]  s4_rs1;
    logic [4:0]  s4_rs2;
    logic [4:0]  s4_rd;
    logic [31:0] s4_imm;
    logic        s4_is_branch;
    logic        s4_is_jal;
    logic        s4_is_jalr;
    logic        s4_is_load;
    logic        s4_is_store;
    logic        s4_is_lui;
    logic        s4_is_auipc;
    logic        s4_unknown_inst;
    logic [31:0] s4_rf1_base;
    logic [31:0] s4_rf2_base;

    logic        load;
    logic        epoch_we;
    logic [31:0] pc;
    logic [31:0] instr;
    logic [1:0]  epoch;
    logic        pred_taken;
    logic [31:0] pred_target;
    logic        fault;
    logic [5:0]  fault_ecode;
    logic [31:0] fault_badv;
    logic [6:0]  opcode;
    logic [2:0]  funct3;
    logic [6:0]  funct7;
    logic [4:0]  op_19_15;
    logic [4:0]  rs1;
    logic [4:0]  rs2;
    logic [4:0]  rd;
    logic [31:0] imm;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic        is_lui;
    logic        is_auipc;
    logic        unknown_inst;
    logic [31:0] rf1_base;
    logic [31:0] rf2_base;
    logic        rf_base_ready;

    s5_slot0_source_select #(
        .XLEN(32),
        .ILEN(32),
        .EPOCH_WIDTH(2)
    ) u_dut (
        .load_promote_i(load_promote),
        .promote_pc_i(promote_pc),
        .promote_instr_i(promote_instr),
        .promote_pred_taken_i(promote_pred_taken),
        .promote_pred_target_i(promote_pred_target),
        .promote_fault_i(promote_fault),
        .promote_fault_ecode_i(promote_fault_ecode),
        .promote_fault_badv_i(promote_fault_badv),
        .promote_opcode_i(promote_opcode),
        .promote_funct3_i(promote_funct3),
        .promote_funct7_i(promote_funct7),
        .promote_op_19_15_i(promote_op_19_15),
        .promote_rs1_i(promote_rs1),
        .promote_rs2_i(promote_rs2),
        .promote_rd_i(promote_rd),
        .promote_imm_i(promote_imm),
        .promote_is_branch_i(promote_is_branch),
        .promote_is_jal_i(promote_is_jal),
        .promote_is_jalr_i(promote_is_jalr),
        .promote_is_load_i(promote_is_load),
        .promote_is_store_i(promote_is_store),
        .promote_is_lui_i(promote_is_lui),
        .promote_is_auipc_i(promote_is_auipc),
        .promote_unknown_inst_i(promote_unknown_inst),
        .promote_rf1_base_i(promote_rf1_base),
        .promote_rf2_base_i(promote_rf2_base),
        .load_hold_i(load_hold),
        .hold_pc_i(hold_pc),
        .hold_instr_i(hold_instr),
        .hold_epoch_i(hold_epoch),
        .hold_pred_taken_i(hold_pred_taken),
        .hold_pred_target_i(hold_pred_target),
        .hold_fault_i(hold_fault),
        .hold_fault_ecode_i(hold_fault_ecode),
        .hold_fault_badv_i(hold_fault_badv),
        .hold_opcode_i(hold_opcode),
        .hold_funct3_i(hold_funct3),
        .hold_funct7_i(hold_funct7),
        .hold_op_19_15_i(hold_op_19_15),
        .hold_rs1_i(hold_rs1),
        .hold_rs2_i(hold_rs2),
        .hold_rd_i(hold_rd),
        .hold_imm_i(hold_imm),
        .hold_is_branch_i(hold_is_branch),
        .hold_is_jal_i(hold_is_jal),
        .hold_is_jalr_i(hold_is_jalr),
        .hold_is_load_i(hold_is_load),
        .hold_is_store_i(hold_is_store),
        .hold_is_lui_i(hold_is_lui),
        .hold_is_auipc_i(hold_is_auipc),
        .hold_unknown_inst_i(hold_unknown_inst),
        .hold_rf1_base_i(hold_rf1_base),
        .hold_rf2_base_i(hold_rf2_base),
        .load_s4_i(load_s4),
        .s4_pc_i(s4_pc),
        .s4_instr_i(s4_instr),
        .s4_epoch_i(s4_epoch),
        .s4_pred_taken_i(s4_pred_taken),
        .s4_pred_target_i(s4_pred_target),
        .s4_fault_i(s4_fault),
        .s4_fault_ecode_i(s4_fault_ecode),
        .s4_fault_badv_i(s4_fault_badv),
        .s4_opcode_i(s4_opcode),
        .s4_funct3_i(s4_funct3),
        .s4_funct7_i(s4_funct7),
        .s4_op_19_15_i(s4_op_19_15),
        .s4_rs1_i(s4_rs1),
        .s4_rs2_i(s4_rs2),
        .s4_rd_i(s4_rd),
        .s4_imm_i(s4_imm),
        .s4_is_branch_i(s4_is_branch),
        .s4_is_jal_i(s4_is_jal),
        .s4_is_jalr_i(s4_is_jalr),
        .s4_is_load_i(s4_is_load),
        .s4_is_store_i(s4_is_store),
        .s4_is_lui_i(s4_is_lui),
        .s4_is_auipc_i(s4_is_auipc),
        .s4_unknown_inst_i(s4_unknown_inst),
        .s4_rf1_base_i(s4_rf1_base),
        .s4_rf2_base_i(s4_rf2_base),
        .load_o(load),
        .epoch_we_o(epoch_we),
        .pc_o(pc),
        .instr_o(instr),
        .epoch_o(epoch),
        .pred_taken_o(pred_taken),
        .pred_target_o(pred_target),
        .fault_o(fault),
        .fault_ecode_o(fault_ecode),
        .fault_badv_o(fault_badv),
        .opcode_o(opcode),
        .funct3_o(funct3),
        .funct7_o(funct7),
        .op_19_15_o(op_19_15),
        .rs1_o(rs1),
        .rs2_o(rs2),
        .rd_o(rd),
        .imm_o(imm),
        .is_branch_o(is_branch),
        .is_jal_o(is_jal),
        .is_jalr_o(is_jalr),
        .is_load_o(is_load),
        .is_store_o(is_store),
        .is_lui_o(is_lui),
        .is_auipc_o(is_auipc),
        .unknown_inst_o(unknown_inst),
        .rf1_base_o(rf1_base),
        .rf2_base_o(rf2_base),
        .rf_base_ready_o(rf_base_ready)
    );

    initial begin
        tb_start();

        load_promote = 1'b0;
        promote_pc = 32'h1c00_1004;
        promote_instr = 32'h1004_aaaa;
        promote_pred_taken = 1'b1;
        promote_pred_target = 32'h1c00_1088;
        promote_fault = 1'b1;
        promote_fault_ecode = 6'h12;
        promote_fault_badv = 32'h1c00_1004;
        promote_opcode = 7'h11;
        promote_funct3 = 3'h2;
        promote_funct7 = 7'h35;
        promote_op_19_15 = 5'h14;
        promote_rs1 = 5'd1;
        promote_rs2 = 5'd2;
        promote_rd = 5'd3;
        promote_imm = 32'h0000_0104;
        promote_is_branch = 1'b1;
        promote_is_jal = 1'b0;
        promote_is_jalr = 1'b1;
        promote_is_load = 1'b0;
        promote_is_store = 1'b1;
        promote_is_lui = 1'b0;
        promote_is_auipc = 1'b1;
        promote_unknown_inst = 1'b1;
        promote_rf1_base = 32'h1111_0001;
        promote_rf2_base = 32'h2222_0002;

        load_hold = 1'b0;
        hold_pc = 32'h1c00_2008;
        hold_instr = 32'h2008_bbbb;
        hold_epoch = 2'd2;
        hold_pred_taken = 1'b0;
        hold_pred_target = 32'h1c00_20cc;
        hold_fault = 1'b1;
        hold_fault_ecode = 6'h21;
        hold_fault_badv = 32'h1c00_2058;
        hold_opcode = 7'h22;
        hold_funct3 = 3'h3;
        hold_funct7 = 7'h46;
        hold_op_19_15 = 5'h0f;
        hold_rs1 = 5'd4;
        hold_rs2 = 5'd5;
        hold_rd = 5'd6;
        hold_imm = 32'h0000_0208;
        hold_is_branch = 1'b0;
        hold_is_jal = 1'b1;
        hold_is_jalr = 1'b0;
        hold_is_load = 1'b1;
        hold_is_store = 1'b0;
        hold_is_lui = 1'b1;
        hold_is_auipc = 1'b0;
        hold_unknown_inst = 1'b0;
        hold_rf1_base = 32'h3333_0003;
        hold_rf2_base = 32'h4444_0004;

        load_s4 = 1'b0;
        s4_pc = 32'h1c00_300c;
        s4_instr = 32'h300c_cccc;
        s4_epoch = 2'd3;
        s4_pred_taken = 1'b1;
        s4_pred_target = 32'h1c00_30dd;
        s4_fault = 1'b0;
        s4_fault_ecode = 6'h2d;
        s4_fault_badv = 32'h1c00_3068;
        s4_opcode = 7'h33;
        s4_funct3 = 3'h4;
        s4_funct7 = 7'h57;
        s4_op_19_15 = 5'h1a;
        s4_rs1 = 5'd7;
        s4_rs2 = 5'd8;
        s4_rd = 5'd9;
        s4_imm = 32'h0000_030c;
        s4_is_branch = 1'b1;
        s4_is_jal = 1'b1;
        s4_is_jalr = 1'b0;
        s4_is_load = 1'b1;
        s4_is_store = 1'b1;
        s4_is_lui = 1'b0;
        s4_is_auipc = 1'b1;
        s4_unknown_inst = 1'b0;
        s4_rf1_base = 32'h5555_0005;
        s4_rf2_base = 32'h6666_0006;
        #1;

        `check("SRCSEL idle has no load", !load && !epoch_we && !rf_base_ready);
        `check32("SRCSEL idle clears payload pc", pc, 32'd0);

        load_s4 = 1'b1;
        #1;
        `check("SRCSEL S4 selects load/epoch and waits RF", load && epoch_we && !rf_base_ready);
        `check32("SRCSEL S4 pc", pc, s4_pc);
        `check32("SRCSEL S4 epoch", {30'd0, epoch}, 32'd3);
        `check32("SRCSEL S4 rf1", rf1_base, s4_rf1_base);

        load_s4 = 1'b0;
        load_hold = 1'b1;
        #1;
        `check("SRCSEL hold selects ready packet", load && epoch_we && rf_base_ready);
        `check32("SRCSEL hold pc", pc, hold_pc);
        `check32("SRCSEL hold epoch", {30'd0, epoch}, 32'd2);
        `check32("SRCSEL hold rf2", rf2_base, hold_rf2_base);

        load_promote = 1'b1;
        #1;
        `check("SRCSEL promote wins priority and keeps epoch", load && !epoch_we && rf_base_ready);
        `check32("SRCSEL promote pc", pc, promote_pc);
        `check32("SRCSEL promote pred target", pred_target, promote_pred_target);
        `check("SRCSEL promote flags", is_branch && is_jalr && is_store &&
               is_auipc && unknown_inst);

        finish_tb();
    end
endmodule
