#include <reg52.h>
#define duanxuan	P0	//使用宏定义数码管段码口

typedef unsigned int u16;	//对系统默认数据类型进行重定义
typedef unsigned char u8;

//共阳极数码管显示0~F的段码数据
u8 gsmg_code[17]={
	0xc0,0xf9,0xa4,0xb0,
	0x99,0x92,0x82,0xf8,
	0x80,0x90,0x88,0x83,
	0xc6,0xa1,0x86,0x8e
};

u8 string[8] = { 6,6,6,6,6,6,6,6 };

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void main()
{	 
      while(1)
      {
        u8 i,temp=0x01;
        for(i=0;i<8;i++)
        {
          //循环右移  高电平选中一个位选
          P2=(temp<<i);            
          duanxuan=gsmg_code[string[i]];  //传送段选数据
          delay_10us(20000);              //延时一段时间，等待显示稳定
          duanxuan=0x00;                  //消影
          if(i==7)
            temp=0x01;
        }
      }
}