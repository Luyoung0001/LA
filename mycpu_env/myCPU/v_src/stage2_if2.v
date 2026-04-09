module stage2_if2 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire        icache_resp_valid,
    input  wire [31:0] icache_resp_data,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst
);

    reg        pend_valid;
    reg [31:0] pend_pc;

    always @(posedge clk) begin
        if (reset) begin
            pend_valid   <= 1'b0;
            pend_pc      <= 32'b0;
            out_valid    <= 1'b0;
            out_pc       <= 32'b0;
            out_inst     <= 32'h03400000;
        end else begin
            out_valid    <= 1'b0;

            if (in_valid && !pend_valid) begin
                pend_valid <= 1'b1;
                pend_pc    <= in_pc;
            end

            if (pend_valid && icache_resp_valid) begin
                out_valid  <= 1'b1;
                out_pc     <= pend_pc;
                out_inst <= icache_resp_data;
                pend_valid <= 1'b0;
            end
        end
    end

endmodule
