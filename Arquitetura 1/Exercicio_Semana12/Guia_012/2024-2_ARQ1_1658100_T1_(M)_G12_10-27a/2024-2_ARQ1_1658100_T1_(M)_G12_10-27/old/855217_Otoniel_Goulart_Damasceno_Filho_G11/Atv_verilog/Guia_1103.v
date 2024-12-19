// Guia_1103.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- Moore FSM para 1001 com interseção
// --------------
`define found 1
`define notfound 0

module guia_1103 (y, x, clk, reset);
    output reg y;  // Saída declarada como reg, pois é alterada no bloco always
    input x, clk, reset;

    // Identificadores de estado
    parameter 
        start  = 3'b000,
        id1    = 3'b001,
        id10   = 3'b010,
        id100  = 3'b011,
        id1001 = 3'b100;
    
    reg [2:0] E1; // Estado atual
    reg [2:0] E2; // Próximo estado

    // Lógica de transição de estados
    always @(x or E1) begin
        case (E1)
            start:   E2 = (x) ? id1 : start;    // Transita para id1 se x for 1
            id1:     E2 = (x) ? id1 : id10;     // Se x for 0, transita para id10
            id10:    E2 = (x) ? id100 : start;  // Se x for 1, transita para id100
            id100:   E2 = (x) ? id1 : id1001;   // Se x for 0, transita para id1001
            id1001:  E2 = (x) ? id1 : start;    // Se x for 1, volta para id1
            default: E2 = 3'bxxx;               // Estado indefinido
        endcase
    end

    // Atualização do estado atual com clock ou reset
    always @(posedge clk or negedge reset) begin
        if (!reset) 
            E1 <= start;  // Se reset for ativo, volta para o estado inicial
        else 
            E1 <= E2;     // Atualiza para o próximo estado
    end

    // Lógica de saída (baseada no estado atual)
    always @(E1) begin
        y = (E1 == id1001) ? `found : `notfound;  // A saída é 'found' quando no estado id1001
    end
endmodule
