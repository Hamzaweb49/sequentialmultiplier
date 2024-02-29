module Counter(
    input logic clk,           
    input logic reset,         
    input logic add_shift,
    input logic shift,    
    output logic [3:0] count,  
    output logic count_check   
);

always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
        count <= 4'b0000;
    end else if (add_shift || shift) begin
        count <= (count == 15) ? 4'b0000 : count + 1;
    end
end

assign count_check = (count == 4'b1111);

endmodule