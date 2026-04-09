module stage8_wbu (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_wb_data,
    input  wire        in_wen,
    output reg         rf_we,
    output reg  [4:0]  rf_waddr,
    output reg  [31:0] rf_wdata,
    output reg         ws_valid,
    output reg  [31:0] debug_wb_pc,
    output reg  [3:0]  debug_wb_rf_wen,
    output reg  [4:0]  debug_wb_rf_wnum,
    output reg  [31:0] debug_wb_rf_wdata,
    output reg  [31:0] debug_wb_inst
);

    wire wen_real;
    assign wen_real = in_valid && in_wen && (in_rd != 5'b0);

    always @(posedge clk) begin
        if (reset) begin
            rf_we            <= 1'b0;
            rf_waddr         <= 5'b0;
            rf_wdata         <= 32'b0;
            ws_valid         <= 1'b0;
            debug_wb_pc      <= 32'b0;
            debug_wb_rf_wen  <= 4'b0;
            debug_wb_rf_wnum <= 5'b0;
            debug_wb_rf_wdata<= 32'b0;
            debug_wb_inst    <= 32'b0;
        end else begin
            rf_we            <= wen_real;
            rf_waddr         <= in_rd;
            rf_wdata         <= in_wb_data;

            ws_valid         <= in_valid;
            debug_wb_pc      <= in_pc;
            debug_wb_rf_wen  <= {4{wen_real}};
            debug_wb_rf_wnum <= in_rd;
            debug_wb_rf_wdata<= in_wb_data;
            debug_wb_inst    <= in_inst;
        end
    end

endmodule
