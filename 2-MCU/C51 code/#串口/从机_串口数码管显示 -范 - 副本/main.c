//�ӻ�������ʾ�����	   num	 (�µ�)
#include<reg51.h> 
#define uint unsigned int 
#define uchar unsigned char   
uchar data fasong[6]={0,0,0,0,0,0};
uchar buf[6],num;
uchar i,temp,aa,miao,fen,shi,play=0; 
uchar shige,shishi,fenge,fenshi,miaoge,miaoshi;
void display(uchar miao,uchar fen,uchar shi); // ��ʾʱ��
void play_display(); // ��ͣ / ��ʼ����
void delay(uint z); // ��ʱ����
void init(); // ��ʼ������

uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66, 0x6d,0x7d,0x07,0x7f,0x6f}; 

//void send(unsigned char dat)            //���ݷ��ͳ���
//{
//   	SBUF=dat;                           //��Ҫ���͵����ݴ��뷢�ͻ�������
//	while(TI==0);                       //�������жϱ�־λû����1(���ڷ�������)���͵ȴ�
//
//	TI=0;                               //��������ɣ�TI�Զ���1�������������
//}

void delay(uint z) 
{ 
uint x,y; 
for(x=z;x>0;x--) 
for(y=110;y>0;y--); 
}

unsigned char receive(void)         //���ݽ��պ���
{
	unsigned char dat;
	
	while(RI==0);                   //����û�н������ʱ�ȴ�����
	RI=0;                           //�������ʱ����
	dat=SBUF;                       //�����ջ������е����ݴ���dat
	return dat;                     //�����յ������ݷ���
}


void main(void)
{  
	TMOD=0x21;                     //���ö�ʱ��T1�����ڷ�ʽ2
	SCON=0x50;                     //���ڹ�����ʽ1�������������
	PCON=0x00;                     //�����ʲ�����
	TH1=0xf4;                      //������Ϊ2400b/s
	TL1=0xf4;
	TR1=1;                         //������ʱ��T1
	ES = 1; 
	EA = 1;
	while(1)
	{
  {	 
		for(i=0;i<6;i++)
		{ 
shishi =buf[0];  
shige =buf[1];  
fenshi=buf[2];  
fenge =buf[3];  
miaoshi =buf[4];  
miaoge=buf[5]; 
		}


display(miao,fen,shi); 	//��������д� ������Ҫд�ɸ�λ+ʮλ  //�������ԣ�����ֻ�����ڹ��� 
			}
	}
}
/////////////////////////////////////////////////////////////////////////////
void display(uchar miao,uchar fen,uchar shi) // ��ʾ�Ӻ���
{

P0=0x00; // ��ʾ���λ
P0=table[miaoge]; 
P2=0x7f; 
delay(1); 
P0=0x00; // ��ʾ��ʮλ
P0=table[miaoshi]; 
P2=0xbf; 
delay(1); 
P0=0x00; // ��ʾ "-" 
P0=0x40; 
P2=0xdf; 
delay(1); 
P0=0x00; // ��ʾ�ָ�λ
P0=table[fenge]; 
P2=0xef; 
delay(1); 
P0=0x00; // ��ʾ��ʮλ
P0=table[fenshi]; 
P2=0xf7; 
delay(1); 
P0=0x00; // ��ʾ "-" 
P0=0x40; 
P2=0xfb; 
delay(1); 
P0=0x00; // ��ʾʱ��λ
P0=table[shige]; 
P2=0xfd; 
delay(1); 
P0=0x00; // ��ʾʱʮλ
P0=table[shishi]; 
P2=0xfe; 
delay(1); 
} 
//////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////


void ser_isr() interrupt 4
{
static unsigned char tou = 0x00;
static unsigned char flag = 0;

RI=0;
tou = SBUF;	
if(flag == 1 )
{ 
	buf[num]=SBUF;
	num++;
	if(num == 6 )
	{
		num = 0;
		flag = 0;
	}
}
if ( tou == 0x55 )
flag = 1;

}



