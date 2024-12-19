`include "clock.v"  // Inclui o módulo clock a partir do arquivo separado

// ---------------------------
// -- pulse1 generator
// ---------------------------
module pulse1 (output reg signal, input clock);
  always @ (posedge clock) begin
    signal = 1'b1;
    #4 signal = 1'b0;
    #4 signal = 1'b1;
    #4 signal = 1'b0;
    #4 signal = 1'b1;
    #4 signal = 1'b0;
  end
endmodule

// ---------------------------
// -- pulse2 generator
// ---------------------------
module pulse2 (output reg signal, input clock);
  always @ (posedge clock) begin
    signal = 1'b1;
    #5 signal = 1'b0;
  end
endmodule

// ---------------------------
// -- pulse3 generator
// ---------------------------
module pulse3 (output reg signal, input clock);
  always @ (negedge clock) begin
    signal = 1'b1;
    #15 signal = 1'b0;
    #15 signal = 1'b1;
  end
endmodule

// ---------------------------
// -- pulse4 generator
// ---------------------------
module pulse4 (output reg signal, input clock);
  always @ (negedge clock) begin
    signal = 1'b1;
    #20 signal = 1'b0;
    #20 signal = 1'b1;
    #20 signal = 1'b0;
  end
endmodule

// ---------------------------
// -- Guia_0902 Testbench
// ---------------------------
module Guia_0902;
  wire clock;
  wire p1, p2, p3, p4;

  // Instanciar o gerador de clock e os geradores de pulsos
  clock clk (clock);
  pulse1 pls1 (p1, clock);
  pulse2 pls2 (p2, clock);
  pulse3 pls3 (p3, clock);
  pulse4 pls4 (p4, clock);

  initial begin
    $dumpfile("Guia_0902.vcd");  // Arquivo de saída para o GTKWave
    $dumpvars(1, clock, p1, p2, p3, p4);
    #480 $finish;  // Duração da simulação
  end
endmodule
