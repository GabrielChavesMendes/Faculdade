/* 
Guia_0305.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0305; 
// define data 
reg [5:0] a = 6'b110101 ;      // 110101(2)
reg [3:0] b = 4'b1011 ;        // 1011(2)
reg [6:0] c = 7'b1011001 ;     // 1011001(2)
reg [8:0] d = 8'o31 ;          // 3,1(8)
reg [7:0] e = 8'h3D ;          // 3D(16)
reg [7:0] f = 8'hC5 ;          // C5(16)
reg [8:0] g = 8'b1011001 ;     // 1011001(2)
reg [7:0] h = 8'd126 ;         // 7E(10)
reg [7:0] i = 8'h2D ;          // 2D(16)
reg [5:0] result_a;
reg [6:0] result_b;
reg [7:0] result_c;
reg [7:0] result_d;
reg [7:0] result_e;

// actions 
initial 
begin : main 
  $display ( "Guia_0305 - Tests" ); 

  // a.) 110101(2) – 1011(2)
  result_a = a - b;                       
  $display("a = %6b - %4b = %6b = %d", a, b, result_a, result_a); 
  
  // b.) 1011001(2) - 3,1(8)
  result_b = c - d;                       
  $display("b = %7b - %4o = %7b = %d", c, d, result_b, result_b); 
  
  // c.) 213(4) - 3D(16)
  result_c = e - c;                       
  $display("c = %8b - %2h = %8b = %d", e, c, result_c, result_c); 
  
  // d.) C5(16) - 1011001(2)
  result_d = f - g;                       
  $display("d = %2h - %7b = %8b = %d", f, g, result_d, result_d); 
  
  // e.) 7E(10) - 2D(16)
  result_e = h - i;                       
  $display("e = %2d - %2h = %8b = %d", h, i, result_e, result_e); 
  
end // main 
endmodule // Guia_0305

/*
Guia_0305 - Tests
a = 110101 - 1011 = 101010 = 42
b = 1011001 -  031 = 1000000 =  64
c = 00111101 - 59 = 11100100 = 228
d = c5 - 001011001 = 01101100 = 108
e = 126 - 2d = 01010001 =  81
*/
