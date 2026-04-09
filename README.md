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
│   └── gettrace/           # golden trace 生成
├── Verilator/              # 仿真入口与 difftest 主循环
└── Makefile                # 顶层构建文件
```

## 文档入口

- 系统总览与模块关系图：`docs/00_system_topology.md`
- 全部文档索引：`docs/README.md`

## Makefile 目标

- `make test EXP=6`：编译 `func` 测试程序
- `make trace`：生成 `golden_trace.txt`
- `make build`：编译 Verilator 可执行文件
- `make run`：运行仿真（含 difftest）
- `make all EXP=6`：执行 `test + trace + run`
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

## 说明

- 当前框架强调“先跑通链路与时序”：
  - 分支预测器：1 拍返回（`branch_predictor_d1`）
  - 寄存器堆读：1 拍返回（`regfile_d1`）
  - `icache/dcache/muldiv/csr` 为可扩展骨架版本
