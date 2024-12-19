// ------------------------- 
// Guia_0705 - Unidade Lógica (LU) 
// Nome: xxx yyy zzz 
// Matricula: 999999 
// ------------------------- 

// ------------------------- 
// Unidade Lógica 
// ------------------------- 
module lu ( output reg s,     // saída selecionada
            input  a,         // entrada 1
            input  b,         // entrada 2
            input  [2:0] select ); // seletor 3 bits para escolher a operação

// definir dados locais 
   wire not_a;      // NOT
   wire and_ab;     // AND
   wire nand_ab;    // NAND
   wire or_ab;      // OR
   wire nor_ab;     // NOR
   wire xor_ab;     // XOR
   wire xnor_ab;    // XNOR

// descrever operações lógicas com portas nativas
   not NOT1  (not_a, a);         // NOT de a
   and AND1  (and_ab, a, b);     // AND
   nand NAND1 (nand_ab, a, b);   // NAND
   or  OR1   (or_ab, a, b);      // OR
   nor NOR1  (nor_ab, a, b);     // NOR
   xor XOR1  (xor_ab, a, b);     // XOR
   xnor XNOR1 (xnor_ab, a, b);   // XNOR

// multiplexador 7x1 para selecionar a saída
   always @(*) begin
      case(select)
         3'b000: s = not_a;      // Seleciona NOT
         3'b001: s = and_ab;     // Seleciona AND
         3'b010: s = nand_ab;    // Seleciona NAND
         3'b011: s = or_ab;      // Seleciona OR
         3'b100: s = nor_ab;     // Seleciona NOR
         3'b101: s = xor_ab;     // Seleciona XOR
         3'b110: s = xnor_ab;    // Seleciona XNOR
         default: s = 1'b0;      // Valor padrão (operação inválida)
      endcase
   end

endmodule // lu


// ------------------------- 
// Teste da Unidade Lógica 
// ------------------------- 
module test_lu;
// Definir variáveis locais
   reg  x;         // entrada 1
   reg  y;         // entrada 2
   reg  [2:0] s;   // seletor
   wire z;         // saída

   // Instanciar a unidade lógica
   lu LU1 (z, x, y, s);

   // Parte principal
   initial begin
      $display("Guia_0705 - xxx yyy zzz - 999999");
      $display("Teste da Unidade Logica (LU)");
      $display("  x  y  s  z");

      // Testar diferentes combinações de entradas e seletores
      x = 1'b0; y = 1'b1; s = 3'b000; // NOT
      #1 $display("%2b %2b %3b %2b", x, y, s, z);
      
      s = 3'b001; // AND
      #1 $display("%2b %2b %3b %2b", x, y, s, z);

      s = 3'b010; // NAND
      #1 $display("%2b %2b %3b %2b", x, y, s, z);

      s = 3'b011; // OR
      #1 $display("%2b %2b %3b %2b", x, y, s, z);

      s = 3'b100; // NOR
      #1 $display("%2b %2b %3b %2b", x, y, s, z);

      s = 3'b101; // XOR
      #1 $display("%2b %2b %3b %2b", x, y, s, z);

      s = 3'b110; // XNOR
      #1 $display("%2b %2b %3b %2b", x, y, s, z);
  
   end

endmodule // test_lu

/*
Guia_0705 - xxx yyy zzz - 999999
Teste da Unidade Logica (LU)
  x  y  s  z
 0  1 000  1
 0  1 001  0
 0  1 010  1
 0  1 011  1
 0  1 100  0
 0  1 101  1
 0  1 110  0
*/