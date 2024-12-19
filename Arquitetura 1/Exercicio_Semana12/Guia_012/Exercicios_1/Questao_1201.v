module RAM_1x4 (
    input wire CLK,         // Clock
    input wire R_W,         // Read/Write control: 1 = Write, 0 = Read
    input wire ADDR,        // Address select (1-bit)
    input wire [3:0] DATA_IN, // 4-bit input data
    input wire CLR,         // Clear signal
    output reg [3:0] DATA_OUT // 4-bit output data
);
    reg [3:0] memory; // Single address (1x4) storage

    // Escrita na borda de subida do clock ou limpeza
    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            memory <= 4'b0; // Clear memory
        end else if (R_W && ADDR) begin
            memory <= DATA_IN; // Write to memory
        end
    end

    // Leitura na borda de descida do clock
    always @(negedge CLK) begin
        if (!R_W && ADDR) begin
            DATA_OUT <= memory; // Read memory
        end else begin
            DATA_OUT <= 4'bx; // Output undefined if not reading
        end
    end
endmodule
