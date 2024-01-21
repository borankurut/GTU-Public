module control_tb();

	/*
	module register_block(
		output wire [31:0] read_data1,
		output wire[31:0] read_data2,

		input byteOperations,
		input [31:0] write_data,
		input [4:0] read_reg1,
		input [4:0] read_reg2,
		input [4:0] write_reg,
		input regWrite
	);
	*/

	wire [2:0] alu_ctr;
	reg [5:0] function_code;
	reg [2:0] ALUop;

	alu_control ac(alu_ctr, function_code, ALUop);
	
	initial begin
		function_code = 6'b000000; ALUop = 3'b000;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000000; ALUop = 3'b001;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000000; ALUop = 3'b100;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000000; ALUop = 3'b101;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000000; ALUop = 3'b110;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000010; ALUop = 3'b111;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000011; ALUop = 3'b111;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000100; ALUop = 3'b111;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000101; ALUop = 3'b111;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

		function_code = 6'b000111; ALUop = 3'b111;
		#50 $display("ac:time:%0t, alu_ctr:%b, function_code:%b, ALUop:%b", $time, alu_ctr, function_code, ALUop);

	end

endmodule

