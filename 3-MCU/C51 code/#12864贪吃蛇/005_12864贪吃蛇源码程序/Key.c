#include "stc.H"
#include "Key.h"
#define OS_LONG_KEY_EN 1//如果应用中需要处理长按键动作，则定义为1，否则定义为0（如果应用中不需要处理长按动作，则建议定义为0，以节省代码空间）
#define GPIO_KEY P1

unsigned char KeyValue;//用来存放读取到的键值
unsigned char code DIG_CODE[17]={
0,0,0,0,0,5,0,0,6,0,4,0,0,3,0,0,0};
/***********************************************
功能说明：按键驱动扫描
入口参数：无
出口参数：扫描一次键盘以获得按键句柄
注：交OSReadKey（）函数调用
***********************************************/
unsigned char KeyDown(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//读取按键是否按下
	{
		Delay10ms();//延时10ms进行消抖
		if(GPIO_KEY!=0x0f)//再次检测键盘是否按下
		{
			
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=0;break;
				case(0X0b):	KeyValue=1;break;
				case(0X0d): KeyValue=2;break;
				case(0X0e):	KeyValue=3;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 //检测按键松手检测
			{
				Delay10ms();
				a++;
			}
		}
	}
 
	return KeyValue;	   
}
/**********************************************
功能说明：读取按键动作
入口参数：无
出口参数：返回按键动作
注意：
没有按键动作，则返回0，
使用矩阵按键:向上S12；向下S6;向左S12;向右S9;
***********************************************/
unsigned char OSReadKey(void)
{
	static unsigned char KeyEventCnt=0;
	static unsigned char KeySampleCnt=0;
	static unsigned char KeyBuffer=0;
#define SHORT_ON_DITHERING_COUNTER 3//定义短按按下去抖时间
#define SHORT_OFF_DITHERING_COUNTER 3//定义短按松开去抖时间，一般与短按按下去抖时间相同

#if OS_LONG_KEY_EN>0
	static unsigned int LongKeySampleCnt=0;
	#define LONG_ON_DITHERING_COUNTER 250//定义长按按下确认需要的时间，如果是每1MS调用一次OSReadKey()，则1000意味着这个时间为1S
	#define LONG_OFF_DITHERING_COUNTER 3//定义长按松开去抖时间，一般和短按去抖时间相同
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
* 函 数 名         : Delay10ms
* 函数功能		   : 延时函数，延时10ms
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Delay10ms(void)   //误差 0us
{
    unsigned char a,b,c;
    for(c=1;c>0;c--)
        for(b=38;b>0;b--)
            for(a=130;a>0;a--);
}
/***************************************************************/
