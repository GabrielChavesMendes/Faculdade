// Ana Clara Lonczynski - 680688
// Guia_1204.v

module Mem4x8(
    input wire clk,
    input wire en_write,
    input wire [3:0] addr,
    input wire [7:0] in_data,
    output reg [7:0] out_data
);

    reg [7:0] mem [3:0];

    // Escreve na memória na posição especificada por 'addr' na subida do clock
    always @(posedge clk) begin
        if (en_write) begin
            mem[addr] <= in_data; 
        end
    end

    // Lê o dado da posição de memória na descida do clock
    always @(negedge clk) begin
        out_data <= mem[addr];  
    end

endmodule

module test;
    reg clk, en_write;
    reg [3:0] addr;
    reg [7:0] in_data;
    wire [7:0] result;

    Mem4x8 mem_inst (clk, en_write, addr, in_data, result); 

    initial begin
        $display("Guia_1204.v - Ana Clara Lonczynski");
        $display("==================================");
        $display("Memory Test");

        $monitor ("%4d %4d %4d %8b | %8b", clk, en_write, addr, in_data, result);
        clk = 1'b1;
        en_write = 1'b1;
        addr = 4'b0000;
        in_data = 8'b10010100; 

          // Teste de escrita e leitura
        #10 clk = 1'b0; en_write = 1'b1; addr = 4'b0000; in_data = 8'bxxxxxxxx;  
        #10 clk = 1'b1; en_write = 1'b1; addr = 4'b0001; in_data = 8'b11110000;  
        #10 clk = 1'b0; en_write = 1'b0; addr = 4'b0001; in_data = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 4'b0010; in_data = 8'b10101010;
        #10 clk = 1'b0; en_write = 1'b0; addr = 4'b0010; in_data = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 4'b0011; in_data = 8'b10000011;
        #10 clk = 1'b0; en_write = 1'b0; addr = 4'b0011; in_data = 8'bxxxxxxxx;
        #10 clk = 1'b1;
        #10 clk = 1'b0; en_write = 1'b0; addr = 4'b0000; in_data = 8'bxxxxxxxx; 
    end
endmodule