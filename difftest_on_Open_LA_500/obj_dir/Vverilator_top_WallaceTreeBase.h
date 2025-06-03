// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_top.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TOP_WALLACETREEBASE_H_
#define VERILATED_VVERILATOR_TOP_WALLACETREEBASE_H_  // guard

#include "verilated.h"

class Vverilator_top__Syms;

class Vverilator_top_WallaceTreeBase final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(__PVT__C,0,0);
    VL_OUT8(__PVT__S,0,0);
    CData/*0:0*/ __Vcellinp__second3__B;
    CData/*0:0*/ __Vcellinp__second3__A;
    CData/*0:0*/ __Vcellinp__second4__C;
    CData/*0:0*/ __Vcellinp__second4__B;
    CData/*0:0*/ __Vcellinp__second4__A;
    CData/*0:0*/ __Vcellinp__third1__A;
    CData/*0:0*/ __Vcellinp__third2__C;
    CData/*0:0*/ __Vcellinp__third2__B;
    CData/*0:0*/ __Vcellinp__third2__A;
    CData/*0:0*/ __Vcellinp__fourth2__B;
    CData/*0:0*/ __Vcellinp__fourth2__A;
    CData/*0:0*/ __PVT__FifSig;
    CData/*0:0*/ __Vcellinp__fifth1__B;
    CData/*0:0*/ __Vcellinp__fifth1__A;
    CData/*0:0*/ first1__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ first2__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ first3__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ first4__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ first5__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ second1__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ second2__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ second3__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ second4__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ third1__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ third2__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ fourth1__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ fourth2__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ fifth1__DOT____VdfgTmp_h99ddda1a__0;
    CData/*0:0*/ sixth1__DOT____VdfgTmp_h99ddda1a__0;
    VL_IN16(__PVT__CIn,13,0);
    VL_OUT16(__PVT__COut,13,0);
    VL_IN(__PVT__InData,16,0);

    // INTERNAL VARIABLES
    Vverilator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vverilator_top_WallaceTreeBase(Vverilator_top__Syms* symsp, const char* v__name);
    ~Vverilator_top_WallaceTreeBase();
    VL_UNCOPYABLE(Vverilator_top_WallaceTreeBase);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
