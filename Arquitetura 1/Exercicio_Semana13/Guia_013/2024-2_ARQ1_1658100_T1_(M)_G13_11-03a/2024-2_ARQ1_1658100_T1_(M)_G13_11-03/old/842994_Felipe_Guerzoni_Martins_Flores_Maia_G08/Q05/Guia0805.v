module ones_complement(input [5:0] in, output [5:0] out);
    assign out = ~in;
endmodule

module fullAdder(input a, input b, input cin, output sum, output cout);
    assign sum = a ^ b ^ cin;
    assign cout = (a & b) | (cin & (a ^ b));
endmodule

// 6-bit Adder, adiciona 1 ao complemento de 2
module adder6bit(input [5:0] in, output [5:0] out, output cout);
    wire [4:0] carry;
    
    fullAdder FA0(.a(in[0]), .b(1'b1), .cin(1'b0), .sum(out[0]), .cout(carry[0]));
    fullAdder FA1(.a(in[1]), .b(1'b0), .cin(carry[0]), .sum(out[1]), .cout(carry[1]));
    fullAdder FA2(.a(in[2]), .b(1'b0), .cin(carry[1]), .sum(out[2]), .cout(carry[2]));
    fullAdder FA3(.a(in[3]), .b(1'b0), .cin(carry[2]), .sum(out[3]), .cout(carry[3]));
    fullAdder FA4(.a(in[4]), .b(1'b0), .cin(carry[3]), .sum(out[4]), .cout(carry[4]));
    fullAdder FA5(.a(in[5]), .b(1'b0), .cin(carry[4]), .sum(out[5]), .cout(cout));
endmodule

module twos_complement(input [5:0] in, output [5:0] out);
    wire [5:0] ones_comp;
    wire cout;

    ones_complement OC(.in(in), .out(ones_comp));
    adder6bit ADD(.in(ones_comp), .out(out), .cout(cout));
endmodule

module testbench;
    reg [5:0] in;
    wire [5:0] out;

    twos_complement TC(.in(in), .out(out));

    initial begin
        $display(" Input  |  Two's Complement ");
        $display("----------------------------");

        in = 6'b000001; #10;
        $display("  %b |      %b", in, out);

        in = 6'b000010; #10;
        $display("  %b |      %b", in, out);

        in = 6'b111111; #10;
        $display("  %b |      %b", in, out);

        in = 6'b100000; #10;
        $display("  %b |      %b", in, out);

        in = 6'b011111; #10;
        $display("  %b |      %b", in, out);

        $finish;
    end
endmodule