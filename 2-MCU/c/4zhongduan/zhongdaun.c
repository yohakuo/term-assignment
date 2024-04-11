#include <reg52.h>
sbit led=P0^0;

void main(){
  led=1;
  EA=1;   //总中断使能
  EX0=1;  //外部中断0使能
  IT0=1;  //设置下降沿触发
  while(1);
}

//外部中断函数
void LED() interrupt 0
{
  led=~led;   //翻转led
}