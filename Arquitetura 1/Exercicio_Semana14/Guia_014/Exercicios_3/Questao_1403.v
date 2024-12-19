module ring_shift_register_right (
    input clk,
    input rst,
    input ld,
    input in_bit,
    output reg [5:0] out
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            out <= 6'b0;
        else if (ld)
            out <= {in_bit, out[5:1]};
        else
            out <= {out[0], out[5:1]};
    end
endmodule

module tb_ring_shift_register_right;
    reg clk, rst, ld, in_bit;
    wire [5:0] out;
    ring_shift_register_right uut (.clk(clk), .rst(rst), .ld(ld), .in_bit(in_bit), .out(out));
    initial begin
        clk = 0; rst = 1; ld = 0; in_bit = 1;
        #5 rst = 0; ld = 1;
        #10 ld = 0;
        #30 $stop;
    end
    always #5 clk = ~clk;
endmodule
