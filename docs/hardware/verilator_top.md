# verilator_top 模块文档

- 源文件：`mycpu_env/myCPU/v_src/verilator_top.v`
- 功能定位：Verilator 仿真顶层（DUT + 内存模型）

## 组成
- DUT：`core_top`
- 内存模型：`axi_ram`

## 关键连接
- 复位：`cpu_resetn = ~rst`，送入 `core_top.aresetn`
- AXI：`core_top` 主口全连接到 `axi_ram` 从口
- 提交调试信号（`/* verilator public */`）：
  - `debug_wb_valid`
  - `debug_wb_pc`
  - `debug_wb_rf_wen`
  - `debug_wb_rf_wnum`
  - `debug_wb_rf_wdata`
  - `debug_wb_inst`

## 时序说明
- 本模块主要是连线层，无额外时序状态。
- 仿真中的周期行为由 `core_top` 与 `axi_ram` 决定。

## 调试建议
- C++ testbench 可直接读取上述 public 信号进行提交比对（difftest/trace）。
- 若要分析性能瓶颈，应聚焦 `core_top` 流水和 AXI 返回时延。
