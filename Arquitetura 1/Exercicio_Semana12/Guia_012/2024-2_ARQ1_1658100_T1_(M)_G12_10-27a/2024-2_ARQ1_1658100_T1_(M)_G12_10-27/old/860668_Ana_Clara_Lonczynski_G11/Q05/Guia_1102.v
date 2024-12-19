/*
Ana Clara Lonczynski
680886
*/

module Guia_1102 (y, x, clk, reset);
  output reg y;           // Saída y que indica quando a sequência é detectada
  input x, clk, reset;    // Entradas: x (sinal de entrada), clk (clock), reset

  // Identificadores de estado
  parameter start  = 3'b000,
            id1    = 3'b001,
            id10   = 3'b010,
            id100  = 3'b011,
            detect = 3'b100;  // Estado ao reconhecer '1001'

  reg [2:0] E1, E2;       // Estado atual e próximo estado

  // Lógica de transição de estado e saída Mealy
  always @(x or E1) begin
    y = 0;  // Saída padrão
    case (E1)
      start: begin
        if (x)
          E2 = id1;
        else
          E2 = start;
      end
      id1: begin
        if (x)
          E2 = id1;       // Permanece em id1 se x for 1
        else
          E2 = id10;
      end
      id10: begin
        if (x)
          E2 = id1;
        else
          E2 = id100;
      end
      id100: begin
        if (x) begin
          E2 = detect;
          y = 1;          // Ativa y ao reconhecer '1001'
        end
        else
          E2 = start;
      end
      detect: begin
        E2 = start;       // Reinicia para buscar nova sequência
      end
      default: E2 = start;
    endcase
  end

  // Atualização de estado
  always @(posedge clk or negedge reset) begin
    if (!reset)
      E1 <= start;         // Reseta para o estado inicial
    else
      E1 <= E2;
  end
endmodule

module Test_Guia_1102;
  reg clk, reset, x;
  wire y;
  Guia_1102 fsm (y, x, clk, reset);

  initial begin
    $display("Guia_1102.v");
    $display("Time   X   Y");
    clk = 0;
    reset = 0;
    x = 0;

    // Reset inicial
    #5 reset = 1;

    #10 x = 1;   // Entrada '1'
    #10 x = 0;   // Entrada '0'
    #10 x = 0;   // Entrada '0'
    #10 x = 1;   // Entrada '1' - Detecta '1001' aqui
    #10 x = 0;   // Reinicia sequência
    #10 x = 1;   // Entrada '1'
    #10 x = 0;   // Entrada '0'
    #10 x = 0;   // Entrada '0'
    #10 x = 1;   // Entrada '1' - Detecta '1001' novamente

    #30 $finish;
  end

  // Gera o clock alternando a cada 5 unidades de tempo
  always #5 clk = ~clk;

  // Mostra os resultados a cada borda de subida do clock
  always @(posedge clk) begin
    $display("%4d   %b   %b", $time, x, y);
  end
endmodule
