module halfAdder(input x, input y, output sum, output cout);
    assign cout = x & y;
    assign sum = x ^ y;
endmodule

module fullAdder(input cin, input x, input y, output sum, output cout);
    assign sum = x ^ y ^ cin;
    assign cout = (x & y) | (x & cin) | (y & cin);
endmodule

module Guia_0801(input [4:0] A, input [4:0] B, input cin, output [4:0] sum, output cout);
    wire [3:0] carry;

    halfAdder HA0(.x(A[0]), .y(B[0]), .sum(sum[0]), .cout(carry[0]));

    fullAdder FA1(.cin(carry[0]), .x(A[1]), .y(B[1]), .sum(sum[1]), .cout(carry[1]));
    fullAdder FA2(.cin(carry[1]), .x(A[2]), .y(B[2]), .sum(sum[2]), .cout(carry[2]));
    fullAdder FA3(.cin(carry[2]), .x(A[3]), .y(B[3]), .sum(sum[3]), .cout(carry[3]));
    fullAdder FA4(.cin(carry[3]), .x(A[4]), .y(B[4]), .sum(sum[4]), .cout(cout));
endmodule

module testbench;
    reg [4:0] A;
    reg [4:0] B;
    reg cin;
    wire [4:0] sum;
    wire cout;

    Guia_0801 uut(.A(A), .B(B), .cin(cin), .sum(sum), .cout(cout));

    initial begin
        $display("    A       B      cin |   sum    cout");
        $display("-----------------------|-----------------");

        A = 5'b00000; B = 5'b00000; cin = 0; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, sum, cout);

        A = 5'b00001; B = 5'b00001; cin = 0; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, sum, cout);

        A = 5'b01111; B = 5'b00001; cin = 1; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, sum, cout);

        A = 5'b11111; B = 5'b11111; cin = 0; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, sum, cout);

        A = 5'b10000; B = 5'b10000; cin = 1; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, sum, cout);

        $finish;
    end
endmodule