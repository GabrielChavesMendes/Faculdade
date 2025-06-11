//Alessandra Faria Rodrigues
//828333
//Guia_0508.v

// ~(~a | ~b)

 
module nand_f12 ( output s, 
                     input  a, 
                     input  b ); 
// definir dados locais 
   wire not_a;
   wire not_b;
   wire not_a_or_not_b;

// descrever por portas 
   nand NAND1 (not_a, a, a); // ~a
   nand NAND2 (not_b, b, b); // ~b
   nand NAND3 (not_a_or_not_b, not_a, not_b); // ~a | ~b
   nand NAND4 (s, not_a_or_not_b, not_a_or_not_b); // ~(~a | ~b)
endmodule // nand_f12 

module test_f12; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
 
       nand_f12 moduloA ( a, x, y ); 
 
// ------------------------- parte principal 
 
   initial 
   begin : main 
          $display("Guia_0508 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a"); 
 
       // projetar testes do modulo 
         $monitor("%4b %4b %4b", x, y, a); 
             x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
 
   end 
 
endmodule // test_f12 
