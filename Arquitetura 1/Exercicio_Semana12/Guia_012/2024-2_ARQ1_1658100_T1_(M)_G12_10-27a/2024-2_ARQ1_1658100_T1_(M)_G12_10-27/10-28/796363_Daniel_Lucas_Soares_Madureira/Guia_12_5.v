module ram_2x8(
    input clk,
    input rst,
    input r_w,
    input [1:0] addrs, // Endereço de 2 bits
    input [7:0] data_in,
    output reg [7:0] data_out
);

    reg [7:0] memory [0:1]; // Memória de 2x8 bits

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            memory[0] <= 8'b0;
            memory[1] <= 8'b0;
        end else if (r_w) begin
            memory[addrs] <= data_in;
        end
    end

    always @(negedge clk) begin
        if (!r_w) begin
            data_out <= memory[addrs];
        end
    end
endmodule

module ram_4x8(
    input clk,
    input rst,
    input r_w,
    input [1:0] addrs, // Endereço de 2 bits
    input addrs_sel,   // Bit para selecionar a RAM
    input [7:0] data_in,
    output [7:0] data_out
);

    wire [7:0] data_out0, data_out1;
    wire en0, en1;

    // Seleção de RAM com base em addrs_sel
    assign en0 = (addrs_sel == 0);
    assign en1 = (addrs_sel == 1);

    // Instâncias das duas RAMs 2x8
    ram_2x8 ram0(
        .clk(clk),
        .rst(rst),
        .r_w(r_w & en0),
        .addrs(addrs),
        .data_in(data_in),
        .data_out(data_out0)
    );

    ram_2x8 ram1(
        .clk(clk),
        .rst(rst),
        .r_w(r_w & en1),
        .addrs(addrs),
        .data_in(data_in),
        .data_out(data_out1)
    );

    // Seleção da saída com base em addrs_sel
    assign data_out = (addrs_sel == 0) ? data_out0 : data_out1;

endmodule
