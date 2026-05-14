#ifndef TB_BASE_H
#define TB_BASE_H

#include <verilated.h>
#include <memory>
#include <cstdint>

// 基础 Testbench 类 - 提供时钟、复位、通用功能
class TbBase {
protected:
    uint64_t sim_time;
    uint64_t cycle_count;

public:
    TbBase() : sim_time(0), cycle_count(0) {}
    virtual ~TbBase() {}

    // 时钟周期推进
    void tick() {
        sim_time++;
        cycle_count++;
    }

    // 获取当前时间
    uint64_t get_time() const { return sim_time; }
    uint64_t get_cycles() const { return cycle_count; }

    // 复位序列
    template<typename T>
    void reset(T* dut, int cycles = 3) {
        dut->rst_n = 0;
        for (int i = 0; i < cycles; i++) {
            dut->clk = 0;
            dut->eval();
            tick();
            dut->clk = 1;
            dut->eval();
            tick();
        }
        dut->rst_n = 1;
    }

    // 时钟边沿
    template<typename T>
    void clock_edge(T* dut) {
        dut->clk = 0;
        dut->eval();
        tick();
        dut->clk = 1;
        dut->eval();
        tick();
    }
};

#endif // TB_BASE_H
