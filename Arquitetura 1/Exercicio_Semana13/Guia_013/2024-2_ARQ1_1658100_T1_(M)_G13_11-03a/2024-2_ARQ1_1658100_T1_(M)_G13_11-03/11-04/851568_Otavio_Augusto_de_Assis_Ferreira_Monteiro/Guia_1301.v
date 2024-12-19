// Nome: Otávio Augusto de Assis Ferreira Monteiro
// Matrícula: 851568

module contador_assincrono_decrescente(
    output [4:0] Q,    // Saída de 5 bits
    input clk,         // Clock de entrada
    input reset        // Sinal de reset
);

    reg [4:0] Q;

    always @(negedge clk or posedge reset) begin
        if (reset) begin
            Q <= 5'b11111; // Inicializa o contador com 31
        end else begin
            Q <= Q - 1;    // Decrementa o contador em 1
        end
    end

endmodule
