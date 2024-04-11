#include <reg52.h>
sbit KEY4 = P3 ^ 3;//����K4
// ����ܶ���0-F
unsigned char SegmentCode[16] =
{0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
void Delay10ms() // ��ʱԼ10ms
{
  unsigned int i;
  i = 1000;
  while (i--);
}
void UART_INT() interrupt 4 // �����жϺ���
{
  if (RI)
  {
    RI = 0; // ���ձ�־λ��0
    P0 = SegmentCode[SBUF];
    // ���յ������ݷŵ����������ʾ����������������00-0F
  }
  if (TI)
  {
    TI = 0; // ���ͱ�־λ��0
  }
}
void main()
{
  SCON = 0x50; // ���ô��ڼĴ���
  // PCON |=0x80;//�����ʷ���
  TMOD = 0x20; // ���ö�ʱ��1 ģʽ2
  TH1 = 0xFD; // ��������
  TL1 = 0xFD; // ���ó�ʼ
  TR1 = 1; // ������ʱ��
  ES = 1; // �򿪴����ж�
  EA = 1; // �����ж�
  while (1)
  {
    if (KEY4 == 0)
    {
    Delay10ms(); // ��������
    if (KEY4 == 0)
      {
        while (KEY4 == 0); // �Ȱ���̧��
        while (TI); // �ȷ��ͽ���
        SBUF = 0x01; // ��������0x01
      }
    }
  }
}
