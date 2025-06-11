// -------------------------
// Guia_0506.v - NAND GATES
// Nome: Andriel Mark da Silva Pinto
// Matricula: 859093
// -------------------------
module f6 (output s, input a, input b);
    wire not_a, not_b;
    wire a_and_not_b, not_a_and_b;
    wire xor_ab;
    
    // Negar a usando NAND
    nand NAND1 (not_a, a, a);
    
    // Negar b usando NAND
    nand NAND2 (not_b, b, b);
    
    // Calcular a & ~b usando NAND
    nand NAND3 (a_and_not_b, a, not_b);
    
    // Calcular ~a & b usando NAND
    nand NAND4 (not_a_and_b, not_a, b);
    
    // Calcular (a & ~b) | (~a & b) usando NAND
    nand NAND5 (xor_ab, a_and_not_b, not_a_and_b);
    
    // Negar (a & ~b) | (~a & b) usando NAND para obter a saída s
    nand NAND6 (s, xor_ab, xor_ab);
endmodule // f6

module test_f6;
    // ------------------------- definir dados
    reg x;
    reg y;
    wire s;
    
    f6 modulo (s, x, y);
    
    // ------------------------- parte principal
    initial begin : main
        $display("Guia_0506 - Andriel Mark da Silva Pinto - 859093");
        $display("Test module");
        $display(" x y s");
        // Projetar testes do modulo
        $monitor("%4b %4b %4b", x, y, s);
        x = 1'b0; y = 1'b0;
        #1 x = 1'b0; y = 1'b1;
        #1 x = 1'b1; y = 1'b0;
        #1 x = 1'b1; y = 1'b1;
    end
endmodule // test_f6
