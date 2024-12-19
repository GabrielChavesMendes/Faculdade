//Otávio Augusto de Assis Ferreira Monteiro
//851568
module ram_1x4 (
    input wire CLK_,
    input wire R_W_,         
    input wire ADDR_,        
    input wire [3:0] data_in, 
    output reg [3:0] data_out, 
    input wire CLR           
);

    reg [3:0] mem; // Registro de memória para armazenar 4 bits

    // Processo de escrita e leitura
    always @(posedge CLK_ or posedge CLR) begin
        if (CLR) begin
            mem <= 4'b0000; // Limpa a memória se CLR for ativado
            data_out <= 4'b0000; // Saída é zerada
        end
        else if (R_W_) begin
            // Escrita na borda de subida do clock
            mem <= data_in;
        end
    end

    always @(negedge CLK_) begin
        if (!R_W_) begin
            // Leitura na borda de descida do clock
            data_out <= mem;
        end
    end

endmodule
