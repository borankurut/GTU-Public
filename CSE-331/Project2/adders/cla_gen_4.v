module cla_gen_4(
	input cin, 
	input [3:0] g,
	input[3:0] p, 
	output g_o, 
	output p_o, 
	output [2:0] cout
);

	wire c0p0;
	wire c0p0p1, g0p1;
	wire c0p0p1p2, g0p1p2, g1p2;

	and and1_1(c0p0, cin, p[0]);

	and and2_1(c0p0p1, c0p0, p[1]);
	and and2_2(g0p1, g[0], p[1]);

	and and3_1(c0p0p1p2, c0p0p1, p[2]);
	and and3_2(g0p1p2, g0p1, p[2]);
	and and3_3(g1p2, g[1], p[2]);


	wire g0p1p2p3, g1p2p3, g2p3; //for g_o

	and andg1(g0p1p2p3, g0p1p2, p[3]);
	and andg2(g1p2p3, g1p2, p[3]);
	and andg3(g2p3, g[2], p[3]);

	and_4 and4_1(p_o, p[0], p[1], p[2], p[3]); // p_0 p_o = p1p2p3p4
	or_4 or4_1(g_o, g0p1p2p3, g1p2p3, g2p3, g[3]); // g_0

	//cout
	or or_r1(cout[0], c0p0, g[0]);
	or_3 or_r2(cout[1], c0p0p1, g0p1, g[1]);
	or_4 or_r3(cout[2], c0p0p1p2, g0p1p2, g1p2, g[2]);

endmodule

