module parallel_to_serial (
    input [5:0] data_in,  
    input load,           
    input clk,             
    input rst,             
    output reg serial_out 
);

    reg [5:0] shift_reg;  
    reg [2:0] bit_counter; 

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            shift_reg <= 6'b0;     
            bit_counter <= 3'b0;    
            serial_out <= 1'b0;   
        end else if (load) begin
            shift_reg <= data_in;   
            bit_counter <= 3'b0;  
        end else if (bit_counter < 6) begin
            serial_out <= shift_reg[5];           
            shift_reg <= {shift_reg[4:0], 1'b0}; 
            bit_counter <= bit_counter + 1;      
        end
    end
endmodule
