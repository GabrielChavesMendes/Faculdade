//Alessandra Faria Rodrigues
//828333
//Guia_0506.v

//  ~(a ^ b) = a xnor b

 
module nand_f10 (output s, 
            input  a, 
            input  b); 
// definir dados locais 
   wire not_a;
   wire not_b;
   wire a_and_b;
   wire not_a_and_not_b;

// descrever por portas 
   nand NAND1 (not_a, a, a); // ~a
   nand NAND2 (not_b, b, b); // ~b
   nand NAND3 (a_and_b, a, b); // a & b
   nand NAND4 (not_a_and_not_b, not_a, not_b); // ~a & ~b
   nand NAND5 (s, a_and_b, not_a_and_not_b); // ~(a & b) & ~(~a & ~b)

endmodule // f10

// Módulo de teste para f10
module test_f10; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
 
       nand_f10 moduloA (a, x, y); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
          $display("Guia_0506 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a "); 
          
          // projetar testes do modulo 
          $monitor("%4b %4b %4b", x, y, a); 
             x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
   end 
 
endmodule // test_f10
