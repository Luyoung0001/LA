module stage4_rrd (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    input  wire [4:0]  in_rd,
    input  wire [31:0] in_imm,
    input  wire        in_use_imm,
    input  wire        in_is_branch,
    input  wire        in_is_load,
    input  wire        in_is_store,
    input  wire        in_is_muldiv,
    input  wire        rf_rvalid,
    input  wire [31:0] rf_rdata1,
    input  wire [31:0] rf_rdata2,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_op1,
    output reg  [31:0] out_op2,
    output reg  [31:0] out_imm,
    output reg         out_use_imm,
    output reg         out_is_branch,
    output reg         out_is_load,
    output reg         out_is_store,
    output reg         out_is_muldiv
);

    reg        meta_valid_d1;
    reg [31:0] meta_pc_d1;
    reg [31:0] meta_inst_d1;
    reg [4:0]  meta_rd_d1;
    reg [31:0] meta_imm_d1;
    reg        meta_use_imm_d1;
    reg        meta_is_branch_d1;
    reg        meta_is_load_d1;
    reg        meta_is_store_d1;
    reg        meta_is_muldiv_d1;

    always @(posedge clk) begin
        if (reset) begin
            meta_valid_d1      <= 1'b0;
            meta_pc_d1         <= 32'b0;
            meta_inst_d1       <= 32'b0;
            meta_rd_d1         <= 5'b0;
            meta_imm_d1        <= 32'b0;
            meta_use_imm_d1    <= 1'b0;
            meta_is_branch_d1  <= 1'b0;
            meta_is_load_d1    <= 1'b0;
            meta_is_store_d1   <= 1'b0;
            meta_is_muldiv_d1  <= 1'b0;

            out_valid          <= 1'b0;
            out_pc             <= 32'b0;
            out_inst           <= 32'b0;
            out_rd             <= 5'b0;
            out_op1            <= 32'b0;
            out_op2            <= 32'b0;
            out_imm            <= 32'b0;
            out_use_imm        <= 1'b0;
            out_is_branch      <= 1'b0;
            out_is_load        <= 1'b0;
            out_is_store       <= 1'b0;
            out_is_muldiv      <= 1'b0;
        end else begin
            meta_valid_d1      <= in_valid;
            meta_pc_d1         <= in_pc;
            meta_inst_d1       <= in_inst;
            meta_rd_d1         <= in_rd;
            meta_imm_d1        <= in_imm;
            meta_use_imm_d1    <= in_use_imm;
            meta_is_branch_d1  <= in_is_branch;
            meta_is_load_d1    <= in_is_load;
            meta_is_store_d1   <= in_is_store;
            meta_is_muldiv_d1  <= in_is_muldiv;

            out_valid          <= meta_valid_d1 && rf_rvalid;
            if (meta_valid_d1 && rf_rvalid) begin
                out_pc         <= meta_pc_d1;
                out_inst       <= meta_inst_d1;
                out_rd         <= meta_rd_d1;
                out_op1        <= rf_rdata1;
                out_op2        <= rf_rdata2;
                out_imm        <= meta_imm_d1;
                out_use_imm    <= meta_use_imm_d1;
                out_is_branch  <= meta_is_branch_d1;
                out_is_load    <= meta_is_load_d1;
                out_is_store   <= meta_is_store_d1;
                out_is_muldiv  <= meta_is_muldiv_d1;
            end
        end
    end

endmodule
