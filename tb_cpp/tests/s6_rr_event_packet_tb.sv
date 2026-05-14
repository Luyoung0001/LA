`timescale 1ns / 1ps

module s6_rr_event_packet_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic       s6_ready_go;
    logic       s6_emit_valid;
    logic       s6_allowin;
    logic       load_use_hazard;
    logic       s7_lane0_load_pending;
    logic       s7_lane1_load_pending;
    logic       s8_lane0_load_pending;
    logic       s8_lane1_load_pending;
    logic       s9_lane0_load_pending;
    logic       s9_lane1_load_pending;
    logic       lane0_rs1_wait_s7;
    logic       lane0_rs2_wait_s7;
    logic       lane0_rs1_wait_s8;
    logic       lane0_rs2_wait_s8;
    logic       lane0_rs1_wait_s9;
    logic       lane0_rs2_wait_s9;
    logic       lane1_rs1_wait_s7;
    logic       lane1_rs2_wait_s7;
    logic       lane1_rs1_wait_s8;
    logic       lane1_rs2_wait_s8;
    logic       lane1_rs1_wait_s9;
    logic       lane1_rs2_wait_s9;
    logic       slot1_emit_valid;
    logic       slot1_fire;
    logic [3:0] slot1_emit_class;

    logic       s6_ready_go_o;
    logic       s6_emit_valid_o;
    logic       s6_allowin_o;
    logic       load_use_hazard_o;
    logic       slot1_emit_valid_o;
    logic       slot1_fire_o;
    logic [3:0] slot1_emit_class_o;
    logic [5:0] older_load_summary_o;
    logic [5:0] lane0_wait_summary_o;
    logic [5:0] lane1_wait_summary_o;
    logic [7:0] rr_event_reason_o;

    s6_rr_event_packet u_dut (
        .s6_ready_go_i(s6_ready_go),
        .s6_emit_valid_i(s6_emit_valid),
        .s6_allowin_i(s6_allowin),
        .load_use_hazard_i(load_use_hazard),
        .s7_lane0_load_pending_i(s7_lane0_load_pending),
        .s7_lane1_load_pending_i(s7_lane1_load_pending),
        .s8_lane0_load_pending_i(s8_lane0_load_pending),
        .s8_lane1_load_pending_i(s8_lane1_load_pending),
        .s9_lane0_load_pending_i(s9_lane0_load_pending),
        .s9_lane1_load_pending_i(s9_lane1_load_pending),
        .lane0_rs1_wait_s7_i(lane0_rs1_wait_s7),
        .lane0_rs2_wait_s7_i(lane0_rs2_wait_s7),
        .lane0_rs1_wait_s8_i(lane0_rs1_wait_s8),
        .lane0_rs2_wait_s8_i(lane0_rs2_wait_s8),
        .lane0_rs1_wait_s9_i(lane0_rs1_wait_s9),
        .lane0_rs2_wait_s9_i(lane0_rs2_wait_s9),
        .lane1_rs1_wait_s7_i(lane1_rs1_wait_s7),
        .lane1_rs2_wait_s7_i(lane1_rs2_wait_s7),
        .lane1_rs1_wait_s8_i(lane1_rs1_wait_s8),
        .lane1_rs2_wait_s8_i(lane1_rs2_wait_s8),
        .lane1_rs1_wait_s9_i(lane1_rs1_wait_s9),
        .lane1_rs2_wait_s9_i(lane1_rs2_wait_s9),
        .slot1_emit_valid_i(slot1_emit_valid),
        .slot1_fire_i(slot1_fire),
        .slot1_emit_class_i(slot1_emit_class),
        .s6_ready_go_o(s6_ready_go_o),
        .s6_emit_valid_o(s6_emit_valid_o),
        .s6_allowin_o(s6_allowin_o),
        .load_use_hazard_o(load_use_hazard_o),
        .slot1_emit_valid_o(slot1_emit_valid_o),
        .slot1_fire_o(slot1_fire_o),
        .slot1_emit_class_o(slot1_emit_class_o),
        .older_load_summary_o(older_load_summary_o),
        .lane0_wait_summary_o(lane0_wait_summary_o),
        .lane1_wait_summary_o(lane1_wait_summary_o),
        .rr_event_reason_o(rr_event_reason_o)
    );

    task automatic clear_inputs;
        begin
            s6_ready_go = 1'b0;
            s6_emit_valid = 1'b0;
            s6_allowin = 1'b0;
            load_use_hazard = 1'b0;
            s7_lane0_load_pending = 1'b0;
            s7_lane1_load_pending = 1'b0;
            s8_lane0_load_pending = 1'b0;
            s8_lane1_load_pending = 1'b0;
            s9_lane0_load_pending = 1'b0;
            s9_lane1_load_pending = 1'b0;
            lane0_rs1_wait_s7 = 1'b0;
            lane0_rs2_wait_s7 = 1'b0;
            lane0_rs1_wait_s8 = 1'b0;
            lane0_rs2_wait_s8 = 1'b0;
            lane0_rs1_wait_s9 = 1'b0;
            lane0_rs2_wait_s9 = 1'b0;
            lane1_rs1_wait_s7 = 1'b0;
            lane1_rs2_wait_s7 = 1'b0;
            lane1_rs1_wait_s8 = 1'b0;
            lane1_rs2_wait_s8 = 1'b0;
            lane1_rs1_wait_s9 = 1'b0;
            lane1_rs2_wait_s9 = 1'b0;
            slot1_emit_valid = 1'b0;
            slot1_fire = 1'b0;
            slot1_emit_class = 4'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("RR event idle clears control",
               !s6_ready_go_o && !s6_emit_valid_o && !s6_allowin_o &&
               !load_use_hazard_o && !slot1_emit_valid_o && !slot1_fire_o);
        `check32("RR event idle summaries clear",
                 {14'd0, older_load_summary_o, lane0_wait_summary_o, lane1_wait_summary_o},
                 32'd0);
        `check32("RR event idle reason clear",
                 {24'd0, rr_event_reason_o}, 32'd0);

        clear_inputs();
        s6_ready_go = 1'b1;
        s6_emit_valid = 1'b1;
        s6_allowin = 1'b1;
        #1;
        `check("RR event forwards ready emit allowin",
               s6_ready_go_o && s6_emit_valid_o && s6_allowin_o &&
               !load_use_hazard_o);
        `check32("RR event ready reason",
                 {24'd0, rr_event_reason_o}, 32'h07);

        clear_inputs();
        load_use_hazard = 1'b1;
        s7_lane0_load_pending = 1'b1;
        s8_lane1_load_pending = 1'b1;
        s9_lane0_load_pending = 1'b1;
        lane0_rs1_wait_s7 = 1'b1;
        lane0_rs2_wait_s8 = 1'b1;
        lane1_rs1_wait_s9 = 1'b1;
        #1;
        `check("RR event forwards load-use hazard",
               load_use_hazard_o && !s6_emit_valid_o && !s6_allowin_o);
        `check32("RR event load summary packs lanes by age",
                 {26'd0, older_load_summary_o}, {26'd0, 6'b011001});
        `check32("RR event lane0 wait summary packs sources",
                 {26'd0, lane0_wait_summary_o}, {26'd0, 6'b001001});
        `check32("RR event lane1 wait summary packs sources",
                 {26'd0, lane1_wait_summary_o}, {26'd0, 6'b010000});
        `check32("RR event hazard reason includes wait bits",
                 {24'd0, rr_event_reason_o}, 32'hc8);

        clear_inputs();
        s6_ready_go = 1'b1;
        s6_emit_valid = 1'b1;
        s6_allowin = 1'b1;
        slot1_emit_valid = 1'b1;
        slot1_fire = 1'b1;
        slot1_emit_class = 4'b1000;
        #1;
        `check("RR event forwards slot1 fire",
               slot1_emit_valid_o && slot1_fire_o &&
               slot1_emit_class_o == 4'b1000);
        `check32("RR event slot1 fire reason",
                 {24'd0, rr_event_reason_o}, 32'h37);

        clear_inputs();
        slot1_emit_class = 4'b1111;
        #1;
        `check("RR event masks class when slot1 emit is invalid",
               !slot1_emit_valid_o && !slot1_fire_o && slot1_emit_class_o == 4'd0);

        finish_tb();
    end
endmodule
