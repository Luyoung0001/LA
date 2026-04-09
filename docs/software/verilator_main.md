# Verilator main.cpp 模块文档

- 源文件：`Verilator/main.cpp`
- 头文件：`Verilator/include/main.h`
- 模块定位：仿真入口、时钟驱动、差分检查控制器

## 1. 功能职责
- 创建 `Vverilator_top` DUT 并打开波形。
- 初始化系统：`init_mem()`、`load_inst()`、打开 `golden_trace.txt`。
- 驱动时钟/复位并执行主循环。
- 读取 `debug_wb_*` 做差分校验。

## 2. 主流程
1. `init_system()`：初始化内存和程序镜像、打开参考 trace。
2. `reset(1)`：`rst=1` 下执行 1 个时钟周期，再释放复位。
3. `cpu_exec(-1)`：持续运行直到失败或到达停止 PC（`0x1c000100`）。
4. `top->final()` 与关闭波形。

## 3. 差分逻辑
- 采样来源：`top->rootp->verilator_top->debug_wb_*`。
- 当 `we==0` 或 `wnum==0` 时跳过本次比较。
- 读取参考 trace 时会跳过参考侧 `we==0` 的记录。
- 若 PC 相同于上一条（`last_op.pc`），直接跳过，避免重复提交。

## 4. 时序说明
- `step()` 每次执行两个半拍：`clk=0` 再 `clk=1`。
- `cpu_exec()` 每轮先做一次 `difftest()`，然后再 `stepi()` 前进 1 周期。
- `debug_wb_*` 被视为提交点信号，差分粒度是“每个周期最多一条提交”。

## 5. 依赖文件
- 程序镜像：`mycpu_env/func/obj/main.bin`
- 参考轨迹：`mycpu_env/gettrace/golden_trace.txt`
- 波形输出：`wave.vcd`
