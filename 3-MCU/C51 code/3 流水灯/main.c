//#include "reg52.h"
//#define led_port P2                 //定义P2端口,重命名
sfr P2 = 0xA0;
typedef unsigned int u8;
typedef unsigned int u16;


void delay_10us(u16 ten_us)
{
    while(ten_us--);
}

void main()
{  
  u8 i=0;
  while(1){
    for(i=0;i<8;i++)
    {
      P2=~(0x01<<i);
      delay_10us(50000);
    }
  }
}
//sbit LED1=P2^0;	
//sbit LED2=P2^1;	
//sbit LED3=P2^2;	
//sbit LED4=P2^3;	
//sbit LED5=P2^4;	
//sbit LED6=P2^5;	
//sbit LED7=P2^6;
//sbit LED8=P2^7;	

//void main()
//{   
//  int j;
//  while(1){
//    j++;
//    LED1=j%8;
//    LED2=(j+1)%8;
//    LED3=(j+2)%8;
//    LED4=(j+3)%8;
//    LED5=(j+4)%8;
//    LED6=(j+5)%8;
//    LED7=(j+6)%8;
//    LED81=(j+7)%8;
//    for(i=0;i<=30000;j++);
//  }
//}