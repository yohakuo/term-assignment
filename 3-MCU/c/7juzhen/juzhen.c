#include<reg52.h>

unsigned char num=0;
unsigned char col[8]={0x81,0x02,0x04,0x08,0x10,0x20,0x40,0x80};//����
unsigned char row[3][8]=
{{0xFF,0XFF,0X00,0X00,0XFC,0XFC,0xFF,0XFF},//L
{0xFF,0X81,0x00,0x3C,0x38,0x00,0X81,0xFC},//Q
{0xCF,0x87,0x83,0xC1,0x83,0x87,0xCF,0xFF}};//����

//������ʾ�����ÿһ֡
unsigned char sav[8]={0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00};

void delay(unsigned int t)
{
  while(t--);
}

//ɨ����ʾÿһ�٣��������飩
void Matrix_Screen(unsigned char Data[8])
{
  static unsigned char j;
  for(j=0;j<8;j++)  //����������ĸ
  {
    P3=col[j];  //��j+1����Ϊ�ߵ�ƽ���߱���������
    P0=Data[j]; //��ʾ��״
    delay(10);  //��̬ɨ�裬�Ӿ��ݻ�
    P3=~(col[j]); //��j+1����Ϊ�ߵ�ƽ����ֹ������������е��ļ�������ʱ�򣬸���Ҳ���ˣ�
    //ȫ����ʼ��һ��
    P3=0x80;  //�У�P3��ȫ��Ϊ�͵�ƽ
    P0=0xff;  //�У�P0��ȫ��Ϊ�ߵ�ƽ
  }
    j=0;      //ȫ�������󣬻ع�����
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
        sav[j]=sav[j+1];    //������������һλ
      }
      sav[7]=row[i/8][i%8];  //�����һ�в����е��������
      t=60;
      while(t--)
      {
        Matrix_Screen(sav);
        delay(10);
      }
    }
  }
}