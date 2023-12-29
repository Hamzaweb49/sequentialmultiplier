/* verilator lint_off DECLFILENAME */
/* verilator lint_off MULTIDRIVEN */
/* verilator lint_off WIDTH */
/* verilator lint_off UNUSED */
/* verilator lint_off BLKSEQ */
/* verilator lint_off MULTITOP */
/* verilator lint_off BLKANDNBLK  */

module Datapath(
    input logic clk,
    input logic reset,
    input logic start,
    input logic add_signal,
    input logic shift_signal,
    input logic mux_signal,
    input logic [15:0] multiplicand,
    input logic [15:0] accumulator,
    input logic [15:0] multiplier,
    output logic [31:0] product
);

logic [15:0] shift_accumulator;
reg [15:0] mux_output;
logic [15:0] intermediate_accumulator;
logic [15:0] shift_multiplier; 
logic carryin;
logic carryout;
logic shiftcarry;

always @(posedge reset) begin
    shift_accumulator <= 16'b0;
    mux_output <= 16'b0;
    intermediate_accumulator <= 16'b0;
    shift_multiplier <= 16'b0;
    carryin <= 1'b0;
    carryout <= 1'b0;
    shiftcarry <= 1'b0;
end


// Mux Module instantiation
MuxModule mux_inst(
    .multiplicand(multiplicand), 
    .zeros(16'b0),
    .mux_signal(mux_signal), 
    .selected_input(mux_output)
);


// // Add Module instantiation
AddModule add_inst(.clk(clk), .multiplicand(mux_output), .accumulator(accumulator), .carryin(carryin),
                  .add_signal(add_signal), .accumulator_out(intermediate_accumulator), .carryout(carryout));

// Shift Module instantiation
ShiftModule shift_inst(
    .clk(clk), 
    .reset(reset), 
    .enable(shift_signal),
    .accumulator(intermediate_accumulator), 
    .multiplier(multiplier),
    .carry(carryout), 
    .accumulator_out(shift_accumulator),
    .multiplier_out(shift_multiplier), 
    .carry_out(shiftcarry)
);

// Output product
assign product = {shift_accumulator, shift_multiplier};

endmodule

module AddModule(
    input logic clk,
    input logic [15:0] multiplicand,
    input logic [15:0] accumulator,
    input logic carryin,
    input logic add_signal,
    output logic [15:0] accumulator_out,
    output logic carryout
);

always @(posedge clk) begin
    accumulator_out <= add_signal ? (multiplicand ^ accumulator) : accumulator;
    carryout <= (multiplicand & accumulator) | (carryin & (multiplicand ^ accumulator));
end


endmodule

module ShiftModule(
    input logic clk,
    input logic reset,
    input logic enable,
    input logic [15:0] accumulator,
    input logic [15:0] multiplier,
    input logic [0:0] carry,
    output logic [15:0] accumulator_out,
    output reg [15:0] multiplier_out,
    output logic [0:0] carry_out
);


always @(posedge clk or posedge reset) begin
    if (reset) begin
        carry_out <= 0;
        accumulator_out <= 0;
        multiplier_out <= 0;
    end
    else if (enable) begin
        carry_out <= carry >> 1;
        accumulator_out <= (accumulator >> 1) | ((carry & 1) << 15);
        multiplier_out <= (multiplier >> 1) | ((accumulator & 1) << 15); 
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


module Controller(
    input logic clk,
    input logic reset,
    input logic start,
    input logic [15:0] multiplier,
    output reg add_signal,
    output reg shift_signal,
    output reg mux_signal
);

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
                add_signal <= 1'b1;
                state <= SHIFT;
            end
            SHIFT: begin
                if (count < 16) begin
                    count <= count + 1;
                    shift_signal <= 1'b1;
                    state <= CHECKLSB;
                end else begin
                    state <= IDLE;
                end
            end
            default: state <= IDLE;
        endcase
    end
end

endmodule

/* verilator lint_on MULTIDRIVEN */
/* verilator lint_on BLKANDNBLK  */
/* verilator lint_on MULTITOP */
/* verilator lint_on BLKSEQ */
/* verilator lint_on UNUSED */
/* verilator lint_on WIDTH */
/* verilator lint_on DECLFILENAME */
