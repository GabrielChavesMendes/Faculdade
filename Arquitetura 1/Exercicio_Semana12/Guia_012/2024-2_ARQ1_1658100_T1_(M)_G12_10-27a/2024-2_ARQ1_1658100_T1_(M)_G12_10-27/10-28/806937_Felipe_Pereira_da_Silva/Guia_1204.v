/*
      Guia_1204.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module ram_4x8 (
    
    input wire clk,
    input wire wr_en,
    input wire [1:0] addr,
    input wire [7:0] data_in,
    output wire [7:0] data_out
);


  wire [7:0] data_out0, data_out1;


  wire wr_en0 = wr_en & ~addr[1];
  wire wr_en1 = wr_en & addr[1];


  ram_2x8 ram0 (
      .clk(clk),
      .wr_en(wr_en0),
      .addr(addr[0]),
      .data_in(data_in),
      .data_out(data_out0)
  );

  ram_2x8 ram1 (
      .clk(clk),
      .wr_en(wr_en1),
      .addr(addr[0]),
      .data_in(data_in),
      .data_out(data_out1)
  );


  assign data_out = addr[1] ? data_out1 : data_out0;

endmodule


module ram_2x8 (
    input wire clk,
    input wire wr_en,
    input wire addr,
    input wire [7:0] data_in,
    output wire [7:0] data_out
);
  wire [7:0] data_out0, data_out1;
  wire wr_en0 = wr_en & ~addr;
  wire wr_en1 = wr_en & addr;

  ram_1x8 ram0 (
      .clk(clk),
      .wr_en(wr_en0),
      .data_in(data_in),
      .data_out(data_out0)
  );
  ram_1x8 ram1 (
      .clk(clk),
      .wr_en(wr_en1),
      .data_in(data_in),
      .data_out(data_out1)
  );

  assign data_out = addr ? data_out1 : data_out0;
endmodule


module ram_1x8 (
    input wire clk,
    input wire wr_en,
    input wire [7:0] data_in,
    output reg [7:0] data_out
);
  reg [7:0] mem;

  always @(posedge clk) begin
    if (wr_en) begin
      mem <= data_in;
    end
    data_out <= mem;
  end
endmodule
