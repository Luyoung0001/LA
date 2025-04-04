#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__
#include <stdio.h>

// 声明全局变量
extern uint8_t* pmem;

#ifdef __cplusplus
extern "C" {
#endif

uint32_t paddr_read(uint32_t addr);
void paddr_write(uint32_t addr, uint32_t data);

// 地址转换
uint32_t padd2host(uint32_t paddr) {
    return paddr + pmem;
}

uint32_t pmem_read(uint32_t paddr);
void pmem_write(uint32_t paddr, uint32_t data);

#ifdef __cplusplus
}
#endif

#endif
