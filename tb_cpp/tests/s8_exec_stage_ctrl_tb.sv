`timescale 1ns / 1ps

module s8_exec_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s8_valid;
    logic s9_allowin;
    logic late_s10_need;
    logic late_s10_data_valid;
    logic late_s10_match;
    logic inst_div_op;
    logic div_done;
    logic slot1_valid;
    logic slot1_issue_valid;
    logic [3:0] slot1_issue_class;

    logic late_s10_ready;
    logic late_s10_wait;
    logic ready_go;
    logic allowin;
    logic to_next_valid;
    logic fire;
    logic slot1_emit_valid;
    logic slot1_fire;
    logic [3:0] slot1_emit_class;

    s8_exec_stage_ctrl u_dut (
        .s8_valid_i(s8_valid),
        .s9_allowin_i(s9_allowin),
        .late_s10_need_i(late_s10_need),
        .late_s10_data_valid_i(late_s10_data_valid),
        .late_s10_match_i(late_s10_match),
        .inst_div_op_i(inst_div_op),
        .div_done_i(div_done),
        .slot1_valid_i(slot1_valid),
        .slot1_issue_valid_i(slot1_issue_valid),
        .slot1_issue_class_i(slot1_issue_class),
        .late_s10_ready_o(late_s10_ready),
        .late_s10_wait_o(late_s10_wait),
        .ready_go_o(ready_go),
        .allowin_o(allowin),
        .to_next_valid_o(to_next_valid),
        .fire_o(fire),
        .slot1_emit_valid_o(slot1_emit_valid),
        .slot1_fire_o(slot1_fire),
        .slot1_emit_class_o(slot1_emit_class)
    );

    task automatic clear_inputs;
        begin
            s8_valid = 1'b0;
            s9_allowin = 1'b0;
            late_s10_need = 1'b0;
            late_s10_data_valid = 1'b0;
            late_s10_match = 1'b0;
            inst_div_op = 1'b0;
            div_done = 1'b0;
            slot1_valid = 1'b0;
            slot1_issue_valid = 1'b0;
            slot1_issue_class = 4'd0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S8CTRL empty stage accepts input",
               late_s10_ready && ready_go && allowin &&
               !to_next_valid && !fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        clear_inputs();
        s8_valid = 1'b1;
        s9_allowin = 1'b1;
        #1;
        `check("S8CTRL valid ready stage fires",
               ready_go && allowin && to_next_valid && fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S8CTRL emits and fires selected slot1 with lane0",
               to_next_valid && fire && slot1_emit_valid && slot1_fire &&
               slot1_emit_class == 4'b1000);

        clear_inputs();
        s8_valid = 1'b1;
        s9_allowin = 1'b0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S8CTRL downstream backpressure holds input",
               ready_go && !allowin && to_next_valid && !fire &&
               slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'b1000);

        clear_inputs();
        s8_valid = 1'b1;
        s9_allowin = 1'b1;
        late_s10_need = 1'b1;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S8CTRL late S10 wait stalls stage",
               !late_s10_ready && late_s10_wait &&
               !ready_go && !allowin && !to_next_valid && !fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        late_s10_match = 1'b1;
        #1;
        `check("S8CTRL same-cycle late S10 match releases wait",
               late_s10_ready && !late_s10_wait &&
               ready_go && allowin && to_next_valid && fire &&
               slot1_emit_valid && slot1_fire && slot1_emit_class == 4'b1000);

        late_s10_match = 1'b0;
        late_s10_data_valid = 1'b1;
        #1;
        `check("S8CTRL captured late S10 data releases wait",
               late_s10_ready && !late_s10_wait && ready_go && fire &&
               slot1_emit_valid && slot1_fire && slot1_emit_class == 4'b1000);

        clear_inputs();
        s8_valid = 1'b1;
        s9_allowin = 1'b1;
        inst_div_op = 1'b1;
        div_done = 1'b0;
        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b1;
        slot1_issue_class = 4'b1000;
        #1;
        `check("S8CTRL divider op waits for done",
               !ready_go && !allowin && !to_next_valid && !fire &&
               !slot1_emit_valid && !slot1_fire && slot1_emit_class == 4'd0);

        div_done = 1'b1;
        #1;
        `check("S8CTRL divider done releases stage",
               ready_go && allowin && to_next_valid && fire &&
               slot1_emit_valid && slot1_fire && slot1_emit_class == 4'b1000);

        clear_inputs();
        s8_valid = 1'b1;
        s9_allowin = 1'b1;
        late_s10_need = 1'b1;
        late_s10_match = 1'b1;
        inst_div_op = 1'b1;
        div_done = 1'b0;
        #1;
        `check("S8CTRL div wait wins even when late S10 ready",
               late_s10_ready && !late_s10_wait &&
               !ready_go && !allowin && !to_next_valid && !fire);

        clear_inputs();
        s8_valid = 1'b1;
        s9_allowin = 1'b1;
        slot1_issue_class = 4'b1111;
        #1;
        `check("S8CTRL masks slot1 class when slot1 is invalid",
               to_next_valid && fire && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        slot1_valid = 1'b1;
        slot1_issue_valid = 1'b0;
        #1;
        `check("S8CTRL masks slot1 class when slot1 is held but not issued",
               to_next_valid && fire && !slot1_emit_valid && !slot1_fire &&
               slot1_emit_class == 4'd0);

        finish_tb();
    end
endmodule
