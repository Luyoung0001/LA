module stage1_if1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    output reg         icache_req_valid,
    output reg  [31:0] icache_req_addr,
    output reg         out_valid,
    output reg  [31:0] out_pc
);

    always @(posedge clk) begin
        if (reset) begin
            icache_req_valid <= 1'b0;
            icache_req_addr  <= 32'b0;
            out_valid        <= 1'b0;
            out_pc           <= 32'b0;
        end else begin
            icache_req_valid <= in_valid;
            icache_req_addr  <= in_pc;
            out_valid        <= in_valid;
            out_pc           <= in_pc;
        end
    end

endmodule
