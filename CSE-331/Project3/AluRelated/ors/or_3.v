module or_3(output y, input a, b, c);
	wire w;
	or or1(w, a, b);
	or or2(y, w, c);
endmodule
