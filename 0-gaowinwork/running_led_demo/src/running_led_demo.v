`timescale 1ns/1ns

module running_led_demo(
    input       clk,
    input       rst_n,
    output [7:0] led_o
);

    localparam CLK_IN_FREQ = 27000000;
    wire clk_1Hz;
    wire [8:0] reg_out;
    assign rst = ~rst_n;

    freq_div #(
        .DIV_RATE_2N (CLK_IN_FREQ)
    ) freq_div_i(
        .clk_in_i (clk),
        .rst_i    (rst),
        .clk_out_o (clk_1Hz)
    );

shift_reg #(
    .WIDTH (9),
    .INIT_VALUE (9'h1)
)   shift_reg_i(
    .clk (clk_1Hz),
    .rst (rst),
    .load_i (1'b0),
    .load_data_i (9'h0),
    .reg_in_i (reg_out[8]),
    .reg_out_o (reg_out)
);

    assign led_o[7:0] = ~reg_out[8:1];

endmodule