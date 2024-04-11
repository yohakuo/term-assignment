#include <reg51.h>

typedef unsigned char u8;

// 定义74HC595控制管脚
sbit SRCLK = P3 ^ 6; // 移位寄存器时钟输入
sbit RCLK = P3 ^ 5;	 // 存储寄存器时钟输入
sbit SER = P3 ^ 4;	 // 串行数据输入

const unsigned char Chars[5][8] = 
{
	{0x00, 0xFE, 0xFE, 0x10, 0x10, 0x10, 0xFE, 0xFE},//H
	{0x00, 0x00, 0xFE, 0xFE, 0x92, 0x92, 0x92, 0x82},//E
	{0x00, 0x00, 0xFE, 0xFE, 0x02, 0x02, 0x02, 0x02},//L
	{0x00, 0x7C, 0xFE, 0x82, 0x82, 0x82, 0xFE, 0x7C},//O
	{0x00, 0x60, 0x80, 0x85, 0x88, 0x70, 0x00, 0x00} //？
}; 

unsigned char DisplayNow[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; // 缓存

// 官方延时函数
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
		SER = dat >> 7; // 发最高位
		dat <<= 1;		// 左移
		SRCLK = 1;
	}
	RCLK = 1;// 锁存器默认为低电平
	RCLK = 0;
}

void Matrix_Screen(u8 Data[8])
{ 
	static u8 Columns = 0;		     // 列计数
	Send_74HC595(0x00);			       // 关闭所有行，准备切换列
	P0 = ~(0x01 << (7 - Columns)); // 切换为点亮某一列,如Columns=0,0x01<<(7-Columns)=10000000,取反则为01111111就是点亮第0列
	Send_74HC595(Data[Columns]);   // 输入这一列对应的编码
	Columns++;					           // 列计数+1
	if (Columns == 8)			         // 如果列计数为8则重新归0
		Columns = 0;
}

void main()
{
	u8 String[6] = {0, 1, 2, 2, 3, 4}; // 字符串对应字符的顺序HELLO?
	u8 i, j, t;
	while (1)
	{
		for (i = 0; i < 48; i++) // 48轮循环
		{
			for (j = 0; j < 7; j++) // 7次循环将缓存数组元素前移一个，也就是所有点往左移
			{
				DisplayNow[j] = DisplayNow[j + 1];
			}
			DisplayNow[7] = Chars[String[i / 8]][i % 8]; // 往最后补一个新元素进去。i/8得出的是该补哪一个字，1%8得出的是该补这个字的哪一列
			t = 100;									 // 用于循环扫描计次，100次大概100ms
			while (t--)
			{
				Matrix_Screen(DisplayNow); // 扫描显示
				Delay1ms();				   // 延时1ms
			}
		}
	}
}
