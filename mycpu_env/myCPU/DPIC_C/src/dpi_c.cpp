#include <dpi_c.h>
#include <paddr.h>

extern "C" int data_ram_read(int addr) {
    // printf("data_addr:%08x\n",addr);
    return paddr_read(addr);
}
extern "C" int inst_ram_read(int addr) {
    // printf("inst_addr:%08x\n",addr);
    return paddr_read(addr);
}

extern "C" void data_ram_write(int addr, int wdata) {
    printf("data_write_addr:%08x--->wdata:%08x\n", addr, wdata);
    paddr_write(addr, wdata);
    // 写完验证一下
    uint32_t ans =  data_ram_read(addr);
    printf("data_wrote:%08x\n",ans);
}
