// -------------------------
// Guia_0503.v - NOR GATES
// Nome: Andriel Mark da Silva Pinto
// Matricula: 859093
// -------------------------
module f6 (output s, input a, input b);
    wire not_a;
    wire or_ab;
    
    // Negar a usando NOR
    nor NOR1 (not_a, a, a);
    
    // Calcular ~a | b usando NOR
    nor NOR2 (or_ab, not_a, b);
    
    // Negar ~a | b usando NOR para obter a saída s
    nor NOR3 (s, or_ab, or_ab);
endmodule // f6

module test_f6;
    // ------------------------- definir dados
    reg x;
    reg y;
    wire s;
    
    f6 modulo (s, x, y);
    
    // ------------------------- parte principal
    initial begin : main
        $display("Guia_0503 - Andriel Mark da Silva Pinto - 859093");
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
