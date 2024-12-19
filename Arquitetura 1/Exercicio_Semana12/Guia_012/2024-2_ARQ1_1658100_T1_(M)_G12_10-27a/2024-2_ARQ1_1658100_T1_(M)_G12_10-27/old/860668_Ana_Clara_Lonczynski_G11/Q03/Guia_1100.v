/*
Ana Clara Lonczynski
680886
*/

`include "Mealy_1101.v" // Inclui o módulo de Mealy
`include "Moore_1101.v" // Inclui o módulo de Moore

module Guia_1101;
  reg clk, reset, x; // Define o clock, reset e entrada x
  wire m1, m2;        // Define as saídas das FSMs Mealy e Moore

  // Instancia as máquinas de estado Mealy e Moore
  mealy_1101 mealy1 (m1, x, clk, reset);
  moore_1101 moore1 (m2, x, clk, reset);

  // Sequência de estímulos
  initial begin
    $display("Guia_1100.v");
    $display("Time   X   Mealy Moore"); // Cabeçalho de saída

    clk = 1;
    reset = 0;
    x = 0;

    #5 reset = 1;      // Ativa o reset em 5 unidades de tempo
    #10 x = 1;         // Entrada '1' em 15 unidades de tempo
    #10 x = 0;         // Entrada '0' em 25 unidades de tempo
    #10 x = 1;         // Entrada '1' em 35 unidades de tempo
    #20 x = 0;         // Entrada '0' em 55 unidades de tempo
    #10 x = 1;         // Entrada '1' em 65 unidades de tempo
    #10 x = 1;         // Entrada '1' em 75 unidades de tempo
    #10 x = 0;         // Entrada '0' em 85 unidades de tempo
    #10 x = 1;         // Entrada '1' em 95 unidades de tempo
    #30 $finish;       // Finaliza a simulação em 125 unidades de tempo
  end

  // Gera o clock alternando a cada 5 unidades de tempo
  always #5 clk = ~clk;

  // Mostra o valor das variáveis a cada borda de subida do clock
  always @(posedge clk) begin
    $display("%4d    %b     %b     %b", $time, x, m1, m2);
  end
endmodule // Guia_1101
