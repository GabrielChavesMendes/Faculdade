//Questao_f

module NOR_Circuit (
    input a, b, c, d,
    output f
);

wire n1, n2, n3, n4, n5, n6, n7, n8;
wire n9;

assign n1 = ~(a | b | c | d);        // M0
assign n2 = ~(a | b | c | ~d);       // M1
assign n3 = ~(a | b | ~c | d);       // M2
assign n4 = ~(a | b | ~c | ~d);      // M3
assign n5 = ~(a | ~b | c | d);       // M4
assign n6 = ~(a | ~b | c | ~d);      // M5
assign n7 = ~(a | ~b | ~c | d);      // M6
assign n8 = ~(a | ~b | ~c | ~d);     // M7

assign n9 = ~(n1 & n2 & n3 & n4 & n5 & n6 & n7 & n8);
assign f = ~n9; // Dupla negação

endmodule

module testbench_NOR;

    reg a, b, c, d;
    wire f;
    
    NOR_Circuit uut (
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
        a = 1; b = 0; c = 0; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 0; c = 0; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 0; c = 1; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 0; c = 1; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 1; c = 0; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 1; c = 0; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 1; c = 1; d = 0; #10 $display("%b %b %b %b | %b", a, b, c, d, f);
        a = 1; b = 1; c = 1; d = 1; #10 $display("%b %b %b %b | %b", a, b, c, d, f);

        $finish;
    end

endmodule


/*
a b c d | f
---------
0 0 0 0 | 0
0 0 0 1 | 0
0 0 1 0 | 0
0 0 1 1 | 0
0 1 0 0 | 0
0 1 0 1 | 0
0 1 1 0 | 0
0 1 1 1 | 0
1 0 0 0 | 0
1 0 0 1 | 0
1 0 1 0 | 0
1 0 1 1 | 0
1 1 0 0 | 0
1 1 0 1 | 0
1 1 1 0 | 0
1 1 1 1 | 0
*/