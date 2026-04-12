#ifndef PADDR_H
#define PADDR_H
#include <stdio.h>
#include <stdint.h>

// 声明全局变量
extern uint8_t* pmem;

#ifdef __cplusplus
extern "C" {
#endif

uint32_t paddr_read(uint32_t addr);
void paddr_write(uint32_t addr, uint32_t data);

// 地址转换
uint8_t* padd2host(uint32_t paddr);
uint32_t pmem_read(uint8_t* paddr);
void pmem_write(uint8_t* paddr, uint32_t data);

#ifdef __cplusplus
}
#endif

#endif
