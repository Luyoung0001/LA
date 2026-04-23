#ifndef PADDR_H
#define PADDR_H
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

#define RESET_VECTOR 0x1c000000u
#define PMEM_SIZE 0x100000000ULL

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
size_t get_loaded_img_size(void);
const char* get_loaded_img_path(void);

#ifdef __cplusplus
}
#endif

#endif
