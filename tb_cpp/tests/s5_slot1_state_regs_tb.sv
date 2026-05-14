`timescale 1ns / 1ps

module s5_slot1_state_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        flush;
    logic        clear;
    logic        load;
    logic [31:0] packet_slot1_pc;
    logic [31:0] packet_instr1;
    logic        packet_slot1_valid;
    logic [6:0]  packet_slot1_opcode;
    logic [2:0]  packet_slot1_funct3;
    logic [6:0]  packet_slot1_funct7;
    logic [4:0]  packet_slot1_op_19_15;
    logic [4:0]  packet_slot1_rs1;
    logic [4:0]  packet_slot1_rs2;
    logic [4:0]  packet_slot1_rd;
    logic [31:0] packet_slot1_imm;
    logic        packet_slot1_is_branch;
    logic        packet_slot1_is_jal;
    logic        packet_slot1_is_jalr;
    logic        packet_slot1_is_load;
    logic        packet_slot1_is_store;
    logic        packet_slot1_is_lui;
    logic        packet_slot1_is_auipc;
    logic        packet_slot1_unknown_inst;
    logic [31:0] packet_slot1_rf1_base;
    logic [31:0] packet_slot1_rf2_base;

    logic        track_rf_base;
    logic [31:0] track_slot1_rf1_base;
    logic [31:0] track_slot1_rf2_base;

    logic [31:0] slot1_pc;
    logic [31:0] instr1;
    logic        slot1_valid;
    logic [6:0]  slot1_opcode;
    logic [2:0]  slot1_funct3;
    logic [6:0]  slot1_funct7;
    logic [4:0]  slot1_op_19_15;
    logic [4:0]  slot1_rs1;
    logic [4:0]  slot1_rs2;
    logic [4:0]  slot1_rd;
    logic [31:0] slot1_imm;
    logic        slot1_is_branch;
    logic        slot1_is_jal;
    logic        slot1_is_jalr;
    logic        slot1_is_load;
    logic        slot1_is_store;
    logic        slot1_is_lui;
    logic        slot1_is_auipc;
    logic        slot1_unknown_inst;
    logic [31:0] slot1_rf1_base;
    logic [31:0] slot1_rf2_base;

    s5_slot1_state_regs #(
        .XLEN(32),
        .ILEN(32)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .clear_i(clear),
        .load_i(load),
        .slot1_pc_i(packet_slot1_pc),
        .instr1_i(packet_instr1),
        .slot1_valid_i(packet_slot1_valid),
        .slot1_opcode_i(packet_slot1_opcode),
        .slot1_funct3_i(packet_slot1_funct3),
        .slot1_funct7_i(packet_slot1_funct7),
        .slot1_op_19_15_i(packet_slot1_op_19_15),
        .slot1_rs1_i(packet_slot1_rs1),
        .slot1_rs2_i(packet_slot1_rs2),
        .slot1_rd_i(packet_slot1_rd),
        .slot1_imm_i(packet_slot1_imm),
        .slot1_is_branch_i(packet_slot1_is_branch),
        .slot1_is_jal_i(packet_slot1_is_jal),
        .slot1_is_jalr_i(packet_slot1_is_jalr),
        .slot1_is_load_i(packet_slot1_is_load),
        .slot1_is_store_i(packet_slot1_is_store),
        .slot1_is_lui_i(packet_slot1_is_lui),
        .slot1_is_auipc_i(packet_slot1_is_auipc),
        .slot1_unknown_inst_i(packet_slot1_unknown_inst),
        .slot1_rf1_base_i(packet_slot1_rf1_base),
        .slot1_rf2_base_i(packet_slot1_rf2_base),
        .track_rf_base_i(track_rf_base),
        .track_slot1_rf1_base_i(track_slot1_rf1_base),
        .track_slot1_rf2_base_i(track_slot1_rf2_base),
        .slot1_pc_o(slot1_pc),
        .instr1_o(instr1),
        .slot1_valid_o(slot1_valid),
        .slot1_opcode_o(slot1_opcode),
        .slot1_funct3_o(slot1_funct3),
        .slot1_funct7_o(slot1_funct7),
        .slot1_op_19_15_o(slot1_op_19_15),
        .slot1_rs1_o(slot1_rs1),
        .slot1_rs2_o(slot1_rs2),
        .slot1_rd_o(slot1_rd),
        .slot1_imm_o(slot1_imm),
        .slot1_is_branch_o(slot1_is_branch),
        .slot1_is_jal_o(slot1_is_jal),
        .slot1_is_jalr_o(slot1_is_jalr),
        .slot1_is_load_o(slot1_is_load),
        .slot1_is_store_o(slot1_is_store),
        .slot1_is_lui_o(slot1_is_lui),
        .slot1_is_auipc_o(slot1_is_auipc),
        .slot1_unknown_inst_o(slot1_unknown_inst),
        .slot1_rf1_base_o(slot1_rf1_base),
        .slot1_rf2_base_o(slot1_rf2_base)
    );

    task automatic drive_idle;
        begin
            flush = 1'b0;
            clear = 1'b0;
            load = 1'b0;
            track_rf_base = 1'b0;
        end
    endtask

    task automatic drive_packet;
        input [31:0] base;
        begin
            packet_slot1_pc = base;
            packet_instr1 = base ^ 32'h0110_7001;
            packet_slot1_valid = 1'b1;
            packet_slot1_opcode = base[6:0];
            packet_slot1_funct3 = base[10:8];
            packet_slot1_funct7 = base[18:12];
            packet_slot1_op_19_15 = base[23:19];
            packet_slot1_rs1 = base[4:0];
            packet_slot1_rs2 = base[9:5];
            packet_slot1_rd = base[14:10];
            packet_slot1_imm = base + 32'h100;
            packet_slot1_is_branch = base[0];
            packet_slot1_is_jal = base[1];
            packet_slot1_is_jalr = base[2];
            packet_slot1_is_load = base[3];
            packet_slot1_is_store = base[4];
            packet_slot1_is_lui = base[5];
            packet_slot1_is_auipc = base[6];
            packet_slot1_unknown_inst = base[7];
            packet_slot1_rf1_base = base + 32'h1000_0001;
            packet_slot1_rf2_base = base + 32'h2000_0002;
        end
    endtask

    task automatic check_cleared;
        input string name;
        begin
            `check32({name, " pc"}, slot1_pc, 32'd0);
            `check32({name, " instr"}, instr1, 32'd0);
            `check({name, " valid flags"}, !slot1_valid &&
                                             !slot1_is_branch &&
                                             !slot1_is_load &&
                                             !slot1_unknown_inst);
            `check32({name, " regs"}, {17'd0, slot1_rs1, slot1_rs2, slot1_rd}, 32'd0);
            `check32({name, " rf1"}, slot1_rf1_base, 32'd0);
            `check32({name, " rf2"}, slot1_rf2_base, 32'd0);
        end
    endtask

    initial begin
        tb_start();
        drive_idle();
        drive_packet(32'h1c00_1104);
        track_slot1_rf1_base = 32'h5555_aaaa;
        track_slot1_rf2_base = 32'haaaa_5555;
        reset_dut();

        check_cleared("STATE reset clears");

        drive_packet(32'h1c00_2208);
        load = 1'b1;
        tick();
        load = 1'b0;
        `check32("STATE load S4 pc", slot1_pc, 32'h1c00_2208);
        `check32("STATE load S4 instr", instr1, 32'h1c00_2208 ^ 32'h0110_7001);
        `check32("STATE load S4 regs", {17'd0, slot1_rs1, slot1_rs2, slot1_rd},
                 {17'd0, 5'd8, 5'd16, 5'd8});
        `check32("STATE load S4 imm", slot1_imm, 32'h1c00_2308);
        `check32("STATE load S4 rf1", slot1_rf1_base, 32'h2c00_2209);
        `check32("STATE load S4 rf2", slot1_rf2_base, 32'h3c00_220a);

        drive_packet(32'h1c00_330c);
        track_slot1_rf1_base = 32'h0102_0304;
        track_slot1_rf2_base = 32'h0506_0708;
        track_rf_base = 1'b1;
        tick();
        track_rf_base = 1'b0;
        `check32("STATE track keeps payload pc", slot1_pc, 32'h1c00_2208);
        `check32("STATE track updates rf1", slot1_rf1_base, 32'h0102_0304);
        `check32("STATE track updates rf2", slot1_rf2_base, 32'h0506_0708);

        drive_packet(32'h1c00_1104);
        load = 1'b1;
        tick();
        load = 1'b0;
        `check32("STATE load hold pc", slot1_pc, 32'h1c00_1104);
        `check32("STATE load hold instr", instr1, 32'h1c00_1104 ^ 32'h0110_7001);
        `check32("STATE load hold regs", {17'd0, slot1_rs1, slot1_rs2, slot1_rd},
                 {17'd0, 5'd4, 5'd8, 5'd4});
        `check32("STATE load hold rf1", slot1_rf1_base, 32'h2c00_1105);
        `check32("STATE load hold rf2", slot1_rf2_base, 32'h3c00_1106);

        drive_packet(32'h1c00_4400);
        clear = 1'b1;
        load = 1'b1;
        track_rf_base = 1'b1;
        tick();
        drive_idle();
        check_cleared("STATE clear wins");

        drive_packet(32'h1c00_5500);
        load = 1'b1;
        tick();
        load = 1'b0;
        flush = 1'b1;
        load = 1'b1;
        tick();
        drive_idle();
        check_cleared("STATE flush wins");

        finish_tb();
    end

endmodule
