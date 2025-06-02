// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_BoothInterBase.h"

VL_ATTR_COLD void Vverilator_top_BoothInterBase___ctor_var_reset(Vverilator_top_BoothInterBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_BoothInterBase___ctor_var_reset\n"); );
    // Body
    vlSelf->__PVT__y = VL_RAND_RESET_I(3);
    vlSelf->__PVT__InX = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__OutX = VL_RAND_RESET_Q(64);
    vlSelf->__PVT__Carry = VL_RAND_RESET_I(1);
    vlSelf->__PVT__negx = VL_RAND_RESET_I(1);
    vlSelf->__PVT__x = VL_RAND_RESET_I(1);
    vlSelf->__PVT__neg2x = VL_RAND_RESET_I(1);
    vlSelf->__PVT___2x = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 65; ++__Vi0) {
        vlSelf->__PVT__CarrySig[__Vi0] = VL_RAND_RESET_I(2);
    }
    vlSelf->uu__DOT____VdfgTmp_hf6cd5b06__0 = 0;
    vlSelf->uu__DOT____VdfgTmp_he6224cd4__0 = 0;
}
