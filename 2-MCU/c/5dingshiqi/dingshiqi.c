#include <reg51.h>
sbit led1=P0^0;
void LED_Routine(void) interrupt 1 
{
  led1=~led1;
  TL0=0xF0;
  TH0=0xD8;
}

void interrupt_inti()
{
  TMOD=0x01;      //ģʽһ
  TL0=0xF0;       // D850(55536)  10000����������   10ms
  TH0=0xD8;
  ET0=1;          //����ж�����
  EA=1;
  TR0=1;          //�򿪶�ʱ��
}

void main(void)
{
  led1=1;
  interrupt_inti();
  while(1);
}
//  static unsigned int n;    //����
//  n++;
//  if(n==100)      //1s
//  {
//    n=0;
//    led1=~led1;
//  }