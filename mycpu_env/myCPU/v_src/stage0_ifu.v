module stage0_ifu #(
    parameter RESET_PC = 32'h1c000000
) (
    input  wire        clk,
    input  wire        reset,
    input  wire        hold,
    input  wire        redirect_valid,
    input  wire [31:0] redirect_pc,
    input  wire        bp_resp_valid,
    input  wire        bp_pred_taken,
    input  wire [31:0] bp_pred_target,
    output reg         bp_req_valid,
    output reg  [31:0] bp_req_pc,
    output reg         out_valid,
    output reg  [31:0] out_pc
);

    reg [31:0] pc_r;

    always @(posedge clk) begin
        if (reset) begin
            pc_r         <= RESET_PC;
            bp_req_valid <= 1'b0;
            bp_req_pc    <= RESET_PC;
            out_valid    <= 1'b0;
            out_pc       <= RESET_PC;
        end else begin
            bp_req_valid <= 1'b1;
            bp_req_pc    <= pc_r;
            out_valid    <= 1'b1;
            out_pc       <= pc_r;

            if (redirect_valid) begin
                pc_r <= redirect_pc;
            end else if (hold) begin
                pc_r <= pc_r;
            end else if (bp_resp_valid && bp_pred_taken) begin
                pc_r <= bp_pred_target;
            end else begin
                pc_r <= pc_r + 32'd4;
            end
        end
    end

endmodule
