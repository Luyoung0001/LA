module s1_f1 #(
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
    output reg  [31:0] out_pc,
    output reg         out_pred_taken,
    output reg  [31:0] out_pred_target
);

    reg [31:0] pc_r;
    reg [1:0]  redirect_suppress_r;

    wire bp_use_valid = bp_resp_valid && bp_pred_taken && (redirect_suppress_r == 2'b0);

    always @(posedge clk) begin
        if (reset) begin
            pc_r         <= RESET_PC;
            bp_req_valid <= 1'b0;
            bp_req_pc    <= RESET_PC;
            out_valid    <= 1'b0;
            out_pc       <= RESET_PC;
            out_pred_taken  <= 1'b0;
            out_pred_target <= RESET_PC + 32'd4;
            redirect_suppress_r <= 2'b0;
        end else begin
            bp_req_valid <= 1'b1;
            bp_req_pc    <= pc_r;
            out_valid    <= 1'b1;
            out_pc       <= pc_r;
            out_pred_taken  <= bp_use_valid;
            out_pred_target <= bp_use_valid ?
                               bp_pred_target : (pc_r + 32'd4);

            if (redirect_valid) begin
                pc_r <= redirect_pc;
                redirect_suppress_r <= 2'd2;
            end else if (hold) begin
                pc_r <= pc_r;
            end else if (bp_use_valid) begin
                pc_r <= bp_pred_target;
            end else begin
                pc_r <= pc_r + 32'd4;
            end

            if (redirect_suppress_r != 2'b0 && !redirect_valid)
                redirect_suppress_r <= redirect_suppress_r - 2'd1;
        end
    end

endmodule
