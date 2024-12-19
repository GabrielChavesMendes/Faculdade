module RAM_1x8 (
    input wire CLK,
    input wire R_W,
    input wire ADDR,
    input wire [7:0] DATA_IN,
    input wire CLR,
    output reg [7:0] DATA_OUT
);
    reg [7:0] memory;

    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            memory <= 8'b0;
        end else if (R_W && ADDR) begin
            memory <= DATA_IN;
        end
    end

    always @(negedge CLK) begin
        if (!R_W && ADDR) begin
            DATA_OUT <= memory;
        end else begin
            DATA_OUT <= 8'bx;
        end
    end
endmodule


module RAM_2x8 (
    input wire CLK,            // Clock
    input wire R_W,            // Read/Write control: 1 = Write, 0 = Read
    input wire ADDR,           // Address select (1-bit: 0 or 1)
    input wire [7:0] DATA_IN,  // 8-bit input data
    input wire CLR,            // Clear signal
    output wire [7:0] DATA_OUT // 8-bit output data
);
    wire [7:0] ram0_out, ram1_out; // Outputs for each RAM_1x8 instance
    wire sel_ram0, sel_ram1;       // Selection signals for the two RAMs

    // Selection logic
    assign sel_ram0 = (ADDR == 0); // Enable RAM 0 when ADDR is 0
    assign sel_ram1 = (ADDR == 1); // Enable RAM 1 when ADDR is 1

    // Instance of RAM_1x8 for Address 0
    RAM_1x8 ram0 (
        .CLK(CLK),
        .R_W(R_W & sel_ram0),    // Activate only when ADDR is 0
        .ADDR(sel_ram0),         // Address is always selected (1)
        .DATA_IN(DATA_IN),
        .CLR(CLR),
        .DATA_OUT(ram0_out)
    );

    // Instance of RAM_1x8 for Address 1
    RAM_1x8 ram1 (
        .CLK(CLK),
        .R_W(R_W & sel_ram1),    // Activate only when ADDR is 1
        .ADDR(sel_ram1),         // Address is always selected (1)
        .DATA_IN(DATA_IN),
        .CLR(CLR),
        .DATA_OUT(ram1_out)
    );

    // Multiplex output based on ADDR
    assign DATA_OUT = (ADDR == 0) ? ram0_out : ram1_out;

endmodule
