//Otávio Augusto de Assis Ferreira Monteiro
//851568
module ram_8x16 (
    input wire [15:0] dados_in,
    input wire enable,
    input wire write_enable,
    input wire [2:0] addr,          
    output reg [15:0] dados_out
);
    reg [15:0] ram[7:0]; 

    always @(*) begin
        if (enable) begin
            if (write_enable) begin
                ram[addr] <= dados_in; 
            end else begin
                dados_out <= ram[addr]; 
            end
        end
    end
endmodule
