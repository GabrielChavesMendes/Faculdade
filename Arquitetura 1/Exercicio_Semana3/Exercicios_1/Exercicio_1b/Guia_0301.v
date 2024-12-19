/* 
Guia_0301.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0301; 
// define data 
reg [7:0] a = 8'b000_1010 ; // binary
reg [7:0] b = 8'b000_1101 ; // binary
reg [7:0] c = 8'b001_0101 ; // binary
reg [7:0] d = 8'b001_1111 ; // binary
reg [7:0] e = 8'b011_0100 ; // binary         
reg [5:0] f  = 0          ; // binary           
// actions 
initial 
begin : main  
$display ( "Guia_0301 - Tests" ); 
d = ~a+1; 
$display ( "a = %8b -> C1(a) = %6b -> C2(a) = %6b", a, ~a, d ); 
e = ~b+1; 
$display ( "b = %7b -> C1(b) = %8b -> C2(b) = %8b", b, ~b, e ); 
f = ~c+1; 
$display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, f ); 
d = ~d + 1; 
$display ( "d = %7b -> C1(d) = %7b -> C2(d) = %7b", d, d, ~d );
e = ~e + 1; 
$display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, e, ~e ); 
end // main 
endmodule // Guia_0301

/*
a = 00001010 -> C1(a) = 11110101 -> C2(a) = 11110110
b = 00001101 -> C1(b) = 11110010 -> C2(b) = 11110011
c = 00010101 -> C1(c) = 11101010 -> C2(c) = 101011
d = 00001010 -> C1(d) = 00001010 -> C2(d) = 11110101
e = 00001101 -> C1(e) = 00001101 -> C2(e) = 11110010
*/