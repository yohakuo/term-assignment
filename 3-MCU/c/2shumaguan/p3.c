#include <reg52.h>
#define duanxuan	P0	//ʹ�ú궨������ܶ����

typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;

//�������������ʾ0~F�Ķ�������
u8 gsmg_code[17]={
	0xc0,0xf9,0xa4,0xb0,
	0x99,0x92,0x82,0xf8,
	0x80,0x90,0x88,0x83,
	0xc6,0xa1,0x86,0x8e
};

u8 string[8] = { 6,6,6,6,6,6,6,6 };

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void main()
{	 
      while(1)
      {
        u8 i,temp=0x01;
        for(i=0;i<8;i++)
        {
          //ѭ������  �ߵ�ƽѡ��һ��λѡ
          P2=(temp<<i);            
          duanxuan=gsmg_code[string[i]];  //���Ͷ�ѡ����
          delay_10us(20000);              //��ʱһ��ʱ�䣬�ȴ���ʾ�ȶ�
          duanxuan=0x00;                  //��Ӱ
          if(i==7)
            temp=0x01;
        }
      }
}