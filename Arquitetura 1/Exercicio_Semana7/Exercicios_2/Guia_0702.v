// ------------------------- 
// Guia_0702 - GATES 
// Nome: xxx yyy zzz 
// Matricula: 999999 
// ------------------------- 
 
// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7 ( output s_or,     // saída para OR
                   output s_nor,    // saída para NOR
                   input  a, 
                   input  b ); 
 
// descrever por portas 
   or  OR1  (s_or, a, b);    // Operação OR
   nor NOR1 (s_nor, a, b);   // Operação NOR
 
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
       wire w_or;    // saída OR
       wire w_nor;   // saída NOR
       wire z; 
 
       f7 modulo   ( w_or, w_nor, x, y ); 
 
       mux MUX1 ( z, w_or, w_nor, s ); 
 
 
// ------------------------- parte principal 
 
   initial 
   begin : main 
          $display("Guia_0702 - xxx yyy zzz - 999999"); 
          $display("Test LU's module"); 
          $display("   x     y    s    z   w_or   w_nor"); 
          
          // Testes iniciais
          x = 1'b0;  y = 1'b1;  s = 1'b0; 
 
       // projetar testes do modulo 
       #1    $monitor("%4b %4b %4b %4b %6b %7b", x, y, s, z, w_or, w_nor); 
       
       // Alterar entradas para testar diferentes casos
       #1     x = 1'b0; y = 1'b1; s = 1'b0; 
       #1     x = 1'b1; y = 1'b0; s = 1'b1; 
       #1     x = 1'b1; y = 1'b1; s = 1'b1; 
 
   end 
 
endmodule // test_f7

/*
Guia_0702 - xxx yyy zzz - 999999
Test LU's module
   x     y    s    z   w_or   w_nor
   0    1    0    1      1       0
   1    0    1    0      1       0
   1    1    1    0      1       0
*/