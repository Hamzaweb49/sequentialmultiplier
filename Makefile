# Makefile for Verilog simulation using Verilator or VSIM

# Define Verilator variables
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc

# Define VSIM variables
VSIM = vsim
VSIM_FLAGS = -R

# Define simulation variables
SIM_BINARY = sim_bin
SIM_SRC_VERILATOR = src/TopModule.sv src/Datapath.sv src/Controller.sv src/AddModule.sv src/MuxModule.sv src/ShiftModule.sv
SIM_SRC_VSIM = $(SIM_SRC_VERILATOR) test/tb_SequentialMultiplier.sv
SRC_SV = src/TopModule.sv src/Datapath.sv src/Controller.sv src/AddModule.sv src/MuxModule.sv src/ShiftModule.sv test/tb_SequentialMultiplier.sv

COMP_OPTS_SV := --incr --relax

TB_TOP = tb_SequentialMultiplier
MODULE = TopModule

# Default target
.PHONY: all
all: help

# Help target
.PHONY: help
help:
	@echo "Verilog Simulation Makefile"
	@echo "---------------------------"
	@echo "Targets:"
	@echo "  help          - Display this help message"
	@echo "  sim TOOL=vsim - Run simulation using VSIM"
	@echo "  sim TOOL=verilator - Run simulation using Verilator"
	@echo "  clean         - Remove generated files"

# Simulation target
.PHONY: sim
sim:
ifdef TOOL
ifeq ($(TOOL),vsim)
	@echo "Running VSIM simulation..."
	vlog $(SIM_SRC_VSIM)
	vsim tb_SequentialMultiplier

else ifeq ($(TOOL),verilator)
	@echo "Running Verilator simulation..."
	verilator -Wall --trace -cc $(SIM_SRC_VERILATOR) --top-module $(MODULE) -Wno-DECLFILENAME -Wno-WIDTH --exe test/main.cpp
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)
	./obj_dir/VTopModule
	gtkwave waveform.vcd

else
	@echo "Invalid TOOL specified. Please use 'vsim' or 'verilator'."
endif
else
	@echo "Please specify the simulation tool using 'make sim TOOL=vsim' or 'make sim TOOL=verilator'."
endif

# Clean target
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rf $(SIM_BINARY) obj_dir