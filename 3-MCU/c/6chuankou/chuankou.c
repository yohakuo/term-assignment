#include <reg51.h>
#define u8 unsigned char
#define u16 unsigned int

sbit led1=P0^0;
sbit led2=P0^3;
sbit key=P1^0;

void Delay10ms() // ��ʱԼ10ms
{
  u16 i;
  i = 1000;
  while (i--);
}
void sent(u8 c)
{
    SBUF=c;
    while(TI==0);
    TI = 0; // ���ͱ�־λ��0
} 

void main()
{
  u8 time=0;
  
  SCON = 0x50; // ���ô���ģʽ1
  PCON |=0x00;//�����ʲ�����
  TMOD = 0x20; // ���ö�ʱ��1 ģʽ2
  TH1 = 0xFD; // ��������
  TL1 = 0xFD; // ���ó�ʼ  ������9600
  TR1 = 1; // ������ʱ��
  ES = 1; // �򿪴����ж�
  EA = 1; // �����ж�
  while (1)
  {
    if (key == 0)
    {
    Delay10ms(); // ��������
    if (key == 0)
      {
        while (key == 0); // �Ȱ���̧��
        time=(time+1)%4; // 0~3ѭ������¼�������´���
      }
      switch(time)
      {
        case 0:led1=led2=1;sent('0');break;       //ȫ��
        case 1:led1=0;led2=1;sent('A');break;     //led1��
        case 2:led1=1;led2=0;sent('B');break;     //led2��
        case 3:led1=led2=0;sent('C');break;       //ȫ��
      }
      TI=0;
    }
  }
}
