module twisted_ring_counter(output reg [4:0] count, input clk, input rese);
    wire jk_input;
    assign jk_input = ~count[4];

    always @(posedge clk or posedge reset) begin
        if (reset)
            count <= 5'b00000; 
        else begin
            count[0] <= jk_input; 
            count[1] <= count[0];
            count[2] <= count[1];
            count[3] <= count[2];
            count[4] <= count[3];
        end
    end
endmodule