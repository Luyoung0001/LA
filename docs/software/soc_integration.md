# 软件 SoC 如何连接 mycpu

- 关联目录：`mycpu_env/myCPU`（硬件 + DPI）与 `Verilator`（仿真驱动）
- 目标：说明 `core_top` 如何经由 `axi_ram + DPI-C + memory` 接到软件 SoC

## 1. 编译连接关系
- 顶层 `Makefile` 会把以下源一起交给 Verilator：
  - Verilog：`mycpu_env/myCPU/v_src/*.v`
  - SystemVerilog：`mycpu_env/myCPU/DPIC/*.sv`
  - DPI C++：`mycpu_env/myCPU/DPIC_C/src/*.cpp`
  - Memory C：`mycpu_env/myCPU/memory/src/*.c`
  - 仿真主程序：`Verilator/*.cpp`
- 因此，硬件模型与软件内存模型在同一仿真可执行文件中联编。

## 2. 取指/访存链路
```mermaid
flowchart LR
    C[core_top AXI master] --> V[verilator_top]
    V --> A[axi_ram.sv]
    A -->|DPI-C| D[dpi_c.cpp]
    D --> P[paddr.c]
    P --> M[pmem 4GB]
    M -->|load_inst @0x1c000000| B[main.bin]
```

## 3. 时序分解（读）
1. `core_top` 发 `AR` 请求（`arvalid/araddr`）。
2. `axi_ram` 在握手后进入读状态，等待 `rready`。
3. 满足发送条件时调用 `data_ram_read(addr)`（DPI）。
4. `dpi_c.cpp` 转发到 `paddr_read`，从 `pmem` 取 32 位数据。
5. `axi_ram` 把数据放到 `rdata/rvalid` 返回 CPU。

## 4. 时序分解（写）
1. `core_top` 先发 `AW`，再发 `W`（含 `wstrb`）。
2. `axi_ram` 在 `W` 握手时调用 `data_ram_write(addr, wdata, wmask)`。
3. `dpi_c.cpp` 进行按字节掩码合成后调用 `paddr_write`。
4. `axi_ram` 返回 `B` 响应给 CPU，CPU 将该次存储视为完成。

## 5. 与差分测试的耦合
- `Verilator/main.cpp` 每周期读取 `verilator_top` 对外公开的 `debug_wb_*`。
- 这些信号来自 `core_top -> stage8_wbu` 的提交信息。
- 主程序把提交流与 `golden_trace.txt` 对齐比较，形成软件 SoC 的正确性闭环。

## 6. 当前框架特性
- `axi_ram` 是仿真内存从设备，不是完整外设总线系统。
- `dpi_c.cpp` 只实现了少量 MMIO 特例，其余地址统一走 `pmem`。
- 该结构适合快速 bring-up 和流水线联调，后续可在此基础上扩展真实 SoC 外设模型。
