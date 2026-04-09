module csr_stub (
    input  wire        clk,
    input  wire        reset,
    input  wire        req_valid,
    input  wire        req_write,
    input  wire [13:0] req_addr,
    input  wire [31:0] req_wdata,
    output reg         resp_valid,
    output reg  [31:0] resp_rdata
);

    always @(posedge clk) begin
        if (reset) begin
            resp_valid <= 1'b0;
            resp_rdata <= 32'b0;
        end else begin
            resp_valid <= req_valid;
            resp_rdata <= 32'b0;
        end
    end

endmodule
