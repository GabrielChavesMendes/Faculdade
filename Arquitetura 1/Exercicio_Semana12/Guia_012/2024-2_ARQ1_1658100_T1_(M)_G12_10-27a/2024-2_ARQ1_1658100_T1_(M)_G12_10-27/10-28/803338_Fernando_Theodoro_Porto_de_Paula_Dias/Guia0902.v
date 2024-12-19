
module Guia0902 (
    input clk,
    input rw,
    input addr,
    input [7:0] data_in,
    output [7:0] data_out
);

    wire [3:0] data_out_low, data_out_high;

    RAM_1x4 lower_half (
        .clk(clk),
        .rw(rw),
        .addr(addr),
        .data_in(data_in[3:0]),
        .data_out(data_out_low)
    );

    RAM_1x4 upper_half (
        .clk(clk),
        .rw(rw),
        .addr(addr),
        .data_in(data_in[7:4]),
        .data_out(data_out_high)
    );

    assign data_out = {data_out_high, data_out_low};

endmodule


module Testes;

    reg clk;
    reg rw;
    reg addr;
    reg [7:0] data_in;
    wire [7:0] data_out;

    Guia0902 ram (
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
        addr = 1'b1;

        // Teste 1:
        rw = 1'b1;
        data_in = 8'b10101010;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        // Teste 2:
        rw = 1'b1;
        data_in = 8'b11001100;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido: %b", data_out);

        $stop;
    end

endmodule
