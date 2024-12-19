module contador_decadico (
    input wire clk,        // Clock de entrada
    input wire reset,      // Sinal de reset
    output reg [3:0] count // Saída de 4 bits
);

    // Inicialização do contador
    initial count = 4'b0000;

    always @(posedge clk or posedge reset) begin
        if (reset) 
            count <= 4'b0000;      // Reset para 0
        else if (count == 4'b1001) // Verifica se o valor é 9 (1001 em binário)
            count <= 4'b0000;      // Reset para 0 ao atingir 9
        else
            count <= count + 1;    // Incrementa de 1 em 1 até 9
    end
endmodule
