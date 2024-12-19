// Módulo: Registrador de Deslocamento para a Esquerda
module registrador_deslocamento (
    input wire clk,             // Sinal de clock
    input wire LD,              // Sinal de carga
    input wire D_in,            // Bit a ser carregado no primeiro estágio
    output reg [5:0] Q         
);

always @(posedge clk) begin
    if (LD)
        Q <= {Q[4:0], D_in};    
    else
        Q <= {Q[4:0], 1'b0};   
end

endmodule

// Testbench para o Registrador de Deslocamento
`timescale 1ns/1ps

module testbench;

    reg clk;                // Sinal de clock
    reg LD;                 // Sinal de carga
    reg D_in;               // Bit de carga unitária
    wire [5:0] Q;           // Saída do registrador

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


    initial begin
   
        $monitor("Time=%0t | LD=%b | D_in=%b | Q=%b", $time, LD, D_in, Q);
        

        LD = 1;
        D_in = 1;

       
        #20;  
        LD = 0;

      
        #100;

        
        LD = 1;
        D_in = 0;

       
        #20;
        LD = 0;

        
        #100;

        $finish;  // Finaliza a simulação
    end

endmodule
