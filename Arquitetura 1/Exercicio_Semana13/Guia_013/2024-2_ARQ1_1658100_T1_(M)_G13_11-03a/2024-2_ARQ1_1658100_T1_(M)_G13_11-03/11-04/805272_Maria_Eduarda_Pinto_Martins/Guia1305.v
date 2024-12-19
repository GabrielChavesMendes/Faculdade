module contador_mod7_t (
    input clk,           // Clock principal
    input reset,         // Reset para inicializar o contador
    output [2:0] q       // Saída de 3 bits (conta de 0 a 6)
);
    // Registradores para armazenar o estado do contador
    reg [2:0] q_reg;

    // Atribuir a saída ao estado do contador
    assign q = q_reg;

    // Inicialização do contador em 0
    initial begin
        q_reg = 3'b000;
    end

    // Sempre que o clock ou reset mudar
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            q_reg <= 3'b000;  // Reiniciar para 0
        end else if (q_reg == 3'b111) begin
            q_reg <= 3'b000;  // Reiniciar para 0 quando chegar em 111
        end else begin
            q_reg[0] <= ~q_reg[0];                   // Toggle Q0 a cada clock
            q_reg[1] <= q_reg[1] ^ q_reg[0];         // Toggle Q1 quando Q0 = 1
            q_reg[2] <= q_reg[2] ^ (q_reg[1] & q_reg[0]); // Toggle Q2 quando Q1 e Q0 = 1
        end
    end
endmodule
