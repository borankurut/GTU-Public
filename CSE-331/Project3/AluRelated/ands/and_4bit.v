module and_4bit(output [3:0] out, input [3:0] a, b);

	and and1(out[0],a[0],b[0]);
	and and2(out[1],a[1],b[1]);
	and and3(out[2],a[2],b[2]);
	and and4(out[3],a[3],b[3]);

endmodule
