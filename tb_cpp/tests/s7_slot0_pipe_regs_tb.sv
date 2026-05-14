`timescale 1ns / 1ps

module s7_slot0_pipe_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        capture;
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
    logic [31:0] rs1_s5_val;
    logic [31:0] rs2_s5_val;
    logic        wb_en;
    logic        uses_rs1;
    logic        uses_rs2;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [3:0]  alu_op;
    logic [2:0]  branch_op;
    logic [1:0]  src_a_sel;
    logic [1:0]  src_b_sel;
    logic        unknown_inst;
    logic        branch_redirected;

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
    logic [31:0] rs1_s5_val_o;
    logic [31:0] rs2_s5_val_o;
    logic        wb_en_o;
    logic        uses_rs1_o;
    logic        uses_rs2_o;
    logic        is_branch_o;
    logic        is_jal_o;
    logic        is_jalr_o;
    logic        is_load_o;
    logic        is_store_o;
    logic [1:0]  mem_size_o;
    logic        mem_sign_ext_o;
    logic [3:0]  alu_op_o;
    logic [2:0]  branch_op_o;
    logic [1:0]  src_a_sel_o;
    logic [1:0]  src_b_sel_o;
    logic        unknown_inst_o;
    logic        branch_redirected_o;

    s7_slot0_pipe_regs #(
        .EPOCH_WIDTH(2)
    ) u_dut (
        .clk(clk),
        .capture_i(capture),
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
        .rs1_s5_val_i(rs1_s5_val),
        .rs2_s5_val_i(rs2_s5_val),
        .wb_en_i(wb_en),
        .uses_rs1_i(uses_rs1),
        .uses_rs2_i(uses_rs2),
        .is_branch_i(is_branch),
        .is_jal_i(is_jal),
        .is_jalr_i(is_jalr),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .alu_op_i(alu_op),
        .branch_op_i(branch_op),
        .src_a_sel_i(src_a_sel),
        .src_b_sel_i(src_b_sel),
        .unknown_inst_i(unknown_inst),
        .branch_redirected_i(branch_redirected),
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
        .rs1_s5_val_o(rs1_s5_val_o),
        .rs2_s5_val_o(rs2_s5_val_o),
        .wb_en_o(wb_en_o),
        .uses_rs1_o(uses_rs1_o),
        .uses_rs2_o(uses_rs2_o),
        .is_branch_o(is_branch_o),
        .is_jal_o(is_jal_o),
        .is_jalr_o(is_jalr_o),
        .is_load_o(is_load_o),
        .is_store_o(is_store_o),
        .mem_size_o(mem_size_o),
        .mem_sign_ext_o(mem_sign_ext_o),
        .alu_op_o(alu_op_o),
        .branch_op_o(branch_op_o),
        .src_a_sel_o(src_a_sel_o),
        .src_b_sel_o(src_b_sel_o),
        .unknown_inst_o(unknown_inst_o),
        .branch_redirected_o(branch_redirected_o)
    );

    task automatic drive_payload;
        input [31:0] base;
        begin
            pc = base;
            instr = base ^ 32'h55aa_1200;
            epoch = base[1:0];
            pred_taken = base[2];
            pred_target = base + 32'h80;
            fault = base[3];
            fault_ecode = base[9:4];
            fault_badv = base + 32'h4000_0000;
            rs1 = base[4:0];
            rs2 = base[9:5];
            rd = base[14:10];
            imm = base + 32'h100;
            rs1_s5_val = base + 32'h1000_0001;
            rs2_s5_val = base + 32'h2000_0002;
            wb_en = base[15];
            uses_rs1 = base[16];
            uses_rs2 = base[17];
            is_branch = base[18];
            is_jal = base[19];
            is_jalr = base[20];
            is_load = base[21];
            is_store = base[22];
            mem_size = base[24:23];
            mem_sign_ext = base[25];
            alu_op = base[31:28];
            branch_op = base[30:28];
            src_a_sel = base[27:26];
            src_b_sel = base[29:28];
            unknown_inst = base[26];
            branch_redirected = base[27];
        end
    endtask

    task automatic check_payload;
        input string prefix;
        input [31:0] base;
        begin
            `check32({prefix, " pc"}, pc_o, base);
            `check32({prefix, " instr"}, instr_o, base ^ 32'h55aa_1200);
            `check32({prefix, " epoch/pred/fault"},
                     {28'd0, epoch_o, pred_taken_o, fault_o},
                     {28'd0, base[1:0], base[2], base[3]});
            `check32({prefix, " pred target"}, pred_target_o, base + 32'h80);
            `check32({prefix, " fault ecode"}, {26'd0, fault_ecode_o},
                     {26'd0, base[9:4]});
            `check32({prefix, " fault badv"}, fault_badv_o, base + 32'h4000_0000);
            `check32({prefix, " registers"}, {17'd0, rs1_o, rs2_o, rd_o},
                     {17'd0, base[4:0], base[9:5], base[14:10]});
            `check32({prefix, " imm"}, imm_o, base + 32'h100);
            `check32({prefix, " S5 operand bases"}, rs1_s5_val_o, base + 32'h1000_0001);
            `check32({prefix, " S5 operand bases 2"}, rs2_s5_val_o, base + 32'h2000_0002);
            `check32({prefix, " controls"},
                     {25'd0, wb_en_o, uses_rs1_o, uses_rs2_o,
                      is_branch_o, is_jal_o, is_jalr_o, is_load_o, is_store_o},
                     {25'd0, base[15], base[16], base[17],
                      base[18], base[19], base[20], base[21], base[22]});
            `check32({prefix, " exec selectors"},
                     {20'd0, mem_size_o, mem_sign_ext_o, src_a_sel_o,
                      src_b_sel_o, alu_op_o, branch_op_o},
                     {20'd0, base[24:23], base[25], base[27:26],
                      base[29:28], base[31:28], base[30:28]});
            `check32({prefix, " tail flags"}, {30'd0, unknown_inst_o, branch_redirected_o},
                     {30'd0, base[26], base[27]});
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        drive_payload(32'h1c00_6104);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S7S0REG capture", 32'h1c00_6104);

        capture = 1'b0;
        drive_payload(32'h1c00_8228);
        tick();
        #1;
        check_payload("S7S0REG hold", 32'h1c00_6104);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S7S0REG recapture", 32'h1c00_8228);

        finish_tb();
    end
endmodule
