module halfAdder(input x, input y, output sum, output cout);
    assign cout = x & y;
    assign sum = x ^ y;
endmodule

module fullAdder(input cin, input x, input y, output sum, output cout);
    assign sum = x ^ y ^ cin;
    assign cout = (x & y) | (x & cin) | (y & cin);
endmodule

module Guia_0802(input [4:0] A, input [4:0] B, input cin, output [4:0] diff, output cout);
    wire [4:0] B_complement;
    wire [3:0] carry;

    assign B_complement = ~B + 1;

    halfAdder HA0(.x(A[0]), .y(B_complement[0]), .sum(diff[0]), .cout(carry[0]));

    fullAdder FA1(.cin(carry[0]), .x(A[1]), .y(B_complement[1]), .sum(diff[1]), .cout(carry[1]));
    fullAdder FA2(.cin(carry[1]), .x(A[2]), .y(B_complement[2]), .sum(diff[2]), .cout(carry[2]));
    fullAdder FA3(.cin(carry[2]), .x(A[3]), .y(B_complement[3]), .sum(diff[3]), .cout(carry[3]));
    fullAdder FA4(.cin(carry[3]), .x(A[4]), .y(B_complement[4]), .sum(diff[4]), .cout(cout));
endmodule

module testbench;
    reg [4:0] A;
    reg [4:0] B;
    reg cin;
    wire [4:0] diff;
    wire cout;

    Guia_0802 uut(.A(A), .B(B), .cin(cin), .diff(diff), .cout(cout));

    initial begin
        $display("    A       B      cin |   diff    cout");
        $display("-----------------------|-----------------");

        A = 5'b00000; B = 5'b00001; cin = 0; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, diff, cout);

        A = 5'b00011; B = 5'b00001; cin = 0; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, diff, cout);

        A = 5'b01111; B = 5'b00001; cin = 1; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, diff, cout);

        A = 5'b11111; B = 5'b11111; cin = 0; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, diff, cout);

        A = 5'b10000; B = 5'b00010; cin = 1; #10;
        $display("  %b    %b    %b  |  %b    %b", A, B, cin, diff, cout);

        $finish;
    end
endmodule