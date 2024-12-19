module RAM_1x8 (
    input wire CLK,
    input wire R_W,         // 1 para escrita, 0 para leitura
    input wire CLR,         // Clear para resetar a memória
    input wire [7:0] data_in, // Entrada de dados de 8 bits
    output reg [7:0] data_out // Saída de dados de 8 bits
);

    reg [7:0] memory; // Registrador de 8 bits para armazenar os dados

    always @(posedge CLK or posedge CLR) begin
        if (CLR)
            memory <= 8'b00000000;
        else if (R_W) // Escreve na borda de subida do clock
            memory <= data_in;
    end

    always @(negedge CLK) begin
        if (!R_W) // Lê na borda de descida do clock
            data_out <= memory;
    end

endmodule
