//Questao_b

module expression (
    input wire x,
    input wire y,
    output wire z
);
    assign z = (~( ~x & y )) & (~( ~x & ~y ));
endmodule

module tb_expression;
    reg x;
    reg y;
    wire z;

    expression uut (
        .x(x),
        .y(y),
        .z(z)
    );

    initial begin
        $display("x y | z");
        $display("-------");

        x = 0; y = 0; #10;
        $display("%b %b | %b", x, y, z);

        x = 0; y = 1; #10;
        $display("%b %b | %b", x, y, z);

        x = 1; y = 0; #10;
        $display("%b %b | %b", x, y, z);

        x = 1; y = 1; #10;
        $display("%b %b | %b", x, y, z);

        $finish;
    end
endmodule


/*
x y | z
-------
0 0 | 0
0 1 | 0
1 0 | 1
1 1 | 1
*/