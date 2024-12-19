// Ana Clara Lonczynski - 680688
// Guia_1203.v

module Mem2x8(
  input wire clk,
  input wire en_write,
  input wire [1:0] addr,
  input wire [7:0] in_data,
  output reg [7:0] out_data
);

  reg [7:0] mem [1:0];

  // Escreve na subida do clock
  always @(posedge clk) begin
      if (en_write) begin
          mem[addr] <= in_data; 
      end
  end

  // Lê o dado  na borda de descida do clock
  always @(negedge clk) begin
      out_data <= mem[addr];  
  end

endmodule

module test;
  reg clk, en_write;
  reg [1:0] addr;
  reg [7:0] in_data;
  wire [7:0] result;

  Mem2x8 mem_inst (clk, en_write, addr, in_data, result); 

  initial begin
      $display("Guia_1203.v - Ana Clara Lonczynski");
      $display("==================================");
      $display("Memory Test");

      $monitor ("%4d %4d %2d %8b | %8b", clk, en_write, addr, in_data, result);
      clk = 1'b1; en_write = 1'b1; addr = 2'b00; in_data = 8'b10010100; 

      // Teste de escrita e leitura
      #10 clk = 1'b0; en_write = 1'b1; addr = 2'b00; in_data = 8'bxxxxxxxx;  
      #10 clk = 1'b1; en_write = 1'b1; addr = 2'b01; in_data = 8'b11110000;  
      #10 clk = 1'b0; en_write = 1'b0; addr = 2'b01; in_data = 8'bxxxxxxxx;
      #10 clk = 1'b1;
      #10 clk = 1'b0; en_write = 1'b0; addr = 2'b00; in_data = 8'bxxxxxxxx; 
  end
endmodule
