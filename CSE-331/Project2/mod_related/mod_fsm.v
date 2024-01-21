// module mod_fsm (input wire clk, input wire reset, output reg [31:0] result, input [31:0] a, b);
//
// 	parameter STATE0 = 0;
// 	parameter STATE1 = 1;
// 	parameter STATE2 = 2;
// 	
// 	reg [1:0] state;
// 	reg [1:0] next_state;
//
// 	reg [31:0] temp;
//
// 	wire [31:0] temp_minus_b;
// 	wire [31:0] temp_min_b_lt_b;
// 	wire cout;
//
// 	subtractor_32 sub1(temp, b, cout, temp_minus_b);
//
// 	lessthan_32 lt1(temp_min_b_lt_b, temp_minus_b, b);
//
// 	always @(posedge clk) begin 
// 		if (reset)
// 			state <= STATE0;
// 		else
// 			state <= next_state;
// 	end
// 	
// 	
// 	always @(posedge clk) begin
// 		if (reset) 
// 			next_state <= STATE0;
// 		else if(state == STATE0)
// 			next_state <= STATE1;
// 		else if(state == STATE1) begin
// 			if(temp_min_b_lt_b[0] == 1) begin // we need temp at end of state1.
// 				next_state <= STATE2;
// 				result <= temp;
// 			end
// 			else
// 				next_state <= STATE1;
// 		end	
//
// 		else if(state == STATE2)
// 			next_state <= STATE2;
// 	end
// 	
// 	always @(posedge clk) begin
// 		if (state == STATE0) 
// 			temp <= a;	
// 		else if (state == STATE1)
// 			temp <= temp_minus_b;
// 	end
//
// 	// always @(posedge clk) begin //debug
// 	// 	if(state != STATE2)
// 	// 		$display("state: %d, temp: %d", state, temp);
// 	// end
//
// endmodule 
//
//
