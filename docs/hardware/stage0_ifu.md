# stage0_ifu 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage0_ifu.v`
- 角色：取指前端 PC 产生

## 功能
- 维护当前 `pc_r`。
- 向分支预测器发 `bp_req_pc`。
- 产生 `out_pc` 给 IF1。

## 时序
- 每拍都输出当前 `pc_r`。
- PC 更新优先级：
  1. `redirect_valid`：PC 跳转到 `redirect_pc`。
  2. `hold`：PC 保持不变。
  3. `bp_resp_valid && bp_pred_taken`：PC 跳到预测目标。
  4. 默认 `pc + 4`。
- `bp_resp_*` 为 1 拍延迟预测返回模型。
