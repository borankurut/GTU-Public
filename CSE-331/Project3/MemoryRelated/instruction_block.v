module instruction_block (output wire [31:0] instruction,  input [31:0] pc);

    reg [31:0] instructions [1023:0]; // 1024 - 1 : 0

	always @(pc) begin
		$readmemb("instructions.mem", instructions);
	end

	assign instruction = instructions[pc];

endmodule

