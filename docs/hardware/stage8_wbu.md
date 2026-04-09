# stage8_wbu 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage8_wbu.v`
- 角色：写回级 + 调试提交级

## 功能
- `wen_real = in_valid && in_wen && (in_rd != 0)`。
- 输出寄存器写回端口：`rf_we/rf_waddr/rf_wdata`。
- 输出提交调试信息：`ws_valid/debug_wb_*`。

## 时序
- 所有写回与 debug 在时钟上升沿产生。
- `debug_wb_rf_wen` 采用 4bit 扩展 `{4{wen_real}}`，兼容 difftest 检查逻辑。
