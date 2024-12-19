module shift_register (
    input wire clk,
    input wire rst,
    input wire LD,
    input wire [5:0] D,
    output reg [5:0] Q
);

always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 6'b0;
    else if (LD)
        Q <= D;
    else
        Q <= {Q[4:0], 1'b0};
end

endmodule
