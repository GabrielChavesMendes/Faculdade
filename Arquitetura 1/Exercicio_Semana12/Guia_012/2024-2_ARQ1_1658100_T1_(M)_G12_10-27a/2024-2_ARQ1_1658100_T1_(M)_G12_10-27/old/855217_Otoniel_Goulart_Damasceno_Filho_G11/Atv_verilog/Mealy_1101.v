// Mealy_1101.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- Mealy FSM
// --------------
`define found 1
`define notfound 0

module mealy_1101 (y, x, clk, reset);
    output reg y;  // Saída como reg, pois é alterada dentro do always
    input x, clk, reset;

    // Identificadores de estado
    parameter 
        start  = 2'b00,
        id1    = 2'b01,
        id11   = 2'b11,
        id110  = 2'b10;
    
    reg [1:0] E1; // Estado atual
    reg [1:0] E2; // Próximo estado

    // Lógica de transição de estados
    always @(x or E1) begin
        y = `notfound;  // Inicializa y como 'notfound'
        case (E1)
            start: E2 = (x) ? id1 : start;                // Transição do estado inicial
            id1:   E2 = (x) ? id11 : start;               // Transição após receber 1
            id11:  E2 = (x) ? id11 : id110;               // Transição ao continuar recebendo 1
            id110: begin
                E2 = (x) ? id1 : start;                   // Transição para id1 ou volta ao início
                y = (x) ? `found : `notfound;            // Define a saída com base em x
            end
            default: E2 = 2'bxx;                           // Estado indefinido
        endcase
    end

    // Atualização do estado atual com o clock ou reset
    always @(posedge clk or negedge reset) begin
        if (!reset) 
            E1 <= start;  // Retorna ao estado inicial em caso de reset
        else 
            E1 <= E2;     // Atualiza para o próximo estado
    end
endmodule
