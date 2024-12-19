//Otávio Augusto de Assis Ferreira Monteiro
//851568
module ram_4x16 (
    input wire [15:0] dados_in,
    input wire enable,
    input wire write_enable,
    input wire [1:0] addr,         
    output reg [15:0] dados_out
);
    reg [7:0] ram0[3:0]; 
    reg [7:0] ram1[3:0]; 

    always @(*) begin
        if (enable) begin
            if (write_enable) begin
                ram0[addr] <= dados_in[7:0];
                ram1[addr] <= dados_in[15:8]; 
            end else begin
                dados_out <= {ram1[addr], ram0[addr]}; 
            end
        end
    end
endmodule
