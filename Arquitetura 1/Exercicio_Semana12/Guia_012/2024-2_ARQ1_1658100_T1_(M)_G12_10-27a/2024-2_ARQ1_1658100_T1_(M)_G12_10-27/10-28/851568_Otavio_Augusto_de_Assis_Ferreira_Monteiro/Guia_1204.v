//Otávio Augusto de Assis Ferreira Monteiro
//851568
module ram_4x8 (
    input wire [7:0] dados_in,
    input wire enable,
    input wire write_enable,
    input wire [1:0] addr,         
    output reg [7:0] dados_out
);
    reg [7:0] ram[3:0]; 

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
