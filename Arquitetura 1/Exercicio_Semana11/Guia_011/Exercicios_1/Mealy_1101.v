// ---------------------
// --- Mealy FSM: 1101
// ---------------------
`define found 1
`define notfound 0

module mealy_1101 (
    output reg y,       // Saída da FSM (1 se padrão encontrado)
    output reg [1:0] E1, // Saída para monitorar o estado atual
    input x,            // Entrada
    input clk,          // Clock
    input reset         // Reset
);

    // Identificadores de estados
    parameter start = 2'b00, 
              id1   = 2'b01, 
              id11  = 2'b11, 
              id110 = 2'b10;

    reg [1:0] E2; // Próximo estado

    // Lógica de próximo estado e saída
    always @(x or E1) begin
        y = `notfound; // Saída padrão
        case (E1)
            start: begin
                if (x)
                    E2 = id1;
                else
                    E2 = start;
            end
            id1: begin
                if (x)
                    E2 = id11;
                else
                    E2 = start;
            end
            id11: begin
                if (x)
                    E2 = id11;
                else
                    E2 = id110;
            end
            id110: begin
                if (x) begin
                    E2 = id1;
                    y = `found; // Padrão encontrado
                end else begin
                    E2 = start;
                    y = `notfound;
                end
            end
            default: E2 = 2'bxx; // Estado indefinido
        endcase
    end

    // Lógica de atualização de estado
    always @(posedge clk or negedge reset) begin
        if (!reset)
            E1 <= start; // Resetar para o estado inicial
        else
            E1 <= E2;    // Atualizar para o próximo estado
    end

endmodule
