module s4_ex (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_op1,
    input  wire [31:0] in_op2,
    input  wire [31:0] in_imm,
    input  wire        in_use_imm,
    input  wire        in_is_branch,
    input  wire        in_is_load,
    input  wire        in_is_store,
    input  wire        in_is_muldiv,
    input  wire        in_is_csr,
    input  wire        in_csr_we,
    input  wire        in_csr_mask,
    input  wire [13:0] in_csr_addr,
    input  wire        in_exception_valid,
    input  wire [5:0]  in_exception_ecode,
    input  wire [8:0]  in_exception_esubcode,
    input  wire        in_exception_badv_valid,
    input  wire [31:0] in_exception_badv,
    input  wire [31:0] csr_read_data,
    input  wire [63:0] timer_64,
    input  wire        forward_ex1_valid,
    input  wire [4:0]  forward_ex1_waddr,
    input  wire [31:0] forward_ex1_wdata,
    input  wire        forward_ex2_valid,
    input  wire [4:0]  forward_ex2_waddr,
    input  wire [31:0] forward_ex2_wdata,
    input  wire        forward_mem_valid,
    input  wire [4:0]  forward_mem_waddr,
    input  wire [31:0] forward_mem_wdata,
    input  wire        forward_wb_valid,
    input  wire [4:0]  forward_wb_waddr,
    input  wire [31:0] forward_wb_wdata,
    output reg         branch_update_valid,
    output reg         branch_taken,
    output reg  [31:0] branch_target,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_result,
    output reg  [31:0] out_op1,
    output reg  [31:0] out_op2,
    output reg         out_is_load,
    output reg         out_is_store,
    output reg  [31:0] out_store_data,
    output reg         out_is_csr,
    output reg         out_csr_we,
    output reg  [13:0] out_csr_addr,
    output reg  [31:0] out_csr_wdata,
    output reg         out_exception_valid,
    output reg  [5:0]  out_exception_ecode,
    output reg  [8:0]  out_exception_esubcode,
    output reg         out_exception_badv_valid,
    output reg  [31:0] out_exception_badv
);

    wire [5:0] op_31_26;
    wire [3:0] op_25_22;
    wire [1:0] op_21_20;
    wire [4:0] op_19_15;
    wire [4:0] rk;

    wire inst_add_w;
    wire inst_sub_w;
    wire inst_slt;
    wire inst_sltu;
    wire inst_and;
    wire inst_or;
    wire inst_xor;
    wire inst_nor;
    wire inst_sll_w;
    wire inst_srl_w;
    wire inst_sra_w;
    wire inst_slli_w;
    wire inst_srli_w;
    wire inst_srai_w;
    wire inst_mul_w;
    wire inst_mulh_w;
    wire inst_mulh_wu;
    wire inst_div_w;
    wire inst_div_wu;
    wire inst_mod_w;
    wire inst_mod_wu;
    wire inst_addi_w;
    wire inst_andi;
    wire inst_ori;
    wire inst_xori;
    wire inst_ld_b;
    wire inst_ld_h;
    wire inst_ld_w;
    wire inst_ld_bu;
    wire inst_ld_hu;
    wire inst_st_b;
    wire inst_st_h;
    wire inst_st_w;
    wire inst_jirl;
    wire inst_b;
    wire inst_bl;
    wire inst_beq;
    wire inst_bne;
    wire inst_blt;
    wire inst_bge;
    wire inst_bltu;
    wire inst_bgeu;
    wire inst_lu12i_w;
    wire inst_pcaddi;
    wire inst_pcaddu12i;
    wire inst_slti;
    wire inst_sltui;
    wire inst_csrwr;
    wire inst_csrxchg;
    wire inst_rdcntid_w;
    wire inst_rdcntvl_w;
    wire inst_rdcntvh_w;
    wire inst_cacop;
    wire src2_is_rd;
    wire [4:0] src1_addr;
    wire [4:0] src2_addr;
    wire [31:0] op1_forwarded;
    wire [31:0] op2_forwarded;
    wire signed [31:0] op1_signed;
    wire signed [31:0] op2_signed;
    wire [31:0] csr_write_data_w;
    wire [63:0] mul_signed_w;
    wire [63:0] mul_unsigned_w;
    wire [31:0] div_signed_w;
    wire [31:0] div_unsigned_w;
    wire [31:0] mod_signed_w;
    wire [31:0] mod_unsigned_w;
    wire        div_signed_neg_w;
    wire [31:0] div_signed_abs1_w;
    wire [31:0] div_signed_abs2_w;
    wire [31:0] div_signed_abs2_safe_w;
    wire [31:0] div_signed_quot_abs_w;
    wire [31:0] div_signed_rem_abs_w;
    wire        unused_timer_64;
    wire        branch_take_w;
    wire [31:0] branch_target_w;

    reg [31:0] ex_result;

    assign unused_timer_64 = &{1'b0, timer_64};

    assign op_31_26 = in_inst[31:26];
    assign op_25_22 = in_inst[25:22];
    assign op_21_20 = in_inst[21:20];
    assign op_19_15 = in_inst[19:15];
    assign rk       = in_inst[14:10];

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
    assign inst_csrwr   = (op_31_26 == 6'h01) && (~in_inst[25]) && (~in_inst[24]) && (in_inst[9:5] == 5'h01);
    assign inst_csrxchg = (op_31_26 == 6'h01) && (~in_inst[25]) && (~in_inst[24]) && (in_inst[9:5] != 5'h00) && (in_inst[9:5] != 5'h01);
    assign inst_rdcntid_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h00) &&
                            (rk == 5'h18) && (in_inst[4:0] == 5'h00);
    assign inst_rdcntvl_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h00) &&
                            (rk == 5'h18) && (in_inst[9:5] == 5'h00) &&
                            (in_inst[4:0] != 5'h00);
    assign inst_rdcntvh_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) &&
                            (op_21_20 == 2'h0) && (op_19_15 == 5'h00) &&
                            (rk == 5'h19) && (in_inst[9:5] == 5'h00);
    assign inst_cacop   = (op_31_26 == 6'h01) && (op_25_22 == 4'h8);

    assign src2_is_rd = inst_beq | inst_bne | inst_blt | inst_bge | inst_bltu | inst_bgeu |
                        inst_st_b | inst_st_h | inst_st_w | inst_csrwr | inst_csrxchg;
    assign src1_addr = in_inst[9:5];
    assign src2_addr = src2_is_rd ? in_inst[4:0] : in_inst[14:10];

    assign op1_forwarded = (forward_ex1_valid && (forward_ex1_waddr != 5'b0) && (forward_ex1_waddr == src1_addr)) ? forward_ex1_wdata :
                           (forward_ex2_valid && (forward_ex2_waddr != 5'b0) && (forward_ex2_waddr == src1_addr)) ? forward_ex2_wdata :
                           (forward_mem_valid && (forward_mem_waddr != 5'b0) && (forward_mem_waddr == src1_addr)) ? forward_mem_wdata :
                           (forward_wb_valid  && (forward_wb_waddr  != 5'b0) && (forward_wb_waddr  == src1_addr)) ? forward_wb_wdata  :
                           in_op1;

    assign op2_forwarded = (forward_ex1_valid && (forward_ex1_waddr != 5'b0) && (forward_ex1_waddr == src2_addr)) ? forward_ex1_wdata :
                           (forward_ex2_valid && (forward_ex2_waddr != 5'b0) && (forward_ex2_waddr == src2_addr)) ? forward_ex2_wdata :
                           (forward_mem_valid && (forward_mem_waddr != 5'b0) && (forward_mem_waddr == src2_addr)) ? forward_mem_wdata :
                           (forward_wb_valid  && (forward_wb_waddr  != 5'b0) && (forward_wb_waddr  == src2_addr)) ? forward_wb_wdata  :
                           in_op2;
    assign op1_signed = op1_forwarded;
    assign op2_signed = op2_forwarded;

    assign csr_write_data_w = in_csr_mask ? ((op1_forwarded & op2_forwarded) | (~op1_forwarded & csr_read_data)) : op2_forwarded;
    assign mul_signed_w = op1_signed * op2_signed;
    assign mul_unsigned_w = op1_forwarded * op2_forwarded;
    assign div_signed_neg_w = op1_forwarded[31] ^ op2_forwarded[31];
    assign div_signed_abs1_w = op1_forwarded[31] ? (~op1_forwarded + 32'b1) : op1_forwarded;
    assign div_signed_abs2_w = op2_forwarded[31] ? (~op2_forwarded + 32'b1) : op2_forwarded;
    assign div_signed_abs2_safe_w = (div_signed_abs2_w == 32'b0) ? 32'b1 : div_signed_abs2_w;
    assign div_signed_quot_abs_w = div_signed_abs1_w / div_signed_abs2_safe_w;
    assign div_signed_rem_abs_w = div_signed_abs1_w % div_signed_abs2_safe_w;
    assign div_signed_w = (op2_forwarded == 32'b0) ? 32'hffffffff :
                          div_signed_neg_w ? (~div_signed_quot_abs_w + 32'b1) : div_signed_quot_abs_w;
    assign div_unsigned_w = (op2_forwarded == 32'b0) ? 32'hffffffff : (op1_forwarded / op2_forwarded);
    assign mod_signed_w = (op2_forwarded == 32'b0) ? op1_forwarded :
                          op1_forwarded[31] ? (~div_signed_rem_abs_w + 32'b1) : div_signed_rem_abs_w;
    assign mod_unsigned_w = (op2_forwarded == 32'b0) ? op1_forwarded : (op1_forwarded % op2_forwarded);
    assign branch_take_w = inst_b | inst_bl | inst_jirl |
                           (inst_beq && (op1_forwarded == op2_forwarded)) |
                           (inst_bne && (op1_forwarded != op2_forwarded)) |
                           (inst_blt && ($signed(op1_forwarded) < $signed(op2_forwarded))) |
                           (inst_bge && ($signed(op1_forwarded) >= $signed(op2_forwarded))) |
                           (inst_bltu && (op1_forwarded < op2_forwarded)) |
                           (inst_bgeu && (op1_forwarded >= op2_forwarded));
    assign branch_target_w = inst_jirl ? (op1_forwarded + in_imm) : (in_pc + in_imm);

    always @(*) begin
        ex_result = 32'b0;

        if (inst_lu12i_w) begin
            ex_result = in_imm;
        end else if (inst_pcaddi || inst_pcaddu12i) begin
            ex_result = in_pc + in_imm;
        end else if (inst_add_w) begin
            ex_result = op1_forwarded + op2_forwarded;
        end else if (inst_addi_w ||
                     inst_ld_b || inst_ld_h || inst_ld_w || inst_ld_bu || inst_ld_hu ||
                     inst_st_b || inst_st_h || inst_st_w || inst_cacop) begin
            ex_result = op1_forwarded + in_imm;
        end else if (inst_sub_w) begin
            ex_result = op1_forwarded - op2_forwarded;
        end else if (inst_slt) begin
            ex_result = ($signed(op1_forwarded) < $signed(op2_forwarded)) ? 32'd1 : 32'd0;
        end else if (inst_slti) begin
            ex_result = ($signed(op1_forwarded) < $signed(in_imm)) ? 32'd1 : 32'd0;
        end else if (inst_sltu) begin
            ex_result = (op1_forwarded < op2_forwarded) ? 32'd1 : 32'd0;
        end else if (inst_sltui) begin
            ex_result = (op1_forwarded < in_imm) ? 32'd1 : 32'd0;
        end else if (inst_and) begin
            ex_result = op1_forwarded & op2_forwarded;
        end else if (inst_andi) begin
            ex_result = op1_forwarded & in_imm;
        end else if (inst_or) begin
            ex_result = op1_forwarded | op2_forwarded;
        end else if (inst_ori) begin
            ex_result = op1_forwarded | in_imm;
        end else if (inst_xor) begin
            ex_result = op1_forwarded ^ op2_forwarded;
        end else if (inst_xori) begin
            ex_result = op1_forwarded ^ in_imm;
        end else if (inst_nor) begin
            ex_result = ~(op1_forwarded | op2_forwarded);
        end else if (inst_sll_w) begin
            ex_result = op1_forwarded << op2_forwarded[4:0];
        end else if (inst_slli_w) begin
            ex_result = op1_forwarded << rk[4:0];
        end else if (inst_srl_w) begin
            ex_result = op1_forwarded >> op2_forwarded[4:0];
        end else if (inst_srli_w) begin
            ex_result = op1_forwarded >> rk[4:0];
        end else if (inst_sra_w) begin
            ex_result = $signed(op1_forwarded) >>> op2_forwarded[4:0];
        end else if (inst_srai_w) begin
            ex_result = $signed(op1_forwarded) >>> rk[4:0];
        end else if (inst_mul_w) begin
            ex_result = mul_signed_w[31:0];
        end else if (inst_mulh_w) begin
            ex_result = mul_signed_w[63:32];
        end else if (inst_mulh_wu) begin
            ex_result = mul_unsigned_w[63:32];
        end else if (inst_div_w) begin
            ex_result = div_signed_w;
        end else if (inst_div_wu) begin
            ex_result = div_unsigned_w;
        end else if (inst_mod_w) begin
            ex_result = mod_signed_w;
        end else if (inst_mod_wu) begin
            ex_result = mod_unsigned_w;
        end else if (inst_bl || inst_jirl) begin
            ex_result = in_pc + 32'd4;
        end else if (inst_rdcntvl_w) begin
            ex_result = 32'b0;
        end else if (inst_rdcntvh_w) begin
            ex_result = 32'b0;
        end else if (in_is_csr) begin
            ex_result = csr_read_data;
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            branch_update_valid <= 1'b0;
            branch_taken        <= 1'b0;
            branch_target       <= 32'b0;
            out_valid      <= 1'b0;
            out_pc         <= 32'b0;
            out_inst       <= 32'b0;
            out_rd         <= 5'b0;
            out_result     <= 32'b0;
            out_op1        <= 32'b0;
            out_op2        <= 32'b0;
            out_is_load    <= 1'b0;
            out_is_store   <= 1'b0;
            out_store_data <= 32'b0;
            out_is_csr     <= 1'b0;
            out_csr_we     <= 1'b0;
            out_csr_addr   <= 14'b0;
            out_csr_wdata  <= 32'b0;
            out_exception_valid      <= 1'b0;
            out_exception_ecode      <= 6'b0;
            out_exception_esubcode   <= 9'b0;
            out_exception_badv_valid <= 1'b0;
            out_exception_badv       <= 32'b0;
        end else begin
            branch_update_valid <= in_valid && in_is_branch;
            branch_taken        <= in_valid && branch_take_w;
            branch_target       <= branch_target_w;
            out_valid      <= in_valid;
            out_pc         <= in_pc;
            out_inst       <= in_inst;
            out_rd         <= in_rd;
            out_result     <= ex_result;
            out_op1        <= op1_forwarded;
            out_op2        <= op2_forwarded;
            out_is_load    <= in_is_load;
            out_is_store   <= in_is_store;
            out_store_data <= op2_forwarded;
            out_is_csr     <= in_is_csr;
            out_csr_we     <= in_csr_we;
            out_csr_addr   <= in_csr_addr;
            out_csr_wdata  <= csr_write_data_w;
            out_exception_valid      <= in_exception_valid;
            out_exception_ecode      <= in_exception_ecode;
            out_exception_esubcode   <= in_exception_esubcode;
            out_exception_badv_valid <= in_exception_badv_valid;
            out_exception_badv       <= in_exception_badv;
        end
    end

endmodule
