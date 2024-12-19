module equals(input [4:0] A, input [4:0] B, output [4:0] out);
    assign out = ~(A ^ B);
endmodule

module testbench;
    reg [4:0] A;
    reg [4:0] B;
    wire [4:0] equal;

    equals EQ(.A(A), .B(B), .out(equal));

    initial begin
        $display("   A      B      |  Equal Bits");
        $display("-----------------|-------------");

        A = 5'b00000; B = 5'b00000; #10;
        $display(" %b  %b  |   %b", A, B, equal);

        A = 5'b00001; B = 5'b00001; #10;
        $display(" %b  %b  |   %b", A, B, equal);

        A = 5'b11111; B = 5'b11111; #10;
        $display(" %b  %b  |   %b", A, B, equal);

        A = 5'b10001; B = 5'b10000; #10;
        $display(" %b  %b  |   %b", A, B, equal);

        A = 5'b10101; B = 5'b10101; #10;
        $display(" %b  %b  |   %b", A, B, equal);

        A = 5'b11000; B = 5'b01111; #10;
        $display(" %b  %b  |   %b", A, B, equal);

        $finish;
    end
endmodule