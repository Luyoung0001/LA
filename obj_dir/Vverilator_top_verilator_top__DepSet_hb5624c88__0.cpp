// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vverilator_top_verilator_top.h"

void Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_write_TOP__verilator_top(IData/*31:0*/ addr, IData/*31:0*/ wdata);

VL_INLINE_OPT void Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__0(Vverilator_top_verilator_top* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vverilator_top_verilator_top___nba_sequent__TOP__verilator_top__0\n"); );
    // Body
    if (((IData)(vlSelf->__PVT__cpu__DOT__mem_we) & (IData)(vlSelf->__PVT__cpu__DOT__valid))) {
        Vverilator_top_verilator_top____Vdpiimwrap_data_ram__DOT__data_ram_write_TOP__verilator_top(vlSelf->__PVT__cpu__DOT__alu_result, vlSelf->__PVT__cpu__DOT__rkd_value);
    }
}
