// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vverilator_top.h"
#include "Vverilator_top__Syms.h"
#include "verilated_fst_c.h"
#include "verilated_dpi.h"

//============================================================
// Constructors

Vverilator_top::Vverilator_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vverilator_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , verilator_top{vlSymsp->TOP.verilator_top}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vverilator_top::Vverilator_top(const char* _vcname__)
    : Vverilator_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vverilator_top::~Vverilator_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vverilator_top___024root___eval_debug_assertions(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vverilator_top___024root___eval_static(Vverilator_top___024root* vlSelf);
void Vverilator_top___024root___eval_initial(Vverilator_top___024root* vlSelf);
void Vverilator_top___024root___eval_settle(Vverilator_top___024root* vlSelf);
void Vverilator_top___024root___eval(Vverilator_top___024root* vlSelf);

void Vverilator_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vverilator_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vverilator_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vverilator_top___024root___eval_static(&(vlSymsp->TOP));
        Vverilator_top___024root___eval_initial(&(vlSymsp->TOP));
        Vverilator_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vverilator_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vverilator_top::eventsPending() { return false; }

uint64_t Vverilator_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vverilator_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vverilator_top___024root___eval_final(Vverilator_top___024root* vlSelf);

VL_ATTR_COLD void Vverilator_top::final() {
    Vverilator_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vverilator_top::hierName() const { return vlSymsp->name(); }
const char* Vverilator_top::modelName() const { return "Vverilator_top"; }
unsigned Vverilator_top::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vverilator_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vverilator_top___024root__trace_init_top(Vverilator_top___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vverilator_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vverilator_top___024root__trace_register(Vverilator_top___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vverilator_top::trace(VerilatedFstC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vverilator_top::trace()' shall not be called after 'VerilatedFstC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vverilator_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
