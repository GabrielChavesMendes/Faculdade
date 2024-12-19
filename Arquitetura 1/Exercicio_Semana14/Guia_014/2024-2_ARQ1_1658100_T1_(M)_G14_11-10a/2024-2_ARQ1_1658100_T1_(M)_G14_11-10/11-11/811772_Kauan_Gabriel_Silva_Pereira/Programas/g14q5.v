module conversor_paralelo_para_serie (
    input wire clk,               // Sinal de clock
    input wire reset,             // Sinal de reset
    input wire [5:0] data_in,     // Entrada paralela de 6 bits
    output reg data_out           // Saída serial
);

    reg [2:0] counter;            // Contador para controlar os ciclos de conversão (6 bits)
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            counter <= 3'b000;    // Reset do contador para iniciar a conversão
            data_out <= 0;        // Reseta a saída serial
        end else begin
            if (counter < 6) begin
                data_out <= data_in[5 - counter];  // Envia os bits mais significativos primeiro
                counter <= counter + 1;             // Incrementa o contador
            end
        end
    end

endmodule


`timescale 1ns/1ps

module testbench;

    reg clk;                    // Sinal de clock
    reg reset;                  // Sinal de reset
    reg [5:0] data_in;          // Entrada paralela de 6 bits
    wire data_out;              // Saída serial

    // Instancia o módulo conversor_paralelo_para_serie para teste
    conversor_paralelo_para_serie uut (
        .clk(clk),
        .reset(reset),
        .data_in(data_in),
        .data_out(data_out)
    );

    // Geração do clock (alternando a cada 10 unidades de tempo)
    initial begin
        clk = 0;
        forever #10 clk = ~clk;
    end

    // Sequência de teste
    initial begin
        // Exibe o estado dos sinais na simulação
        $monitor("Time=%0t | Reset=%b | Data_in=%b | Data_out=%b", $time, reset, data_in, data_out);
        
        // Teste 1: Reset do sistema
        reset = 1;
        data_in = 6'b101010;      // Dados de entrada paralela
        #20;                      // Aguarda o clock
        reset = 0;
        
        // Teste 2: Conversão de dados paralelos para série
        #100;                     // Aguarda a conversão completa dos 6 bits
        
        // Teste 3: Novo conjunto de dados
        data_in = 6'b110011;      // Novo dado de entrada
        #100;                     // Aguarda a conversão completa dos 6 bits
        
        $finish;                  // Finaliza a simulação
    end

endmodule
