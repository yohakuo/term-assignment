//#include "reg52.h"
sfr P2 = 0xA0;
sbit LED8=P2^7;	
void main()
{
	int i;
	while(1)
	{
		LED8=0;	
		for(i=0;i<=10000;i++);
		LED8=1;
		for(i=0;i<=10000;i++);
						
    }
}