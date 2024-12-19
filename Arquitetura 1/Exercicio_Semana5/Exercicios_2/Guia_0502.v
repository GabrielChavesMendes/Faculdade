// ------------------------- 
// Guia_0502v - GATES 
// Nome: xxx yyy zzz 
// Matricula: 999999 
// ------------------------- 
 
// ------------------------- 
//  f5_gate 
//  m  a  b  s 
//  0  0  0  0 
//  1  0  1  1 <- a'.b 
//  2  1  0  0 
//  3  1  1  0 
// 
// ------------------------- 
module f5_nand (output s, input a, input b);
   wire not_b, temp1, temp2;

   // Negação de 'b' usando NOR
   nand NAND1 (not_b, b, b);

   // Resultado final: ~(a | ~b)
   nor NOR2 (temp1, a, not_b);
   nor NOR3 (s, temp1, temp1);
endmodule 
 
 
 
 
 
 
module test_f5_nand;
   reg x;
   reg y;
   wire s;

   f5_nand moduloNAND (s, x, y);

   initial
   begin : main
      $display("Guia_0502 - xxx yyy zzz - 999999");
      $display("Teste modulo NAND portas");
      $display("   x     y    s");
      $monitor("%4b %4b %4b", x, y, s);

      x = 1'b0; y = 1'b0;
      #1 x = 1'b0; y = 1'b1;
      #1 x = 1'b1; y = 1'b0;
      #1 x = 1'b1; y = 1'b1;
   end
endmodule // test_f5

/*
Guia_0502 - xxx yyy zzz - 999999
Teste modulo NAND portas
   x     y    s
   0    0    1
   0    1    0
   1    0    1
   1    1    1
*/