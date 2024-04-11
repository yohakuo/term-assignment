#include <reg51.h>
#define duanxuan	P0	//使用宏定义数码管段码口
typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;
//定义数码管位选信号控制脚
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
u8 string[8] = { 6,6,6,6,6,6,6,6 };

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void smg()
{
      u8 LSX,i;
      for(i=0;i<8;i++)
      {
        LSX=7-i;
        LSC=(LSX>>2)&1;LSB=(LSX>>1)&1;LSA=LSX&1;  //段选
        duanxuan=gsmg_code[string[i]];  //传送段选数据
        delay_10us(100);  //延时一段时间，等待显示稳定
        duanxuan=0x00;  //消音
      }
}


void interrupt_init(void)
{
  IT0=1;  //跳变沿触发方式
  EX0=1;  //打开INT0 的中断允许
  EA=1;    //打开总中断
}



void main()
{
  interrupt_init();
  while(1)
  {	 
      smg();
  }		
}


void TestFunction0() interrupt 0
{
  string[0]=7;
}
