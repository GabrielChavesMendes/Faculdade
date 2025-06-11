// Andriel Mark da Silva Pinto
// Matrícula: 859093

module f5_nor ( output s,
                input a,
                input b );
  wire not_a;
  wire and_result;

  nor NOR1 (not_a, a, a);
  nor NOR2 (and_result, not_a, b);
  nor NOR3 (s, and_result, and_result);

endmodule // f5_nor

module test_f5_nor;
  reg x;
  reg y;
  wire z;
  
  f5_nor modulo (z, x, y);

  initial
  begin : main
    $display("Guia_0501 - xxx yyy zzz - 999999");
    $display("Test module");
    $display(" x y z");
    $monitor("%4b %4b %4b", x, y, z);
    x = 1'b0; y = 1'b0;
    #1 x = 1'b0; y = 1'b1;
    #1 x = 1'b1; y = 1'b0;
    #1 x = 1'b1; y = 1'b1;
  end
endmodule // test_f5_nor
