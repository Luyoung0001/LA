`timescale 1ns / 1ps

module s10_wb_stage_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s10_valid;
    logic s9_to_s10_valid;
    logic s11_allowin;
    logic is_load;
    logic is_store;
    logic is_sc;
    logic sc_success;
    logic exception;
    logic dc_resp_valid;
    logic inst_cacop_valid;
    logic cacop_done;
    logic slot1_store_wait;

    logic sc_store_wait;
    logic load_wait;
    logic store_wait;
    logic cacop_wait;
    logic ready_go;
    logic allowin;
    logic capture;
    logic commit_ready;

    s10_wb_stage_ctrl u_dut (
        .s10_valid_i(s10_valid),
        .s9_to_s10_valid_i(s9_to_s10_valid),
        .s11_allowin_i(s11_allowin),
        .is_load_i(is_load),
        .is_store_i(is_store),
        .is_sc_i(is_sc),
        .sc_success_i(sc_success),
        .exception_i(exception),
        .dc_resp_valid_i(dc_resp_valid),
        .inst_cacop_valid_i(inst_cacop_valid),
        .cacop_done_i(cacop_done),
        .slot1_store_wait_i(slot1_store_wait),
        .sc_store_wait_o(sc_store_wait),
        .load_wait_o(load_wait),
        .store_wait_o(store_wait),
        .cacop_wait_o(cacop_wait),
        .ready_go_o(ready_go),
        .allowin_o(allowin),
        .capture_o(capture),
        .commit_ready_o(commit_ready)
    );

    task automatic clear_inputs;
        begin
            s10_valid = 1'b0;
            s9_to_s10_valid = 1'b0;
            s11_allowin = 1'b1;
            is_load = 1'b0;
            is_store = 1'b0;
            is_sc = 1'b0;
            sc_success = 1'b0;
            exception = 1'b0;
            dc_resp_valid = 1'b0;
            inst_cacop_valid = 1'b0;
            cacop_done = 1'b0;
            slot1_store_wait = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        #1;
        `check("S10CTRL empty stage accepts input",
               ready_go && allowin && !commit_ready);

        s9_to_s10_valid = 1'b1;
        #1;
        `check("S10CTRL empty stage captures upstream", capture);

        clear_inputs();
        s10_valid = 1'b1;
        #1;
        `check("S10CTRL valid ready commits",
               ready_go && allowin && commit_ready);

        clear_inputs();
        s10_valid = 1'b1;
        is_load = 1'b1;
        #1;
        `check("S10CTRL load waits for dcache response",
               load_wait && !ready_go && !allowin && !commit_ready);

        dc_resp_valid = 1'b1;
        #1;
        `check("S10CTRL load response releases stage",
               !load_wait && ready_go && allowin && commit_ready);

        clear_inputs();
        s10_valid = 1'b1;
        is_store = 1'b1;
        #1;
        `check("S10CTRL store waits for dcache response",
               store_wait && !ready_go);

        clear_inputs();
        s10_valid = 1'b1;
        is_store = 1'b1;
        is_sc = 1'b1;
        sc_success = 1'b1;
        #1;
        `check("S10CTRL successful SC uses SC store wait",
               sc_store_wait && !store_wait && !ready_go);

        clear_inputs();
        s10_valid = 1'b1;
        is_store = 1'b1;
        is_sc = 1'b1;
        sc_success = 1'b0;
        #1;
        `check("S10CTRL failed SC does not wait for dcache",
               !sc_store_wait && !store_wait && ready_go && commit_ready);

        clear_inputs();
        s10_valid = 1'b1;
        inst_cacop_valid = 1'b1;
        #1;
        `check("S10CTRL CACOP waits for done",
               cacop_wait && !ready_go);

        cacop_done = 1'b1;
        #1;
        `check("S10CTRL CACOP done releases stage",
               !cacop_wait && ready_go && commit_ready);

        clear_inputs();
        s10_valid = 1'b1;
        slot1_store_wait = 1'b1;
        #1;
        `check("S10CTRL slot1 store wait blocks commit",
               !ready_go && !allowin && !commit_ready);

        clear_inputs();
        s10_valid = 1'b1;
        is_load = 1'b1;
        exception = 1'b1;
        #1;
        `check("S10CTRL exception suppresses memory wait",
               !load_wait && ready_go && commit_ready);

        finish_tb();
    end
endmodule
