module and_4(output y, input a, b, c, d);
	wire w1, w2;
	and and1(w1, a, b);
	and and2(w2, c, d);
	and and3(y, w1, w2);
endmodule
