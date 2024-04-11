#include <reg51.h> 
#include <intrins.h>
typedef unsigned int u16; 
void delay_10us(u16 ten_us)
{
  while(ten_us--);
}
void key_scan()
{
  if(P1!=0)//任意按键按下
  {
      delay_10us(100);  //消抖
      if(P1!=0)  {
        switch(P1)
        {
          case 0xef:
            P0 = _cror_(P0,1);     //循环右移
            break;
          case 0xdf:
            P0 = _crol_(P0,1);
            break;
          case 0xbf:
            P2 = _cror_(P2,1);
            break;
          case 0x7f:
            P2 = _crol_(P2,1);
            break;
        }
      }while(P1!=0xff);
      
   }
}
void main()
{
  P2=~0x01;       //1111 1110
  P0=~0x01;
  while(1)
  {
    key_scan();
  }      
}