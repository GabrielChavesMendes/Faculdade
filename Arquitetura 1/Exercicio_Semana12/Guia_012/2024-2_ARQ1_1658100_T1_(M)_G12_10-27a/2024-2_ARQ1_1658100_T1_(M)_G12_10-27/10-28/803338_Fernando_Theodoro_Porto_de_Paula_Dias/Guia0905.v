
module Guia0905 (
    input clk,
    input rw,
    input [2:0] addr,      
    input [7:0] data_in,
    output [7:0] data_out
);

    wire [7:0] data_out0, data_out1;
    reg [7:0] selected_out;

    
    RAM_4x8 mem0 (
        .clk(clk),
        .rw(rw & (addr[2] == 1'b0)), 
        .addr(addr[1:0]),
        .data_in(data_in),
        .data_out(data_out0)
    );

    RAM_4x8 mem1 (
        .clk(clk),
        .rw(rw & (addr[2] == 1'b1)),  
        .addr(addr[1:0]),
        .data_in(data_in),
        .data_out(data_out1)
    );

    always @(*) begin
        case (addr[2])
            1'b0: selected_out = data_out0;
            1'b1: selected_out = data_out1;
            default: selected_out = 8'bx;
        endcase
    end

    assign data_out = selected_out;

endmodule


module Testes;

    reg clk;
    reg rw;
    reg [2:0] addr;
    reg [7:0] data_in;
    wire [7:0] data_out;

    RAM_8x8 ram (
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
        data_in = 8'b11111111;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 2: 
        addr = 3'b100;
        rw = 1'b1;
        data_in = 8'b00000000;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido: %b", data_out);

        // Teste 3: 
        addr = 3'b011;
        rw = 1'b1;
        data_in = 8'b10101010;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 4: 
        addr = 3'b111;
        rw = 1'b1;
        data_in = 8'b01010101;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        $stop;
    end

endmodule
