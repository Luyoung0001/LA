# dcache_stub 模块文档

- 源文件：`mycpu_env/myCPU/v_src/dcache_stub.v`
- 角色：数据缓存空壳（未接当前主链路）

## 功能
- 内部 256 深度 `ram`。
- `req_ready` 恒为 1。
- 请求打一拍后 `resp_valid`。
- 写请求按 `pend_wstrb` 非零判断写入；读返回 `ram[addr]`。

## 时序
- 请求到响应固定 1 拍。
- 当前 `core_top` 走 AXI 访存，不经过此模块。
