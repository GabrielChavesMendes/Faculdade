module Guia_1102 ( y, x, clk, reset );
output reg y;
input x;
input clk;
input reset;

parameter  start = 2'b00, 
           id1 = 2'b01, 
           id10 = 2'b10, 
           id100 = 2'b11;

reg [1:0] state, next_state;

// Lógica de transição de estados
always @(posedge clk or negedge reset)
begin
    if (!reset)
        state <= start;
    else
        state <= next_state;
end

// Lógica de próxima transição de estados e saída
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
                next_state = start;
                y = 1; // Sequência 1001 encontrada
            end
            else
                next_state = start;

        default:
            next_state = start;
    endcase
end
endmodule
