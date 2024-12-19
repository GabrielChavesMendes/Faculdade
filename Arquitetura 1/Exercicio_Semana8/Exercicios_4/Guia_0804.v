// -------------------------
// Guia_0804 - Unidade Lógica (LU) com Comparador de Desigualdade
// Nome: [Seu Nome Aqui]
// Matrícula: [Sua Matrícula Aqui]
// -------------------------

// -------------------------
// comparador de desigualdade de 1 bit
// -------------------------
module bitComparator (output result,   // resultado da comparação (desigualdade)
                      input a,         // primeiro bit de entrada
                      input b);        // segundo bit de entrada
  xor XOR1 (result, a, b);             // comparador de desigualdade usando XOR
endmodule // bitComparator


// -------------------------
// comparador de desigualdade de 5 bits
// -------------------------
module LU_5bits (output unequal,        // resultado final (1 se os dois são diferentes, 0 caso contrário)
                 input [4:0] a,         // primeiro operando de 5 bits
                 input [4:0] b);        // segundo operando de 5 bits
  wire [4:0] compare;  // armazena resultados da comparação de cada bit

  // Comparar bit a bit usando XOR
  bitComparator BC0 (compare[0], a[0], b[0]);
  bitComparator BC1 (compare[1], a[1], b[1]);
  bitComparator BC2 (compare[2], a[2], b[2]);
  bitComparator BC3 (compare[3], a[3], b[3]);
  bitComparator BC4 (compare[4], a[4], b[4]);

  // O resultado final será 1 se pelo menos um bit for diferente
  or OR1 (unequal, compare[0], compare[1], compare[2], compare[3], compare[4]);
endmodule // LU_5bits


// -------------------------
// Teste para comparador de desigualdade de 5 bits
// -------------------------
module test_LU_5bits;
  // ------------------------- definir dados
  reg [4:0] x;
  reg [4:0] y;
  wire unequal;

  LU_5bits LU (unequal, x, y);


  // ------------------------- parte principal
  initial begin
    $display("Guia_0804");
    $display("Testes do Comparador de Desigualdade de 5 bits");
    $display("x      y      = desigualdade");
    
    // Teste 1
    x = 5'b01101;  // 13
    y = 5'b01101;  // 13
    #1;
    $display("%b  %b  = %b", x, y, unequal);
    
    // Teste 2
    x = 5'b01101;  // 13
    y = 5'b01011;  // 11
    #1;
    $display("%b  %b  = %b", x, y, unequal);
    
    // Teste 3
    x = 5'b11101;  // -3
    y = 5'b11100;  // -4
    #1;
    $display("%b  %b  = %b", x, y, unequal);
    
    // Teste 4
    x = 5'b10101;  // -11
    y = 5'b00101;  // 5
    #1;
    $display("%b  %b  = %b", x, y, unequal);
  end
endmodule // test_LU_5bits

/*
Guia_0804
Testes do Comparador de Desigualdade de 5 bits
x      y      = desigualdade
01101  01101  = 0
01101  01011  = 1
11101  11100  = 1
10101  00101  = 1
*/