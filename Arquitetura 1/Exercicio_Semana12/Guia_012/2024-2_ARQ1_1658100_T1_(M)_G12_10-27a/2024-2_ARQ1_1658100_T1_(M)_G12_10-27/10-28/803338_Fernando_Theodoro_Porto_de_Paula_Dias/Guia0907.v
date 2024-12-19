
module Guia0907 (
    input clk,
    input rw,
    input [2:0] addr,        
    input [15:0] data_in,
    output [15:0] data_out
);

 
    wire [15:0] data_out_array [7:0];
    reg [15:0] selected_out;

    
    RAM_1x16 mem0 (.clk(clk), .rw(rw & (addr == 3'b000)), .data_in(data_in), .data_out(data_out_array[0]));
    RAM_1x16 mem1 (.clk(clk), .rw(rw & (addr == 3'b001)), .data_in(data_in), .data_out(data_out_array[1]));
    RAM_1x16 mem2 (.clk(clk), .rw(rw & (addr == 3'b010)), .data_in(data_in), .data_out(data_out_array[2]));
    RAM_1x16 mem3 (.clk(clk), .rw(rw & (addr == 3'b011)), .data_in(data_in), .data_out(data_out_array[3]));
    RAM_1x16 mem4 (.clk(clk), .rw(rw & (addr == 3'b100)), .data_in(data_in), .data_out(data_out_array[4]));
    RAM_1x16 mem5 (.clk(clk), .rw(rw & (addr == 3'b101)), .data_in(data_in), .data_out(data_out_array[5]));
    RAM_1x16 mem6 (.clk(clk), .rw(rw & (addr == 3'b110)), .data_in(data_in), .data_out(data_out_array[6]));
    RAM_1x16 mem7 (.clk(clk), .rw(rw & (addr == 3'b111)), .data_in(data_in), .data_out(data_out_array[7]));

    
    always @(*) begin
        selected_out = data_out_array[addr];
    end

    assign data_out = selected_out;

endmodule


module Testes;

    reg clk;
    reg rw;
    reg [2:0] addr;
    reg [15:0] data_in;
    wire [15:0] data_out;

    RAM_8x16 ram (
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
        addr = 3'b000;
        rw = 1'b1;
        data_in = 16'b1111111111111111;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 2: 
        addr = 3'b100;
        rw = 1'b1;
        data_in = 16'b0000000000000000;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 3: 
        addr = 3'b011;
        rw = 1'b1;
        data_in = 16'b1010101010101010;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 4: 
        addr = 3'b111;
        rw = 1'b1;
        data_in = 16'b0101010101010101;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido: %b", data_out);

        $stop;
    end

endmodule
