# stage6_ex2 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage6_ex2.v`
- 角色：执行二级（分支决策 + mul/div 请求）

## 功能
- 分支判定：
  - 无条件：`b/bl/jirl`
  - 条件：`beq/bne` 比较 `in_op1/in_op2`
- 分支目标：
  - `jirl`：`in_op1 + in_imm`
  - 其余：`in_pc + in_imm`
- 乘除空壳请求：`in_is_muldiv` 时发 `muldiv_req_*`。

## 时序
- 分支更新信号在输入有效拍输出到 BP：`branch_update_valid/branch_taken/branch_target`。
- 非 muldiv 时 `out_result = in_alu_result`。
- muldiv 返回时（`muldiv_resp_valid`）覆盖 `out_result`。
