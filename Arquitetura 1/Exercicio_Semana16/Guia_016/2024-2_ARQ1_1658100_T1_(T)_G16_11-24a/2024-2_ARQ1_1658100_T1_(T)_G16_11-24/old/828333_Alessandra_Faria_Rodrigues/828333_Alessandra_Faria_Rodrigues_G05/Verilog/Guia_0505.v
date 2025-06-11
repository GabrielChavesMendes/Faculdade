//Alessandra Faria Rodrigues
//828333
//Guia_0505.v

// ~(a ^ b) = a xnor b
 
module nor_f9 (output s, 
           input  a, 
           input  b); 
// definir dados locais
   wire not_a, not_b, a_and_b, not_a_and_not_b, or_result;

// descrições usando apenas portas NOR
   nor NOR1 (not_a, a, a);              // ~a
   nor NOR2 (not_b, b, b);              // ~b
   nor NOR3 (a_and_b, not_a, not_b);    // ~(~a | ~b) -> (a & b)
   nor NOR4 (not_a_and_not_b, a, b);    // ~(a | b) -> (~a & ~b)
   nor NOR5 (or_result, a_and_b, not_a_and_not_b); // ~(~(a & b) | ~(~a & ~b))
   nor NOR6 (s, or_result, or_result);  // ~(~or_result) -> (a & b) | (~a & ~b)

endmodule // f9

// Módulo de teste para f9
module test_f9; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
 
       nor_f9 moduloA (a, x, y); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
          $display("Guia_0505 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a"); 
          
          // projetar testes do modulo 
          $monitor("%4b %4b %4b ", x, y, a); 
             x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
   end 
 
endmodule // test_f9
