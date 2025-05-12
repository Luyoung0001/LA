// module pre_IFU (
//         input wire clk,             // 时钟信号
//         input wire rst,             // 复位信号

//         input wire [31:0] fs_pc,

//         input wire [32:0] bus_br_data,

//         output wire [31:0] next_pc,
//         output wire [31:0] inst_addr,       // 发射给inst_ram的地址
//         output wire [31:0] inst_data,        // 发送到 ifu
//         input wire [1:0] flush,
//         input wire [31:0] csr_era,
//         input wire [31:0] csr_eentry,

//         output wire pfs_excp_adef,
//         output wire pfs_excp,

//         // 保持 ram 的输出是一个关键，但是观察波形图，可以让inst_addr 遇到 load_use 的时候
//         // 让 inst_addr 变成上一个周期的值
//         input wire fs_allowin,
//         // AXI 接口
//         output   reg[ 3:0] arid,
//         output   reg[31:0] araddr,
//         output   reg[ 7:0] arlen,
//         output   reg[ 2:0] arsize,
//         output      [ 1:0] arburst,
//         output      [ 1:0] arlock,
//         output      [ 3:0] arcache,
//         output      [ 2:0] arprot,
//         output   reg       arvalid,
//         input              arready,

//         input    [ 3:0] rid,
//         input    [31:0] rdata,
//         input    [ 1:0] rresp,
//         input           rlast,
//         input           rvalid,
//         output   reg    rready,

//         output rvalid
//     );


//     wire excp_flush;
//     wire ertn_flush;
//     assign {excp_flush, ertn_flush} = flush;

//     wire flush_sign;
//     assign flush_sign = ertn_flush || excp_flush;

//     wire [31:0] seq_pc;
//     wire [31:0] nextpc;

//     wire br_taken;
//     wire [31:0] br_target;

//     wire [31:0] inst_flush_pc;

//     assign {br_taken, br_target } = bus_br_data;

//     assign inst_flush_pc = {32{ertn_flush}} & csr_era;

//     assign seq_pc       = fs_pc + 32'h4;
//     assign nextpc       = excp_flush ? csr_eentry:
//            ertn_flush ? inst_flush_pc:
//            br_taken ? br_target :
//            seq_pc;

//     assign inst_addr = fs_allowin ? nextpc : fs_pc;
//     assign next_pc = nextpc;

//     // 取值地址错例外
//     assign pfs_excp_adef = (nextpc[0] || nextpc[1]);
//     assign pfs_excp = pfs_excp_adef;

//     // AXI 握手信号
//     // 这里发出指令访存请求，拿到指令之后，一级一级往下传
//     assign arid = 4'b0;
//     assign araddr = inst_addr;
//     assign arlen = 8'b0; // 固定为 0
//     assign arsize = 3'b010; // 4 字节
//     assign arburst = 2'b01; // 固定为 INCR
//     assign arlock = 2'b00; // 固定为 0
//     assign arcache = 4'b0000; // 固定为 0
//     assign arprot = 3'b000; // 固定为 0

//     reg [3:0] state; // 状态机的状态
//     localparam IDLE = 4'b0000;
//     localparam WAITE_RVALID = 4'b0001;

//     always @(posedge clk) begin
//         if(rst) begin
//             state <= IDLE;
//             arvalid <= 1'b0;
//             rready <= 1'b0;
//         end
//         else begin
//             case (state)
//                 IDLE: begin
//                     if (fs_allowin) begin
//                         arvalid <= 1'b1;
//                         state <= WAITE_RVALID;
//                     end
//                 end

//                 WAITE_RVALID: begin
//                     if (arready) begin
//                     // 传送地址
//                         arvalid <= 1'b1; //  地址有效
//                         rready <= 1'b1; // 准好被接收数据
//                         state <= rvalid ? IDLE : WAITE_RVALID;
//                     end
//                 end

//                 default: begin
//                     state <= IDLE;
//                 end
//             endcase
//         end

//     end
//     assign

// endmodule
