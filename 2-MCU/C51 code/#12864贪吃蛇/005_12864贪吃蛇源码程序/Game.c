/***********************************************************
����˵��������̰����
���ߣ����ֿ��12864�ӵ�12864�ӿ�
      ���ʹ�õ���A4���Ͽ����� ����Ҫ������߾��󰴼���IO��P1

���󰴼���S6���� S14����
          S9���� S11����
          
�޸ĺ궨���е�Speed���޸��ٶ�
*****************************************************************/
#include "stc.h"
#include "Lcd12864.h"
#include "Key.h"
#define uchar unsigned char
#define uint unsigned int

static unsigned long Seed = 1;
#define A 48271L
#define M 2147483647L
#define Q (M / A)
#define R (M % A)
/************************************
α�����������
*************************************/
double Random(void)
{
	long TmpSeed;
	TmpSeed=A*(Seed%Q)-R*(Seed/Q);
	if(TmpSeed>=0)
		Seed=TmpSeed;
	else
		Seed=TmpSeed+M;
	return (double)Seed/M;
}

/**************************************
Ϊα���������������
***************************************/
void InitRandom(unsigned long InitVal)
{
	Seed=InitVal;
}

//��ʱ�ӳ���
void delay(unsigned int t)
{  
	unsigned int i,j;
	for(i=0;i<t;i++)
		for(j=0;j<10;j++);    
}

/*********************************
��ʼ��MPU
**********************************/
void InitCpu(void)
{
	TMOD=0x01;
	TH0=0;
	TL0=0;
	TR0=1;
	ET0=1;
	EA=1;
}

#define N 25
struct Food//ʳ��ṹ��
{
	unsigned char x;
	unsigned char y;
	unsigned char yes;
}food;

struct Snake//�߽ṹ��
{
	unsigned char x[N];
	unsigned char y[N];
	unsigned char node;
	unsigned char direction;
	unsigned char life;
}snake;

unsigned char Flag=0;
unsigned char Score=0;         //����
unsigned char Speed=3;		   //speedԽ���ٶ�Խ��
unsigned char KeyBuffer=0;     //��ֵ
#define FUNC 1				   //(P3^1)��ʾ����
#define UP 2				   //(P3^3)��ʾ��
#define DOWN 3				   //(P3^5)��ʾ��
#define LEFT 4				   //(P3^4)��ʾ��
#define RIGHT 5				   //(P3^2)��ʾ��
#define PASSSCORE 20		   //Ԥ������سɼ�

void Timer0Int(void) interrupt 1 //����ɨ���ж�
{
	switch(OSReadKey())
	{
		case 5:
				KeyBuffer=FUNC;						  //��ʾ����
				/*if(++Speed>=10)
					Speed=1;
			   	Flag|=1<<1;//�ٶȱ仯��־��1*/
				break;
		case 13:
				KeyBuffer=DOWN;						 //��ʾ��
				/*if(snake.direction!=2)
					snake.direction=1;*/
				break;
		case 21:
				KeyBuffer=UP;						 //��ʾ��
				/*if(snake.direction!=1)
					snake.direction=2;*/
				break;
		case 17:
				KeyBuffer=RIGHT;					 //��ʾ��
				/*if(snake.direction!=4)
					snake.direction=3;*/
				break;
	   	case 9:
				KeyBuffer=LEFT;						 //��ʾ��
				/*if(snake.direction!=3)
					snake.direction=4;*/
				break;
		default:
				break;
	}
}

/******************************
��ǽ�ڣ���ʼ������
*******************************/
void DrawBoard(void)
{
	unsigned char n;
	for(n=0;n<31;n++)
	{
		Lcd_Rectangle(3*n,0,3*n+2,2,1);
		Lcd_Rectangle(3*n,60,3*n+2,62,1);
	}
	for(n=0;n<21;n++)
	{
		Lcd_Rectangle(0,3*n,2,3*n+2,1);
		Lcd_Rectangle(90,3*n,92,3*n+2,1);		
	}
	Lcd_HoriLine(93,31,35,1);
	Lcd_HoriLine(93,63,35,1);
}

/***************************
��ӡ�ɼ�
****************************/
void PrintScore(void)
{
	unsigned char Str[3];
	Lcd_WriteStr(6,0,"�ɼ�");
	Str[0]=(Score/10)|0x30;//ʮλ
	Str[1]=(Score%10)|0x30;//��λ
	Str[2]=0;
	Lcd_WriteStr(7,1,Str);
}

/********************************
��ӡ�ٶȼ���
*********************************/
void PrintSpeed(void)
{
	unsigned char Str[2];
	Lcd_WriteStr(6,2,"����");
	Str[0]=Speed|0x30;
	Str[1]=0;
	Lcd_WriteStr(7,3,Str);
}

/***********************************
��Ϸ��������
************************************/
void GameOver(void)
{
	unsigned char n;
	Lcd_Rectangle(food.x,food.y,food.x+2,food.y+2,0);//������ʳ��
	for(n=1;n<snake.node;n++)
	{
		Lcd_Rectangle(snake.x[n],snake.y[n],snake.x[n]+2,snake.y[n]+2,0);//����ʳ���ͷ�ѵ�ǽ���ڣ��ʲ�����ȥ		
	}
	if(snake.life==0)//����߻�����
		Lcd_WriteStr(2,1,"����");
	else             //���������
		Lcd_WriteStr(2,1,"����");
	Lcd_WriteStr(1,2,"��Ϸ����");
}

/********************************
��Ϸ�ľ�����̣�Ҳ��̰�����㷨�Ĺؼ�����
*********************************/
void GamePlay(void)
{
	unsigned char n;
	InitRandom(TL0);
	food.yes=1;//1��ʾ��Ҫ���������0��ʾ�Ѿ�����ʳ����δ�Ե�
	snake.life=0;//��ʾ�߻�����
	snake.direction=DOWN;
	snake.x[0]=6;snake.y[0]=6;
	snake.x[1]=3;snake.y[1]=6;
	snake.node=2;
	PrintScore();
	PrintSpeed();
	while(1)
	{
		if(food.yes==1)
		{
			while(1)
			{
				food.x=Random()*85+3;
				food.y=Random()*55+3;//��������
	
				while(food.x%3!=0)
					food.x++;
				while(food.y%3!=0)
					food.y++;
			    for(n=0;n<snake.node;n++)//�жϲ�����ʳ�������Ƿ�������غ�
				{
					if((food.x==snake.x[n])&&(food.y==snake.y[n]))
						break;
				}
				if(n==snake.node)
				{
					food.yes=0;
					break;//������Ч��ʳ������
				}
			}
		}
		if(food.yes==0)
		{
			Lcd_Rectangle(food.x,food.y,food.x+2,food.y+2,1);
		}	
		for(n=snake.node-1;n>0;n--)
		{
			snake.x[n]=snake.x[n-1];
			snake.y[n]=snake.y[n-1];
		}
		switch(snake.direction)
		{
			case DOWN:snake.x[0]+=3;break;
			case UP:snake.x[0]-=3;break;
			case RIGHT:snake.y[0]-=3;break;
			case LEFT:snake.y[0]+=3;break;
			default:break;
		}
		for(n=3;n<snake.node;n++)//�ӵ����ڿ�ʼ�ж���ͷ�Ƿ�ҧ���Լ�
		{
			if(snake.x[n]==snake.x[0]&&snake.y[n]==snake.y[0])
			{
				GameOver();
				snake.life=1;
				break;
			}
		}
		if(snake.x[0]<3||snake.x[0]>=90||snake.y[0]<3||snake.y[0]>=60)//����ͷ�Ƿ�ײ��ǽ��
		{
			GameOver();
			snake.life=1;
		}
		if(snake.life==1)
			break;//������������while(1)ѭ��
		if(snake.x[0]==food.x&&snake.y[0]==food.y)//�����Ƿ�Ե�ʳ��
		{
			Lcd_Rectangle(food.x,food.y,food.x+2,food.y+2,0);//����ʳ��
			snake.x[snake.node]=200;
			snake.y[snake.node]=200;//�������µĽ������ȷ��ڿ�������λ��
			snake.node++;//�߽�����1
			food.yes=1;//ʳ���־��1
			if(++Score>=PASSSCORE)
			{
				PrintScore();
				GameOver();
				break;
			}
			PrintScore();
		}
		for(n=0;n<snake.node;n++)
		{
			Lcd_Rectangle(snake.x[n],snake.y[n],snake.x[n]+2,snake.y[n]+2,1);
		}//�����ߵĽ���������
		delay(Speed*1000);	  //����
		delay(Speed*1000);
		Lcd_Rectangle(snake.x[snake.node-1],snake.y[snake.node-1],snake.x[snake.node-1]+2,snake.y[snake.node-1]+2,0);
		switch(KeyBuffer)
		{
			case FUNC:
					KeyBuffer=0;
					if(++Speed>=10)
						Speed=1;
				   	PrintSpeed();
					break;
			case DOWN:
					KeyBuffer=0;
					if(snake.direction!=UP)
						snake.direction=DOWN;
					break;
			case UP:
					KeyBuffer=0;
					if(snake.direction!=DOWN)
						snake.direction=UP;
					break;
			case RIGHT:
					KeyBuffer=0;
					if(snake.direction!=LEFT)
						snake.direction=RIGHT;
					break;
		   	case LEFT:
					KeyBuffer=0;
					if(snake.direction!=RIGHT)
						snake.direction=LEFT;
					break;
			default:
					break;
		}			
	}//����while(1)
}

void Main()
{  
	InitCpu();//��ʼ��CPU
	Lcd_Reset(); //��ʼ��LCD��
	Lcd_WriteStr(2,1,"����̰����");
	delay(5000);
	delay(5000);
	Lcd_WriteCmd(0x01);   //�����ʾ�������趨��ַָ��Ϊ00H
	Lcd_Clear(0);//����
	DrawBoard();//������
	GamePlay();//����Ϸ
	GameOver();//��Ϸ����
	while(1);//Ҫ�����棬ֻ���������ɼ������Ƹ���Ϸ
}

