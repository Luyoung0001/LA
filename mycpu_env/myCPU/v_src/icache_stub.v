module icache_stub (
    input  wire        clk,
    input  wire        reset,
    input  wire        req_valid,
    input  wire [31:0] req_addr,
    output wire        req_ready,
    output reg         resp_valid,
    output reg  [31:0] resp_data
);

    reg        pend_valid;
    reg [31:0] pend_addr;

    assign req_ready = 1'b1;

    always @(posedge clk) begin
        if (reset) begin
            pend_valid <= 1'b0;
            pend_addr  <= 32'b0;
            resp_valid <= 1'b0;
            resp_data  <= 32'h03400000;
        end else begin
            pend_valid <= req_valid;
            pend_addr  <= req_addr;
            resp_valid <= pend_valid;

            case (pend_addr[5:2])
                4'h0: resp_data <= 32'h03400000;
                4'h1: resp_data <= 32'h00100021;
                4'h2: resp_data <= 32'h00110021;
                4'h3: resp_data <= 32'h00120021;
                default: resp_data <= 32'h03400000;
            endcase
        end
    end

endmodule
