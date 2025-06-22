module pre_IFU (
        input wire clk,             // 时钟信号
        input wire rst,             // 复位信号
        input wire [33:0] bus_br_data,
        output wire [31:0] pc_o,

        input wire [1:0] flush,
        input wire [31:0] csr_era,
        input wire [31:0] csr_eentry,
        input wire [31:0] csr_tlbrentry,
        input wbu_excp_tlbrefill,
        // 握手信号
        input wire waite_ready_i,
        output wire state_valid,

        // refetch
        input wire [31:0] refetch_pc_i,
        input wire refetch_sign_i,
        input wire wbu_refetch_flush
    );

    reg  [31:0] pc;
    wire excp_flush;
    wire ertn_flush;
    wire flush_sign;
    assign {excp_flush, ertn_flush} = flush;
    assign flush_sign = ertn_flush || excp_flush || wbu_refetch_flush;

    wire [31:0] seq_pc;
    wire [31:0] nextpc;

    wire br_taken;
    wire [31:0] br_target;
    wire caculate_done;

    wire [31:0] inst_flush_pc;

    assign {br_taken, br_target,caculate_done} = bus_br_data;

    assign inst_flush_pc = {32{ertn_flush}} & csr_era;
    assign seq_pc       = pc + 32'h4;

    // 这里要注意优先级
    assign nextpc       =
           wbu_excp_tlbrefill ? csr_tlbrentry :
           excp_flush ? csr_eentry:
           ertn_flush ? inst_flush_pc:
           refetch_sign_i ? refetch_pc_i :
           br_taken ? br_target :
           seq_pc;

    reg [1:0] pfs_state;
    always @(posedge clk) begin
        if (rst) begin
            pfs_state <= 2'd0;
            pc <= 32'h1bfffffc;
        end
        else if(pfs_state == 2'd0 || flush_sign) begin
            if(caculate_done && !flush_sign) begin
                pfs_state <= 2'd1;
                pc <= nextpc;
            end
            else if (flush_sign)begin
                pfs_state <= 2'd1;
                pc <= nextpc;
            end

        end
        else if(pfs_state == 2'd1) begin
            if(waite_ready_i) begin
                pfs_state <= 2'd0;
            end
        end
    end

    assign pc_o = pc;
    assign state_valid = pfs_state == 2'd1  ? 1'b1 : 1'b0;

endmodule



