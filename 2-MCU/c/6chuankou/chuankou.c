#include <reg51.h>
#define u8 unsigned char
#define u16 unsigned int

sbit led1=P0^0;
sbit led2=P0^3;
sbit key=P1^0;

void Delay10ms() // 延时约10ms
{
  u16 i;
  i = 1000;
  while (i--);
}
void sent(u8 c)
{
    SBUF=c;
    while(TI==0);
    TI = 0; // 发送标志位清0
} 

void main()
{
  u8 time=0;
  
  SCON = 0x50; // 配置串口模式1
  PCON |=0x00;//波特率不翻倍
  TMOD = 0x20; // 配置定时器1 模式2
  TH1 = 0xFD; // 配置重载
  TL1 = 0xFD; // 配置初始  波特率9600
  TR1 = 1; // 启动定时器
  ES = 1; // 打开串口中断
  EA = 1; // 打开总中断
  while (1)
  {
    if (key == 0)
    {
    Delay10ms(); // 按键消抖
    if (key == 0)
      {
        while (key == 0); // 等按键抬起
        time=(time+1)%4; // 0~3循环，记录按键按下次数
      }
      switch(time)
      {
        case 0:led1=led2=1;sent('0');break;       //全灭
        case 1:led1=0;led2=1;sent('A');break;     //led1亮
        case 2:led1=1;led2=0;sent('B');break;     //led2亮
        case 3:led1=led2=0;sent('C');break;       //全亮
      }
      TI=0;
    }
  }
}
