#include <reg51.h>
sbit BEEP = P2^5;//蜂鸣器控制引脚
void Beep(void) interrupt N //定时器中断函数
{
TRX=0;
BEEP=~BEEP;
TLX=0xXX;
THX=0xXX;
TRX=1;
}
void main(void)
{
TMOD=0xXX;
TLX=0xXX;
THX=0xXX;
ETX=1;
EA=1;
TRX=1;
while(1);
}