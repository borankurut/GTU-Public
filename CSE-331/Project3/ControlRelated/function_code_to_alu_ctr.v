module function_code_to_alu_ctr(
	output [2:0] alu_ctr,
	input [5:0] function_code
);

	wire fc0notandfc1andfc2not, fc0andfc1notandfc2; // or them for aluctr0;

	wire fc0andfc1andfc2not; // this is aluctr1; and aluctr[2] is fc[1]

	wire fc0not, fc1not, fc2not;

	wire fc0notandfc1;
	wire fc0andfc1not;
	wire fc0andfc1;

	not n0(fc0not, function_code[0]);
	not n1(fc1not, function_code[1]);
	not n2(fc2not, function_code[2]);

	and and0(fc0notandfc1, fc0not, function_code[1]);
	and and1(fc0andfc1not, function_code[0], fc1not);
	and and2(fc0andfc1, function_code[0], function_code[1]);

	and and3(fc0notandfc1andfc2not, fc0notandfc1, fc2not);
	and and4(fc0andfc1notandfc2, fc0andfc1not, function_code[2]);
	and and5(fc0andfc1andfc2not, fc0andfc1, fc2not);

	or or0(alu_ctr[0], fc0notandfc1andfc2not, fc0andfc1notandfc2);
	or or1(alu_ctr[1], fc0andfc1andfc2not, 1'b0);
	or or2(alu_ctr[2], function_code[1], 1'b0);

endmodule

