module contador_decadico_decrescente_jk (
    input clk,         // Clock principal
    input reset,       // Reset para inicializar o contador
    output [3:0] q     // Saída de 4 bits
);
    // Registradores para armazenar o estado do contador
    reg [3:0] q_reg;

    // Atribuir a saída ao estado do contador
    assign q = q_reg;

    // Inicializar o contador no valor 9 (1001)
    initial begin
        q_reg = 4'b1001;
    end

    // Sempre que o clock ou reset mudar
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            q_reg <= 4'b1001;  // Reiniciar para 1001
        end else if (q_reg == 4'b0000) begin
            q_reg <= 4'b1001;  // Reiniciar para 1001 quando chegar em 0000
        end else begin
            q_reg[0] <= ~q_reg[0];                          // Toggle Q0 a cada clock
            q_reg[1] <= q_reg[1] ^ ~q_reg[0];               // Toggle Q1 quando Q0 = 0 (decrescente)
            q_reg[2] <= q_reg[2] ^ (~q_reg[1] & ~q_reg[0]); // Toggle Q2 quando Q1 e Q0 = 0
            q_reg[3] <= q_reg[3] ^ (~q_reg[2] & ~q_reg[1] & ~q_reg[0]); // Toggle Q3 quando todos os bits anteriores são 0
        end
    end
endmodule
