//Guia_0702.v

// -------------------------
// Guia_0702 - GATES
// Alessandra Faria Rodrigues
// 828333
// -------------------------
// -------------------------
// LU (OR e NOR)
// -------------------------
module lu (
    output or_out, 
    output nor_out, 
    input a, 
    input b
);
// Descrever por portas
    or OR1 (or_out, a, b);
    nor NOR1 (nor_out, a, b);
endmodule // lu

// -------------------------
// Multiplexer
// -------------------------
module mux (
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
endmodule // mux

// -------------------------
// Teste LU com MUX
// -------------------------
module test_lu_mux;
// ------------------------- Definir dados
    reg x;
    reg y;
    reg sel; // Sinal de seleção
    wire or_res;
    wire nor_res;
    wire z; // Saída única selecionada

    // Instanciar módulos
    lu modulo (or_res, nor_res, x, y);
    mux MUX1 (z, nor_res, or_res, sel);

// ------------------------- Parte principal
    initial
    begin : main
        $display("Guia_0702 - Alessandra Faria Rodrigues - 828333");
        $display("Test LU's module");
        $display(" x y sel z");

        // Inicializar valores
        x = 1'b0; y = 1'b1; sel = 1'b0;

        // Monitorar mudanças
        #1 $monitor("%4b %4b %4b %4b", x, y, sel, z);

        // Testes
        #1 sel = 1'b1; // Selecionar OR
        #1 x = 1'b1; y = 1'b1; // Teste com ambos iguais a 1
        #1 sel = 1'b0; // Selecionar NOR
        #1 x = 1'b0; y = 1'b0; // Teste com ambos iguais a 0
    end
endmodule // test_lu_mux
