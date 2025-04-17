// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vverilator_top__Syms.h"


void Vverilator_top___024root__trace_chg_sub_0(Vverilator_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vverilator_top___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_chg_top_0\n"); );
    // Init
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vverilator_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vverilator_top___024root__trace_chg_sub_0(Vverilator_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<3>/*95:0*/ __Vtemp_h4ead006d__0;
    VlWide<5>/*159:0*/ __Vtemp_hddfd4d09__0;
    VlWide<5>/*159:0*/ __Vtemp_h16c6ceab__0;
    VlWide<3>/*95:0*/ __Vtemp_hffc645e5__0;
    VlWide<3>/*95:0*/ __Vtemp_h4be78b6d__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exe_es_allowin));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+1,(vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata),32);
        bufp->chgCData(oldp+2,((0xfU & ((0xcU & (((- (IData)(
                                                             (1U 
                                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                 >> 7U)))) 
                                                  & (- (IData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__es_valid)))) 
                                                 << 2U)) 
                                        | (3U & ((- (IData)(
                                                            (1U 
                                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                                >> 7U)))) 
                                                 & (- (IData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__es_valid)))))))),4);
        bufp->chgIData(oldp+3,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_data),32);
        bufp->chgIData(oldp+4,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                 << 0x19U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                              >> 7U))),32);
        bufp->chgIData(oldp+5,(vlSymsp->TOP__verilator_top.__PVT__cpu_data_rdata),32);
        bufp->chgIData(oldp+6,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[0U]),32);
        bufp->chgCData(oldp+7,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])),5);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U]),32);
        bufp->chgBit(oldp+9,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__fs_valid));
        bufp->chgQData(oldp+10,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__br_taken)) 
                                  << 0x20U) | (QData)((IData)(
                                                              (((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                                                                | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0))
                                                                ? 
                                                               (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg 
                                                                + 
                                                                (((0x14U 
                                                                   == 
                                                                   (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                    >> 0x1aU)) 
                                                                  | (0x15U 
                                                                     == 
                                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                      >> 0x1aU)))
                                                                  ? 
                                                                 (((- (IData)(
                                                                              (1U 
                                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 9U)))) 
                                                                   << 0x1cU) 
                                                                  | ((0xffc0000U 
                                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                         << 0x12U)) 
                                                                     | (0x3fffcU 
                                                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                           >> 8U))))
                                                                  : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs))
                                                                : 
                                                               (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                                                + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs)))))),33);
        bufp->chgCData(oldp+12,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 5U))),5);
        bufp->chgCData(oldp+13,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_rf_raddr2),5);
        __Vtemp_h4ead006d__0[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem)) 
                                             << 0x26U) 
                                            | (((QData)((IData)(
                                                                ((0x15U 
                                                                  == 
                                                                  (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                   >> 0x1aU)) 
                                                                 | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                    | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                       | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                                          | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w))))))))))))))))) 
                                                << 0x25U) 
                                               | (((QData)((IData)(
                                                                   ((0x15U 
                                                                     == 
                                                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                      >> 0x1aU))
                                                                     ? 1U
                                                                     : 
                                                                    (0x1fU 
                                                                     & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg))))));
        __Vtemp_h4ead006d__0[1U] = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData 
                                     << 7U) | (IData)(
                                                      ((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem)) 
                                                         << 0x26U) 
                                                        | (((QData)((IData)(
                                                                            ((0x15U 
                                                                              == 
                                                                              (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                               >> 0x1aU)) 
                                                                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w))))))))))))))))) 
                                                            << 0x25U) 
                                                           | (((QData)((IData)(
                                                                               ((0x15U 
                                                                                == 
                                                                                (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x1aU))
                                                                                 ? 1U
                                                                                 : 
                                                                                (0x1fU 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)))) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg))))) 
                                                       >> 0x20U)));
        __Vtemp_hddfd4d09__0[3U] = (((IData)((((QData)((IData)(
                                                               ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                 ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                 : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                   | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                      | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                           | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                              | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                  ? 
                                                                 ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                   ? 4U
                                                                   : 
                                                                  ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                    ? 
                                                                   (0xfffff000U 
                                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       << 7U))
                                                                    : 
                                                                   (((- (IData)(
                                                                                (1U 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                     << 0xcU) 
                                                                    | (0xfffU 
                                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 0xaU)))))
                                                                  : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData))))) 
                                     >> 0x18U) | ((IData)(
                                                          ((((QData)((IData)(
                                                                             ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                               ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                               : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              ((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                                ? 
                                                                               ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                                 ? 4U
                                                                                 : 
                                                                                ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                                 ? 
                                                                                (0xfffff000U 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                << 7U))
                                                                                 : 
                                                                                (((- (IData)(
                                                                                (1U 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                                << 0xcU) 
                                                                                | (0xfffU 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0xaU)))))
                                                                                : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData)))) 
                                                           >> 0x20U)) 
                                                  << 8U));
        __Vtemp_h16c6ceab__0[0U] = __Vtemp_h4ead006d__0[0U];
        __Vtemp_h16c6ceab__0[1U] = __Vtemp_h4ead006d__0[1U];
        __Vtemp_h16c6ceab__0[2U] = (((IData)((((QData)((IData)(
                                                               ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                 ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                 : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                ((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                   | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                      | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                           | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                              | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                  ? 
                                                                 ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                   ? 4U
                                                                   : 
                                                                  ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                    ? 
                                                                   (0xfffff000U 
                                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                       << 7U))
                                                                    : 
                                                                   (((- (IData)(
                                                                                (1U 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                     << 0xcU) 
                                                                    | (0xfffU 
                                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          >> 0xaU)))))
                                                                  : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData))))) 
                                     << 8U) | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                << 7U) 
                                               | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData 
                                                  >> 0x19U)));
        __Vtemp_h16c6ceab__0[3U] = __Vtemp_hddfd4d09__0[3U];
        __Vtemp_h16c6ceab__0[4U] = ((0xffffff00U & 
                                     (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                       << 0x13U) | 
                                      (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                        << 0x12U) | 
                                       (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                         << 0x11U) 
                                        | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                            << 0x10U) 
                                           | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                               << 0xfU) 
                                              | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                  << 0xeU) 
                                                 | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                     << 0xdU) 
                                                    | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                        << 0xcU) 
                                                       | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                           << 0xbU) 
                                                          | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                              << 0xaU) 
                                                             | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                 << 9U) 
                                                                | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                    | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                       | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                          | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                             | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))) 
                                                                   << 8U))))))))))))) 
                                    | ((IData)(((((QData)((IData)(
                                                                  ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                    ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg
                                                                    : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   ((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                                      | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                                         | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                           | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                              | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                                                     ? 
                                                                    ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                                                      ? 4U
                                                                      : 
                                                                     ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                                                       ? 
                                                                      (0xfffff000U 
                                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                          << 7U))
                                                                       : 
                                                                      (((- (IData)(
                                                                                (1U 
                                                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                                >> 0x15U)))) 
                                                                        << 0xcU) 
                                                                       | (0xfffU 
                                                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                             >> 0xaU)))))
                                                                     : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData)))) 
                                                >> 0x20U)) 
                                       >> 0x18U));
        bufp->chgWData(oldp+14,(__Vtemp_h16c6ceab__0),148);
        bufp->chgBit(oldp+19,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_ds_allowin));
        bufp->chgBit(oldp+20,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_ds_to_es_valid));
        __Vtemp_hffc645e5__0[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
                                             << 0x25U) 
                                            | (0x1fffffffffULL 
                                               & (((QData)((IData)(
                                                                   vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]))))));
        __Vtemp_hffc645e5__0[1U] = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_data 
                                     << 6U) | (IData)(
                                                      ((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
                                                         << 0x25U) 
                                                        | (0x1fffffffffULL 
                                                           & (((QData)((IData)(
                                                                               vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])) 
                                                               << 0x20U) 
                                                              | (QData)((IData)(
                                                                                vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]))))) 
                                                       >> 0x20U)));
        __Vtemp_hffc645e5__0[2U] = ((0x40U & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U]) 
                                    | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_data 
                                       >> 0x1aU));
        bufp->chgWData(oldp+21,(__Vtemp_hffc645e5__0),71);
        bufp->chgBit(oldp+24,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__es_valid));
        bufp->chgQData(oldp+25,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
                                  << 0x25U) | (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_data)) 
                                                << 5U) 
                                               | (QData)((IData)(
                                                                 (0x1fU 
                                                                  & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])))))),38);
        __Vtemp_h4be78b6d__0[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_data)) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U]))));
        __Vtemp_h4be78b6d__0[1U] = (IData)(((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_data)) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U]))) 
                                            >> 0x20U));
        __Vtemp_h4be78b6d__0[2U] = (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_regWr) 
                                     << 5U) | (0x1fU 
                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U]));
        bufp->chgWData(oldp+27,(__Vtemp_h4be78b6d__0),70);
        bufp->chgBit(oldp+30,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__ms_valid));
        bufp->chgQData(oldp+31,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_regWr)) 
                                  << 0x25U) | (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_data)) 
                                                << 5U) 
                                               | (QData)((IData)(
                                                                 (0x1fU 
                                                                  & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U])))))),38);
        bufp->chgBit(oldp+33,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__wbu_regWr));
        bufp->chgQData(oldp+34,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__wbu_regWr)) 
                                  << 0x25U) | (((QData)((IData)(
                                                                vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U])) 
                                                << 5U) 
                                               | (QData)((IData)(
                                                                 (0x1fU 
                                                                  & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])))))),38);
        bufp->chgIData(oldp+36,(((0U == (0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                  >> 5U)))
                                  ? 0U : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf
                                 [(0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 5U))])),32);
        bufp->chgIData(oldp+37,(((0U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_rf_raddr2))
                                  ? 0U : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf
                                 [vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_rf_raddr2])),32);
        bufp->chgBit(oldp+38,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr));
        bufp->chgCData(oldp+39,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])),5);
        bufp->chgWData(oldp+40,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r),148);
        bufp->chgSData(oldp+45,((0xfffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                           >> 8U))),12);
        bufp->chgIData(oldp+46,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                               >> 8U))),32);
        bufp->chgIData(oldp+47,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                  << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                               >> 8U))),32);
        bufp->chgBit(oldp+48,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                     >> 7U))));
        bufp->chgBit(oldp+49,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                     >> 6U))));
        bufp->chgBit(oldp+50,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                     >> 5U))));
        bufp->chgIData(oldp+51,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]),32);
        bufp->chgBit(oldp+52,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 8U))));
        bufp->chgBit(oldp+53,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 9U))));
        bufp->chgBit(oldp+54,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0xaU))));
        bufp->chgBit(oldp+55,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0xbU))));
        bufp->chgBit(oldp+56,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0xcU))));
        bufp->chgBit(oldp+57,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0xdU))));
        bufp->chgBit(oldp+58,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0xeU))));
        bufp->chgBit(oldp+59,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0xfU))));
        bufp->chgBit(oldp+60,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0x10U))));
        bufp->chgBit(oldp+61,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0x11U))));
        bufp->chgBit(oldp+62,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0x12U))));
        bufp->chgBit(oldp+63,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                     >> 0x13U))));
        bufp->chgIData(oldp+64,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result),32);
        bufp->chgIData(oldp+65,((1U & (((~ (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                            >> 7U)) 
                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                           >> 7U)) 
                                       | ((~ ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                               ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U]) 
                                              >> 7U)) 
                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result 
                                             >> 0x1fU))))),32);
        bufp->chgIData(oldp+66,((1U & (~ (IData)((1ULL 
                                                  & (((QData)((IData)(
                                                                      ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                        << 0x18U) 
                                                                       | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                          >> 8U)))) 
                                                      + 
                                                      ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b)) 
                                                       + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)))) 
                                                     >> 0x20U)))))),32);
        bufp->chgIData(oldp+67,((((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                   << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                >> 8U)) 
                                 & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                     << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                  >> 8U)))),32);
        bufp->chgIData(oldp+68,((~ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result)),32);
        bufp->chgIData(oldp+69,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result),32);
        bufp->chgIData(oldp+70,((((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                   << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                >> 8U)) 
                                 ^ ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                     << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                  >> 8U)))),32);
        bufp->chgIData(oldp+71,((((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                   << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                >> 8U)) 
                                 << (0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                              >> 8U)))),32);
        bufp->chgQData(oldp+72,(((((QData)((IData)(
                                                   (- (IData)((IData)(
                                                                      (0x40080U 
                                                                       == 
                                                                       (0x40080U 
                                                                        & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U]))))))) 
                                   << 0x20U) | (QData)((IData)(
                                                               ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                 << 0x18U) 
                                                                | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                   >> 8U))))) 
                                 >> (0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                              >> 8U)))),64);
        bufp->chgIData(oldp+74,((IData)(((((QData)((IData)(
                                                           (- (IData)((IData)(
                                                                              (0x40080U 
                                                                               == 
                                                                               (0x40080U 
                                                                                & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U]))))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(
                                                            ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                              << 0x18U) 
                                                             | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                >> 8U))))) 
                                         >> (0x1fU 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                >> 8U))))),32);
        bufp->chgIData(oldp+75,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b),32);
        bufp->chgBit(oldp+76,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin));
        bufp->chgBit(oldp+77,((1U & (IData)((1ULL & 
                                             (((QData)((IData)(
                                                               ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                 << 0x18U) 
                                                                | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                   >> 8U)))) 
                                               + ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b)) 
                                                  + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)))) 
                                              >> 0x20U))))));
        bufp->chgBit(oldp+78,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_regWr));
        bufp->chgIData(oldp+79,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_data),32);
        bufp->chgCData(oldp+80,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U])),5);
        bufp->chgSData(oldp+81,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                  << 0xbU) | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                               << 0xaU) 
                                              | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                  << 9U) 
                                                 | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                     << 8U) 
                                                    | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                        << 7U) 
                                                       | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                           << 6U) 
                                                          | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                                              << 5U) 
                                                             | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                                 << 4U) 
                                                                | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                                                    << 3U) 
                                                                   | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                                                       << 2U) 
                                                                      | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                                                          << 1U) 
                                                                         | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                                                            | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))))))))))))),12);
        bufp->chgIData(oldp+82,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                  ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg
                                  : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData)),32);
        bufp->chgIData(oldp+83,(((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                   | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                      | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                           | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                              | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))
                                  ? ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                      ? 4U : ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                               ? (0xfffff000U 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     << 7U))
                                               : ((
                                                   (- (IData)(
                                                              (1U 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                                  >> 0x15U)))) 
                                                   << 0xcU) 
                                                  | (0xfffU 
                                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                        >> 0xaU)))))
                                  : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData)),32);
        bufp->chgBit(oldp+84,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we));
        bufp->chgIData(oldp+85,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData),32);
        bufp->chgBit(oldp+86,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem));
        bufp->chgBit(oldp+87,(((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU)) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt) 
                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu) 
                                           | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor) 
                                              | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and) 
                                                 | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or) 
                                                    | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor) 
                                                       | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                                          | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                                                   | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                                                      | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)))))))))))))))));
        bufp->chgCData(oldp+88,(((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 0x1aU))
                                  ? 1U : (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg))),5);
        bufp->chgIData(oldp+89,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg),32);
        bufp->chgBit(oldp+90,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__br_taken));
        bufp->chgIData(oldp+91,((((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                                  | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0))
                                  ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg 
                                     + (((0x14U == 
                                          (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 0x1aU)) 
                                         | (0x15U == 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 0x1aU)))
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                            >> 9U)))) 
                                             << 0x1cU) 
                                            | ((0xffc0000U 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                   << 0x12U)) 
                                               | (0x3fffcU 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     >> 8U))))
                                         : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs))
                                  : (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData 
                                     + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs))),32);
        bufp->chgIData(oldp+92,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg),32);
        bufp->chgBit(oldp+93,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc));
        bufp->chgBit(oldp+94,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                   | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                           | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))));
        bufp->chgBit(oldp+95,((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                         >> 0x1aU))));
        bufp->chgBit(oldp+96,(((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                               | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we))));
        bufp->chgIData(oldp+97,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData),32);
        bufp->chgIData(oldp+98,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                                  ? 4U : ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w)
                                           ? (0xfffff000U 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                 << 7U))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                              >> 0x15U)))) 
                                               << 0xcU) 
                                              | (0xfffU 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                    >> 0xaU)))))),32);
        bufp->chgBit(oldp+99,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__rj_eq_rd));
        bufp->chgIData(oldp+100,((((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              >> 0x1aU)) 
                                   | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                >> 0x1aU)))
                                   ? (((- (IData)((1U 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                      >> 9U)))) 
                                       << 0x1cU) | 
                                      ((0xffc0000U 
                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           << 0x12U)) 
                                       | (0x3fffcU 
                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 8U))))
                                   : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs)),32);
        bufp->chgIData(oldp+101,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs),32);
        bufp->chgCData(oldp+102,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                  >> 0x1aU)),6);
        bufp->chgCData(oldp+103,((0xfU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x16U))),4);
        bufp->chgCData(oldp+104,((3U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0x14U))),2);
        bufp->chgCData(oldp+105,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+106,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)),5);
        bufp->chgCData(oldp+107,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 0xaU))),5);
        bufp->chgSData(oldp+108,((0xfffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                            >> 0xaU))),12);
        bufp->chgIData(oldp+109,((0xfffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              >> 5U))),20);
        bufp->chgSData(oldp+110,((0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 0xaU))),16);
        bufp->chgIData(oldp+111,(((0x3ff0000U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                 << 0x10U)) 
                                  | (0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                >> 0xaU)))),26);
        bufp->chgQData(oldp+112,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__op_31_26_d),64);
        bufp->chgSData(oldp+114,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__op_25_22_d),16);
        bufp->chgCData(oldp+115,((((3U == (3U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                 >> 0x14U))) 
                                   << 3U) | (((2U == 
                                               (3U 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                   >> 0x14U))) 
                                              << 2U) 
                                             | (((1U 
                                                  == 
                                                  (3U 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                      >> 0x14U))) 
                                                 << 1U) 
                                                | (0U 
                                                   == 
                                                   (3U 
                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                       >> 0x14U))))))),4);
        bufp->chgIData(oldp+116,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__op_19_15_d),32);
        bufp->chgBit(oldp+117,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w));
        bufp->chgBit(oldp+118,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w));
        bufp->chgBit(oldp+119,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt));
        bufp->chgBit(oldp+120,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu));
        bufp->chgBit(oldp+121,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor));
        bufp->chgBit(oldp+122,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and));
        bufp->chgBit(oldp+123,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or));
        bufp->chgBit(oldp+124,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor));
        bufp->chgBit(oldp+125,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w));
        bufp->chgBit(oldp+126,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w));
        bufp->chgBit(oldp+127,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w));
        bufp->chgBit(oldp+128,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w));
        bufp->chgBit(oldp+129,((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU))));
        bufp->chgBit(oldp+130,((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU))));
        bufp->chgBit(oldp+131,((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU))));
        bufp->chgBit(oldp+132,((0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU))));
        bufp->chgBit(oldp+133,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w));
        bufp->chgBit(oldp+134,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                   | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w)))));
        bufp->chgBit(oldp+135,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                   | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we)))));
        bufp->chgBit(oldp+136,(((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 0x1aU)) 
                                | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0))));
        bufp->chgBit(oldp+137,(((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 0x1aU)) 
                                | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 0x1aU)))));
        bufp->chgBit(oldp+138,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__is_load));
        bufp->chgBit(oldp+139,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__is_load) 
                                & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr) 
                                   & ((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h3372f28b__0) 
                                      & (0U != (0x1fU 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                   >> 5U))))))));
        bufp->chgBit(oldp+140,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__ds_valid));
        bufp->chgBit(oldp+141,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__ds_ready_go));
        bufp->chgWData(oldp+142,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r),71);
        bufp->chgIData(oldp+145,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                   << 0x1aU) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                                >> 6U))),32);
        bufp->chgBit(oldp+146,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                      >> 6U))));
        bufp->chgBit(oldp+147,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                      >> 5U))));
        bufp->chgIData(oldp+148,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U]),32);
        bufp->chgIData(oldp+149,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+150,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+151,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+152,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+153,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+154,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+155,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+156,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+157,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+158,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+159,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+160,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+161,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+162,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+163,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+164,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+165,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+166,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+167,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+168,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+169,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+170,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+171,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+172,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+173,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+174,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+175,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+176,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+177,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+178,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+179,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+180,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[31]),32);
        bufp->chgBit(oldp+181,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                      >> 5U))));
        bufp->chgWData(oldp+182,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r),70);
        bufp->chgBit(oldp+185,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__ws_valid));
    }
    bufp->chgBit(oldp+186,(vlSelf->rst));
    bufp->chgBit(oldp+187,(vlSelf->clk));
    bufp->chgBit(oldp+188,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->chgIData(oldp+189,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu_fs_allowin)
                               ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__preifu_next_pc
                               : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__pc)),32);
    bufp->chgIData(oldp+190,(vlSymsp->TOP__verilator_top.debug_wb_pc),32);
    bufp->chgCData(oldp+191,(vlSymsp->TOP__verilator_top.debug_wb_rf_we),4);
    bufp->chgCData(oldp+192,(vlSymsp->TOP__verilator_top.debug_wb_rf_wnum),5);
    bufp->chgIData(oldp+193,(vlSymsp->TOP__verilator_top.debug_wb_rf_wdata),32);
    bufp->chgIData(oldp+194,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__preifu_next_pc),32);
    bufp->chgIData(oldp+195,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__pc),32);
    bufp->chgBit(oldp+196,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu_fs_allowin));
    bufp->chgIData(oldp+197,(((IData)(4U) + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__pc)),32);
}

void Vverilator_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_cleanup\n"); );
    // Init
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
