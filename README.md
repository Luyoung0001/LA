# LA
Loongarch 挑战赛

## 快速开始

```bash
# 一键运行（默认 EXP=10）
make all

# 或指定测试编号
make all EXP=15
```

## 项目结构

```
LA/
├── mycpu_env/              # CPU 验证环境
│   ├── myCPU/             # 用户 CPU 实现
│   │   ├── v_src/         # Verilog 源文件
│   │   ├── DPIC/          # SystemVerilog DPI-C 接口（RAM、CSR）
│   │   ├── DPIC_C/        # DPI-C C++ 实现（内存读写、外设模拟）
│   │   └── memory/        # 内存模型
│   ├── func/              # 功能测试程序
│   │   ├── inst/          # 测试指令集（n1-n81）
│   │   └── obj/           # 编译输出（.elf, .bin, .coe）
│   └── gettrace/          # Golden trace 生成器
│       └── src/           # 单周期参考 SOC（用于生成 golden_trace.txt）
├── Verilator/             # Verilator 仿真主程序
│   └── main.cpp           # difftest 主逻辑
├── obj_dir/               # Verilator 编译输出
└── Makefile               # 顶层构建文件
```

## 工作流程

### 1. 测试程序生成与编译

在 `mycpu_env/func/` 目录下：

```bash
make EXP=N  # N={0,6-16,18-19,21-23}
```

编译流程：
1. 预处理 `start.S` 和 `init.S` → 生成 `.s` 文件
2. 编译测试指令 `inst/nXX_*.S` → 生成 `libinst.a`
3. 链接生成 `main.elf`
4. 提取 `.text` 和 `.data` 段 → `main.bin` 和 `main.data`
5. 转换为 COE 格式 → `inst_ram.coe`（用于仿真）

工具链：`loongarch32r-linux-gnusf-gcc/as/ld/objcopy/objdump`

### 2. Golden Trace 生成

在 `mycpu_env/gettrace/` 目录下：

```bash
make iverilog  # 使用 iverilog 仿真单周期 SOC
```

- 使用单周期参考实现（CPI=1）快速生成标准执行轨迹
- 读取 `../func/obj/inst_ram.mif`
- 输出 `golden_trace.txt`（格式：we pc wnum value）

### 3. Verilator 仿真与 Difftest

顶层 Makefile：

```bash
make build  # 编译 Verilator 仿真器
make run    # 运行仿真并进行 difftest
```

#### Verilator 编译流程
1. `make simu`：Verilator 将 Verilog 转换为 C++
   - 输入：`myCPU/v_src/*.v` + `DPIC/*.sv`
   - 输出：`obj_dir/Vverilator_top.mk`
2. `make build`：编译 C++ 代码
   - 链接：`Verilator/main.cpp` + `DPIC_C/src/*.cpp` + `memory/src/*.c`
   - 生成：`obj_dir/Vverilator_top`（可执行文件）

#### Difftest 机制
- 对比 PC、写使能、寄存器号、写入值
- 每个时钟周期对比 CPU 输出与 golden trace
- 不匹配时报错并输出差异

### 4. DPI-C 接口

通过 SystemVerilog DPI-C 实现 CPU 与 C++ 的交互：

- `inst_ram_read(addr)`：指令内存读取
- `data_ram_read(addr)`：数据内存读取（支持外设地址）
- `data_ram_write(addr, wdata, wmask)`：数据内存写入（支持字节写掩码）

外设地址映射：
- `0xbfafff10`：虚拟串口（UART）
- `0xbfafff20`：仿真结束标志
- `0xbfafff30`：Trace 开关
- `0xbfaf8000-0xbfaf8070`：控制寄存器

## 快速开始

```bash
# 1. 编译测试程序（例如 EXP=10）
cd mycpu_env/func && make EXP=10

# 2. 生成 golden trace
cd ../gettrace && make iverilog

# 3. 运行仿真与 difftest
cd ../.. && make run
```

波形文件：`wave.vcd`（可用 GTKWave 查看）

