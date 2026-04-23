# paddr.c 模块文档

- 源文件：`mycpu_env/myCPU/memory/src/paddr.c`
- 头文件：`mycpu_env/myCPU/memory/include/paddr.h`
- 模块定位：软件物理内存模型（pmem）

## 1. 功能职责
- 维护全局内存指针 `pmem`。
- 提供物理地址读写接口：`paddr_read/paddr_write`。
- 负责将测试镜像装载到复位向量地址。

## 2. 内存模型
- `init_mem()` 申请 `0x100000000` 字节（4GB）连续内存。
- `padd2host(paddr)` 将 32 位物理地址映射到 `pmem + paddr`。
- `pmem_read/pmem_write` 会把地址低 2 位清零，按 4 字节对齐访问。

## 3. 镜像加载
- `load_inst()` 按候选路径读取镜像（支持 `LA_MAIN_BIN` 环境变量覆盖）。
- 装载目标地址：`RESET_VECTOR = 0x1c000000`。
- 读入大小为镜像文件实际大小，直接拷贝到 `pmem + RESET_VECTOR`。
- 提供 `get_loaded_img_size()/get_loaded_img_path()` 给动态 difftest 使用。

## 4. 时序说明
- `paddr.c` 不维护时钟，属于纯软件存储层。
- 每次 DPI 读写调用都会立即进入 `paddr_read/paddr_write`。
- 对硬件观察到的“1 拍/多拍”行为，来源于 Verilog 侧状态机，不是 `paddr.c` 自身延迟。

## 5. 约束与注意点
- `pmem` 生命周期依赖仿真主程序，当前无主动释放。
- `load_data()` 目前为空壳，数据段初始化未单独实现。
- `paddr.h` 中 `pmem_read/pmem_write` 原型与 `.c` 定义的参数类型存在不一致，当前编译仍可过，但建议后续统一。
