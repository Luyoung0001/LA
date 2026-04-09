# muldiv_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/muldiv_stub.v`
- 角色：乘除法器空壳

## 功能
- 接收 `req_valid` 与操作数。
- 一拍后输出 `resp_valid`。
- `resp_result` 固定为 `0`。

## 时序
- `pend_valid <= req_valid`。
- 下一拍 `resp_valid <= pend_valid`。
