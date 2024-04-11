module shizhong_demo(
input clk,  //22
input rst_n,  //20 
input key_i_1, //27  按下加一
input key_i_2, //28
input key_i_3, //29
input key_i_pause, //30
output reg [3:0]sel_seg,//位选 43 44 45 46
output reg [7:0]seg_led//段选  31-32 34-35 39-40 41-42

);


wire [3:0]shuju0;//秒个位
wire [3:0]shuju1;//秒十位
wire [3:0]shuju2;//分个位
wire [3:0]shuju3;//分十位
wire [3:0]shuju4;//时个位
wire [3:0]shuju5;//时十位
assign shuju5=(hour+adjust_time_shi)/4'd10;//数码管显示数据处理
assign shuju4=(hour+adjust_time_shi)%4'd10;
assign shuju3=(min+adjust_time_fen )/4'd10;
assign shuju2=(min +adjust_time_fen)%4'd10;
assign shuju1=sec/4'd10;
assign shuju0=sec%4'd10;
 

reg [7:0]naomin;
reg [7:0]naohour;

wire [3:0]naoshuju2;//分个位
wire [3:0]naoshuju3;//分十位
wire [3:0]naoshuju4;//时个位
wire [3:0]naoshuju5;//时十位
assign naoshuju5=(naohour+adjust_nao_shi)/4'd10;//数码管显示数据处理
assign naoshuju4=(naohour+adjust_nao_shi)%4'd10;
assign naoshuju3=(naomin +adjust_nao_fen)/4'd10;
assign naoshuju2=(naomin +adjust_nao_fen)%4'd10;



wire rst=~rst_n;
wire clk_sec;
wire clk_shuma;

//秒分频  产生1hz的方波信号
localparam CLK_IN_FREQ=27000000;
freq_div #(
    .DIV_RATE_2N(CLK_IN_FREQ)
)  freq_div_i0 (
    .clk (clk),
    .rst (rst),
    .clk_out_o (clk_sec)
);

//生成数码管刷新的方波信号 1khz
freq_div #(
    .DIV_RATE_2N(CLK_IN_FREQ/1000)
)  freq_div_i1 (
    .clk (clk),
    .rst (rst),
    .clk_out_o (clk_shuma)
);


key_db(clk,rst,key_i_pause,key_flag_pause);//暂停标志位
reg [1:0]flag_pause;
always @(posedge key_flag_pause) begin
    if(flag_pause==1'b0)
    flag_pause<=1'b1;
    else if(flag_pause==1'b1)
    flag_pause<=1'b0;   
end

wire [7:0]sec;
wire [7:0]min;
wire [7:0]hour;
wire flag_sec;
wire flag_min;

//秒计数模块
counter #(
    .WIDTH (6),
    .DATA_MAX (59)
) counter_i0 (
    .clk  (clk_sec),
    .rst  (rst),
    .pulse_i  (1'b1),
    .cout_o  (flag_sec),
    .count_o  (sec)
);

//分计数模块
counter #(
    .WIDTH (6),
    .DATA_MAX (59)
) counter_i1 (
    .clk (flag_sec),
    .rst (rst),
    .pulse_i (1'b1),
    .cout_o (flag_min),
    .count_o (min)
);


//时计数模块
counter #(
    .WIDTH (6),
    .DATA_MAX (59)
) counter_i2 (
    .clk (flag_min),
    .rst (rst),
    .pulse_i (1'b1),
    .cout_o (),
    .count_o (hour)
);

//按键调时
key_db(clk,rst,key_i_1,key_flag_1);
key_db(clk,rst,key_i_2,key_flag_2);
key_db(clk,rst,key_i_3,key_flag_3);

reg [2:0]cnt_key_flag;
reg [7:0]adjust_time_fen;
reg [7:0]adjust_time_shi; 
reg [7:0]adjust_nao_shi;
reg [7:0]adjust_nao_fen;
reg save_key_flag_2;
reg save_key_flag_3;
always @(posedge key_flag_1) begin//菜单标志位选择
    cnt_key_flag<=cnt_key_flag+1'b1;
    if (cnt_key_flag==4) begin
        cnt_key_flag<=1'b0;
    end
end



reg [3:0]display_num;
reg [2:0]cnt0;//位选计数

always @(posedge clk_shuma or negedge rst)begin
    if(!rst)begin
        cnt0<=3'd0;
        end
    else begin
        if(cnt0==3'd3)
            cnt0<=3'd0;
        else cnt0<=cnt0+1'b1;
    end
end

wire [2:0]cnt_shuma_flag;
assign cnt_shuma_flag=cnt_key_flag; //
always @(cnt0)
        begin
            if ((cnt_shuma_flag==3'd0)||(cnt_shuma_flag==3'd1)) 
            begin
                case(cnt0)//位选
                3'd0:begin
                display_num<=shuju0;
                sel_seg<=6'b1110;
                end
                3'd1:begin
 display_num<=shuju1;
                sel_seg<=6'b1101;
                end
                3'd2:begin
                display_num<=shuju2;
                sel_seg<=6'b1011;
                end
                3'd3:begin
                display_num<=shuju3;
                sel_seg<=6'b0111;
                end   
                default:begin
                sel_seg<=6'b1111;
                display_num<=4'd0;
                end
                endcase
            end
            else  if(cnt_shuma_flag==3'd2||cnt_shuma_flag==3'd3) //闹钟位选关闭秒位
            begin
                case(cnt0)//位选
                3'd0:begin
                //display_num<=naoshuju0;
                sel_seg<=6'b1111;
                end
                3'd1:begin
                //display_num<=naoshuju1;
                sel_seg<=6'b1111;
                end
                3'd2:begin
                display_num<=naoshuju2;
                sel_seg<=6'b1110;
  end
                3'd3:begin
                display_num<=naoshuju3;
                sel_seg<=6'b1101;
                end   
                3'd4:begin
                display_num<=naoshuju4;
                sel_seg<=6'b1011;
                end
                3'd5:begin
                display_num<=naoshuju5;
                sel_seg<=6'b0111;
                end
                default:begin
                sel_seg<=6'b1111;
                display_num<=4'd0;
                end
                endcase
            end
    end


endmodule


