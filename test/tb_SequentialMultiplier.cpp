#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtb_SequentialMultiplier.h"

#define MAX_SIM_TIME 166
vluint64_t sim_time = 0;

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vtb_SequentialMultiplier* top = new Vtb_SequentialMultiplier;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("waveform.vcd");

    while (!Verilated::gotFinish() && sim_time < MAX_SIM_TIME) {
        if (sim_time < 4){
            top->reset = 1;
            top->start = 0;
        }
        
        if (sim_time == 4) {
            top->reset = 0;
            top->start = 1;
        }
      
        top->clk ^= 1;


        top->eval();

        tfp->dump(sim_time);

        sim_time++;


    }

    tfp->close();

    delete top;

    exit(EXIT_SUCCESS);
}
