/*
      Guia_1202.v  
      806937 - FELIPE PEREIRA DA SILVA
      ------------------------------------------------
      Compilar  => iverilog -o programa.vvp programa.v
      Executar  => vvp programa.vvp
*/

module ram_1x8 (
    
    input wire clk,        
    input wire wr_en,       
    input wire [7:0] data_in,
    output wire [7:0] data_out 
);

    
    wire [3:0] data_in_high = data_in[7:4];
    wire [3:0] data_in_low = data_in[3:0];
    
    
    wire [3:0] data_out_high;
    wire [3:0] data_out_low;

    
    ram_1x4 ram_high (
        .clk(clk),
        .wr_en(wr_en),
        .data_in(data_in_high),
        .data_out(data_out_high)
    );

    ram_1x4 ram_low (
        .clk(clk),
        .wr_en(wr_en),
        .data_in(data_in_low),
        .data_out(data_out_low)
    );

   
    assign data_out = {data_out_high, data_out_low};

endmodule


module ram_1x4 (
    input wire clk,
    input wire wr_en,
    input wire [3:0] data_in,
    output reg [3:0] data_out
);
    reg [3:0] mem; 

    always @(posedge clk) begin
        if (wr_en) begin
            mem <= data_in; 
        end
        data_out <= mem; 
    end
endmodule
