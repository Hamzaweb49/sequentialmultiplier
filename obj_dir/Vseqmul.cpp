// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vseqmul.h for the primary calling header

#include "Vseqmul.h"
#include "Vseqmul__Syms.h"

//==========

void Vseqmul::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vseqmul::eval\n"); );
    Vseqmul__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("seqmul.v", 119, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vseqmul::_eval_initial_loop(Vseqmul__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("seqmul.v", 119, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__2(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__2\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (vlTOPp->Datapath__02Ereset) {
        vlTOPp->Datapath__DOT__shift_inst__DOT__carry_reg = 0U;
    } else {
        if (vlTOPp->Datapath__02Eshift_signal) {
            vlTOPp->Datapath__DOT__shift_inst__DOT__carry_reg = 0U;
        }
    }
    if ((1U & (~ (IData)(vlTOPp->Datapath__02Ereset)))) {
        if (vlTOPp->Datapath__02Eshift_signal) {
            vlTOPp->Datapath__DOT__shift_multiplier 
                = (0xffffU & ((IData)(vlTOPp->Datapath__02Emultiplier) 
                              >> 1U));
        }
    }
    if (vlTOPp->Datapath__02Ereset) {
        vlTOPp->Datapath__DOT__shift_inst__DOT__shift_reg = 0U;
    } else {
        if (vlTOPp->Datapath__02Eshift_signal) {
            vlTOPp->Datapath__DOT__shift_inst__DOT__shift_reg 
                = (0xffffU & ((IData)(vlTOPp->Datapath__DOT__intermediate_accumulator) 
                              >> 1U));
        }
    }
    vlTOPp->product = (((IData)(vlTOPp->Datapath__DOT__shift_inst__DOT__shift_reg) 
                        << 0x10U) | (IData)(vlTOPp->Datapath__DOT__shift_multiplier));
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__3(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__3\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*1:0*/ __Vdly__Controller__DOT__state;
    CData/*3:0*/ __Vdly__Controller__DOT__count;
    CData/*0:0*/ __Vdly__Controller__02Eadd_signal;
    CData/*0:0*/ __Vdly__Controller__02Emux_signal;
    // Body
    __Vdly__Controller__DOT__count = vlTOPp->Controller__DOT__count;
    __Vdly__Controller__DOT__state = vlTOPp->Controller__DOT__state;
    __Vdly__Controller__02Emux_signal = vlTOPp->Controller__02Emux_signal;
    __Vdly__Controller__02Eadd_signal = vlTOPp->Controller__02Eadd_signal;
    if (vlTOPp->Controller__02Ereset) {
        __Vdly__Controller__DOT__state = 0U;
        __Vdly__Controller__DOT__count = 0U;
        __Vdly__Controller__02Eadd_signal = 0U;
        vlTOPp->Controller__02Eshift_signal = 0U;
        __Vdly__Controller__02Emux_signal = 0U;
    } else {
        if ((2U & (IData)(vlTOPp->Controller__DOT__state))) {
            if ((1U & (IData)(vlTOPp->Controller__DOT__state))) {
                __Vdly__Controller__DOT__state = 0U;
            } else {
                __Vdly__Controller__DOT__count = (0xfU 
                                                  & ((IData)(1U) 
                                                     + (IData)(vlTOPp->Controller__DOT__count)));
                vlTOPp->Controller__02Eshift_signal = 1U;
                __Vdly__Controller__DOT__state = 1U;
            }
        } else {
            if ((1U & (IData)(vlTOPp->Controller__DOT__state))) {
                vlTOPp->Controller__02Emux_signal = 
                    (1U & (IData)(vlTOPp->Controller__02Emultiplier));
                vlTOPp->Controller__02Eadd_signal = 1U;
                __Vdly__Controller__DOT__state = 2U;
            } else {
                if (vlTOPp->Controller__02Estart) {
                    __Vdly__Controller__DOT__state = 1U;
                    __Vdly__Controller__DOT__count = 0U;
                    __Vdly__Controller__02Eadd_signal = 0U;
                    vlTOPp->Controller__02Eshift_signal = 0U;
                    __Vdly__Controller__02Emux_signal = 0U;
                }
            }
        }
    }
    vlTOPp->Controller__DOT__state = __Vdly__Controller__DOT__state;
    vlTOPp->Controller__DOT__count = __Vdly__Controller__DOT__count;
    vlTOPp->Controller__02Eadd_signal = __Vdly__Controller__02Eadd_signal;
    vlTOPp->Controller__02Emux_signal = __Vdly__Controller__02Emux_signal;
}

VL_INLINE_OPT void Vseqmul::_sequent__TOP__5(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_sequent__TOP__5\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->Datapath__DOT__intermediate_accumulator 
        = ((IData)(vlTOPp->Datapath__02Eadd_signal)
            ? (((IData)(vlTOPp->Datapath__02Emux_signal)
                 ? (IData)(vlTOPp->multiplicand) : 0U) 
               ^ (IData)(vlTOPp->accumulator)) : (IData)(vlTOPp->accumulator));
}

void Vseqmul::_eval(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->Datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Eclk))) 
         | ((IData)(vlTOPp->Datapath__02Ereset) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Ereset))))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlTOPp->Controller__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Controller__02Eclk))) 
         | ((IData)(vlTOPp->Controller__02Ereset) & 
            (~ (IData)(vlTOPp->__Vclklast__TOP__Controller__02Ereset))))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if (((IData)(vlTOPp->Datapath__02Eclk) & (~ (IData)(vlTOPp->__Vclklast__TOP__Datapath__02Eclk)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__Datapath__02Eclk = vlTOPp->Datapath__02Eclk;
    vlTOPp->__Vclklast__TOP__Datapath__02Ereset = vlTOPp->Datapath__02Ereset;
    vlTOPp->__Vclklast__TOP__Controller__02Eclk = vlTOPp->Controller__02Eclk;
    vlTOPp->__Vclklast__TOP__Controller__02Ereset = vlTOPp->Controller__02Ereset;
}

VL_INLINE_OPT QData Vseqmul::_change_request(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_change_request\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vseqmul::_change_request_1(Vseqmul__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_change_request_1\n"); );
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vseqmul::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vseqmul::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((Controller__02Eclk & 0xfeU))) {
        Verilated::overWidthError("Controller.clk");}
    if (VL_UNLIKELY((Controller__02Ereset & 0xfeU))) {
        Verilated::overWidthError("Controller.reset");}
    if (VL_UNLIKELY((Controller__02Estart & 0xfeU))) {
        Verilated::overWidthError("Controller.start");}
    if (VL_UNLIKELY((Datapath__02Eclk & 0xfeU))) {
        Verilated::overWidthError("Datapath.clk");}
    if (VL_UNLIKELY((Datapath__02Ereset & 0xfeU))) {
        Verilated::overWidthError("Datapath.reset");}
    if (VL_UNLIKELY((Datapath__02Estart & 0xfeU))) {
        Verilated::overWidthError("Datapath.start");}
    if (VL_UNLIKELY((Datapath__02Eadd_signal & 0xfeU))) {
        Verilated::overWidthError("Datapath.add_signal");}
    if (VL_UNLIKELY((Datapath__02Eshift_signal & 0xfeU))) {
        Verilated::overWidthError("Datapath.shift_signal");}
    if (VL_UNLIKELY((Datapath__02Emux_signal & 0xfeU))) {
        Verilated::overWidthError("Datapath.mux_signal");}
}
#endif  // VL_DEBUG
