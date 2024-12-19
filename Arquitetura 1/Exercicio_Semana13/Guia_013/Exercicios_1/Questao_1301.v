module contador_decrescente (
    input clk,           // Clock principal
    input reset,         // Reset assíncrono
    output [4:0] count   // Saída do contador de 5 bits
);
    // Registradores internos para armazenar o estado
    reg [4:0] q;

    // Conexões internas para os flip-flops JK
    wire [4:0] clk_div;  // Clocks para os flip-flops individuais

    // Inicialização do contador no reset
    always @(negedge reset or posedge clk) begin
        if (!reset)
            q <= 5'b11111;  // Reset para o valor máximo
        else begin
            q[0] <= ~q[0];                        // FF0 alterna
            q[1] <= (q[0]) ? ~q[1] : q[1];       // FF1 alterna quando FF0 vai para 0
            q[2] <= (q[1] & q[0]) ? ~q[2] : q[2];// FF2 alterna quando FF1 e FF0 estão em 0
            q[3] <= (q[2] & q[1] & q[0]) ? ~q[3] : q[3];
            q[4] <= (q[3] & q[2] & q[1] & q[0]) ? ~q[4] : q[4];
        end
    end

    assign count = q;

endmodule
