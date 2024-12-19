/*
      Guia_1305.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/
module Contador (

    output [2:0] saida,
    input clk_principal,
    input reset_principal
);

  t_ff flipflop0 (
      .q  (saida[0]),
      .t  (1'b1),
      .clk(clk_principal),
      .rst(reset_principal)
  );

  t_ff flipflop1 (
      .q  (saida[1]),
      .t  (saida[0]),
      .clk(clk_principal),
      .rst(reset_principal)
  );

  t_ff flipflop2 (
      .q  (saida[2]),
      .t  (saida[0] & saida[1]),
      .clk(clk_principal),
      .rst(reset_principal)
  );

  assign condicao_reset = (saida == 3'b111);

endmodule

module t_ff (
    output reg estado,
    input entrada_t,
    clk_flipflop,
    reset_flipflop
);
  always @(posedge clk_flipflop or posedge reset_flipflop) begin
    if (reset_flipflop) begin
      estado <= 1'b0;
    end else if (entrada_t) begin
      estado <= ~estado;
    end
  end
endmodule
