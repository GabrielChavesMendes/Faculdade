/*
      Guia_1403.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module registrador_shift_anel (
      
    input wire clock,
    input wire reset,
    input wire carregar,
    input wire dado,
    output reg [5:0] saida
);

  always @(posedge clock or posedge reset) begin
    if (reset) saida <= 6'b0;
    else if (carregar) saida <= {dado, saida[5:1]};
    else saida <= {saida[0], saida[5:1]};
  end

endmodule
