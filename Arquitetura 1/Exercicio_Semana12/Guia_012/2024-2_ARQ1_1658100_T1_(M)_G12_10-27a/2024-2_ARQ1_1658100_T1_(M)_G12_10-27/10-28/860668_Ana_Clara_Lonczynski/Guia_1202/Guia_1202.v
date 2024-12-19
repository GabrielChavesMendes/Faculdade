// Ana Clara Lonczynski - 680688
// Guia_1202.v

module Memory1x8(
    input wire clk,
    input wire en_write,
    input wire addr,
    input wire [7:0] in_data,
    output reg [7:0] out_data
);

    reg [7:0] mem [0:0];  

    // Escreve na memória na borda de subida do clock se en_write estiver ativo
    always @(posedge clk) begin
        if (en_write) begin
            mem[0] <= in_data;  
        end
    end

    // Lê da memória na borda de descida do clock
    always @(negedge clk) begin
        out_data <= mem[0];  
    end

endmodule

module test;
    reg clk, en_write, addr;
    reg [7:0] in_data;
    wire [7:0] result;

    Memory1x8 mem_inst (clk, en_write, addr, in_data, result); 

    initial begin
        $display("Guia_1202.v - Ana Clara Lonczynski");
        $display("==================================");
        $display("Memory Test");

        $monitor ("%4d %4d %4d %8b | %8b", clk, en_write, addr, in_data, result);
        clk = 1;
        en_write = 1;
        addr = 1;
        in_data = 8'b10010100;  // Escreve um valor na memória

        // Simulação de ciclos de clock
        #10 clk = 0; en_write = 1; addr = 0; in_data = 8'b00010100;  
        #10 clk = 1; en_write = 1; addr = 1; in_data = 8'b11110000;  
        #10 clk = 0;  
    end
endmodule
