module parallel_to_serial (
    input wire clk,
    input wire rst,
    input wire load,
    input wire [5:0] parallel_in,
    output reg serial_out
);

reg [5:0] shift_reg;
reg [2:0] count;

always @(posedge clk or posedge rst) begin
    if (rst) begin
        shift_reg <= 6'b0;
        count <= 3'b0;
        serial_out <= 1'b0;
    end else if (load) begin
        shift_reg <= parallel_in;
        count <= 3'b101; // Inicia o contador em 5 
    end else if (count > 0) begin
        serial_out <= shift_reg[0];
        shift_reg <= shift_reg >> 1;
        count <= count - 1;
    end
end

endmodule
