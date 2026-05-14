`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ============================================================================
// AXI 仲裁器 - L2 Cache 两个通道共享一条对外 AXI 总线
//
// Master 0 (L2 读通道)：L2 burst read，由 L1I miss/prefetch 或 L1D read miss 触发，优先级高
// Master 1 (L2 写通道)：L2 write-through，由 L1D store 触发，优先级低
// 当前事务（burst）完成后才切换 Master。
// ============================================================================
module axi_arbiter #(
    parameter AXI_ID_WIDTH = 4
) (
    input  wire        clk,
    input  wire        rst_n,

    // Master 0 (L2 读通道) - AR/R only
    input  wire        m0_axi_arvalid_i,
    output reg         m0_axi_arready_o,
    input  wire [31:0] m0_axi_araddr_i,
    input  wire [AXI_ID_WIDTH-1:0] m0_axi_arid_i,
    input  wire [7:0]  m0_axi_arlen_i,
    input  wire [2:0]  m0_axi_arsize_i,
    input  wire [1:0]  m0_axi_arburst_i,
    output reg         m0_axi_rvalid_o,
    input  wire        m0_axi_rready_i,
    output reg  [31:0] m0_axi_rdata_o,
    output reg  [1:0]  m0_axi_rresp_o,
    output reg  [AXI_ID_WIDTH-1:0] m0_axi_rid_o,
    output reg         m0_axi_rlast_o,

    // Master 1 (L2 写通道) - AR/R/AW/W/B
    input  wire        m1_axi_arvalid_i,
    output reg         m1_axi_arready_o,
    input  wire [31:0] m1_axi_araddr_i,
    input  wire [AXI_ID_WIDTH-1:0] m1_axi_arid_i,
    input  wire [7:0]  m1_axi_arlen_i,
    input  wire [2:0]  m1_axi_arsize_i,
    input  wire [1:0]  m1_axi_arburst_i,
    output reg         m1_axi_rvalid_o,
    input  wire        m1_axi_rready_i,
    output reg  [31:0] m1_axi_rdata_o,
    output reg  [1:0]  m1_axi_rresp_o,
    output reg  [AXI_ID_WIDTH-1:0] m1_axi_rid_o,
    output reg         m1_axi_rlast_o,
    input  wire        m1_axi_awvalid_i,
    output wire        m1_axi_awready_o,
    input  wire [31:0] m1_axi_awaddr_i,
    input  wire [AXI_ID_WIDTH-1:0] m1_axi_awid_i,
    input  wire [7:0]  m1_axi_awlen_i,
    input  wire [2:0]  m1_axi_awsize_i,
    input  wire [1:0]  m1_axi_awburst_i,
    input  wire        m1_axi_wvalid_i,
    output wire        m1_axi_wready_o,
    input  wire [31:0] m1_axi_wdata_i,
    input  wire [3:0]  m1_axi_wstrb_i,
    input  wire        m1_axi_wlast_i,
    output wire        m1_axi_bvalid_o,
    input  wire        m1_axi_bready_i,
    output wire [1:0]  m1_axi_bresp_o,
    output wire [AXI_ID_WIDTH-1:0] m1_axi_bid_o,

    // Slave (Memory)
    output reg         s_axi_arvalid_o,
    input  wire        s_axi_arready_i,
    output reg  [31:0] s_axi_araddr_o,
    output reg  [AXI_ID_WIDTH-1:0] s_axi_arid_o,
    output reg  [7:0]  s_axi_arlen_o,
    output reg  [2:0]  s_axi_arsize_o,
    output reg  [1:0]  s_axi_arburst_o,
    input  wire        s_axi_rvalid_i,
    output wire        s_axi_rready_o,
    input  wire [31:0] s_axi_rdata_i,
    input  wire [1:0]  s_axi_rresp_i,
    input  wire [AXI_ID_WIDTH-1:0] s_axi_rid_i,
    input  wire        s_axi_rlast_i,
    output wire        s_axi_awvalid_o,
    input  wire        s_axi_awready_i,
    output wire [31:0] s_axi_awaddr_o,
    output wire [AXI_ID_WIDTH-1:0] s_axi_awid_o,
    output wire [7:0]  s_axi_awlen_o,
    output wire [2:0]  s_axi_awsize_o,
    output wire [1:0]  s_axi_awburst_o,
    output wire        s_axi_wvalid_o,
    input  wire        s_axi_wready_i,
    output wire [31:0] s_axi_wdata_o,
    output wire [3:0]  s_axi_wstrb_o,
    output wire        s_axi_wlast_o,
    input  wire        s_axi_bvalid_i,
    output wire        s_axi_bready_o,
    input  wire [1:0]  s_axi_bresp_i,
    input  wire [AXI_ID_WIDTH-1:0] s_axi_bid_i
);

    // 仲裁状态：0=idle, 1=m0 active, 2=m1 active
    reg [1:0] arb_state_q;
    localparam ARB_IDLE = 2'd0;
    localparam ARB_M0 = 2'd1;
    localparam ARB_M1 = 2'd2;

    // AR 通道仲裁
    always @(posedge clk) begin
        if (!rst_n) begin
            arb_state_q <= ARB_IDLE;
        end else begin
            case (arb_state_q)
                ARB_IDLE: begin
                    if (m0_axi_arvalid_i)
                        arb_state_q <= ARB_M0;
                    else if (m1_axi_arvalid_i)
                        arb_state_q <= ARB_M1;
                end
                ARB_M0: begin
                    if (s_axi_rvalid_i && s_axi_rlast_i && m0_axi_rready_i)
                        arb_state_q <= ARB_IDLE;
                end
                ARB_M1: begin
                    if (s_axi_rvalid_i && s_axi_rlast_i && m1_axi_rready_i)
                        arb_state_q <= ARB_IDLE;
                end
            endcase
        end
    end

    // AR 通道多路复用
    always @(*) begin
        case (arb_state_q)
            ARB_M0, ARB_IDLE: begin
                if (m0_axi_arvalid_i) begin
                    s_axi_arvalid_o = m0_axi_arvalid_i;
                    s_axi_araddr_o = m0_axi_araddr_i;
                    s_axi_arid_o = m0_axi_arid_i;
                    s_axi_arlen_o = m0_axi_arlen_i;
                    s_axi_arsize_o = m0_axi_arsize_i;
                    s_axi_arburst_o = m0_axi_arburst_i;
                    m0_axi_arready_o = s_axi_arready_i;
                    m1_axi_arready_o = 1'b0;
                end else begin
                    s_axi_arvalid_o = m1_axi_arvalid_i;
                    s_axi_araddr_o = m1_axi_araddr_i;
                    s_axi_arid_o = m1_axi_arid_i;
                    s_axi_arlen_o = m1_axi_arlen_i;
                    s_axi_arsize_o = m1_axi_arsize_i;
                    s_axi_arburst_o = m1_axi_arburst_i;
                    m0_axi_arready_o = 1'b0;
                    m1_axi_arready_o = s_axi_arready_i;
                end
            end
            ARB_M1: begin
                s_axi_arvalid_o = m1_axi_arvalid_i;
                s_axi_araddr_o = m1_axi_araddr_i;
                s_axi_arid_o = m1_axi_arid_i;
                s_axi_arlen_o = m1_axi_arlen_i;
                s_axi_arsize_o = m1_axi_arsize_i;
                s_axi_arburst_o = m1_axi_arburst_i;
                m0_axi_arready_o = 1'b0;
                m1_axi_arready_o = s_axi_arready_i;
            end
            default: begin
                s_axi_arvalid_o = 1'b0;
                s_axi_araddr_o = 32'h0;
                s_axi_arid_o = {AXI_ID_WIDTH{1'b0}};
                s_axi_arlen_o = 8'h0;
                s_axi_arsize_o = 3'b010;
                s_axi_arburst_o = 2'b0;
                m0_axi_arready_o = 1'b0;
                m1_axi_arready_o = 1'b0;
            end
        endcase
    end

    // R 通道路由
    assign s_axi_rready_o = (arb_state_q == ARB_M0) ? m0_axi_rready_i : m1_axi_rready_i;

    always @(*) begin
        if (arb_state_q == ARB_M0) begin
            m0_axi_rvalid_o = s_axi_rvalid_i;
            m0_axi_rdata_o = s_axi_rdata_i;
            m0_axi_rresp_o = s_axi_rresp_i;
            m0_axi_rid_o = s_axi_rid_i;
            m0_axi_rlast_o = s_axi_rlast_i;
            m1_axi_rvalid_o = 1'b0;
            m1_axi_rdata_o = 32'h0;
            m1_axi_rresp_o = 2'b0;
            m1_axi_rid_o = {AXI_ID_WIDTH{1'b0}};
            m1_axi_rlast_o = 1'b0;
        end else begin
            m0_axi_rvalid_o = 1'b0;
            m0_axi_rdata_o = 32'h0;
            m0_axi_rresp_o = 2'b0;
            m0_axi_rid_o = {AXI_ID_WIDTH{1'b0}};
            m0_axi_rlast_o = 1'b0;
            m1_axi_rvalid_o = s_axi_rvalid_i;
            m1_axi_rdata_o = s_axi_rdata_i;
            m1_axi_rresp_o = s_axi_rresp_i;
            m1_axi_rid_o = s_axi_rid_i;
            m1_axi_rlast_o = s_axi_rlast_i;
        end
    end

    // AW/W/B 通道直通（只有 DCache 写）
    assign s_axi_awvalid_o = m1_axi_awvalid_i;
    assign s_axi_awaddr_o = m1_axi_awaddr_i;
    assign s_axi_awid_o = m1_axi_awid_i;
    assign s_axi_awlen_o = m1_axi_awlen_i;
    assign s_axi_awsize_o = m1_axi_awsize_i;
    assign s_axi_awburst_o = m1_axi_awburst_i;
    assign m1_axi_awready_o = s_axi_awready_i;

    assign s_axi_wvalid_o = m1_axi_wvalid_i;
    assign s_axi_wdata_o = m1_axi_wdata_i;
    assign s_axi_wstrb_o = m1_axi_wstrb_i;
    assign s_axi_wlast_o = m1_axi_wlast_i;
    assign m1_axi_wready_o = s_axi_wready_i;

    assign m1_axi_bvalid_o = s_axi_bvalid_i;
    assign m1_axi_bresp_o = s_axi_bresp_i;
    assign m1_axi_bid_o = s_axi_bid_i;
    assign s_axi_bready_o = m1_axi_bready_i;

`ifdef CPU_DEBUG_HAS_RUNTIME
    wire [1:0] dbg_expected_ar_grant =
        ((arb_state_q != ARB_M1) && m0_axi_arvalid_i) ? ARB_M0 :
        (m1_axi_arvalid_i ? ARB_M1 : ARB_IDLE);
    wire [1:0] dbg_actual_ar_grant =
        (s_axi_arvalid_o && m0_axi_arready_o) ? ARB_M0 :
        ((s_axi_arvalid_o && m1_axi_arready_o) ? ARB_M1 : ARB_IDLE);

    reg        dbg_m0_ar_hold_q;
    reg [31:0] dbg_m0_araddr_q;
    reg [AXI_ID_WIDTH-1:0] dbg_m0_arid_q;
    reg [7:0]  dbg_m0_arlen_q;
    reg [1:0]  dbg_m0_arburst_q;
    reg        dbg_m1_ar_hold_q;
    reg [31:0] dbg_m1_araddr_q;
    reg [AXI_ID_WIDTH-1:0] dbg_m1_arid_q;
    reg [7:0]  dbg_m1_arlen_q;
    reg [1:0]  dbg_m1_arburst_q;
    reg        dbg_m1_aw_hold_q;
    reg [31:0] dbg_m1_awaddr_q;
    reg [AXI_ID_WIDTH-1:0] dbg_m1_awid_q;
    reg [7:0]  dbg_m1_awlen_q;
    reg [1:0]  dbg_m1_awburst_q;
    reg        dbg_m1_w_hold_q;
    reg [31:0] dbg_m1_wdata_q;
    reg [3:0]  dbg_m1_wstrb_q;
    reg        dbg_m1_wlast_q;

    `CPU_DEBUG_WATCHDOG(axi_read_burst, clk, rst_n,
        (arb_state_q != ARB_IDLE),
        (s_axi_rvalid_i && s_axi_rready_o),
        64,
        $sformatf("[AXI][DEADLOCK] read burst owner=%0d m0_ready=%0d m1_ready=%0d slave_r(valid=%0d ready=%0d last=%0d)",
                  arb_state_q, m0_axi_rready_i, m1_axi_rready_i, s_axi_rvalid_i, s_axi_rready_o, s_axi_rlast_i))

    always @(posedge clk) begin
        if (!rst_n) begin
            dbg_m0_ar_hold_q <= 1'b0;
            dbg_m1_ar_hold_q <= 1'b0;
            dbg_m1_aw_hold_q <= 1'b0;
            dbg_m1_w_hold_q  <= 1'b0;
            `CPU_DEBUG($sformatf("[AXI][RESET] expected_state=ARB_IDLE(0) actual_state=%0d", arb_state_q));
        end else begin
            `CPU_ASSERT("AXI_AR_SINGLE_GRANT",
                !(m0_axi_arready_o && m1_axi_arready_o),
                $sformatf("[AXI][ASSERT] both AR masters ready: state=%0d m0_valid=%0d m1_valid=%0d s_ready=%0d",
                          arb_state_q, m0_axi_arvalid_i, m1_axi_arvalid_i, s_axi_arready_i))
            `CPU_ASSERT("AXI_R_SINGLE_ROUTE",
                !(m0_axi_rvalid_o && m1_axi_rvalid_o),
                $sformatf("[AXI][ASSERT] R channel routed to both masters: state=%0d s_rvalid=%0d id=0x%0x",
                          arb_state_q, s_axi_rvalid_i, s_axi_rid_i))
            `CPU_ASSERT("AXI_R_HAS_OWNER",
                !(s_axi_rvalid_i && (arb_state_q == ARB_IDLE)),
                $sformatf("[AXI][ASSERT] slave R valid while no AR owner: id=0x%0x last=%0d data=0x%08x",
                          s_axi_rid_i, s_axi_rlast_i, s_axi_rdata_i))

            if (dbg_m0_ar_hold_q) begin
                `CPU_ASSERT("AXI_M0_AR_STABLE",
                    !m0_axi_arvalid_i || m0_axi_arready_o ||
                    ((m0_axi_araddr_i == dbg_m0_araddr_q) &&
                     (m0_axi_arid_i == dbg_m0_arid_q) &&
                     (m0_axi_arlen_i == dbg_m0_arlen_q) &&
                     (m0_axi_arburst_i == dbg_m0_arburst_q)),
                    $sformatf("[AXI][ASSERT] M0 AR changed while stalled: prev(addr=0x%08x id=0x%0x len=%0d burst=%0d) now(addr=0x%08x id=0x%0x len=%0d burst=%0d)",
                              dbg_m0_araddr_q, dbg_m0_arid_q, dbg_m0_arlen_q, dbg_m0_arburst_q,
                              m0_axi_araddr_i, m0_axi_arid_i, m0_axi_arlen_i, m0_axi_arburst_i))
            end
            if (dbg_m1_ar_hold_q) begin
                `CPU_ASSERT("AXI_M1_AR_STABLE",
                    !m1_axi_arvalid_i || m1_axi_arready_o ||
                    ((m1_axi_araddr_i == dbg_m1_araddr_q) &&
                     (m1_axi_arid_i == dbg_m1_arid_q) &&
                     (m1_axi_arlen_i == dbg_m1_arlen_q) &&
                     (m1_axi_arburst_i == dbg_m1_arburst_q)),
                    $sformatf("[AXI][ASSERT] M1 AR changed while stalled: prev(addr=0x%08x id=0x%0x len=%0d burst=%0d) now(addr=0x%08x id=0x%0x len=%0d burst=%0d)",
                              dbg_m1_araddr_q, dbg_m1_arid_q, dbg_m1_arlen_q, dbg_m1_arburst_q,
                              m1_axi_araddr_i, m1_axi_arid_i, m1_axi_arlen_i, m1_axi_arburst_i))
            end
            if (dbg_m1_aw_hold_q) begin
                `CPU_ASSERT("AXI_M1_AW_STABLE",
                    !m1_axi_awvalid_i || m1_axi_awready_o ||
                    ((m1_axi_awaddr_i == dbg_m1_awaddr_q) &&
                     (m1_axi_awid_i == dbg_m1_awid_q) &&
                     (m1_axi_awlen_i == dbg_m1_awlen_q) &&
                     (m1_axi_awburst_i == dbg_m1_awburst_q)),
                    $sformatf("[AXI][ASSERT] M1 AW changed while stalled: prev(addr=0x%08x id=0x%0x len=%0d burst=%0d) now(addr=0x%08x id=0x%0x len=%0d burst=%0d)",
                              dbg_m1_awaddr_q, dbg_m1_awid_q, dbg_m1_awlen_q, dbg_m1_awburst_q,
                              m1_axi_awaddr_i, m1_axi_awid_i, m1_axi_awlen_i, m1_axi_awburst_i))
            end
            if (dbg_m1_w_hold_q) begin
                `CPU_ASSERT("AXI_M1_W_STABLE",
                    !m1_axi_wvalid_i || m1_axi_wready_o ||
                    ((m1_axi_wdata_i == dbg_m1_wdata_q) &&
                     (m1_axi_wstrb_i == dbg_m1_wstrb_q) &&
                     (m1_axi_wlast_i == dbg_m1_wlast_q)),
                    $sformatf("[AXI][ASSERT] M1 W changed while stalled: prev(data=0x%08x strb=0x%0x last=%0d) now(data=0x%08x strb=0x%0x last=%0d)",
                              dbg_m1_wdata_q, dbg_m1_wstrb_q, dbg_m1_wlast_q,
                              m1_axi_wdata_i, m1_axi_wstrb_i, m1_axi_wlast_i))
            end

            dbg_m0_ar_hold_q <= m0_axi_arvalid_i && !m0_axi_arready_o;
            dbg_m0_araddr_q  <= m0_axi_araddr_i;
            dbg_m0_arid_q    <= m0_axi_arid_i;
            dbg_m0_arlen_q   <= m0_axi_arlen_i;
            dbg_m0_arburst_q <= m0_axi_arburst_i;
            dbg_m1_ar_hold_q <= m1_axi_arvalid_i && !m1_axi_arready_o;
            dbg_m1_araddr_q  <= m1_axi_araddr_i;
            dbg_m1_arid_q    <= m1_axi_arid_i;
            dbg_m1_arlen_q   <= m1_axi_arlen_i;
            dbg_m1_arburst_q <= m1_axi_arburst_i;
            dbg_m1_aw_hold_q <= m1_axi_awvalid_i && !m1_axi_awready_o;
            dbg_m1_awaddr_q  <= m1_axi_awaddr_i;
            dbg_m1_awid_q    <= m1_axi_awid_i;
            dbg_m1_awlen_q   <= m1_axi_awlen_i;
            dbg_m1_awburst_q <= m1_axi_awburst_i;
            dbg_m1_w_hold_q  <= m1_axi_wvalid_i && !m1_axi_wready_o;
            dbg_m1_wdata_q   <= m1_axi_wdata_i;
            dbg_m1_wstrb_q   <= m1_axi_wstrb_i;
            dbg_m1_wlast_q   <= m1_axi_wlast_i;

            if (m0_axi_arvalid_i || m1_axi_arvalid_i || s_axi_arvalid_o) begin
                `CPU_DEBUG($sformatf(
                    "[AXI][AR] state actual=%0d expected_grant=%0d actual_grant=%0d m0(valid=%0d ready=%0d addr=0x%08x id=0x%0x) m1(valid=%0d ready=%0d addr=0x%08x id=0x%0x) slave(valid=%0d ready=%0d addr=0x%08x id=0x%0x)",
                    arb_state_q, dbg_expected_ar_grant, dbg_actual_ar_grant,
                    m0_axi_arvalid_i, m0_axi_arready_o, m0_axi_araddr_i, m0_axi_arid_i,
                    m1_axi_arvalid_i, m1_axi_arready_o, m1_axi_araddr_i, m1_axi_arid_i,
                    s_axi_arvalid_o, s_axi_arready_i, s_axi_araddr_o, s_axi_arid_o
                ));
            end
            if (s_axi_rvalid_i || m0_axi_rvalid_o || m1_axi_rvalid_o) begin
                `CPU_DEBUG($sformatf(
                    "[AXI][R] state actual=%0d expected_master=%0d actual_m0_valid=%0d actual_m1_valid=%0d slave(valid=%0d ready=%0d last=%0d data=0x%08x id=0x%0x)",
                    arb_state_q, arb_state_q, m0_axi_rvalid_o, m1_axi_rvalid_o,
                    s_axi_rvalid_i, s_axi_rready_o, s_axi_rlast_i, s_axi_rdata_i, s_axi_rid_i
                ));
            end
            if (m1_axi_awvalid_i || m1_axi_wvalid_i || s_axi_bvalid_i) begin
                `CPU_DEBUG($sformatf(
                    "[AXI][WRITE] aw(valid=%0d ready=%0d addr=0x%08x id=0x%0x) w(valid=%0d ready=%0d data=0x%08x strb=0x%0x last=%0d) b(valid=%0d ready=%0d id=0x%0x resp=0x%0x)",
                    s_axi_awvalid_o, m1_axi_awready_o, s_axi_awaddr_o, s_axi_awid_o,
                    s_axi_wvalid_o, m1_axi_wready_o, s_axi_wdata_o, s_axi_wstrb_o, s_axi_wlast_o,
                    m1_axi_bvalid_o, s_axi_bready_o, m1_axi_bid_o, m1_axi_bresp_o
                ));
            end
        end
    end
`endif

    `CPU_DEBUG_MODULE("axi_arbiter")
endmodule
