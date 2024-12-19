module contador_crescente (
    input wire clk,           // Sinal de clock
    input wire reset,         // Sinal de reset
    output reg [4:0] count    // Saída de 5 bits
);
    // Inicialização do contador
    initial count = 5'b00000; // Inicializa em 0

    always @(posedge clk or posedge reset) begin
        if (reset) 
            count <= 5'b00000; // Reseta para 0
        else
            count <= count + 1; // Incrementa em 1
    end
endmodule
