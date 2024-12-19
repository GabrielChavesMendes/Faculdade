
module Guia0901 (
    input clk,
    input rw,         
    input addr,       
    input [3:0] data_in,
    output reg [3:0] data_out
);

    reg [3:0] mem;    

    always @(posedge clk) begin
        if (rw && addr) 
            mem <= data_in;
    end

    always @(negedge clk) begin
        if (!rw && addr) 
            data_out <= mem;
    end

endmodule


module Testes;

    reg clk;
    reg rw;
    reg addr;
    reg [3:0] data_in;
    wire [3:0] data_out;

    
    Guia0901 ram (
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
        
        // Teste 1
        rw = 1'b1;
        data_in = 4'b1010;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido: %b", data_out);

        // Teste 2
        rw = 1'b1;
        data_in = 4'b1100;
        #10;
        rw = 1'b0;
        #10;
        $display("Dado lido : %b", data_out);

        $stop;
    end

endmodule
