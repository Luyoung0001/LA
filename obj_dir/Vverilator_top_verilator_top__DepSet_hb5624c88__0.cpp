// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_verilator_top.h"

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__2(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__2\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__ifu_fs_allowin = (1U & 
                                               ((~ (IData)(vlSelf->__PVT__cpu__DOT__ifu__DOT__fs_valid)) 
                                                | (IData)(vlSelf->__PVT__cpu__DOT__idu_ds_allowin)));
}

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_comb__TOP__verilator_top__0\n"); );
    // Body
    vlSelf->__PVT__cpu__DOT__preifu_next_pc = ((IData)(vlSelf->__PVT__cpu__DOT__idu__DOT__br_taken)
                                                ? (
                                                   ((IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                                                    | (IData)(vlSelf->cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0))
                                                    ? 
                                                   (vlSelf->__PVT__cpu__DOT__idu__DOT__pc_reg 
                                                    + 
                                                    (((0x14U 
                                                       == 
                                                       (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                        >> 0x1aU)) 
                                                      | (0x15U 
                                                         == 
                                                         (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                          >> 0x1aU)))
                                                      ? 
                                                     (((- (IData)(
                                                                  (1U 
                                                                   & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                      >> 9U)))) 
                                                       << 0x1cU) 
                                                      | ((0xffc0000U 
                                                          & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                             << 0x12U)) 
                                                         | (0x3fffcU 
                                                            & (vlSelf->__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                               >> 8U))))
                                                      : vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs))
                                                    : 
                                                   (vlSelf->__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                                    + vlSelf->__PVT__cpu__DOT__idu__DOT__jirl_offs))
                                                : ((IData)(4U) 
                                                   + vlSelf->__PVT__cpu__DOT__ifu__DOT__pc));
}
