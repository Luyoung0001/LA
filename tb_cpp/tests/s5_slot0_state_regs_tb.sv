`timescale 1ns / 1ps

module s5_slot0_state_regs_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic        flush;
    logic        load;
    logic        epoch_we;
    logic [31:0] packet_pc;
    logic [31:0] packet_instr;
    logic [1:0]  packet_epoch;
    logic        packet_pred_taken;
    logic [31:0] packet_pred_target;
    logic        packet_fault;
    logic [5:0]  packet_fault_ecode;
    logic [31:0] packet_fault_badv;
    logic [6:0]  packet_opcode;
    logic [2:0]  packet_funct3;
    logic [6:0]  packet_funct7;
    logic [4:0]  packet_op_19_15;
    logic [4:0]  packet_rs1;
    logic [4:0]  packet_rs2;
    logic [4:0]  packet_rd;
    logic [31:0] packet_imm;
    logic        packet_is_branch;
    logic        packet_is_jal;
    logic        packet_is_jalr;
    logic        packet_is_load;
    logic        packet_is_store;
    logic        packet_is_lui;
    logic        packet_is_auipc;
    logic        packet_unknown_inst;
    logic [31:0] packet_rf1_base;
    logic [31:0] packet_rf2_base;
    logic        packet_rf_base_ready;

    logic        track_rf_base;
    logic [31:0] track_rf1_base;
    logic [31:0] track_rf2_base;

    logic [31:0] pc;
    logic [31:0] instr;
    logic [1:0]  epoch;
    logic        pred_taken;
    logic [31:0] pred_target;
    logic        fault;
    logic [5:0]  fault_ecode;
    logic [31:0] fault_badv;
    logic [6:0]  opcode;
    logic [2:0]  funct3;
    logic [6:0]  funct7;
    logic [4:0]  op_19_15;
    logic [4:0]  rs1;
    logic [4:0]  rs2;
    logic [4:0]  rd;
    logic [31:0] imm;
    logic        is_branch;
    logic        is_jal;
    logic        is_jalr;
    logic        is_load;
    logic        is_store;
    logic        is_lui;
    logic        is_auipc;
    logic        unknown_inst;
    logic [31:0] rf1_base;
    logic [31:0] rf2_base;
    logic        rf_base_ready;

    s5_slot0_state_regs #(
        .XLEN(32),
        .ILEN(32),
        .EPOCH_WIDTH(2)
    ) u_dut (
        .clk(clk),
        .rst_n(rst_n),
        .flush(flush),
        .load_i(load),
        .epoch_we_i(epoch_we),
        .pc_i(packet_pc),
        .instr_i(packet_instr),
        .epoch_i(packet_epoch),
        .pred_taken_i(packet_pred_taken),
        .pred_target_i(packet_pred_target),
        .fault_i(packet_fault),
        .fault_ecode_i(packet_fault_ecode),
        .fault_badv_i(packet_fault_badv),
        .opcode_i(packet_opcode),
        .funct3_i(packet_funct3),
        .funct7_i(packet_funct7),
        .op_19_15_i(packet_op_19_15),
        .rs1_i(packet_rs1),
        .rs2_i(packet_rs2),
        .rd_i(packet_rd),
        .imm_i(packet_imm),
        .is_branch_i(packet_is_branch),
        .is_jal_i(packet_is_jal),
        .is_jalr_i(packet_is_jalr),
        .is_load_i(packet_is_load),
        .is_store_i(packet_is_store),
        .is_lui_i(packet_is_lui),
        .is_auipc_i(packet_is_auipc),
        .unknown_inst_i(packet_unknown_inst),
        .rf1_base_i(packet_rf1_base),
        .rf2_base_i(packet_rf2_base),
        .rf_base_ready_i(packet_rf_base_ready),
        .track_rf_base_i(track_rf_base),
        .track_rf1_base_i(track_rf1_base),
        .track_rf2_base_i(track_rf2_base),
        .pc_o(pc),
        .instr_o(instr),
        .epoch_o(epoch),
        .pred_taken_o(pred_taken),
        .pred_target_o(pred_target),
        .fault_o(fault),
        .fault_ecode_o(fault_ecode),
        .fault_badv_o(fault_badv),
        .opcode_o(opcode),
        .funct3_o(funct3),
        .funct7_o(funct7),
        .op_19_15_o(op_19_15),
        .rs1_o(rs1),
        .rs2_o(rs2),
        .rd_o(rd),
        .imm_o(imm),
        .is_branch_o(is_branch),
        .is_jal_o(is_jal),
        .is_jalr_o(is_jalr),
        .is_load_o(is_load),
        .is_store_o(is_store),
        .is_lui_o(is_lui),
        .is_auipc_o(is_auipc),
        .unknown_inst_o(unknown_inst),
        .rf1_base_o(rf1_base),
        .rf2_base_o(rf2_base),
        .rf_base_ready_o(rf_base_ready)
    );

    task automatic drive_idle;
        begin
            flush = 1'b0;
            load = 1'b0;
            epoch_we = 1'b0;
            track_rf_base = 1'b0;
        end
    endtask

    task automatic drive_packet;
        input [31:0] base;
        input [1:0]  packet_epoch_in;
        input        epoch_we_in;
        input        rf_ready_in;
        begin
            packet_pc = base;
            packet_instr = base ^ 32'h0a0a_0101;
            packet_epoch = packet_epoch_in;
            epoch_we = epoch_we_in;
            packet_pred_taken = base[0];
            packet_pred_target = base + 32'h44;
            packet_fault = base[1];
            packet_fault_ecode = base[7:2];
            packet_fault_badv = base + 32'h48;
            packet_opcode = base[6:0];
            packet_funct3 = base[10:8];
            packet_funct7 = base[18:12];
            packet_op_19_15 = base[23:19];
            packet_rs1 = base[4:0];
            packet_rs2 = base[9:5];
            packet_rd = base[14:10];
            packet_imm = base + 32'h100;
            packet_is_branch = base[0];
            packet_is_jal = base[1];
            packet_is_jalr = base[2];
            packet_is_load = base[3];
            packet_is_store = base[4];
            packet_is_lui = base[5];
            packet_is_auipc = base[6];
            packet_unknown_inst = base[7];
            packet_rf1_base = base + 32'h1000_0001;
            packet_rf2_base = base + 32'h2000_0002;
            packet_rf_base_ready = rf_ready_in;
        end
    endtask

    initial begin
        tb_start();
        drive_idle();
        drive_packet(32'h1c00_1104, 2'd1, 1'b1, 1'b1);
        track_rf1_base = 32'h0102_0304;
        track_rf2_base = 32'h0506_0708;
        reset_dut();

        `check("STATE reset clears rf ready", !rf_base_ready);
        `check32("STATE reset clears pc", pc, 32'd0);
        `check32("STATE reset clears instr", instr, 32'd0);
        `check32("STATE reset clears rf1", rf1_base, 32'd0);
        `check32("STATE reset clears rf2", rf2_base, 32'd0);

        drive_packet(32'h1c00_330c, 2'd3, 1'b1, 1'b0);
        load = 1'b1;
        tick();
        load = 1'b0;
        `check32("STATE load S4 pc", pc, 32'h1c00_330c);
        `check32("STATE load S4 instr", instr, 32'h1c00_330c ^ 32'h0a0a_0101);
        `check32("STATE load S4 epoch", {30'd0, epoch}, 32'd3);
        `check32("STATE load S4 regs", {17'd0, rs1, rs2, rd},
                 {17'd0, 5'd12, 5'd24, 5'd12});
        `check32("STATE load S4 imm", imm, 32'h1c00_340c);
        `check("STATE load S4 marks rf not ready", !rf_base_ready);
        `check32("STATE load S4 rf1", rf1_base, 32'h2c00_330d);
        `check32("STATE load S4 rf2", rf2_base, 32'h3c00_330e);

        track_rf_base = 1'b1;
        tick();
        track_rf_base = 1'b0;
        `check32("STATE track keeps pc", pc, 32'h1c00_330c);
        `check32("STATE track keeps epoch", {30'd0, epoch}, 32'd3);
        `check("STATE track marks rf ready", rf_base_ready);
        `check32("STATE track updates rf1", rf1_base, 32'h0102_0304);
        `check32("STATE track updates rf2", rf2_base, 32'h0506_0708);

        drive_packet(32'h1c00_1104, 2'd1, 1'b0, 1'b1);
        load = 1'b1;
        tick();
        load = 1'b0;
        `check32("STATE promote pc", pc, 32'h1c00_1104);
        `check32("STATE promote instr", instr, 32'h1c00_1104 ^ 32'h0a0a_0101);
        `check32("STATE promote keeps previous epoch", {30'd0, epoch}, 32'd3);
        `check32("STATE promote regs", {17'd0, rs1, rs2, rd},
                 {17'd0, 5'd4, 5'd8, 5'd4});
        `check("STATE promote marks rf ready", rf_base_ready);
        `check32("STATE promote rf1", rf1_base, 32'h2c00_1105);
        `check32("STATE promote rf2", rf2_base, 32'h3c00_1106);

        drive_packet(32'h1c00_2208, 2'd2, 1'b1, 1'b1);
        load = 1'b1;
        tick();
        load = 1'b0;
        `check32("STATE hold pc", pc, 32'h1c00_2208);
        `check32("STATE hold instr", instr, 32'h1c00_2208 ^ 32'h0a0a_0101);
        `check32("STATE hold updates epoch", {30'd0, epoch}, 32'd2);
        `check32("STATE hold regs", {17'd0, rs1, rs2, rd},
                 {17'd0, 5'd8, 5'd16, 5'd8});
        `check("STATE hold marks rf ready", rf_base_ready);
        `check32("STATE hold rf1", rf1_base, 32'h2c00_2209);
        `check32("STATE hold rf2", rf2_base, 32'h3c00_220a);

        drive_packet(32'h1c00_4400, 2'd1, 1'b0, 1'b1);
        load = 1'b1;
        tick();
        drive_idle();
        `check32("STATE generic load updates pc", pc, 32'h1c00_4400);
        `check32("STATE generic load keeps epoch when epoch_we=0",
                 {30'd0, epoch}, 32'd2);

        drive_packet(32'h1c00_5500, 2'd1, 1'b1, 1'b0);
        load = 1'b1;
        tick();
        load = 1'b0;
        flush = 1'b1;
        tick();
        drive_idle();
        `check("STATE flush clears rf ready", !rf_base_ready);
        `check32("STATE flush clears pc", pc, 32'd0);
        `check32("STATE flush clears epoch", {30'd0, epoch}, 32'd0);
        `check32("STATE flush clears rf1", rf1_base, 32'd0);
        `check32("STATE flush clears rf2", rf2_base, 32'd0);

        finish_tb();
    end

endmodule
