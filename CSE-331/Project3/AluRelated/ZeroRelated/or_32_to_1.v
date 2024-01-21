module or_32_to_1(
	output wire result,
	input [31:0] i
);

   wire w0, w1, w2, w3, w4, w5, w6, w7, w8, w9;

   or_4 or0 (w0, i[0], i[1], i[2], i[3]);
   or_4 or1 (w1, i[4], i[5], i[6], i[7]);
   or_4 or2 (w2, i[8], i[9], i[10], i[11]);
   or_4 or3 (w3, i[12], i[13], i[14], i[15]);
   or_4 or4 (w4, i[16], i[17], i[18], i[19]);
   or_4 or5 (w5, i[20], i[21], i[22], i[23]);
   or_4 or6 (w6, i[24], i[25], i[26], i[27]);
   or_4 or7 (w7, i[28], i[29], i[30], i[31]);

   or_4 or8 (w8, w0, w1, w2, w3);
   or_4 or9 (w9, w4, w5, w6, w7);

   or or10(result, w8, w9);

endmodule

