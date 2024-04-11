#include "reg52.h"
#define LEDDZ_COL_PORT P0             //点阵列控制端口
//对系统默认数据类型进行重定义
  typedef unsigned int u16; 
  typedef unsigned char u8;
//定义74HC595 控制管脚
  sbit shift_reg=P3^6;        //数据输入时钟线
  sbit storage_reg=P3^5;      //输出存储器锁存时钟线
  sbit serial_dat=P3^4;       //串行数据输入

  u8 Ghc595_buf[5]={0xFF,0xF0,0xCC,0xAA,0x00};
  
  void delay_10us(u16 ten_us)
  {
    while(ten_us--);
  }
  void delay_ms(u16 ms)
  {
    u16 i,j;
    for(i=ms;i>0;i--)
      for(j=110;j>0;j--);
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
    storage_reg=0;
    delay_10us(1);
    storage_reg=1;           //将前面写入到寄存器的数据输出
  }
  
  void main()
  {
    u8 i=0;
    LEDDZ_COL_PORT=0x00;        //将LED 点阵列全部设置为0，即LED阴极为低电平
    while(1)
    {	
      for(i=0;i<5;i++)
      {
        Send_595(0x00);            //消除前面寄存器缓存数据
        Send_595(Ghc595_buf[i]);   //写入新的数据
        delay_ms(500);             //延时500ms
      }
    }		
  }