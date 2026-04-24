# dcache_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/dcache_stub.v`
- 功能定位：数据侧 all-miss forwarding（单请求在途，支持读写）

## 接口与行为
- CPU 请求：`req_valid/req_write/req_addr/req_wdata/req_wstrb`
- CPU 响应：`req_ready/resp_valid/resp_rdata`
- AXI 侧：`axi_req_valid/axi_req_write/axi_req_addr/axi_req_wdata/axi_req_wstrb/axi_req_ready/axi_resp_valid/axi_resp_rdata`

工作机制：
1. `req_valid && req_ready` 时把请求发往 AXI。
2. AXI 接受后清 `axi_req_valid`，置 `waiting_resp`。
3. 收到 `axi_resp_valid` 后输出一拍 `resp_valid`。

约束：
- 单在途事务：`req_ready = ~axi_req_valid & ~waiting_resp`
- 不做 cache 命中判断与回填。

## 时序说明
- 读写都走“请求握手 + 返回握手”两段同步时序。
- 写请求的 `resp_rdata` 语义由上游 AXI 封装定义（在 `core_top` 中写回应答数据固定为 0）。
- 组合逻辑较浅，通常不构成主频瓶颈。

## 与 stage7_mem1 的配合
- `stage7_mem1` 会先锁存访存指令，再单拍发 `dcache_req_*`，然后等待 `resp_valid` 提交。
- 因此访存时延主要由 AXI 返回时间决定。
