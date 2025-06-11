//Guia_0801.v

// -------------------------
// Guia_0801 - FULL ADDER
// Alessandra Faria Rodrigues
// 828333
// -------------------------

// -------------------------
// half adder
// -------------------------
module halfAdder (
    output s1,   // carry out
    output s0,   // sum
    input a, 
    input b
);
    // Implementação com portas nativas
    xor XOR1 (s0, a, b); // soma parcial
    and AND1 (s1, a, b); // carry
endmodule // halfAdder

// -------------------------
// full adder
// -------------------------
module fullAdder (
    output carryOut, // carry final
    output sum,      // soma
    input a, 
    input b, 
    input carryIn    // carry de entrada
);
    wire s0, c0, c1;

    // Meia soma 1
    halfAdder HA1 (c0, s0, a, b);
    // Meia soma 2
    halfAdder HA2 (c1, sum, s0, carryIn);
    // Carry final
    or OR1 (carryOut, c0, c1);
endmodule // fullAdder

// -------------------------
// 5-bit Arithmetic Unit
// -------------------------
module arithmeticUnit (
    output [4:0] result,  // Resultado final
    output carryOut,      // Carry final
    input [4:0] x,        // Operando 1
    input [4:0] y,        // Operando 2
    input carryIn         // Carry inicial
);
    wire [4:0] carry; // Fios intermediários para "vai-um"

    // Full Adders em cascata
    fullAdder FA0 (carry[0], result[0], x[0], y[0], carryIn);
    fullAdder FA1 (carry[1], result[1], x[1], y[1], carry[0]);
    fullAdder FA2 (carry[2], result[2], x[2], y[2], carry[1]);
    fullAdder FA3 (carry[3], result[3], x[3], y[3], carry[2]);
    fullAdder FA4 (carryOut, result[4], x[4], y[4], carry[3]);
endmodule // arithmeticUnit

// -------------------------
// Testbench
// -------------------------
module test_arithmeticUnit;
// Definir variáveis de entrada e saída
    reg [4:0] x;
    reg [4:0] y;
    reg carryIn;
    wire [4:0] result;
    wire carryOut;

    // Instanciar a AU
    arithmeticUnit AU (result, carryOut, x, y, carryIn);

    // Testes
    initial begin
        $display("Guia_0801 - Alessandra Faria Rodrigues - 828333");
        $display("Testes para a Unidade Aritmética (AU)");
        $display("x      y      carryIn | result  carryOut");
        $monitor("%b %b   %b       | %b   %b", x, y, carryIn, result, carryOut);

        // Casos de teste
        x = 5'b00001; y = 5'b00010; carryIn = 0; #10; // 1 + 2
        x = 5'b11111; y = 5'b00001; carryIn = 0; #10; // -1 + 1
        x = 5'b10000; y = 5'b00001; carryIn = 0; #10; // -16 + 1
        x = 5'b01111; y = 5'b00001; carryIn = 1; #10; // 15 + 1 com carryIn

        $finish;
    end
endmodule // test_arithmeticUnit
