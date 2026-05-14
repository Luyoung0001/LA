`timescale 1ns / 1ps

module s3_if2_accept_ctrl_tb;
    logic clk;
    logic rst_n;
    integer checks;
    integer failures;
    `include "tb_common.svh"

    logic flush;
    logic s2_to_s3_valid;
    logic s2_epoch_match;
    logic stream_skip_match;
    logic preview_skip_match;
    logic [3:0] total_queued;
    logic out_pop;

    logic capacity_available;
    logic duplicate_match;
    logic allowin;
    logic meta_push;
    logic stream_skip_drop;
    logic preview_skip_drop;
    logic duplicate_drop;
    logic s2_dup_drop;

    s3_if2_accept_ctrl #(
        .COUNT_WIDTH(4),
        .DEPTH_COUNT(4'd8)
    ) u_dut (
        .flush_i(flush),
        .s2_to_s3_valid_i(s2_to_s3_valid),
        .s2_epoch_match_i(s2_epoch_match),
        .stream_skip_match_i(stream_skip_match),
        .preview_skip_match_i(preview_skip_match),
        .total_queued_i(total_queued),
        .out_pop_i(out_pop),
        .capacity_available_o(capacity_available),
        .duplicate_match_o(duplicate_match),
        .allowin_o(allowin),
        .meta_push_o(meta_push),
        .stream_skip_drop_o(stream_skip_drop),
        .preview_skip_drop_o(preview_skip_drop),
        .duplicate_drop_o(duplicate_drop),
        .s2_dup_drop_o(s2_dup_drop)
    );

    task automatic clear_inputs;
        begin
            flush = 1'b0;
            s2_to_s3_valid = 1'b0;
            s2_epoch_match = 1'b1;
            stream_skip_match = 1'b0;
            preview_skip_match = 1'b0;
            total_queued = 4'd0;
            out_pop = 1'b0;
        end
    endtask

    initial begin
        tb_start();
        clk = 1'b0;
        rst_n = 1'b1;

        clear_inputs();
        total_queued = 4'd3;
        s2_to_s3_valid = 1'b1;
        #1;
        `check("S3ACCEPT queue space accepts real metadata",
               capacity_available && allowin && meta_push &&
               !duplicate_match && !duplicate_drop);

        total_queued = 4'd8;
        #1;
        `check("S3ACCEPT full queue blocks real metadata",
               !capacity_available && !allowin && !meta_push);

        out_pop = 1'b1;
        #1;
        `check("S3ACCEPT output pop frees one shared slot",
               capacity_available && allowin && meta_push);

        clear_inputs();
        s2_to_s3_valid = 1'b1;
        s2_epoch_match = 1'b0;
        total_queued = 4'd8;
        #1;
        `check("S3ACCEPT stale epoch is swallowed even when full",
               allowin && !meta_push && !duplicate_match && !s2_dup_drop);

        clear_inputs();
        s2_to_s3_valid = 1'b1;
        total_queued = 4'd8;
        stream_skip_match = 1'b1;
        #1;
        `check("S3ACCEPT stream duplicate drops without queue space",
               allowin && meta_push && duplicate_match && s2_dup_drop &&
               stream_skip_drop && duplicate_drop);

        stream_skip_match = 1'b0;
        preview_skip_match = 1'b1;
        #1;
        `check("S3ACCEPT preview duplicate drops without queue space",
               allowin && meta_push && duplicate_match && s2_dup_drop &&
               preview_skip_drop && duplicate_drop);

        s2_to_s3_valid = 1'b0;
        #1;
        `check("S3ACCEPT duplicate sideband is visible before valid fires",
               duplicate_match && s2_dup_drop && allowin && !meta_push &&
               !preview_skip_drop && !duplicate_drop);

        flush = 1'b1;
        s2_to_s3_valid = 1'b1;
        #1;
        `check("S3ACCEPT flush blocks allowin but preserves duplicate sideband",
               !allowin && !meta_push && duplicate_match && s2_dup_drop);

        finish_tb();
    end
endmodule
