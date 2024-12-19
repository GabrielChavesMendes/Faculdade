// ------------------------- 
// Guia_0504.v - GATES 
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
module f5_nand ( output s, 
                     input  a, 
                     input  b ); 
// definir dado local 
   wire not_a; 
// descrever por portas 
   not NOT1  ( not_a, a ); 
   nand NAND1 ( s, not_a, b ); 
   not NOT2(not_s, s);
endmodule // f5_nand


module test_f5_nand;
   reg x;
   reg y;
   wire s;

   f5_nand moduloNAND (s, x, y);

   initial
   begin : main
      $display("Guia_0504 - xxx yyy zzz - 999999");
      $display("Teste modulo NOR portas");
      $display("   x     y    s");
      $monitor("%4b %4b %4b", x, y, s);

      x = 1'b0; y = 1'b0;
      #1 x = 1'b0; y = 1'b1;
      #1 x = 1'b1; y = 1'b0;
      #1 x = 1'b1; y = 1'b1;
   end
endmodule // test_f5_nor

/*
Guia_0504 - xxx yyy zzz - 999999
Teste modulo NOR portas
   x     y    s
   0    0    1
   0    1    0
   1    0    1
   1    1    1
*/