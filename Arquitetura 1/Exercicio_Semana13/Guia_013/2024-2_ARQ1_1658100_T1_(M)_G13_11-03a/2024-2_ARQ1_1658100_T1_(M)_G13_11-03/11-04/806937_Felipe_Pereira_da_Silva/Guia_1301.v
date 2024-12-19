/*
      Guia_1301.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module Contador (
    output [4:0] saida,
    input clk,
    input reset
);

  jk_ff flipflop0 (
      .q  (saida[0]),
      .j  (1'b1),
      .k  (1'b1),
      .clk(clk),
      .rst(reset)
  );

  jk_ff flipflop1 (
      .q  (saida[1]),
      .j  (1'b1),
      .k  (1'b1),
      .clk(saida[0]),
      .rst(reset)
  );

  jk_ff flipflop2 (
      .q  (saida[2]),
      .j  (1'b1),
      .k  (1'b1),
      .clk(saida[1]),
      .rst(reset)
  );

  jk_ff flipflop3 (
      .q  (saida[3]),
      .j  (1'b1),
      .k  (1'b1),
      .clk(saida[2]),
      .rst(reset)
  );

  jk_ff flipflop4 (
      .q  (saida[4]),
      .j  (1'b1),
      .k  (1'b1),
      .clk(saida[3]),
      .rst(reset)
  );

endmodule

module jk_ff (
    output reg estado,
    input entrada_j,
    entrada_k,
    entrada_clk,
    entrada_reset
);
  always @(posedge entrada_clk or posedge entrada_reset) begin
    if (entrada_reset) begin
      estado <= 1'b1;
    end else begin
      case ({
        entrada_j, entrada_k
      })
        2'b00: estado <= estado;
        2'b01: estado <= 1'b0;
        2'b10: estado <= 1'b1;
        2'b11: estado <= ~estado;
      endcase
    end
  end
endmodule
