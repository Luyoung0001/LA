// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top__Syms.h"
#include "Vverilator_top_verilator_top.h"

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__3(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__3\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g3 
        = (0x18U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 7U)) & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0) 
                                        << 3U)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p3 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 7U)) | (0x18U & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0) 
                                                 << 3U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0xcU)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 2U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0xcU)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 2U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x12U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 8U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x12U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 8U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__g6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x19U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0xfU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__p6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x19U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0xfU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g1 
        = (7U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                          >> 0x20U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                >> 0x16U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p1 
        = (7U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                          >> 0x20U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                >> 0x16U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g2 
        = (0xfU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                            >> 0x23U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 0x19U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p2 
        = (0xfU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                            >> 0x23U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 0x19U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g3 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x27U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x1dU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p3 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x27U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x1dU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x2cU)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x22U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x2cU)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x22U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x32U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x28U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x32U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x28U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__g6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x39U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x2fU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__p6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x39U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x2fU))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x32U)) ^ ((IData)(
                                                   (vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                    >> 0x28U)) 
                                           ^ ((0x7eU 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c5) 
                                                  << 1U)) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4) 
                                                    >> 5U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x2cU)) ^ ((IData)(
                                                   (vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                    >> 0x22U)) 
                                           ^ ((0x3eU 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c4) 
                                                  << 1U)) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3) 
                                                    >> 4U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba801ce4__0 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x19U)) ^ ((IData)(
                                                   (vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                    >> 0xfU)) 
                                           ^ ((0x7eU 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6) 
                                                  << 1U)) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5) 
                                                    >> 6U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x27U)) ^ ((IData)(
                                                   (vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                    >> 0x1dU)) 
                                           ^ ((0x1eU 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c3) 
                                                  << 1U)) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2) 
                                                    >> 3U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbb7d496d__0 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0x12U)) ^ ((IData)(
                                                   (vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                    >> 8U)) 
                                           ^ ((0x7eU 
                                               & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c5) 
                                                  << 1U)) 
                                              | (1U 
                                                 & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4) 
                                                    >> 5U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbadb26f2__0 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 0xcU)) ^ ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 2U)) 
                                          ^ ((0x3eU 
                                              & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c4) 
                                                 << 1U)) 
                                             | (1U 
                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3) 
                                                   >> 4U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbabf5eef__0 
        = (0xfU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                            >> 0x23U)) ^ ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x19U)) 
                                          ^ ((0xeU 
                                              & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c2) 
                                                 << 1U)) 
                                             | (1U 
                                                & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1) 
                                                   >> 2U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hba8f8829__0 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                             >> 7U)) ^ ((0x18U & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0) 
                                                  << 3U)) 
                                        ^ ((0x1eU & 
                                            ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c3) 
                                             << 1U)) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2) 
                                               >> 3U))))));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbaecaf09__0 
        = (7U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                          >> 0x20U)) ^ ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                 >> 0x16U)) 
                                        ^ ((6U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_high__DOT__c1) 
                                                  << 1U)) 
                                           | (1U & 
                                              ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c6) 
                                               >> 6U))))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x39U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x2fU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x39U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x2fU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x32U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x28U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x32U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x28U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x2cU)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x22U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x2cU)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x22U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g3 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x27U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x1dU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p3 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x27U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0x1dU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g2 
        = (0xfU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                            >> 0x23U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 0x19U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p2 
        = (0xfU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                            >> 0x23U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 0x19U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__g1 
        = (7U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                          >> 0x20U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                >> 0x16U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_high__DOT__p1 
        = (7U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                          >> 0x20U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                >> 0x16U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x19U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0xfU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p6 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x19U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 0xfU))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x12U)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 8U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p5 
        = (0x7fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0x12U)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                   >> 8U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0xcU)) & (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 2U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p4 
        = (0x3fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 0xcU)) | (IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0 
                                                  >> 2U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__g3 
        = (0x18U & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 7U)) & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0) 
                                        << 3U)));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__resulttemp__DOT__adder_low__DOT__p3 
        = (0x1fU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__PVT__opa 
                             >> 7U)) | (0x18U & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o1__DOT__wallace.__VdfgTmp_hb69c62fc__0) 
                                                 << 3U))));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g5 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p5 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbb7d496d__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7e4e467__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g4 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p4 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hbadb26f2__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7439dfc__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__g3 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0) 
           & (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0));
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT__p3 
        = ((IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hba8f8829__0) 
           | (IData)(vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_high__DOT____VdfgTmp_hf7372d37__0));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__15(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__15\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0 
        = ((4U & (((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                            >> 2U)) << 2U) & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0) 
                                              << 1U))) 
           | (2U & (((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                              >> 1U)) & (IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0)) 
                    << 1U)));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbaecaf09__0 
        = (7U & ((IData)(vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa) 
                 ^ ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0) 
                    << 1U)));
    vlSelf->cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__result__DOT__adder_low__DOT____VdfgTmp_hbabf5eef__0 
        = (0xfU & ((IData)((vlSymsp->TOP__verilator_top__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__wallace.__PVT__opa 
                            >> 3U)) ^ ((0xeU & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c2) 
                                                << 1U)) 
                                       | (1U & ((IData)(vlSelf->__PVT__cpu__DOT__exu__DOT__mul__DOT__o__DOT__o__DOT__resulttemp__DOT__adder_low__DOT__c1_s0) 
                                                >> 2U)))));
}
