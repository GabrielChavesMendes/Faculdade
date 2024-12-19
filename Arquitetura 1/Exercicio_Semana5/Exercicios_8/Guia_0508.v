// ------------------------- 
// Guia_0508.v - GATES 
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

   wire nand_ab, nand_aa, nand_bb;

   // Calcula a NAND de a e b
   nand (nand_aa, a, a);
   nand (nand_bb, b, b);          

   nand (nand_ab, nand_aa, nand_bb);

   nor (s, nand_ab, nand_ab);

endmodule // f5_xor


module test_f5_xor;
   reg x;
   reg y;
   wire s;

   f5_xor moduloXOR (s, x, y);

   initial
   begin : main
      $display("Guia_0508 - xxx yyy zzz - 999999");
      $display("Teste modulo NAND portas");
      $display("   x     y    s");
      $monitor("%4b %4b %4b", x, y, s);

      x = 1'b0; y = 1'b0;
      #1 x = 1'b0; y = 1'b1;
      #1 x = 1'b1; y = 1'b0;
      #1 x = 1'b1; y = 1'b1;
   end
endmodule // test_f5_nor

/*
Guia_0508 - xxx yyy zzz - 999999
Teste modulo NAND portas
   x     y    s
   0    0    1
   0    1    0
   1    0    0
   1    1    0
*/