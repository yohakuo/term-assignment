`timescale 1ns / 1ps
`define	UD #1
module btn_deb #(
    parameter     BT_WIDTH = 4'd8,
    parameter     CLK_FRE  = 26'd50_000_000
)
(
    input                          clk,
    input      [BT_WIDTH-1:0]      btn_in,
                               
    output reg [BT_WIDTH-1:0]      btn_out
);
    
    parameter  CLK_DIV = CLK_FRE/50;
    reg [19:0] time_cnt=20'd0;//21ms计时计数寄存器；
    
    always @(posedge clk)
    begin
        if(time_cnt == CLK_DIV-1'b1)
            time_cnt <= `UD 20'd0;
        else
            time_cnt <= `UD time_cnt + 20'd1;  //计数器到20'hf_ffff时周期约为21ms
    end
    
    always @(posedge clk)
    begin
        if(time_cnt == 0)   //每隔21ms取一次按键状态值；
            btn_out <= `UD btn_in;
    end

endmodule
