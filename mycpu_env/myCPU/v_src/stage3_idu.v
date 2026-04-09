module stage3_idu (
    input  wire        clk,
    input  wire        reset,
    input  wire        in_valid,
    input  wire [31:0] in_pc,
    input  wire [31:0] in_inst,
    output reg         rf_req_valid,
    output reg  [4:0]  rf_raddr1,
    output reg  [4:0]  rf_raddr2,
    output reg         out_valid,
    output reg  [31:0] out_pc,
    output reg  [31:0] out_inst,
    output reg  [4:0]  out_rd,
    output reg  [31:0] out_imm,
    output reg         out_use_imm,
    output reg         out_is_branch,
    output reg         out_is_load,
    output reg         out_is_store,
    output reg         out_is_muldiv
);

    wire [5:0]  op_31_26;
    wire [3:0]  op_25_22;
    wire [1:0]  op_21_20;
    wire [4:0]  op_19_15;
    wire [4:0]  rj;
    wire [4:0]  rk;
    wire [4:0]  rd;

    wire [11:0] i12;
    wire [15:0] i16;
    wire [19:0] i20;
    wire [25:0] i26;

    wire [31:0] imm12_sext;
    wire [31:0] imm20_lsh12;
    wire [31:0] br_offs16;
    wire [31:0] br_offs26;
    wire [31:0] shamt_imm;

    wire        inst_add_w;
    wire        inst_sub_w;
    wire        inst_slt;
    wire        inst_sltu;
    wire        inst_and;
    wire        inst_or;
    wire        inst_xor;
    wire        inst_nor;
    wire        inst_slli_w;
    wire        inst_srli_w;
    wire        inst_srai_w;
    wire        inst_addi_w;
    wire        inst_ld_w;
    wire        inst_st_w;
    wire        inst_jirl;
    wire        inst_b;
    wire        inst_bl;
    wire        inst_beq;
    wire        inst_bne;
    wire        inst_lu12i_w;

    wire [4:0]  rf_raddr1_w;
    wire [4:0]  rf_raddr2_w;
    wire [4:0]  out_rd_w;
    wire [31:0] out_imm_w;
    wire        out_use_imm_w;
    wire        out_is_branch_w;
    wire        out_is_load_w;
    wire        out_is_store_w;
    wire        out_is_muldiv_w;

    assign op_31_26 = in_inst[31:26];
    assign op_25_22 = in_inst[25:22];
    assign op_21_20 = in_inst[21:20];
    assign op_19_15 = in_inst[19:15];
    assign rj       = in_inst[9:5];
    assign rk       = in_inst[14:10];
    assign rd       = in_inst[4:0];

    assign i12      = in_inst[21:10];
    assign i16      = in_inst[25:10];
    assign i20      = in_inst[24:5];
    assign i26      = {in_inst[9:0], in_inst[25:10]};

    assign imm12_sext = {{20{in_inst[21]}}, in_inst[21:10]};
    assign imm20_lsh12 = {i20, 12'b0};
    assign br_offs16   = {{14{i16[15]}}, i16, 2'b0};
    assign br_offs26   = {{4{i26[25]}}, i26, 2'b0};
    assign shamt_imm   = {27'b0, rk};

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
    assign inst_b       = (op_31_26 == 6'h14);
    assign inst_bl      = (op_31_26 == 6'h15);
    assign inst_beq     = (op_31_26 == 6'h16);
    assign inst_bne     = (op_31_26 == 6'h17);
    assign inst_lu12i_w = (op_31_26 == 6'h05) && (~in_inst[25]);

    assign out_is_branch_w = inst_jirl | inst_b | inst_bl | inst_beq | inst_bne;
    assign out_is_load_w   = inst_ld_w;
    assign out_is_store_w  = inst_st_w;
    assign out_is_muldiv_w = 1'b0;

    assign rf_raddr1_w = (inst_b | inst_bl | inst_lu12i_w) ? 5'b0 : rj;
    assign rf_raddr2_w = (inst_add_w | inst_sub_w | inst_slt | inst_sltu | inst_and | inst_or | inst_xor | inst_nor) ? rk :
                         (inst_beq | inst_bne | inst_st_w) ? rd : 5'b0;

    assign out_rd_w = inst_bl ? 5'd1 : rd;

    assign out_imm_w = inst_lu12i_w ? imm20_lsh12 :
                       (inst_addi_w | inst_ld_w | inst_st_w) ? imm12_sext :
                       (inst_slli_w | inst_srli_w | inst_srai_w) ? shamt_imm :
                       (inst_beq | inst_bne | inst_jirl) ? br_offs16 :
                       (inst_b | inst_bl) ? br_offs26 :
                       32'b0;

    assign out_use_imm_w = inst_addi_w | inst_ld_w | inst_st_w |
                           inst_slli_w | inst_srli_w | inst_srai_w;

    always @(posedge clk) begin
        if (reset) begin
            rf_req_valid   <= 1'b0;
            rf_raddr1      <= 5'b0;
            rf_raddr2      <= 5'b0;
            out_valid      <= 1'b0;
            out_pc         <= 32'b0;
            out_inst       <= 32'b0;
            out_rd         <= 5'b0;
            out_imm        <= 32'b0;
            out_use_imm    <= 1'b0;
            out_is_branch  <= 1'b0;
            out_is_load    <= 1'b0;
            out_is_store   <= 1'b0;
            out_is_muldiv  <= 1'b0;
        end else begin
            rf_req_valid   <= in_valid;
            rf_raddr1      <= rf_raddr1_w;
            rf_raddr2      <= rf_raddr2_w;

            out_valid      <= in_valid;
            out_pc         <= in_pc;
            out_inst       <= in_inst;
            out_rd         <= out_rd_w;
            out_imm        <= out_imm_w;
            out_use_imm    <= out_use_imm_w;
            out_is_branch  <= out_is_branch_w;
            out_is_load    <= out_is_load_w;
            out_is_store   <= out_is_store_w;
            out_is_muldiv  <= out_is_muldiv_w;
        end
    end

endmodule
