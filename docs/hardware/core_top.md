# core_top 模块文档

- 源文件：`mycpu_env/myCPU/v_src/mycpu_top.v`
- 模块定位：CPU 主核心（流水线串接 + AXI 主机控制）

## 1. 功能职责
- 串接 `stage0_ifu` 到 `stage8_wbu`。
- 串接 `branch_predictor_d1`、`regfile_d1`、`muldiv_stub`。
- 统一仲裁并驱动 AXI 主接口（指令读 + 数据读写）。
- 输出 `debug0_wb_*` 与 `ws_valid`。

## 2. 关键接口
- AXI 主接口：`ar* / r* / aw* / w* / b*`。
- 外部调试接口：`reg_num -> rf_rdata`，`debug0_wb_*`。
- 中断等输入当前未实用，仅保留端口兼容。

## 3. 时序与状态机
### 3.1 指令发射节奏
- `issue_fire_w = ifu_out_valid_w && !issue_busy_r`。
- 发射后 `issue_busy_r` 置位，直到 `stage8_wbu` 给出 `wbu_ws_valid_w` 才清零。
- 结果：当前实现是“单在途指令”的流水线框架（控制简单，时序稳定）。

### 3.2 AXI 状态机（`axi_state_r`）
- `AXI_IDLE`：优先处理数据访存请求，再处理取指请求。
- 取指：`AXI_I_AR -> AXI_I_R`，收到 `rvalid` 后打一拍 `icache_resp_valid_r` 给 IF2。
- 数据读：`AXI_D_AR -> AXI_D_R`，收到 `rvalid` 后打一拍 `dcache_resp_valid_r` 给 MEM1。
- 数据写：`AXI_D_AW -> AXI_D_W -> AXI_D_B`，收到 `bvalid` 后打一拍 `dcache_resp_valid_r`（写完成应答）。

## 4. 分支与重定向
- EX2 给出 `branch_update_valid/branch_taken/branch_target`。
- IFU 接收 `redirect_valid/redirect_pc`；分支重定向优先于普通取指。
- `hold_fetch_w` 由 `issue_busy_r` 生成，用于冻结 IFU 的 PC 前进。

## 5. 备注
- 该模块已删除旧版“`rj_val + S_EXEC` 单体执行”逻辑，改为真正 stage 连接。
