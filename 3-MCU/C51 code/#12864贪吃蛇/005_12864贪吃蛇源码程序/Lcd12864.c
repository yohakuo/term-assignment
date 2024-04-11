#include "stc.h"
#include "intrins.h"
#include "Lcd12864.h"
/*************
测试LCD是否处于忙状态
如果忙则返回0x80，否则返回0
**************/
unsigned char Lcd_CheckBusy(void)
{
    unsigned char Busy;
	LcdData=0xff;
    RS=0;
    RW=1;
    E=1;
    _nop_(); 
    Busy=LcdData&0x80;
    E=0;
    return Busy;
}

/*********************************
向LCD写入字节数据
**********************************/
void Lcd_WriteData(unsigned char Data)
{  
	while(Lcd_CheckBusy());
	RS=1;
	RW=0;
	E=0;
	_nop_();  
	_nop_(); 
	LcdData=Data;
	E=1;
	_nop_();
	_nop_();
	E=0;
}

/***********************************
从LCD中读出数据
************************************/
unsigned char Lcd_ReadData(void)
{
	unsigned char Temp;
	while(Lcd_CheckBusy());
 	LcdData=0xff;
 	RS=1;
	RW=1;
	E=1;
	_nop_();
   	Temp=LcdData;
   	E=0;
   	return Temp;
}

/*************************************
想LCD中写入指令代码
**************************************/
void Lcd_WriteCmd(unsigned char CmdCode)
{  
	while(Lcd_CheckBusy());
   	RS=0;
   	RW=0;
   	E=0;
   	_nop_();  
	_nop_();
   	LcdData=CmdCode;
   	_nop_(); 
	_nop_();
   	E=1;
   	_nop_();  
	_nop_();
   	E=0;
}

/*************************************
向LCD指定起始位置写入一个字符串
*************************************/
void Lcd_WriteStr(unsigned char x,unsigned char y,unsigned char *Str)
{
	if((y>3)||(x>7))
		return;//如果指定位置不在显示区域内，则不做任何写入直接返回
	EA=0;
	switch(y)
	{
		case 0:
				Lcd_WriteCmd(0x80+x);
				break;
		case 1:
				Lcd_WriteCmd(0x90+x);
				break;				
		case 2:
				Lcd_WriteCmd(0x88+x);
				break;
		case 3:
				Lcd_WriteCmd(0x98+x);
				break;
	}
	while(*Str>0)
	{  
		Lcd_WriteData(*Str);
  		Str++;     
	}
	EA=1;
}

/**************************************
为加速逻辑运算而设置的掩码表，这是以牺牲空间而换取时间的办法
***************************************/
code unsigned int MaskTab[]={0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,
							 0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
/***************************************
向LCD指定坐标写入一个象素,象素颜色有两种，0代表白（无显示），1代表黑（有显示）
****************************************/
void Lcd_PutPixel(unsigned char x,unsigned char y,unsigned char Color)
{
	unsigned char z,w;
	unsigned int Temp;
	if(x>=128||y>=64)
		return;
	Color=Color%2;
	w=15-x%16;//确定对这个字的第多少位进行操作
	x=x/16;//确定为一行上的第几字

	if(y<32) //如果为上页
		z=0x80;
	else     //否则如果为下页
		z=0x88;

	y=y%32;
	EA=0;
	Lcd_WriteCmd(0x36);
	Lcd_WriteCmd(y+0x80);        //行地址
	Lcd_WriteCmd(x+z);     //列地址 
	Temp=Lcd_ReadData();//先空读一次
	Temp=(unsigned int)Lcd_ReadData()<<8;//再读出高8位
	Temp|=(unsigned int)Lcd_ReadData();//再读出低8位
	EA=1;
	if(Color==1) //如果写入颜色为1
		Temp|=MaskTab[w];//在此处查表实现加速
	else         //如果写入颜色为0
		Temp&=~MaskTab[w];//在此处查表实现加速
	EA=0;
	Lcd_WriteCmd(y+0x80);        //行地址
	Lcd_WriteCmd(x+z);     //列地址
    Lcd_WriteData(Temp>>8);//先写入高8位，再写入低8位
    Lcd_WriteData(Temp&0x00ff);
	Lcd_WriteCmd(0x30);
	EA=1;
}

/******************************************
从LCD指定坐标读取象素颜色值
*******************************************/
unsigned char Lcd_ReadPixel(unsigned char x,unsigned char y)
{
	unsigned char z,w;
	unsigned int Temp;
	x=x%128;
	y=y%64;
	w=15-x%16;//确定对这个字的第多少位进行操作
	x=x/16;//确定为一行上的第几字

	if(y<32) //如果为上页
		z=0x80;
	else     //否则如果为下页
		z=0x88;

	y=y%32;
	Lcd_WriteCmd(0x36);
	Lcd_WriteCmd(y+0x80);        //行地址
	Lcd_WriteCmd(x+z);     //列地址 
	Temp=Lcd_ReadData();//先空读一次
	Temp=(unsigned int)Lcd_ReadData()<<8;//再读出高8位
	Temp|=(unsigned int)Lcd_ReadData();//再读出低8位

	if((Temp&&MaskTab[w])==0)
		return 0;
	else
		return 1;
}

/***************************************
向LCD指定位置画一条长度为Length的指定颜色的水平线
****************************************/
void Lcd_HoriLine(unsigned char x,unsigned char y,unsigned char Length,unsigned char Color)
{
	unsigned char i;
	if(Length==0)
		return;
	for(i=0;i<Length;i++)
	{
		Lcd_PutPixel(x+i,y,Color);
	}
}

/***************************************
向LCD指定位置画一条长度为Length的指定颜色的垂直线
****************************************/
void Lcd_VertLine(unsigned char x,unsigned char y,unsigned char Length,unsigned char Color)
{
	unsigned char i;
	if(Length==0)
		return;
	for(i=0;i<Length;i++)
	{
		Lcd_PutPixel(x,y+i,Color);
	}
}

/*******************************************
向LCD指定起始坐标和结束坐标之间画一条指定颜色的直线
********************************************/
void Lcd_Line(unsigned char x1,unsigned char y1,unsigned char x2,unsigned char y2,unsigned char Color)
{
	unsigned int x,y; 
	unsigned int d_x,d_y;//d_x=x2-x1;d_y=y2-y1;
	int err=0;
	unsigned char temp=0;
	if(y2<y1)
	{
		x=x1;
		y=y1;
		x1=x2;
		y1=y2;
		x2=x;
		y2=y;
	}
	d_y=y2-y1;
	if (d_y==0)
	{
		if (x1>x2) 
		{
			x=x1;
			x1=x2;
			x2=x;
		}
		for (x=x1;x<=x2;x++) 
			Lcd_PutPixel(x,y1,Color);
	}

	else
	{
		if(x2>=x1)
		{
			temp=1;
			d_x=x2-x1;
		}
		else 
			d_x=x1-x2;
		x=x1;
		y=y1;
		Lcd_PutPixel(x,y,1);

		if(temp&&(d_y<=d_x))
			while(x!=x2)
			{
				if(err<0)
				{
					x=x+1;
					err=err+(y2-y);
				}
				else 
				{
					x=x+1;
					y=y+1;
					err=err+(y2-y)-(x2-x);
				}
				Lcd_PutPixel(x,y,Color);
			}

		else if(temp&&(d_y>d_x))
			while(y!=y2)
			{
				d_x=x2-x;
				d_y=y2-y; 
				if(err<0)
				{
					x=x+1;
					y=y+1;
					err=err+d_y-d_x;
				}
				else 
				{
					y=y+1;
					err=err-d_x;
				}
				Lcd_PutPixel(x,y,Color);

			}

		else if(!temp&&(d_y<=d_x))
			while(x!=x2)
			{
				d_x=x-x2;
				d_y=y2-y; 
				if(err<0)
				{
					x=x-1;
					err=err+d_y;
				}
				else 
				{
					x=x-1;
					y=y+1;
					err=err+d_y-d_x;
				}
				Lcd_PutPixel(x,y,Color);
			}

		else if(!temp &&(d_y>d_x))
			while(y!=y2)
			{
				d_x=x-x2;
				d_y=y2-y; 
				if(err<0)
				{
					x=x-1;
					y=y+1;
					err=err+d_y-d_x;
				}
				else 
				{
					y=y+1;
					err=err-d_x;
				}
				Lcd_PutPixel(x,y,Color);
			}
	}
}

/*******************************************
向LCD指定左上角坐标和右下角坐标画一个指定颜色的矩形
********************************************/
void Lcd_Rectangle(unsigned char x0,unsigned char y0,unsigned char x1,unsigned char y1,unsigned char Color)
{
	unsigned char Temp;
	if(x0>x1)
	{
		Temp=x0;
		x0=x1;
		x1=Temp;
	}	
	if(y0>y1)
	{
		Temp=y0;
		y0=y1;
		y1=Temp;
	}
	Lcd_VertLine(x0,y0,y1-y0+1,Color);
	Lcd_VertLine(x1,y0,y1-y0+1,Color);
	Lcd_HoriLine(x0,y0,x1-x0+1,Color);
	Lcd_HoriLine(x0,y1,x1-x0+1,Color);	
}

/****************************************
对称法画圆的8个镜像点
*****************************************/
void CircleDot(unsigned char x,unsigned char y,char xx,char yy,unsigned char Color)//内部函数，对称法画圆的8个镜像点
{
	Lcd_PutPixel((x+yy),(y+xx),Color);//第 1 个 8 分圆
	Lcd_PutPixel((x+xx),(y+yy),Color);//第 2 个 8 分圆
	Lcd_PutPixel((x-xx),(y+yy),Color);//第 3 个 8 分圆
	Lcd_PutPixel((x-yy),(y+xx),Color);//第 4 个 8 分圆
	Lcd_PutPixel((x-yy),(y-xx),Color);//第 5 个 8 分圆
	Lcd_PutPixel((x-xx),(y-yy),Color);//第 6 个 8 分圆
	Lcd_PutPixel((x+xx),(y-yy),Color);//第 7 个 8 分圆
	Lcd_PutPixel((x+yy),(y-xx),Color);//第 8 个 8 分圆
}

/******************************************
向LCD指定圆心坐标画一个半径为r的指定颜色的圆
*******************************************/
void Lcd_Circle(unsigned char x,unsigned char y,unsigned char r,unsigned char Color)//中点法画圆
{//中点法画圆
	unsigned char xx,yy;
	char deltax,deltay,d;
	xx=0;
	yy=r;
	deltax=3;
	deltay=2-r-r;
	d=1-r;
	CircleDot(x,y,xx,yy,Color);//对称法画圆的8个镜像点
	while (xx<yy)
	{
		if (d<0)
		{
			d+=deltax;
			deltax+=2;
			xx++;
		}
		else
		{
			d+=deltax+deltay;
			deltax+=2;
			deltay+=2;
			xx++;
			yy--;
		}
		CircleDot(x,y,xx,yy,Color);//对称法画圆的8个镜像点
	}
}

/*****************************************
清除Lcd全屏，如果清除模式Mode为0，则为全屏清除为颜色0（无任何显示）
否则为全屏清除为颜色1(全屏填充显示)
******************************************/
void Lcd_Clear(unsigned char Mode)
{
	unsigned char x,y,ii;
	unsigned char Temp;
	if(Mode%2==0)
		Temp=0x00;
	else
		Temp=0xff;
	Lcd_WriteCmd(0x36);//扩充指令 绘图显示
	for(ii=0;ii<9;ii+=8)   
		for(y=0;y<0x20;y++)     
			for(x=0;x<8;x++)
			{ 	
				EA=0;
				Lcd_WriteCmd(y+0x80);        //行地址
				Lcd_WriteCmd(x+0x80+ii);     //列地址     
				Lcd_WriteData(Temp); //写数据 D15－D8 
				Lcd_WriteData(Temp); //写数据 D7－D0 
				EA=1;
			}
	Lcd_WriteCmd(0x30);
}

/****************************************
LCD初始化
*****************************************/
void Lcd_Reset()
{  
	PSB=1;
	Lcd_WriteCmd(0x30);       //选择基本指令集
	Lcd_WriteCmd(0x0c);       //开显示(无游标、不反白)
	Lcd_WriteCmd(0x01);       //清除显示，并且设定地址指针为00H
	Lcd_WriteCmd(0x06);       //指定在资料的读取及写入时，设定游标的移动方向及指定显示的移位
}

