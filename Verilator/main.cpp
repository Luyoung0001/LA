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

// 这里会生成基于 OpenLA500 的 golden_trace.txt

typedef struct golden_trace {
    uint32_t we;
    uint32_t wnum;
    uint32_t pc;
    uint32_t value;
    uint32_t inst;
    // 每一项多了 CSR 的信息，由于一条指令可能修改多个 CSR，因此这里将记录多个
    // CSR
    uint32_t csr_crmd;
    uint32_t csr_prmd;
    uint32_t csr_ecfg;
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
golden_trace mycpu_trace_info;
// 打开文件
FILE* fp;

void op_file() {
    fp = fopen("/home/luyoung/LA/open_la500_golden_difftest.txt", "r");
}

void step() {
    top->clk = 0;
    top->eval();

    // if (i >= 800000)
        tfp->dump(main_time);  // 记录波形数据
    main_time++;               // 时间递增

    top->clk = 1;
    top->eval();

    // if (i >= 800000)
        tfp->dump(main_time);
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

typedef struct diff {
    uint32_t we;
    uint32_t pc;
    uint32_t wnum;
    uint32_t value;

} diff;

// 读取 ref
diff ref_struct;

void read_ref() {
    fscanf(fp,
           "%d %02X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X "
           "%08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X %08X "
           "%08X %08X %08X %08X %08X\n",
           &trace_info.we, &trace_info.wnum, &trace_info.pc, &trace_info.value,
           &trace_info.inst, &trace_info.csr_crmd, &trace_info.csr_prmd,
           &trace_info.csr_ecfg, &trace_info.csr_estat, &trace_info.csr_era,
           &trace_info.csr_badv, &trace_info.csr_eentry, &trace_info.csr_tlbidx,
           &trace_info.csr_tlbehi, &trace_info.csr_tlbelo0,
           &trace_info.csr_tlbelo1, &trace_info.csr_asid, &trace_info.csr_save0,
           &trace_info.csr_save1, &trace_info.csr_save2, &trace_info.csr_save3,
           &trace_info.csr_tid, &trace_info.csr_tcfg, &trace_info.csr_tval,
           &trace_info.csr_ticlr, &trace_info.csr_llbctl,
           &trace_info.csr_tlbrentry, &trace_info.csr_dmw0,
           &trace_info.csr_dmw1, &trace_info.csr_pgdl, &trace_info.csr_pgdh);
}

// 读取 trace，与拉到的信号进行比对
// 上次的状态
diff last_op;

int difftest() {
    mycpu_trace_info.we = top->rootp->verilator_top->debug_wb_rf_we;
    mycpu_trace_info.wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    mycpu_trace_info.pc = top->rootp->verilator_top->debug_wb_pc;
    mycpu_trace_info.value = top->rootp->verilator_top->debug_wb_rf_wdata;
    mycpu_trace_info.inst = top->rootp->verilator_top->debug_wb_inst;
    mycpu_trace_info.csr_crmd = top->rootp->verilator_top->csr_crmd_diff;
    mycpu_trace_info.csr_prmd = top->rootp->verilator_top->csr_prmd_diff;
    mycpu_trace_info.csr_ecfg = top->rootp->verilator_top->csr_ecfg_diff;
    mycpu_trace_info.csr_estat = top->rootp->verilator_top->csr_estat_diff;
    mycpu_trace_info.csr_era = top->rootp->verilator_top->csr_era_diff;
    mycpu_trace_info.csr_badv = top->rootp->verilator_top->csr_badv_diff;
    mycpu_trace_info.csr_eentry = top->rootp->verilator_top->csr_eentry_diff;
    mycpu_trace_info.csr_tlbidx = top->rootp->verilator_top->csr_tlbidx_diff;
    mycpu_trace_info.csr_tlbehi = top->rootp->verilator_top->csr_tlbehi_diff;
    mycpu_trace_info.csr_tlbelo0 = top->rootp->verilator_top->csr_tlbelo0_diff;
    mycpu_trace_info.csr_tlbelo1 = top->rootp->verilator_top->csr_tlbelo1_diff;
    mycpu_trace_info.csr_asid = top->rootp->verilator_top->csr_asid_diff;
    mycpu_trace_info.csr_save0 = top->rootp->verilator_top->csr_save0_diff;
    mycpu_trace_info.csr_save1 = top->rootp->verilator_top->csr_save1_diff;
    mycpu_trace_info.csr_save2 = top->rootp->verilator_top->csr_save2_diff;
    mycpu_trace_info.csr_save3 = top->rootp->verilator_top->csr_save3_diff;
    mycpu_trace_info.csr_tid = top->rootp->verilator_top->csr_tid_diff;
    mycpu_trace_info.csr_tcfg = top->rootp->verilator_top->csr_tcfg_diff;
    mycpu_trace_info.csr_tval = top->rootp->verilator_top->csr_tval_diff;
    mycpu_trace_info.csr_ticlr = top->rootp->verilator_top->csr_ticlr_diff;
    mycpu_trace_info.csr_llbctl = top->rootp->verilator_top->csr_llbctl_diff;
    mycpu_trace_info.csr_tlbrentry =
        top->rootp->verilator_top->csr_tlbrentry_diff;
    mycpu_trace_info.csr_dmw0 = top->rootp->verilator_top->csr_dmw0_diff;
    mycpu_trace_info.csr_dmw1 = top->rootp->verilator_top->csr_dmw1_diff;
    mycpu_trace_info.csr_pgdl = top->rootp->verilator_top->csr_pgdl_diff;
    mycpu_trace_info.csr_pgdh = top->rootp->verilator_top->csr_pgdh_diff;

    // 防止一个指令保持多个周期，这里需要判断等幂性，如果等幂直接退出
    // 如果当前指令写的寄存器是 0 号，直接退出
    if (mycpu_trace_info.we == 15 && last_op.we == mycpu_trace_info.we &&
            last_op.wnum == mycpu_trace_info.wnum &&
            last_op.pc == mycpu_trace_info.pc &&
            last_op.value == mycpu_trace_info.value ||
        mycpu_trace_info.wnum == 0) {
        return 1;
    }

    if (mycpu_trace_info.we) {
        // 保存最新的状态
        last_op.we = mycpu_trace_info.we;
        last_op.wnum = mycpu_trace_info.wnum;
        last_op.pc = mycpu_trace_info.pc;
        last_op.value = mycpu_trace_info.value;

        read_ref();
        // 这里打印和 ref 对齐
        // 如果 cpu 的 we 是 1，但是 ref 为 0，直接返回，因为这个 difftest
        // 没有意义

        int good = trace_info.wnum == mycpu_trace_info.wnum &&
                   trace_info.pc == mycpu_trace_info.pc &&
                   trace_info.value == mycpu_trace_info.value;
        if (!good) {
            printf("-->CPU %d %08x %02x %08x\n", mycpu_trace_info.we == 15,
                   mycpu_trace_info.pc, mycpu_trace_info.wnum,
                   mycpu_trace_info.value);
            printf("-->REF %d %08x %02x %08x\n", trace_info.we, trace_info.pc,
                   trace_info.wnum, trace_info.value);
        }
        
        if (trace_info.we == 0) {
            return 1;
        }

        return good;
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
