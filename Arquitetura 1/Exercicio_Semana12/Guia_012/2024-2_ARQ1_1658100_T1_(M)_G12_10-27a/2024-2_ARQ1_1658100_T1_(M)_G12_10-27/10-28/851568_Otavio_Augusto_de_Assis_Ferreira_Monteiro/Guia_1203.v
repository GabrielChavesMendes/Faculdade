//Otávio Augusto de Assis Ferreira Monteiro
//851568
module ram_2x8 (
    input wire [7:0] dados_in,
    input wire enable,
    input wire write_enable,
    input wire addr,         
    output reg [7:0] dados_out
);
    reg [7:0] ram[1:0]; 

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
