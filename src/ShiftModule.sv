/* verilator lint_off EOFNEWLINE */
/* verilator lint_off UNUSED */
module ShiftModule #(
  parameter WIDTH_M = 16
) (
  input logic                clk,
  input logic                reset,
  input logic                enable,
  input logic [WIDTH_M-1:0]  accumulator_in,
  input logic [WIDTH_M-1:0]  multiplier,
  input logic                carry,
  //output logic
  output logic               shift_done,
  output logic [WIDTH_M-1:0] final_accumulator,
  output logic [WIDTH_M-1:0] final_multiplier,
  output logic               carry_out
);


always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    carry_out         <= 0;
    final_accumulator <= 0;
    shift_done        <= 0;
    final_multiplier  <= 0;
  end
  else if (enable) begin
    // carry_out <= carry >> 1;
    final_accumulator    <= accumulator_in >> 1;
    // final_accumulator[15] <= carry[0];
    final_multiplier     <= multiplier >> 1; 
    final_multiplier[15] <= accumulator_in[0];
    shift_done           <= 1; 
  end
end

endmodule
/* verilator lint_on UNUSED */
