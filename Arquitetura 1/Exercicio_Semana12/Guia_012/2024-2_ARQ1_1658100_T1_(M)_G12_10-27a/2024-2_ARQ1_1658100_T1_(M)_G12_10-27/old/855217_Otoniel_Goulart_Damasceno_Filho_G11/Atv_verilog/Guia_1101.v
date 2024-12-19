// Guia_1101.v
// Nome: Otoniel Goulart Damasceno Filho
// Matrícula: 855217
// --------------
// --- Mealy FSM para 1001
// --------------
`define found 1
`define notfound 0

module guia_1101 (y, x, clk, reset);
    output reg y;  // Saída declarada como reg, pois é atribuída em sempre (always)
    input x, clk, reset;

    // Identificadores dos estados
    parameter 
        start = 2'b00,
        id1 = 2'b01,
        id10 = 2'b10,
        id100 = 2'b11;
    
    reg [1:0] E1; // Estado atual
    reg [1:0] E2; // Próximo estado

    // Lógica para definir o próximo estado e saída
    always @(x or E1) begin
        y = `notfound;  // Inicializa y como não encontrado
        case (E1)
            start:   E2 = (x) ? id1 : start;
            id1:     E2 = (x) ? id1 : id10;
            id10:    E2 = (x) ? id100 : start;
            id100: begin
                E2 = (x) ? id1 : start;
                y = (x) ? `notfound : `found;  // Define y como encontrado quando a sequência '1001' é reconhecida
            end
            default: E2 = 2'bxx;  // Estado indefinido
        endcase
    end

    // Atualização dos estados com clock ou reset
    always @(posedge clk or negedge reset) begin
        if (!reset) 
            E1 <= start;  // Se reset for acionado, vai para o estado inicial
        else 
            E1 <= E2;      // Caso contrário, transita para o próximo estado
    end
endmodule
