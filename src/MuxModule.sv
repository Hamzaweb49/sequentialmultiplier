module MuxModule #(
  parameter WIDTH_M = 16
) (
  input logic [WIDTH_M-1:0]  multiplicand,
  input logic [WIDTH_M-1:0]  zeros,
  input logic                mux_signal,
  output logic [WIDTH_M-1:0] selected_input
);

assign selected_input = mux_signal ? multiplicand : zeros;

endmodule