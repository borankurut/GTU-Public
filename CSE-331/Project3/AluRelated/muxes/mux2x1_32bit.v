module mux2x1_32bit(output [31:0] result, input [31:0] in0, input [31:0] in1, input sel);

	mux2x1_4bit mux1(result[3:0], in0[3:0], in1[3:0], sel);
	mux2x1_4bit mux2(result[7:4], in0[7:4], in1[7:4], sel);
	mux2x1_4bit mux3(result[11:8], in0[11:8], in1[11:8], sel);
	mux2x1_4bit mux4(result[15:12], in0[15:12], in1[15:12], sel);
	mux2x1_4bit mux5(result[19:16], in0[19:16], in1[19:16], sel);
	mux2x1_4bit mux6(result[23:20], in0[23:20], in1[23:20], sel);
	mux2x1_4bit mux7(result[27:24], in0[27:24], in1[27:24], sel);
	mux2x1_4bit mux8(result[31:28], in0[31:28], in1[31:28], sel);

endmodule

