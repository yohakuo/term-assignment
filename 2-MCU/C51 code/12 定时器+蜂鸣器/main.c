#include <reg51.h>
sbit BEEP = P2^5;//蜂鸣器控制引脚

// 0xE1  0x08
void Beep(void) interrupt 1 //定时器中断函数
{
  TR0=0;
  BEEP=~BEEP;     //默认为高
  TL0=0x1F;
  TH0=0xF7;
  TR0=1;
}
void main(void)
{
  TMOD=0x01;      //模式一
  TL0=0x1F;      
  TH0=0xF7;
  ET0=1;          //溢出中断允许
  EA=1;
  TR0=1;          //打开定时器
  while(1);
}