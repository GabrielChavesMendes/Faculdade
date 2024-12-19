module registrador_deslocamento_circular_torcido (
    input wire clk,               // Sinal de clock
    input wire LD,                // Sinal de carga
    input wire D_in,              // Dado de entrada para carga no primeiro estágio
    output reg [5:0] Q            // Saída do registrador (6 bits)
);

always @(posedge clk) begin
    if (LD)
        Q <= {Q[4:0], D_in};      
    else
        Q <= {Q[4:0], Q[5]};      
end

endmodule


`timescale 1ns/1ps

module testbench;

    reg clk;                 // Sinal de clock
    reg LD;                  // Sinal de carga
    reg D_in;                // Dado de entrada para carga unitária no primeiro estágio
    wire [5:0] Q;            // Saída do registrador

    // Instancia o módulo registrador_deslocamento_circular_torcido para teste
    registrador_deslocamento_circular_torcido uut (
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
        
        // Inicializa as entradas
        LD = 1;
        D_in = 1;              

       
        #20;                
        LD = 0;

        // Inicia o deslocamento circular para a esquerda (LD=0)
        #100;

        // Define uma nova carga unitária (LD=1)
        LD = 1;
        D_in = 0;            
        #20;                 
        LD = 0;

        // Continua o deslocamento circular para a esquerda
        #100;

        $finish;               // Finaliza a simulação
    end

endmodule
