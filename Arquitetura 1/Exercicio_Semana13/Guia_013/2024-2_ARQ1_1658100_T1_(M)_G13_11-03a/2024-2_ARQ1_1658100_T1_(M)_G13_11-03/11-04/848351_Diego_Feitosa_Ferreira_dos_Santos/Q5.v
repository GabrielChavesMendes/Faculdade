module contador_mod7 (
    output [2:0] q,  
    input clk,       
    input rst        
);

 
    t_ff ff0 (
        .q(q[0]),
        .t(1'b1),    
        .clk(clk),
        .rst(rst)
    );

    
    t_ff ff1 (
        .q(q[1]),
        .t(q[0]),
        .clk(clk),
        .rst(rst)
    );

  
    t_ff ff2 (
        .q(q[2]),
        .t(q[0] & q[1]),
        .clk(clk),
        .rst(rst)
    );

    
    assign reset_cond = (q == 3'b111);

endmodule


module t_ff (
    output reg q,
    input t, clk, rst
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 1'b0;   
        end
        else if (t) begin
            q <= ~q;     
        end
    end
endmodule
