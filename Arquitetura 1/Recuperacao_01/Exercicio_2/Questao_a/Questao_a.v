//Questao_a

module mux (
    input wire a,  
    input wire c,  
    output wire y  
);
    wire not_a;  

    not (not_a, a);
    
    assign y = (c) ? not_a : a;
endmodule


module tb_mux;
    reg a;       // Registro para entrada a
    reg c;       // Registro para entrada c
    wire y;      // Fio para saída

    mux uut (
        .a(a),
        .c(c),
        .y(y)
    );

    initial begin
        $display("a c | y");
        $display("---------");

        a = 0; c = 0; #10;  // a = 0, c = 0
        $display("%b %b | %b", a, c, y); 

        a = 0; c = 1; #10;  // a = 0, c = 1
        $display("%b %b | %b", a, c, y); 

        a = 1; c = 0; #10;  // a = 1, c = 0
        $display("%b %b | %b", a, c, y); 

        a = 1; c = 1; #10;  // a = 1, c = 1
        $display("%b %b | %b", a, c, y); 

        $finish;     end
endmodule


/*
a c | y
---------
0 0 | 0
0 1 | 1
1 0 | 1
1 1 | 0
*/