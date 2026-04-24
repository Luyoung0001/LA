# muldiv_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/muldiv_stub.v`
- 功能定位：乘除法占位单元（固定 1 拍响应，结果恒 0）

## 接口与行为
- 输入：`req_valid/req_is_div/req_signed/req_op1/req_op2`
- 输出：`resp_valid/resp_result`

当前实现：
- `pend_valid <= req_valid`
- `resp_valid <= pend_valid`
- `resp_result <= 32'b0`

即：请求后下一拍给有效响应，但结果固定 0。

## 时序说明
- 全寄存路径，无复杂组合运算。
- 该模块本身不会形成主频关键路径。

## 注意事项
- `stage6_ex2` 在 `muldiv_resp_valid=1` 时会覆盖 `out_result`，接真实乘除器时需保证响应与指令上下文严格对齐。
