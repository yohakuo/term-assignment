`timescale 1ns/1ns  

module uart_rx #(
    parameter CLK_FREQ_Hz = 27000000,
    parameter BAUD_RATE   = 9600,
    parameter DATA_WIDTH  = 8,
    parameter PARITY      = "NONE" // "NONE" "ODD" "EVEN"
)(
    input                   clk,
    input                   rst,
    input                   rx_i,
    output                  data_vld_o,
    output [DATA_WIDTH-1:0] data_o
);

    localparam SIM_DELAY = 1;
    localparam FRAME_BITS = PARITY == "NONE" ? DATA_WIDTH+3 : DATA_WIDTH+4;

    reg [2:0] rx_d;
    wire rx_negedge = (rx_d[1] == 1'b0) && (rx_d[2] == 1'b1);
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            rx_d[2:0] <= #SIM_DELAY 3'h7;
        end else begin 
            rx_d[2:0] <= #SIM_DELAY {rx_d[1:0],rx_i};
        end
    end

    reg busy;
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            busy <= #SIM_DELAY 1'b0;
        end else if(rx_negedge) begin 
            busy <= #SIM_DELAY 1'b1;
        end else if(frame_done) begin 
            busy <= #SIM_DELAY 1'b0;
        end
    end

    wire clk_sample;
    freq_div #(
        .DIV_RATE_2N (CLK_FREQ_Hz/BAUD_RATE)
    ) freq_div_i (
        .clk_in_i   (clk),
        .rst_i      (rst|(~busy)),
        .clk_out_o  (clk_sample)
    );

    wire [FRAME_BITS-1:0] bits;
    shift_reg #(
        .DIRECTION  ("RIGHT"),
        .WIDTH      (FRAME_BITS),
        .INIT_VALUE ({FRAME_BITS{1'b1}})
    ) shift_reg_i (
        .clk            (clk_sample),
        .rst            (rst),
        .load_i         (1'b0),
        .load_data_i    ({FRAME_BITS{1'b1}}),
        .reg_in_i       (rx_i),
        .reg_out_o      (bits)
    );

    wire farme_done;
    counter #(
        .WIDTH      (4),
        .DATA_MAX   (FRAME_BITS-1)
    ) counter_i2 (
        .clk        (~clk_sample),
        .rst        (rst|(~busy)),
        .pulse_i    (1'b1),
        .cout_o     (frame_done),
        .count_o    ()
     );
        
    assign data_vld_o = frame_done;
    assign data_o     = bits[FRAME_BITS-3:1];

endmodule