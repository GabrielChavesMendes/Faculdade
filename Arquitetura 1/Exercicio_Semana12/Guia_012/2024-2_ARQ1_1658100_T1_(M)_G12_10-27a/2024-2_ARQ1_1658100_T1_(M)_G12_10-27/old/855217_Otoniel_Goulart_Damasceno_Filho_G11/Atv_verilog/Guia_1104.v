// Guia_1104.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- FSM para reconhecer x000
// --------------
`define found 1
`define notfound 0

module guia_1104 (y, x, clk, reset);
    output reg y;  // Saída como reg, pois é alterada dentro do always
    input x, clk, reset;

    // Identificadores de estado
    parameter 
        start     = 3'b000,
        detect0   = 3'b001,
        detect00  = 3'b010,
        detect000 = 3'b011;

    reg [2:0] E1; // Estado atual
    reg [2:0] E2; // Próximo estado

    // Lógica de transição de estados
    always @(x or E1) begin
        case (E1)
            start:     E2 = (x) ? start : detect0;      // Se x for 0, vai para detect0
            detect0:   E2 = (x) ? start : detect00;     // Se x for 0, vai para detect00
            detect00:  E2 = (x) ? start : detect000;    // Se x for 0, vai para detect000
            detect000: begin
                E2 = (x) ? start : detect000;           // Mantém em detect000 se x for 0
                y = (x) ? `notfound : `found;           // Saída é 'found' quando x é 0 em detect000
            end
            default:   E2 = 3'bxxx;                     // Estado indefinido
        endcase
    end

    // Atualização do estado atual com o clock ou reset
    always @(posedge clk or negedge reset) begin
        if (!reset) 
            E1 <= start;  // Volta para o estado inicial em caso de reset
        else 
            E1 <= E2;     // Atualiza para o próximo estado
    end
endmodule
