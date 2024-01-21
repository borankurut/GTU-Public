module mux2x1_4bit (output [3:0] result, input [3:0] result1, input [3:0] result2, input sel);

	wire [3:0] result_1;
	wire [3:0] result_2;
	wire [3:0] select;
	wire [3:0] select_not;
	// sel -> 1  select = 1111             sel -> 0    select = 0000
	
	or or1 (select[0], sel, sel);
	or or2 (select[1], sel, sel);
	or or3 (select[2], sel, sel);
	or or4 (select[3], sel, sel);
	
	// if sel == 0   ->> result = result1 (and)
	not not1 (sel_not, sel);
	or or9 (select_not[0], sel_not, sel_not);
	or or10 (select_not[1], sel_not, sel_not);
	or or11 (select_not[2], sel_not, sel_not);
	or or12 (select_not[3], sel_not, sel_not);
	and_4bit and1 (result_1, result1, select_not);
	

	// if sel == 1   ->> result = result2 (add)
	and_4bit and2 (result_2, result2, select);
	
	
	or or5 (result[0], result_1[0], result_2[0]);
	or or6 (result[1], result_1[1], result_2[1]);
	or or7 (result[2], result_1[2], result_2[2]);
	or or8 (result[3], result_1[3], result_2[3]);
	

endmodule

