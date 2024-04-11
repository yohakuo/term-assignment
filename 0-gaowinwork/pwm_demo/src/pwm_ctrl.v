`timescale 1ns/1ns

module pwm_ctrl(
    input         clk,
    input         rst,
    input         enable_i,
    input  [15:0] thres_i,
    output        pwm_o
);

    wire [15:0] count;
    counter #(
        .WIDTH       (16),
        .DATA_MAX    (16'hffff)
    ) counter_i (
        .clk         (clk),
        .rst         (rst),
        .pulse_i     (1'b1),
        .cout_o      (),
        .count_o     (count[15:0])
    );

    assign pwm_o = (count[15:0] < thres_i[15:0]) ? 1'b1 : 1'b0;

endmodule 