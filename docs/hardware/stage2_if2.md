# stage2_if2 模块文档

- 源文件：`mycpu_env/myCPU/v_src/stage2_if2.v`
- 功能定位：取指响应对齐级（IF2）

## 内部状态
- `pend_valid/pend_pc`：保存一条在途取指请求

## 工作流程
1. `in_valid && !pend_valid`：锁存 `pend_pc`，置 `pend_valid`。
2. `pend_valid && icache_resp_valid`：输出 `out_valid/out_pc/out_inst`，并清 `pend_valid`。

## 时序语义
- 对响应延迟不敏感，可等待任意拍数 AXI 返回。
- `out_valid` 是脉冲信号，仅在响应到达拍拉高。
- 复位时 `out_inst` 初始化为 `32'h03400000`（调试友好默认值）。

## 设计边界
- 仅支持 1 条 pending fetch。
- 在当前 `core_top` 单在途发射策略下，该限制不会造成功能冲突。

## 时序风险
- 主要是控制寄存器切换，无深组合路径。
