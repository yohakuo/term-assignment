#include<reg52.h>

unsigned char num=0;
unsigned char col[8]={0x81,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//点亮
unsigned char row[3][8]=
{{0xFF,0XFF,0X00,0X00,0XFC,0XFC,0xFF,0XFF},//L
{0xFF,0X81,0x00,0x3C,0x38,0x00,0X81,0xFC},//Q
{0xCF,0x87,0x83,0xC1,0x83,0x87,0xCF,0xFF}};//爱心

//用来显示点阵的每一帧
unsigned char sav[8]={0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00};

void delay(unsigned int t)
{
  while(t--);
}

//扫描显示每一顿（缓存数组）
void Matrix_Screen(unsigned char Data[8])
{
  static unsigned char j;
  for(j=0;j<8;j++)  //单个点亮字母
  {
    P3=col[j];  //第j+1列置为高电平，具备点亮条件
    P0=Data[j]; //显示形状
    delay(10);  //动态扫描，视觉暂缓
    P3=~(col[j]); //第j+1列置为高电平（防止后面控制其它列的哪几个亮的时候，该列也亮了）
    //全部初始化一遍
    P3=0x80;  //列，P3口全置为低电平
    P0=0xff;  //行，P0口全置为高电平
  }
    j=0;      //全部结束后，回归首行
}

void main()
{
  unsigned char i;    //saomiao
  unsigned char j;    //xianshi
  unsigned char t;
  while(1)
  {
    for(i=0;i<24;i++)
    {
      for(j=0;j<7;j++)
      {
        sav[j]=sav[j+1];    //缓存数据左移一位
      }
      sav[7]=row[i/8][i%8];  //在最后一列补充列的亮灭情况
      t=60;
      while(t--)
      {
        Matrix_Screen(sav);
        delay(10);
      }
    }
  }
}