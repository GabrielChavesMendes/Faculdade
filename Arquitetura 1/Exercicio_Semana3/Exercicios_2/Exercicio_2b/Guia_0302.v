/* 
Guia_0302.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0302; 
// define data 
reg [6:0] a = 7'b111001 ; // binario(321(4)) 
reg [8:0] b = 9'hB2 ; // hexadecimal 
reg [6:0] c = 7'b101101; // binario(231(4))    
reg [7:0] d = 8'o146 ; // octal         
reg [8:0] e = 9'h6F ;  //hexadecimal     
reg [5:0] f  = 0  ;      
// actions 
initial 
begin : main 
// decimal 
; // binary 
; // binary 
; // binary 
$display ( "Guia_0302 - Tests" ); 
d = ~a+1; 
$display ( "a = %8b -> C1(a) = %8b -> C2(a) = %8b", a, ~a, d ); 
e = ~b+1; 
$display ( "b = %7b -> C1(b) = %7b -> C2(b) = %7b", b, ~b, e ); 
f = ~c+1; 
$display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b", c, ~c, f );
 
$display ( "d = %8b -> C1(d) = %8b -> C2(d) = %8b", d, d, ~d );

$display ( "e = %8b -> C1(e) = %8b -> C2(e) = %8b", e, e, ~e ); 
end // main 
endmodule // Guia_0302

/*
Guia_0302 - Tests
a =  0111001 -> C1(a) =  1000110 -> C2(a) = 11000111
b = 010110010 -> C1(b) = 101001101 -> C2(b) = 101001110
c = 0101101 -> C1(c) = 1010010 -> C2(c) = 010011
d = 11000111 -> C1(d) = 11000111 -> C2(d) = 00111000
e = 101001110 -> C1(e) = 101001110 -> C2(e) = 010110001
*/ 