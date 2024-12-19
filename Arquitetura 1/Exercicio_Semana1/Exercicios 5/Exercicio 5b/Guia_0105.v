/* 
  Guia_0105.v 
  999999 - Xxx Yyy Zzz 
*/ 
module Guia_0105; 
// define data 
   integer   x = 13; // decimal 
   reg [7:0] b; // binary 
   reg [0:4][7:0] s; // char array[5] (5x8 bits - little Endian) 
 
// actions 
   initial 
    begin : main 
     $display ( "Guia_0105 - Tests" ); 
     $display ( "x = %d"  , x ); 
     $display ( "b = %8b", b ); 
     
     s[0] = 8'h4D; // 'M' 
     s[1] = 8'h61; // 'a' 
     s[2] = 8'h6E; // 'n' 
     s[3] = 8'h68; // 'h' 
     s[4] = 8'h61; // 'a'
     
     $display ( "s = %s"  , s ); 
     b = x; 
     $display ( "b = [%4b] [%4b] = %h %h", b[7:4], b[3:0], b[7:4], b[3:0] ); 
    end // main 
 
endmodule // Guia_0105


/*
Guia_0105 - Tests
x =          13
b = xxxxxxxx
s = PUC-M.G.
b = [0000] [1101] = 0 d

Guia_0105 - Tests
x =          13
b = xxxxxxxx
s = 2024-02
b = [0000] [1101] = 0 d

Guia_0105 - Tests
x =          13
b = xxxxxxxx
s = Belo Horizonte
b = [0000] [1101] = 0 d

Guia_0105 - Tests
x =          13
b = xxxxxxxx
s = noite
b = [0000] [1101] = 0 d

Guia_0105 - Tests
x =          13
b = xxxxxxxx
s = Manha
b = [0000] [1101] = 0 d
*/