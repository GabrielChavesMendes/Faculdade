// Nome: Andriel Mark da Silva Pinto
// Matrícula: 859093

module contador_anel_5bits(
    output reg [4:0] Q,  // Saída de 5 bits
    input clk,           // Clock de entrada
    input reset          // Sinal de reset
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 5'b10000;  // Inicializa o contador em "10000"
        end else begin
            Q <= {Q[3:0], Q[4]};  // Desloca o bit "1" para a esquerda em cada pulso
        end
    end

endmodule
