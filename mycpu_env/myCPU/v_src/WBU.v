`include "csr.h"
module WBU(
        // from mem
        input wire clk,
        input wire rst,

        input wire [149:0] bus_mem_to_wbu_data,

        input wire ms_excp,
        input wire [15:0] ms_excp_num,

        // to rf
        output wire rf_we,
        output wire [4:0] rf_waddr,
        output wire [31:0] rf_wdata,
        output wire [31:0] pc,

        // bus
        output wire [84:0] bus_wbu_bypass_data,
        // csr
        output wire csr_we,
        output wire [13:0] csr_addr,
        output wire [31:0] csr_wdata,

        output [ 5:0] csr_ecode,
        output wire va_error,
        output [31:0] bad_va,
        output [8:0] csr_esubcode,
        output wire excp_tlbrefill,
        output wire excp_tlb,
        output [18:0] excp_tlb_vppn,

        // exception
        output wire ertn_flush,
        output wire  excp_flush,
        output wire [31:0] csr_era,
        // ertn
        output wire is_ertn,
        // 握手信号
        //allowin
        output  ws_allowin,    // 发给上游的 allowin 信号
        input   ms_to_ws_valid // 来自的上游的 valid 信号

    );

    // 异常信号
    reg [15:0] ms_excp_num_r; // 从上一级接收
    reg ms_excp_r;

    wire [15:0] wire_ms_excp_num;
    wire wire_ms_excp;

    wire [15:0] ws_excp_num;
    wire ws_excp;

    assign wire_ms_excp_num = ms_excp_num_r;
    assign wire_ms_excp = ms_excp_r;

    assign ws_excp_num = wire_ms_excp_num;
    assign ws_excp = wire_ms_excp;

    wire flush_sign;

    // 数据相关
    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    wire wbu_csr_we;
    wire [13:0] wbu_csr_idx;
    wire [31:0] wbu_csr_wdata;

    wire wire_gr_we;
    wire [4:0] wire_dest;
    wire [31:0] wire_final_result;
    wire [31:0] wire_pc;
    wire wire_csr_we;
    wire [13:0] wire_csr_idx;
    wire [31:0] wire_csr_wdata;
    wire wire_is_inst_ertn;
    wire [31:0] wire_error_va;

    reg [149:0] bus_mem_to_wbu_data_r;

    assign {
            wire_gr_we,
            wire_dest,
            wire_final_result,
            wire_pc,
            wire_csr_we,
            wire_csr_idx,
            wire_csr_wdata,
            wire_is_inst_ertn,
            wire_error_va
        } = bus_mem_to_wbu_data_r;



    reg ws_valid;
    wire ws_ready_go;

    assign ws_ready_go = 1'b1;
    assign ws_allowin  = !ws_valid || ws_ready_go;
    always @(posedge clk) begin
        if (rst || flush_sign) begin
            ws_valid <= 1'b0;
        end
        else if (ws_allowin) begin
            ws_valid <= ms_to_ws_valid;
        end

        if (ms_to_ws_valid && ws_allowin) begin
            bus_mem_to_wbu_data_r <= bus_mem_to_wbu_data;
            ms_excp_num_r <= ms_excp_num;
            ms_excp_r <= ms_excp;
        end
    end

    // 输出到 regfile
    assign rf_we    = wire_gr_we & ws_valid & !ws_excp;
    assign rf_waddr = wire_dest;
    assign rf_wdata = wire_final_result;
    assign pc       = wire_pc;

    // 输出到 csr
    assign csr_we = wire_csr_we & ws_valid & !ws_excp;
    assign csr_addr = wire_csr_idx;
    assign csr_wdata = wire_csr_wdata;

    assign ertn_flush = wire_is_inst_ertn & ws_valid & !ws_excp;

    // 解决数据相关
    assign wbu_regWr = rf_we;
    assign wbu_data = wire_final_result;
    assign wbu_regAddr = wire_dest;

    assign wbu_csr_we = csr_we;
    assign wbu_csr_idx = csr_addr;
    assign wbu_csr_wdata = csr_wdata;

    assign bus_wbu_bypass_data = {
               wbu_regWr,
               wbu_data,
               wbu_regAddr,
               wbu_csr_we,
               wbu_csr_idx,
               wbu_csr_wdata
           };

    assign excp_flush = ws_excp & ws_valid;
    assign flush_sign = excp_flush || ertn_flush;

    assign is_ertn = wire_is_inst_ertn;


    assign csr_era = wire_pc;
    // 检测异常
    assign {csr_ecode,
            va_error,
            bad_va,
            csr_esubcode,
            excp_tlbrefill,
            excp_tlb,
            excp_tlb_vppn} =
           ws_excp_num[0] ? {`ECODE_INT , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0}:
           ws_excp_num[8] ? {`ECODE_ADEF, ws_valid, wire_pc, `ESUBCODE_ADEF, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[9] ? {`ECODE_ALE , ws_valid, wire_error_va, 9'b0, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[11] ? {`ECODE_SYS, 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0}:
           ws_excp_num[12] ? {`ECODE_BRK , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[13] ? {`ECODE_INE , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0} :
           69'b0;

endmodule
