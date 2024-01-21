module mod(input wire clk, input wire reset, output reg [31:0] result, input [31:0] a, b);
	parameter STATE0 = 0;
	parameter STATE1 = 1;
	parameter STATE2 = 2;
	
	reg [1:0] state;
	wire [1:0] next_state_wire;

	reg [31:0] temp;

	wire [31:0] temp_minus_b;
	wire temp_min_b_lt_b;

//	module mod_dp (output temp_min_b_lt_b, output[31:0] temp_minus_b, input [31:0] temp, b);
//	module mod_cu(input wire clk, input reg[1:0] state, output reg[1:0] next_state, input wire reset, input temp_min_b_lt_b);

	mod_cu cu1(state, next_state_wire, reset, temp_min_b_lt_b);
	mod_dp dp1(temp_min_b_lt_b, temp_minus_b, temp, b);

	always @(posedge clk) begin 
		if (reset)
			state <= STATE0;
		else
			state <= next_state_wire;
	end

	always @(posedge clk) begin
		if (state == STATE0) 
			temp <= a;	
		else if (state == STATE1)
			temp <= temp_minus_b;
		else if(state == STATE2)
			result <= temp;
	end

	// always @(posedge clk) begin //debug
	// 	if(state != STATE2)
	// 		$display("time:%0t, state: %d, temp: %d, tempminbltb:%b",$time, state, temp, temp_min_b_lt_b);
	// end

endmodule 

