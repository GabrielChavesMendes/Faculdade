//Alessandra Faria Rodrigues
//828333
//Guia_0503.v
 
// ~(~a | b) usando nor
//nor(nor(nor(a,a),b))


module nor_f7 (output s, 
           input  a, 
           input  b); 
// definir dados locais
   wire not_a, not_b, not_a_or_b;

// descrições usando apenas portas NOR
   nor NOR1 (not_a, a, a);        // ~a
   //nor NOR2 (not_b, b, b);        // ~b
   nor NOR3 (not_a_or_b, not_a, b); // ~(~a | b)

   // A inversão da última NOR será para obter o valor correto.
   nor NOR4 (s, not_a_or_b, not_a_or_b); // ~(~(~a | b))

endmodule // f7

// Módulo de teste para f7
module test_f7; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
 
       nor_f7 moduloC (a, x, y); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
          $display("Guia_0503 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a"); 
          
          // projetar testes do modulo 
          $monitor("%4b %4b %4b ", x, y, a); 
           x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
   end 
 
endmodule // test_f7
