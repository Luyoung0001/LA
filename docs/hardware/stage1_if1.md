# stage1_if1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage1_if1.v`
- 功能定位：取指请求发射级（IF1）

## 功能
- 把 `in_pc` 直接作为 `icache_req_addr` 发起请求。
- 同拍寄存并透传 `out_valid/out_pc` 给 IF2。

## 时序语义
- 纯时序寄存级：
  - `icache_req_valid <= in_valid`
  - `icache_req_addr <= in_pc`
  - `out_valid <= in_valid`
  - `out_pc <= in_pc`

## 与上下游关系
- 上游由 `issue_fire_w` 控制 `in_valid`。
- 下游 IF2 负责等待真正的 ICache/AXI 返回。

## 时序风险
- 组合逻辑极少，通常不构成时序瓶颈。
