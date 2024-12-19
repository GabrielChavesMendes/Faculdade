// Moore_1101.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- Moore FSM
// --------------
`define found 1
`define notfound 0

module moore_1101 (y, x, clk, reset);
    output reg y;  // Saída como reg, pois é alterada dentro do always
    input x, clk, reset;

    // Identificadores de estado
    parameter 
        start   = 3'b000,
        id1     = 3'b001,
        id11    = 3'b011,
        id110   = 3'b010,
        id1101  = 3'b110;

    reg [2:0] E1; // Estado atual
    reg [2:0] E2; // Próximo estado

    // Lógica de transição de estados
    always @(x or E1) begin
        case (E1)
            start:   E2 = (x) ? id1 : start;              // Transição do estado inicial
            id1:     E2 = (x) ? id11 : start;             // Transição após receber 1
            id11:    E2 = (x) ? id11 : id110;             // Transição ao continuar recebendo 1
            id110:   E2 = (x) ? id1101 : start;           // Transição para id1101 ou volta ao início
            id1101:  E2 = (x) ? id11 : start;              // Transição para id11 ou volta ao início
            default: E2 = 3'bxxx;                         // Estado indefinido
        endcase
    end

    // Atualização do estado atual com o clock ou reset
    always @(posedge clk or negedge reset) begin
        if (!reset) 
            E1 <= start;  // Retorna ao estado inicial em caso de reset
        else 
            E1 <= E2;     // Atualiza para o próximo estado
    end

    // Lógica de saída
    always @(E1) begin
        y = (E1 == id1101) ? `found : `notfound;  // Define a saída com base no estado
    end
endmodule
