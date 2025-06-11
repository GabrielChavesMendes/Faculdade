// -------------------------
// Guia_0502.v - GATES
// Nome: Andriel Mark da Silva Pinto
// Matricula: 859093
// -------------------------
module f6a (output s, input a, input b);
    wire not_b;
    wire nand_ab;

    // obter ~b usando NAND
    nand NAND1 (not_b, b, b);
    
    // obter a | ~b usando NAND (equivalente a ~ (a & ~b))
    nand NAND2 (nand_ab, a, not_b);
    nand NAND3 (s, nand_ab, nand_ab);
endmodule // f6a

module f6b (output s, input a, input b);
    // descrever diretamente usando expressão com NAND
    assign s = ~(~(a & ~b) & ~(a & ~b));
endmodule // f6b

module test_f6;
    // ------------------------- definir dados
    reg x;
    reg y;
    wire a, b;
    
    f6a moduloA (a, x, y);
    f6b moduloB (b, x, y);
    
    // ------------------------- parte principal
    initial begin : main
        $display("Guia_0502 - Andriel Mark da Silva Pinto - 859093");
        $display("Test module");
        $display(" x y a b");
        // projetar testes do modulo
        $monitor("%4b %4b %4b %4b", x, y, a, b);
        x = 1'b0; y = 1'b0;
        #1 x = 1'b0; y = 1'b1;
        #1 x = 1'b1; y = 1'b0;
        #1 x = 1'b1; y = 1'b1;
    end
endmodule // test_f6
