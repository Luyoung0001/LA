# stage7_mem1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage7_mem1.v`
- 功能定位：访存一级（请求发射 + 等待返回 + 写回数据整理）

## 内部状态
- `pend_valid`：是否有 pending 访存
- `pend_req_sent`：是否已发送请求
- `pend_*`：缓存当前访存指令上下文

## 行为流程
- 非访存指令（`!in_is_load && !in_is_store`）：
  - 直接旁路到输出，`out_valid=1`。
- 访存指令：
  1. 先缓存到 `pend_*`。
  2. 下一拍发送 `dcache_req_*`（仅 1 拍脉冲）。
  3. 等待 `dcache_resp_valid`。
  4. 返回后提交：
     - load：`out_wb_data = dcache_resp_data`
     - store：`out_wb_data = pend_result`，`out_wen=0`

## 写回使能规则
- 非访存：`out_wen = ~(inst_b | inst_beq | inst_bne)`
- load：`out_wen = 1`
- store：`out_wen = 0`

## 时序语义
- 访存指令至少多 1 拍（进入 pending）+ 外设返回拍。
- 控制状态均寄存化，组合路径较短。
- 由于单 pending 设计，不存在多请求乱序返回问题。

## 时序风险
- 本级通常不是关键路径；性能瓶颈更多来自外部 AXI 返回延迟。
