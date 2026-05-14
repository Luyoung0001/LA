`timescale 1ns / 1ps
`include "cpu_defs.vh"

module redirect_token_arbiter_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic wb_excp_valid, wb_ertn_valid, wb_refetch_valid;
    logic s8_redirect_valid, s7_redirect_valid, s5_redirect_valid, s4_redirect_valid;
    logic redirect_valid, redirect_from_wb;
    logic redirect_is_s4, redirect_is_s5, redirect_is_s7, redirect_is_s8, redirect_is_wb;
    logic kill_frontend, kill_s4_side_effect, kill_s5, kill_s6, kill_s7, kill_s8, kill_s9;
    logic [1:0] redirect_next_epoch_i, redirect_next_epoch;
    logic [2:0] redirect_source;
    logic [5:0] wb_excp_ecode;
    logic [31:0] wb_excp_entry, wb_tlbr_entry, wb_ertn_pc, wb_refetch_pc;
    logic [31:0] s8_redirect_pc, s7_redirect_pc, s5_redirect_pc, s4_redirect_pc;
    logic [31:0] redirect_pc;

    redirect_token_arbiter #(.XLEN(32), .EPOCH_WIDTH(2)) u_dut (
        .redirect_next_epoch_i(redirect_next_epoch_i),
        .wb_excp_valid_i(wb_excp_valid),
        .wb_excp_ecode_i(wb_excp_ecode),
        .wb_excp_entry_i(wb_excp_entry),
        .wb_tlbr_entry_i(wb_tlbr_entry),
        .wb_ertn_valid_i(wb_ertn_valid),
        .wb_ertn_pc_i(wb_ertn_pc),
        .wb_refetch_valid_i(wb_refetch_valid),
        .wb_refetch_pc_i(wb_refetch_pc),
        .s8_redirect_valid_i(s8_redirect_valid),
        .s8_redirect_pc_i(s8_redirect_pc),
        .s7_redirect_valid_i(s7_redirect_valid),
        .s7_redirect_pc_i(s7_redirect_pc),
        .s5_redirect_valid_i(s5_redirect_valid),
        .s5_redirect_pc_i(s5_redirect_pc),
        .s4_redirect_valid_i(s4_redirect_valid),
        .s4_redirect_pc_i(s4_redirect_pc),
        .redirect_valid_o(redirect_valid),
        .redirect_pc_o(redirect_pc),
        .redirect_source_o(redirect_source),
        .redirect_from_wb_o(redirect_from_wb),
        .redirect_is_s4_o(redirect_is_s4),
        .redirect_is_s5_o(redirect_is_s5),
        .redirect_is_s7_o(redirect_is_s7),
        .redirect_is_s8_o(redirect_is_s8),
        .redirect_is_wb_o(redirect_is_wb),
        .redirect_next_epoch_o(redirect_next_epoch),
        .kill_frontend_o(kill_frontend),
        .kill_s4_side_effect_o(kill_s4_side_effect),
        .kill_s5_o(kill_s5),
        .kill_s6_o(kill_s6),
        .kill_s7_o(kill_s7),
        .kill_s8_o(kill_s8),
        .kill_s9_o(kill_s9)
    );

    task automatic clear_inputs;
        begin
            wb_excp_valid = 1'b0;
            wb_ertn_valid = 1'b0;
            wb_refetch_valid = 1'b0;
            s8_redirect_valid = 1'b0;
            s7_redirect_valid = 1'b0;
            s5_redirect_valid = 1'b0;
            s4_redirect_valid = 1'b0;
            wb_excp_ecode = 6'd0;
            wb_excp_entry = 32'h1c00_0180;
            wb_tlbr_entry = 32'h1c00_0200;
            wb_ertn_pc = 32'h1c00_0300;
            wb_refetch_pc = 32'h1c00_0400;
            s8_redirect_pc = 32'h1c00_0800;
            s7_redirect_pc = 32'h1c00_0700;
            s5_redirect_pc = 32'h1c00_0500;
            s4_redirect_pc = 32'h1c00_0404;
            redirect_next_epoch_i = 2'd2;
        end
    endtask

    initial begin
        tb_start();
        rst_n = 1'b1;
        clear_inputs();
        #1;
        `check("Redirect token idle invalid", !redirect_valid && !redirect_from_wb);
        `check32("Redirect token idle source", {29'd0, redirect_source}, 32'd0);
        `check32("Redirect token idle epoch zero", {30'd0, redirect_next_epoch}, 32'd0);
        `check("Redirect token idle has no class",
               !(redirect_is_s4 || redirect_is_s5 || redirect_is_s7 ||
                 redirect_is_s8 || redirect_is_wb));
        `check("Redirect token idle kills nothing", !(kill_frontend || kill_s4_side_effect || kill_s5 ||
                                                       kill_s6 || kill_s7 || kill_s8 || kill_s9));

        s4_redirect_valid = 1'b1; #1;
        `check("Redirect token accepts S4", redirect_valid && !redirect_from_wb);
        `check32("Redirect token S4 PC", redirect_pc, s4_redirect_pc);
        `check32("Redirect token S4 source", {29'd0, redirect_source}, 32'd7);
        `check("Redirect token S4 class", redirect_is_s4 && !redirect_is_wb);
        `check32("Redirect token carries next epoch", {30'd0, redirect_next_epoch}, 32'd2);
        `check("Redirect token S4 kills only frontend", kill_frontend && !(kill_s4_side_effect || kill_s5 ||
                                                                           kill_s6 || kill_s7 || kill_s8 || kill_s9));

        s5_redirect_valid = 1'b1; #1;
        `check32("Redirect token S5 beats S4", redirect_pc, s5_redirect_pc);
        `check32("Redirect token S5 source", {29'd0, redirect_source}, 32'd6);
        `check("Redirect token S5 class", redirect_is_s5 && !redirect_is_s4);
        `check("Redirect token S5 kills S4 side effect and S5", kill_frontend && kill_s4_side_effect &&
                                                                 kill_s5 && !(kill_s6 || kill_s7 || kill_s8 || kill_s9));
        redirect_next_epoch_i = 2'd3; #1;
        `check32("Redirect token updates epoch payload", {30'd0, redirect_next_epoch}, 32'd3);

        s7_redirect_valid = 1'b1; #1;
        `check32("Redirect token S7 beats S5", redirect_pc, s7_redirect_pc);
        `check32("Redirect token S7 source", {29'd0, redirect_source}, 32'd5);
        `check("Redirect token S7 class", redirect_is_s7 && !redirect_is_s5);
        `check("Redirect token S7 kills younger backend", kill_frontend && kill_s4_side_effect &&
                                                         kill_s5 && kill_s6 && !(kill_s7 || kill_s8 || kill_s9));

        s8_redirect_valid = 1'b1; #1;
        `check32("Redirect token S8 beats S7", redirect_pc, s8_redirect_pc);
        `check32("Redirect token S8 source", {29'd0, redirect_source}, 32'd4);
        `check("Redirect token S8 class", redirect_is_s8 && !redirect_is_s7);
        `check("Redirect token S8 kills through S7", kill_frontend && kill_s4_side_effect &&
                                                       kill_s5 && kill_s6 && kill_s7 && !(kill_s8 || kill_s9));

        wb_refetch_valid = 1'b1; #1;
        `check("Redirect token WB refetch beats backend", redirect_valid && redirect_from_wb);
        `check32("Redirect token WB refetch PC", redirect_pc, wb_refetch_pc);
        `check32("Redirect token WB refetch source", {29'd0, redirect_source}, 32'd3);
        `check("Redirect token WB class", redirect_is_wb && !redirect_is_s8);
        `check("Redirect token WB kills frontend and younger backend", kill_frontend && kill_s4_side_effect &&
                                                                     kill_s5 && kill_s6 && kill_s7 && kill_s8 && kill_s9);

        wb_ertn_valid = 1'b1; #1;
        `check32("Redirect token ERTN beats refetch", redirect_pc, wb_ertn_pc);
        `check32("Redirect token ERTN source", {29'd0, redirect_source}, 32'd2);

        wb_excp_valid = 1'b1; wb_excp_ecode = `CPU_ECODE_SYS; #1;
        `check32("Redirect token exception uses eentry", redirect_pc, wb_excp_entry);
        `check32("Redirect token exception source", {29'd0, redirect_source}, 32'd1);

        wb_excp_ecode = `CPU_ECODE_TLBR; #1;
        `check32("Redirect token TLBR uses tlbrentry", redirect_pc, wb_tlbr_entry);

        finish_tb();
    end
endmodule
