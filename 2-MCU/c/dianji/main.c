#include <reg52.h>

#define uint  unsigned int
#define uchar unsigned char
 
sbit IN1=P1^0;
sbit IN2=P1^1;
sbit ENA=P1^2; 
sbit k0=P2^0;//正转
sbit k1=P2^1;//反转
sbit k2=P2^2;//加速
sbit k3=P2^3;//减速
sbit k4=P2^4;//停止
 
uchar Counter=0,Compare=0;
 
void delay(uint n)
{
	uint i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<120;j++);
	}
}
 
void Timer0_init()  //100us
{
	TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式
	TL0 = 0x9C;		  //设置定时初值
	TH0 = 0xFF;		  //设置定时初值
	ET0=1;
	EA=1;	
	TR0=1;          //开始工作
}
 
void main()
{
	ENA=0;
	IN1=0;
	IN2=0;            //让电机停止
	Timer0_init();
	Compare=50;
	while(1)
	{
		if(k0==0)//正转
		{
			delay(100);
			while(!k0);
            ENA=1;
			IN1=1;
			IN2=0;
		}
	  else if(k1==0)//反转
		{
			delay(100);
			while(!k1);
            ENA=1;
			IN1=0;
			IN2=1;
		}
		else if(k2==0)//加速
		{
			delay(100);
			while(!k2);
			Compare=Compare+20;
		}
		else if(k3==0)//减速
		{
			delay(100);
			while(!k3);
			Compare=Compare-20;
		}
		if(k4==0)//停止
		{
			delay(100);
			while(!k4);
			ENA=0;
			TR0=0;
			IN1=0;
			IN2=0;								
		}	
		 
	}
}
 
void Timer0() interrupt 1
{
	TL0 = 0x9C;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	Counter++;
	Counter%=100;       //对100取余
	if(Counter<Compare) //高电平持续时间为占空比*定时时间，5ms
	{
		IN1=1;
	}
	else
	{
		IN1=0;
	}
}