module RAM_2x8 (
    input wire CLK,
    input wire R_W,           // 1 para escrita, 0 para leitura
    input wire ADDR,          // Endereço de seleção (1 bit para selecionar entre RAM0 e RAM1)
    input wire CLR,           // Clear para resetar as memórias
    input wire [7:0] data_in, // Entrada de dados de 8 bits
    output reg [7:0] data_out // Saída de dados de 8 bits
);

    reg [7:0] memory [1:0]; // 2 endereços de 8 bits cada

    always @(posedge CLK or posedge CLR) begin
        if (CLR)
            memory[0] <= 8'b00000000;
            memory[1] <= 8'b00000000;
        else if (R_W)
            memory[ADDR] <= data_in;
    end

    always @(negedge CLK) begin
        if (!R_W)
            data_out <= memory[ADDR];
        else
            data_out <= 8'bz;
    end

endmodule
