# inst_ram 模块文档

- 源文件：`mycpu_env/myCPU/DPIC/inst_ram.sv`
- 角色：DPI 同步指令 RAM 封装

## 功能
- 调用 DPI-C `inst_ram_read(a)` 读取指令。
- 当 `en=1` 时，时钟上升沿更新 `spo`。

## 时序
- 同步读模型：地址与使能在本拍输入，`spo` 在本拍上升沿后更新。
- 若 `en=0`，输出置 `0`。

## 备注
- 当前主仿真路径主要使用 `axi_ram`，此模块可用于 SRAM-like 路径实验。
