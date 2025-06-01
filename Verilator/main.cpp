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

void step() {
    top->clk = 0;
    top->eval();

    if(i > 800000) tfp->dump(main_time);  // 记录波形数据
    main_time++;           // 时间递增

    top->clk = 1;
    top->eval();

    if(i > 800000) tfp->dump(main_time);
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
    uint32_t wnum;
    uint32_t pc;
    uint32_t value;

} diff;
// 打开文件



FILE* fp;
void op_file() {
    fp = fopen("/home/luyoung/LA/mycpu_env/gettrace/golden_trace.txt", "r");
}
// 读取 ref

diff ref_struct;

void read_ref() {
    fscanf(fp, "%x%x%x%x", &ref_struct.we, &ref_struct.pc, &ref_struct.wnum,
           &ref_struct.value);

    printf("-->REF %d %08x %02x %08x\n", ref_struct.we, ref_struct.pc,
           ref_struct.wnum, ref_struct.value);
}

// 读取 trace，与拉到的信号进行比对
// 上次的状态
diff last_op;

int difftest() {
    uint32_t we = top->rootp->verilator_top->debug_wb_rf_we;
    uint32_t wnum = top->rootp->verilator_top->debug_wb_rf_wnum;
    uint32_t pc = top->rootp->verilator_top->debug_wb_pc;
    uint32_t value = top->rootp->verilator_top->debug_wb_rf_wdata;

    if (we == 15 && last_op.we == we && last_op.wnum == wnum &&
        last_op.pc == pc && last_op.value == value) {
        return 1;
    }
    if(wnum == 0){
        return 1;

    }
    if (we && wnum !=0) {
        last_op.we = we;
        last_op.wnum = wnum;
        last_op.pc = pc;
        last_op.value = value;
    }
    if (we)
        printf("-->CPU %d %08x %02x %08x\n", we == 15, pc, wnum, value);

    int temp_we = (we == 15 ? 1 : 0);
    if (temp_we == 1 && wnum != 0) {
        read_ref();
        // 如果执行读取内核时钟指令，ref 的 difftest we 信号为 0，此时不应该进行
        // difftest 直接返回 1 即可
        if (ref_struct.we == 0) {
            return 1;
        }
        return wnum == ref_struct.wnum && pc == ref_struct.pc &&
               value == ref_struct.value;
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
        printf("i:%d\n", i);

        // 停机信号
        uint32_t pc = top->rootp->verilator_top->debug_wb_pc;
        if (difftest() == 0) {
            printf("Error!\n");
            // break;
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
    cpu_exec(832690+10);
    return 0;
}
