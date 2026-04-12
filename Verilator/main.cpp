#include <main.h>
#include <stdbool.h>
#include <stdint.h>
#include <cstdio>
#include <cstdlib>
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

diff ref_struct;
diff last_op;
bool trace_eof = false;
bool trace_eof_warned = false;

int i = 0;
diff mycpu_trace_info;
// 打开文件
FILE* fp;
const char* golden_trace_path = NULL;

static FILE* open_golden_trace() {
    const char* env_path = getenv("LA_GOLDEN_TRACE");
    if (env_path == NULL) {
        env_path = "";
    }
    const char* candidates[] = {
        env_path,
        "mycpu_env/gettrace/golden_trace.txt",
        "../mycpu_env/gettrace/golden_trace.txt",
        NULL
    };
    for (int i = 0; candidates[i] != NULL; i++) {
        if (candidates[i][0] == '\0') {
            continue;
        }
        FILE* f = fopen(candidates[i], "r");
        if (f != NULL) {
            golden_trace_path = candidates[i];
            return f;
        }
    }
    fprintf(stderr, "Failed to open golden_trace.txt. Tried:\n");
    for (int i = 0; candidates[i] != NULL; i++) {
        if (candidates[i][0] != '\0') {
            fprintf(stderr, "  %s\n", candidates[i]);
        }
    }
    return NULL;
}

void op_file() {
    fp = open_golden_trace();
    if (fp == NULL) {
        exit(1);
    }
    printf("Use golden trace: %s\n", golden_trace_path);
}
void step() {
    top->clk = 0;
    top->eval();
    tfp->dump(main_time);
    main_time++;

    top->clk = 1;
    top->eval();
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

// 打印行数
int j = 1;

int read_ref() {
    int rc = fscanf(fp, "%x%x%x%x", &ref_struct.we, &ref_struct.pc,
                    &ref_struct.wnum, &ref_struct.value);
    if (rc != 4) {
        trace_eof = true;
        if (!trace_eof_warned) {
            fprintf(stderr, "Warning: golden trace EOF reached: %s\n",
                    golden_trace_path == NULL ? "(unknown)" : golden_trace_path);
            trace_eof_warned = true;
        }
        return 0;
    }
    return 1;
}
void print_info() {
    printf("-->CPU %d %08x %02x %08x\n", mycpu_trace_info.we,
           mycpu_trace_info.pc, mycpu_trace_info.wnum, mycpu_trace_info.value);
    printf("-->REF %d %08x %02x %08x\n\n\n", ref_struct.we, ref_struct.pc,
           ref_struct.wnum, ref_struct.value);
}

int difftest() {
    mycpu_trace_info.we = top->rootp->verilator_top->debug_wb_rf_wen == 15;
    mycpu_trace_info.wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    mycpu_trace_info.pc = top->rootp->verilator_top->debug_wb_pc;
    mycpu_trace_info.value = top->rootp->verilator_top->debug_wb_rf_wdata;

    if (last_op.pc == mycpu_trace_info.pc) {
        return 1;
    }
    last_op.wnum = mycpu_trace_info.wnum;
    last_op.pc = mycpu_trace_info.pc;
    last_op.value = mycpu_trace_info.value;

    if (mycpu_trace_info.we == 0 || mycpu_trace_info.wnum == 0) {
        return 1;
    } else {
        if (trace_eof) {
            return 1;
        }
        if (!read_ref()) {
            return 1;
        }
        while (!trace_eof && ref_struct.we == 0) {
            if (!read_ref()) {
                return 1;
            }
        }
        if (trace_eof) {
            return 1;
        }
        if (mycpu_trace_info.pc != ref_struct.pc) {
            return 1;
        }
        print_info();
        int good = (ref_struct.we == mycpu_trace_info.we &&
                    ref_struct.wnum == mycpu_trace_info.wnum &&
                    ref_struct.pc == mycpu_trace_info.pc &&
                    ref_struct.value == mycpu_trace_info.value);

        if (!good) {
            print_info();
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
    printf("i: %d\n", i);
    if (fp != NULL) {
        fclose(fp);
        fp = NULL;
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
