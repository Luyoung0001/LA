`include "csr.h"
module EXU
    #(
         parameter TLBNUM = 16
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
         input wire [31:0] inst_data_i,
         output wire [31:0] inst_data_o,
         output wire [150:0] bus_exu_to_mem_data,

         input wire [9:0] in_mem_op,

         output wire req, //
         output wr,   // |we
         output [1:0] size, // 新增
         output [3:0] wstrb, // we
         output wire [31:0] addr,
         output [31:0] wdata,
         input addr_ok, // 新增
         input data_ok,
         input [31:0] rdata,

         output wire [31:0] rdata_o,

         output wire [85:0] bus_exu_bypass_data,
         output wire [9:0] out_mem_op,
         output wire [3:0] out_mem_mask,


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
         input wire [4:0] tlb_inst_bus,
         output wire [4:0] tlb_inst_bus_o,

         // from csr
         input wire [1:0]  csr_plv,
         input wire [31:0] csr_dmw0,
         input wire [31:0] csr_dmw1,
         input wire        csr_da,
         input wire        csr_pg,
         input wire [31:0] csr_tlbidx,
         input wire [31:0] csr_tlbehi,
         input wire [31:0] csr_tlbelo0,
         input wire [31:0] csr_tlbelo1,
         input wire [18:0] csr_vppn,
         input wire [9:0]  csr_asid,
         input             ds_llbit,

         // from or to addr_trans
         // for tlbsrch and access mem
         output wire           data_addr_trans_en,
         output wire [9:0]     data_asid,
         output wire [31:0]    data_vaddr,
         output wire           data_dmw0_en,
         output wire           data_dmw1_en,
         output wire [31:0]    data_dmw0,
         output wire [31:0]    data_dmw1,
         output wire           data_da,
         output wire           data_pg,

         input wire  [ 7:0]    data_index,
         input wire  [19:0]    data_tag,
         input wire  [ 3:0]    data_offset,

         input wire            data_tlb_found,
         input wire  [$clog2(TLBNUM)-1:0]     data_tlb_index,

         input wire            data_tlb_v,
         input wire            data_tlb_d,
         input wire  [1:0]     data_tlb_mat,
         input wire  [1:0]     data_tlb_plv,

         // for tlbsrch
         output wire[$clog2(TLBNUM)-1:0]  tlbsrch_index,
         output wire           tlbsrch_found,
         // for invtlb
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

         output wire [31:0] paddr,

         input  [27:0]     lladdr,

         output wire es_to_ds_valid
     );

    reg [82:0] bus_csr_rd_wr_data_i_r;
    reg is_csr_wr_i_r;
    wire excp_flush;
    wire ertn_flush;
    assign {excp_flush, ertn_flush} = flush;

    // 异常信号
    reg [15:0] ds_excp_num_r; // 从上一级接收
    reg ds_excp_r;

    // 地址非对齐
    wire excp_ale;
    wire [15:0] excp_ale_num;
    // TLB重填异常
    wire exu_excp_tlbr;
    wire [15:0] excp_tlbr_num;
    // load 操作页无效异常
    wire exu_excp_pil;
    wire [15:0] excp_pil_num;
    // store 操作页无效异常
    wire exu_excp_pis;
    wire [15:0] excp_pis_num;
    // 页特权异常
    wire exu_excp_ppi;
    wire [15:0] excp_ppi_num;
    // 页修改例外
    wire exu_excp_pme;
    wire [15:0] excp_pme_num;

    wire [31:0] pv_addr ;
    wire [31:0] error_va ;

    // 数据相关
    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;
    wire exu_over;

    wire exu_csr_we;
    wire [13:0] exu_csr_idx;
    wire [31:0] exu_csr_wdata;

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

    wire flush_sign = ertn_flush || excp_flush || wbu_refetch_flush;

    // 遇见这些信号不能产生任何执行效果
    wire stop_signal = es_excp || mem_excp || flush_sign || mem_in_is_ertn;

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
            // wire_in_pc,
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
    // 同时，将错误地址传递到下游
    assign pv_addr = alu_result;
    assign error_va = pv_addr;

    // 解决数据相关
    // 如果这是读取 csr 的指令，此时要写入 csr 的数据并没有被读出来
    // 因此这里遇到寄存器读的指令，exu_regWr 无效
    assign exu_regWr = gr_we && !res_from_csr;
    assign exu_data = exu_result;
    assign exu_regAddr = wire_in_dest;

    assign exu_csr_we = wire_csr_we;
    assign exu_csr_idx = wire_csr_idx;
    assign exu_csr_wdata = wire_csr_wdata;

    assign bus_exu_bypass_data = {
               exu_regWr,
               exu_data,
               exu_regAddr,
               exu_csr_we,
               exu_csr_idx,
               exu_csr_wdata,
               exu_over
           };

    // 提前发射访存信号，必须在 es 阶段有效
    // 写使能信号，根据地址生成

    wire [9:0] mem_op;
    assign mem_op = mem_op_reg;
    assign out_mem_op = mem_op_reg;


    wire st_b;
    wire st_h;
    wire st_w;
    wire ld_b;
    wire ld_bu;
    wire ld_h;
    wire ld_hu;
    wire ld_w;

    wire ll_w;
    wire sc_w;

    assign st_b = mem_op[0];
    assign st_h = mem_op[1];
    assign st_w = mem_op[2];

    assign ld_b = mem_op[3];
    assign ld_bu = mem_op[4];
    assign ld_h = mem_op[5];
    assign ld_hu = mem_op[6];
    assign ld_w = mem_op[7];
    assign ll_w = mem_op[8];
    assign sc_w = mem_op[9];


    wire [3:0] st_b_we;
    wire [3:0] st_h_we;
    wire [3:0] st_w_we;

    wire [3:0] ld_mask;

    assign out_mem_mask = ld_mask;

    assign ld_mask = (ld_b | ld_bu) && (alu_result[1:0] == 2'b00) ? 4'b0001 :
           (ld_b |ld_bu ) && (alu_result[1:0] == 2'b01) ? 4'b0010 :
           (ld_b | ld_bu) && (alu_result[1:0] == 2'b10) ? 4'b0100 :
           (ld_b | ld_bu) && (alu_result[1:0] == 2'b11) ? 4'b1000 :
           (ld_h | ld_hu)  && (alu_result[1:0] == 2'b00) ? 4'b0011 :
           (ld_h | ld_hu) && (alu_result[1:0] == 2'b10) ? 4'b1100 :
           (ld_w | ll_w) && (alu_result[1:0] == 2'b00) ? 4'b1111 :
           4'b0000;

    assign st_b_we = alu_result[1:0] == 2'b00 ? 4'b0001 :
           alu_result[1:0] == 2'b01 ? 4'b0010 :
           alu_result[1:0] == 2'b10 ? 4'b0100 :
           4'b1000;
    assign st_h_we = alu_result[1:0] == 2'b00 ? 4'b0011 :
           alu_result[1:0] == 2'b10 ? 4'b1100 :
           4'b0000;
    assign st_w_we = 4'b1111;

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

    wire [31:0] real_data;
    assign exu_result =
           sc_w ? {{31{1'b0}},1'b1}: // 如果是 sc，就看能否成功执行
           res_from_mem ? real_data :
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


    // sc 是否执行，如果执行了，就往 rd 中写 1
    wire sc_do;
    assign sc_do = (sc_w & ds_llbit && lladdr == paddr[31:4]);

    // 是否访存
    // 握手信号
    assign gr_we = wire_in_gr_we;
    assign dest = wire_in_dest;
    assign pc = wire_in_pc;
    // 访存信号
    assign size = ld_b || ld_bu || st_b ? 2'b00 :
           ld_h || ld_hu || st_h ? 2'b01 :
           st_w || ld_w || ll_w || sc_do ? 2'b10 : 2'b00;
    assign wr = (st_b || st_h || st_w || sc_do) ;

    assign wstrb = stop_signal ? 4'b0000 : // 异常
           st_b  ? st_b_we :
           st_h  ? st_h_we :
           st_w | sc_do  ? st_w_we :
           4'b0000 ;
    // assign req = 1'b0; // 默认信号
    // 写入
    assign wdata = st_b ? {4{wire_in_rkd_value[7:0]}} :
           st_h ? {2{wire_in_rkd_value[15:0]}} :
           st_w | sc_do ? wire_in_rkd_value : 32'b0;

    wire access_memo = ld_b || ld_bu || ld_h || ld_hu || ld_w ||
         st_b || st_h || st_w || ll_w || sc_do;

    reg [4:0] invtlb_op_i_r;
    reg [9:0] invtlb_asid_i_r;
    reg [18:0] invtlb_vpn_i_r;

    reg [31:0] pc_pro_i_r;

    reg refetch_excp_i_r;
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

        end
        // 这里要处理，进入处理阶段
        else if(exu_state == 2'd1) begin
            // 处理流程
            // 访存
            if(access_memo && !stop_signal) begin
                if(waite_ready_i && addr_ok) begin
                    // req <= 1'b1;
                    exu_state <= 2'd2; // 等待
                end
            end
            else if(stop_signal) begin
                exu_state <= 2'd0;
            end
            else if(wire_complete & div) begin
                exu_state <= 2'd0;
            end
            else if(div) begin
                // 继续保持这个状态等待
            end
            else begin
                // 否则处理完成
                exu_state <= 2'd0;
            end
        end

        else if (exu_state == 2'd2) begin
            if(data_ok) begin
                exu_state <= 2'd0;// 处理完成
                // reg_rdata <= rdata;
            end
        end
    end

    // real data
    // axi 返回的永远是 4 字节，因此这里会根据 size 以及地址生成最终的数据
    // offset[1:0] == 00 的时候：
    // size:0--->0001
    // size:1--->0011
    // size:2--->1111
    // offset[1:0] == 01 的时候：
    // size:0--->0010
    // offset[1:0] == 10 的时候：
    // size:0--->0100
    // size:1--->1100
    // offset[1:0] == 11 的时候：
    // size:0--->1000
    // 另外，这里还得考虑一下符号扩展
    assign real_data =
           (data_offset[1:0] == 2'b00) ? (
               (size == 2'b00) ? (
                   ld_b ? {{24{rdata[7]}},rdata[7:0]}: {24'b0, rdata[7:0]}):
               (size == 2'b01) ? (
                   ld_h ? {{16{rdata[15]}},rdata[15:0]} : {16'b0, rdata[15:0]}):
               rdata
           ) :
           (data_offset[1:0] == 2'b01) ? (
               ld_b ? {{24{rdata[15]}},rdata[15:8]}: {24'b0, rdata[15:8]}
           ) :
           (data_offset[1:0] == 2'b10) ? (
               (size == 2'b00) ? (
                   ld_b ? {{24{rdata[23]}},rdata[23:16]}: {24'b0, rdata[23:16]}):
               (size == 2'b01) ? (
                   ld_h ? {{16{rdata[31]}},rdata[31:16]} : {16'b0, rdata[31:16]}):
               rdata
           ) :
           (data_offset[1:0] == 2'b11) ? (
               ld_b ? {{24{rdata[31]}},rdata[31:24]}: {24'b0, rdata[31:24]}
           ) :
           rdata;  // 默认情况返回原始数据

    assign rdata_o = flush_sign ? 32'd0 : real_data;
    assign req = stop_signal ? 1'b0 : exu_state == 2'd1 && access_memo && waite_ready_i && !addr_ok;

    assign state_valid = (exu_state == 2'd1 &&  (wire_complete & div) ) ? 1'b1 : // 计算除法
           exu_state == 2'd2 && data_ok ? 1'b1 :  // 访存
           exu_state == 2'd1 && (!div) && (!access_memo) || stop_signal;

    assign waite_ready_o = exu_state == 2'b0 ? 1'b1 : 1'b0;
    assign exu_over = exu_state == 2'b0;

    // 异常===========================================================================

    // 检测地址是否自然对齐
    // 如果是 ld_h 或者 st_h，对齐到偶数地址
    // 如果是 ld_w 或者 st_w，对齐到4字节
    // 0x9
    assign excp_ale = (ld_h | ld_hu | st_h) && alu_result[0] ? 1'b1 :
           (ld_w | st_w) && (alu_result[1:0] != 2'b00) ? 1'b1 : 1'b0;
    assign excp_ale_num = excp_ale ? 16'h0200 :16'b0;
    // 0x10
    assign exu_excp_tlbr = access_memo && !data_tlb_found && data_addr_trans_en;
    assign excp_tlbr_num = exu_excp_tlbr ? 16'h0400 : 16'b0;
    // 0x11
    assign exu_excp_pil  = (ld_b | ld_bu | ld_h | ld_hu | ld_w) && !data_tlb_v && data_addr_trans_en;
    assign excp_pil_num = exu_excp_pil ? 16'h0800 : 16'b0;
    // 0x12
    assign exu_excp_pis  = (st_b | st_h | st_w) && !data_tlb_v && data_addr_trans_en;
    assign excp_pis_num = exu_excp_pis ? 16'h1000 : 16'b0;
    // 0x13
    assign exu_excp_ppi  = access_memo && data_tlb_v && (csr_plv > data_tlb_plv) && data_addr_trans_en;
    assign excp_ppi_num = exu_excp_ppi ? 16'h2000 : 16'b0;
    // 0x14
    assign exu_excp_pme  = (st_b | st_h | st_w) && data_tlb_v && (csr_plv <= data_tlb_plv) && !data_tlb_d && data_addr_trans_en;
    assign excp_pme_num = exu_excp_pme ? 16'h4000 : 16'b0;

    wire [15:0] wire_ds_excp_num = ds_excp_num_r;
    wire wire_ds_excp = ds_excp_r;

    wire [15:0] es_excp_num = wire_ds_excp_num | excp_ale_num |
         excp_tlbr_num | excp_pil_num | excp_pis_num |
         excp_ppi_num | excp_pme_num;

    wire es_excp = wire_ds_excp | excp_ale |
         exu_excp_tlbr | exu_excp_pil | exu_excp_pis |
         exu_excp_ppi | exu_excp_pme;

    // 输出
    assign es_excp_out = es_excp;
    assign es_excp_num_out = es_excp_num;

    // 异常===========================================================================

    // tlb
    // 窗口映射使能检查
    wire pg_mode;

    // 加上 tlb 之后，地址的意义发生了变化
    // 假设是 pg 映射模式，那么地址就得从 addr_trans 返回
    // 这里将会考虑数据前递技术解决数据相关
    assign data_vaddr = wire_inst_tlbsrch ? {csr_vppn,13'd0} : alu_result;
    assign data_asid = csr_asid;
    assign data_dmw0 = csr_dmw0;
    assign data_dmw1 = csr_dmw1;
    assign data_da = csr_da;
    assign data_pg = csr_pg;
    assign pg_mode = csr_pg && !csr_da;
    assign data_dmw0_en = ((data_dmw0[`PLV0] && csr_plv == 2'd0) || (data_dmw0[`PLV3] && csr_plv == 2'd3)) && (alu_result[31:29] == data_dmw0[`VSEG]) && pg_mode;
    assign data_dmw1_en = ((data_dmw1[`PLV0] && csr_plv == 2'd0) || (data_dmw1[`PLV3] && csr_plv == 2'd3)) && (alu_result[31:29] == data_dmw1[`VSEG]) && pg_mode;
    assign data_addr_trans_en = pg_mode && !data_dmw0_en && !data_dmw1_en;
    assign addr = {data_tag, data_index, data_offset}; // 物理地址

    // for tlbsrch
    assign tlbsrch_index = data_tlb_index;
    assign tlbsrch_found = data_tlb_found;

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

    assign paddr = {data_tag, error_va[11:0]};

    assign  es_to_ds_valid = state_valid;

endmodule
