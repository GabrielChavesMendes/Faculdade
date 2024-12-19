/* 
  Guia_0304.v 
  999999 - Xxx Yyy Zzz 
*/ 
module Guia_0304; 
// define data 
   reg signed [5:0] a = 6'b11010;  // binary for 312(4)
   reg signed [5:0] b = 6'b10011;  // binary for 231(4)
   reg signed [7:0] c = 0;         // binary to store result for 312(4) - 231(4)
   reg signed [4:0] d = 5'b11001;  // binary (11001(2))
   reg signed [3:0] e = 4'b1101;   // binary (1101(2))
   reg signed [7:0] f = 8'b101_1101; // binary (101,1101(2))
   reg signed [3:0] g = 4'b1001;   // binary (10,01(2))
   reg signed [7:0] h = 8'o376;    // octal (376(8))
   reg signed [7:0] i = 8'o267;    // octal (267(8))
   reg signed [11:0] j = 12'h7D2;  // hexadecimal (7D2(16))
   reg signed [11:0] k = 12'hA51;  // hexadecimal (A51(16))
   reg signed [7:0] l = 0;         // binary 
   reg signed [4:0] m = 0;         // binary
   reg signed [7:0] n = 0;         // binary
   reg signed [11:0] o = 0;        // hexadecimal
   
// actions 
   initial 
    begin : main 
     $display ( "Guia_0304 - Tests" ); 
     
     m = d - e;
     $display ( "a = %8b = %d = %8b = %d = %8b = %d", d, d, e, e, m, m ); 
     
     n = f - {g, 4'b0000};   
     $display ( "b = %8b = %d = %8b = %d = %8b = %d", f, f, g, g, n, n ); 
     
     c = a - b;
     $display ( "c = %8b - %8b  = %8b", a, b, c ); 

     l = h - i;
     $display ( "d = %3o = %d = %3o = %d = %3o = %d", h, h, i, i, l, l ); 
     
     o = j - k;
     $display ( "e = %3h = %d = %3h = %d = %3h = %d", j, j, k, k, o, o ); 
    end // main 
endmodule // Guia_0304

/*
a =    11001 =  -7 =     1101 = -3 =    11100 =  -4
b = 01011101 =   93 =     1001 = -7 = 11001101 =  -51
c =   011010 -   010011  = 00000111
d = 376 =   -2 = 267 =  -73 = 107 =   71
e = 7d2 =  2002 = a51 = -1455 = d81 =  -639
*/
