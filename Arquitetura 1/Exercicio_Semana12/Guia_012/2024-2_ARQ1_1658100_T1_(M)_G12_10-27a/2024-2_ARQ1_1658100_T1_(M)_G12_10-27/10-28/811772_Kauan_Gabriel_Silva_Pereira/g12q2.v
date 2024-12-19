module RAM1x8 (
    input wire addr,            // Seleção da RAM (0 ou 1)
    input wire [7:0] data_in,  // Dados de entrada (8 bits)
    input wire we,             // Write Enable
    output reg [7:0] data_out   // Dados de saída (8 bits)
);
    reg [3:0] RAM0; // Primeira RAM de 4 bits
    reg [3:0] RAM1; // Segunda RAM de 4 bits

    always @(posedge we) begin
        if (addr == 0) begin
            RAM0 <= data_in[3:0];     // Escreve os 4 bits menos significativos
            RAM1 <= data_in[7:4];     // Escreve os 4 bits mais significativos
        end else if (addr == 1) begin
            RAM0 <= data_in[3:0];     // Escreve os 4 bits menos significativos
            RAM1 <= data_in[7:4];     // Escreve os 4 bits mais significativos
        end
    end

    always @(addr or RAM0 or RAM1) begin
        data_out = {RAM1, RAM0}; // Combina os dados das duas RAMs
    end
endmodule
