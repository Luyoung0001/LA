// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VVERILATOR_TOP__SYMS_H_
#define VERILATED_VVERILATOR_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vverilator_top.h"

// INCLUDE MODULE CLASSES
#include "Vverilator_top___024root.h"
#include "Vverilator_top_verilator_top.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class Vverilator_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vverilator_top* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vverilator_top___024root       TOP;
    Vverilator_top_verilator_top   TOP__verilator_top;

    // SCOPE NAMES
    VerilatedScope __Vscope_verilator_top;

    // CONSTRUCTORS
    Vverilator_top__Syms(VerilatedContext* contextp, const char* namep, Vverilator_top* modelp);
    ~Vverilator_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
