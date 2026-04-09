# icache_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/icache_stub.v`
- 角色：指令缓存空壳（未接当前主链路）

## 功能
- `req_ready` 恒为 1。
- 请求地址打一拍后输出 `resp_valid`。
- `resp_data` 根据 `pend_addr[5:2]` 返回少量硬编码样例指令。

## 时序
- 请求到响应固定 1 拍。
- 当前 `core_top` 走 AXI 取指，不经过此模块。
