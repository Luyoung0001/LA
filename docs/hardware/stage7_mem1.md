# stage7_mem1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage7_mem1.v`
- 角色：访存一级（请求发射 + 返回等待）

## 功能
- 非访存指令：直接旁路到写回数据。
- 访存指令：
  - 锁存到 `pend_*`。
  - 首拍发 `dcache_req_*`。
  - 等待 `dcache_resp_valid` 后提交。
- store 返回时仅作为完成确认，不写寄存器。

## 时序
- load/store 为“请求拍 + 等待拍 + 返回提交拍”模型。
- `pend_valid` 保证一个访存事务完整闭环。
