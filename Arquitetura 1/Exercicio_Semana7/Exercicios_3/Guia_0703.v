// ------------------------- 
// Guia_0703 - Unidade Lógica (LU) 
// Nome: xxx yyy zzz 
// Matricula: 999999 
// ------------------------- 
 
// ------------------------- 
//  Unidade Lógica (LU) 
// ------------------------- 
module lu ( output s,           // saída final
            input  a,           // entrada 1 bit
            input  b,           // entrada 1 bit
            input  select_group, // chave para selecionar grupo (AND/NAND ou OR/NOR)
            input  select_gate  // chave para selecionar a operação dentro do grupo
            ); 

// Definir sinais intermediários
   wire and_out, nand_out, or_out, nor_out; // saídas das portas
   wire mux1_out, mux2_out;  // saídas dos multiplexadores

// Descrever operações lógicas
   and  AND1  (and_out, a, b);   // Operação AND
   nand NAND1 (nand_out, a, b);  // Operação NAND
   or   OR1   (or_out, a, b);    // Operação OR
   nor  NOR1  (nor_out, a, b);   // Operação NOR

// Multiplexador para selecionar entre AND e NAND
   mux mux1 (mux1_out, and_out, nand_out, select_gate);

// Multiplexador para selecionar entre OR e NOR
   mux mux2 (mux2_out, or_out, nor_out, select_gate);

// Multiplexador final para escolher entre os dois grupos (AND/NAND ou OR/NOR)
   mux mux3 (s, mux1_out, mux2_out, select_group);

endmodule // lu
 
 
// ------------------------- 
//  Multiplexer 2x1 
// ------------------------- 
module mux ( output s, 
             input  a, 
             input  b, 
             input  select ); 

// Definir dados locais
   wire not_select;
   wire sa, sb;

// Descrever por portas
   not NOT1 (not_select, select); 
   and AND1 (sa, a, not_select); 
   and AND2 (sb, b, select); 
   or  OR1  (s, sa, sb);

endmodule // mux
 
 
// ------------------------- 
//  Teste da Unidade Lógica (LU) 
// ------------------------- 
module test_lu; 
// Definir dados 
   reg  x; 
   reg  y; 
   reg  select_group;  // Seleciona grupo (AND/NAND ou OR/NOR)
   reg  select_gate;   // Seleciona operação dentro do grupo
   wire z;             // Saída final

   // Instanciar a unidade lógica (LU)
   lu LU1 (z, x, y, select_group, select_gate);

// Parte principal 
   initial 
   begin : main 
          $display("Guia_0703 - xxx yyy zzz - 999999"); 
          $display("Test LU's module"); 
          $display(" x  y  select_group select_gate |  z "); 

          // Testes iniciais
          x = 1'b0; y = 1'b1; select_group = 1'b0; select_gate = 1'b0; 
          #1 $monitor("%2b %2b %10b %11b  |  %2b", x, y, select_group, select_gate, z); 

          // Testar diferentes combinações de chaves e entradas
          #1 x = 1'b0; y = 1'b0; select_group = 1'b0; select_gate = 1'b0; // AND
          #1 x = 1'b1; y = 1'b0; select_group = 1'b0; select_gate = 1'b1; // NAND
          #1 x = 1'b1; y = 1'b1; select_group = 1'b1; select_gate = 1'b0; // OR
          #1 x = 1'b1; y = 1'b1; select_group = 1'b1; select_gate = 1'b1; // NOR
end 
 
endmodule // test_lu

/*
Guia_0703 - xxx yyy zzz - 999999
Test LU's module
 x  y  select_group select_gate |  z
 0  1          0           0  |   0
 0  0          0           0  |   0
 1  0          0           1  |   1
 1  1          1           0  |   1
 1  1          1           1  |   0
*/