// fixed_delay_3.v
// 一个固定延迟模块 (3个周期)
// 接收 start_i 信号，延迟 3 个周期后发出 stop_over_o 单周期脉冲

module fixed_delay_3 (
  input wire        clk_i,      // 时钟信号
  input wire        rst_n_i,    // 复位信号 (低电平有效)
  input wire        start_i,    // 启动延迟信号

  output reg        stop_over_o // 延迟结束后发出的单周期脉冲信号
);

// 延迟计数器
// 我们需要计数 3 个延迟周期。
// 如果从 0 开始计数到 2，然后在计数器将变为 3 的那个周期触发输出，
// 那么计数器需要能表示 0, 1, 2。2 bits ([1:0]) 可以表示 0到3。
// 让我们计数 0, 1, 2，然后在计数器为 2 时触发下一个周期的输出。
reg [1:0] delay_count;

//----------------------------------------------------------------
// 主时序逻辑
// 在每个时钟上升沿或复位信号下降沿更新状态和输出
//----------------------------------------------------------------
always @(posedge clk_i or negedge rst_n_i) begin
  if (!rst_n_i) begin
    // 复位时，计数器清零，输出为低
    delay_count <= 2'b00;
    stop_over_o <= 1'b0;
  end else begin
    // 默认情况下，输出为低，除非在完成周期被置高
    stop_over_o <= 1'b0;

    // 根据当前计数器状态和 start_i 信号更新计数器和输出
    case (delay_count)
      2'b00: begin // 空闲状态 (计数器为 0)
        if (start_i) begin
          // 接收到启动信号，开始计数 (下一个周期计数器变为 1)
          delay_count <= 2'b01;
        end else begin
          // 没有启动信号，保持在 0
          delay_count <= 2'b00;
        end
      end
      2'b01: begin // 计数到 1 (第一个延迟周期结束)
        // 计数到 2 (下一个周期计数器变为 2)
        delay_count <= 2'b10;
      end
      2'b10: begin // 计数到 2 (第二个延迟周期结束)
        // 计数到 3 (下一个周期计数器将变为 3)
        // 表示 3 个延迟周期已过
        delay_count <= 2'b11; // 计数到 3
      end
      2'b11: begin // 计数到 3 (第三个延迟周期结束，完成周期)
        // 延迟完成，回到空闲状态 (下一个周期计数器变为 0)
        delay_count <= 2'b00;
        // 在本周期拉高输出信号 stop_over_o
        stop_over_o <= 1'b1;
      end
    endcase
  end
end

endmodule