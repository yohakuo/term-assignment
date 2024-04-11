#include <reg52.h>

#define uint  unsigned int
#define uchar unsigned char
 
sbit IN1=P1^0;
sbit IN2=P1^1;
sbit ENA=P1^2; 
sbit k0=P2^0;//��ת
sbit k1=P2^1;//��ת
sbit k2=P2^2;//����
sbit k3=P2^3;//����
sbit k4=P2^4;//ֹͣ
 
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
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TMOD |= 0x01;		//���ö�ʱ��ģʽ
	TL0 = 0x9C;		  //���ö�ʱ��ֵ
	TH0 = 0xFF;		  //���ö�ʱ��ֵ
	ET0=1;
	EA=1;	
	TR0=1;          //��ʼ����
}
 
void main()
{
	ENA=0;
	IN1=0;
	IN2=0;            //�õ��ֹͣ
	Timer0_init();
	Compare=50;
	while(1)
	{
		if(k0==0)//��ת
		{
			delay(100);
			while(!k0);
            ENA=1;
			IN1=1;
			IN2=0;
		}
	  else if(k1==0)//��ת
		{
			delay(100);
			while(!k1);
            ENA=1;
			IN1=0;
			IN2=1;
		}
		else if(k2==0)//����
		{
			delay(100);
			while(!k2);
			Compare=Compare+20;
		}
		else if(k3==0)//����
		{
			delay(100);
			while(!k3);
			Compare=Compare-20;
		}
		if(k4==0)//ֹͣ
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
	TL0 = 0x9C;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	Counter++;
	Counter%=100;       //��100ȡ��
	if(Counter<Compare) //�ߵ�ƽ����ʱ��Ϊռ�ձ�*��ʱʱ�䣬5ms
	{
		IN1=1;
	}
	else
	{
		IN1=0;
	}
}