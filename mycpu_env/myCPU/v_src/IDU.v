module IDU (
        // from top
        input wire clk,
        input wire rst,
        // to ifu
        output wire [33:0] bus_br_data,
        // from ifu
        input wire [31:0] in_pc,
        input wire [31:0] in_rdata,

        input wire fs_excp,
        input wire [15:0] fs_excp_num,
        output wire ds_excp_out,
        output wire [15:0] ds_excp_num_out,

        // to rf
        output wire [4:0] rf_raddr1,
        output wire [4:0] rf_raddr2,

        // from rf
        input wire [31:0] rf_rdata1,
        input wire [31:0] rf_rdata2,
        // bus
        output wire [226:0] bus_ds_to_es_data,
        output wire [31:0] idu_inst_o,
        output wire [7:0] out_mem_op,

        // csr
        output wire [13:0] rd_csr_addr,
        input  wire [31:0] rd_csr_data,
        input  wire [1:0]  csr_plv,
        //timer 64
        input [63:0] timer_64,
        input [31:0] csr_tid,
        // exception

        input wire [1:0] flush,
        input wire has_int,

        input wire exu_excp,
        input wire exu_is_ertn_i,

        // 直通解决数据相关
        input wire [85:0] bus_exu_bypass_data,
        input wire [85:0] bus_mem_bypass_data,
        input wire [85:0] bus_wbu_bypass_data,

        // csr 的数据相关
        // 握手信号
        input up_valid,
        output state_valid,
        input waite_ready_i,
        output waite_ready_o,
        // tlb
        output wire [4:0] tlb_inst_bus,
        // invtlb
        output wire [4:0] invtlb_op,
        output wire [9:0] invtlb_asid,
        output wire [18:0] invtlb_vpn,
        output wire is_csr_wr,

        // from WBU
        input wire wbu_refetch_sign_i,
        input wire refetch_excp_i,
        output wire refetch_excp_o,

        output [31:0] pc_pro_o, // PC 应该走专线

        input wbu_refetch_flush
    );

    wire excp_flush;
    wire ertn_flush;
    assign {excp_flush, ertn_flush} = flush;

    // 异常类型
    wire [15:0] syscall_num;    // 系统调用异常
    wire idu_excp_syacall;

    wire [15:0] excp_ine_num;   // 指令无效异常
    wire idu_excp_ine;

    wire [15:0] excp_brk_num;   // 断点异常
    wire idu_excp_brk;

    wire [15:0] excp_ie_num;    // 中断异常
    wire idu_excp_ie;

    wire [15:0] excp_ipe_num;   // 指令等级错例外
    wire idu_excp_ipe;

    wire excp_brk;
    wire inst_valid;

    reg [15:0] fs_excp_num_r; // 从上一级接收
    reg fs_excp_r;
    reg reg_condition_4;

    wire [15:0] wire_fs_excp_num;
    wire wire_fs_excp;

    assign wire_fs_excp_num = fs_excp_num_r;
    assign wire_fs_excp = fs_excp_r;

    wire [15:0] ds_excp_num;
    wire ds_excp;
    wire is_nop;

    wire caculate_done_1;
    wire caculate_done_2;

    wire caculate_done;



    wire flush_sign = ertn_flush || excp_flush || wbu_refetch_flush;

    // 数据相关

    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;
    wire exu_csr_we;
    wire [13:0] exu_csr_idx;
    wire [31:0] exu_csr_wdata;
    wire exu_over;

    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;
    wire mem_csr_we;
    wire [13:0] mem_csr_idx;
    wire [31:0] mem_csr_wdata;
    wire mem_over;

    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;
    wire wbu_csr_we;
    wire [13:0] wbu_csr_idx;
    wire [31:0] wbu_csr_wdata;
    wire wbu_over;

    assign {
            exu_regWr,
            exu_data,
            exu_regAddr,
            exu_csr_we,
            exu_csr_idx,
            exu_csr_wdata,
            exu_over
        } = bus_exu_bypass_data;
    assign {
            mem_regWr,
            mem_data,
            mem_regAddr,
            mem_csr_we,
            mem_csr_idx,
            mem_csr_wdata,
            mem_over
        } = bus_mem_bypass_data;
    assign {
            wbu_regWr,
            wbu_data,
            wbu_regAddr,
            wbu_csr_we,
            wbu_csr_idx,
            wbu_csr_wdata,
            wbu_over
        } = bus_wbu_bypass_data;


    wire [31:0] alu_op;
    wire [31:0] alu_src1;
    wire [31:0] alu_src2;

    wire [9:0]  mul_div_op;
    wire        mem_we;
    wire [31:0] rkd_value;
    wire        res_from_mem;
    wire        res_from_csr;
    wire        gr_we;
    wire [4:0]  dest;
    // wire [31:0] pc;
    // csr
    wire [13:0] csr_idx;    // csr 索引
    wire [31:0] csr_data;
    wire [31:0] csr_mask;
    wire [31:0] csr_wdata;  // 给 csr 中写的数据
    wire is_inst_ertn;
    wire csr_we;

    wire rdcnt_en;
    wire [31:0] rdcnt_result;

    wire [31:0] idu_inst;
    wire [31:0] idu_pc;
    wire        src1_is_pc;
    wire        src2_is_imm;
    wire        dst_is_r1;
    wire        dst_is_rj;
    wire        src_reg_is_rd;
    wire [31:0] rj_value;
    wire [31:0] imm;
    wire        rj_eq_rd;
    wire [31:0] br_offs;
    wire [31:0] jirl_offs;

    wire [ 5:0] op_31_26;
    wire [ 3:0] op_25_22;
    wire [ 1:0] op_21_20;
    wire [ 4:0] op_19_15;
    wire [ 4:0] rd;
    wire [ 4:0] rj;
    wire [ 4:0] rk;
    wire [11:0] i12;
    wire [19:0] i20;
    wire [15:0] i16;
    wire [25:0] i26;

    wire [63:0] op_31_26_d;
    wire [15:0] op_25_22_d;
    wire [ 3:0] op_21_20_d;
    wire [31:0] op_19_15_d;

    // csr
    wire [31:0] rd_d;
    wire [31:0] rj_d;
    wire [31:0] rk_d;

    wire        inst_add_w;
    wire        inst_sub_w;
    wire        inst_slt;
    wire        inst_slti;
    wire        inst_sltu;
    wire        inst_sltui;
    wire        inst_nor;
    wire        inst_and;
    wire        inst_andi;
    wire        inst_or;
    wire        inst_ori;
    wire        inst_xor;
    wire        inst_xori;
    wire        inst_sll;
    wire        inst_slli_w;
    wire        inst_srl;
    wire        inst_srli_w;
    wire        inst_sra;
    wire        inst_srai_w;
    wire        inst_addi_w;
    wire        inst_ld_w;
    wire        inst_ld_b;
    wire        inst_ld_bu;
    wire        inst_ld_h;
    wire        inst_ld_hu;
    wire        inst_st_w;
    wire        inst_st_b;
    wire        inst_st_h;
    wire        inst_jirl;
    wire        inst_b;
    wire        inst_bl;
    wire        inst_blt;
    wire        inst_bltu;
    wire        inst_beq;
    wire        inst_bne;
    wire        inst_bge;
    wire        inst_bgeu;
    wire        inst_lu12i_w;
    wire        inst_pcaddu12i;

    wire        inst_mul_w;
    wire        inst_mulh_w;
    wire        inst_mulh_wu;
    wire        inst_div_w;
    wire        inst_div_wu;
    wire        inst_mod_w;
    wire        inst_mod_wu;

    wire        inst_csrrd;
    wire        inst_csrwr;
    wire        inst_csrxchg;
    wire        inst_ertn;

    wire        inst_syscall;
    wire        inst_break;

    wire        inst_rdcntid_w;
    wire        inst_rdcntvl_w;
    wire        inst_rdcntvh_w;
    wire        inst_zero;

    wire        inst_tlbsrch;
    wire        inst_tlbrd;
    wire        inst_tlbwr;
    wire        inst_tlbfill;
    wire        inst_invtlb;


    wire        need_ui5;
    wire        need_si12;
    wire        need_si16;
    wire        need_si20;
    wire        need_si26;
    wire        src2_is_4;
    wire        need_ui12;


    wire br_taken;
    wire [31:0] br_target;

    assign bus_br_data = {br_taken, br_target, caculate_done};
    assign bus_ds_to_es_data = {
               mul_div_op,
               alu_op,
               alu_src1,
               alu_src2,
               mem_we,
               rkd_value,
               res_from_mem,
               gr_we,
               dest,
               //    idu_pc,
               res_from_csr,
               csr_data,
               csr_we,
               csr_idx,
               csr_wdata,
               is_inst_ertn
           };

    // 判断是否数据相关
    // 暂存上一级来的数据

    reg [31:0] inst_sram_rdata_reg;
    reg [31:0] pc_reg;
    wire [31:0] inst_nop_data = 32'b0000_0011_0100_0000_0000_0000_0000_0000; // nop : andi r0, r0,0
    reg [1:0] idu_state;

    assign caculate_done = caculate_done_1 && caculate_done_2;

    reg refetch_excp_i_r;

    always @(posedge clk ) begin
        if (rst || flush_sign) begin
            idu_state <= 2'd0;
            inst_sram_rdata_reg <= 32'd0;
            fs_excp_num_r <= 16'd0;
            fs_excp_r <= 1'b0;

            refetch_excp_i_r <= 1'b0;
        end
        // idle
        else if (idu_state == 2'd0 && up_valid) begin
            // 取出数据
            pc_reg <= br_taken ? pc_reg : in_pc;
            // 如果当前是跳转，那么下一条指令置 NOP
            inst_sram_rdata_reg <= br_taken ? inst_nop_data : in_rdata;
            fs_excp_num_r <= fs_excp_num;
            fs_excp_r <= fs_excp;
            idu_state <= 2'd1;
            refetch_excp_i_r <= wbu_refetch_sign_i | refetch_excp_i; // 记录是否需要重取
        end
        // waite_valid
        else if (idu_state == 2'd1 && caculate_done) begin
            // 等待数据相关稳定
            if(waite_ready_i) begin
                idu_state <= 2'd0;
            end
        end
    end

    assign state_valid = idu_state == 2'd1 && caculate_done;
    assign waite_ready_o = idu_state == 2'd0 ? 1'b1 : 1'b0;


    reg [31:0] conflict_regaData;
    reg [31:0] conflict_regbData;

    // 当检测到冲突以后，就得阻塞

    assign caculate_done_1 = exu_regWr &&
       (rf_raddr1 == exu_regAddr) && rf_raddr1 != 5'd0 ? exu_over ? 1'b1 : 1'b0:
           mem_regWr &&
       (rf_raddr1 == mem_regAddr) && rf_raddr1 != 5'd0 ? mem_over ? 1'b1 : 1'b0:
           wbu_regWr &&
       (rf_raddr1 == wbu_regAddr) && rf_raddr1 != 5'd0 ? wbu_over ? 1'b1 : 1'b0:
           1'b1;


    assign caculate_done_2 = exu_regWr &&
       (rf_raddr2 == exu_regAddr) && rf_raddr2 != 5'd0 ? exu_over ? 1'b1 : 1'b0:
           mem_regWr &&
       (rf_raddr2 == mem_regAddr) && rf_raddr2 != 5'd0 ? mem_over ? 1'b1 : 1'b0:
           wbu_regWr &&
       (rf_raddr2 == wbu_regAddr) && rf_raddr2 != 5'd0 ? wbu_over ? 1'b1 : 1'b0:
           1'b1;

    always @(*) begin
        if (exu_regWr && (rf_raddr1 == exu_regAddr) && rf_raddr1 != 5'd0) begin
            conflict_regaData = exu_data;
        end
        else if (mem_regWr && (rf_raddr1 == mem_regAddr)&& rf_raddr1 != 5'd0) begin
            conflict_regaData = mem_data;
        end
        else if (wbu_regWr && (rf_raddr1 == wbu_regAddr)&& rf_raddr1 != 5'd0) begin
            conflict_regaData = wbu_data;
        end
        else begin
            conflict_regaData = rf_rdata1;  // 默认值
        end
    end

    always @(*) begin
        if (exu_regWr && (rf_raddr2 == exu_regAddr)&& rf_raddr2 != 5'd0) begin
            conflict_regbData = exu_data;
        end
        else if (mem_regWr && (rf_raddr2 == mem_regAddr)&& rf_raddr2 != 5'd0) begin
            conflict_regbData = mem_data;
        end
        else if (wbu_regWr && (rf_raddr2 == wbu_regAddr)&& rf_raddr2 != 5'd0) begin
            conflict_regbData = wbu_data;
        end
        else begin
            conflict_regbData = rf_rdata2;  // 默认值
        end
    end



    assign idu_inst = inst_sram_rdata_reg;
    assign is_nop = (idu_inst == inst_nop_data) ? 1'b1 : 1'b0; // 当前指令是空指令信号，不要挂中断信号
    assign idu_pc = pc_reg;
    // assign pc = idu_pc;

    assign op_31_26  = idu_inst[31:26];
    assign op_25_22  = idu_inst[25:22];
    assign op_21_20  = idu_inst[21:20];
    assign op_19_15  = idu_inst[19:15];

    assign rd   = idu_inst[4:0];
    assign rj   = idu_inst[9:5];
    assign rk   = idu_inst[14:10];

    assign i12  = idu_inst[21:10];
    assign i20  = idu_inst[24:5];
    assign i16  = idu_inst[25:10];
    assign i26  = {idu_inst[9:
                            0], idu_inst[25:
                                         10]};

    // csr
    // 支持数据前递 tid
    assign csr_idx = inst_rdcntid_w ? 14'h40 : idu_inst[23:10];

    decoder_6_64 u_dec0(.in(op_31_26 ), .out(op_31_26_d ));
    decoder_4_16 u_dec1(.in(op_25_22 ), .out(op_25_22_d ));
    decoder_2_4  u_dec2(.in(op_21_20 ), .out(op_21_20_d ));
    decoder_5_32 u_dec3(.in(op_19_15 ), .out(op_19_15_d ));

    decoder_5_32 u_dec4(.in(rd  ), .out(rd_d  ));
    decoder_5_32 u_dec5(.in(rj  ), .out(rj_d  ));
    decoder_5_32 u_dec6(.in(rk  ), .out(rk_d  ));

    assign inst_add_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h00];
    assign inst_sub_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h02];
    assign inst_slt    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h04];
    assign inst_slti   = op_31_26_d[6'h00] & op_25_22_d[4'h8];
    assign inst_sltu   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h05];
    assign inst_sltui  = op_31_26_d[6'h00] & op_25_22_d[4'h9];
    assign inst_nor    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h08];
    assign inst_and    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h09];
    assign inst_andi   = op_31_26_d[6'h00] & op_25_22_d[4'hd];
    assign inst_or     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0a];
    assign inst_ori    = op_31_26_d[6'h00] & op_25_22_d[4'he];
    assign inst_xor    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0b];
    assign inst_xori   = op_31_26_d[6'h00] & op_25_22_d[4'hf];
    assign inst_sll    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'he];
    assign inst_slli_w = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h01];
    assign inst_srl    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'hf];
    assign inst_srli_w = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h09];
    assign inst_sra    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h10];
    assign inst_srai_w = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h11];
    assign inst_addi_w = op_31_26_d[6'h00] & op_25_22_d[4'ha];

    assign inst_ld_w   = op_31_26_d[6'h0a] & op_25_22_d[4'h2];
    assign inst_ld_b   = op_31_26_d[6'h0a] & op_25_22_d[4'h0];
    assign inst_ld_bu  = op_31_26_d[6'h0a] & op_25_22_d[4'h8];
    assign inst_ld_h   = op_31_26_d[6'h0a] & op_25_22_d[4'h1];
    assign inst_ld_hu  = op_31_26_d[6'h0a] & op_25_22_d[4'h9];
    assign inst_st_w   = op_31_26_d[6'h0a] & op_25_22_d[4'h6];
    assign inst_st_b   = op_31_26_d[6'h0a] & op_25_22_d[4'h4];
    assign inst_st_h   = op_31_26_d[6'h0a] & op_25_22_d[4'h5];

    assign inst_jirl   = op_31_26_d[6'h13];
    assign inst_b      = op_31_26_d[6'h14];
    assign inst_bl     = op_31_26_d[6'h15];
    assign inst_blt    = op_31_26_d[6'h18];
    assign inst_bltu   = op_31_26_d[6'h1a];
    assign inst_beq    = op_31_26_d[6'h16];
    assign inst_bne    = op_31_26_d[6'h17];
    assign inst_bge    = op_31_26_d[6'h19];
    assign inst_bgeu   = op_31_26_d[6'h1b];

    assign inst_lu12i_w   = op_31_26_d[6'h05] & ~idu_inst[25];
    assign inst_pcaddu12i = op_31_26_d[6'h07] & ~idu_inst[25];

    assign inst_mul_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h18];
    assign inst_mulh_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h19];
    assign inst_mulh_wu = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h1a];
    assign inst_div_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h2] & op_19_15_d[5'h0];
    assign inst_div_wu  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h2] & op_19_15_d[5'h2];
    assign inst_mod_w   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h2] & op_19_15_d[5'h1];
    assign inst_mod_wu  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h2] & op_19_15_d[5'h3];

    assign inst_csrrd      = op_31_26_d[6'h01] & ~idu_inst[25] & ~idu_inst[24] & rj_d[5'h00];
    assign inst_csrwr      = op_31_26_d[6'h01] & ~idu_inst[25] & ~idu_inst[24] & rj_d[5'h01];
    assign inst_csrxchg    = op_31_26_d[6'h01] & ~idu_inst[25] & ~idu_inst[24] & ~rj_d[5'h00] & ~rj_d[5'h01];
    assign inst_ertn       = op_31_26_d[6'h01] & op_25_22_d[4'h9] & op_21_20_d[2'h0] & op_19_15_d[5'h10] & rk_d[5'h0e] & rj_d[5'h00] & rd_d[5'h00];
    assign inst_syscall    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h2] & op_19_15_d[5'h16];
    assign inst_break      = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h2] & op_19_15_d[5'h14];

    assign inst_rdcntid_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h0] & op_19_15_d[5'h00] & rk_d[5'h18] & rd_d[5'h00];
    assign inst_rdcntvl_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h0] & op_19_15_d[5'h00] & rk_d[5'h18] & rj_d[5'h00] & !rd_d[5'h00];
    assign inst_rdcntvh_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h0] & op_19_15_d[5'h00] & rk_d[5'h19] & rj_d[5'h00];
    assign inst_zero       = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h0] & op_19_15_d[5'h00] & rk_d[5'h00] & rj_d[5'h00] & rd_d[5'h00];

    assign inst_invtlb     = op_31_26_d[6'h01] & op_25_22_d[4'h9] & op_21_20_d[2'h0] & op_19_15_d[5'h13];
    assign inst_tlbsrch    = op_31_26_d[6'h01] & op_25_22_d[4'h9] & op_21_20_d[2'h0] & op_19_15_d[5'h10] & rk_d[5'h0a] & rj_d[5'h00] & rd_d[5'h00];
    assign inst_tlbrd      = op_31_26_d[6'h01] & op_25_22_d[4'h9] & op_21_20_d[2'h0] & op_19_15_d[5'h10] & rk_d[5'h0b] & rj_d[5'h00] & rd_d[5'h00];
    assign inst_tlbwr      = op_31_26_d[6'h01] & op_25_22_d[4'h9] & op_21_20_d[2'h0] & op_19_15_d[5'h10] & rk_d[5'h0c] & rj_d[5'h00] & rd_d[5'h00];
    assign inst_tlbfill    = op_31_26_d[6'h01] & op_25_22_d[4'h9] & op_21_20_d[2'h0] & op_19_15_d[5'h10] & rk_d[5'h0d] & rj_d[5'h00] & rd_d[5'h00];

    // assign kernel_inst = inst_csrrd|
    //        inst_csrwr|
    //        inst_csrxchg;

    assign alu_op[0] = inst_add_w | inst_addi_w | inst_ld_w | inst_st_w |
           | inst_jirl | inst_bl | inst_pcaddu12i | inst_ld_b | inst_ld_bu |
           inst_ld_h | inst_ld_hu | inst_st_b | inst_st_h;
    assign alu_op[1] = inst_sub_w;
    assign alu_op[2] = inst_slt | inst_slti;
    assign alu_op[3] = inst_sltu| inst_sltui;
    assign alu_op[4] = inst_and | inst_andi;
    assign alu_op[5] = inst_nor;
    assign alu_op[6] = inst_or | inst_ori;
    assign alu_op[7] = inst_xor| inst_xori;
    assign alu_op[8] = inst_slli_w | inst_sll;
    assign alu_op[9] = inst_srli_w | inst_srl;
    assign alu_op[10] = inst_srai_w | inst_sra;
    assign alu_op[11] = inst_lu12i_w;


    assign mul_div_op[0] = inst_mul_w; // 乘法低位
    assign mul_div_op[1] = inst_mulh_w; // 有符号乘法高位
    assign mul_div_op[2] = inst_mulh_wu; // 无符号乘法高位

    assign mul_div_op[3] = inst_div_w; // 有符号除法低位
    assign mul_div_op[4] = inst_div_wu; // 无符号除法低位
    assign mul_div_op[5] = inst_mod_w; // 有符号取余低位
    assign mul_div_op[6] = inst_mod_wu; // 无符号取余低位

    assign need_ui5   =  inst_slli_w | inst_srli_w | inst_srai_w;

    assign need_si12  =  inst_addi_w | inst_ld_w | inst_st_w | inst_slti | inst_sltui | inst_ld_b | inst_ld_bu |
           inst_ld_h | inst_ld_hu | inst_st_b | inst_st_h;

    assign need_si16  =  inst_jirl | inst_beq | inst_bne;
    assign need_si20  =  inst_lu12i_w | inst_pcaddu12i;
    assign need_si26  =  inst_b | inst_bl;
    assign src2_is_4  =  inst_jirl | inst_bl;

    assign need_ui12  =  inst_andi | inst_ori | inst_xori;

    assign imm = src2_is_4 ? 32'h4:
           need_ui12 ? {20'b0, i12[11:0]}: // 12位零扩展立即数
           need_si20 ? {i20[19:0], 12'b0}:
           {{20{i12[11]}}, i12[11:0]};     // 12位符号扩展立即数


    assign br_offs = need_si26 ? {{ 4{i26[25]}}, i26[25:0], 2'b0} :
           {{14{i16[15]}}, i16[15:0], 2'b0} ;

    assign jirl_offs = {{14{i16[15]}}, i16[15:
                                           0], 2'b0};

    assign src_reg_is_rd = inst_beq |
           inst_bne |
           inst_st_w |
           inst_st_h |
           inst_st_b |
           inst_blt |
           inst_bltu |
           inst_bge |
           inst_bgeu |
           inst_csrwr  |
           inst_csrxchg;

    assign src1_is_pc    = inst_jirl | inst_bl | inst_pcaddu12i;

    assign src2_is_imm   = inst_slli_w |
           inst_srli_w |
           inst_srai_w |
           inst_addi_w |
           inst_lu12i_w|
           inst_jirl   |
           inst_bl     |
           inst_slti   |
           inst_sltui  |
           inst_andi   |
           inst_ori    |
           inst_xori   |
           inst_pcaddu12i |

           inst_st_b   |
           inst_st_h   |
           inst_st_w   |
           inst_ld_b   |
           inst_ld_bu  |
           inst_ld_h   |
           inst_ld_hu  |
           inst_ld_w;

    assign out_mem_op = {inst_ld_w, inst_ld_hu, inst_ld_h, inst_ld_bu, inst_ld_b, inst_st_w, inst_st_h, inst_st_b};

    assign res_from_mem  = inst_ld_w |
           inst_ld_b |
           inst_ld_bu |
           inst_ld_h |
           inst_ld_hu;

    assign res_from_csr =  inst_csrrd |
           inst_csrwr |
           inst_csrxchg |
           inst_rdcntid_w |
           inst_rdcntvl_w |
           inst_rdcntvh_w;

    assign rd_csr_addr = csr_idx;

    // 解决 tid 数据相关
    // 1c076234:	0401002d 	csrwr	$r13,0x40
    // 1c076238:	0000600f 	rdtimel.w	$r15,$r0
    // 1c07623c:	00006180 	rdtimel.w	$r0,$r12

    assign {rdcnt_en, rdcnt_result} = ({33{inst_rdcntvl_w}} & {1'b1, timer_64[31: 0]}) |
           ({33{inst_rdcntvh_w}} & {1'b1, timer_64[63:32]}) |
           ({33{inst_rdcntid_w}} & {1'b1, csr_tid});

    // 解决 csr 数据相关

    wire [31:0] conflict_csr_data;
    assign conflict_csr_data = exu_csr_we && (exu_csr_idx == csr_idx) ? exu_csr_wdata :
           mem_csr_we && (mem_csr_idx == csr_idx) ? mem_csr_wdata :
           wbu_csr_we && (wbu_csr_idx == csr_idx) ? wbu_csr_wdata :
           rdcnt_en ? rdcnt_result : rd_csr_data;

    assign csr_data = conflict_csr_data;
    assign csr_we = inst_csrwr | inst_csrxchg; // 修改 csr

    // 根据掩码 rj，将 old_rd 写入到 rj[x]=1 对应的 csr 位中
    assign csr_mask = inst_csrwr ? 32'hffffffff : rj_value;
    assign csr_wdata = rkd_value & csr_mask | (csr_data & ~csr_mask);

    assign is_inst_ertn = inst_ertn; // 是 ertn 指令

    assign dst_is_r1 = inst_bl;
    assign dst_is_rj = inst_rdcntid_w;
    assign gr_we = inst_jirl|
           inst_bl |
           inst_add_w |
           inst_sub_w |
           inst_slt |
           inst_sltu|
           inst_nor |
           inst_and |
           inst_or  |
           inst_xor |
           inst_slli_w|
           inst_srli_w|
           inst_srai_w|
           inst_addi_w|
           inst_ld_w|
           inst_ld_b|
           inst_ld_bu|
           inst_ld_h|
           inst_ld_hu|
           inst_lu12i_w|
           inst_slti|
           inst_sltui|
           inst_andi|
           inst_ori |
           inst_xori|
           inst_sll |
           inst_srl |
           inst_sra |
           inst_pcaddu12i|
           inst_mul_w|
           inst_mulh_w|
           inst_mulh_wu|
           inst_div_w|
           inst_div_wu|
           inst_mod_w|
           inst_mod_wu|
           inst_csrrd|
           inst_csrxchg|
           inst_csrwr|
           inst_rdcntid_w|
           inst_rdcntvl_w|
           inst_rdcntvh_w
           ;

    assign mem_we = inst_st_w | inst_st_b | inst_st_h;
    assign dest = dst_is_r1 ? 5'd1 :
           dst_is_rj ? rj : rd;

    assign rf_raddr1 = rj;
    assign rf_raddr2 = src_reg_is_rd ? rd :rk;

    assign rj_value  = conflict_regaData;
    assign rkd_value = conflict_regbData;

    wire rj_lt_rd;
    wire rj_ltu_rd;
    wire rj_gt_rd;
    wire rj_gtu_rd;

    assign rj_eq_rd = (rj_value == rkd_value);
    assign rj_lt_rd = ($signed(rj_value) < $signed(rkd_value));
    assign rj_ltu_rd = ($unsigned(rj_value) < $unsigned(rkd_value));
    assign rj_gt_rd = ($signed(rj_value) >= $signed(rkd_value));
    assign rj_gtu_rd = ($unsigned(rj_value) >= $unsigned(rkd_value));

    // 转移指令首先要计算完毕
    // 因为有前递数据会不断得刷新
    // 什么是就计算完了？
    // 我的思路是，让下游每一个模块都计算完毕，这样
    // IDU 才会拿到完整的数据并顺利完成计算


    assign br_taken = (inst_beq  &&  rj_eq_rd
                       || inst_bne  && !rj_eq_rd
                       || inst_jirl
                       || inst_bl
                       || inst_b
                       || inst_blt  && rj_lt_rd
                       || inst_bltu && rj_ltu_rd
                       || inst_bge  && rj_gt_rd
                       || inst_bgeu && rj_gtu_rd
                      )  && !wire_fs_excp && !refetch_excp_i_r;
    //   )  && !wire_fs_excp ;
    assign br_target = (inst_beq || inst_bne || inst_bl || inst_b || inst_blt || inst_bltu || inst_bge || inst_bgeu) ? (idu_pc + br_offs) :
           /*inst_jirl*/  (rj_value + jirl_offs);

    // 如果下游有异常，当前指令全部 valid 就行，不用报指令无效异常
    assign inst_valid = exu_excp ? 1'b1 : inst_add_w |
           inst_sub_w|
           inst_slt |
           inst_slti|
           inst_sltu|
           inst_sltui|
           inst_nor |
           inst_and |
           inst_andi|
           inst_or  |
           inst_ori |
           inst_xor |
           inst_xori|
           inst_sll |
           inst_slli_w|
           inst_srl |
           inst_srli_w|
           inst_sra |
           inst_srai_w|
           inst_addi_w|
           inst_ld_w |
           inst_ld_b |
           inst_ld_bu|
           inst_ld_h |
           inst_ld_hu|
           inst_st_w |
           inst_st_b |
           inst_st_h |
           inst_jirl |
           inst_b    |
           inst_bl  |
           inst_blt |
           inst_bltu|
           inst_beq |
           inst_bne |
           inst_bge |
           inst_bgeu|
           inst_lu12i_w|
           inst_pcaddu12i|
           inst_mul_w|
           inst_mulh_w|
           inst_mulh_wu|
           inst_div_w|
           inst_div_wu|
           inst_mod_w|
           inst_mod_wu|
           inst_csrrd|
           inst_csrwr|
           inst_csrxchg|
           inst_ertn|
           inst_syscall|
           inst_break|
           inst_rdcntid_w|
           inst_rdcntvl_w|
           inst_rdcntvh_w|
           inst_tlbsrch    |
           inst_tlbrd      |
           inst_tlbwr      |
           inst_tlbfill    |
           (inst_invtlb && (rd == 5'd0 ||
                            rd == 5'd1 ||
                            rd == 5'd2 ||
                            rd == 5'd3 ||
                            rd == 5'd4 ||
                            rd == 5'd5 ||
                            rd == 5'd6 ));


    wire kernel_inst = inst_csrrd      |
         inst_csrwr      |
         inst_csrxchg    |
         inst_tlbsrch    |
         inst_tlbrd      |
         inst_tlbwr      |
         inst_tlbfill    |
         inst_invtlb     |
         inst_ertn ;


    // 异常=================================================
    // 0x4
    assign idu_excp_syacall = inst_syscall;
    assign syscall_num = idu_excp_syacall ? 16'h0010 : 16'b0;
    // 0x5
    assign idu_excp_ine = ~inst_valid;
    assign excp_ine_num = idu_excp_ine ? 16'h0020 : 16'b0;
    // 0x6
    assign idu_excp_brk = inst_break;
    assign excp_brk_num = idu_excp_brk ? 16'h0040 : 16'b0;
    // 0x7
    assign idu_excp_ie = has_int & ~is_nop;
    assign excp_ie_num = idu_excp_ie ? 16'h0080 : 16'b0;
    // 0x8
    assign idu_excp_ipe = kernel_inst && (csr_plv == 2'b11);
    assign excp_ipe_num = idu_excp_ipe ? 16'h0100 : 16'b0;

    assign ds_excp = ( wire_fs_excp | idu_excp_syacall |
                       idu_excp_ine | idu_excp_brk | idu_excp_ie | idu_excp_ipe
                     ) & ~is_nop;

    assign ds_excp_num = ~is_nop ? (wire_fs_excp_num | syscall_num | excp_ine_num | excp_brk_num | excp_ie_num) :
           ( wire_fs_excp_num | syscall_num | excp_ine_num | excp_brk_num);

    // 输出
    assign ds_excp_out =  ds_excp;
    assign ds_excp_num_out =  ds_excp_num;

    // 异常=================================================

    assign alu_src1 = src1_is_pc  ? idu_pc[31:0] : rj_value;
    assign alu_src2 = src2_is_imm ? imm : rkd_value;

    // tlb
    assign tlb_inst_bus = {
               inst_tlbsrch,
               inst_tlbrd,
               inst_tlbwr,
               inst_tlbfill,
               inst_invtlb
           };

    // invtlb
    assign invtlb_op = rd;
    assign invtlb_asid = rj_value[9:0];
    assign invtlb_vpn = rkd_value[31:13];

    //debug
    assign idu_inst_o = inst_sram_rdata_reg;
    assign is_csr_wr = inst_csrwr |
           inst_csrxchg |
           inst_tlbrd|
           inst_tlbsrch;
    assign refetch_excp_o = refetch_excp_i_r;
    assign pc_pro_o = idu_pc;

endmodule
