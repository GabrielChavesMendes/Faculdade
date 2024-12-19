module contador_modulo7 (
    input clk,             // Clock principal
    input reset,           // Reset síncrono
    output [2:0] count     // Saída do contador de 3 bits
);
    // Registradores para os flip-flops T
    reg [2:0] q;           // Estados dos flip-flops

    // Lógica combinacional para entradas T
    wire t0, t1, t2;
    assign t0 = 1'b1;              // FF0 alterna sempre
    assign t1 = q[0];              // FF1 alterna quando Q0 é 1
    assign t2 = q[1] & q[0];       // FF2 alterna quando Q1 e Q0 são 1

    // Lógica sequencial para flip-flops T
    always @(posedge clk) begin
        if (reset) begin
            q <= 3'b000;           // Reset para 000
        end else begin
            // Atualização dos estados dos flip-flops
            q[0] <= t0 ? ~q[0] : q[0];
            q[1] <= t1 ? ~q[1] : q[1];
            q[2] <= t2 ? ~q[2] : q[2];
        end
    end

    assign count = q;              // Saída do contador
endmodule
