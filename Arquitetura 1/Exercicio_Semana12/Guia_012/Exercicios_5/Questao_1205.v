module RAM_4x8 (
    input wire CLK,                 // Clock
    input wire R_W,                 // Read/Write control: 1 = Write, 0 = Read
    input wire [1:0] ADDR,          // 2-bit Address (4 endereços)
    input wire [7:0] DATA_IN,       // 8-bit Input Data
    input wire CLR,                 // Clear signal
    output reg [7:0] DATA_OUT       // 8-bit Output Data
);
    reg [7:0] memory [3:0];         // Memória de 4 endereços com 8 bits cada

    // Operações de leitura e escrita
    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            memory[0] <= 8'b0;
            memory[1] <= 8'b0;
            memory[2] <= 8'b0;
            memory[3] <= 8'b0;
        end else if (R_W) begin
            memory[ADDR] <= DATA_IN; // Escrita
        end
    end

    // Leitura síncrona
    always @(posedge CLK) begin
        if (!R_W) begin
            DATA_OUT <= memory[ADDR]; // Leitura
        end
    end
endmodule


module RAM_8x8 (
    input wire CLK,                 // Clock
    input wire R_W,                 // Read/Write control: 1 = Write, 0 = Read
    input wire [2:0] ADDR,          // 3-bit Address (8 endereços)
    input wire [7:0] DATA_IN,       // 8-bit Input Data
    input wire CLR,                 // Clear signal
    output wire [7:0] DATA_OUT      // 8-bit Output Data
);
    wire [7:0] ram0_out, ram1_out;  // Saídas das RAMs 4x8
    wire sel_ram0, sel_ram1;        // Sinais de seleção das RAMs 4x8

    // Dividir o endereço para selecionar a RAM correta
    assign sel_ram0 = (ADDR[2] == 0); // RAM_4x8 para os endereços 0 a 3
    assign sel_ram1 = (ADDR[2] == 1); // RAM_4x8 para os endereços 4 a 7

    // Instância da primeira RAM_4x8 (endereços 0 a 3)
    RAM_4x8 ram0 (
        .CLK(CLK),
        .R_W(R_W & sel_ram0),       // Habilitar escrita apenas quando sel_ram0 for 1
        .ADDR(ADDR[1:0]),           // Endereço de 2 bits para RAM_4x8
        .DATA_IN(DATA_IN),
        .CLR(CLR),
        .DATA_OUT(ram0_out)
    );

    // Instância da segunda RAM_4x8 (endereços 4 a 7)
    RAM_4x8 ram1 (
        .CLK(CLK),
        .R_W(R_W & sel_ram1),       // Habilitar escrita apenas quando sel_ram1 for 1
        .ADDR(ADDR[1:0]),           // Endereço de 2 bits para RAM_4x8
        .DATA_IN(DATA_IN),
        .CLR(CLR),
        .DATA_OUT(ram1_out)
    );

    // Multiplexador para selecionar a saída correta
    assign DATA_OUT = sel_ram0 ? ram0_out : ram1_out;

endmodule
