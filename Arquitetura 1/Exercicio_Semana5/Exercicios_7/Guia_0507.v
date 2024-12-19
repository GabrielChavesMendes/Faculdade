// ------------------------- 
// Guia_0507.v - GATES 
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
module f5_xor ( output s, input  a, input  b );

   wire nor_ab, nor_aa, nor_bb;

   // Calcula a NAND de a e b
   nor (nor_aa, a, a);
   nor (nor_bb, b, b);          

   nor (nor_ab, nor_aa, nor_bb);

   nor (s, nor_ab, nor_ab);

endmodule // f5_xor


module test_f5_xor;
   reg x;
   reg y;
   wire s;

   f5_xor moduloXOR (s, x, y);

   initial
   begin : main
      $display("Guia_0507 - xxx yyy zzz - 999999");
      $display("Teste modulo XNOR portas");
      $display("   x     y    s");
      $monitor("%4b %4b %4b", x, y, s);

      x = 1'b0; y = 1'b0;
      #1 x = 1'b0; y = 1'b1;
      #1 x = 1'b1; y = 1'b0;
      #1 x = 1'b1; y = 1'b1;
   end
endmodule // test_f5_nor

/*
Guia_0507 - xxx yyy zzz - 999999
Teste modulo XNOR portas
   x     y    s
   0    0    1
   0    1    1
   1    0    1
   1    1    0
*/