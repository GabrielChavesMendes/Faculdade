module shift_register(
    input wire clk,      // Sinal de clock
    input wire reset,    // Sinal de reset para inicializar o registrador
    input wire LD,       // Sinal de carga (load) inicial em todos os estágios
    output reg [5:0] Q   // Saída do registrador de 6 bits
);

    // Bloco sempre sensível ao clock e ao reset
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 6'b000000;  // Reset do registrador para zero
        end else if (LD) begin
            Q <= 6'b111111;  // Carga inicial com todos os bits em 1
        end else begin
            Q <= {Q[4:0], 1'b0};  // Deslocamento para a esquerda com 0 no último bit
        end
    end

endmodule
