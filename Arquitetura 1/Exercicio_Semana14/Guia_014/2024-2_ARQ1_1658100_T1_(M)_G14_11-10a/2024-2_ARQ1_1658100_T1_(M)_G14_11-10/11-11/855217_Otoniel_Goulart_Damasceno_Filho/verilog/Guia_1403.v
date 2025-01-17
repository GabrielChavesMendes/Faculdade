// --------------------
//  Nome: Otoniel Goulart Damasceno Filho
// Matricula: 855217
// --------------------

module ring_shift_register (
    input wire clk,
    input wire ld,
    input wire data,
    output reg [4:0] q
);

    always @(posedge clk) begin
        if (ld) begin
            q[0] <= data;
        end else begin
            q[0] <= q[4];
        end
        q[1] <= q[0];
        q[2] <= q[1];
        q[3] <= q[2];
        q[4] <= q[3];
    end

endmodule
