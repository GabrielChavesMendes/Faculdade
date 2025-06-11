/*
Guia_1101.v
859919 - Marcella Santos Belchior
*/

// --------------
// --- Mealy FSM
// --------------
// constant definitions
`define found 1
`define notfound 0

module mealy_1101 (y, x, clk, reset);
    output reg y;  // Saída
    input x;       // Entrada
    input clk;     // Clock
    input reset;   // Reset
    reg [1:0] E1;  // Estado atual
    reg [1:0] E2;  // Próximo estado

    // Definição dos estados
    parameter 
        start = 2'b00,
        id1 = 2'b01,
        id11 = 2'b11,
        id110 = 2'b10;

    // Lógica de transição de estados (combinacional)
    always @(x or E1) begin
        y = `notfound;  // Inicializa a saída como não encontrada
        case (E1)
            start: 
                if (x)
                    E2 = id1;
                else
                    E2 = start;

            id1: 
                if (x)
                    E2 = id11;
                else
                    E2 = start;

            id11: 
                if (x)
                    E2 = id11;
                else
                    E2 = id110;

            id110: 
                if (x) begin
                    E2 = id1;
                    y = `found;  // Define a saída como encontrada
                end else begin
                    E2 = start;
                    y = `notfound;
                end

            default: 
                E2 = 2'bxx;  // Estado indefinido
        endcase
    end

    // Atualização do estado atual (sequencial)
    always @(posedge clk or negedge reset) begin
        if (!reset)
            E1 <= start;  // Estado inicial no reset
        else
            E1 <= E2;  // Transição para o próximo estado
    end
endmodule
