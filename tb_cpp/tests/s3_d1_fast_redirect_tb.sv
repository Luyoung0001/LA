`timescale 1ns / 1ps

module s3_d1_fast_redirect_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic reset;
    logic flush;
    logic next_allowin;
    logic in_valid;
    logic in_pred_taken;
    logic in_exception_valid;
    logic in_exception_badv_valid;
    logic wb_we;
    logic ex_load_valid;
    logic m1_load_valid;
    logic d1_allowin;
    logic fast_redirect_valid;
    logic out_valid;
    logic out_pred_taken;
    logic out_use_imm;
    logic out_is_branch;
    logic out_is_load;
    logic out_is_store;
    logic out_is_muldiv;
    logic out_is_csr;
    logic out_csr_we;
    logic out_csr_mask;
    logic out_exception_valid;
    logic out_exception_badv_valid;

    logic [4:0] wb_waddr;
    logic [4:0] ex_load_rd;
    logic [4:0] m1_load_rd;
    logic [4:0] dbg_reg_num;
    logic [4:0] out_rd;
    logic [5:0] in_exception_ecode;
    logic [5:0] out_exception_ecode;
    logic [8:0] in_exception_esubcode;
    logic [8:0] out_exception_esubcode;
    logic [13:0] out_csr_addr;
    logic [31:0] in_pc;
    logic [31:0] in_inst;
    logic [31:0] in_pred_target;
    logic [31:0] in_exception_badv;
    logic [31:0] wb_wdata;
    logic [31:0] dbg_rf_rdata;
    logic [31:0] fast_redirect_pc;
    logic [31:0] out_pc;
    logic [31:0] out_inst;
    logic [31:0] out_pred_target;
    logic [31:0] out_op1;
    logic [31:0] out_op2;
    logic [31:0] out_imm;
    logic [31:0] out_exception_badv;

    localparam [31:0] PC0 = 32'h1c00_1000;

    assign reset = !rst_n;

    s3_d1 u_dut (
        .clk(clk),
        .reset(reset),
        .flush(flush),
        .next_allowin(next_allowin),
        .in_valid(in_valid),
        .in_pc(in_pc),
        .in_inst(in_inst),
        .in_pred_taken(in_pred_taken),
        .in_pred_target(in_pred_target),
        .in_exception_valid(in_exception_valid),
        .in_exception_ecode(in_exception_ecode),
        .in_exception_esubcode(in_exception_esubcode),
        .in_exception_badv_valid(in_exception_badv_valid),
        .in_exception_badv(in_exception_badv),
        .wb_we(wb_we),
        .wb_waddr(wb_waddr),
        .wb_wdata(wb_wdata),
        .ex_load_valid(ex_load_valid),
        .ex_load_rd(ex_load_rd),
        .m1_load_valid(m1_load_valid),
        .m1_load_rd(m1_load_rd),
        .dbg_reg_num(dbg_reg_num),
        .dbg_rf_rdata(dbg_rf_rdata),
        .d1_allowin(d1_allowin),
        .fast_redirect_valid(fast_redirect_valid),
        .fast_redirect_pc(fast_redirect_pc),
        .out_valid(out_valid),
        .out_pc(out_pc),
        .out_inst(out_inst),
        .out_pred_taken(out_pred_taken),
        .out_pred_target(out_pred_target),
        .out_rd(out_rd),
        .out_op1(out_op1),
        .out_op2(out_op2),
        .out_imm(out_imm),
        .out_use_imm(out_use_imm),
        .out_is_branch(out_is_branch),
        .out_is_load(out_is_load),
        .out_is_store(out_is_store),
        .out_is_muldiv(out_is_muldiv),
        .out_is_csr(out_is_csr),
        .out_csr_we(out_csr_we),
        .out_csr_mask(out_csr_mask),
        .out_csr_addr(out_csr_addr),
        .out_exception_valid(out_exception_valid),
        .out_exception_ecode(out_exception_ecode),
        .out_exception_esubcode(out_exception_esubcode),
        .out_exception_badv_valid(out_exception_badv_valid),
        .out_exception_badv(out_exception_badv)
    );

    function automatic [31:0] encode_b_like(
        input [5:0] op,
        input signed [31:0] byte_offset
    );
        reg [25:0] offs26;
        begin
            offs26 = byte_offset[27:2];
            encode_b_like = {op, offs26[15:0], offs26[25:16]};
        end
    endfunction

    function automatic [31:0] encode_beq(
        input signed [31:0] byte_offset
    );
        reg [15:0] offs16;
        begin
            offs16 = byte_offset[17:2];
            encode_beq = {6'h16, offs16, 5'd0, 5'd0};
        end
    endfunction

    task automatic clear_inputs;
        begin
            flush = 1'b0;
            next_allowin = 1'b1;
            in_valid = 1'b0;
            in_pc = 32'd0;
            in_inst = 32'd0;
            in_pred_taken = 1'b0;
            in_pred_target = 32'd0;
            in_exception_valid = 1'b0;
            in_exception_ecode = 6'd0;
            in_exception_esubcode = 9'd0;
            in_exception_badv_valid = 1'b0;
            in_exception_badv = 32'd0;
            wb_we = 1'b0;
            wb_waddr = 5'd0;
            wb_wdata = 32'd0;
            ex_load_valid = 1'b0;
            ex_load_rd = 5'd0;
            m1_load_valid = 1'b0;
            m1_load_rd = 5'd0;
            dbg_reg_num = 5'd0;
        end
    endtask

    task automatic issue_inst(
        input [31:0] pc,
        input [31:0] inst,
        input        pred_taken,
        input [31:0] pred_target
    );
        begin
            in_valid = 1'b1;
            in_pc = pc;
            in_inst = inst;
            in_pred_taken = pred_taken;
            in_pred_target = pred_target;
            tick();
            in_valid = 1'b0;
            in_pred_taken = 1'b0;
            in_pred_target = 32'd0;
        end
    endtask

    task automatic issue_exception_inst(
        input [31:0] pc,
        input [31:0] inst
    );
        begin
            in_valid = 1'b1;
            in_pc = pc;
            in_inst = inst;
            in_pred_taken = 1'b0;
            in_pred_target = 32'd0;
            in_exception_valid = 1'b1;
            in_exception_ecode = 6'h08;
            tick();
            in_valid = 1'b0;
            in_exception_valid = 1'b0;
            in_exception_ecode = 6'd0;
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        issue_inst(PC0, encode_b_like(6'h14, 32'sd64), 1'b0, 32'd0);
        `check("D1 fast redirect fires for unpredicted B", fast_redirect_valid);
        `check32("D1 fast redirect target for B", fast_redirect_pc, PC0 + 32'd64);
        `check("D1 marks B as predicted taken", out_pred_taken);
        `check32("D1 stores B predicted target", out_pred_target, PC0 + 32'd64);
        tick();
        `check("D1 fast redirect is a pulse", !fast_redirect_valid);

        issue_inst(PC0 + 32'd4, encode_b_like(6'h15, 32'sd128), 1'b1, PC0 + 32'd132);
        `check("D1 does not redirect already-correct BL", !fast_redirect_valid);
        `check("D1 keeps BL predicted taken", out_pred_taken);
        `check32("D1 keeps BL target", out_pred_target, PC0 + 32'd132);

        issue_inst(PC0 + 32'd8, encode_b_like(6'h14, -32'sd16), 1'b1, PC0 + 32'd4);
        `check("D1 redirects wrong-target B", fast_redirect_valid);
        `check32("D1 redirects to signed B target", fast_redirect_pc, PC0 - 32'd8);
        `check32("D1 fixes wrong-target sideband", out_pred_target, PC0 - 32'd8);

        issue_inst(PC0 + 32'd12, encode_beq(32'sd32), 1'b0, 32'd0);
        `check("D1 does not fast redirect conditional branch", !fast_redirect_valid);
        `check("D1 preserves conditional branch prediction", !out_pred_taken);

        issue_exception_inst(PC0 + 32'd16, encode_b_like(6'h14, 32'sd32));
        `check("D1 does not fast redirect exception packet", !fast_redirect_valid);
        `check("D1 preserves exception valid", out_exception_valid);

        issue_inst(PC0 + 32'd16, encode_b_like(6'h14, 32'sd32), 1'b0, 32'd0);
        flush = 1'b1;
        tick();
        `check("D1 flush clears fast redirect pulse", !fast_redirect_valid);
        `check("D1 flush clears valid", !out_valid);

        finish_tb();
    end
endmodule
