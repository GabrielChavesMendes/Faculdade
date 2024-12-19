// --------------------
//  Nome: Iasmin Ferreira e Oliveira
// Matricula: 854946
// --------------------

`include "jkff.v"

module Contador_Anel;
    reg clk, clear;
    reg H; // constante positiva - high
    reg L; // constante negativa - low

    wire [4:0] q; // saída do contador

    // Instanciando flip-flops JK
    jkff JKFF1 (q[0], q[1], H, H, clk, L, clear);
    jkff JKFF2 (q[1], q[2], H, H, q[0], L, clear);
    jkff JKFF3 (q[2], q[3], H, H, q[1], L, clear);
    jkff JKFF4 (q[3], q[4], H, H, q[2], L, clear);
    jkff JKFF5 (q[4], q[0], H, H, q[3], L, clear); // Conexão para formar o anel

    initial begin : main
        $display("Contador em Anel - 5 Bits");
        $display(" clk    output");
        // Valores iniciais
        clk   = 1;
        H     = 1;
        L     = 0;
        clear = 1;
        #5 clear = 0; // Ativar o contador
        #650
        $finish;
    end // main

    always
        #5 clk = ~clk;

    always @(posedge clk) begin
        $display(" %3d    %b", $time, q); // Exibe o valor atual do contador
    end 
endmodule // Contador_Anel
