//Alessandra Faria Rodrigues
//828333
//Guia_0502.v


module nand_f6 (output s, 
           input  a, 
           input  b); 
// definir dados locais
   wire not_b, not_a, a_or_not_b;

// descrições usando apenas portas NAND
   nand NAND1 (not_b, b, b);        // ~b
   nand NAND2 (not_a, a, a);        // ~a
   nand NAND3 (a_or_not_b, not_a, b); // ~(~a & b)
   nand NAND4 (s, not_a, b);    // a | ~b

endmodule // f6

// Módulo de teste para f6
module test_f6; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
 
       nand_f6 moduloC (a, x, y); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
          $display("Guia_0502 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a"); 
          
          // projetar testes do modulo 
          $monitor("%4b %4b %4b", x, y, a); 
             x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
   end 
 
endmodule // test_f6
