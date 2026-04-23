# verilator_top 模块文档

- 源文件：`mycpu_env/myCPU/v_src/verilator_top.v`
- 模块定位：Verilator 仿真专用硬件顶层

## 1. 功能职责
- 例化 `core_top`（DUT）。
- 例化 `axi_ram`（AXI 从设备内存模型）。
- 连接 `core_top` 的 AXI 主口到 `axi_ram`。
- 暴露 `debug_wb_valid/debug_wb_*` 为 `verilator public`，供 C++ 侧读取 difftest 信息。

## 2. 关键连接
- `rst` 取反得到 `cpu_resetn`，连接 `core_top.aresetn`。
- `core_top.ar/aw/w/...` 全连接到 `axi_ram` 对应端口。
- `ws_valid` 连接为 `debug_wb_valid`，作为提交有效信号。
- `debug_wb_pc/debug_wb_rf_wen/debug_wb_rf_wnum/debug_wb_rf_wdata/debug_wb_inst` 供 `main.cpp` 读取。

## 3. 时序
- 自身无状态机。
- 纯连接层，时序由 `core_top` 与 `axi_ram` 决定。
