//Guia_0704.v

// -------------------------
// Guia_0704 - GATES
// Alessandra Faria Rodrigues
// 828333
// -------------------------
// -------------------------
// LU (OR, NOR, XOR, XNOR)
// -------------------------
module lu (
    output nor_out,
    output or_out,
    output xor_out,
    output xnor_out,
    input a,
    input b
);
// Descrever por portas
    nor NOR1 (nor_out, a, b);
    or OR1 (or_out, a, b);
    xor XOR1 (xor_out, a, b);
    xnor XNOR1 (xnor_out, a, b);
endmodule // lu

// -------------------------
// Multiplexer 4x1
// -------------------------
module mux4x1 (
    output s,
    input a,
    input b,
    input c,
    input d,
    input [1:0] select
);
// Definir dados locais
    wire sel0, sel1, sel2, sel3;
    wire not_sel0, not_sel1;
    wire sa, sb, sc, sd;

    // Inversores para seleção
    not NOT_SEL0 (not_sel0, select[0]);
    not NOT_SEL1 (not_sel1, select[1]);

    // Geração de sinais de habilitação
    and AND_SEL0 (sel0, not_sel0, not_sel1);
    and AND_SEL1 (sel1, select[0], not_sel1);
    and AND_SEL2 (sel2, not_sel0, select[1]);
    and AND_SEL3 (sel3, select[0], select[1]);

    // Multiplexação das entradas
    and AND1 (sa, a, sel0);
    and AND2 (sb, b, sel1);
    and AND3 (sc, c, sel2);
    and AND4 (sd, d, sel3);
    or OR1 (s, sa, sb, sc, sd);
endmodule // mux4x1

// -------------------------
// Seleção de operações LU
// -------------------------
module lu_selector (
    output result,
    input a,
    input b,
    input [1:0] op_select
);
// Definir dados locais
    wire nor_out, or_out, xor_out, xnor_out;

    // Instanciar a LU
    lu LU1 (nor_out, or_out, xor_out, xnor_out, a, b);

    // Multiplexador 4x1 para seleção da operação
    mux4x1 MUX1 (result, nor_out, or_out, xor_out, xnor_out, op_select);
endmodule // lu_selector

// -------------------------
// Teste LU com seleção de operação
// -------------------------
module test_lu_selector;
// Definir dados
    reg x;
    reg y;
    reg [1:0] op_sel; // Seleção da operação
    wire z;           // Resultado final

    // Instanciar módulo principal
    lu_selector LU_SELECTOR1 (z, x, y, op_sel);

    // Parte principal
    initial
    begin : main
        $display("Guia_0704 - Alessandra Faria Rodrigues - 828333");
        $display("Test LU");
        $display(" x y op_sel z");

        // Inicializar valores
        x = 1'b0; y = 1'b1; op_sel = 2'b00;

        // Monitorar mudanças
        #1 $monitor("%4b %4b %6b %4b", x, y, op_sel, z);

        // Testes
        #1 op_sel = 2'b01; // Selecionar OR
        #1 op_sel = 2'b10; // Selecionar XOR
        #1 op_sel = 2'b11; // Selecionar XNOR
        #1 x = 1'b1; y = 1'b1; // Teste com ambos iguais a 1
        #1 op_sel = 2'b00; // Voltar para NOR
    end
endmodule // test_lu_selector
