#include <reg52.h>
sbit led=P0^0;

void main(){
  led=1;
  EA=1;   //���ж�ʹ��
  EX0=1;  //�ⲿ�ж�0ʹ��
  IT0=1;  //�����½��ش���
  while(1);
}

//�ⲿ�жϺ���
void LED() interrupt 0
{
  led=~led;   //��תled
}