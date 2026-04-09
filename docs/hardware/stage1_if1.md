# stage1_if1 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage1_if1.v`
- 角色：取指请求发射级

## 功能
- 将 `in_pc` 直接转成 `icache_req_addr`。
- 将 valid/pc 透传到 IF2。

## 时序
- 时钟上升沿寄存输入。
- 无停顿控制；是否发射由上游 `in_valid` 决定。
