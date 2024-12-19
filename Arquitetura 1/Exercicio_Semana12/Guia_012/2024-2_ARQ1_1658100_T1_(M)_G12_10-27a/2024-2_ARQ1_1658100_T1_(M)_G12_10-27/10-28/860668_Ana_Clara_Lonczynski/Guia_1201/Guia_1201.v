
// Ana Clara Lonczynski - 680688
// Guia_1201.v

module RAM_1x4(
    input wire clk,
    input wire write_en,
    input wire address,
    input wire [3:0] data_in,
    output reg [3:0] data_out
);

reg [3:0] memory [0:0]; 

always @(posedge clk) begin
    if (write_en) begin
        memory[0] <= data_in; 
    end
end

always @(negedge clk) begin
    data_out <= memory[0];  
end

endmodule

module test;
    reg clk, write_en, address;
    reg [3:0] data_in;
    wire [3:0] s;

    RAM_1x4 moduleRam (clk, write_en, address, data_in, s);  

    initial begin
      $display("Guia_1212.v - Ana Clara Lonczynski");
      $display("==================================");
        $display("Test Module");

        $monitor ("%4d %4d %4d %4d | %4d", clk, write_en, address, data_in, s);
        clk = 1;
        write_en = 1;
        address = 1;
        data_in = 4'b0100;  

        #10 clk = 0; write_en = 1; address = 0; data_in = 4'b0100; 
        #10 clk = 1; write_en = 1; address = 1; data_in = 4'b0000;  
        #10 clk = 0;  


    end
endmodule