/* 
Guia_0101.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0101; 
// define data 
integer   x = 365; // decimal 
reg [7:0] b =  0;  // binary   (bits - little endian) 
// actions 
initial 
begin : main 
$display ( "Guia_0101 - Tests" ); 
$display ( "x = %d"  , x ); 
$display ( "b = %8b", b ); 
b = x; 
$display ( "b = %8b", b ); 
end // main 
endmodule // Guia_0101

/*
Guia_0101 - Tests
x =          26
b = 00000000
b = 00011010

Guia_0101 - Tests
x =          53
b = 00000000
b = 00110101

Guia_0101 - Tests
x =         713
b = 00000000
b = 11001001

Guia_0101 - Tests
x =         213
b = 00000000
b = 11010101

Guia_0101 - Tests
x =         365
b = 00000000
b = 01101101
*/