module and_3(output y, input a, b, c);
	wire w;
	and and1(w, a, b);
	and and2(y, w, c);
endmodule
