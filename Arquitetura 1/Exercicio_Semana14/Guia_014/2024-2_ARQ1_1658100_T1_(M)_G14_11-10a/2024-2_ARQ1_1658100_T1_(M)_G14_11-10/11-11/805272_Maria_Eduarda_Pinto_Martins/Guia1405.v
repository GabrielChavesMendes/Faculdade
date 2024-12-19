module parallel_to_serial(
    input wire clk,              // Sinal de clock
    input wire reset,            // Sinal de reset para inicializar o registrador
    input wire Load,             // Sinal de controle para carregar em paralelo ou deslocar em série
    input wire [5:0] parallel_in, // Entrada de dados em paralelo (6 bits)
    output reg serial_out        // Saída serial de 1 bit
);

    reg [5:0] shift_register;    // Registrador de deslocamento para armazenar o valor paralelo

    // Bloco sempre sensível ao clock e ao reset
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            shift_register <= 6'b000000; // Reset do registrador
            serial_out <= 1'b0;          // Reset da saída serial
        end else if (Load) begin
            shift_register <= parallel_in; // Carga paralela
        end else begin
            serial_out <= shift_register[0]; // Envia o bit menos significativo para a saída serial
            shift_register <= {1'b0, shift_register[5:1]}; // Desloca os bits para a direita
        end
    end

endmodule
