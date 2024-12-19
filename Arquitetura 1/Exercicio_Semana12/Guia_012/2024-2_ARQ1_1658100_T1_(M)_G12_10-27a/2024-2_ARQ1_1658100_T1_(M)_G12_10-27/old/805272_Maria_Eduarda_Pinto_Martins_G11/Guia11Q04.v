module Guia_1101 ( y, x, clk, reset );
output reg y;
input x;
input clk;
input reset;

parameter  start = 2'b00, 
           id1 = 2'b01, 
           id10 = 2'b10, 
           id100 = 2'b11, 
           found = 2'bxx; 

reg [1:0] state, next_state;

always @(posedge clk or negedge reset)
begin
    if (!reset)
        state <= start;
    else
        state <= next_state;
end

always @(state or x)
begin
    y = 0;
    case (state)
        start:
            if (x)
                next_state = id1;
            else
                next_state = start;

        id1:
            if (x)
                next_state = id1;
            else
                next_state = id10;

        id10:
            if (x)
                next_state = id100;
            else
                next_state = start;

        id100:
            if (x)
            begin
                next_state = found;
                y = 1; 
            end
            else
                next_state = start;

        found:
            next_state = found; 

        default:
            next_state = start;
    endcase
end
endmodule
