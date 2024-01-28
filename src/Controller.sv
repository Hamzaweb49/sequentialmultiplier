module Controller #(
  parameter WIDTH_M = 16,
  parameter WIDTH_C = 4,
  parameter WIDTH_S = 3
) (   
  input logic               clk,
  input logic               reset,
  input logic               start,
  input logic [WIDTH_M-1:0] multiplier,
  output reg                add_signal,
  output reg                shift_signal,
  output reg                mux_signal
);

localparam S0 = 3'b000, S1 = 3'b001, S2 = 3'b010, 
           S3 = 3'b011, S4 = 3'b100;


logic [WIDTH_S-1:0] state;
logic [WIDTH_S-1:0] next_state;
logic [WIDTH_C-1:0] count = 4'b0;

always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    state <= S0;
  end else begin
    state <= next_state;
  end
end

always_comb begin
  case (state)
    S0: begin
      if (start && count < 16) begin
        count        = 4'b0;
        add_signal   = 1'b0;
        shift_signal = 1'b0;
        mux_signal   = 1'b0;
        next_state   = S1;
      end
    end
    S1: begin
      shift_signal = 1'b0;
      add_signal   = 1'b0;
      mux_signal   = multiplier[0];
      next_state   = S2;
    end
    S2: begin
      shift_signal = 1'b0;
      add_signal   = 1'b1;
      next_state   = S3;
    end
    S3: begin
      add_signal   = 1'b0;
      shift_signal = 1'b1;
      next_state   = S4;
    end
    S4: begin
      if (count < 16) begin
        count = count + 1;
        shift_signal = 1'b0;
        next_state   = S1;
      end else begin
        add_signal   = 1'b0;
        shift_signal = 1'b0;
        mux_signal   = 1'b0;
      end
    end
    default: next_state = S0;
  endcase
end

endmodule
