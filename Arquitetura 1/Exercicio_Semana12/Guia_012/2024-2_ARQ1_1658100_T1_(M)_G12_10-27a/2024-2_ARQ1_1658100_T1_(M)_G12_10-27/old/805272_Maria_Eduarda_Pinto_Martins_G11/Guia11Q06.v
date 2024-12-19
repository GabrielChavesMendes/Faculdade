module Guia_1103 ( y, x, clk, reset );
output reg y;
input x;
input clk;
input reset;

parameter  start = 3'b000, 
           id1 = 3'b001, 
           id10 = 3'b010, 
           id100 = 3'b011, 
           id1001 = 3'b100;

reg [2:0] state, next_state;

// Lógica de transição de estados
always @(posedge clk or negedge reset)
begin
    if (!reset)
        state <= start;
    else
        state <= next_state;
end

// Lógica de próxima transição de estados
always @(state or x)
begin
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
                next_state = id1001;
            else
                next_state = start;

        id1001:
            if (x)
                next_state = id1;
            else
                next_state = start;

        default:
            next_state = start;
    endcase
end

// Lógica de saída (Moore depende apenas do estado)
always @(state)
begin
    case (state)
        id1001: y = 1; // Sequência 1001 reconhecida
        default: y = 0;
    endcase
end
endmodule
