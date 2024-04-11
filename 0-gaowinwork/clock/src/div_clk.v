`timescale 1ns / 1ps
`define UD #1
module div_clk #(
    parameter     CLK_FRE  = 26'd50_000_000
)
(
	input clk,
	output  clk_100khz
);
//times =500 :20ns*500=10us=1khz;
parameter CLK_DIV_10US = CLK_FRE/100_000;
reg [8:0]cnt;
always @(posedge clk)
begin
	if(cnt == CLK_DIV_10US - 1'b1)
		cnt<= `UD 9'd0;
	else 
		cnt <= `UD cnt + 1'b1;
end  

reg flag=1'b0;
always @(posedge clk)
begin
	if(cnt == (CLK_DIV_10US>>1) - 1'b1)
		flag <= `UD 1'b1;
	else if(cnt == CLK_DIV_10US - 1'b1)
		flag <= `UD 1'b0;
end 
assign clk_100khz = flag;

endmodule