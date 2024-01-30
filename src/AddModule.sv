/* verilator lint_off IMPLICIT */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
module AddModule #(
  parameter WIDTH_M = 16
) (
  input logic [WIDTH_M-1:0]  mux_out,
  input logic [WIDTH_M-1:0]  accumulator,
  input logic                carryin,
  input logic                add_signal,
  output logic [WIDTH_M-1:0] adder_accumulator
);

assign adder_accumulator = mux_out + accumulator;
assign carryout = (mux_out & accumulator) | (carryin & (mux_out ^ accumulator));
    

endmodule
/* verilator lint_on IMPLICIT */
/* verilator lint_on WIDTH */
/* verilator lint_on UNUSED */
