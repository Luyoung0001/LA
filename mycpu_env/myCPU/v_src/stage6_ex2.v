module stage6_ex2 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_alu_result,
    input  wire [31:0] in_op1,
    input  wire [31:0] in_op2,
    input  wire [31:0] in_imm,
    input  wire        in_is_branch,
    input  wire        in_is_load,
    input  wire        in_is_store,
    input  wire        in_is_muldiv,
    output reg         muldiv_req_valid,
    output reg         muldiv_req_is_div,
    output reg         muldiv_req_signed,
    output reg  [31:0] muldiv_req_op1,
    output reg  [31:0] muldiv_req_op2,
    input  wire        muldiv_resp_valid,
    input  wire [31:0] muldiv_resp_result,
    output reg         branch_update_valid,
    output reg         branch_taken,
    output reg  [31:0] branch_target,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_result,
    output reg         out_is_load,
    output reg         out_is_store,
    output reg  [31:0] out_store_data
);

    wire [5:0] op_31_26;
    wire inst_jirl;
    wire inst_b;
    wire inst_bl;
    wire inst_beq;
    wire inst_bne;
    wire branch_take_w;
    wire [31:0] branch_target_w;

    assign op_31_26 = in_inst[31:26];
    assign inst_jirl = (op_31_26 == 6'h13);
    assign inst_b    = (op_31_26 == 6'h14);
    assign inst_bl   = (op_31_26 == 6'h15);
    assign inst_beq  = (op_31_26 == 6'h16);
    assign inst_bne  = (op_31_26 == 6'h17);

    assign branch_take_w = inst_b | inst_bl | inst_jirl |
                           (inst_beq && (in_op1 == in_op2)) |
                           (inst_bne && (in_op1 != in_op2));
    assign branch_target_w = inst_jirl ? (in_op1 + in_imm) : (in_pc + in_imm);

    always @(posedge clk) begin
        if (reset) begin
            muldiv_req_valid   <= 1'b0;
            muldiv_req_is_div  <= 1'b0;
            muldiv_req_signed  <= 1'b0;
            muldiv_req_op1     <= 32'b0;
            muldiv_req_op2     <= 32'b0;

            branch_update_valid <= 1'b0;
            branch_taken        <= 1'b0;
            branch_target       <= 32'b0;

            out_valid          <= 1'b0;
            out_pc             <= 32'b0;
            out_inst           <= 32'b0;
            out_rd             <= 5'b0;
            out_result         <= 32'b0;
            out_is_load        <= 1'b0;
            out_is_store       <= 1'b0;
            out_store_data     <= 32'b0;
        end else begin
            muldiv_req_valid   <= in_valid && in_is_muldiv;
            muldiv_req_is_div  <= in_inst[25];
            muldiv_req_signed  <= in_inst[24];
            muldiv_req_op1     <= in_op1;
            muldiv_req_op2     <= in_op2;

            branch_update_valid <= in_valid && in_is_branch;
            branch_taken        <= in_valid && branch_take_w;
            branch_target       <= branch_target_w;

            out_valid          <= in_valid;
            out_pc             <= in_pc;
            out_inst           <= in_inst;
            out_rd             <= in_rd;
            out_result         <= in_is_muldiv ? 32'b0 : in_alu_result;
            out_is_load        <= in_is_load;
            out_is_store       <= in_is_store;
            out_store_data     <= in_op2;

            if (muldiv_resp_valid) begin
                out_result <= muldiv_resp_result;
            end
        end
    end

endmodule
