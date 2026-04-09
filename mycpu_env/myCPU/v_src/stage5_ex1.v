module stage5_ex1 (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_op1,
    input  wire [31:0] in_op2,
    input  wire [31:0] in_imm,
    input  wire        in_use_imm,
    input  wire        in_is_branch,
    input  wire        in_is_load,
    input  wire        in_is_store,
    input  wire        in_is_muldiv,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_alu_result,
    output reg  [31:0] out_op1,
    output reg  [31:0] out_op2,
    output reg  [31:0] out_imm,
    output reg         out_is_branch,
    output reg         out_is_load,
    output reg         out_is_store,
    output reg         out_is_muldiv
);

    wire [5:0] op_31_26;
    wire [3:0] op_25_22;
    wire [1:0] op_21_20;
    wire [4:0] op_19_15;
    wire [4:0] rk;

    wire inst_add_w;
    wire inst_sub_w;
    wire inst_slt;
    wire inst_sltu;
    wire inst_and;
    wire inst_or;
    wire inst_xor;
    wire inst_nor;
    wire inst_slli_w;
    wire inst_srli_w;
    wire inst_srai_w;
    wire inst_addi_w;
    wire inst_ld_w;
    wire inst_st_w;
    wire inst_jirl;
    wire inst_bl;
    wire inst_lu12i_w;

    reg [31:0] ex_result;

    assign op_31_26 = in_inst[31:26];
    assign op_25_22 = in_inst[25:22];
    assign op_21_20 = in_inst[21:20];
    assign op_19_15 = in_inst[19:15];
    assign rk       = in_inst[14:10];

    assign inst_add_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h00);
    assign inst_sub_w   = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h02);
    assign inst_slt     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h04);
    assign inst_sltu    = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h05);
    assign inst_and     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h09);
    assign inst_or      = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0a);
    assign inst_xor     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h0b);
    assign inst_nor     = (op_31_26 == 6'h00) && (op_25_22 == 4'h0) && (op_21_20 == 2'h1) && (op_19_15 == 5'h08);
    assign inst_slli_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h01);
    assign inst_srli_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h09);
    assign inst_srai_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'h1) && (op_21_20 == 2'h0) && (op_19_15 == 5'h11);
    assign inst_addi_w  = (op_31_26 == 6'h00) && (op_25_22 == 4'ha);
    assign inst_ld_w    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h2);
    assign inst_st_w    = (op_31_26 == 6'h0a) && (op_25_22 == 4'h6);
    assign inst_jirl    = (op_31_26 == 6'h13);
    assign inst_bl      = (op_31_26 == 6'h15);
    assign inst_lu12i_w = (op_31_26 == 6'h05) && (~in_inst[25]);

    always @(*) begin
        ex_result = 32'b0;

        if (inst_lu12i_w) begin
            ex_result = in_imm;
        end else if (inst_add_w) begin
            ex_result = in_op1 + in_op2;
        end else if (inst_addi_w || inst_ld_w || inst_st_w) begin
            ex_result = in_op1 + in_imm;
        end else if (inst_sub_w) begin
            ex_result = in_op1 - in_op2;
        end else if (inst_slt) begin
            ex_result = ($signed(in_op1) < $signed(in_op2)) ? 32'd1 : 32'd0;
        end else if (inst_sltu) begin
            ex_result = (in_op1 < in_op2) ? 32'd1 : 32'd0;
        end else if (inst_and) begin
            ex_result = in_op1 & in_op2;
        end else if (inst_or) begin
            ex_result = in_op1 | in_op2;
        end else if (inst_xor) begin
            ex_result = in_op1 ^ in_op2;
        end else if (inst_nor) begin
            ex_result = ~(in_op1 | in_op2);
        end else if (inst_slli_w) begin
            ex_result = in_op1 << rk[4:0];
        end else if (inst_srli_w) begin
            ex_result = in_op1 >> rk[4:0];
        end else if (inst_srai_w) begin
            ex_result = $signed(in_op1) >>> rk[4:0];
        end else if (inst_bl || inst_jirl) begin
            ex_result = in_pc + 32'd4;
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            out_valid      <= 1'b0;
            out_pc         <= 32'b0;
            out_inst       <= 32'b0;
            out_rd         <= 5'b0;
            out_alu_result <= 32'b0;
            out_op1        <= 32'b0;
            out_op2        <= 32'b0;
            out_imm        <= 32'b0;
            out_is_branch  <= 1'b0;
            out_is_load    <= 1'b0;
            out_is_store   <= 1'b0;
            out_is_muldiv  <= 1'b0;
        end else begin
            out_valid      <= in_valid;
            out_pc         <= in_pc;
            out_inst       <= in_inst;
            out_rd         <= in_rd;
            out_alu_result <= ex_result;
            out_op1        <= in_op1;
            out_op2        <= in_op2;
            out_imm        <= in_imm;
            out_is_branch  <= in_is_branch;
            out_is_load    <= in_is_load;
            out_is_store   <= in_is_store;
            out_is_muldiv  <= in_is_muldiv;
        end
    end

endmodule
