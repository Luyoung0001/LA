# stage6_ex2 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage6_ex2.v`
- 功能定位：执行二级（分支决策 + mul/div 请求封装）

## 功能行为
- 根据 `in_inst[31:26]` 判定 `jirl/b/bl/beq/bne`。
- 分支是否跳转：
  - 无条件：`b/bl/jirl`
  - 条件：`beq(in_op1==in_op2)`、`bne(in_op1!=in_op2)`
- 分支目标：
  - `jirl`：`in_op1 + in_imm`
  - 其他分支：`in_pc + in_imm`
- mul/div 请求：`in_valid && in_is_muldiv` 时发 `muldiv_req_*`。
- 默认结果：`out_result = in_alu_result`（muldiv 指令先给 0，待响应覆盖）。

## 时序语义
- 分支决定与结果寄存同拍完成，下一拍反馈到 IFU 重定向路径。
- `muldiv_resp_valid` 到达拍会覆盖 `out_result`。

## 时序风险
- 分支比较是 32 位等值比较，组合深度中等。
- 当前全局关键路径不在本级，但分支反馈链路影响前端 redirect 延迟感知。
