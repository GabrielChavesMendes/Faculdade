module RAM8x16 (
    input wire [2:0] addr,        // Seleção do endereço (3 bits)
    input wire [15:0] data_in,    // Dados de entrada (16 bits)
    input wire we,                // Write Enable
    output reg [15:0] data_out      // Dados de saída (16 bits)
);
    reg [15:0] RAM[7:0]; // 8 endereços de 16 bits

    always @(posedge we) begin
        // Escreve os dados nos endereços selecionados
        RAM[addr] <= data_in; 
    end

    always @(addr) begin
        // Lê os dados do endereço selecionado
        data_out = RAM[addr]; 
    end
endmodule
