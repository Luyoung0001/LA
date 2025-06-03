#include <main.h>
#include <stdbool.h>
#include <stdint.h>
#include "Vverilator_top.h"
#include "Vverilator_top___024root.h"
#include "Vverilator_top_verilator_top.h"

#include "verilated_fst_c.h"
VerilatedFstC* tfp = new VerilatedFstC;

vluint64_t main_time = 0;  // initial 仿真时间

Vverilator_top* top = new Vverilator_top;

int i = 0;

typedef struct diff {
    uint32_t we;
    uint32_t pc;
    uint32_t wnum;
    uint32_t value;

} diff;

// 读取 ref
diff ref_struct;

// 这里会生成基于 OpenLA500 的 golden_trace.txt

typedef struct golden_trace {
    uint32_t we;
    uint32_t wnum;
    uint32_t pc;
    uint32_t value;
    uint32_t inst;
    uint32_t is_csr_wr;  // 是否对 csr 进行修改
    uint32_t csr_crmd;
    uint32_t csr_prmd;
    uint32_t csr_ectl;
    uint32_t csr_estat;
    uint32_t csr_era;
    uint32_t csr_badv;
    uint32_t csr_eentry;
    uint32_t csr_tlbidx;
    uint32_t csr_tlbehi;
    uint32_t csr_tlbelo0;
    uint32_t csr_tlbelo1;
    uint32_t csr_asid;
    uint32_t csr_save0;
    uint32_t csr_save1;
    uint32_t csr_save2;
    uint32_t csr_save3;
    uint32_t csr_tid;
    uint32_t csr_tcfg;
    uint32_t csr_tval;
    uint32_t csr_ticlr;
    uint32_t csr_llbctl;
    uint32_t csr_tlbrentry;
    uint32_t csr_dmw0;
    uint32_t csr_dmw1;
    uint32_t csr_pgdl;
    uint32_t csr_pgdh;

} golden_trace;
golden_trace trace_info;
// 打开文件
FILE* golden_trace_fp;
FILE* fp;

void op_file() {
    fp = fopen("/home/luyoung/LA/mycpu_env/gettrace/golden_trace.txt", "r");
    golden_trace_fp =
        fopen("/home/luyoung/LA/open_la500_golden_difftest.txt", "w");
}

void gen_golden_trace_file1() {
    fprintf(golden_trace_fp,
            "%d %02x %08x %08x %08x %d %08x %08x %08x %08x %08x %08x %08x %08x "
            "%08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x "
            "%08x %08x %08x %08x %08x\n",
            trace_info.we == 15, trace_info.wnum, trace_info.pc,
            trace_info.value, trace_info.inst, trace_info.is_csr_wr,
            trace_info.csr_crmd, trace_info.csr_prmd, trace_info.csr_ectl,
            trace_info.csr_estat, trace_info.csr_era, trace_info.csr_badv,
            trace_info.csr_eentry, trace_info.csr_tlbidx, trace_info.csr_tlbehi,
            trace_info.csr_tlbelo0, trace_info.csr_tlbelo1, trace_info.csr_asid,
            trace_info.csr_save0, trace_info.csr_save1, trace_info.csr_save2,
            trace_info.csr_save3, trace_info.csr_tid, trace_info.csr_tcfg,
            trace_info.csr_tval, trace_info.csr_ticlr, trace_info.csr_llbctl,
            trace_info.csr_tlbrentry, trace_info.csr_dmw0, trace_info.csr_dmw1,
            trace_info.csr_pgdl, trace_info.csr_pgdh);
}

void gen_golden_trace_file2() {
    fprintf(golden_trace_fp,
            "%d %02x %08x %08x %08x %d %08x %08x %08x %08x %08x %08x %08x %08x "
            "%08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x "
            "%08x %08x %08x %08x %08x\n",
            ref_struct.we, trace_info.wnum, trace_info.pc,
            trace_info.value, trace_info.inst, trace_info.is_csr_wr,
            trace_info.csr_crmd, trace_info.csr_prmd, trace_info.csr_ectl,
            trace_info.csr_estat, trace_info.csr_era, trace_info.csr_badv,
            trace_info.csr_eentry, trace_info.csr_tlbidx, trace_info.csr_tlbehi,
            trace_info.csr_tlbelo0, trace_info.csr_tlbelo1, trace_info.csr_asid,
            trace_info.csr_save0, trace_info.csr_save1, trace_info.csr_save2,
            trace_info.csr_save3, trace_info.csr_tid, trace_info.csr_tcfg,
            trace_info.csr_tval, trace_info.csr_ticlr, trace_info.csr_llbctl,
            trace_info.csr_tlbrentry, trace_info.csr_dmw0, trace_info.csr_dmw1,
            trace_info.csr_pgdl, trace_info.csr_pgdh);
}

void step() {
    top->clk = 0;
    top->eval();

    // if (i >= 800000)
    // tfp->dump(main_time);  // 记录波形数据
    main_time++;  // 时间递增

    top->clk = 1;
    top->eval();

    // if (i >= 800000)
    // tfp->dump(main_time);
    main_time++;
}
void reset(int n) {
    top->rst = 1;
    while (n--) {
        step();
    }
    top->rst = 0;
}

// 执行一步
void stepi() {
    step();
}

void read_ref() {
    fscanf(fp, "%x%x%x%x", &ref_struct.we, &ref_struct.pc, &ref_struct.wnum,
           &ref_struct.value);
}

// 读取 trace，与拉到的信号进行比对
// 上次的状态
diff last_op;

int difftest() {
    trace_info.we = top->rootp->verilator_top->debug_wb_rf_we;
    trace_info.wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    trace_info.pc = top->rootp->verilator_top->debug_wb_pc;
    trace_info.value = top->rootp->verilator_top->debug_wb_rf_wdata;
    trace_info.inst = top->rootp->verilator_top->debug_wb_inst;
    trace_info.is_csr_wr = top->rootp->verilator_top->debug_wb_is_csr_wr_o;
    trace_info.csr_crmd = top->rootp->verilator_top->csr_crmd_diff;
    trace_info.csr_prmd = top->rootp->verilator_top->csr_prmd_diff;
    trace_info.csr_ectl = top->rootp->verilator_top->csr_ectl_diff;
    trace_info.csr_estat = top->rootp->verilator_top->csr_estat_diff;
    trace_info.csr_era = top->rootp->verilator_top->csr_era_diff;
    trace_info.csr_badv = top->rootp->verilator_top->csr_badv_diff;
    trace_info.csr_eentry = top->rootp->verilator_top->csr_eentry_diff;
    trace_info.csr_tlbidx = top->rootp->verilator_top->csr_tlbidx_diff;
    trace_info.csr_tlbehi = top->rootp->verilator_top->csr_tlbehi_diff;
    trace_info.csr_tlbelo0 = top->rootp->verilator_top->csr_tlbelo0_diff;
    trace_info.csr_tlbelo1 = top->rootp->verilator_top->csr_tlbelo1_diff;
    trace_info.csr_asid = top->rootp->verilator_top->csr_asid_diff;
    trace_info.csr_save0 = top->rootp->verilator_top->csr_save0_diff;
    trace_info.csr_save1 = top->rootp->verilator_top->csr_save1_diff;
    trace_info.csr_save2 = top->rootp->verilator_top->csr_save2_diff;
    trace_info.csr_save3 = top->rootp->verilator_top->csr_save3_diff;
    trace_info.csr_tid = top->rootp->verilator_top->csr_tid_diff;
    trace_info.csr_tcfg = top->rootp->verilator_top->csr_tcfg_diff;
    trace_info.csr_tval = top->rootp->verilator_top->csr_tval_diff;
    trace_info.csr_ticlr = top->rootp->verilator_top->csr_ticlr_diff;
    trace_info.csr_llbctl = top->rootp->verilator_top->csr_llbctl_diff;
    trace_info.csr_tlbrentry = top->rootp->verilator_top->csr_tlbrentry_diff;
    trace_info.csr_dmw0 = top->rootp->verilator_top->csr_dmw0_diff;
    trace_info.csr_dmw1 = top->rootp->verilator_top->csr_dmw1_diff;
    trace_info.csr_pgdl = top->rootp->verilator_top->csr_pgdl_diff;
    trace_info.csr_pgdh = top->rootp->verilator_top->csr_pgdh_diff;

    // 防止一个指令保持多个周期，这里需要判断等幂性，如果等幂直接退出
    if (last_op.wnum == trace_info.wnum && last_op.pc == trace_info.pc &&
        last_op.value == trace_info.value) {
        return 1;
    }

    // 保存最新的状态
    last_op.wnum = trace_info.wnum;
    last_op.pc = trace_info.pc;
    last_op.value = trace_info.value;

    // 如果修改 csr，那么 trace
    // 这里其实增加了一种情况，那就是原生的 difftest 中只记录了对 GPR 的修改信息
    // 事实上，完善的 difftest 应该记录对 CSR 的修改信息
    // 因此，当某条指令的 trace_info.we == 0 且 trace_info.is_csr_wr == 1 的时候，正好补充了这点
    if (trace_info.is_csr_wr && trace_info.we == 0) {
        gen_golden_trace_file1();
    } else if (trace_info.we != 0 && trace_info.wnum != 0) {
        // 这种情况意味着 trace_info.we != 0
        // 当 trace_info.we != 0 时，可能就是这个指令是受到 CSR
        // 寄存器影响的，比如读取的 CSR.TVAL，这个结果不应卡在 difftest
        // 过不去，因此这种情况应该将 trace_info.we 标记为 0 生成 trace
        // 好消息是，这个信息trace_info.we 已经在上面被赋值了
        read_ref();
        int good = trace_info.wnum == ref_struct.wnum &&
                   trace_info.pc == ref_struct.pc &&
                   trace_info.value == ref_struct.value;

        // 全部生成 difftest
        gen_golden_trace_file2();

        if (!good) {
            // 这里打印和 ref 对齐
            // 如果 cpu 的 we 是 1，但是 ref 为 0，直接返回，因为这个 difftest
            // 没有意义
            printf("-->CPU %d %08x %02x %08x\n", trace_info.we == 15,
                   trace_info.pc, trace_info.wnum, trace_info.value);
            printf("-->REF %d %08x %02x %08x\n", ref_struct.we, ref_struct.pc,
                   ref_struct.wnum, ref_struct.value);
        }
        if (ref_struct.we == 0) {
            return 1;
        }
        return good;
    } else {
        return 1;
    }

    return -1;
}

void run(int n) {
    while (n) {
        stepi();
        n--;
    }
}

void cpu_exec(uint64_t n) {
    while (n) {
        i++;
        // 停机信号
        uint32_t pc = top->rootp->verilator_top->debug_wb_pc;
        if (difftest() == 0) {
            printf("i:%d -->Error!\n", i);
            break;
        }
        uint32_t stop_pc = 0x1c000100;
        if (pc == stop_pc) {
            printf("\033[32mPassed all the tests!\033[0m\n");
            break;
        }

        stepi();
        n--;
    }
    top->final();
    tfp->close();
}

void init_system() {
    init_mem();
    load_inst();
    op_file();
}

int main(int argc, char* argv[]) {
    init_system();
    Verilated::traceEverOn(true);  //导出 FST 波形需要加此语句
    top->trace(tfp, 99);
    tfp->open("wave.vcd");
    reset(1);
    cpu_exec(-1);
    return 0;
}
