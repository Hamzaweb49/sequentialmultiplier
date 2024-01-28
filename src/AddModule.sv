module AddModule #(
  parameter WIDTH_M = 16
) (
  input logic                clk,
  input logic [WIDTH_M-1:0]  mux_out,
  input logic [WIDTH_M-1:0]  accumulator,
  input logic                carryin,
  input logic                add_signal,
  output logic [WIDTH_M-1:0] adder_accumulator,
  output logic               carryout
);

assign adder_accumulator = mux_out + accumulator;
assign carryout = (mux_out & accumulator) | (carryin & (mux_out ^ accumulator));
    

endmodule