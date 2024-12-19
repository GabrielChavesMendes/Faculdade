module RAM_8x8 (
    input wire CLK,
    input wire R_W,             // 1 para escrita, 0 para leitura
    input wire [2:0] ADDR,      // Endereço de seleção (3 bits para selecionar entre 8 endereços)
    input wire CLR,             // Clear para resetar as memórias
    input wire [7:0] data_in,   // Entrada de dados de 8 bits
    output reg [7:0] data_out   // Saída de dados de 8 bits
);

    wire [7:0] data_out0, data_out1; // Saídas das duas RAMs 4x8

    // Instância da RAM 4x8 para os endereços 0 a 3
    RAM_4x8 ram0 (
        .CLK(CLK),
        .R_W(R_W && (ADDR[2] == 0)), // Habilita a escrita quando ADDR[2] == 0
        .ADDR(ADDR[1:0]),            // Endereço interno (2 bits para os endereços 0 a 3)
        .CLR(CLR),
        .data_in(data_in),
        .data_out(data_out0)
    );

    // Instância da RAM 4x8 para os endereços 4 a 7
    RAM_4x8 ram1 (
        .CLK(CLK),
        .R_W(R_W && (ADDR[2] == 1)), // Habilita a escrita quando ADDR[2] == 1
        .ADDR(ADDR[1:0]),            // Endereço interno (2 bits para os endereços 4 a 7)
        .CLR(CLR),
        .data_in(data_in),
        .data_out(data_out1)
    );

    // Multiplexador para selecionar a saída correta com base em ADDR[2]
    always @(*) begin
        case (ADDR[2])
            1'b0: data_out = data_out0;
            1'b1: data_out = data_out1;
            default: data_out = 8'bz;
        endcase
    end

endmodule
