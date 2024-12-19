module RAM_1x4 (
    input wire CLK,
    input wire R_W,         // 1 para escrita, 0 para leitura
    input wire ADDR,        // 1 para habilitar endereço
    input wire CLR,         // Clear para resetar memória
    input wire [3:0] data_in, // Entrada de dados de 4 bits
    output reg [3:0] data_out // Saída de dados de 4 bits
);

    // Flip-flops para armazenar os 4 bits
    reg [3:0] memory;

    always @(posedge CLK or posedge CLR) begin
        if (CLR)
            memory <= 4'b0000;
        else if (R_W && ADDR)
            memory <= data_in;
    end

    always @(negedge CLK) begin
        if (!R_W && ADDR)
            data_out <= memory;
        else
            data_out <= 4'bz; // Saída indefinida se não estiver em leitura
    end

endmodule
