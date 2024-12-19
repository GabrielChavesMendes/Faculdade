/*
      Guia_1402.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module registrador_shift (
    input wire clock,
    input wire reset,
    input wire carregar,
    input wire [5:0] dados,
    output reg [5:0] saida
);

  always @(posedge clock or posedge reset) begin
    if (reset) saida <= 6'b0;
    else if (carregar) saida <= dados;
    else saida <= {saida[4:0], 1'b0};
  end

endmodule
