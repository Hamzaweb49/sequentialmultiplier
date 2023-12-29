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
        tracep->chgBit(oldp+0,(vlTOPp->Controller__02Eclk));
        tracep->chgBit(oldp+1,(vlTOPp->Controller__02Ereset));
        tracep->chgBit(oldp+2,(vlTOPp->Controller__02Estart));
        tracep->chgSData(oldp+3,(vlTOPp->Controller__02Emultiplier),16);
        tracep->chgBit(oldp+4,(vlTOPp->Controller__02Eadd_signal));
        tracep->chgBit(oldp+5,(vlTOPp->Controller__02Eshift_signal));
        tracep->chgBit(oldp+6,(vlTOPp->Controller__02Emux_signal));
        tracep->chgBit(oldp+7,(vlTOPp->Datapath__02Eclk));
        tracep->chgBit(oldp+8,(vlTOPp->Datapath__02Ereset));
        tracep->chgBit(oldp+9,(vlTOPp->Datapath__02Estart));
        tracep->chgBit(oldp+10,(vlTOPp->Datapath__02Eadd_signal));
        tracep->chgBit(oldp+11,(vlTOPp->Datapath__02Eshift_signal));
        tracep->chgBit(oldp+12,(vlTOPp->Datapath__02Emux_signal));
        tracep->chgSData(oldp+13,(vlTOPp->multiplicand),16);
        tracep->chgSData(oldp+14,(vlTOPp->accumulator),16);
        tracep->chgSData(oldp+15,(vlTOPp->Datapath__02Emultiplier),16);
        tracep->chgIData(oldp+16,(vlTOPp->product),32);
        tracep->chgCData(oldp+17,(vlTOPp->Controller__DOT__state),2);
        tracep->chgCData(oldp+18,(vlTOPp->Controller__DOT__count),4);
        tracep->chgSData(oldp+19,(vlTOPp->Datapath__DOT__shift_accumulator),16);
        tracep->chgSData(oldp+20,(vlTOPp->Datapath__DOT__mux_output),16);
        tracep->chgSData(oldp+21,(vlTOPp->Datapath__DOT__intermediate_accumulator),16);
        tracep->chgSData(oldp+22,(vlTOPp->Datapath__DOT__shift_multiplier),16);
        tracep->chgBit(oldp+23,(vlTOPp->Datapath__DOT__carryin));
        tracep->chgBit(oldp+24,(vlTOPp->Datapath__DOT__carryout));
        tracep->chgBit(oldp+25,(vlTOPp->Datapath__DOT__shiftcarry));
    }
}

void Vseqmul::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
