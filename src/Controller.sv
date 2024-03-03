module Controller(
  input logic  clk,
  input logic  reset, 

  input logic  start,
  
  input logic  multiplier_lsb,
  input logic  count_check,
  input logic  empty,
  
  output logic load_words,
  output logic ready,
  output logic shift,
  output logic add_shift,
  output logic flush
);

// Define states
typedef enum logic [1:0] {
    S0, // Idle
    S1, // Load and Shift
    S2  // Flush
} state_t;

state_t current_state, next_state;

// Registers for storing state
always_ff @(posedge clk or posedge reset) begin
  if (reset) begin
    current_state <= S0;
  end else begin
    current_state <= next_state;
  end
end

// State transition and output logic
always_comb begin
  case (current_state)
    S0: begin
      if(start && !empty) begin
        next_state = S1; // Transition to S1 if start signal is received
      end else if(start && empty) begin
        next_state = S2;
      end else begin
        next_state = S0;
      end
      load_words = (start && !empty);
      ready      = 1'b1;
      shift      = 1'b0;
      add_shift  = 1'b0;
      flush      = (start && empty);
    end
    S1: begin
      next_state = count_check ? S2 : S1; // Transition to S2 if count_check is asserted
      load_words = 1'b0;
      ready      = 1'b0;
      shift      = !multiplier_lsb && !count_check;
      add_shift  = multiplier_lsb && !count_check;
      flush      = 1'b0;
    end
    S2: begin
      if(start && !empty)  begin
        next_state = S1;
      end else if(start && empty) begin
        next_state = S2;
      end else begin
        next_state = S0;
      end
      load_words = (start && !empty);
      ready      = 1'b1;
      shift      = 1'b0;
      add_shift  = 1'b0;
      flush      = (start && empty);
    end
    default: begin
      next_state = S0;
      load_words = 1'b0;
      ready      = 1'b0;
      shift      = 1'b0;
      add_shift  = 1'b0;
      flush      = 1'b1;
    end
  endcase
end

endmodule
