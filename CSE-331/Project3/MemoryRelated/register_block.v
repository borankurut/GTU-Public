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

    reg [31:0] registers [31:0];

    always @(read_reg1 or read_reg2 or write_reg or regWrite or write_data) begin
		$readmemb("registers.mem", registers);
        if (regWrite) begin
            registers[write_reg] = write_data;
			$writememb("registers.mem", registers);
        end
    end

    // Read from the specified address
    assign read_data1 = registers[read_reg1];
    assign read_data2 = registers[read_reg2];

endmodule

