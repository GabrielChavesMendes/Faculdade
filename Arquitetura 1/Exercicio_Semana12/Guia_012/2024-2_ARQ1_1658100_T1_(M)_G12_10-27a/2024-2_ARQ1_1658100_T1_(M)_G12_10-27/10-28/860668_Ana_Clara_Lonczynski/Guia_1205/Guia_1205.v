// Ana Clara Lonczynski - 680688
// Guia_1205.v

module Mem8x8(
    input wire clk,
    input wire en_write,
    input wire [7:0] addr,
    input wire [7:0] data_in,
    output reg [7:0] data_out
);

    reg [7:0] mem [7:0];

    // Processo de escrita na borda de subida do clock
    always @(posedge clk) begin
        if (en_write) begin
            mem[addr[2:0]] <= data_in;
        end
    end

    // Processo de leitura na borda de descida do clock
    always @(negedge clk) begin
        data_out <= mem[addr[2:0]];
    end

endmodule

module test;
    reg clk, en_write;
    reg [7:0] addr;
    reg [7:0] data_in;
    wire [7:0] result;

    Mem8x8 mem_inst (clk, en_write, addr, data_in, result);

    initial begin
        $display("Guia_1205.v - Ana Clara Lonczynski");
        $display("==================================");
        $display("Memory Test");

        $monitor ("%4d %4d %4d %8b | %8b", clk, en_write, addr, data_in, result);
        clk = 1'b1;
        en_write = 1'b1;
        addr = 8'b00000000;
        data_in = 8'b10010100;

        #10 clk = 1'b0; en_write = 1'b1; addr = 8'b00000000; data_in = 8'bxxxxxxxx; 
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000001; data_in = 8'b11110000;  
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000001; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000010; data_in = 8'b10101010;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000010; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000011; data_in = 8'b10000011;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000011; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000100; data_in = 8'b10000000;  
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000100; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000101; data_in = 8'b00000001;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000101; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000110; data_in = 8'b10110011;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000110; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1; en_write = 1'b1; addr = 8'b00000111; data_in = 8'b11111111;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000111; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000000; data_in = 8'bxxxxxxxx;  
        #10 clk = 1'b1;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000100; data_in = 8'bxxxxxxxx;
        #10 clk = 1'b1;
        #10 clk = 1'b0; en_write = 1'b0; addr = 8'b00000010; data_in = 8'bxxxxxxxx;
    end
endmodule
