#include <reg51.h>
sbit K3=P3^2;
sbit K4=P3^3;
typedef unsigned int u8;

u8 Code[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
u8 num;

void interrupt_init(void)
{
  num=1;  //初始值
  IT0=1;  //跳变沿触发方式
  EX0=1;  //打开INT0 的中断允许
  IT1=1;
  EX1=1;
  EA=1;    //打开总中断
}
void main()
{
  interrupt_init();
  P0=Code[num];
  while(1);
}
void TestFunction0() interrupt 0
{
  if(num==0)
    num=9;
  else
    num--;
  P0=Code[num];
}
void TestFunction1() interrupt 2
{
  if(num==9)
    num=0;
  else
    num++;
  P0=Code[num];
}
