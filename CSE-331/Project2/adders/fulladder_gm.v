module fulladder_gm(input a, b, cin, output g, p, sum);

	wire wp, wg;

	//sum	
	xor xor1(p, a, b);
	xor xor2(wp, a, b);

	//cout
	and and1(g, a, b);

	xor xor3(sum, cin, wp);

endmodule

