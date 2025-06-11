//Alessandra Faria Rodrigues
//828333
//Guia_0507.v

// ~(a ^ b)


module nor_f11 ( output s, 
                     input  a, 
                     input  b ); 
// definir dados locais 
   wire not_a;
   wire not_b;
   wire not_a_or_not_b;
   wire a_or_b;
   wire not_a_or_b;

// descrever por portas 
   nor NOR1 (not_a, a, a); // ~a
   nor NOR2 (not_b, b, b); // ~b
   nor NOR3 (not_a_or_not_b, not_a, not_b); // ~a | ~b
   nor NOR4 (a_or_b, a, b); // a | b
   nor NOR5 (not_a_or_b, a_or_b, a_or_b); // ~(a | b)
   nor NOR6 (s, not_a_or_not_b, not_a_or_b); // (~a | ~b) & ~(a | b)
endmodule // nor_f11 

module test_f11; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 

       nor_f11 moduloA ( a, x, y ); 
 
// ------------------------- parte principal 
 
   initial 
   begin : main 
          $display("Guia_0507 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a "); 
 
       // projetar testes do modulo 
         $monitor("%4b %4b %4b ", x, y, a); 
             x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
 
   end 
 
endmodule // test_f11 
