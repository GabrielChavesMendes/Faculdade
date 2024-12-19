module ram_8x8 (input wire clk, input wire wr_en, input wire [2:0] addr, input wire [7:0] in, output wire [7:0] out);
    wire [7:0] out0, out1;

    wire wr_en0 = wr_en & ~addr[2]; 
    wire wr_en1 = wr_en & addr[2];  

    ram_4x8 ram1 (.clk(clk), .wr_en(wr_en1),.addr(addr[1:0]), .in(in), .out(out1));
    ram_4x8 ram2 (.clk(clk), .wr_en(wr_en1),.addr(addr[1:0]), .in(in), .out(out1));

    assign out = addr[2] ? out1 : out0;
endmodule


module ram_4x8 (input wire clk, input wire wr_en, input wire [1:0] addr, input wire [7:0] in, output wire [7:0] out);
    wire [7:0] out0, out1;

    wire wr_en0 = wr_en & ~addr[1]; 
    wire wr_en1 = wr_en & addr[1];  

    ram_2x8 ram0 (.clk(clk), .wr_en(wr_en0), .addr(addr[0]), .in(in), .out(out0));
    ram_2x8 ram1 (.clk(clk), .wr_en(wr_en1), .addr(addr[0]), .in(in), .out(out1));

    assign out = addr[1] ? out1 : out0;
endmodule

module ram_2x8 (input wire clk, input wire wr_en, input wire addr, input wire [7:0] in, output wire [7:0] out);
    wire [7:0] out0, out1;
    wire wr_en0 = wr_en & ~addr;
    wire wr_en1 = wr_en & addr;

    ram_1x8 ram0 (.clk(clk), .wr_en(wr_en0), .in(in), .out(out0));
    ram_1x8 ram1 (.clk(clk), .wr_en(wr_en1), .in(in), .out(out1));

    assign out = addr ? out1 : out0;
endmodule

module ram_1x8 (input wire clk, input wire wr_en, input wire [7:0] in, output reg [7:0] out);
    reg [7:0] mem;

    always @(posedge clk) begin
        if (wr_en) begin
            mem <= in;
        end
        out <= mem;
    end
endmodule
