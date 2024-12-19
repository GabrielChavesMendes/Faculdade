module twisted_ring_shift_register (
    input wire clk,
    input wire rst,
    input wire LD,
    input wire D,
    output reg [5:0] Q
);

always @(posedge clk or posedge rst) begin
    if (rst)
        Q <= 6'b0;
    else if (LD)
        Q <= {D, Q[5:1]};
    else
        Q <= {Q[4:0], ~Q[5]};
end

endmodule
