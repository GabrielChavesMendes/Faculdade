module RAM_2x8 (
    input wire CLK,
    input wire R_W,
    input wire ADDR,
    input wire [7:0] DATA_IN,
    input wire CLR,
    output reg [7:0] DATA_OUT
);
    reg [7:0] memory [1:0]; // 2 endereços para 8 bits cada

    always @(posedge CLK or posedge CLR) begin
        if (CLR) begin
            memory[0] <= 8'b0;
            memory[1] <= 8'b0;
        end else if (R_W) begin
            memory[ADDR] <= DATA_IN; // Escrever no endereço
        end
    end

    always @(*) begin
        if (!R_W) begin
            DATA_OUT = memory[ADDR]; // Ler do endereço
        end else begin
            DATA_OUT = 8'bx;
        end
    end
endmodule

module RAM_4x8 (
    input wire CLK,
    input wire R_W,
    input wire [1:0] ADDR,
    input wire [7:0] DATA_IN,
    input wire CLR,
    output wire [7:0] DATA_OUT
);
    wire [7:0] ram0_out, ram1_out;
    wire sel_ram0, sel_ram1;

    // Seleção das memórias
    assign sel_ram0 = (ADDR[1] == 0); // Memória RAM0
    assign sel_ram1 = (ADDR[1] == 1); // Memória RAM1

    // Instâncias de RAM_2x8
    RAM_2x8 ram0 (
        .CLK(CLK),
        .R_W(R_W & sel_ram0),
        .ADDR(ADDR[0]),
        .DATA_IN(DATA_IN),
        .CLR(CLR),
        .DATA_OUT(ram0_out)
    );

    RAM_2x8 ram1 (
        .CLK(CLK),
        .R_W(R_W & sel_ram1),
        .ADDR(ADDR[0]),
        .DATA_IN(DATA_IN),
        .CLR(CLR),
        .DATA_OUT(ram1_out)
    );

    // Multiplexador para selecionar a saída
    assign DATA_OUT = sel_ram0 ? ram0_out : ram1_out;
endmodule
