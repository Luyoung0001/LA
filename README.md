# LA
LoongArch 挑战赛工程（当前为 8~9 级流水线骨架 + 软件 SoC 仿真链路）。

## 环境准备

### 工具链安装
1. LoongArch 工具链：从 [ChipLab 仓库](https://gitee.com/loongson-edu/chiplab/tree/chiplab_diff/toolchains) 下载并安装 `loongarch32r-linux-gnusf-*`
2. 仿真工具：
```bash
sudo apt install iverilog verilator bear
```

## 快速开始

```bash
# 一键运行（默认 EXP=6）
make all

# 指定测试编号
make all EXP=6
```

## 项目结构

```text
LA/
├── docs/                   # 模块文档与系统拓扑（含 Mermaid）
├── mycpu_env/
│   ├── myCPU/
│   │   ├── v_src/          # 核心流水线模块（stage0~stage8, core_top, mycpu_top）
│   │   ├── DPIC/           # SystemVerilog DPI/AXI RAM 侧
│   │   ├── DPIC_C/         # DPI-C C/C++ 桥接实现
│   │   └── memory/         # 软件物理内存模型（pmem）
│   ├── func/               # 功能测试程序（EXP 控制）
│   └── gettrace/           # legacy 静态 trace 生成（可选）
├── Verilator/              # 仿真入口与 difftest 主循环
└── Makefile                # 顶层构建文件
```

## 文档入口

- 系统总览与模块关系图：`docs/00_system_topology.md`
- 全部文档索引：`docs/README.md`

## Makefile 目标

- `make test EXP=6`：编译 `func` 测试程序
- `make trace`：生成 `golden_trace.txt`（仅 legacy 静态比对）
- `make build`：编译 Verilator 可执行文件
- `make run`：运行仿真（动态 NEMU difftest）
- `make all EXP=6`：执行 `test + run`
- `make docs`：输出文档索引路径
- `make clean`：清理构建产物
- `make help`：查看命令帮助

## 仿真链路（软件 SoC 接入）

`core_top (AXI master)`
-> `verilator_top`
-> `axi_ram.sv`
-> `dpi_c.cpp`
-> `paddr.c (pmem)`

程序镜像 `mycpu_env/func/obj/main.bin` 由 `paddr.c::load_inst()` 装载到 `0x1c000000`。

## 动态 Difftest

- 默认参考核：`/home/luyoung/chiplab/toolchains/nemu/la32r-nemu-interpreter-so`
- 每次 DUT `ws_valid` 提交一条指令时，REF 执行 `difftest_exec(1)`，随后对比 GPR + 提交 PC。
- 不再依赖 `golden_trace.txt` 作为运行必需条件。

可选环境变量：

- `LA_DIFFTEST_REF_SO`：指定 NEMU `.so` 路径
- `LA_STOP_PC`：指定通过判定 PC（默认 `0x1c000100`）
- `LA_DIFFTEST_VERBOSE=1`：打印每条提交日志

## 说明

- 当前框架强调“先跑通链路与时序”：
  - 分支预测器：1 拍返回（`branch_predictor_d1`）
  - 寄存器堆读：1 拍返回（`regfile_d1`）
  - `icache/dcache/muldiv/csr` 为可扩展骨架版本
