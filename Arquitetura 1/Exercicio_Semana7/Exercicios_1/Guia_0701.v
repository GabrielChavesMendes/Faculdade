// ------------------------- 
// Guia_0701 - GATES 
// Nome: xxx yyy zzz 
// Matricula: 999999 
// ------------------------- 
 
// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7 ( output s_and,
		   output s_nand, 
                   input  a, 
                   input  b ); 
 
// descrever por portas 

and AND1 (s_and, a, b);   // Operação AND
   nand NAND1 (s_nand, a, b); // Operação NAND
 
endmodule // f7 
 
 
// ------------------------- 
//  multiplexer 
// ------------------------- 
module mux ( output s, 
                       input  a, 
                       input  b, 
                       input  select ); 
 
// definir dados locais 
   wire not_select; 
   wire sa; 
   wire sb; 
 
// descrever por portas 
   not NOT1 ( not_select, select ); 
 
   and AND1 ( sa, a, not_select ); 
   and AND2 ( sb, b,    select     ); 
 
   or  OR1     ( s , sa, sb ); 
endmodule // mux 
 
 
module test_f7; 
// ------------------------- definir dados 
       reg  x; 
       reg  y; 
       reg  s; 
       wire w_and;
       wire w_nand; 
       wire z; 
 
       f7 modulo   ( w_and, w_nand, x, y ); 
 
       mux MUX1 ( z, w_and, w_nand, s ); 
 
 
 
 
// ------------------------- parte principal 
 
   initial 
   begin : main 
          $display("Guia_0700 - xxx yyy zzz - 999999"); 
          $display("Test LU's module"); 
          $display("   x     y    s    z   w_and   w_nand"); 
 
           x = 1'b0;  y = 1'b1;  s = 1'b0; 
 
       // projetar testes do modulo 
   #1    $monitor("%4b %4b %4b %4b %6b %7b", x, y, s, z, w_and, w_nand); 
       
       // Alterar entradas para testar diferentes casos
       #1     x = 1'b0; y = 1'b1; s = 1'b0; 
       #1     x = 1'b1; y = 1'b0; s = 1'b1; 
       #1     x = 1'b1; y = 1'b1; s = 1'b1;  
 
   end 
 
endmodule // test_f7


/*
Guia_0700 - xxx yyy zzz - 999999
Test LU's module
   x     y    s    z   w_and   w_nand
   0    1    0    0      0       1
   1    0    1    1      0       1
   1    1    1    0      1       0
*/