module contador_mod7 (
    input wire clk,         
    input wire reset,        
    output reg [2:0] count   
);

    // Inicialização do contador
    initial count = 3'b000;

    always @(posedge clk or posedge reset) begin
        if (reset)
            count <= 3'b000;      // Reset para 0
        else if (count == 3'b110) // Verifica se o valor é 6 (110 em binário)
            count <= 3'b000;      // Reset para 0 ao atingir 6
        else
            count <= count + 1;  
    end
endmodule
