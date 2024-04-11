sfr P2 = 0xA0;
sfr P3 = 0xB0;
#define led_port P2 
#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY4_PRESS	4
#define KEY_UNPRESS	0	
typedef unsigned int u16; //对系统默认数据类型进行重定义
typedef unsigned char u8;
//独立按键
sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

//延时函数
void delay_10us(u16 ten_us)
{
  while(ten_us--);
}


//mode=0：单次扫描按键
//mode=1：连续扫描按键
  u8 key_scan(u8 mode)
  {
      static u8 flag=1;
      if(mode) flag=1;  //连续扫描，每次按下返回一个值后key又为1 
      if(flag==1&&(k1==0||k2==0||k3==0||k4==0))//任意按键按下
      {
          delay_10us(1000);  //消抖
          flag=0;            //按下后改变标志，扫描停止
          if(k1==0)
            return KEY1_PRESS;
          else if(k2==0)
            return KEY2_PRESS;
          else if(k3==0)
            return KEY3_PRESS;
          else if(k4==0)
            return KEY4_PRESS;
       }
       else if(k1==1&&k2==1&&k3==1&&k4==1) //无按键按下
      {
          flag=1;
      }
       return KEY_UNPRESS;
   }
  void main()
  {
        u8 key = 0;
        while(1)
        {
          key=key_scan(0);      //扫描
          if(key!=KEY_UNPRESS)
            {
              u8 i=0;
              led_port=~0x01;
              delay_10us(50000);
              
                for(i=0;i<8;i++)
                {
                  led_port=~(0x01<<i);
                  delay_10us(50000);
                }
            }
        }      
  }