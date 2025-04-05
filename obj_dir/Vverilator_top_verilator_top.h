// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_top.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TOP_VERILATOR_TOP_H_
#define VERILATED_VVERILATOR_TOP_VERILATOR_TOP_H_  // guard

#include "verilated.h"

class Vverilator_top__Syms;

class Vverilator_top_verilator_top final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ __PVT__cpu_resetn;
    CData/*3:0*/ debug_wb_rf_we;
    CData/*4:0*/ debug_wb_rf_wnum;
    CData/*0:0*/ __PVT__data_sram_en;
    CData/*0:0*/ __PVT__data_sram_we;
    CData/*0:0*/ __PVT__cpu__DOT__reset;
    CData/*0:0*/ __PVT__cpu__DOT__valid;
    CData/*0:0*/ __PVT__cpu__DOT__load_op;
    CData/*0:0*/ __PVT__cpu__DOT__src1_is_pc;
    CData/*0:0*/ __PVT__cpu__DOT__res_from_mem;
    CData/*0:0*/ __PVT__cpu__DOT__mem_we;
    CData/*4:0*/ __PVT__cpu__DOT__dest;
    CData/*0:0*/ __PVT__cpu__DOT__rj_eq_rd;
    CData/*0:0*/ __PVT__cpu__DOT__inst_add_w;
    CData/*0:0*/ __PVT__cpu__DOT__inst_addi_w;
    CData/*4:0*/ __PVT__cpu__DOT__rf_raddr2;
    CData/*0:0*/ __PVT__cpu__DOT__rf_we;
    CData/*0:0*/ cpu__DOT____VdfgTmp_h1c4a3e54__0;
    CData/*0:0*/ cpu__DOT____VdfgTmp_h19962199__0;
    CData/*0:0*/ cpu__DOT____VdfgTmp_h78773bd0__0;
    CData/*0:0*/ cpu__DOT____VdfgTmp_h7517b185__0;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_sub;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_slt;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_sltu;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_and;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_nor;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_or;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_xor;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_sll;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_srl;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_sra;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__op_lui;
    CData/*0:0*/ __PVT__cpu__DOT__u_alu__DOT__adder_cin;
    CData/*0:0*/ __VdfgTmp_h6e61b208__0;
    SData/*15:0*/ __PVT__cpu__DOT__op_25_22_d;
    IData/*31:0*/ __PVT__cpu_inst_rdata;
    IData/*31:0*/ __PVT__cpu_data_rdata;
    IData/*31:0*/ debug_wb_pc;
    IData/*31:0*/ debug_wb_rf_wdata;
    IData/*31:0*/ __PVT__data_sram_addr;
    IData/*31:0*/ __PVT__data_sram_wdata;
    IData/*31:0*/ __PVT__data_sram_rdata;
    IData/*31:0*/ __PVT__cpu__DOT__nextpc;
    IData/*31:0*/ __PVT__cpu__DOT__pc;
    IData/*31:0*/ __PVT__cpu__DOT__rj_value;
    IData/*31:0*/ __PVT__cpu__DOT__rkd_value;
    IData/*31:0*/ __PVT__cpu__DOT__jirl_offs;
    IData/*31:0*/ __PVT__cpu__DOT__op_19_15_d;
    IData/*31:0*/ __PVT__cpu__DOT__rf_wdata;
    IData/*31:0*/ __PVT__cpu__DOT__alu_result;
    IData/*31:0*/ __PVT__cpu__DOT__u_alu__DOT__add_sub_result;
    IData/*31:0*/ __PVT__cpu__DOT__u_alu__DOT__or_result;
    IData/*31:0*/ __PVT__cpu__DOT__u_alu__DOT__lui_result;
    IData/*31:0*/ __PVT__cpu__DOT__u_alu__DOT__adder_a;
    IData/*31:0*/ __PVT__cpu__DOT__u_alu__DOT__adder_b;
    IData/*31:0*/ __Vfunc_inst_ram__DOT__inst_ram_read__0__Vfuncout;
    IData/*31:0*/ __Vfunc_data_ram__DOT__data_ram_read__2__Vfuncout;
    QData/*63:0*/ __PVT__cpu__DOT__op_31_26_d;
    VlUnpacked<IData/*31:0*/, 32> __PVT__cpu__DOT__u_regfile__DOT__rf;

    // INTERNAL VARIABLES
    Vverilator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vverilator_top_verilator_top(Vverilator_top__Syms* symsp, const char* v__name);
    ~Vverilator_top_verilator_top();
    VL_UNCOPYABLE(Vverilator_top_verilator_top);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
