/*
      Guia_1405.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module paralelo_para_serial (
    input wire clock,
    input wire reset,
    input wire carregar,
    input wire [5:0] entrada_paralela,
    output reg saida_serial
);

  reg [5:0] registrador_deslocamento;
  reg [2:0] contador;

  always @(posedge clock or posedge reset) begin
    if (reset) begin
      registrador_deslocamento <= 6'b0;
      contador <= 3'b0;
      saida_serial <= 1'b0;
    end else if (carregar) begin
      registrador_deslocamento <= entrada_paralela;
      contador <= 3'b101;  
    end else if (contador > 0) begin
      saida_serial <= registrador_deslocamento[0];
      registrador_deslocamento <= registrador_deslocamento >> 1;
      contador <= contador - 1;
    end
  end

endmodule
