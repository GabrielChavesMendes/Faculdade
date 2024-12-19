module RAM8x8 (
    input wire [2:0] addr,        // Seleção do endereço (3 bits)
    input wire [7:0] data_in,     // Dados de entrada (8 bits)
    input wire we,                // Write Enable
    output reg [7:0] data_out      // Dados de saída (8 bits)
);
    reg [7:0] RAM0 [3:0]; // RAM 0: Endereços 0, 1, 2, 3
    reg [7:0] RAM1 [3:0]; // RAM 1: Endereços 4, 5, 6, 7

    always @(posedge we) begin
        if (addr[2] == 0) begin
            RAM0[addr[1:0]] <= data_in; // Escreve no endereço 0, 1, 2 ou 3
        end else begin
            RAM1[addr[1:0]] <= data_in; // Escreve no endereço 4, 5, 6 ou 7
        end
    end

    always @(addr) begin
        if (addr[2] == 0) begin
            data_out = RAM0[addr[1:0]]; // Lê do endereço 0, 1, 2 ou 3
        end else begin
            data_out = RAM1[addr[1:0]]; // Lê do endereço 4, 5, 6 ou 7
        end
    end
endmodule
