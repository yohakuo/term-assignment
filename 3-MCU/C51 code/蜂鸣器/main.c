sfr P2 = 0xA0;

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

sbit BEEP=P2^5;	//将P2.5管脚定义为BEEP

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void main()
{	
	u16 i=2000;

	while(1)
	{
	   	while(i--)//循环2000次
		{
			BEEP=!BEEP;//产生一定频率的脉冲信号
			delay_10us(100);
		}
		i=0;//清零
		BEEP=0;//关闭蜂鸣器
	}		
}