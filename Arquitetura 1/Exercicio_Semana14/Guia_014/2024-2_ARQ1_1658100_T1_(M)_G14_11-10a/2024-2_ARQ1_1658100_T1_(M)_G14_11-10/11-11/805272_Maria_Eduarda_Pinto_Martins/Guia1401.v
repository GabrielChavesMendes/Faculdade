module shift_register(
    input wire clk,      // Sinal de clock
    input wire reset,    // Sinal de reset para inicializar o registrador
    input wire LD,       // Sinal de carga (load) de 1 bit
    output reg [5:0] Q   // Saída do registrador de 6 bits
);

    // Sempre que o clock tiver uma borda positiva ou o reset for ativado
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            Q <= 6'b000000;  // Reset do registrador
        end else if (LD) begin
            Q <= {Q[4:0], 1'b1};  // Carrega 1 no primeiro bit e desloca para a esquerda
        end else begin
            Q <= {Q[4:0], 1'b0};  // Desloca para a esquerda e insere 0 no último bit
        end
    end

endmodule
