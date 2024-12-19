// Nome: Andriel Mark da Silva Pinto
// Matrícula: 859093

module contador_assincrono_crescente(
    output [4:0] Q,    // Saída de 5 bits
    input clk,         // Clock de entrada
    input reset        // Sinal de reset
);

    reg [4:0] Q;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 5'b00000; // Inicializa o contador em 0
        end else begin
            Q <= Q + 1;    // Incrementa o contador em 1
        end
    end

endmodule
