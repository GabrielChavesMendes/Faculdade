 -------------------------
 Guia_0507.v - NOR GATES
 Nome Andriel Mark da Silva Pinto
 Matricula 859093
 -------------------------
module f6 (output s, input a, input b);
    wire not_a, not_b;
    wire not_a_and_b, a_and_not_b;
    wire xor_ab;
    
     Negar a usando NOR
    nor NOR1 (not_a, a, a);
    
     Negar b usando NOR
    nor NOR2 (not_b, b, b);
    
     Calcular ~a & b usando NOR
    nor NOR3 (not_a_and_b, not_a, b);
    
     Calcular a & ~b usando NOR
    nor NOR4 (a_and_not_b, a, not_b);
    
     Calcular (~a & b)  (a & ~b) usando NOR
    nor NOR5 (xor_ab, not_a_and_b, a_and_not_b);
    
     Negar (~a & b)  (a & ~b) para obter a saída s usando NOR
    nor NOR6 (s, xor_ab, xor_ab);
endmodule  f6

module test_f6;
     ------------------------- definir dados
    reg x;
    reg y;
    wire s;
    
    f6 modulo (s, x, y);
