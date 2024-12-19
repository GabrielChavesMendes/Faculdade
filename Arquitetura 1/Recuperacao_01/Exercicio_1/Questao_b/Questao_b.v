//Questao_b


module PoS_Circuit (
    input a, b, c, d,
    output f
);

assign f = (a | b | c | d) &
           (a | b | c | ~d) &
           (a | b | ~c | d) &
           (a | ~b | ~c | d) &
           (~a | ~b | ~c | ~d);

endmodule


module testbench_PoS;

    reg a, b, c, d;
    wire f;
    
    PoS_Circuit uut (
        .a(a), 
        .b(b), 
        .c(c), 
        .d(d), 
        .f(f)
    );

    initial begin
        $display("a b c d | f");
        $display("---------");

        a = 0; b = 0; c = 0; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 0; c = 0; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 0; c = 1; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 0; c = 1; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 1; c = 0; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 1; c = 0; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 1; c = 1; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 0; b = 1; c = 1; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);

        $finish;
    end

endmodule

/*
a b c d | f
---------
0 0 0 0 | 0
0 0 0 1 | 0
0 0 1 0 | 0
0 0 1 1 | 1
0 1 0 0 | 1
0 1 0 1 | 1
0 1 1 0 | 0
0 1 1 1 | 1
*/