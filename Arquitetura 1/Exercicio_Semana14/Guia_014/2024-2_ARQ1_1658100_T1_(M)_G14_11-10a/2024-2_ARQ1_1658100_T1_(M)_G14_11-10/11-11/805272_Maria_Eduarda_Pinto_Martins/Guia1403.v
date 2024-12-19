module circular_shift_register(
    input wire clk,      // Sinal de clock
    input wire reset,    // Sinal de reset para inicializar o registrador
    input wire LD,       // Sinal de carga (load) unitária no primeiro estágio
    output reg [5:0] Q   // Saída do registrador de 6 bits
);

    // Bloco sempre sensível ao clock e ao reset
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 6'b000000;  // Reset do registrador para zero
        end else if (LD) begin
            Q <= {1'b1, Q[5:1]};  // Carrega 1 no primeiro estágio (Q[5])
        end else begin
            Q <= {Q[0], Q[5:1]};  // Deslocamento circular para a direita
        end
    end

endmodule
