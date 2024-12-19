`include "clock.v"

// ---------------------------
// -- Pulse generator (4x frequency)
// ---------------------------
module pulse (output reg signal, input clock);
  initial begin
    signal = 1'b0;  // Inicializa o sinal do pulso em 0
  end

  always @ (posedge clock) begin
    signal = 1'b1;  // Gera o pulso alto
    #3 signal = 1'b0;  // Gera o pulso baixo após 3 unidades de tempo
  end
endmodule

// ---------------------------
// -- Testbench for Guia_0904
// ---------------------------
module Guia_0904;
  wire clock;
  wire pulse_signal;

  // Instancia o gerador de clock e o gerador de pulso
  clock clk_gen (clock);       // Clock gerado a partir de clock.v
  pulse pulse_gen (pulse_signal, clock);  // Gerador de pulso com 4x da frequência do clock

  initial begin
    $dumpfile("Guia_0904.vcd");  // Arquivo de saída para GTKWave
    $dumpvars(1, clock, pulse_signal);
    #480 $finish;  // Duração da simulação
  end
endmodule
