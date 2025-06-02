// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_top.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TOP_BOOTHINTERBASE_H_
#define VERILATED_VVERILATOR_TOP_BOOTHINTERBASE_H_  // guard

#include "verilated.h"

class Vverilator_top__Syms;

class Vverilator_top_BoothInterBase final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(__PVT__y,2,0);
    VL_OUT8(__PVT__Carry,0,0);
    CData/*0:0*/ __PVT__negx;
    CData/*0:0*/ __PVT__x;
    CData/*0:0*/ __PVT__neg2x;
    CData/*0:0*/ __PVT___2x;
    CData/*0:0*/ uu__DOT____VdfgTmp_hf6cd5b06__0;
    CData/*0:0*/ uu__DOT____VdfgTmp_he6224cd4__0;
    VL_IN64(__PVT__InX,63,0);
    VL_OUT64(__PVT__OutX,63,0);
    VlUnpacked<CData/*1:0*/, 65> __PVT__CarrySig;

    // INTERNAL VARIABLES
    Vverilator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vverilator_top_BoothInterBase(Vverilator_top__Syms* symsp, const char* v__name);
    ~Vverilator_top_BoothInterBase();
    VL_UNCOPYABLE(Vverilator_top_BoothInterBase);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
