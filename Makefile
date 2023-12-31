# Makefile for Verilog simulation using Verilator or XSIM

# Define Verilator variables
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc

# Define VSIM variables
VSIM = vsim
VSIM_FLAGS = -R

# Define simulation variables
SIM_BINARY = sim_bin
SIM_SRC_VERILATOR = tb_SequentialMultiplier.sv

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
	@echo "  sim TOOL=vsim - Run simulation using XSIM"
	@echo "  sim TOOL=verilator - Run simulation using Verilator"
	@echo "  clean         - Remove generated files"

# Simulation target
.PHONY: sim
sim:
ifdef TOOL
ifeq ($(TOOL),vsim)
	@echo "Running VSIM simulation..."
	vlog seqmul.sv tb_SequentialMultiplier.sv
	vsim tb_SequentialMultiplier
else ifeq ($(TOOL),verilator)
	@echo "Running Verilator simulation..."
	verilator -Wall --trace --exe --build -cc main.cpp seqmul.sv
	./obj_dir/Vseqmul
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

