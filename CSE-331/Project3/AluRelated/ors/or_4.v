module or_4(output y, input a, b, c, d);
	wire w1, w2;
	or or1(w1, a, b);
	or or2(w2, c, d);
	or or3(y, w1, w2);
endmodule
