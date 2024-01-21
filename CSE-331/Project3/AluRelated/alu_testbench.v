module alu_testbench();
	reg [31:0] a;
	reg [31:0] b;
	reg [2:0] sel;

	wire [31:0]result;
	reg clk;
	reg reset;
	wire zero_bit;
	
	//fulladder_gm fa1(.a(a), .b(b), .cin(cin), .g(g), .p(p), .sum(sum));
	
	//cl_adder_4 adder(.a({a[3], a[2], a[1], a[0]}), .b({b[3], b[2], b[1], b[0]}), .cin(cin), .cout(cout), .s({sum[3], sum[2], sum[1], sum[0]}));
	/*module mux2x1 (output [3:0] result, input [3:0] result1, input [3:0] result2, input sel);*/
	//subtractor_32 sub(a, b, cout, result);
	
	//module mod_fsm (input wire clk, input wire reset, output reg [31:0] result, input [31:0] a, b);
	
	always #5 clk = ~clk;

//	mod mod1(clk, reset, result, a, b);
	alu alu1(clk, reset, result, zero_bit, sel, a, b);

	initial begin
		clk = 0;
		#100 a= 10; b= 3; sel = 0;

		#5000 $display("time: %0t, a:%d b:%d sel:%d(and) result:%d, zero_bit:%b ", $time,a,b,sel, result, zero_bit);


		#100 a= 10; b= 3; sel = 1;


		#5000 $display("time: %0t, a:%d b:%d sel:%d(or) result:%d, zero_bit:%b ", $time,a,b,sel, result, zero_bit);
		#100 a= 10; b= 3; sel = 2;


		#5000 $display("time: %0t, a:%d b:%d sel:%d(xor) result:%d, zero_bit:%b ", $time,a,b,sel, result, zero_bit);
		#100 a= 10; b= 3; sel = 3;

		#5000 $display("time: %0t, a:%d b:%d sel:%d(nor) result:%d, zero_bit:%b ", $time,a,b,sel, result, zero_bit);
		#100 a= 10; b= 3; sel = 4;


		#5000 $display("time: %0t, a:%d b:%d sel:%d(lessthan) result:%d, zero_bit:%b ", $time,a,b,sel, result, zero_bit);
		#100 a= 10; b= 3; sel = 5;


		#5000 $display("time: %0t, a:%d b:%d sel:%d(add) result:%d, zero_bit:%b ", $time,a,b,sel, result, zero_bit);
		#100 a= 10; b= 3; sel = 6;


		#5000 $display("time: %0t, a:%d b:%d sel:%d(sub) result:%d ", $time,a,b,sel, result);
		#100 a= 10; b= 3; sel = 7; reset = 1;
		#500 reset = 0;

		#5000 $display("time: %0t, a:%d b:%d sel:%d(mod) result:%d ", $time,a,b,sel, result);
	end

endmodule

