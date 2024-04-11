`timescale 1ns/1ns
module seg_ctrl #(
    parameter DIG_WIDTH =4
)(
   input    clk,
   input    rst,
   input [DIG_WIDTH*4-1:0] data_i,
   output [DIG_WIDTH-1:0]   dig_o,
   output [7:0]      seg_o
);

  localparam CLK_IN_FREQ =1000000;   //越小越稳定
  wire clk_100Hz;

   freq_div #(
    .DIV_RATE_2N (CLK_IN_FREQ/100)
) freq_div_i (
   .clk_in_i (clk),
   .rst_i    (rst),
   .clk_out_o  (clk_100Hz)
);

    shift_reg #(
    .WIDTH   (4),
    .INIT_VALUE (4'h1)
)shift_reg_i (
    .clk          (clk_100Hz),
    .rst          (rst),
    .load_i       (1'b0),
    .load_data_i  (4'h0),
    .reg_in_i     (dig_o[3]),
    .reg_out_o    (dig_o[3:0])
);

   wire [3:0] data_sel;
   mux_4x4 mux_4x4_i(
    .index_i      (dig_o[3:0]),
    .data_i       (data_i[15:0]),
    .data_o       (data_sel[3:0])
);
   seg_decode seg_decode_i(
    .data_i       (data_sel[3:0]),
    .seg_code_o    (seg_o[7:0])
);
endmodule
