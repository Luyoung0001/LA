module branch_predictor_d1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        req_valid,
    input  wire [31:0] req_pc,
    output reg         resp_valid,
    output reg         pred_taken,
    output reg  [31:0] pred_target,
    input  wire        update_valid,
    input  wire        update_taken,
    input  wire [31:0] update_pc,
    input  wire [31:0] update_target
);

    reg        q_valid;
    reg [31:0] q_pc;

    reg        btb_valid;
    reg [31:0] btb_pc;
    reg [31:0] btb_target;

    wire hit;
    assign hit = btb_valid && (q_pc == btb_pc);

    always @(posedge clk) begin
        if (reset) begin
            q_valid     <= 1'b0;
            q_pc        <= 32'b0;
            resp_valid  <= 1'b0;
            pred_taken  <= 1'b0;
            pred_target <= 32'b0;
            btb_valid   <= 1'b0;
            btb_pc      <= 32'b0;
            btb_target  <= 32'b0;
        end else begin
            q_valid     <= req_valid;
            q_pc        <= req_pc;

            resp_valid  <= q_valid;
            pred_taken  <= hit;
            pred_target <= hit ? btb_target : (q_pc + 32'd4);

            if (update_valid) begin
                btb_valid  <= update_taken;
                btb_pc     <= update_pc;
                btb_target <= update_target;
            end
        end
    end

endmodule
