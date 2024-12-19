module contador_decadico_crescente (
    input clk,            // Clock principal
    input reset,          // Reset assíncrono
    output [3:0] count    // Saída do contador de 4 bits
);
    // Registradores internos para os flip-flops JK
    reg [3:0] q;          // Estados dos flip-flops

    // Lógica combinacional para reset no estado 1010
    wire reset_condition;
    assign reset_condition = (q == 4'b1010);

    // Contador decádico
    always @(negedge reset or negedge clk) begin
        if (!reset || reset_condition) begin
            q <= 4'b0000;  // Reset para 0000
        end else begin
            q[0] <= ~q[0];                          // FF0 alterna sempre
            q[1] <= (q[0]) ? ~q[1] : q[1];         // FF1 alterna quando FF0 é 1
            q[2] <= (q[1] & q[0]) ? ~q[2] : q[2];  // FF2 alterna quando FF1 e FF0 são 1
            q[3] <= (q[2] & q[1] & q[0]) ? ~q[3] : q[3]; // FF3 alterna quando FF2, FF1 e FF0 são 1
        end
    end

    assign count = q;

endmodule
