module IDU (
        // from top
        input wire clk,
        input wire rst,
        // to ifu
        output wire [32:0] bus_br_data,
        // from ifu
        input wire [31:0] in_pc,

        // to rf
        output wire [4:0] rf_raddr1,
        output wire [4:0] rf_raddr2,

        // from rf
        input wire [31:0] rf_rdata1,
        input wire [31:0] rf_rdata2,

        // from inst_ram
        input [31:0] inst_sram_data,

        // bus
        output wire [147:0] bus_ds_to_es_data,

        // 直通解决数据相关
        input wire [37:0] bus_exu_bypass_data,
        input wire [37:0] bus_mem_bypass_data,
        input wire [37:0] bus_wbu_bypass_data,

        // 握手信号
        //allowin
        input    es_allowin, // 下游发来的 allowin
        output   ds_allowin, // 发给上游的 allowin

        input    fs_to_ds_valid,    // 上游发来的空闲信号
        output   ds_to_es_valid     // 发给下游的空闲信号
    );

    // 数据相关

    wire exu_regWr;
    wire [31:0] exu_data;
    wire [4:0] exu_regAddr;

    wire mem_regWr;
    wire [31:0] mem_data;
    wire [4:0] mem_regAddr;

    wire wbu_regWr;
    wire [31:0] wbu_data;
    wire [4:0] wbu_regAddr;

    assign {
            exu_regWr,
            exu_data,
            exu_regAddr
        } = bus_exu_bypass_data;
    assign {
            mem_regWr,
            mem_data,
            mem_regAddr
        } = bus_mem_bypass_data;
    assign {
            wbu_regWr,
            wbu_data,
            wbu_regAddr
        } = bus_wbu_bypass_data;


    wire [11:0] alu_op;
    wire [31:0] alu_src1;
    wire [31:0] alu_src2;
    wire        mem_we;
    wire [31:0] rkd_value;
    wire        res_from_mem;
    wire        gr_we;
    wire [4:0]  dest;
    wire [31:0] pc;

    wire br_taken;
    wire [31:0] br_target;

    assign bus_br_data = {br_taken, br_target};
    assign bus_ds_to_es_data = {alu_op, alu_src1, alu_src2, mem_we, rkd_value, res_from_mem, gr_we, dest, idu_pc};

    wire [31:0] idu_inst;
    wire [31:0] idu_pc;
    wire        src1_is_pc;
    wire        src2_is_imm;
    wire        dst_is_r1;
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

    wire        inst_add_w;
    wire        inst_sub_w;
    wire        inst_slt;
    wire        inst_sltu;
    wire        inst_nor;
    wire        inst_and;
    wire        inst_or;
    wire        inst_xor;
    wire        inst_slli_w;
    wire        inst_srli_w;
    wire        inst_srai_w;
    wire        inst_addi_w;
    wire        inst_ld_w;
    wire        inst_st_w;
    wire        inst_jirl;
    wire        inst_b;
    wire        inst_bl;
    wire        inst_beq;
    wire        inst_bne;
    wire        inst_lu12i_w;

    wire        need_ui5;
    wire        need_si12;
    wire        need_si16;
    wire        need_si20;
    wire        need_si26;
    wire        src2_is_4;

    // 判断是否数据相关
    // 越靠近 idu 越优先

    // 检测上一条指令是否是 load 指令
    reg is_load;
    always @(posedge clk) begin
        if (rst) begin
            is_load <= 1'b0;
        end
        else if (fs_to_ds_valid && ds_allowin) begin
            is_load <= inst_ld_w;
        end
    end
    // 检测 load-use 数据相关
    wire load_use_conflict;
    assign load_use_conflict = is_load && exu_regWr && (rf_raddr1 == exu_regAddr) && rf_raddr1 != 5'd0;

    reg [31:0] conflict_regaData;
    reg [31:0] conflict_regbData;

    // 当检测到冲突以后，就得阻塞

    always @(*) begin
        if (exu_regWr && (rf_raddr1 == exu_regAddr)) begin
            conflict_regaData = exu_data;
        end
        else if (mem_regWr && (rf_raddr1 == mem_regAddr)) begin
            conflict_regaData = mem_data;
        end
        else if (wbu_regWr && (rf_raddr1 == wbu_regAddr)) begin
            conflict_regaData = wbu_data;
        end
        else begin
            conflict_regaData = rf_rdata1;  // 默认值
        end
    end

    always @(*) begin
        if (exu_regWr && (rf_raddr2 == exu_regAddr)) begin
            conflict_regbData = exu_data;
        end
        else if (mem_regWr && (rf_raddr2 == mem_regAddr)) begin
            conflict_regbData = mem_data;
        end
        else if (wbu_regWr && (rf_raddr2 == wbu_regAddr)) begin
            conflict_regbData = wbu_data;
        end
        else begin
            conflict_regbData = rf_rdata2;  // 默认值
        end
    end

    // 暂存上一级来的数据
    reg [31:0] inst_sram_rdata_reg;
    reg [31:0] pc_reg;

    // 握手信号
    reg   ds_valid;    // 表示当前流水级是否在处理指令
    wire  ds_ready_go; // 是否需要阻塞

    assign ds_ready_go    =  ds_valid  & !load_use_conflict;
    assign ds_allowin     = !ds_valid || ds_ready_go && es_allowin; // 表示当前阶段是否允许上游进入
    assign ds_to_es_valid = ds_valid && ds_ready_go;

    always @(posedge clk ) begin
        if (rst) begin
            ds_valid <= 1'b0;
        end
        else if (ds_allowin) begin
            ds_valid <= fs_to_ds_valid;
        end
        if (fs_to_ds_valid && ds_allowin) begin
            // 卸货，暂时不使用 bus
            pc_reg <= in_pc;
            // 如果当前是跳转，那么下一条指令置空
            inst_sram_rdata_reg <= br_taken ? 32'd0 :inst_sram_data;
            // inst_sram_rdata_reg <= inst_sram_rdata;

        end
    end
    assign idu_inst            = inst_sram_rdata_reg;
    assign idu_pc              = pc_reg;
    assign pc = idu_pc;

    assign op_31_26  = idu_inst[31:26];
    assign op_25_22  = idu_inst[25:22];
    assign op_21_20  = idu_inst[21:20];
    assign op_19_15  = idu_inst[19:15];

    assign rd   = idu_inst[ 4: 0];
    assign rj   = idu_inst[ 9: 5];
    assign rk   = idu_inst[14:10];

    assign i12  = idu_inst[21:10];
    assign i20  = idu_inst[24: 5];
    assign i16  = idu_inst[25:10];
    assign i26  = {idu_inst[ 9:
                             0], idu_inst[25:
                                          10]};

    decoder_6_64 u_dec0(.in(op_31_26 ), .out(op_31_26_d ));
    decoder_4_16 u_dec1(.in(op_25_22 ), .out(op_25_22_d ));
    decoder_2_4  u_dec2(.in(op_21_20 ), .out(op_21_20_d ));
    decoder_5_32 u_dec3(.in(op_19_15 ), .out(op_19_15_d ));

    assign inst_add_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h00];
    assign inst_sub_w  = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h02];
    assign inst_slt    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h04];
    assign inst_sltu   = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h05];
    assign inst_nor    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h08];
    assign inst_and    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h09];
    assign inst_or     = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0a];
    assign inst_xor    = op_31_26_d[6'h00] & op_25_22_d[4'h0] & op_21_20_d[2'h1] & op_19_15_d[5'h0b];
    assign inst_slli_w = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h01];
    assign inst_srli_w = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h09];
    assign inst_srai_w = op_31_26_d[6'h00] & op_25_22_d[4'h1] & op_21_20_d[2'h0] & op_19_15_d[5'h11];
    assign inst_addi_w = op_31_26_d[6'h00] & op_25_22_d[4'ha];
    assign inst_ld_w   = op_31_26_d[6'h0a] & op_25_22_d[4'h2];
    assign inst_st_w   = op_31_26_d[6'h0a] & op_25_22_d[4'h6];
    assign inst_jirl   = op_31_26_d[6'h13];
    assign inst_b      = op_31_26_d[6'h14];
    assign inst_bl     = op_31_26_d[6'h15];
    assign inst_beq    = op_31_26_d[6'h16];
    assign inst_bne    = op_31_26_d[6'h17];
    assign inst_lu12i_w= op_31_26_d[6'h05] & ~idu_inst[25];

    assign alu_op[ 0] = inst_add_w | inst_addi_w | inst_ld_w | inst_st_w
           | inst_jirl | inst_bl;
    assign alu_op[ 1] = inst_sub_w;
    assign alu_op[ 2] = inst_slt;
    assign alu_op[ 3] = inst_sltu;
    assign alu_op[ 4] = inst_and;
    assign alu_op[ 5] = inst_nor;
    assign alu_op[ 6] = inst_or;
    assign alu_op[ 7] = inst_xor;
    assign alu_op[ 8] = inst_slli_w;
    assign alu_op[ 9] = inst_srli_w;
    assign alu_op[10] = inst_srai_w;
    assign alu_op[11] = inst_lu12i_w;

    assign need_ui5   =  inst_slli_w | inst_srli_w | inst_srai_w;
    assign need_si12  =  inst_addi_w | inst_ld_w | inst_st_w;
    assign need_si16  =  inst_jirl | inst_beq | inst_bne;
    assign need_si20  =  inst_lu12i_w;
    assign need_si26  =  inst_b | inst_bl;
    assign src2_is_4  =  inst_jirl | inst_bl;

    assign imm = src2_is_4 ? 32'h4                      :
           need_si20 ? {i20[19:0], 12'b0}         :
           /*need_ui5 || need_si12*/{{20{i12[11]}}, i12[11:0]} ;

    assign br_offs = need_si26 ? {{ 4{i26[25]}}, i26[25:0], 2'b0} :
           {{14{i16[15]}}, i16[15:0], 2'b0} ;

    assign jirl_offs = {{14{i16[15]}}, i16[15:
                                           0], 2'b0};

    assign src_reg_is_rd = inst_beq | inst_bne | inst_st_w;

    assign src1_is_pc    = inst_jirl | inst_bl;

    assign src2_is_imm   = inst_slli_w |
           inst_srli_w |
           inst_srai_w |
           inst_addi_w |
           inst_ld_w   |
           inst_st_w   |
           inst_lu12i_w|
           inst_jirl   |
           inst_bl     ;

    assign res_from_mem  = inst_ld_w;
    assign dst_is_r1     = inst_bl;
    assign gr_we         = inst_bl |
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
           inst_lu12i_w
           ;
    assign mem_we        = inst_st_w;
    assign dest          = dst_is_r1 ? 5'd1 : rd;

    assign rf_raddr1 = rj;
    assign rf_raddr2 = src_reg_is_rd ? rd :rk;

    assign rj_value  = conflict_regaData;
    assign rkd_value = conflict_regbData;

    assign rj_eq_rd = (rj_value == rkd_value);
    assign br_taken = (inst_beq  &&  rj_eq_rd
                       || inst_bne  && !rj_eq_rd
                       || inst_jirl
                       || inst_bl
                       || inst_b
                      ) && ds_valid;
    assign br_target = (inst_beq || inst_bne || inst_bl || inst_b) ? (idu_pc + br_offs) :
           /*inst_jirl*/  (rj_value + jirl_offs);

    assign alu_src1 = src1_is_pc  ? idu_pc[31:0] : rj_value;
    assign alu_src2 = src2_is_imm ? imm : rkd_value;




endmodule
