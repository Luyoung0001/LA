module core_top #(
    parameter TLBNUM = 32
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
    output wire [31:0] debug0_wb_inst
);

    localparam [2:0] AXI_IDLE = 3'd0;
    localparam [2:0] AXI_I_AR = 3'd1;
    localparam [2:0] AXI_I_R  = 3'd2;
    localparam [2:0] AXI_D_AR = 3'd3;
    localparam [2:0] AXI_D_R  = 3'd4;
    localparam [2:0] AXI_D_AW = 3'd5;
    localparam [2:0] AXI_D_W  = 3'd6;
    localparam [2:0] AXI_D_B  = 3'd7;

    wire reset;
    assign reset = ~aresetn;

    wire unused_inputs;
    assign unused_inputs = &{1'b0, intrpt, rid, rresp, rlast, bid, bresp, break_point, infor_flag, TLBNUM[0]};

    reg [2:0] axi_state_r;

    reg [3:0]  arid_r;
    reg [31:0] araddr_r;
    reg [7:0]  arlen_r;
    reg [2:0]  arsize_r;
    reg [1:0]  arburst_r;
    reg [1:0]  arlock_r;
    reg [3:0]  arcache_r;
    reg [2:0]  arprot_r;
    reg        arvalid_r;
    reg        rready_r;

    reg [3:0]  awid_r;
    reg [31:0] awaddr_r;
    reg [7:0]  awlen_r;
    reg [2:0]  awsize_r;
    reg [1:0]  awburst_r;
    reg [1:0]  awlock_r;
    reg [3:0]  awcache_r;
    reg [2:0]  awprot_r;
    reg        awvalid_r;

    reg [3:0]  wid_r;
    reg [31:0] wdata_r;
    reg [3:0]  wstrb_r;
    reg        wlast_r;
    reg        wvalid_r;
    reg        bready_r;

    reg [31:0] dwr_addr_r;
    reg [31:0] dwr_wdata_r;
    reg [3:0]  dwr_wstrb_r;

    reg        icache_resp_valid_r;
    reg [31:0] icache_resp_data_r;
    reg        dcache_resp_valid_r;
    reg [31:0] dcache_resp_data_r;

    reg        issue_busy_r;

    wire bp_req_valid_w;
    wire [31:0] bp_req_pc_w;
    wire bp_resp_valid_w;
    wire bp_pred_taken_w;
    wire [31:0] bp_pred_target_w;

    wire ifu_out_valid_w;
    wire [31:0] ifu_out_pc_w;

    wire if1_icache_req_valid_w;
    wire [31:0] if1_icache_req_addr_w;
    wire if1_out_valid_w;
    wire [31:0] if1_out_pc_w;

    wire if2_out_valid_w;
    wire [31:0] if2_out_pc_w;
    wire [31:0] if2_out_inst_w;

    wire idu_rf_req_valid_w;
    wire [4:0] idu_rf_raddr1_w;
    wire [4:0] idu_rf_raddr2_w;
    wire idu_out_valid_w;
    wire [31:0] idu_out_pc_w;
    wire [31:0] idu_out_inst_w;
    wire [4:0] idu_out_rd_w;
    wire [31:0] idu_out_imm_w;
    wire idu_out_use_imm_w;
    wire idu_out_is_branch_w;
    wire idu_out_is_load_w;
    wire idu_out_is_store_w;
    wire idu_out_is_muldiv_w;

    wire rf_rvalid_w;
    wire [31:0] rf_rdata1_w;
    wire [31:0] rf_rdata2_w;
    wire rf_we_w;
    wire [4:0] rf_waddr_w;
    wire [31:0] rf_wdata_w;

    wire rrd_out_valid_w;
    wire [31:0] rrd_out_pc_w;
    wire [31:0] rrd_out_inst_w;
    wire [4:0] rrd_out_rd_w;
    wire [31:0] rrd_out_op1_w;
    wire [31:0] rrd_out_op2_w;
    wire [31:0] rrd_out_imm_w;
    wire rrd_out_use_imm_w;
    wire rrd_out_is_branch_w;
    wire rrd_out_is_load_w;
    wire rrd_out_is_store_w;
    wire rrd_out_is_muldiv_w;

    wire ex1_out_valid_w;
    wire [31:0] ex1_out_pc_w;
    wire [31:0] ex1_out_inst_w;
    wire [4:0] ex1_out_rd_w;
    wire [31:0] ex1_out_alu_result_w;
    wire [31:0] ex1_out_op1_w;
    wire [31:0] ex1_out_op2_w;
    wire [31:0] ex1_out_imm_w;
    wire ex1_out_is_branch_w;
    wire ex1_out_is_load_w;
    wire ex1_out_is_store_w;
    wire ex1_out_is_muldiv_w;

    wire muldiv_req_valid_w;
    wire muldiv_req_is_div_w;
    wire muldiv_req_signed_w;
    wire [31:0] muldiv_req_op1_w;
    wire [31:0] muldiv_req_op2_w;
    wire muldiv_resp_valid_w;
    wire [31:0] muldiv_resp_result_w;

    wire ex2_branch_update_valid_w;
    wire ex2_branch_taken_w;
    wire [31:0] ex2_branch_target_w;
    wire ex2_out_valid_w;
    wire [31:0] ex2_out_pc_w;
    wire [31:0] ex2_out_inst_w;
    wire [4:0] ex2_out_rd_w;
    wire [31:0] ex2_out_result_w;
    wire ex2_out_is_load_w;
    wire ex2_out_is_store_w;
    wire [31:0] ex2_out_store_data_w;

    wire mem1_dcache_req_valid_w;
    wire mem1_dcache_req_write_w;
    wire [31:0] mem1_dcache_req_addr_w;
    wire [31:0] mem1_dcache_req_wdata_w;
    wire [3:0] mem1_dcache_req_wstrb_w;
    wire mem1_out_valid_w;
    wire [31:0] mem1_out_pc_w;
    wire [31:0] mem1_out_inst_w;
    wire [4:0] mem1_out_rd_w;
    wire [31:0] mem1_out_wb_data_w;
    wire mem1_out_wen_w;

    wire wbu_ws_valid_w;
    wire [31:0] wbu_debug_wb_pc_w;
    wire [3:0] wbu_debug_wb_rf_wen_w;
    wire [4:0] wbu_debug_wb_rf_wnum_w;
    wire [31:0] wbu_debug_wb_rf_wdata_w;
    wire [31:0] wbu_debug_wb_inst_w;

    wire issue_fire_w;
    wire hold_fetch_w;
    wire branch_redirect_valid_w;
    wire [31:0] branch_redirect_pc_w;

    assign issue_fire_w = ifu_out_valid_w && (~issue_busy_r);
    assign hold_fetch_w = issue_busy_r;

    assign branch_redirect_valid_w = ex2_branch_update_valid_w;
    assign branch_redirect_pc_w    = ex2_branch_taken_w ? ex2_branch_target_w : (ex2_out_pc_w + 32'd4);

    always @(posedge aclk) begin
        if (reset) begin
            issue_busy_r <= 1'b0;
        end else begin
            if (issue_fire_w) begin
                issue_busy_r <= 1'b1;
            end
            if (wbu_ws_valid_w) begin
                issue_busy_r <= 1'b0;
            end
        end
    end

    branch_predictor_d1 u_bp (
        .clk          (aclk),
        .reset        (reset),
        .req_valid    (bp_req_valid_w),
        .req_pc       (bp_req_pc_w),
        .resp_valid   (bp_resp_valid_w),
        .pred_taken   (bp_pred_taken_w),
        .pred_target  (bp_pred_target_w),
        .update_valid (ex2_branch_update_valid_w),
        .update_taken (ex2_branch_taken_w),
        .update_pc    (ex2_out_pc_w),
        .update_target(ex2_branch_target_w)
    );

    stage0_ifu #(
        .RESET_PC(32'h1c000000)
    ) u_stage0_ifu (
        .clk           (aclk),
        .reset         (reset),
        .hold          (hold_fetch_w),
        .redirect_valid(branch_redirect_valid_w),
        .redirect_pc   (branch_redirect_pc_w),
        .bp_resp_valid (bp_resp_valid_w),
        .bp_pred_taken (bp_pred_taken_w),
        .bp_pred_target(bp_pred_target_w),
        .bp_req_valid  (bp_req_valid_w),
        .bp_req_pc     (bp_req_pc_w),
        .out_valid     (ifu_out_valid_w),
        .out_pc        (ifu_out_pc_w)
    );

    stage1_if1 u_stage1_if1 (
        .clk            (aclk),
        .reset          (reset),
        .in_valid       (issue_fire_w),
        .in_pc          (ifu_out_pc_w),
        .icache_req_valid(if1_icache_req_valid_w),
        .icache_req_addr(if1_icache_req_addr_w),
        .out_valid      (if1_out_valid_w),
        .out_pc         (if1_out_pc_w)
    );

    stage2_if2 u_stage2_if2 (
        .clk            (aclk),
        .reset          (reset),
        .in_valid       (if1_out_valid_w),
        .in_pc          (if1_out_pc_w),
        .icache_resp_valid(icache_resp_valid_r),
        .icache_resp_data (icache_resp_data_r),
        .out_valid      (if2_out_valid_w),
        .out_pc         (if2_out_pc_w),
        .out_inst       (if2_out_inst_w)
    );

    stage3_idu u_stage3_idu (
        .clk           (aclk),
        .reset         (reset),
        .in_valid      (if2_out_valid_w),
        .in_pc         (if2_out_pc_w),
        .in_inst       (if2_out_inst_w),
        .rf_req_valid  (idu_rf_req_valid_w),
        .rf_raddr1     (idu_rf_raddr1_w),
        .rf_raddr2     (idu_rf_raddr2_w),
        .out_valid     (idu_out_valid_w),
        .out_pc        (idu_out_pc_w),
        .out_inst      (idu_out_inst_w),
        .out_rd        (idu_out_rd_w),
        .out_imm       (idu_out_imm_w),
        .out_use_imm   (idu_out_use_imm_w),
        .out_is_branch (idu_out_is_branch_w),
        .out_is_load   (idu_out_is_load_w),
        .out_is_store  (idu_out_is_store_w),
        .out_is_muldiv (idu_out_is_muldiv_w)
    );

    regfile_d1 u_regfile_d1 (
        .clk       (aclk),
        .reset     (reset),
        .rreq_valid(idu_rf_req_valid_w),
        .raddr1    (idu_rf_raddr1_w),
        .raddr2    (idu_rf_raddr2_w),
        .rvalid    (rf_rvalid_w),
        .rdata1    (rf_rdata1_w),
        .rdata2    (rf_rdata2_w),
        .we        (rf_we_w),
        .waddr     (rf_waddr_w),
        .wdata     (rf_wdata_w),
        .dbg_raddr (reg_num),
        .dbg_rdata (rf_rdata)
    );

    stage4_rrd u_stage4_rrd (
        .clk          (aclk),
        .reset        (reset),
        .in_valid     (idu_out_valid_w),
        .in_pc        (idu_out_pc_w),
        .in_inst      (idu_out_inst_w),
        .in_rd        (idu_out_rd_w),
        .in_imm       (idu_out_imm_w),
        .in_use_imm   (idu_out_use_imm_w),
        .in_is_branch (idu_out_is_branch_w),
        .in_is_load   (idu_out_is_load_w),
        .in_is_store  (idu_out_is_store_w),
        .in_is_muldiv (idu_out_is_muldiv_w),
        .rf_rvalid    (rf_rvalid_w),
        .rf_rdata1    (rf_rdata1_w),
        .rf_rdata2    (rf_rdata2_w),
        .out_valid    (rrd_out_valid_w),
        .out_pc       (rrd_out_pc_w),
        .out_inst     (rrd_out_inst_w),
        .out_rd       (rrd_out_rd_w),
        .out_op1      (rrd_out_op1_w),
        .out_op2      (rrd_out_op2_w),
        .out_imm      (rrd_out_imm_w),
        .out_use_imm  (rrd_out_use_imm_w),
        .out_is_branch(rrd_out_is_branch_w),
        .out_is_load  (rrd_out_is_load_w),
        .out_is_store (rrd_out_is_store_w),
        .out_is_muldiv(rrd_out_is_muldiv_w)
    );

    stage5_ex1 u_stage5_ex1 (
        .clk          (aclk),
        .reset        (reset),
        .in_valid     (rrd_out_valid_w),
        .in_pc        (rrd_out_pc_w),
        .in_inst      (rrd_out_inst_w),
        .in_rd        (rrd_out_rd_w),
        .in_op1       (rrd_out_op1_w),
        .in_op2       (rrd_out_op2_w),
        .in_imm       (rrd_out_imm_w),
        .in_use_imm   (rrd_out_use_imm_w),
        .in_is_branch (rrd_out_is_branch_w),
        .in_is_load   (rrd_out_is_load_w),
        .in_is_store  (rrd_out_is_store_w),
        .in_is_muldiv (rrd_out_is_muldiv_w),
        .out_valid    (ex1_out_valid_w),
        .out_pc       (ex1_out_pc_w),
        .out_inst     (ex1_out_inst_w),
        .out_rd       (ex1_out_rd_w),
        .out_alu_result(ex1_out_alu_result_w),
        .out_op1      (ex1_out_op1_w),
        .out_op2      (ex1_out_op2_w),
        .out_imm      (ex1_out_imm_w),
        .out_is_branch(ex1_out_is_branch_w),
        .out_is_load  (ex1_out_is_load_w),
        .out_is_store (ex1_out_is_store_w),
        .out_is_muldiv(ex1_out_is_muldiv_w)
    );

    muldiv_stub u_muldiv_stub (
        .clk        (aclk),
        .reset      (reset),
        .req_valid  (muldiv_req_valid_w),
        .req_is_div (muldiv_req_is_div_w),
        .req_signed (muldiv_req_signed_w),
        .req_op1    (muldiv_req_op1_w),
        .req_op2    (muldiv_req_op2_w),
        .resp_valid (muldiv_resp_valid_w),
        .resp_result(muldiv_resp_result_w)
    );

    stage6_ex2 u_stage6_ex2 (
        .clk               (aclk),
        .reset             (reset),
        .in_valid          (ex1_out_valid_w),
        .in_pc             (ex1_out_pc_w),
        .in_inst           (ex1_out_inst_w),
        .in_rd             (ex1_out_rd_w),
        .in_alu_result     (ex1_out_alu_result_w),
        .in_op1            (ex1_out_op1_w),
        .in_op2            (ex1_out_op2_w),
        .in_imm            (ex1_out_imm_w),
        .in_is_branch      (ex1_out_is_branch_w),
        .in_is_load        (ex1_out_is_load_w),
        .in_is_store       (ex1_out_is_store_w),
        .in_is_muldiv      (ex1_out_is_muldiv_w),
        .muldiv_req_valid  (muldiv_req_valid_w),
        .muldiv_req_is_div (muldiv_req_is_div_w),
        .muldiv_req_signed (muldiv_req_signed_w),
        .muldiv_req_op1    (muldiv_req_op1_w),
        .muldiv_req_op2    (muldiv_req_op2_w),
        .muldiv_resp_valid (muldiv_resp_valid_w),
        .muldiv_resp_result(muldiv_resp_result_w),
        .branch_update_valid(ex2_branch_update_valid_w),
        .branch_taken      (ex2_branch_taken_w),
        .branch_target     (ex2_branch_target_w),
        .out_valid         (ex2_out_valid_w),
        .out_pc            (ex2_out_pc_w),
        .out_inst          (ex2_out_inst_w),
        .out_rd            (ex2_out_rd_w),
        .out_result        (ex2_out_result_w),
        .out_is_load       (ex2_out_is_load_w),
        .out_is_store      (ex2_out_is_store_w),
        .out_store_data    (ex2_out_store_data_w)
    );

    stage7_mem1 u_stage7_mem1 (
        .clk            (aclk),
        .reset          (reset),
        .in_valid       (ex2_out_valid_w),
        .in_pc          (ex2_out_pc_w),
        .in_inst        (ex2_out_inst_w),
        .in_rd          (ex2_out_rd_w),
        .in_result      (ex2_out_result_w),
        .in_is_load     (ex2_out_is_load_w),
        .in_is_store    (ex2_out_is_store_w),
        .in_store_data  (ex2_out_store_data_w),
        .dcache_req_valid(mem1_dcache_req_valid_w),
        .dcache_req_write(mem1_dcache_req_write_w),
        .dcache_req_addr (mem1_dcache_req_addr_w),
        .dcache_req_wdata(mem1_dcache_req_wdata_w),
        .dcache_req_wstrb(mem1_dcache_req_wstrb_w),
        .dcache_resp_valid(dcache_resp_valid_r),
        .dcache_resp_data (dcache_resp_data_r),
        .out_valid       (mem1_out_valid_w),
        .out_pc          (mem1_out_pc_w),
        .out_inst        (mem1_out_inst_w),
        .out_rd          (mem1_out_rd_w),
        .out_wb_data     (mem1_out_wb_data_w),
        .out_wen         (mem1_out_wen_w)
    );

    stage8_wbu u_stage8_wbu (
        .clk             (aclk),
        .reset           (reset),
        .in_valid        (mem1_out_valid_w),
        .in_pc           (mem1_out_pc_w),
        .in_inst         (mem1_out_inst_w),
        .in_rd           (mem1_out_rd_w),
        .in_wb_data      (mem1_out_wb_data_w),
        .in_wen          (mem1_out_wen_w),
        .rf_we           (rf_we_w),
        .rf_waddr        (rf_waddr_w),
        .rf_wdata        (rf_wdata_w),
        .ws_valid        (wbu_ws_valid_w),
        .debug_wb_pc     (wbu_debug_wb_pc_w),
        .debug_wb_rf_wen (wbu_debug_wb_rf_wen_w),
        .debug_wb_rf_wnum(wbu_debug_wb_rf_wnum_w),
        .debug_wb_rf_wdata(wbu_debug_wb_rf_wdata_w),
        .debug_wb_inst   (wbu_debug_wb_inst_w)
    );

    assign ws_valid           = wbu_ws_valid_w;
    assign debug0_wb_pc       = wbu_debug_wb_pc_w;
    assign debug0_wb_rf_wen   = wbu_debug_wb_rf_wen_w;
    assign debug0_wb_rf_wnum  = wbu_debug_wb_rf_wnum_w;
    assign debug0_wb_rf_wdata = wbu_debug_wb_rf_wdata_w;
    assign debug0_wb_inst     = wbu_debug_wb_inst_w;

    assign arid    = arid_r;
    assign araddr  = araddr_r;
    assign arlen   = arlen_r;
    assign arsize  = arsize_r;
    assign arburst = arburst_r;
    assign arlock  = arlock_r;
    assign arcache = arcache_r;
    assign arprot  = arprot_r;
    assign arvalid = arvalid_r;
    assign rready  = rready_r;

    assign awid    = awid_r;
    assign awaddr  = awaddr_r;
    assign awlen   = awlen_r;
    assign awsize  = awsize_r;
    assign awburst = awburst_r;
    assign awlock  = awlock_r;
    assign awcache = awcache_r;
    assign awprot  = awprot_r;
    assign awvalid = awvalid_r;

    assign wid     = wid_r;
    assign wdata   = wdata_r;
    assign wstrb   = wstrb_r;
    assign wlast   = wlast_r;
    assign wvalid  = wvalid_r;
    assign bready  = bready_r;

    always @(posedge aclk) begin
        if (reset) begin
            axi_state_r <= AXI_IDLE;

            arid_r    <= 4'b0;
            araddr_r  <= 32'b0;
            arlen_r   <= 8'b0;
            arsize_r  <= 3'b010;
            arburst_r <= 2'b01;
            arlock_r  <= 2'b0;
            arcache_r <= 4'b0;
            arprot_r  <= 3'b0;
            arvalid_r <= 1'b0;
            rready_r  <= 1'b0;

            awid_r    <= 4'b0;
            awaddr_r  <= 32'b0;
            awlen_r   <= 8'b0;
            awsize_r  <= 3'b010;
            awburst_r <= 2'b01;
            awlock_r  <= 2'b0;
            awcache_r <= 4'b0;
            awprot_r  <= 3'b0;
            awvalid_r <= 1'b0;

            wid_r    <= 4'b0;
            wdata_r  <= 32'b0;
            wstrb_r  <= 4'b0;
            wlast_r  <= 1'b1;
            wvalid_r <= 1'b0;
            bready_r <= 1'b0;

            dwr_addr_r  <= 32'b0;
            dwr_wdata_r <= 32'b0;
            dwr_wstrb_r <= 4'b0;

            icache_resp_valid_r <= 1'b0;
            icache_resp_data_r  <= 32'h03400000;
            dcache_resp_valid_r <= 1'b0;
            dcache_resp_data_r  <= 32'b0;
        end else begin
            icache_resp_valid_r <= 1'b0;
            dcache_resp_valid_r <= 1'b0;

            case (axi_state_r)
                AXI_IDLE: begin
                    if (mem1_dcache_req_valid_w) begin
                        if (mem1_dcache_req_write_w) begin
                            dwr_addr_r  <= mem1_dcache_req_addr_w;
                            dwr_wdata_r <= mem1_dcache_req_wdata_w;
                            dwr_wstrb_r <= mem1_dcache_req_wstrb_w;

                            awid_r    <= 4'h1;
                            awaddr_r  <= mem1_dcache_req_addr_w;
                            awlen_r   <= 8'd0;
                            awsize_r  <= 3'b010;
                            awburst_r <= 2'b01;
                            awlock_r  <= 2'b0;
                            awcache_r <= 4'b0;
                            awprot_r  <= 3'b0;
                            awvalid_r <= 1'b1;

                            axi_state_r <= AXI_D_AW;
                        end else begin
                            arid_r    <= 4'h1;
                            araddr_r  <= mem1_dcache_req_addr_w;
                            arlen_r   <= 8'd0;
                            arsize_r  <= 3'b010;
                            arburst_r <= 2'b01;
                            arlock_r  <= 2'b0;
                            arcache_r <= 4'b0;
                            arprot_r  <= 3'b0;
                            arvalid_r <= 1'b1;

                            axi_state_r <= AXI_D_AR;
                        end
                    end else if (if1_icache_req_valid_w) begin
                        arid_r    <= 4'h0;
                        araddr_r  <= if1_icache_req_addr_w;
                        arlen_r   <= 8'd0;
                        arsize_r  <= 3'b010;
                        arburst_r <= 2'b01;
                        arlock_r  <= 2'b0;
                        arcache_r <= 4'b0;
                        arprot_r  <= 3'b0;
                        arvalid_r <= 1'b1;

                        axi_state_r <= AXI_I_AR;
                    end
                end

                AXI_I_AR: begin
                    if (arvalid_r && arready) begin
                        arvalid_r <= 1'b0;
                        rready_r  <= 1'b1;
                        axi_state_r <= AXI_I_R;
                    end
                end

                AXI_I_R: begin
                    if (rvalid && rready_r) begin
                        rready_r <= 1'b0;
                        icache_resp_valid_r <= 1'b1;
                        icache_resp_data_r  <= rdata;
                        axi_state_r <= AXI_IDLE;
                    end
                end

                AXI_D_AR: begin
                    if (arvalid_r && arready) begin
                        arvalid_r <= 1'b0;
                        rready_r  <= 1'b1;
                        axi_state_r <= AXI_D_R;
                    end
                end

                AXI_D_R: begin
                    if (rvalid && rready_r) begin
                        rready_r <= 1'b0;
                        dcache_resp_valid_r <= 1'b1;
                        dcache_resp_data_r  <= rdata;
                        axi_state_r <= AXI_IDLE;
                    end
                end

                AXI_D_AW: begin
                    if (awvalid_r && awready) begin
                        awvalid_r <= 1'b0;

                        wid_r    <= 4'h1;
                        wdata_r  <= dwr_wdata_r;
                        wstrb_r  <= dwr_wstrb_r;
                        wlast_r  <= 1'b1;
                        wvalid_r <= 1'b1;

                        axi_state_r <= AXI_D_W;
                    end
                end

                AXI_D_W: begin
                    if (wvalid_r && wready) begin
                        wvalid_r <= 1'b0;
                        bready_r <= 1'b1;
                        axi_state_r <= AXI_D_B;
                    end
                end

                AXI_D_B: begin
                    if (bvalid && bready_r) begin
                        bready_r <= 1'b0;
                        dcache_resp_valid_r <= 1'b1;
                        dcache_resp_data_r  <= 32'b0;
                        axi_state_r <= AXI_IDLE;
                    end
                end

                default: begin
                    axi_state_r <= AXI_IDLE;
                end
            endcase
        end
    end

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
    output wire [31:0] debug_wb_rf_wdata
);

    wire [31:0] debug_wb_inst_unused;

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
        .debug0_wb_inst     (debug_wb_inst_unused)
    );

endmodule
