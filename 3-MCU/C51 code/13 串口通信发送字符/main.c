#include <reg52.h>
sbit KEY4 = P3 ^ 3;//按键K4
// 数码管段码0-F
unsigned char SegmentCode[16] =
{0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
void Delay10ms() // 延时约10ms
{
  unsigned int i;
  i = 1000;
  while (i--);
}
void UART_INT() interrupt 4 // 串口中断函数
{
  if (RI)
  {
    RI = 0; // 接收标志位清0
    P0 = SegmentCode[SBUF];
    // 把收到的数据放到数码管中显示出来，仅限于数字00-0F
  }
  if (TI)
  {
    TI = 0; // 发送标志位清0
  }
}
void main()
{
  SCON = 0x50; // 配置串口寄存器
  // PCON |=0x80;//波特率翻倍
  TMOD = 0x20; // 配置定时器1 模式2
  TH1 = 0xFD; // 配置重载
  TL1 = 0xFD; // 配置初始
  TR1 = 1; // 启动定时器
  ES = 1; // 打开串口中断
  EA = 1; // 打开总中断
  while (1)
  {
    if (KEY4 == 0)
    {
    Delay10ms(); // 按键消抖
    if (KEY4 == 0)
      {
        while (KEY4 == 0); // 等按键抬起
        while (TI); // 等发送结束
        SBUF = 0x01; // 发送数据0x01
      }
    }
  }
}
