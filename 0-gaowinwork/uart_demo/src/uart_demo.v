`timescale 1ns/1ns  
module uart_demo (
    input                   clk,
    input                   rst_n,
    input                   key_i,
    input             [3:0] switch_i,
    output            [3:0] led_o,  
    input                   rx_i,
    output                  tx_o
);

    localparam CLK_FREQ_Hz = 27000000;
    localparam BAUD_RATE   = 9600;
    localparam DATA_WIDTH  = 8;
    localparam PARITY      = "NONE";//"NONE""ODD""EVEN"
    
    wire rst = ~rst_n;

    wire key_db;
    key_db #(
        .RST_VALUE   (1'b1),
        .CLK_FREQ_Hz (CLK_FREQ_Hz)
    ) key_db_i (
        .clk            (clk),
        .rst            (rst),
        .key_i          (key_i),
        .key_db_o       (key_db)
    );
    
    uart_rx #(
        .CLK_FREQ_Hz (CLK_FREQ_Hz),
        .BAUD_RATE   (BAUD_RATE),
        .DATA_WIDTH  (DATA_WIDTH),
        .PARITY      (PARITY)
    ) uart_rx_i (
        .clk            (clk),
        .rst            (rst),
        .rx_i           (rx_i),
        .data_vld_o     (),
        .data_o         (led_o[3:0])
    );
    
    uart_tx #(
        .CLK_FREQ_Hz (CLK_FREQ_Hz),
        .BAUD_RATE   (BAUD_RATE),
        .DATA_WIDTH  (DATA_WIDTH),
        .PARITY      (PARITY)
    ) uart_tx_i (
        .clk            (clk),
        .rst            (rst),
        .data_en_i      (key_db),
        .data_i      (switch_i[3:0]),
        .tx_o           (tx_o )
    );

endmodule