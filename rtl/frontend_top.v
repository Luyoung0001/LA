`include "la_core_defs.vh"

module frontend_top #(
    parameter RESET_PC = 32'h1c000000,
    parameter BPU_ENABLE = `LA_BPU_ENABLE,
    parameter FETCH_BUFFER_ENABLE = `LA_FETCH_BUFFER_ENABLE,
    parameter ITCM_ENABLE = `LA_ITCM_ENABLE,
    parameter L1I_ENABLE = `LA_L1I_ENABLE
) (
    input  wire        clk,
    input  wire        reset,

    input  wire        d1_allowin,
    input  wire        redirect_valid,
    input  wire [31:0] redirect_pc,

    input  wire        branch_update_valid,
    input  wire        branch_update_taken,
    input  wire [31:0] branch_update_pc,
    input  wire [31:0] branch_update_target,

    output wire        i_tlb_query_valid,
    output wire        i_tlb_query_write,
    output wire [31:0] i_tlb_query_vaddr,
    input  wire        i_tlb_resp_valid,
    input  wire [31:0] i_tlb_query_paddr,
    input  wire        i_tlb_exception_valid,
    input  wire [5:0]  i_tlb_exception_ecode,

    output wire        ifetch_req_valid,
    output wire [31:0] ifetch_req_addr,
    input  wire        ifetch_req_ready,
    input  wire        ifetch_resp_valid,
    input  wire [31:0] ifetch_resp_data,

    output wire        fetch_valid,
    output wire [31:0] fetch_pc,
    output wire [31:0] fetch_inst,
    output wire        fetch_pred_taken,
    output wire [31:0] fetch_pred_target,
    output wire        fetch_exception_valid,
    output wire [5:0]  fetch_exception_ecode,
    output wire [8:0]  fetch_exception_esubcode,
    output wire        fetch_exception_badv_valid,
    output wire [31:0] fetch_exception_badv,

    output wire        pc_valid,
    output wire [31:0] pc
);

    wire bp_req_valid_w;
    wire [31:0] bp_req_pc_w;
    wire bp_resp_valid_w;
    wire [31:0] bp_resp_pc_w;
    wire bp_pred_taken_w;
    wire [31:0] bp_pred_target_w;
    wire ifu_pred_taken_w;
    wire [31:0] ifu_pred_target_w;

    wire if2_out_valid_w;
    wire [31:0] if2_out_pc_w;
    wire [31:0] if2_out_inst_w;
    wire if2_out_pred_taken_w;
    wire [31:0] if2_out_pred_target_w;
    wire if2_out_exception_valid_w;
    wire [5:0] if2_out_exception_ecode_w;
    wire [8:0] if2_out_exception_esubcode_w;
    wire if2_out_exception_badv_valid_w;
    wire [31:0] if2_out_exception_badv_w;
    wire if2_next_allowin_w;
    wire s2_allowin_w;
    wire unused_frontend_cfg;
    assign unused_frontend_cfg = &{1'b0, FETCH_BUFFER_ENABLE[0],
                                   ITCM_ENABLE[0], L1I_ENABLE[0]};

    generate
        if (BPU_ENABLE != 0) begin : gen_bpu_enabled
            la_bpu_adapter u_bp (
                .clk          (clk),
                .reset        (reset),
                .req_valid    (bp_req_valid_w),
                .req_pc       (bp_req_pc_w),
                .resp_valid   (bp_resp_valid_w),
                .resp_pc      (bp_resp_pc_w),
                .pred_taken   (bp_pred_taken_w),
                .pred_target  (bp_pred_target_w),
                .update_valid (branch_update_valid),
                .update_taken (branch_update_taken),
                .update_pc    (branch_update_pc),
                .update_target(branch_update_target)
            );
        end else begin : gen_bpu_disabled
            wire unused_bpu_inputs;
            assign unused_bpu_inputs = &{1'b0, bp_req_valid_w, bp_req_pc_w,
                                         branch_update_valid, branch_update_taken,
                                         branch_update_pc, branch_update_target};
            assign bp_resp_valid_w  = bp_req_valid_w;
            assign bp_resp_pc_w     = bp_req_pc_w;
            assign bp_pred_taken_w  = 1'b0;
            assign bp_pred_target_w = 32'b0;
        end
    endgenerate

    s1_f1 #(
        .RESET_PC(RESET_PC)
    ) u_s1_f1 (
        .clk           (clk),
        .reset         (reset),
        .hold          (!pc_valid || !s2_allowin_w),
        .redirect_valid(redirect_valid),
        .redirect_pc   (redirect_pc),
        .bp_resp_valid (bp_resp_valid_w),
        .bp_resp_pc    (bp_resp_pc_w),
        .bp_pred_taken (bp_pred_taken_w),
        .bp_pred_target(bp_pred_target_w),
        .bp_req_valid  (bp_req_valid_w),
        .bp_req_pc     (bp_req_pc_w),
        .out_valid     (pc_valid),
        .out_pc        (pc),
        .out_pred_taken(ifu_pred_taken_w),
        .out_pred_target(ifu_pred_target_w)
    );

    s2_f2 u_s2_f2 (
        .clk               (clk),
        .reset             (reset),
        .flush             (redirect_valid),
        .next_allowin      (if2_next_allowin_w),
        .in_valid          (pc_valid),
        .in_pc             (pc),
        .in_pred_taken     (ifu_pred_taken_w),
        .in_pred_target    (ifu_pred_target_w),
        .s2_allowin        (s2_allowin_w),
        .tlb_query_valid   (i_tlb_query_valid),
        .tlb_query_write   (i_tlb_query_write),
        .tlb_query_vaddr   (i_tlb_query_vaddr),
        .tlb_resp_valid    (i_tlb_resp_valid),
        .tlb_query_paddr   (i_tlb_query_paddr),
        .tlb_exception_valid(i_tlb_exception_valid),
        .tlb_exception_ecode(i_tlb_exception_ecode),
        .icache_req_valid  (ifetch_req_valid),
        .icache_req_addr   (ifetch_req_addr),
        .icache_req_ready  (ifetch_req_ready),
        .icache_resp_valid (ifetch_resp_valid),
        .icache_resp_data  (ifetch_resp_data),
        .out_valid         (if2_out_valid_w),
        .out_pc            (if2_out_pc_w),
        .out_inst          (if2_out_inst_w),
        .out_pred_taken    (if2_out_pred_taken_w),
        .out_pred_target   (if2_out_pred_target_w),
        .out_exception_valid(if2_out_exception_valid_w),
        .out_exception_ecode(if2_out_exception_ecode_w),
        .out_exception_esubcode(if2_out_exception_esubcode_w),
        .out_exception_badv_valid(if2_out_exception_badv_valid_w),
        .out_exception_badv(if2_out_exception_badv_w)
    );

    generate
        if (FETCH_BUFFER_ENABLE != 0) begin : gen_fetch_buffer_enabled
            wire fetch_buffer_in_allowin_w;
            assign if2_next_allowin_w = fetch_buffer_in_allowin_w;

            la_fetch_buffer_adapter u_fetch_buffer_adapter (
                .clk        (clk),
                .reset      (reset),
                .flush      (redirect_valid),
                .out_allowin(d1_allowin),
                .in_allowin (fetch_buffer_in_allowin_w),
                .in_valid   (if2_out_valid_w),
                .in_pc      (if2_out_pc_w),
                .in_inst    (if2_out_inst_w),
                .in_pred_taken(if2_out_pred_taken_w),
                .in_pred_target(if2_out_pred_target_w),
                .in_exception_valid(if2_out_exception_valid_w),
                .in_exception_ecode(if2_out_exception_ecode_w),
                .in_exception_badv(if2_out_exception_badv_w),
                .out_valid  (fetch_valid),
                .out_pc     (fetch_pc),
                .out_inst   (fetch_inst),
                .out_pred_taken(fetch_pred_taken),
                .out_pred_target(fetch_pred_target),
                .out_exception_valid(fetch_exception_valid),
                .out_exception_ecode(fetch_exception_ecode),
                .out_exception_badv(fetch_exception_badv)
            );
            assign fetch_exception_esubcode = 9'b0;
            assign fetch_exception_badv_valid = fetch_exception_valid;
        end else begin : gen_fetch_buffer_disabled
            assign if2_next_allowin_w = d1_allowin;

            assign fetch_valid                = if2_out_valid_w;
            assign fetch_pc                   = if2_out_pc_w;
            assign fetch_inst                 = if2_out_inst_w;
            assign fetch_pred_taken           = if2_out_pred_taken_w;
            assign fetch_pred_target          = if2_out_pred_target_w;
            assign fetch_exception_valid      = if2_out_exception_valid_w;
            assign fetch_exception_ecode      = if2_out_exception_ecode_w;
            assign fetch_exception_esubcode   = if2_out_exception_esubcode_w;
            assign fetch_exception_badv_valid = if2_out_exception_badv_valid_w;
            assign fetch_exception_badv       = if2_out_exception_badv_w;
        end
    endgenerate

endmodule
