//Guia_0705.v

// -------------------------
// Guia_0705 - GATES
// Alessandra Faria Rodrigues
// 828333
// -------------------------

// -------------------------
// LU (NOT, AND, NAND, OR, NOR, XOR, XNOR)
// -------------------------
module lu (
    output not_out,
    output and_out,
    output nand_out,
    output or_out,
    output nor_out,
    output xor_out,
    output xnor_out,
    input a,
    input b
);
// Descrever por portas
    not NOT1 (not_out, a);           // Operação NOT (somente A é considerado)
    and AND1 (and_out, a, b);        // Operação AND
    nand NAND1 (nand_out, a, b);     // Operação NAND
    or OR1 (or_out, a, b);           // Operação OR
    nor NOR1 (nor_out, a, b);        // Operação NOR
    xor XOR1 (xor_out, a, b);        // Operação XOR
    xnor XNOR1 (xnor_out, a, b);     // Operação XNOR
endmodule // lu

// -------------------------
// Multiplexer 7x1
// -------------------------
module mux7x1 (
    output s,
    input a,
    input b,
    input c,
    input d,
    input e,
    input f,
    input g,
    input [2:0] select
);
// Definir dados locais
    wire sa, sb, sc, sd, se, sf, sg;
    wire sel0, sel1, sel2, sel3, sel4, sel5, sel6;
    wire not_sel0, not_sel1, not_sel2;

    // Inversores para os sinais de seleção
    not NOT_SEL0 (not_sel0, select[0]);
    not NOT_SEL1 (not_sel1, select[1]);
    not NOT_SEL2 (not_sel2, select[2]);

    // Geração de sinais de habilitação
    and AND_SEL0 (sel0, not_sel2, not_sel1, not_sel0); // 000
    and AND_SEL1 (sel1, not_sel2, not_sel1, select[0]); // 001
    and AND_SEL2 (sel2, not_sel2, select[1], not_sel0); // 010
    and AND_SEL3 (sel3, not_sel2, select[1], select[0]); // 011
    and AND_SEL4 (sel4, select[2], not_sel1, not_sel0); // 100
    and AND_SEL5 (sel5, select[2], not_sel1, select[0]); // 101
    and AND_SEL6 (sel6, select[2], select[1], not_sel0); // 110

    // Multiplexar os sinais
    and AND1 (sa, a, sel0);
    and AND2 (sb, b, sel1);
    and AND3 (sc, c, sel2);
    and AND4 (sd, d, sel3);
    and AND5 (se, e, sel4);
    and AND6 (sf, f, sel5);
    and AND7 (sg, g, sel6);

    or OR1 (s, sa, sb, sc, sd, se, sf, sg); // Saída única
endmodule // mux7x1

// -------------------------
// LU com seleção
// -------------------------
module lu_selector (
    output result,
    input a,
    input b,
    input [2:0] op_select
);
// Definir dados locais
    wire not_out, and_out, nand_out, or_out, nor_out, xor_out, xnor_out;

    // Instanciar a LU
    lu LU1 (not_out, and_out, nand_out, or_out, nor_out, xor_out, xnor_out, a, b);

    // Multiplexador 7x1 para selecionar operação
    mux7x1 MUX1 (result, not_out, and_out, nand_out, or_out, nor_out, xor_out, xnor_out, op_select);
endmodule // lu_selector

// -------------------------
// Teste LU com seleção
// -------------------------
module test_lu_selector;
// Definir dados
    reg x;              // Entrada A
    reg y;              // Entrada B
    reg [2:0] op_sel;   // Seleção da operação
    wire z;             // Saída final

    // Instanciar o módulo principal
    lu_selector LU_SELECTOR1 (z, x, y, op_sel);

    // Parte principal
    initial
    begin : main
        $display("Guia_0705 - Alessandra Faria Rodrigues - 828333");
        $display("Test LU Selector");
        $display(" x y op_sel z");

        // Inicializar valores
        x = 1'b0; y = 1'b1; op_sel = 3'b000;

        // Monitorar mudanças
        #1 $monitor("%4b %4b %6b %4b", x, y, op_sel, z);

        // Testes
        #1 op_sel = 3'b001; // Selecionar AND
        #1 op_sel = 3'b010; // Selecionar NAND
        #1 op_sel = 3'b011; // Selecionar OR
        #1 op_sel = 3'b100; // Selecionar NOR
        #1 op_sel = 3'b101; // Selecionar XOR
        #1 op_sel = 3'b110; // Selecionar XNOR
        #1 x = 1'b1; y = 1'b1; // Teste com ambos iguais a 1
        #1 op_sel = 3'b000; // Voltar para NOT
    end
endmodule // test_lu_selector
