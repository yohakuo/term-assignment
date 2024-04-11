`timescale 1ns/1ns

module freq_div #(
    parameter DIV_RATE_2N = 10
)(
    input      clk_in_i,
    input      rst_i,
    output reg clk_out_o
);

    localparam SIM_DELAY = 1;
    localparam CNT_WIDTH = $clog2(DIV_RATE_2N);

    reg [CNT_WIDTH-1:0] counter;
    always @(posedge clk_in_i or posedge rst_i) begin
        if(rst_i) begin
            counter         <= #SIM_DELAY 0;
            clk_out_o       <= #SIM_DELAY 0;
        end else begin
            if(counter < DIV_RATE_2N/2-1) begin
                counter     <= #SIM_DELAY counter + 1;
            end else begin
                counter     <= #SIM_DELAY 0;
                clk_out_o   <= #SIM_DELAY ~clk_out_o;
            end
        end
    end

endmodule 