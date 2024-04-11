#include <reg52.h>
sbit KEY4 = P3 ^ 3; // 按键K4
void Delay10ms() // 延时约10ms
{
  unsigned int i;
  i = 1000;
  while (i--);
}
void print(unsigned char string[]) // 自定义的经典打印函数
{
  unsigned char i = 0;
  while (string[i] != '\0') // 循环发送字符直到字符串末尾
  {
    SBUF = string[i]; // 将字符串内容发送
    while (TI == 0); // 等待发送结束时TI 会=1
    TI = 0; // 清零
    i++;
  }
}
void main()
{
  SCON = 0x50; // 配置串口寄存器
  TMOD = 0x20; // 配置定时器1 模式2
  TH1 = 0xFD; // 配置重载
  TL1 = 0xFD; // 配置初始
  TR1 = 1; // 启动定时器
  while (1)
  {
    if (KEY4 == 0)
    {
      Delay10ms(); // 按键消抖
      if (KEY4 == 0)
      {
        while (KEY4 == 0); // 等按键抬起
        print("Hello World!\r\n");//发送字符串
      }
     }
  }
}
