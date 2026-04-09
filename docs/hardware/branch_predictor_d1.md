# branch_predictor_d1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/branch_predictor_d1.v`
- 角色：1 拍延迟 BTB 预测器

## 功能
- `req_pc` 进入队列寄存器 `q_pc`。
- 下一拍输出 `resp_valid` 与预测结果。
- 命中条件：`btb_valid && (q_pc == btb_pc)`。
- 更新策略：`update_valid` 时写 BTB；`update_taken=0` 会清空 `btb_valid`。

## 时序
- 预测固定延迟 1 拍。
- 更新与查询可在同一时钟域并行进行。
