# csr_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/csr.v`
- 功能定位：CSR 占位模块（当前不实现真实 CSR 读写）

## 接口与行为
- 输入：`req_valid/req_write/req_addr/req_wdata`
- 输出：`resp_valid/resp_rdata`

当前行为：
- `resp_valid <= req_valid`
- `resp_rdata <= 32'b0`

即：只做“请求存在性应答”，不区分地址，不保存写入数据。

## 时序说明
- 全同步时序，1 拍响应模型。
- 第 N 拍 `req_valid=1`，第 N+1 拍 `resp_valid=1`。
- 无复杂组合逻辑，几乎不影响全局主频。

## 后续接入真实 CSR 的建议
- 若增加 CSR 译码与旁路，建议把“译码 + 读数据多路选择”拆为两拍，避免 EX2/WB 路径被拉长。
