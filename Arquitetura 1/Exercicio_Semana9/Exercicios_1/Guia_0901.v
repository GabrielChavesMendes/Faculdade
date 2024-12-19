// ---------------------------
// -- test clock generator (2)
// ---------------------------
module clock (output reg clk);
  initial begin
    clk = 1'b0;
  end
  always begin
    #12 clk = ~clk;  // Gera clock com período de 24 unidades de tempo
  end
endmodule

// ---------------------------
// -- pulse generator
// ---------------------------
module pulse (output reg signal, input clock);
  always @ (posedge clock) begin
    signal = 1'b1;
    #3 signal = 1'b0;
    #3 signal = 1'b1;
    #3 signal = 1'b0;
  end
endmodule

// ---------------------------
// -- trigger generator
// ---------------------------
module trigger (output reg signal, input on, input clock);
  always @ (posedge clock) begin
    if (on) begin
      #60 signal = 1'b1;
      #60 signal = 1'b0;
    end
  end
endmodule

// ---------------------------
// -- Guia_0901 Testbench
// ---------------------------
module Guia_0901;
  wire clock;
  reg p;
  wire p1, t1;

  // Instanciar clock, pulse e trigger
  clock clk (clock);
  pulse pulse1 (p1, clock);
  trigger trigger1 (t1, p, clock);

  initial begin
    p = 1'b0;
  end

  initial begin
    $dumpfile("Guia_0901.vcd");  // Arquivo de saída para o GTKWave
    $dumpvars(1, clock, p1, p, t1);

    #60  p = 1'b1;
    #120 p = 1'b0;
    #180 p = 1'b1;
    #240 p = 1'b0;
    #300 p = 1'b1;
    #360 p = 1'b0;
    #376 $finish;  // Termina a simulação
  end
endmodule
