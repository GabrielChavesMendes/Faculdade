module twisted_ring_shift_register_right (
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
        Q <= {~Q[0], Q[4:1]};
end

endmodule
