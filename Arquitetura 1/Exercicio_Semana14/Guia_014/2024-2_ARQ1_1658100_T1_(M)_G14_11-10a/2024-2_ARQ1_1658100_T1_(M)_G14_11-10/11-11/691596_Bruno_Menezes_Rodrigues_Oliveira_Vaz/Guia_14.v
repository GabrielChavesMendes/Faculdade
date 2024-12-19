//Bruno Menezes Rodrigues Oliveira Vaz, 691596
//questão 1
module deslocamento_esq (
  input clk,
  input rst, // Sinal de reset (opcional)
  input ld,
  input din,
  output reg [5:0] q
);

  always @(posedge clk) begin
    if (rst) begin // Reset assíncrono (opcional)
      q <= 6'b000000;
    end else begin
      if (ld) begin
        q[0] <= din;  // Carrega din em q[0] quando ld=1
      end else begin
        q <= {q[4:0], 1'b0}; // Deslocamento para a esquerda quando ld=0
      end
    end
  end

endmodule


-----------------------------------------------------------------------------------
//questão 2
module deslocamento_esq (
  input clk,
  input rst,
  input ld,
  input [5:0] din,
  output reg [5:0] q
);

  always @(posedge clk) begin
    if (rst) begin
      q <= 6'b000000;
    end else begin
      if (ld) begin
        q <= din; // Carga paralela
      end else begin
        q <= {q[4:0], 1'b0}; // Deslocamento para a esquerda
      end
    end
  end

endmodule

----------------------------------------------------------------------------------
//questão 3
module circular (
  input clk,
  input rst,
  input ld,
  input din,
  output reg [5:0] q
);

  always @(posedge clk) begin
    if (rst) begin
      q <= 6'b000000;
    end else begin
      if (ld) begin
        q <= {q[5], q[5:1]}; // Mantém os bits e insere 0 no final
        q[5] <= din;        // Carrega din
      end else begin
        q <= {q[0], q[5:1]}; // Deslocamento circular para a direita
      end
    end
  end

endmodule

------------------------------------------------------------------------------------
//questão 4
module twisted_ring(
  input clk,
  input rst,
  input ld,
  input din,
  output reg [5:0] q
);

  always @(posedge clk) begin
    if (rst) begin
      q <= 6'b000000;
    end else begin
      if (ld) begin
        q <= {q[5:1], din};
      end else begin
        q <= {q[4:0], ~q[5]}; // Deslocamento com inversão
      end
    end
  end
endmodule