module fullAdder(input a, input b, input cin, output sum, output cout);
    assign sum = a ^ b ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));
endmodule

module adder_subtractor(input [5:0] A, input [5:0] B, input carryIn, output [5:0] result, output cout);
    wire [5:0] B_xor;
    wire [4:0] carry;

    assign B_xor = B ^ {6{carryIn}};

    fullAdder FA0(.a(A[0]), .b(B_xor[0]), .cin(carryIn), .sum(result[0]), .cout(carry[0]));
    fullAdder FA1(.a(A[1]), .b(B_xor[1]), .cin(carry[0]), .sum(result[1]), .cout(carry[1]));
    fullAdder FA2(.a(A[2]), .b(B_xor[2]), .cin(carry[1]), .sum(result[2]), .cout(carry[2]));
    fullAdder FA3(.a(A[3]), .b(B_xor[3]), .cin(carry[2]), .sum(result[3]), .cout(carry[3]));
    fullAdder FA4(.a(A[4]), .b(B_xor[4]), .cin(carry[3]), .sum(result[4]), .cout(carry[4]));
    fullAdder FA5(.a(A[5]), .b(B_xor[5]), .cin(carry[4]), .sum(result[5]), .cout(cout));
endmodule

module comparator(input [5:0] A, input [5:0] B, output equal, output not_equal);
    assign equal = (A == B);
    assign not_equal = ~equal;
endmodule

module Guia_0806(input [5:0] A, input [5:0] B, input carryIn, input key, output [5:0] output_result, output equal, output not_equal);
    wire [5:0] arith_result;
    wire cout;

    adder_subtractor AS(.A(A), .B(B), .carryIn(carryIn), .result(arith_result), .cout(cout));

    comparator COMP(.A(A), .B(B), .equal(equal), .not_equal(not_equal));

    assign output_result = key ? {5'b0, equal} : arith_result;
endmodule

module testbench;
    reg [5:0] A, B;
    reg carryIn, key;
    wire [5:0] output_result;
    wire equal, not_equal;

    Guia_0806 uut(.A(A), .B(B), .carryIn(carryIn), .key(key), .output_result(output_result), .equal(equal), .not_equal(not_equal));

    initial begin
        $display("   A      B      | carryIn key | Result | Equal Not_Equal");
        $display("----------------------------------------------------------");

        A = 6'b000001; B = 6'b000001; carryIn = 0; key = 0; #10;
        $display(" %b  %b  |    %b      %b   |  %b  |   %b     %b", A, B, carryIn, key, output_result, equal, not_equal);

        A = 6'b000001; B = 6'b000010; carryIn = 0; key = 0; #10;
        $display(" %b  %b  |    %b      %b   |  %b  |   %b     %b", A, B, carryIn, key, output_result, equal, not_equal);

        A = 6'b000001; B = 6'b000001; carryIn = 1; key = 1; #10;
        $display(" %b  %b  |    %b      %b   |  %b  |   %b     %b", A, B, carryIn, key, output_result, equal, not_equal);

        A = 6'b111111; B = 6'b000001; carryIn = 1; key = 0; #10;
        $display(" %b  %b  |    %b      %b   |  %b  |   %b     %b", A, B, carryIn, key, output_result, equal, not_equal);

        $finish;
    end
endmodule