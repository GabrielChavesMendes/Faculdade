/* 
Guia_0203.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0203; 
// define data 
real    
  x   
= 0.625;                 
// decimal 
reg [7:0] b = 8'b1010_0000  ; // binary 
// actions 
initial 
begin : main 
$display ( "Guia_0203 - Tests" ); 
$display ( "x = %f" , x ); 
$display ( "b = 0.%8b", b ); 
$display ( "b = 0.%x%x (16)", b[7:4],b[3:0] ); 
$display ( "b = 0.%o%o%o (8) ", b[7:6],b[5:3],b[2:0] ); 
end // main 
endmodule // Guia_0203

/*
Guia_0203 - Tests
x = 0.625000
b = 0.10100000
b = 0.a0 (16)
b = 0.240 (8)
*/