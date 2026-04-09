# mycpu_top 模块文档

- 源文件：`mycpu_env/myCPU/v_src/mycpu_top.v`
- 模块定位：SoC 侧包装壳

## 1. 功能职责
- 作为外部可见 CPU 顶层。
- 直接例化 `core_top`，主要做端口透传。
- 将 `core_top` 的 `debug0_wb_*` 映射成 `debug_wb_*` 风格信号。

## 2. 时序
- 无独立状态机。
- 所有时序行为来自内部 `core_top`。

## 3. 使用建议
- 在仿真/板级环境中优先连接 `mycpu_top`（若接口要求是 `debug_wb_*` 命名）。
- 当前工程 `verilator_top` 直接连 `core_top`，也可改连 `mycpu_top`。
