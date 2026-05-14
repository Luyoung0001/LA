`timescale 1ns / 1ps

module s1_if0_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s1_valid;
    logic s2_allowin;
    logic redirect_valid;
    logic bpu_redirect_valid;

    logic ready_go;
    logic allowin;
    logic to_next_valid;
    logic redirect_fire;
    logic bpu_redirect_fire;
    logic seq_advance;
    logic pc_accept;

    s1_if0_stage_ctrl u_dut (
        .s1_valid_i(s1_valid),
        .s2_allowin_i(s2_allowin),
        .redirect_valid_i(redirect_valid),
        .bpu_redirect_valid_i(bpu_redirect_valid),
        .ready_go_o(ready_go),
        .allowin_o(allowin),
        .to_next_valid_o(to_next_valid),
        .redirect_fire_o(redirect_fire),
        .bpu_redirect_fire_o(bpu_redirect_fire),
        .seq_advance_o(seq_advance),
        .pc_accept_o(pc_accept)
    );

    task automatic clear_inputs;
        begin
            s1_valid = 1'b0;
            s2_allowin = 1'b0;
            redirect_valid = 1'b0;
            bpu_redirect_valid = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S1CTRL empty stage accepts downstream backpressure",
               ready_go && allowin && !to_next_valid && seq_advance && pc_accept);

        clear_inputs();
        s1_valid = 1'b1;
        s2_allowin = 1'b1;
        #1;
        `check("S1CTRL valid stage advances sequential PC",
               ready_go && allowin && to_next_valid && seq_advance && pc_accept);

        clear_inputs();
        s1_valid = 1'b1;
        s2_allowin = 1'b0;
        #1;
        `check("S1CTRL downstream backpressure holds sequential PC",
               ready_go && !allowin && to_next_valid && !seq_advance && !pc_accept);

        redirect_valid = 1'b1;
        bpu_redirect_valid = 1'b1;
        #1;
        `check("S1CTRL backend redirect has priority over BPU",
               redirect_fire && !bpu_redirect_fire && !seq_advance);

        redirect_valid = 1'b0;
        bpu_redirect_valid = 1'b1;
        #1;
        `check("S1CTRL BPU redirect updates PC without sequential accept",
               !redirect_fire && bpu_redirect_fire && !seq_advance);

        finish_tb();
    end
endmodule
