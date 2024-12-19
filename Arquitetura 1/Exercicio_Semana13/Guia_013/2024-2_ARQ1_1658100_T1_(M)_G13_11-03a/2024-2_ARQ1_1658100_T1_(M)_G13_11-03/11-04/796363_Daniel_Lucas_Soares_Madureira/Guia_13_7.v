// Módulo do flip-flop tipo JK
module jkff (output reg q, output reg qnot, input j, input k, input clk, input preset, input clear);
    always @(posedge clk or posedge preset or posedge clear) begin
        if (clear) begin
            q <= 0;
            qnot <= 1;
        end else if (preset) begin
            q <= 1;
            qnot <= 0;
        end else if (j & ~k) begin
            q <= 1;
            qnot <= 0;
        end else if (~j & k) begin
            q <= 0;
            qnot <= 1;
        end else if (j & k) begin
            q <= ~q;
            qnot <= ~qnot;
        end
    end
endmodule 

module contador_anel_torcido_5bits(output [4:0] count, input clk, input clear);
    jkff jk1(count[0], , count[4], ~count[4], clk, 1'b0, clear);
    jkff jk2(count[1], , count[0], ~count[0], clk, 1'b0, clear);
    jkff jk3(count[2], , count[1], ~count[1], clk, 1'b0, clear);
    jkff jk4(count[3], , count[2], ~count[2], clk, 1'b0, clear);
    jkff jk5(count[4], , ~count[3], count[3], clk, 1'b0, clear); 

endmodule 

module tb;

    reg clk = 0;
    reg clear = 1;
    wire [4:0] count;

    contador_anel_torcido_5bits uut (count, clk, clear);

    always #5 clk = ~clk;

    initial begin
        #10 clear = 0; 
        #200;          
        $finish;
    end

    initial begin
        $monitor("Time = %0t, count = %b", $time, count);
    end
endmodule
