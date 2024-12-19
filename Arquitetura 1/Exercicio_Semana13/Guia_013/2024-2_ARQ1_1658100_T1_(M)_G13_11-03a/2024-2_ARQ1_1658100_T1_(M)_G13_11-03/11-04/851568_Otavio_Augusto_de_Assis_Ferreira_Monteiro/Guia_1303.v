// Nome: Otávio Augusto de Assis Ferreira Monteiro
// Matrícula: 851568

module contador_decadico_assincrono(
    output reg [3:0] Q,  // Saída de 4 bits
    input clk,           // Clock de entrada
    input reset          // Sinal de reset
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 4'b0000;  // Inicializa o contador em 0
        end else if (Q == 4'b1001) begin
            Q <= 4'b0000;  // Reseta para 0 ao alcançar 9 (1001)
        end else begin
            Q <= Q + 1;    // Incrementa o contador em 1
        end
    end

endmodule
