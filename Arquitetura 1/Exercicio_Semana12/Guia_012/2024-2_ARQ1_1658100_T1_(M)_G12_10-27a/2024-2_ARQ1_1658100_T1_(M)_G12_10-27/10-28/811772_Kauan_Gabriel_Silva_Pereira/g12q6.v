module RAM4x16 (
    input wire [1:0] addr,        // Seleção do endereço (2 bits)
    input wire [15:0] data_in,    // Dados de entrada (16 bits)
    input wire we,                // Write Enable
    output reg [15:0] data_out      // Dados de saída (16 bits)
);
    reg [7:0] RAM0 [3:0]; // RAM 0: Endereços 0, 1, 2, 3
    reg [7:0] RAM1 [3:0]; // RAM 1: Endereços 0, 1, 2, 3

    always @(posedge we) begin
        // Escreve os 8 bits superiores e inferiores
        if (addr < 2'b10) begin
            RAM0[addr] <= data_in[7:0];   // Escreve os 8 bits inferiores
            RAM1[addr] <= data_in[15:8];  // Escreve os 8 bits superiores
        end
    end

    always @(addr) begin
        // Lê os dados de RAM0 e RAM1
        if (addr < 2'b10) begin
            data_out = {RAM1[addr], RAM0[addr]}; // Combina as saídas em 16 bits
        end
    end
endmodule
