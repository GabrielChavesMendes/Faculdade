module registrador_deslocamento (
    input wire clk,             
    input wire LD,             
    input wire [5:0] D_in,     
    output reg [5:0] Q           
);

always @(posedge clk) begin
    if (LD)
        Q <= D_in;               
    else
        Q <= {Q[4:0], 1'b0};     
end

endmodule

`timescale 1ns/1ps

module testbench;

    reg clk;                 // Sinal de clock
    reg LD;                  // Sinal de carga
    reg [5:0] D_in;          // Dados de entrada para carga inicial
    wire [5:0] Q;            // Saída do registrador

    // Instancia o módulo registrador_deslocamento para teste
    registrador_deslocamento uut (
        .clk(clk),
        .LD(LD),
        .D_in(D_in),
        .Q(Q)
    );

    // Geração do clock (alternando a cada 10 unidades de tempo)
    initial begin
        clk = 0;
        forever #10 clk = ~clk;
    end

    // Sequência de teste
    initial begin
        // Exibe o estado dos sinais na simulação
        $monitor("Time=%0t | LD=%b | D_in=%b | Q=%b", $time, LD, D_in, Q);
        
        // Inicializa com LD=1 para carregar D_in
        LD = 1;
        D_in = 6'b101010;     // Define D_in como 101010 para teste
        #20;                  // Aguarda um ciclo de clock para ver a carga
        LD = 0;

        // Desloca para a esquerda com LD=0
        #100;

        // Define uma nova carga completa com LD=1
        LD = 1;
        D_in = 6'b111000;     // Define um novo valor de D_in
        #20;                  // Carrega o novo valor
        LD = 0;

        // Continua deslocando à esquerda
        #100;

        $finish;              // Finaliza a simulação
    end

endmodule
