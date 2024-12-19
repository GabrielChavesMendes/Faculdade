// ------------------------- 
// Guia_0501.v - GATES 
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
module f5_nor (output s, input a, input b);
   wire not_a, not_b, temp;

   // Negação de 'a' usando NOR
   nor NOR1 (not_a, a, a);

   // Negação de 'b' usando NOR
   nor NOR2 (not_b, b, b);

   // Resultado final: ~(~a + b)
   nor NOR3 (temp, not_a, b);
   nor NOR4 (s, temp, temp);
endmodule 
 
 
 
 
 
 
module test_f5_nor;
   reg x;
   reg y;
   wire s;

   f5_nor moduloNOR (s, x, y);

   initial
   begin : main
      $display("Guia_0500 - xxx yyy zzz - 999999");
      $display("Teste modulo NOR portas");
      $display("   x     y    s");
      $monitor("%4b %4b %4b", x, y, s);

      x = 1'b0; y = 1'b0;
      #1 x = 1'b0; y = 1'b1;
      #1 x = 1'b1; y = 1'b0;
      #1 x = 1'b1; y = 1'b1;
   end
endmodule // test_f5

/*
Guia_0500 - xxx yyy zzz - 999999
Teste modulo NOR portas
   x     y    s
   0    0    1
   0    1    1
   1    0    0
   1    1    1
*/