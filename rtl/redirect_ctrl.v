module redirect_ctrl (
    input  wire        branch_valid,
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
    output wire [31:0] redirect_pc
);

    wire [31:0] branch_next_pc;

    assign branch_next_pc = branch_taken ? branch_target : (branch_pc + 32'd4);

    assign redirect_valid = exception_valid || ertn_valid || refetch_valid || branch_valid;
    assign redirect_pc    = exception_valid ? exception_target :
                            ertn_valid      ? ertn_target :
                            refetch_valid   ? refetch_target :
                                              branch_next_pc;

endmodule
