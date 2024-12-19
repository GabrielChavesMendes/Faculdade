module parallel_to_serial (
    input clk,
    input rst,
    input ld,
    input [5:0] parallel_data,
    output reg serial_out
);
    reg [5:0] shift_reg;
    always @(posedge clk or posedge rst) begin
        if (rst)
            shift_reg <= 6'b0;
        else if (ld)
            shift_reg <= parallel_data;
        else
            shift_reg <= {shift_reg[4:0], 1'b0};
    end
    always @(*) begin
        serial_out = shift_reg[5];
    end
endmodule

module tb_parallel_to_serial;
    reg clk, rst, ld;
    reg [5:0] parallel_data;
    wire serial_out;
    parallel_to_serial uut (.clk(clk), .rst(rst), .ld(ld), .parallel_data(parallel_data), .serial_out(serial_out));
    initial begin
        clk = 0; rst = 1; ld = 0; parallel_data = 6'b110011;
        #5 rst = 0; ld = 1;
        #10 ld = 0;
        #30 $stop;
    end
    always #5 clk = ~clk;
endmodule
