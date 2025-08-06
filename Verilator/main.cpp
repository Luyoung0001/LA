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

typedef struct diff {
    uint32_t we;
    uint32_t pc;
    uint32_t wnum;
    uint32_t value;
} diff;

// 读取 ref
diff ref_struct;
diff last_op;

#define EASY_MODE 1

int i = 0;
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

#ifdef EASY_MODE
diff mycpu_trace_info;
#else
golden_trace mycpu_trace_info;
#endif
// 打开文件
FILE* fp;
void op_file() {
#ifdef EASY_MODE
    fp = fopen("/home/luyoung/LA/mycpu_env/gettrace/golden_trace.txt", "r");
#else
    fp = fopen("/home/luyoung/LA/open_la500_golden_difftest.txt", "r");
#endif
}
void step() {
    top->clk = 0;
    top->eval();

    // 读取临时文件 temp_i.txt: int temp_i
    int temp_i;
    FILE* temp_fp = fopen("temp_i.txt", "r");
    if (temp_fp == NULL) {
        printf("Error opening temp_i.txt\n");
        return;
    }
    fscanf(temp_fp, "%d", &temp_i);
    fclose(temp_fp);

    // 记录最新的 1000 个周期
    int start_time = 0;
    if (temp_i <= 5000) {
        start_time = 0;
    } else {
        start_time = temp_i - 5000;
    }

    if (i >= start_time) {
        tfp->dump(main_time);
        main_time++;
    }
    top->clk = 1;
    top->eval();

    if (i >= start_time) {
        tfp->dump(main_time);
        main_time++;
    }
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

// 打印行数
int j = 1;

void read_ref() {
#ifdef EASY_MODE
    fscanf(fp, "%x%x%x%x", &ref_struct.we, &ref_struct.pc, &ref_struct.wnum,
           &ref_struct.value);
#else
    fscanf(fp,
           "%d %02x %08x %08x %08x %d %08x %08x %08x %08x %08x %08x %08x %08x "
           "%08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x %08x "
           "%08x %08x %08x %08x %08x\n",
           &trace_info.we, &trace_info.wnum, &trace_info.pc, &trace_info.value,
           &trace_info.inst, &trace_info.is_csr_wr, &trace_info.csr_crmd,
           &trace_info.csr_prmd, &trace_info.csr_ecfg, &trace_info.csr_estat,
           &trace_info.csr_era, &trace_info.csr_badv, &trace_info.csr_eentry,
           &trace_info.csr_tlbidx, &trace_info.csr_tlbehi,
           &trace_info.csr_tlbelo0, &trace_info.csr_tlbelo1,
           &trace_info.csr_asid, &trace_info.csr_save0, &trace_info.csr_save1,
           &trace_info.csr_save2, &trace_info.csr_save3, &trace_info.csr_tid,
           &trace_info.csr_tcfg, &trace_info.csr_tval, &trace_info.csr_ticlr,
           &trace_info.csr_llbctl, &trace_info.csr_tlbrentry,
           &trace_info.csr_dmw0, &trace_info.csr_dmw1, &trace_info.csr_pgdl,
           &trace_info.csr_pgdh);
    printf("Read %dth: line\n", j);
    j++;
#endif
}

#ifdef EASY_MODE

#else
// how good it is?
uint32_t good_level = 0;
// 对比
void get_good_level() {
    good_level = trace_info.we == mycpu_trace_info.we;
    good_level = (trace_info.wnum == mycpu_trace_info.wnum) << 1 | good_level;
    good_level = (trace_info.pc == mycpu_trace_info.pc) << 2 | good_level;
    good_level = (trace_info.value == mycpu_trace_info.value) << 3 | good_level;
    good_level = (trace_info.inst == mycpu_trace_info.inst) << 4 | good_level;
    good_level =
        (trace_info.is_csr_wr == mycpu_trace_info.is_csr_wr) << 5 | good_level;
    good_level =
        (trace_info.csr_crmd == mycpu_trace_info.csr_crmd) << 6 | good_level;
    good_level =
        (trace_info.csr_prmd == mycpu_trace_info.csr_prmd) << 7 | good_level;
    good_level =
        (trace_info.csr_ecfg == mycpu_trace_info.csr_ecfg) << 8 | good_level;
    good_level =
        (trace_info.csr_estat == mycpu_trace_info.csr_estat) << 9 | good_level;
    good_level =
        (trace_info.csr_era == mycpu_trace_info.csr_era) << 10 | good_level;
    good_level =
        (trace_info.csr_badv == mycpu_trace_info.csr_badv) << 11 | good_level;
    good_level = (trace_info.csr_eentry == mycpu_trace_info.csr_eentry) << 12 |
                 good_level;
    good_level = (trace_info.csr_tlbidx == mycpu_trace_info.csr_tlbidx) << 13 |
                 good_level;
    good_level = (trace_info.csr_tlbehi == mycpu_trace_info.csr_tlbehi) << 14 |
                 good_level;
    good_level = (trace_info.csr_tlbelo0 == mycpu_trace_info.csr_tlbelo0)
                     << 15 |
                 good_level;
    good_level = (trace_info.csr_tlbelo1 == mycpu_trace_info.csr_tlbelo1)
                     << 16 |
                 good_level;
    good_level =
        (trace_info.csr_asid == mycpu_trace_info.csr_asid) << 17 | good_level;
    good_level =
        (trace_info.csr_save0 == mycpu_trace_info.csr_save0) << 18 | good_level;
    good_level =
        (trace_info.csr_save1 == mycpu_trace_info.csr_save1) << 19 | good_level;
    good_level =
        (trace_info.csr_save2 == mycpu_trace_info.csr_save2) << 20 | good_level;
    good_level =
        (trace_info.csr_save3 == mycpu_trace_info.csr_save3) << 21 | good_level;
    good_level =
        (trace_info.csr_tid == mycpu_trace_info.csr_tid) << 22 | good_level;
    good_level =
        (trace_info.csr_tcfg == mycpu_trace_info.csr_tcfg) << 23 | good_level;
    good_level =
        (trace_info.csr_tval == mycpu_trace_info.csr_tval) << 24 | good_level;
    good_level =
        (trace_info.csr_ticlr == mycpu_trace_info.csr_ticlr) << 25 | good_level;
    good_level = (trace_info.csr_llbctl == mycpu_trace_info.csr_llbctl) << 26 |
                 good_level;
    good_level = (trace_info.csr_tlbrentry == mycpu_trace_info.csr_tlbrentry)
                     << 27 |
                 good_level;
    good_level =
        (trace_info.csr_dmw0 == mycpu_trace_info.csr_dmw0) << 28 | good_level;
    good_level =
        (trace_info.csr_dmw1 == mycpu_trace_info.csr_dmw1) << 29 | good_level;
    good_level =
        (trace_info.csr_pgdl == mycpu_trace_info.csr_pgdl) << 30 | good_level;
    good_level =
        (trace_info.csr_pgdh == mycpu_trace_info.csr_pgdh) << 31 | good_level;
}

#endif
void print_info() {
#ifdef EASY_MODE
    // uint32_t inst = top->rootp->verilator_top->debug_wb_inst;
    printf("-->CPU %d %08x %02x %08x\n", mycpu_trace_info.we,
           mycpu_trace_info.pc, mycpu_trace_info.wnum, mycpu_trace_info.value);
    printf("-->REF %d %08x %02x %08x\n\n\n", ref_struct.we, ref_struct.pc,
           ref_struct.wnum, ref_struct.value);
#else
    printf(
        "\033[32mCPU\033[0m:  we: %d, wnum: %d, \033[32mpc: %08x\033[0m, "
        "value: %08x, inst: %08x, csr_wr: %d\n",
        mycpu_trace_info.we, mycpu_trace_info.wnum, mycpu_trace_info.pc,
        mycpu_trace_info.value, mycpu_trace_info.inst,
        mycpu_trace_info.is_csr_wr);
    printf(
        "REF:  we: %d, wnum: %d, pc: %08x, value: %08x, inst: %08x, csr_wr: "
        "%d\n\n",
        trace_info.we, trace_info.wnum, trace_info.pc, trace_info.value,
        trace_info.inst, trace_info.is_csr_wr);

    printf(
        "\033[32mCPU\033[0m:  csr_crmd: %08x, csr_prmd: %08x, csr_ecfg: %08x, "
        "csr_estat: %08x\n",
        mycpu_trace_info.csr_crmd, mycpu_trace_info.csr_prmd,
        mycpu_trace_info.csr_ecfg, mycpu_trace_info.csr_estat);
    printf(
        "REF:  csr_crmd: %08x, csr_prmd: %08x, csr_ecfg: %08x, csr_estat: "
        "%08x\n\n",
        trace_info.csr_crmd, trace_info.csr_prmd, trace_info.csr_ecfg,
        trace_info.csr_estat);

    printf(
        "\033[32mCPU\033[0m:  csr_era: %08x, csr_badv: %08x, csr_eentry: "
        "%08x\n",
        mycpu_trace_info.csr_era, mycpu_trace_info.csr_badv,
        mycpu_trace_info.csr_eentry);
    printf("REF:  csr_era: %08x, csr_badv: %08x, csr_eentry: %08x\n\n",
           trace_info.csr_era, trace_info.csr_badv, trace_info.csr_eentry);

    printf("\033[32mCPU\033[0m:  csr_tlbidx: %08x, csr_tlbehi: %08x\n",
           mycpu_trace_info.csr_tlbidx, mycpu_trace_info.csr_tlbehi);
    printf("REF:  csr_tlbidx: %08x, csr_tlbehi: %08x\n\n",
           trace_info.csr_tlbidx, trace_info.csr_tlbehi);

    printf("\033[32mCPU\033[0m:  csr_tlbelo0: %08x, csr_tlbelo1: %08x\n",
           mycpu_trace_info.csr_tlbelo0, mycpu_trace_info.csr_tlbelo1);
    printf("REF:  csr_tlbelo0: %08x, csr_tlbelo1: %08x\n\n",
           trace_info.csr_tlbelo0, trace_info.csr_tlbelo1);

    printf("\033[32mCPU\033[0m:  csr_asid: %08x\n", mycpu_trace_info.csr_asid);
    printf("REF:  csr_asid: %08x\n\n", trace_info.csr_asid);

    printf("\033[32mCPU\033[0m:  csr_save0: %08x, csr_save1: %08x\n",
           mycpu_trace_info.csr_save0, mycpu_trace_info.csr_save1);
    printf("REF:  csr_save0: %08x, csr_save1: %08x\n\n", trace_info.csr_save0,
           trace_info.csr_save1);

    printf("\033[32mCPU\033[0m:  csr_save2: %08x, csr_save3: %08x\n",
           mycpu_trace_info.csr_save2, mycpu_trace_info.csr_save3);
    printf("REF:  csr_save2: %08x, csr_save3: %08x\n\n", trace_info.csr_save2,
           trace_info.csr_save3);

    printf("\033[32mCPU\033[0m:  csr_tid: %08x\n", mycpu_trace_info.csr_tid);
    printf("REF:  csr_tid: %08x\n\n", trace_info.csr_tid);

    printf("\033[32mCPU\033[0m:  csr_tcfg: %08x, csr_tval: %08x\n",
           mycpu_trace_info.csr_tcfg, mycpu_trace_info.csr_tval);
    printf("REF:  csr_tcfg: %08x, csr_tval: %08x\n\n", trace_info.csr_tcfg,
           trace_info.csr_tval);

    printf("\033[32mCPU\033[0m:  csr_ticlr: %08x, csr_llbctl: %08x\n",
           mycpu_trace_info.csr_ticlr, mycpu_trace_info.csr_llbctl);
    printf("REF:  csr_ticlr: %08x, csr_llbctl: %08x\n\n", trace_info.csr_ticlr,
           trace_info.csr_llbctl);

    printf(
        "\033[32mCPU\033[0m:  csr_tlbrentry: %08x, csr_dmw0: %08x, csr_dmw1: "
        "%08x\n",
        mycpu_trace_info.csr_tlbrentry, mycpu_trace_info.csr_dmw0,
        mycpu_trace_info.csr_dmw1);
    printf("REF:  csr_tlbrentry: %08x, csr_dmw0: %08x, csr_dmw1: %08x\n\n",
           trace_info.csr_tlbrentry, trace_info.csr_dmw0, trace_info.csr_dmw1);

    printf("\033[32mCPU\033[0m:  csr_pgdl: %08x, csr_pgdh: %08x\n",
           mycpu_trace_info.csr_pgdl, mycpu_trace_info.csr_pgdh);
    printf("REF:  csr_pgdl: %08x, csr_pgdh: %08x\n\n", trace_info.csr_pgdl,
           trace_info.csr_pgdh);
#endif
}

// 读取 trace，与拉到的信号进行比对
// 上次的状态

#define WE_DIFF 0xfffffffe
#define WNUM_DIFF 0xfffffffd
#define PC_DIFF 0xfffffffb
#define VALUE_DIFF 0xfffffff7
#define INST_DIFF 0xffffffef
#define CSR_WR_DIFF 0xffffffdf
#define CSR_CRMD_DIFF 0xffffffbf
#define CSR_PRMD_DIFF 0xffffff7f
#define CSR_ECFG_DIFF 0xfffffeff
#define CSR_ESTAT_DIFF 0xfffffdff
#define CSR_ERA_DIFF 0xfffffbff
#define CSR_BADV_DIFF 0xfffff7ff
#define CSR_EENTRY_DIFF 0xffffefff
#define CSR_TLBIDX_DIFF 0xffffdfff
#define CSR_TLBEHI_DIFF 0xffffbfff
#define CSR_TLBLO0_DIFF 0xffff7fff
#define CSR_TLBLO1_DIFF 0xfffeffff
#define CSR_ASID_DIFF 0xfffdffff
#define CSR_SAVE0_DIFF 0xfffbffff
#define CSR_SAVE1_DIFF 0xfff7ffff
#define CSR_SAVE2_DIFF 0xffefffff
#define CSR_SAVE3_DIFF 0xffdfffff
#define CSR_TID_DIFF 0xffbfffff
#define CSR_TCFG_DIFF 0xff7fffff
#define CSR_TVAL_DIFF 0xfeffffff
#define CSR_TICLR_DIFF 0xfdffffff
#define CSR_LLBCTL_DIFF 0xfbffffff
#define CSR_TLBRENTRY_DIFF 0xf7ffffff
#define CSR_DMW0_DIFF 0xefffffff
#define CSR_DMW1_DIFF 0xdfffffff
#define CSR_PGDL_DIFF 0xbfffffff
#define CSR_PGDH_DIFF 0x7fffffff

int difftest() {
#ifdef EASY_MODE
    mycpu_trace_info.we = top->rootp->verilator_top->debug_wb_rf_wen == 15;
    mycpu_trace_info.wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    mycpu_trace_info.pc = top->rootp->verilator_top->debug_wb_pc;
    mycpu_trace_info.value = top->rootp->verilator_top->debug_wb_rf_wdata;
    // 防止一个指令保持多个周期，这里需要判断等幂性，如果等幂直接退出

    if (last_op.pc == mycpu_trace_info.pc) {
        return 1;
    }
    // 保存最新的状态
    last_op.wnum = mycpu_trace_info.wnum;
    last_op.pc = mycpu_trace_info.pc;
    last_op.value = mycpu_trace_info.value;

    if (mycpu_trace_info.we == 0 || mycpu_trace_info.wnum == 0) {
        // 如果 mycpu_trace_info 的 we 是 0或者 wnum 是 0
        // 直接跳过
        return 1;
    } else {
        // 读取 ref
        // 一直读到 ref 的 we 为 1
        read_ref();
        while (ref_struct.we == 0) {
            read_ref();
        }
        // 如果 PC 不一样，说明 mycpu 此时的指令没有比较的意义
        if (mycpu_trace_info.pc != ref_struct.pc) {
            return 1;
        }
        // pc 应该每次都进行打印
        print_info();
        // 比较
        int good = (ref_struct.we == mycpu_trace_info.we &&
                    ref_struct.wnum == mycpu_trace_info.wnum &&
                    ref_struct.pc == mycpu_trace_info.pc &&
                    ref_struct.value == mycpu_trace_info.value);

        if (!good) {
            // 如果不相等，打印信息
            print_info();
        }
        return good;
    }
    return -1;

#else
    mycpu_trace_info.we = top->rootp->verilator_top->debug_wb_rf_we == 15;
    mycpu_trace_info.wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    mycpu_trace_info.pc = top->rootp->verilator_top->debug_wb_pc;
    mycpu_trace_info.value = top->rootp->verilator_top->debug_wb_rf_wdata;
    mycpu_trace_info.inst = top->rootp->verilator_top->debug_wb_inst;
    mycpu_trace_info.is_csr_wr =
        top->rootp->verilator_top->debug_wb_is_csr_wr_o;
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
    if (last_op.pc == mycpu_trace_info.pc) {
        return 1;
    }
    // 保存最新的状态
    last_op.wnum = mycpu_trace_info.wnum;
    last_op.pc = mycpu_trace_info.pc;
    last_op.value = mycpu_trace_info.value;

    if (top->rootp->verilator_top->debug_has_refetch_excp_o) {
        // 如果有 refetch，不用比较
        print_info();
        return 1;

    } else if (mycpu_trace_info.we && mycpu_trace_info.wnum != 0 ||
               mycpu_trace_info.is_csr_wr) {
        // 读取 ref
        read_ref();

        get_good_level();

        // pc 应该每次都进行打印
        printf("CPU: \033[32mpc: %08x\033[0m\n", mycpu_trace_info.pc);
        printf("REF: \033[32mpc: %08x\033[0m\n\n", trace_info.pc);

        if (~good_level & ~PC_DIFF) {
            // 如果 PC 不一样，直接退出
            printf("good_level: 0x%08x\n", good_level);
            print_info();
        } else if (mycpu_trace_info.we == 1 && trace_info.we == 0) {
            // 这里的情况是 CPU 的 we 是 1，但是 ref 的 we 是 0
            // 这种情况直接跳过，因为这个指令没有意义
            print_info();
            return 1;
        } else if (good_level == WE_DIFF || good_level == CSR_TVAL_DIFF ||
                   good_level == VALUE_DIFF) {
            // 仅仅由于 we 的不同的时候，直接跳过
            print_info();
            return 1;
        } else if (good_level == (CSR_TVAL_DIFF & WE_DIFF)) {
            // 由于 CSR.TVAL 和 we 的不同的时候，直接跳过
            print_info();
            return 1;
        } else if (good_level != 0xffffffff) {
            printf("good_level: 0x%08x\n", good_level);
            print_info();
        }
        return good_level == 0xffffffff;
    }
    return -1;
#endif
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
        // printf("i: %d\n", i);
        stepi();
        n--;
    }
    // 将 i 的值写到一个临时文件中 temp_i.txt
    FILE* temp_fp = fopen("temp_i.txt", "w");
    if (temp_fp == NULL) {
        printf("Error opening temp_i.txt\n");
        return;
    }
    fprintf(temp_fp, "%d", i);
    fclose(temp_fp);
    printf("i: %d\n", i);
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