#include "reg52.h"
sfr P0 = 0x80;
sfr P1 = 0x90;
//对系统默认数据类型进行重定义
typedef unsigned char u8;
typedef unsigned int u16;
#define juzhen P1 //使用宏定义矩阵按键控制口
#define duanma P0 //使用宏定义数码管段码口

//共阴极数码管显示0~F 的段码数据
u8 gsmg_code[17]=
{
  0x71,0x79,0x5e,0x39,0x7c,0x77,0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f
};


void delay_10us(u16 ten_us)
{
  while(ten_us--);
}

//行列扫描法
u8 key_matrix_ranks_scan(void)
{
    u8 key_value=0;
  
  
    juzhen=0xf7;//给第一列赋值0，其余全为1
    if(juzhen!=0xf7)//判断第一列按键是否按下
    {
        delay_10us(1000);//消抖
        switch(juzhen)//保存第一列按键按下后的键值
          {
              case 0x77: key_value=1;break;
              case 0xb7: key_value=5;break;
              case 0xd7: key_value=9;break;
              case 0xe7: key_value=13;break;
          }
     }
        while(juzhen!=0xf7);//等待按键松开
          
      juzhen=0xfb;//给第二列赋值0，其余全为1
      if(juzhen!=0xfb)//判断第二列按键是否按下
      {
          delay_10us(1000);//消抖
          switch(juzhen)//保存第二列按键按下后的键值
          {
          case 0x7b: key_value=2;break;
          case 0xbb: key_value=6;break;
          case 0xdb: key_value=10;break;
          case 0xeb: key_value=14;break;
          }
      }
      while(juzhen!=0xfb);//等待按键松开
      
      juzhen=0xfd;//给第三列赋值0，其余全为1
      if(juzhen!=0xfd)//判断第三列按键是否按下
      {
      delay_10us(1000);//消抖
      switch(juzhen)//保存第三列按键按下后的键值
        {
        case 0x7d: key_value=3;break;
        case 0xbd: key_value=7;break;
        case 0xdd: key_value=11;break;
        case 0xed: key_value=15;break;
        }
      } 
        while(juzhen!=0xfd);//等待按键松开
      
        
        juzhen=0xfe;//给第四列赋值0，其余全为1
        if(juzhen!=0xfe)//判断第四列按键是否按下
        {
        delay_10us(1000);//消抖
        switch(juzhen)//保存第四列按键按下后的键值
          {
              case 0x7e: key_value=4;break;
              case 0xbe: key_value=8;break;
              case 0xde: key_value=12;break;
              case 0xee: key_value=16;break;
          }
       }
       while(juzhen!=0xfe);//等待按键松开
       
       
       return key_value;
}
void main()
{
	u8 key=0;
	while(1)
	{
		key=key_matrix_ranks_scan();
    if(key!=0)
    {
      duanma=gsmg_code[key-1];
    }
	}		
}