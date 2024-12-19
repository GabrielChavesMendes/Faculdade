module RAM_1x4 (
    input wire CLK,
    input wire R_W,         // 1 para escrita, 0 para leitura
    input wire ADDR,        // 1 para habilitar endereço, 0 para ignorar
    input wire CLR,         // Clear para resetar flip-flops
    input wire [3:0] data_in,  // Entrada de dados (4 bits)
    output reg [3:0] data_out // Saída de dados (4 bits)
);

    // Flip-flops JK para armazenamento dos 4 bits
    reg Q0, Q1, Q2, Q3;

    // Comportamento de escrita na borda de subida do clock
    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            Q0 <= 0;
            Q1 <= 0;
            Q2 <= 0;
            Q3 <= 0;
        end else if (ADDR && R_W) begin
            Q0 <= data_in[0];
            Q1 <= data_in[1];
            Q2 <= data_in[2];
            Q3 <= data_in[3];
        end
    end

    // Comportamento de leitura na borda de descida do clock
    always @(negedge CLK) begin
        if (ADDR && !R_W) begin
            data_out[0] <= Q0;
            data_out[1] <= Q1;
            data_out[2] <= Q2;
            data_out[3] <= Q3;
        end else begin
            data_out <= 4'bx; // Saída indefinida se endereço não habilitado
        end
    end

endmodule
