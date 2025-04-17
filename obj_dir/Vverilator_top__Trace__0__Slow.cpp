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
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
}

VL_ATTR_COLD void Vverilator_top___024root__trace_init_sub__TOP__verilator_top__0(Vverilator_top___024root* vlSelf, VerilatedFst* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_init_sub__TOP__verilator_top__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+189,"cpu_resetn",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+199,"cpu_inst_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+200,"cpu_inst_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+190,"cpu_inst_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+201,"cpu_inst_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"cpu_inst_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+199,"cpu_data_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+3,"cpu_data_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+4,"cpu_data_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"cpu_data_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"cpu_data_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+191,"debug_wb_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+192,"debug_wb_rf_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+193,"debug_wb_rf_wnum",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+194,"debug_wb_rf_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+202,"data_sram_en",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+203,"data_sram_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+204,"data_sram_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+205,"data_sram_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+206,"data_sram_rdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("cpu ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+189,"resetn",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+199,"inst_sram_en",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+200,"inst_sram_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+190,"inst_sram_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+201,"inst_sram_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"inst_sram_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+199,"data_sram_en",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+3,"data_sram_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+4,"data_sram_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"data_sram_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"data_sram_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"debug_wb_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+192,"debug_wb_rf_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+8,"debug_wb_rf_wnum",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"debug_wb_rf_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+187,"reset",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+190,"preifu_inst_addr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+195,"preifu_next_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+196,"ifu_fs_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+197,"ifu_fs_allowin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+10,"ifu_fs_to_ds_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declQuad(c+11,"idu_bus_br_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 32,0);
    tracep->declBus(c+13,"idu_rf_raddr1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+14,"idu_rf_raddr2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declArray(c+15,"idu_bus_ds_to_es_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 147,0);
    tracep->declBit(c+20,"idu_ds_allowin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+21,"idu_ds_to_es_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declArray(c+22,"exu_bus_exu_to_mem_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 70,0);
    tracep->declBit(c+207,"exu_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+208,"exu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+209,"exu_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+1,"exe_es_allowin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"exe_es_to_ms_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declQuad(c+26,"exu_bus_exu_bypass_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declArray(c+28,"mem_bus_mem_to_wbu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 69,0);
    tracep->declBit(c+210,"mem_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+211,"mem_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+212,"mem_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+199,"mem_ms_allowin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+31,"mem_ms_to_ws_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declQuad(c+32,"mem_bus_mem_bypass_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declBit(c+34,"wbu_rf_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"wbu_rf_waddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"wbu_rf_wdata",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"wbu_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+213,"wbu_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+214,"wbu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+215,"wbu_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+199,"wbu_ws_allowin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declQuad(c+35,"wbu_bus_wbu_bypass_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declBus(c+37,"rf_rdata1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+38,"rf_rdata2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("exu ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declArray(c+15,"bus_ds_to_es_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 147,0);
    tracep->declArray(c+22,"bus_exu_to_mem_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 70,0);
    tracep->declBus(c+4,"data_sram_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"data_sram_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+3,"data_sram_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declQuad(c+26,"bus_exu_bypass_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declBit(c+199,"ms_allowin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+1,"es_allowin",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+21,"ds_to_es_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"es_to_ms_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+39,"exu_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"exu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+40,"exu_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declArray(c+41,"ds_to_es_bus_data_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 147,0);
    tracep->declBit(c+25,"es_valid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+199,"es_ready_go",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+46,"wire_alu_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+47,"wire_alu_src1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"wire_alu_src2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+49,"wire_in_mem_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+5,"wire_in_rkd_value",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+50,"wire_in_res_from_mem",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+51,"wire_in_gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+40,"wire_in_dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+52,"wire_in_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+50,"res_from_mem",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"alu_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+39,"gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+40,"dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+52,"pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->pushNamePrefix("u_alu ");
    tracep->declBus(c+46,"alu_op",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+47,"alu_src1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"alu_src2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+4,"alu_result",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+53,"op_add",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+54,"op_sub",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+55,"op_slt",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+56,"op_sltu",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+57,"op_and",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+58,"op_nor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+59,"op_or",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+60,"op_xor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+61,"op_sll",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+62,"op_srl",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+63,"op_sra",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+64,"op_lui",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+65,"add_sub_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+66,"slt_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+67,"sltu_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+68,"and_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+69,"nor_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+70,"or_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+71,"xor_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+48,"lui_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+72,"sll_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declQuad(c+73,"sr64_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 63,0);
    tracep->declBus(c+75,"sr_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+47,"adder_a",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+76,"adder_b",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+77,"adder_cin",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+65,"adder_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+78,"adder_cout",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("idu ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declQuad(c+11,"bus_br_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 32,0);
    tracep->declBus(c+196,"in_pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+13,"rf_raddr1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+14,"rf_raddr2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+37,"rf_rdata1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+38,"rf_rdata2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"inst_sram_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+15,"bus_ds_to_es_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 147,0);
    tracep->declQuad(c+26,"bus_exu_bypass_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declQuad(c+32,"bus_mem_bypass_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declQuad(c+35,"bus_wbu_bypass_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declBit(c+1,"es_allowin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+20,"ds_allowin",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+10,"fs_to_ds_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+21,"ds_to_es_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+39,"exu_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"exu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+40,"exu_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+79,"mem_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+80,"mem_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+81,"mem_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+34,"wbu_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+9,"wbu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+8,"wbu_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+82,"alu_op",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+83,"alu_src1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+84,"alu_src2",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+85,"mem_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+86,"rkd_value",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+87,"res_from_mem",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+88,"gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+89,"dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+90,"pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+91,"br_taken",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+92,"br_target",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+93,"idu_inst",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+90,"idu_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+94,"src1_is_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+95,"src2_is_imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+96,"dst_is_r1",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+97,"src_reg_is_rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+98,"rj_value",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+99,"imm",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+100,"rj_eq_rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+101,"br_offs",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+102,"jirl_offs",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+103,"op_31_26",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declBus(c+104,"op_25_22",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+105,"op_21_20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+106,"op_19_15",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+107,"rd",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+13,"rj",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+108,"rk",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+109,"i12",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 11,0);
    tracep->declBus(c+110,"i20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 19,0);
    tracep->declBus(c+111,"i16",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBus(c+112,"i26",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 25,0);
    tracep->declQuad(c+113,"op_31_26_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 63,0);
    tracep->declBus(c+115,"op_25_22_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->declBus(c+116,"op_21_20_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+117,"op_19_15_d",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+118,"inst_add_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+119,"inst_sub_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+120,"inst_slt",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+121,"inst_sltu",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+122,"inst_nor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+123,"inst_and",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+124,"inst_or",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+125,"inst_xor",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+126,"inst_slli_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+127,"inst_srli_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+128,"inst_srai_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+129,"inst_addi_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+87,"inst_ld_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+85,"inst_st_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+130,"inst_jirl",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+131,"inst_b",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+96,"inst_bl",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+132,"inst_beq",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+133,"inst_bne",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+134,"inst_lu12i_w",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+135,"need_ui5",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+136,"need_si12",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+137,"need_si16",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+134,"need_si20",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+138,"need_si26",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+94,"src2_is_4",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+139,"is_load",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+140,"load_use_conflict",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+98,"conflict_regaData",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,"conflict_regbData",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,"inst_sram_rdata_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+90,"pc_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+141,"ds_valid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+142,"ds_ready_go",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->pushNamePrefix("u_dec0 ");
    tracep->declBus(c+103,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 5,0);
    tracep->declQuad(c+113,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 63,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec1 ");
    tracep->declBus(c+104,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+115,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 15,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec2 ");
    tracep->declBus(c+105,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 1,0);
    tracep->declBus(c+116,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_dec3 ");
    tracep->declBus(c+106,"in",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+117,"out",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("ifu ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+195,"next_pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+196,"fs_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+20,"ds_allowin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+197,"fs_allowin",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+10,"fs_to_ds_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+196,"pc",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBus(c+216,"inst_ram_data_reg",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 31,0);
    tracep->declBit(c+10,"fs_valid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+199,"fs_ready_go",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+189,"to_fs_valid",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mem ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declArray(c+22,"bus_exu_to_mem_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 70,0);
    tracep->declArray(c+28,"bus_mem_to_wbu_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 69,0);
    tracep->declBus(c+6,"data_sram_rdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declQuad(c+32,"bus_mem_bypass_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declBit(c+199,"ws_allowin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+199,"ms_allowin",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+25,"es_to_ms_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+31,"ms_to_ws_valid",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+79,"mem_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+80,"mem_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+81,"mem_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declArray(c+143,"bus_exu_to_mem_data_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 70,0);
    tracep->declBit(c+31,"ms_valid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+199,"ms_ready_go",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+146,"wire_alu_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+147,"wire_res_from_mem",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+81,"wire_dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+148,"wire_gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+149,"wire_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+79,"gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+81,"dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+149,"pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+80,"final_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"mem_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("pre_ifu ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+196,"fs_pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declQuad(c+11,"bus_br_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 32,0);
    tracep->declBus(c+195,"next_pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+190,"inst_addr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+197,"fs_allowin",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+198,"seq_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+195,"nextpc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+91,"br_taken",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+92,"br_target",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("u_regfile ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+13,"raddr1",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+37,"rdata1",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+14,"raddr2",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+38,"rdata2",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBit(c+34,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"waddr",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+150+i*1,"rf",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, true,(i+0), 31,0);
    }
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("wbu ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+187,"rst",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declArray(c+28,"bus_mem_to_wbu_data",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 69,0);
    tracep->declBit(c+34,"rf_we",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"rf_waddr",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"rf_wdata",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"pc",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declQuad(c+35,"bus_wbu_bypass_data",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 37,0);
    tracep->declBit(c+199,"ws_allowin",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+31,"ms_to_ws_valid",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBit(c+34,"wbu_regWr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+9,"wbu_data",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+8,"wbu_regAddr",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBit(c+182,"wire_gr_we",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+8,"wire_dest",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"wire_final_result",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+7,"wire_pc",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declArray(c+183,"bus_mem_to_wbu_data_r",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1, 69,0);
    tracep->declBit(c+186,"ws_valid",-1, FST_VD_IMPLICIT,FST_VT_SV_LOGIC, false,-1);
    tracep->declBit(c+199,"ws_ready_go",-1, FST_VD_IMPLICIT,FST_VT_VCD_WIRE, false,-1);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("data_ram ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+3,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBit(c+199,"en",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+4,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+5,"d",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+6,"spo",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("debug ");
    tracep->declBus(c+7,"debug_wb_pc",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+192,"debug_wb_rf_we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBus(c+8,"debug_wb_rf_wnum",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 4,0);
    tracep->declBus(c+9,"debug_wb_rf_wdata",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("inst_ram ");
    tracep->declBit(c+188,"clk",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+200,"we",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 3,0);
    tracep->declBit(c+199,"en",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1);
    tracep->declBus(c+190,"a",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+201,"d",-1,FST_VD_INPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
    tracep->declBus(c+2,"spo",-1,FST_VD_OUTPUT,FST_VT_VCD_WIRE, false,-1, 31,0);
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
    VlWide<3>/*95:0*/ __Vtemp_h4ead006d__0;
    VlWide<5>/*159:0*/ __Vtemp_hddfd4d09__0;
    VlWide<5>/*159:0*/ __Vtemp_h16c6ceab__0;
    VlWide<3>/*95:0*/ __Vtemp_hffc645e5__0;
    VlWide<3>/*95:0*/ __Vtemp_h4be78b6d__0;
    // Body
    bufp->fullBit(oldp+1,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exe_es_allowin));
    bufp->fullIData(oldp+2,(vlSymsp->TOP__verilator_top.__PVT__cpu_inst_rdata),32);
    bufp->fullCData(oldp+3,((0xfU & ((0xcU & (((- (IData)(
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
    bufp->fullIData(oldp+4,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_data),32);
    bufp->fullIData(oldp+5,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                              << 0x19U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                           >> 7U))),32);
    bufp->fullIData(oldp+6,(vlSymsp->TOP__verilator_top.__PVT__cpu_data_rdata),32);
    bufp->fullIData(oldp+7,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[0U]),32);
    bufp->fullCData(oldp+8,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])),5);
    bufp->fullIData(oldp+9,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U]),32);
    bufp->fullBit(oldp+10,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__fs_valid));
    bufp->fullQData(oldp+11,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__br_taken)) 
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
    bufp->fullCData(oldp+13,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 5U))),5);
    bufp->fullCData(oldp+14,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_rf_raddr2),5);
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
                                 << 7U) | (IData)((
                                                   (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem)) 
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
    __Vtemp_h16c6ceab__0[4U] = ((0xffffff00U & (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                                 << 0x13U) 
                                                | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w) 
                                                    << 0x12U) 
                                                   | (((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
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
    bufp->fullWData(oldp+15,(__Vtemp_h16c6ceab__0),148);
    bufp->fullBit(oldp+20,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_ds_allowin));
    bufp->fullBit(oldp+21,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_ds_to_es_valid));
    __Vtemp_hffc645e5__0[0U] = (IData)((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
                                         << 0x25U) 
                                        | (0x1fffffffffULL 
                                           & (((QData)((IData)(
                                                               vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]))))));
    __Vtemp_hffc645e5__0[1U] = ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_data 
                                 << 6U) | (IData)((
                                                   (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
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
    bufp->fullWData(oldp+22,(__Vtemp_hffc645e5__0),71);
    bufp->fullBit(oldp+25,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__es_valid));
    bufp->fullQData(oldp+26,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr)) 
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
                                 << 5U) | (0x1fU & 
                                           vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U]));
    bufp->fullWData(oldp+28,(__Vtemp_h4be78b6d__0),70);
    bufp->fullBit(oldp+31,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__ms_valid));
    bufp->fullQData(oldp+32,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_regWr)) 
                               << 0x25U) | (((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_data)) 
                                             << 5U) 
                                            | (QData)((IData)(
                                                              (0x1fU 
                                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U])))))),38);
    bufp->fullBit(oldp+34,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__wbu_regWr));
    bufp->fullQData(oldp+35,((((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__wbu_regWr)) 
                               << 0x25U) | (((QData)((IData)(
                                                             vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[1U])) 
                                             << 5U) 
                                            | (QData)((IData)(
                                                              (0x1fU 
                                                               & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U])))))),38);
    bufp->fullIData(oldp+37,(((0U == (0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                               >> 5U)))
                               ? 0U : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf
                              [(0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                         >> 5U))])),32);
    bufp->fullIData(oldp+38,(((0U == (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_rf_raddr2))
                               ? 0U : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf
                              [vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu_rf_raddr2])),32);
    bufp->fullBit(oldp+39,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr));
    bufp->fullCData(oldp+40,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U])),5);
    bufp->fullWData(oldp+41,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r),148);
    bufp->fullSData(oldp+46,((0xfffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                        >> 8U))),12);
    bufp->fullIData(oldp+47,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                               << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                            >> 8U))),32);
    bufp->fullIData(oldp+48,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                               << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                            >> 8U))),32);
    bufp->fullBit(oldp+49,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                  >> 7U))));
    bufp->fullBit(oldp+50,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                  >> 6U))));
    bufp->fullBit(oldp+51,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[1U] 
                                  >> 5U))));
    bufp->fullIData(oldp+52,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[0U]),32);
    bufp->fullBit(oldp+53,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 8U))));
    bufp->fullBit(oldp+54,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 9U))));
    bufp->fullBit(oldp+55,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0xaU))));
    bufp->fullBit(oldp+56,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0xbU))));
    bufp->fullBit(oldp+57,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0xcU))));
    bufp->fullBit(oldp+58,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0xdU))));
    bufp->fullBit(oldp+59,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0xeU))));
    bufp->fullBit(oldp+60,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0xfU))));
    bufp->fullBit(oldp+61,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0x10U))));
    bufp->fullBit(oldp+62,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0x11U))));
    bufp->fullBit(oldp+63,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0x12U))));
    bufp->fullBit(oldp+64,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                  >> 0x13U))));
    bufp->fullIData(oldp+65,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result),32);
    bufp->fullIData(oldp+66,((1U & (((~ (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                         >> 7U)) & 
                                     (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                      >> 7U)) | ((~ 
                                                  ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                    ^ 
                                                    vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U]) 
                                                   >> 7U)) 
                                                 & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__add_sub_result 
                                                    >> 0x1fU))))),32);
    bufp->fullIData(oldp+67,((1U & (~ (IData)((1ULL 
                                               & (((QData)((IData)(
                                                                   ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                     << 0x18U) 
                                                                    | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                       >> 8U)))) 
                                                   + 
                                                   ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b)) 
                                                    + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)))) 
                                                  >> 0x20U)))))),32);
    bufp->fullIData(oldp+68,((((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                             >> 8U)) 
                              & ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                  << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                               >> 8U)))),32);
    bufp->fullIData(oldp+69,((~ vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result)),32);
    bufp->fullIData(oldp+70,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__or_result),32);
    bufp->fullIData(oldp+71,((((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                             >> 8U)) 
                              ^ ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                  << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                               >> 8U)))),32);
    bufp->fullIData(oldp+72,((((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                << 0x18U) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                             >> 8U)) 
                              << (0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                           >> 8U)))),32);
    bufp->fullQData(oldp+73,(((((QData)((IData)((- (IData)((IData)(
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
    bufp->fullIData(oldp+75,((IData)(((((QData)((IData)(
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
                                      >> (0x1fU & (
                                                   vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[2U] 
                                                   >> 8U))))),32);
    bufp->fullIData(oldp+76,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b),32);
    bufp->fullBit(oldp+77,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin));
    bufp->fullBit(oldp+78,((1U & (IData)((1ULL & (((QData)((IData)(
                                                                   ((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[4U] 
                                                                     << 0x18U) 
                                                                    | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__ds_to_es_bus_data_r[3U] 
                                                                       >> 8U)))) 
                                                   + 
                                                   ((QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_b)) 
                                                    + (QData)((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__u_alu__DOT__adder_cin)))) 
                                                  >> 0x20U))))));
    bufp->fullBit(oldp+79,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_regWr));
    bufp->fullIData(oldp+80,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_data),32);
    bufp->fullCData(oldp+81,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U])),5);
    bufp->fullSData(oldp+82,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
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
    bufp->fullIData(oldp+83,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
                               ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg
                               : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData)),32);
    bufp->fullIData(oldp+84,(((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
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
                                            : (((- (IData)(
                                                           (1U 
                                                            & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                               >> 0x15U)))) 
                                                << 0xcU) 
                                               | (0xfffU 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     >> 0xaU)))))
                               : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData)),32);
    bufp->fullBit(oldp+85,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we));
    bufp->fullIData(oldp+86,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regbData),32);
    bufp->fullBit(oldp+87,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem));
    bufp->fullBit(oldp+88,(((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x1aU)) | 
                            ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w) 
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
    bufp->fullCData(oldp+89,(((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                         >> 0x1aU))
                               ? 1U : (0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg))),5);
    bufp->fullIData(oldp+90,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg),32);
    bufp->fullBit(oldp+91,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__br_taken));
    bufp->fullIData(oldp+92,((((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                               | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h1c4a3e54__0))
                               ? (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__pc_reg 
                                  + (((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                 >> 0x1aU)) 
                                      | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
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
    bufp->fullIData(oldp+93,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg),32);
    bufp->fullBit(oldp+94,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc));
    bufp->fullBit(oldp+95,((((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w))) 
                            | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                               | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                  | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we) 
                                     | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w) 
                                        | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc))))))));
    bufp->fullBit(oldp+96,((0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                      >> 0x1aU))));
    bufp->fullBit(oldp+97,(((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0) 
                            | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we))));
    bufp->fullIData(oldp+98,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__conflict_regaData),32);
    bufp->fullIData(oldp+99,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__src1_is_pc)
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
    bufp->fullBit(oldp+100,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__rj_eq_rd));
    bufp->fullIData(oldp+101,((((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 0x1aU)) 
                                | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 0x1aU)))
                                ? (((- (IData)((1U 
                                                & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                   >> 9U)))) 
                                    << 0x1cU) | ((0xffc0000U 
                                                  & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                     << 0x12U)) 
                                                 | (0x3fffcU 
                                                    & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                       >> 8U))))
                                : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs)),32);
    bufp->fullIData(oldp+102,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__jirl_offs),32);
    bufp->fullCData(oldp+103,((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                               >> 0x1aU)),6);
    bufp->fullCData(oldp+104,((0xfU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x16U))),4);
    bufp->fullCData(oldp+105,((3U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                     >> 0x14U))),2);
    bufp->fullCData(oldp+106,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+107,((0x1fU & vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg)),5);
    bufp->fullCData(oldp+108,((0x1fU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0xaU))),5);
    bufp->fullSData(oldp+109,((0xfffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                         >> 0xaU))),12);
    bufp->fullIData(oldp+110,((0xfffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                           >> 5U))),20);
    bufp->fullSData(oldp+111,((0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0xaU))),16);
    bufp->fullIData(oldp+112,(((0x3ff0000U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              << 0x10U)) 
                               | (0xffffU & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                             >> 0xaU)))),26);
    bufp->fullQData(oldp+113,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__op_31_26_d),64);
    bufp->fullSData(oldp+115,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__op_25_22_d),16);
    bufp->fullCData(oldp+116,((((3U == (3U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                              >> 0x14U))) 
                                << 3U) | (((2U == (3U 
                                                   & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                      >> 0x14U))) 
                                           << 2U) | 
                                          (((1U == 
                                             (3U & 
                                              (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                               >> 0x14U))) 
                                            << 1U) 
                                           | (0U == 
                                              (3U & 
                                               (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                >> 0x14U))))))),4);
    bufp->fullIData(oldp+117,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__op_19_15_d),32);
    bufp->fullBit(oldp+118,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_add_w));
    bufp->fullBit(oldp+119,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sub_w));
    bufp->fullBit(oldp+120,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slt));
    bufp->fullBit(oldp+121,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sltu));
    bufp->fullBit(oldp+122,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_nor));
    bufp->fullBit(oldp+123,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_and));
    bufp->fullBit(oldp+124,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_or));
    bufp->fullBit(oldp+125,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_xor));
    bufp->fullBit(oldp+126,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w));
    bufp->fullBit(oldp+127,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w));
    bufp->fullBit(oldp+128,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w));
    bufp->fullBit(oldp+129,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w));
    bufp->fullBit(oldp+130,((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x1aU))));
    bufp->fullBit(oldp+131,((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x1aU))));
    bufp->fullBit(oldp+132,((0x16U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x1aU))));
    bufp->fullBit(oldp+133,((0x17U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                       >> 0x1aU))));
    bufp->fullBit(oldp+134,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_lu12i_w));
    bufp->fullBit(oldp+135,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_slli_w) 
                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srli_w) 
                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_srai_w)))));
    bufp->fullBit(oldp+136,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_addi_w) 
                             | ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__res_from_mem) 
                                | (IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__mem_we)))));
    bufp->fullBit(oldp+137,(((0x13U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0x1aU)) 
                             | (IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h19962199__0))));
    bufp->fullBit(oldp+138,(((0x14U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                        >> 0x1aU)) 
                             | (0x15U == (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                          >> 0x1aU)))));
    bufp->fullBit(oldp+139,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__is_load));
    bufp->fullBit(oldp+140,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__is_load) 
                             & ((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu__DOT__exu_regWr) 
                                & ((IData)(vlSymsp->TOP__verilator_top.cpu__DOT__idu__DOT____VdfgTmp_h3372f28b__0) 
                                   & (0U != (0x1fU 
                                             & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__inst_sram_rdata_reg 
                                                >> 5U))))))));
    bufp->fullBit(oldp+141,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__ds_valid));
    bufp->fullBit(oldp+142,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__idu__DOT__ds_ready_go));
    bufp->fullWData(oldp+143,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r),71);
    bufp->fullIData(oldp+146,(((vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                << 0x1aU) | (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                             >> 6U))),32);
    bufp->fullBit(oldp+147,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[2U] 
                                   >> 6U))));
    bufp->fullBit(oldp+148,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[1U] 
                                   >> 5U))));
    bufp->fullIData(oldp+149,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem__DOT__bus_exu_to_mem_data_r[0U]),32);
    bufp->fullIData(oldp+150,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[0]),32);
    bufp->fullIData(oldp+151,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[1]),32);
    bufp->fullIData(oldp+152,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[2]),32);
    bufp->fullIData(oldp+153,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[3]),32);
    bufp->fullIData(oldp+154,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[4]),32);
    bufp->fullIData(oldp+155,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[5]),32);
    bufp->fullIData(oldp+156,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[6]),32);
    bufp->fullIData(oldp+157,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[7]),32);
    bufp->fullIData(oldp+158,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[8]),32);
    bufp->fullIData(oldp+159,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[9]),32);
    bufp->fullIData(oldp+160,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[10]),32);
    bufp->fullIData(oldp+161,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[11]),32);
    bufp->fullIData(oldp+162,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[12]),32);
    bufp->fullIData(oldp+163,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[13]),32);
    bufp->fullIData(oldp+164,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[14]),32);
    bufp->fullIData(oldp+165,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[15]),32);
    bufp->fullIData(oldp+166,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[16]),32);
    bufp->fullIData(oldp+167,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[17]),32);
    bufp->fullIData(oldp+168,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[18]),32);
    bufp->fullIData(oldp+169,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[19]),32);
    bufp->fullIData(oldp+170,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[20]),32);
    bufp->fullIData(oldp+171,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[21]),32);
    bufp->fullIData(oldp+172,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[22]),32);
    bufp->fullIData(oldp+173,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[23]),32);
    bufp->fullIData(oldp+174,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[24]),32);
    bufp->fullIData(oldp+175,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[25]),32);
    bufp->fullIData(oldp+176,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[26]),32);
    bufp->fullIData(oldp+177,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[27]),32);
    bufp->fullIData(oldp+178,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[28]),32);
    bufp->fullIData(oldp+179,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[29]),32);
    bufp->fullIData(oldp+180,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[30]),32);
    bufp->fullIData(oldp+181,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__u_regfile__DOT__rf[31]),32);
    bufp->fullBit(oldp+182,((1U & (vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r[2U] 
                                   >> 5U))));
    bufp->fullWData(oldp+183,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__bus_mem_to_wbu_data_r),70);
    bufp->fullBit(oldp+186,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu__DOT__ws_valid));
    bufp->fullBit(oldp+187,(vlSelf->rst));
    bufp->fullBit(oldp+188,(vlSelf->clk));
    bufp->fullBit(oldp+189,((1U & (~ (IData)(vlSelf->rst)))));
    bufp->fullIData(oldp+190,(((IData)(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu_fs_allowin)
                                ? vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__preifu_next_pc
                                : vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__pc)),32);
    bufp->fullIData(oldp+191,(vlSymsp->TOP__verilator_top.debug_wb_pc),32);
    bufp->fullCData(oldp+192,(vlSymsp->TOP__verilator_top.debug_wb_rf_we),4);
    bufp->fullCData(oldp+193,(vlSymsp->TOP__verilator_top.debug_wb_rf_wnum),5);
    bufp->fullIData(oldp+194,(vlSymsp->TOP__verilator_top.debug_wb_rf_wdata),32);
    bufp->fullIData(oldp+195,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__preifu_next_pc),32);
    bufp->fullIData(oldp+196,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__pc),32);
    bufp->fullBit(oldp+197,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu_fs_allowin));
    bufp->fullIData(oldp+198,(((IData)(4U) + vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__pc)),32);
    bufp->fullBit(oldp+199,(1U));
    bufp->fullCData(oldp+200,(0U),4);
    bufp->fullIData(oldp+201,(0U),32);
    bufp->fullBit(oldp+202,(vlSymsp->TOP__verilator_top.__PVT__data_sram_en));
    bufp->fullBit(oldp+203,(vlSymsp->TOP__verilator_top.__PVT__data_sram_we));
    bufp->fullIData(oldp+204,(vlSymsp->TOP__verilator_top.__PVT__data_sram_addr),32);
    bufp->fullIData(oldp+205,(vlSymsp->TOP__verilator_top.__PVT__data_sram_wdata),32);
    bufp->fullIData(oldp+206,(vlSymsp->TOP__verilator_top.__PVT__data_sram_rdata),32);
    bufp->fullBit(oldp+207,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu_regWr));
    bufp->fullIData(oldp+208,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu_data),32);
    bufp->fullCData(oldp+209,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__exu_regAddr),5);
    bufp->fullBit(oldp+210,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_regWr));
    bufp->fullIData(oldp+211,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_data),32);
    bufp->fullCData(oldp+212,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__mem_regAddr),5);
    bufp->fullBit(oldp+213,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu_regWr));
    bufp->fullIData(oldp+214,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu_data),32);
    bufp->fullCData(oldp+215,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__wbu_regAddr),5);
    bufp->fullIData(oldp+216,(vlSymsp->TOP__verilator_top.__PVT__cpu__DOT__ifu__DOT__inst_ram_data_reg),32);
}
