#ifndef __MAIN_H__
#define __MAIN_H__

#include <reg52.h>
#include <intrins.h>

#define uchar unsigned char	//����ת��
#define uint unsigned int	//����ת��

/*��Ҫ: 
	��һƬ��74HC595������14Ҫ�ӵ��ڶ�Ƭ��74HC595������9, ǧ���ܸ㷴
	��һƬ��74HC595������12�ӵڶ�Ƭ��74HC595������12
	��һƬ��74HC595������11�ӵڶ�Ƭ��74HC595������11

�������Žӷ�, �뿴��·ͼ
*/

sbit serial_dat = P3^4;	//�ڶ�Ƭ74HC595������14
sbit storage_reg = P3^5;	//�ڶ�Ƭ74HC595������12
sbit shift_reg = P3^6;	//�ڶ�Ƭ74HC595������11 


//�������߱�������
extern void Delay_ms(uint n);
extern void Send_Data(uchar dat);
extern void Send_Byte(uchar dat);

#endif