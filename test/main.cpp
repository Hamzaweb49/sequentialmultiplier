#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vseqmul.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vseqmul* top = new Vseqmul;

    top->clk = 0;
    top->reset = 1;
    top->start = 0;
    top->add_signal = 0;
    top->shift_signal = 0;
    top->mux_signal = 0;

    for (int i = 0; i < 10; ++i) {
    }

    top->reset = 0;
    top->start = 1;
    

    top->multiplicand = 0x0002; 
    top->multiplier = 0x0005; 
    top->accumulator = 0x0000;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;

    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    for (int i = 0; i < 500; ++i) {
        top->clk = !top->clk;

        tfp->dump(i);

        top->eval();

        tfp->flush();
    }

    tfp->close();

    delete top;

    return 0;
}
