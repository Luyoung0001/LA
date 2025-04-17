// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_top.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TOP___024ROOT_H_
#define VERILATED_VVERILATOR_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vverilator_top__Syms;
class Vverilator_top_verilator_top;


class Vverilator_top___024root final : public VerilatedModule {
  public:
    // CELLS
    Vverilator_top_verilator_top* verilator_top;

    // DESIGN SPECIFIC STATE
    VL_IN8(rst,0,0);
    VL_IN8(clk,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vverilator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vverilator_top___024root(Vverilator_top__Syms* symsp, const char* v__name);
    ~Vverilator_top___024root();
    VL_UNCOPYABLE(Vverilator_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
