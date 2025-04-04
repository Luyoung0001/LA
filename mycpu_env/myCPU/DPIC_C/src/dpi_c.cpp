#include <dpic.h>
#include <paddr.h>

extern "C" int data_ram_read(int addr){
    return paddr_read(addr);
}
extern "C" void inst_ram_read(int addr){
    return paddr_read(addr);
}

extern "C" void data_ram_write(int addr, int wdata){
    paddr_write(addr, wdata);
}





