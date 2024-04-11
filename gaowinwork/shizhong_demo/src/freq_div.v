module freq_div #(
    parameter   DIV_RATE_2N = 10 // 27000000 产生1hz的信号
)(
    input clk,
    input rst,
    output reg clk_out_o
);


    localparam CNT_WIDTH = $clog2(DIV_RATE_2N);

    reg [CNT_WIDTH-1:0] counter;
    always @(posedge clk or posedge rst) begin
        if(rst) begin
            counter     <=  0;
            clk_out_o   <=  0;
        end else begin 
            if(counter < DIV_RATE_2N/2-1) begin
                counter     <=  counter + 1;
            end else begin 
                counter     <=  0;
                clk_out_o    <= ~clk_out_o;
             end
        end
    end


endmodule