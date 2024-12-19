/*
      Guia_1401.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module shift_register (
    input wire clk,
    input wire reset,
    input wire load,
    input wire data_in,
    output reg [5:0] out
);

  always @(posedge clk or posedge reset) begin
    if (reset) out <= 6'b0;
    else if (load) out[5:0] <= {data_in, out[5:1]};
    else out[5:0] <= {1'b0, out[5:1]};
  end

endmodule
