//Alessandra Faria Rodrigues
//828333
//Guia_0501.v

// ------------------------- 
//  f5_gate 
//  m  a  b  s 
//  0  0  0  0 
//  1  0  1  1 <- a'.b 
//  2  1  0  0 
//  3  1  1  0 
// 
// ------------------------- 
module nor_f5 (output s, 
            input  a, 
            input  b); 
// definir dados locais
   wire not_a, not_b, not_a_and_b;

// descrições usando apenas portas NOR
   nor NOR1 (not_a, a, a);        // ~a
   nor NOR2 (not_b, b, b);        // ~b
   nor NOR3 (not_a_and_b, not_a, not_b); // (~a & b)'
   nor NOR4 (s, not_a_and_b, not_a_and_b); // inverter para obter (~a & b)

endmodule // f5c

// Módulo de teste para nor_f5
module test_f5; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       wire a; 
  
       nor_f5 moduloA (a, x, y); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
          $display("Guia_0501 - Alessandra Faria Rodrigues - 828333"); 
          $display("Test module"); 
          $display("   x     y    a"); 
          
          // projetar testes do modulo 
          $monitor("%4b %4b %4b", x, y, a); 
            x = 1'b0;  y = 1'b0; 
   #1      x = 1'b0;  y = 1'b1; 
   #1      x = 1'b1;  y = 1'b0; 
   #1      x = 1'b1;  y = 1'b1; 
   end 
 
endmodule // test_f5
