module RAM2x8 (
    input wire addr,            // Seleção do endereço (0 ou 1)
    input wire [7:0] data_in,  // Dados de entrada (8 bits)
    input wire we,             // Write Enable
    output reg [7:0] data_out   // Dados de saída (8 bits)
);
    reg [7:0] RAM[1:0]; // Array de 2 memórias RAM de 8 bits

    always @(posedge we) begin
        RAM[addr] <= data_in; // Escreve os 8 bits no endereço selecionado
    end

    always @(addr or RAM[0] or RAM[1]) begin
        data_out = RAM[addr]; // Lê os dados do endereço selecionado
    end
endmodule
