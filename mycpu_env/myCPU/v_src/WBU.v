`include "csr.h"
module WBU
    #(
         parameter TLBNUM = 64
     )
     (
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
         output wire [85:0] bus_wbu_bypass_data,

         // csr
         output wire [147:0] bus_wub_to_csr_data,

         // exception
         output wire [1:0] flush,
         // ertn
         output wire is_ertn,

         // 握手信号
         input up_valid,
         output waite_ready_o,

         // tlb
         input wire [4:0] tlb_inst_bus,
         // tlbsrch
         input wire[$clog2(TLBNUM)-1:0]     tlbsrch_index,
         input wire                         tlbsrch_found,
         // tlbrd
         input wire [31:0]       tlbehi_in,
         input wire [31:0]       tlbelo0_in,
         input wire [31:0]       tlbelo1_in,
         input wire [31:0]       tlbidx_in,
         // to csr
         output  wire        tlbsrch_en,
         output  wire        tlbsrch_found_o,
         output  wire [5:0]  tlbsrch_index_o,
         // tlbrd
         output wire tlbrd_en,
         output  wire [31:0] tlbehi_o,
         output  wire [31:0] tlbelo0_o,
         output  wire [31:0] tlbelo1_o,
         output  wire [31:0] tlbidx_o1
     );

    wire excp_flush;
    wire ertn_flush;
    assign flush = {excp_flush, ertn_flush};

    // to_csr
    wire csr_we;
    wire [13:0] csr_addr;
    wire [31:0] csr_wdata;
    wire [31:0] csr_era;
    wire [5:0] csr_ecode;
    wire [31:0] bad_va;
    wire [8:0] csr_esubcode;
    wire va_error;
    wire excp_tlbrefill;
    wire excp_tlb;
    wire [18:0] excp_tlb_vppn;

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
    wire wbu_over;

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

    // tlb
    reg [4:0] tlb_inst_bus_r;
    wire wire_inst_tlbsrch;
    wire wire_inst_tlbrd;
    wire wire_inst_tlbwr;
    wire wire_inst_tlbfill;
    wire wire_inst_invtlb;
    assign {
            wire_inst_tlbsrch,
            wire_inst_tlbrd,
            wire_inst_tlbwr,
            wire_inst_tlbfill,
            wire_inst_invtlb
        } = tlb_inst_bus_r;

    // 这里为了不重复发射寄存器写信号，采用如下的策略
    // 每次对 4?(2其实就行了，difftest 过了后可以将 difftest 的信号全部去掉) 元组进行获取，如果检测到和上次发生变化，则将标记置 1
    reg [31:0] last_pc;
    reg [4:0] last_waddr;
    reg [31:0] last_wdata;
    wire is_same;
    // assign is_same = last_pc == pc && last_wdata == rf_wdata && last_waddr == rf_waddr; // 条件太过严格？
    assign is_same = last_pc == pc && last_waddr == rf_waddr; // 只要 pc、rf_waddr 一致，就不再重复写

    reg [1:0] wbu_state;
    reg [$clog2(TLBNUM)-1:0] tlbsrch_index_r;
    reg tlbsrch_found_r;
    reg [31:0] tlbehi_in_r;
    reg [31:0] tlbelo0_in_r;
    reg [31:0] tlbelo1_in_r;
    reg [31:0] tlbidx_in_r;
    always @(posedge clk) begin
        last_pc <= pc;
        last_waddr <= rf_waddr;
        last_wdata <= rf_wdata;
        if (rst || flush_sign) begin
            wbu_state <= 2'd0;
            // tlbsrch
            tlbsrch_index_r <= 6'd0;
            tlbsrch_found_r <= 1'b0;
            // tlbrd
            tlbehi_in_r <= 32'd0;
            tlbelo0_in_r <= 32'd0;
            tlbelo1_in_r <= 32'd0;
            tlbidx_in_r <= 32'd0;
        end
        else if (wbu_state == 2'd0 && up_valid) begin
            bus_mem_to_wbu_data_r <= bus_mem_to_wbu_data;
            ms_excp_num_r <= ms_excp_num;
            ms_excp_r <= ms_excp;
            wbu_state <= 2'd1;
            // tlbsrch
            tlbsrch_index_r <= tlbsrch_index;
            tlbsrch_found_r <= tlbsrch_found;
            // tlbrd
            tlbehi_in_r <= tlbehi_in;
            tlbelo0_in_r <= tlbelo0_in;
            tlbelo1_in_r <= tlbelo1_in;
            tlbidx_in_r <= tlbidx_in;

        end
        else if(wbu_state == 2'd1) begin
            wbu_state <= 2'd0;
        end
    end

    wire ws_valid;
    assign ws_valid = wbu_state == 2'd1;
    assign waite_ready_o = wbu_state == 2'd0 ? 1'b1 : 1'b0;
    assign wbu_over = wbu_state == 2'd0;

    // 输出到 regfile
    assign rf_we    = wire_gr_we & ws_valid & !ws_excp && !is_same;
    assign rf_waddr = wire_dest;
    assign rf_wdata = wire_final_result;
    assign pc       = wire_pc;

    // 输出到 csr
    assign csr_we = wire_csr_we & ws_valid & !ws_excp;
    assign csr_addr = wire_csr_idx;
    assign csr_wdata = wire_csr_wdata;

    // tlb
    // tlbsrch
    assign tlbsrch_en = wire_inst_tlbsrch & ws_valid & !ws_excp;
    assign tlbsrch_found_o = tlbsrch_found_r;
    assign tlbsrch_index_o = tlbsrch_index_r;
    // tlbrd
    assign tlbrd_en = wire_inst_tlbrd & ws_valid & !ws_excp;
    assign tlbehi_o = tlbehi_in_r;
    assign tlbelo0_o = tlbelo0_in_r;
    assign tlbelo1_o = tlbelo1_in_r;
    assign tlbidx_o1 = tlbidx_in_r;
    
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
               wbu_csr_wdata,
               wbu_over
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

    // 信号发射到下游
    assign bus_wub_to_csr_data = {
               csr_we,
               csr_addr,
               csr_wdata,
               csr_ecode,
               va_error,
               bad_va,
               csr_esubcode,
               excp_tlbrefill,
               excp_tlb,
               excp_tlb_vppn,
               csr_era};

endmodule
