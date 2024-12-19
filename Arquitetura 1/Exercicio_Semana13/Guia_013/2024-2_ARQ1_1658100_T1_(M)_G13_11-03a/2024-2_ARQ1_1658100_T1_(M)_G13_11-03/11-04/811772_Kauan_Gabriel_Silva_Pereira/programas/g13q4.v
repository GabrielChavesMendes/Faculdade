module contador_decadico_decrescente (
    input wire clk,          
    input wire reset,        
    output reg [3:0] count   
);

    // Inicialização do contador
    initial count = 4'b1001; // Inicializa em 9 (1001 em binário)

    always @(posedge clk or posedge reset) begin
        if (reset)
            count <= 4'b1001;      // Reseta para 9
        else if (count == 4'b0000) // Verifica se o valor é 0
            count <= 4'b1001;      // Reseta para 9 ao atingir 0
        else
            count <= count - 1;   
    end
endmodule
