module alu(
	input wire clk,
	input wire reset,

	output [31:0] result, 
	output zero_bit,

	input [2:0] sel,
	input [31:0] a,
	input [31:0] b
);

	wire [31:0] result_and, result_or, result_xor, result_nor, result_lt, result_add, result_sub, result_mod;
	wire cout;

	and_32_bit	and1(result_and, a, b);
	or_32_bit or1(result_or, a, b);
	xor_32_bit xor1(result_xor, a, b);
	nor_32_bit nor1(result_nor, a, b);
	lessthan_32 lt1(result_lt, a, b);
	adder_32 add1(a, b, {1'b0}, cout, result_add);	
	subtractor_32 sub1(a, b, cout, result_sub);

	

	mod mod1(clk, reset, result_mod, a, b);

	//module mod(input wire clk, input wire reset, output reg [31:0] result, input [31:0] a, b);

//result_and, result_or, result_xor, result_nor, result_lt, result_add, result_sub, result_mod;
	mux8x1_32bit mux1(
		.result(result), 

		.in0(result_and), 
		.in1(result_or), 
		.in2(result_xor), 
		.in3(result_nor), 
		.in4(result_lt), 
		.in5(result_add), 
		.in6(result_sub), 
		.in7(result_mod), 

		.sel(sel)
	);

	is_zero iz(zero_bit, result);

endmodule
