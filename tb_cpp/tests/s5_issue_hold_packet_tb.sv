`timescale 1ns / 1ps

module s5_issue_hold_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic push;
    logic [31:0] pc;
    logic [31:0] instr;
    logic [0:0]  epoch;
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

    logic [31:0] hold_pc;
    logic [31:0] hold_instr;
    logic [0:0]  hold_epoch;
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
    logic [31:0] hold_slot1_pc;
    logic [31:0] hold_instr1;
    logic        hold_slot1_valid;
    logic [6:0]  hold_slot1_opcode;
    logic [2:0]  hold_slot1_funct3;
    logic [6:0]  hold_slot1_funct7;
    logic [4:0]  hold_slot1_op_19_15;
    logic [4:0]  hold_slot1_rs1;
    logic [4:0]  hold_slot1_rs2;
    logic [4:0]  hold_slot1_rd;
    logic [31:0] hold_slot1_imm;
    logic        hold_slot1_is_branch;
    logic        hold_slot1_is_jal;
    logic        hold_slot1_is_jalr;
    logic        hold_slot1_is_load;
    logic        hold_slot1_is_store;
    logic        hold_slot1_is_lui;
    logic        hold_slot1_is_auipc;
    logic        hold_slot1_unknown_inst;

    s5_issue_hold_packet #(
        .XLEN(32),
        .ILEN(32),
        .EPOCH_WIDTH(1)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .push_i(push),
        .push_pc_i(pc),
        .push_instr_i(instr),
        .push_epoch_i(epoch),
        .push_pred_taken_i(pred_taken),
        .push_pred_target_i(pred_target),
        .push_fault_i(fault),
        .push_fault_ecode_i(fault_ecode),
        .push_fault_badv_i(fault_badv),
        .push_opcode_i(opcode),
        .push_funct3_i(funct3),
        .push_funct7_i(funct7),
        .push_op_19_15_i(op_19_15),
        .push_rs1_i(rs1),
        .push_rs2_i(rs2),
        .push_rd_i(rd),
        .push_imm_i(imm),
        .push_is_branch_i(is_branch),
        .push_is_jal_i(is_jal),
        .push_is_jalr_i(is_jalr),
        .push_is_load_i(is_load),
        .push_is_store_i(is_store),
        .push_is_lui_i(is_lui),
        .push_is_auipc_i(is_auipc),
        .push_unknown_inst_i(unknown_inst),
        .push_slot1_pc_i(slot1_pc),
        .push_instr1_i(instr1),
        .push_slot1_valid_i(slot1_valid),
        .push_slot1_opcode_i(slot1_opcode),
        .push_slot1_funct3_i(slot1_funct3),
        .push_slot1_funct7_i(slot1_funct7),
        .push_slot1_op_19_15_i(slot1_op_19_15),
        .push_slot1_rs1_i(slot1_rs1),
        .push_slot1_rs2_i(slot1_rs2),
        .push_slot1_rd_i(slot1_rd),
        .push_slot1_imm_i(slot1_imm),
        .push_slot1_is_branch_i(slot1_is_branch),
        .push_slot1_is_jal_i(slot1_is_jal),
        .push_slot1_is_jalr_i(slot1_is_jalr),
        .push_slot1_is_load_i(slot1_is_load),
        .push_slot1_is_store_i(slot1_is_store),
        .push_slot1_is_lui_i(slot1_is_lui),
        .push_slot1_is_auipc_i(slot1_is_auipc),
        .push_slot1_unknown_inst_i(slot1_unknown_inst),
        .hold_pc_o(hold_pc),
        .hold_instr_o(hold_instr),
        .hold_epoch_o(hold_epoch),
        .hold_pred_taken_o(hold_pred_taken),
        .hold_pred_target_o(hold_pred_target),
        .hold_fault_o(hold_fault),
        .hold_fault_ecode_o(hold_fault_ecode),
        .hold_fault_badv_o(hold_fault_badv),
        .hold_opcode_o(hold_opcode),
        .hold_funct3_o(hold_funct3),
        .hold_funct7_o(hold_funct7),
        .hold_op_19_15_o(hold_op_19_15),
        .hold_rs1_o(hold_rs1),
        .hold_rs2_o(hold_rs2),
        .hold_rd_o(hold_rd),
        .hold_imm_o(hold_imm),
        .hold_is_branch_o(hold_is_branch),
        .hold_is_jal_o(hold_is_jal),
        .hold_is_jalr_o(hold_is_jalr),
        .hold_is_load_o(hold_is_load),
        .hold_is_store_o(hold_is_store),
        .hold_is_lui_o(hold_is_lui),
        .hold_is_auipc_o(hold_is_auipc),
        .hold_unknown_inst_o(hold_unknown_inst),
        .hold_slot1_pc_o(hold_slot1_pc),
        .hold_instr1_o(hold_instr1),
        .hold_slot1_valid_o(hold_slot1_valid),
        .hold_slot1_opcode_o(hold_slot1_opcode),
        .hold_slot1_funct3_o(hold_slot1_funct3),
        .hold_slot1_funct7_o(hold_slot1_funct7),
        .hold_slot1_op_19_15_o(hold_slot1_op_19_15),
        .hold_slot1_rs1_o(hold_slot1_rs1),
        .hold_slot1_rs2_o(hold_slot1_rs2),
        .hold_slot1_rd_o(hold_slot1_rd),
        .hold_slot1_imm_o(hold_slot1_imm),
        .hold_slot1_is_branch_o(hold_slot1_is_branch),
        .hold_slot1_is_jal_o(hold_slot1_is_jal),
        .hold_slot1_is_jalr_o(hold_slot1_is_jalr),
        .hold_slot1_is_load_o(hold_slot1_is_load),
        .hold_slot1_is_store_o(hold_slot1_is_store),
        .hold_slot1_is_lui_o(hold_slot1_is_lui),
        .hold_slot1_is_auipc_o(hold_slot1_is_auipc),
        .hold_slot1_unknown_inst_o(hold_slot1_unknown_inst)
    );

    task automatic drive_packet;
        input [31:0] base_pc;
        begin
            pc = base_pc;
            instr = 32'h0280_0401;
            epoch = 1'b1;
            pred_taken = 1'b1;
            pred_target = base_pc + 32'h40;
            fault = 1'b1;
            fault_ecode = 6'h17;
            fault_badv = base_pc + 32'h4;
            opcode = 7'h21;
            funct3 = 3'h4;
            funct7 = 7'h55;
            op_19_15 = 5'h12;
            rs1 = 5'd3;
            rs2 = 5'd4;
            rd = 5'd5;
            imm = 32'hffff_00aa;
            is_branch = 1'b1;
            is_jal = 1'b0;
            is_jalr = 1'b1;
            is_load = 1'b0;
            is_store = 1'b1;
            is_lui = 1'b0;
            is_auipc = 1'b1;
            unknown_inst = 1'b0;
            slot1_pc = base_pc + 32'h4;
            instr1 = 32'h0280_0802;
            slot1_valid = 1'b1;
            slot1_opcode = 7'h22;
            slot1_funct3 = 3'h5;
            slot1_funct7 = 7'h56;
            slot1_op_19_15 = 5'h13;
            slot1_rs1 = 5'd6;
            slot1_rs2 = 5'd7;
            slot1_rd = 5'd8;
            slot1_imm = 32'h0000_0bb0;
            slot1_is_branch = 1'b0;
            slot1_is_jal = 1'b1;
            slot1_is_jalr = 1'b0;
            slot1_is_load = 1'b1;
            slot1_is_store = 1'b0;
            slot1_is_lui = 1'b1;
            slot1_is_auipc = 1'b0;
            slot1_unknown_inst = 1'b1;
        end
    endtask

    initial begin
        tb_start();
        flush = 1'b0;
        push = 1'b0;
        drive_packet(32'h1c00_1000);
        reset_dut();

        `check32("HOLD reset clears pc", hold_pc, 32'd0);
        `check("HOLD reset clears flags",
               !hold_pred_taken && !hold_fault && !hold_slot1_valid);

        push = 1'b1;
        tick();
        push = 1'b0;
        `check32("HOLD captures slot0 pc", hold_pc, 32'h1c00_1000);
        `check32("HOLD captures slot0 instr", hold_instr, instr);
        `check("HOLD captures slot0 control",
               hold_epoch == 1'b1 && hold_pred_taken && hold_fault &&
               hold_fault_ecode == 6'h17 && hold_opcode == 7'h21 &&
               hold_rs1 == 5'd3 && hold_rs2 == 5'd4 && hold_rd == 5'd5 &&
               hold_is_branch && hold_is_jalr && hold_is_store &&
               hold_is_auipc);
        `check32("HOLD captures slot1 pc", hold_slot1_pc, 32'h1c00_1004);
        `check("HOLD captures slot1 control",
               hold_slot1_valid && hold_slot1_opcode == 7'h22 &&
               hold_slot1_rs1 == 5'd6 && hold_slot1_rs2 == 5'd7 &&
               hold_slot1_rd == 5'd8 && hold_slot1_is_jal &&
               hold_slot1_is_load && hold_slot1_is_lui &&
               hold_slot1_unknown_inst);

        drive_packet(32'h1c00_2000);
        tick();
        `check32("HOLD keeps payload when push is low", hold_pc, 32'h1c00_1000);

        flush = 1'b1;
        tick();
        flush = 1'b0;
        `check32("HOLD flush clears pc", hold_pc, 32'd0);
        `check("HOLD flush clears slot flags",
               !hold_slot1_valid && !hold_is_branch && !hold_unknown_inst);

        finish_tb();
    end
endmodule
