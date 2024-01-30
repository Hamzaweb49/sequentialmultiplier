#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VTopModule.h"

#define MAX_SIM_TIME 750
vluint64_t sim_time = 0;

int main(int argc, char** argv) {
    short int a, b;
    int product;

    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    VTopModule* top = new VTopModule;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    a = 120;
    b = 80;

    while (!Verilated::gotFinish() && sim_time < MAX_SIM_TIME) {
        if (sim_time == 4) {
            top->reset = 1;
            top->start = 0;
            top->multiplier = 0;
            top->multiplicand = 0;
            top->accumulator = 0;
            top->product = 0;
        }
        top->clk ^= 1;

        if (sim_time == 5) {
            top->multiplier = 80;
            top->multiplicand = 120;
            top->start = 1;
        }


        top->eval();

        product = top->product; 

        tfp->dump(sim_time);
        sim_time++;
    }

    printf("Multiplicand = %d; Multiplier = %d; Product = %d\n", top->multiplicand, top->multiplier, top->product);
    tfp->close();

    delete top;

    exit(EXIT_SUCCESS);
}
