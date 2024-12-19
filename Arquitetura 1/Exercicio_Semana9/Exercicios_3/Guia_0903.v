`include "clock.v"  // Inclui o gerador de clock definido em clock.v

// ---------------------------
// -- Pulse generator (1/3 frequency)
// ---------------------------
module pulse (output reg signal, input clock);
  integer count;  // Variável de contagem para estender o período do clock

  initial begin
    signal = 1'b0;
    count = 0;
  end

  always @ (posedge clock) begin
    count = count + 1;
    if (count == 3) begin
      signal = ~signal;  // Inverte o sinal a cada 3 ciclos do clock
      count = 0;         // Reinicia o contador
    end
  end
endmodule

// ---------------------------
// -- Testbench for Guia_0903
// ---------------------------
module Guia_0903;
  wire clock;
  wire pulse_signal;

  // Instancia o gerador de clock e o gerador de pulso
  clock clk_gen (clock);       // Clock gerado a partir de clock.v
  pulse pulse_gen (pulse_signal, clock);  // Gerador de pulso com 1/3 da frequência do clock

  initial begin
    $dumpfile("Guia_0903.vcd");  // Arquivo de saída para GTKWave
    $dumpvars(1, clock, pulse_signal);
    #480 $finish;  // Duração da simulação
  end
endmodule
