`timescale 1ns/1ns

module freq_meter_demo(
    input       clk,
    input       rst_n,
    output [3:0]clk_out_o,
    input       clk_in_i,
    output [3:0]dig_o,
    output [7:0]seg_o
);

    localparam CLK_FREQ_Hz = 27000000;
    
    wire rst=~rst_n;

    genvar i;
    generate
    for(i=0;i<4;i=i+1) begin :FREQ_DIV_GEN
        freq_div #(
            .DIV_RATE_2N ((i+1)*2)
        ) freq_div_i (
            .clk_in_i   (clk),
            .rst_i      (rst),
            .clk_out_o  (clk_out_o[i])
        );
        end
        endgenerate
    
        wire cout_1s;
        wire clear;
        wire count_en;
        wire lock;
        state_ctrl  state_ctrl_i(
            .clk        (clk),
            .rst        (rst),
            
            .cout_i     (cout_1s),
            .clear_o    (clear),
            .count_en_o (count_en),
            .lock_o     (lock)
        );

        counter #(
            .WIDTH      ($clog2(CLK_FREQ_Hz)),
            .DATA_MAX   (CLK_FREQ_Hz-1)
        ) counter_i0 (
            .clk        (clk),
            .rst        (rst|clear),
            .pulse_i    (count_en),
            .cout_o     (cout_1s),
            .count_o    ()
        );

        wire [8*4-1:0] freq;
        dec_counter #(
             .DIG_WIDTH   (8)
         )(
             .clk        (clk_in_i),
             .rst        (rst|clear),
             .enable_i   (count_en),
             .cout_o     (),
             .count_o    (freq)
         );
    
         reg [15:0] freq_reg;
         always @(posedge clk or posedge rst) begin
            if(rst) begin   
                freq_reg[15:0] <=16'h0;
            end else if(lock) begin
                freq_reg[15:0] <=freq[31:16];
            end
          end

        seg_ctrl #(
            .DIG_WIDTH  (4)
        ) seg_ctrl_i (
            .clk        (clk),
            .rst        (rst),
            .data_i     (freq_reg[15:0]),
            .dig_o      (dig_o[3:0]),
            .seg_o      (seg_o[7:0])
        );
    
    endmodule

