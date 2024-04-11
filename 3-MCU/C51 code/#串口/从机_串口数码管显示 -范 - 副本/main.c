//从机——显示数码管	   num	 (新的)
#include<reg51.h> 
#define uint unsigned int 
#define uchar unsigned char   
uchar data fasong[6]={0,0,0,0,0,0};
uchar buf[6],num;
uchar i,temp,aa,miao,fen,shi,play=0; 
uchar shige,shishi,fenge,fenshi,miaoge,miaoshi;
void display(uchar miao,uchar fen,uchar shi); // 显示时钟
void play_display(); // 暂停 / 开始函数
void delay(uint z); // 延时函数
void init(); // 初始化函数

uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66, 0x6d,0x7d,0x07,0x7f,0x6f}; 

//void send(unsigned char dat)            //数据发送程序
//{
//   	SBUF=dat;                           //将要发送的数据存入发送缓冲器中
//	while(TI==0);                       //若发送中断标志位没有置1(正在发送数据)，就等待
//
//	TI=0;                               //若发送完成，TI自动置1，这里把它清零
//}

void delay(uint z) 
{ 
uint x,y; 
for(x=z;x>0;x--) 
for(y=110;y>0;y--); 
}

unsigned char receive(void)         //数据接收函数
{
	unsigned char dat;
	
	while(RI==0);                   //数据没有接收完毕时等待接收
	RI=0;                           //接收完毕时清零
	dat=SBUF;                       //将接收缓冲器中的数据存入dat
	return dat;                     //将接收到的数据返回
}


void main(void)
{  
	TMOD=0x21;                     //设置定时器T1工作于方式2
	SCON=0x50;                     //串口工作方式1，允许接收数据
	PCON=0x00;                     //波特率不倍增
	TH1=0xf4;                      //波特率为2400b/s
	TL1=0xf4;
	TR1=1;                         //启动定时器T1
	ES = 1; 
	EA = 1;
	while(1)
	{
  {	 
		for(i=0;i<6;i++)
		{ 
shishi =buf[0];  
shige =buf[1];  
fenshi=buf[2];  
fenge =buf[3];  
miaoshi =buf[4];  
miaoge=buf[5]; 
		}


display(miao,fen,shi); 	//这里可能有错 ，可能要写成个位+十位  //经过测试，现在只有他在工作 
			}
	}
}
/////////////////////////////////////////////////////////////////////////////
void display(uchar miao,uchar fen,uchar shi) // 显示子函数
{

P0=0x00; // 显示秒个位
P0=table[miaoge]; 
P2=0x7f; 
delay(1); 
P0=0x00; // 显示秒十位
P0=table[miaoshi]; 
P2=0xbf; 
delay(1); 
P0=0x00; // 显示 "-" 
P0=0x40; 
P2=0xdf; 
delay(1); 
P0=0x00; // 显示分个位
P0=table[fenge]; 
P2=0xef; 
delay(1); 
P0=0x00; // 显示分十位
P0=table[fenshi]; 
P2=0xf7; 
delay(1); 
P0=0x00; // 显示 "-" 
P0=0x40; 
P2=0xfb; 
delay(1); 
P0=0x00; // 显示时个位
P0=table[shige]; 
P2=0xfd; 
delay(1); 
P0=0x00; // 显示时十位
P0=table[shishi]; 
P2=0xfe; 
delay(1); 
} 
//////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////


void ser_isr() interrupt 4
{
static unsigned char tou = 0x00;
static unsigned char flag = 0;

RI=0;
tou = SBUF;	
if(flag == 1 )
{ 
	buf[num]=SBUF;
	num++;
	if(num == 6 )
	{
		num = 0;
		flag = 0;
	}
}
if ( tou == 0x55 )
flag = 1;

}



