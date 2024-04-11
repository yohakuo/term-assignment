`timescale 1ns/1ns

module key_db #(
    parameter RST_VALUE   = 1'b0,
    parameter CLK_FREQ_Hz = 27000000
)(
    input       clk,
    input       rst,
    input       key_i,
    output      key_db_o
);

wire clk_100Hz;

    freq_div #(
        .DIV_RATE_2N (CLK_FREQ_Hz/100)
    ) freq_div_i (
        .clk_in_i    (clk),
        .rst_i       (rst),
        .clk_out_o   (clk_100Hz)
    );

    wire [2:0] samples;    
    shift_reg #(
        .WIDTH       (3),
        .INIT_VALUE  ({3{RST_VALUE[0]}})
    ) shift_reg_i (
        .clk         (clk_100Hz),
        .rst         (rst),
        .load_i      (1'b0),
        .load_data_i (3'h0),
        .reg_in_i    (key_i),
        .reg_out_o   (samples[2:0])
    );

    assign key_db_o = RST_VALUE ? |samples[2:0] : &samples[2:0];

endmodule 