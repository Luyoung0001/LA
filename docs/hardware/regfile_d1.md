# regfile_d1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/regfile_d1.v`
- 角色：32x32 通用寄存器堆（读延迟 1 拍）

## 功能
- 写口：`we && waddr!=0` 时写寄存器。
- 读口：`rreq_valid` 时在下一拍给出 `rvalid/rdata1/rdata2`。
- `x0` 固定为 0（读时硬编码）。
- 提供调试读口：`dbg_raddr -> dbg_rdata`。

## 时序
- 同步读、同步写。
- 读结果与请求相隔 1 个上升沿。
