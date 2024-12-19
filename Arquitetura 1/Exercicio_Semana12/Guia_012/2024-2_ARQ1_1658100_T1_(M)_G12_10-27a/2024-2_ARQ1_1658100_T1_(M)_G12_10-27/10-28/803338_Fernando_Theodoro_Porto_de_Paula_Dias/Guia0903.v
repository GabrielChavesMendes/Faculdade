// Módulo RAM 2x8
module Guia0903 (
    input clk,
    input rw,
    input [1:0] addr,
    input [7:0] data_in,
    output [7:0] data_out
);

    wire [7:0] data_out0, data_out1;
    reg [7:0] selected_out;

    RAM_1x8 mem0 (
        .clk(clk),
        .rw(rw & (addr == 2'b00)),
        .addr(1'b1),
        .data_in(data_in),
        .data_out(data_out0)
    );

    RAM_1x8 mem1 (
        .clk(clk),
        .rw(rw & (addr == 2'b01)),
        .addr(1'b1),
        .data_in(data_in),
        .data_out(data_out1)
    );

    always @(*) begin
        case (addr)
            2'b00: selected_out = data_out0;
            2'b01: selected_out = data_out1;
            default: selected_out = 8'bx;
        endcase
    end

    assign data_out = selected_out;

endmodule


module Testes;

    reg clk;
    reg rw;
    reg [1:0] addr;
    reg [7:0] data_in;
    wire [7:0] data_out;

    Guia0903 ram (
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
        data_in = 8'b10101010;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido: %b", data_out);

        // Teste 2: E
        addr = 2'b01;
        rw = 1'b1;
        data_in = 8'b11001100;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido: %b", data_out);

        $stop;
    end

endmodule
