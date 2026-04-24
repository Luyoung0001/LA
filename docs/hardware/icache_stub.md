# icache_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/icache_stub.v`
- 功能定位：指令侧 all-miss forwarding（单请求在途）

## 接口与行为
- CPU 请求：`req_valid/req_addr`
- CPU 响应：`req_ready/resp_valid/resp_data`
- AXI 侧：`axi_req_valid/axi_req_addr/axi_req_ready/axi_resp_valid/axi_resp_data`

工作机制：
1. `req_valid && req_ready` 时锁存并发出 `axi_req_valid`。
2. `axi_req_valid && axi_req_ready` 后进入 `waiting_resp`。
3. `waiting_resp && axi_resp_valid` 时拉高一拍 `resp_valid` 并返回 `resp_data`。

约束：
- 单在途事务：`req_ready = ~axi_req_valid & ~waiting_resp`
- 不做命中判断，不缓存数据。

## 时序说明
- 最短延迟通常为 2 拍以上（请求拍 -> AXI 接受拍 -> AXI 返回拍）。
- 所有关键状态寄存于时钟边沿，无长组合回路。
- 本模块不是当前主频关键路径，瓶颈主要在 EX1 组合计算。

## 系统级时序影响
- IF2 只有在 `resp_valid` 到达时才输出 `out_valid`，因此取指时延由 AXI 返回决定。
- 因 `core_top` 的 `issue_busy_r` 机制，前端不会并发堆积多条请求。
