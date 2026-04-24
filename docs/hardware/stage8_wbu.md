# stage8_wbu 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage8_wbu.v`
- 功能定位：写回级（GPR 写回 + 提交调试口）

## 核心逻辑
- `wen_real = in_valid && in_wen && (in_rd != 0)`
- GPR 写回：
  - `rf_we <= wen_real`
  - `rf_waddr <= in_rd`
  - `rf_wdata <= in_wb_data`
- 提交调试：
  - `ws_valid <= in_valid`
  - `debug_wb_rf_wen <= {4{wen_real}}`
  - 其余调试字段透传

## 时序语义
- 全部输出在上升沿寄存。
- `ws_valid` 与 `rf_we` 语义不同：
  - `ws_valid` 表示“有指令提交”
  - `rf_we` 表示“有寄存器写回”

## 时序风险
- 纯寄存输出级，组合路径极短，通常不构成时序瓶颈。
