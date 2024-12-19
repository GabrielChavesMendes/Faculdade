module shift_register_left_load (
    input clk,
    input rst,
    input ld,
    input [5:0] load_val,
    output reg [5:0] out
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            out <= 6'b0;
        else if (ld)
            out <= load_val;
        else
            out <= {out[4:0], 1'b0};
    end
endmodule

module tb_shift_register_left_load;
    reg clk, rst, ld;
    reg [5:0] load_val;
    wire [5:0] out;
    shift_register_left_load uut (.clk(clk), .rst(rst), .ld(ld), .load_val(load_val), .out(out));
    initial begin
        clk = 0; rst = 1; ld = 0; load_val = 6'b101010;
        #5 rst = 0; ld = 1;
        #10 ld = 0;
        #30 $stop;
    end
    always #5 clk = ~clk;
endmodule
