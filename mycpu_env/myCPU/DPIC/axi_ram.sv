// module axi_ram (
//         input          clock,
//         input          reset,

//         input   reg[ 3:0] arid,
//         input   reg[31:0] araddr,
//         input   reg[ 7:0] arlen,
//         input   reg[ 2:0] arsize,
//         input      [ 1:0] arburst,
//         input      [ 1:0] arlock,
//         input      [ 3:0] arcache,
//         input      [ 2:0] arprot,
//         input   reg       arvalid,
//         output  reg       arready,

//         output  reg  [ 3:0] rid,
//         output  reg  [31:0] rdata,
//         output  reg  [ 1:0] rresp,
//         output  reg         rlast,
//         output  reg         rvalid,
//         input   reg         rready,

//         input      [ 3:0] awid,
//         input   reg[31:0] awaddr,
//         input   reg[ 7:0] awlen,
//         input   reg[ 2:0] awsize,
//         input      [ 1:0] awburst,
//         input      [ 1:0] awlock,
//         input      [ 3:0] awcache,
//         input      [ 2:0] awprot,
//         input   reg       awvalid,
//         output  reg       awready,

//         input      [ 3:0] wid,
//         input   reg[31:0] wdata,
//         input   reg[ 3:0] wstrb,
//         input   reg       wlast,
//         input   reg       wvalid,
//         output  reg       wready,

//         output  reg [ 3:0] bid,
//         output  reg [ 1:0] bresp,
//         output  reg        bvalid,
//         input   reg        bready
//     );

//     import "DPI-C" function int data_ram_read(input int addr);
//     import "DPI-C" function void data_ram_write(input int addr, input int wdata, input byte we_7);

//     // 寄存器信号
//     logic [3:0] state;
//     logic [3:0] state1;

//     // 读通道状态机
//     always_ff @(posedge clock or posedge reset) begin
//         if (reset) begin
//             // 初始化状态和信号
//             arready <= 1'b0;
//             rvalid  <= 1'b0;
//             rdata   <= 32'b0;
//             rresp   <= 2'b00;
//             rlast   <= 1'b1;
//             rid     <= 4'b0;
//             state   <= 4'd0;
//         end
//         else begin
//             case (state)
//                 4'd0: begin // 等待 arvalid
//                     arready <= 1'b0;
//                     rvalid  <= 1'b0;
//                     if (arvalid) begin
//                         arready <= 1'b1;  // 地址已接受
//                         rid     <= arid;   // 修复：在接受地址时设置 rid
//                         state   <= 4'd1;  // 转换到处理数据状态
//                     end
//                 end

//                 4'd1: begin
//                     arready <= 1'b0;
//                     rdata   <= data_ram_read(araddr);
//                     rvalid  <= 1'b1;
//                     rresp   <= 2'b00;
//                     rlast   <= 1'b1;

//                     if (rready) begin
//                         state <= 4'd0;
//                     end
//                 end
//                 default:begin end

//             endcase
//         end
//     end

//     // 写通道状态机
//     wire [7:0] wstrb_1;  // 目标是扩展为 8 位
//     assign wstrb_1 = {4'b0, wstrb};  // 高 4 位填充 0，低 4 位为 wstrb

//     always_ff @(posedge clock or posedge reset) begin
//         if (reset) begin
//             // 初始化状态和信号
//             awready <= 1'b0;
//             wready  <= 1'b0;
//             bvalid  <= 1'b0;
//             bresp   <= 2'b00;
//             bid     <= 4'b0;    // 修复：初始化 bid
//             state1  <= 4'd0;
//         end
//         else begin
//             case (state1)
//                 4'd0: begin // 等待 awvalid
//                     awready <= 1'b0;
//                     wready  <= 1'b0;
//                     bvalid  <= 1'b0;

//                     if (awvalid) begin
//                         awready <= 1'b1;
//                         bid     <= awid;
//                         state1  <= 4'd1;
//                     end
//                 end

//                 4'd1: begin // 等待 wvalid
//                     awready <= 1'b0;

//                     if (wvalid) begin
//                         data_ram_write(awaddr, wdata, wstrb_1);
//                         wready <= 1'b1;
//                         state1 <= 4'd2;
//                     end
//                 end

//                 4'd2: begin // 写响应，发射信号并保持直到 bready
//                     wready <= 1'b0;
//                     bresp  <= 2'b00;      // 响应状态（OKAY）
//                     bvalid <= 1'b1;       // 准备写响应

//                     if (bready) begin
//                         bvalid <= 1'b0;
//                         state1 <= 4'd0;
//                     end
//                 end
//                 default: begin
//                 end
//             endcase
//         end
//     end

// endmodule

module axi_ram (
    input clock,
    input reset,

    input  reg [ 3:0] arid,
    input  reg [31:0] araddr,
    input  reg [ 7:0] arlen,
    input  reg [ 2:0] arsize,
    input      [ 1:0] arburst,
    input      [ 1:0] arlock,
    input      [ 3:0] arcache,
    input      [ 2:0] arprot,
    input  reg        arvalid,
    output reg        arready,

    output reg [ 3:0] rid,
    output reg [31:0] rdata,
    output reg [ 1:0] rresp,
    output reg        rlast,
    output reg        rvalid,
    input  reg        rready,

    input      [ 3:0] awid,
    input  reg [31:0] awaddr,
    input  reg [ 7:0] awlen,
    input  reg [ 2:0] awsize,
    input      [ 1:0] awburst,
    input      [ 1:0] awlock,
    input      [ 3:0] awcache,
    input      [ 2:0] awprot,
    input  reg        awvalid,
    output reg        awready,

    input      [ 3:0] wid,
    input  reg [31:0] wdata,
    input  reg [ 3:0] wstrb,
    input  reg        wlast,
    input  reg        wvalid,
    output reg        wready,

    output reg [3:0] bid,
    output reg [1:0] bresp,
    output reg       bvalid,
    input  reg       bready
);

  import "DPI-C" function int data_ram_read(input int addr);
  import "DPI-C" function void data_ram_write(
    input int  addr,
    input int  wdata,
    input byte we_7
  );

  // 读通道信号
  logic [ 3:0] r_state;
  logic [ 7:0] r_beat_count;  // 当前传输的节拍计数
  logic [ 7:0] r_total_beats;  // 总节拍数 (arlen + 1)
  logic [31:0] r_current_addr;  // 当前传输地址
  logic [ 2:0] r_size;  // 传输大小
  logic [ 1:0] r_burst_type;  // 突发类型

  // 写通道信号
  logic [ 3:0] w_state;
  logic [ 7:0] w_beat_count;  // 当前写入的节拍计数
  logic [ 7:0] w_total_beats;  // 总节拍数 (awlen + 1)
  logic [31:0] w_current_addr;  // 当前写入地址
  logic [ 2:0] w_size;  // 传输大小
  logic [ 1:0] w_burst_type;  // 突发类型

  // 计算下一个地址的函数
  function [31:0] get_next_addr(input [31:0] addr, input [2:0] size, input [1:0] burst_type,
                                input [7:0] beat);
    logic [31:0] increment;
    case (size)
      3'b000:  increment = 1;  // 1 byte
      3'b001:  increment = 2;  // 2 bytes
      3'b010:  increment = 4;  // 4 bytes
      3'b011:  increment = 8;  // 8 bytes
      3'b100:  increment = 16;  // 16 bytes
      3'b101:  increment = 32;  // 32 bytes
      3'b110:  increment = 64;  // 64 bytes
      3'b111:  increment = 128;  // 128 bytes
      default: increment = 4;
    endcase

    case (burst_type)
      2'b00:   get_next_addr = addr;  // FIXED - 地址不变
      2'b01:   get_next_addr = addr + increment;  // INCR - 递增
      2'b10: begin  // WRAP - 回环
        logic [31:0] wrap_boundary;
        logic [31:0] wrap_mask;
        wrap_boundary = increment * (w_total_beats);  // 回环边界
        wrap_mask = wrap_boundary - 1;
        get_next_addr = (addr & ~wrap_mask) | ((addr + increment) & wrap_mask);
      end
      default: get_next_addr = addr + increment;
    endcase
  endfunction

  // 读通道状态机
  always_ff @(posedge clock or posedge reset) begin
    if (reset) begin
      arready        <= 1'b0;
      rvalid         <= 1'b0;
      rdata          <= 32'b0;
      rresp          <= 2'b00;
      rlast          <= 1'b0;
      rid            <= 4'b0;
      r_state        <= 4'd0;
      r_beat_count   <= 8'd0;
      r_total_beats  <= 8'd0;
      r_current_addr <= 32'd0;
      r_size         <= 3'd0;
      r_burst_type   <= 2'd0;
    end else begin
      case (r_state)
        4'd0: begin  // 等待 arvalid
          arready <= 1'b0;
          rvalid  <= 1'b0;
          rlast   <= 1'b0;

          if (arvalid) begin
            arready        <= 1'b1;
            rid            <= arid;
            r_total_beats  <= arlen + 1;  // arlen=0表示1个节拍
            r_beat_count   <= 8'd0;
            r_current_addr <= araddr;
            r_size         <= arsize;
            r_burst_type   <= arburst;
            r_state        <= 4'd1;
          end
        end

        4'd1: begin  // 处理读传输
          arready <= 1'b0;
          rresp   <= 2'b00;  // OKAY响应
          if (rready) begin
            if (r_beat_count == (r_total_beats - 1)) begin
              rdata   <= data_ram_read(r_current_addr);
              rvalid  <= 1'b1;
              rlast   <= 1'b1;
              r_state <= 4'd0;
            end else begin
              // 不是最后一个节拍，准备下一个
              r_beat_count <= r_beat_count + 1;
              rdata <= data_ram_read(r_current_addr);
              rvalid <= 1'b1;
              r_current_addr <= get_next_addr(r_current_addr, r_size, r_burst_type, r_beat_count);
              rlast <= 1'b0;
            end
          end
        end

        default: begin
        end
      endcase
    end
  end

  // 写通道状态机
  wire [7:0] wstrb_1;  // 目标是扩展为 8 位
  assign wstrb_1 = {4'b0, wstrb};  // 高 4 位填充 0，低 4 位为 wstrb
  logic [3:0] state1;

  always_ff @(posedge clock or posedge reset) begin
    if (reset) begin
      // 初始化状态和信号
      awready <= 1'b0;
      wready  <= 1'b0;
      bvalid  <= 1'b0;
      bresp   <= 2'b00;
      bid     <= 4'b0;  // 修复：初始化 bid
      state1  <= 4'd0;
    end else begin
      case (state1)
        4'd0: begin  // 等待 awvalid
          awready <= 1'b0;
          wready  <= 1'b0;
          bvalid  <= 1'b0;

          if (awvalid) begin
            awready <= 1'b1;
            bid     <= awid;
            state1  <= 4'd1;
          end
        end

        4'd1: begin  // 等待 wvalid
          awready <= 1'b0;

          if (wvalid) begin
            data_ram_write(awaddr, wdata, wstrb_1);
            wready <= 1'b1;
            state1 <= 4'd2;
          end
        end

        4'd2: begin  // 写响应，发射信号并保持直到 bready
          wready <= 1'b0;
          bresp  <= 2'b00;  // 响应状态（OKAY）
          bvalid <= 1'b1;  // 准备写响应

          if (bready) begin
            bvalid <= 1'b0;
            state1 <= 4'd0;
          end
        end
        default: begin
        end
      endcase
    end
  end

  // 写通道状态机
  //   wire [7:0] wstrb_1;
  //   assign wstrb_1 = {4'b0, wstrb};

  //   always_ff @(posedge clock or posedge reset) begin
  //     if (reset) begin
  //       awready        <= 1'b0;
  //       wready         <= 1'b0;
  //       bvalid         <= 1'b0;
  //       bresp          <= 2'b00;
  //       bid            <= 4'b0;
  //       w_state        <= 4'd0;
  //       w_beat_count   <= 8'd0;
  //       w_total_beats  <= 8'd0;
  //       w_current_addr <= 32'd0;
  //       w_size         <= 3'd0;
  //       w_burst_type   <= 2'd0;
  //     end else begin
  //       case (w_state)
  //         4'd0: begin  // 等待 awvalid
  //           awready <= 1'b0;
  //           wready  <= 1'b0;
  //           bvalid  <= 1'b0;

  //           if (awvalid) begin
  //             awready        <= 1'b1;
  //             bid            <= awid;
  //             w_total_beats  <= awlen + 1;
  //             w_beat_count   <= 8'd0;
  //             w_current_addr <= awaddr;
  //             w_size         <= awsize;
  //             w_burst_type   <= awburst;
  //             w_state        <= 4'd1;
  //           end
  //         end

  //         4'd1: begin  // 处理写数据
  //           awready <= 1'b0;
  //           wready  <= 1'b1;  // 准备接收写数据
  //           if (wvalid) begin
  //             // 执行写操作
  //             data_ram_write(w_current_addr, wdata, wstrb_1);

  //             if (w_beat_count == (w_total_beats - 1)) begin
  //               // 最后一个写节拍
  //               w_state <= 4'd2;  // 转到写响应状态
  //               wready  <= 1'b0;
  //             end else begin
  //               // 不是最后一个节拍，准备下一个
  //               w_beat_count   <= w_beat_count + 1;
  //               w_current_addr <= get_next_addr(w_current_addr, w_size, w_burst_type, w_beat_count);
  //             end
  //           end
  //         end

  //         4'd2: begin  // 写响应
  //           wready <= 1'b0;
  //           bresp  <= 2'b00;  // OKAY响应
  //           bvalid <= 1'b1;

  //           if (bready) begin
  //             bvalid  <= 1'b0;
  //             w_state <= 4'd0;
  //           end
  //         end

  //         default: begin
  //         end
  //       endcase
  //     end
  //   end



endmodule
