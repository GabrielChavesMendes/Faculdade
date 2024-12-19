// Guia_1102.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- Mealy FSM para 1001 sem interseção
// --------------
`define found 1
`define notfound 0

module guia_1102 (y, x, clk, reset);
    output reg y;  // Saída declarada como reg, pois é alterada no bloco always
    input x, clk, reset;

    // Identificadores de estado
    parameter 
        start = 2'b00,
        id1 = 2'b01,
        id10 = 2'b10,
        id100 = 2'b11;
    
    reg [1:0] E1; // Estado atual
    reg [1:0] E2; // Próximo estado

    // Lógica de transição de estados
    always @(x or E1) begin
        y = `notfound;  // Inicializa como não encontrado
        case (E1)
            start:   E2 = (x) ? id1 : start;  // Transição para id1 se x for 1
            id1:     E2 = (x) ? id1 : id10;  // Se x for 0, transita para id10
            id10:    E2 = (x) ? id100 : start;  // Se x for 1, transita para id100
            id100: begin
                E2 = (x) ? id1 : start;  // Se x for 1, volta para id1
                y = (x) ? `notfound : `found;  // Detecta a sequência completa '1001'
            end
            default: E2 = 2'bxx;  // Estado indefinido
        endcase
    end

    // Atualização do estado atual com clock ou reset
    always @(posedge clk or negedge reset) begin
        if (!reset) 
            E1 <= start;  // Se reset ativo, volta para o estado inicial
        else 
            E1 <= E2;  // Atualiza para o próximo estado
    end
endmodule
