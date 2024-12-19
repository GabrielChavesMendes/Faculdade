/* 
Guia_0303.v 
999999 - Xxx Yyy Zzz 
*/ 
module Guia_0303; 
// define data 
reg signed [7:0] a = 8'b0001_0110 ; // binary 
reg signed [7:0] b = 8'b0011_0011 ; // binary 
reg signed [7:0] c = 8'b0100_0100 ; // binary 
reg signed [7:0] d = 8'b0101_1011 ; // binary                    
reg signed [7:0] e = 8'b0111_0011 ; // binary                     
// actions 
initial 
begin : main 
$display ( "Guia_0303 - Tests" ); 
d = ~a+1; 
e = ~(a-1);  
$display ( "a = %8b -> C1(a) = %8b -> C2(a) = %8b = %d = %d", a, ~a, d, d, e ); 

d = ~b+1; 
e = ~(b-1); 
$display ( "b = %7b -> C1(b) = %7b -> C2(b) = %7b = %d = %d", b, ~b, d, d, e ); 

d = ~c+1; 
e = ~(c-1); 
$display ( "c = %6b -> C1(c) = %6b -> C2(c) = %6b = %d = %d", c, ~c, d, d, e );

d = ~d+1; 
e = ~(d-1); 
$display ( "d = %8b -> C1(d) = %8b -> C2(d) = %8b = %d = %d", d, ~d, d, d, e );
 
d = ~e+1; 
e = ~(e-1); 
$display ( "e = %7b -> C1(e) = %7b -> C2(e) = %7b = %d = %d", e, ~e, d, d, e );
end // main    end // main 
endmodule // Guia_0303 

/*
Guia_0303 - Tests
a = 00010110 -> C1(a) = 11101001 -> C2(a) = 11101010 =  -22 =  -22
b = 00110011 -> C1(b) = 11001100 -> C2(b) = 11001101 =  -51 =  -51
c = 01000100 -> C1(c) = 10111011 -> C2(c) = 10111100 =  -68 =  -68
d = 01000100 -> C1(d) = 10111011 -> C2(d) = 01000100 =   68 =  -68
e = 01000100 -> C1(e) = 10111011 -> C2(e) = 01000100 =   68 =   68
*/