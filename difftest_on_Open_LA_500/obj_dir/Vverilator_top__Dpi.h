// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VVERILATOR_TOP__DPI_H_
#define VERILATED_VVERILATOR_TOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/luyoung/LA/difftest_on_Open_LA_500/mycpu_env/myCPU/DPIC/axi_ram.sv:47:33
    extern int data_ram_read(int addr);
    // DPI import at /home/luyoung/LA/difftest_on_Open_LA_500/mycpu_env/myCPU/DPIC/axi_ram.sv:48:34
    extern void data_ram_write(int addr, int wdata, char we_7);

#ifdef __cplusplus
}
#endif

#endif  // guard
