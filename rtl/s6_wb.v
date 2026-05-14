module s6_wb (
    input  wire        clk,
    input  wire        reset,

    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_wb_data,
    input  wire        in_wen,
    input  wire        in_csr_we,
    input  wire [13:0] in_csr_addr,
    input  wire [31:0] in_csr_wdata,
    input  wire        in_exception,
    input  wire [5:0]  in_exception_ecode,
    input  wire [10:0] in_interrupt_pending,
    input  wire        in_ertn,

    output reg         gpr_we,
    output reg  [4:0]  gpr_waddr,
    output reg  [31:0] gpr_wdata,
    output reg         csr_we,
    output reg  [13:0] csr_addr,
    output reg  [31:0] csr_wdata,

    output reg         ws_valid,
    output reg  [31:0] debug_wb_pc,
    output reg  [3:0]  debug_wb_rf_wen,
    output reg  [4:0]  debug_wb_rf_wnum,
    output reg  [31:0] debug_wb_rf_wdata,
    output reg  [31:0] debug_wb_inst,
    output reg         debug_excp_valid,
    output reg  [5:0]  debug_excp_ecode,
    output reg  [10:0] debug_intr_no,
    output reg         debug_ertn_valid
);

    wire wen_real;
    assign wen_real = in_valid && !in_exception && in_wen && (in_rd != 5'b0);

    always @(posedge clk) begin
        if (reset) begin
            gpr_we             <= 1'b0;
            gpr_waddr          <= 5'b0;
            gpr_wdata          <= 32'b0;
            csr_we             <= 1'b0;
            csr_addr           <= 14'b0;
            csr_wdata          <= 32'b0;
            ws_valid           <= 1'b0;
            debug_wb_pc        <= 32'b0;
            debug_wb_rf_wen    <= 4'b0;
            debug_wb_rf_wnum   <= 5'b0;
            debug_wb_rf_wdata  <= 32'b0;
            debug_wb_inst      <= 32'b0;
            debug_excp_valid   <= 1'b0;
            debug_excp_ecode   <= 6'b0;
            debug_intr_no      <= 11'b0;
            debug_ertn_valid   <= 1'b0;
        end else begin
            gpr_we             <= wen_real;
            gpr_waddr          <= in_rd;
            gpr_wdata          <= in_wb_data;
            csr_we             <= in_valid && !in_exception && in_csr_we;
            csr_addr           <= in_csr_addr;
            csr_wdata          <= in_csr_wdata;

            ws_valid           <= in_valid;
            debug_wb_pc        <= in_pc;
            debug_wb_rf_wen    <= {4{wen_real}};
            debug_wb_rf_wnum   <= in_rd;
            debug_wb_rf_wdata  <= in_wb_data;
            debug_wb_inst      <= in_inst;
            debug_excp_valid   <= in_valid && in_exception;
            debug_excp_ecode   <= in_exception_ecode;
            debug_intr_no      <= in_interrupt_pending;
            debug_ertn_valid   <= in_valid && !in_exception && in_ertn;
        end
    end

endmodule
