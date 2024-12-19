
module Guia0906 (
    input clk,
    input rw,
    input [1:0] addr,        
    input [15:0] data_in,
    output [15:0] data_out
);

    wire [7:0] data_out_low, data_out_high;
    reg [15:0] selected_out;

   
    RAM_4x8 mem_low (
        .clk(clk),
        .rw(rw),
        .addr(addr),
        .data_in(data_in[7:0]),
        .data_out(data_out_low)
    );

    RAM_4x8 mem_high (
        .clk(clk),
        .rw(rw),
        .addr(addr),
        .data_in(data_in[15:8]),
        .data_out(data_out_high)
    );

    
    always @(*) begin
        selected_out = {data_out_high, data_out_low};
    end

    assign data_out = selected_out;

endmodule


module Testes;

    reg clk;
    reg rw;
    reg [1:0] addr;
    reg [15:0] data_in;
    wire [15:0] data_out;

    RAM_4x16 ram (
        .clk(clk),
        .rw(rw),
        .addr(addr),
        .data_in(data_in),
        .data_out(data_out)
    );

    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    initial begin
        // Teste 1: 
        addr = 2'b00;
        rw = 1'b1;
        data_in = 16'b1111111111111111;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 2
        addr = 2'b01;
        rw = 1'b1;
        data_in = 16'b0000000000000000;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 3: 
        addr = 2'b10;
        rw = 1'b1;
        data_in = 16'b1010101010101010;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 4: 
        addr = 2'b11;
        rw = 1'b1;
        data_in = 16'b0101010101010101;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        $stop;
    end

endmodule
