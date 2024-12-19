module jk_flipflop(input clk, input reset, input J, input K, output reg Q);
    always @(negedge clk or posedge reset) begin
        if (reset)
            Q <= 1'b0; 
        else if (J == 1'b1 && K == 1'b1)
            Q <= ~Q;
    end
endmodule

module up_counter_5bit(input clk, input reset, output [4:0] count);
    wire [4:0] Q;

    jk_flipflop FF0(.clk(clk), .reset(reset), .J(1'b1), .K(1'b1), .Q(Q[0]));
    jk_flipflop FF1(.clk(Q[0]), .reset(reset), .J(1'b1), .K(1'b1), .Q(Q[1]));
    jk_flipflop FF2(.clk(Q[1]), .reset(reset), .J(1'b1), .K(1'b1), .Q(Q[2]));
    jk_flipflop FF3(.clk(Q[2]), .reset(reset), .J(1'b1), .K(1'b1), .Q(Q[3]));
    jk_flipflop FF4(.clk(Q[3]), .reset(reset), .J(1'b1), .K(1'b1), .Q(Q[4]));

    assign count = Q; 

endmodule

module testbench;
    reg clk;
    reg reset;
    wire [4:0] count;

    up_counter_5bit uut(.clk(clk), .reset(reset), .count(count));

    initial begin
        clk = 0;
        reset = 1;
        #5 reset = 0;

        forever #5 clk = ~clk;
    end

    initial begin
        $monitor("Time=%0d, count=%b", $time, count);
        #100 $finish;
    end
endmodule