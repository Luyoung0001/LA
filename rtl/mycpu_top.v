`include "la_core_defs.vh"

module core_top #(
    parameter TLBNUM = 32,
    parameter TLB_ENABLE = `LA_TLB_ENABLE,
    parameter L1I_ENABLE = `LA_L1I_ENABLE,
    parameter L1D_ENABLE = `LA_L1D_ENABLE,
    parameter L2_ENABLE = `LA_L2_ENABLE,
    parameter BPU_ENABLE = `LA_BPU_ENABLE,
    parameter FETCH_BUFFER_ENABLE = `LA_FETCH_BUFFER_ENABLE,
    parameter ITCM_ENABLE = `LA_ITCM_ENABLE,
    parameter CACHE_OP_STRICT_ENABLE = `LA_CACHE_OP_STRICT_ENABLE
) (
    input  wire        aclk,
    input  wire        aresetn,
    input  wire [7:0]  intrpt,

    output wire [3:0]  arid,
    output wire [31:0] araddr,
    output wire [7:0]  arlen,
    output wire [2:0]  arsize,
    output wire [1:0]  arburst,
    output wire [1:0]  arlock,
    output wire [3:0]  arcache,
    output wire [2:0]  arprot,
    output wire        arvalid,
    input  wire        arready,

    input  wire [3:0]  rid,
    input  wire [31:0] rdata,
    input  wire [1:0]  rresp,
    input  wire        rlast,
    input  wire        rvalid,
    output wire        rready,

    output wire [3:0]  awid,
    output wire [31:0] awaddr,
    output wire [7:0]  awlen,
    output wire [2:0]  awsize,
    output wire [1:0]  awburst,
    output wire [1:0]  awlock,
    output wire [3:0]  awcache,
    output wire [2:0]  awprot,
    output wire        awvalid,
    input  wire        awready,

    output wire [3:0]  wid,
    output wire [31:0] wdata,
    output wire [3:0]  wstrb,
    output wire        wlast,
    output wire        wvalid,
    input  wire        wready,

    input  wire [3:0]  bid,
    input  wire [1:0]  bresp,
    input  wire        bvalid,
    output wire        bready,

    input  wire        break_point,
    input  wire        infor_flag,
    input  wire [4:0]  reg_num,
    output wire        ws_valid,
    output wire [31:0] rf_rdata,

    output wire [31:0] debug0_wb_pc,
    output wire [3:0]  debug0_wb_rf_wen,
    output wire [4:0]  debug0_wb_rf_wnum,
    output wire [31:0] debug0_wb_rf_wdata,
    output wire [31:0] debug0_wb_inst,
    output wire        debug0_excp_valid,
    output wire [5:0]  debug0_excp_ecode,
    output wire [10:0] debug0_intr_no,
    output wire        debug0_ertn_valid,
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

    output wire [31:0] debug1_wb_pc,
    output wire [3:0]  debug1_wb_rf_wen,
    output wire [4:0]  debug1_wb_rf_wnum,
    output wire [31:0] debug1_wb_rf_wdata
);

    wire reset;
    assign reset = ~aresetn;

    wire unused_inputs;
    assign unused_inputs = &{1'b0, break_point, infor_flag, TLBNUM[0]};

    wire ifu_out_valid_w;
    wire [31:0] ifu_out_pc_w;

    wire i_tlb_query_valid_w;
    wire i_tlb_query_write_w;
    wire [31:0] i_tlb_query_vaddr_w;
    wire i_tlb_resp_valid_w;
    wire [31:0] i_tlb_query_paddr_w;
    wire i_tlb_exception_valid_w;
    wire [5:0] i_tlb_exception_ecode_w;

    wire if1_icache_req_valid_w;
    wire [31:0] if1_icache_req_addr_w;
    wire if2_icache_resp_valid_w;
    wire [31:0] if2_icache_resp_data_w;
    wire ifetch_req_ready_w;

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

    wire ex_branch_update_valid_w;
    wire ex_branch_mispredict_w;
    wire ex_branch_taken_w;
    wire [31:0] ex_branch_target_w;
    wire [31:0] ex_branch_pc_w;
    wire d1_early_redirect_valid_w;
    wire [31:0] d1_early_redirect_pc_w;

    wire mem1_dcache_req_valid_w;
    wire mem1_dcache_req_write_w;
    wire [31:0] mem1_dcache_req_addr_w;
    wire [31:0] mem1_dcache_req_wdata_w;
    wire [3:0] mem1_dcache_req_wstrb_w;
    wire dcache_mem_resp_valid_w;
    wire [31:0] dcache_mem_resp_data_w;
    wire dmem_req_ready_w;

    wire commit_ws_valid_w;
    wire [31:0] commit_debug_wb_pc_w;
    wire [3:0] commit_debug_wb_rf_wen_w;
    wire [4:0] commit_debug_wb_rf_wnum_w;
    wire [31:0] commit_debug_wb_rf_wdata_w;
    wire [31:0] commit_debug_wb_inst_w;
    wire commit_debug_excp_valid_w;
    wire [5:0] commit_debug_excp_ecode_w;
    wire [10:0] commit_debug_intr_no_w;
    wire commit_debug_ertn_valid_w;

    wire branch_redirect_valid_w;
    wire [31:0] branch_redirect_pc_w;
    wire exception_redirect_valid_w;
    wire [31:0] exception_redirect_pc_w;
    wire ertn_redirect_valid_w;
    wire [31:0] ertn_redirect_pc_w;
    wire refetch_redirect_valid_w;
    wire [31:0] refetch_redirect_pc_w;
    wire icacop_valid_w;
    wire [1:0] icacop_mode_w;
    wire [31:0] icacop_addr_w;

    // Pipeline flow control: D1 backpressure is consumed by S2; S1 holds on
    // S2's own allowin so the fetch PC is not lost while an icache request is
    // pending or an output packet is waiting for D1.
    wire d1_allowin_w;
    wire unused_frontend_pc;
    assign unused_frontend_pc = &{1'b0, ifu_out_valid_w, ifu_out_pc_w};

    redirect_ctrl u_redirect_ctrl (
        .branch_valid    (ex_branch_update_valid_w),
        .branch_mispredict(ex_branch_mispredict_w),
        .branch_pc       (ex_branch_pc_w),
        .branch_taken    (ex_branch_taken_w),
        .branch_target   (ex_branch_target_w),
        .early_valid     (d1_early_redirect_valid_w),
        .early_target    (d1_early_redirect_pc_w),
        .exception_valid (exception_redirect_valid_w),
        .exception_target(exception_redirect_pc_w),
        .ertn_valid      (ertn_redirect_valid_w),
        .ertn_target     (ertn_redirect_pc_w),
        .refetch_valid   (refetch_redirect_valid_w),
        .refetch_target  (refetch_redirect_pc_w),
        .redirect_valid  (branch_redirect_valid_w),
        .redirect_pc     (branch_redirect_pc_w)
    );

    frontend_top #(
        .RESET_PC(32'h1c000000),
        .BPU_ENABLE(BPU_ENABLE),
        .FETCH_BUFFER_ENABLE(FETCH_BUFFER_ENABLE),
        .ITCM_ENABLE(ITCM_ENABLE),
        .L1I_ENABLE(L1I_ENABLE)
    ) u_frontend_top (
        .clk                 (aclk),
        .reset               (reset),
        .d1_allowin          (d1_allowin_w),
        .redirect_valid      (branch_redirect_valid_w),
        .redirect_pc         (branch_redirect_pc_w),
        .branch_update_valid (ex_branch_update_valid_w),
        .branch_update_taken (ex_branch_taken_w),
        .branch_update_pc    (ex_branch_pc_w),
        .branch_update_target(ex_branch_target_w),
        .i_tlb_query_valid   (i_tlb_query_valid_w),
        .i_tlb_query_write   (i_tlb_query_write_w),
        .i_tlb_query_vaddr   (i_tlb_query_vaddr_w),
        .i_tlb_resp_valid    (i_tlb_resp_valid_w),
        .i_tlb_query_paddr   (i_tlb_query_paddr_w),
        .i_tlb_exception_valid(i_tlb_exception_valid_w),
        .i_tlb_exception_ecode(i_tlb_exception_ecode_w),
        .ifetch_req_valid    (if1_icache_req_valid_w),
        .ifetch_req_addr     (if1_icache_req_addr_w),
        .ifetch_req_ready    (ifetch_req_ready_w),
        .ifetch_resp_valid   (if2_icache_resp_valid_w),
        .ifetch_resp_data    (if2_icache_resp_data_w),
        .fetch_valid         (if2_out_valid_w),
        .fetch_pc            (if2_out_pc_w),
        .fetch_inst          (if2_out_inst_w),
        .fetch_pred_taken    (if2_out_pred_taken_w),
        .fetch_pred_target   (if2_out_pred_target_w),
        .fetch_exception_valid(if2_out_exception_valid_w),
        .fetch_exception_ecode(if2_out_exception_ecode_w),
        .fetch_exception_esubcode(if2_out_exception_esubcode_w),
        .fetch_exception_badv_valid(if2_out_exception_badv_valid_w),
        .fetch_exception_badv(if2_out_exception_badv_w),
        .pc_valid            (ifu_out_valid_w),
        .pc                  (ifu_out_pc_w)
    );

    backend_top #(
        .TLB_ENABLE(TLB_ENABLE),
        .CACHE_OP_STRICT_ENABLE(CACHE_OP_STRICT_ENABLE)
    ) u_backend_top (
        .clk                (aclk),
        .reset              (reset),
        .interrupt          (intrpt),
        .fetch_valid        (if2_out_valid_w),
        .fetch_pc           (if2_out_pc_w),
        .fetch_inst         (if2_out_inst_w),
        .fetch_pred_taken   (if2_out_pred_taken_w),
        .fetch_pred_target  (if2_out_pred_target_w),
        .fetch_exception_valid(if2_out_exception_valid_w),
        .fetch_exception_ecode(if2_out_exception_ecode_w),
        .fetch_exception_esubcode(if2_out_exception_esubcode_w),
        .fetch_exception_badv_valid(if2_out_exception_badv_valid_w),
        .fetch_exception_badv(if2_out_exception_badv_w),
        .dmem_req_valid     (mem1_dcache_req_valid_w),
        .dmem_req_write     (mem1_dcache_req_write_w),
        .dmem_req_addr      (mem1_dcache_req_addr_w),
        .dmem_req_wdata     (mem1_dcache_req_wdata_w),
        .dmem_req_wstrb     (mem1_dcache_req_wstrb_w),
        .dmem_req_ready     (dmem_req_ready_w),
        .dmem_resp_valid    (dcache_mem_resp_valid_w),
        .dmem_resp_rdata    (dcache_mem_resp_data_w),
        .branch_update_valid(ex_branch_update_valid_w),
        .branch_taken       (ex_branch_taken_w),
        .branch_pc          (ex_branch_pc_w),
        .branch_target      (ex_branch_target_w),
        .branch_mispredict  (ex_branch_mispredict_w),
        .early_redirect_valid(d1_early_redirect_valid_w),
        .early_redirect_pc  (d1_early_redirect_pc_w),
        .exception_redirect_valid(exception_redirect_valid_w),
        .exception_redirect_pc(exception_redirect_pc_w),
        .ertn_redirect_valid(ertn_redirect_valid_w),
        .ertn_redirect_pc   (ertn_redirect_pc_w),
        .refetch_redirect_valid(refetch_redirect_valid_w),
        .refetch_redirect_pc(refetch_redirect_pc_w),
        .icacop_valid       (icacop_valid_w),
        .icacop_mode        (icacop_mode_w),
        .icacop_addr        (icacop_addr_w),
`ifdef PERF_MONI
        .bpu_perf_valid     (bpu_perf_valid),
        .bpu_perf_is_branch (bpu_perf_is_branch),
        .bpu_perf_is_jump   (bpu_perf_is_jump),
        .bpu_perf_pc        (bpu_perf_pc),
        .bpu_perf_pred_taken(bpu_perf_pred_taken),
        .bpu_perf_actual_taken(bpu_perf_actual_taken),
        .bpu_perf_correct   (bpu_perf_correct),
        .bpu_perf_direction_miss(bpu_perf_direction_miss),
        .bpu_perf_target_miss(bpu_perf_target_miss),
        .bpu_perf_exu_flush (bpu_perf_exu_flush),
        .bpu_perf_is_direct_jump(bpu_perf_is_direct_jump),
        .bpu_perf_is_jirl(bpu_perf_is_jirl),
        .bpu_perf_is_ret_jirl(bpu_perf_is_ret_jirl),
        .bpu_perf_is_indirect_jirl(bpu_perf_is_indirect_jirl),
`endif
        .i_tlb_query_valid  (i_tlb_query_valid_w),
        .i_tlb_query_write  (i_tlb_query_write_w),
        .i_tlb_query_vaddr  (i_tlb_query_vaddr_w),
        .i_tlb_resp_valid   (i_tlb_resp_valid_w),
        .i_tlb_query_paddr  (i_tlb_query_paddr_w),
        .i_tlb_exception_valid(i_tlb_exception_valid_w),
        .i_tlb_exception_ecode(i_tlb_exception_ecode_w),
        .dbg_reg_num        (reg_num),
        .dbg_rf_rdata       (rf_rdata),
        .ws_valid           (commit_ws_valid_w),
        .d1_allowin         (d1_allowin_w),
        .debug_wb_pc        (commit_debug_wb_pc_w),
        .debug_wb_rf_wen    (commit_debug_wb_rf_wen_w),
        .debug_wb_rf_wnum   (commit_debug_wb_rf_wnum_w),
        .debug_wb_rf_wdata  (commit_debug_wb_rf_wdata_w),
        .debug_wb_inst      (commit_debug_wb_inst_w),
        .debug_excp_valid   (commit_debug_excp_valid_w),
        .debug_excp_ecode   (commit_debug_excp_ecode_w),
        .debug_intr_no      (commit_debug_intr_no_w),
        .debug_ertn_valid   (commit_debug_ertn_valid_w)
    );

    memsys_top #(
        .ITCM_ENABLE(ITCM_ENABLE),
        .L1I_ENABLE(L1I_ENABLE),
        .L1D_ENABLE(L1D_ENABLE),
        .L2_ENABLE(L2_ENABLE),
        .CACHE_OP_STRICT_ENABLE(CACHE_OP_STRICT_ENABLE)
    ) u_memsys_top (
        .clk               (aclk),
        .reset             (reset),
        .ifetch_flush      (branch_redirect_valid_w),
        .icacop_valid      (icacop_valid_w),
        .icacop_mode       (icacop_mode_w),
        .icacop_addr       (icacop_addr_w),

        .ifetch_req_valid  (if1_icache_req_valid_w),
        .ifetch_req_addr   (if1_icache_req_addr_w),
        .ifetch_req_ready  (ifetch_req_ready_w),
        .ifetch_resp_valid (if2_icache_resp_valid_w),
        .ifetch_resp_data  (if2_icache_resp_data_w),

        .dmem_req_valid    (mem1_dcache_req_valid_w),
        .dmem_req_write    (mem1_dcache_req_write_w),
        .dmem_req_addr     (mem1_dcache_req_addr_w),
        .dmem_req_wdata    (mem1_dcache_req_wdata_w),
        .dmem_req_wstrb    (mem1_dcache_req_wstrb_w),
        .dmem_req_ready    (dmem_req_ready_w),
        .dmem_resp_valid   (dcache_mem_resp_valid_w),
        .dmem_resp_rdata   (dcache_mem_resp_data_w),

        .arid              (arid),
        .araddr            (araddr),
        .arlen             (arlen),
        .arsize            (arsize),
        .arburst           (arburst),
        .arlock            (arlock),
        .arcache           (arcache),
        .arprot            (arprot),
        .arvalid           (arvalid),
        .arready           (arready),
        .rid               (rid),
        .rdata             (rdata),
        .rresp             (rresp),
        .rlast             (rlast),
        .rvalid            (rvalid),
        .rready            (rready),

        .awid              (awid),
        .awaddr            (awaddr),
        .awlen             (awlen),
        .awsize            (awsize),
        .awburst           (awburst),
        .awlock            (awlock),
        .awcache           (awcache),
        .awprot            (awprot),
        .awvalid           (awvalid),
        .awready           (awready),

        .wid               (wid),
        .wdata             (wdata),
        .wstrb             (wstrb),
        .wlast             (wlast),
        .wvalid            (wvalid),
        .wready            (wready),
        .bid               (bid),
        .bresp             (bresp),
        .bvalid            (bvalid),
        .bready            (bready)
    );

    assign ws_valid           = commit_ws_valid_w;
    assign debug0_wb_pc       = commit_debug_wb_pc_w;
    assign debug0_wb_rf_wen   = commit_debug_wb_rf_wen_w;
    assign debug0_wb_rf_wnum  = commit_debug_wb_rf_wnum_w;
    assign debug0_wb_rf_wdata = commit_debug_wb_rf_wdata_w;
    assign debug0_wb_inst     = commit_debug_wb_inst_w;
    assign debug0_excp_valid  = commit_debug_excp_valid_w;
    assign debug0_excp_ecode  = commit_debug_excp_ecode_w;
    assign debug0_intr_no     = commit_debug_intr_no_w;
    assign debug0_ertn_valid  = commit_debug_ertn_valid_w;
    assign debug1_wb_pc       = 32'b0;
    assign debug1_wb_rf_wen   = 4'b0;
    assign debug1_wb_rf_wnum  = 5'b0;
    assign debug1_wb_rf_wdata = 32'b0;

`ifdef VERILATOR
`ifdef PERF_MONI
    integer perf_cycle_cnt = 0;
    integer perf_commit_cnt = 0;
    integer perf_no_commit_cnt = 0;
    integer perf_frontend_empty_cnt = 0;
    integer perf_frontend_has_inst_cnt = 0;
    integer perf_d1_not_allow_cnt = 0;
    integer perf_ifetch_req_cnt = 0;
    integer perf_ifetch_req_fire_cnt = 0;
    integer perf_ifetch_resp_cnt = 0;
    integer perf_redirect_cnt = 0;
    final begin
        $display("[PERF][CORE] cycles=%0d commit=%0d no_commit=%0d frontend_empty=%0d frontend_has_inst=%0d d1_not_allow=%0d redirect=%0d",
                 perf_cycle_cnt, perf_commit_cnt, perf_no_commit_cnt,
                 perf_frontend_empty_cnt, perf_frontend_has_inst_cnt,
                 perf_d1_not_allow_cnt, perf_redirect_cnt);
        $display("[PERF][CORE] ifetch_req=%0d ifetch_req_fire=%0d ifetch_resp=%0d",
                 perf_ifetch_req_cnt, perf_ifetch_req_fire_cnt,
                 perf_ifetch_resp_cnt);
    end
    always @(posedge aclk) begin
        if (!reset) begin
            perf_cycle_cnt <= perf_cycle_cnt + 1;
            if (commit_ws_valid_w)
                perf_commit_cnt <= perf_commit_cnt + 1;
            else
                perf_no_commit_cnt <= perf_no_commit_cnt + 1;

            if (!if2_out_valid_w)
                perf_frontend_empty_cnt <= perf_frontend_empty_cnt + 1;
            else
                perf_frontend_has_inst_cnt <= perf_frontend_has_inst_cnt + 1;

            if (!d1_allowin_w)
                perf_d1_not_allow_cnt <= perf_d1_not_allow_cnt + 1;
            if (if1_icache_req_valid_w)
                perf_ifetch_req_cnt <= perf_ifetch_req_cnt + 1;
            if (if1_icache_req_valid_w && ifetch_req_ready_w)
                perf_ifetch_req_fire_cnt <= perf_ifetch_req_fire_cnt + 1;
            if (if2_icache_resp_valid_w)
                perf_ifetch_resp_cnt <= perf_ifetch_resp_cnt + 1;
            if (branch_redirect_valid_w)
                perf_redirect_cnt <= perf_redirect_cnt + 1;
        end
    end
`endif
`endif

endmodule

module mycpu_top (
    input  wire        aclk,
    input  wire        aresetn,
    output wire [3:0]  arid,
    output wire [31:0] araddr,
    output wire [7:0]  arlen,
    output wire [2:0]  arsize,
    output wire [1:0]  arburst,
    output wire [1:0]  arlock,
    output wire [3:0]  arcache,
    output wire [2:0]  arprot,
    output wire        arvalid,
    input  wire        arready,
    input  wire [3:0]  rid,
    input  wire [31:0] rdata,
    input  wire [1:0]  rresp,
    input  wire        rlast,
    input  wire        rvalid,
    output wire        rready,
    output wire [3:0]  awid,
    output wire [31:0] awaddr,
    output wire [7:0]  awlen,
    output wire [2:0]  awsize,
    output wire [1:0]  awburst,
    output wire [1:0]  awlock,
    output wire [3:0]  awcache,
    output wire [2:0]  awprot,
    output wire        awvalid,
    input  wire        awready,
    output wire [3:0]  wid,
    output wire [31:0] wdata,
    output wire [3:0]  wstrb,
    output wire        wlast,
    output wire        wvalid,
    input  wire        wready,
    input  wire [3:0]  bid,
    input  wire [1:0]  bresp,
    input  wire        bvalid,
    output wire        bready,
    output wire [31:0] debug_wb_pc,
    output wire [3:0]  debug_wb_rf_we,
    output wire [4:0]  debug_wb_rf_wnum,
    output wire [31:0] debug_wb_rf_wdata,
    output wire [31:0] debug1_wb_pc,
    output wire [3:0]  debug1_wb_rf_we,
    output wire [4:0]  debug1_wb_rf_wnum,
    output wire [31:0] debug1_wb_rf_wdata
);

    wire [31:0] debug_wb_inst_unused;
    wire debug_excp_valid_unused;
    wire [5:0] debug_excp_ecode_unused;
    wire [10:0] debug_intr_no_unused;
    wire debug_ertn_valid_unused;
`ifdef PERF_MONI
    wire bpu_perf_valid_unused;
    wire bpu_perf_is_branch_unused;
    wire bpu_perf_is_jump_unused;
    wire [31:0] bpu_perf_pc_unused;
    wire bpu_perf_pred_taken_unused;
    wire bpu_perf_actual_taken_unused;
    wire bpu_perf_correct_unused;
    wire bpu_perf_direction_miss_unused;
    wire bpu_perf_target_miss_unused;
    wire bpu_perf_exu_flush_unused;
    wire bpu_perf_is_direct_jump_unused;
    wire bpu_perf_is_jirl_unused;
    wire bpu_perf_is_ret_jirl_unused;
    wire bpu_perf_is_indirect_jirl_unused;
`endif

    core_top u_core_top (
        .aclk               (aclk),
        .aresetn            (aresetn),
        .intrpt             (8'b0),
        .arid               (arid),
        .araddr             (araddr),
        .arlen              (arlen),
        .arsize             (arsize),
        .arburst            (arburst),
        .arlock             (arlock),
        .arcache            (arcache),
        .arprot             (arprot),
        .arvalid            (arvalid),
        .arready            (arready),
        .rid                (rid),
        .rdata              (rdata),
        .rresp              (rresp),
        .rlast              (rlast),
        .rvalid             (rvalid),
        .rready             (rready),
        .awid               (awid),
        .awaddr             (awaddr),
        .awlen              (awlen),
        .awsize             (awsize),
        .awburst            (awburst),
        .awlock             (awlock),
        .awcache            (awcache),
        .awprot             (awprot),
        .awvalid            (awvalid),
        .awready            (awready),
        .wid                (wid),
        .wdata              (wdata),
        .wstrb              (wstrb),
        .wlast              (wlast),
        .wvalid             (wvalid),
        .wready             (wready),
        .bid                (bid),
        .bresp              (bresp),
        .bvalid             (bvalid),
        .bready             (bready),
        .break_point        (1'b0),
        .infor_flag         (1'b0),
        .reg_num            (5'b0),
        .ws_valid           (),
        .rf_rdata           (),
        .debug0_wb_pc       (debug_wb_pc),
        .debug0_wb_rf_wen   (debug_wb_rf_we),
        .debug0_wb_rf_wnum  (debug_wb_rf_wnum),
        .debug0_wb_rf_wdata (debug_wb_rf_wdata),
        .debug0_wb_inst     (debug_wb_inst_unused),
        .debug0_excp_valid  (debug_excp_valid_unused),
        .debug0_excp_ecode  (debug_excp_ecode_unused),
        .debug0_intr_no     (debug_intr_no_unused),
        .debug0_ertn_valid  (debug_ertn_valid_unused),
`ifdef PERF_MONI
        .bpu_perf_valid     (bpu_perf_valid_unused),
        .bpu_perf_is_branch (bpu_perf_is_branch_unused),
        .bpu_perf_is_jump   (bpu_perf_is_jump_unused),
        .bpu_perf_pc        (bpu_perf_pc_unused),
        .bpu_perf_pred_taken(bpu_perf_pred_taken_unused),
        .bpu_perf_actual_taken(bpu_perf_actual_taken_unused),
        .bpu_perf_correct   (bpu_perf_correct_unused),
        .bpu_perf_direction_miss(bpu_perf_direction_miss_unused),
        .bpu_perf_target_miss(bpu_perf_target_miss_unused),
        .bpu_perf_exu_flush (bpu_perf_exu_flush_unused),
        .bpu_perf_is_direct_jump(bpu_perf_is_direct_jump_unused),
        .bpu_perf_is_jirl(bpu_perf_is_jirl_unused),
        .bpu_perf_is_ret_jirl(bpu_perf_is_ret_jirl_unused),
        .bpu_perf_is_indirect_jirl(bpu_perf_is_indirect_jirl_unused),
`endif
        .debug1_wb_pc       (debug1_wb_pc),
        .debug1_wb_rf_wen   (debug1_wb_rf_we),
        .debug1_wb_rf_wnum  (debug1_wb_rf_wnum),
        .debug1_wb_rf_wdata (debug1_wb_rf_wdata)
    );

endmodule
