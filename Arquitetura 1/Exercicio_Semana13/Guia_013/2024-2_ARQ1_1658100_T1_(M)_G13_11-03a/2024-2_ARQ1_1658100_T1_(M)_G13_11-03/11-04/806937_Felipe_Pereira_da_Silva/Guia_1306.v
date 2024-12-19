/*
      Guia_1306.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module Contador (
    output [4:0] saida,
    input clk_principal,
    input reset_principal
);

  jk_ff flipflop0 (
      .q  (saida[0]),
      .j  (~saida[0]),
      .k  (saida[0]),
      .clk(clk_principal),
      .rst(reset_principal || ~saida[4])
  );

  jk_ff flipflop1 (
      .q  (saida[1]),
      .j  (~saida[1]),
      .k  (saida[1]),
      .clk(saida[0]),
      .rst(reset_principal)
  );

  jk_ff flipflop2 (
      .q  (saida[2]),
      .j  (~saida[2]),
      .k  (saida[2]),
      .clk(saida[1]),
      .rst(reset_principal)
  );

  jk_ff flipflop3 (
      .q  (saida[3]),
      .j  (~saida[3]),
      .k  (saida[3]),
      .clk(saida[2]),
      .rst(reset_principal)
  );

  jk_ff flipflop4 (
      .q  (saida[4]),
      .j  (~saida[4]),
      .k  (saida[4]),
      .clk(saida[3]),
      .rst(reset_principal)
  );

endmodule


module jk_ff (
    output reg estado,
    input entrada_j,
    entrada_k,
    clk_flipflop,
    reset_flipflop
);
  always @(posedge clk_flipflop or posedge reset_flipflop) begin
    if (reset_flipflop) begin
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
