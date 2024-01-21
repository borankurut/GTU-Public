module mux_2x1(output result, input a, b, sel);
	
	wire notsel, notsela, selb;

	not not1(notsel, sel);
	and and1(notsela, a, notsel);
	and and2(selb, b, sel);

	or or1(result, notsela, selb);

endmodule
