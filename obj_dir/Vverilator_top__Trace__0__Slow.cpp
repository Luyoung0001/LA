// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "Vverilator_top__Syms.h"


VL_ATTR_COLD void Vverilator_top___024root__trace_init_sub__TOP__0(Vverilator_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+117,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+118,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
}

VL_ATTR_COLD void Vverilator_top___024root__trace_init_sub__TOP__verilator_top__0(Vverilator_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_init_sub__TOP__verilator_top__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+117,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+118,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+1,"cpu_resetn",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+123,"cpu_inst_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"cpu_inst_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+124,"cpu_inst_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"cpu_inst_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+4,"cpu_data_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+5,"cpu_data_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"cpu_data_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"cpu_data_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+119,"debug_wb_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+120,"debug_wb_rf_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+121,"debug_wb_rf_wnum",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+122,"debug_wb_rf_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+125,"data_sram_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+126,"data_sram_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+127,"data_sram_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+128,"data_sram_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+129,"data_sram_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+118,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+1,"resetn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+123,"inst_sram_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"inst_sram_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+124,"inst_sram_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"inst_sram_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+4,"data_sram_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+5,"data_sram_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"data_sram_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"data_sram_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"debug_wb_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+120,"debug_wb_rf_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+8,"debug_wb_rf_wnum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"debug_wb_rf_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+10,"reset",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+11,"valid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBus(c+12,"seq_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+13,"nextpc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+14,"br_taken",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+15,"br_target",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"inst",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"pc",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+16,"alu_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBit(c+130,"load_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+17,"src1_is_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+18,"src2_is_imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"res_from_mem",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"dst_is_r1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+21,"gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+22,"mem_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+23,"src_reg_is_rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+24,"rj_value",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"rkd_value",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+25,"imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+26,"rj_eq_rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+27,"br_offs",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+28,"jirl_offs",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+29,"op_31_26",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declBus(c+30,"op_25_22",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+31,"op_21_20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+32,"op_19_15",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+33,"rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+34,"rj",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+35,"rk",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+36,"i12",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+37,"i20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 19,0);
    tracep->declBus(c+38,"i16",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBus(c+39,"i26",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 25,0);
    tracep->declQuad(c+40,"op_31_26_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 63,0);
    tracep->declBus(c+42,"op_25_22_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBus(c+43,"op_21_20_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+44,"op_19_15_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+45,"inst_add_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"inst_sub_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+47,"inst_slt",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+48,"inst_sltu",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"inst_nor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+50,"inst_and",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+51,"inst_or",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"inst_xor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+53,"inst_slli_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+54,"inst_srli_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"inst_srai_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"inst_addi_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+19,"inst_ld_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+22,"inst_st_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"inst_jirl",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+58,"inst_b",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"inst_bl",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"inst_beq",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+60,"inst_bne",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"inst_lu12i_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"need_ui5",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+63,"need_si12",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+64,"need_si16",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"need_si20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+65,"need_si26",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+17,"src2_is_4",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+34,"rf_raddr1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+24,"rf_rdata1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+66,"rf_raddr2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+6,"rf_rdata2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"rf_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"rf_waddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"rf_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+68,"alu_src1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+69,"alu_src2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"alu_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"mem_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+9,"final_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("u_alu ");
    tracep->declBus(c+16,"alu_op",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+68,"alu_src1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+69,"alu_src2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"alu_result",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+70,"op_add",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+46,"op_sub",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+47,"op_slt",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+48,"op_sltu",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+50,"op_and",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+49,"op_nor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+51,"op_or",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+52,"op_xor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+53,"op_sll",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+54,"op_srl",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"op_sra",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"op_lui",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+71,"add_sub_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"slt_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+73,"sltu_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+74,"and_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+75,"nor_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+76,"or_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+77,"xor_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+69,"lui_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+78,"sll_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declQuad(c+79,"sr64_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 63,0);
    tracep->declBus(c+81,"sr_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+68,"adder_a",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+82,"adder_b",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+83,"adder_cin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+71,"adder_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+84,"adder_cout",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec0 ");
    tracep->declBus(c+29,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declQuad(c+40,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec1 ");
    tracep->declBus(c+30,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+42,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec2 ");
    tracep->declBus(c+31,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+43,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec3 ");
    tracep->declBus(c+32,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+44,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_regfile ");
    tracep->declBit(c+118,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+34,"raddr1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+24,"rdata1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+66,"raddr2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+6,"rdata2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+67,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+85+i*1,"rf",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("data_ram ");
    tracep->declBit(c+118,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+4,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+5,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"d",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"spo",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("debug ");
    tracep->declBus(c+2,"debug_wb_pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+120,"debug_wb_rf_we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+8,"debug_wb_rf_wnum",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"debug_wb_rf_wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("inst_ram ");
    tracep->declBit(c+118,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+123,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+2,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+124,"d",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"spo",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vverilator_top___024root__trace_init_top(Vverilator_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_init_top\n"); );
    // Body
    Vverilator_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
    tracep->pushNamePrefix("verilator_top ");
    Vverilator_top___024root__trace_init_sub__TOP__verilator_top__0(vlSelf, tracep);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vverilator_top___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vverilator_top___024root__trace_chg_top_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vverilator_top___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vverilator_top___024root__trace_register(Vverilator_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vverilator_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vverilator_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vverilator_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vverilator_top___024root__trace_full_sub_0(Vverilator_top___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vverilator_top___024root__trace_full_top_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_full_top_0\n"); );
    // Init
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vverilator_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vverilator_top___024root__trace_full_sub_0(Vverilator_top___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSymsp->TOP__verilator_top.__PVT__cpu_resetn));
    bufp->fullIData(oldp+2,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc),32);
    bufp->fullIData(oldp+3,(vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata),32);
    bufp->fullBit(oldp+4,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                           & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid))));
    bufp->fullIData(oldp+5,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__alu_result),32);
    bufp->fullIData(oldp+6,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rkd_value),32);
    bufp->fullIData(oldp+7,(vlSymsp->TOP__verilator_top.__PVT__cpu_data_rdata),32);
    bufp->fullCData(oldp+8,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__dest),5);
    bufp->fullIData(oldp+9,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rf_wdata),32);
    bufp->fullBit(oldp+10,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__reset));
    bufp->fullBit(oldp+11,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid));
    bufp->fullIData(oldp+12,(((IData)(4U) + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc)),32);
    bufp->fullIData(oldp+13,((((((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0x1aU)) 
                                 & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                | (((~ (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                    & (0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 >> 0x1aU))) 
                                   | ((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 >> 0x1aU)) 
                                      | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0)))) 
                               & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid))
                               ? (((IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0) 
                                   | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0))
                                   ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc 
                                      + (((0x14U == 
                                           (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0x1aU)) 
                                          | (0x15U 
                                             == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
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
    bufp->fullBit(oldp+14,(((((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0x1aU)) 
                              & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                             | (((~ (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd)) 
                                 & (0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                              >> 0x1aU))) 
                                | ((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                              >> 0x1aU)) 
                                   | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0)))) 
                            & (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__valid))));
    bufp->fullIData(oldp+15,((((IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0) 
                               | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h1c4a3e54__0))
                               ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__pc 
                                  + (((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                 >> 0x1aU)) 
                                      | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
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
    bufp->fullSData(oldp+16,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui) 
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
    bufp->fullBit(oldp+17,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc));
    bufp->fullBit(oldp+18,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll) 
                             | (IData)(vlSymsp->TOP__verilator_top.__VdfgTmp_h6e61b208__0)) 
                            | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui) 
                                        | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc))))))));
    bufp->fullBit(oldp+19,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem));
    bufp->fullBit(oldp+20,((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                      >> 0x1aU))));
    bufp->fullBit(oldp+21,(((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0x1aU)) | 
                            ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w) 
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
    bufp->fullBit(oldp+22,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we));
    bufp->fullBit(oldp+23,(((IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0) 
                            | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we))));
    bufp->fullIData(oldp+24,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_value),32);
    bufp->fullIData(oldp+25,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc)
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
    bufp->fullBit(oldp+26,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rj_eq_rd));
    bufp->fullIData(oldp+27,((((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 0x1aU)) 
                               | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0x1aU)))
                               ? (((- (IData)((1U & 
                                               (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                >> 9U)))) 
                                   << 0x1cU) | ((0xffc0000U 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                    << 0x12U)) 
                                                | (0x3fffcU 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                      >> 8U))))
                               : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs)),32);
    bufp->fullIData(oldp+28,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__jirl_offs),32);
    bufp->fullCData(oldp+29,((vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                              >> 0x1aU)),6);
    bufp->fullCData(oldp+30,((0xfU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                      >> 0x16U))),4);
    bufp->fullCData(oldp+31,((3U & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                    >> 0x14U))),2);
    bufp->fullCData(oldp+32,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+33,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata)),5);
    bufp->fullCData(oldp+34,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 5U))),5);
    bufp->fullCData(oldp+35,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0xaU))),5);
    bufp->fullSData(oldp+36,((0xfffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                        >> 0xaU))),12);
    bufp->fullIData(oldp+37,((0xfffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                          >> 5U))),20);
    bufp->fullSData(oldp+38,((0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                         >> 0xaU))),16);
    bufp->fullIData(oldp+39,(((0x3ff0000U & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                             << 0x10U)) 
                              | (0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                            >> 0xaU)))),26);
    bufp->fullQData(oldp+40,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__op_31_26_d),64);
    bufp->fullSData(oldp+42,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__op_25_22_d),16);
    bufp->fullCData(oldp+43,((((3U == (3U & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                             >> 0x14U))) 
                               << 3U) | (((2U == (3U 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                     >> 0x14U))) 
                                          << 2U) | 
                                         (((1U == (3U 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                      >> 0x14U))) 
                                           << 1U) | 
                                          (0U == (3U 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                                     >> 0x14U))))))),4);
    bufp->fullIData(oldp+44,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__op_19_15_d),32);
    bufp->fullBit(oldp+45,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w));
    bufp->fullBit(oldp+46,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sub));
    bufp->fullBit(oldp+47,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_slt));
    bufp->fullBit(oldp+48,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sltu));
    bufp->fullBit(oldp+49,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_nor));
    bufp->fullBit(oldp+50,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_and));
    bufp->fullBit(oldp+51,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_or));
    bufp->fullBit(oldp+52,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_xor));
    bufp->fullBit(oldp+53,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll));
    bufp->fullBit(oldp+54,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_srl));
    bufp->fullBit(oldp+55,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra));
    bufp->fullBit(oldp+56,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w));
    bufp->fullBit(oldp+57,((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                      >> 0x1aU))));
    bufp->fullBit(oldp+58,((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                      >> 0x1aU))));
    bufp->fullBit(oldp+59,((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                      >> 0x1aU))));
    bufp->fullBit(oldp+60,((0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                      >> 0x1aU))));
    bufp->fullBit(oldp+61,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_lui));
    bufp->fullBit(oldp+62,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sll) 
                            | (IData)(vlSymsp->TOP__verilator_top.__VdfgTmp_h6e61b208__0))));
    bufp->fullBit(oldp+63,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                            | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                               | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we)))));
    bufp->fullBit(oldp+64,(((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0x1aU)) | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT____VdfgTmp_h19962199__0))));
    bufp->fullBit(oldp+65,(((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0x1aU)) | 
                            (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata 
                                       >> 0x1aU)))));
    bufp->fullCData(oldp+66,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rf_raddr2),5);
    bufp->fullBit(oldp+67,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__rf_we));
    bufp->fullIData(oldp+68,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a),32);
    bufp->fullIData(oldp+69,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result),32);
    bufp->fullBit(oldp+70,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_add_w) 
                            | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__inst_addi_w) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__res_from_mem) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_we) 
                                     | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__src1_is_pc)))))));
    bufp->fullIData(oldp+71,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__add_sub_result),32);
    bufp->fullIData(oldp+72,((1U & (((~ (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result 
                                         >> 0x1fU)) 
                                     & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                        >> 0x1fU)) 
                                    | ((~ ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                                            ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result) 
                                           >> 0x1fU)) 
                                       & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__add_sub_result 
                                          >> 0x1fU))))),32);
    bufp->fullIData(oldp+73,((1U & (~ (IData)((1ULL 
                                               & (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a)) 
                                                   + 
                                                   ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_b)) 
                                                    + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_cin)))) 
                                                  >> 0x20U)))))),32);
    bufp->fullIData(oldp+74,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                              & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result)),32);
    bufp->fullIData(oldp+75,((~ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__or_result)),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__or_result),32);
    bufp->fullIData(oldp+77,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                              ^ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result)),32);
    bufp->fullIData(oldp+78,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a 
                              << (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result))),32);
    bufp->fullQData(oldp+79,(((((QData)((IData)((- (IData)(
                                                           ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra) 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result 
                                                               >> 0x1fU)))))) 
                                << 0x20U) | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result))) 
                              >> (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a))),64);
    bufp->fullIData(oldp+81,((IData)(((((QData)((IData)(
                                                        (- (IData)(
                                                                   ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__op_sra) 
                                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result 
                                                                       >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__lui_result))) 
                                      >> (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a)))),32);
    bufp->fullIData(oldp+82,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_b),32);
    bufp->fullBit(oldp+83,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_cin));
    bufp->fullBit(oldp+84,((1U & (IData)((1ULL & (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_a)) 
                                                   + 
                                                   ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_b)) 
                                                    + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_alu__DOT__adder_cin)))) 
                                                  >> 0x20U))))));
    bufp->fullIData(oldp+85,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+86,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+87,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+88,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+89,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+90,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+91,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+92,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+93,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+94,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+95,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+96,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+97,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+98,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+99,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+100,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+101,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+103,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+104,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+105,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+106,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+107,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+108,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+109,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+110,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+111,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+112,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+113,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+114,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+115,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+116,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+117,(vlSelf->rst));
    bufp->fullBit(oldp+118,(vlSelf->clk));
    bufp->fullIData(oldp+119,(vlSymsp->TOP__verilator_top.debug_wb_pc),32);
    bufp->fullCData(oldp+120,(vlSymsp->TOP__verilator_top.debug_wb_rf_we),4);
    bufp->fullCData(oldp+121,(vlSymsp->TOP__verilator_top.debug_wb_rf_wnum),5);
    bufp->fullIData(oldp+122,(vlSymsp->TOP__verilator_top.debug_wb_rf_wdata),32);
    bufp->fullBit(oldp+123,(0U));
    bufp->fullIData(oldp+124,(0U),32);
    bufp->fullBit(oldp+125,(vlSymsp->TOP__verilator_top.__PVT__data_sram_en));
    bufp->fullBit(oldp+126,(vlSymsp->TOP__verilator_top.__PVT__data_sram_we));
    bufp->fullIData(oldp+127,(vlSymsp->TOP__verilator_top.__PVT__data_sram_addr),32);
    bufp->fullIData(oldp+128,(vlSymsp->TOP__verilator_top.__PVT__data_sram_wdata),32);
    bufp->fullIData(oldp+129,(vlSymsp->TOP__verilator_top.__PVT__data_sram_rdata),32);
    bufp->fullBit(oldp+130,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__load_op));
}
