`include "csr.h"
module EXU
    #(
         parameter TLBNUM = 32
     )
     (
         input wire clk,
         input wire rst,

         input wire ds_excp,
         input wire [15:0] ds_excp_num,
         output wire es_excp_out,
         output wire [15:0] es_excp_num_out,

         // bus
         input wire [226:0] bus_ds_to_es_data,
         input wire [31:0]  inst_data_i,
         output wire [31:0] inst_data_o,
         output wire [150:0] bus_exu_to_mem_data,

         input wire [9:0] in_mem_op,
         output wire [9:0] out_mem_op,

         output wire [70:0] bus_exu_bypass_data,
         // exception
         input wire [1:0] flush,
         input wire mem_excp,
         output wire exu_excp, // 发射到上游的异常信号
         input wire mem_in_is_ertn,
         output wire exu_is_ertn,

         // 握手信号
         input up_valid,
         output state_valid,
         input waite_ready_i,
         output waite_ready_o,

         // tlb
         input wire [4:0] tlb_inst_bus, // 关于 tlb 的指令
         output wire [4:0] tlb_inst_bus_o,

         // 下游访存需要的信号
         output wire [31:0] alu_result_o,
         output wire [31:0] wire_in_rkd_value_o,

         //  for invtlb
         input wire [4:0]       invtlb_op_i,
         input wire [9:0]       invtlb_asid_i,
         input wire [18:0]      invtlb_vpn_i,

         output wire [4:0]      invtlb_op_o,
         output wire [9:0]      invtlb_asid_o,
         output wire [18:0]     invtlb_vpn_o,


         input wire is_csr_wr_i,
         output wire is_csr_wr_o,

         // from WBU
         input wire wbu_refetch_sign_i,
         input wire refetch_excp_i,
         output wire refetch_excp_o,


         input [31:0] pc_pro_i,
         output [31:0] pc_pro_o,

         input wbu_refetch_flush,
         input [82:0] bus_csr_rd_wr_data_i,
         output [82:0] bus_csr_rd_wr_data_o,

         output wire es_to_ds_valid,

         input wire csr_rstat_i,
         output wire csr_rstat_o,

         input  wire after_br_invalid_i,
         output wire after_br_invalid_o,

         input wire inst_idle_i,
         output wire inst_idle_o,

         input wire idle_flush,


         // cacop，执行动作就应该放在 MEM 阶段
         input  wire cacop_i,
         output wire cacop_o,

         input wire icacop_flush_i
     );
    reg cacop_i_r;


    reg inst_idle_i_r;
    reg csr_rstat_i_r;
    reg [82:0] bus_csr_rd_wr_data_i_r;
    reg is_csr_wr_i_r;
    wire excp_flush;
    wire ertn_flush;
    assign {excp_flush, ertn_flush} = flush;

    reg after_br_invalid_i_r;

    reg refetch_excp_i_r;

    // 异常信号
    reg [15:0] ds_excp_num_r; // 从上一级接收
    reg ds_excp_r;

    wire [31:0] error_va ;

    // 数据相关
    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;
    wire exu_over;


    reg [226:0] ds_to_es_bus_data_r;
    reg [31:0] inst_data_i_r;

    reg [9:0] mem_op_reg;

    wire [9:0] mul_div_op;
    wire [31:0] wire_alu_op;
    wire [31:0] wire_alu_src1;
    wire [31:0] wire_alu_src2;

    wire wire_in_mem_we;
    wire [31:0] wire_in_rkd_value;
    wire wire_in_res_from_mem;

    wire wire_in_gr_we;
    wire [4:0] wire_in_dest;
    wire [31:0] wire_in_pc;

    wire res_from_csr;
    wire [31:0] wire_csr_data;
    wire wire_csr_we;
    wire [13:0] wire_csr_idx;
    wire [31:0] wire_csr_wdata;
    wire wire_is_inst_ertn;

    wire res_from_mem;
    wire [31:0] exu_result;
    wire gr_we;
    wire [4:0] dest;
    wire [31:0] pc;

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

    assign exu_excp = es_excp | mem_excp; // 收集下游的信号，向上传递
    assign exu_is_ertn = wire_is_inst_ertn | mem_in_is_ertn;

    wire flush_sign;
    assign flush_sign = ertn_flush || excp_flush || wbu_refetch_flush || icacop_flush_i;

    // 遇见这些信号不能产生任何执行效果
    wire stop_signal;
    assign stop_signal = es_excp || mem_excp || flush_sign || mem_in_is_ertn || refetch_excp_i_r;

    assign {
            mul_div_op,
            wire_alu_op,
            wire_alu_src1,
            wire_alu_src2,

            wire_in_mem_we,
            wire_in_rkd_value,
            wire_in_res_from_mem,

            wire_in_gr_we,
            wire_in_dest,
            res_from_csr,
            wire_csr_data,
            wire_csr_we,
            wire_csr_idx,
            wire_csr_wdata,
            wire_is_inst_ertn
        } = ds_to_es_bus_data_r;


    assign wire_in_pc = pc_pro_i_r;

    assign bus_exu_to_mem_data = {
               res_from_mem,
               exu_result,
               gr_we,
               dest,
               pc,
               wire_csr_we,
               wire_csr_idx,
               wire_csr_wdata,
               wire_is_inst_ertn,
               error_va
           };


    assign res_from_mem = wire_in_res_from_mem;

    wire [31:0] alu_result;
    alu u_alu(
            .alu_op     (wire_alu_op    ),
            .alu_src1   (wire_alu_src1  ),
            .alu_src2   (wire_alu_src2  ),
            .alu_result (alu_result)
        );
    assign error_va = alu_result;

    // 解决数据相关
    // 如果这是读取 csr 的指令，此时要写入 csr 的数据并没有被读出来
    // 因此这里遇到寄存器读的指令，exu_regWr 无效
    assign exu_regWr = gr_we && !res_from_csr;
    assign exu_data = exu_result;
    assign exu_regAddr = wire_in_dest;

    wire [31:0] exu_pc = pc_pro_i_r;
    assign bus_exu_bypass_data = {
               exu_regWr,
               exu_data,
               exu_regAddr,
               exu_pc,
               exu_over
           };

    // 乘除法
    wire op_div;   //signed divide operation low
    wire op_divu;  //unsigned divide operation low
    wire op_mod;   //signed mod operation low
    wire op_modu;  //unsigned mod operation low


    assign op_div  = mul_div_op[3];
    assign op_divu = mul_div_op[4];
    assign op_mod  = mul_div_op[5];
    assign op_modu = mul_div_op[6];


    reg [1:0] exu_state;
    reg [31:0] reg_rdata;

    wire div;
    wire div_signed;
    assign div = op_div || op_divu || op_mod || op_modu;
    assign div_signed = op_div || op_mod;


    // 乘法器
    wire [31:0] mul_result;
    mul mul(
            .mul_div_op(mul_div_op),
            .alu_src1(wire_alu_src1),
            .alu_src2(wire_alu_src2),
            .mul_result(mul_result)
        );

    // 除法器
    wire [31:0] div_result;
    wire [31:0] mod_result;
    wire wire_complete;
    // 适当的时机撤销除法信号
    wire do_div;
    assign do_div = div && exu_state == 2'd1 && !wire_complete;
    divider divider(
                .div_clk(clk),
                .reset(rst),
                .div(do_div),
                .div_signed (div_signed),
                .x(wire_alu_src1),
                .y(wire_alu_src2),
                .s(div_result),
                .r(mod_result),
                .complete(wire_complete)
            );

    // 对结果进行汇总
    assign exu_result =
           op_div || op_divu ? div_result :
           op_mod || op_modu ? mod_result :
           mul_div_op[0] || mul_div_op[1] || mul_div_op[2] ? mul_result :
           wire_alu_op[0] ||
           wire_alu_op[1] ||
           wire_alu_op[2] ||
           wire_alu_op[3] ||
           wire_alu_op[4] ||
           wire_alu_op[5] ||
           wire_alu_op[6] ||
           wire_alu_op[7] ||
           wire_alu_op[8] ||
           wire_alu_op[9] ||
           wire_alu_op[10] ||
           wire_alu_op[11] ? alu_result:
           alu_result;

    // 是否访存
    // 握手信号
    assign gr_we = wire_in_gr_we;
    assign dest = wire_in_dest;
    assign pc = wire_in_pc;

    reg [4:0] invtlb_op_i_r;
    reg [9:0] invtlb_asid_i_r;
    reg [18:0] invtlb_vpn_i_r;
    reg [31:0] pc_pro_i_r;

    always @(posedge clk) begin
        if (rst || flush_sign) begin
            exu_state <= 2'd0;
            ds_to_es_bus_data_r <= 227'd0;
            inst_data_i_r <= 32'd0;
            mem_op_reg <= 10'd0;
            ds_excp_num_r <= 16'd0;
            ds_excp_r <= 1'b0;
            // tlb
            tlb_inst_bus_r <= 5'd0;
            // invtlb
            invtlb_op_i_r <= 5'd0;
            invtlb_asid_i_r <= 10'd0;
            invtlb_vpn_i_r <= 19'd0;

            is_csr_wr_i_r <= 1'b0;

            refetch_excp_i_r <= 1'b0;

            bus_csr_rd_wr_data_i_r <= 83'd0;


            csr_rstat_i_r <= 1'b0;

            after_br_invalid_i_r <= 1'b0;
            inst_idle_i_r <= 1'b0;


            cacop_i_r <= 1'b0;

        end
        else if (exu_state == 2'd0 && up_valid) begin
            ds_to_es_bus_data_r <= bus_ds_to_es_data;
            mem_op_reg <= in_mem_op;
            ds_excp_num_r <= ds_excp_num;
            inst_data_i_r <= inst_data_i;
            ds_excp_r <= ds_excp;
            exu_state <= 2'd1;
            // tlb
            tlb_inst_bus_r <= tlb_inst_bus;
            // invtlb
            invtlb_op_i_r <= invtlb_op_i;
            invtlb_asid_i_r <= invtlb_asid_i;
            invtlb_vpn_i_r <= invtlb_vpn_i;

            is_csr_wr_i_r <= is_csr_wr_i;

            refetch_excp_i_r <= wbu_refetch_sign_i | refetch_excp_i;

            pc_pro_i_r <= pc_pro_i;

            bus_csr_rd_wr_data_i_r <= bus_csr_rd_wr_data_i;

            csr_rstat_i_r <= csr_rstat_i;

            after_br_invalid_i_r <= after_br_invalid_i;
            inst_idle_i_r <= inst_idle_i;

            cacop_i_r <= cacop_i;

        end
        // 这里要处理，进入处理阶段
        else if(exu_state == 2'd1) begin
            if(stop_signal) begin
                exu_state <= waite_ready_i ? 2'd0 : 2'd1;
            end
            else if(div) begin
                exu_state <= wire_complete ? 2'd2 : 2'd1;
            end
            else begin
                // 否则处理完成
                exu_state <= 2'd2;
            end
        end
        else if(exu_state == 2'd2) begin
            if (waite_ready_i) begin
                exu_state <= 2'd0;
            end
        end
    end

    assign state_valid = exu_state == 2'd1 ? (stop_signal == 1'b1 ? 1'b1: (div ? wire_complete : 1'b1)):1'b0;

    assign waite_ready_o = idle_flush ? 1'b0: (exu_state == 2'd0);
    assign exu_over = exu_state == 2'b0;

    wire [15:0] wire_ds_excp_num = ds_excp_num_r;
    wire wire_ds_excp = ds_excp_r;

    wire [15:0] es_excp_num = wire_ds_excp_num;
    wire es_excp = wire_ds_excp;

    // 输出
    assign es_excp_out = es_excp;
    assign es_excp_num_out = es_excp_num;

    assign wire_in_rkd_value_o = wire_in_rkd_value;
    assign alu_result_o = alu_result;

    // for invtlb
    assign invtlb_op_o = invtlb_op_i_r;
    assign invtlb_asid_o = invtlb_asid_i_r;
    assign invtlb_vpn_o = invtlb_vpn_i_r;

    assign tlb_inst_bus_o = tlb_inst_bus_r;

    assign inst_data_o = inst_data_i_r;

    assign is_csr_wr_o = is_csr_wr_i_r;

    assign refetch_excp_o = refetch_excp_i_r;

    assign pc_pro_o = pc_pro_i_r;

    assign bus_csr_rd_wr_data_o = bus_csr_rd_wr_data_i_r;

    assign es_to_ds_valid = state_valid;

    assign csr_rstat_o = csr_rstat_i_r;

    assign after_br_invalid_o = after_br_invalid_i_r;
    assign inst_idle_o = inst_idle_i_r;

    assign out_mem_op = mem_op_reg;


    assign cacop_o = cacop_i_r;

endmodule
