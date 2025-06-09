#include <dpi_c.h>
#include <paddr.h>

#define CR0_ADDR 0xbfaf8000  // 32'hbfaf_8000
#define CR1_ADDR 0xbfaf8010  // 32'hbfaf_8010
#define CR2_ADDR 0xbfaf8020  // 32'hbfaf_8020
#define CR3_ADDR 0xbfaf8030  // 32'hbfaf_8030
#define CR4_ADDR 0xbfaf8040  // 32'hbfaf_8040
#define CR5_ADDR 0xbfaf8050  // 32'hbfaf_8050
#define CR6_ADDR 0xbfaf8060  // 32'hbfaf_8060
#define CR7_ADDR 0xbfaf8070  // 32'hbfaf_8070

#define LED_ADDR 0xbfaff020       // 32'hbfaf_f020
#define LED_RG0_ADDR 0xbfaff030   // 32'hbfaf_f030
#define LED_RG1_ADDR 0xbfaff040   // 32'hbfaf_f040
#define NUM_ADDR 0xbfaff050       // 32'hbfaf_f050
#define SWITCH_ADDR 0xbfaff060    // 32'hbfaf_f060
#define BTN_KEY_ADDR 0xbfaff070   // 32'hbfaf_f070
#define BTN_STEP_ADDR 0xbfaff080  // 32'hbfaf_f080
#define SW_INTER_ADDR 0xbfaff090  // 32'hbfaf_f090
#define TIMER_ADDR 0xbfafe000     // 32'hbfaf_e000

#define IO_SIMU_ADDR 0xbfafff00       // 32'hbfaf_ff00
#define VIRTUAL_UART_ADDR 0xbfafff10  // 32'hbfaf_ff10
#define SIMU_FLAG_ADDR 0xbfafff20     // 32'hbfaf_ff20
#define OPEN_TRACE_ADDR 0xbfafff30    // 32'hbfaf_ff30
#define NUM_MONITOR_ADDR 0xbfafff40   // 32'hbfaf_ff40

extern "C" int data_ram_read(int addr) {
    // gpio
    // printf("data_read_addr:%08x\n", addr);
    if (addr == SW_INTER_ADDR) {
        return 0x0000aaaa;
    } else if (addr == OPEN_TRACE_ADDR) {
        return 0x0000001;
    }
    return paddr_read(addr);
}
extern "C" int inst_ram_read(int addr) {
    return paddr_read(addr);
}

extern "C" void data_ram_write(int addr, int wdata, unsigned char wmask) {
    // 底层写的实现原理为：
    // 所有的写写地址都对齐到 4 字节
    // 写之前，先读出，之后根据 wmask 修改这个数据
    // 修改好后，将其再写入
    // 此逻辑对 MEM 模块透明，它只管发射自然对齐的地址（ld\st
    // 地址如果不自然对齐，会发生例外）、 写的数据、we。至于怎么实现，对 MEM
    // 完全透明。

    uint32_t pre_target = data_ram_read(addr);
    printf("raw_wdata:%08x\n", wdata);

    printf("data_write_addr:%08x--->pre_wdata:%08x\n", addr, pre_target);

    // 一字节自然对其
    // 如果 wmask 为 b0001，只需要将 wdata 的最低字节写入

    uint32_t pre_data;
    uint32_t target;
    if (wmask == 0b00000001) {
        pre_data = wdata & 0x000000ff;  // 保留最后一个字
        target = (pre_target & 0xffffff00) | pre_data;
    } else if (wmask == 0b00000010) {
        pre_data = wdata & 0x0000ff00;
        target = (pre_target & 0xffff00ff) | pre_data;
    } else if (wmask == 0b00000100) {
        pre_data = wdata & 0x00ff0000;
        target = (pre_target & 0xff00ffff) | pre_data;
    } else if (wmask == 0b00001000) {
        pre_data = wdata & 0xff000000;
        target = (pre_target & 0x00ffffff) | pre_data;
    }
    // 二字节自然对其
    // 如果 wmask 为 b0011
    // 如果 wmask 为 b1100
    else if (wmask == 0b00000011) {
        pre_data = wdata & 0x0000ffff;
        target = (pre_target & 0xffff0000) | pre_data;
    } else if (wmask == 0b00000110) {  // 非自然对齐，这种情况不会送到这里，会在
                                       // MEM 中发生例外
        pre_data = wdata & 0x00ffff00;
        target = (pre_target & 0xff0000ff) | pre_data;
    } else if (wmask == 0b00001100) {
        pre_data = wdata & 0xffff0000;
        target = (pre_target & 0x0000ffff) | pre_data;
    }
    // 四字节自然对其
    // 如果 wmask 为 b1111
    else if (wmask == 0b00001111) {
        pre_data = wdata & 0xffffffff;
        target = (pre_target & 0x00000000) | pre_data;
    }

    // printf("data_write_addr:%08x--->final_wdata:%08x\n", addr, target);
    paddr_write(addr, target);
    // 写完验证一下
    // uint32_t ans = data_ram_read(addr);
    // printf("after write and check: data_wrote:%08x\n", ans);
}
