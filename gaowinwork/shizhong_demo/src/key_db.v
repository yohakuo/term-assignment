`timescale 1ns/1ns                                           //按键消抖模块
module key_db #(
   //parameter INVE=1'b1,
   parameter RST_VALUE =1'b0,                                //表示复位时的值，默认为0（低电平）
   parameter CLK_FREQ_Hz =27000000                           //时钟频率，默认值
   //parameter WIDTH =4
)(
   input clk,                                                //时钟信号
   input rst,                                                //复位信号
   input key_i,                                              //按键输入信号
   output  key_db_o                                          //消抖后的按键信号
   //input wire[WIDTH-1:0] key_i, 
   //output wire [WIDTH-1:0] key_db_o  
);
   // wire [15:0] data_selw;//定义一个中间信号，用于选择要显示的数据
  // assign data_selw=(key_i==2'b00)? ~key_db_o :key_db_o;
    //wire [WIDTH-1:0] samples;
   wire clk_100Hz;
   freq_div #(                                               //实例化一个频率分频器模块，将输入信号分频得到100Hz的时钟信号
    .DIV_RATE_2N (CLK_FREQ_Hz/100)                           //分频系数
) freq_div_i( 
   .clk   (clk),
   .rst     (rst),
   .clk_out_o  (clk_100Hz)
);
//分频到100HZ

  wire [2:0] samples;                                         //存储按键信号的采样值
  shift_reg #(                                                //实例化移位寄存器模块
    .WIDTH   (3),
    .INIT_VALUE ({3{RST_VALUE[0]}})
) shift_reg_i(
      .clk   (clk_100Hz),                                      //将分频后的时钟信号作为时钟输入
      .rst   (rst),
      .load_i (1'b0),                                          //低电平
      .load_data_i (3'h0),      
      .reg_in_i   (key_i),                                     //将按键信号作为数据输入
      .reg_out_o  (samples[2:0])
);
 assign key_db_o =RST_VALUE ? |samples[2:0] :&samples[2:0];    //根据复位值RST_VALUE的状态，设置输出端口key_db_o的值，复位值为高电平则输出按键信号samples[2:0]的或操作结果,否则输出与操作结果
endmodule