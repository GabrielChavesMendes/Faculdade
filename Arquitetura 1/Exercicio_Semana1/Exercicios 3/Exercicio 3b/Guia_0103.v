/* 
Guia_0103.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0103; 
// define data 
integer   x = 753; // decimal 
reg [7:0] b =  0;  // binary 
// actions 
initial 
begin : main 
$display ( "Guia_0103 - Tests" ); 
$display ( "x = %d"  , x ); 
$display ( "b = %8b", b ); 
b = x; 
$display ( "b = %B (2) = %o (8) = %x (16) = %X (16)", b, b, b, b ); 
end // main 
endmodule // Guia_0103

/*
Guia_0103 - Tests
x =          61
b = 00000000
b = 00111101 (2) = 075 (8) = 3d (16) = 3d (16)

Guia_0103 - Tests
x =          53
b = 00000000
b = 00110101 (2) = 065 (8) = 35 (16) = 35 (16)

Guia_0103 - Tests
x =          77
b = 00000000
b = 01001101 (2) = 115 (8) = 4d (16) = 4d (16)

Guia_0103 - Tests
x =         153
b = 00000000
b = 10011001 (2) = 231 (8) = 99 (16) = 99 (16)

Guia_0103 - Tests
x =         753
b = 00000000
b = 11110001 (2) = 361 (8) = f1 (16) = f1 (16)
*/