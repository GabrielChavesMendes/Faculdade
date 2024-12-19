/* 
Guia_0104.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0104; 
// define data 
integer   x = 45; // decimal 
reg [7:0] b = 101101;  // binary 
// actions 
initial 
begin : main 
$display ( "Guia_0104 - Tests" ); 
$display ( "x = %d"  , x ); 
$display ( "b = %8b", b ); 
b = x; 
$display ( "b = [%4b] [%4b] = %x %x", b[7:4], b[3:0], b[7:4], b[3:0] ); 
end // main 
endmodule // Guia_0104


/*
Guia_0104 - Tests
x =          20
b = 01110100
b = [0001] [0100] = 1 4

Guia_0104 - Tests
x =          26
b = 00000010
b = [0001] [1010] = 1 a

Guia_0104 - Tests
x =          39
b = 00001111
b = [0010] [0111] = 2 7

Guia_0104 - Tests
x =          37
b = 00000101
b = [0010] [0101] = 2 5

Guia_0104 - Tests
x =          45
b = 11101101
b = [0010] [1101] = 2 d
*/