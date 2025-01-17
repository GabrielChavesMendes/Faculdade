// --------------------
//  Nome: Otoniel Goulart Damasceno Filho
// Matricula: 855217
// --------------------

module shift_register (
    input wire clk,
    input wire ld,
    input wire data,
    output reg [4:0] q
);

    always @(posedge clk) begin
        if (ld) begin
            q[0] <= data;
        end else begin
            q[0] <= q[1];
        end
        q[1] <= q[2];
        q[2] <= q[3];
        q[3] <= q[4];
        q[4] <= 0; // Assuming the leftmost bit is shifted out as 0
    end

endmodule
