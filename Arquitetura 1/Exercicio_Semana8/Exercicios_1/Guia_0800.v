// -------------------------
// Guia_0801 - Unidade Aritmética (AU) com Somador Completo
// Nome: [Seu Nome Aqui]
// Matrícula: [Sua Matrícula Aqui]
// -------------------------

// -------------------------
// half adder 
// -------------------------
module halfAdder (output s1,  
                  output s0,  
                  input a,    
                  input b);   
  xor XOR1 (s0, a, b);  
  and AND1 (s1, a, b);  
endmodule // halfAdder


// -------------------------
// full adder (somador completo)
// -------------------------
module fullAdder (output carryOut,  
                  output sum,       
                  input a,          
                  input b,          
                  input carryIn);   
  wire s1, s2, c1, c2;

  halfAdder HA1 (c1, s1, a, b);     
  halfAdder HA2 (c2, s2, s1, carryIn); 
  or OR1 (carryOut, c1, c2);        
  assign sum = s2;                  
endmodule // fullAdder

// -------------------------
// AU de 5 bits com somador completo
// -------------------------
module AU_5bits (output [4:0] soma,    
                 output carryOut,      
                 input [4:0] a,        
                 input [4:0] b);     
  wire [3:0] carry;

  fullAdder FA0 (carry[0], soma[0], a[0], b[0], 1'b0);   
  fullAdder FA1 (carry[1], soma[1], a[1], b[1], carry[0]); 
  fullAdder FA2 (carry[2], soma[2], a[2], b[2], carry[1]); 
  fullAdder FA3 (carry[3], soma[3], a[3], b[3], carry[2]); 
  fullAdder FA4 (carryOut, soma[4], a[4], b[4], carry[3]); 
endmodule // AU_5bits


// -------------------------

// -------------------------
module test_AU_5bits;
  // ------------------------- definir dados
  reg [4:0] x;
  reg [4:0] y;
  wire [4:0] soma;
  wire carryOut;

  AU_5bits AU (soma, carryOut, x, y);

  // ------------------------- parte principal
  initial begin
    $display("Guia_0801 - [Seu Nome Aqui] - [Sua Matrícula Aqui]");
    $display("Testes da AU com Somador Completo");
    $display("x      + y      = soma   CarryOut");
    
    // Teste 1
    x = 5'b01101;  // 13
    y = 5'b01011;  // 11
    #1;
    $display("%b + %b = %b   %b", x, y, soma, carryOut);
    
    // Teste 2
    x = 5'b10101;  // -11
    y = 5'b00111;  // 7
    #1;
    $display("%b + %b = %b   %b", x, y, soma, carryOut);
    
    // Teste 3
    x = 5'b11101;  // -3
    y = 5'b10011;  // -13
    #1;
    $display("%b + %b = %b   %b", x, y, soma, carryOut);
  end
endmodule // test_AU_5bits

/*
Guia_0801 
Testes da AU com Somador Completo
x      + y      = soma   CarryOut
01101 + 01011 = 11000   0
10101 + 00111 = 11100   0
11101 + 10011 = 10000   1
*/
