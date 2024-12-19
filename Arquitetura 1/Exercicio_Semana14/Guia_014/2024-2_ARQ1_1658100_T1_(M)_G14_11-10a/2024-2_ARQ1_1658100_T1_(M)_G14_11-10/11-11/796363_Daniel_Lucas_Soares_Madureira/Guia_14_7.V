module dff (
    output reg q,       
    input d,           
    input clk,         
    input preset,      
    input clear       
);

    always @(posedge clk or posedge clear) begin
        if (clear)     
            q <= 0;
        else if (preset) 
            q <= 1;
        else            
            q <= d;
    end
endmodule

module right_twisted_ring (
    output [4:0] number, 
    input load,         
    input clk,           
    input clr           
);

    // Instanciação dos flip-flops com deslocamento circular para a direita em anel torcido
    dff d0 (number[0], ~number[4], clk, load, clr);
    dff d1 (number[1], number[0], clk, load, clr);
    dff d2 (number[2], number[1], clk, load, clr);
    dff d3 (number[3], number[2], clk, load, clr);
    dff d4 (number[4], number[3], clk, load, clr);

endmodule
