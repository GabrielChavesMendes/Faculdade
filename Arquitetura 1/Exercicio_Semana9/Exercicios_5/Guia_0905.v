`include "clock.v"  
// ---------------------------
// -- Pulse generator (4 time units)
// ---------------------------
module pulse (output reg signal, input clock);
  initial begin
    signal = 1'b0;  // Inicializa o sinal do pulso em 0
  end

  always @ (posedge clock) begin
    signal = 1'b1;   // Gera o pulso alto
    #4 signal = 1'b0;  // Gera o pulso baixo após 4 unidades de tempo
  end
endmodule

// ---------------------------
// -- Testbench for Guia_0905
// ---------------------------
module Guia_0905;
  wire clock;
  wire pulse_signal;

  // Instancia o gerador de clock e o gerador de pulso
  clock clk_gen (clock);         // Clock gerado a partir de clock.v
  pulse pulse_gen (pulse_signal, clock);  // Gerador de pulso sincronizado com o clock

  initial begin
    $dumpfile("Guia_0905.vcd");  // Arquivo de saída para GTKWave
    $dumpvars(1, clock, pulse_signal);
    #480 $finish;  // Duração da simulação
  end
endmodule
