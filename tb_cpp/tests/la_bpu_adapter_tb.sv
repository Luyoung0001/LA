`timescale 1ns / 1ps

module la_bpu_adapter_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic reset;
    logic req_valid;
    logic resp_valid;
    logic pred_taken;
    logic update_valid;
    logic update_taken;
    logic [31:0] req_pc;
    logic [31:0] pred_target;
    logic [31:0] update_pc;
    logic [31:0] update_target;

    localparam [31:0] PC_TAKEN     = 32'h8000_0100;
    localparam [31:0] PC_NOT_TAKEN = 32'h8000_0200;
    localparam [31:0] PC_UNKNOWN   = 32'h8000_0300;
    localparam [31:0] TARGET_TAKEN = 32'h8000_1000;

    assign reset = !rst_n;

    la_bpu_adapter u_dut (
        .clk(clk),
        .reset(reset),
        .req_valid(req_valid),
        .req_pc(req_pc),
        .resp_valid(resp_valid),
        .pred_taken(pred_taken),
        .pred_target(pred_target),
        .update_valid(update_valid),
        .update_taken(update_taken),
        .update_pc(update_pc),
        .update_target(update_target)
    );

    task automatic clear_inputs;
        begin
            req_valid = 1'b0;
            req_pc = 32'd0;
            update_valid = 1'b0;
            update_taken = 1'b0;
            update_pc = 32'd0;
            update_target = 32'd0;
        end
    endtask

    task automatic train_branch(
        input [31:0] pc,
        input        taken,
        input [31:0] target
    );
        begin
            update_valid = 1'b1;
            update_taken = taken;
            update_pc = pc;
            update_target = target;
            tick();
            update_valid = 1'b0;
            update_taken = 1'b0;
            update_pc = 32'd0;
            update_target = 32'd0;
            repeat (2) tick();
        end
    endtask

    task automatic train_and_check_update_pipe;
        begin
            update_valid = 1'b1;
            update_taken = 1'b1;
            update_pc = PC_TAKEN;
            update_target = TARGET_TAKEN;
            tick();
            update_valid = 1'b0;
            update_taken = 1'b0;
            update_pc = 32'd0;
            update_target = 32'd0;

            req_valid = 1'b1;
            req_pc = PC_TAKEN;
            tick();
            req_valid = 1'b0;
            req_pc = 32'd0;
            #1;
            `check("BPU adapter registered update has no same-cycle write-read bypass",
                   resp_valid && !pred_taken);
            `check32("BPU adapter registered update immediate fallback target",
                     pred_target, PC_TAKEN + 32'd4);
            tick();

            req_valid = 1'b1;
            req_pc = PC_TAKEN;
            tick();
            req_valid = 1'b0;
            req_pc = 32'd0;
            #1;
            `check("BPU adapter registered update becomes visible after settled write",
                   resp_valid && pred_taken);
            `check32("BPU adapter registered update settled target",
                     pred_target, TARGET_TAKEN);
            tick();
        end
    endtask

    task automatic request_and_expect_one_cycle(
        input string name,
        input [31:0] pc,
        input        exp_taken,
        input [31:0] exp_target
    );
        begin
            req_valid = 1'b1;
            req_pc = pc;
            #1;
            `check({name, " no same-cycle response"}, !resp_valid);
            tick();
            req_valid = 1'b0;
            req_pc = 32'd0;
            #1;
            `check({name, " one-cycle response valid"}, resp_valid);
            `check({name, " predicted direction"}, pred_taken == exp_taken);
            `check32({name, " predicted target"}, pred_target, exp_target);
            tick();
            #1;
            `check({name, " response is a level pulse"}, !resp_valid);
        end
    endtask

    initial begin
        tb_start();
        clear_inputs();
        reset_dut();

        train_and_check_update_pipe();

        train_branch(PC_TAKEN, 1'b1, TARGET_TAKEN);
        request_and_expect_one_cycle("BPU adapter trained taken",
                                     PC_TAKEN, 1'b1, TARGET_TAKEN);

        train_branch(PC_NOT_TAKEN, 1'b0, 32'h8000_2000);
        request_and_expect_one_cycle("BPU adapter trained not-taken",
                                     PC_NOT_TAKEN, 1'b0, PC_NOT_TAKEN + 32'd4);

        request_and_expect_one_cycle("BPU adapter untrained fallback",
                                     PC_UNKNOWN, 1'b0, PC_UNKNOWN + 32'd4);

        req_valid = 1'b1;
        req_pc = PC_TAKEN;
        tick();
        rst_n = 1'b0;
        tick();
        rst_n = 1'b1;
        req_valid = 1'b0;
        #1;
        `check("BPU adapter reset clears pending response", !resp_valid);

        finish_tb();
    end
endmodule
