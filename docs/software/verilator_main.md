# Verilator main.cpp 模块文档

- 源文件：`Verilator/main.cpp`
- 头文件：`Verilator/include/main.h`
- 模块定位：仿真入口、时钟驱动、动态 difftest 控制器

## 1. 功能职责
- 创建 `Vverilator_top` DUT 并打开波形。
- 初始化系统：`init_mem()`、`load_inst()`、加载 NEMU 动态库。
- 将镜像从 DUT 内存同步到 REF（`difftest_memcpy`）。
- 在提交点驱动 REF 单步执行并做寄存器/PC 比对。

## 2. 主流程
1. `init_system()`：初始化内存和镜像，初始化动态 difftest。
2. `reset(1)`：`rst=1` 下执行 1 个时钟周期，再释放复位。
3. `cpu_exec(-1)`：持续运行直到 mismatch 或到达停止 PC。
4. `top->final()`、关闭波形和 `dlopen` 句柄。

## 3. 差分逻辑
- 采样来源：`top->rootp->verilator_top->debug_wb_valid/debug_wb_*`。
- 仅当 `debug_wb_valid==1` 视为一条真实提交。
- 每次提交：
  - REF 执行 `difftest_exec(1)`。
  - 从 NEMU 导出的 `cpu` 符号读取 `gpr` 与 `pc`。
  - 比较 DUT shadow GPR + 提交 PC 与 REF 状态。
- 失败时打印提交信息和逐寄存器差异。

## 4. 时序说明
- `step()` 每次执行两个半拍：`clk=0` 再 `clk=1`。
- `cpu_exec()` 每轮先做 `difftest_step()`，再 `stepi()` 前进 1 周期。
- 差分粒度是“每次提交 1 条指令”。

## 5. 依赖文件
- 程序镜像：`mycpu_env/func/obj/main.bin`
- 参考核：`la32r-nemu-interpreter-so`（默认路径见 README）
- 波形输出：`wave.vcd`
