module MultiplicandLoader(
    input logic clk,           
    input logic reset,         
    input logic load_words,    
    input logic [31:0] data_in,
    output logic [31:0] data_out
);

always_ff @(posedge clk or negedge reset) begin
    if (!reset) begin
        data_out <= 32'h00000000;
    end else if (load_words) begin
        data_out <= data_in;
    end
end

endmodule