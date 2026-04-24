# stage4_rrd 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage4_rrd.v`
- 功能定位：寄存器读数据对齐级（RRD）

## 内部结构
- 元信息打一拍：`meta_*_d1`
- 读数据来自 `regfile_d1` 的 `rf_rdata1/rf_rdata2`

## 提交流程
- 每拍先缓存 IDU 元信息到 `meta_*_d1`。
- 仅当 `meta_valid_d1 && rf_rvalid` 时输出：
  - `out_op1 <= rf_rdata1`
  - `out_op2 <= rf_rdata2`
  - 同步输出 `out_pc/out_inst/out_rd/out_imm/...`

## 时序语义
- 明确寄存器边界：IDU 与 EX1 之间通过本级切断。
- 有效位门控提交，避免读端口未就绪导致脏数据下传。

## 与全局时序的关系（重点）
根据 `2026-04-24` 的实现后报告：
- 多条最差路径从本级寄存器发起，终止于 EX1 的 `out_alu_result_reg[*]`。
- 典型起点：`u_stage4_rrd/out_op1_reg[*]`、`u_stage4_rrd/out_inst_reg[*]`。
- `high_fanout.rpt` 显示 `out_inst` 若干位扇出可达 `95~112`，会放大路由延迟。

## 优化方向
- 把 EX1 重复指令解码前移到 IDU，并以紧凑控制信号跨级传递，减少 `out_inst` 高扇出。
- 对热点控制网做寄存复制/扇出约束，缓解路由型时序压力。
