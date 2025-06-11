//Guia_0703.v

// -------------------------
// Guia_0703 - GATES
// Alessandra Faria Rodrigues
// 828333
// -------------------------
// -------------------------
// LU (AND, NAND, OR, NOR)
// -------------------------
module lu (
    output and_out,
    output nand_out,
    output or_out,
    output nor_out,
    input a,
    input b
);
// Descrever por portas
    and AND1 (and_out, a, b);
    nand NAND1 (nand_out, a, b);
    or OR1 (or_out, a, b);
    nor NOR1 (nor_out, a, b);
endmodule // lu

// -------------------------
// Multiplexer 2x1
// -------------------------
module mux2x1 (
    output s,
    input a,
    input b,
    input select
);
// Definir dados locais
    wire not_select;
    wire sa;
    wire sb;
// Descrever por portas
    not NOT1 (not_select, select);
    and AND1 (sa, a, not_select);
    and AND2 (sb, b, select);
    or OR1 (s, sa, sb);
endmodule // mux2x1

// -------------------------
// Seleção de grupo e operação
// -------------------------
module lu_selector (
    output result,
    input a,
    input b,
    input op_select,  // Seleciona operação dentro do grupo
    input group_select // Seleciona grupo (0: AND/NAND, 1: OR/NOR)
);
// Definir dados locais
    wire and_out, nand_out, or_out, nor_out;
    wire selected_op_group1, selected_op_group2;

    // Instanciar a LU
    lu LU1 (and_out, nand_out, or_out, nor_out, a, b);

    // Multiplexadores para selecionar a operação de cada grupo
    mux2x1 MUX_OP_GROUP1 (selected_op_group1, nand_out, and_out, op_select); // AND/NAND
    mux2x1 MUX_OP_GROUP2 (selected_op_group2, nor_out, or_out, op_select);   // OR/NOR

    // Multiplexador para selecionar o grupo
    mux2x1 MUX_GROUP (result, selected_op_group1, selected_op_group2, group_select);
endmodule // lu_selector

// -------------------------
// Teste LU com seleção de grupo e operação
// -------------------------
module test_lu_selector;
// Definir dados
    reg x;
    reg y;
    reg op_sel;     // Seleciona operação dentro do grupo
    reg group_sel;  // Seleciona grupo
    wire z;         // Resultado final

    // Instanciar módulo principal
    lu_selector LU_SELECTOR1 (z, x, y, op_sel, group_sel);

    // Parte principal
    initial
    begin : main
        $display("Guia_0703 - Alessandra Faria Rodrigues - 828333");
        $display("Test LU");
        $display(" x y op_sel group_sel z");

        // Inicializar valores
        x = 1'b0; y = 1'b1; op_sel = 1'b0; group_sel = 1'b0;

        // Monitorar mudanças
        #1 $monitor("%4b %4b %7b %9b %4b", x, y, op_sel, group_sel, z);

        // Testes
        #1 op_sel = 1'b1; // Selecionar AND no grupo AND/NAND
        #1 group_sel = 1'b1; // Mudar para grupo OR/NOR e selecionar NOR
        #1 op_sel = 1'b1; // Selecionar OR no grupo OR/NOR
        #1 x = 1'b1; y = 1'b1; // Teste com ambos iguais a 1
        #1 group_sel = 1'b0; op_sel = 1'b0; // Voltar para NAND no grupo AND/NAND
    end
endmodule // test_lu_selector
