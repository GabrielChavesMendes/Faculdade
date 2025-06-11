// -------------------------
// Guia_0505.v - NOR GATES
// Nome: Andriel Mark da Silva Pinto
// Matricula: 859093
// -------------------------
module f6 (output s, input a, input b);
    wire not_a, not_b;
    wire a_and_not_b, not_a_and_b;
    wire xor_ab;
    
    // Negar a usando NOR
    nor NOR1 (not_a, a, a);
    
    // Negar b usando NOR
    nor NOR2 (not_b, b, b);
    
    // Calcular a & ~b usando NOR
    nor NOR3 (a_and_not_b, a, not_b);
    
    // Calcular ~a & b usando NOR
    nor NOR4 (not_a_and_b, not_a, b);
    
    // Calcular (a & ~b) | (~a & b) usando NOR
    nor NOR5 (xor_ab, a_and_not_b, not_a_and_b);
    
    // Negar (a & ~b) | (~a & b) usando NOR para obter a saída s
    nor NOR6 (s, xor_ab, xor_ab);
endmodule // f6

module test_f6;
    // ------------------------- definir dados
    reg x;
    reg y;
    wire s;
    
    f6 modulo (s, x, y);
    
    // ------------------------- parte principal
    initial begin : main
        $display("Guia_0505 - Andriel Mark da Silva Pinto - 859093");
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
