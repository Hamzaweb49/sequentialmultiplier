# Makefile for Verilog simulation using Verilator or VSIM

# Define Verilator variables
VERILATOR = verilator
VERILATOR_FLAGS = -Wall --cc

# Define VSIM variables
VSIM = vsim
VSIM_FLAGS = -R

# Define simulation variables
SIM_BINARY = sim_bin

SIM_SRC_VERILATOR = src/SM.sv \
					src/Datapath.sv \
					src/Controller.sv \
					src/ALU.sv \
					src/Counter.sv \
					src/LeftShifter.sv \
					src/RightShifter.sv \
					src/MultiplierLoader.sv \
					src/MultiplicandLoader.sv \
					test/SM_tb.sv

SIM_SRC_VSIM = $(SIM_SRC_VERILATOR)

COMP_OPTS_SV := --incr --relax

TB_TOP = SM_tb
MODULE = SM_tb

DEFINES_VER:= src/defines/verilator.svh

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
	vsim SM_tb

else ifeq ($(TOOL),verilator)
	@echo "Running Verilator simulation..."
	verilator --trace -cc $(SIM_SRC_VERILATOR) $(DEFINES_VER) \
	  	  --top-module $(MODULE)     \
		  -Wno-DECLFILENAME 		 \
		  -Wno-WIDTH 				 \
		  -Wno-REDEFMACRO			 \
		  -Wno-INITIALDLY			 \
		  --exe ./test/$(TB_TOP).cpp \
		  --timing
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)
	./obj_dir/V$(MODULE)
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

# verilator -Wall --trace --exe --build -cc test/tb_SequentialMultiplier.cpp $(SIM_SRC_VERILATOR)