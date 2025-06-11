//Alessandra Faria Rodrigues
//828333
//Guia_0504.v

//~(~a & b)
//nand(nand(nand(a,a), b))


module nand_f8 (output s, 
           input  a, 
           input  b); 
// definir dados locais
   wire not_a, not_a_and_b;

// descrições usando apenas portas NAND
   nand NAND1 (not_a, a, a);        // ~a
   nand NAND2 (not_a_and_b, not_a, b); // ~(~a & b)

   // A inversão da última NAND para obter o valor correto.
   nand NAND3 (s, not_a_and_b, not_a_and_b); // ~(~(~a & b))

endmodule // f8

// Módulo de teste para f8
module test_f8; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
 
       nand_f8 moduloA (a, x, y); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
          $display("Guia_0500 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a"); 
          
          // projetar testes do modulo 
          $monitor("%4b %4b %4b", x, y, a); 
             x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
   end 
 
endmodule // test_f8
