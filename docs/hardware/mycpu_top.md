# mycpu_top 模块文档

- 源文件：`mycpu_env/myCPU/v_src/mycpu_top.v`（`module mycpu_top`）
- 功能定位：面向板级接口的轻量 wrapper

## 接口职责
- 透传 AXI 主口：`ar*/r*/aw*/w*/b*`
- 输出调试写回口：`debug_wb_pc/debug_wb_rf_we/debug_wb_rf_wnum/debug_wb_rf_wdata`

## 内部连接
- 仅例化 `core_top`，并做固定输入绑定：
  - `intrpt = 8'b0`
  - `break_point = 1'b0`
  - `infor_flag = 1'b0`
  - `reg_num = 5'b0`
- `core_top.debug0_wb_inst` 接到本地未使用线 `debug_wb_inst_unused`。

## 时序说明
- 本模块无状态机、无寄存器。
- 时序表现完全继承 `core_top`。

## 使用建议
- 板级工程需要标准 `debug_wb_*` 命名时，优先实例化 `mycpu_top`。
- 仿真（如 Verilator）可直接实例化 `core_top` 以保留更多调试端口。
