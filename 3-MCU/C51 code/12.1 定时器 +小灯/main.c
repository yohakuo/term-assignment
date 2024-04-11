#include <reg51.h>
sbit led1=P2^0;

void LED_Routine(void) interrupt 1 
{
  static unsigned int n;    //计数100次
  n++;
  if(n==100)
  {
    n=0;
    led1=~led1;
  }
  TL0=0xF0;
  TH0=0xD8;
}

void interrupt_inti()
{
  TMOD=0x01;      //模式一
  TL0=0xF0;      
  TH0=0xD8;
  ET0=1;          //溢出中断允许
  EA=1;
  TR0=1;          //打开定时器
}

void main(void)
{
  led1=1;
  interrupt_inti();
  while(1);
}