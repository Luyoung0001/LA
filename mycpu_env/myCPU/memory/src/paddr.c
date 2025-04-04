#include <paddr.h>
#include <main.h>
#include <stdio.h>

uint8_t* pmem = NULL;

void init_mem() {
    // 申请内存 16*16MB
    pmem = (uint8_t*)malloc(0x100000000);
}

// 地址转换
uint32_t padd2host(uint32_t paddr) {
    return paddr + pmem;
}

uint32_t paddr_read(uint32_t paddr) {
    return pmem_read(padd2host(paddr), len);
}

void paddr_write(uint32_t paddr, uint32_t data) {
    pmem_write(padd2host(paddr), data);
}
uint32_t pmem_read(uint32_t paddr) {
    return pmem[paddr];
}
void pmem_write(uint32_t paddr, uint32_t data) {
    pmem[paddr] = data;
}


// 加载指令
#define img_file "/home/luyoung/LA/mycpu_env/func/obj/main.bin"
#define RESET_VECTOR 0x1c000000
void load_inst(){
    FILE* fp = fopen(img_file, "rb");

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    printf("The image is %s, size = %ld\n", img_file, size);

    fseek(fp, 0, SEEK_SET);

    // 装载 bin 到仿真环境，可以是 sram、mrom、flash
    int ret = fread(padd2host(RESET_VECTOR), size, 1, fp);
    // for (int i = 0; i < 57; i++) {
    //     printf("i = %d, uint32_t:0x%08x\n", i, ((uint32_t*)pmem)[i]);
    // }


    fclose(fp);

}
// 加载数据，这里不设置 bootloader，数据与指令共享内存，越简单越好
#define data_file "/home/luyoung/LA/mycpu_env/func/obj/main.bin"
void load_data(){
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
