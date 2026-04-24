# stage0_ifu 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage0_ifu.v`
- 功能定位：PC 维护与取指发起（IFU）

## 主要寄存器
- `pc_r`：当前 PC

## 每拍行为
- 输出：`out_valid<=1`、`out_pc<=pc_r`
- 同时向预测器发请求：`bp_req_valid<=1`、`bp_req_pc<=pc_r`

PC 更新优先级（高到低）：
1. `redirect_valid`：`pc_r <= redirect_pc`
2. `hold`：`pc_r` 保持
3. `bp_resp_valid && bp_pred_taken`：`pc_r <= bp_pred_target`
4. 默认顺序流：`pc_r <= pc_r + 4`

## 时序说明
- 所有状态在上升沿更新，无跨拍组合反馈。
- 分支重定向在当前拍决定、下一拍体现在 `out_pc`（1 拍可见延迟）。
- `hold` 与 `issue_busy_r` 联动，保证单在途发射模型下 PC 不“空转前进”。

## 时序风险
- 模块本身逻辑浅，不是关键路径。
- 若后续在 IFU 内增加更复杂预测融合逻辑，建议继续保持“PC 更新寄存边界”不变。
