/* verilator lint_off UNUSED */
module Datapath #(
  parameter WIDTH_M = 16,
  parameter WIDTH_P = 32
) (
  input logic               clk,
  input logic               reset,
  input logic               start,
  input logic               add_signal,
  input logic               shift_signal,
  input logic               mux_signal,
  input logic [WIDTH_M-1:0] multiplicand,
  input logic [WIDTH_M-1:0] accumulator,
  input logic [WIDTH_M-1:0] multiplier,
  output logic [WIDTH_P-1:0] product
);


logic [WIDTH_M-1:0] mux_output;
logic [WIDTH_M-1:0] intermediate_accumulator;
logic [WIDTH_M-1:0] shift_multiplier; 
logic [WIDTH_M-1:0] shift_accumulator; 
logic carryin;
logic carryout;
logic shiftcarry;
logic shift_done;


assign carryin  = 1'b0;
assign carryout = 1'b0;


MuxModule mux_inst (
  .multiplicand  (multiplicand), 
  .zeros         (16'b0),
  .mux_signal    (mux_signal), 
  .selected_input(mux_output)
);

AddModule add_inst (
  .mux_out          (mux_output), 
  .accumulator      (accumulator), 
  .carryin          (carryin),
  .add_signal       (add_signal), 
  .adder_accumulator(intermediate_accumulator)
);

ShiftModule shift_inst (
  .clk              (clk), 
  .reset            (reset), 
  .enable           (shift_signal),
  .accumulator_in   (intermediate_accumulator), 
  .multiplier       (multiplier),
  .carry            (add_inst.carryout), 
  .final_accumulator(shift_accumulator),
  .final_multiplier (shift_multiplier), 
  .shift_done       (shift_done),
  .carry_out        (shiftcarry)
);

assign product = {shift_accumulator, shift_multiplier};


endmodule
/* verilator lint_on UNUSED */
