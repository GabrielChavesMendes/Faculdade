module RAM_1x4 (
    input wire CLK,        // Clock
    input wire R_W,        // Read/Write control: 0 = Write, 1 = Read
    input wire ADDR,       // Address (single bit for 1x4)
    input wire CLR,        // Clear signal
    input wire [3:0] D_IN, // Data input (4 bits)
    output reg [3:0] D_OUT // Data output (4 bits)
);

    // Internal register to store 4-bit data
    reg [3:0] memory;

    // Asynchronous clear
    always @(posedge CLR) begin
        memory <= 4'b0000;
        D_OUT <= 4'b0000;
    end

    // Memory write operation on rising edge of clock
    always @(posedge CLK) begin
        if (!R_W && ADDR) begin // Write operation (R_W = 0)
            memory <= D_IN;
        end
    end

    // Memory read operation on falling edge of clock
    always @(negedge CLK) begin
        if (R_W && ADDR) begin // Read operation (R_W = 1)
            D_OUT <= memory;
        end else begin
            D_OUT <= 4'bx; // Output undefined if address not selected
        end
    end
endmodule
