# axi_ram 模块文档

- 源文件：`mycpu_env/myCPU/DPIC/axi_ram.sv`
- 角色：AXI 从设备内存模型（仿真 SoC）

## 功能
- 实现 AXI4 读写通道状态机。
- 读数据由 DPI-C `data_ram_read(addr)` 提供。
- 写数据通过 DPI-C `data_ram_write(addr, wdata, wmask)` 落到软件内存。

## 读通道时序
- 状态：`r_state: 0(等待AR) -> 1(发R)`。
- 接收到 `arvalid` 后锁存 `arid/araddr/arlen/arsize/arburst`。
- 在 `rready` 条件下逐 beat 返回 `rdata/rvalid`。
- 最后一个 beat 置 `rlast=1`，回到空闲。

## 写通道时序
- 状态：`w_state: 0(等待AW) -> 1(收W) -> 2(发B)`。
- 接收到 `awvalid` 后锁存写突发参数。
- `wvalid` 到达时调用 `data_ram_write`。
- 最后 beat 后进入 `B` 响应，等待 `bready` 完成事务。

## 备注
- 支持 `FIXED/INCR/WRAP` 地址前进（通过 `get_next_addr`）。
- 该模块是 CPU AXI 接口到软件内存的核心桥。
