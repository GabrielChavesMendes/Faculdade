module ram_2x8(
    input clk,
    input rst,
    input r_w,
    input addrs, // 1-bit address (0 or 1 for selection)
    input [7:0] data_in,
    output reg [7:0] data_out
);
    reg [7:0] memory [1:0]; // Memory array with 2 addresses of 8 bits each

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            memory[0] <= 8'b0;
            memory[1] <= 8'b0;
        end else if (r_w) begin
            memory[addrs] <= data_in; // Write data to selected address
        end
    end

    always @(negedge clk) begin
        if (!r_w) begin
            data_out <= memory[addrs]; // Read data from selected address
        end
    end
endmodule

module ram_4x8(
    input clk,
    input rst,
    input r_w,
    input [1:0] addrs, // 2-bit address (00 to 11)
    input [7:0] data_in,
    output [7:0] data_out
);
    wire [7:0] data_out0, data_out1;
    wire en0, en1;

    // Enable signals based on the most significant bit of the address
    assign en0 = (addrs[1] == 0) & r_w;
    assign en1 = (addrs[1] == 1) & r_w;

    // Instantiate two RAM 2x8 modules
    ram_2x8 ram0(
        .clk(clk),
        .rst(rst),
        .r_w(en0), // Enable write/read only when address MSB is 0
        .addrs(addrs[0]), // Use LSB as the address input for the RAM 2x8
        .data_in(data_in),
        .data_out(data_out0)
    );

    ram_2x8 ram1(
        .clk(clk),
        .rst(rst),
        .r_w(en1), // Enable write/read only when address MSB is 1
        .addrs(addrs[0]), // Use LSB as the address input for the RAM 2x8
        .data_in(data_in),
        .data_out(data_out1)
    );

    // Output multiplexer to select the correct data output based on the address MSB
    assign data_out = (addrs[1] == 0) ? data_out0 : data_out1;

endmodule

module ram_4x8_tb;
    // Signal declarations for the testbench
    reg clk;
    reg rst;
    reg r_w;
    reg [1:0] addrs;
    reg [7:0] data_in;
    wire [7:0] data_out;

    // Instantiate the RAM 4x8 module
    ram_4x8 dut (
        .clk(clk),
        .rst(rst),
        .r_w(r_w),
        .addrs(addrs),
        .data_in(data_in),
        .data_out(data_out)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 10 ns clock period
    end

    // Test procedure
    initial begin
        // Initialize signals
        rst = 1; r_w = 0; data_in = 8'b0; addrs = 2'b00;
        #10; // Wait for 10 ns

        rst = 0; // Release reset
        r_w = 1; // Set to write mode
        data_in = 8'b10101010; // Write value to address 00
        addrs = 2'b00;
        #10; // Wait for 10 ns

        r_w = 0; // Set to read mode
        #10; // Wait for 10 ns

        r_w = 1;
        data_in = 8'b11111111; // Write value to address 01
        addrs = 2'b01;
        #10; // Wait for 10 ns

        r_w = 0;
        #10; // Wait for 10 ns

        r_w = 1;
        data_in = 8'b00001111; // Write value to address 10
        addrs = 2'b10;
        #10; // Wait for 10 ns

        r_w = 0;
        #10; // Wait for 10 ns

        r_w = 1;
        data_in = 8'b11001100; // Write value to address 11
        addrs = 2'b11;
        #10; // Wait for 10 ns

        r_w = 0;
        #10; // Wait for 10 ns

        // Finish simulation
        $finish;
    end

    // Monitor signals
    initial begin
        $monitor("At time %t, Address = %b, Data Out = %b", $time, addrs, data_out);
    end
endmodule
