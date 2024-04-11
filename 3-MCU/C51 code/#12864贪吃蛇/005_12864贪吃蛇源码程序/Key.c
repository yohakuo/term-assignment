#include "stc.H"
#include "Key.h"
#define OS_LONG_KEY_EN 1//���Ӧ������Ҫ������������������Ϊ1��������Ϊ0�����Ӧ���в���Ҫ���������������鶨��Ϊ0���Խ�ʡ����ռ䣩
#define GPIO_KEY P1

unsigned char KeyValue;//������Ŷ�ȡ���ļ�ֵ
unsigned char code DIG_CODE[17]={
0,0,0,0,0,5,0,0,6,0,4,0,0,3,0,0,0};
/***********************************************
����˵������������ɨ��
��ڲ�������
���ڲ�����ɨ��һ�μ����Ի�ð������
ע����OSReadKey������������
***********************************************/
unsigned char KeyDown(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//��ȡ�����Ƿ���
	{
		Delay10ms();//��ʱ10ms��������
		if(GPIO_KEY!=0x0f)//�ٴμ������Ƿ���
		{
			
			//������
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//������
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 //��ⰴ�����ּ��
			{
				Delay10ms();
				a++;
			}
		}
	}
 
	return KeyValue;	   
}
/**********************************************
����˵������ȡ��������
��ڲ�������
���ڲ��������ذ�������
ע�⣺
û�а����������򷵻�0��
ʹ�þ��󰴼�:����S12������S6;����S12;����S9;
***********************************************/
unsigned char OSReadKey(void)
{
	static unsigned char KeyEventCnt=0;
	static unsigned char KeySampleCnt=0;
	static unsigned char KeyBuffer=0;
#define SHORT_ON_DITHERING_COUNTER 3//����̰�����ȥ��ʱ��
#define SHORT_OFF_DITHERING_COUNTER 3//����̰��ɿ�ȥ��ʱ�䣬һ����̰�����ȥ��ʱ����ͬ

#if OS_LONG_KEY_EN>0
	static unsigned int LongKeySampleCnt=0;
	#define LONG_ON_DITHERING_COUNTER 250//���峤������ȷ����Ҫ��ʱ�䣬�����ÿ1MS����һ��OSReadKey()����1000��ζ�����ʱ��Ϊ1S
	#define LONG_OFF_DITHERING_COUNTER 3//���峤���ɿ�ȥ��ʱ�䣬һ��Ͷ̰�ȥ��ʱ����ͬ
#endif
	unsigned char KeyTemp;
	KeyTemp=DIG_CODE[KeyDown()];
	switch(KeyEventCnt)
	{
		case 0:
			if(KeyTemp!=0)
			{
				KeySampleCnt=0;
				KeyBuffer=KeyTemp;
				KeyEventCnt=1;     
			}
			return 0;//no key on,return 0
			break;
		
		#if OS_LONG_KEY_EN>0	
		case 1:
			if(KeyTemp!=KeyBuffer)
			{
				KeyEventCnt=0;
				return 0;//is dithering,return 0
			}
			else
			{
				if(++KeySampleCnt>SHORT_ON_DITHERING_COUNTER)
				{
					KeySampleCnt=0;
					KeyEventCnt=2;
					LongKeySampleCnt=0;
					return ((KeyBuffer-1)<<2)+1;//sure that key on,return (KeyBuffer-1)<<2+1
				}
				else
					return 0;//not sure that key on,return 0                 
			}
			break;
				
		case 2:
			if(++LongKeySampleCnt>LONG_ON_DITHERING_COUNTER)
			{
				KeySampleCnt=0;
				KeyEventCnt=3;
				return ((KeyBuffer-1)<<2)+2; //sure that key long on,return (KeyBuffer-1)<<2+2
			}
			else
			{
				if(KeyTemp!=KeyBuffer)
				{
					if(++KeySampleCnt>SHORT_OFF_DITHERING_COUNTER)
					{
						KeyEventCnt=0;
						return ((KeyBuffer-1)<<2)+3;//after short on to off,(KeyBuffer-1)<<2+3
					}
					else
						return 0;
				}
				else
				{
					KeySampleCnt=0;
					return 0;
				}
			}
			break;
		
		case 3:
			if(KeyTemp!=KeyBuffer)
			{
				if(++KeySampleCnt>LONG_OFF_DITHERING_COUNTER)
				{
					KeyEventCnt=0;
					return ((KeyBuffer-1)<<2)+4;  //after long key on turn to off,(KeyBuffer-1)<<2+4
				}
				else
					return 0;
			}
			else
			{
				KeySampleCnt=0;
				return 0;
			}
			break;
		
		#else
		case 1:
			if(KeyTemp!=KeyBuffer)
			{
				KeyEventCnt=0;
				return 0;//is dithering,return 0
			}
			else
			{
				if(++KeySampleCnt>=SHORT_ON_DITHERING_COUNTER)
				{
					KeySampleCnt=0;
					KeyEventCnt=2;
					return ((KeyBuffer-1)<<2)+1;//sure that key on,return (KeyBuffer-1)<<2+1
				}
				else
					return 0;//not sure that key on,return 0                 
			}
			break;
				
		case 2:
			if(KeyTemp!=KeyBuffer)
			{
				if(++KeySampleCnt>=SHORT_OFF_DITHERING_COUNTER)
				{
					KeyEventCnt=0;
					return ((KeyBuffer-1)<<2)+3;//after short on to off,(KeyBuffer-1)<<2+3
				}
				else
					return 0;
			}
			else
			{
				KeySampleCnt=0;
				return 0;
			}
			break;
		#endif

		default:break;
	}
	return 0;
}

/*******************************************************************************
* �� �� ��         : Delay10ms
* ��������		   : ��ʱ��������ʱ10ms
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void Delay10ms(void)   //��� 0us
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}
/***************************************************************/
