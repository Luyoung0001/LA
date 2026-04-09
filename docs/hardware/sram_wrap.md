# sram_wrap 模块文档

- 源文件：`mycpu_env/myCPU/DPIC/sram_wrap.v`
- 角色：SRAM-like 到 RAM 端口包装（带返回缓冲）

## 功能
- 将 `req/wr/size/wstrb/addr/wdata` 转为 `ram_en/ram_we/ram_addr/ram_wdata`。
- 提供 `addr_ok/data_ok/rdata` 语义。
- 内部用小 FIFO（`buf_wptr/buf_rptr/buf_rdata`）缓存返回数据。

## 时序
- `addr_ok`：地址通道可接收时拉高（受 `buf_full` 限制）。
- `data_ok`：有可返回数据时拉高（`!buf_empty || ram_en_r`）。
- `rdata`：优先返回新鲜 `ram_rdata`，否则返回 FIFO 中缓存值。

## 备注
- 当前 AXI 主路径下未启用该模块，但它保留了 SRAM-like 适配能力。
