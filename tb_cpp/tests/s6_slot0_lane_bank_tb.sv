`timescale 1ns / 1ps

module s6_slot0_lane_bank_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        capture;
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

    logic [4:0]  raw_rs1_o;
    logic [4:0]  raw_rs2_o;
    logic [4:0]  raw_rd_o;
    logic        raw_wb_en_o;
    logic        raw_uses_rs1_o;
    logic        raw_uses_rs2_o;
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

    s6_slot0_lane_bank #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .clk(clk),
        .capture_i(capture),
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
        .raw_rs1_o(raw_rs1_o),
        .raw_rs2_o(raw_rs2_o),
        .raw_rd_o(raw_rd_o),
        .raw_wb_en_o(raw_wb_en_o),
        .raw_uses_rs1_o(raw_uses_rs1_o),
        .raw_uses_rs2_o(raw_uses_rs2_o),
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

    task automatic drive_payload;
        input [31:0] base;
        begin
            pc = base;
            instr = base ^ 32'h0f0f_3300;
            epoch = base[1:0];
            pred_taken = base[2];
            pred_target = base + 32'h40;
            fault = base[3];
            fault_ecode = base[9:4];
            fault_badv = base + 32'h4000_0000;
            rs1 = base[4:0];
            rs2 = base[9:5];
            rd = base[14:10];
            imm = base + 32'h100;
            wb_en = base[15];
            uses_rs1 = base[16];
            uses_rs2 = base[17];
            is_branch = base[18];
            is_jal = base[19];
            is_jalr = base[20];
            is_load = base[21];
            is_store = base[22];
            rs1_val = base + 32'h0100_0001;
            rs2_val = base + 32'h0200_0002;
            mem_size = base[24:23];
            mem_sign_ext = base[25];
            src_a_sel = base[27:26];
            src_b_sel = base[29:28];
            alu_op = base[31:28];
            branch_op = base[30:28];
            unknown_inst = base[26];
            branch_redirected = base[27];
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        issue_valid = 1'b0;
        drive_payload(32'h1c00_4104);

        capture = 1'b1;
        issue_valid = 1'b1;
        tick();
        #1;
        `check("S6S0BANK issue valid after capture", issue_valid_o);
        `check32("S6S0BANK raw regs after capture",
                 {17'd0, raw_rs1_o, raw_rs2_o, raw_rd_o},
                 {17'd0, 5'd4, 5'd8, 5'd16});
        `check("S6S0BANK raw flags after capture",
               raw_wb_en_o == 1'b0 && raw_uses_rs1_o == 1'b0 && raw_uses_rs2_o == 1'b0);
        `check32("S6S0BANK packet pc", pc_o, 32'h1c00_4104);
        `check32("S6S0BANK packet instr", instr_o, 32'h130f_7204);

        issue_valid = 1'b0;
        #1;
        `check("S6S0BANK issue valid is combinational", !issue_valid_o);
        `check32("S6S0BANK packet holds while issue low", pc_o, 32'h1c00_4104);

        capture = 1'b0;
        drive_payload(32'h1c00_5228);
        #1;
        `check32("S6S0BANK raw regs hold when capture low",
                 {17'd0, raw_rs1_o, raw_rs2_o, raw_rd_o},
                 {17'd0, 5'd4, 5'd8, 5'd16});

        capture = 1'b1;
        issue_valid = 1'b1;
        tick();
        #1;
        `check("S6S0BANK issue valid after recapture", issue_valid_o);
        `check32("S6S0BANK raw regs after recapture",
                 {17'd0, raw_rs1_o, raw_rs2_o, raw_rd_o},
                 {17'd0, 5'd8, 5'd17, 5'd20});
        `check("S6S0BANK raw flags after recapture",
               raw_wb_en_o == 1'b0 && raw_uses_rs1_o == 1'b0 && raw_uses_rs2_o == 1'b0);
        `check32("S6S0BANK packet pc recapture", pc_o, 32'h1c00_5228);
        `check32("S6S0BANK packet imm recapture", imm_o, 32'h1c00_5328);

        finish_tb();
    end
endmodule
