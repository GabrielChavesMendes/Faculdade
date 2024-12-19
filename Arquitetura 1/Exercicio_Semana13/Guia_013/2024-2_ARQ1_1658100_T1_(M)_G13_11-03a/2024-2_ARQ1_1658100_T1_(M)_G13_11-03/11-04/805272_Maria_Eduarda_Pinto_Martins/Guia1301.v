module contador_crescente_jk (
    input clk,        // clock principal
    input reset,      // reset para inicializar o contador em 0
    output [4:0] q    // saída de 5 bits
);
    // Registradores para armazenar cada bit do contador
    reg [4:0] q_reg;

    // Atribuir as saídas dos flip-flops aos bits do contador
    assign q = q_reg;

    // Inicialização do contador em 0
    initial begin
        q_reg = 5'b00000;  // Começa em 0
    end

    // Sempre que o clock ou reset mudar
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            q_reg <= 5'b00000;  // Reiniciar para 0
        end else begin
            q_reg[0] <= ~q_reg[0];                  // Toggle Q0 a cada clock
            q_reg[1] <= q_reg[1] ^ q_reg[0];        // Toggle Q1 quando Q0 = 1
            q_reg[2] <= q_reg[2] ^ (q_reg[1] & q_reg[0]); // Toggle Q2 quando Q1 e Q0 = 1
            q_reg[3] <= q_reg[3] ^ (q_reg[2] & q_reg[1] & q_reg[0]); // Toggle Q3 quando Q2, Q1 e Q0 = 1
            q_reg[4] <= q_reg[4] ^ (q_reg[3] & q_reg[2] & q_reg[1] & q_reg[0]); // Toggle Q4 quando todos = 1
        end
    end
endmodule
