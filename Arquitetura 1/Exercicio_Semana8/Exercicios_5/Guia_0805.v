// -------------------------
// Guia_0805 - Unidade Lógica (LU) para Complemento de 2
// Nome: [Seu Nome Aqui]
// Matrícula: [Sua Matrícula Aqui]
// -------------------------

// -------------------------
// complemento de 1 de 6 bits
// -------------------------
module complement1_6bits (output [5:0] comp1,   // saída: complemento de 1
                          input [5:0] a);      // entrada: valor de 6 bits
  // Inverter todos os bits para obter o complemento de 1
  not NOT0 (comp1[0], a[0]);
  not NOT1 (comp1[1], a[1]);
  not NOT2 (comp1[2], a[2]);
  not NOT3 (comp1[3], a[3]);
  not NOT4 (comp1[4], a[4]);
  not NOT5 (comp1[5], a[5]);
endmodule // complement1_6bits


// -------------------------
// somador completo de 1 bit
// -------------------------
module fullAdder (output carryOut,  
                  output sum,       
                  input a,          
                  input b,          
                  input carryIn);   
  wire s1, s2, c1, c2;

  xor XOR1 (s1, a, b);     
  xor XOR2 (sum, s1, carryIn); 
  and AND1 (c1, a, b);     
  and AND2 (c2, s1, carryIn); 
  or OR1 (carryOut, c1, c2);        
endmodule // fullAdder


// -------------------------
// complemento de 2 de 6 bits
// -------------------------
module complement2_6bits (output [5:0] comp2,  // saída: complemento de 2
                          input [5:0] a);     // entrada: valor de 6 bits
  wire [5:0] comp1;  // armazena complemento de 1
  wire [4:0] carry;  // armazena bits de carry

  // Obter complemento de 1
  complement1_6bits C1 (comp1, a);

  // Adicionar 1 ao complemento de 1 para obter o complemento de 2
  fullAdder FA0 (carry[0], comp2[0], comp1[0], 1'b0, 1'b1);  // Somar 1 ao bit menos significativo
  fullAdder FA1 (carry[1], comp2[1], comp1[1], 1'b0, carry[0]);
  fullAdder FA2 (carry[2], comp2[2], comp1[2], 1'b0, carry[1]);
  fullAdder FA3 (carry[3], comp2[3], comp1[3], 1'b0, carry[2]);
  fullAdder FA4 (carry[4], comp2[4], comp1[4], 1'b0, carry[3]);
  fullAdder FA5 ( , comp2[5], comp1[5], 1'b0, carry[4]);      // Carry final não é necessário
endmodule // complement2_6bits

// -------------------------
// Teste para complemento de 2 de 6 bits
// -------------------------
module test_complement2_6bits;
  // ------------------------- definir dados
  reg [5:0] x;
  wire [5:0] comp2;

  complement2_6bits C2 (comp2, x);


  // ------------------------- parte principal
  initial begin
    $display("Guia_0805");
    $display("Testes do Complemento de 2 de 6 bits");
    $display("x      = complemento de 2");

    // Teste 1
    x = 6'b000001;  // 1
    #1;
    $display("%b = %b", x, comp2);

    // Teste 2
    x = 6'b000011;  // 3
    #1;
    $display("%b = %b", x, comp2);

    // Teste 3
    x = 6'b100011;  // -13 em complemento de 2
    #1;
    $display("%b = %b", x, comp2);

    // Teste 4
    x = 6'b111111;  // -1
    #1;
    $display("%b = %b", x, comp2);

    // Teste 5
    x = 6'b000000;  // 0
    #1;
    $display("%b = %b", x, comp2);
  end
endmodule // test_complement2_6bits

/*
Guia_0805
Testes do Complemento de 2 de 6 bits
x      = complemento de 2
000001 = 111111
000011 = 111101
100011 = 011101
111111 = 000001
000000 = 000000
*/