module ring_shift_register_left (
    input wire clk,
    input wire rst,
    input wire load,
    input wire [4:0] D,
    output reg [4:0] Q
);

always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 5'b0;
    else if (load)
        Q <= D;
    else
        Q <= {Q[3:0], Q[4]};
end

endmodule
