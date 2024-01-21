module mod_cu (
  input wire [1:0] state,
  output wire [1:0] next_state,
  input wire reset,
  input wire temp_min_b_lt_b
);

  assign next_state[0] = !reset & ((~state[0] & ~state[1]) | (~temp_min_b_lt_b & state[0] & ~state[1]));
  assign next_state[1] = !reset & ((temp_min_b_lt_b & state[0] & ~state[1]) | (state[1] & ~state[0]));

endmodule

