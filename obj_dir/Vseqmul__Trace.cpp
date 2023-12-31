// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vseqmul__Syms.h"


void Vseqmul::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vseqmul::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+0,(vlTOPp->TopModule__DOT__shift_signal_int));
            tracep->chgBit(oldp+1,(vlTOPp->TopModule__DOT__mux_signal_int));
            tracep->chgSData(oldp+2,(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_accumulator),16);
            tracep->chgSData(oldp+3,(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_multiplier),16);
            tracep->chgBit(oldp+4,(vlTOPp->TopModule__DOT__dp_inst__DOT__shiftcarry));
            tracep->chgBit(oldp+5,(vlTOPp->TopModule__DOT__dp_inst__DOT__shift_done));
            tracep->chgCData(oldp+6,(vlTOPp->TopModule__DOT__ctrl_inst__DOT__state),2);
            tracep->chgCData(oldp+7,(vlTOPp->TopModule__DOT__ctrl_inst__DOT__count),4);
        }
        tracep->chgBit(oldp+8,(vlTOPp->clk));
        tracep->chgBit(oldp+9,(vlTOPp->reset));
        tracep->chgBit(oldp+10,(vlTOPp->start));
        tracep->chgSData(oldp+11,(vlTOPp->multiplier),16);
        tracep->chgSData(oldp+12,(vlTOPp->multiplicand),16);
        tracep->chgSData(oldp+13,(vlTOPp->accumulator),16);
        tracep->chgBit(oldp+14,(vlTOPp->add_signal));
        tracep->chgBit(oldp+15,(vlTOPp->shift_signal));
        tracep->chgBit(oldp+16,(vlTOPp->mux_signal));
        tracep->chgIData(oldp+17,(vlTOPp->product),32);
        tracep->chgBit(oldp+18,(vlTOPp->TopModule__DOT__add_signal_int));
        tracep->chgSData(oldp+19,(vlTOPp->TopModule__DOT__top_multiplier),16);
        tracep->chgSData(oldp+20,(vlTOPp->TopModule__DOT__top_accumulator),16);
        tracep->chgSData(oldp+21,(vlTOPp->TopModule__DOT__dp_inst__DOT__mux_output),16);
        tracep->chgSData(oldp+22,(vlTOPp->TopModule__DOT__dp_inst__DOT__intermediate_accumulator),16);
        tracep->chgBit(oldp+23,(vlTOPp->TopModule__DOT__dp_inst__DOT__carryin));
        tracep->chgBit(oldp+24,(vlTOPp->TopModule__DOT__dp_inst__DOT__carryout));
    }
}

void Vseqmul::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
