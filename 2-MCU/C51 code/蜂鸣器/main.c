sfr P2 = 0xA0;

typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;

sbit BEEP=P2^5;	//��P2.5�ܽŶ���ΪBEEP

void delay_10us(u16 ten_us)
{
	while(ten_us--);	
}

void main()
{	
	u16 i=2000;

	while(1)
	{
	   	while(i--)//ѭ��2000��
		{
			BEEP=!BEEP;//����һ��Ƶ�ʵ������ź�
			delay_10us(100);
		}
		i=0;//����
		BEEP=0;//�رշ�����
	}		
}