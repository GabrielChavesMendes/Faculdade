module ring_counter(output reg [4:0] count, input clk,input reset);
    always @(posedge clk or posedge reset) begin
        if (reset)
            count <= 5'b00001; 
        else begin
            count <= {count[3:0], count[4]};
        end
    end
endmodule