//国玉的主机_数码管显示	num
#include<reg51.h> 
#define uint unsigned int 
#define uchar unsigned char   
uchar data fasong[6]={0,0,0,0,0,0};
uchar i,temp,aa,miao,fen,shi,play=0; 
uchar shige,shishi,fenge,fenshi,miaoge,miaoshi;
/************************************************ 
定义 3 个键， K1 用于调节分，
K2 用于调节时， K3 用于调节时
************************************************/ 
sbit K1=P3^3; //国玉的 调节分
sbit K2=P3^4; // 国玉的调节时
sbit K3=P3^5; // 国玉的暂停、开始

void display(uchar miao,uchar fen,uchar shi); // 显示时钟
void play_display(); // 暂停 / 开始函数
void delay(uint z); // 延时函数
void init(); // 初始化函数
//////////////////////////////////////////////////////////

 
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66, 0x6d,0x7d,0x07,0x7f,0x6f}; 

void send(unsigned char dat)            //数据发送程序
{
   	SBUF=dat;                           //将要发送的数据存入发送缓冲器中
	while(TI==0);                       //若发送中断标志位没有置1(正在发送数据)，就等待

	TI=0;                               //若发送完成，TI自动置1，这里把它清零
}



////////////////////////////////////////////////////////////
void delay(uint z) 
{ 
uint x,y; 
for(x=z;x>0;x--) 
for(y=110;y>0;y--); 
}



void main()
{
	unsigned char i=0;
	 init();// 初始化子程序
miao=0; 
shi=0; 
fen=0; 
	TMOD=0x21;                         //定时器T1工作于方式2（可自动重装的8位定时器）
	SCON=0x50;                         //串口工作方式1，不允许接收
	PCON=0x00;                         //波特率不倍增
	TH1=0xf4;                          //波特率为2400b/s
	TL1=0xf4;
	TR1=1;                             //启动定时器T1（T1作波特率的发生器）
	REN=1;                         //允许接收数据
	while(1)
	{	
	
	  uchar i;

//fasong[0]=shishi;
//fasong[1]=shige;
//fasong[2]=fenshi;
//fasong[3]=fenge;
//fasong[4]=miaoshi;
//fasong[5]=miaoge;	

fasong[0]=miao;
fasong[1]=fen;
fasong[2]=shi;


	   

				play_display(); 
				display(miao,fen,shi);  
				
				send(0x55); //开始 头
				for(i=0;i<6;i++)		 //问题出在这个循环地方，解决方法： 改display(miao,fen,shi)函数，或者发送shi、fen、miao
				{
				send(fasong[i]);
				display(miao,fen,shi);
				}


				send(0x60); 	//９
                
	}

}
 ////////////////////////////////////////////////////////////

void display(uchar miao,uchar fen,uchar shi) // 显示子函数
{
uchar shige,shishi,fenge,fenshi,miaoge,miaoshi;
				shige=shi%10;
				shishi=shi/10;
				fenge=fen%10;
				fenshi=fen/10;
				miaoge=miao%10;
				miaoshi=miao/10;

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
void init() // 初始化子函数
{ 
temp=0; 
//TMOD=0x01; 
TH0=(65536-45872)/256; 
TL0=(65536-45872)%256; // 定时器初值，定时 50ms（12M 晶振），由于考虑 MCU 指令处理时间，此处赋初值位 45872 
EA=1; 
ET0=1; 
TR0=1; 
} 

///////////////////////////////////////////////////////
void timer0() interrupt 1 // 定时计数器中断
{ 
TH0=(65536-45872)/256; 
TL0=(65536-45872)%256; 
aa++; 
if(aa==20) // 中断 20 次为 1S，秒加 1 
{ 
miao++; 
aa=0; 
if(miao==60) 
{ 
fen++; // 满 60S, 分加 1,秒清 0 
miao=0; 
if(fen==60) 
{ 
shi++; // 小时加 1 
fen=0; 
if(shi==24) shi=0; // 小时满
} 
} 
} 

shige=shi%10;
shishi=shi/10;
fenge=fen%10;
fenshi=fen/10;
miaoge=miao%10;
miaoshi=miao/10;

fasong[0]=shishi;
fasong[1]=shige;
fasong[2]=fenshi;
fasong[3]=fenge;
fasong[4]=miaoshi;
fasong[5]=miaoge;		   
	



} 
//////////////////////////////////////////////////////////


void play_display() 
{ 
if(K3==0) 
{ delay(1); 
if(K3==0) 
{ 
play++; // 用来检测暂停或开始，单数为暂停，双数为开始
} 
while((i<50)&&(K3==0)) // 检测按键是否松开
{ 
delay(1); 
i++; 
} 
} 
if(play%2==1) // 暂停
{ 
TR0=0; 
if(K1==0) // 调分
{ 
delay(2); 
if(K1==0) fen++; 
if(fen==60) fen=0; 
delay(2); 
while(!K1); 
} 
if(K2==0) // 调小时
{ 
delay(2); 
if(K2==0) shi++; 
if(shi==24) shi=0; 
delay(2); 
while(!K2); 
} 
} 
else // 开始
{ 
TR0=1; 
} 
}

unsigned char receive(void)         //数据接收函数
{
	unsigned char dat;
	
	while(RI==0);                   //数据没有接收完毕时等待接收
	RI=0;                           //接收完毕时清零
	dat=SBUF;                       //将接收缓冲器中的数据存入dat
	return dat;                     //将接收到的数据返回
}