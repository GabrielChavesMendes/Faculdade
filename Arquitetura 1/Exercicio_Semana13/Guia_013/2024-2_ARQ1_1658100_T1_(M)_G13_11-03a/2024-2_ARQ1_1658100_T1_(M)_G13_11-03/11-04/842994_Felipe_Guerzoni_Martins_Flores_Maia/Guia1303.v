module jk_flipflop(input clk, input reset, input J, input K, output reg Q);
    always @(negedge clk or posedge reset) begin
        if (reset)
            Q <= 1'b0;
        else if (J & K)
            Q <= ~Q;
    end
endmodule

module decade_counter(input clk, input reset, output [3:0] count);
    wire [3:0] Q;
    wire reset_count;

    assign reset_count = Q[3] & Q[1];

    jk_flipflop FF0(.clk(clk), .reset(reset | reset_count), .J(1'b1), .K(1'b1), .Q(Q[0]));
    jk_flipflop FF1(.clk(Q[0]), .reset(reset | reset_count), .J(1'b1), .K(1'b1), .Q(Q[1]));
    jk_flipflop FF2(.clk(Q[1]), .reset(reset | reset_count), .J(1'b1), .K(1'b1), .Q(Q[2]));
    jk_flipflop FF3(.clk(Q[2]), .reset(reset | reset_count), .J(1'b1), .K(1'b1), .Q(Q[3]));

    assign count = Q;
endmodule

module testbench;
    reg clk;
    reg reset;
    wire [3:0] count;

    decade_counter uut (.clk(clk), .reset(reset), .count(count));

    initial begin
        clk = 0;
        reset = 1;
        #5 reset = 0;

        #200 $finish;
    end

    always #5 clk = ~clk;

    initial begin
        $monitor("Time: %0t | Reset: %b | Count: %b", $time, reset, count);
    end
endmodule