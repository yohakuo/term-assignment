#include "reg52.h"
#define LEDDZ_COL_PORT P0         //点阵列控制端口
//对系统默认数据类型进行重定义
typedef unsigned int u16; 
typedef unsigned char u8;

//定义74HC595 控制管脚
sbit shift_reg=P3^6;        //移位寄存器时钟线
sbit storage_reg=P3^5;      //输出存储器锁存时钟线
sbit serial_dat=P3^4;       //串行数据输入

code unsigned char Chars[5][8]=
{
  {0xC3,0x9D,0x8D,0xC3,0xB0,0xBC,0xC3,0xFF},
  {0xC1,0x9C,0x9C,0xC0,0xFC,0xF9,0xC3,0xFF},
  {0xE1,0xCC,0x9F,0x9F,0x9F,0xCC,0xE1,0xFF},
  {0x81,0x9F,0x81,0xFC,0xFC,0x9C,0xC1,0xFF},
  {0xF3,0xE3,0xF3,0xF3,0xF3,0xF3,0xC0,0xFF}
};


void delay_10us(u16 ten_us)
{
  while(ten_us--);
}


void Send_595(u8 dat)
{
  u8 i=0;
  for(i=0;i<8;i++)         //循环8次即可将一个字节写入寄存器中
  {
    serial_dat=dat>>7;     //优先传输一个字节中的高位
    dat<<=1;               //将低位移动到高位
    shift_reg=0;
    delay_10us(1);
    shift_reg=1;           // 0-->1表示上升沿
    delay_10us(1);        
  }
  storage_reg=1;           
  delay_10us(1);
  storage_reg=0;           
}

void Matrix_Screen(u8 Data[])
{
  u8 i=0;
  u8 Scan[8]={0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};   
  for(i=0;i<8;i++)
		{
      Send_595(Scan[i]);          //选择行有效
			LEDDZ_COL_PORT=Data[i];     //传送数据  一行行 
      delay_10us(50);
			Send_595(0x00);             //消影	
		}							
}

void main()
{
  u8 i,k=0;
  u8 temp[8];               //存一个字母
  while(1)
  {	 
    for(i=0;i<8;i++)
    {
      temp[i]=Chars[k][i];
    }
    for(i=0;i<100;i++)
    {
      Matrix_Screen(temp);
    }   
    delay_10us(5000);
    k++;
    if(k>4)
    {
      k=0;                  //复原
    }
  }		
}