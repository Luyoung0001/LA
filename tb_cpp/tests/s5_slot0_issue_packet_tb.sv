`timescale 1ns / 1ps

module s5_slot0_issue_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        issue_valid;
    logic [31:0] pc;
    logic [31:0] instr;
    logic [1:0]  epoch;
    logic        pred_taken;
    logic [31:0] pred_target;
    logic        fault;
    logic [5:0]  fault_ecode;
    logic [31:0] fault_badv;
    logic [4:0]  rs1;
    logic [4:0]  rs2;
    logic [4:0]  rd;
    logic [31:0] imm;
    logic        wb_en;
    logic        uses_rs1;
    logic        uses_rs2;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic [31:0] rs1_val;
    logic [31:0] rs2_val;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [1:0]  src_a_sel;
    logic [1:0]  src_b_sel;
    logic [3:0]  alu_op;
    logic [2:0]  branch_op;
    logic        unknown_inst;
    logic        branch_redirected;

    logic        issue_valid_o;
    logic [31:0] pc_o;
    logic [31:0] instr_o;
    logic [1:0]  epoch_o;
    logic        pred_taken_o;
    logic [31:0] pred_target_o;
    logic        fault_o;
    logic [5:0]  fault_ecode_o;
    logic [31:0] fault_badv_o;
    logic [4:0]  rs1_o;
    logic [4:0]  rs2_o;
    logic [4:0]  rd_o;
    logic [31:0] imm_o;
    logic        wb_en_o;
    logic        uses_rs1_o;
    logic        uses_rs2_o;
    logic        is_branch_o;
    logic        is_jal_o;
    logic        is_jalr_o;
    logic        is_load_o;
    logic        is_store_o;
    logic [31:0] rs1_val_o;
    logic [31:0] rs2_val_o;
    logic [1:0]  mem_size_o;
    logic        mem_sign_ext_o;
    logic [1:0]  src_a_sel_o;
    logic [1:0]  src_b_sel_o;
    logic [3:0]  alu_op_o;
    logic [2:0]  branch_op_o;
    logic        unknown_inst_o;
    logic        branch_redirected_o;

    s5_slot0_issue_packet #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .issue_valid_i(issue_valid),
        .pc_i(pc),
        .instr_i(instr),
        .epoch_i(epoch),
        .pred_taken_i(pred_taken),
        .pred_target_i(pred_target),
        .fault_i(fault),
        .fault_ecode_i(fault_ecode),
        .fault_badv_i(fault_badv),
        .rs1_i(rs1),
        .rs2_i(rs2),
        .rd_i(rd),
        .imm_i(imm),
        .wb_en_i(wb_en),
        .uses_rs1_i(uses_rs1),
        .uses_rs2_i(uses_rs2),
        .is_branch_i(is_branch),
        .is_jal_i(is_jal),
        .is_jalr_i(is_jalr),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .rs1_val_i(rs1_val),
        .rs2_val_i(rs2_val),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .src_a_sel_i(src_a_sel),
        .src_b_sel_i(src_b_sel),
        .alu_op_i(alu_op),
        .branch_op_i(branch_op),
        .unknown_inst_i(unknown_inst),
        .branch_redirected_i(branch_redirected),
        .issue_valid_o(issue_valid_o),
        .pc_o(pc_o),
        .instr_o(instr_o),
        .epoch_o(epoch_o),
        .pred_taken_o(pred_taken_o),
        .pred_target_o(pred_target_o),
        .fault_o(fault_o),
        .fault_ecode_o(fault_ecode_o),
        .fault_badv_o(fault_badv_o),
        .rs1_o(rs1_o),
        .rs2_o(rs2_o),
        .rd_o(rd_o),
        .imm_o(imm_o),
        .wb_en_o(wb_en_o),
        .uses_rs1_o(uses_rs1_o),
        .uses_rs2_o(uses_rs2_o),
        .is_branch_o(is_branch_o),
        .is_jal_o(is_jal_o),
        .is_jalr_o(is_jalr_o),
        .is_load_o(is_load_o),
        .is_store_o(is_store_o),
        .rs1_val_o(rs1_val_o),
        .rs2_val_o(rs2_val_o),
        .mem_size_o(mem_size_o),
        .mem_sign_ext_o(mem_sign_ext_o),
        .src_a_sel_o(src_a_sel_o),
        .src_b_sel_o(src_b_sel_o),
        .alu_op_o(alu_op_o),
        .branch_op_o(branch_op_o),
        .unknown_inst_o(unknown_inst_o),
        .branch_redirected_o(branch_redirected_o)
    );

    task automatic drive_payload(input logic valid);
        begin
            issue_valid = valid;
            pc = 32'h1c00_2000;
            instr = 32'h0280_0421;
            epoch = 2'd2;
            pred_taken = 1'b1;
            pred_target = 32'h1c00_2040;
            fault = 1'b1;
            fault_ecode = 6'h12;
            fault_badv = 32'h1c00_2000;
            rs1 = 5'd3;
            rs2 = 5'd4;
            rd = 5'd5;
            imm = 32'hffff_fffc;
            wb_en = 1'b1;
            uses_rs1 = 1'b1;
            uses_rs2 = 1'b0;
            is_branch = 1'b1;
            is_jal = 1'b0;
            is_jalr = 1'b0;
            is_load = 1'b0;
            is_store = 1'b0;
            rs1_val = 32'h1111_2222;
            rs2_val = 32'h3333_4444;
            mem_size = 2'b10;
            mem_sign_ext = 1'b0;
            src_a_sel = 2'd1;
            src_b_sel = 2'd2;
            alu_op = 4'h7;
            branch_op = 3'h4;
            unknown_inst = 1'b0;
            branch_redirected = 1'b1;
        end
    endtask

    task automatic check_payload(input string prefix, input logic valid);
        begin
            `check({prefix, " issue valid"}, issue_valid_o == valid);
            `check32({prefix, " pc"}, pc_o, 32'h1c00_2000);
            `check32({prefix, " instr"}, instr_o, 32'h0280_0421);
            `check32({prefix, " epoch/pred"}, {28'd0, epoch_o, pred_taken_o, fault_o},
                     {28'd0, 2'd2, 1'b1, 1'b1});
            `check32({prefix, " pred target"}, pred_target_o, 32'h1c00_2040);
            `check32({prefix, " fault bundle"}, {18'd0, fault_ecode_o, fault_badv_o[7:0]},
                     {18'd0, 6'h12, 8'h00});
            `check32({prefix, " registers"}, {17'd0, rs1_o, rs2_o, rd_o},
                     {17'd0, 5'd3, 5'd4, 5'd5});
            `check32({prefix, " imm"}, imm_o, 32'hffff_fffc);
            `check({prefix, " controls"},
                   wb_en_o && uses_rs1_o && !uses_rs2_o && is_branch_o &&
                   !is_jal_o && !is_jalr_o && !is_load_o && !is_store_o);
            `check32({prefix, " rs values"}, rs1_val_o ^ rs2_val_o,
                     32'h2222_6666);
            `check32({prefix, " exec selectors"},
                     {20'd0, mem_size_o, mem_sign_ext_o, src_a_sel_o, src_b_sel_o, alu_op_o, branch_op_o},
                     {20'd0, 2'b10, 1'b0, 2'd1, 2'd2, 4'h7, 3'h4});
            `check({prefix, " tail flags"}, !unknown_inst_o && branch_redirected_o);
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        drive_payload(1'b0);
        #1;
        check_payload("PKT invalid", 1'b0);

        drive_payload(1'b1);
        #1;
        check_payload("PKT valid", 1'b1);

        finish_tb();
    end
endmodule
