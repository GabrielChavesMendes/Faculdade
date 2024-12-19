module contador_decrescente(
    input wire clk,         // Sinal de clock
    input wire reset,       // Sinal de reset
    output reg [4:0] count  // Saída de 5 bits
);
    // Inicialização do contador
    initial count = 5'b11111; // Inicializa em 31 (11111 em binário)

    always @(posedge clk or posedge reset) begin
        if (reset) 
            count <= 5'b11111;   // Reseta para o valor máximo (31)
        else
            count <= count - 1;  // Decrementa em 1
    end
endmodule
