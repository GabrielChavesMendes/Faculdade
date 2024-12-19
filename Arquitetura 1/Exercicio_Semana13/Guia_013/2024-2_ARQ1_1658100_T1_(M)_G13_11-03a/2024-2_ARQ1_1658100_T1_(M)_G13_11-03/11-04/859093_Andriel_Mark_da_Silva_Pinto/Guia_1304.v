// Nome: Andriel Mark da Silva Pinto
// Matrícula: 859093

module contador_decadico_assincrono_decrescente(
    output reg [3:0] Q,  // Saída de 4 bits
    input clk,           // Clock de entrada
    input reset          // Sinal de reset
);

    always @(negedge clk or posedge reset) begin
        if (reset) begin
            Q <= 4'b1001;  // Inicializa o contador em 9
        end else if (Q == 4'b0000) begin
            Q <= 4'b1001;  // Reseta para 9 ao alcançar 0
        end else begin
            Q <= Q - 1;    // Decrementa o contador em 1
        end
    end

endmodule
