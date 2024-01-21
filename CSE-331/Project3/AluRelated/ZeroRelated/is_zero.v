module is_zero(
	output wire result,
	input [31:0] i
);

	wire or_wire;
	or_32_to_1 or0(or_wire, i);
	not n(result, or_wire);

endmodule

