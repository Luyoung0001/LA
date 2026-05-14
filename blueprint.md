# LA 处理器实现蓝图

本文档是新的执行版蓝图：目标流水线从当前 LA 工程里的 8 级临时流水线，调整为 6 级目标流水线。当前 8 级实现只作为功能基线和迁移参照，不作为最终结构继续扩展。

新的工程策略是：

- CPU 主干按 6 级流水线重搭：`F1 -> F2 -> D1 -> EX -> M1 -> WB`。
- 先学习并移植 `/home/luyoung/demos/fpga-pipeline-cpu` 的工程外壳：根 Makefile、Chiplab wrapper、Verilator shell、模块级 `tb_cpp`，再搬 cache/BPU/AXI RTL。
- L1 ICache、L1 DCache、L2 Cache、BPU、AXI 仲裁器优先直接复用 `/home/luyoung/demos/fpga-pipeline-cpu/rtl` 中的成熟 RTL，不重新研发。
- 只写 LA 侧 wrapper、packet 适配、CSR/TLB/异常/commit/difftest 适配，不重写 cache/BPU/AXI/arbiter 内部算法。
- 存储阵列使用 FPGA 原语；仿真使用同名 `RAMB36E1` 行为模型。
- Chiplab/difftest 是主验证工具；复杂裸机、RTOS、Linux boot/early printk 是强回归负载，但不作为里程碑名称。

## 0. 总原则

### 0.1 6 级流水线为目标结构

目标流水线固定为：

```text
F1: PC/BPU/redirect
F2: ITCM/L1I/Fetch Buffer
D1: Decode/Issue/Regfile/Scoreboard
EX: ALU/Branch/MDU/CSR/TLB execute
M1: LSU/Store Buffer/L1D/L2 request
WB: Commit/GPR/CSR/store visible/debug/difftest
```

当前 `stage0_ifu` 到 `stage8_wbu` 的 8 级实现不再继续作为目标扩展。后续只保留它的两个价值：

- 作为可运行基线，防止重构期间功能倒退。
- 迁移其中已经验证过的 LA 指令译码、ALU、LSU、debug/difftest 行为。

### 0.2 参考 RTL 直接复用优先

以下模块原则上直接从 `/home/luyoung/demos/fpga-pipeline-cpu/rtl` 复制进入本项目，不重新设计：

- `cpu_bpu.v`
- `fetch_buffer.v`
- `cpu_l1_icache.v`
- `cpu_l1_dcache.v`
- `cpu_l2_cache.v`
- `axi_arbiter.v`
- cache/BPU 依赖的 primitive/helper 文件，例如 `cpu_primitives.v`、必要的 packet/helper 模块。

直接复用的含义：

- 不重写替换算法、miss/refill 状态机、store queue、AXI 仲裁策略。
- 不把参考 RTL 拆散后重新实现一遍。
- 允许做 LA wrapper：信号命名、packet 打包、reset 极性、debug 宏、参数、difftest 可见状态适配。
- 若发现 bug，优先以“最小补丁 + 注释记录”的方式修，不进行大改。

复制管理要求：

- copied 原始模块保留来源记录：参考路径、复制日期、参考仓库 commit 或文件 hash。
- 建议放在独立目录或用文件头标记 `COPIED_FROM=/home/luyoung/demos/fpga-pipeline-cpu/rtl/...`。
- LA 适配优先写在 wrapper 中；若必须改 copied 模块内部，必须在文件头或旁边 patch note 中记录差异。
- 后续参考工程更新时，不自动覆盖本项目版本，必须人工比较差异后再合并。

### 0.3 FPGA 原语与仿真模型

cache/tag/data/BTB/PHT 等存储单元优先使用 FPGA 友好的 BRAM/原语封装。

- 综合/时序：使用 Xilinx `RAMB36E1` 或参考 RTL 中已经封装好的 primitive 路线。
- 仿真：使用同名行为模型 `/home/luyoung/demos/fpga-pipeline-cpu/sim/ramb36e1_model.v`。
- 本项目可放置本地仿真副本，例如 `mycpu_env/myCPU/sim/ramb36e1_model.v`，只加入 Verilator 源列表，不加入 Vivado `v_src/*.v` 综合源。
- 禁止为 cache 存储阵列重新写一套项目私有 RAM 行为，除非 reference primitive 无法覆盖。

### 0.4 架构状态只在 WB/commit 可见

- GPR 写、CSR 写、store 对外可见、异常入口、`ertn`、debug/difftest 都从 WB/commit 侧统一输出。
- LSU 可以在 M1 分配 Store Buffer，但 store 释放必须受 commit 控制。
- 中间级可以产生结果、旁路、预测更新，但不能直接修改架构状态。

### 0.5 每阶段必须可运行

每个阶段结束都要记录可运行状态：

- 至少 RTL 可编译。
- 骨架阶段必须通过 `smoke_test.S` 或最小 EXP。
- 功能阶段必须通过对应 Chiplab/EXP/difftest。
- 如果失败，记录失败项、原因、定位入口和下一步修复责任。

### 0.6 先移植工程外壳，再复制 RTL

`fpga-pipeline-cpu` 值得学习的不只是 RTL，而是它把 CPU 工程拆成了四层稳定入口：

- RTL 核心层：`rtl/fpga_pipeline_cpu_core.v` 和 `rtl/*.v`，提供统一 AXI master、commit/debug、可选 `DIFFTEST_EN` 观察总线。
- 动态 difftest 层：`rtl/verilator_top.v`、`rtl/verilator_top_la500.v` 和根 Makefile 的 `make all EXP=23 PERF_MONI=1`。
- Chiplab 层：根 Makefile 的 `make configure RUN=...`、`chiplab-sync-rtl`、`chiplab/myCPU/core_top.v`，把项目 core 包成 Chiplab 期待的 AXI/debug/difftest 接口。
- 模块级验证层：`tb_cpp/Makefile` 和大量 `*_tb.sv`，先测 BPU/L1/L2/AXI/fetch buffer，再跑整机。

因此本项目的移植顺序必须是：

```text
工程外壳/Chiplab 入口
  -> 6 级 core wrapper 和 packet
  -> copied cache/BPU/AXI 模块
  -> LA 指令/CSR/TLB/异常完整化
```

不能只把 `rtl/*.v` 复制进来，然后临时拼 Chiplab。Chiplab 是正式工程入口，不是最后补的脚本。

## 1. 目标架构图

### 1.1 6 级流水线图

```text
┌─────────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                         │
│    ┌──────────┐    ┌───────────┐    ┌──────────┐    ┌──────────┐    ┌──────────┐        │
│    │   F1     │    │    F2     │    │    D1    │    │    EX    │    │    M1    │   WB   │
│    │ 取指1    │───►│  取指2    │───►│ 译码发射  │───►│   执行   │───►│   访存   │──►写回 │
│    │ PC/BPU   │    │ I$/FBuf   │    │ Reg/Issue│    │ ALU/MDU  │    │ D$/Store │ Commit│
│    └──────────┘    └───────────┘    └──────────┘    └──────────┘    └──────────┘        │
│         │               │               │               │               │              │
│         ▼               ▼               ▼               ▼               ▼              │
│    ┌──────────┐    ┌───────────┐    ┌──────────┐    ┌──────────┐    ┌──────────┐        │
│    │ cpu_bpu  │    │ L1I/ITCM  │    │ Regfile  │    │ ALU0 ALU1│    │ Store Buf│        │
│    │ PC Gen   │    │ Fetch Buf │    │ Scorebd  │    │ MDU/CSR  │    │ L1 D$    │        │
│    └──────────┘    └───────────┘    └──────────┘    └──────────┘    └──────────┘        │
│                                                                   │           │         │
│                                                                    └─────┬─────┘         │
│                                                                          │               │
│                                                                    ┌──────────┐          │
│                                                                    │   L2 $   │          │
│                                                                    └──────────┘          │
│                                                                          │               │
│                                                                    ┌──────────┐          │
│                                                                    │ AXI/Arb  │          │
│                                                                    └──────────┘          │
└─────────────────────────────────────────────────────────────────────────────────────────┘
```

### 1.1.1 当前 RTL 命名约定

流水级源码统一放在 `/home/luyoung/LA/rtl`，按级号命名。`mycpu_env/myCPU/v_src` 已废弃，不再放源码或软链接；`chiplab/myCPU` 只保留 Chiplab 兼容符号链接视图。

| 流水级 | RTL 文件 | 模块名 | 当前职责 |
| --- | --- | --- | --- |
| S1/F1 | `rtl/s1_f1.v` | `s1_f1` | PC 维护、redirect、BPU 查询入口。 |
| S2/F2 | `rtl/s2_f2.v` | `s2_f2` | I-TLB 查询、取指请求/响应、fetch 异常 packet。 |
| S3/D1 | `rtl/s3_d1.v` | `s3_d1` | LA32 译码、寄存器读、发射控制字段生成。 |
| S4/EX | `rtl/s4_ex.v` | `s4_ex` | ALU、branch resolve、CSR 执行侧数据、乘除结果。 |
| S5/M1 | `rtl/s5_m1.v` | `s5_m1` | LSU、D-TLB、DCache 请求/响应、访存异常。 |
| S6/WB | `rtl/s6_wb.v` | `s6_wb` | commit、GPR/CSR 写回、debug/difftest 可见提交。 |

旧的 `stage0_ifu.v` 到 `stage8_wbu.v`、`regfile_d1.v`、`muldiv_stub.v`、`commit_unit.v` 等零散目标文件不再作为独立源码存在；该合并的逻辑已经收进 6 个 `s*_*.v` 流水级或对应 top/wrapper。

### 1.2 顶层模块关系

```text
mycpu_top
  core_top
    redirect_ctrl

    frontend_top
      s1_f1                   // PC/BPU/redirect
      cpu_bpu                  // copied
      frontend_lookup wrappers // copied/adapted
      s2_f2                   // I-TLB/ifetch/fetch packet
      fetch_buffer             // copied

    backend_top
      s3_d1
        decode_la32
        issue_single / issue_pair_later
        regfile
        scoreboard / hazard_matrix
      s4_ex
        alu0 / alu1_later
        branch_resolve
        mdu
        csr_exec
        tlb_exec
      s5_m1
        lsu
        store_buffer
      s6_wb
        commit/debug/difftest output

    memsys_top
      cpu_l1_icache            // copied
      cpu_l1_dcache            // copied
      cpu_l2_cache             // copied
      axi_arbiter              // copied
      axi_bridge / SoC adapter
      RAMB36E1 primitive model for simulation
```

`core_top` 只负责实例化、时钟复位、外部 AXI/debug/difftest 连接，不再堆临时状态机。

### 1.3 主数据流

```text
redirect/PC
  -> cpu_bpu lookup
  -> L1I/ITCM fetch
  -> fetch_buffer
  -> decode/issue/regfile
  -> EX branch/ALU/MDU/CSR/TLB
  -> M1 LSU/store_buffer/L1D/L2
  -> WB commit
  -> GPR/CSR/store/debug/difftest visible
```

## 2. 6 级流水线职责

### F1：取指 1

职责：

- 接收 `redirect_pkt`。
- 维护 PC。
- 查询 `cpu_bpu`。
- 生成 I-side request。

复用：

- `cpu_bpu.v`
- `frontend_control.v`
- `frontend_lookup_packet.v`
- `frontend_lookup_request_boundary.v`
- `frontend_lookup_response_regs.v`

验收：

- 默认 not-taken 或参考 BPU 都能取到正确 PC。
- redirect 后旧路径响应不能进入有效提交流。

### F2：取指 2

职责：

- 接收 L1I/ITCM 响应。
- 形成 `fetch_pkt`。
- 写入 `fetch_buffer`。
- 向 D1 提供顺序 fetch entry。

复用：

- `fetch_buffer.v`
- `frontend_icache_request_boundary.v`
- `cpu_l1_icache.v`

验收：

- ICache 关闭/开启均可跑 smoke。
- F1/F2 redirect/flush 不丢包、不重复发射。

### D1：译码发射

职责：

- LA32 指令译码为 `uop_pkt`。
- 寄存器堆读。
- 单发射起步，保留双发射 packet/slot 形态。
- scoreboard/hazard 判断。
- 生成 EX/M1/WB 所需控制字段。

复用：

- `s5_issue_scoreboard.v`
- `s6_rr_hazard_matrix.v`
- `cpu_regfile.v` 或 `cpu_regfile_2w.v` 视发射宽度选择。

注意：

- 参考 issue/scoreboard 可以借结构，但 LA decode 必须按 LA32 ISA 自己实现或迁移当前工程实现。
- D1 后级不再重复完整译码。

### EX：执行

职责：

- ALU 运算。
- branch resolve。
- MDU 多周期乘除。
- CSR/TLB 执行侧读写准备。
- 产生 redirect 候选。

复用：

- `backend_branch_resolve.v`
- `s8_slot0_exec_bank.v` 中的乘除实现。
- `backend_lane_alu.v` 可作为 ALU 结构参考。

注意：

- EX 可以长延迟，必须通过 valid/ready 或 busy/hold 控制反压。
- branch redirect 只在 predicted next PC 与 actual next PC 不一致时产生。

### M1：访存

职责：

- LSU 地址、粒度、对齐、uncached 判断。
- Store Buffer 分配。
- L1D 访问。
- cache op/barrier 对 memsys 发命令。
- 接收 DCache/L2/AXI 响应。

复用：

- `cpu_l1_dcache.v`
- `cpu_l2_cache.v`
- `axi_arbiter.v`

注意：

- L1D/L2/AXI 不重新研发。
- LA 只做 mem_req/mem_resp 适配、uncached/MMIO 规则、异常码对接。

### WB：写回提交

职责：

- 唯一架构状态出口。
- GPR 写回。
- CSR 写回。
- store commit release。
- exception/ertn/interrupt redirect。
- debug/difftest 输出。

复用：

- `s10_*commit*` 系列可借鉴顺序提交、双 slot 选择、difftest packet 整理。

注意：

- 初期单提交。
- 后续双发射可以先双 issue 单 commit，再扩展双 commit。

## 3. 关键 packet

先用 Verilog `localparam` 切片和宽 bus，不强依赖 SystemVerilog struct。

约束：

- 每个 packet 必须在 `la_core_defs.vh` 中写清楚总宽度、字段位宽、切片范围和语义。
- 禁止在模块内部私自复制 packet 位定义；新增字段先改定义文件，再改使用者。
- 每个阶段记录中要写明本阶段新增/修改了哪些 packet 字段。

`fetch_pkt`：

```text
valid
pc
inst
epoch
pred_taken
pred_target
pred_meta
fetch_fault
```

`uop_pkt`：

```text
valid
pc
inst
epoch
slot
op_class
alu_op
br_op
mem_op
csr_op
tlb_op
mdu_op
src1/src2/src3
src1_used/src2_used/src3_used
rd/rd_we
imm
pred_taken/pred_target/pred_meta
exception/ecode/esubcode/badv
```

`mem_req` / `mem_resp`：

```text
valid/ready
op
addr
wdata
wstrb
size
uncached
cache_op
barrier
epoch
seq
fault
rdata
```

`redirect_pkt`：

```text
valid
target_pc
reason        // branch / exception / ertn / interrupt
source_stage
epoch_new
kill_younger
```

`commit_pkt`：

```text
valid
pc
inst
rd_we
rd
wdata
is_store
store_seq
csr_we
exception
debug_wb_*
perf_evt_inst_retired
perf_evt_exception
```

`commit_if`：

```text
in_valid[1:0]
in_pkt[1:0]
in_ready
gpr_we[1:0]
gpr_waddr[1:0]
gpr_wdata[1:0]
csr_we
csr_waddr
csr_wdata
store_commit_valid
store_commit_seq
exception_redirect
debug_wb_*
perf_evt_inst_retired[1:0]
perf_evt_store_commit
```

## 4. 参考 RTL 复用清单

### 4.1 必须优先直接复制的模块

| 功能 | 参考文件 | 使用方式 |
| --- | --- | --- |
| BPU | `cpu_bpu.v` | 直接复制，外包 LA lookup/update wrapper。 |
| Fetch Buffer | `fetch_buffer.v` | 直接复制或极小参数适配。 |
| L1 ICache | `cpu_l1_icache.v` | 直接复制，接 F2/memsys wrapper。 |
| L1 DCache | `cpu_l1_dcache.v` | 直接复制，接 M1 LSU wrapper。 |
| L2 Cache | `cpu_l2_cache.v` | 直接复制，接 L1I/L1D/AXI wrapper。 |
| AXI 仲裁 | `axi_arbiter.v` | 直接复制，服务 L2 read/write 通道。 |
| FPGA primitive | `cpu_primitives.v` | 复制需要的 primitive/helper。 |
| BRAM 仿真模型 | `sim/ramb36e1_model.v` | 放入 LA sim-only 路径。 |

### 4.2 可复制后适配的模块

| 功能 | 参考文件 | 适配点 |
| --- | --- | --- |
| 分支解析 | `backend_branch_resolve.v` | LA branch/jump 类型和 PC 规则。 |
| scoreboard | `s5_issue_scoreboard.v` | 改成 LA `producer_status/uop_pkt`。 |
| hazard matrix | `s6_rr_hazard_matrix.v` | 改寄存器编号、load-use、CSR/TLB hazard。 |
| MDU | `s8_slot0_exec_bank.v` | 抽出乘法和 32 拍除法。 |
| commit | `s10_*commit*` | 按 LA debug/difftest/CSR/store 可见状态重包。 |
| frontend 边界 | `frontend_*` | 改 reset、packet、epoch、LA PC。 |

### 4.3 不直接复制的部分

- RISC-V 或参考工程 ISA 绑定的 decode。
- 与 LA CSR/TLB/异常语义不一致的控制逻辑。
- 完整双发射后端在单发射未稳定前不整体搬入。

## 5. fpga-pipeline-cpu 工程外壳移植清单

这一节是从 `/home/luyoung/demos/fpga-pipeline-cpu` 学到的工程层结论。它的成功形态不是“有一堆 RTL 文件”，而是根目录能同时跑：

```bash
make all EXP=23 PERF_MONI=1
make all EXP=23 PERF_MONI=1 CPU=LA500
make configure RUN=coremark
make configure RUN=coremark CPU=LA500
make -C tb_cpp run CASE=cpu_l1_icache
```

本项目也要朝这个形态靠齐。

### 5.1 目录与入口对齐

推荐本项目最终形成这些入口：

```text
LA/
  rtl/                         // 唯一 RTL 源目录：当前 core、目标 6 级 core、copied RTL
    verilator_top.v            // 动态 difftest shell
    verilator_top_la500.v      // 可选 reference_cpu 对照 shell
  mycpu_env/myCPU/sim/         // sim-only primitive model，例如 ramb36e1_model.v
  chiplab/
    myCPU/core_top.v -> ../../rtl/mycpu_top.v
    myCPU/*.v/*.vh -> ../../rtl/*
  tb_cpp/
    Makefile
    tests/*_tb.sv              // copied 模块和 wrapper 的模块级测试
  reference_cpu/open-la500/
```

规则：

- `rtl/` 是本项目 RTL 的唯一实体源目录。
- `mycpu_env/myCPU/v_src/` 是废弃目录，不再使用；如果历史脚本生成了它，运行 `make mycpu-sync-rtl` 会删除。
- `chiplab/myCPU/` 只作为 Chiplab 源入口，用软链接指向 `rtl/` 和 sim-only 模型。
- 新增或修改 RTL 时只改 `rtl/`；需要刷新 Chiplab 视图时运行 `make chiplab-sync-rtl`。
- `mycpu_env/myCPU/sim/` 放 `RAMB36E1` 等仿真模型；这些文件只进仿真/Chiplab 源列表，不作为综合 RTL 主源。

### 5.2 根 Makefile 要学习的能力

从参考工程迁移这些能力：

- `CPU ?= PIPELINE` / `CPU=LA500`：同一套命令能切换本项目 core 和 `reference_cpu/open-la500`。
- `PERF_MONI`、`L2_PREFETCH`、`RTL_LOG`、`TRACE`：性能计数和 debug trace 用 Make 参数开关控制。
- `SIM_JOBS`、`CHIPLAB_BUILD_JOBS`：避免 Verilator/Chiplab 编译并行度写死。
- `VSRC_project_rtl`、`VSRC_sim_top`、`SIM_MODELS`：区分项目 RTL、仿真 shell、sim-only 模型。
- `configure` / `chiplab-run`：在 LA 根目录直接启动 Chiplab，不要求手动进入 `chiplab/sims/verilator/run_prog`。
- `chiplab-list`：列出支持的软件目标。
- `chiplab-sync-rtl`：把项目 RTL、`.vh`、sim-only RAM 模型同步或软链接到 `chiplab/myCPU`。

移植时先做 wrapper 命令和目录结构，再把 copied RTL 接上。这样即使 CPU 还没完成，也能早期发现 Chiplab 源列表、宏、顶层端口和仿真模型问题。

### 5.3 Chiplab `core_top` wrapper 合同

`chiplab/myCPU/core_top.v` 是必须单独维护的适配层，职责是：

- 对外保持 Chiplab/NSCSCC 风格 AXI 端口：`ar/aw/w/r/b`、`arlock/arcache/arprot`、`awlock/awcache/awprot`、`wid` 等。
- 对内实例化本项目目标 core，例如后续 `la_pipeline_core` 或 `core_top`。
- 输出 `debug0_wb_*`，后续在 `CPU_2CMT` 下可输出 `debug1_wb_*`。
- 提供 `ws_valid`，最小实现为提交有效信号 OR。
- 在 `DIFFTEST_EN` 下接出 Chiplab 需要的 commit、exception、load/store、CSR、GPR 观察总线。
- 保持 reset PC、interrupt、AXI ID/len/size/burst 语义和 Chiplab 环境一致。

注意：Chiplab difftest 需要的不只是 `debug_wb_*`。EXP 和复杂软件阶段必须能观察 CSR、异常、TLB fill、load/store 物理地址、`ertn`、timer 等状态；这些信号要从 WB/commit 统一产生。

### 5.4 Verilator shell 合同

动态 difftest 入口继续使用 `verilator_top`，但要向参考工程靠齐：

- `verilator_top.v` 包本项目 core，连接 `axi_ram`、DPI memory、public debug wire。
- `verilator_top_la500.v` 包 `reference_cpu/open-la500`，用于 `CPU=LA500` 对照。
- public wire 至少保留：`debug_wb_valid`、`debug_wb_pc`、`debug_wb_rf_wen`、`debug_wb_rf_wnum`、`debug_wb_rf_wdata`、`debug_wb_inst`。
- 后续双发射只先支持 `debug1_*` 观察，不改变单提交 difftest 的基本路径。
- `PERF_MONI=1` 时暴露 BPU/cache/frontend/mem wait 计数器，不开时不污染综合路径。

### 5.5 tb_cpp 模块级验证

复制 cache/BPU/AXI 前，要同步迁移或重建最小 `tb_cpp` 框架。优先覆盖：

- `cpu_bpu`
- `fetch_buffer`
- `cpu_l1_icache`
- `cpu_l1_dcache`
- `cpu_l2_cache`
- `axi_arbiter`
- `ramb36e1_model`
- LA wrapper：`frontend_top`、`memsys_top`、`commit_unit`

模块级测试的价值是把 “copied 模块本身坏了” 和 “LA wrapper 接错了” 分开。每次改 ready/valid、flush、epoch、uncached、AXI burst、cache op，可优先跑对应 case，再进 EXP/Chiplab。

### 5.6 Chiplab 特别坑位

移植时必须提前固化这些规则：

- `0x1fe0_xxxx` 这类 Chiplab MMIO 必须走 uncached 精确 byte/half/word 单拍访问，不能对齐成 cache line refill。
- ICache/L2 旧路径响应在 redirect/flush 后不能绑定到新 PC，必须用 epoch、stale response pending 或 response kill 规则处理。
- `cacop/ibar` 后必须有可解释的 I/D 自一致规则，哪怕第一版退化为全 invalidate。
- Chiplab wrapper 里的 `DIFFTEST_EN` 信号要从 commit 后打一拍或按 Chiplab 期望整理，避免异常 PC/指令和普通 commit 混在同一拍错位。
- `CPU=LA500` 对照入口用于区分“环境坏了”还是“本项目 core 坏了”，必须保留。

## 6. 阶段计划

### A0.0：学习并移植 fpga-pipeline-cpu 工程外壳

目标：

- 先把参考工程的外壳学过来：根 Makefile、Chiplab wrapper、Verilator shell、`tb_cpp` 框架、`CPU=LA500` 对照入口。
- 在本项目中建立 Chiplab 可接入的工程形态，避免 A0-A3 只在动态 difftest 中闭门造车。
- 不在 A0.0 大改 CPU 微架构；重点是把工程入口和接口合同定下来。

任务：

- 对照参考工程 Makefile，给 LA 根 Makefile 增加或规划：`CPU`、`PERF_MONI`、`TRACE`、`SIM_JOBS`、`CHIPLAB_BUILD_JOBS`、`configure`、`chiplab-list`、`chiplab-sync-rtl`。
- 在 LA 中引入 Chiplab 目录或固定 `CHIPLAB_HOME` 策略；项目内保留 `chiplab/`，保证可复现。
- 新增或规划 `chiplab/myCPU/core_top.v`，把 Chiplab AXI/debug/difftest 端口适配到当前 core 或后续 6 级 core。
- 对齐 `verilator_top.v`，保留当前动态 difftest 入口，同时预留 `CPU=LA500` 的 `verilator_top_la500.v`。
- 迁移 `sim/ramb36e1_model.v` 的使用规则：sim-only 加入 Verilator/Chiplab 源列表，不混入综合 RTL。
- 引入最小 `tb_cpp` 框架或记录迁移步骤，至少能先跑 copied 模块的独立 testbench。
- 记录参考工程关键命令、日志位置和 Chiplab MMIO/ICache stale response 两个已知坑。

验收：

- LA 根目录能列出 Chiplab 软件目标，或明确记录尚缺 Chiplab tree 的阻塞原因。
- `make all EXP=...` 动态 difftest 入口不被破坏。
- Chiplab `core_top` wrapper 的端口合同写清楚，`DIFFTEST_EN`、`CPU_2CMT`、AXI/debug 连接点明确。
- `CPU=LA500` 对照入口有落点；即使第一版未跑通，也不能和本项目 core 入口混在一起。
- `tb_cpp` 第一批目标清单明确：BPU、fetch buffer、L1I、L1D、L2、AXI arbiter、RAMB36E1。

### A0：6 级流水线与外部接口

目标：

- 直接建立目标 6 级流水线：`F1/F2/D1/EX/M1/WB`。
- 完善 CPU 外部 AXI、debug、difftest、SoC wrapper 接口，避免后续阶段再重排顶层。
- 把当前 8 级实现当作迁移参照，而不是继续包壳扩展。

任务：

- 新建或重构 `core_top` 主干，划分 `frontend_top/backend_top/memsys_top/commit_unit/redirect_ctrl`。
- 定义 6 级 stage packet：`fetch_pkt/uop_pkt/mem_req/redirect_pkt/commit_pkt`。
- 完成 AXI read/write 基本桥接与仲裁接口，先可 all-miss/uncached 保守实现。
- 接通 `debug_wb_*`、`ws_valid`、difftest 提交点到 WB/commit。
- 保留当前 EXP 基线记录，用于对照迁移是否退步。

验收：

- 6 级 RTL 主链可编译。
- 最小 `smoke_test.S` 能跑通 F1/F2/D1/EX/M1/WB。
- AXI I/D 基础读写握手可观察。
- debug/difftest 不重复、不漏提交。

### A1：完整骨架与 stub

目标：

- 在 A0 主链上补齐所有最终会存在的模块位置和 stub。
- stub 可以保守，但接口必须接近最终形态。

任务：

- 前端 stub：BPU、L1I/ITCM 选择、fetch buffer 占位、redirect/epoch。
- 后端 stub：decode/issue、regfile、scoreboard、hazard、bypass、ALU、MDU、CSR、TLB。
- 访存 stub：L1D、Store Buffer、L2、AXI bridge、uncached/MMIO path。
- 配置参数占位：`TLB_ENABLE/L1I_ENABLE/L1D_ENABLE/L2_ENABLE/BPU_ENABLE`。
- Verilator sim-only 接入 `RAMB36E1` 同名模型。

验收：

- 所有 stub 存在并参与顶层连接。
- `BASE_SAFE` 配置能跑 smoke。
- 关掉 BPU/cache/TLB 时仍有可解释的保守路径。

### A2：借鉴参考骨架彻底完善

目标：

- 借鉴并复制成熟 reference 模块，把 A1 的 stub 替换成可工作的骨架。
- 这一阶段重在“结构彻底到位”，不是追求所有指令一次性补完。
- A2 是最大接口风险阶段，必须拆成两个门槛：`A2a 接入可编译` 和 `A2b 接口调通可跑 smoke`。

任务：

- 从 `/home/luyoung/demos/fpga-pipeline-cpu/rtl` 复制并接入 `cpu_bpu.v`、`fetch_buffer.v`、`cpu_l1_icache.v`、`cpu_l1_dcache.v`、`cpu_l2_cache.v`、`axi_arbiter.v`。
- 复制必要依赖：`cpu_primitives.v`、debug macro shim、必要 helper/packet 模块。
- 借鉴 `reference_cpu/open-la500` 的 `csr.v/addr_trans.v/tlb_entry.v/axi_bridge.v`，确定 LA CSR/TLB/MMU/AXI 行为边界。
- 建立 copied 模块外层 LA wrapper，统一 reset、valid/ready、flush/epoch、config enable。
- WB/commit 统一 GPR、CSR、store release、exception/ertn、debug/difftest。
- 明确 wrapper 复杂度不低，必须逐项处理：信号命名、reset 极性、valid/ready、stall/flush、epoch kill、config enable、debug 可见性、uncached/MMIO、difftest sideband。

A2a 接入门槛：

- copied 模块进入工程并可被 Verilator 解析。
- 所有 copied 模块有 wrapper 或明确的未接入 stub。
- 允许功能暂不通，但不能破坏 `BASE_SAFE` 的保守路径。

A2b 调通门槛：

- `BASE_SAFE` smoke 通过。
- 至少一个 copied 模块的 enable-on 配置跑通最小程序，例如 `BPU_ENABLE=1` 或 `L1I_ENABLE=1`。
- copied 模块的 flush/epoch/ready/valid 行为有波形或日志观察点。

验收：

- copied BPU/L1I/L1D/L2/AXI/arbiter 都进入工程，且可通过参数关闭。
- `BASE_SAFE` smoke 通过。
- `L1_ON` 或等价 cache-on 最小程序可运行；若未完全稳定，记录阻塞点但接口不再重改。
- A2 结束时要重新评估 A3 工期和风险；如果 A2b 仍有 enable-on 组合不稳定，不能假装 A3 是普通补指令阶段。

### A3：补完 reference_cpu 指令并通过 EXP=23

目标：

- 在 6 级主链上实现 `/home/luyoung/LA/reference_cpu/open-la500` 已覆盖的全部 LA32R 指令和系统机制。
- A3 的退出红线是 `make all EXP=23` 通过；只通过较小 EXP 不算 A3 完成。
- `reference_cpu/open-la500/id_stage.v` 是指令覆盖清单的第一参考，`csr.v/addr_trans.v/tlb_entry.v` 是 CSR/TLB/MMU 行为参考。
- A3 是集成调试死亡谷，进入 A3 前必须基于 A2 结束时的 EXP 基线重新评估任务量。

任务：

- 整数 ALU：`add.w/sub.w/slt/sltu/nor/and/or/xor/andn/orn`。
- 立即数与 PC 类：`lu12i.w/addi.w/slti/sltui/pcaddi/pcaddu12i/andi/ori/xori`。
- 移位：`slli.w/srli.w/srai.w/sll.w/srl.w/sra.w`。
- 分支跳转：`jirl/b/bl/beq/bne/blt/bge/bltu/bgeu`。
- 乘除：`mul.w/mulh.w/mulh.wu/div.w/div.wu/mod.w/mod.wu`。
- 访存：`ld.b/ld.bu/ld.h/ld.hu/ld.w/st.b/st.h/st.w`，含 ALE、符号扩展、写掩码和 store data 对齐。
- 原子：`ll.w/sc.w`，含 `llbit`、异常/flush 后清理和失败返回语义。
- CSR/计数：`csrrd/csrwr/csrxchg/rdcntid.w/rdcntvl.w/rdcntvh.w/cpucfg`。
- 异常与特权：`syscall/break/ertn/idle`，含 INE/IPE/ADEF/ADEM/ALE/INT 等可见状态。
- TLB/MMU：`tlbsrch/tlbrd/tlbwr/tlbfill/invtlb`，DMW、ASID、TLB refill/page invalid/dirty/privilege 路径。
- cache/barrier：`cacop/preld/dbar/ibar`，允许最小安全退化，但软件可解释且 difftest/定向测试可验证。
- 对齐 reference 行为：除 0、CSR side effect、TLB 指令 stall/refetch、cache op 后 refetch、barrier 顺序都要与 `reference_cpu` 或 Chiplab 期望一致。
- 调试重点必须显式覆盖：精确异常、TLB refill 后重取、`ertn` 特权级/PC 恢复、`llbit` 状态机、cache op/refetch、CSR side effect、cache miss 与中断/异常竞争。

验收：

- `make all EXP=23` 通过。
- Chiplab/func 中 EXP=23 覆盖的普通指令、CSR、异常、TLB、cache op、原子、barrier 项全部通过。
- difftest 提交顺序、GPR 写回、CSR/TLB/异常可见状态与参考一致。
- 对 reference_cpu 已实现但 EXP=23 未充分覆盖的指令，必须补充定向 smoke 或记录缺口。
- A3 通过后冻结一份 `EXP=23` 配置和日志，作为 A4/B/C 的回归基线。

### A4：可配置系统软件正确性收口

目标：

- 在 A3 `EXP=23` 通过的基础上，建立可配置 CPU：TLB、L1I、L1D、L2、BPU 都必须有清晰开关。
- 每个开关关闭时功能仍可解释，打开时功能结果一致，只允许性能变化。

必须提供的配置开关：

- `TLB_ENABLE`：关闭时走 direct/DMW/保守直通策略，打开时启用 TLB 查询、refill 和权限异常。
- `L1I_ENABLE`：关闭时 I-side 走 uncached/all-miss path，打开时使用 copied `cpu_l1_icache`。
- `L1D_ENABLE`：关闭时 D-side 走 uncached/all-miss path，打开时使用 copied `cpu_l1_dcache`。
- `L2_ENABLE`：关闭时 L1 miss 直接到 AXI/bridge，打开时使用 copied `cpu_l2_cache`。
- `BPU_ENABLE`：关闭时固定 not-taken/顺序取指，打开时使用 copied `cpu_bpu`。
- `CACHE_OP_STRICT_ENABLE` 或等价参数：选择最小安全退化 cache op 或真实 cache invalidate/writeback 行为。

推荐回归矩阵：

```text
BASE_SAFE : TLB=0 L1I=0 L1D=0 L2=0 BPU=0
TLB_ON    : TLB=1 L1I=0 L1D=0 L2=0 BPU=0
L1_ON     : TLB=1 L1I=1 L1D=1 L2=0 BPU=0
L2_ON     : TLB=1 L1I=1 L1D=1 L2=1 BPU=0
BPU_ON    : TLB=1 L1I=1 L1D=1 L2=1 BPU=1
PERF_ON   : 全部打开，允许 prefetch/merge 等性能功能按参数开启
```

验收：

- `BASE_SAFE` 和 `BPU_ON` 至少都能通过 `make all EXP=23`。
- `TLB_ON/L1_ON/L2_ON` 至少通过对应 Chiplab/EXP 子集和 smoke；最终目标是同样通过 EXP=23。
- 每个开关组合都有仿真参数、Makefile 参数或 Verilog parameter 入口，不靠手改 RTL。
- cache/BPU/TLB 关闭和打开时，功能结果一致；若某组合暂不支持，必须在配置表中写明原因和替代安全配置。
- 中断、timer、DMW、TLB refill、MMIO uncached、cache op、barrier、原子指令都有定向测试。
- 异常嵌套、TLB 填满替换、异常/中断优先级可解释。
- 复杂裸机/启动代码/RTOS 可跑。
- 条件具备时跑 Linux boot/early printk 作为强回归。

### B1：ITCM

目标：

- 在 F2/memsys 中加入可配置 ITCM，作为低延迟取指窗口。

任务：

- `ITCM_ENABLE`、窗口 base/size 参数。
- 命中 ITCM 时绕过 L1I/L2/AXI，固定低延迟返回。
- ITCM 存储使用 FPGA 原语或可综合 RAM；仿真有同等初始化路径。
- 与 ICache、`ibar/cacop`、redirect/epoch 的一致性规则写清楚。

验收：

- ITCM on/off 功能一致。
- ITCM 命中取指等待周期下降。
- boot/裸机热点代码可放入 ITCM 跑通。

### B2：Fetch Buffer 完整化

目标：

- 在 copied `fetch_buffer` 基础上完善取指缓冲，支撑 cache miss、redirect、后续双发射。
- A3 前必须已有最小 Fetch Buffer 或等价单 entry 缓冲；B2 做的是完整化，不是从零补前端缓冲。

任务：

- 扩展 entry 数、slot 信息、epoch、pred meta、fetch fault。
- 支持 redirect 后清空旧 entry。
- 支持 ICache response queue、same-line merge 或 fast redirect buffer 的接入点。
- 暴露 frontend stall、fetch buffer full/empty、branch flush 计数器。

验收：

- 分支压力和 ICache miss 压力下不丢指令、不重复发射。
- Fetch Buffer 开关或深度变化不影响功能结果。

### B3：Store Buffer 完整化

目标：

- 在 M1/WB 之间完成 Store Buffer：store 在 M1 分配，WB commit 后按序对外可见。
- A3 前必须已有最小 Store Buffer 或等价精确 store 机制，保证 EXP=23 中 store、异常、MMIO、原子语义正确；B3 做容量、forwarding 和性能完整化。

任务：

- 至少 4 entry store buffer。
- store-load forwarding，先覆盖同 word，部分字节冲突可 stall。
- commit release、flush kill、异常精确性。
- uncached/MMIO store 不被错误合并或重排。
- 与 L1D write-through 路径对接。

验收：

- store/load 压力测试、MMIO store、异常前后 store 精确性通过。
- Store Buffer full 有反压和计数器。

### C：双发射

目标：

- 在 A4 正确性和 B2/B3 缓冲能力稳定后，再打开双发射。
- C 阶段只承诺“双发射单提交”作为正式目标；双提交属于 C+ 延伸目标，不在本蓝图完成承诺内。

任务：

- D1 扩展双译码、双 issue packet。
- 初版只允许安全配对：ALU+ALU、ALU+branch、ALU+load/store。
- 禁止 LSU+LSU、MDU+任意、CSR/TLB/异常+任意、slot1 依赖 slot0。
- EX 扩展 ALU1，M1 保守单 LSU。
- WB 使用双 issue 单提交队列，difftest/commit log 始终按程序顺序逐条提交。
- 双提交只在 C 完全稳定后另立 C+，不得为了追双提交破坏 C 的验收边界。

验收：

- 双发射开关关闭/开启功能一致。
- difftest/commit log 仍按程序顺序可解释。
- 独立 ALU/混合流 IPC 相比单发射有可量化提升。

## 7. 里程碑

| 里程碑 | 覆盖阶段 | 成果类型 | 验收重点 |
| --- | --- | --- | --- |
| M0 工程外壳/Chiplab 对齐 | A0.0 | 完整性 | 根 Makefile、Chiplab wrapper、Verilator shell、tb_cpp、CPU=LA500 对照入口有明确落点。 |
| M1 6 级接口主链 | A0 | 完整性 | F1/F2/D1/EX/M1/WB 主链、AXI/debug/difftest 接口可跑 smoke。 |
| M2 完整 stub 骨架 | A1 | 完整性 | BPU/L1I/L1D/L2/TLB/CSR/MDU/SB 等 stub 全部在位，BASE_SAFE 可跑。 |
| M3 参考骨架完善 | A2a/A2b | 完整性 | copied BPU/L1I/L1D/L2/AXI/arbiter 接入并可配置关闭，BASE_SAFE smoke 通过。 |
| M4 EXP=23 功能 CPU | A3 | 完整性 | `reference_cpu/open-la500` 指令覆盖对齐，`make all EXP=23` 通过。 |
| M5 可配置系统软件正确性 CPU | A4 | 完整性 | TLB/L1I/L1D/L2/BPU 可关闭可开启，开关矩阵功能一致。 |
| P1 ITCM 取指加速 | B1 | 性能 | ITCM 命中路径降低取指等待。 |
| P2 前端缓冲增强 | B2 | 性能/完整性 | Fetch Buffer 在 miss/redirect 压力下稳定，并为双发射准备 slot。 |
| P3 Store Buffer 增强 | B3 | 性能/完整性 | store commit release、forwarding、MMIO 顺序和精确异常稳定。 |
| P4 双发射单提交性能版 | C | 性能 | 双发射开关开启后 IPC 有可量化提升，提交仍逐条有序。 |

## 8. 验证策略

验证分三层：

- 最小冒烟：`smoke_test.S`，覆盖 ALU、load/store、branch、commit debug。
- Chiplab/difftest：主功能验证，检查提交顺序、寄存器写回、异常可见状态、CSR/TLB 状态。
- 强回归软件：复杂裸机、启动代码、RTOS、Linux boot/early printk。
- 定向压力测试：TLB refill/替换/权限、cache miss/refill/cacop、Store Buffer forwarding/MMIO/flush、interrupt 与 cache/TLB miss 竞争。
- 模块级验证：关键模块至少补独立 testbench 或 SystemVerilog assertion，覆盖 ready/valid 不丢包、flush kill、epoch 过滤、store commit 顺序。

每次接入 copied 模块都要做开关对照：

```text
cache/bpu off: 功能先正确
cache/bpu on : 功能一致，性能再评估
```

Chiplab 入口采用参考工程同款根目录 wrapper：

```bash
make chiplab-list
make configure RUN=hello_world
make configure RUN=coremark
make configure RUN=coremark CPU=LA500
```

Chiplab 日志默认按参考工程约定查看：

```text
chiplab/sims/verilator/run_prog/log/<case>_log/
```

动态 difftest 入口继续保留：

```bash
make all EXP=23
make all EXP=23 CPU=LA500
make all EXP=23 PERF_MONI=1
```

模块级入口参考：

```bash
make -C tb_cpp list
make -C tb_cpp run CASE=cpu_bpu
make -C tb_cpp run CASE=cpu_l1_icache
make -C tb_cpp run CASE=cpu_l1_dcache
make -C tb_cpp run CASE=cpu_l2_cache
make -C tb_cpp run CASE=axi_arbiter
```

Linux 强回归门槛：

- A4 结束后，如果 `TLB=1 L1I=1 L1D=1 L2=1 BPU=1` 能通过 `EXP=23`，必须启动 Linux boot/early printk 回归。
- Linux 回归失败不改变里程碑命名，但必须回到 A4 配置矩阵或 A3 系统机制清单定位。
- 若全开配置尚不能过 `EXP=23`，不得把 Linux 失败当作独立问题处理，先回到 EXP/difftest 基线。

## 9. 立即执行顺序

```text
A0.0 学习并移植 fpga-pipeline-cpu 工程外壳和 Chiplab 入口
  -> A0 建 6 级流水线主链，完善 AXI/debug/difftest 接口
  -> A1 补齐完整骨架和 stub
  -> A2 复制/借鉴参考骨架，接入 BPU/L1I/L1D/L2/AXI/arbiter
  -> A3 补完 reference_cpu 指令覆盖并通过 EXP=23
  -> A4 建 TLB/L1/L2/BPU 等开关矩阵并做系统软件正确性收口
  -> B1 ITCM
  -> B2 Fetch Buffer 完整化
  -> B3 Store Buffer 完整化
  -> C  双发射
```

依赖关系：

- A0.0 是工程入口前置，不追求 CPU 功能提升，但必须避免后续 Chiplab 接入变成返工。
- A0-A4 是正确性主线，必须串行推进。
- B1/B2/B3 是增强线，原则上在 A4 后做；若某项对 A3 调试有明显帮助，可以提前做最小版本，但不能阻塞 A3 `EXP=23`。
- C 依赖 A4 正确性闭环，并强依赖 B2/B3 的前端/访存缓冲能力。
- C 只承诺双发射单提交；双提交另立 C+，不和本轮目标混在一起。

核心原则：先把可复制的成熟模块放进来，再围绕它们搭 LA 的 6 级流水线。不要在本项目里重新发明 L1/L2/BPU/AXI 仲裁器。

## 10. 每阶段记录模板

```text
阶段:
目标:
工程入口变化:
Chiplab wrapper 状态:
tb_cpp 状态:
复制的参考模块:
参考来源版本/hash:
copied 模块本地 patch 记录:
新增/修改 LA wrapper:
新增/修改 packet:
cache/bpu 开关状态:
TLB/L1I/L1D/L2/BPU 配置:
通过测试:
可运行状态:
difftest 状态:
Chiplab/EXP 状态:
定向压力/模块级测试:
未通过但已知原因:
时序风险:
接口适配风险:
下一阶段依赖:
```
