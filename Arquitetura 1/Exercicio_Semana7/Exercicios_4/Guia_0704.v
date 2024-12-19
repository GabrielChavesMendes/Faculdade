// ------------------------- 
// Guia_0704 - GATES 
// Nome: xxx yyy zzz 
// Matricula: 999999 
// ------------------------- 
 
// ------------------------- 
//  f7_gate 
// ------------------------- 
module f7 ( output s_xor,     // saída para XOR
            output s_xnor,    // saída para XNOR
            input  a, 
            input  b ); 
 
// descrever por portas nativas 
   xor XOR1 (s_xor, a, b);    // Operação XOR
   xnor XNOR1 (s_xnor, a, b); // Operação XNOR
 
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
   and AND2 ( sb, b, select ); 
   or  OR1  ( s , sa, sb ); 

endmodule // mux 
 
 
// ------------------------- 
// Teste da f7 com XOR e XNOR
// ------------------------- 
module test_f7; 
// ------------------------- definir dados 
   reg  x; 
   reg  y; 
   reg  s; 
   wire w_xor;    // saída XOR
   wire w_xnor;   // saída XNOR
   wire z; 
 
   f7 modulo ( w_xor, w_xnor, x, y ); 
   mux MUX1  ( z, w_xor, w_xnor, s ); 
 
// ------------------------- parte principal 
   initial 
   begin : main 
      $display("Guia_0704 - xxx yyy zzz - 999999"); 
      $display("Test LU's module"); 
      $display("   x     y    s    z   w_xor   w_xnor"); 
          
      // Teste inicial
      x = 1'b0;  y = 1'b1;  s = 1'b0; 
 
      // projetar testes do módulo 
      #1 $monitor("%4b %4b %4b %4b %6b %7b", x, y, s, z, w_xor, w_xnor); 
       
      // Alterar entradas para testar diferentes casos
      #1 x = 1'b0; y = 1'b1; s = 1'b0;  // XOR
      #1 x = 1'b1; y = 1'b0; s = 1'b1;  // XNOR
      #1 x = 1'b1; y = 1'b1; s = 1'b1;  // XNOR
      
   end 
 
endmodule // test_f7

/*
Guia_0704 - xxx yyy zzz - 999999
Test LU's module
   x     y    s    z   w_xor   w_xnor
   0    1    0    1      1       0
   1    0    1    0      1       0
   1    1    1    1      0       1
*/