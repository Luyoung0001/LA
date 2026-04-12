#include <main.h>
#include <paddr.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t* pmem = NULL;

// 加载指令
#define RESET_VECTOR 0x1c000000
#define PMEM_SIZE 0x100000000ULL

static const char* img_path = NULL;

static FILE* open_img_file() {
    const char* env_path = getenv("LA_MAIN_BIN");
    if (env_path == NULL) {
        env_path = "";
    }
    const char* candidates[] = {
        env_path,
        "mycpu_env/func/obj/main.bin",
        "../mycpu_env/func/obj/main.bin",
        NULL
    };

    for (int i = 0; candidates[i] != NULL; i++) {
        if (candidates[i][0] == '\0') {
            continue;
        }
        FILE* fp = fopen(candidates[i], "rb");
        if (fp != NULL) {
            img_path = candidates[i];
            return fp;
        }
    }

    fprintf(stderr, "Failed to open main.bin. Tried:\n");
    for (int i = 0; candidates[i] != NULL; i++) {
        if (candidates[i][0] != '\0') {
            fprintf(stderr, "  %s\n", candidates[i]);
        }
    }
    return NULL;
}

void init_mem() {
    pmem = (uint8_t*)malloc(PMEM_SIZE);
    if (pmem == NULL) {
        fprintf(stderr, "Memory allocation failed for PMEM_SIZE=%llu bytes\n",
                (unsigned long long)PMEM_SIZE);
        exit(1);
    }
    printf("PMEM_ADDR:%p\n", (void*)pmem);
    printf("PMEM_END :%p\n", (void*)(pmem + PMEM_SIZE));
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
    FILE* fp = open_img_file();
    if (fp == NULL) {
        exit(1);
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        perror("fseek(main.bin, SEEK_END) failed");
        fclose(fp);
        exit(1);
    }
    long size = ftell(fp);
    if (size <= 0) {
        fprintf(stderr, "Invalid main.bin size: %ld\n", size);
        fclose(fp);
        exit(1);
    }

    printf("The image is %s, size = %ld\n", img_path, size);

    if (fseek(fp, 0, SEEK_SET) != 0) {
        perror("fseek(main.bin, SEEK_SET) failed");
        fclose(fp);
        exit(1);
    }

    // 装载 bin 到仿真环境，可以是 sram、mrom、flash
    size_t ret = fread(padd2host(RESET_VECTOR), (size_t)size, 1, fp);
    if (ret != 1) {
        perror("fread(main.bin) failed");
        fclose(fp);
        exit(1);
    }

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
