`timescale 1ns/1ns                              //计数器
module counter #(                               //定义两个参数
    parameter WIDTH =4,                         //计数器的宽度        四个灯led5-8
    parameter DATA_MAX =15                      //计数器可计数的最大值 led5-8: 1111
)(
                                                //定义输入端口
    input                  clk,                 //时钟信号
    input                  rst,                 //复位信号
    input                  pulse_i,             //脉冲输入信号
    output reg             cout_o,              //定义一个寄存器类型的输出端口，表示计数器溢出信号
    output reg [WIDTH-1:0] count_o              //表示计数器当前计数的值
);

   localparam SIM_DELAY =1;                     //定义一个本地常量，表示仿真运行的延时时间

   always @(posedge clk or posedge rst) begin   //边沿触发符合D触发器的发生条件（posedge表示上升沿触发，negedge表示下降沿触发）
     if(rst) begin
       cout_o    <=#SIM_DELAY 0;
       count_o   <=#SIM_DELAY 0;
     end else if(pulse_i) begin                 //脉冲输入信号为高电平时执行
       if(count_o <DATA_MAX) begin              //计数值小于最大值时增加计数值
         cout_o   <=#SIM_DELAY 1'b0;
         count_o  <=#SIM_DELAY count_o+1;       
       end else begin                           //计数值大于等于最大值时计数器清零
         cout_o  <=#SIM_DELAY 1'b1;
         count_o  <=#SIM_DELAY 0;            
     end
   end
  end
endmodule