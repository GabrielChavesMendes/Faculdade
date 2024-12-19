/*
Ana Clara Lonczynski
680886
*/
module Guia_1101 (y, x, clk, reset);
  output reg y;          // Saída y que indica quando a sequência é detectada
  input x, clk, reset;   // Entradas: x (sinal de entrada), clk (clock), reset

  // Identificadores de estado
  parameter start  = 3'b000,
            id1    = 3'b001,
            id10   = 3'b010,
            id100  = 3'b011,
            id1001 = 3'b100,  // Estado final ao detectar a sequência '1001'
            done   = 3'b101;  // Estado de finalização que ignora novas entradas

  reg [2:0] E1, E2;      // Estado atual e próximo estado

  // Lógica de transição de estado
  always @(x or E1) begin
    case (E1)
      start:  E2 = x ? id1 : start;
      id1:    E2 = x ? id1 : id10;
      id10:   E2 = x ? id100 : start;
      id100:  E2 = x ? id1 : id1001;
      id1001: E2 = done;       // Ao detectar '1001', vai para o estado 'done'
      done:   E2 = done;       // Mantém-se em 'done' após a primeira detecção
      default: E2 = 3'bxxx;
    endcase
  end

  // Atualização de estado
  always @(posedge clk or negedge reset) begin
    if (!reset)
      E1 <= start;             // Reseta para o estado inicial
    else
      E1 <= E2;
  end

  // Lógica de saída
  always @(E1) begin
    if (E1 == id1001)
      y = 1;                  // Sinaliza a detecção de '1001'
    else
      y = 0;                  // Saída permanece 0 até que a sequência seja detectada
  end
endmodule

//testes

module Test_Guia_1101;
  reg clk, reset, x;
  wire y;
  Guia_1101 fsm (y, x, clk, reset);

  initial begin
    $display("Guia_1101.v");
    $display("Time   X   Y");
    clk = 0;
    reset = 0;
    x = 0;

    #5 reset = 1;

    // Sequência de testes para verificar apenas a primeira detecção de '1001'
    #10 x = 1;   // Entrada '1'
    #10 x = 0;   // Entrada '0'
    #10 x = 0;   // Entrada '0'
    #10 x = 1;   // Entrada '1' - Detecta '1001' aqui
    #10 x = 0;   // Entrada extra após a detecção

    // Repetir '1001' para garantir que não seja detectada novamente
    #10 x = 1;
    #10 x = 0;
    #10 x = 0;
    #10 x = 1;

    #30 $finish;
  end

  // Gera o clock alternando a cada 5 unidades de tempo
  always #5 clk = ~clk;

  // Mostra os resultados a cada borda de subida do clock
  always @(posedge clk) begin
    $display("%4d   %b   %b", $time, x, y);
  end
endmodule
