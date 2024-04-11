`timescale 1ns/1ns

module pwm_demo(
    input  clk,
    input  rst_n,
    input  key_i,
    output led_o
);

    wire rst = ~rst_n;

    wire key_db;
    key_db key_db_i(
        .clk         (clk),
        .rst         (rst),
        .key_i       (key_i),
        .key_db_o    (key_db)
    );

    wire [3:0] thres;
    counter #(
        .WIDTH       (4),
        .DATA_MAX    (15)
    ) counter_i (
        .clk         (key_db),
        .rst         (rst),
        .pulse_i     (1'b1),
        .cout_o      (),
        .count_o     (thres[3:0])
    );

    pwm_ctrl pwm_ctrl_i(
        .clk        (clk),
        .rst        (rst),
        .enable_i   (1'b1),
        .thres_i    ({thres[3:0], 12'hfff}),
        .pwm_o      (led_o)
    );

endmodule 