module mux8x1_32bit(
	output [31:0] result, 

	input [31:0] in0, 
	input [31:0] in1, 
	input [31:0] in2, 
	input [31:0] in3, 
	input [31:0] in4, 
	input [31:0] in5, 
	input [31:0] in6, 
	input [31:0] in7, 

	input [2:0] sel
);

	wire [31:0] w1,w2,w3,w4,w5,w6;

	mux2x1_32bit mux0(w1, in0,in1,sel[0]);
	mux2x1_32bit mux1(w2, in2,in3,sel[0]);
	mux2x1_32bit mux2(w3, in4,in5,sel[0]);
	mux2x1_32bit mux3(w4, in6,in7,sel[0]);

	mux2x1_32bit mux4(w5, w1,w2,sel[1]);
	mux2x1_32bit mux5(w6, w3,w4,sel[1]);

	mux2x1_32bit mux6(result, w5, w6,sel[2]);

endmodule

