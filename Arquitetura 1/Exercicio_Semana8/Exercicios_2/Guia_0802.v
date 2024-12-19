// -------------------------
// Guia_0802 - Unidade Aritmética (AU) com Subtrator Completo
// Nome: [Seu Nome Aqui]
// Matrícula: [Sua Matrícula Aqui]
// -------------------------

// -------------------------
// half subtractor (meia-diferença)
// -------------------------
module halfSubtractor (output borrowOut,  // borrow out
                       output diff,      // diferença
                       input a,          // minuendo (bit a)
                       input b);         // subtraendo (bit b)
  xor XOR1 (diff, a, b);  // diferença
  and AND1 (temp_borrow, ~a, b);  // borrow temporário
  assign borrowOut = temp_borrow; // saída do borrow
endmodule // halfSubtractor


// -------------------------
// full subtractor (subtrator completo)
// -------------------------
module fullSubtractor (output borrowOut,  // borrow out
                       output diff,       // diferença
                       input a,           // minuendo (bit a)
                       input b,           // subtraendo (bit b)
                       input borrowIn);   // borrow in
  wire d1, b1, b2;

  halfSubtractor HS1 (b1, d1, a, b);         // primeira meia-diferença
  halfSubtractor HS2 (b2, diff, d1, borrowIn); // segunda meia-diferença
  or OR1 (borrowOut, b1, b2);                // saída do borrow out
endmodule // fullSubtractor


// -------------------------
// AU de 5 bits com subtrator completo
// -------------------------
module AU_5bits_sub (output [4:0] diff,    // resultado da diferença
                     output borrowOut,     // borrow final
                     input [4:0] a,        // minuendo (5 bits)
                     input [4:0] b);       // subtraendo (5 bits)
  wire [3:0] borrow;

  fullSubtractor FS0 (borrow[0], diff[0], a[0], b[0], 1'b0);   // bit menos significativo
  fullSubtractor FS1 (borrow[1], diff[1], a[1], b[1], borrow[0]); // segundo bit
  fullSubtractor FS2 (borrow[2], diff[2], a[2], b[2], borrow[1]); // terceiro bit
  fullSubtractor FS3 (borrow[3], diff[3], a[3], b[3], borrow[2]); // quarto bit
  fullSubtractor FS4 (borrowOut, diff[4], a[4], b[4], borrow[3]);  // bit mais significativo
endmodule // AU_5bits_sub

// -------------------------
// Teste para AU de 5 bits com subtrator completo
// -------------------------
module test_AU_5bits_sub;
  // ------------------------- definir dados
  reg [4:0] x;
  reg [4:0] y;
  wire [4:0] diff;
  wire borrowOut;

  AU_5bits_sub AU_sub (diff, borrowOut, x, y);


  // ------------------------- parte principal
  initial begin
    $display("Guia_0802");
    $display("Testes da AU com Subtrator Completo");
    $display("x      - y      = diff   BorrowOut");
    
    // Teste 1
    x = 5'b01101;  // 13
    y = 5'b01011;  // 11
    #1;
    $display("%b - %b = %b   %b", x, y, diff, borrowOut);
    
    // Teste 2
    x = 5'b10101;  // -11
    y = 5'b00111;  // 7
    #1;
    $display("%b - %b = %b   %b", x, y, diff, borrowOut);
    
    // Teste 3
    x = 5'b11101;  // -3
    y = 5'b10011;  // -13
    #1;
    $display("%b - %b = %b   %b", x, y, diff, borrowOut);
  end
endmodule // test_AU_5bits_sub

/*
Guia_0802
Testes da AU com Subtrator Completo
x      - y      = diff   BorrowOut
01101 - 01011 = 00010   0
10101 - 00111 = 01110   0
11101 - 10011 = 01010   0
*/
