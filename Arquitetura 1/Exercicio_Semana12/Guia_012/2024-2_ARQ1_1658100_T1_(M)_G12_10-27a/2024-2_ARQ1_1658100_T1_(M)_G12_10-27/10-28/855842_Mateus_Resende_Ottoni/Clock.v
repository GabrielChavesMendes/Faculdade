/* 
Clock.v 
855842 - Mateus Resende Ottoni

iverilog -o Clock.vvp Clock.v
vvp Clock.vvp
*/



// Clock
//----------------------------------------
module clock (output signal);

// Dados
reg signal;

// Processo
initial
  begin
    signal = 1'b0;
  end

  always
    begin
      #6 signal = ~signal;
    end


endmodule
//----------------------------------------



