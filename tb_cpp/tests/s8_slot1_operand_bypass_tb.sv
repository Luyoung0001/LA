`timescale 1ns / 1ps
`include "cpu_defs.vh"

module s8_slot1_operand_bypass_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        slot0_wb_en;
    logic        slot0_is_load;
    logic        slot0_is_store;
    logic        slot0_is_branch;
    logic        slot0_is_jal;
    logic        slot0_is_jalr;
    logic [4:0]  slot0_rd;
    logic [31:0] slot0_result;

    logic        slot1_valid;
    logic        slot1_issue_valid;
    logic        slot1_ctrl_flow;
    logic        slot1_is_store;
    logic        slot1_uses_rs1;
    logic        slot1_uses_rs2;
    logic [1:0]  slot1_src_a_sel;
    logic [1:0]  slot1_src_b_sel;
    logic [4:0]  slot1_rs1;
    logic [4:0]  slot1_rs2;
    logic [31:0] slot1_op_a;
    logic [31:0] slot1_op_b;
    logic [31:0] slot1_rs1_val;
    logic [31:0] slot1_rs2_val;

    logic        slot0_result_bypass;
    logic        op_a_from_slot0;
    logic        op_b_from_slot0;
    logic        branch_rs1_from_slot0;
    logic        branch_rs2_from_slot0;
    logic        store_data_from_slot0;
    logic [31:0] op_a;
    logic [31:0] op_b;
    logic [31:0] branch_rs1;
    logic [31:0] branch_rs2;
    logic [31:0] store_data;

    s8_slot1_operand_bypass u_dut (
        .slot0_wb_en_i(slot0_wb_en),
        .slot0_is_load_i(slot0_is_load),
        .slot0_is_store_i(slot0_is_store),
        .slot0_is_branch_i(slot0_is_branch),
        .slot0_is_jal_i(slot0_is_jal),
        .slot0_is_jalr_i(slot0_is_jalr),
        .slot0_rd_i(slot0_rd),
        .slot0_result_i(slot0_result),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_ctrl_flow_i(slot1_ctrl_flow),
        .slot1_is_store_i(slot1_is_store),
        .slot1_uses_rs1_i(slot1_uses_rs1),
        .slot1_uses_rs2_i(slot1_uses_rs2),
        .slot1_src_a_sel_i(slot1_src_a_sel),
        .slot1_src_b_sel_i(slot1_src_b_sel),
        .slot1_rs1_i(slot1_rs1),
        .slot1_rs2_i(slot1_rs2),
        .slot1_op_a_i(slot1_op_a),
        .slot1_op_b_i(slot1_op_b),
        .slot1_rs1_val_i(slot1_rs1_val),
        .slot1_rs2_val_i(slot1_rs2_val),
        .slot0_result_bypass_o(slot0_result_bypass),
        .op_a_from_slot0_o(op_a_from_slot0),
        .op_b_from_slot0_o(op_b_from_slot0),
        .branch_rs1_from_slot0_o(branch_rs1_from_slot0),
        .branch_rs2_from_slot0_o(branch_rs2_from_slot0),
        .store_data_from_slot0_o(store_data_from_slot0),
        .op_a_o(op_a),
        .op_b_o(op_b),
        .branch_rs1_o(branch_rs1),
        .branch_rs2_o(branch_rs2),
        .store_data_o(store_data)
    );

    task automatic clear_inputs;
        begin
            slot0_wb_en = 1'b0;
            slot0_is_load = 1'b0;
            slot0_is_store = 1'b0;
            slot0_is_branch = 1'b0;
            slot0_is_jal = 1'b0;
            slot0_is_jalr = 1'b0;
            slot0_rd = 5'd0;
            slot0_result = 32'hcafe_beef;

            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_ctrl_flow = 1'b0;
            slot1_is_store = 1'b0;
            slot1_uses_rs1 = 1'b0;
            slot1_uses_rs2 = 1'b0;
            slot1_src_a_sel = `CPU_SRC_A_RS1;
            slot1_src_b_sel = `CPU_SRC_B_RS2;
            slot1_rs1 = 5'd0;
            slot1_rs2 = 5'd0;
            slot1_op_a = 32'h1111_1111;
            slot1_op_b = 32'h2222_2222;
            slot1_rs1_val = 32'h3333_3333;
            slot1_rs2_val = 32'h4444_4444;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S8 slot1 bypass idle keeps original operands",
               !slot0_result_bypass && !op_a_from_slot0 &&
               !op_b_from_slot0 && !branch_rs1_from_slot0 &&
               !branch_rs2_from_slot0 && !store_data_from_slot0);
        `check32("S8 slot1 bypass idle op_a", op_a, 32'h1111_1111);
        `check32("S8 slot1 bypass idle store data", store_data, 32'h4444_4444);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd8;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs1 = 5'd8;
        slot1_rs2 = 5'd8;
        #1;
        `check("S8 slot1 bypass forwards both ALU operands",
               slot0_result_bypass && op_a_from_slot0 && op_b_from_slot0);
        `check32("S8 slot1 bypass op_a from slot0", op_a, 32'hcafe_beef);
        `check32("S8 slot1 bypass op_b from slot0", op_b, 32'hcafe_beef);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_is_load = 1'b1;
        slot0_rd = 5'd8;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd8;
        #1;
        `check("S8 slot1 bypass blocks load-class slot0 producer",
               !slot0_result_bypass && !op_a_from_slot0);
        `check32("S8 slot1 bypass blocked op_a keeps original", op_a, 32'h1111_1111);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd9;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_ctrl_flow = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs1 = 5'd9;
        slot1_rs2 = 5'd9;
        #1;
        `check("S8 slot1 bypass forwards branch compare operands",
               branch_rs1_from_slot0 && branch_rs2_from_slot0);
        `check32("S8 slot1 bypass branch rs1", branch_rs1, 32'hcafe_beef);
        `check32("S8 slot1 bypass branch rs2", branch_rs2, 32'hcafe_beef);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd9;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        slot1_ctrl_flow = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_uses_rs2 = 1'b1;
        slot1_rs1 = 5'd9;
        slot1_rs2 = 5'd9;
        #1;
        `check("S8 slot1 bypass blocks unissued branch operands",
               !branch_rs1_from_slot0 && !branch_rs2_from_slot0);
        `check32("S8 slot1 unissued branch keeps rs1", branch_rs1, 32'h3333_3333);
        `check32("S8 slot1 unissued branch keeps rs2", branch_rs2, 32'h4444_4444);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd10;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_is_store = 1'b1;
        slot1_rs2 = 5'd10;
        #1;
        `check("S8 slot1 bypass forwards store data without uses_rs2 gate",
               store_data_from_slot0);
        `check32("S8 slot1 bypass store data", store_data, 32'hcafe_beef);

        clear_inputs();
        slot0_wb_en = 1'b1;
        slot0_rd = 5'd0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_uses_rs1 = 1'b1;
        slot1_rs1 = 5'd0;
        slot1_ctrl_flow = 1'b1;
        #1;
        `check("S8 slot1 bypass never forwards x0 producer",
               !slot0_result_bypass && !op_a_from_slot0 && !branch_rs1_from_slot0);

        finish_tb();
    end
endmodule
