module subtractor_32(input[31:0] a, b, output cout, output[31:0] result);
	wire [31:0] b_not;
	not_32_bit not1(b_not, b);
	adder_32 adder(
		.a(a), 
		.b(b_not), 
		.cin({1'b1}),
		.cout(cout),
		.result(result)
	);

endmodule

