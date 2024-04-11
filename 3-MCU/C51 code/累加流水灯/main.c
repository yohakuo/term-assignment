#include "reg52.h"
typedef unsigned int u16; //对系统默认数据类型进行重定义
typedef unsigned char u8;

sbit LED0=P2^0;	
sbit LED1=P2^1;
sbit LED2=P2^2;	
sbit LED3=P2^3;	
sbit LED4=P2^4;
sbit LED5=P2^5;
sbit LED6=P2^6;
sbit LED7=P2^7;
void Delay1000ms()		//@12.000MHz
{
	unsigned char i, j, k;
	i = 8;
	j = 154;
	k = 122;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}



void main()
{
  //初始值
  P2=0xFD;
	while(1)
	{
		if(LED0==0)
    {
      LED0=~LED0;
        if(LED1==0)
        {
          LED1=~LED1;
            if(LED2==0)
            {
              LED2=~LED2;
                if(LED3==0)
                {
                  LED3=~LED3;
                  if(LED4==0)
                  {
                    LED4=~LED4;
                    if(LED5==0)
                    {
                      LED5=~LED5;
                      if(LED6==0)
                      {
                        LED6=~LED6;
                        if(LED7==0)
                        {
                          LED7=~LED7;
                        }
                        else
                          LED7=0;
                      }
                      else
                        LED6=0;
                    }
                    else
                      LED5=0;
                  }
                  else
                    LED4=0;
                }
                else
                  LED3=0;
            }
             else
               LED2=0;
         }
        else
          LED1=0;
      }
    else
      LED0=0;
    Delay1000ms();
	}		
}