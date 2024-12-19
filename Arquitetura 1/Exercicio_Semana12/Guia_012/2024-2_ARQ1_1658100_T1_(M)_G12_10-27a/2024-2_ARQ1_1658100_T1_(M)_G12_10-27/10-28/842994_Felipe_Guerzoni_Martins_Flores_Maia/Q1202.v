module ram_1x8 (input wire clk, input wire wr_en, input wire [7:0] in, output wire [7:0] out);
    wire [3:0] in_high = in[7:4];
    wire [3:0] in_low = in[3:0];
    wire [3:0] out_high, out_low;

    ram_1x4 ram_high (.clk(clk), .wr_en(wr_en), .in(in_high), .out(out_high));
    ram_1x4 ram_low (.clk(clk), .wr_en(wr_en), .in(in_low), .out(out_low));

    assign out = {out_high, out_low};
endmodule

module ram_1x4 (input wire clk, input wire wr_en, input wire [3:0] in, output reg [3:0] out);
    reg [3:0] mem; 

    always @(posedge clk) begin
        if (wr_en) begin
            mem <= in; 
        end
        out <= mem; 
    end
endmodule
