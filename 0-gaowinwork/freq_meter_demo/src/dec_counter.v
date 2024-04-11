`timescale 1ns/1ns
module dec_counter#(
    parameter DIG_WIDTH = 8
)(
    input                    clk,
    input                    rst,
    input                    enable_i,               
    output                   cout_o,
    output [DIG_WIDTH*4-1:0] count_o
);

    wire [DIG_WIDTH:0] cout;
    assign cout[0] = clk;
    assign cout_o = cout[DIG_WIDTH];

    genvar i;
    generate
    for(i=0;i<DIG_WIDTH;i=i+1) begin : CNT_GEN
        counter #(
            .WIDTH      (4),
            .DATA_MAX   (9)
        ) counter_i0 (
            .clk        (cout[i]),
            .rst        (rst),
            .pulse_i    (enable_i),
            .cout_o     (cout[i+1]),
            .count_o    (count_o[4*(i+1)-1:4*i])
        );
    end
    endgenerate

endmodule
