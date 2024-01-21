module cl_adder_4(input[3:0] a, b, input cin, output g_o, p_o, output[3:0] s);
	
	wire [3:0] g, p;

	wire [2:0] couts;

	cla_gen_4 gen(
		.cin(cin), 
		.g({g[3], g[2], g[1], g[0]}),
		.p({p[3], p[2], p[1], p[0]}), 
		.g_o(g_o), 
		.p_o(p_o), 
		.cout({couts[2], couts[1], couts[0]})
	);
	
	fulladder_gm fa1(.a(a[0]), .b(b[0]), .cin(cin), .g(g[0]), .p(p[0]), .sum(s[0]));
	fulladder_gm fa2(.a(a[1]), .b(b[1]), .cin(couts[0]), .g(g[1]), .p(p[1]), .sum(s[1]));
	fulladder_gm fa3(.a(a[2]), .b(b[2]), .cin(couts[1]), .g(g[2]), .p(p[2]), .sum(s[2]));
	fulladder_gm fa4(.a(a[3]), .b(b[3]), .cin(couts[2]), .g(g[3]), .p(p[3]), .sum(s[3]));

endmodule
