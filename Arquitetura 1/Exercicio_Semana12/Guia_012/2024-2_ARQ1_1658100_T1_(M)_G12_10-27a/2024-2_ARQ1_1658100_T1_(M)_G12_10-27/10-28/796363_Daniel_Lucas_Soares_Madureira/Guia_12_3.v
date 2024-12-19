module ram_1x8(
    input clk,          // Sinal de clock
    input rst,          // Sinal de reset
    input r_w,          // Sinal de controle de leitura/escrita, 0 para leitura e 1 para escrita
    input [7:0] data_in, // Entrada de dados de 8 bits
    output reg [7:0] data_out // Saída de dados de 8 bits
);

    reg [7:0] memory; // Registrador de 8 bits para armazenar os dados

    // Código para escrever na memória se r_w == 1 e clk estiver na borda de subida
    always @(posedge clk or posedge rst) begin
        if (rst) begin
            memory <= 8'b0;
        end else if (r_w) begin
            memory <= data_in;
        end
    end

    // Código para ler da memória se r_w == 0 e clk estiver na borda de descida
    always @(negedge clk) begin
        if (!r_w) begin
            data_out <= memory;
        end else begin
            data_out <= 8'bx;
        end
    end

endmodule

module ram_2x8(
    input clk,
    input rst,
    input r_w,
    input addrs, // Sinal de endereço de 1 bit
    input [7:0] data_in,
    output [7:0] data_out
);

    wire [7:0] data_out0, data_out1;

    // Instância das duas memórias RAM 1x8
    ram_1x8 ram0(
        .clk(clk),
        .rst(rst),
        .r_w(r_w & ~addrs), // Ativa escrita/leitura apenas quando addrs é 0
        .data_in(data_in),
        .data_out(data_out0)
    );

    ram_1x8 ram1(
        .clk(clk),
        .rst(rst),
        .r_w(r_w & addrs), // Ativa escrita/leitura apenas quando addrs é 1
        .data_in(data_in),
        .data_out(data_out1)
    );

    // Seleção da saída de dados com base no endereço
    assign data_out = addrs ? data_out1 : data_out0;

endmodule

module ram_2x8_tb;

    // Declaração de sinais para conectar ao módulo de RAM.
    reg clk;
    reg rst;
    reg r_w;
    reg addrs;
    reg [7:0] data_in;
    wire [7:0] data_out;

    // Instância do módulo de RAM 2x8
    ram_2x8 memoria (
        .clk(clk),
        .rst(rst),
        .r_w(r_w),
        .addrs(addrs),
        .data_in(data_in),
        .data_out(data_out)
    );

    // Geração do sinal de clock.
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // Gera um clock com período de 10 unidades de tempo
    end

    // Procedimento de teste.
    initial begin
        // Inicializa os sinais.
        rst = 1; r_w = 0; data_in = 8'b0; addrs = 0;
        #10; // Aguarda por 10 unidades de tempo.

        rst = 0; // Desativa o reset.
        r_w = 1; // Modo de escrita.
        data_in = 8'b10101010; // Valor a ser escrito na memória.
        addrs = 0;
        #10; // Aguarda um ciclo de clock.

        r_w = 0; // Modo de leitura.
        #10; // Aguarda um ciclo de clock.

        r_w = 1; // Modo de escrita.
        data_in = 8'b11111111;
        addrs = 1;
        #10; // Aguarda um ciclo de clock.

        r_w = 0; // Modo de leitura.
        #10; // Aguarda um ciclo de clock.

        // Finaliza a simulação.
        $finish;
    end

    // Monitoramento dos sinais.
    initial begin
        $monitor("Tempo: %t | Endereço: %b | Data_out: %b", $time, addrs, data_out);
    end

endmodule
