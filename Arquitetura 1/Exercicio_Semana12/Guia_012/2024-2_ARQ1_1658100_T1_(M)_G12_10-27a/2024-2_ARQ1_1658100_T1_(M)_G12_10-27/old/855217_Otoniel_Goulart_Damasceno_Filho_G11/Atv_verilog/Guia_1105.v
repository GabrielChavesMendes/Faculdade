// Guia_1105.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- FSM para reconhecer 010 ou 101
// --------------
`define found 1
`define notfound 0

module guia_1105 (y, x, clk, reset);
    output reg y;  // Saída como reg, pois é alterada dentro do always
    input x, clk, reset;

    // Identificadores de estado
    parameter 
        start     = 2'b00,
        detect1   = 2'b01,
        detect10  = 2'b10,
        detect010 = 2'b11;

    reg [1:0] E1; // Estado atual
    reg [1:0] E2; // Próximo estado

    // Lógica de transição de estados
    always @(x or E1) begin
        case (E1)
            start:     E2 = (x) ? detect1 : start;        // Se x for 1, vai para detect1
            detect1:   E2 = (x) ? start : detect10;       // Se x for 0, vai para detect10
            detect10:  E2 = (x) ? detect1 : detect010;    // Se x for 1, vai para detect1, senão para detect010
            detect010: begin
                E2 = (x) ? start : detect010;             // Mantém em detect010 se x for 0
                y = (x) ? `found : `notfound;            // Saída é 'found' quando x é 0 em detect010
            end
            default:   E2 = 2'bxx;                         // Estado indefinido
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
