`ifdef VERILATOR
`ifndef MDU
`define S4_EX_FAST_MDU
`endif
`endif

module s4_ex (
    input  wire        clk,
    input  wire        reset,
    input  wire        flush,
    input  wire        next_allowin,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire        in_pred_taken,
    input  wire [31:0] in_pred_target,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_op1,
    input  wire [31:0] in_op2,
    input  wire [31:0] in_imm,
    input  wire        in_use_imm,
    input  wire        in_is_branch,
    input  wire [3:0]  in_branch_type,
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
    output reg         branch_mispredict,
`ifdef PERF_MONI
    output reg         bpu_perf_valid,
    output reg         bpu_perf_is_branch,
    output reg         bpu_perf_is_jump,
    output reg  [31:0] bpu_perf_pc,
    output reg         bpu_perf_pred_taken,
    output reg         bpu_perf_actual_taken,
    output reg         bpu_perf_correct,
    output reg         bpu_perf_direction_miss,
    output reg         bpu_perf_target_miss,
    output reg         bpu_perf_exu_flush,
    output reg         bpu_perf_is_direct_jump,
    output reg         bpu_perf_is_jirl,
    output reg         bpu_perf_is_ret_jirl,
    output reg         bpu_perf_is_indirect_jirl,
`endif
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
    output reg  [31:0] out_exception_badv,
    output wire        ex_allowin
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
    wire [9:0]  mul_div_op_w;
    wire [31:0] mul_result_w;
    wire [31:0] div_signed_w;
    wire [31:0] div_unsigned_w;
    wire [31:0] mod_signed_w;
    wire [31:0] mod_unsigned_w;
`ifdef S4_EX_FAST_MDU
    wire [63:0] mul_signed_w;
    wire [63:0] mul_unsigned_w;
    wire        div_signed_neg_w;
    wire [31:0] div_signed_abs1_w;
    wire [31:0] div_signed_abs2_w;
    wire [31:0] div_signed_abs2_safe_w;
    wire [31:0] div_signed_quot_abs_w;
    wire [31:0] div_signed_rem_abs_w;
`else
    wire        mul_inst_w;
    wire        mul_active_w;
    wire        multiplier_start_w;
    wire        multiplier_done_w;
    wire        divmod_inst_w;
    wire        divmod_active_w;
    wire        div_signed_op_w;
    wire        divider_start_w;
    wire        divider_complete_w;
    wire [31:0] divider_quot_w;
    wire [31:0] divider_rem_w;
    reg         mul_busy_r;
    reg         mul_done_r;
    reg  [31:0] mul_result_r;
    reg         div_active_r;
    reg         div_done_r;
`endif
    wire        unused_timer_64;
    wire        branch_take_w;
    wire [31:0] branch_target_w;
    wire        branch_is_jirl_w;
    wire        branch_is_b_w;
    wire        branch_is_bl_w;
    wire        branch_is_cond_w;
    wire        control_flow_w;
    wire        actual_taken_w;
    wire [31:0] actual_next_pc_w;
    wire [31:0] predicted_next_pc_w;
    wire        direction_miss_w;
    wire        target_miss_w;
    wire        redirect_miss_w;
    wire        ex_slot_allowin_w;
    wire        ex_ready_go_w;

    assign ex_slot_allowin_w = !out_valid || next_allowin;
`ifdef S4_EX_FAST_MDU
    assign ex_ready_go_w = 1'b1;
`else
    assign ex_ready_go_w = (!mul_active_w || mul_done_r) &&
                           (!divmod_active_w || div_done_r);
`endif
    assign ex_allowin = ex_slot_allowin_w && ex_ready_go_w;

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
    assign mul_div_op_w = {3'b0, inst_mod_wu, inst_mod_w, inst_div_wu, inst_div_w,
                           inst_mulh_wu, inst_mulh_w, inst_mul_w};
`ifdef S4_EX_FAST_MDU
    assign mul_signed_w = op1_signed * op2_signed;
    assign mul_unsigned_w = op1_forwarded * op2_forwarded;
    assign mul_result_w =
        inst_mul_w   ? mul_signed_w[31:0] :
        inst_mulh_w  ? mul_signed_w[63:32] :
        inst_mulh_wu ? mul_unsigned_w[63:32] :
                       32'b0;
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
`else
    assign mul_inst_w = inst_mul_w | inst_mulh_w | inst_mulh_wu;
    assign mul_active_w = in_valid && !in_exception_valid && mul_inst_w;
    assign multiplier_start_w = ex_slot_allowin_w && mul_active_w &&
                                !mul_busy_r && !mul_done_r;

    mul u_mul (
        .clk        (clk),
        .reset      (reset || flush),
        .mult       (multiplier_start_w),
        .mul_div_op (mul_div_op_w),
        .alu_src1   (op1_forwarded),
        .alu_src2   (op2_forwarded),
        .mul_result (mul_result_w),
        .done       (multiplier_done_w)
    );

    assign divmod_inst_w = inst_div_w | inst_div_wu | inst_mod_w | inst_mod_wu;
    assign divmod_active_w = in_valid && !in_exception_valid && divmod_inst_w;
    assign div_signed_op_w = inst_div_w | inst_mod_w;
    assign divider_start_w = ex_slot_allowin_w && divmod_active_w &&
                             !div_active_r && !div_done_r;

    divider u_divider (
        .div_clk    (clk),
        .reset      (reset || flush),
        .div        (divider_start_w),
        .div_signed (div_signed_op_w),
        .x          (op1_forwarded),
        .y          (op2_forwarded),
        .s          (divider_quot_w),
        .r          (divider_rem_w),
        .complete   (divider_complete_w)
    );

    assign div_signed_w   = (op2_forwarded == 32'b0) ? 32'hffffffff : divider_quot_w;
    assign div_unsigned_w = (op2_forwarded == 32'b0) ? 32'hffffffff : divider_quot_w;
    assign mod_signed_w   = (op2_forwarded == 32'b0) ? op1_forwarded : divider_rem_w;
    assign mod_unsigned_w = (op2_forwarded == 32'b0) ? op1_forwarded : divider_rem_w;
`endif
    assign branch_is_jirl_w = (in_branch_type == 4'd1);
    assign branch_is_b_w    = (in_branch_type == 4'd2);
    assign branch_is_bl_w   = (in_branch_type == 4'd3);
    assign branch_is_cond_w = (in_branch_type >= 4'd4);
    assign branch_take_w =
        branch_is_jirl_w | branch_is_b_w | branch_is_bl_w |
        ((in_branch_type == 4'd4) && (op1_forwarded == op2_forwarded)) |
        ((in_branch_type == 4'd5) && (op1_forwarded != op2_forwarded)) |
        ((in_branch_type == 4'd6) && ($signed(op1_forwarded) < $signed(op2_forwarded))) |
        ((in_branch_type == 4'd7) && ($signed(op1_forwarded) >= $signed(op2_forwarded))) |
        ((in_branch_type == 4'd8) && (op1_forwarded < op2_forwarded)) |
        ((in_branch_type == 4'd9) && (op1_forwarded >= op2_forwarded));
    assign branch_target_w = branch_is_jirl_w ? (op1_forwarded + in_imm) : (in_pc + in_imm);
    assign control_flow_w = in_valid && in_is_branch;
    assign actual_taken_w = branch_take_w;
    assign actual_next_pc_w = actual_taken_w ? branch_target_w : (in_pc + 32'd4);
    assign predicted_next_pc_w = in_pred_taken ? in_pred_target : (in_pc + 32'd4);
    assign direction_miss_w = control_flow_w && (in_pred_taken != actual_taken_w);
    assign target_miss_w =
        control_flow_w && actual_taken_w && in_pred_taken &&
        (in_pred_target != branch_target_w);
    assign redirect_miss_w = control_flow_w && (predicted_next_pc_w != actual_next_pc_w);

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
        end else if (inst_mul_w || inst_mulh_w || inst_mulh_wu) begin
`ifdef S4_EX_FAST_MDU
            ex_result = mul_result_w;
`else
            ex_result = mul_result_r;
`endif
        end else if (inst_div_w) begin
            ex_result = div_signed_w;
        end else if (inst_div_wu) begin
            ex_result = div_unsigned_w;
        end else if (inst_mod_w) begin
            ex_result = mod_signed_w;
        end else if (inst_mod_wu) begin
            ex_result = mod_unsigned_w;
        end else if (branch_is_bl_w || branch_is_jirl_w) begin
            ex_result = in_pc + 32'd4;
        end else if (inst_rdcntvl_w) begin
            ex_result = 32'b0;
        end else if (inst_rdcntvh_w) begin
            ex_result = 32'b0;
        end else if (in_is_csr) begin
            ex_result = csr_read_data;
        end
    end

`ifndef S4_EX_FAST_MDU
    always @(posedge clk) begin
        if (reset || flush) begin
            mul_busy_r  <= 1'b0;
            mul_done_r  <= 1'b0;
            mul_result_r <= 32'b0;
            div_active_r <= 1'b0;
            div_done_r   <= 1'b0;
        end else begin
            if (multiplier_start_w) begin
                mul_busy_r <= 1'b1;
                mul_done_r <= 1'b0;
            end else if (multiplier_done_w) begin
                mul_busy_r   <= 1'b0;
                mul_result_r <= mul_result_w;
                mul_done_r   <= 1'b1;
            end

            if (divider_start_w) begin
                div_active_r <= 1'b1;
                div_done_r   <= 1'b0;
            end else if (divider_complete_w) begin
                div_active_r <= 1'b0;
                div_done_r   <= 1'b1;
            end

            if (ex_allowin) begin
                mul_done_r <= 1'b0;
                div_done_r <= 1'b0;
            end
        end
    end
`endif

    always @(posedge clk) begin
        if (reset) begin
            branch_update_valid <= 1'b0;
            branch_taken        <= 1'b0;
            branch_target       <= 32'b0;
            branch_mispredict   <= 1'b0;
`ifdef PERF_MONI
            bpu_perf_valid          <= 1'b0;
            bpu_perf_is_branch      <= 1'b0;
            bpu_perf_is_jump        <= 1'b0;
            bpu_perf_pc             <= 32'b0;
            bpu_perf_pred_taken     <= 1'b0;
            bpu_perf_actual_taken   <= 1'b0;
            bpu_perf_correct        <= 1'b0;
            bpu_perf_direction_miss <= 1'b0;
            bpu_perf_target_miss    <= 1'b0;
            bpu_perf_exu_flush      <= 1'b0;
            bpu_perf_is_direct_jump   <= 1'b0;
            bpu_perf_is_jirl          <= 1'b0;
            bpu_perf_is_ret_jirl      <= 1'b0;
            bpu_perf_is_indirect_jirl <= 1'b0;
`endif
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
        end else if (flush) begin
            branch_update_valid <= 1'b0;
            branch_taken        <= 1'b0;
            branch_target       <= 32'b0;
            branch_mispredict   <= 1'b0;
`ifdef PERF_MONI
            bpu_perf_valid          <= 1'b0;
            bpu_perf_exu_flush      <= 1'b0;
`endif
            out_valid <= 1'b0;
        end else if (ex_allowin) begin
            branch_update_valid <= in_valid && in_is_branch;
            branch_taken        <= in_valid && branch_take_w;
            branch_target       <= branch_target_w;
            branch_mispredict   <= redirect_miss_w;
`ifdef PERF_MONI
            bpu_perf_valid          <= control_flow_w;
            bpu_perf_is_branch      <= control_flow_w && branch_is_cond_w;
            bpu_perf_is_jump        <= control_flow_w && !branch_is_cond_w;
            bpu_perf_pc             <= in_pc;
            bpu_perf_pred_taken     <= in_pred_taken;
            bpu_perf_actual_taken   <= actual_taken_w;
            bpu_perf_correct        <= control_flow_w && !redirect_miss_w;
            bpu_perf_direction_miss <= direction_miss_w;
            bpu_perf_target_miss    <= target_miss_w;
            bpu_perf_exu_flush      <= redirect_miss_w;
            bpu_perf_is_direct_jump   <= control_flow_w && (branch_is_b_w || branch_is_bl_w);
            bpu_perf_is_jirl          <= control_flow_w && branch_is_jirl_w &&
                                         (in_inst[4:0] == 5'h01);
            bpu_perf_is_ret_jirl      <= control_flow_w && branch_is_jirl_w &&
                                         (in_inst[4:0] == 5'h00) &&
                                         (in_inst[9:5] == 5'h01);
            bpu_perf_is_indirect_jirl <= control_flow_w && branch_is_jirl_w &&
                                         (in_inst[4:0] == 5'h00) &&
                                         (in_inst[9:5] != 5'h01);
`endif
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
        end else if (out_valid && next_allowin) begin
            branch_update_valid <= 1'b0;
            branch_taken        <= 1'b0;
            branch_target       <= 32'b0;
            branch_mispredict   <= 1'b0;
`ifdef PERF_MONI
            bpu_perf_valid          <= 1'b0;
            bpu_perf_exu_flush      <= 1'b0;
`endif
            out_valid <= 1'b0;
        end else begin
            branch_update_valid <= 1'b0;
            branch_taken        <= 1'b0;
            branch_target       <= 32'b0;
            branch_mispredict   <= 1'b0;
`ifdef PERF_MONI
            bpu_perf_valid          <= 1'b0;
            bpu_perf_exu_flush      <= 1'b0;
`endif
        end
    end

endmodule

`ifdef S4_EX_FAST_MDU
`undef S4_EX_FAST_MDU
`endif
