/*
Ana Clara Lonczynski
680886
*/

`timescale 1ns / 1ps

`define found 1
`define notfound 0

module moore_1101 (y, x, clk, reset);
  output reg y;           // Saída da FSM
  input x;                 // Entrada de dados
  input clk;               // Clock
  input reset;             // Reset

  // Identificadores de estados
  parameter start  = 3'b000,
            id1    = 3'b001,
            id11   = 3'b011,
            id110  = 3'b010,
            id1101 = 3'b110; // Estado onde a sequência é detectada

  // Variáveis de estado
  reg [2:0] E1; // Estado atual
  reg [2:0] E2; // Próximo estado

  // Lógica de transição de estado
  always @(x or E1) begin
    case (E1)
      start:  if (x) E2 = id1; else E2 = start;
      id1:    if (x) E2 = id11; else E2 = start;
      id11:   if (x) E2 = id11; else E2 = id110;
      id110:  if (x) E2 = id1101; else E2 = start;
      id1101: if (x) E2 = id11; else E2 = start;
      default: E2 = 3'bxxx; // Estado indefinido
    endcase
  end

  // Atualização do estado atual no clock
  always @(posedge clk or negedge reset) begin
    if (reset)
      E1 = E2; // Atualiza o estado atual
    else
      E1 = 0; // Reset
  end

  module testbench;
    reg x;        // Entrada de dados
    reg clk;      // Clock
    reg reset;    // Reset
    wire y;       // Saída da FSM

    // Instância da FSM
    moore_1101 fsm (y, x, clk, reset);

    // Geração do clock (alternância a cada 5 ns)
    initial begin
      clk = 0;
      forever #5 clk = ~clk;
    end

    // Simulação da entrada e reset
    initial begin
      $display("Moore.v");
      $display("---------------------------------");
      $display("Tempo\tReset\tX\tEstado\tY");
      $display("---------------------------------");

      // Reseta a FSM no início
      reset = 0;
      x = 0;
      #10 reset = 1;

      // Sequência de testes
      #10 x = 1;  // Entrada '1'
      #10 x = 1;  // Entrada '1'
      #10 x = 0;  // Entrada '0'
      #10 x = 1;  // Entrada '1' (deve detectar a sequência 1101)

      #10 x = 0;  // Entrada '0' (reinicia sequência)
      #10 x = 1;  // Entrada '1'
      #10 x = 1;  // Entrada '1'
      #10 x = 0;  // Entrada '0'
      #10 x = 1;  // Entrada '1' (detecta a sequência novamente)

      #10 $finish; // Termina a simulação
    end

    // Monitoramento das variáveis
    always @(posedge clk) begin
      $display("%0d\t%b\t%b\t%b\t%b", $time, reset, x, fsm.E1, y);
    end
  endmodule

  // Lógica de saída (independente da entrada `x`)
  always @(E1) begin
    y = (E1 == id1101) ? `found : `notfound;
  end
endmodule
