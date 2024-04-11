#include "reg52.h"
typedef unsigned int u8;
typedef unsigned int u16;


void delay_10us(u16 ten_us)
{
    while(ten_us--);
}

void main()
{  
  u8 i=0;
  while(1)
  {
    for(i=0;i<8;i++)
    {
      P2=~(0x01<<i);
      delay_10us(50000);
      if(i==7)
      {
        for(i=1;i<8;i++)
        {
          P2=~(0x80>>i);
          delay_10us(50000);
        }
      }
    }
  }
}