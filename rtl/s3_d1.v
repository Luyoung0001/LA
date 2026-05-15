module s3_d1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire        in_pred_taken,
    input  wire [31:0] in_pred_target,
    input  wire        in_exception_valid,
    input  wire [5:0]  in_exception_ecode,
    input  wire [8:0]  in_exception_esubcode,
    input  wire        in_exception_badv_valid,
    input  wire [31:0] in_exception_badv,
    input  wire        wb_we,
    input  wire [4:0]  wb_waddr,
    input  wire [31:0] wb_wdata,
    input  wire [4:0]  dbg_reg_num,
    output wire [31:0] dbg_rf_rdata,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg         out_pred_taken,
    output reg  [31:0] out_pred_target,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_op1,
    output reg  [31:0] out_op2,
    output reg  [31:0] out_imm,
    output reg         out_use_imm,
    output reg         out_is_branch,
    output reg         out_is_load,
    output reg         out_is_store,
    output reg         out_is_muldiv,
    output reg         out_is_csr,
    output reg         out_csr_we,
    output reg         out_csr_mask,
    output reg  [13:0] out_csr_addr,
    output reg         out_exception_valid,
    output reg  [5:0]  out_exception_ecode,
    output reg  [8:0]  out_exception_esubcode,
    output reg         out_exception_badv_valid,
    output reg  [31:0] out_exception_badv
);

    wire [5:0]  op_31_26;
    wire [3:0]  op_25_22;
    wire [1:0]  op_21_20;
    wire [4:0]  op_19_15;
    wire [4:0]  rj;
    wire [4:0]  rk;
    wire [4:0]  rd;

    wire [11:0] i12;
    wire [15:0] i16;
    wire [19:0] i20;
    wire [25:0] i26;

    wire [31:0] imm12_sext;
    wire [31:0] imm12_zext;
    wire [31:0] imm20_lsh12;
    wire [31:0] imm20_pc_sext;
    wire [31:0] br_offs16;
    wire [31:0] br_offs26;
    wire [31:0] shamt_imm;

    wire        inst_add_w;
    wire        inst_sub_w;
    wire        inst_slt;
    wire        inst_sltu;
    wire        inst_and;
    wire        inst_or;
    wire        inst_xor;
    wire        inst_nor;
    wire        inst_sll_w;
    wire        inst_srl_w;
    wire        inst_sra_w;
    wire        inst_slli_w;
    wire        inst_srli_w;
    wire        inst_srai_w;
    wire        inst_mul_w;
    wire        inst_mulh_w;
    wire        inst_mulh_wu;
    wire        inst_div_w;
    wire        inst_div_wu;
    wire        inst_mod_w;
    wire        inst_mod_wu;
    wire        inst_addi_w;
    wire        inst_andi;
    wire        inst_ori;
    wire        inst_xori;
    wire        inst_ld_b;
    wire        inst_ld_h;
    wire        inst_ld_w;
    wire        inst_ld_bu;
    wire        inst_ld_hu;
    wire        inst_st_b;
    wire        inst_st_h;
    wire        inst_st_w;
    wire        inst_jirl;
    wire        inst_b;
    wire        inst_bl;
    wire        inst_beq;
    wire        inst_bne;
    wire        inst_blt;
    wire        inst_bge;
    wire        inst_bltu;
    wire        inst_bgeu;
    wire        inst_lu12i_w;
    wire        inst_pcaddi;
    wire        inst_pcaddu12i;
    wire        inst_slti;
    wire        inst_sltui;
    wire        inst_csrrd;
    wire        inst_csrwr;
    wire        inst_csrxchg;
    wire        inst_rdcntid_w;
    wire        inst_rdcntvl_w;
    wire        inst_rdcntvh_w;
    wire        inst_break;
    wire        inst_syscall;
    wire        inst_idle;
    wire        inst_ertn;
    wire        inst_tlbsrch;
    wire        inst_tlbrd;
    wire        inst_tlbwr;
    wire        inst_tlbfill;
    wire        inst_invtlb;
    wire        inst_cacop;
    wire        inst_preld;
    wire        inst_dbar;
    wire        inst_ibar;
    wire        inst_no_gpr;

    wire [4:0]  rf_raddr1_w;
    wire [4:0]  rf_raddr2_w;
    wire [4:0]  out_rd_w;
    wire [31:0] out_imm_w;
    wire        out_use_imm_w;
    wire        out_is_branch_w;
    wire        out_is_load_w;
    wire        out_is_store_w;
    wire        out_is_muldiv_w;
    wire        out_is_csr_w;
    wire        out_csr_we_w;
    wire        out_csr_mask_w;
    wire [13:0] out_csr_addr_w;
    wire [31:0] rf_rdata1_w;
    wire [31:0] rf_rdata2_w;

    reg [31:0] regs [31:0];
    integer i;

    assign op_31_26 = in_inst[31:26];
    assign op_25_22 = in_inst[25:22];
    assign op_21_20 = in_inst[21:20];
    assign op_19_15 = in_inst[19:15];
    assign rj       = in_inst[9:5];
    assign rk       = in_inst[14:10];
    assign rd       = in_inst[4:0];

    assign i12      = in_inst[21:10];
    assign i16      = in_inst[25:10];
    assign i20      = in_inst[24:5];
    assign i26      = {in_inst[9:0], in_inst[25:10]};

    assign imm12_sext = {{20{in_inst[21]}}, in_inst[21:10]};
    assign imm12_zext = {20'b0, in_inst[21:10]};
    assign imm20_lsh12 = {i20, 12'b0};
    assign imm20_pc_sext = {{10{i20[19]}}, i20, 2'b0};
    assign br_offs16   = {{14{i16[15]}}, i16, 2'b0};
    assign br_offs26   = {{4{i26[25]}}, i26, 2'b0};
    assign shamt_imm   = {27'b0, rk};

    assign inst_add_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h00);
    assign inst_sub_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h02);
    assign inst_slt     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h04);
    assign inst_sltu    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h05);
    assign inst_and     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h09);
    assign inst_or      = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0a);
    assign inst_xor     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0b);
    assign inst_nor     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h08);
    assign inst_sll_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0e);
    assign inst_srl_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0f);
    assign inst_sra_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h10);
    assign inst_slli_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h01);
    assign inst_srli_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h09);
    assign inst_srai_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h11);
    assign inst_mul_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h18);
    assign inst_mulh_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h19);
    assign inst_mulh_wu = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h1a);
    assign inst_div_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h00);
    assign inst_mod_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h01);
    assign inst_div_wu  = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h02);
    assign inst_mod_wu  = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h03);
    assign inst_addi_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'ha);
    assign inst_andi    = (op_31_26 == 6'h00) && (op_25_22 == 4'hd);
    assign inst_ori     = (op_31_26 == 6'h00) && (op_25_22 == 4'he);
    assign inst_xori    = (op_31_26 == 6'h00) && (op_25_22 == 4'hf);
    assign inst_ld_b    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h0);
    assign inst_ld_h    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h1);
    assign inst_ld_w    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h2);
    assign inst_st_b    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h4);
    assign inst_st_h    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h5);
    assign inst_st_w    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h6);
    assign inst_ld_bu   = (op_31_26 == 6'h0a) && (op_25_22 == 4'h8);
    assign inst_ld_hu   = (op_31_26 == 6'h0a) && (op_25_22 == 4'h9);
    assign inst_jirl    = (op_31_26 == 6'h13);
    assign inst_b       = (op_31_26 == 6'h14);
    assign inst_bl      = (op_31_26 == 6'h15);
    assign inst_beq     = (op_31_26 == 6'h16);
    assign inst_bne     = (op_31_26 == 6'h17);
    assign inst_blt     = (op_31_26 == 6'h18);
    assign inst_bge     = (op_31_26 == 6'h19);
    assign inst_bltu    = (op_31_26 == 6'h1a);
    assign inst_bgeu    = (op_31_26 == 6'h1b);
    assign inst_lu12i_w = (op_31_26 == 6'h05) && (~in_inst[25]);
    assign inst_pcaddi  = (op_31_26 == 6'h06) && (~in_inst[25]);
    assign inst_pcaddu12i = (op_31_26 == 6'h07) && (~in_inst[25]);
    assign inst_slti    = (op_31_26 == 6'h00) && (op_25_22 == 4'h8);
    assign inst_sltui   = (op_31_26 == 6'h00) && (op_25_22 == 4'h9);
    assign inst_csrrd   = (op_31_26 == 6'h01) && (~in_inst[25]) && (~in_inst[24]) && (rj == 5'h00);
    assign inst_csrwr   = (op_31_26 == 6'h01) && (~in_inst[25]) && (~in_inst[24]) && (rj == 5'h01);
    assign inst_csrxchg = (op_31_26 == 6'h01) && (~in_inst[25]) && (~in_inst[24]) && (rj != 5'h00) && (rj != 5'h01);
    assign inst_rdcntid_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h00) &&
                            (rk == 5'h18) && (rd == 5'h00);
    assign inst_rdcntvl_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h00) &&
                            (rk == 5'h18) && (rj == 5'h00) && (rd != 5'h00);
    assign inst_rdcntvh_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h00) &&
                            (rk == 5'h19) && (rj == 5'h00);
    assign inst_break     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h2) && (op_19_15 == 5'h14);
    assign inst_syscall   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h2) && (op_19_15 == 5'h16);
    assign inst_idle      = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h11);
    assign inst_ertn      = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h10) &&
                            (rk == 5'h0e) && (rj == 5'h00) && (rd == 5'h00);
    assign inst_tlbsrch   = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h10) &&
                            (rk == 5'h0a) && (rj == 5'h00) && (rd == 5'h00);
    assign inst_tlbrd     = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h10) &&
                            (rk == 5'h0b) && (rj == 5'h00) && (rd == 5'h00);
    assign inst_tlbwr     = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h10) &&
                            (rk == 5'h0c) && (rj == 5'h00) && (rd == 5'h00);
    assign inst_tlbfill   = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h10) &&
                            (rk == 5'h0d) && (rj == 5'h00) && (rd == 5'h00);
    assign inst_invtlb    = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h13) && (rd <= 5'd6);
    assign inst_cacop     = (op_31_26 == 6'h01) && (op_25_22 == 4'h8);
    assign inst_preld     = (op_31_26 == 6'h0a) && (op_25_22 == 4'hb);
    assign inst_dbar      = (op_31_26 == 6'h0e) && (op_25_22 == 4'h1) &&
                            (op_21_20 == 2'h3) && (op_19_15 == 5'h04);
    assign inst_ibar      = (op_31_26 == 6'h0e) && (op_25_22 == 4'h1) &&
                            (op_21_20 == 2'h3) && (op_19_15 == 5'h05);
    assign inst_no_gpr    = inst_b | inst_beq | inst_bne | inst_blt | inst_bge |
                            inst_bltu | inst_bgeu | inst_st_b | inst_st_h |
                            inst_st_w | inst_break | inst_syscall | inst_idle |
                            inst_ertn | inst_tlbsrch | inst_tlbrd | inst_tlbwr |
                            inst_tlbfill | inst_invtlb | inst_cacop | inst_preld |
                            inst_dbar | inst_ibar;

    assign out_is_branch_w = inst_jirl | inst_b | inst_bl | inst_beq | inst_bne |
                             inst_blt | inst_bge | inst_bltu | inst_bgeu;
    assign out_is_load_w   = inst_ld_b | inst_ld_h | inst_ld_w | inst_ld_bu | inst_ld_hu |
                             inst_cacop;
    assign out_is_store_w  = inst_st_b | inst_st_h | inst_st_w;
    assign out_is_muldiv_w = 1'b0;
    assign out_is_csr_w    = inst_csrrd | inst_csrwr | inst_csrxchg |
                              inst_rdcntid_w | inst_rdcntvl_w | inst_rdcntvh_w;
    assign out_csr_we_w    = inst_csrwr | inst_csrxchg;
    assign out_csr_mask_w  = inst_csrxchg;
    assign out_csr_addr_w  = inst_rdcntid_w ? 14'h040 : in_inst[23:10];

    assign rf_raddr1_w = (inst_b | inst_bl | inst_lu12i_w | inst_pcaddi | inst_pcaddu12i | inst_csrwr) ? 5'b0 : rj;
    assign rf_raddr2_w = (inst_add_w | inst_sub_w | inst_slt | inst_sltu | inst_and | inst_or | inst_xor | inst_nor |
                          inst_sll_w | inst_srl_w | inst_sra_w |
                          inst_mul_w | inst_mulh_w | inst_mulh_wu |
                          inst_div_w | inst_div_wu | inst_mod_w | inst_mod_wu) ? rk :
                         (inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu |
                          inst_st_b | inst_st_h | inst_st_w | inst_csrwr | inst_csrxchg) ? rd :
                         inst_invtlb ? rk : 5'b0;

    assign out_rd_w = inst_bl ? 5'd1 :
                      inst_rdcntid_w ? rj :
                      inst_no_gpr ? 5'b0 : rd;

    assign out_imm_w = (inst_lu12i_w | inst_pcaddu12i) ? imm20_lsh12 :
                       inst_pcaddi ? imm20_pc_sext :
                       (inst_addi_w | inst_ld_b | inst_ld_h | inst_ld_w | inst_ld_bu | inst_ld_hu |
                        inst_st_b | inst_st_h | inst_st_w | inst_cacop | inst_slti | inst_sltui) ? imm12_sext :
                       (inst_andi | inst_ori | inst_xori) ? imm12_zext :
                       (inst_slli_w | inst_srli_w | inst_srai_w) ? shamt_imm :
                       (inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu | inst_jirl) ? br_offs16 :
                       (inst_b | inst_bl) ? br_offs26 :
                       32'b0;

    assign out_use_imm_w = inst_addi_w |
                           inst_ld_b | inst_ld_h | inst_ld_w | inst_ld_bu | inst_ld_hu |
                           inst_st_b | inst_st_h | inst_st_w | inst_cacop |
                           inst_slti | inst_sltui | inst_pcaddi | inst_pcaddu12i |
                           inst_andi | inst_ori | inst_xori |
                           inst_slli_w | inst_srli_w | inst_srai_w;

    assign rf_rdata1_w = (rf_raddr1_w == 5'b0) ? 32'b0 :
                         (wb_we && (wb_waddr == rf_raddr1_w)) ? wb_wdata :
                         regs[rf_raddr1_w];
    assign rf_rdata2_w = (rf_raddr2_w == 5'b0) ? 32'b0 :
                         (wb_we && (wb_waddr == rf_raddr2_w)) ? wb_wdata :
                         regs[rf_raddr2_w];
    assign dbg_rf_rdata = (dbg_reg_num == 5'b0) ? 32'b0 : regs[dbg_reg_num];

    always @(posedge clk) begin
        if (reset) begin
            for (i = 0; i < 32; i = i + 1) begin
                regs[i] <= 32'b0;
            end
            out_valid      <= 1'b0;
            out_pc         <= 32'b0;
            out_inst       <= 32'b0;
            out_pred_taken <= 1'b0;
            out_pred_target <= 32'b0;
            out_rd         <= 5'b0;
            out_op1        <= 32'b0;
            out_op2        <= 32'b0;
            out_imm        <= 32'b0;
            out_use_imm    <= 1'b0;
            out_is_branch  <= 1'b0;
            out_is_load    <= 1'b0;
            out_is_store   <= 1'b0;
            out_is_muldiv  <= 1'b0;
            out_is_csr     <= 1'b0;
            out_csr_we     <= 1'b0;
            out_csr_mask   <= 1'b0;
            out_csr_addr   <= 14'b0;
            out_exception_valid      <= 1'b0;
            out_exception_ecode      <= 6'b0;
            out_exception_esubcode   <= 9'b0;
            out_exception_badv_valid <= 1'b0;
            out_exception_badv       <= 32'b0;
        end else begin
            if (wb_we && (wb_waddr != 5'b0)) begin
                regs[wb_waddr] <= wb_wdata;
            end

            out_valid      <= in_valid && !flush;
            out_pc         <= in_pc;
            out_inst       <= in_inst;
            out_pred_taken <= in_pred_taken;
            out_pred_target <= in_pred_target;
            out_rd         <= out_rd_w;
            out_op1        <= rf_rdata1_w;
            out_op2        <= rf_rdata2_w;
            out_imm        <= out_imm_w;
            out_use_imm    <= out_use_imm_w;
            out_is_branch  <= out_is_branch_w;
            out_is_load    <= out_is_load_w;
            out_is_store   <= out_is_store_w;
            out_is_muldiv  <= out_is_muldiv_w;
            out_is_csr     <= out_is_csr_w;
            out_csr_we     <= out_csr_we_w;
            out_csr_mask   <= out_csr_mask_w;
            out_csr_addr   <= out_csr_addr_w;
            out_exception_valid      <= in_valid && in_exception_valid;
            out_exception_ecode      <= in_exception_ecode;
            out_exception_esubcode   <= in_exception_esubcode;
            out_exception_badv_valid <= in_exception_badv_valid;
            out_exception_badv       <= in_exception_badv;
        end
    end

endmodule
