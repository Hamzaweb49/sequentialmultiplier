module Controller(
  input logic clk,
  input logic reset, 
  input logic start,
  input logic multiplier_lsb,
  input logic count_check,
  output logic load_words,
  output logic ready,
  output logic shift,
  output logic add_shift
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
            next_state = start ? S1 : S0; // Transition to S1 if start signal is received
            load_words = start;
            ready = start;
            shift = 1'b0;
            add_shift = 1'b0;
        end
        S1: begin
            next_state = count_check ? S2 : S1; // Transition to S2 if count_check is asserted
            load_words = 1'b0;
            ready = 1'b0;
            shift = !multiplier_lsb && !count_check;
            add_shift = multiplier_lsb && !count_check;
        end
        S2: begin
            next_state = start ? S1 : S0; // Transition to S1 if start signal is received
            load_words = start;
            ready = !start;
            shift = 1'b0;
            add_shift = 1'b0;
        end
        default: begin
            next_state = S0;
            load_words = 1'b0;
            ready = 1'b0;
            shift = 1'b0;
            add_shift = 1'b0;
        end
    endcase
end

endmodule
