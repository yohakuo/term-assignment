module key_filter 
(
    input wire clk,
    input wire rst,
    input wire key_i,
    output reg key_db_o//输出按键标志

);

parameter CNT_MAX=20'd999_999;//延时计数值
reg [19:0] cnt_20ms;//延时判断值
always @(posedge clk or negedge rst) begin//按键检测加延时消抖模块
    if(!rst)//复位
    cnt_20ms<=  20'd0;
    else if(key_i==1'b1)
    cnt_20ms<=  20'd0;
    else if(cnt_20ms==CNT_MAX)
    cnt_20ms<=CNT_MAX;
    else
    cnt_20ms<=cnt_20ms+20'd1;
end
always @(posedge clk or negedge rst) begin
    if(!rst)
    key_db_o<=1'b0;
    else if (cnt_20ms==(CNT_MAX-20'd1)) begin
         key_db_o<=1'b1;//按键信号产生
    end
    else 
    key_db_o<=1'b0;
end
endmodule