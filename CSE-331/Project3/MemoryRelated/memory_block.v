module memory_block (
	output wire [31:0] read_data,
	input byteOperations, 
	input [17:0] address, 
	input [31:0] write_data, 
	input memRead,
	input memWrite
);
    reg [31:0] memory [262143:0]; // 2^18 - 1 : 0

    always @(address or write_data or memRead or memWrite) begin
		$readmemb("memory.mem", registers);
        if (memWrite) begin
            memory[address] = write_data;
			$writememb("memory.mem", registers);
        end
    end

    // Read from the specified address
    assign read_data = memory[memRead];

endmodule
