#include <main.h>
#include <paddr.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t* pmem = NULL;

// 加载指令
#define img_file "/home/luyoung/LA/mycpu_env/func/obj/main.bin"
#define RESET_VECTOR 0x1c000000

void init_mem() {
    pmem = (uint8_t*)malloc(0x100000000);
    printf("PMEM_ADDR:0x%08x\n", pmem);
    printf("PMEM_END:0x%08x\n", pmem + 0x100000000);
    if (pmem == NULL) {
        fprintf(stderr, "内存分配失败！\n");
        exit(1);
    }
}

// 地址转换
uint8_t* padd2host(uint32_t paddr) {
    // printf("paddr:%08x\n",paddr);
    // printf("host_addr:%08x\n\n",pmem + paddr);
    return pmem + paddr;
}

uint32_t pmem_read(uint8_t* paddr) {
    uintptr_t addr_val = (uintptr_t)paddr;  // 将指针转换为整数类型
    uintptr_t aligned_addr_val =
        addr_val & ~3;  // 确保地址是 4 字节对齐的起始地址
    uint8_t* aligned_addr =
        (uint8_t*)aligned_addr_val;  // 将整数类型转换回指针类型

    return *((uint32_t*)aligned_addr);
}

void pmem_write(uint8_t* paddr, uint32_t data) {
    uintptr_t addr_val = (uintptr_t)paddr;  // 将指针转换为整数类型
    uintptr_t aligned_addr_val =
        addr_val & ~3;  // 确保地址是 4 字节对齐的起始地址
    uint8_t* aligned_addr =
        (uint8_t*)aligned_addr_val;  // 将整数类型转换回指针类型
    *((uint32_t*)aligned_addr) = data;
}

uint32_t paddr_read(uint32_t paddr) {
    return pmem_read(padd2host(paddr));
}

void paddr_write(uint32_t paddr, uint32_t data) {
    pmem_write(padd2host(paddr), data);
}

void load_inst() {
    FILE* fp = fopen(img_file, "rb");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    printf("The image is %s, size = %ld\n", img_file, size);

    fseek(fp, 0, SEEK_SET);

    // 装载 bin 到仿真环境，可以是 sram、mrom、flash
    int ret = fread(padd2host(RESET_VECTOR), size, 1, fp);

    fclose(fp);
}
// 加载数据，这里不设置 bootloader，数据与指令共享内存，越简单越好
void load_data() {
    // FILE* fp = fopen(img_file, "rb");

    // fseek(fp, 0, SEEK_END);
    // long size = ftell(fp);

    // printf("The image is %s, size = %ld\n", img_file, size);

    // fseek(fp, 0, SEEK_SET);

    // // 装载 bin 到仿真环境，可以是 sram、mrom、flash
    // int ret = fread(padd2host(RESET_VECTOR), size, 1, fp);
    // // int ret = fread(flash, size, 1, fp);

    // // for (int i = 0; i < 57; i++) {
    // //     printf("i = %d, uint32_t:0x%08x\n", i, ((uint32_t*)pmem)[i]);
    // // }

    // fclose(fp);
}
