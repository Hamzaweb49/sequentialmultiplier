// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSEQMUL_H_
#define _VSEQMUL_H_  // guard

#include "verilated.h"

//==========

class Vseqmul__Syms;
class Vseqmul_VerilatedVcd;


//----------

VL_MODULE(Vseqmul) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(Controller__02Eclk,0,0);
    VL_IN8(Controller__02Ereset,0,0);
    VL_IN8(Datapath__02Eclk,0,0);
    VL_IN8(Datapath__02Ereset,0,0);
    VL_IN8(Controller__02Estart,0,0);
    VL_OUT8(Controller__02Eadd_signal,0,0);
    VL_OUT8(Controller__02Eshift_signal,0,0);
    VL_OUT8(Controller__02Emux_signal,0,0);
    VL_IN8(Datapath__02Estart,0,0);
    VL_IN8(Datapath__02Eadd_signal,0,0);
    VL_IN8(Datapath__02Eshift_signal,0,0);
    VL_IN8(Datapath__02Emux_signal,0,0);
    VL_IN16(Controller__02Emultiplier,15,0);
    VL_IN16(multiplicand,15,0);
    VL_IN16(accumulator,15,0);
    VL_IN16(Datapath__02Emultiplier,15,0);
    VL_OUT(product,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ Controller__DOT__state;
    CData/*3:0*/ Controller__DOT__count;
    CData/*0:0*/ Datapath__DOT__carryin;
    CData/*0:0*/ Datapath__DOT__carryout;
    CData/*0:0*/ Datapath__DOT__shiftcarry;
    SData/*15:0*/ Datapath__DOT__shift_accumulator;
    SData/*15:0*/ Datapath__DOT__mux_output;
    SData/*15:0*/ Datapath__DOT__intermediate_accumulator;
    SData/*15:0*/ Datapath__DOT__shift_multiplier;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__Datapath__02Ereset;
    CData/*0:0*/ __Vclklast__TOP__Datapath__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__Controller__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__Controller__02Ereset;
    CData/*0:0*/ __Vm_traceActivity[1];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vseqmul__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vseqmul);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vseqmul(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vseqmul();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vseqmul__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vseqmul__Syms* symsp, bool first);
  private:
    static QData _change_request(Vseqmul__Syms* __restrict vlSymsp);
    static QData _change_request_1(Vseqmul__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__7(Vseqmul__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vseqmul__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vseqmul__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vseqmul__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(Vseqmul__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vseqmul__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(Vseqmul__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vseqmul__Syms* __restrict vlSymsp);
    static void _sequent__TOP__8(Vseqmul__Syms* __restrict vlSymsp);
    static void _settle__TOP__5(Vseqmul__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
