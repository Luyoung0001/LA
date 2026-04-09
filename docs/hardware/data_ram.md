# data_ram 模块文档

- 源文件：`mycpu_env/myCPU/DPIC/data_ram.sv`
- 角色：DPI 同步数据 RAM 封装

## 功能
- 写：`we!=0 && en` 时调用 `data_ram_write(a, d, we7)`。
- 读：`we==0 && en` 时调用 `data_ram_read(a)` 更新 `spo`。

## 时序
- 同步读写，均在时钟上升沿生效。
- 读写互斥由 `we` 判断。

## 备注
- `we7={4'b0,we}`，与 C++ 侧 `wmask` 接口保持一致。
