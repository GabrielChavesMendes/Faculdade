//Guia_0804.v

// -------------------------
// Guia_0804 - INEQUALITY COMPARATOR
// Alessandra Faria Rodrigues
// 828333
// -------------------------

// -------------------------
// Inequality Comparator (1 bit)
// -------------------------
module inequalityComparator1Bit (
    output neq, // Resultado da comparação: 1 se a != b
    input a, 
    input b
);
    // Implementação com portas lógicas
    xor XOR1 (neq, a, b); // neq = 1 se a != b
endmodule // inequalityComparator1Bit

// -------------------------
// Inequality Comparator (5 bits)
// -------------------------
module inequalityComparator5Bits (
    output neq,       // Resultado final: 1 se x != y
    input [4:0] x,    // Operando 1
    input [4:0] y     // Operando 2
);
    wire [4:0] neqBits; // Fios para comparar cada bit

    // Comparação bit a bit
    inequalityComparator1Bit IC0 (neqBits[0], x[0], y[0]);
    inequalityComparator1Bit IC1 (neqBits[1], x[1], y[1]);
    inequalityComparator1Bit IC2 (neqBits[2], x[2], y[2]);
    inequalityComparator1Bit IC3 (neqBits[3], x[3], y[3]);
    inequalityComparator1Bit IC4 (neqBits[4], x[4], y[4]);

    // Resultado final: pelo menos um bit deve ser diferente
    or OR1 (neq, neqBits[0], neqBits[1], neqBits[2], neqBits[3], neqBits[4]);
endmodule // inequalityComparator5Bits

// -------------------------
// Testbench
// -------------------------
module test_inequalityComparator5Bits;
// Definir variáveis de entrada e saída
    reg [4:0] x;
    reg [4:0] y;
    wire neq;

    // Instanciar o comparador
    inequalityComparator5Bits comparator (neq, x, y);

    // Testes
    initial begin
        $display("Guia_0804 - Alessandra Faria Rodrigues - 828333");
        $display("Testes para o Comparador de Desigualdade (5 bits)");
        $display("x      y      | neq");
        $monitor("%b %b | %b", x, y, neq);

        // Casos de teste
        x = 5'b00001; y = 5'b00001; #10; // Iguais: neq = 0
        x = 5'b11111; y = 5'b11110; #10; // Diferentes: neq = 1
        x = 5'b10000; y = 5'b01111; #10; // Diferentes: neq = 1
        x = 5'b00010; y = 5'b00001; #10; // Diferentes: neq = 1

        $finish;
    end
endmodule // test_inequalityComparator5Bits
