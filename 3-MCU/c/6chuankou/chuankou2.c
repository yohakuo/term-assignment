#include <reg51.h>
#define u8 unsigned char
#define u16 unsigned int

sbit led1=P0^0;
sbit led2=P0^3;

void Delay10ms() // 延时约10ms
{
  u16 i;
  i = 1000;
  while (i--);
}

void main()
{
  SCON = 0x50; // 配置串口模式1
  PCON |=0x00;//波特率不翻倍
  TMOD = 0x20; // 配置定时器1 模式2
  TH1 = 0xFD; // 配置重载
  TL1 = 0xFD; // 配置初始  波特率9600
  TR1 = 1; // 启动定时器
  ES = 1; // 打开串口中断
  EA = 1; // 打开总中断
  led1=led2=1;
  
  while (1)
  {
    if (RI)       //接收完毕
    {
    RI=0;
    switch(SBUF)
    {
      case '0':led1=led2=1;break;       //全灭
      case 'A':led1=0;led2=1;break;     //led1亮
      case 'B':led1=1;led2=0;break;     //led2亮
      case 'C':led1=led2=0;break;       //全亮
    }
    
    }
  }
}
