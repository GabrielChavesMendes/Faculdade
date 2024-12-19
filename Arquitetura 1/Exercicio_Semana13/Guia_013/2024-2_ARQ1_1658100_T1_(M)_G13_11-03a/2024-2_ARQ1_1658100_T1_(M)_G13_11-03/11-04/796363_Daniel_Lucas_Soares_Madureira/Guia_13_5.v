// Módulo do flip-flop tipo T
module tff (output reg q, output reg qnot, input t, input clk, input preset, input clear);
    always @(posedge clk or negedge preset or negedge clear) begin
        if (!clear) begin
            q <= 0;
            qnot <= 1;
        end else if (!preset) begin
            q <= 1;
            qnot <= 0;
        end else if (t) begin
            q <= ~q;
            qnot <= ~qnot;
        end
    end
endmodule 

// Módulo do contador síncrono módulo 7
module contador_sincrono_modulo7(output [2:0] contador, input clk, input clear);

    // O contador reinicia quando o valor 7 (111) for atingido
    reg clr = 1'b0;

    always @(posedge clk) begin
        if (contador[2] & contador[1] & contador[0]) begin
            clr <= 1'b1; 
        end else begin
            clr <= clear; 
        end
    end

    tff t1(contador[0], , 1'b1, clk, 1'b0, clr);
    tff t2(contador[1], , contador[0], clk, 1'b0, clr);
    tff t3(contador[2], , contador[0] & contador[1], clk, 1'b0, clr);

endmodule 

module tb;

    reg clk = 0;
    reg clear = 1;
    wire [2:0] contador;

    contador_sincrono_modulo7 uut (contador, clk, clear);

    
    always #5 clk = ~clk;

    initial begin
        #10;
        clear = 0; 
        #250;      
        $finish;
    end

    initial begin
        $monitor("Time = %0t, contador = %b", $time, contador);
    end
endmodule
