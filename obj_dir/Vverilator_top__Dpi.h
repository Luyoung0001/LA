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
    // DPI import at /home/luyoung/LA/mycpu_env/myCPU/DPIC/data_ram.sv:37:33
    extern int data_ram_read(int addr);
    // DPI import at /home/luyoung/LA/mycpu_env/myCPU/DPIC/data_ram.sv:38:34
    extern void data_ram_write(int addr, int wdata);
    // DPI import at /home/luyoung/LA/mycpu_env/myCPU/DPIC/inst_ram.sv:27:33
    extern int inst_ram_read(int addr);

#ifdef __cplusplus
}
#endif

#endif  // guard
