#include <reg51.h>
#define duanxuan	P0	//ʹ�ú궨������ܶ����
typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;
//���������λѡ�źſ��ƽ�
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

u8 gsmg_code[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
                  0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
u8 string[8] = { 6,6,6,6,6,6,6,6 };

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void smg()
{
      u8 LSX,i;
      for(i=0;i<8;i++)
      {
        LSX=7-i;
        LSC=(LSX>>2)&1;LSB=(LSX>>1)&1;LSA=LSX&1;  //��ѡ
        duanxuan=gsmg_code[string[i]];  //���Ͷ�ѡ����
        delay_10us(100);  //��ʱһ��ʱ�䣬�ȴ���ʾ�ȶ�
        duanxuan=0x00;  //����
      }
}


void interrupt_init(void)
{
  IT0=1;  //�����ش�����ʽ
  EX0=1;  //��INT0 ���ж�����
  EA=1;    //�����ж�
}



void main()
{
  interrupt_init();
  while(1)
  {	 
      smg();
  }		
}


void TestFunction0() interrupt 0
{
  string[0]=7;
}
