module comparator_6bit(input [5:0] A, input [5:0] B, output equal, output not_equal);
    assign equal = (A == B);   
    assign not_equal = ~equal;
endmodule   

module Guia_0807(input [5:0] A, input [5:0] B, input key, output result);
    wire equal, not_equal;

    comparator_6bit COMP(.A(A), .B(B), .equal(equal), .not_equal(not_equal));

    assign result = key ? not_equal : equal;
endmodule

module testbench;
    reg [5:0] A, B;
    reg key;
    wire result;

    Guia_0807 uut(.A(A), .B(B), .key(key), .result(result));

    initial begin
        $display("   A      B      | key | Result");
        $display("-----------------|------|--------");

        A = 6'b000000; B = 6'b000000; key = 0; #10;
        $display(" %b  %b  |   %b  |   %b", A, B, key, result);

        A = 6'b000001; B = 6'b000001; key = 0; #10;
        $display(" %b  %b  |   %b  |   %b", A, B, key, result);

        A = 6'b000001; B = 6'b000010; key = 1; #10;
        $display(" %b  %b  |   %b  |   %b", A, B, key, result);

        A = 6'b111111; B = 6'b111111; key = 1; #10;
        $display(" %b  %b  |   %b  |   %b", A, B, key, result);

        $finish;
    end
endmodule