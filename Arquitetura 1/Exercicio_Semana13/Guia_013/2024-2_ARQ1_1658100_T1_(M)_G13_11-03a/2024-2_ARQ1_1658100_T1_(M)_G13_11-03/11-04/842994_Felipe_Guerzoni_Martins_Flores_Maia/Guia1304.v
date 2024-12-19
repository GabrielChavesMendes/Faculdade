module decade_down_counter(output reg [3:0] count, input clk, input reset);
    always @(negedge clk or posedge reset) begin
        if (reset)
            count <= 4'b1001;
        else begin
            if (count == 4'b0000)
                count <= 4'b1001;
            else
                count <= count - 1;
        end
    end
endmodule