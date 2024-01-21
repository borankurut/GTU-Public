module adder_32(input[31:0] a, b, input cin, output cout, output[31:0] result);

	wire cout1;

	adder_16 adder1(
		.a(a[15:0]),
		.b(b[15:0]),
		.cin(cin),
		.cout(cout1),
		.result(result[15:0])
	);


	adder_16 adder2(
		.a(a[31:16]),
		.b(b[31:16]),
		.cin(cout1),
		.cout(cout),
		.result(result[31:16])
	);


endmodule

