//Questao_e

module NAND_Circuit (
    input a, b, c, d,
    output f
);

wire n1, n2, n3, n4;

assign n1 = ~(a & b & c & ~d); // m4
assign n2 = ~(a & b & c & d);   // m5
assign n3 = ~(a & ~b & ~c & d); // m6
assign n4 = ~(a & ~b & ~c & ~d); // m7

assign f = ~(n1 & n2 & n3 & n4);

endmodule

module testbench_NAND;

    reg a, b, c, d;
    wire f;
    
    NAND_Circuit uut (
        .a(a), 
        .b(b), 
        .c(c), 
        .d(d), 
        .f(f)
    );

    initial begin
        $display("a b c d | f");
        $display("---------");

        // Testando todas as combinações de a, b, c e d de 0 a 7
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
1 0 0 0 | 1
1 0 0 1 | 1
1 0 1 0 | 0
1 0 1 1 | 0
1 1 0 0 | 0
1 1 0 1 | 0
1 1 1 0 | 1
1 1 1 1 | 1
*/