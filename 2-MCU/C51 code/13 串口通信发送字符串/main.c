#include <reg52.h>
sbit KEY4 = P3 ^ 3; // ����K4
void Delay10ms() // ��ʱԼ10ms
{
  unsigned int i;
  i = 1000;
  while (i--);
}
void print(unsigned char string[]) // �Զ���ľ����ӡ����
{
  unsigned char i = 0;
  while (string[i] != '\0') // ѭ�������ַ�ֱ���ַ���ĩβ
  {
    SBUF = string[i]; // ���ַ������ݷ���
    while (TI == 0); // �ȴ����ͽ���ʱTI ��=1
    TI = 0; // ����
    i++;
  }
}
void main()
{
  SCON = 0x50; // ���ô��ڼĴ���
  TMOD = 0x20; // ���ö�ʱ��1 ģʽ2
  TH1 = 0xFD; // ��������
  TL1 = 0xFD; // ���ó�ʼ
  TR1 = 1; // ������ʱ��
  while (1)
  {
    if (KEY4 == 0)
    {
      Delay10ms(); // ��������
      if (KEY4 == 0)
      {
        while (KEY4 == 0); // �Ȱ���̧��
        print("Hello World!\r\n");//�����ַ���
      }
     }
  }
}
