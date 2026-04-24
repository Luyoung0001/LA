# regfile_d1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/regfile_d1.v`
- 功能定位：32x32 GPR，单写口、双读口，读延迟 1 拍

## 接口与行为
- 读请求：`rreq_valid/raddr1/raddr2`
- 读响应：`rvalid/rdata1/rdata2`
- 写口：`we/waddr/wdata`
- 调试读口：`dbg_raddr -> dbg_rdata`

行为规则：
- `x0` 恒为 0（读路径强制返回 0，写入 `waddr==0` 被忽略）。
- `rvalid` 为 `rreq_valid` 延迟 1 拍。
- 复位时所有寄存器清零。

## 时序语义
- 读写都在 `posedge clk`。
- 同拍读写同地址时，当前实现是“读旧值”语义（先用旧数组值采样到 `rdata*`，写入在拍末更新）。
- 与 `stage3_idu -> stage4_rrd` 的接口是严格 1 拍对齐关系。

## 时序风险与建议
- 当前规模下 regfile 不是主频瓶颈。
- 若未来加入前递旁路，可在 `rreq_valid` 路径上增加组合选择器，建议评估对 `stage4` 输入扇出的影响。
