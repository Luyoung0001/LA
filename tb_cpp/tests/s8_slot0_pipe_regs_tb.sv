`timescale 1ns / 1ps

module s8_slot0_pipe_regs_tb;
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
    logic [4:0]  rd;
    logic [31:0] imm;
    logic        wb_en;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [3:0]  alu_op;
    logic [2:0]  branch_op;
    logic        unknown_inst;
    logic        branch_redirected;
    logic [31:0] op_a;
    logic [31:0] op_b;
    logic [31:0] rs1_val;
    logic [31:0] rs2_val;
    logic        op_a_late_s10;
    logic        op_b_late_s10;
    logic        rs1_late_s10;
    logic        rs2_late_s10;
    logic [4:0]  late_s10_rd;

    logic [31:0] pc_o;
    logic [31:0] instr_o;
    logic [1:0]  epoch_o;
    logic        pred_taken_o;
    logic [31:0] pred_target_o;
    logic        fault_o;
    logic [5:0]  fault_ecode_o;
    logic [31:0] fault_badv_o;
    logic [4:0]  rd_o;
    logic [31:0] imm_o;
    logic        wb_en_o;
    logic        is_branch_o;
    logic        is_jal_o;
    logic        is_jalr_o;
    logic        is_load_o;
    logic        is_store_o;
    logic [1:0]  mem_size_o;
    logic        mem_sign_ext_o;
    logic [3:0]  alu_op_o;
    logic [2:0]  branch_op_o;
    logic        unknown_inst_o;
    logic        branch_redirected_o;
    logic [31:0] op_a_o;
    logic [31:0] op_b_o;
    logic [31:0] rs1_val_o;
    logic [31:0] rs2_val_o;
    logic        op_a_late_s10_o;
    logic        op_b_late_s10_o;
    logic        rs1_late_s10_o;
    logic        rs2_late_s10_o;
    logic [4:0]  late_s10_rd_o;

    s8_slot0_pipe_regs #(
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
        .rd_i(rd),
        .imm_i(imm),
        .wb_en_i(wb_en),
        .is_branch_i(is_branch),
        .is_jal_i(is_jal),
        .is_jalr_i(is_jalr),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .mem_size_i(mem_size),
        .mem_sign_ext_i(mem_sign_ext),
        .alu_op_i(alu_op),
        .branch_op_i(branch_op),
        .unknown_inst_i(unknown_inst),
        .branch_redirected_i(branch_redirected),
        .op_a_i(op_a),
        .op_b_i(op_b),
        .rs1_val_i(rs1_val),
        .rs2_val_i(rs2_val),
        .op_a_late_s10_i(op_a_late_s10),
        .op_b_late_s10_i(op_b_late_s10),
        .rs1_late_s10_i(rs1_late_s10),
        .rs2_late_s10_i(rs2_late_s10),
        .late_s10_rd_i(late_s10_rd),
        .pc_o(pc_o),
        .instr_o(instr_o),
        .epoch_o(epoch_o),
        .pred_taken_o(pred_taken_o),
        .pred_target_o(pred_target_o),
        .fault_o(fault_o),
        .fault_ecode_o(fault_ecode_o),
        .fault_badv_o(fault_badv_o),
        .rd_o(rd_o),
        .imm_o(imm_o),
        .wb_en_o(wb_en_o),
        .is_branch_o(is_branch_o),
        .is_jal_o(is_jal_o),
        .is_jalr_o(is_jalr_o),
        .is_load_o(is_load_o),
        .is_store_o(is_store_o),
        .mem_size_o(mem_size_o),
        .mem_sign_ext_o(mem_sign_ext_o),
        .alu_op_o(alu_op_o),
        .branch_op_o(branch_op_o),
        .unknown_inst_o(unknown_inst_o),
        .branch_redirected_o(branch_redirected_o),
        .op_a_o(op_a_o),
        .op_b_o(op_b_o),
        .rs1_val_o(rs1_val_o),
        .rs2_val_o(rs2_val_o),
        .op_a_late_s10_o(op_a_late_s10_o),
        .op_b_late_s10_o(op_b_late_s10_o),
        .rs1_late_s10_o(rs1_late_s10_o),
        .rs2_late_s10_o(rs2_late_s10_o),
        .late_s10_rd_o(late_s10_rd_o)
    );

    task automatic drive_payload;
        input [31:0] base;
        begin
            pc = base;
            instr = base ^ 32'ha5a5_1700;
            epoch = base[1:0];
            pred_taken = base[2];
            pred_target = base + 32'hc0;
            fault = base[3];
            fault_ecode = base[9:4];
            fault_badv = base + 32'h4000_0000;
            rd = base[14:10];
            imm = base + 32'h100;
            wb_en = base[15];
            is_branch = base[16];
            is_jal = base[17];
            is_jalr = base[18];
            is_load = base[19];
            is_store = base[20];
            mem_size = base[22:21];
            mem_sign_ext = base[23];
            alu_op = base[31:28];
            branch_op = base[30:28];
            unknown_inst = base[24];
            branch_redirected = base[25];
            op_a = base + 32'h1000_0001;
            op_b = base + 32'h2000_0002;
            rs1_val = base + 32'h3000_0003;
            rs2_val = base + 32'h4000_0004;
            op_a_late_s10 = base[26];
            op_b_late_s10 = base[27];
            rs1_late_s10 = base[28];
            rs2_late_s10 = base[29];
            late_s10_rd = base[4:0];
        end
    endtask

    task automatic check_payload;
        input string prefix;
        input [31:0] base;
        begin
            `check32({prefix, " pc"}, pc_o, base);
            `check32({prefix, " instr"}, instr_o, base ^ 32'ha5a5_1700);
            `check32({prefix, " epoch/pred/fault"},
                     {28'd0, epoch_o, pred_taken_o, fault_o},
                     {28'd0, base[1:0], base[2], base[3]});
            `check32({prefix, " pred target"}, pred_target_o, base + 32'hc0);
            `check32({prefix, " fault ecode"}, {26'd0, fault_ecode_o},
                     {26'd0, base[9:4]});
            `check32({prefix, " fault badv"}, fault_badv_o, base + 32'h4000_0000);
            `check32({prefix, " rd/imm"}, {15'd0, rd_o, imm_o[11:0]},
                     {15'd0, base[14:10], base[11:0] + 12'h100});
            `check32({prefix, " controls"},
                     {25'd0, wb_en_o, is_branch_o, is_jal_o, is_jalr_o,
                      is_load_o, is_store_o, unknown_inst_o, branch_redirected_o},
                     {25'd0, base[15], base[16], base[17], base[18],
                      base[19], base[20], base[24], base[25]});
            `check32({prefix, " exec selectors"},
                     {21'd0, mem_size_o, mem_sign_ext_o, alu_op_o, branch_op_o},
                     {21'd0, base[22:21], base[23], base[31:28], base[30:28]});
            `check32({prefix, " op A"}, op_a_o, base + 32'h1000_0001);
            `check32({prefix, " op B"}, op_b_o, base + 32'h2000_0002);
            `check32({prefix, " rs1"}, rs1_val_o, base + 32'h3000_0003);
            `check32({prefix, " rs2"}, rs2_val_o, base + 32'h4000_0004);
            `check32({prefix, " late flags"},
                     {27'd0, op_a_late_s10_o, op_b_late_s10_o,
                      rs1_late_s10_o, rs2_late_s10_o, late_s10_rd_o[0]},
                     {27'd0, base[26], base[27], base[28], base[29], base[0]});
            `check32({prefix, " late rd"}, {27'd0, late_s10_rd_o},
                     {27'd0, base[4:0]});
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        capture = 1'b0;
        drive_payload(32'h1c00_8104);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S8S0REG capture", 32'h1c00_8104);

        capture = 1'b0;
        drive_payload(32'h1c00_a228);
        tick();
        #1;
        check_payload("S8S0REG hold", 32'h1c00_8104);

        capture = 1'b1;
        tick();
        #1;
        check_payload("S8S0REG recapture", 32'h1c00_a228);

        finish_tb();
    end
endmodule
