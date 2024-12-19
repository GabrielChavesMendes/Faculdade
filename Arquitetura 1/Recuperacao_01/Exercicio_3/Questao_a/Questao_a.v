//Questao_a

module expression (
    input wire a,
    input wire b,
    input wire c,
    output wire y
);
    assign y = ((~a | b) & (b | ~c));
endmodule

module tb_expression;
    reg a;
    reg b;
    reg c;
    wire y;

    expression uut (
        .a(a),
        .b(b),
        .c(c),
        .y(y)
    );

    initial begin
        $display("a b c | y");
        $display("---------");

        a = 0; b = 0; c = 0; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 0; b = 0; c = 1; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 0; b = 1; c = 0; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 0; b = 1; c = 1; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 1; b = 0; c = 0; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 1; b = 0; c = 1; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 1; b = 1; c = 0; #10;
        $display("%b %b %b | %b", a, b, c, y);

        a = 1; b = 1; c = 1; #10;
        $display("%b %b %b | %b", a, b, c, y);

        $finish;
    end
endmodule


/*
a b c | y
---------
0 0 0 | 1
0 0 1 | 0
0 1 0 | 1
0 1 1 | 1
1 0 0 | 0
1 0 1 | 0
1 1 0 | 1
1 1 1 | 1
*/