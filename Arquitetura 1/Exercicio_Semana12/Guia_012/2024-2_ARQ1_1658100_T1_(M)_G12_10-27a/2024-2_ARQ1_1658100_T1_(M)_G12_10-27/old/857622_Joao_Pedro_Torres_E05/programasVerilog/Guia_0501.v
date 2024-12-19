// -------------------------
// Guia_0501.v - GATES
// Nome: Joao Pedro Torres
// Matricula: 857622
// -------------------------
// -------------------------
/*

Exercício 01 - f5c.

Projetar e descrever em Verilog, usando apenas portas nativas nor
um módulo equivalente à expressão (~a & b).
O nome do arquivo deverá ser Guia_0501.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos.

Exercício 02 - f5d.

Projetar e descrever em Verilog, usando apenas portas nativas nand
um módulo equivalente à expressão (a | ~b).
O nome do arquivo deverá ser Guia_0502.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos

Exercício 03 - f5e.

Projetar e descrever em Verilog, usando apenas portas nativas nor
módulo equivalente à expressão ~(~a | b).
O nome do arquivo deverá ser Guia_0503.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos

Exercício 04 - f5f.

Projetar e descrever em Verilog, usando apenas portas nativas nand
módulo equivalente à expressão ~(~a & b).
O nome do arquivo deverá ser Guia_0504.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular os módulos no Logisim e
apresentar layout dos circuitos e subcircuitos

Exercício 05 - f5g.

Projetar e descrever em Verilog, usando apenas portas nativas nor
um módulo equivalente à disjunção exclusiva (~(a ^ b) = a xnor b).
O nome do arquivo deverá ser Guia_0505.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos.

Exercício 06 - f5h.

Projetar e descrever em Verilog, usando apenas portas nativas nand
um módulo equivalente à negação da disjunção exclusiva (a ^ b = a xor b).
O nome do arquivo deverá ser Guia_0506.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos

Exercício 07 - f5i.

Projetar e descrever em Verilog, usando apenas portas nativas nor
um módulo equivalente à expressão ( ~a ^ ~b ).
O nome do arquivo deverá ser Guia_0507.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos.

Exercício 08 - f5j.

Projetar e descrever em Verilog, usando apenas portas nativas nand
um módulo equivalente à expressão ~( ~a | ~b ).
O nome do arquivo deverá ser Guia_ 0508.v,
e poderá seguir o modelo descrito anteriormente.
Incluir previsão de testes.
Simular o módulo no Logisim e
apresentar layout do circuito e subcircuitos.
*/
// -------------------------

//Funções Universalidade Porta NAND

module notNand ( output s,
 input a);
// descrever por portas
 nand notNand1 (s, a, a);
endmodule // notNand

module andNand ( output s,
 input a, input b);
// definir dado local
 wire nand_ab;
// descrever por portas
 nand nand1 (nand_ab, a, b);
 notNand moduloA ( s, nand_ab);
endmodule // andNand

module orNand ( output s,
 input a, input b);
// definir dado local
 wire notNand_a, notNand_b;
// descrever por portas
 notNand moduloA ( notNand_a, a);
 notNand moduloB ( notNand_b, b);
 nand orNand1 (s, notNand_a, notNand_b);
endmodule // orNand

module xorNand ( output s,
 input a, input b);
// definir dado local
 wire nand_ab, nand_aba, nand_abb;
// descrever por portas
 nand moduloA ( nand_ab, a, b);
 nand moduloB ( nand_aba, nand_ab, a);
 nand moduloC ( nand_abb, nand_ab, b);
 nand moduloD (s, nand_aba, nand_abb);
endmodule // xorNand


//Funções Universalidade Porta NOR

module notNor ( output s,
 input a);
// descrever por portas
 nor notNor1 (s, a, a);
endmodule // notNor

module orNor ( output s,
 input a, input b);
// definir dado local
 wire nor_ab;
// descrever por portas
 nor notNor1 (nor_ab, a, b);
 notNor moduloA ( s, nor_ab);
endmodule // orNor

module andNor ( output s,
 input a, input b);
// definir dado local
 wire notNor_a, notNor_b;
// descrever por portas
 notNor moduloA ( notNor_a, a);
 notNor moduloB ( notNor_b, b);
 nor andNor1 (s, notNor_a, notNor_b);
endmodule // andNor

module xorNor ( output s,
 input a, input b);
// definir dado local
 wire andNor_ab, nor_ab;
// descrever por portas
 andNor moduloA ( andNor_ab, a, b);
 nor nor1 (nor_ab, a, b);
 nor noe2 ( s, andNor_ab, nor_ab);
endmodule // xorNor

module f5a ( output s,
 input a,
 input b );
// definir dado local
 wire not_a;
// descrever por portas
 not NOT1 ( not_a, a );
 and AND1 ( s, not_a, b );
endmodule // f5a
// -------------------------
// f5_gate
// m a b s
// 0 0 0 0
// 1 0 1 1 <- a'.b
// 2 1 0 0
// 3 1 1 0
//
// -------------------------
module f5b ( output s,
 input a,
 input b );
// descrever por expressao
 assign s = ~a & b;
endmodule // f5b

module f5c ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1;
 notNor moduloA (s1, a);
 andNor moduloB (s, s1, b); 
endmodule // f5c

// -------------------------
// s = (~a & b)
// m a b ~a s
// 0 0 0  1 0
// 1 0 1  1 1 
// 2 1 0  0 0
// 3 1 1  0 0
//
// -------------------------

module f5d ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1;
 notNand moduloA (s1, b);
 orNand moduloB (s, a, s1); 
endmodule // f5d

// -------------------------
// s = (a | ~b)
// m a b ~b s
// 0 0 0  1 1
// 1 0 1  0 0 
// 2 1 0  1 1
// 3 1 1  0 1
//
// -------------------------

module f5e ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1, s2;
 notNand moduloA (s1, a);
 orNand moduloB (s2, s1, b); 
 notNand moduloC (s, s2);
endmodule // f5e

// -------------------------
// ~(~a | b)
// m a b ~a  ~a | b s
// 0 0 0  1     1   0
// 1 0 1  1     1   0 
// 2 1 0  0     0   1
// 3 1 1  0     1   0
//
// -------------------------

module f5f ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1, s2;
 notNand moduloA (s1, a);
 andNand moduloB (s2, s1, b); 
 notNand moduloC (s, s2);
endmodule // f5f

// -------------------------
//  ~(~a & b)
// m a b ~a   a & b s
// 0 0 0  1     0   1
// 1 0 1  1     1   0 
// 2 1 0  0     0   1
// 3 1 1  0     0   1
//
// -------------------------


module f5g ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1;
 xorNor moduloA (s1, a, b); 
 notNor moduloB (s, s1);
endmodule // f5g

// -------------------------
//  ~(a ^ b) 
// m a b a^b  s
// 0 0 0  0   1   
// 1 0 1  1   0    
// 2 1 0  1   0   
// 3 1 1  0   1   
//
// -------------------------


module f5h ( output s,
 input a,
 input b );
// descrever por expressao
 xorNand moduloA (s, a, b); 
endmodule // f5h

// -------------------------
//  a ^ b 
// m a b a^b 
// 0 0 0  0     
// 1 0 1  1      
// 2 1 0  1     
// 3 1 1  0     
//
// -------------------------

module f5i ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1, s2;
 notNor moduloA (s1, a);
 notNor moduloB (s2, b); 
 xorNor moduloC (s, s1, s2);
endmodule // f5i

// -------------------------
//  ( ~a ^ ~b )
// m a b ~a ~b s 
// 0 0 0  1  1 0  
// 1 0 1  1  0 1   
// 2 1 0  0  1 1  
// 3 1 1  0  0 0  
//
// -------------------------

module f5j ( output s,
 input a,
 input b );
// descrever por expressao
 wire s1, s2, s3;
 notNand moduloA (s1, a);
 notNand moduloB (s2, b); 
 orNor moduloC (s3, s1, s2);
 notNand moduloD (s, s3);
endmodule // f5j

// -------------------------
//  ~( ~a | ~b )
// m a b ~a ~b ~a|~b s 
// 0 0 0  1  1   1   0
// 1 0 1  1  0   1   0
// 2 1 0  0  1   1   0
// 3 1 1  0  0   0   1
//
// -------------------------


module test_f5;
// ------------------------- definir dados
 reg x;
 reg y;
 wire a, b, c, d, e, f, g, h, i, j;
 f5a moduloA ( a, x, y );
 f5b moduloB ( b, x, y );
 f5c moduloC ( c, x, y );
 f5d moduloD ( d, x, y );
 f5e moduloE ( e, x, y );
 f5f moduloF ( f, x, y );
 f5g moduloG ( g, x, y );
 f5h moduloH ( h, x, y );
 f5i moduloI ( i, x, y );
 f5j moduloJ ( j, x, y );
// ------------------------- parte principal
 initial
 begin : main
 $display("Guia_0500 - João Pedro Torres - 857622");
 $display("Test module");
 $display("   x    y    a    b    c    d    e    f    g    h    i    j");
 // projetar testes do modulo
 $monitor("%4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b %4b", x, y, a, b, c, d, e, f, g, h, i, j);
 // tabela verdade
    x = 1'b0; y = 1'b0;
 #1 x = 1'b0; y = 1'b1;
 #1 x = 1'b1; y = 1'b0; 
 #1 x = 1'b1; y = 1'b1;
 end
endmodule // test_f5