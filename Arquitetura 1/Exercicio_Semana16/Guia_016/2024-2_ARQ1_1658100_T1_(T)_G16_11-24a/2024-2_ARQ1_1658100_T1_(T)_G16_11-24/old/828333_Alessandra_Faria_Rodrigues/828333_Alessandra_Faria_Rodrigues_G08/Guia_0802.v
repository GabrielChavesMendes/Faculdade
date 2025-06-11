//Guia_0802.v

// -------------------------
// Guia_0802 - FULL SUBTRACTOR
// Alessandra Faria Rodrigues
// 828333
// -------------------------

// -------------------------
// half subtractor
// -------------------------
module halfSubtractor (
    output borrowOut, // Saída do "empresta"
    output diff,      // Diferença
    input a, 
    input b
);
    // Implementação com portas nativas
    xor XOR1 (diff, a, b);          // Diferença parcial
    and AND1 (w1, ~a, b);           // Empresta se b > a
    assign borrowOut = w1;          // Empresta final
endmodule // halfSubtractor

// -------------------------
// full subtractor
// -------------------------
module fullSubtractor (
    output borrowOut, // Empresta final
    output diff,      // Diferença
    input a, 
    input b, 
    input borrowIn    // Empresta de entrada
);
    wire d0, b0, b1;

    // Meia diferença 1
    halfSubtractor HS1 (b0, d0, a, b);
    // Meia diferença 2
    halfSubtractor HS2 (b1, diff, d0, borrowIn);
    // Borrow final
    or OR1 (borrowOut, b0, b1);
endmodule // fullSubtractor

// -------------------------
// 5-bit Arithmetic Unit (Subtraction)
// -------------------------
module arithmeticUnit (
    output [4:0] result,  // Resultado final
    output borrowOut,     // Empresta final
    input [4:0] x,        // Operando 1
    input [4:0] y,        // Operando 2
    input borrowIn        // Empresta inicial
);
    wire [4:0] borrow; // Fios intermediários para "empresta"

    // Full Subtractors em cascata
    fullSubtractor FS0 (borrow[0], result[0], x[0], y[0], borrowIn);
    fullSubtractor FS1 (borrow[1], result[1], x[1], y[1], borrow[0]);
    fullSubtractor FS2 (borrow[2], result[2], x[2], y[2], borrow[1]);
    fullSubtractor FS3 (borrow[3], result[3], x[3], y[3], borrow[2]);
    fullSubtractor FS4 (borrowOut, result[4], x[4], y[4], borrow[3]);
endmodule // arithmeticUnit

// -------------------------
// Testbench
// -------------------------
module test_arithmeticUnit;
// Definir variáveis de entrada e saída
    reg [4:0] x;
    reg [4:0] y;
    reg borrowIn;
    wire [4:0] result;
    wire borrowOut;

    // Instanciar a AU
    arithmeticUnit AU (result, borrowOut, x, y, borrowIn);

    // Testes
    initial begin
        $display("Guia_0802 - Alessandra Faria Rodrigues - 828333");
        $display("Testes para a Unidade Aritmética (AU) - Subtração");
        $display("x      y      borrowIn | result  borrowOut");
        $monitor("%b %b   %b       | %b   %b", x, y, borrowIn, result, borrowOut);

        // Casos de teste
        x = 5'b00010; y = 5'b00001; borrowIn = 0; #10; // 2 - 1
        x = 5'b00001; y = 5'b00010; borrowIn = 0; #10; // 1 - 2
        x = 5'b11111; y = 5'b00001; borrowIn = 0; #10; // -1 - 1
        x = 5'b10000; y = 5'b01111; borrowIn = 1; #10; // -16 - 15 com borrowIn

        $finish;
    end
endmodule // test_arithmeticUnit
