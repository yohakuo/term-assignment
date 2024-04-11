#include <reg51.h>
#define u8 unsigned char
#define u16 unsigned int

sbit led1=P0^0;
sbit led2=P0^3;

void Delay10ms() // ��ʱԼ10ms
{
  u16 i;
  i = 1000;
  while (i--);
}

void main()
{
  SCON = 0x50; // ���ô���ģʽ1
  PCON |=0x00;//�����ʲ�����
  TMOD = 0x20; // ���ö�ʱ��1 ģʽ2
  TH1 = 0xFD; // ��������
  TL1 = 0xFD; // ���ó�ʼ  ������9600
  TR1 = 1; // ������ʱ��
  ES = 1; // �򿪴����ж�
  EA = 1; // �����ж�
  led1=led2=1;
  
  while (1)
  {
    if (RI)       //�������
    {
    RI=0;
    switch(SBUF)
    {
      case '0':led1=led2=1;break;       //ȫ��
      case 'A':led1=0;led2=1;break;     //led1��
      case 'B':led1=1;led2=0;break;     //led2��
      case 'C':led1=led2=0;break;       //ȫ��
    }
    
    }
  }
}
