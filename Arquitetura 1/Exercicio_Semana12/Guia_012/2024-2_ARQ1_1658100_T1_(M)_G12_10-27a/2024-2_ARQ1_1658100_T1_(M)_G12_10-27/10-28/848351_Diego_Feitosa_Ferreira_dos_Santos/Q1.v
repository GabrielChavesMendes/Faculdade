module ram_1x4 (
    input wire clk,         
    input wire wr_en,       
    input wire [3:0] data_in,  
    output wire [3:0] data_out 
);
    
    
    wire [3:0] q;
    wire [3:0] j, k;     
    
    assign j[0] = wr_en & data_in[0];
    assign k[0] = wr_en & ~data_in[0];
    
    assign j[1] = wr_en & data_in[1];
    assign k[1] = wr_en & ~data_in[1];
    
    assign j[2] = wr_en & data_in[2];
    assign k[2] = wr_en & ~data_in[2];
    
    assign j[3] = wr_en & data_in[3];
    assign k[3] = wr_en & ~data_in[3];

   
    jk_ff ff0 (.clk(clk), .j(j[0]), .k(k[0]), .q(q[0]));
    jk_ff ff1 (.clk(clk), .j(j[1]), .k(k[1]), .q(q[1]));
    jk_ff ff2 (.clk(clk), .j(j[2]), .k(k[2]), .q(q[2]));
    jk_ff ff3 (.clk(clk), .j(j[3]), .k(k[3]), .q(q[3]));

 
    assign data_out = q;

endmodule


module jk_ff (
    input wire clk,
    input wire j,
    input wire k,
    output reg q
);
    always @(posedge clk) begin
        if (j == 1 && k == 0) q <= 1;   
        else if (j == 0 && k == 1) q <= 0; 
        else if (j == 1 && k == 1) q <= ~q; 
        
    end
endmodule
