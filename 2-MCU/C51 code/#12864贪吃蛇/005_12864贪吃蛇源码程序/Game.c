/***********************************************************
功能说明：普中贪吃蛇
接线：带字库的12864接到12864接口
      如果使用的是A4以上开发板 则需要另外接线矩阵按键到IO口P1

矩阵按键：S6向上 S14向下
          S9向左 S11向右
          
修改宏定义中的Speed可修改速度
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
伪随机数发生器
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
为伪随机数发生器播种
***************************************/
void InitRandom(unsigned long InitVal)
{
	Seed=InitVal;
}

//延时子程序
void delay(unsigned int t)
{  
	unsigned int i,j;
	for(i=0;i<t;i++)
		for(j=0;j<10;j++);    
}

/*********************************
初始化MPU
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
struct Food//食物结构体
{
	unsigned char x;
	unsigned char y;
	unsigned char yes;
}food;

struct Snake//蛇结构体
{
	unsigned char x[N];
	unsigned char y[N];
	unsigned char node;
	unsigned char direction;
	unsigned char life;
}snake;

unsigned char Flag=0;
unsigned char Score=0;         //分数
unsigned char Speed=3;		   //speed越大，速度越慢
unsigned char KeyBuffer=0;     //键值
#define FUNC 1				   //(P3^1)表示级别
#define UP 2				   //(P3^3)表示左
#define DOWN 3				   //(P3^5)表示右
#define LEFT 4				   //(P3^4)表示下
#define RIGHT 5				   //(P3^2)表示上
#define PASSSCORE 20		   //预定义过关成绩

void Timer0Int(void) interrupt 1 //按键扫描中断
{
	switch(OSReadKey())
	{
		case 5:
				KeyBuffer=FUNC;						  //表示级别
				/*if(++Speed>=10)
					Speed=1;
			   	Flag|=1<<1;//速度变化标志置1*/
				break;
		case 13:
				KeyBuffer=DOWN;						 //表示右
				/*if(snake.direction!=2)
					snake.direction=1;*/
				break;
		case 21:
				KeyBuffer=UP;						 //表示左
				/*if(snake.direction!=1)
					snake.direction=2;*/
				break;
		case 17:
				KeyBuffer=RIGHT;					 //表示上
				/*if(snake.direction!=4)
					snake.direction=3;*/
				break;
	   	case 9:
				KeyBuffer=LEFT;						 //表示下
				/*if(snake.direction!=3)
					snake.direction=4;*/
				break;
		default:
				break;
	}
}

/******************************
画墙壁，初始化界面
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
打印成绩
****************************/
void PrintScore(void)
{
	unsigned char Str[3];
	Lcd_WriteStr(6,0,"成绩");
	Str[0]=(Score/10)|0x30;//十位
	Str[1]=(Score%10)|0x30;//个位
	Str[2]=0;
	Lcd_WriteStr(7,1,Str);
}

/********************************
打印速度级别
*********************************/
void PrintSpeed(void)
{
	unsigned char Str[2];
	Lcd_WriteStr(6,2,"级别");
	Str[0]=Speed|0x30;
	Str[1]=0;
	Lcd_WriteStr(7,3,Str);
}

/***********************************
游戏结束处理
************************************/
void GameOver(void)
{
	unsigned char n;
	Lcd_Rectangle(food.x,food.y,food.x+2,food.y+2,0);//消隐出食物
	for(n=1;n<snake.node;n++)
	{
		Lcd_Rectangle(snake.x[n],snake.y[n],snake.x[n]+2,snake.y[n]+2,0);//消隐食物，蛇头已到墙壁内，故不用消去		
	}
	if(snake.life==0)//如果蛇还活着
		Lcd_WriteStr(2,1,"过关");
	else             //如果蛇死了
		Lcd_WriteStr(2,1,"输了");
	Lcd_WriteStr(1,2,"游戏结束");
}

/********************************
游戏的具体过程，也是贪吃蛇算法的关键部分
*********************************/
void GamePlay(void)
{
	unsigned char n;
	InitRandom(TL0);
	food.yes=1;//1表示需要出现新事物，0表示已经存在食物尚未吃掉
	snake.life=0;//表示蛇还活着
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
				food.y=Random()*55+3;//获得随机数
	
				while(food.x%3!=0)
					food.x++;
				while(food.y%3!=0)
					food.y++;
			    for(n=0;n<snake.node;n++)//判断产生的食物坐标是否和蛇身重合
				{
					if((food.x==snake.x[n])&&(food.y==snake.y[n]))
						break;
				}
				if(n==snake.node)
				{
					food.yes=0;
					break;//产生有效的食物坐标
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
		for(n=3;n<snake.node;n++)//从第三节开始判断蛇头是否咬到自己
		{
			if(snake.x[n]==snake.x[0]&&snake.y[n]==snake.y[0])
			{
				GameOver();
				snake.life=1;
				break;
			}
		}
		if(snake.x[0]<3||snake.x[0]>=90||snake.y[0]<3||snake.y[0]>=60)//判蛇头是否撞到墙壁
		{
			GameOver();
			snake.life=1;
		}
		if(snake.life==1)
			break;//蛇死，则跳出while(1)循环
		if(snake.x[0]==food.x&&snake.y[0]==food.y)//判蛇是否吃到食物
		{
			Lcd_Rectangle(food.x,food.y,food.x+2,food.y+2,0);//消隐食物
			snake.x[snake.node]=200;
			snake.y[snake.node]=200;//产生蛇新的节坐标先放在看不见的位置
			snake.node++;//蛇节数加1
			food.yes=1;//食物标志置1
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
		}//根据蛇的节数画出蛇
		delay(Speed*1000);	  //调速
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
	}//结束while(1)
}

void Main()
{  
	InitCpu();//初始化CPU
	Lcd_Reset(); //初始化LCD屏
	Lcd_WriteStr(2,1,"普中贪吃蛇");
	delay(5000);
	delay(5000);
	Lcd_WriteCmd(0x01);   //清除显示，并且设定地址指针为00H
	Lcd_Clear(0);//清屏
	DrawBoard();//画界面
	GamePlay();//玩游戏
	GameOver();//游戏结束
	while(1);//要想重玩，只能重启，可继续完善该游戏
}

