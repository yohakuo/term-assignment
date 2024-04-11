`timescale 1ns/1ns

module counter #(
    parameter WIDTH    = 4,
    parameter DATA_MAX = 15
)(
    input                  clk,
    input                  rst,
    input                  pulse_i,
    output reg             cout_o,
    output reg [WIDTH-1:0] count_o
);

    localparam SIM_DELAY = 1;

    always @(posedge clk or posedge rst) begin
        if(rst) begin
            cout_o          <= #SIM_DELAY 0;
            count_o         <= #SIM_DELAY 0;
        end else if (pulse_i) begin
            if(count_o < DATA_MAX) begin
                cout_o      <= #SIM_DELAY 1'b0;
                count_o     <= #SIM_DELAY count_o + 1;
            end else begin
                cout_o      <= #SIM_DELAY 1'b1;
                count_o     <= #SIM_DELAY 0;
            end
        end
    end

endmodule 