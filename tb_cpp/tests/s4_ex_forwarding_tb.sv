`timescale 1ns / 1ps

module s4_ex_forwarding_tb;
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
    logic in_use_imm;
    logic in_is_branch;
    logic in_is_load;
    logic in_is_store;
    logic in_is_muldiv;
    logic in_is_csr;
    logic in_csr_we;
    logic in_csr_mask;
    logic in_exception_valid;
    logic in_exception_badv_valid;
    logic forward_ex1_valid;
    logic forward_ex2_valid;
    logic forward_mem_valid;
    logic forward_wb_valid;
    logic branch_update_valid;
    logic branch_taken;
    logic branch_mispredict;
    logic out_valid;
    logic out_is_load;
    logic out_is_store;
    logic out_is_csr;
    logic out_csr_we;
    logic out_exception_valid;
    logic out_exception_badv_valid;
    logic ex_allowin;

    logic [3:0] in_branch_type;
    logic [4:0] in_rd;
    logic [4:0] in_src1;
    logic [4:0] in_src2;
    logic [4:0] forward_ex1_waddr;
    logic [4:0] forward_ex2_waddr;
    logic [4:0] forward_mem_waddr;
    logic [4:0] forward_wb_waddr;
    logic [4:0] out_rd;
    logic [5:0] in_exception_ecode;
    logic [5:0] out_exception_ecode;
    logic [8:0] in_exception_esubcode;
    logic [8:0] out_exception_esubcode;
    logic [13:0] in_csr_addr;
    logic [13:0] out_csr_addr;

    logic [31:0] in_pc;
    logic [31:0] in_inst;
    logic [31:0] in_pred_target;
    logic [31:0] in_op1;
    logic [31:0] in_op2;
    logic [31:0] in_imm;
    logic [31:0] in_exception_badv;
    logic [31:0] csr_read_data;
    logic [31:0] forward_ex1_wdata;
    logic [31:0] forward_ex2_wdata;
    logic [31:0] forward_mem_wdata;
    logic [31:0] forward_wb_wdata;
    logic [31:0] branch_target;
    logic [31:0] out_pc;
    logic [31:0] out_inst;
    logic [31:0] out_result;
    logic [31:0] out_op1;
    logic [31:0] out_op2;
    logic [31:0] out_store_data;
    logic [31:0] out_csr_wdata;
    logic [31:0] out_exception_badv;
    logic [63:0] timer_64;

    assign reset = !rst_n;

    s4_ex u_dut (
        .clk(clk),
        .reset(reset),
        .flush(flush),
        .next_allowin(next_allowin),
        .in_valid(in_valid),
        .in_pc(in_pc),
        .in_inst(in_inst),
        .in_pred_taken(in_pred_taken),
        .in_pred_target(in_pred_target),
        .in_rd(in_rd),
        .in_src1(in_src1),
        .in_src2(in_src2),
        .in_op1(in_op1),
        .in_op2(in_op2),
        .in_imm(in_imm),
        .in_use_imm(in_use_imm),
        .in_is_branch(in_is_branch),
        .in_branch_type(in_branch_type),
        .in_is_load(in_is_load),
        .in_is_store(in_is_store),
        .in_is_muldiv(in_is_muldiv),
        .in_is_csr(in_is_csr),
        .in_csr_we(in_csr_we),
        .in_csr_mask(in_csr_mask),
        .in_csr_addr(in_csr_addr),
        .in_exception_valid(in_exception_valid),
        .in_exception_ecode(in_exception_ecode),
        .in_exception_esubcode(in_exception_esubcode),
        .in_exception_badv_valid(in_exception_badv_valid),
        .in_exception_badv(in_exception_badv),
        .csr_read_data(csr_read_data),
        .timer_64(timer_64),
        .forward_ex1_valid(forward_ex1_valid),
        .forward_ex1_waddr(forward_ex1_waddr),
        .forward_ex1_wdata(forward_ex1_wdata),
        .forward_ex2_valid(forward_ex2_valid),
        .forward_ex2_waddr(forward_ex2_waddr),
        .forward_ex2_wdata(forward_ex2_wdata),
        .forward_mem_valid(forward_mem_valid),
        .forward_mem_waddr(forward_mem_waddr),
        .forward_mem_wdata(forward_mem_wdata),
        .forward_wb_valid(forward_wb_valid),
        .forward_wb_waddr(forward_wb_waddr),
        .forward_wb_wdata(forward_wb_wdata),
        .branch_update_valid(branch_update_valid),
        .branch_taken(branch_taken),
        .branch_target(branch_target),
        .branch_mispredict(branch_mispredict),
        .out_valid(out_valid),
        .out_pc(out_pc),
        .out_inst(out_inst),
        .out_rd(out_rd),
        .out_result(out_result),
        .out_op1(out_op1),
        .out_op2(out_op2),
        .out_is_load(out_is_load),
        .out_is_store(out_is_store),
        .out_store_data(out_store_data),
        .out_is_csr(out_is_csr),
        .out_csr_we(out_csr_we),
        .out_csr_addr(out_csr_addr),
        .out_csr_wdata(out_csr_wdata),
        .out_exception_valid(out_exception_valid),
        .out_exception_ecode(out_exception_ecode),
        .out_exception_esubcode(out_exception_esubcode),
        .out_exception_badv_valid(out_exception_badv_valid),
        .out_exception_badv(out_exception_badv),
        .ex_allowin(ex_allowin)
    );

    function automatic [31:0] encode_add_w(
        input [4:0] rd_in,
        input [4:0] rj_in,
        input [4:0] rk_in
    );
        begin
            encode_add_w = {6'h00, 4'h0, 2'h1, 5'h00, rk_in, rj_in, rd_in};
        end
    endfunction

    function automatic [31:0] encode_beq(
        input [4:0] rj_in,
        input [4:0] rd_in,
        input signed [31:0] byte_offset
    );
        reg [15:0] offs16;
        begin
            offs16 = byte_offset[17:2];
            encode_beq = {6'h16, offs16, rj_in, rd_in};
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
            in_rd = 5'd0;
            in_src1 = 5'd0;
            in_src2 = 5'd0;
            in_op1 = 32'd0;
            in_op2 = 32'd0;
            in_imm = 32'd0;
            in_use_imm = 1'b0;
            in_is_branch = 1'b0;
            in_branch_type = 4'd0;
            in_is_load = 1'b0;
            in_is_store = 1'b0;
            in_is_muldiv = 1'b0;
            in_is_csr = 1'b0;
            in_csr_we = 1'b0;
            in_csr_mask = 1'b0;
            in_csr_addr = 14'd0;
            in_exception_valid = 1'b0;
            in_exception_ecode = 6'd0;
            in_exception_esubcode = 9'd0;
            in_exception_badv_valid = 1'b0;
            in_exception_badv = 32'd0;
            csr_read_data = 32'd0;
            timer_64 = 64'd0;
            forward_ex1_valid = 1'b0;
            forward_ex1_waddr = 5'd0;
            forward_ex1_wdata = 32'd0;
            forward_ex2_valid = 1'b0;
            forward_ex2_waddr = 5'd0;
            forward_ex2_wdata = 32'd0;
            forward_mem_valid = 1'b0;
            forward_mem_waddr = 5'd0;
            forward_mem_wdata = 32'd0;
            forward_wb_valid = 1'b0;
            forward_wb_waddr = 5'd0;
            forward_wb_wdata = 32'd0;
        end
    endtask

    task automatic issue_add_with_forwarding;
        begin
            in_valid = 1'b1;
            in_pc = 32'h1c00_2000;
            in_inst = encode_add_w(5'd3, 5'd1, 5'd2);
            in_rd = 5'd3;
            in_src1 = 5'd10;
            in_src2 = 5'd11;
            in_op1 = 32'd1;
            in_op2 = 32'd2;
            forward_ex1_valid = 1'b1;
            forward_ex1_waddr = 5'd10;
            forward_ex1_wdata = 32'd40;
            forward_mem_valid = 1'b1;
            forward_mem_waddr = 5'd11;
            forward_mem_wdata = 32'd2;
            tick();
            in_valid = 1'b0;
            forward_ex1_valid = 1'b0;
            forward_mem_valid = 1'b0;
        end
    endtask

    task automatic issue_beq_with_forwarding;
        begin
            in_valid = 1'b1;
            in_pc = 32'h1c00_3000;
            in_inst = encode_beq(5'd1, 5'd2, 32'sd16);
            in_pred_taken = 1'b0;
            in_pred_target = 32'd0;
            in_src1 = 5'd12;
            in_src2 = 5'd13;
            in_op1 = 32'd1;
            in_op2 = 32'd2;
            in_imm = 32'd16;
            in_is_branch = 1'b1;
            in_branch_type = 4'd4;
            forward_ex1_valid = 1'b1;
            forward_ex1_waddr = 5'd12;
            forward_ex1_wdata = 32'h55aa_55aa;
            forward_wb_valid = 1'b1;
            forward_wb_waddr = 5'd13;
            forward_wb_wdata = 32'h55aa_55aa;
            tick();
            in_valid = 1'b0;
            in_is_branch = 1'b0;
            in_branch_type = 4'd0;
            forward_ex1_valid = 1'b0;
            forward_wb_valid = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        issue_add_with_forwarding();
        `check("EX accepts ADD packet", out_valid);
        `check32("EX forwards src1 from decoded in_src1", out_op1, 32'd40);
        `check32("EX forwards src2 from decoded in_src2", out_op2, 32'd2);
        `check32("EX ADD result uses decoded source forwarding", out_result, 32'd42);

        tick();
        issue_beq_with_forwarding();
        `check("EX emits branch update", branch_update_valid);
        `check("EX takes BEQ using decoded source forwarding", branch_taken);
        `check("EX reports BEQ mispredict", branch_mispredict);
        `check32("EX BEQ target", branch_target, 32'h1c00_3010);

        finish_tb();
    end
endmodule
