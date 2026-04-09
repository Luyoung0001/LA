# dpi_c.cpp 模块文档

- 源文件：`mycpu_env/myCPU/DPIC_C/src/dpi_c.cpp`
- 头文件：`mycpu_env/myCPU/DPIC_C/include/dpi_c.h`
- 模块定位：SystemVerilog DPI 与 C 内存模型之间的桥接层

## 1. 功能职责
- 对外提供 DPI 接口：`inst_ram_read`、`data_ram_read`、`data_ram_write`。
- 将读写请求转发到 `paddr_read/paddr_write`。
- 处理仿真 MMIO 特例地址（例如 `VIRTUAL_UART_ADDR`、`OPEN_TRACE_ADDR`、`SW_INTER_ADDR`）。
- 对写请求执行按字节掩码的 read-modify-write。

## 2. 关键接口
- `int inst_ram_read(int addr)`：取指读，直接走 `paddr_read(addr)`。
- `int data_ram_read(int addr)`：数据读，先处理 MMIO，再走 `paddr_read(addr)`。
- `void data_ram_write(int addr, int wdata, unsigned char wmask)`：
  - 若地址是 `VIRTUAL_UART_ADDR`，按掩码提取字符并打印。
  - 否则先读旧值，再根据 `wmask` 合成新值后写回 `paddr_write`。

## 3. 地址行为
- 代码中定义了板级外设地址（LED、数码管、按键、开关、中断寄存器等）。
- 当前实现真正生效的读特例：
  - `SW_INTER_ADDR -> 0x0000aaaa`
  - `OPEN_TRACE_ADDR -> 0x00000001`
- 其余大多回落到统一 `paddr` 内存空间。

## 4. 时序说明
- 调用发起端：
  - `axi_ram.sv` 的读状态机在 `rready` 握手时调用 `data_ram_read`。
  - `axi_ram.sv` 的写状态机在 `wvalid&wready` 时调用 `data_ram_write`。
- DPI 函数本身是“调用即返回”的组合软件路径，不额外引入 Verilog 拍延迟。
- 系统层面的读写延迟由 `axi_ram` 状态机与 CPU AXI 握手决定，不由 `dpi_c.cpp` 决定。

## 5. 约束与注意点
- `data_ram_write` 仅处理常见字节掩码组合（`1/2/4/8/3/6/12/15`）。
- 非自然对齐的半字访问在注释中标注为“应由 CPU 侧提前例外处理”。
- 当前实现保留了调试打印，长测时可能影响仿真速度。
