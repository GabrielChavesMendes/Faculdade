// Guia_1100.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------------
// --- Mealy-Moore FSM
// --------------------
`include "mealy_1101.v"
`include "moore_1101.v"

module Guia_1100;
    reg clk, reset, x;
    wire m1, m2;

    // Instanciando os módulos Mealy e Moore
    mealy_1101 mealy1(
        .y(m1),
        .x(x),
        .clk(clk),
        .reset(reset)
    );
    
    moore_1101 moore1(
        .y(m2),
        .x(x),
        .clk(clk),
        .reset(reset)
    );

    initial begin
        // Exibe o cabeçalho da simulação
        $display("Time   X   Mealy   Moore");

        // Inicializando sinais
        clk = 1;
        reset = 0;
        x = 0;
        
        // Sequência de testes
        #5 reset = 1;  // Reset ativo
        #10 x = 1;
        #10 x = 0;
        #10 x = 1;
        #20 x = 0;
        #10 x = 1;
        #10 x = 1;
        #10 x = 0;
        #10 x = 1;
        
        // Encerrando simulação após 30 unidades de tempo
        #30 $finish;
    end

    // Geração do sinal de clock
    always #5 clk = ~clk;

    // Exibe os valores durante a borda de subida do clock
    always @(posedge clk) begin
        $display("%4d   %b     %b      %b", $time, x, m1, m2);
    end
endmodule
