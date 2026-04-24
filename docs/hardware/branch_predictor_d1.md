# branch_predictor_d1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/branch_predictor_d1.v`
- 功能定位：1-entry BTB，查询固定 1 拍延迟的分支预测器

## 接口与行为
- 请求口：`req_valid/req_pc`
- 响应口：`resp_valid/pred_taken/pred_target`
- 更新口：`update_valid/update_taken/update_pc/update_target`

内部包含：
- 查询队列寄存器：`q_valid/q_pc`
- BTB 表项寄存器：`btb_valid/btb_pc/btb_target`

命中条件：
- `hit = btb_valid && (q_pc == btb_pc)`

预测输出：
- 命中：`pred_taken=1`，`pred_target=btb_target`
- 未命中：`pred_taken=0`，`pred_target=q_pc + 4`

更新策略：
- `update_valid=1` 时覆盖 BTB
- `update_taken=0` 会把 `btb_valid` 清零（相当于失效该表项）

## 时序说明
- 查询路径全寄存化：`req_*` 在第 N 拍进入 `q_*`，第 N+1 拍给 `resp_*`。
- 更新与查询同拍可并行，更新结果从下一拍开始影响命中。
- 组合路径很短，通常不是主频瓶颈。

## 时序风险与建议
- 仅 1-entry BTB，冲突率高时预测命中率受限，但对时序友好。
- 若后续扩展多表项，建议保持“查询结果寄存后输出”的接口时序，不要把比较链直接拉到 IFU 组合路径中。
