`timescale 1ns / 1ps
`include "rtl_debug.vh"

// ############################################################################
//  硬件原语模板库 (Hardware Primitives)
//
//  使用规则：
//    1. 任何寄存器、存储、选择器优先从本文件中选用模板
//    2. 模板带来明显问题（时序/面积/功能不匹配）时才直接写 RTL
//    3. 模板参数化设计，实例化时通过 #(...) 配置
// ############################################################################

// ============================================================================
// 1. Reg — 带复位、写使能的 D 触发器
// ============================================================================
//  用途：所有需要复位值和写使能控制的寄存器
//  时序：posedge clk，同步复位（rst 高有效）
module Reg #(
    parameter WIDTH     = 1,
    parameter RESET_VAL = 0
) (
    input  wire             clk,
    input  wire             rst,
    input  wire [WIDTH-1:0] din,
    output reg  [WIDTH-1:0] dout,
    input  wire             wen
);
    always @(posedge clk) begin
        if (rst)       dout <= RESET_VAL;
        else if (wen)  dout <= din;
    end
    `CPU_DEBUG_MODULE("Reg")
endmodule

// ============================================================================
// 2. RegAsyncRst — 带异步复位、写使能的 D 触发器
// ============================================================================
//  用途：需要异步复位的寄存器（本项目 rst_n 低有效）
module RegAsyncRst #(
    parameter WIDTH     = 1,
    parameter RESET_VAL = 0
) (
    input  wire             clk,
    input  wire             rst_n,
    input  wire [WIDTH-1:0] din,
    output reg  [WIDTH-1:0] dout,
    input  wire             wen
);
    always @(posedge clk) begin
        if (!rst_n)    dout <= RESET_VAL;
        else if (wen)  dout <= din;
    end
    `CPU_DEBUG_MODULE("RegAsyncRst")
endmodule

// ============================================================================
// 3. PipeReg — 流水线级间寄存器（异步复位 + 冲刷 + 互锁）
// ============================================================================
//  用途：流水线每一级之间的数据传递
//  优先级：rst_n > flush > stall > 正常传递
//  stall 时保持当前值，flush 时清为复位值
module PipeReg #(
    parameter WIDTH     = 1,
    parameter RESET_VAL = 0
) (
    input  wire             clk,
    input  wire             rst_n,
    input  wire             flush,    // 冲刷（清为复位值）
    input  wire             stall,    // 互锁（保持当前值）
    input  wire [WIDTH-1:0] din,
    output reg  [WIDTH-1:0] dout
);
    always @(posedge clk) begin
        if (!rst_n)       dout <= RESET_VAL;
        else if (flush)   dout <= RESET_VAL;
        else if (!stall)  dout <= din;
    end
    `CPU_DEBUG_MODULE("PipeReg")
endmodule

// ============================================================================
// 4. BramSDP — Simple Dual Port BRAM（1 写 1 读，读延迟 1 拍）
// ============================================================================
//  用途：寄存器堆、BPU BTB/PHT、Cache data/tag
//  时序：写端口和读端口独立，读数据下一拍可用
//  推断：(* ram_style = "block" *) 强制 BRAM
//  同地址同周期读写行为：读出旧值（READ_FIRST）
module BramSDP #(
    parameter DEPTH    = 32,
    parameter WIDTH    = 32,
    parameter ADDR_W   = $clog2(DEPTH)
) (
    input  wire              clk,
    // 写端口
    input  wire              we,
    input  wire [ADDR_W-1:0] waddr,
    input  wire [WIDTH-1:0]  wdata,
    // 读端口
    input  wire [ADDR_W-1:0] raddr,
    output reg  [WIDTH-1:0]  rdata
);
    (* ram_style = "block" *) reg [WIDTH-1:0] mem [0:DEPTH-1];

    always @(posedge clk) begin
        if (we)
            mem[waddr] <= wdata;
    end

    always @(posedge clk) begin
        rdata <= mem[raddr];
    end
    `CPU_DEBUG_MODULE("BramSDP")
endmodule

// ============================================================================
// 5. BramTDP — True Dual Port BRAM（2 个独立读写端口，读延迟 1 拍）
// ============================================================================
//  用途：需要两个独立读端口的场景（如寄存器堆的 rs1/rs2）
//  每个端口都可以独立读或写
module BramTDP #(
    parameter DEPTH    = 32,
    parameter WIDTH    = 32,
    parameter ADDR_W   = $clog2(DEPTH)
) (
    input  wire              clk,
    // 端口 A
    input  wire              a_we,
    input  wire [ADDR_W-1:0] a_addr,
    input  wire [WIDTH-1:0]  a_wdata,
    output reg  [WIDTH-1:0]  a_rdata,
    // 端口 B
    input  wire              b_we,
    input  wire [ADDR_W-1:0] b_addr,
    input  wire [WIDTH-1:0]  b_wdata,
    output reg  [WIDTH-1:0]  b_rdata
);
    (* ram_style = "block" *) reg [WIDTH-1:0] mem [0:DEPTH-1];

    always @(posedge clk) begin
        if (a_we)
            mem[a_addr] <= a_wdata;
        a_rdata <= mem[a_addr];
    end

    always @(posedge clk) begin
        if (b_we)
            mem[b_addr] <= b_wdata;
        b_rdata <= mem[b_addr];
    end
    `CPU_DEBUG_MODULE("BramTDP")
endmodule

// ============================================================================
// 6. SatCounter — 饱和计数器（上溢不翻转，下溢不翻转）
// ============================================================================
//  用途：BPU PHT 的 2-bit 饱和计数器
//  WIDTH=2 时：00 → 01 → 10 → 11，到顶/底不再变
//  带同步复位和写使能
module SatCounter #(
    parameter WIDTH     = 2,
    parameter RESET_VAL = 0
) (
    input  wire clk,
    input  wire rst,
    input  wire en,       // 更新使能
    input  wire inc,      // 1=递增, 0=递减
    output reg  [WIDTH-1:0] cnt
);
    localparam MAX_VAL = {WIDTH{1'b1}};
    localparam MIN_VAL = {WIDTH{1'b0}};

    always @(posedge clk) begin
        if (rst) begin
            cnt <= RESET_VAL;
        end else if (en) begin
            if (inc && (cnt != MAX_VAL))
                cnt <= cnt + 1'b1;
            else if (!inc && (cnt != MIN_VAL))
                cnt <= cnt - 1'b1;
        end
    end
    `CPU_DEBUG_MODULE("SatCounter")
endmodule

// ============================================================================
// 7. OnehotToBin — 独热码转二进制编码
// ============================================================================
//  用途：TLB match 向量 → 命中条目索引
//  输入必须是独热或全零，多位同时为 1 时行为未定义（取最高位）
module OnehotToBin #(
    parameter WIDTH = 16,
    parameter BIN_W = $clog2(WIDTH)
) (
    input  wire [WIDTH-1:0] onehot,
    output reg  [BIN_W-1:0] bin,
    output wire             valid     // 是否有任意一位为 1
);
    assign valid = |onehot;

    integer i;
    always @(*) begin
        bin = {BIN_W{1'b0}};
        for (i = 0; i < WIDTH; i = i + 1) begin
            if (onehot[i])
                bin = i[BIN_W-1:0];
        end
    end
    `CPU_DEBUG_MODULE("OnehotToBin")
endmodule

// ============================================================================
// 8. BinToOnehot — 二进制编码转独热码
// ============================================================================
//  用途：解码器、写使能生成
module BinToOnehot #(
    parameter BIN_W = 4,
    parameter WIDTH = (1 << BIN_W)
) (
    input  wire [BIN_W-1:0] bin,
    input  wire             en,       // 使能，为 0 时输出全零
    output wire [WIDTH-1:0] onehot
);
    assign onehot = en ? ({{(WIDTH-1){1'b0}}, 1'b1} << bin) : {WIDTH{1'b0}};
    `CPU_DEBUG_MODULE("BinToOnehot")
endmodule

// ============================================================================
// 9. PriorityMux — 优先级多路选择器
// ============================================================================
//  用途：旁路网络（EX > MEM > WB > regfile，优先级从高到低）
//  sel[0] 优先级最高，sel[NR_INPUT-1] 优先级最低
//  所有 sel 都为 0 时输出 default_val
module PriorityMux #(
    parameter NR_INPUT  = 4,
    parameter DATA_LEN  = 32
) (
    input  wire [NR_INPUT-1:0]           sel,
    input  wire [NR_INPUT*DATA_LEN-1:0]  data_in,    // {data[N-1], ..., data[1], data[0]}
    input  wire [DATA_LEN-1:0]           default_val,
    output reg  [DATA_LEN-1:0]           out
);
    integer i;
    always @(*) begin
        out = default_val;
        // 从低优先级往高优先级扫，高优先级覆盖低优先级
        for (i = NR_INPUT - 1; i >= 0; i = i - 1) begin
            if (sel[i])
                out = data_in[i*DATA_LEN +: DATA_LEN];
        end
    end
    `CPU_DEBUG_MODULE("PriorityMux")
endmodule

// ============================================================================
// 10. LFSR — 线性反馈移位寄存器（伪随机数发生器）
// ============================================================================
//  用途：TLB TLBFILL 随机替换索引、Cache 随机替换
//  多项式：使用 Fibonacci LFSR，最大长度反馈
//  WIDTH=4: x^4 + x^3 + 1
//  WIDTH=5: x^5 + x^3 + 1
//  WIDTH=8: x^8 + x^6 + x^5 + x^4 + 1
module LFSR #(
    parameter WIDTH = 4
) (
    input  wire             clk,
    input  wire             rst_n,
    input  wire             en,       // 使能，每拍移位
    output wire [WIDTH-1:0] val
);
    reg [WIDTH-1:0] state_r;
    wire feedback_w;

    // 反馈多项式（最大长度）
    generate
        if (WIDTH == 4)
            assign feedback_w = state_r[3] ^ state_r[2];           // x^4+x^3+1
        else if (WIDTH == 5)
            assign feedback_w = state_r[4] ^ state_r[2];           // x^5+x^3+1
        else if (WIDTH == 8)
            assign feedback_w = state_r[7] ^ state_r[5] ^ state_r[4] ^ state_r[3]; // x^8+x^6+x^5+x^4+1
        else
            assign feedback_w = state_r[WIDTH-1] ^ state_r[0];     // 通用回退
    endgenerate

    always @(posedge clk) begin
        if (!rst_n)
            state_r <= {{(WIDTH-1){1'b0}}, 1'b1};  // 不能全零
        else if (en)
            state_r <= {state_r[WIDTH-2:0], feedback_w};
    end

    assign val = state_r;
    `CPU_DEBUG_MODULE("LFSR")
endmodule

// ============================================================================
// 11. MuxKeyInternal — 键值查找选择器（内部实现）
// ============================================================================
//  用途：解码逻辑、ALU op 选择等 case-like 场景
//  lut 格式：{key_N-1, data_N-1, ..., key_1, data_1, key_0, data_0}
module MuxKeyInternal #(
    parameter NR_KEY      = 2,
    parameter KEY_LEN     = 1,
    parameter DATA_LEN    = 1,
    parameter HAS_DEFAULT = 0
) (
    output reg  [DATA_LEN-1:0]                  out,
    input  wire [KEY_LEN-1:0]                    key,
    input  wire [DATA_LEN-1:0]                   default_out,
    input  wire [NR_KEY*(KEY_LEN+DATA_LEN)-1:0]  lut
);
    localparam PAIR_LEN = KEY_LEN + DATA_LEN;

    wire [PAIR_LEN-1:0]  pair_list [0:NR_KEY-1];
    wire [KEY_LEN-1:0]   key_list  [0:NR_KEY-1];
    wire [DATA_LEN-1:0]  data_list [0:NR_KEY-1];

    genvar n;
    generate
        for (n = 0; n < NR_KEY; n = n + 1) begin : unpack
            assign pair_list[n] = lut[PAIR_LEN*(n+1)-1 : PAIR_LEN*n];
            assign data_list[n] = pair_list[n][DATA_LEN-1:0];
            assign key_list[n]  = pair_list[n][PAIR_LEN-1:DATA_LEN];
        end
    endgenerate

    reg [DATA_LEN-1:0] lut_out;
    reg hit;
    integer i;
    always @(*) begin
        lut_out = {DATA_LEN{1'b0}};
        hit     = 1'b0;
        for (i = 0; i < NR_KEY; i = i + 1) begin
            lut_out = lut_out | ({DATA_LEN{key == key_list[i]}} & data_list[i]);
            hit     = hit | (key == key_list[i]);
        end
        if (!HAS_DEFAULT) out = lut_out;
        else              out = hit ? lut_out : default_out;
    end
    `CPU_DEBUG_MODULE("MuxKeyInternal")
endmodule

// ============================================================================
// 12. MuxKey — 不带默认值的键值选择器
// ============================================================================
module MuxKey #(
    parameter NR_KEY   = 2,
    parameter KEY_LEN  = 1,
    parameter DATA_LEN = 1
) (
    output wire [DATA_LEN-1:0]                  out,
    input  wire [KEY_LEN-1:0]                    key,
    input  wire [NR_KEY*(KEY_LEN+DATA_LEN)-1:0]  lut
);
    MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 0) i0 (
        .out(out), .key(key), .default_out({DATA_LEN{1'b0}}), .lut(lut)
    );
    `CPU_DEBUG_MODULE("MuxKey")
endmodule

// ============================================================================
// 13. MuxKeyWithDefault — 带默认值的键值选择器
// ============================================================================
module MuxKeyWithDefault #(
    parameter NR_KEY   = 2,
    parameter KEY_LEN  = 1,
    parameter DATA_LEN = 1
) (
    output wire [DATA_LEN-1:0]                  out,
    input  wire [KEY_LEN-1:0]                    key,
    input  wire [DATA_LEN-1:0]                   default_out,
    input  wire [NR_KEY*(KEY_LEN+DATA_LEN)-1:0]  lut
);
    MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 1) i0 (
        .out(out), .key(key), .default_out(default_out), .lut(lut)
    );
    `CPU_DEBUG_MODULE("MuxKeyWithDefault")
endmodule

// ============================================================================
// 14. Mux2 / Mux4 — 2/4 路简单数据选择器
// ============================================================================
//  用途：操作数选择（src_a_sel / src_b_sel）等小规模 MUX
module Mux2 #(
    parameter WIDTH = 32
) (
    input  wire             sel,
    input  wire [WIDTH-1:0] d0,       // sel=0 时选中
    input  wire [WIDTH-1:0] d1,       // sel=1 时选中
    output wire [WIDTH-1:0] out
);
    assign out = sel ? d1 : d0;
    `CPU_DEBUG_MODULE("Mux2")
endmodule

module Mux4 #(
    parameter WIDTH = 32
) (
    input  wire [1:0]       sel,
    input  wire [WIDTH-1:0] d0,       // sel=00
    input  wire [WIDTH-1:0] d1,       // sel=01
    input  wire [WIDTH-1:0] d2,       // sel=10
    input  wire [WIDTH-1:0] d3,       // sel=11
    output reg  [WIDTH-1:0] out
);
    always @(*) begin
        case (sel)
            2'd0:    out = d0;
            2'd1:    out = d1;
            2'd2:    out = d2;
            default: out = d3;
        endcase
    end
    `CPU_DEBUG_MODULE("Mux4")
endmodule
