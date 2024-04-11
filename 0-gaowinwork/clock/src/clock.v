`define UD #1
module clock
(
    input clk, //22
    input [2:0]key,//27 28 
    output led,//20
    output  reg[3:0]dig,//43 44 45 46 
    output reg dp,//23   L1 L2
    output  reg[7:0]smg//31-32 34-35 39-40 41-42
);
  

    parameter CLK_FRE = 26'd50_000_000;

/*===================================================
				复位信号的产生
===================================================*/
reg [4:0] rstn_cnt=0;
always @(posedge clk)
begin
	if(rstn_cnt==5'h1f) //31
		rstn_cnt <= `UD rstn_cnt;
	else 
		rstn_cnt <= `UD rstn_cnt + 1'b1;
end 

wire rstn;
assign rstn = rstn_cnt[4];
/*===================================================
					数字时钟的产生和控制
===================================================*/
wire [3:0] hour_h_o,hour_l_o,minutes_h_o,minutes_l_o;
wire [2:0] state_flag;

watch_data_gen #(
    .CLK_FRE    (CLK_FRE    )
) u_watch_data_gen
(
	.clk		(clk		), 
	.rstn		(rstn		), 
	.key		(key		),
	.hour_h_o	(hour_h_o	), 
	.hour_l_o	(hour_l_o	), 
	.minutes_h_o(minutes_h_o), 
	.minutes_l_o(minutes_l_o), 
	.second_led	(led		), 
	.state_flag (state_flag )  
);


/*===================================================
					时钟分频
===================================================*/
wire clk_100khz;
div_clk #(
    .CLK_FRE    (CLK_FRE    )
)  div_clk
(
	.clk		(clk),
	.clk_100khz (clk_100khz)
);
/*===================================================
					数码管显示
===================================================*/
reg  [1:0]sel=0;
wire [3:0]dig0;
wire [7:0]smg0;

always @(posedge clk_100khz)
begin
	sel <= `UD sel+1'b1;
end 

seq_control seq_control_0
(
	.clk(clk),
	.sec_en(led),
	.control_dig(state_flag),//显示状态state_flag
	.sel(2'd0),              //位选 第一位
	.key(hour_h_o),         
	.dig(dig0),
	.smg(smg0)
);

wire [3:0]dig1;
wire [7:0]smg1;

seq_control seq_control_1
(
	.clk(clk),
	.sec_en(led),
	.control_dig(state_flag),
	.sel(2'd1),
	.key(hour_l_o),
	.dig(dig1),
	.smg(smg1)
);

wire [3:0]dig2;
wire [7:0]smg2;

seq_control seq_control_2
(
	.clk(clk),
	.sec_en(led),
	.control_dig(state_flag),
	.sel(2'd2),
	.key(minutes_h_o),
	.dig(dig2),
	.smg(smg2)
);

wire [3:0]dig3;
wire [7:0]smg3;

seq_control seq_control_3
(
	.clk(clk),
	.sec_en(led),
	.control_dig(state_flag),
	.sel(2'd3),                 //第四位
	.key(minutes_l_o),   
	.dig(dig3),
	.smg(smg3)
);

always @(posedge clk_100khz)
begin
    if(state_flag!=5)
        dp <= 1'b0;
    else if(state_flag==5)
        dp = 1'b1;
end

always @(posedge clk_100khz)
begin
	if(sel==2'b00)
		dig <= `UD dig0;
	else if(sel==2'b01)
		dig <= `UD dig1;
	else if(sel==2'b10)
		dig <= `UD dig2;
	else if(sel==2'b11)
		dig <= `UD dig3;
end 


always @(posedge clk_100khz)
begin
	if(sel==2'b00)
		smg <= `UD smg0;
	else if(sel==2'b01)
		smg <= `UD smg1;
	else if(sel==2'b10)
		smg <= `UD smg2;
	else if(sel==2'b11)
		smg <= `UD smg3;
end



endmodule



















