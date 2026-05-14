# LA 处理器详细设计与落地方案

本文档基于 `plan.md` 的目标微架构，并结合当前仓库 RTL、文档和验证链路整理而成。原 `plan.md` 更偏高性能目标描述，本文档更偏工程实施方案：先给出当前基线，再给出可分阶段落地的处理器设计、模块接口、关键状态机、验证路径和风险控制。

## 1. 设计目标

### 1.1 总体目标

本项目目标是实现一颗面向 LoongArch 32 位教学/竞赛场景的顺序处理器核心，具备可持续扩展的流水线、动态 difftest 验证链路和 Vivado 频率评估链路。最终形态参考 `plan.md` 中提出的双发射、分支预测、L1 I/D Cache、Store Buffer、L2 Cache 等高性能组件，但落地顺序应以正确性和可验证性优先。

当前仓库已经具备：

- `stage0_ifu` 到 `stage8_wbu` 的 9 级流水骨架。
- `branch_predictor_d1` 的 1 拍预测返回模型。
- `regfile_d1` 的 1 拍寄存器读取模型。
- `icache_stub`、`dcache_stub` 到 AXI 的 all-miss forwarding 模型。
- `core_top` 内部 AXI 仲裁状态机。
- Verilator + DPI-C + NEMU 动态 difftest 链路。
- Vivado 时序脚本 `scripts/synth_timing.tcl`。

本文档建议的落地路线是：

1. 稳定当前单发射单在途基线。
2. 改造为真正可停顿/可冲刷的单发射流水线。
3. 扩展指令集、异常/CSR、乘除法和访存粒度。
4. 引入 ICache/DCache、Store Buffer 和更强分支预测。
5. 在单发射稳定后再演进到双发射。

### 1.2 优先级原则

| 优先级 | 原则 | 说明 |
| --- | --- | --- |
| P0 | 功能正确 | 每个阶段必须能通过 `make all EXP=...` 和动态 difftest。 |
| P1 | 可观察 | 每条提交指令必须有准确的 `debug_wb_*` 信息。 |
| P2 | 可停顿 | 流水线必须支持 cache miss、load-use、mul/div 等真实停顿。 |
| P3 | 可冲刷 | 分支预测错误、异常和中断必须能统一冲刷年轻指令。 |
| P4 | 可扩展 | 控制信号用结构化 bus 或明确字段传递，避免每级重复译码。 |
| P5 | 性能提升 | 在功能稳定后引入 cache、旁路、双发射和预测器优化。 |

### 1.3 推荐阶段目标

| 阶段 | 目标 | 通过标准 |
| --- | --- | --- |
| S0 | 清理并固化当前基线 | EXP=6 可通过，`make fmax` 可生成报告。 |
| S1 | 单发射多在途流水线 | 去掉 `issue_busy_r` 的全局单在途限制，通过基础算术/访存/分支测试。 |
| S2 | 完整冒险处理 | RAW、load-use、分支冲刷、访存等待均正确。 |
| S3 | 指令集扩展 | 覆盖 `func/inst` 中更多 EXP 指令。 |
| S4 | Cache 和 Store Buffer | I/D cache hit/miss 正确，store/load 顺序正确。 |
| S5 | CSR/异常/TLB 骨架 | CSR、异常返回、地址转换基础正确。 |
| S6 | 双发射 | 单周期最多提交 2 条，保持顺序提交和精确异常。 |

## 2. 当前工程基线

### 2.1 文件与模块对应

| 模块 | 文件 | 当前定位 |
| --- | --- | --- |
| 顶层核心 | `rtl/mycpu_top.v` 中的 `core_top` | 串接流水线、AXI 仲裁、调试接口。 |
| 兼容包装 | `rtl/mycpu_top.v` 中的 `mycpu_top` | 对接 SoC/仿真外壳。 |
| 取指 PC | `stage0_ifu.v` | PC 生成、预测响应使用、重定向。 |
| 取指请求 | `stage1_if1.v` | 产生 ICache 请求。 |
| 取指返回 | `stage2_if2.v` | 等待指令返回并输出。 |
| 译码 | `stage3_idu.v` | 解码少量 LA32 指令，产生寄存器读地址和基础控制位。 |
| 读寄存器对齐 | `stage4_rrd.v` | 对齐 1 拍寄存器堆返回数据。 |
| 执行 1 | `stage5_ex1.v` | ALU、地址计算、link 结果。 |
| 执行 2 | `stage6_ex2.v` | 分支决策、预测器更新、乘除接口占位。 |
| 访存 | `stage7_mem1.v` | 发 DCache 请求、等待返回、产生写回数据。 |
| 写回 | `stage8_wbu.v` | 写 GPR，产生 `debug_wb_*`。 |
| 分支预测 | `branch_predictor_d1.v` | 单项 BTB，1 拍响应。 |
| 寄存器堆 | `regfile_d1.v` | 2 读 1 写，读延迟 1 拍。 |
| ICache 占位 | `icache_stub.v` | 单请求 all-miss 转 AXI。 |
| DCache 占位 | `dcache_stub.v` | 单请求 all-miss 转 AXI。 |
| 乘除占位 | `muldiv_stub.v` | 1 拍空壳结果。 |
| CSR 占位 | `csr.v` | CSR stub。 |

### 2.2 当前控制模型

当前 `core_top` 使用 `issue_busy_r` 做全局单在途控制：

- `issue_fire_w = ifu_out_valid_w && !issue_busy_r`
- 指令发射后 `issue_busy_r` 置 1。
- 写回阶段 `wbu_ws_valid_w` 后清 0。

该模型优点是简单，避免 RAW、结构冲突、访存等待和分支冲刷的复杂组合问题。缺点是 IPC 极低，流水级大部分时间为空，无法体现 9 级流水的性能优势。后续设计应把它替换为标准的 valid/ready 或 valid/allowin 流水控制。

### 2.3 当前 AXI 模型

`core_top` 内部 AXI 状态机只支持单个在途事务：

- 取指读：`AXI_I_AR -> AXI_I_R`
- 数据读：`AXI_D_AR -> AXI_D_R`
- 数据写：`AXI_D_AW -> AXI_D_W -> AXI_D_B`
- 仲裁策略：I-side 优先于 D-side。

这适合作为最小可运行基线。引入 cache 后，AXI 状态机应逐步改造为 cache line 填充和写回接口，支持 burst 读写，至少支持 ICache miss 和 DCache miss 的请求仲裁。

### 2.4 当前主要短板

| 短板 | 影响 | 建议处理阶段 |
| --- | --- | --- |
| 全局单在途 | IPC 接近串行执行 | S1 |
| 控制信号过少 | EX 阶段重复译码，时序和维护压力大 | S1 |
| 缺少旁路 | 多在途后会出现 RAW 错误 | S2 |
| 缺少 load-use stall | load 后立即使用会错误 | S2 |
| 分支无预测正确性标记 | 目前每个分支都重定向，预测器语义不完整 | S2 |
| I/D cache 是 all-miss stub | 性能受 AXI 延迟限制 | S4 |
| 乘除/CSR/TLB 是 stub | 高级 EXP 无法完整通过 | S3/S5 |
| 访存只覆盖 word 粒度 | byte/halfword/load unsigned/store mask 未完成 | S3 |

## 3. 总体微架构方案

### 3.1 推荐核心形态

短中期采用单发射、顺序执行、顺序提交的 9 级流水：

```text
S0 IFU  : PC 选择、重定向、预测请求
S1 IF1  : 发起取指请求
S2 IF2  : 指令返回、fetch buffer 输出
S3 IDU  : 译码、立即数、源/目的寄存器、控制 bus
S4 RRD  : 寄存器读返回、旁路选择、冒险检查
S5 EX1  : ALU、地址计算、部分分支比较
S6 EX2  : 分支确认、乘除/多周期单元握手
S7 MEM  : DCache、Store Buffer、访存对齐
S8 WBU  : 顺序提交、写回、debug/difftest
```

长期可在 S3/S4 之间扩展双发射 issue，并复制部分执行资源：

```text
Fetch 2 inst/cycle -> Decode 2 -> Issue 0/1/2 -> ALU0 + ALU1/BR + LSU + MDU -> In-order Commit
```

### 3.2 基本数据通路

```text
PC/BPU
  -> ICache or AXI fetch
  -> Fetch Buffer
  -> Decode
  -> Regfile read
  -> Bypass / Scoreboard
  -> ALU / Branch / LSU / MDU / CSR
  -> DCache or Store Buffer
  -> Writeback / Commit
  -> Difftest debug
```

### 3.3 指令信息包设计

后续不要让 EX/MEM/WB 重复从 `inst[31:0]` 解码所有控制信号。建议在 IDU 生成统一的 micro-op 信息包，在各级寄存传递。

推荐字段：

| 字段 | 位宽 | 说明 |
| --- | --- | --- |
| `valid` | 1 | 本 uop 有效。 |
| `pc` | 32 | 指令 PC。 |
| `inst` | 32 | 原始指令，用于 debug 和异常。 |
| `op_class` | 4 | ALU/BR/LSU/MDU/CSR/SYS/NOP。 |
| `alu_op` | 6 | ADD/SUB/SLT/AND/OR/XOR/SLL/SRL/SRA/LU12I 等。 |
| `br_op` | 4 | B/BL/JIRL/BEQ/BNE/BLT/BGE 等。 |
| `mem_op` | 4 | LB/LH/LW/LBU/LHU/SB/SH/SW。 |
| `csr_op` | 4 | CSRRD/CSRWR/CSRXCHG/ERTN 等。 |
| `src1` | 5 | 第 1 源寄存器。 |
| `src2` | 5 | 第 2 源寄存器。 |
| `rd` | 5 | 目的寄存器。 |
| `imm` | 32 | 扩展后的立即数或分支偏移。 |
| `src1_used` | 1 | 是否读取 src1。 |
| `src2_used` | 1 | 是否读取 src2。 |
| `rd_we` | 1 | 是否写 GPR。 |
| `pred_taken` | 1 | 取指时预测方向。 |
| `pred_target` | 32 | 取指时预测目标。 |
| `exception` | 1 | 前级已发现异常。 |
| `ecode/esubcode` | 若干 | 异常类型。 |

在 Verilog 中可以先不用 SystemVerilog struct，而是用明确的宽 bus 和 localparam 切片；等工程稳定后再考虑结构体。

### 3.4 流水级控制协议

建议所有流水级采用统一握手：

```verilog
allowin = !valid || (ready_go && next_allowin);
to_next_valid = valid && ready_go;
```

每一级维护：

- `valid_r`：本级是否持有有效指令。
- `ready_go`：本级内部工作是否完成。
- `allowin`：本级能否接收上一级新数据。
- `flush`：来自分支/异常/中断的冲刷。
- `stall`：本级因资源或数据等待暂停。

控制优先级建议：

1. `reset`
2. `flush`
3. `allowin && in_valid` 接收新数据
4. `allowin && !in_valid` 清空本级
5. 否则保持

冲刷规则：

- 分支在 EX2 或更早阶段确认后，冲刷所有年轻级：IFU、IF1、IF2、IDU、RRD，以及可能已经发出的错误路径取指。
- 异常在任意阶段发现后，按最老异常优先，到 WBU 提交时统一重定向到异常入口。
- 后续双发射时，slot0 比 slot1 老；slot0 异常/分支可以冲刷同拍 slot1。

## 4. 前端设计

### 4.1 S0 IFU：PC 生成与重定向

当前 `stage0_ifu` 已具备 reset PC、hold、redirect 和预测响应输入。后续要增加预测元信息和更严格的时序语义。

输入：

- `redirect_valid`
- `redirect_pc`
- `redirect_reason`：branch/exception/ertn/debug。
- `bp_resp_valid`
- `bp_pred_taken`
- `bp_pred_target`
- `fetch_allowin`

输出：

- `bp_req_valid`
- `bp_req_pc`
- `if0_valid`
- `if0_pc`
- `if0_pred_taken`
- `if0_pred_target`

PC 选择优先级：

```text
reset_pc
  > exception/ertn redirect
  > branch mispredict redirect
  > hold current pc
  > bp taken target
  > pc + 4
```

设计要点：

- 当前 LA32 指令固定 4 字节，基础阶段 PC 每次加 4。
- 引入 fetch buffer 或双发射后，可以每次取 8 或 16 字节，但提交 PC 仍按指令粒度维护。
- `bp_req_pc` 与 `if0_pc` 要配套保存，后续分支更新时要能判断预测是否正确。

### 4.2 分支预测器设计

分阶段实现：

| 阶段 | 预测器 | 说明 |
| --- | --- | --- |
| BPU0 | 当前单项 BTB | 保持最小模型，验证重定向。 |
| BPU1 | 直接映射 BTB 64/128 项 | 用 `PC[8:2]` 索引，存 tag/target/type。 |
| BPU2 | 2-bit BHT/PHT | 条件分支方向预测，非条件跳转直接 taken。 |
| BPU3 | 2 路组关联 BTB + Gshare | 兼顾容量和方向精度。 |
| BPU4 | RAS | 优化 `jirl r1` 类返回预测。 |

推荐 BPU2 字段：

```text
BTB entry:
  valid
  tag
  target[31:0]
  type: cond / uncond / call / ret

PHT entry:
  counter[1:0]  // 00 strong N, 01 weak N, 10 weak T, 11 strong T
```

预测流程：

1. IFU 发出 `req_pc`。
2. 预测器下一拍返回 `pred_taken/pred_target`。
3. IFU 使用预测结果生成下一 PC。
4. 分支在 EX2 确认后回写：
   - `update_valid`
   - `update_pc`
   - `actual_taken`
   - `actual_target`
   - `pred_taken`
   - `pred_target`
5. 若 `pred_taken != actual_taken` 或 taken 目标不同，则生成 flush。

当前 `core_top` 中每个分支都会生成 `branch_redirect_valid_w`，即使预测正确也会重定向。后续应改为：

```text
mispredict = branch_valid &&
             ((pred_taken != actual_taken) ||
              (actual_taken && pred_target != actual_target))
redirect_valid = mispredict
redirect_pc = actual_taken ? actual_target : pc + 4
```

### 4.3 S1/S2：取指请求与返回

短期继续使用 `icache_stub`，但要让它支持标准 ready/valid：

- S1 只有在 `icache_req_ready` 为 1 时才能消耗 IFU 的 PC。
- S2 需要保存 outstanding PC，并能被 flush 清空。
- 若 flush 时仍有旧路径 AXI 返回，S2 要丢弃该响应。

建议引入 fetch transaction id：

```text
fetch_seq_r 每次有效取指递增
S1 发出 {pc, seq}
S2 等待返回时保存 {pc, seq}
flush 时记录 kill_seq 或清空 pend_valid
返回时若 seq 已被 kill，则丢弃
```

### 4.4 Fetch Buffer

在引入真实 ICache 前，Fetch Buffer 可以先作为 2 到 4 项 FIFO：

每项：

- `valid`
- `pc`
- `inst`
- `pred_taken`
- `pred_target`

用途：

- 解耦取指返回和译码。
- 支持前端继续预取。
- 分支冲刷时快速清空。

基础实现先每项 1 条指令；双发射阶段再扩展为每项 2 条或 4 条指令。

## 5. 译码与控制设计

### 5.1 IDU 目标

`stage3_idu` 应成为全项目唯一的主要指令解码位置。后续 `stage5_ex1`、`stage6_ex2`、`stage7_mem1` 不应重复完整 opcode 解码，而应使用 IDU 传来的 `alu_op/br_op/mem_op/rd_we` 等控制字段。

### 5.2 指令分类

推荐分类：

| 类别 | 指令示例 | 执行单元 |
| --- | --- | --- |
| ALU-R | `add.w/sub.w/slt/sltu/and/or/xor/nor` | EX1 ALU |
| ALU-I | `addi.w/slti/sltui/andi/ori/xori/lu12i.w/pcaddu12i` | EX1 ALU |
| SHIFT | `slli.w/srli.w/srai.w/sll.w/srl.w/sra.w` | EX1 shifter |
| BR | `b/bl/jirl/beq/bne/blt/bge/bltu/bgeu` | EX2 branch |
| LSU | `ld.b/ld.h/ld.w/ld.bu/ld.hu/st.b/st.h/st.w` | MEM |
| MDU | `mul.w/mulh.w/mulh.wu/div.w/div.wu/mod.w/mod.wu` | MDU |
| CSR | CSR 读写、`ertn` | CSR |
| EXC | syscall/break/ine/ale 等 | WBU commit |
| TLB | tlbsrch/tlbrd/tlbwr/tlbfill/invtlb | TLB/CSR |
| CACHE | cacop、ibar/dbar | cache controller |

### 5.3 立即数生成

IDU 统一生成立即数：

| 格式 | 用途 | 生成规则 |
| --- | --- | --- |
| I12 | `addi.w/ld/st` | `{{20{inst[21]}}, inst[21:10]}` |
| U12 | 逻辑立即数 | `20'b0 + inst[21:10]` |
| I14/offset | 部分访存/原子可扩展 | 按 ISA 格式扩展 |
| I16 branch | `beq/bne/blt/.../jirl` | `signext(inst[25:10] << 2)` |
| I20 | `lu12i.w/pcaddu12i` | `{inst[24:5], 12'b0}` |
| I26 | `b/bl` | `signext({inst[9:0], inst[25:10]} << 2)` |
| shamt | shift immediate | `inst[14:10]` |

### 5.4 IDU 输出控制字段

建议优先把这些字段加到 IDU 输出：

```text
src1, src2, rd
src1_used, src2_used, rd_we
imm
alu_op
br_op
mem_op
is_load, is_store
is_branch
is_mul, is_div
is_csr
is_exception
```

短期改造可以先保留现有接口，同时新增 `alu_op/br_op/mem_op/rd_we`，逐步删除后级重复译码。

### 5.5 非法指令处理

IDU 对不认识的指令不要静默当作 NOP。建议输出：

- `exception = 1`
- `ecode = INE`
- `rd_we = 0`
- 后续级只携带该异常到 WBU

在 CSR/异常系统完成前，可以先让仿真打印非法指令并停止，避免误通过。

## 6. 寄存器堆、旁路与冒险

### 6.1 寄存器堆

当前 `regfile_d1` 是 2 读 1 写、读延迟 1 拍。单发射阶段足够。双发射阶段需要：

- 4 读 2 写，或
- 双泵/复制寄存器堆，或
- 限制双发射组合，避免同周期超过 2 个读端口和 1 个写端口。

短期建议仍以单发射为主，保留 2R1W。

### 6.2 RAW 冒险

去掉 `issue_busy_r` 后，必须处理 RAW：

```text
上一条 ALU 写 rd，下一条用 rd：EX/MEM/WB 旁路解决。
上一条 load 写 rd，下一条用 rd：若 load 数据未返回，则 stall。
上一条 mul/div 写 rd，下一条用 rd：若 MDU 未完成，则 stall。
CSR/TLB 写后读：按 CSR busy 或 scoreboard stall。
```

### 6.3 Scoreboard

单发射阶段推荐使用 32 位 scoreboard：

```text
busy[31:0]

issue:
  if rd_we && rd != 0:
      busy[rd] = 1

writeback:
  if rf_we && waddr != 0:
      busy[waddr] = 0

decode/rrd:
  if src_used && busy[src] && not bypassable:
      stall
```

注意：

- `r0` 永远不置 busy。
- ALU 结果虽然还未写回，但若可从 EX/MEM/WB 旁路，则不必 stall。
- Load 数据在 DCache miss 时不可旁路，必须 stall。
- 多周期 MDU 完成前不可旁路。

### 6.4 旁路网络

单发射推荐旁路优先级：

| 优先级 | 来源 | 适用 |
| --- | --- | --- |
| 1 | EX1/EX2 ALU 结果 | ALU、分支比较、store data |
| 2 | MEM 阶段非 load 结果 | ALU/link 等 |
| 3 | MEM 阶段 load 返回 | load-use 间隔足够时 |
| 4 | WBU 写回数据 | 最后一层保护 |
| 5 | GPR 读数据 | 默认 |

每个源操作数独立选择：

```text
src_data =
  match_ex  ? ex_result  :
  match_mem ? mem_result :
  match_wb  ? wb_data    :
              rf_data
```

需要保存每级：

- `valid`
- `rd`
- `rd_we`
- `result_valid`
- `result`
- `is_load`

### 6.5 Load-Use Stall

规则：

```text
if ID/RRD 指令源寄存器依赖前方 load
and load 数据尚未到达:
    stall ID/RRD 及更前端
```

若 DCache hit 为 1 拍返回，则典型 load-use 需要停 1 拍。若 miss，则停到返回为止。

### 6.6 Store Data 冒险

store 有两个源：

- 地址基址 `rj`
- 写入数据 `rd` 或对应 ISA 字段

地址必须在 EX 前准备好。store data 可以稍晚到 MEM 阶段，只要进入 Store Buffer 前通过旁路补齐即可。推荐把 store data 也纳入旁路选择，不要只依赖 RRD 阶段读出的旧值。

## 7. 执行单元设计

### 7.1 EX1 ALU

EX1 负责：

- 加减法。
- 有符号/无符号比较。
- 逻辑运算。
- 移位。
- `lu12i.w`、`pcaddu12i`。
- load/store 地址计算。
- `bl/jirl` link 地址生成。

为改善当前时序，应把重复译码前移到 IDU：

```text
IDU: alu_op = ALU_ADD / ALU_SUB / ...
EX1: case (alu_op)
```

这样可以减少 `stage5_ex1` 中 opcode 比较的高扇出和组合链。

### 7.2 分支执行

分支条件建议在 EX1 或 EX2 中计算：

| 指令 | 条件 | 目标 |
| --- | --- | --- |
| `b` | always | `pc + imm26` |
| `bl` | always，写 `r1=pc+4` | `pc + imm26` |
| `jirl` | always，写 `rd=pc+4` | `rj + imm16` |
| `beq` | `src1 == src2` | `pc + imm16` |
| `bne` | `src1 != src2` | `pc + imm16` |
| `blt/bge` | signed compare | `pc + imm16` |
| `bltu/bgeu` | unsigned compare | `pc + imm16` |

EX2 输出：

- `branch_valid`
- `actual_taken`
- `actual_target`
- `pred_taken`
- `pred_target`
- `mispredict`

只有 `mispredict` 才冲刷前端。

### 7.3 MDU

分阶段实现：

| 阶段 | 乘法 | 除法 |
| --- | --- | --- |
| MDU0 | 组合或 1 拍 `*` | 暂不支持，遇到 div stall/报错 |
| MDU1 | 2-3 拍流水 Booth/Wallace 或 FPGA DSP | 迭代 restoring/non-restoring |
| MDU2 | 完整 signed/unsigned high/low | 32 周期或 radix-4 16 周期 |

接口建议：

```text
req_valid
req_ready
req_op       // mul/div/mod/mulh...
req_signed
req_src1
req_src2
resp_valid
resp_result
busy
flush
```

MDU 是多周期单元，必须和 scoreboard 配合：

- 发射 MDU 指令时置 `busy[rd]`。
- MDU 响应进入写回队列或 EX2/MEM 管线。
- flush 时取消年轻 MDU 请求；如果 MDU 无法取消，则响应回来时按 tag 丢弃。

### 7.4 CSR 与系统指令

CSR 阶段建议先实现最小可用集合：

- `crmd`
- `prmd`
- `estat`
- `era`
- `eentry`
- `badv`
- `tid/tcfg/tval/ticlr` 可后续补充

CSR 指令：

- `csrrd`
- `csrwr`
- `csrxchg`
- `ertn`
- `syscall`
- `break`

精确异常策略：

- 异常可以在前级检测，但只在 WBU/commit 阶段修改 CSR 和 PC。
- 异常指令之后的年轻指令必须被冲刷，不允许提交。
- `debug_wb_*` 对异常指令要保持可解释：一般 `ws_valid=1`，写回使能按实际指令，异常事件另行输出给仿真或 CSR。

## 8. 访存系统设计

### 8.1 地址与粒度

MEM 阶段应支持：

| 指令 | 读写 | 对齐 | 写掩码/扩展 |
| --- | --- | --- | --- |
| `ld.b` | read | 任意字节 | sign extend 8 |
| `ld.bu` | read | 任意字节 | zero extend 8 |
| `ld.h` | read | 2 字节对齐 | sign extend 16 |
| `ld.hu` | read | 2 字节对齐 | zero extend 16 |
| `ld.w` | read | 4 字节对齐 | 32 位 |
| `st.b` | write | 任意字节 | `wstrb` 单 bit |
| `st.h` | write | 2 字节对齐 | `wstrb` 双 bit |
| `st.w` | write | 4 字节对齐 | `wstrb=4'hf` |

地址不对齐要产生 ALE 异常：

- halfword 地址 `addr[0] != 0`
- word 地址 `addr[1:0] != 0`

### 8.2 DCache Stub 到真实 DCache

当前 `dcache_stub` 单请求转 AXI。建议分三步：

1. DCache0：保留 all-miss，但完善 ready/valid、flush 丢弃、byte mask、load 扩展。
2. DCache1：直接映射 4KB/8KB cache，write-through，先不做脏行。
3. DCache2：2 路组关联 16KB，write-back/write-allocate，支持 dirty eviction。

推荐 DCache2 参数：

| 参数 | 推荐值 |
| --- | --- |
| 容量 | 16KB |
| 路数 | 2-way |
| 行大小 | 32B 或 64B |
| 组数 | 16KB / line_size / 2 |
| 状态 | valid, dirty, tag, repl |
| 写策略 | write-back |
| 分配 | write-allocate |
| 未命中 | MSHR 先 1 项，后续扩展 2 项 |

### 8.3 ICache 设计

ICache 可以比 DCache 更早实现，因为它没有写回和 store/load 顺序问题。

推荐阶段：

1. ICache0：直接映射，行大小 16B 或 32B。
2. ICache1：2-way，行大小 32B/64B。
3. ICache2：支持 prefetch/fetch buffer/双发射取指。

ICache miss 流程：

```text
lookup miss
  -> allocate miss request
  -> AXI burst read cache line
  -> critical word first response to IF2
  -> fill remaining words
  -> set valid/tag
```

FPGA 上为了简单，可以先不做 critical word first，而是整行填完后返回。

### 8.4 Store Buffer

Store Buffer 是从单发射向高 IPC 过渡的关键组件。建议先实现 4 项 FIFO，后续扩展到 8 项。

每项：

```text
valid
committed
addr
wdata
wstrb
size
seq
```

流程：

1. store 到 MEM 阶段时分配 entry。
2. 到 commit/WBU 后标记 committed。
3. committed store 按序写入 DCache/AXI。
4. 若异常/flush，未 committed 的 store 全部丢弃。

Load 查询 Store Buffer：

- 从最新到最旧匹配地址重叠。
- 若找到更老 store，按字节合成返回数据。
- 若找到未提交但更老 store，仍可转发，因为它在程序顺序上早于 load。
- 若存在地址未知的更老 store，则 load 必须等待。

### 8.5 AXI 接口演进

当前 AXI 单拍读写适合 stub。真实 cache 后建议抽象成内部 miss bus：

```text
miss_req_valid
miss_req_ready
miss_req_write
miss_req_addr
miss_req_len
miss_req_wdata_line
miss_resp_valid
miss_resp_data
miss_resp_last
```

再由独立 `axi_bridge` 转成 AXI4：

- ICache miss read
- DCache miss read
- DCache dirty writeback
- uncached load/store

仲裁优先级建议：

1. DCache dirty writeback 或 uncached store 已提交
2. DCache load miss
3. ICache miss
4. prefetch

早期仍可保留 ICache 优先，便于简单验证；性能优化阶段再调整。

## 9. 写回、提交与精确状态

### 9.1 WBU 职责

`stage8_wbu` 是顺序处理器的提交点，应负责：

- GPR 写回。
- CSR 写回。
- 异常提交和重定向。
- 分支预测统计更新可在 EX2，精确恢复在 WBU 或 EX2 视实现复杂度选择。
- `debug_wb_*` 输出。
- 清 scoreboard。
- 标记 Store Buffer entry committed。

### 9.2 Debug/Difftest 约束

当前 Verilator 主程序依赖：

- `debug_wb_pc`
- `debug_wb_rf_wen`
- `debug_wb_rf_wnum`
- `debug_wb_rf_wdata`
- `debug_wb_inst`
- `ws_valid`

设计要求：

- 每条架构提交指令只能产生一次 `ws_valid`。
- 冲刷掉的指令不能产生 `ws_valid`。
- store、branch 等不写 GPR 的指令也应该产生 `ws_valid`，但 `debug_wb_rf_wen=0`。
- 多周期/访存等待不能导致同一指令重复提交。
- 双发射阶段若每周期提交 2 条，要扩展 debug 通道或保持单提交，先不要直接破坏 difftest 接口。

### 9.3 精确异常

精确异常要求：

- 异常指令之前的指令全部提交。
- 异常指令之后的指令全部不提交。
- CSR 中保存异常 PC 和原因。
- PC 重定向到异常入口。

推荐实现：

```text
每条 uop 携带 exception/ecode/badv
若前级发现异常，后级不再执行有副作用操作
WBU 看到 exception:
  写 CSR.era = pc
  写 CSR.estat.ecode = ecode
  redirect_valid = 1
  redirect_pc = eentry
  flush younger
```

Store 必须延迟到 commit 后才真正写出，保证异常不会让年轻 store 污染内存。

## 10. 双发射演进方案

### 10.1 前置条件

不要在以下能力完成前实现双发射：

- 单发射多在途正确。
- 旁路网络稳定。
- load-use stall 正确。
- 分支冲刷正确。
- Store Buffer 或保守 store 提交机制正确。
- debug/difftest 可区分提交顺序。

### 10.2 双发射限制

初版双发射建议保守：

允许：

- ALU + ALU
- ALU + branch
- ALU + load/store
- branch + ALU，若 branch 在 slot0 需谨慎处理 slot1 是否在 delay-like 路径中，LoongArch 无延迟槽，通常 slot0 分支后 slot1 不应作为顺序指令发射，初期可禁止。

禁止：

- 两条 load/store 同发射。
- MDU 与任何其他指令同发射。
- CSR/TLB/异常类与任何其他指令同发射。
- slot1 依赖 slot0 的结果。
- slot0 是 taken 概率较高或无条件分支时发射 slot1。

### 10.3 双发射发射规则

```text
slot0_ready = src ready && fu available && no older block
slot1_ready = src ready && fu available && no resource conflict
slot1_dep_slot0 = slot0.rd_we && slot0.rd != 0 &&
                  ((slot1.src1_used && slot1.src1 == slot0.rd) ||
                   (slot1.src2_used && slot1.src2 == slot0.rd))

if !slot0_ready:
    issue none
else if slot1_ready && !slot1_dep_slot0 && pair_allowed:
    issue slot0 + slot1
else:
    issue slot0 only
```

### 10.4 双提交

推荐先保持单提交，即双发射但在 WBU 排队按序逐条输出 debug。这样可以复用现有 difftest。性能会受提交带宽限制，但能大幅降低验证风险。

双提交阶段再扩展：

- `ws_valid[1:0]`
- `debug_wb_pc[1:0]`
- `debug_wb_rf_wen[1:0]`
- `debug_wb_rf_wnum[1:0]`
- `debug_wb_rf_wdata[1:0]`
- difftest 每周期按 slot0 -> slot1 顺序执行。

## 11. 时序与综合策略

### 11.1 当前时序热点

已有文档指出，当前 Vivado 200MHz 附近的热点主要在：

- `stage4_rrd -> stage5_ex1`
- EX1 重复译码和 ALU 组合链。
- `out_inst` 控制网高扇出。

### 11.2 RTL 优化顺序

1. IDU 前移译码，EX1 使用 `alu_op`。
2. 分离加减/比较/逻辑/移位结果，最后一层 mux 简化。
3. 对高扇出控制字段增加一级寄存或复制。
4. 移位器、比较器、加法器按 FPGA CARRY4/DSP 资源调整。
5. Cache RAM 使用 block RAM 或 distributed RAM 时明确时序假设。

### 11.3 目标频率

| 平台 | 阶段 | 目标 |
| --- | --- | --- |
| FPGA baseline | 单发射 + stub cache | 100-200MHz |
| FPGA optimized | 单发射 + I/D cache | 150-250MHz |
| FPGA ambitious | 双发射 | 150MHz 左右先保证正确 |
| ASIC 参考 | `plan.md` 长期目标 | 800MHz-1.2GHz，需工艺库和 SRAM compiler 支撑 |

`plan.md` 中的 800MHz-1.2GHz 更接近 ASIC 目标，不应直接作为当前 FPGA RTL 的硬约束。

## 12. 验证方案

### 12.1 每次改动的最低验证

```bash
make clean
make all EXP=6
```

若涉及译码/指令集：

```bash
make test EXP=<目标编号>
make run
```

若涉及时序：

```bash
make fmax
```

### 12.2 模块级测试建议

| 模块 | 测试重点 |
| --- | --- |
| IDU | 每条指令的 src/rd/imm/op/rd_we 是否正确。 |
| ALU | 加减、比较、移位、逻辑边界值。 |
| Branch | taken/not taken、target、mispredict flush。 |
| Regfile/Bypass | RAW、WAW-like 顺序、r0 恒零。 |
| DCache | byte/halfword/word、mask、sign/zero extend。 |
| Store Buffer | store-load forward、异常丢弃、顺序写出。 |
| MDU | signed/unsigned、除 0、溢出边界。 |
| CSR | 读写、异常进入、`ertn` 返回。 |

### 12.3 指令级验证顺序

建议按风险递增：

1. `lu12i.w/add.w/addi.w/sub.w`
2. 逻辑与移位：`and/or/xor/nor/slli/srli/srai`
3. 比较：`slt/sltu/slti/sltui`
4. 分支：`b/bl/jirl/beq/bne`
5. 基础访存：`ld.w/st.w`
6. 非 word 访存：`ld.b/ld.h/ld.bu/ld.hu/st.b/st.h`
7. 乘法。
8. 除法/取模。
9. CSR/异常。
10. TLB/cache 指令。

### 12.4 随机与压力测试

在基础 EXP 通过后，应增加：

- 随机 ALU 指令流。
- 随机 RAW 距离 0-4 的相关指令。
- load-use 紧邻和间隔测试。
- 分支密集测试。
- store/load 同地址和部分重叠测试。
- cache hit/miss 混合测试。
- 长时间运行统计提交数和 difftest 一致性。

## 13. 分阶段实施清单

### S0：基线整理

目标：

- 保持当前 `make all EXP=6` 通过。
- 明确哪些文件是源码，哪些是生成物。
- 保留 `debug_wb_inst`，确保 difftest 输出稳定。

建议任务：

- 把 `.cache/clangd` 和 `hs_err_pid*.log` 从 Git 追踪中移除。
- 保留 `compile_commands.json` 为生成物。
- 给 `planx.md` 后续每次更新添加变更记录。

### S1：单发射多在途流水控制

目标：

- 用 `valid/allowin/ready_go` 替换 `issue_busy_r` 全局单在途。
- 支持前后级自然停顿。

改造点：

- 每个 `stage*.v` 增加 `allowin` 和 `to_next_valid`。
- `core_top` 统一连接流水握手。
- `icache_stub/dcache_stub` 的 `req_ready` 真正接入上游。
- flush 能清空前端和等待返回的错误路径请求。

通过标准：

- EXP=6 通过。
- 手写 back-to-back ALU 指令通过。

### S2：冒险、旁路和分支冲刷

目标：

- 正确处理多在途 RAW。
- 分支预测正确时不冲刷，错误时冲刷。

改造点：

- IDU 输出 `src1/src2/src_used/rd_we`。
- RRD 增加旁路选择。
- 增加 scoreboard。
- EX2 生成 `mispredict`。
- IF/S1/S2/ID/RRD 支持 flush。

通过标准：

- 连续相关 ALU 指令通过。
- load-use 测试通过。
- 分支 taken/not taken 混合通过。

### S3：指令集补全

目标：

- 覆盖 `mycpu_env/func/inst` 中更多指令。

改造点：

- 补全 IDU opcode。
- 补全 ALU op。
- 补全访存 mask 和扩展。
- 实现基础 MDU。
- 引入非法指令异常或仿真停止机制。

通过标准：

- 按 EXP 逐步推进，新增指令都有定向测试。

### S4：Cache 与 Store Buffer

目标：

- ICache/DCache 取代 all-miss stub。
- Store Buffer 保证 store 精确提交。

改造点：

- `icache_stub` 替换为 `icache`。
- `dcache_stub` 替换为 `dcache`。
- 增加 `store_buffer`。
- `core_top` AXI FSM 拆出为 `axi_bridge`。

通过标准：

- cache 关闭和开启结果一致。
- hit/miss 随机测试一致。
- store-load forwarding 通过。

### S5：CSR、异常与 TLB

目标：

- 支持系统级测试。
- 为更高级 LoongArch 特性铺路。

改造点：

- `csr_stub` 替换为真实 CSR。
- 异常入口、`ertn`、`syscall/break/ine/ale`。
- TLB skeleton：查询、填充、读写、失效。
- IF/MEM 地址转换。

通过标准：

- 异常类 EXP 通过。
- TLB 相关指令基础通过。

### S6：双发射

目标：

- 在单发射稳定基础上提升 IPC。

改造点：

- Fetch Buffer 一次输出 2 条。
- IDU 双译码。
- Issue Arbiter。
- 至少两个 ALU 或 ALU+BR/LSU 资源。
- 双 slot scoreboard 和旁路。
- 提交队列保持顺序提交。

通过标准：

- 双发射关闭/开启结果一致。
- 单提交 difftest 稳定。
- IPC 统计有提升。

## 14. 推荐模块拆分

为了降低 `core_top` 复杂度，建议逐步拆分：

```text
core_top
  frontend/
    ifu
    branch_predictor
    fetch_buffer
    icache
  backend/
    idu
    regfile
    bypass
    scoreboard
    alu
    mdu
    csr
    lsu
    dcache
    store_buffer
    wbu
  bus/
    axi_bridge
```

当前仓库可先不移动目录，只新增独立 Verilog 文件。等功能稳定后再整理目录。

## 15. 关键风险与规避

| 风险 | 典型表现 | 规避方式 |
| --- | --- | --- |
| 冲刷不彻底 | 错路径指令提交 | 每级统一 flush，AXI 返回加 kill/tag。 |
| RAW 漏旁路 | difftest 偶发寄存器错误 | scoreboard + 定向相关测试。 |
| load-use 漏停顿 | load 后一条错误 | DCache result_valid 未到前禁止使用。 |
| store 过早写内存 | 异常后内存被污染 | Store Buffer commit 后写出。 |
| debug 重复提交 | difftest 指令数不一致 | WBU 单点产生 `ws_valid`。 |
| 后级重复译码 | 时序差、维护难 | IDU 输出控制 bus。 |
| AXI 旧响应污染 | 分支后取到旧路径指令 | fetch seq/kill 机制。 |
| 双发射过早 | bug 组合爆炸 | 先完成单发射多在途。 |

## 16. 建议立即执行的下一步

1. 先在当前基线上新增 IDU 控制字段：`alu_op/br_op/mem_op/rd_we/src_used`。
2. 改写 `stage5_ex1`，让它不再重复完整 opcode 解码。
3. 为所有流水级加 `valid/allowin/flush`，但先保持单发射。
4. 接入 `icache_req_ready/dcache_req_ready`，让访存等待能自然反压。
5. 加 scoreboard 和最小旁路网络。
6. 调整分支逻辑，只在 mispredict 时 redirect。
7. 再补全访存 byte/halfword 和更多 LA32 指令。

这条路线能最大程度复用当前已经跑通的 Verilator/difftest 链路，同时把 `plan.md` 中的高性能目标拆成可验证、可回退、可度量的小步。
