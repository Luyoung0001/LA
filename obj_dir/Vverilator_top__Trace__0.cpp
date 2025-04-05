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
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSymsp->TOP__verilator_top.__PVT__cpu_resetn));
        bufp->chgIData(oldp+1,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc),32);
        bufp->chgIData(oldp+2,(vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata),32);
        bufp->chgBit(oldp+3,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                              & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid))));
        bufp->chgIData(oldp+4,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__alu_result),32);
        bufp->chgIData(oldp+5,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rkd_value),32);
        bufp->chgIData(oldp+6,(vlSymsp->TOP__verilator_top.__PVT__cpu_data_rdata),32);
        bufp->chgCData(oldp+7,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dest),5);
        bufp->chgIData(oldp+8,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rf_wdata),32);
        bufp->chgBit(oldp+9,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__reset));
        bufp->chgBit(oldp+10,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid));
        bufp->chgIData(oldp+11,(((IData)(4U) + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc)),32);
        bufp->chgIData(oldp+12,((((((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                               >> 0x1aU)) 
                                    & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                   | (((~ (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                       & (0x17U == 
                                          (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                           >> 0x1aU))) 
                                      | ((0x13U == 
                                          (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                           >> 0x1aU)) 
                                         | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0)))) 
                                  & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid))
                                  ? (((IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0) 
                                      | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0))
                                      ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc 
                                         + (((0x14U 
                                              == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                  >> 0x1aU)) 
                                             | (0x15U 
                                                == 
                                                (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 >> 0x1aU)))
                                             ? (((- (IData)(
                                                            (1U 
                                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                                >> 9U)))) 
                                                 << 0x1cU) 
                                                | ((0xffc0000U 
                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                       << 0x12U)) 
                                                   | (0x3fffcU 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                         >> 8U))))
                                             : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs))
                                      : (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_value 
                                         + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs))
                                  : ((IData)(4U) + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc))),32);
        bufp->chgBit(oldp+13,(((((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0x1aU)) 
                                 & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                | (((~ (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                    & (0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 >> 0x1aU))) 
                                   | ((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 >> 0x1aU)) 
                                      | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0)))) 
                               & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid))));
        bufp->chgIData(oldp+14,((((IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0) 
                                  | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0))
                                  ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc 
                                     + (((0x14U == 
                                          (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                           >> 0x1aU)) 
                                         | (0x15U == 
                                            (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                             >> 0x1aU)))
                                         ? (((- (IData)(
                                                        (1U 
                                                         & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                            >> 9U)))) 
                                             << 0x1cU) 
                                            | ((0xffc0000U 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                   << 0x12U)) 
                                               | (0x3fffcU 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                     >> 8U))))
                                         : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs))
                                  : (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_value 
                                     + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs))),32);
        bufp->chgSData(oldp+15,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui) 
                                  << 0xbU) | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra) 
                                               << 0xaU) 
                                              | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_srl) 
                                                  << 9U) 
                                                 | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll) 
                                                     << 8U) 
                                                    | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_xor) 
                                                        << 7U) 
                                                       | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_or) 
                                                           << 6U) 
                                                          | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_nor) 
                                                              << 5U) 
                                                             | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_and) 
                                                                 << 4U) 
                                                                | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sltu) 
                                                                    << 3U) 
                                                                   | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_slt) 
                                                                       << 2U) 
                                                                      | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sub) 
                                                                          << 1U) 
                                                                         | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w) 
                                                                            | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                                                                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                                                                | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc))))))))))))))))),12);
        bufp->chgBit(oldp+16,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc));
        bufp->chgBit(oldp+17,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll) 
                                | (IData)(vlSymsp->TOP__verilator_top.__VdfgTmp_h6e61b208__0)) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui) 
                                           | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc))))))));
        bufp->chgBit(oldp+18,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem));
        bufp->chgBit(oldp+19,((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x1aU))));
        bufp->chgBit(oldp+20,(((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 0x1aU)) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_slt) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sltu) 
                                        | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_nor) 
                                           | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_and) 
                                              | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_or) 
                                                 | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_xor) 
                                                    | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll) 
                                                       | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_srl) 
                                                          | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                                                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui)))))))))))))));
        bufp->chgBit(oldp+21,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we));
        bufp->chgBit(oldp+22,(((IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0) 
                               | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we))));
        bufp->chgIData(oldp+23,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_value),32);
        bufp->chgIData(oldp+24,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc)
                                  ? 4U : ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui)
                                           ? (0xfffff000U 
                                              & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 << 7U))
                                           : (((- (IData)(
                                                          (1U 
                                                           & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                              >> 0x15U)))) 
                                               << 0xcU) 
                                              | (0xfffU 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                    >> 0xaU)))))),32);
        bufp->chgBit(oldp+25,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd));
        bufp->chgIData(oldp+26,((((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                             >> 0x1aU)) 
                                  | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                               >> 0x1aU)))
                                  ? (((- (IData)((1U 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                     >> 9U)))) 
                                      << 0x1cU) | (
                                                   (0xffc0000U 
                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                       << 0x12U)) 
                                                   | (0x3fffcU 
                                                      & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                         >> 8U))))
                                  : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs)),32);
        bufp->chgIData(oldp+27,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs),32);
        bufp->chgCData(oldp+28,((vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                 >> 0x1aU)),6);
        bufp->chgCData(oldp+29,((0xfU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x16U))),4);
        bufp->chgCData(oldp+30,((3U & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0x14U))),2);
        bufp->chgCData(oldp+31,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+32,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata)),5);
        bufp->chgCData(oldp+33,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 5U))),5);
        bufp->chgCData(oldp+34,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 0xaU))),5);
        bufp->chgSData(oldp+35,((0xfffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                           >> 0xaU))),12);
        bufp->chgIData(oldp+36,((0xfffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                             >> 5U))),20);
        bufp->chgSData(oldp+37,((0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0xaU))),16);
        bufp->chgIData(oldp+38,(((0x3ff0000U & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                << 0x10U)) 
                                 | (0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                               >> 0xaU)))),26);
        bufp->chgQData(oldp+39,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__op_31_26_d),64);
        bufp->chgSData(oldp+41,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__op_25_22_d),16);
        bufp->chgCData(oldp+42,((((3U == (3U & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                >> 0x14U))) 
                                  << 3U) | (((2U == 
                                              (3U & 
                                               (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                >> 0x14U))) 
                                             << 2U) 
                                            | (((1U 
                                                 == 
                                                 (3U 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                     >> 0x14U))) 
                                                << 1U) 
                                               | (0U 
                                                  == 
                                                  (3U 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                      >> 0x14U))))))),4);
        bufp->chgIData(oldp+43,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__op_19_15_d),32);
        bufp->chgBit(oldp+44,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w));
        bufp->chgBit(oldp+45,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sub));
        bufp->chgBit(oldp+46,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_slt));
        bufp->chgBit(oldp+47,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sltu));
        bufp->chgBit(oldp+48,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_nor));
        bufp->chgBit(oldp+49,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_and));
        bufp->chgBit(oldp+50,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_or));
        bufp->chgBit(oldp+51,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_xor));
        bufp->chgBit(oldp+52,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll));
        bufp->chgBit(oldp+53,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_srl));
        bufp->chgBit(oldp+54,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra));
        bufp->chgBit(oldp+55,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w));
        bufp->chgBit(oldp+56,((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x1aU))));
        bufp->chgBit(oldp+57,((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x1aU))));
        bufp->chgBit(oldp+58,((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x1aU))));
        bufp->chgBit(oldp+59,((0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x1aU))));
        bufp->chgBit(oldp+60,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui));
        bufp->chgBit(oldp+61,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll) 
                               | (IData)(vlSymsp->TOP__verilator_top.__VdfgTmp_h6e61b208__0))));
        bufp->chgBit(oldp+62,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                  | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we)))));
        bufp->chgBit(oldp+63,(((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 0x1aU)) 
                               | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0))));
        bufp->chgBit(oldp+64,(((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 0x1aU)) 
                               | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0x1aU)))));
        bufp->chgCData(oldp+65,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rf_raddr2),5);
        bufp->chgBit(oldp+66,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rf_we));
        bufp->chgIData(oldp+67,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a),32);
        bufp->chgIData(oldp+68,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result),32);
        bufp->chgBit(oldp+69,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                                        | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc)))))));
        bufp->chgIData(oldp+70,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__add_sub_result),32);
        bufp->chgIData(oldp+71,((1U & (((~ (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result 
                                            >> 0x1fU)) 
                                        & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                           >> 0x1fU)) 
                                       | ((~ ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                               ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result) 
                                              >> 0x1fU)) 
                                          & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__add_sub_result 
                                             >> 0x1fU))))),32);
        bufp->chgIData(oldp+72,((1U & (~ (IData)((1ULL 
                                                  & (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a)) 
                                                      + 
                                                      ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_b)) 
                                                       + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_cin)))) 
                                                     >> 0x20U)))))),32);
        bufp->chgIData(oldp+73,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                 & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result)),32);
        bufp->chgIData(oldp+74,((~ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__or_result)),32);
        bufp->chgIData(oldp+75,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__or_result),32);
        bufp->chgIData(oldp+76,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                 ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result)),32);
        bufp->chgIData(oldp+77,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                 << (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result))),32);
        bufp->chgQData(oldp+78,(((((QData)((IData)(
                                                   (- (IData)(
                                                              ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra) 
                                                               & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result 
                                                                  >> 0x1fU)))))) 
                                   << 0x20U) | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result))) 
                                 >> (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a))),64);
        bufp->chgIData(oldp+80,((IData)(((((QData)((IData)(
                                                           (- (IData)(
                                                                      ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra) 
                                                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result 
                                                                          >> 0x1fU)))))) 
                                           << 0x20U) 
                                          | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result))) 
                                         >> (0x1fU 
                                             & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a)))),32);
        bufp->chgIData(oldp+81,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_b),32);
        bufp->chgBit(oldp+82,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_cin));
        bufp->chgBit(oldp+83,((1U & (IData)((1ULL & 
                                             (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a)) 
                                               + ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_b)) 
                                                  + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_cin)))) 
                                              >> 0x20U))))));
        bufp->chgIData(oldp+84,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[0]),32);
        bufp->chgIData(oldp+85,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[1]),32);
        bufp->chgIData(oldp+86,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[2]),32);
        bufp->chgIData(oldp+87,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[3]),32);
        bufp->chgIData(oldp+88,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[4]),32);
        bufp->chgIData(oldp+89,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[5]),32);
        bufp->chgIData(oldp+90,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[6]),32);
        bufp->chgIData(oldp+91,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[7]),32);
        bufp->chgIData(oldp+92,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[8]),32);
        bufp->chgIData(oldp+93,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[9]),32);
        bufp->chgIData(oldp+94,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[10]),32);
        bufp->chgIData(oldp+95,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[11]),32);
        bufp->chgIData(oldp+96,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[12]),32);
        bufp->chgIData(oldp+97,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[13]),32);
        bufp->chgIData(oldp+98,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[14]),32);
        bufp->chgIData(oldp+99,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[15]),32);
        bufp->chgIData(oldp+100,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[16]),32);
        bufp->chgIData(oldp+101,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[17]),32);
        bufp->chgIData(oldp+102,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[18]),32);
        bufp->chgIData(oldp+103,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[19]),32);
        bufp->chgIData(oldp+104,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[20]),32);
        bufp->chgIData(oldp+105,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[21]),32);
        bufp->chgIData(oldp+106,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[22]),32);
        bufp->chgIData(oldp+107,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[23]),32);
        bufp->chgIData(oldp+108,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[24]),32);
        bufp->chgIData(oldp+109,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[25]),32);
        bufp->chgIData(oldp+110,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[26]),32);
        bufp->chgIData(oldp+111,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[27]),32);
        bufp->chgIData(oldp+112,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[28]),32);
        bufp->chgIData(oldp+113,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[29]),32);
        bufp->chgIData(oldp+114,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[30]),32);
        bufp->chgIData(oldp+115,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[31]),32);
    }
    bufp->chgBit(oldp+116,(vlSelf->rst));
    bufp->chgBit(oldp+117,(vlSelf->clk));
    bufp->chgIData(oldp+118,(vlSymsp->TOP__verilator_top.debug_wb_pc),32);
    bufp->chgCData(oldp+119,(vlSymsp->TOP__verilator_top.debug_wb_rf_we),4);
    bufp->chgCData(oldp+120,(vlSymsp->TOP__verilator_top.debug_wb_rf_wnum),5);
    bufp->chgIData(oldp+121,(vlSymsp->TOP__verilator_top.debug_wb_rf_wdata),32);
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
