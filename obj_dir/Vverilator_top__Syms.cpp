// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vverilator_top__Syms.h"
#include "Vverilator_top.h"
#include "Vverilator_top___024root.h"
#include "Vverilator_top_verilator_top.h"

// FUNCTIONS
Vverilator_top__Syms::~Vverilator_top__Syms()
{
}

Vverilator_top__Syms::Vverilator_top__Syms(VerilatedContext* contextp, const char* namep, Vverilator_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
    , TOP__verilator_top{this, Verilated::catName(namep, "verilator_top")}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.verilator_top = &TOP__verilator_top;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__verilator_top.__Vconfigure(true);
    // Setup scopes
    __Vscope_verilator_top.configure(this, name(), "verilator_top", "verilator_top", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal = 0; __Vfinal < 2; ++__Vfinal) {
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_pc", &(TOP__verilator_top.debug_wb_pc), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_rf_wdata", &(TOP__verilator_top.debug_wb_rf_wdata), false, VLVT_UINT32,VLVD_NODIR|VLVF_PUB_RW,1 ,31,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_rf_we", &(TOP__verilator_top.debug_wb_rf_we), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,3,0);
        __Vscope_verilator_top.varInsert(__Vfinal,"debug_wb_rf_wnum", &(TOP__verilator_top.debug_wb_rf_wnum), false, VLVT_UINT8,VLVD_NODIR|VLVF_PUB_RW,1 ,4,0);
    }
}
