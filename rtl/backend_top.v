`include "la_core_defs.vh"

module backend_top #(
    parameter TLB_ENABLE = `LA_TLB_ENABLE,
    parameter CACHE_OP_STRICT_ENABLE = `LA_CACHE_OP_STRICT_ENABLE
) (
    input  wire        clk,
    input  wire        reset,
    input  wire [7:0]  interrupt,

    input  wire        fetch_valid,
    input  wire [31:0] fetch_pc,
    input  wire [31:0] fetch_inst,
    input  wire        fetch_pred_taken,
    input  wire [31:0] fetch_pred_target,
    input  wire        fetch_exception_valid,
    input  wire [5:0]  fetch_exception_ecode,
    input  wire [8:0]  fetch_exception_esubcode,
    input  wire        fetch_exception_badv_valid,
    input  wire [31:0] fetch_exception_badv,
    input  wire        i_tlb_query_valid,
    input  wire        i_tlb_query_write,
    input  wire [31:0] i_tlb_query_vaddr,
    output wire        i_tlb_resp_valid,
    output wire [31:0] i_tlb_resp_vaddr,
    output wire [31:0] i_tlb_query_paddr,
    output wire        i_tlb_exception_valid,
    output wire [5:0]  i_tlb_exception_ecode,

    output wire        dmem_req_valid,
    output wire        dmem_req_write,
    output wire [31:0] dmem_req_addr,
    output wire [31:0] dmem_req_wdata,
    output wire [3:0]  dmem_req_wstrb,
    input  wire        dmem_req_ready,
    input  wire        dmem_resp_valid,
    input  wire [31:0] dmem_resp_rdata,

    output wire        branch_update_valid,
    output wire        branch_taken,
    output wire [31:0] branch_pc,
    output wire [31:0] branch_target,
    output wire        branch_mispredict,
    output wire        early_redirect_valid,
    output wire [31:0] early_redirect_pc,
    output wire        exception_redirect_valid,
    output wire [31:0] exception_redirect_pc,
    output wire        ertn_redirect_valid,
    output wire [31:0] ertn_redirect_pc,
    output wire        refetch_redirect_valid,
    output wire [31:0] refetch_redirect_pc,
    output wire        icacop_valid,
    output wire [1:0]  icacop_mode,
    output wire [31:0] icacop_addr,
`ifdef PERF_MONI
    output wire        bpu_perf_valid,
    output wire        bpu_perf_is_branch,
    output wire        bpu_perf_is_jump,
    output wire [31:0] bpu_perf_pc,
    output wire        bpu_perf_pred_taken,
    output wire        bpu_perf_actual_taken,
    output wire        bpu_perf_correct,
    output wire        bpu_perf_direction_miss,
    output wire        bpu_perf_target_miss,
    output wire        bpu_perf_exu_flush,
    output wire        bpu_perf_is_direct_jump,
    output wire        bpu_perf_is_jirl,
    output wire        bpu_perf_is_ret_jirl,
    output wire        bpu_perf_is_indirect_jirl,
`endif

    input  wire [4:0]  dbg_reg_num,
    output wire [31:0] dbg_rf_rdata,

    output wire        ws_valid,
    output wire        d1_allowin,
    output wire [31:0] debug_wb_pc,
    output wire [3:0]  debug_wb_rf_wen,
    output wire [4:0]  debug_wb_rf_wnum,
    output wire [31:0] debug_wb_rf_wdata,
    output wire [31:0] debug_wb_inst,
    output wire        debug_excp_valid,
    output wire [5:0]  debug_excp_ecode,
    output wire [10:0] debug_intr_no,
    output wire        debug_ertn_valid
);

    wire unused_ready;
    assign unused_ready = dmem_req_ready;
    wire unused_backend_cfg;
    assign unused_backend_cfg = &{1'b0, TLB_ENABLE[0], CACHE_OP_STRICT_ENABLE[0]};

    wire rf_we_w;
    wire [4:0] rf_waddr_w;
    wire [31:0] rf_wdata_w;

    wire rrd_out_valid_w;
    wire [31:0] rrd_out_pc_w;
    wire [31:0] rrd_out_inst_w;
    wire rrd_out_pred_taken_w;
    wire [31:0] rrd_out_pred_target_w;
    wire [4:0] rrd_out_rd_w;
    wire [31:0] rrd_out_op1_w;
    wire [31:0] rrd_out_op2_w;
    wire [31:0] rrd_out_imm_w;
    wire rrd_out_use_imm_w;
    wire rrd_out_is_branch_w;
    wire rrd_out_is_load_w;
    wire rrd_out_is_store_w;
    wire rrd_out_is_muldiv_w;
    wire rrd_out_is_csr_w;
    wire rrd_out_csr_we_w;
    wire rrd_out_csr_mask_w;
    wire [13:0] rrd_out_csr_addr_w;
    wire rrd_out_exception_valid_w;
    wire [5:0] rrd_out_exception_ecode_w;
    wire [8:0] rrd_out_exception_esubcode_w;
    wire rrd_out_exception_badv_valid_w;
    wire [31:0] rrd_out_exception_badv_w;

    wire ex1_out_valid_w;
    wire [31:0] ex1_out_pc_w;
    wire [31:0] ex1_out_inst_w;
    wire [4:0] ex1_out_rd_w;
    wire [31:0] ex1_out_result_w;
    wire [31:0] ex1_out_op1_w;
    wire [31:0] ex1_out_op2_w;
    wire ex1_out_is_load_w;
    wire ex1_out_is_store_w;
    wire [31:0] ex1_out_store_data_w;
    wire ex1_out_is_csr_w;
    wire ex1_out_csr_we_w;
    wire [13:0] ex1_out_csr_addr_w;
    wire [31:0] ex1_out_csr_wdata_w;
    wire ex1_out_exception_valid_w;
    wire [5:0] ex1_out_exception_ecode_w;
    wire [8:0] ex1_out_exception_esubcode_w;
    wire ex1_out_exception_badv_valid_w;
    wire [31:0] ex1_out_exception_badv_w;

    wire mem1_out_valid_w;
    wire [31:0] mem1_out_pc_w;
    wire [31:0] mem1_out_inst_w;
    wire [4:0] mem1_out_rd_w;
    wire [31:0] mem1_out_wb_data_w;
    wire [31:0] mem1_out_op1_w;
    wire [31:0] mem1_out_op2_w;
    wire mem1_out_wen_w;
    wire mem1_out_csr_we_w;
    wire [13:0] mem1_out_csr_addr_w;
    wire [31:0] mem1_out_csr_wdata_w;
    wire mem1_out_exception_valid_w;
    wire [5:0] mem1_out_exception_ecode_w;
    wire [8:0] mem1_out_exception_esubcode_w;
    wire mem1_out_exception_badv_valid_w;
    wire [31:0] mem1_out_exception_badv_w;

    wire csr_we_w;
    wire [13:0] csr_addr_w;
    wire [31:0] csr_wdata_w;
    wire [13:0] csr_read_addr_w;
    wire [31:0] csr_read_data_w;
    wire csr_timer_tick_w;
    wire [31:0] csr_exception_entry_w;
    wire [31:0] csr_ertn_pc_w;
    wire [63:0] csr_timer_64_w;
    wire csr_has_int_w;
    wire [10:0] csr_interrupt_pending_w;
    wire d_tlb_query_valid_w;
    wire d_tlb_query_write_w;
    wire [31:0] d_tlb_query_vaddr_w;
    wire [31:0] d_tlb_query_paddr_w;
    wire [31:0] d_tlb_resp_vaddr_w;
    wire d_tlb_resp_valid_w;
    wire d_tlb_exception_valid_w;
    wire [5:0] d_tlb_exception_ecode_w;
    wire [31:0] i_tlb_query_paddr_w;
    wire [31:0] i_tlb_resp_vaddr_w;
    wire i_tlb_resp_valid_w;
    wire i_tlb_exception_valid_w;
    wire [5:0] i_tlb_exception_ecode_w;
    wire mem1_is_syscall_w;
    wire mem1_is_break_w;
    wire mem1_is_ertn_w;
    wire mem1_is_tlbsrch_w;
    wire mem1_is_tlbrd_w;
    wire mem1_is_tlbwr_w;
    wire mem1_is_tlbfill_w;
    wire mem1_is_invtlb_w;
    wire mem1_is_ibar_w;
    wire mem1_is_cacop_w;
    wire mem1_is_icacop_w;
    wire mem1_needs_refetch_w;
    wire mem1_is_ine_w;
    wire mem1_exception_w;
    wire mem1_interrupt_w;
    wire [5:0] mem1_exception_ecode_w;
    wire [8:0] mem1_exception_esubcode_w;
    wire mem1_exception_badv_valid_w;
    wire [31:0] mem1_exception_badv_w;
    wire ex_branch_update_valid_raw_w;
    wire ex_branch_taken_raw_w;
    wire [31:0] ex_branch_target_raw_w;
    wire ex_branch_mispredict_raw_w;

    function is_valid_la32_inst;
        input [31:0] inst;
        reg [5:0] op_31_26;
        reg [3:0] op_25_22;
        reg [1:0] op_21_20;
        reg [4:0] op_19_15;
        reg [4:0] rj;
        reg [4:0] rk;
        reg [4:0] rd;
        reg inst_add_w;
        reg inst_sub_w;
        reg inst_slt;
        reg inst_sltu;
        reg inst_nor;
        reg inst_and;
        reg inst_or;
        reg inst_xor;
        reg inst_orn;
        reg inst_andn;
        reg inst_sll_w;
        reg inst_srl_w;
        reg inst_sra_w;
        reg inst_mul_w;
        reg inst_mulh_w;
        reg inst_mulh_wu;
        reg inst_div_w;
        reg inst_mod_w;
        reg inst_div_wu;
        reg inst_mod_wu;
        reg inst_break;
        reg inst_syscall;
        reg inst_slli_w;
        reg inst_srli_w;
        reg inst_srai_w;
        reg inst_idle;
        reg inst_invtlb;
        reg inst_dbar;
        reg inst_ibar;
        reg inst_slti;
        reg inst_sltui;
        reg inst_addi_w;
        reg inst_andi;
        reg inst_ori;
        reg inst_xori;
        reg inst_ld_b;
        reg inst_ld_h;
        reg inst_ld_w;
        reg inst_st_b;
        reg inst_st_h;
        reg inst_st_w;
        reg inst_ld_bu;
        reg inst_ld_hu;
        reg inst_cacop;
        reg inst_preld;
        reg inst_jirl;
        reg inst_b;
        reg inst_bl;
        reg inst_beq;
        reg inst_bne;
        reg inst_blt;
        reg inst_bge;
        reg inst_bltu;
        reg inst_bgeu;
        reg inst_lu12i_w;
        reg inst_pcaddi;
        reg inst_pcaddu12i;
        reg inst_csrxchg;
        reg inst_ll_w;
        reg inst_sc_w;
        reg inst_csrrd;
        reg inst_csrwr;
        reg inst_rdcntid_w;
        reg inst_rdcntvl_w;
        reg inst_rdcntvh_w;
        reg inst_ertn;
        reg inst_tlbsrch;
        reg inst_tlbrd;
        reg inst_tlbwr;
        reg inst_tlbfill;
        reg inst_cpucfg;
        begin
            op_31_26 = inst[31:26];
            op_25_22 = inst[25:22];
            op_21_20 = inst[21:20];
            op_19_15 = inst[19:15];
            rj       = inst[9:5];
            rk       = inst[14:10];
            rd       = inst[4:0];

            inst_add_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h00);
            inst_sub_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h02);
            inst_slt       = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h04);
            inst_sltu      = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h05);
            inst_nor       = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h08);
            inst_and       = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h09);
            inst_or        = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0a);
            inst_xor       = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0b);
            inst_orn       = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0c);
            inst_andn      = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0d);
            inst_sll_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0e);
            inst_srl_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0f);
            inst_sra_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h10);
            inst_mul_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h18);
            inst_mulh_w    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h19);
            inst_mulh_wu   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h1a);
            inst_div_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h00);
            inst_mod_w     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h01);
            inst_div_wu    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h02);
            inst_mod_wu    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h03);
            inst_break     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h14);
            inst_syscall   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h2) && (op_19_15 == 5'h16);
            inst_slli_w    = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h01);
            inst_srli_w    = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h09);
            inst_srai_w    = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h11);
            inst_idle      = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h11);
            inst_invtlb    = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h13) && (rd <= 5'd6);
            inst_dbar      = (op_31_26 == 6'h0e) && (op_25_22 == 4'h1) && (op_21_20 == 2'h3) && (op_19_15 == 5'h04);
            inst_ibar      = (op_31_26 == 6'h0e) && (op_25_22 == 4'h1) && (op_21_20 == 2'h3) && (op_19_15 == 5'h05);
            inst_slti      = (op_31_26 == 6'h00) && (op_25_22 == 4'h8);
            inst_sltui     = (op_31_26 == 6'h00) && (op_25_22 == 4'h9);
            inst_addi_w    = (op_31_26 == 6'h00) && (op_25_22 == 4'ha);
            inst_andi      = (op_31_26 == 6'h00) && (op_25_22 == 4'hd);
            inst_ori       = (op_31_26 == 6'h00) && (op_25_22 == 4'he);
            inst_xori      = (op_31_26 == 6'h00) && (op_25_22 == 4'hf);
            inst_ld_b      = (op_31_26 == 6'h0a) && (op_25_22 == 4'h0);
            inst_ld_h      = (op_31_26 == 6'h0a) && (op_25_22 == 4'h1);
            inst_ld_w      = (op_31_26 == 6'h0a) && (op_25_22 == 4'h2);
            inst_st_b      = (op_31_26 == 6'h0a) && (op_25_22 == 4'h4);
            inst_st_h      = (op_31_26 == 6'h0a) && (op_25_22 == 4'h5);
            inst_st_w      = (op_31_26 == 6'h0a) && (op_25_22 == 4'h6);
            inst_ld_bu     = (op_31_26 == 6'h0a) && (op_25_22 == 4'h8);
            inst_ld_hu     = (op_31_26 == 6'h0a) && (op_25_22 == 4'h9);
            inst_cacop     = (op_31_26 == 6'h01) && (op_25_22 == 4'h8);
            inst_preld     = (op_31_26 == 6'h0a) && (op_25_22 == 4'hb);
            inst_jirl      = (op_31_26 == 6'h13);
            inst_b         = (op_31_26 == 6'h14);
            inst_bl        = (op_31_26 == 6'h15);
            inst_beq       = (op_31_26 == 6'h16);
            inst_bne       = (op_31_26 == 6'h17);
            inst_blt       = (op_31_26 == 6'h18);
            inst_bge       = (op_31_26 == 6'h19);
            inst_bltu      = (op_31_26 == 6'h1a);
            inst_bgeu      = (op_31_26 == 6'h1b);
            inst_lu12i_w   = (op_31_26 == 6'h05) && !inst[25];
            inst_pcaddi    = (op_31_26 == 6'h06) && !inst[25];
            inst_pcaddu12i = (op_31_26 == 6'h07) && !inst[25];
            inst_csrxchg   = (op_31_26 == 6'h01) && !inst[25] && !inst[24] && (rj != 5'h00) && (rj != 5'h01);
            inst_ll_w      = (op_31_26 == 6'h08) && !inst[25] && !inst[24];
            inst_sc_w      = (op_31_26 == 6'h08) && !inst[25] && inst[24];
            inst_csrrd     = (op_31_26 == 6'h01) && !inst[25] && !inst[24] && (rj == 5'h00);
            inst_csrwr     = (op_31_26 == 6'h01) && !inst[25] && !inst[24] && (rj == 5'h01);
            inst_rdcntid_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h0) && (op_19_15 == 5'h00) && (rk == 5'h18) && (rd == 5'h00);
            inst_rdcntvl_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h0) && (op_19_15 == 5'h00) && (rk == 5'h18) && (rj == 5'h00) && (rd != 5'h00);
            inst_rdcntvh_w = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h0) && (op_19_15 == 5'h00) && (rk == 5'h19) && (rj == 5'h00);
            inst_ertn      = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h10) && (rk == 5'h0e) && (rj == 5'h00) && (rd == 5'h00);
            inst_tlbsrch   = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h10) && (rk == 5'h0a) && (rj == 5'h00) && (rd == 5'h00);
            inst_tlbrd     = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h10) && (rk == 5'h0b) && (rj == 5'h00) && (rd == 5'h00);
            inst_tlbwr     = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h10) && (rk == 5'h0c) && (rj == 5'h00) && (rd == 5'h00);
            inst_tlbfill   = (op_31_26 == 6'h01) && (op_25_22 == 4'h9) && (op_21_20 == 2'h0) && (op_19_15 == 5'h10) && (rk == 5'h0d) && (rj == 5'h00) && (rd == 5'h00);
            inst_cpucfg    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h0) && (op_19_15 == 5'h00) && (rk == 5'h1b);

            is_valid_la32_inst = inst_add_w | inst_sub_w | inst_slt | inst_sltu |
                                  inst_nor | inst_and | inst_or | inst_xor |
                                  inst_orn | inst_andn | inst_sll_w | inst_srl_w |
                                  inst_sra_w | inst_mul_w | inst_mulh_w |
                                  inst_mulh_wu | inst_div_w | inst_mod_w |
                                  inst_div_wu | inst_mod_wu | inst_break |
                                  inst_syscall | inst_slli_w | inst_srli_w |
                                  inst_srai_w | inst_idle | inst_slti | inst_sltui |
                                  inst_addi_w | inst_andi | inst_ori | inst_xori |
                                  inst_ld_b | inst_ld_h | inst_ld_w | inst_st_b |
                                  inst_st_h | inst_st_w | inst_ld_bu | inst_ld_hu |
                                  inst_ll_w | inst_sc_w | inst_jirl | inst_b |
                                  inst_bl | inst_beq | inst_bne | inst_blt |
                                  inst_bge | inst_bltu | inst_bgeu | inst_lu12i_w |
                                  inst_pcaddi | inst_pcaddu12i | inst_csrrd |
                                  inst_csrwr | inst_csrxchg | inst_rdcntid_w |
                                  inst_rdcntvh_w | inst_rdcntvl_w | inst_ertn |
                                  inst_cacop | inst_preld | inst_dbar | inst_ibar |
                                  inst_tlbsrch | inst_tlbrd | inst_tlbwr |
                                  inst_tlbfill | inst_cpucfg | inst_invtlb;
        end
    endfunction

    assign mem1_is_syscall_w = (mem1_out_inst_w[31:26] == 6'h00) &&
                               (mem1_out_inst_w[25:22] == 4'h0) &&
                               (mem1_out_inst_w[21:20] == 2'h2) &&
                               (mem1_out_inst_w[19:15] == 5'h16);
    assign mem1_is_break_w = (mem1_out_inst_w[31:26] == 6'h00) &&
                             (mem1_out_inst_w[25:22] == 4'h0) &&
                             (mem1_out_inst_w[21:20] == 2'h2) &&
                             (mem1_out_inst_w[19:15] == 5'h14);
    assign mem1_is_ertn_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                            (mem1_out_inst_w[25:22] == 4'h9) &&
                            (mem1_out_inst_w[21:20] == 2'h0) &&
                            (mem1_out_inst_w[19:15] == 5'h10) &&
                            (mem1_out_inst_w[14:10] == 5'h0e) &&
                            (mem1_out_inst_w[9:5] == 5'h00) &&
                            (mem1_out_inst_w[4:0] == 5'h00);
    assign mem1_is_tlbsrch_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                               (mem1_out_inst_w[25:22] == 4'h9) &&
                               (mem1_out_inst_w[21:20] == 2'h0) &&
                               (mem1_out_inst_w[19:15] == 5'h10) &&
                               (mem1_out_inst_w[14:10] == 5'h0a) &&
                               (mem1_out_inst_w[9:5] == 5'h00) &&
                               (mem1_out_inst_w[4:0] == 5'h00);
    assign mem1_is_tlbrd_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                             (mem1_out_inst_w[25:22] == 4'h9) &&
                             (mem1_out_inst_w[21:20] == 2'h0) &&
                             (mem1_out_inst_w[19:15] == 5'h10) &&
                             (mem1_out_inst_w[14:10] == 5'h0b) &&
                             (mem1_out_inst_w[9:5] == 5'h00) &&
                             (mem1_out_inst_w[4:0] == 5'h00);
    assign mem1_is_tlbwr_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                             (mem1_out_inst_w[25:22] == 4'h9) &&
                             (mem1_out_inst_w[21:20] == 2'h0) &&
                             (mem1_out_inst_w[19:15] == 5'h10) &&
                             (mem1_out_inst_w[14:10] == 5'h0c) &&
                             (mem1_out_inst_w[9:5] == 5'h00) &&
                             (mem1_out_inst_w[4:0] == 5'h00);
    assign mem1_is_tlbfill_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                               (mem1_out_inst_w[25:22] == 4'h9) &&
                               (mem1_out_inst_w[21:20] == 2'h0) &&
                               (mem1_out_inst_w[19:15] == 5'h10) &&
                               (mem1_out_inst_w[14:10] == 5'h0d) &&
                               (mem1_out_inst_w[9:5] == 5'h00) &&
                               (mem1_out_inst_w[4:0] == 5'h00);
    assign mem1_is_invtlb_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                              (mem1_out_inst_w[25:22] == 4'h9) &&
                              (mem1_out_inst_w[21:20] == 2'h0) &&
                              (mem1_out_inst_w[19:15] == 5'h13) &&
                              (mem1_out_inst_w[4:0] <= 5'd6);
    assign mem1_is_ibar_w = (mem1_out_inst_w[31:26] == 6'h0e) &&
                            (mem1_out_inst_w[25:22] == 4'h1) &&
                            (mem1_out_inst_w[21:20] == 2'h3) &&
                            (mem1_out_inst_w[19:15] == 5'h05);
    assign mem1_is_cacop_w = (mem1_out_inst_w[31:26] == 6'h01) &&
                             (mem1_out_inst_w[25:22] == 4'h8);
    assign mem1_is_icacop_w = mem1_is_cacop_w && (mem1_out_inst_w[2:0] == 3'b000);
    assign mem1_interrupt_w = mem1_out_valid_w && csr_has_int_w;
    assign mem1_is_ine_w = mem1_out_valid_w && !mem1_out_exception_valid_w && !is_valid_la32_inst(mem1_out_inst_w);
    assign mem1_exception_w = mem1_out_valid_w && (mem1_interrupt_w || mem1_out_exception_valid_w || mem1_is_syscall_w || mem1_is_break_w || mem1_is_ine_w);
    assign mem1_exception_ecode_w = mem1_interrupt_w ? 6'h00 :
                                    mem1_out_exception_valid_w ? mem1_out_exception_ecode_w :
                                    mem1_is_syscall_w ? 6'h0b :
                                    mem1_is_break_w ? 6'h0c : 6'h0d;
    assign mem1_exception_esubcode_w = mem1_out_exception_valid_w ? mem1_out_exception_esubcode_w : 9'b0;
    assign mem1_exception_badv_valid_w = mem1_out_exception_valid_w && mem1_out_exception_badv_valid_w;
    assign mem1_exception_badv_w = mem1_out_exception_badv_w;
    assign exception_redirect_valid = mem1_exception_w;
    assign exception_redirect_pc = csr_exception_entry_w;
    assign ertn_redirect_valid = mem1_out_valid_w && mem1_is_ertn_w;
    assign ertn_redirect_pc = csr_ertn_pc_w;
    assign mem1_needs_refetch_w = mem1_out_csr_we_w || mem1_is_tlbsrch_w ||
                                  mem1_is_tlbrd_w ||
                                  mem1_is_tlbwr_w || mem1_is_tlbfill_w ||
                                  mem1_is_invtlb_w || mem1_is_ibar_w ||
                                  mem1_is_icacop_w;
    assign refetch_redirect_valid = mem1_out_valid_w && !mem1_exception_w &&
                                    !mem1_is_ertn_w && mem1_needs_refetch_w;
    assign refetch_redirect_pc = mem1_out_pc_w + 32'd4;
    assign icacop_valid = mem1_out_valid_w && !mem1_exception_w &&
                          !mem1_is_ertn_w && mem1_is_icacop_w;
    assign icacop_mode  = mem1_out_inst_w[4:3];
    assign icacop_addr  = mem1_out_wb_data_w;
    wire backend_redirect_flush_w;
    wire mem1_redirect_flush_w;
    assign backend_redirect_flush_w = (branch_update_valid && branch_mispredict) ||
                                      exception_redirect_valid || ertn_redirect_valid ||
                                      refetch_redirect_valid;
    assign mem1_redirect_flush_w = exception_redirect_valid || ertn_redirect_valid ||
                                   refetch_redirect_valid;
    assign branch_update_valid = ex_branch_update_valid_raw_w && !mem1_redirect_flush_w;
    assign branch_taken        = ex_branch_taken_raw_w;
    assign branch_target       = ex_branch_target_raw_w;
    assign branch_mispredict   = ex_branch_mispredict_raw_w && !mem1_redirect_flush_w;

    s3_d1 u_s3_d1 (
        .clk          (clk),
        .reset        (reset),
        .flush        (backend_redirect_flush_w),
        .next_allowin (ex_allowin_w),
        .in_valid     (fetch_valid),
        .in_pc        (fetch_pc),
        .in_inst      (fetch_inst),
        .in_pred_taken(fetch_pred_taken),
        .in_pred_target(fetch_pred_target),
        .in_exception_valid(fetch_exception_valid),
        .in_exception_ecode(fetch_exception_ecode),
        .in_exception_esubcode(fetch_exception_esubcode),
        .in_exception_badv_valid(fetch_exception_badv_valid),
        .in_exception_badv(fetch_exception_badv),
        .wb_we        (rf_we_w),
        .wb_waddr     (rf_waddr_w),
        .wb_wdata     (rf_wdata_w),
        .ex_load_valid(ex1_out_valid_w && ex1_out_is_load_w),
        .ex_load_rd   (ex1_out_rd_w),
        .m1_load_valid(m1_load_valid_w),
        .m1_load_rd   (m1_load_rd_w),
        .dbg_reg_num  (dbg_reg_num),
        .dbg_rf_rdata (dbg_rf_rdata),
        .d1_allowin   (d1_allowin_w),
        .fast_redirect_valid(early_redirect_valid),
        .fast_redirect_pc(early_redirect_pc),
        .out_valid    (rrd_out_valid_w),
        .out_pc       (rrd_out_pc_w),
        .out_inst     (rrd_out_inst_w),
        .out_pred_taken(rrd_out_pred_taken_w),
        .out_pred_target(rrd_out_pred_target_w),
        .out_rd       (rrd_out_rd_w),
        .out_op1      (rrd_out_op1_w),
        .out_op2      (rrd_out_op2_w),
        .out_imm      (rrd_out_imm_w),
        .out_use_imm  (rrd_out_use_imm_w),
        .out_is_branch(rrd_out_is_branch_w),
        .out_is_load  (rrd_out_is_load_w),
        .out_is_store (rrd_out_is_store_w),
        .out_is_muldiv(rrd_out_is_muldiv_w),
        .out_is_csr   (rrd_out_is_csr_w),
        .out_csr_we   (rrd_out_csr_we_w),
        .out_csr_mask (rrd_out_csr_mask_w),
        .out_csr_addr (rrd_out_csr_addr_w),
        .out_exception_valid(rrd_out_exception_valid_w),
        .out_exception_ecode(rrd_out_exception_ecode_w),
        .out_exception_esubcode(rrd_out_exception_esubcode_w),
        .out_exception_badv_valid(rrd_out_exception_badv_valid_w),
        .out_exception_badv(rrd_out_exception_badv_w)
    );

    assign csr_read_addr_w = rrd_out_csr_addr_w;
    assign csr_timer_tick_w = ws_valid;

    csr_stub u_csr_stub (
        .clk         (clk),
        .reset       (reset),
        .read_addr   (csr_read_addr_w),
        .read_data   (csr_read_data_w),
        .write_valid (csr_we_w),
        .write_addr  (csr_addr_w),
        .write_data  (csr_wdata_w),
        .timer_tick  (csr_timer_tick_w),
        .tlb_commit_valid(mem1_out_valid_w && !mem1_exception_w),
        .tlb_commit_inst(mem1_out_inst_w),
        .tlb_commit_op1(mem1_out_op1_w),
        .tlb_commit_op2(mem1_out_op2_w),
        .i_tlb_query_valid(i_tlb_query_valid),
        .i_tlb_query_write(i_tlb_query_write),
        .i_tlb_query_vaddr(i_tlb_query_vaddr),
        .i_tlb_resp_valid(i_tlb_resp_valid_w),
        .i_tlb_resp_vaddr(i_tlb_resp_vaddr_w),
        .i_tlb_query_paddr(i_tlb_query_paddr_w),
        .i_tlb_exception_valid(i_tlb_exception_valid_w),
        .i_tlb_exception_ecode(i_tlb_exception_ecode_w),
        .d_tlb_query_valid(d_tlb_query_valid_w),
        .d_tlb_query_write(d_tlb_query_write_w),
        .d_tlb_query_vaddr(d_tlb_query_vaddr_w),
        .d_tlb_resp_valid(d_tlb_resp_valid_w),
        .d_tlb_resp_vaddr(d_tlb_resp_vaddr_w),
        .d_tlb_query_paddr(d_tlb_query_paddr_w),
        .d_tlb_exception_valid(d_tlb_exception_valid_w),
        .d_tlb_exception_ecode(d_tlb_exception_ecode_w),
        .exception_valid(mem1_exception_w),
        .exception_pc(mem1_out_pc_w),
        .exception_ecode(mem1_exception_ecode_w),
        .exception_esubcode(mem1_exception_esubcode_w),
        .exception_badv_valid(mem1_exception_badv_valid_w),
        .exception_badv(mem1_exception_badv_w),
        .ertn_valid  (ertn_redirect_valid),
        .interrupt   (interrupt),
        .exception_entry(csr_exception_entry_w),
        .ertn_pc     (csr_ertn_pc_w),
        .interrupt_pending(csr_interrupt_pending_w),
        .has_int     (csr_has_int_w),
        .timer_64_out(csr_timer_64_w)
    );

    assign i_tlb_resp_valid      = i_tlb_resp_valid_w;
    assign i_tlb_resp_vaddr      = i_tlb_resp_vaddr_w;
    assign i_tlb_query_paddr    = i_tlb_query_paddr_w;
    assign i_tlb_exception_valid = i_tlb_exception_valid_w;
    assign i_tlb_exception_ecode = i_tlb_exception_ecode_w;

    s4_ex u_s4_ex (
        .clk           (clk),
        .reset         (reset),
        .flush         (mem1_redirect_flush_w),
        .next_allowin  (m1_allowin_w),
        .in_valid      (rrd_out_valid_w && !backend_redirect_flush_w),
        .in_pc         (rrd_out_pc_w),
        .in_inst       (rrd_out_inst_w),
        .in_pred_taken (rrd_out_pred_taken_w),
        .in_pred_target(rrd_out_pred_target_w),
        .in_rd         (rrd_out_rd_w),
        .in_op1        (rrd_out_op1_w),
        .in_op2        (rrd_out_op2_w),
        .in_imm        (rrd_out_imm_w),
        .in_use_imm    (rrd_out_use_imm_w),
        .in_is_branch  (rrd_out_is_branch_w),
        .in_is_load    (rrd_out_is_load_w),
        .in_is_store   (rrd_out_is_store_w),
        .in_is_muldiv  (rrd_out_is_muldiv_w),
        .in_is_csr     (rrd_out_is_csr_w),
        .in_csr_we     (rrd_out_csr_we_w),
        .in_csr_mask   (rrd_out_csr_mask_w),
        .in_csr_addr   (rrd_out_csr_addr_w),
        .in_exception_valid(rrd_out_exception_valid_w),
        .in_exception_ecode(rrd_out_exception_ecode_w),
        .in_exception_esubcode(rrd_out_exception_esubcode_w),
        .in_exception_badv_valid(rrd_out_exception_badv_valid_w),
        .in_exception_badv(rrd_out_exception_badv_w),
        .csr_read_data (csr_read_data_w),
        .timer_64      (csr_timer_64_w),
        .forward_ex1_valid(ex1_out_valid_w && !ex1_out_is_load_w && !ex1_out_is_store_w),
        .forward_ex1_waddr(ex1_out_rd_w),
        .forward_ex1_wdata(ex1_out_result_w),
        .forward_ex2_valid(1'b0),
        .forward_ex2_waddr(5'b0),
        .forward_ex2_wdata(32'b0),
        .forward_mem_valid(mem1_out_valid_w && mem1_out_wen_w),
        .forward_mem_waddr(mem1_out_rd_w),
        .forward_mem_wdata(mem1_out_wb_data_w),
        .forward_wb_valid(rf_we_w),
        .forward_wb_waddr(rf_waddr_w),
        .forward_wb_wdata(rf_wdata_w),
        .branch_update_valid(ex_branch_update_valid_raw_w),
        .branch_taken   (ex_branch_taken_raw_w),
        .branch_target  (ex_branch_target_raw_w),
        .branch_mispredict(ex_branch_mispredict_raw_w),
`ifdef PERF_MONI
        .bpu_perf_valid (bpu_perf_valid),
        .bpu_perf_is_branch(bpu_perf_is_branch),
        .bpu_perf_is_jump(bpu_perf_is_jump),
        .bpu_perf_pc(bpu_perf_pc),
        .bpu_perf_pred_taken(bpu_perf_pred_taken),
        .bpu_perf_actual_taken(bpu_perf_actual_taken),
        .bpu_perf_correct(bpu_perf_correct),
        .bpu_perf_direction_miss(bpu_perf_direction_miss),
        .bpu_perf_target_miss(bpu_perf_target_miss),
        .bpu_perf_exu_flush(bpu_perf_exu_flush),
        .bpu_perf_is_direct_jump(bpu_perf_is_direct_jump),
        .bpu_perf_is_jirl(bpu_perf_is_jirl),
        .bpu_perf_is_ret_jirl(bpu_perf_is_ret_jirl),
        .bpu_perf_is_indirect_jirl(bpu_perf_is_indirect_jirl),
`endif
        .out_valid     (ex1_out_valid_w),
        .out_pc        (ex1_out_pc_w),
        .out_inst      (ex1_out_inst_w),
        .out_rd        (ex1_out_rd_w),
        .out_result    (ex1_out_result_w),
        .out_op1       (ex1_out_op1_w),
        .out_op2       (ex1_out_op2_w),
        .out_is_load   (ex1_out_is_load_w),
        .out_is_store  (ex1_out_is_store_w),
        .out_store_data(ex1_out_store_data_w),
        .out_is_csr    (ex1_out_is_csr_w),
        .out_csr_we    (ex1_out_csr_we_w),
        .out_csr_addr  (ex1_out_csr_addr_w),
        .out_csr_wdata (ex1_out_csr_wdata_w),
        .out_exception_valid(ex1_out_exception_valid_w),
        .out_exception_ecode(ex1_out_exception_ecode_w),
        .out_exception_esubcode(ex1_out_exception_esubcode_w),
        .out_exception_badv_valid(ex1_out_exception_badv_valid_w),
        .out_exception_badv(ex1_out_exception_badv_w),
        .ex_allowin    (ex_allowin_w)
    );

    wire m1_allowin_w;
    wire m1_load_valid_w;
    wire [4:0] m1_load_rd_w;
    wire d1_allowin_w;
    wire ex_allowin_w;
    assign d1_allowin = d1_allowin_w;

    assign branch_pc = ex1_out_pc_w;

    s5_m1 u_s5_m1 (
        .clk               (clk),
        .reset             (reset),
        .in_valid          (ex1_out_valid_w && m1_allowin_w && !mem1_redirect_flush_w),
        .in_pc             (ex1_out_pc_w),
        .in_inst           (ex1_out_inst_w),
        .in_rd             (ex1_out_rd_w),
        .in_result         (ex1_out_result_w),
        .in_op1            (ex1_out_op1_w),
        .in_op2            (ex1_out_op2_w),
        .in_is_load        (ex1_out_is_load_w),
        .in_is_store       (ex1_out_is_store_w),
        .in_store_data     (ex1_out_store_data_w),
        .in_is_csr         (ex1_out_is_csr_w),
        .in_csr_we         (ex1_out_csr_we_w),
        .in_csr_addr       (ex1_out_csr_addr_w),
        .in_csr_wdata      (ex1_out_csr_wdata_w),
        .in_exception_valid(ex1_out_exception_valid_w),
        .in_exception_ecode(ex1_out_exception_ecode_w),
        .in_exception_esubcode(ex1_out_exception_esubcode_w),
        .in_exception_badv_valid(ex1_out_exception_badv_valid_w),
        .in_exception_badv (ex1_out_exception_badv_w),
        .d_tlb_query_valid(d_tlb_query_valid_w),
        .d_tlb_query_write(d_tlb_query_write_w),
        .d_tlb_query_vaddr(d_tlb_query_vaddr_w),
        .d_tlb_resp_valid(d_tlb_resp_valid_w),
        .d_tlb_resp_vaddr(d_tlb_resp_vaddr_w),
        .d_tlb_query_paddr(d_tlb_query_paddr_w),
        .d_tlb_exception_valid(d_tlb_exception_valid_w),
        .d_tlb_exception_ecode(d_tlb_exception_ecode_w),
        .dcache_req_valid  (dmem_req_valid),
        .dcache_req_write  (dmem_req_write),
        .dcache_req_addr   (dmem_req_addr),
        .dcache_req_wdata  (dmem_req_wdata),
        .dcache_req_wstrb  (dmem_req_wstrb),
        .dcache_resp_valid (dmem_resp_valid),
        .dcache_resp_data  (dmem_resp_rdata),
        .m1_allowin        (m1_allowin_w),
        .m1_load_valid     (m1_load_valid_w),
        .m1_load_rd        (m1_load_rd_w),
        .out_valid         (mem1_out_valid_w),
        .out_pc            (mem1_out_pc_w),
        .out_inst          (mem1_out_inst_w),
        .out_rd            (mem1_out_rd_w),
        .out_wb_data       (mem1_out_wb_data_w),
        .out_op1           (mem1_out_op1_w),
        .out_op2           (mem1_out_op2_w),
        .out_wen           (mem1_out_wen_w),
        .out_csr_we        (mem1_out_csr_we_w),
        .out_csr_addr      (mem1_out_csr_addr_w),
        .out_csr_wdata     (mem1_out_csr_wdata_w),
        .out_exception_valid(mem1_out_exception_valid_w),
        .out_exception_ecode(mem1_out_exception_ecode_w),
        .out_exception_esubcode(mem1_out_exception_esubcode_w),
        .out_exception_badv_valid(mem1_out_exception_badv_valid_w),
        .out_exception_badv(mem1_out_exception_badv_w)
    );

    s6_wb u_s6_wb (
        .clk              (clk),
        .reset            (reset),
        .in_valid         (mem1_out_valid_w),
        .in_pc            (mem1_out_pc_w),
        .in_inst          (mem1_out_inst_w),
        .in_rd            (mem1_out_rd_w),
        .in_wb_data       (mem1_out_wb_data_w),
        .in_wen           (mem1_out_wen_w),
        .in_csr_we        (mem1_out_csr_we_w),
        .in_csr_addr      (mem1_out_csr_addr_w),
        .in_csr_wdata     (mem1_out_csr_wdata_w),
        .in_exception     (mem1_exception_w),
        .in_exception_ecode(mem1_exception_ecode_w),
        .in_interrupt_pending(csr_interrupt_pending_w),
        .in_ertn          (mem1_is_ertn_w),
        .gpr_we           (rf_we_w),
        .gpr_waddr        (rf_waddr_w),
        .gpr_wdata        (rf_wdata_w),
        .csr_we           (csr_we_w),
        .csr_addr         (csr_addr_w),
        .csr_wdata        (csr_wdata_w),
        .ws_valid         (ws_valid),
        .debug_wb_pc      (debug_wb_pc),
        .debug_wb_rf_wen  (debug_wb_rf_wen),
        .debug_wb_rf_wnum (debug_wb_rf_wnum),
        .debug_wb_rf_wdata(debug_wb_rf_wdata),
        .debug_wb_inst    (debug_wb_inst),
        .debug_excp_valid (debug_excp_valid),
        .debug_excp_ecode (debug_excp_ecode),
        .debug_intr_no    (debug_intr_no),
        .debug_ertn_valid (debug_ertn_valid)
    );

endmodule
