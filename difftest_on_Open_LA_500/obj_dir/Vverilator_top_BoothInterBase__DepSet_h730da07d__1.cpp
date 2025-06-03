// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_BoothInterBase.h"
#include "Vverilator_top__Syms.h"

VL_INLINE_OPT void Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai__0(Vverilator_top_BoothInterBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__6__KET____DOT__ai__0\n"); );
    // Init
    CData/*0:0*/ uu__DOT____VdfgTmp_hf6cd5b06__0;
    uu__DOT____VdfgTmp_hf6cd5b06__0 = 0;
    CData/*0:0*/ uu__DOT____VdfgTmp_he6224cd4__0;
    uu__DOT____VdfgTmp_he6224cd4__0 = 0;
    // Body
    uu__DOT____VdfgTmp_hf6cd5b06__0 = (IData)((0x80ULL 
                                               == (0xc0ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    uu__DOT____VdfgTmp_he6224cd4__0 = (IData)((0x40ULL 
                                               == (0xc0ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    vlSelf->__PVT__CarrySig[1U] = ((1U & vlSelf->__PVT__CarrySig
                                    [1U]) | (2U & (
                                                   (~ (IData)(
                                                              (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 6U))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[1U] = ((2U & vlSelf->__PVT__CarrySig
                                    [1U]) | (1U & (IData)(
                                                          (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                           << 6U))));
    vlSelf->__PVT__CarrySig[2U] = ((1U & vlSelf->__PVT__CarrySig
                                    [2U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7fffffffffffffe0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 5U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[2U] = ((2U & vlSelf->__PVT__CarrySig
                                    [2U]) | (1U & (IData)(
                                                          (0x7fffffffffffffe0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 5U)))));
    vlSelf->__PVT__CarrySig[3U] = ((1U & vlSelf->__PVT__CarrySig
                                    [3U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3ffffffffffffff0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 4U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[3U] = ((2U & vlSelf->__PVT__CarrySig
                                    [3U]) | (1U & (IData)(
                                                          (0x3ffffffffffffff0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 4U)))));
    vlSelf->__PVT__CarrySig[4U] = ((1U & vlSelf->__PVT__CarrySig
                                    [4U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1ffffffffffffff8ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 3U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[4U] = ((2U & vlSelf->__PVT__CarrySig
                                    [4U]) | (1U & (IData)(
                                                          (0x1ffffffffffffff8ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 3U)))));
    vlSelf->__PVT__CarrySig[5U] = ((1U & vlSelf->__PVT__CarrySig
                                    [5U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xffffffffffffffcULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 2U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[5U] = ((2U & vlSelf->__PVT__CarrySig
                                    [5U]) | (1U & (IData)(
                                                          (0xffffffffffffffcULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 2U)))));
    vlSelf->__PVT__CarrySig[6U] = ((1U & vlSelf->__PVT__CarrySig
                                    [6U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7fffffffffffffeULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 1U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[6U] = ((2U & vlSelf->__PVT__CarrySig
                                    [6U]) | (1U & (IData)(
                                                          (0x7fffffffffffffeULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 1U)))));
    vlSelf->__PVT__CarrySig[7U] = ((1U & vlSelf->__PVT__CarrySig
                                    [7U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3ffffffffffffffULL 
                                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[7U] = ((2U & vlSelf->__PVT__CarrySig
                                    [7U]) | (1U & (IData)(
                                                          (0x3ffffffffffffffULL 
                                                           & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))));
    vlSelf->__PVT__CarrySig[8U] = ((1U & vlSelf->__PVT__CarrySig
                                    [8U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1ffffffffffffffULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  >> 1U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[8U] = ((2U & vlSelf->__PVT__CarrySig
                                    [8U]) | (1U & (IData)(
                                                          (0x1ffffffffffffffULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              >> 1U)))));
    vlSelf->__PVT__CarrySig[9U] = ((1U & vlSelf->__PVT__CarrySig
                                    [9U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xffffffffffffffULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  >> 2U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[9U] = ((2U & vlSelf->__PVT__CarrySig
                                    [9U]) | (1U & (IData)(
                                                          (0xffffffffffffffULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              >> 2U)))));
    vlSelf->__PVT__CarrySig[0xaU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 3U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xaU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (1U 
                                                 & (IData)(
                                                           (0x7fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 3U)))));
    vlSelf->__PVT__CarrySig[0xbU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 4U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xbU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (1U 
                                                 & (IData)(
                                                           (0x3fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 4U)))));
    vlSelf->__PVT__CarrySig[0xcU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x1fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 5U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xcU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (1U 
                                                 & (IData)(
                                                           (0x1fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 5U)))));
    vlSelf->__PVT__CarrySig[0xdU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0xfffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 6U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xdU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (1U 
                                                 & (IData)(
                                                           (0xfffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 6U)))));
    vlSelf->__PVT__CarrySig[0xeU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 7U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xeU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (1U 
                                                 & (IData)(
                                                           (0x7ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 7U)))));
    vlSelf->__PVT__CarrySig[0xfU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 8U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xfU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (1U 
                                                 & (IData)(
                                                           (0x3ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 8U)))));
    vlSelf->__PVT__CarrySig[0x10U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 9U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x10U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 9U)))));
    vlSelf->__PVT__CarrySig[0x11U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xaU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x11U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xaU)))));
    vlSelf->__PVT__CarrySig[0x12U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xbU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x12U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xbU)))));
    vlSelf->__PVT__CarrySig[0x13U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xcU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x13U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xcU)))));
    vlSelf->__PVT__CarrySig[0x14U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xdU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x14U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xdU)))));
    vlSelf->__PVT__CarrySig[0x15U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xeU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x15U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xeU)))));
    vlSelf->__PVT__CarrySig[0x16U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xfU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x16U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xfU)))));
    vlSelf->__PVT__CarrySig[0x17U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x10U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x17U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x10U)))));
    vlSelf->__PVT__CarrySig[0x18U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x11U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x18U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x11U)))));
    vlSelf->__PVT__CarrySig[0x19U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x12U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x19U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x12U)))));
    vlSelf->__PVT__CarrySig[0x1aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x13U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x13U)))));
    vlSelf->__PVT__CarrySig[0x1bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x14U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x14U)))));
    vlSelf->__PVT__CarrySig[0x1cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x15U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x15U)))));
    vlSelf->__PVT__CarrySig[0x1dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x16U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x16U)))));
    vlSelf->__PVT__CarrySig[0x1eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x17U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x17U)))));
    vlSelf->__PVT__CarrySig[0x1fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x18U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x18U)))));
    vlSelf->__PVT__CarrySig[0x20U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x19U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x20U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x19U)))));
    vlSelf->__PVT__CarrySig[0x21U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x21U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1aU)))));
    vlSelf->__PVT__CarrySig[0x22U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x22U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1bU)))));
    vlSelf->__PVT__CarrySig[0x23U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x23U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1cU)))));
    vlSelf->__PVT__CarrySig[0x24U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x24U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1dU)))));
    vlSelf->__PVT__CarrySig[0x25U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x25U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1eU)))));
    vlSelf->__PVT__CarrySig[0x26U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x26U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1fU)))));
    vlSelf->__PVT__CarrySig[0x27U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x20U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x27U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x20U)))));
    vlSelf->__PVT__CarrySig[0x28U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x21U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x28U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x21U)))));
    vlSelf->__PVT__CarrySig[0x29U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x22U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x29U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x22U)))));
    vlSelf->__PVT__CarrySig[0x2aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x23U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x23U)))));
    vlSelf->__PVT__CarrySig[0x2bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x24U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x24U)))));
    vlSelf->__PVT__CarrySig[0x2cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x25U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x25U)))));
    vlSelf->__PVT__CarrySig[0x2dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x26U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x26U)))));
    vlSelf->__PVT__CarrySig[0x2eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x27U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x27U)))));
    vlSelf->__PVT__CarrySig[0x2fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x28U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x28U)))));
    vlSelf->__PVT__CarrySig[0x30U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x29U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x30U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x29U)))));
    vlSelf->__PVT__CarrySig[0x31U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x31U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (1U 
                                                   & (IData)(
                                                             (0xffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2aU)))));
    vlSelf->__PVT__CarrySig[0x32U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x32U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2bU)))));
    vlSelf->__PVT__CarrySig[0x33U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x33U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2cU)))));
    vlSelf->__PVT__CarrySig[0x34U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x34U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2dU)))));
    vlSelf->__PVT__CarrySig[0x35U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x35U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (1U 
                                                   & (IData)(
                                                             (0xfffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2eU)))));
    vlSelf->__PVT__CarrySig[0x36U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x36U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2fU)))));
    vlSelf->__PVT__CarrySig[0x37U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x30U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x37U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x30U)))));
    vlSelf->__PVT__CarrySig[0x38U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x31U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x38U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x31U)))));
    vlSelf->__PVT__CarrySig[0x39U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x32U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x39U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (1U 
                                                   & (IData)(
                                                             (0xffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x32U)))));
    vlSelf->__PVT__CarrySig[0x3aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x33U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x33U)))));
    vlSelf->__PVT__CarrySig[0x3bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x34U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x34U)))));
    vlSelf->__PVT__CarrySig[0x3cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x35U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x35U)))));
    vlSelf->__PVT__CarrySig[0x3dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x36U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (1U 
                                                   & (IData)(
                                                             (0xfULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x36U)))));
    vlSelf->__PVT__CarrySig[0x3eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (7ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x37U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (1U 
                                                   & (IData)(
                                                             (7ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x37U)))));
    vlSelf->__PVT__CarrySig[0x3fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (3ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x38U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (1U 
                                                   & (IData)(
                                                             (3ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x38U)))));
    vlSelf->__PVT__CarrySig[0x40U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (1ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x39U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x40U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (1U 
                                                   & (IData)(
                                                             (1ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x39U)))));
    vlSelf->__PVT__neg2x = ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                        >> 5U))) & (IData)(uu__DOT____VdfgTmp_hf6cd5b06__0));
    vlSelf->__PVT__negx = (1U & ((IData)((0xc0ULL == 
                                          (0xe0ULL 
                                           & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                                 | ((IData)(uu__DOT____VdfgTmp_hf6cd5b06__0) 
                                    & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 5U)))));
    vlSelf->__PVT__x = (1U & ((IData)((0x20ULL == (0xe0ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                              | ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                             >> 5U))) 
                                 & (IData)(uu__DOT____VdfgTmp_he6224cd4__0))));
    vlSelf->__PVT___2x = ((IData)(uu__DOT____VdfgTmp_he6224cd4__0) 
                          & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                     >> 5U)));
    vlSelf->__PVT__OutX = (((QData)((IData)((((~ (IData)(
                                                         (1ULL 
                                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                             >> 0x39U)))) 
                                              & (IData)(vlSelf->__PVT__negx)) 
                                             | ((IData)(
                                                        ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                          >> 0x39U) 
                                                         & (IData)(vlSelf->__PVT__x))) 
                                                | (((vlSelf->__PVT__CarrySig
                                                     [0x3fU] 
                                                     >> 1U) 
                                                    & (IData)(vlSelf->__PVT__neg2x)) 
                                                   | (vlSelf->__PVT__CarrySig
                                                      [0x3fU] 
                                                      & (IData)(vlSelf->__PVT___2x))))))) 
                            << 0x3fU) | (((QData)((IData)(
                                                          (((~ (IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x38U)))) 
                                                            & (IData)(vlSelf->__PVT__negx)) 
                                                           | (((IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x38U))) 
                                                               & (IData)(vlSelf->__PVT__x)) 
                                                              | (((vlSelf->__PVT__CarrySig
                                                                   [0x3eU] 
                                                                   >> 1U) 
                                                                  & (IData)(vlSelf->__PVT__neg2x)) 
                                                                 | (vlSelf->__PVT__CarrySig
                                                                    [0x3eU] 
                                                                    & (IData)(vlSelf->__PVT___2x))))))) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             (((~ (IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x37U)))) 
                                                               & (IData)(vlSelf->__PVT__negx)) 
                                                              | (((IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x37U))) 
                                                                  & (IData)(vlSelf->__PVT__x)) 
                                                                 | (((vlSelf->__PVT__CarrySig
                                                                      [0x3dU] 
                                                                      >> 1U) 
                                                                     & (IData)(vlSelf->__PVT__neg2x)) 
                                                                    | (vlSelf->__PVT__CarrySig
                                                                       [0x3dU] 
                                                                       & (IData)(vlSelf->__PVT___2x))))))) 
                                             << 0x3dU) 
                                            | (((QData)((IData)(
                                                                (((~ (IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x36U)))) 
                                                                  & (IData)(vlSelf->__PVT__negx)) 
                                                                 | (((IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x36U))) 
                                                                     & (IData)(vlSelf->__PVT__x)) 
                                                                    | (((vlSelf->__PVT__CarrySig
                                                                         [0x3cU] 
                                                                         >> 1U) 
                                                                        & (IData)(vlSelf->__PVT__neg2x)) 
                                                                       | (vlSelf->__PVT__CarrySig
                                                                          [0x3cU] 
                                                                          & (IData)(vlSelf->__PVT___2x))))))) 
                                                << 0x3cU) 
                                               | (((QData)((IData)(
                                                                   (((~ (IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x35U)))) 
                                                                     & (IData)(vlSelf->__PVT__negx)) 
                                                                    | (((IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x35U))) 
                                                                        & (IData)(vlSelf->__PVT__x)) 
                                                                       | (((vlSelf->__PVT__CarrySig
                                                                            [0x3bU] 
                                                                            >> 1U) 
                                                                           & (IData)(vlSelf->__PVT__neg2x)) 
                                                                          | (vlSelf->__PVT__CarrySig
                                                                             [0x3bU] 
                                                                             & (IData)(vlSelf->__PVT___2x))))))) 
                                                   << 0x3bU) 
                                                  | (((QData)((IData)(
                                                                      (((~ (IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x34U)))) 
                                                                        & (IData)(vlSelf->__PVT__negx)) 
                                                                       | (((IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x34U))) 
                                                                           & (IData)(vlSelf->__PVT__x)) 
                                                                          | (((vlSelf->__PVT__CarrySig
                                                                               [0x3aU] 
                                                                               >> 1U) 
                                                                              & (IData)(vlSelf->__PVT__neg2x)) 
                                                                             | (vlSelf->__PVT__CarrySig
                                                                                [0x3aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                      << 0x3aU) 
                                                     | (((QData)((IData)(
                                                                         (((~ (IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x33U)))) 
                                                                           & (IData)(vlSelf->__PVT__negx)) 
                                                                          | (((IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x33U))) 
                                                                              & (IData)(vlSelf->__PVT__x)) 
                                                                             | (((vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                         << 0x39U) 
                                                        | (((QData)((IData)(
                                                                            (((~ (IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x32U)))) 
                                                                              & (IData)(vlSelf->__PVT__negx)) 
                                                                             | (((IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x32U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                            << 0x38U) 
                                                           | (((QData)((IData)(
                                                                               (((~ (IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x31U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x31U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                               << 0x37U) 
                                                              | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                  << 0x36U) 
                                                                 | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                     << 0x35U) 
                                                                    | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                        << 0x34U) 
                                                                       | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                           << 0x33U) 
                                                                          | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                              << 0x32U) 
                                                                             | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((((~ (IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1fU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1fU) 
                                                                                | ((0x80000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                << 0x1eU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1fU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1fU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1eU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1eU) 
                                                                                | ((0xc0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                << 0x1dU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1eU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1eU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1dU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1dU) 
                                                                                | ((0xe0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                << 0x1cU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1dU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1dU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1cU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1cU) 
                                                                                | ((0xf0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                << 0x1bU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1cU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1cU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1bU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1bU) 
                                                                                | ((0xf8000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                << 0x1aU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1bU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1bU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1aU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1aU) 
                                                                                | ((0xfc000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                << 0x19U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1aU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1aU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x19U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x19U) 
                                                                                | ((0xfe000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                << 0x18U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x19U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x19U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x18U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x18U) 
                                                                                | ((0xff000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                << 0x17U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x18U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x18U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x17U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x17U) 
                                                                                | ((0xff800000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                << 0x16U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x17U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x17U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x16U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x16U) 
                                                                                | ((0xffc00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                << 0x15U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x16U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x16U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x15U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x15U) 
                                                                                | ((0xffe00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                << 0x14U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x15U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x15U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x14U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x14U) 
                                                                                | ((0xfff00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                << 0x13U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x14U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x14U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x13U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x13U) 
                                                                                | ((0xfff80000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                << 0x12U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x13U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x13U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x12U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x12U) 
                                                                                | ((0xfffc0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                << 0x11U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x12U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x12U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x11U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x11U) 
                                                                                | ((0xfffe0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                << 0x10U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x11U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x11U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x10U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x10U) 
                                                                                | ((0xffff0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                << 0xfU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x10U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x10U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xfU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xfU) 
                                                                                | ((0xffff8000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                << 0xeU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xfU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xfU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xeU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xeU) 
                                                                                | ((0xffffc000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                << 0xdU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xeU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xeU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xdU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xdU) 
                                                                                | ((0xffffe000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                << 0xcU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xdU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xdU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xcU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xcU) 
                                                                                | ((0xfffff000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                << 0xbU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xcU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xcU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xbU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xbU) 
                                                                                | ((0xfffff800U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                << 0xaU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xbU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xbU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xaU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xaU) 
                                                                                | ((0xfffffc00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                << 9U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xaU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xaU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 9U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 9U) 
                                                                                | ((0xfffffe00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                << 8U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 9U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 9U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 8U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 8U) 
                                                                                | ((0xffffff00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                << 7U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 8U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 8U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 7U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 7U) 
                                                                                | ((0xffffff80U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                << 6U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 7U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 7U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 6U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 6U) 
                                                                                | ((0xffffffc0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                << 5U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 6U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 6U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 5U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 5U) 
                                                                                | ((0xffffffe0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                << 4U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 5U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 5U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 4U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 4U) 
                                                                                | ((0xfffffff0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                << 3U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 4U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 4U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 3U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 3U) 
                                                                                | ((0xfffffff8U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                << 2U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 3U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 3U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 2U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 2U) 
                                                                                | ((0xfffffffcU 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                << 1U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 2U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 2U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 1U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 1U) 
                                                                                | ((0xfffffffeU 
                                                                                & (vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 1U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 1U)))) 
                                                                                | (((~ (IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (IData)(vlSelf->__PVT__neg2x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai__0(Vverilator_top_BoothInterBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__8__KET____DOT__ai__0\n"); );
    // Init
    CData/*0:0*/ uu__DOT____VdfgTmp_hf6cd5b06__0;
    uu__DOT____VdfgTmp_hf6cd5b06__0 = 0;
    CData/*0:0*/ uu__DOT____VdfgTmp_he6224cd4__0;
    uu__DOT____VdfgTmp_he6224cd4__0 = 0;
    // Body
    uu__DOT____VdfgTmp_hf6cd5b06__0 = (IData)((0x200ULL 
                                               == (0x300ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    uu__DOT____VdfgTmp_he6224cd4__0 = (IData)((0x100ULL 
                                               == (0x300ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    vlSelf->__PVT__CarrySig[1U] = ((1U & vlSelf->__PVT__CarrySig
                                    [1U]) | (2U & (
                                                   (~ (IData)(
                                                              (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 8U))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[1U] = ((2U & vlSelf->__PVT__CarrySig
                                    [1U]) | (1U & (IData)(
                                                          (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                           << 8U))));
    vlSelf->__PVT__CarrySig[2U] = ((1U & vlSelf->__PVT__CarrySig
                                    [2U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7fffffffffffff80ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 7U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[2U] = ((2U & vlSelf->__PVT__CarrySig
                                    [2U]) | (1U & (IData)(
                                                          (0x7fffffffffffff80ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 7U)))));
    vlSelf->__PVT__CarrySig[3U] = ((1U & vlSelf->__PVT__CarrySig
                                    [3U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3fffffffffffffc0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 6U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[3U] = ((2U & vlSelf->__PVT__CarrySig
                                    [3U]) | (1U & (IData)(
                                                          (0x3fffffffffffffc0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 6U)))));
    vlSelf->__PVT__CarrySig[4U] = ((1U & vlSelf->__PVT__CarrySig
                                    [4U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1fffffffffffffe0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 5U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[4U] = ((2U & vlSelf->__PVT__CarrySig
                                    [4U]) | (1U & (IData)(
                                                          (0x1fffffffffffffe0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 5U)))));
    vlSelf->__PVT__CarrySig[5U] = ((1U & vlSelf->__PVT__CarrySig
                                    [5U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xffffffffffffff0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 4U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[5U] = ((2U & vlSelf->__PVT__CarrySig
                                    [5U]) | (1U & (IData)(
                                                          (0xffffffffffffff0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 4U)))));
    vlSelf->__PVT__CarrySig[6U] = ((1U & vlSelf->__PVT__CarrySig
                                    [6U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7fffffffffffff8ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 3U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[6U] = ((2U & vlSelf->__PVT__CarrySig
                                    [6U]) | (1U & (IData)(
                                                          (0x7fffffffffffff8ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 3U)))));
    vlSelf->__PVT__CarrySig[7U] = ((1U & vlSelf->__PVT__CarrySig
                                    [7U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3fffffffffffffcULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 2U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[7U] = ((2U & vlSelf->__PVT__CarrySig
                                    [7U]) | (1U & (IData)(
                                                          (0x3fffffffffffffcULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 2U)))));
    vlSelf->__PVT__CarrySig[8U] = ((1U & vlSelf->__PVT__CarrySig
                                    [8U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1fffffffffffffeULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 1U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[8U] = ((2U & vlSelf->__PVT__CarrySig
                                    [8U]) | (1U & (IData)(
                                                          (0x1fffffffffffffeULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 1U)))));
    vlSelf->__PVT__CarrySig[9U] = ((1U & vlSelf->__PVT__CarrySig
                                    [9U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xffffffffffffffULL 
                                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[9U] = ((2U & vlSelf->__PVT__CarrySig
                                    [9U]) | (1U & (IData)(
                                                          (0xffffffffffffffULL 
                                                           & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))));
    vlSelf->__PVT__CarrySig[0xaU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 1U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xaU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (1U 
                                                 & (IData)(
                                                           (0x7fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 1U)))));
    vlSelf->__PVT__CarrySig[0xbU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 2U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xbU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (1U 
                                                 & (IData)(
                                                           (0x3fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 2U)))));
    vlSelf->__PVT__CarrySig[0xcU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x1fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 3U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xcU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (1U 
                                                 & (IData)(
                                                           (0x1fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 3U)))));
    vlSelf->__PVT__CarrySig[0xdU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0xfffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 4U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xdU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (1U 
                                                 & (IData)(
                                                           (0xfffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 4U)))));
    vlSelf->__PVT__CarrySig[0xeU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 5U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xeU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (1U 
                                                 & (IData)(
                                                           (0x7ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 5U)))));
    vlSelf->__PVT__CarrySig[0xfU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 6U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xfU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (1U 
                                                 & (IData)(
                                                           (0x3ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 6U)))));
    vlSelf->__PVT__CarrySig[0x10U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 7U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x10U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 7U)))));
    vlSelf->__PVT__CarrySig[0x11U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 8U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x11U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 8U)))));
    vlSelf->__PVT__CarrySig[0x12U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 9U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x12U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 9U)))));
    vlSelf->__PVT__CarrySig[0x13U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xaU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x13U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xaU)))));
    vlSelf->__PVT__CarrySig[0x14U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xbU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x14U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xbU)))));
    vlSelf->__PVT__CarrySig[0x15U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xcU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x15U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xcU)))));
    vlSelf->__PVT__CarrySig[0x16U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xdU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x16U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xdU)))));
    vlSelf->__PVT__CarrySig[0x17U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xeU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x17U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xeU)))));
    vlSelf->__PVT__CarrySig[0x18U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xfU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x18U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xfU)))));
    vlSelf->__PVT__CarrySig[0x19U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x10U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x19U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x10U)))));
    vlSelf->__PVT__CarrySig[0x1aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x11U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x11U)))));
    vlSelf->__PVT__CarrySig[0x1bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x12U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x12U)))));
    vlSelf->__PVT__CarrySig[0x1cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x13U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x13U)))));
    vlSelf->__PVT__CarrySig[0x1dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x14U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x14U)))));
    vlSelf->__PVT__CarrySig[0x1eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x15U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x15U)))));
    vlSelf->__PVT__CarrySig[0x1fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x16U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x16U)))));
    vlSelf->__PVT__CarrySig[0x20U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x17U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x20U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x17U)))));
    vlSelf->__PVT__CarrySig[0x21U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x18U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x21U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x18U)))));
    vlSelf->__PVT__CarrySig[0x22U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x19U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x22U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x19U)))));
    vlSelf->__PVT__CarrySig[0x23U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x23U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1aU)))));
    vlSelf->__PVT__CarrySig[0x24U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x24U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1bU)))));
    vlSelf->__PVT__CarrySig[0x25U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x25U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1cU)))));
    vlSelf->__PVT__CarrySig[0x26U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x26U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1dU)))));
    vlSelf->__PVT__CarrySig[0x27U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x27U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1eU)))));
    vlSelf->__PVT__CarrySig[0x28U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x28U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1fU)))));
    vlSelf->__PVT__CarrySig[0x29U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x20U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x29U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x20U)))));
    vlSelf->__PVT__CarrySig[0x2aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x21U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x21U)))));
    vlSelf->__PVT__CarrySig[0x2bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x22U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x22U)))));
    vlSelf->__PVT__CarrySig[0x2cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x23U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x23U)))));
    vlSelf->__PVT__CarrySig[0x2dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x24U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x24U)))));
    vlSelf->__PVT__CarrySig[0x2eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x25U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x25U)))));
    vlSelf->__PVT__CarrySig[0x2fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x26U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x26U)))));
    vlSelf->__PVT__CarrySig[0x30U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x27U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x30U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x27U)))));
    vlSelf->__PVT__CarrySig[0x31U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x28U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x31U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (1U 
                                                   & (IData)(
                                                             (0xffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x28U)))));
    vlSelf->__PVT__CarrySig[0x32U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x29U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x32U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x29U)))));
    vlSelf->__PVT__CarrySig[0x33U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x33U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2aU)))));
    vlSelf->__PVT__CarrySig[0x34U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x34U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2bU)))));
    vlSelf->__PVT__CarrySig[0x35U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x35U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (1U 
                                                   & (IData)(
                                                             (0xfffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2cU)))));
    vlSelf->__PVT__CarrySig[0x36U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x36U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2dU)))));
    vlSelf->__PVT__CarrySig[0x37U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x37U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2eU)))));
    vlSelf->__PVT__CarrySig[0x38U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x38U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2fU)))));
    vlSelf->__PVT__CarrySig[0x39U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x30U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x39U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (1U 
                                                   & (IData)(
                                                             (0xffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x30U)))));
    vlSelf->__PVT__CarrySig[0x3aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x31U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x31U)))));
    vlSelf->__PVT__CarrySig[0x3bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x32U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x32U)))));
    vlSelf->__PVT__CarrySig[0x3cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x33U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x33U)))));
    vlSelf->__PVT__CarrySig[0x3dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x34U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (1U 
                                                   & (IData)(
                                                             (0xfULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x34U)))));
    vlSelf->__PVT__CarrySig[0x3eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (7ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x35U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (1U 
                                                   & (IData)(
                                                             (7ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x35U)))));
    vlSelf->__PVT__CarrySig[0x3fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (3ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x36U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (1U 
                                                   & (IData)(
                                                             (3ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x36U)))));
    vlSelf->__PVT__CarrySig[0x40U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (1ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x37U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x40U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (1U 
                                                   & (IData)(
                                                             (1ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x37U)))));
    vlSelf->__PVT__neg2x = ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                        >> 7U))) & (IData)(uu__DOT____VdfgTmp_hf6cd5b06__0));
    vlSelf->__PVT__negx = (1U & ((IData)((0x300ULL 
                                          == (0x380ULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                                 | ((IData)(uu__DOT____VdfgTmp_hf6cd5b06__0) 
                                    & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 7U)))));
    vlSelf->__PVT__x = (1U & ((IData)((0x80ULL == (0x380ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                              | ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                             >> 7U))) 
                                 & (IData)(uu__DOT____VdfgTmp_he6224cd4__0))));
    vlSelf->__PVT___2x = ((IData)(uu__DOT____VdfgTmp_he6224cd4__0) 
                          & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                     >> 7U)));
    vlSelf->__PVT__OutX = (((QData)((IData)((((~ (IData)(
                                                         (1ULL 
                                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                             >> 0x37U)))) 
                                              & (IData)(vlSelf->__PVT__negx)) 
                                             | ((IData)(
                                                        ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                          >> 0x37U) 
                                                         & (IData)(vlSelf->__PVT__x))) 
                                                | (((vlSelf->__PVT__CarrySig
                                                     [0x3fU] 
                                                     >> 1U) 
                                                    & (IData)(vlSelf->__PVT__neg2x)) 
                                                   | (vlSelf->__PVT__CarrySig
                                                      [0x3fU] 
                                                      & (IData)(vlSelf->__PVT___2x))))))) 
                            << 0x3fU) | (((QData)((IData)(
                                                          (((~ (IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x36U)))) 
                                                            & (IData)(vlSelf->__PVT__negx)) 
                                                           | (((IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x36U))) 
                                                               & (IData)(vlSelf->__PVT__x)) 
                                                              | (((vlSelf->__PVT__CarrySig
                                                                   [0x3eU] 
                                                                   >> 1U) 
                                                                  & (IData)(vlSelf->__PVT__neg2x)) 
                                                                 | (vlSelf->__PVT__CarrySig
                                                                    [0x3eU] 
                                                                    & (IData)(vlSelf->__PVT___2x))))))) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             (((~ (IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x35U)))) 
                                                               & (IData)(vlSelf->__PVT__negx)) 
                                                              | (((IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x35U))) 
                                                                  & (IData)(vlSelf->__PVT__x)) 
                                                                 | (((vlSelf->__PVT__CarrySig
                                                                      [0x3dU] 
                                                                      >> 1U) 
                                                                     & (IData)(vlSelf->__PVT__neg2x)) 
                                                                    | (vlSelf->__PVT__CarrySig
                                                                       [0x3dU] 
                                                                       & (IData)(vlSelf->__PVT___2x))))))) 
                                             << 0x3dU) 
                                            | (((QData)((IData)(
                                                                (((~ (IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x34U)))) 
                                                                  & (IData)(vlSelf->__PVT__negx)) 
                                                                 | (((IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x34U))) 
                                                                     & (IData)(vlSelf->__PVT__x)) 
                                                                    | (((vlSelf->__PVT__CarrySig
                                                                         [0x3cU] 
                                                                         >> 1U) 
                                                                        & (IData)(vlSelf->__PVT__neg2x)) 
                                                                       | (vlSelf->__PVT__CarrySig
                                                                          [0x3cU] 
                                                                          & (IData)(vlSelf->__PVT___2x))))))) 
                                                << 0x3cU) 
                                               | (((QData)((IData)(
                                                                   (((~ (IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x33U)))) 
                                                                     & (IData)(vlSelf->__PVT__negx)) 
                                                                    | (((IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x33U))) 
                                                                        & (IData)(vlSelf->__PVT__x)) 
                                                                       | (((vlSelf->__PVT__CarrySig
                                                                            [0x3bU] 
                                                                            >> 1U) 
                                                                           & (IData)(vlSelf->__PVT__neg2x)) 
                                                                          | (vlSelf->__PVT__CarrySig
                                                                             [0x3bU] 
                                                                             & (IData)(vlSelf->__PVT___2x))))))) 
                                                   << 0x3bU) 
                                                  | (((QData)((IData)(
                                                                      (((~ (IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x32U)))) 
                                                                        & (IData)(vlSelf->__PVT__negx)) 
                                                                       | (((IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x32U))) 
                                                                           & (IData)(vlSelf->__PVT__x)) 
                                                                          | (((vlSelf->__PVT__CarrySig
                                                                               [0x3aU] 
                                                                               >> 1U) 
                                                                              & (IData)(vlSelf->__PVT__neg2x)) 
                                                                             | (vlSelf->__PVT__CarrySig
                                                                                [0x3aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                      << 0x3aU) 
                                                     | (((QData)((IData)(
                                                                         (((~ (IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x31U)))) 
                                                                           & (IData)(vlSelf->__PVT__negx)) 
                                                                          | (((IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x31U))) 
                                                                              & (IData)(vlSelf->__PVT__x)) 
                                                                             | (((vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                         << 0x39U) 
                                                        | (((QData)((IData)(
                                                                            (((~ (IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U)))) 
                                                                              & (IData)(vlSelf->__PVT__negx)) 
                                                                             | (((IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                            << 0x38U) 
                                                           | (((QData)((IData)(
                                                                               (((~ (IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                               << 0x37U) 
                                                              | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                  << 0x36U) 
                                                                 | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                     << 0x35U) 
                                                                    | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                        << 0x34U) 
                                                                       | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                           << 0x33U) 
                                                                          | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                              << 0x32U) 
                                                                             | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((((~ (IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1fU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1fU) 
                                                                                | ((0x80000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                << 0x1eU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1fU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1fU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1eU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1eU) 
                                                                                | ((0xc0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                << 0x1dU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1eU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1eU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1dU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1dU) 
                                                                                | ((0xe0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                << 0x1cU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1dU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1dU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1cU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1cU) 
                                                                                | ((0xf0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                << 0x1bU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1cU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1cU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1bU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1bU) 
                                                                                | ((0xf8000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                << 0x1aU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1bU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1bU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1aU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1aU) 
                                                                                | ((0xfc000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                << 0x19U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1aU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1aU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x19U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x19U) 
                                                                                | ((0xfe000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                << 0x18U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x19U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x19U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x18U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x18U) 
                                                                                | ((0xff000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                << 0x17U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x18U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x18U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x17U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x17U) 
                                                                                | ((0xff800000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                << 0x16U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x17U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x17U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x16U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x16U) 
                                                                                | ((0xffc00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                << 0x15U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x16U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x16U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x15U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x15U) 
                                                                                | ((0xffe00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                << 0x14U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x15U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x15U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x14U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x14U) 
                                                                                | ((0xfff00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                << 0x13U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x14U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x14U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x13U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x13U) 
                                                                                | ((0xfff80000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                << 0x12U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x13U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x13U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x12U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x12U) 
                                                                                | ((0xfffc0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                << 0x11U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x12U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x12U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x11U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x11U) 
                                                                                | ((0xfffe0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                << 0x10U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x11U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x11U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x10U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x10U) 
                                                                                | ((0xffff0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                << 0xfU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x10U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x10U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xfU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xfU) 
                                                                                | ((0xffff8000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                << 0xeU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xfU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xfU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xeU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xeU) 
                                                                                | ((0xffffc000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                << 0xdU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xeU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xeU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xdU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xdU) 
                                                                                | ((0xffffe000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                << 0xcU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xdU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xdU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xcU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xcU) 
                                                                                | ((0xfffff000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                << 0xbU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xcU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xcU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xbU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xbU) 
                                                                                | ((0xfffff800U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                << 0xaU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xbU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xbU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xaU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xaU) 
                                                                                | ((0xfffffc00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                << 9U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xaU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xaU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 9U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 9U) 
                                                                                | ((0xfffffe00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                << 8U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 9U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 9U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 8U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 8U) 
                                                                                | ((0xffffff00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                << 7U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 8U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 8U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 7U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 7U) 
                                                                                | ((0xffffff80U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                << 6U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 7U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 7U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 6U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 6U) 
                                                                                | ((0xffffffc0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                << 5U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 6U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 6U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 5U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 5U) 
                                                                                | ((0xffffffe0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                << 4U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 5U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 5U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 4U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 4U) 
                                                                                | ((0xfffffff0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                << 3U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 4U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 4U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 3U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 3U) 
                                                                                | ((0xfffffff8U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                << 2U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 3U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 3U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffffc0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 2U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffffc0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 2U) 
                                                                                | ((0xfffffffcU 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                << 1U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 2U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 2U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffff80ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 1U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffff80ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 1U) 
                                                                                | ((0xfffffffeU 
                                                                                & (vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 1U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 1U)))) 
                                                                                | (((~ (IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 8U))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 8U)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (IData)(vlSelf->__PVT__neg2x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__10__KET____DOT__ai__0(Vverilator_top_BoothInterBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__10__KET____DOT__ai__0\n"); );
    // Init
    CData/*0:0*/ uu__DOT____VdfgTmp_hf6cd5b06__0;
    uu__DOT____VdfgTmp_hf6cd5b06__0 = 0;
    CData/*0:0*/ uu__DOT____VdfgTmp_he6224cd4__0;
    uu__DOT____VdfgTmp_he6224cd4__0 = 0;
    // Body
    uu__DOT____VdfgTmp_hf6cd5b06__0 = (IData)((0x800ULL 
                                               == (0xc00ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    uu__DOT____VdfgTmp_he6224cd4__0 = (IData)((0x400ULL 
                                               == (0xc00ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    vlSelf->__PVT__CarrySig[1U] = ((1U & vlSelf->__PVT__CarrySig
                                    [1U]) | (2U & (
                                                   (~ (IData)(
                                                              (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 0xaU))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[1U] = ((2U & vlSelf->__PVT__CarrySig
                                    [1U]) | (1U & (IData)(
                                                          (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                           << 0xaU))));
    vlSelf->__PVT__CarrySig[2U] = ((1U & vlSelf->__PVT__CarrySig
                                    [2U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7ffffffffffffe00ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 9U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[2U] = ((2U & vlSelf->__PVT__CarrySig
                                    [2U]) | (1U & (IData)(
                                                          (0x7ffffffffffffe00ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 9U)))));
    vlSelf->__PVT__CarrySig[3U] = ((1U & vlSelf->__PVT__CarrySig
                                    [3U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3fffffffffffff00ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 8U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[3U] = ((2U & vlSelf->__PVT__CarrySig
                                    [3U]) | (1U & (IData)(
                                                          (0x3fffffffffffff00ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 8U)))));
    vlSelf->__PVT__CarrySig[4U] = ((1U & vlSelf->__PVT__CarrySig
                                    [4U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1fffffffffffff80ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 7U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[4U] = ((2U & vlSelf->__PVT__CarrySig
                                    [4U]) | (1U & (IData)(
                                                          (0x1fffffffffffff80ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 7U)))));
    vlSelf->__PVT__CarrySig[5U] = ((1U & vlSelf->__PVT__CarrySig
                                    [5U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xfffffffffffffc0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 6U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[5U] = ((2U & vlSelf->__PVT__CarrySig
                                    [5U]) | (1U & (IData)(
                                                          (0xfffffffffffffc0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 6U)))));
    vlSelf->__PVT__CarrySig[6U] = ((1U & vlSelf->__PVT__CarrySig
                                    [6U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7ffffffffffffe0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 5U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[6U] = ((2U & vlSelf->__PVT__CarrySig
                                    [6U]) | (1U & (IData)(
                                                          (0x7ffffffffffffe0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 5U)))));
    vlSelf->__PVT__CarrySig[7U] = ((1U & vlSelf->__PVT__CarrySig
                                    [7U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3fffffffffffff0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 4U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[7U] = ((2U & vlSelf->__PVT__CarrySig
                                    [7U]) | (1U & (IData)(
                                                          (0x3fffffffffffff0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 4U)))));
    vlSelf->__PVT__CarrySig[8U] = ((1U & vlSelf->__PVT__CarrySig
                                    [8U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1fffffffffffff8ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 3U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[8U] = ((2U & vlSelf->__PVT__CarrySig
                                    [8U]) | (1U & (IData)(
                                                          (0x1fffffffffffff8ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 3U)))));
    vlSelf->__PVT__CarrySig[9U] = ((1U & vlSelf->__PVT__CarrySig
                                    [9U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xfffffffffffffcULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 2U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[9U] = ((2U & vlSelf->__PVT__CarrySig
                                    [9U]) | (1U & (IData)(
                                                          (0xfffffffffffffcULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 2U)))));
    vlSelf->__PVT__CarrySig[0xaU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7ffffffffffffeULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   << 1U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xaU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (1U 
                                                 & (IData)(
                                                           (0x7ffffffffffffeULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 1U)))));
    vlSelf->__PVT__CarrySig[0xbU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3fffffffffffffULL 
                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xbU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (1U 
                                                 & (IData)(
                                                           (0x3fffffffffffffULL 
                                                            & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))));
    vlSelf->__PVT__CarrySig[0xcU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x1fffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 1U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xcU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (1U 
                                                 & (IData)(
                                                           (0x1fffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 1U)))));
    vlSelf->__PVT__CarrySig[0xdU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0xfffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 2U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xdU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (1U 
                                                 & (IData)(
                                                           (0xfffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 2U)))));
    vlSelf->__PVT__CarrySig[0xeU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 3U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xeU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (1U 
                                                 & (IData)(
                                                           (0x7ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 3U)))));
    vlSelf->__PVT__CarrySig[0xfU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 4U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xfU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (1U 
                                                 & (IData)(
                                                           (0x3ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 4U)))));
    vlSelf->__PVT__CarrySig[0x10U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 5U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x10U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 5U)))));
    vlSelf->__PVT__CarrySig[0x11U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 6U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x11U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 6U)))));
    vlSelf->__PVT__CarrySig[0x12U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 7U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x12U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 7U)))));
    vlSelf->__PVT__CarrySig[0x13U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 8U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x13U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 8U)))));
    vlSelf->__PVT__CarrySig[0x14U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 9U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x14U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 9U)))));
    vlSelf->__PVT__CarrySig[0x15U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xaU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x15U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xaU)))));
    vlSelf->__PVT__CarrySig[0x16U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xbU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x16U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xbU)))));
    vlSelf->__PVT__CarrySig[0x17U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xcU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x17U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xcU)))));
    vlSelf->__PVT__CarrySig[0x18U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xdU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x18U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xdU)))));
    vlSelf->__PVT__CarrySig[0x19U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xeU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x19U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xeU)))));
    vlSelf->__PVT__CarrySig[0x1aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xfU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xfU)))));
    vlSelf->__PVT__CarrySig[0x1bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x10U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x10U)))));
    vlSelf->__PVT__CarrySig[0x1cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x11U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x11U)))));
    vlSelf->__PVT__CarrySig[0x1dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x12U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x12U)))));
    vlSelf->__PVT__CarrySig[0x1eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x13U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x13U)))));
    vlSelf->__PVT__CarrySig[0x1fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x14U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x14U)))));
    vlSelf->__PVT__CarrySig[0x20U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x15U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x20U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x15U)))));
    vlSelf->__PVT__CarrySig[0x21U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x16U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x21U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x16U)))));
    vlSelf->__PVT__CarrySig[0x22U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x17U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x22U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x17U)))));
    vlSelf->__PVT__CarrySig[0x23U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x18U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x23U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x18U)))));
    vlSelf->__PVT__CarrySig[0x24U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x19U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x24U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x19U)))));
    vlSelf->__PVT__CarrySig[0x25U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x25U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1aU)))));
    vlSelf->__PVT__CarrySig[0x26U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x26U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1bU)))));
    vlSelf->__PVT__CarrySig[0x27U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x27U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1cU)))));
    vlSelf->__PVT__CarrySig[0x28U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x28U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1dU)))));
    vlSelf->__PVT__CarrySig[0x29U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x29U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1eU)))));
    vlSelf->__PVT__CarrySig[0x2aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1fU)))));
    vlSelf->__PVT__CarrySig[0x2bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x20U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x20U)))));
    vlSelf->__PVT__CarrySig[0x2cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x21U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x21U)))));
    vlSelf->__PVT__CarrySig[0x2dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x22U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x22U)))));
    vlSelf->__PVT__CarrySig[0x2eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x23U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x23U)))));
    vlSelf->__PVT__CarrySig[0x2fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x24U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x24U)))));
    vlSelf->__PVT__CarrySig[0x30U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x25U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x30U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x25U)))));
    vlSelf->__PVT__CarrySig[0x31U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x26U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x31U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (1U 
                                                   & (IData)(
                                                             (0xffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x26U)))));
    vlSelf->__PVT__CarrySig[0x32U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x27U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x32U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x27U)))));
    vlSelf->__PVT__CarrySig[0x33U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x28U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x33U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x28U)))));
    vlSelf->__PVT__CarrySig[0x34U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x29U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x34U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x29U)))));
    vlSelf->__PVT__CarrySig[0x35U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x35U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (1U 
                                                   & (IData)(
                                                             (0xfffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2aU)))));
    vlSelf->__PVT__CarrySig[0x36U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x36U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2bU)))));
    vlSelf->__PVT__CarrySig[0x37U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x37U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2cU)))));
    vlSelf->__PVT__CarrySig[0x38U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x38U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2dU)))));
    vlSelf->__PVT__CarrySig[0x39U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x39U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (1U 
                                                   & (IData)(
                                                             (0xffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2eU)))));
    vlSelf->__PVT__CarrySig[0x3aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2fU)))));
    vlSelf->__PVT__CarrySig[0x3bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x30U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x30U)))));
    vlSelf->__PVT__CarrySig[0x3cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x31U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x31U)))));
    vlSelf->__PVT__CarrySig[0x3dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x32U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (1U 
                                                   & (IData)(
                                                             (0xfULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x32U)))));
    vlSelf->__PVT__CarrySig[0x3eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (7ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x33U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (1U 
                                                   & (IData)(
                                                             (7ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x33U)))));
    vlSelf->__PVT__CarrySig[0x3fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (3ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x34U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (1U 
                                                   & (IData)(
                                                             (3ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x34U)))));
    vlSelf->__PVT__CarrySig[0x40U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (1ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x35U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x40U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (1U 
                                                   & (IData)(
                                                             (1ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x35U)))));
    vlSelf->__PVT__neg2x = ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                        >> 9U))) & (IData)(uu__DOT____VdfgTmp_hf6cd5b06__0));
    vlSelf->__PVT__negx = (1U & ((IData)((0xc00ULL 
                                          == (0xe00ULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                                 | ((IData)(uu__DOT____VdfgTmp_hf6cd5b06__0) 
                                    & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 9U)))));
    vlSelf->__PVT__x = (1U & ((IData)((0x200ULL == 
                                       (0xe00ULL & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                              | ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                             >> 9U))) 
                                 & (IData)(uu__DOT____VdfgTmp_he6224cd4__0))));
    vlSelf->__PVT___2x = ((IData)(uu__DOT____VdfgTmp_he6224cd4__0) 
                          & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                     >> 9U)));
    vlSelf->__PVT__OutX = (((QData)((IData)((((~ (IData)(
                                                         (1ULL 
                                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                             >> 0x35U)))) 
                                              & (IData)(vlSelf->__PVT__negx)) 
                                             | ((IData)(
                                                        ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                          >> 0x35U) 
                                                         & (IData)(vlSelf->__PVT__x))) 
                                                | (((vlSelf->__PVT__CarrySig
                                                     [0x3fU] 
                                                     >> 1U) 
                                                    & (IData)(vlSelf->__PVT__neg2x)) 
                                                   | (vlSelf->__PVT__CarrySig
                                                      [0x3fU] 
                                                      & (IData)(vlSelf->__PVT___2x))))))) 
                            << 0x3fU) | (((QData)((IData)(
                                                          (((~ (IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x34U)))) 
                                                            & (IData)(vlSelf->__PVT__negx)) 
                                                           | (((IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x34U))) 
                                                               & (IData)(vlSelf->__PVT__x)) 
                                                              | (((vlSelf->__PVT__CarrySig
                                                                   [0x3eU] 
                                                                   >> 1U) 
                                                                  & (IData)(vlSelf->__PVT__neg2x)) 
                                                                 | (vlSelf->__PVT__CarrySig
                                                                    [0x3eU] 
                                                                    & (IData)(vlSelf->__PVT___2x))))))) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             (((~ (IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x33U)))) 
                                                               & (IData)(vlSelf->__PVT__negx)) 
                                                              | (((IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x33U))) 
                                                                  & (IData)(vlSelf->__PVT__x)) 
                                                                 | (((vlSelf->__PVT__CarrySig
                                                                      [0x3dU] 
                                                                      >> 1U) 
                                                                     & (IData)(vlSelf->__PVT__neg2x)) 
                                                                    | (vlSelf->__PVT__CarrySig
                                                                       [0x3dU] 
                                                                       & (IData)(vlSelf->__PVT___2x))))))) 
                                             << 0x3dU) 
                                            | (((QData)((IData)(
                                                                (((~ (IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x32U)))) 
                                                                  & (IData)(vlSelf->__PVT__negx)) 
                                                                 | (((IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x32U))) 
                                                                     & (IData)(vlSelf->__PVT__x)) 
                                                                    | (((vlSelf->__PVT__CarrySig
                                                                         [0x3cU] 
                                                                         >> 1U) 
                                                                        & (IData)(vlSelf->__PVT__neg2x)) 
                                                                       | (vlSelf->__PVT__CarrySig
                                                                          [0x3cU] 
                                                                          & (IData)(vlSelf->__PVT___2x))))))) 
                                                << 0x3cU) 
                                               | (((QData)((IData)(
                                                                   (((~ (IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x31U)))) 
                                                                     & (IData)(vlSelf->__PVT__negx)) 
                                                                    | (((IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x31U))) 
                                                                        & (IData)(vlSelf->__PVT__x)) 
                                                                       | (((vlSelf->__PVT__CarrySig
                                                                            [0x3bU] 
                                                                            >> 1U) 
                                                                           & (IData)(vlSelf->__PVT__neg2x)) 
                                                                          | (vlSelf->__PVT__CarrySig
                                                                             [0x3bU] 
                                                                             & (IData)(vlSelf->__PVT___2x))))))) 
                                                   << 0x3bU) 
                                                  | (((QData)((IData)(
                                                                      (((~ (IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U)))) 
                                                                        & (IData)(vlSelf->__PVT__negx)) 
                                                                       | (((IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U))) 
                                                                           & (IData)(vlSelf->__PVT__x)) 
                                                                          | (((vlSelf->__PVT__CarrySig
                                                                               [0x3aU] 
                                                                               >> 1U) 
                                                                              & (IData)(vlSelf->__PVT__neg2x)) 
                                                                             | (vlSelf->__PVT__CarrySig
                                                                                [0x3aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                      << 0x3aU) 
                                                     | (((QData)((IData)(
                                                                         (((~ (IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU)))) 
                                                                           & (IData)(vlSelf->__PVT__negx)) 
                                                                          | (((IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU))) 
                                                                              & (IData)(vlSelf->__PVT__x)) 
                                                                             | (((vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                         << 0x39U) 
                                                        | (((QData)((IData)(
                                                                            (((~ (IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU)))) 
                                                                              & (IData)(vlSelf->__PVT__negx)) 
                                                                             | (((IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                            << 0x38U) 
                                                           | (((QData)((IData)(
                                                                               (((~ (IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                               << 0x37U) 
                                                              | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                  << 0x36U) 
                                                                 | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                     << 0x35U) 
                                                                    | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                        << 0x34U) 
                                                                       | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                           << 0x33U) 
                                                                          | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                              << 0x32U) 
                                                                             | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((((~ (IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1fU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1fU) 
                                                                                | ((0x80000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                << 0x1eU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1fU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1fU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1eU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1eU) 
                                                                                | ((0xc0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                << 0x1dU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1eU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1eU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1dU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1dU) 
                                                                                | ((0xe0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                << 0x1cU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1dU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1dU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1cU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1cU) 
                                                                                | ((0xf0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                << 0x1bU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1cU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1cU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1bU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1bU) 
                                                                                | ((0xf8000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                << 0x1aU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1bU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1bU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1aU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1aU) 
                                                                                | ((0xfc000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                << 0x19U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1aU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1aU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x19U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x19U) 
                                                                                | ((0xfe000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                << 0x18U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x19U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x19U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x18U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x18U) 
                                                                                | ((0xff000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                << 0x17U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x18U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x18U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x17U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x17U) 
                                                                                | ((0xff800000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                << 0x16U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x17U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x17U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x16U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x16U) 
                                                                                | ((0xffc00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                << 0x15U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x16U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x16U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x15U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x15U) 
                                                                                | ((0xffe00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                << 0x14U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x15U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x15U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x14U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x14U) 
                                                                                | ((0xfff00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                << 0x13U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x14U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x14U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x13U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x13U) 
                                                                                | ((0xfff80000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                << 0x12U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x13U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x13U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x12U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x12U) 
                                                                                | ((0xfffc0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                << 0x11U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x12U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x12U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x11U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x11U) 
                                                                                | ((0xfffe0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                << 0x10U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x11U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x11U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x10U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x10U) 
                                                                                | ((0xffff0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                << 0xfU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x10U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x10U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xfU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xfU) 
                                                                                | ((0xffff8000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                << 0xeU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xfU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xfU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xeU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xeU) 
                                                                                | ((0xffffc000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                << 0xdU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xeU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xeU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xdU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xdU) 
                                                                                | ((0xffffe000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                << 0xcU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xdU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xdU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xcU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xcU) 
                                                                                | ((0xfffff000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                << 0xbU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xcU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xcU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xbU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xbU) 
                                                                                | ((0xfffff800U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                << 0xaU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xbU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xbU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xaU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xaU) 
                                                                                | ((0xfffffc00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                << 9U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xaU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xaU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 9U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 9U) 
                                                                                | ((0xfffffe00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                << 8U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 9U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 9U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 8U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 8U) 
                                                                                | ((0xffffff00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                << 7U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 8U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 8U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 7U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 7U) 
                                                                                | ((0xffffff80U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                << 6U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 7U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 7U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 6U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 6U) 
                                                                                | ((0xffffffc0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                << 5U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 6U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 6U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 5U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 5U) 
                                                                                | ((0xffffffe0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                << 4U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 5U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 5U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffffc0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 4U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffffc0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 4U) 
                                                                                | ((0xfffffff0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                << 3U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 4U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 4U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffff80ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 3U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffff80ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 3U) 
                                                                                | ((0xfffffff8U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                << 2U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 3U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 3U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffff00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 8U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 2U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffff00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 8U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 2U) 
                                                                                | ((0xfffffffcU 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                << 1U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 2U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 2U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffe00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 9U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 1U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffe00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 9U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 1U) 
                                                                                | ((0xfffffffeU 
                                                                                & (vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 1U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 1U)))) 
                                                                                | (((~ (IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xaU))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xaU)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (IData)(vlSelf->__PVT__neg2x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__12__KET____DOT__ai__0(Vverilator_top_BoothInterBase* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vverilator_top_BoothInterBase___nba_sequent__TOP__verilator_top__cpu__DOT__u_mul__DOT__boothfor__BRA__12__KET____DOT__ai__0\n"); );
    // Init
    CData/*0:0*/ uu__DOT____VdfgTmp_hf6cd5b06__0;
    uu__DOT____VdfgTmp_hf6cd5b06__0 = 0;
    CData/*0:0*/ uu__DOT____VdfgTmp_he6224cd4__0;
    uu__DOT____VdfgTmp_he6224cd4__0 = 0;
    // Body
    uu__DOT____VdfgTmp_hf6cd5b06__0 = (IData)((0x2000ULL 
                                               == (0x3000ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    uu__DOT____VdfgTmp_he6224cd4__0 = (IData)((0x1000ULL 
                                               == (0x3000ULL 
                                                   & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY)));
    vlSelf->__PVT__CarrySig[1U] = ((1U & vlSelf->__PVT__CarrySig
                                    [1U]) | (2U & (
                                                   (~ (IData)(
                                                              (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 0xcU))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[1U] = ((2U & vlSelf->__PVT__CarrySig
                                    [1U]) | (1U & (IData)(
                                                          (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                           << 0xcU))));
    vlSelf->__PVT__CarrySig[2U] = ((1U & vlSelf->__PVT__CarrySig
                                    [2U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7ffffffffffff800ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 0xbU)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[2U] = ((2U & vlSelf->__PVT__CarrySig
                                    [2U]) | (1U & (IData)(
                                                          (0x7ffffffffffff800ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 0xbU)))));
    vlSelf->__PVT__CarrySig[3U] = ((1U & vlSelf->__PVT__CarrySig
                                    [3U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3ffffffffffffc00ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 0xaU)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[3U] = ((2U & vlSelf->__PVT__CarrySig
                                    [3U]) | (1U & (IData)(
                                                          (0x3ffffffffffffc00ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 0xaU)))));
    vlSelf->__PVT__CarrySig[4U] = ((1U & vlSelf->__PVT__CarrySig
                                    [4U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1ffffffffffffe00ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 9U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[4U] = ((2U & vlSelf->__PVT__CarrySig
                                    [4U]) | (1U & (IData)(
                                                          (0x1ffffffffffffe00ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 9U)))));
    vlSelf->__PVT__CarrySig[5U] = ((1U & vlSelf->__PVT__CarrySig
                                    [5U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xfffffffffffff00ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 8U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[5U] = ((2U & vlSelf->__PVT__CarrySig
                                    [5U]) | (1U & (IData)(
                                                          (0xfffffffffffff00ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 8U)))));
    vlSelf->__PVT__CarrySig[6U] = ((1U & vlSelf->__PVT__CarrySig
                                    [6U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x7ffffffffffff80ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 7U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[6U] = ((2U & vlSelf->__PVT__CarrySig
                                    [6U]) | (1U & (IData)(
                                                          (0x7ffffffffffff80ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 7U)))));
    vlSelf->__PVT__CarrySig[7U] = ((1U & vlSelf->__PVT__CarrySig
                                    [7U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x3ffffffffffffc0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 6U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[7U] = ((2U & vlSelf->__PVT__CarrySig
                                    [7U]) | (1U & (IData)(
                                                          (0x3ffffffffffffc0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 6U)))));
    vlSelf->__PVT__CarrySig[8U] = ((1U & vlSelf->__PVT__CarrySig
                                    [8U]) | (2U & (
                                                   (~ (IData)(
                                                              (0x1ffffffffffffe0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 5U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[8U] = ((2U & vlSelf->__PVT__CarrySig
                                    [8U]) | (1U & (IData)(
                                                          (0x1ffffffffffffe0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 5U)))));
    vlSelf->__PVT__CarrySig[9U] = ((1U & vlSelf->__PVT__CarrySig
                                    [9U]) | (2U & (
                                                   (~ (IData)(
                                                              (0xfffffffffffff0ULL 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                  << 4U)))) 
                                                   << 1U)));
    vlSelf->__PVT__CarrySig[9U] = ((2U & vlSelf->__PVT__CarrySig
                                    [9U]) | (1U & (IData)(
                                                          (0xfffffffffffff0ULL 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                              << 4U)))));
    vlSelf->__PVT__CarrySig[0xaU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7ffffffffffff8ULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   << 3U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xaU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xaU]) | (1U 
                                                 & (IData)(
                                                           (0x7ffffffffffff8ULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 3U)))));
    vlSelf->__PVT__CarrySig[0xbU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3ffffffffffffcULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   << 2U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xbU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xbU]) | (1U 
                                                 & (IData)(
                                                           (0x3ffffffffffffcULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 2U)))));
    vlSelf->__PVT__CarrySig[0xcU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x1ffffffffffffeULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   << 1U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xcU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xcU]) | (1U 
                                                 & (IData)(
                                                           (0x1ffffffffffffeULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               << 1U)))));
    vlSelf->__PVT__CarrySig[0xdU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0xfffffffffffffULL 
                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xdU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xdU]) | (1U 
                                                 & (IData)(
                                                           (0xfffffffffffffULL 
                                                            & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))));
    vlSelf->__PVT__CarrySig[0xeU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x7ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 1U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xeU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xeU]) | (1U 
                                                 & (IData)(
                                                           (0x7ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 1U)))));
    vlSelf->__PVT__CarrySig[0xfU] = ((1U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (2U 
                                                 & ((~ (IData)(
                                                               (0x3ffffffffffffULL 
                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                   >> 2U)))) 
                                                    << 1U)));
    vlSelf->__PVT__CarrySig[0xfU] = ((2U & vlSelf->__PVT__CarrySig
                                      [0xfU]) | (1U 
                                                 & (IData)(
                                                           (0x3ffffffffffffULL 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                               >> 2U)))));
    vlSelf->__PVT__CarrySig[0x10U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 3U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x10U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x10U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 3U)))));
    vlSelf->__PVT__CarrySig[0x11U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 4U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x11U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x11U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 4U)))));
    vlSelf->__PVT__CarrySig[0x12U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 5U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x12U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x12U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 5U)))));
    vlSelf->__PVT__CarrySig[0x13U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 6U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x13U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x13U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 6U)))));
    vlSelf->__PVT__CarrySig[0x14U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 7U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x14U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x14U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 7U)))));
    vlSelf->__PVT__CarrySig[0x15U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 8U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x15U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x15U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 8U)))));
    vlSelf->__PVT__CarrySig[0x16U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 9U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x16U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x16U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 9U)))));
    vlSelf->__PVT__CarrySig[0x17U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xaU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x17U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x17U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xaU)))));
    vlSelf->__PVT__CarrySig[0x18U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xbU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x18U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x18U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xbU)))));
    vlSelf->__PVT__CarrySig[0x19U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xcU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x19U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x19U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xcU)))));
    vlSelf->__PVT__CarrySig[0x1aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xdU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xdU)))));
    vlSelf->__PVT__CarrySig[0x1bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xeU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xeU)))));
    vlSelf->__PVT__CarrySig[0x1cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0xfU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0xfU)))));
    vlSelf->__PVT__CarrySig[0x1dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x10U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x10U)))));
    vlSelf->__PVT__CarrySig[0x1eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x11U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x11U)))));
    vlSelf->__PVT__CarrySig[0x1fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x12U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x1fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x1fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x12U)))));
    vlSelf->__PVT__CarrySig[0x20U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x13U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x20U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x20U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x13U)))));
    vlSelf->__PVT__CarrySig[0x21U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x14U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x21U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x21U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x14U)))));
    vlSelf->__PVT__CarrySig[0x22U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x15U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x22U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x22U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x15U)))));
    vlSelf->__PVT__CarrySig[0x23U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x16U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x23U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x23U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x16U)))));
    vlSelf->__PVT__CarrySig[0x24U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x17U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x24U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x24U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x17U)))));
    vlSelf->__PVT__CarrySig[0x25U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x18U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x25U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x25U]) | (1U 
                                                   & (IData)(
                                                             (0xfffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x18U)))));
    vlSelf->__PVT__CarrySig[0x26U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x19U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x26U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x26U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x19U)))));
    vlSelf->__PVT__CarrySig[0x27U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x27U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x27U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1aU)))));
    vlSelf->__PVT__CarrySig[0x28U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x28U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x28U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1bU)))));
    vlSelf->__PVT__CarrySig[0x29U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x29U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x29U]) | (1U 
                                                   & (IData)(
                                                             (0xffffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1cU)))));
    vlSelf->__PVT__CarrySig[0x2aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1dU)))));
    vlSelf->__PVT__CarrySig[0x2bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1eU)))));
    vlSelf->__PVT__CarrySig[0x2cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x1fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x1fU)))));
    vlSelf->__PVT__CarrySig[0x2dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x20U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2dU]) | (1U 
                                                   & (IData)(
                                                             (0xfffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x20U)))));
    vlSelf->__PVT__CarrySig[0x2eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x21U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2eU]) | (1U 
                                                   & (IData)(
                                                             (0x7ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x21U)))));
    vlSelf->__PVT__CarrySig[0x2fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x22U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x2fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x2fU]) | (1U 
                                                   & (IData)(
                                                             (0x3ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x22U)))));
    vlSelf->__PVT__CarrySig[0x30U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x23U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x30U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x30U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x23U)))));
    vlSelf->__PVT__CarrySig[0x31U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x24U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x31U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x31U]) | (1U 
                                                   & (IData)(
                                                             (0xffffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x24U)))));
    vlSelf->__PVT__CarrySig[0x32U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x25U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x32U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x32U]) | (1U 
                                                   & (IData)(
                                                             (0x7fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x25U)))));
    vlSelf->__PVT__CarrySig[0x33U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x26U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x33U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x33U]) | (1U 
                                                   & (IData)(
                                                             (0x3fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x26U)))));
    vlSelf->__PVT__CarrySig[0x34U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x27U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x34U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x34U]) | (1U 
                                                   & (IData)(
                                                             (0x1fffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x27U)))));
    vlSelf->__PVT__CarrySig[0x35U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x28U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x35U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x35U]) | (1U 
                                                   & (IData)(
                                                             (0xfffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x28U)))));
    vlSelf->__PVT__CarrySig[0x36U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x29U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x36U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x36U]) | (1U 
                                                   & (IData)(
                                                             (0x7ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x29U)))));
    vlSelf->__PVT__CarrySig[0x37U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2aU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x37U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x37U]) | (1U 
                                                   & (IData)(
                                                             (0x3ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2aU)))));
    vlSelf->__PVT__CarrySig[0x38U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1ffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2bU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x38U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x38U]) | (1U 
                                                   & (IData)(
                                                             (0x1ffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2bU)))));
    vlSelf->__PVT__CarrySig[0x39U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xffULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2cU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x39U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x39U]) | (1U 
                                                   & (IData)(
                                                             (0xffULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2cU)))));
    vlSelf->__PVT__CarrySig[0x3aU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x7fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2dU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3aU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3aU]) | (1U 
                                                   & (IData)(
                                                             (0x7fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2dU)))));
    vlSelf->__PVT__CarrySig[0x3bU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x3fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2eU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3bU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3bU]) | (1U 
                                                   & (IData)(
                                                             (0x3fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2eU)))));
    vlSelf->__PVT__CarrySig[0x3cU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0x1fULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x2fU)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3cU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3cU]) | (1U 
                                                   & (IData)(
                                                             (0x1fULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x2fU)))));
    vlSelf->__PVT__CarrySig[0x3dU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (0xfULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x30U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3dU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3dU]) | (1U 
                                                   & (IData)(
                                                             (0xfULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x30U)))));
    vlSelf->__PVT__CarrySig[0x3eU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (7ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x31U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3eU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3eU]) | (1U 
                                                   & (IData)(
                                                             (7ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x31U)))));
    vlSelf->__PVT__CarrySig[0x3fU] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (2U 
                                                   & ((~ (IData)(
                                                                 (3ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x32U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x3fU] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x3fU]) | (1U 
                                                   & (IData)(
                                                             (3ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x32U)))));
    vlSelf->__PVT__CarrySig[0x40U] = ((1U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (2U 
                                                   & ((~ (IData)(
                                                                 (1ULL 
                                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                     >> 0x33U)))) 
                                                      << 1U)));
    vlSelf->__PVT__CarrySig[0x40U] = ((2U & vlSelf->__PVT__CarrySig
                                       [0x40U]) | (1U 
                                                   & (IData)(
                                                             (1ULL 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                 >> 0x33U)))));
    vlSelf->__PVT__neg2x = ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                        >> 0xbU))) 
                            & (IData)(uu__DOT____VdfgTmp_hf6cd5b06__0));
    vlSelf->__PVT__negx = (1U & ((IData)((0x3000ULL 
                                          == (0x3800ULL 
                                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                                 | ((IData)(uu__DOT____VdfgTmp_hf6cd5b06__0) 
                                    & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                               >> 0xbU)))));
    vlSelf->__PVT__x = (1U & ((IData)((0x800ULL == 
                                       (0x3800ULL & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY))) 
                              | ((~ (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                             >> 0xbU))) 
                                 & (IData)(uu__DOT____VdfgTmp_he6224cd4__0))));
    vlSelf->__PVT___2x = ((IData)(uu__DOT____VdfgTmp_he6224cd4__0) 
                          & (IData)((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalY 
                                     >> 0xbU)));
    vlSelf->__PVT__OutX = (((QData)((IData)((((~ (IData)(
                                                         (1ULL 
                                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                             >> 0x33U)))) 
                                              & (IData)(vlSelf->__PVT__negx)) 
                                             | ((IData)(
                                                        ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                          >> 0x33U) 
                                                         & (IData)(vlSelf->__PVT__x))) 
                                                | (((vlSelf->__PVT__CarrySig
                                                     [0x3fU] 
                                                     >> 1U) 
                                                    & (IData)(vlSelf->__PVT__neg2x)) 
                                                   | (vlSelf->__PVT__CarrySig
                                                      [0x3fU] 
                                                      & (IData)(vlSelf->__PVT___2x))))))) 
                            << 0x3fU) | (((QData)((IData)(
                                                          (((~ (IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x32U)))) 
                                                            & (IData)(vlSelf->__PVT__negx)) 
                                                           | (((IData)(
                                                                       (3ULL 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                           >> 0x32U))) 
                                                               & (IData)(vlSelf->__PVT__x)) 
                                                              | (((vlSelf->__PVT__CarrySig
                                                                   [0x3eU] 
                                                                   >> 1U) 
                                                                  & (IData)(vlSelf->__PVT__neg2x)) 
                                                                 | (vlSelf->__PVT__CarrySig
                                                                    [0x3eU] 
                                                                    & (IData)(vlSelf->__PVT___2x))))))) 
                                          << 0x3eU) 
                                         | (((QData)((IData)(
                                                             (((~ (IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x31U)))) 
                                                               & (IData)(vlSelf->__PVT__negx)) 
                                                              | (((IData)(
                                                                          (7ULL 
                                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                              >> 0x31U))) 
                                                                  & (IData)(vlSelf->__PVT__x)) 
                                                                 | (((vlSelf->__PVT__CarrySig
                                                                      [0x3dU] 
                                                                      >> 1U) 
                                                                     & (IData)(vlSelf->__PVT__neg2x)) 
                                                                    | (vlSelf->__PVT__CarrySig
                                                                       [0x3dU] 
                                                                       & (IData)(vlSelf->__PVT___2x))))))) 
                                             << 0x3dU) 
                                            | (((QData)((IData)(
                                                                (((~ (IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U)))) 
                                                                  & (IData)(vlSelf->__PVT__negx)) 
                                                                 | (((IData)(
                                                                             (0xfULL 
                                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x30U))) 
                                                                     & (IData)(vlSelf->__PVT__x)) 
                                                                    | (((vlSelf->__PVT__CarrySig
                                                                         [0x3cU] 
                                                                         >> 1U) 
                                                                        & (IData)(vlSelf->__PVT__neg2x)) 
                                                                       | (vlSelf->__PVT__CarrySig
                                                                          [0x3cU] 
                                                                          & (IData)(vlSelf->__PVT___2x))))))) 
                                                << 0x3cU) 
                                               | (((QData)((IData)(
                                                                   (((~ (IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU)))) 
                                                                     & (IData)(vlSelf->__PVT__negx)) 
                                                                    | (((IData)(
                                                                                (0x1fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2fU))) 
                                                                        & (IData)(vlSelf->__PVT__x)) 
                                                                       | (((vlSelf->__PVT__CarrySig
                                                                            [0x3bU] 
                                                                            >> 1U) 
                                                                           & (IData)(vlSelf->__PVT__neg2x)) 
                                                                          | (vlSelf->__PVT__CarrySig
                                                                             [0x3bU] 
                                                                             & (IData)(vlSelf->__PVT___2x))))))) 
                                                   << 0x3bU) 
                                                  | (((QData)((IData)(
                                                                      (((~ (IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU)))) 
                                                                        & (IData)(vlSelf->__PVT__negx)) 
                                                                       | (((IData)(
                                                                                (0x3fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2eU))) 
                                                                           & (IData)(vlSelf->__PVT__x)) 
                                                                          | (((vlSelf->__PVT__CarrySig
                                                                               [0x3aU] 
                                                                               >> 1U) 
                                                                              & (IData)(vlSelf->__PVT__neg2x)) 
                                                                             | (vlSelf->__PVT__CarrySig
                                                                                [0x3aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                      << 0x3aU) 
                                                     | (((QData)((IData)(
                                                                         (((~ (IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU)))) 
                                                                           & (IData)(vlSelf->__PVT__negx)) 
                                                                          | (((IData)(
                                                                                (0x7fULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2dU))) 
                                                                              & (IData)(vlSelf->__PVT__x)) 
                                                                             | (((vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x39U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                         << 0x39U) 
                                                        | (((QData)((IData)(
                                                                            (((~ (IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU)))) 
                                                                              & (IData)(vlSelf->__PVT__negx)) 
                                                                             | (((IData)(
                                                                                (0xffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x38U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                            << 0x38U) 
                                                           | (((QData)((IData)(
                                                                               (((~ (IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x37U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                               << 0x37U) 
                                                              | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x2aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x36U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                  << 0x36U) 
                                                                 | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x29U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x35U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                     << 0x35U) 
                                                                    | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x28U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x34U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                        << 0x34U) 
                                                                       | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x27U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x33U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                           << 0x33U) 
                                                                          | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x26U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x32U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                              << 0x32U) 
                                                                             | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x25U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x31U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x31U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x24U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x30U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x23U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2fU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2fU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x22U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2eU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2eU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x21U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2dU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2dU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x20U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2cU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2cU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1fU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2bU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2bU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1eU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x2aU] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x2aU) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1dU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x29U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x29U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1cU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x28U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1bU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x27U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x27U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x1aU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x26U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x26U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7ffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x19U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x25U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x25U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xfffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x18U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x24U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x24U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x1fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x17U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x23U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x23U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x3fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x16U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x22U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x22U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0x7fffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x15U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x21U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x21U) 
                                                                                | (((QData)((IData)(
                                                                                (((~ (IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (0xffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x14U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (((vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                >> 1U) 
                                                                                & (IData)(vlSelf->__PVT__neg2x)) 
                                                                                | (vlSelf->__PVT__CarrySig
                                                                                [0x20U] 
                                                                                & (IData)(vlSelf->__PVT___2x))))))) 
                                                                                << 0x20U) 
                                                                                | (QData)((IData)(
                                                                                (((((~ (IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1fU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x13U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1fU) 
                                                                                | ((0x80000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                << 0x1eU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1fU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1fU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1fU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1eU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x12U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1eU) 
                                                                                | ((0xc0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                << 0x1dU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1eU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1eU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1eU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1dU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x11U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1dU) 
                                                                                | ((0xe0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                << 0x1cU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1dU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1dU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1dU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1cU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0x10U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1cU) 
                                                                                | ((0xf0000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                << 0x1bU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1cU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1cU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1cU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1bU) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xfU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1bU) 
                                                                                | ((0xf8000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                << 0x1aU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1bU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1bU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1bU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x1aU) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xeU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x1aU) 
                                                                                | ((0xfc000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                << 0x19U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x1aU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x1aU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x1aU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x19U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xdU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x19U) 
                                                                                | ((0xfe000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                << 0x18U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x19U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x19U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x19U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x18U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xcU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x18U) 
                                                                                | ((0xff000000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                << 0x17U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x18U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x18U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x18U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x17U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xbU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x17U) 
                                                                                | ((0xff800000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                << 0x16U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x17U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x17U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x17U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x16U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 0xaU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x16U) 
                                                                                | ((0xffc00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                << 0x15U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x16U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x16U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x16U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x15U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 9U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x15U) 
                                                                                | ((0xffe00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                << 0x14U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x15U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x15U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x15U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x14U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 8U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x14U) 
                                                                                | ((0xfff00000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                << 0x13U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x14U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x14U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x14U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x13U) 
                                                                                | ((((IData)(
                                                                                (0x1fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x13U) 
                                                                                | ((0xfff80000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                << 0x12U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x13U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x13U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x13U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x12U) 
                                                                                | ((((IData)(
                                                                                (0x3fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x12U) 
                                                                                | ((0xfffc0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                << 0x11U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x12U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x12U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x12U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x11U) 
                                                                                | ((((IData)(
                                                                                (0x7fffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x11U) 
                                                                                | ((0xfffe0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                << 0x10U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x11U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x11U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x11U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0x10U) 
                                                                                | ((((IData)(
                                                                                (0xffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0x10U) 
                                                                                | ((0xffff0000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                << 0xfU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0x10U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0x10U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0x10U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xfU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xfU) 
                                                                                | ((0xffff8000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                << 0xeU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xfU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xfU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xfU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xeU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xeU) 
                                                                                | ((0xffffc000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                << 0xdU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xeU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xeU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xeU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xdU) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffffULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                >> 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xdU) 
                                                                                | ((0xffffe000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                << 0xcU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xdU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xdU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xdU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xcU) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffffULL 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xcU) 
                                                                                | ((0xfffff000U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                << 0xbU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xcU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xcU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xcU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xbU) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffeULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 1U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xbU) 
                                                                                | ((0xfffff800U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                << 0xaU) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xbU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xbU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xbU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 0xaU) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffcULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 2U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 0xaU) 
                                                                                | ((0xfffffc00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                << 9U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 0xaU))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [0xaU] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 0xaU)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 9U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffff8ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 3U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 9U) 
                                                                                | ((0xfffffe00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                << 8U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 9U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [9U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 9U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 8U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffff0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 4U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 8U) 
                                                                                | ((0xffffff00U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                << 7U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 8U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [8U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 8U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 7U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffe0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 5U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 7U) 
                                                                                | ((0xffffff80U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                << 6U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 7U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [7U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 7U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffc0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 6U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffc0ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 6U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 6U) 
                                                                                | ((0xffffffc0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                << 5U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 6U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [6U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 6U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffff80ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 7U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 5U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffff80ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 7U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 5U) 
                                                                                | ((0xffffffe0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                << 4U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 5U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [5U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 5U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0xfffffffffffff00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 8U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 4U) 
                                                                                | ((((IData)(
                                                                                (0xfffffffffffff00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 8U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 4U) 
                                                                                | ((0xfffffff0U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                << 3U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 4U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [4U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 4U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x1ffffffffffffe00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 9U)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 3U) 
                                                                                | ((((IData)(
                                                                                (0x1ffffffffffffe00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 9U))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 3U) 
                                                                                | ((0xfffffff8U 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                << 2U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 3U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [3U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 3U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x3ffffffffffffc00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xaU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 2U) 
                                                                                | ((((IData)(
                                                                                (0x3ffffffffffffc00ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xaU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 2U) 
                                                                                | ((0xfffffffcU 
                                                                                & ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                << 1U) 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 2U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [2U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 2U)))) 
                                                                                | (((((~ (IData)(
                                                                                (0x7ffffffffffff800ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xbU)))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                << 1U) 
                                                                                | ((((IData)(
                                                                                (0x7ffffffffffff800ULL 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xbU))) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                << 1U) 
                                                                                | ((0xfffffffeU 
                                                                                & (vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & ((IData)(vlSelf->__PVT__neg2x) 
                                                                                << 1U))) 
                                                                                | ((vlSelf->__PVT__CarrySig
                                                                                [1U] 
                                                                                & (IData)(vlSelf->__PVT___2x)) 
                                                                                << 1U)))) 
                                                                                | (((~ (IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xcU))) 
                                                                                & (IData)(vlSelf->__PVT__negx)) 
                                                                                | (((IData)(
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_mul__DOT__CalX 
                                                                                << 0xcU)) 
                                                                                & (IData)(vlSelf->__PVT__x)) 
                                                                                | (IData)(vlSelf->__PVT__neg2x))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
}
