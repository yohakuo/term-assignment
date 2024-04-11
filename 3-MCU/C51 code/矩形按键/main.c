#include "reg52.h"
sfr P0 = 0x80;
sfr P1 = 0x90;
//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;
typedef unsigned int u16;
#define juzhen P1 //ʹ�ú궨����󰴼����ƿ�
#define duanma P0 //ʹ�ú궨������ܶ����

//�������������ʾ0~F �Ķ�������
u8 gsmg_code[17]=
{
  0x71,0x79,0x5e,0x39,0x7c,0x77,0x6f,0x7f,0x07,0x7d,0x6d,0x66,0x4f,0x5b,0x06,0x3f
};


void delay_10us(u16 ten_us)
{
  while(ten_us--);
}

//����ɨ�跨
u8 key_matrix_ranks_scan(void)
{
    u8 key_value=0;
  
  
    juzhen=0xf7;//����һ�и�ֵ0������ȫΪ1
    if(juzhen!=0xf7)//�жϵ�һ�а����Ƿ���
    {
        delay_10us(1000);//����
        switch(juzhen)//�����һ�а������º�ļ�ֵ
          {
              case 0x77: key_value=1;break;
              case 0xb7: key_value=5;break;
              case 0xd7: key_value=9;break;
              case 0xe7: key_value=13;break;
          }
     }
        while(juzhen!=0xf7);//�ȴ������ɿ�
          
      juzhen=0xfb;//���ڶ��и�ֵ0������ȫΪ1
      if(juzhen!=0xfb)//�жϵڶ��а����Ƿ���
      {
          delay_10us(1000);//����
          switch(juzhen)//����ڶ��а������º�ļ�ֵ
          {
          case 0x7b: key_value=2;break;
          case 0xbb: key_value=6;break;
          case 0xdb: key_value=10;break;
          case 0xeb: key_value=14;break;
          }
      }
      while(juzhen!=0xfb);//�ȴ������ɿ�
      
      juzhen=0xfd;//�������и�ֵ0������ȫΪ1
      if(juzhen!=0xfd)//�жϵ����а����Ƿ���
      {
      delay_10us(1000);//����
      switch(juzhen)//��������а������º�ļ�ֵ
        {
        case 0x7d: key_value=3;break;
        case 0xbd: key_value=7;break;
        case 0xdd: key_value=11;break;
        case 0xed: key_value=15;break;
        }
      } 
        while(juzhen!=0xfd);//�ȴ������ɿ�
      
        
        juzhen=0xfe;//�������и�ֵ0������ȫΪ1
        if(juzhen!=0xfe)//�жϵ����а����Ƿ���
        {
        delay_10us(1000);//����
        switch(juzhen)//��������а������º�ļ�ֵ
          {
              case 0x7e: key_value=4;break;
              case 0xbe: key_value=8;break;
              case 0xde: key_value=12;break;
              case 0xee: key_value=16;break;
          }
       }
       while(juzhen!=0xfe);//�ȴ������ɿ�
       
       
       return key_value;
}
void main()
{
	u8 key=0;
	while(1)
	{
		key=key_matrix_ranks_scan();
    if(key!=0)
    {
      duanma=gsmg_code[key-1];
    }
	}		
}