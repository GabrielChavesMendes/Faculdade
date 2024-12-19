module mod7_counter(output reg [2:0] count, input clk, input reset);
    always @(posedge clk or posedge reset) begin
        if (reset)
            count <= 3'b000;
        else if (count == 3'b110)
            count <= 3'b000;
        else
            count <= count + 1;
    end
endmodule