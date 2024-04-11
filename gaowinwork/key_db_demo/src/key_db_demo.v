`timescale 1ns/1ns                       //按键消抖主要程序
module key_db_demo(
    input        clk,                    //时钟信号
    input        rst_n,
    input        key_i,                  //按键输入信号
    output [7:0] led_o                   //输出端口：8个LED灯
); 

   wire rst =~rst_n;                     //定义一个连线RST,通过取反操作将rst_n转化为正性的复位信号
   
    wire key_db;
    key_db key_db_i(                     //按键消抖控制器
         .clk       (clk),
         .rst       (rst),
         .key_i     (key_i),            //按键输入的值
         .key_db_o  (key_db)
);

    wire[7:0] led; //存储LED灯的状态
    counter #( //16进制计数      下面四个消抖
         .WIDTH    (4),
         .DATA_MAX (15)
)counter_i0(    
       .clk       (key_i),//对按键输入信号计数，消抖前
       .rst       (rst),
       .pulse_i   (1'b1),
       .cout_o    (),
       .count_o   (led[3:0]) //计数器的输出结果作为LED灯的前四位
);

 counter #(
       .WIDTH    (4), //位宽四位
       .DATA_MAX  (15)  //最大计数值15
)counter_i1(
       .clk      (key_db),//对消抖后的按键信号计数，将该信号作为时钟脉冲
       .rst      (rst),
       .pulse_i  (1'b1),  //初始化脉冲信号为高电平
       .cout_o   (),
       .count_o  (led[7:4]) //将输出结果作为LED灯的后四位，消抖后LED灯点亮的个数依次加一
);

assign led_o[7:0]=~led[7:0]; //将led[7:0]取反后赋值给LED输出端口led_o[7:0]，实现LED灯的控制。

endmodule
