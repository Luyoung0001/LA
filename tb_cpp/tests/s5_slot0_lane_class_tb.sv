`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s5_slot0_lane_class_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    function automatic [31:0] la_i12(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_i12 = {6'h00, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_alu_3r(input [1:0] op21_20, input [4:0] op19_15, input [4:0] rd, input [4:0] rj, input [4:0] rk);
        la_alu_3r = {6'h00, 4'h0, op21_20, op19_15, rk, rj, rd};
    endfunction

    function automatic [31:0] la_mem(input [3:0] op25_22, input [4:0] rd, input [4:0] rj, input [11:0] imm);
        la_mem = {6'h0a, op25_22, imm, rj, rd};
    endfunction

    function automatic [31:0] la_branch(input [5:0] op31_26, input [4:0] rd, input [4:0] rj, input [15:0] imm);
        la_branch = {op31_26, imm, rj, rd};
    endfunction

    function automatic [31:0] la_csr(input [4:0] rd, input [4:0] rj, input [13:0] csr);
        la_csr = {6'h01, 2'b00, csr, rj, rd};
    endfunction

    function automatic [31:0] la_rdcntvl(input [4:0] rd);
        la_rdcntvl = {6'h00, 4'h0, 2'h0, 5'h00, 5'h18, 5'd0, rd};
    endfunction

    function automatic [31:0] la_ertn();
        la_ertn = {6'h01, 4'h9, 2'h0, 5'h10, 5'h0e, 5'd0, 5'd0};
    endfunction

    function automatic [31:0] la_cacop(input [4:0] op, input [4:0] rj, input [11:0] imm);
        la_cacop = {6'h01, 4'h8, imm, rj, op};
    endfunction

    function automatic [31:0] la_ll_w(input [4:0] rd, input [4:0] rj, input [13:0] imm14);
        la_ll_w = {6'h08, 1'b0, 1'b0, imm14, rj, rd};
    endfunction

    logic [31:0] instr;
    logic        fault;
    logic [6:0]  opcode;
    logic [2:0]  funct3;
    logic [6:0]  funct7;
    logic [4:0]  op_19_15;
    logic [4:0]  rs1;
    logic [4:0]  rd;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic        is_lui;
    logic        is_auipc;
    logic        unknown_inst;
    logic        wb_en;
    logic        uses_rs1;
    logic        uses_rs2;
    logic        single_issue;
    logic        pairable_compute;
    logic [1:0]  mem_size;
    logic        mem_sign_ext;
    logic [1:0]  src_a_sel;
    logic [1:0]  src_b_sel;
    logic [3:0]  alu_op;
    logic [2:0]  branch_op;
    logic        is_alu_div;
    logic        is_syscall;
    logic        is_break;
    logic        is_idle;
    logic        is_dbar;
    logic        is_ibar;
    logic        is_rdcnt;
    logic        is_csr;
    logic        is_ertn;
    logic        is_tlb_op;
    logic        is_cacop_valid;
    logic        is_cacop_nop;
    logic        is_preld;
    logic        is_ll_w;
    logic        is_sc_w;
    logic        is_cpucfg;

    s5_slot0_lane_class u_dut (
        .instr_i(instr),
        .fault_i(fault),
        .opcode_i(opcode),
        .funct3_i(funct3),
        .funct7_i(funct7),
        .op_19_15_i(op_19_15),
        .rs1_i(rs1),
        .rd_i(rd),
        .is_branch_i(is_branch),
        .is_jal_i(is_jal),
        .is_jalr_i(is_jalr),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .is_lui_i(is_lui),
        .is_auipc_i(is_auipc),
        .unknown_inst_i(unknown_inst),
        .wb_en_o(wb_en),
        .uses_rs1_o(uses_rs1),
        .uses_rs2_o(uses_rs2),
        .single_issue_o(single_issue),
        .pairable_compute_o(pairable_compute),
        .mem_size_o(mem_size),
        .mem_sign_ext_o(mem_sign_ext),
        .src_a_sel_o(src_a_sel),
        .src_b_sel_o(src_b_sel),
        .alu_op_o(alu_op),
        .branch_op_o(branch_op),
        .is_alu_div_o(is_alu_div),
        .is_syscall_o(is_syscall),
        .is_break_o(is_break),
        .is_idle_o(is_idle),
        .is_dbar_o(is_dbar),
        .is_ibar_o(is_ibar),
        .is_rdcnt_o(is_rdcnt),
        .is_csr_o(is_csr),
        .is_ertn_o(is_ertn),
        .is_tlb_op_o(is_tlb_op),
        .is_cacop_valid_o(is_cacop_valid),
        .is_cacop_nop_o(is_cacop_nop),
        .is_preld_o(is_preld),
        .is_ll_w_o(is_ll_w),
        .is_sc_w_o(is_sc_w),
        .is_cpucfg_o(is_cpucfg)
    );

    task automatic drive(
        input [31:0] inst,
        input        branch_flag,
        input        jal_flag,
        input        jalr_flag,
        input        load_flag,
        input        store_flag,
        input        lui_flag,
        input        auipc_flag,
        input        unknown_flag
    );
        begin
            instr = inst;
            opcode = {1'b0, inst[31:26]};
            funct3 = {1'b0, inst[21:20]};
            funct7 = {3'b0, inst[25:22]};
            op_19_15 = inst[19:15];
            rs1 = inst[9:5];
            rd = inst[4:0];
            is_branch = branch_flag;
            is_jal = jal_flag;
            is_jalr = jalr_flag;
            is_load = load_flag;
            is_store = store_flag;
            is_lui = lui_flag;
            is_auipc = auipc_flag;
            unknown_inst = unknown_flag;
            fault = 1'b0;
            #1;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        drive(la_i12(4'ha, 5'd4, 5'd3, 12'h010), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 addi writes and uses rs1", wb_en && uses_rs1 && !uses_rs2 && !single_issue && pairable_compute);
        `check32("S5S0 addi src B imm", {30'd0, src_b_sel}, {30'd0, `CPU_SRC_B_IMM});
        `check32("S5S0 addi ALU add", {28'd0, alu_op}, {28'd0, `CPU_ALU_ADD});

        drive(la_alu_3r(2'h1, 5'h02, 5'd4, 5'd3, 5'd2), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 sub uses two sources", wb_en && uses_rs1 && uses_rs2 && !single_issue && pairable_compute);
        `check32("S5S0 sub src B rs2", {30'd0, src_b_sel}, {30'd0, `CPU_SRC_B_RS2});
        `check32("S5S0 sub ALU sub", {28'd0, alu_op}, {28'd0, `CPU_ALU_SUB});

        drive(la_alu_3r(2'h1, 5'h18, 5'd4, 5'd3, 5'd2), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 mul remains non-serial but is not a slot1-memory pair anchor",
               wb_en && uses_rs1 && uses_rs2 && !single_issue && !pairable_compute);

        drive(la_alu_3r(2'h2, 5'h00, 5'd4, 5'd3, 5'd2), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 div serializes slot0", is_alu_div && single_issue && uses_rs1 && uses_rs2 && !pairable_compute);

        drive(la_mem(4'h2, 5'd4, 5'd3, 12'h020), 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 word load serializes and writes", single_issue && wb_en && uses_rs1 && !uses_rs2 && !pairable_compute);
        `check32("S5S0 word load size", {30'd0, mem_size}, 32'd2);

        drive(la_mem(4'h5, 5'd4, 5'd3, 12'h020), 1'b0, 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0);
        `check("S5S0 half store serializes and does not write", single_issue && !wb_en && uses_rs1 && uses_rs2 && !pairable_compute);
        `check32("S5S0 half store size", {30'd0, mem_size}, 32'd1);

        drive(la_branch(6'h18, 5'd4, 5'd3, 16'h0010), 1'b1, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 branch uses two sources no write", !wb_en && uses_rs1 && uses_rs2);
        `check32("S5S0 BLT branch op", {29'd0, branch_op}, {29'd0, `CPU_BR_LT});

        drive(la_csr(5'd4, 5'd1, `CPU_CSR_CRMD), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 csrwr is CSR and serializes", is_csr && single_issue && uses_rs2 && !uses_rs1);

        drive(la_rdcntvl(5'd5), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 rdcnt serializes without source regs", is_rdcnt && single_issue && !uses_rs1 && !uses_rs2);

        drive(la_ertn(), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 ertn has no writeback and serializes", is_ertn && single_issue && !wb_en);

        drive(la_cacop(5'd0, 5'd3, 12'h010), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 valid cacop uses rs1 and no writeback", is_cacop_valid && single_issue && uses_rs1 && !wb_en);

        drive(la_cacop(5'd31, 5'd3, 12'h010), 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 invalid cacop pattern becomes nop class", is_cacop_nop && single_issue && !wb_en);

        drive(la_ll_w(5'd4, 5'd3, 14'h010), 1'b0, 1'b0, 1'b0, 1'b1, 1'b0, 1'b0, 1'b0, 1'b0);
        `check("S5S0 ll.w serializes and writes", is_ll_w && single_issue && wb_en);

        drive(32'hffff_ffff, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b0, 1'b1);
        `check("S5S0 unknown serializes and suppresses writeback", single_issue && !wb_en);

        finish_tb();
    end
endmodule
