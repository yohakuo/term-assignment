#include <reg51.h>
sbit BEEP = P2^5;//��������������

// 0xE1  0x08
void Beep(void) interrupt 1 //��ʱ���жϺ���
{
  TR0=0;
  BEEP=~BEEP;     //Ĭ��Ϊ��
  TL0=0x1F;
  TH0=0xF7;
  TR0=1;
}
void main(void)
{
  TMOD=0x01;      //ģʽһ
  TL0=0x1F;      
  TH0=0xF7;
  ET0=1;          //����ж�����
  EA=1;
  TR0=1;          //�򿪶�ʱ��
  while(1);
}