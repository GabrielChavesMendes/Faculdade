module contador_crescente (
    input clk,           // Clock principal
    input reset,         // Reset assíncrono
    output [4:0] count   // Saída do contador de 5 bits
);
    // Registradores internos para armazenar o estado
    reg [4:0] q;

    // Inicialização do contador no reset
    always @(negedge reset or negedge clk) begin
        if (!reset)
            q <= 5'b00000;  // Reset para o valor mínimo
        else begin
            q[0] <= ~q[0];                        // FF0 alterna a cada pulso de clock
            q[1] <= (q[0]) ? ~q[1] : q[1];       // FF1 alterna quando FF0 é 1
            q[2] <= (q[1] & q[0]) ? ~q[2] : q[2];// FF2 alterna quando FF1 e FF0 são 1
            q[3] <= (q[2] & q[1] & q[0]) ? ~q[3] : q[3];
            q[4] <= (q[3] & q[2] & q[1] & q[0]) ? ~q[4] : q[4];
        end
    end

    assign count = q;

endmodule

