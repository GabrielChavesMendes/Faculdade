//Otávio Augusto de Assis Ferreira Monteiro
//851568
module ram_1x8 (
    input wire [7:0] dados_in,
    input wire enable,
    input wire write_enable,
    output reg [7:0] dados_out
);
    reg [3:0] ram_lower; 
    reg [3:0] ram_upper; 

    always @(*) begin
        if (enable) begin
            if (write_enable) begin
                ram_lower <= dados_in[3:0]; 
                ram_upper <= dados_in[7:4]; 
            end else begin
                dados_out <= {ram_upper, ram_lower}; 
            end
        end
    end
endmodule
