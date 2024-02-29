module MultiplierLoader(
    input logic clk,           
    input logic reset,         
    input logic load_words,    
    input logic [15:0] data_in,
    output logic [15:0] data_out
);

always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
        data_out <= 16'h0;
    end else if (load_words) begin
        data_out <=  data_in;
    end
end

endmodule