sfr P2 = 0xA0;
sfr P3 = 0xB0;
#define led_port P2 
#define KEY1_PRESS	1
#define KEY2_PRESS	2
#define KEY3_PRESS	3
#define KEY4_PRESS	4
#define KEY_UNPRESS	0	
typedef unsigned int u16; //��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;
//��������
sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;

//��ʱ����
void delay_10us(u16 ten_us)
{
  while(ten_us--);
}


//mode=0������ɨ�谴��
//mode=1������ɨ�谴��
  u8 key_scan(u8 mode)
  {
      static u8 flag=1;
      if(mode) flag=1;  //����ɨ�裬ÿ�ΰ��·���һ��ֵ��key��Ϊ1 
      if(flag==1&&(k1==0||k2==0||k3==0||k4==0))//���ⰴ������
      {
          delay_10us(1000);  //����
          flag=0;            //���º�ı��־��ɨ��ֹͣ
          if(k1==0)
            return KEY1_PRESS;
          else if(k2==0)
            return KEY2_PRESS;
          else if(k3==0)
            return KEY3_PRESS;
          else if(k4==0)
            return KEY4_PRESS;
       }
       else if(k1==1&&k2==1&&k3==1&&k4==1) //�ް�������
      {
          flag=1;
      }
       return KEY_UNPRESS;
   }
  void main()
  {
        u8 key = 0;
        while(1)
        {
          key=key_scan(0);      //ɨ��
          if(key!=KEY_UNPRESS)
            {
              u8 i=0;
              led_port=~0x01;
              delay_10us(50000);
              
                for(i=0;i<8;i++)
                {
                  led_port=~(0x01<<i);
                  delay_10us(50000);
                }
            }
        }      
  }