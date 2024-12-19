module contador_decadico_decrescente (
    output [3:0] q,  
    input clk,       
    input rst        
);


    jk_ff ff0 (
        .q(q[0]),
        .j(1'b1),     
        .k(1'b1),     
        .clk(clk),
        .rst(rst || reset_cond)  
    );

    jk_ff ff1 (
        .q(q[1]),
        .j(1'b1),
        .k(1'b1),
        .clk(q[0]),
        .rst(rst || reset_cond)
    );

    jk_ff ff2 (
        .q(q[2]),
        .j(1'b1),
        .k(1'b1),
        .clk(q[1]),
        .rst(rst || reset_cond)
    );

    jk_ff ff3 (
        .q(q[3]),
        .j(1'b1),
        .k(1'b1),
        .clk(q[2]),
        .rst(rst || reset_cond)
    );

   
    wire reset_cond = (q == 4'b1111);

endmodule


module jk_ff (
    output reg q,
    input j, k, clk, rst
);
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            q <= 1'b1;   
        end
        else begin
            case ({j, k})
                2'b00: q <= q;      
                2'b01: q <= 1'b0;   
                2'b10: q <= 1'b1; 
                2'b11: q <= ~q;      
            endcase
        end
    end
endmodule
