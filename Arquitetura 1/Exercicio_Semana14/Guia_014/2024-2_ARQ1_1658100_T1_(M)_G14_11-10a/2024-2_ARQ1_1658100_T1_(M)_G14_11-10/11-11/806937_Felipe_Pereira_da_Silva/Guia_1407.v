/*
      Guia_1407.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/


module registrador_shift_anel_torcido_direita (
    input wire clock,
    input wire reset,
    input wire carregar,
    input wire [4:0] dado,
    output reg [4:0] saida
);

  always @(posedge clock or posedge reset) begin
    if (reset) saida <= 5'b0;
    else if (carregar) saida <= dado;
    else saida <= {~saida[0], saida[4:1]};
  end

endmodule
