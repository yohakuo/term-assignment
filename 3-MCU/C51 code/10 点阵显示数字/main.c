#include "reg52.h"
#define LEDDZ_COL_PORT P0             //�����п��ƶ˿�
//��ϵͳĬ���������ͽ����ض���
typedef unsigned int u16; 
typedef unsigned char u8;

//����74HC595 ���ƹܽ�
sbit shift_reg=P3^6;        //��������ʱ����
sbit storage_reg=P3^5;      //����洢������ʱ����
sbit serial_dat=P3^4;       //������������
  
u8 Data1[8]={0x00,0x00,0x7E,0x91,0x91,0x91,0x0E,0x00};        // ����������ÿ�ж�Ӧ�������� 6
u8 Data2[8]={0x00,0x00,0x40,0x40,0x40,0x7E,0x00,0x00};        //  7

void delay_10us(u16 ten_us)
{
  while(ten_us--);
}
void delay_ms(u16 ms)
  {
    u16 i,j;
    for(i=ms;i>0;i--)
      for(j=110;j>0;j--);
  }


void Send_595(u8 dat)
{
  u8 i=0;
  for(i=0;i<8;i++)         //ѭ��8�μ��ɽ�һ���ֽ�д��Ĵ�����
  {
    serial_dat=dat>>7;     //���ȴ���һ���ֽ��еĸ�λ
    dat<<=1;               //����λ�ƶ�����λ
    shift_reg=0;
    delay_10us(1);
    shift_reg=1;           // 0-->1��ʾ������
    delay_10us(1);        
  }
  storage_reg=1;           
  delay_10us(1);
  storage_reg=0;           
}

void Matrix_Screen(u8 Data[8])
{
  u8 i=0;
  u8 Scan[8]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};   
  for(i=0;i<8;i++)
		{
			LEDDZ_COL_PORT=Scan[i];     //ѡ������Ч
			Send_595(Data[i]);          //��������
			Send_595(0x00);             //��Ӱ	
		}								
}

void main()
{
  while(1)
  {	 
      Matrix_Screen(Data1);     
      delay_ms(1);
  }		
}