// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_WallaceTreeBase.h"

VL_ATTR_COLD void Vverilator_top_WallaceTreeBase___ctor_var_reset(Vverilator_top_WallaceTreeBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_WallaceTreeBase___ctor_var_reset\n"); );
    // Body
    vlSelf->__PVT__InData = VL_RAND_RESET_I(17);
    vlSelf->__PVT__CIn = VL_RAND_RESET_I(14);
    vlSelf->__PVT__COut = VL_RAND_RESET_I(14);
    vlSelf->__PVT__C = VL_RAND_RESET_I(1);
    vlSelf->__PVT__S = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__second3__B = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__second3__A = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__second4__C = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__second4__B = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__second4__A = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__third1__A = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__third2__C = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__third2__B = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__third2__A = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__fourth2__B = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__fourth2__A = VL_RAND_RESET_I(1);
    vlSelf->__PVT__FifSig = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__fifth1__B = VL_RAND_RESET_I(1);
    vlSelf->__Vcellinp__fifth1__A = VL_RAND_RESET_I(1);
    vlSelf->first1__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->first2__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->first3__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->first4__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->first5__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->second1__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->second2__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->second3__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->second4__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->third1__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->third2__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->fourth1__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->fourth2__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->fifth1__DOT____VdfgTmp_h99ddda1a__0 = 0;
    vlSelf->sixth1__DOT____VdfgTmp_h99ddda1a__0 = 0;
}
