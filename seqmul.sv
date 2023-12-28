/* verilator lint_off DECLFILENAME */
module AddModule(
    input logic clk,
    input logic [15:0] multiplicand,
    input logic [15:0] accumulator,
    input logic add_signal,
    output logic [15:0] accumulator_out
);
always @(posedge clk) begin
    accumulator_out <= add_signal ? (multiplicand ^ accumulator) : accumulator;
end

endmodule

module ShiftModule(
    input logic clk,
    input logic reset,
    input logic enable,
    input logic [15:0] accumulator,
    input logic [15:0] multiplier,
    /* verilator lint_off UNUSED */
    input logic [0:0] carry,
    /* verilator lint_on UNUSED */
    output logic [15:0] accumulator_out,
    output reg [15:0] multiplier_out,
    output logic [0:0] carry_out
);

reg [15:0] shift_reg;
reg carry_reg;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        shift_reg <= 16'b0;
        carry_reg <= 1'b0;
    end else if (enable) begin
        carry_out <= carry_reg >> 1;
        accumulator_out <= accumulator >> 1;
        multiplier_out <= multiplier >> 1;
    end
end


endmodule

module MuxModule(
    input logic [15:0] multiplicand,
    input logic [15:0] zeros,
    input logic mux_signal,
    output logic [15:0] selected_input
);

assign selected_input = mux_signal ? multiplicand : zeros;

endmodule

/* verilator lint_off MULTITOP */
module Datapath(
    input logic clk,
    input logic reset,
    /* verilator lint_off UNUSED */
    input logic start,
    /* verilator lint_on UNUSED */
    input logic add_signal,
    input logic shift_signal,
    input logic mux_signal,
    input logic [15:0] multiplicand,
    input logic [15:0] accumulator,
    input logic [15:0] multiplier,
    output logic [31:0] product
);
/* verilator lint_on MULTITOP */

logic [15:0] shift_reg_shift;
reg [15:0] shift_reg_mux;
reg [15:0] intermediate_accumulator;
logic [15:0] shift_multiplier; 
reg carry;

always @(posedge reset) begin
    // Add the following lines to initialize the variables to zero
    shift_reg_shift <= 16'b0;
    shift_reg_mux <= 16'b0;
    intermediate_accumulator <= 16'b0;
    shift_multiplier <= 16'b0;
    carry <= 1'b0;
end


// Mux Module instantiation
MuxModule mux_inst(
    .multiplicand(multiplicand), 
    .zeros(16'b0),
    .mux_signal(mux_signal), 
    .selected_input(shift_reg_mux)
);


// // Add Module instantiation
AddModule add_inst(.clk(clk), .multiplicand(shift_reg_mux), .accumulator(accumulator),
                  .add_signal(add_signal), .accumulator_out(intermediate_accumulator));

// Shift Module instantiation
ShiftModule shift_inst(
    .clk(clk), 
    .reset(reset), 
    .enable(shift_signal),
    .accumulator(intermediate_accumulator), 
    .multiplier(multiplier),
    .carry(carry), 
    .accumulator_out(shift_reg_shift),
    .multiplier_out(shift_multiplier), 
    .carry_out(carry)
);

// Output product
assign product = {shift_reg_shift, shift_multiplier};

endmodule

/* verilator lint_off MULTITOP */
module Controller(
    input logic clk,
    input logic reset,
    input logic start,
    /* verilator lint_off UNUSED */
    input logic [15:0] multiplier,
    /* verilator lint_on UNUSED */
    // verilator lint_off BLKANDNBLK 
    output reg add_signal,
    output reg shift_signal,
    output reg mux_signal
    // verilator lint_on BLKANDNBLK 
);
/* verilator lint_on MULTITOP */

parameter IDLE = 2'b00;
parameter CHECKLSB = 2'b01;
parameter ADD = 2'b10;
parameter SHIFT = 2'b11;

reg [1:0] state;
reg [3:0] count;


always @(posedge clk or posedge reset) begin
    if (reset) begin
        state <= IDLE;
        count <= 4'b0;
        add_signal <= 1'b0;
        shift_signal <= 1'b0;
        mux_signal <= 1'b0;
    end else begin
        case (state)
            IDLE: begin
                if (start) begin
                    count <= 4'b0;
                    add_signal <= 1'b0;
                    shift_signal <= 1'b0;
                    mux_signal <= 1'b0;
                    state <= CHECKLSB;
                end
            end
            CHECKLSB: begin
                mux_signal <= multiplier[0];
                state <= ADD;
            end
            ADD: begin
            /* verilator lint_off BLKSEQ */
                add_signal <= 1'b1;
                state <= SHIFT;
            /* verilator lint_on BLKSEQ */
            end
            SHIFT: begin
            /* verilator lint_off WIDTH */
                if (count < 16) begin
                    count <= count + 1;
                    shift_signal <= 1'b1;
                    state <= CHECKLSB;
                end else begin
                    state <= IDLE;
                end
             /* verilator lint_on WIDTH */
            end
            default: state <= IDLE;
        endcase
    end
end

endmodule

// always @(posedge clk) begin
// $display("The values of intermediate accumulator is %b:", intermediate_accumulator);
// end
/* verilator lint_on DECLFILENAME */
