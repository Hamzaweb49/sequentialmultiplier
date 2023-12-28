// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vseqmul__Syms.h"


//======================

void Vseqmul::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vseqmul::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vseqmul::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vseqmul::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vseqmul::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+4,"Controller.clk", false,-1);
        tracep->declBit(c+5,"Controller.reset", false,-1);
        tracep->declBit(c+6,"Controller.start", false,-1);
        tracep->declBus(c+7,"Controller.multiplier", false,-1, 15,0);
        tracep->declBit(c+8,"Controller.add_signal", false,-1);
        tracep->declBit(c+9,"Controller.shift_signal", false,-1);
        tracep->declBit(c+10,"Controller.mux_signal", false,-1);
        tracep->declBit(c+11,"Datapath.clk", false,-1);
        tracep->declBit(c+12,"Datapath.reset", false,-1);
        tracep->declBit(c+13,"Datapath.start", false,-1);
        tracep->declBit(c+14,"Datapath.add_signal", false,-1);
        tracep->declBit(c+15,"Datapath.shift_signal", false,-1);
        tracep->declBit(c+16,"Datapath.mux_signal", false,-1);
        tracep->declBus(c+17,"multiplicand", false,-1, 15,0);
        tracep->declBus(c+18,"accumulator", false,-1, 15,0);
        tracep->declBus(c+19,"Datapath.multiplier", false,-1, 15,0);
        tracep->declBus(c+20,"product", false,-1, 31,0);
        tracep->declBit(c+4,"Controller clk", false,-1);
        tracep->declBit(c+5,"Controller reset", false,-1);
        tracep->declBit(c+6,"Controller start", false,-1);
        tracep->declBus(c+7,"Controller multiplier", false,-1, 15,0);
        tracep->declBit(c+8,"Controller add_signal", false,-1);
        tracep->declBit(c+9,"Controller shift_signal", false,-1);
        tracep->declBit(c+10,"Controller mux_signal", false,-1);
        tracep->declBus(c+25,"Controller IDLE", false,-1, 1,0);
        tracep->declBus(c+26,"Controller ADD", false,-1, 1,0);
        tracep->declBus(c+27,"Controller SHIFT", false,-1, 1,0);
        tracep->declBus(c+28,"Controller FINISH", false,-1, 1,0);
        tracep->declBus(c+21,"Controller state", false,-1, 1,0);
        tracep->declBus(c+22,"Controller count", false,-1, 3,0);
        tracep->declBit(c+11,"Datapath clk", false,-1);
        tracep->declBit(c+12,"Datapath reset", false,-1);
        tracep->declBit(c+13,"Datapath start", false,-1);
        tracep->declBit(c+14,"Datapath add_signal", false,-1);
        tracep->declBit(c+15,"Datapath shift_signal", false,-1);
        tracep->declBit(c+16,"Datapath mux_signal", false,-1);
        tracep->declBus(c+17,"Datapath multiplicand", false,-1, 15,0);
        tracep->declBus(c+18,"Datapath accumulator", false,-1, 15,0);
        tracep->declBus(c+19,"Datapath multiplier", false,-1, 15,0);
        tracep->declBus(c+20,"Datapath product", false,-1, 31,0);
        tracep->declBus(c+1,"Datapath shift_reg_shift", false,-1, 15,0);
        tracep->declBus(c+23,"Datapath shift_reg_mux", false,-1, 15,0);
        tracep->declBus(c+24,"Datapath intermediate_accumulator", false,-1, 15,0);
        tracep->declBus(c+2,"Datapath shift_multiplier", false,-1, 15,0);
        tracep->declBit(c+3,"Datapath carry", false,-1);
        tracep->declBus(c+17,"Datapath mux_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+29,"Datapath mux_inst zeros", false,-1, 15,0);
        tracep->declBit(c+16,"Datapath mux_inst mux_signal", false,-1);
        tracep->declBus(c+23,"Datapath mux_inst selected_input", false,-1, 15,0);
        tracep->declBit(c+11,"Datapath add_inst clk", false,-1);
        tracep->declBus(c+23,"Datapath add_inst multiplicand", false,-1, 15,0);
        tracep->declBus(c+18,"Datapath add_inst accumulator", false,-1, 15,0);
        tracep->declBit(c+14,"Datapath add_inst add_signal", false,-1);
        tracep->declBus(c+24,"Datapath add_inst accumulator_out", false,-1, 15,0);
        tracep->declBit(c+11,"Datapath shift_inst clk", false,-1);
        tracep->declBit(c+12,"Datapath shift_inst reset", false,-1);
        tracep->declBit(c+15,"Datapath shift_inst enable", false,-1);
        tracep->declBus(c+24,"Datapath shift_inst accumulator", false,-1, 15,0);
        tracep->declBus(c+19,"Datapath shift_inst multiplier", false,-1, 15,0);
        tracep->declBus(c+3,"Datapath shift_inst carry", false,-1, 0,0);
        tracep->declBus(c+1,"Datapath shift_inst accumulator_out", false,-1, 15,0);
        tracep->declBus(c+2,"Datapath shift_inst multiplier_out", false,-1, 15,0);
        tracep->declBus(c+3,"Datapath shift_inst carry_out", false,-1, 0,0);
        tracep->declBus(c+1,"Datapath shift_inst shift_reg", false,-1, 15,0);
        tracep->declBit(c+3,"Datapath shift_inst carry_reg", false,-1);
    }
}

void Vseqmul::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vseqmul::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vseqmul::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vseqmul__Syms* __restrict vlSymsp = static_cast<Vseqmul__Syms*>(userp);
    Vseqmul* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullSData(oldp+1,(vlTOPp->Datapath__DOT__shift_inst__DOT__shift_reg),16);
        tracep->fullSData(oldp+2,(vlTOPp->Datapath__DOT__shift_multiplier),16);
        tracep->fullBit(oldp+3,(vlTOPp->Datapath__DOT__shift_inst__DOT__carry_reg));
        tracep->fullBit(oldp+4,(vlTOPp->Controller__02Eclk));
        tracep->fullBit(oldp+5,(vlTOPp->Controller__02Ereset));
        tracep->fullBit(oldp+6,(vlTOPp->Controller__02Estart));
        tracep->fullSData(oldp+7,(vlTOPp->Controller__02Emultiplier),16);
        tracep->fullBit(oldp+8,(vlTOPp->Controller__02Eadd_signal));
        tracep->fullBit(oldp+9,(vlTOPp->Controller__02Eshift_signal));
        tracep->fullBit(oldp+10,(vlTOPp->Controller__02Emux_signal));
        tracep->fullBit(oldp+11,(vlTOPp->Datapath__02Eclk));
        tracep->fullBit(oldp+12,(vlTOPp->Datapath__02Ereset));
        tracep->fullBit(oldp+13,(vlTOPp->Datapath__02Estart));
        tracep->fullBit(oldp+14,(vlTOPp->Datapath__02Eadd_signal));
        tracep->fullBit(oldp+15,(vlTOPp->Datapath__02Eshift_signal));
        tracep->fullBit(oldp+16,(vlTOPp->Datapath__02Emux_signal));
        tracep->fullSData(oldp+17,(vlTOPp->multiplicand),16);
        tracep->fullSData(oldp+18,(vlTOPp->accumulator),16);
        tracep->fullSData(oldp+19,(vlTOPp->Datapath__02Emultiplier),16);
        tracep->fullIData(oldp+20,(vlTOPp->product),32);
        tracep->fullCData(oldp+21,(vlTOPp->Controller__DOT__state),2);
        tracep->fullCData(oldp+22,(vlTOPp->Controller__DOT__count),4);
        tracep->fullSData(oldp+23,(((IData)(vlTOPp->Datapath__02Emux_signal)
                                     ? (IData)(vlTOPp->multiplicand)
                                     : 0U)),16);
        tracep->fullSData(oldp+24,(vlTOPp->Datapath__DOT__intermediate_accumulator),16);
        tracep->fullCData(oldp+25,(0U),2);
        tracep->fullCData(oldp+26,(1U),2);
        tracep->fullCData(oldp+27,(2U),2);
        tracep->fullCData(oldp+28,(3U),2);
        tracep->fullSData(oldp+29,(0U),16);
    }
}
