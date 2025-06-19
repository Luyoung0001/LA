`include "csr.h"
module WBU
    #(
         parameter TLBNUM = 16
     )
     (
         // from mem
         input wire clk,
         input wire rst,

         input wire [149:0] bus_mem_to_wbu_data,
         input wire [31:0] pc_pro_i,
         input wire [31:0] inst_data_i,

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
         input  wire up_valid,
         output wire waite_ready_o,

         // tlb
         input wire [4:0] tlb_inst_bus,
         // from csr
         input wire [31:0] csr_tlbidx,
         input wire [31:0] csr_tlbehi,
         input wire [31:0] csr_tlbelo0,
         input wire [31:0] csr_tlbelo1,
         input wire [$clog2(TLBNUM)-1:0]  csr_rand_index,
         input wire [9:0]  csr_asid,
         input wire [5:0] csr_ecode_i,
         // tlbsrch
         output  wire                          tlbsrch_en,
         input   wire [$clog2(TLBNUM)-1:0]     tlbsrch_index,
         input   wire                          tlbsrch_found,
         output  wire                          tlbsrch_found_o,
         output  wire [$clog2(TLBNUM)-1:0]     tlbsrch_index_o,

         // tlbrd
         output wire [31:0]     to_trans_tlbidx_o, // 发射给 trans 模块
         input wire  [31:0]     from_trans_tlbehi_in, // 来自 tlb
         input wire  [31:0]     from_trans_tlbelo0_in,
         input wire  [31:0]     from_trans_tlbelo1_in,
         input wire  [31:0]     from_trans_tlbidx_in,
         input wire  [9:0]      from_trans_asid_in,

         output  wire         csr_tlbrd_en_o, // 发射到 csr
         output  wire [31:0]  csr_tlbehi_o,
         output  wire [31:0]  csr_tlbelo0_o,
         output  wire [31:0]  csr_tlbelo1_o,
         output  wire [31:0]  csr_tlbidx_o,
         output  wire [9:0]   csr_asid_o,
         // tlbwr
         output wire        tlbwr_en_o,
         output wire [9:0]  tlbwr_fill_w_asid_o,
         output wire [31:0] tlbwr_fill_tlbehi_o,
         output wire [31:0] tlbwr_fill_tlbelo0_o,
         output wire [31:0] tlbwr_fill_tlbelo1_o,
         output wire [31:0] tlbwr_fill_tlbidx_o,
         output wire [5:0]  tlbwr_fill_ecode_o, // tlbwr tlbfill

         // tlbfill
         output wire  tlbfill_en_o,
         output wire  [$clog2(TLBNUM)-1:0] rand_index_o,
         // invtlb
         input wire   [4:0]       invtlb_op_i,
         input wire   [9:0]       invtlb_asid_i,
         input wire   [18:0]      invtlb_vpn_i,
         output wire  [4:0]       invtlb_op_o,
         output wire  [9:0]       invtlb_asid_o,
         output wire  [18:0]      invtlb_vpn_o,
         output wire              invtlb_en_o,
         // debug
         output wire [31:0] inst_data_o,
         input  wire        is_csr_wr_i,
         output wire        is_csr_wr_o,
         output wire        has_refetch_excp_o,
         // refetch_sign
         output wire        is_refetch_sign,
         input  wire        refetch_excp_i,
         // 发射新的PC
         output wire [31:0] refetch_pc,
         output wire        refetch_sign,
         output wire        refetch_flush,

         output wire        excp_tlbrefill_o
     );

    // for debug
    reg is_csr_wr_i_r;

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
    reg [31:0] inst_data_i_r;
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

    reg [1:0] wbu_state;
    reg [3:0] tlbsrch_index_r;
    reg tlbsrch_found_r;

    reg [4:0] invtlb_op_i_r;
    reg [9:0] invtlb_asid_i_r;
    reg [18:0] invtlb_vpn_i_r;

    reg refetch_excp_i_r;

    reg [31:0] pc_pro_i_r;




    always @(posedge clk) begin
        if (rst || flush_sign) begin
            bus_mem_to_wbu_data_r <= 150'd0;
            inst_data_i_r <= 32'd0;
            wbu_state <= 2'd0;
            tlb_inst_bus_r <= 5'd0;
            // tlbsrch
            tlbsrch_index_r <= 4'd0;
            tlbsrch_found_r <= 1'b0;
            // invtlb
            invtlb_op_i_r <= 5'd0;
            invtlb_asid_i_r <= 10'd0;
            invtlb_vpn_i_r <= 19'd0;

            is_csr_wr_i_r <= 1'b0;

            refetch_excp_i_r <= 1'b0;

        end
        else if (wbu_state == 2'd0 && up_valid) begin
            bus_mem_to_wbu_data_r <= bus_mem_to_wbu_data;
            inst_data_i_r <= inst_data_i;
            ms_excp_num_r <= ms_excp_num;
            ms_excp_r <= ms_excp;
            wbu_state <= 2'd1;
            tlb_inst_bus_r <= tlb_inst_bus;
            // tlbsrch
            tlbsrch_index_r <= tlbsrch_index;
            tlbsrch_found_r <= tlbsrch_found;
            // invtlb
            invtlb_op_i_r <= invtlb_op_i;
            invtlb_asid_i_r <= invtlb_asid_i;
            invtlb_vpn_i_r <= invtlb_vpn_i;

            // debug
            is_csr_wr_i_r <= is_csr_wr_i;

            refetch_excp_i_r <= refetch_excp_i;

            pc_pro_i_r <= pc_pro_i;

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
    assign rf_we    = wire_gr_we & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign rf_waddr = wire_dest;
    assign rf_wdata = wire_final_result;
    assign pc       = wire_pc;

    // 输出到 csr
    assign csr_we = wire_csr_we & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign csr_addr = wire_csr_idx;
    assign csr_wdata = wire_csr_wdata;

    // tlb
    // tlbsrch
    assign tlbsrch_en = wire_inst_tlbsrch & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign tlbsrch_found_o = tlbsrch_found_r;
    assign tlbsrch_index_o = tlbsrch_index_r;
    // tlbrd
    assign to_trans_tlbidx_o = csr_tlbidx;
    assign csr_tlbrd_en_o = wire_inst_tlbrd & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign csr_tlbehi_o = from_trans_tlbehi_in;
    assign csr_tlbelo0_o = from_trans_tlbelo0_in;
    assign csr_tlbelo1_o = from_trans_tlbelo1_in;
    assign csr_tlbidx_o = from_trans_tlbidx_in;
    assign csr_asid_o = from_trans_asid_in;
    // tlbwr tlbfill
    assign tlbwr_en_o = wire_inst_tlbwr & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign tlbwr_fill_tlbehi_o = csr_tlbehi;
    assign tlbwr_fill_tlbelo0_o = csr_tlbelo0;
    assign tlbwr_fill_tlbelo1_o = csr_tlbelo1;
    assign tlbwr_fill_tlbidx_o = csr_tlbidx;
    assign tlbwr_fill_ecode_o = csr_ecode_i;
    assign tlbwr_fill_w_asid_o = csr_asid;

    assign tlbfill_en_o = wire_inst_tlbfill & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign rand_index_o = csr_rand_index;
    // invtlb
    assign invtlb_en_o = wire_inst_invtlb & ws_valid & !ws_excp && !refetch_excp_i_r;
    assign invtlb_op_o = invtlb_op_i_r;
    assign invtlb_asid_o = invtlb_asid_i_r;
    assign invtlb_vpn_o = invtlb_vpn_i_r;


    assign ertn_flush = wire_is_inst_ertn & ws_valid & !ws_excp; // 保持一个周期

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

    assign excp_flush = ws_excp & ws_valid; // 保持一个周期
    assign flush_sign = excp_flush || ertn_flush || refetch_flush;

    assign is_ertn = wire_is_inst_ertn;
    assign csr_era = wire_pc;

    // 约定
    // adef:0
    // fs_tlbr:1
    // fs_pif:2
    // fs_ppi:3
    // syscall:4
    // ine:5
    // brk:6
    // ie:7
    // ipe:8
    // ale:9
    // exu_tlbr:10
    // exu_pil:11
    // exu_pis:12
    // exu_ppi:13
    // exu_pme:14


    // 检测异常
    assign {csr_ecode,
            va_error,
            bad_va,
            csr_esubcode,
            excp_tlbrefill,
            excp_tlb,
            excp_tlb_vppn} =
           ws_excp_num[7] ? {`ECODE_INT , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0}:
           ws_excp_num[0] ? {`ECODE_ADEF, ws_valid, wire_pc, `ESUBCODE_ADEF, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[1] ? {`ECODE_TLBR, ws_valid, wire_pc, 9'b0, ws_valid, ws_valid, wire_pc[31:13]} :
           ws_excp_num[2] ? {`ECODE_PIF , ws_valid, wire_pc, 9'b0, 1'b0, ws_valid, wire_pc[31:13]} :
           ws_excp_num[3] ? {`ECODE_PPI , ws_valid, wire_pc, 9'b0, 1'b0, ws_valid, wire_pc[31:13]} :
           ws_excp_num[4] ? {`ECODE_SYS, 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0}:
           ws_excp_num[6] ? {`ECODE_BRK , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[5] ? {`ECODE_INE , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[8] ? {`ECODE_IPE , 1'b0, 32'b0, 9'b0, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[9] ? {`ECODE_ALE , ws_valid, wire_error_va, 9'b0, 1'b0, 1'b0, 19'b0} :
           ws_excp_num[10] ? {`ECODE_TLBR, ws_valid, wire_error_va, 9'b0, ws_valid, ws_valid, wire_error_va[31:13]} :
           ws_excp_num[14] ? {`ECODE_PME , ws_valid, wire_error_va, 9'b0, 1'b0, ws_valid, wire_error_va[31:13]} :
           ws_excp_num[13] ? {`ECODE_PPI , ws_valid, wire_error_va, 9'b0, 1'b0, ws_valid, wire_error_va[31:13]} :
           ws_excp_num[12] ? {`ECODE_PIS , ws_valid, wire_error_va, 9'b0, 1'b0, ws_valid, wire_error_va[31:13]} :
           ws_excp_num[11] ? {`ECODE_PIL , ws_valid, wire_error_va, 9'b0, 1'b0, ws_valid, wire_error_va[31:13]} :
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


    assign inst_data_o = inst_data_i_r;

    assign is_csr_wr_o = is_csr_wr_i_r;

    // 这里发出 refetch_sign 信号，这里的保持时间要注意，保持整个周期，以便于上游模块设置"异常"
    // 接收到这个信号的上游所有模块的所有指令都会被打上一个重取标记
    // 这个标记带给各个模块的效果和异常一样，都会取消各自的执行效果
    // 当带有重取标记的指令到达 WBU 的时候，直接清空流水线
    // 此时，pre_IFU 会拿到这个指令的 PC 信号，重新取址

    assign is_refetch_sign = (wire_inst_invtlb ||
                              wire_inst_tlbrd ||
                              wire_inst_tlbwr ||
                              wire_inst_tlbfill || wire_csr_we) && !refetch_excp_i_r;

    assign refetch_pc = pc_pro_i_r;
    assign refetch_sign = refetch_excp_i_r;

    assign has_refetch_excp_o = refetch_excp_i_r;

    assign refetch_flush = refetch_excp_i_r && !ws_excp && !ertn_flush; // 保持一个周期???

    assign excp_tlbrefill_o = excp_tlbrefill;
endmodule
