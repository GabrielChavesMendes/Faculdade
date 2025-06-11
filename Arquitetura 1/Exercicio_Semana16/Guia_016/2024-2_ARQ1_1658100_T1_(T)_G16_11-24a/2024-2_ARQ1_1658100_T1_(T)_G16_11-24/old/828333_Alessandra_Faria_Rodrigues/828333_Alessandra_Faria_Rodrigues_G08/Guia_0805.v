//Guia_0805.v

// -------------------------
// Guia_0805 - 2'S COMPLEMENT
// Alessandra Faria Rodrigues
// 828333
// -------------------------

// -------------------------
// Complemento de 1 (bit)
// -------------------------
module complemento1Bit (
    output c1, // Complemento de 1 do bit
    input a    // Bit original
);
    not NOT1 (c1, a); // Complemento de 1 é o inverso do bit
endmodule // complemento1Bit

// -------------------------
// Complemento de 1 (6 bits)
// -------------------------
module complemento1 (
    output [5:0] c1, // Complemento de 1 do número
    input [5:0] x    // Número original
);
    // Calcula complemento de 1 para cada bit
    complemento1Bit C1_0 (c1[0], x[0]);
    complemento1Bit C1_1 (c1[1], x[1]);
    complemento1Bit C1_2 (c1[2], x[2]);
    complemento1Bit C1_3 (c1[3], x[3]);
    complemento1Bit C1_4 (c1[4], x[4]);
    complemento1Bit C1_5 (c1[5], x[5]);
endmodule // complemento1

// -------------------------
// Somador Completo (1 bit)
// -------------------------
module somadorCompleto (
    output soma,    // Soma
    output carryOut, // Vai-um
    input a, 
    input b, 
    input carryIn
);
    wire s1, c1, c2;

    // Implementação usando meia-soma
    xor XOR1 (s1, a, b);
    xor XOR2 (soma, s1, carryIn);
    and AND1 (c1, a, b);
    and AND2 (c2, s1, carryIn);
    or OR1 (carryOut, c1, c2);
endmodule // somadorCompleto

// -------------------------
// Complemento de 2 (6 bits)
// -------------------------
module complemento2 (
    output [5:0] c2,  // Complemento de 2 do número
    input [5:0] x     // Número original
);
    wire [5:0] c1;    // Complemento de 1
    wire [5:0] carry; // Vai-um entre os bits

    // Calcula complemento de 1
    complemento1 comp1 (c1, x);

    // Adiciona 1 ao complemento de 1
    somadorCompleto SC0 (c2[0], carry[0], c1[0], 1'b1, 1'b0); // Adiciona 1 ao bit menos significativo
    somadorCompleto SC1 (c2[1], carry[1], c1[1], 1'b0, carry[0]);
    somadorCompleto SC2 (c2[2], carry[2], c1[2], 1'b0, carry[1]);
    somadorCompleto SC3 (c2[3], carry[3], c1[3], 1'b0, carry[2]);
    somadorCompleto SC4 (c2[4], carry[4], c1[4], 1'b0, carry[3]);
    somadorCompleto SC5 (c2[5], carry[5], c1[5], 1'b0, carry[4]);
endmodule // complemento2

// -------------------------
// Testbench
// -------------------------
module test_complemento2;
// Definir variáveis de entrada e saída
    reg [5:0] x;
    wire [5:0] c2;

    // Instanciar o módulo de complemento de 2
    complemento2 comp2 (c2, x);

    // Testes
    initial begin
        $display("Guia_0805 - Alessandra Faria Rodrigues - 828333");
        $display("Testes para o Complemento de 2 (6 bits)");
        $display("x       | c2");
        $monitor("%b | %b", x, c2);

        // Casos de teste
        x = 6'b000001; #10; // Complemento de 2 de 1
        x = 6'b000010; #10; // Complemento de 2 de 2
        x = 6'b111111; #10; // Complemento de 2 de -1
        x = 6'b100000; #10; // Complemento de 2 do menor valor negativo

        $finish;
    end
endmodule // test_complemento2
