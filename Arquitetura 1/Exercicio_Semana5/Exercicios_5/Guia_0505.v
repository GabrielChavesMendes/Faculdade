// ------------------------- 
// Guia_0505.v - GATES 
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
module f5_xnor ( output s, input  a, input  b );

   wire na, nb, nand_ab, nand_ba;

   // Inversão dos sinais a e b usando portas NOR
   nor (na, a, a); // na = ~a
   nor (nb, b, b); // nb = ~b

   // NOR dos sinais invertidos
   nor (nand_ab, a, nb); // NAND(a, ~b) = ~(a & ~b)
   nor (nand_ba, b, na); // NAND(b, ~a) = ~(b & ~a)

   // NOR final para obter o XNOR
   nor (s, nand_ab, nand_ba); // XNOR = ~(NAND(a, ~b) & NAND(b, ~a))

endmodule // f5_xnor


module test_f5_xnor;
   reg x;
   reg y;
   wire s;

   f5_xnor moduloXNOR (s, x, y);

   initial
   begin : main
      $display("Guia_0505 - xxx yyy zzz - 999999");
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
Guia_0505 - xxx yyy zzz - 999999
Teste modulo XNOR portas
   x     y    s
   0    0    1
   0    1    0
   1    0    0
   1    1    1
*/