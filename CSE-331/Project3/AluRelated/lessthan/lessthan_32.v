module lessthan_32(output [31:0]result, input [31:0] a, b);

	wire [31:0] subresult;
	wire cout;
	wire result_1bit;
	subtractor_32 sub1(a, b, cout, subresult);

	wire different; // if true, no need to subtract
	xor(different, a[31], b[31]); // if msb different, the result is a[31].

	mux_2x1 mux1(result_1bit, subresult[31], a[31], different);

	mux2x1_32bit mux2(result, {32'h00000000}, {32'h00000001}, result_1bit); // convert 1 bit result to 32 bits.

endmodule


