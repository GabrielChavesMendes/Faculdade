//Guia_0803.v

// -------------------------
// Guia_0803 - COMPARATOR
// Alessandra Faria Rodrigues
// 828333
// -------------------------

// -------------------------
// Equality Comparator (1 bit)
// -------------------------
module equalityComparator1Bit (
    output eq, // Resultado da comparação: 1 se a == b
    input a, 
    input b
);
    // Implementação com portas lógicas
    xnor XNOR1 (eq, a, b); // eq = 1 se a == b
endmodule // equalityComparator1Bit

// -------------------------
// Equality Comparator (5 bits)
// -------------------------
module equalityComparator5Bits (
    output eq,       // Resultado final: 1 se x == y
    input [4:0] x,   // Operando 1
    input [4:0] y    // Operando 2
);
    wire [4:0] eqBits; // Fios para comparar cada bit

    // Comparação bit a bit
    equalityComparator1Bit EC0 (eqBits[0], x[0], y[0]);
    equalityComparator1Bit EC1 (eqBits[1], x[1], y[1]);
    equalityComparator1Bit EC2 (eqBits[2], x[2], y[2]);
    equalityComparator1Bit EC3 (eqBits[3], x[3], y[3]);
    equalityComparator1Bit EC4 (eqBits[4], x[4], y[4]);

    // Resultado final: todos os bits devem ser iguais
    and AND1 (eq, eqBits[0], eqBits[1], eqBits[2], eqBits[3], eqBits[4]);
endmodule // equalityComparator5Bits

// -------------------------
// Testbench
// -------------------------
module test_equalityComparator5Bits;
// Definir variáveis de entrada e saída
    reg [4:0] x;
    reg [4:0] y;
    wire eq;

    // Instanciar o comparador
    equalityComparator5Bits comparator (eq, x, y);

    // Testes
    initial begin
        $display("Guia_0803 - Alessandra Faria Rodrigues - 828333");
        $display("Testes para o Comparador de Igualdade (5 bits)");
        $display("x      y      | eq");
        $monitor("%b %b | %b", x, y, eq);

        // Casos de teste
        x = 5'b00001; y = 5'b00001; #10; // Iguais: eq = 1
        x = 5'b11111; y = 5'b11111; #10; // Iguais: eq = 1
        x = 5'b10000; y = 5'b01111; #10; // Diferentes: eq = 0
        x = 5'b00010; y = 5'b00001; #10; // Diferentes: eq = 0

        $finish;
    end
endmodule // test_equalityComparator5Bits
