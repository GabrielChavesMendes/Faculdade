// -------------------------
// Guia_0508.v - NAND GATES
// Nome: Andriel Mark da Silva Pinto
// Matricula: 859093
// -------------------------
module f6 (output s, input a, input b);
    wire nand_ab;
    
    // Calcular a & b usando NAND
    nand NAND1 (nand_ab, a, b);
    nand NAND2 (s, nand_ab, nand_ab); // Negar o resultado de NAND1 para obter a AND
endmodule // f6

module test_f6;
    // ------------------------- definir dados
    reg x;
    reg y;
    wire s;
    
    f6 modulo (s, x, y);
    
    // ------------------------- parte principal
    initial begin : main
        $display("Guia_0508 - Andriel Mark da Silva Pinto - 859093");
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
