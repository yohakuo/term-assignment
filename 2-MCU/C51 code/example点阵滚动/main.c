#include <reg51.h>

typedef unsigned char u8;

// ����74HC595���ƹܽ�
sbit SRCLK = P3 ^ 6; // ��λ�Ĵ���ʱ������
sbit RCLK = P3 ^ 5;	 // �洢�Ĵ���ʱ������
sbit SER = P3 ^ 4;	 // ������������

const unsigned char Chars[5][8] = 
{
	{0x00, 0xFE, 0xFE, 0x10, 0x10, 0x10, 0xFE, 0xFE},//H
	{0x00, 0x00, 0xFE, 0xFE, 0x92, 0x92, 0x92, 0x82},//E
	{0x00, 0x00, 0xFE, 0xFE, 0x02, 0x02, 0x02, 0x02},//L
	{0x00, 0x7C, 0xFE, 0x82, 0x82, 0x82, 0xFE, 0x7C},//O
	{0x00, 0x60, 0x80, 0x85, 0x88, 0x70, 0x00, 0x00} //��
}; 

unsigned char DisplayNow[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // ����

// �ٷ���ʱ����
void Delay1ms() //@11.0592MHz
{
	u8 i, j;

	i = 2;
	j = 199;
	do
	{
		while (--j)
			;
	} while (--i);
}

void Send_74HC595(u8 dat)
{
	u8 i;
	for (i = 0; i < 8; i++)
	{
		SRCLK = 0;
		SER = dat >> 7; // �����λ
		dat <<= 1;		// ����
		SRCLK = 1;
	}
	RCLK = 1;// ������Ĭ��Ϊ�͵�ƽ
	RCLK = 0;
}

void Matrix_Screen(u8 Data[8])
{ 
	static u8 Columns = 0;		     // �м���
	Send_74HC595(0x00);			       // �ر������У�׼���л���
	P0 = ~(0x01 << (7 - Columns)); // �л�Ϊ����ĳһ��,��Columns=0,0x01<<(7-Columns)=10000000,ȡ����Ϊ01111111���ǵ�����0��
	Send_74HC595(Data[Columns]);   // ������һ�ж�Ӧ�ı���
	Columns++;					           // �м���+1
	if (Columns == 8)			         // ����м���Ϊ8�����¹�0
		Columns = 0;
}

void main()
{
	u8 String[6] = {0, 1, 2, 2, 3, 4}; // �ַ�����Ӧ�ַ���˳��HELLO?
	u8 i, j, t;
	while (1)
	{
		for (i = 0; i < 48; i++) // 48��ѭ��
		{
			for (j = 0; j < 7; j++) // 7��ѭ������������Ԫ��ǰ��һ����Ҳ�������е�������
			{
				DisplayNow[j] = DisplayNow[j + 1];
			}
			DisplayNow[7] = Chars[String[i / 8]][i % 8]; // �����һ����Ԫ�ؽ�ȥ��i/8�ó����Ǹò���һ���֣�1%8�ó����Ǹò�����ֵ���һ��
			t = 100;									 // ����ѭ��ɨ��ƴΣ�100�δ��100ms
			while (t--)
			{
				Matrix_Screen(DisplayNow); // ɨ����ʾ
				Delay1ms();				   // ��ʱ1ms
			}
		}
	}
}
