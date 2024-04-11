#include "reg52.h"
#define LEDDZ_COL_PORT P0             //�����п��ƶ˿�
//��ϵͳĬ���������ͽ����ض���
  typedef unsigned int u16; 
  typedef unsigned char u8;
//����74HC595 ���ƹܽ�
  sbit shift_reg=P3^6;        //��������ʱ����
  sbit storage_reg=P3^5;      //����洢������ʱ����
  sbit serial_dat=P3^4;       //������������

  u8 Ghc595_buf[5]={0xFF,0xF0,0xCC,0xAA,0x00};
  
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
    storage_reg=0;
    delay_10us(1);
    storage_reg=1;           //��ǰ��д�뵽�Ĵ������������
  }
  
  void main()
  {
    u8 i=0;
    LEDDZ_COL_PORT=0x00;        //��LED ������ȫ������Ϊ0����LED����Ϊ�͵�ƽ
    while(1)
    {	
      for(i=0;i<5;i++)
      {
        Send_595(0x00);            //����ǰ��Ĵ�����������
        Send_595(Ghc595_buf[i]);   //д���µ�����
        delay_ms(500);             //��ʱ500ms
      }
    }		
  }