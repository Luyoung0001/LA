module redirect_ctrl (
    // EX-stage branch resolve. branch_valid asserts when a control-flow
    // instruction commits in EX; branch_mispredict tells whether we need
    // to actually steer the frontend (i.e. predicted next PC mismatched
    // the actual next PC). A correctly predicted branch produces
    // branch_valid=1 / branch_mispredict=0 and does NOT raise redirect.
    input  wire        branch_valid,
    input  wire        branch_mispredict,
    input  wire [31:0] branch_pc,
    input  wire        branch_taken,
    input  wire [31:0] branch_target,

    input  wire        exception_valid,
    input  wire [31:0] exception_target,

    input  wire        ertn_valid,
    input  wire [31:0] ertn_target,

    input  wire        refetch_valid,
    input  wire [31:0] refetch_target,

    output wire        redirect_valid,
    output wire [31:0] redirect_pc,
    output wire        redirect_is_exception
);

    wire [31:0] branch_next_pc;
    wire        branch_redirect_w = branch_valid && branch_mispredict;

    assign branch_next_pc = branch_taken ? branch_target : (branch_pc + 32'd4);

    assign redirect_valid = exception_valid || ertn_valid || refetch_valid || branch_redirect_w;
    assign redirect_pc    = exception_valid ? exception_target :
                            ertn_valid      ? ertn_target :
                            refetch_valid   ? refetch_target :
                                              branch_next_pc;
    assign redirect_is_exception = exception_valid || ertn_valid || refetch_valid;

endmodule
