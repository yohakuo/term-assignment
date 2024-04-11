`timescale 1ns/1ns
module seg_scan_demo(
     input  clk,
     input    rst_n,
     output [3:0]   dig_o,
     output [7:0]   seg_o
);
   assign rst =~rst_n;
   seg_ctrl #(
    .DIG_WIDTH (4)
  ) seg_ctrl_i(
    .clk    (clk),
    .rst    (rst),
    .data_i (16'h1234),
    .dig_o  (dig_o[3:0]),
    .seg_o  (seg_o[7:0])
);

endmodule
