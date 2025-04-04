#ifndef DPIC_H
#define DPIC_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int data_ram_read(int addr);
void inst_ram_read(int addr);

void data_ram_write(int addr, int wdata);

#ifdef __cplusplus
}
#endif

#endif
