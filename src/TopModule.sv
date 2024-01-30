/* verilator lint_off LATCH */
module TopModule #(
  parameter WIDTH_M = 16,
  parameter WIDTH_P = 32
) (
  input logic               clk,
  input logic               reset,
  input logic               start,
  input logic [WIDTH_M-1:0] multiplier,
  input logic [WIDTH_M-1:0] multiplicand,  
  input logic [WIDTH_M-1:0] accumulator,
  output logic              add_signal,
  output logic              shift_signal,
  output logic              mux_signal,
  output logic [WIDTH_P-1:0] product
);

logic [WIDTH_M-1:0] top_multiplier;
logic [WIDTH_M-1:0] top_accumulator;

always_comb begin
  if (dp_inst.shift_done) begin
    top_multiplier  = dp_inst.shift_multiplier;
    top_accumulator = dp_inst.shift_accumulator;
  end
  else if (!dp_inst.shift_done) begin
    top_multiplier  = multiplier;
    top_accumulator = accumulator;
  end
end

Datapath dp_inst (
  .clk         (clk),
  .reset       (reset),
  .start       (start),
  .add_signal  (add_signal),
  .shift_signal(shift_signal),
  .mux_signal  (mux_signal),
  .multiplicand(multiplicand),
  .accumulator (top_accumulator),
  .multiplier  (top_multiplier),
  .product     (product)
);

Controller ctrl_inst(
  .clk         (clk),
  .reset       (reset),
  .start       (start),
  .multiplier  (top_multiplier),
  .add_signal  (add_signal), 
  .shift_signal(shift_signal),
  .mux_signal  (mux_signal)
);

endmodule

/* verilator lint_on LATCH */

