module ram_1x4(
    input clk,        // Clock signal
    input rst,        // Reset signal
    input r_w,        // Read/Write control signal, 0 for read and 1 for write
    input [3:0] data_in,  // 4-bit data input
    output [3:0] data_out // 4-bit data output
);

    // Memória implementada com registradores simples de 4 bits
    reg [3:0] memory;

    // Lógica de escrita na memória
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            memory <= 4'b0000; // Resetar o conteúdo da memória
        end else if (r_w) begin
            memory <= data_in; // Escrever na memória
        end
    end

    // Lógica de leitura da memória
    assign data_out = (r_w == 0) ? memory : 4'bz; // Se for leitura, retornar o valor armazenado

endmodule

module ram_1x8(
    input clk,
    input rst,
    input r_w,
    input [7:0] data_in,
    output [7:0] data_out
);

    wire [3:0] data_out_lower;
    wire [3:0] data_out_upper;

    // Instancia a memória RAM de 1x4 para os bits menos significativos (LSB)
    ram_1x4 ram_lower(
        .clk(clk),
        .rst(rst),
        .r_w(r_w),
        .data_in(data_in[3:0]),
        .data_out(data_out_lower)
    );

    // Instancia a memória RAM de 1x4 para os bits mais significativos (MSB)
    ram_1x4 ram_upper(
        .clk(clk),
        .rst(rst),
        .r_w(r_w),
        .data_in(data_in[7:4]),
        .data_out(data_out_upper)
    );

    // Combina as saídas dos módulos ram_1x4
    assign data_out = {data_out_upper, data_out_lower};

endmodule

// Testbench para testar a memória RAM 1x8
module ram_1x8_tb;

    reg clk;
    reg rst;
    reg r_w;
    reg [7:0] data_in;
    wire [7:0] data_out;

    // Instancia o módulo RAM 1x8
    ram_1x8 uut (
        .clk(clk),
        .rst(rst),
        .r_w(r_w),
        .data_in(data_in),
        .data_out(data_out)
    );

    // Geração do sinal de clock
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end

    // Testes para verificar a funcionalidade da RAM 1x8
    initial begin
        // Inicializa os sinais
        rst = 1; r_w = 0; data_in = 8'b00000000;
        #10; // Espera 10 unidades de tempo

        rst = 0; // Desativa o reset
        r_w = 1; // Modo de escrita
        data_in = 8'b10101010; // Dados a serem escritos
        #10; // Aguarda um ciclo de clock

        r_w = 0; // Modo de leitura
        #10; // Aguarda um ciclo de clock

        r_w = 1;
        data_in = 8'b11111111;
        #10;

        r_w = 0;
        #10;

        $finish;
    end

    // Monitoramento dos sinais para verificar o funcionamento
    initial begin
        $monitor("Tempo = %0t, data_out = %b", $time, data_out);
    end

endmodule
