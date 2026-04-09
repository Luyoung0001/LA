module muldiv_stub (
    input  wire        clk,
    input  wire        reset,
    input  wire        req_valid,
    input  wire        req_is_div,
    input  wire        req_signed,
    input  wire [31:0] req_op1,
    input  wire [31:0] req_op2,
    output reg         resp_valid,
    output reg  [31:0] resp_result
);

    reg pend_valid;

    always @(posedge clk) begin
        if (reset) begin
            pend_valid  <= 1'b0;
            resp_valid  <= 1'b0;
            resp_result <= 32'b0;
        end else begin
            pend_valid  <= req_valid;
            resp_valid  <= pend_valid;
            resp_result <= 32'b0;
        end
    end

endmodule
