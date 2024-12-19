//Questao_b

module mux2 (
    input wire a,  
    input wire b, 
    input wire c,  
    output wire y  
);
    wire not_a;               
    wire not_c;               
    wire mux_a_not_a_b;      

    not (not_a, a);

    not (not_c, c);

    assign mux_a_not_a_b = (b) ? not_a : a;

    assign y = (c) ? not_c : mux_a_not_a_b;
endmodule

module tb_mux2;
    reg a;       
    reg b;       
    reg c;   
    wire y;      

    mux2 uut (
        .a(a),
        .b(b),
        .c(c),
        .y(y)
    );

    initial begin
        $display("a b c | y");
        $display("---------");

        // Testes
        a = 0; b = 0; c = 0; #10;  // a = 0, b = 0, c = 0
        $display("%b %b %b | %b", a, b, c, y); 

        a = 0; b = 0; c = 1; #10;  // a = 0, b = 0, c = 1
        $display("%b %b %b | %b", a, b, c, y); 

        a = 0; b = 1; c = 0; #10;  // a = 0, b = 1, c = 0
        $display("%b %b %b | %b", a, b, c, y); 

        a = 0; b = 1; c = 1; #10;  // a = 0, b = 1, c = 1
        $display("%b %b %b | %b", a, b, c, y); 

        a = 1; b = 0; c = 0; #10;  // a = 1, b = 0, c = 0
        $display("%b %b %b | %b", a, b, c, y); 

        a = 1; b = 0; c = 1; #10;  // a = 1, b = 0, c = 1
        $display("%b %b %b | %b", a, b, c, y); 

        a = 1; b = 1; c = 0; #10;  // a = 1, b = 1, c = 0
        $display("%b %b %b | %b", a, b, c, y); 

        a = 1; b = 1; c = 1; #10;  // a = 1, b = 1, c = 1
        $display("%b %b %b | %b", a, b, c, y); 

        $finish;     end
endmodule


/*
a b c | y
---------
0 0 0 | 0
0 0 1 | 0
0 1 0 | 1
0 1 1 | 0
1 0 0 | 1
1 0 1 | 0
1 1 0 | 0
1 1 1 | 0
*/