# csr_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/csr.v`
- 角色：CSR 空壳模块

## 功能
- 保留 CSR 访问接口。
- 对任意请求返回 `resp_valid=req_valid`，`resp_rdata=0`。

## 时序
- 请求后一拍给出响应（同步时序）。
