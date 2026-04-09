# stage2_if2 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage2_if2.v`
- 角色：取指响应对齐级

## 功能
- 用 `pend_valid/pend_pc` 缓存一次在途取指。
- 等待 `icache_resp_valid`，到达后输出 `out_valid/out_pc/out_inst`。

## 时序
- 当 `in_valid && !pend_valid`：锁存请求 PC。
- 当 `pend_valid && icache_resp_valid`：同拍输出指令并清空 pending。
- 对 AXI 返回延迟不敏感，可等待任意拍数。
