#include <stdbool.h>
#include <stdint.h>
#include <main.h>
#include "Vsoc_mini_top.h"
#include "Vsoc_mini_top___024root.h"

#include "verilated_fst_c.h"
VerilatedFstC* tfp = new VerilatedFstC;

vluint64_t main_time = 0;  // initial 仿真时间

Vsoc_mini_top* top = new Vsoc_mini_top;

void step() {
    top->clk = 0;
    top->eval();

    tfp->dump(main_time);  // 记录波形数据
    main_time++;           // 时间递增

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

// 执行 CPU
int cpu_exec(uint64_t n) {
    int ret = 0;
    while (n) {
        stepi();
        n--;
    }
    top->final();
    tfp->close();
    return ret;
}

int init_system(){
    // 分配内存
    init_mem();
    // 加载镜像
    load_inst();
}

int main(int argc, char* argv[]) {
    init_system();
    Verilated::traceEverOn(true);  //导出 FST 波形需要加此语句
    top->trace(tfp, 99);
    tfp->open("wave.vcd");
    reset(1);
    int ret = cpu_exec(500);
    return ret;
}
