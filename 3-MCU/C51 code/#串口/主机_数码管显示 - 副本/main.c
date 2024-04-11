//���������_�������ʾ	num
#include<reg51.h> 
#define uint unsigned int 
#define uchar unsigned char   
uchar data fasong[6]={0,0,0,0,0,0};
uchar i,temp,aa,miao,fen,shi,play=0; 
uchar shige,shishi,fenge,fenshi,miaoge,miaoshi;
/************************************************ 
���� 3 ������ K1 ���ڵ��ڷ֣�
K2 ���ڵ���ʱ�� K3 ���ڵ���ʱ
************************************************/ 
sbit K1=P3^3; //����� ���ڷ�
sbit K2=P3^4; // ����ĵ���ʱ
sbit K3=P3^5; // �������ͣ����ʼ

void display(uchar miao,uchar fen,uchar shi); // ��ʾʱ��
void play_display(); // ��ͣ / ��ʼ����
void delay(uint z); // ��ʱ����
void init(); // ��ʼ������
//////////////////////////////////////////////////////////

 
uchar code table[]={0x3f,0x06,0x5b,0x4f,0x66, 0x6d,0x7d,0x07,0x7f,0x6f}; 

void send(unsigned char dat)            //���ݷ��ͳ���
{
   	SBUF=dat;                           //��Ҫ���͵����ݴ��뷢�ͻ�������
	while(TI==0);                       //�������жϱ�־λû����1(���ڷ�������)���͵ȴ�

	TI=0;                               //��������ɣ�TI�Զ���1�������������
}



////////////////////////////////////////////////////////////
void delay(uint z) 
{ 
uint x,y; 
for(x=z;x>0;x--) 
for(y=110;y>0;y--); 
}



void main()
{
	unsigned char i=0;
	 init();// ��ʼ���ӳ���
miao=0; 
shi=0; 
fen=0; 
	TMOD=0x21;                         //��ʱ��T1�����ڷ�ʽ2�����Զ���װ��8λ��ʱ����
	SCON=0x50;                         //���ڹ�����ʽ1�����������
	PCON=0x00;                         //�����ʲ�����
	TH1=0xf4;                          //������Ϊ2400b/s
	TL1=0xf4;
	TR1=1;                             //������ʱ��T1��T1�������ʵķ�������
	REN=1;                         //�����������
	while(1)
	{	
	
	  uchar i;

//fasong[0]=shishi;
//fasong[1]=shige;
//fasong[2]=fenshi;
//fasong[3]=fenge;
//fasong[4]=miaoshi;
//fasong[5]=miaoge;	

fasong[0]=miao;
fasong[1]=fen;
fasong[2]=shi;


	   

				play_display(); 
				display(miao,fen,shi);  
				
				send(0x55); //��ʼ ͷ
				for(i=0;i<6;i++)		 //����������ѭ���ط������������ ��display(miao,fen,shi)���������߷���shi��fen��miao
				{
				send(fasong[i]);
				display(miao,fen,shi);
				}


				send(0x60); 	//��
                
	}

}
 ////////////////////////////////////////////////////////////

void display(uchar miao,uchar fen,uchar shi) // ��ʾ�Ӻ���
{
uchar shige,shishi,fenge,fenshi,miaoge,miaoshi;
				shige=shi%10;
				shishi=shi/10;
				fenge=fen%10;
				fenshi=fen/10;
				miaoge=miao%10;
				miaoshi=miao/10;

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
void init() // ��ʼ���Ӻ���
{ 
temp=0; 
//TMOD=0x01; 
TH0=(65536-45872)/256; 
TL0=(65536-45872)%256; // ��ʱ����ֵ����ʱ 50ms��12M ���񣩣����ڿ��� MCU ָ���ʱ�䣬�˴�����ֵλ 45872 
EA=1; 
ET0=1; 
TR0=1; 
} 

///////////////////////////////////////////////////////
void timer0() interrupt 1 // ��ʱ�������ж�
{ 
TH0=(65536-45872)/256; 
TL0=(65536-45872)%256; 
aa++; 
if(aa==20) // �ж� 20 ��Ϊ 1S����� 1 
{ 
miao++; 
aa=0; 
if(miao==60) 
{ 
fen++; // �� 60S, �ּ� 1,���� 0 
miao=0; 
if(fen==60) 
{ 
shi++; // Сʱ�� 1 
fen=0; 
if(shi==24) shi=0; // Сʱ��
} 
} 
} 

shige=shi%10;
shishi=shi/10;
fenge=fen%10;
fenshi=fen/10;
miaoge=miao%10;
miaoshi=miao/10;

fasong[0]=shishi;
fasong[1]=shige;
fasong[2]=fenshi;
fasong[3]=fenge;
fasong[4]=miaoshi;
fasong[5]=miaoge;		   
	



} 
//////////////////////////////////////////////////////////


void play_display() 
{ 
if(K3==0) 
{ delay(1); 
if(K3==0) 
{ 
play++; // ���������ͣ��ʼ������Ϊ��ͣ��˫��Ϊ��ʼ
} 
while((i<50)&&(K3==0)) // ��ⰴ���Ƿ��ɿ�
{ 
delay(1); 
i++; 
} 
} 
if(play%2==1) // ��ͣ
{ 
TR0=0; 
if(K1==0) // ����
{ 
delay(2); 
if(K1==0) fen++; 
if(fen==60) fen=0; 
delay(2); 
while(!K1); 
} 
if(K2==0) // ��Сʱ
{ 
delay(2); 
if(K2==0) shi++; 
if(shi==24) shi=0; 
delay(2); 
while(!K2); 
} 
} 
else // ��ʼ
{ 
TR0=1; 
} 
}

unsigned char receive(void)         //���ݽ��պ���
{
	unsigned char dat;
	
	while(RI==0);                   //����û�н������ʱ�ȴ�����
	RI=0;                           //�������ʱ����
	dat=SBUF;                       //�����ջ������е����ݴ���dat
	return dat;                     //�����յ������ݷ���
}