module alu_control(
	output [2:0] alu_ctr,
	input [5:0] function_code,
	input [2:0] ALUop
);

	//alu_ctr = aluop if aluop != 111, otherwise look function_code
	//
	wire is_r_type;
	wire[2:0] f_to_alu_ctr;

	wire[3:0] mux_result;

	and_4 and0(is_r_type, ALUop[0], ALUop[1], ALUop[2], 1'b1);

	function_code_to_alu_ctr falu(f_to_alu_ctr, function_code);

	 /*
	 *
module mux2x1_4bit (output [3:0] result, input [3:0] result1, input [3:0] result2, input sel);
		 * */

	mux2x1_4bit mux0(mux_result, {1'b0, ALUop}, {1'b0, f_to_alu_ctr}, is_r_type);

	or or0(alu_ctr[0], mux_result[0], 1'b0);
	or or1(alu_ctr[1], mux_result[1], 1'b0);
	or or2(alu_ctr[2], mux_result[2], 1'b0);


endmodule

