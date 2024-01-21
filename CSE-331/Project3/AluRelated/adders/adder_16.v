module adder_16(input[15:0] a, b, input cin, output cout, output[15:0] result);

//module cl_adder_4(input[3:0] a, b, input cin, output g_o, p_o, output[3:0] s);

/*
module cla_gen_4(
	input cin, 
	input [3:0] g,
	input[3:0] p, 
	output g_o, 
	output p_o, 
	output [2:0] cout
);
*/


	wire [2:0] cins;
	wire [3:0] g;
	wire [3:0] p;
	wire go;
	wire po;
	wire poc0;

	cla_gen_4 level2(cin, g, p, go, po, cins);

	cl_adder_4 a1(a[3:0], b[3:0], cin, g[0], p[0], result[3:0]);

	cl_adder_4 a2(a[7:4], b[7:4], cins[0], g[1], p[1], result[7:4]);

	cl_adder_4 a3(a[11:8], b[11:8], cins[1], g[2], p[2], result[11:8]);

	cl_adder_4 a4(a[15:12], b[15:12], cins[2], g[3], p[3], result[15:12]);

	and and1(poc0, po, cin);
	or or1(cout, poc0, go);

endmodule

