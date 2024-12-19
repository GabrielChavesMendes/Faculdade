// Nome: Laura Persilva
// Matrícula: 855476

module contador_sincrono_modulo7(
    output reg [2:0] Q,  // Saída de 3 bits
    input clk,           // Clock de entrada
    input reset          // Sinal de reset
);

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 3'b000;  // Inicializa o contador em 0
        end else if (Q == 3'b110) begin
            Q <= 3'b000;  // Reseta para 0 ao alcançar 7
        end else begin
            Q <= Q + 1;   // Incrementa o contador em 1
        end
    end

endmodule
