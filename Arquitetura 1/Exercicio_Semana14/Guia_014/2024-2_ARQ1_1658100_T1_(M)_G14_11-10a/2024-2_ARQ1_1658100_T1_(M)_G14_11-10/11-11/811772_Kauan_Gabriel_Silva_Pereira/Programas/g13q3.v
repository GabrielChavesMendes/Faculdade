module registrador_circular (
    input wire clk,             
    input wire LD,              
    input wire D_in,           
    output reg [5:0] Q          
);

always @(posedge clk) begin
    if (LD)
        Q <= {D_in, Q[5:1]};   
    else
        Q <= {Q[0], Q[5:1]};    
end

endmodule


module registrador_deslocamento_circular (
    input wire clk,               // Sinal de clock
    input wire LD,                // Sinal de carga
    input wire D_in,              // Dado de entrada para carga unitária no primeiro estágio
    output reg [5:0] Q            // Saída do registrador (6 bits)
);

always @(posedge clk) begin
    if (LD)
        Q <= {D_in, Q[5:1]};      // Carrega D_in no primeiro bit, com deslocamento circular
    else
        Q <= {Q[0], Q[5:1]};      // Deslocamento circular para a direita
end

endmodule
