module memory_testbench();

	wire[31:0] read_data1;
	wire[31:0] read_data2;

	reg byteOperations;
	reg[31:0] write_data;
	reg[4:0] read_reg1;
	reg[4:0] read_reg2;
	reg[4:0] write_reg;
	reg regWrite;

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

	register_block rb(read_data1, read_data2, byteOperations, write_data, read_reg1, read_reg2, write_reg, regWrite);
	
	initial begin
		byteOperations = 0; write_data = 100; read_reg1 = 1; read_reg2 = 2; write_reg = 0; regWrite = 1;
		#50 $display("rb:time:%0t, rd1:%d, rd2:%d, byteop:%d, writ_data:%d, rreg1:%d, rreg2:%d, wreg:%d, regWrite:%d", $time, read_data1, read_data2, byteOperations, write_data, read_reg1, read_reg2, write_reg, regWrite);

		byteOperations = 0; write_data = 0; read_reg1 = 0; read_reg2 = 1; write_reg = 0; regWrite = 0;
		#50 $display("rb:time:%0t, rd1:%d, rd2:%d, byteop:%d, writ_data:%d, rreg1:%d, rreg2:%d, wreg:%d, regWrite:%d", $time, read_data1, read_data2, byteOperations, write_data, read_reg1, read_reg2, write_reg, regWrite);

	end

endmodule

