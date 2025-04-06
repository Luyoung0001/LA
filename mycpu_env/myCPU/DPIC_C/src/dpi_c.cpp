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
    if (addr == SW_INTER_ADDR) {
        return 0x0000aaaa;
    }
    return paddr_read(addr);
}
extern "C" int inst_ram_read(int addr) {
    return paddr_read(addr);
}

extern "C" void data_ram_write(int addr, int wdata) {
    printf("data_write_addr:%08x--->wdata:%08x\n", addr, wdata);
    paddr_write(addr, wdata);
    // 写完验证一下
    uint32_t ans = data_ram_read(addr);
    printf("data_wrote:%08x\n", ans);
}
