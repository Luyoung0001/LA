// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_verilator_top.h"

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__0\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2 
        = ((4U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__1(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__1\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2 
        = ((4U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__0\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3 
        = ((8U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0 
        = (0x1fU & ((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                        >> 7U)) ^ ((0x1eU & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3) 
                                             << 1U)) 
                                   | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2) 
                                            >> 3U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__2(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__2\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h63a56e8b__0;
    // Body
    __Vtemp_h63a56e8b__0 = ((0x40U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                           >> 0x1fU)) 
                                       << 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0) 
                                                 << 1U))) 
                            | ((0x20U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0x1eU)) 
                                          << 5U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0) 
                                          << 1U))) 
                               | ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x1dU)) 
                                             << 4U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0) 
                                               << 1U))) 
                                  | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x1cU)) 
                                             << 3U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0) 
                                               << 1U))) 
                                     | ((4U & (((~ 
                                                 (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0x1bU)) 
                                                << 2U) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U))) 
                                        | (2U & (((~ 
                                                   (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                    >> 0x1aU)) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0)) 
                                                 << 1U)))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0 
        = __Vtemp_h63a56e8b__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__3(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__3\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h55f93b23__0;
    // Body
    __Vtemp_h55f93b23__0 = ((0x40U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                           >> 0x1fU)) 
                                       << 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1) 
                                                 << 1U))) 
                            | ((0x20U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0x1eU)) 
                                          << 5U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1) 
                                          << 1U))) 
                               | ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x1dU)) 
                                             << 4U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1) 
                                               << 1U))) 
                                  | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x1cU)) 
                                             << 3U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1) 
                                               << 1U))) 
                                     | ((4U & (((~ 
                                                 (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0x1bU)) 
                                                << 2U) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U))) 
                                        | ((2U & ((
                                                   (~ 
                                                    (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                     >> 0x1aU)) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1)) 
                                                  << 1U)) 
                                           | (1U & 
                                              (~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0x19U)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1 
        = __Vtemp_h55f93b23__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__4(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__4\n"); );
    // Init
    CData/*31:0*/ __Vtemp_ha857b339__0;
    // Body
    __Vtemp_ha857b339__0 = ((0x40U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                           >> 0x18U)) 
                                       << 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0) 
                                                 << 1U))) 
                            | ((0x20U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0x17U)) 
                                          << 5U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0) 
                                          << 1U))) 
                               | ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x16U)) 
                                             << 4U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0) 
                                               << 1U))) 
                                  | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x15U)) 
                                             << 3U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0) 
                                               << 1U))) 
                                     | ((4U & (((~ 
                                                 (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0x14U)) 
                                                << 2U) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U))) 
                                        | (2U & (((~ 
                                                   (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                    >> 0x13U)) 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0)) 
                                                 << 1U)))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0 
        = __Vtemp_ha857b339__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__5(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__5\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h8206a99b__0;
    // Body
    __Vtemp_h8206a99b__0 = ((0x40U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                           >> 0x18U)) 
                                       << 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1) 
                                                 << 1U))) 
                            | ((0x20U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0x17U)) 
                                          << 5U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1) 
                                          << 1U))) 
                               | ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x16U)) 
                                             << 4U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1) 
                                               << 1U))) 
                                  | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0x15U)) 
                                             << 3U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1) 
                                               << 1U))) 
                                     | ((4U & (((~ 
                                                 (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0x14U)) 
                                                << 2U) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U))) 
                                        | ((2U & ((
                                                   (~ 
                                                    (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                     >> 0x13U)) 
                                                   & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1)) 
                                                  << 1U)) 
                                           | (1U & 
                                              (~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0x12U)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1 
        = __Vtemp_h8206a99b__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__6(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__6\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h8477c06f__0;
    // Body
    __Vtemp_h8477c06f__0 = ((0x20U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                           >> 0x11U)) 
                                       << 5U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0) 
                                                 << 1U))) 
                            | ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0x10U)) 
                                          << 4U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0) 
                                          << 1U))) 
                               | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0xfU)) 
                                          << 3U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0) 
                                          << 1U))) 
                                  | ((4U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0xeU)) 
                                             << 2U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0) 
                                               << 1U))) 
                                     | (2U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                   >> 0xdU)) 
                                               & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0)) 
                                              << 1U))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0 
        = __Vtemp_h8477c06f__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__7(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__7\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h48b25211__0;
    // Body
    __Vtemp_h48b25211__0 = ((0x20U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                           >> 0x11U)) 
                                       << 5U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1) 
                                                 << 1U))) 
                            | ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0x10U)) 
                                          << 4U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1) 
                                          << 1U))) 
                               | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                              >> 0xfU)) 
                                          << 3U) & 
                                         ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1) 
                                          << 1U))) 
                                  | ((4U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                 >> 0xeU)) 
                                             << 2U) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1) 
                                               << 1U))) 
                                     | ((2U & (((~ 
                                                 (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0xdU)) 
                                                & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1)) 
                                               << 1U)) 
                                        | (1U & (~ 
                                                 (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                                  >> 0xcU))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1 
        = __Vtemp_h48b25211__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__8(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__8\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0 
        = ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                          >> 0xbU)) << 4U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0) 
                                              << 1U))) 
           | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                          >> 0xaU)) << 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0) 
                                              << 1U))) 
              | ((4U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                             >> 9U)) << 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0) 
                                               << 1U))) 
                 | (2U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                               >> 8U)) & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s0)) 
                          << 1U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__9(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__9\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1 
        = ((0x10U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                          >> 0xbU)) << 4U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1) 
                                              << 1U))) 
           | ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                          >> 0xaU)) << 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1) 
                                              << 1U))) 
              | ((4U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                             >> 9U)) << 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1) 
                                               << 1U))) 
                 | ((2U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                >> 8U)) & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3_s1)) 
                           << 1U)) | (1U & (~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                               >> 7U)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__10(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__10\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0 
        = ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                       >> 6U)) << 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0) 
                                         << 1U))) | 
           ((4U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                        >> 5U)) << 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0) 
                                          << 1U))) 
            | (2U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                          >> 4U)) & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s0)) 
                     << 1U))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__11(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__11\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1 
        = ((8U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                       >> 6U)) << 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1) 
                                         << 1U))) | 
           ((4U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                        >> 5U)) << 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1) 
                                          << 1U))) 
            | ((2U & (((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                           >> 4U)) & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2_s1)) 
                      << 1U)) | (1U & (~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                                          >> 3U))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__12(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__12\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0 
        = ((4U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                     << 1U))) | ((2U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                                           << 1U))) 
                                 | (1U & (~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0 
        = (7U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                 ^ (1U | (6U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                                << 1U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__13(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__13\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s1 
        = (1U | ((4U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s1) 
                           << 1U))) | (2U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s1) 
                                                << 1U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__2(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__2\n"); );
    // Body
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0 
        = (0xfU & ((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                       >> 3U)) ^ ((0xeU & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2) 
                                           << 1U)) 
                                  | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                                           >> 2U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__22(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__22\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__23(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__23\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__24(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__24\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__25(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__25\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                       | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__26(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__26\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h297773a5__0;
    // Body
    __Vtemp_h297773a5__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s0 
        = __Vtemp_h297773a5__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__27(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__27\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h3fba1ed5__0;
    // Body
    __Vtemp_h3fba1ed5__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5_s1 
        = __Vtemp_h3fba1ed5__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__28(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__28\n"); );
    // Init
    CData/*31:0*/ __Vtemp_hbfbecbb2__0;
    // Body
    __Vtemp_hbfbecbb2__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s0 
        = __Vtemp_hbfbecbb2__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__29(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__29\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h25f87048__0;
    // Body
    __Vtemp_h25f87048__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6_s1 
        = __Vtemp_h25f87048__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__30(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__30\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s0 
        = ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s0) 
                        << 1U)))) | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s0) 
                                                  << 1U)))) 
                                     | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__31(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__31\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s1 
        = ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s1) 
                        << 1U)))) | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1_s1) 
                                                  << 1U)))) 
                                     | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                                              | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__32(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__32\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s0 
        = ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s0) 
                        << 1U)))) | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s0) 
                                                  << 1U)))) 
                                     | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s0) 
                                                     << 1U)))) 
                                        | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__33(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__33\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s1 
        = ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s1) 
                        << 1U)))) | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s1) 
                                                  << 1U)))) 
                                     | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2_s1) 
                                                     << 1U)))) 
                                        | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__34(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__34\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__35(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__35\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__36(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__36\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__37(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__37\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                       | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__38(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__38\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h6ab43a56__0;
    // Body
    __Vtemp_h6ab43a56__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s0 
        = __Vtemp_h6ab43a56__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__39(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__39\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h2d148c79__0;
    // Body
    __Vtemp_h2d148c79__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5_s1 
        = __Vtemp_h2d148c79__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__40(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__40\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h02f899a8__0;
    // Body
    __Vtemp_h02f899a8__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s0 
        = __Vtemp_h02f899a8__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__41(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__41\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h7ccec8fc__0;
    // Body
    __Vtemp_h7ccec8fc__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c6_s1 
        = __Vtemp_h7ccec8fc__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__42(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__42\n"); );
    // Init
    CData/*31:0*/ __Vtemp_hb50969a1__0;
    // Body
    __Vtemp_hb50969a1__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s0 
        = __Vtemp_hb50969a1__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__43(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__43\n"); );
    // Init
    CData/*31:0*/ __Vtemp_hdbd62c20__0;
    // Body
    __Vtemp_hdbd62c20__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c6_s1 
        = __Vtemp_hdbd62c20__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__44(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__44\n"); );
    // Init
    CData/*31:0*/ __Vtemp_hd0a8d2cb__0;
    // Body
    __Vtemp_hd0a8d2cb__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0 
        = __Vtemp_hd0a8d2cb__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__45(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__45\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h81859725__0;
    // Body
    __Vtemp_h81859725__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1 
        = __Vtemp_h81859725__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__46(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__46\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__47(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__47\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4) 
                                                       | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__48(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__48\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__49(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__49\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__50(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__50\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0 
        = ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0) 
                        << 1U)))) | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0) 
                                                  << 1U)))) 
                                     | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0) 
                                                     << 1U)))) 
                                        | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__51(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__51\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1 
        = ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1) 
                        << 1U)))) | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1) 
                                                  << 1U)))) 
                                     | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1) 
                                                     << 1U)))) 
                                        | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__52(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__52\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s0 
        = ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s0) 
                        << 1U)))) | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s0) 
                                                  << 1U)))) 
                                     | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__53(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__53\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s1 
        = ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s1) 
                        << 1U)))) | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s1) 
                                                  << 1U)))) 
                                     | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1) 
                                              | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__54(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__54\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h758f2c8b__0;
    // Body
    __Vtemp_h758f2c8b__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s0 
        = __Vtemp_h758f2c8b__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__55(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__55\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h083dbaa2__0;
    // Body
    __Vtemp_h083dbaa2__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6_s1 
        = __Vtemp_h083dbaa2__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__56(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__56\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h8ee8dcb5__0;
    // Body
    __Vtemp_h8ee8dcb5__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0 
        = __Vtemp_h8ee8dcb5__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__57(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__57\n"); );
    // Init
    CData/*31:0*/ __Vtemp_hfd496833__0;
    // Body
    __Vtemp_hfd496833__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1 
        = __Vtemp_hfd496833__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__58(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__58\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__59(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__59\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4) 
                                                       | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__60(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__60\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__61(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_sequent__TOP__verilator_top__61\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__4(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__4\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4 
        = ((0x10U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4_s0));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0 
        = (0x3fU & ((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                        >> 0xcU)) ^ ((0x3eU & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4) 
                                               << 1U)) 
                                     | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c3) 
                                              >> 4U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__6(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__6\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                      >> 4U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0) 
                                >> 3U))) << 4U) | (
                                                   (8U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0) 
                                                          << 1U))) 
                                                   | ((4U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0) 
                                                             << 1U))) 
                                                      | (2U 
                                                         & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0) 
                                                               << 1U))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__7(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__7\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                      >> 4U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1) 
                                >> 3U))) << 4U) | (
                                                   (8U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1) 
                                                          << 1U))) 
                                                   | ((4U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1) 
                                                             << 1U))) 
                                                      | ((2U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1) 
                                                                << 1U))) 
                                                         | (1U 
                                                            & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__8(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__8\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s1 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0) 
                      >> 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s1) 
                                >> 1U))) << 2U) | (
                                                   (2U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s1) 
                                                          << 1U))) 
                                                   | (1U 
                                                      & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__9(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__9\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0) 
                      >> 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0) 
                                >> 1U))) << 2U) | (2U 
                                                   & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0) 
                                                      & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0) 
                                                         << 1U))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__10(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__10\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                      >> 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0) 
                                >> 2U))) << 3U) | (
                                                   (4U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0) 
                                                          << 1U))) 
                                                   | (2U 
                                                      & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0) 
                                                            << 1U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__11(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__11\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                      >> 3U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1) 
                                >> 2U))) << 3U) | (
                                                   (4U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1) 
                                                          << 1U))) 
                                                   | ((2U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1) 
                                                             << 1U))) 
                                                      | (1U 
                                                         & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__12(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__12\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2 
        = ((4U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c1_s0))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__13(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__13\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5 
        = ((0x20U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5_s0));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0 
        = (0x7fU & ((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                        >> 0x12U)) ^ ((0x7eU & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5) 
                                                << 1U)) 
                                      | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c4) 
                                               >> 5U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__15(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__15\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                      >> 5U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0) 
                                >> 4U))) << 5U) | (
                                                   (0x10U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0) 
                                                          << 1U))) 
                                                   | ((8U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0) 
                                                             << 1U))) 
                                                      | ((4U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0) 
                                                                << 1U))) 
                                                         | (2U 
                                                            & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0) 
                                                                  << 1U)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__16(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__16\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                      >> 5U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1) 
                                >> 4U))) << 5U) | (
                                                   (0x10U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1) 
                                                          << 1U))) 
                                                   | ((8U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1) 
                                                             << 1U))) 
                                                      | ((4U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1) 
                                                                << 1U))) 
                                                         | ((2U 
                                                             & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1) 
                                                                   << 1U))) 
                                                            | (1U 
                                                               & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__17(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__17\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2 
        = ((4U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__18(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__18\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3 
        = ((8U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c2))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__19(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__19\n"); );
    // Body
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf708c3fe__0 
        = (0x7fU & ((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                        >> 0x19U)) ^ ((0x7eU & (((0x40U 
                                                  & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5))
                                                  ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s1)
                                                  : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c6_s0)) 
                                                << 1U)) 
                                      | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c5) 
                                               >> 6U)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__21(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__21\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                      >> 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0) 
                                >> 5U))) << 6U) | (
                                                   (0x20U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0) 
                                                          << 1U))) 
                                                   | ((0x10U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0) 
                                                             << 1U))) 
                                                      | ((8U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0) 
                                                                << 1U))) 
                                                         | ((4U 
                                                             & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0) 
                                                                   << 1U))) 
                                                            | (2U 
                                                               & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0) 
                                                                     << 1U))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__22(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__22\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                      >> 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1) 
                                >> 5U))) << 6U) | (
                                                   (0x20U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1) 
                                                          << 1U))) 
                                                   | ((0x10U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1) 
                                                             << 1U))) 
                                                      | ((8U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1) 
                                                                << 1U))) 
                                                         | ((4U 
                                                             & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1) 
                                                                   << 1U))) 
                                                            | ((2U 
                                                                & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1) 
                                                                      << 1U))) 
                                                               | (1U 
                                                                  & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__23(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__23\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3 
        = ((8U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__24(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__24\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4 
        = ((0x10U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c3))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__26(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__26\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                      >> 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0) 
                                >> 5U))) << 6U) | (
                                                   (0x20U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0) 
                                                          << 1U))) 
                                                   | ((0x10U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0) 
                                                             << 1U))) 
                                                      | ((8U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0) 
                                                                << 1U))) 
                                                         | ((4U 
                                                             & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0) 
                                                                   << 1U))) 
                                                            | (2U 
                                                               & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0) 
                                                                     << 1U))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__27(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__27\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1 
        = (((IData)((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                      >> 6U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1) 
                                >> 5U))) << 6U) | (
                                                   (0x20U 
                                                    & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1) 
                                                          << 1U))) 
                                                   | ((0x10U 
                                                       & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1) 
                                                             << 1U))) 
                                                      | ((8U 
                                                          & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1) 
                                                                << 1U))) 
                                                         | ((4U 
                                                             & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1) 
                                                                   << 1U))) 
                                                            | ((2U 
                                                                & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1) 
                                                                      << 1U))) 
                                                               | (1U 
                                                                  & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__28(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__28\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4 
        = ((0x10U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__29(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__29\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5 
        = ((0x20U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c4))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c5_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__31(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__31\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__32(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__32\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5 
        = ((0x20U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__35(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__35\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__36(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__36\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s0 
        = ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s0) 
                        << 1U)))) | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s0) 
                                                  << 1U)))) 
                                     | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__37(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__37\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s1 
        = ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s1) 
                        << 1U)))) | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s1) 
                                                  << 1U)))) 
                                     | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1) 
                                              | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__38(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__38\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6 
        = ((0x40U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__39(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__39\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1 
        = ((0x40U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__c6))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__41(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__41\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__42(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__42\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0 
        = ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0) 
                        << 1U)))) | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0) 
                                                  << 1U)))) 
                                     | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0) 
                                                     << 1U)))) 
                                        | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2)))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__43(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__43\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1 
        = ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2) 
                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1) 
                        << 1U)))) | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1) 
                                                  << 1U)))) 
                                     | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1) 
                                                     << 1U)))) 
                                        | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2) 
                                                 | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__44(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__44\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1 
        = ((0x40U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__45(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__45\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2 
        = ((4U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c1))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__47(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__47\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__48(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__48\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__49(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__49\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1 
        = ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1) 
                           << 1U)))) | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1) 
                                                     << 1U)))) 
                                        | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1) 
                                                        << 1U)))) 
                                           | ((2U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1) 
                                                      << 1U)))) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3) 
                                                    | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__50(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__50\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2 
        = ((4U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__51(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__51\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3 
        = ((8U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c2))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__53(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__53\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__54(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__54\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4)))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__55(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__55\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1 
        = ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1) 
                           << 1U)))) | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1) 
                                                        << 1U)))) 
                                        | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1) 
                                                        << 1U)))) 
                                           | ((4U & 
                                               ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                   & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1) 
                                                      << 1U)))) 
                                              | ((2U 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                     | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4) 
                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1) 
                                                           << 1U)))) 
                                                 | (1U 
                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4) 
                                                       | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4))))))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__56(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__56\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3 
        = ((8U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__57(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__57\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4 
        = ((0x10U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c3))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__58(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__58\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba801ce4__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf708c3fe__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba801ce4__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf708c3fe__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__59(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__59\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h2355b3c2__0;
    // Body
    __Vtemp_h2355b3c2__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0 
        = __Vtemp_h2355b3c2__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__60(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__60\n"); );
    // Init
    CData/*31:0*/ __Vtemp_he5f4c1d7__0;
    // Body
    __Vtemp_he5f4c1d7__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1 
        = __Vtemp_he5f4c1d7__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__61(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__61\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4 
        = ((0x10U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__62(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__62\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5 
        = ((0x20U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c4))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__c5_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__63(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__63\n"); );
    // Init
    CData/*31:0*/ __Vtemp_h4d042aab__0;
    // Body
    __Vtemp_h4d042aab__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0) 
                                                        << 1U)))) 
                                           | (1U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0 
        = __Vtemp_h4d042aab__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__64(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__64\n"); );
    // Init
    CData/*31:0*/ __Vtemp_heaa8bbf5__0;
    // Body
    __Vtemp_heaa8bbf5__0 = ((0x40U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                      | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1) 
                                            << 1U)))) 
                            | ((0x20U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                         | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1) 
                                               << 1U)))) 
                               | ((0x10U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U)))) 
                                  | ((8U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                            | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1) 
                                                  << 1U)))) 
                                     | ((4U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                               | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1) 
                                                     << 1U)))) 
                                        | ((2U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                                  | ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6) 
                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1) 
                                                        << 1U)))) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g6) 
                                               | (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p6)))))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1 
        = __Vtemp_heaa8bbf5__0;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__65(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__65\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5 
        = ((0x20U & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4))
            ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s1)
            : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5_s0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___act_comb__TOP__verilator_top__67(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___act_comb__TOP__verilator_top__67\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data = (
                                                   (0x800000U 
                                                    & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U])
                                                    ? vlSelf->__PVT__cpu__DOT__o__DOT__data_read_data
                                                    : 
                                                   ((0x10000U 
                                                     & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U])
                                                     ? 
                                                    ((vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                      << 0x10U) 
                                                     | (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                                        >> 0x10U))
                                                     : 
                                                    ((IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_h817cd92b__0)
                                                      ? vlSelf->__PVT__cpu__DOT__exu__DOT__div_result
                                                      : 
                                                     ((IData)(vlSelf->cpu__DOT__exu__DOT____VdfgTmp_hd54a942d__0)
                                                       ? vlSelf->__PVT__cpu__DOT__exu__DOT__mod_result
                                                       : 
                                                      ((IData)(
                                                               (0U 
                                                                != 
                                                                (0xe000000U 
                                                                 & vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U])))
                                                        ? 
                                                       (((- (IData)(
                                                                    (1U 
                                                                     & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U] 
                                                                        >> 0x19U)))) 
                                                         & ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0) 
                                                              << 0x19U) 
                                                             ^ 
                                                             (((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6) 
                                                               << 0x1aU) 
                                                              | (0x2000000U 
                                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5) 
                                                                    << 0x13U)))) 
                                                            | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0) 
                                                                 << 0x12U) 
                                                                ^ 
                                                                ((0x1f80000U 
                                                                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c5) 
                                                                     << 0x13U)) 
                                                                 | (0x40000U 
                                                                    & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4) 
                                                                       << 0xdU)))) 
                                                               | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0) 
                                                                    << 0xcU) 
                                                                   ^ 
                                                                   ((0x3e000U 
                                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c4) 
                                                                        << 0xdU)) 
                                                                    | (0x1000U 
                                                                       & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3) 
                                                                          << 8U)))) 
                                                                  | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0) 
                                                                       << 7U) 
                                                                      ^ 
                                                                      ((0xf00U 
                                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c3) 
                                                                           << 8U)) 
                                                                       | (0x80U 
                                                                          & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2) 
                                                                             << 4U)))) 
                                                                     | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0) 
                                                                          << 3U) 
                                                                         ^ 
                                                                         ((0x70U 
                                                                           & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c2) 
                                                                              << 4U)) 
                                                                          | (8U 
                                                                             & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0) 
                                                                                << 1U)))) 
                                                                        | (7U 
                                                                           & ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0) 
                                                                              ^ 
                                                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c1_s0) 
                                                                               << 1U))))))))) 
                                                        | (((- (IData)(
                                                                       (1U 
                                                                        & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U] 
                                                                           >> 0x1aU)))) 
                                                            & ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba801ce4__0) 
                                                                 << 0x19U) 
                                                                ^ 
                                                                (((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf708c3fe__0) 
                                                                  << 0x19U) 
                                                                 ^ 
                                                                 ((((0x40U 
                                                                     & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5))
                                                                     ? (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s1)
                                                                     : (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c6_s0)) 
                                                                   << 0x1aU) 
                                                                  | (0x2000000U 
                                                                     & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5) 
                                                                        << 0x13U))))) 
                                                               | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0) 
                                                                    << 0x12U) 
                                                                   ^ 
                                                                   (((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0) 
                                                                     << 0x12U) 
                                                                    ^ 
                                                                    ((0x1f80000U 
                                                                      & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c5) 
                                                                         << 0x13U)) 
                                                                     | (0x40000U 
                                                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4) 
                                                                           << 0xdU))))) 
                                                                  | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0) 
                                                                       << 0xcU) 
                                                                      ^ 
                                                                      (((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0) 
                                                                        << 0xcU) 
                                                                       ^ 
                                                                       ((0x3e000U 
                                                                         & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c4) 
                                                                            << 0xdU)) 
                                                                        | (0x1000U 
                                                                           & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3) 
                                                                              << 8U))))) 
                                                                     | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0) 
                                                                          << 7U) 
                                                                         ^ 
                                                                         (((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0) 
                                                                           << 7U) 
                                                                          ^ 
                                                                          ((0xf00U 
                                                                            & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c3) 
                                                                               << 8U)) 
                                                                           | (0x80U 
                                                                              & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2) 
                                                                                << 4U))))) 
                                                                        | ((((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0) 
                                                                             << 3U) 
                                                                            ^ 
                                                                            (((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0) 
                                                                              << 3U) 
                                                                             ^ 
                                                                             ((0x70U 
                                                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c2) 
                                                                                << 4U)) 
                                                                              | (8U 
                                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1) 
                                                                                << 1U))))) 
                                                                           | ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0) 
                                                                              ^ 
                                                                              ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0) 
                                                                               ^ 
                                                                               ((6U 
                                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__c1) 
                                                                                << 1U)) 
                                                                                | (1U 
                                                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT__c6) 
                                                                                >> 6U))))))))))) 
                                                           | ((- (IData)(
                                                                         (1U 
                                                                          & (vlSelf->__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[7U] 
                                                                             >> 0x1bU)))) 
                                                              & vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT____Vcellout__adder_high__sum)))
                                                        : vlSelf->__PVT__cpu__DOT__exu__DOT__pv_addr)))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData 
        = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h1fbcf766__0)
            ? vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data
            : ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h8b961b55__0)
                ? vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data
                : ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h52bf9dc3__0)
                    ? ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                        << 0x10U) | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                                     >> 0x10U)) : (
                                                   (0U 
                                                    == (IData)(vlSelf->__PVT__cpu__DOT__idu_rf_raddr2))
                                                    ? 0U
                                                    : 
                                                   vlSelf->__PVT__cpu__DOT__u_regfile__DOT__rf
                                                   [vlSelf->__PVT__cpu__DOT__idu_rf_raddr2]))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
        = ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h29275379__0)
            ? vlSelf->__PVT__cpu__DOT__exu__DOT__exu_data
            : ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_h504567f6__0)
                ? vlSelf->__PVT__cpu__DOT__idu__DOT__mem_data
                : ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgExtracted_hb28e2988__0)
                    ? ((vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[4U] 
                        << 0x10U) | (vlSelf->__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[3U] 
                                     >> 0x10U)) : (
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                        >> 5U)))
                                                    ? 0U
                                                    : 
                                                   vlSelf->__PVT__cpu__DOT__u_regfile__DOT__rf
                                                   [
                                                   (0x1fU 
                                                    & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                       >> 5U))]))));
    vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd = (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                                   == vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData);
    vlSelf->__PVT__cpu__DOT__idu__DOT__br_taken = (
                                                   (~ (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__fs_excp_r)) 
                                                   & (((0x16U 
                                                        == 
                                                        (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                         >> 0x1aU)) 
                                                       & (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd)) 
                                                      | (((~ (IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__rj_eq_rd)) 
                                                          & (0x17U 
                                                             == 
                                                             (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 0x1aU))) 
                                                         | ((0x13U 
                                                             == 
                                                             (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 0x1aU)) 
                                                            | ((0x15U 
                                                                == 
                                                                (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                 >> 0x1aU)) 
                                                               | ((0x14U 
                                                                   == 
                                                                   (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                    >> 0x1aU)) 
                                                                  | (((0x18U 
                                                                       == 
                                                                       (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                        >> 0x1aU)) 
                                                                      & VL_LTS_III(32, vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData, vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData)) 
                                                                     | (((0x1aU 
                                                                          == 
                                                                          (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                           >> 0x1aU)) 
                                                                         & (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                                                            < vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData)) 
                                                                        | (((0x19U 
                                                                             == 
                                                                             (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                              >> 0x1aU)) 
                                                                            & VL_GTES_III(32, vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData, vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData)) 
                                                                           | ((0x1bU 
                                                                               == 
                                                                               (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU)) 
                                                                              & (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                                                                >= vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regbData)))))))))));
    vlSelf->__PVT__cpu__DOT__pre_ifu__DOT__nextpc = 
        ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__excp_flush)
          ? vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_eentry
          : ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush)
              ? ((- (IData)((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__ertn_flush))) 
                 & vlSelf->__PVT__cpu__DOT__csr_o__DOT__csr_era)
              : ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__br_taken)
                  ? (((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                      | ((0x15U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                    >> 0x1aU)) | ((0x14U 
                                                   == 
                                                   (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                    >> 0x1aU)) 
                                                  | ((0x18U 
                                                      == 
                                                      (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                       >> 0x1aU)) 
                                                     | ((0x1aU 
                                                         == 
                                                         (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                          >> 0x1aU)) 
                                                        | ((0x19U 
                                                            == 
                                                            (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                             >> 0x1aU)) 
                                                           | (0x1bU 
                                                              == 
                                                              (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                               >> 0x1aU))))))))
                      ? (vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg 
                         + (((0x14U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0x1aU)) 
                             | (0x15U == (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU)))
                             ? (((- (IData)((1U & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                   >> 9U)))) 
                                 << 0x1cU) | ((0xffc0000U 
                                               & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  << 0x12U)) 
                                              | (0x3fffcU 
                                                 & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                    >> 8U))))
                             : vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs))
                      : (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                         + vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs))
                  : ((IData)(4U) + vlSelf->__PVT__cpu__DOT__pre_ifu__DOT__pc))));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__4(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__4\n"); );
    // Body
    vlSelf->__PVT__wire_bvalid = vlSelf->__Vdly__wire_bvalid;
    vlSelf->__PVT__wire_wready = vlSelf->__Vdly__wire_wready;
    vlSelf->__PVT__wire_awready = vlSelf->__Vdly__wire_awready;
    vlSelf->__PVT__wire_rvalid = vlSelf->__Vdly__wire_rvalid;
    vlSelf->__PVT__wire_rid = vlSelf->__Vdly__wire_rid;
    vlSelf->__PVT__wire_rdata = vlSelf->__Vdly__wire_rdata;
    vlSelf->__PVT__wire_arready = vlSelf->__Vdly__wire_arready;
    vlSelf->__PVT__cpu__DOT__exu__DOT__wire_complete 
        = vlSelf->__Vdly__cpu__DOT__exu__DOT__wire_complete;
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__10(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__10\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0 
        = ((4U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                  & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                     << 1U))) | ((2U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                                        & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                                           << 1U))) 
                                 | (1U & (~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0 
        = (0xfU & ((~ (vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign 
                       >> 3U)) ^ ((0xeU & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c2) 
                                           << 1U)) 
                                  | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                                           >> 2U)))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0 
        = (7U & ((~ vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__sign) 
                 ^ (1U | (6U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__signcomp__DOT__adder_high__DOT__c1_s0) 
                                << 1U)))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g2 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p2 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf720fbf1__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g1 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p1 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf76b0a0f__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__76(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__76\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__do_div = ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__div) 
                                                 & ((~ (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__wire_complete)) 
                                                    & (1U 
                                                       == (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__exu_state))));
}
