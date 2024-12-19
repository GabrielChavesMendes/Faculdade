// Nome: Andriel Mark da Silva Pinto
// Matrícula: 859093

module contador_anel_torcido_5bits(
    output reg [4:0] Q,  // Saída de 5 bits
    input clk,           // Clock de entrada
    input reset          // Sinal de reset
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 5'b10000;  // Inicializa o contador em "10000"
        end else if (Q == 5'b00001) begin
            Q <= 5'b11110;  // Inverte para "11110" quando a contagem completa
        end else begin
            Q <= {Q[3:0], ~Q[4]};  // Desloca o "1" ou "0" e torce no final do ciclo
        end
    end

endmodule
