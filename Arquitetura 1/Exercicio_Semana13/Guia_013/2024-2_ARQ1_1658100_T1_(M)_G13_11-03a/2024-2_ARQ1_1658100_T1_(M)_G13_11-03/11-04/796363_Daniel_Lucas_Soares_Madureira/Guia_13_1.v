// Módulo do flip-flop JK com entradas de preset e clear
module jkff (output reg q, output reg qnot,
             input j, input k,
             input clk, input preset, input clear);

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

// Módulo do contador assíncrono decrescente de 5 bits
module contador_5bits_decrescente(output [4:0] count, input clk, input clear);

   
    jkff jk1(count[0], , 1'b1, 1'b1, clk, 1'b0, clear);
    jkff jk2(count[1], , 1'b1, 1'b1, count[0], 1'b0, clear);
    jkff jk3(count[2], , 1'b1, 1'b1, count[1], 1'b0, clear);
    jkff jk4(count[3], , 1'b1, 1'b1, count[2], 1'b0, clear);
    jkff jk5(count[4], , 1'b1, 1'b1, count[3], 1'b0, clear);

endmodule 

// Testbench para simular o contador
module contador_5bit_decrescente_tb;
    reg clk = 0;
    reg clear = 0;
    wire [4:0] contador;

    contador_5bits_decrescente uut (contador, clk, clear);

 
    always #5 clk = ~clk;

    initial begin
        clear = 1; 
        #10;
        clear = 0; /
        #325;      
        $finish;  
    end

    initial begin
        $monitor("Time = %0t, Contador: %b", $time, contador);
    end
endmodule
