`timescale 1ns / 1ps

module s5_issue_policy_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic s5_valid;
    logic load_use_hazard;
    logic is_barrier;
    logic pipeline_no_empty;
    logic branch;
    logic fault;
    logic branch_operands_ready;
    logic branch_mismatch;
    logic load_use_stall;
    logic barrier_stall;
    logic ready_go;
    logic branch_redirect_raw;
    logic [2:0] stall_reason;

    s5_issue_policy u_dut (
        .s5_valid_i(s5_valid),
        .load_use_hazard_i(load_use_hazard),
        .is_barrier_i(is_barrier),
        .pipeline_no_empty_i(pipeline_no_empty),
        .branch_i(branch),
        .fault_i(fault),
        .branch_operands_ready_i(branch_operands_ready),
        .branch_mismatch_i(branch_mismatch),
        .load_use_stall_o(load_use_stall),
        .barrier_stall_o(barrier_stall),
        .ready_go_o(ready_go),
        .branch_redirect_raw_o(branch_redirect_raw),
        .stall_reason_o(stall_reason)
    );

    task automatic clear_inputs;
        begin
            s5_valid = 1'b0;
            load_use_hazard = 1'b0;
            is_barrier = 1'b0;
            pipeline_no_empty = 1'b0;
            branch = 1'b0;
            fault = 1'b0;
            branch_operands_ready = 1'b0;
            branch_mismatch = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;
        clear_inputs();
        #1;
        `check("POL idle has no stall", !load_use_stall && !barrier_stall && ready_go);
        `check("POL idle has no redirect", !branch_redirect_raw);
        `check32("POL idle stall reason clear", {29'd0, stall_reason}, 32'd0);

        clear_inputs();
        s5_valid = 1'b1;
        load_use_hazard = 1'b1;
        #1;
        `check("POL load-use stalls ready_go", load_use_stall && !barrier_stall && !ready_go);
        `check32("POL load-use reason bit", {29'd0, stall_reason}, 32'h1);

        clear_inputs();
        s5_valid = 1'b1;
        is_barrier = 1'b1;
        pipeline_no_empty = 1'b1;
        #1;
        `check("POL barrier waits for backend drain", !load_use_stall && barrier_stall && !ready_go);
        `check32("POL barrier reason bit", {29'd0, stall_reason}, 32'h2);

        clear_inputs();
        s5_valid = 1'b1;
        is_barrier = 1'b1;
        pipeline_no_empty = 1'b0;
        #1;
        `check("POL barrier passes when backend empty", !load_use_stall && !barrier_stall && ready_go);
        `check32("POL empty backend clears reason", {29'd0, stall_reason}, 32'd0);

        clear_inputs();
        branch = 1'b1;
        branch_mismatch = 1'b1;
        branch_operands_ready = 1'b1;
        #1;
        `check("POL branch redirect fires when ready", branch_redirect_raw);
        `check32("POL redirect-ready leaves stall reason clear", {29'd0, stall_reason}, 32'd0);

        clear_inputs();
        branch = 1'b1;
        branch_mismatch = 1'b1;
        branch_operands_ready = 1'b0;
        #1;
        `check("POL branch redirect waits for operands", !branch_redirect_raw);
        `check32("POL branch wait reason bit", {29'd0, stall_reason}, 32'h4);

        clear_inputs();
        branch = 1'b1;
        branch_mismatch = 1'b1;
        branch_operands_ready = 1'b1;
        fault = 1'b1;
        #1;
        `check("POL fault suppresses early redirect", !branch_redirect_raw);
        `check32("POL fault does not report operand wait", {29'd0, stall_reason}, 32'd0);

        finish_tb();
    end
endmodule
